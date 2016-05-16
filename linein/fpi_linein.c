/*********************************************************************************************
* Filename	: fpi_linein.c
* Author   	: LinShunda
* Description: 供切换信源。  
* Version:   
* Function List:	
* 1. --------- 
* History: 	
* <author>  	  <time>   			<version >   <desc>	
* LinShunda    	2012-07-11 	 		1.0    	 	build this moudle  	
* Copyright	: TCL Electronics(Shen Zhen) Co.,Ltd.
********************************************************************************************/

#include <stdio.h>
#include "fpi_demod.h"
#include "tvh_state.h"
#include "fpi_error_code.h"
#include "fpp_linein.h"
#include "fpp_system.h"
#include "fpp_zoom.h"
#include "fpp_channel.h"
#include "tvh_signal.h"
#include "tvh_scart.h"
#include "fpi_debug_helper.h"
#include "fpi_mheg.h"
#include "tvh_dtv_play.h"
#include "fpi_notify_event.h"
#include "fpi_zoom.h"
#include "fpi_3d.h"
#include "fpi_channel_play.h"
#include "fpi_factory.h"
#include "fpi_power.h"
#include "fpi_common.h"
#include "db_dtv.h"
#include "db_factory.h"
#include "fpi_linein.h"
#include "sys_config.h"
#include "uti_config.h"
#include "db_user_setting.h"
#include "db_atv.h"
#include "fpi_cec.h"
#include "app_user_setting.h"
#include "fpi_teletext.h"
#include "app_video.h"
#ifdef FPI_CIPLUS
#include"tvh_ci_service.h"
#endif

//#ifdef SCART_ENABLE
#include "fpi_scart.h"

#include "fcntl.h"
//#endif
#define BOOT_WAKEUP_FLAG_FILE	   "/tmp/boot_by_netflix_key"	
#ifdef SUBTITLE_ENABLED
#include "fpi_program_play_subtitle.h"
#endif

#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)
#include "fpi_hbbtv.h"
#endif

#include "fpi_closed_caption.h"
#include "tvh_oad_mgr.h"

#include "tvh_boot_video.h"
#include "sita_property.h"
#include "itv_platform.h"
#include "fpi_dtv.h"
/**************************************************/
SET_MODEL_ID(SITA_MODULE_LINEIN);


#define DEBUG_LINEIN(fmt, arg...)   fpi_trace("*fpi_linein*"fmt, ##arg)


void tvh_notify_func( uint32_t un32_event, uint32_t un32_p1, uint32_t un32_p2 ) ;


static os_mutex_handle_t change_linein_mux = OS_MUTEX_INVALID_ID;


static fpi_linein_t s_current_linein = FPI_LINEIN_INVALID;
static fpi_linein_t s_previous_linein  = FPI_LINEIN_INVALID;
static LINEIN_INIT_BY_MID_TYPE linein_init_by_mid = LINEIN_INIT_BY_MID_NONE;
static fpi_bool is_fpi_linein_changing = fpi_false;
static fpi_linein_t s_target_source;
static uint8_t u8_timing_distinguish = 1;
static fpi_linein_t current_open_linein = FPI_LINEIN_INVALID;

void add_linein_test( void ) ;


static void linein_av_mute(void)
{
	fpi_info("Enter %s,line = %d\n",__FUNCTION__,__LINE__);
	fpi_video_mute_config_t st_mute = {fpi_true, EN_VIDEO_MUTE_CHANGE_LINEIN};

	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.chglinein",fpi_true);
	fpi_video_mute(&st_mute);
}


static void linein_av_unmute(fpi_linein_t linein)
{
	fpi_info("Enter %s,line = %d,linein = 0x%x\n",__FUNCTION__,__LINE__,linein);
	fpi_video_mute_config_t st_mute = {fpi_false, EN_VIDEO_MUTE_CHANGE_LINEIN};
#if 0//linshunda 不能以东芝之类来区分
	if(EN_TYPE_TOSHIBA == uti_config_getint(CONFIG_COMMON, CONFIG_COM_TYPE)) // 按照舜大2014-7-5邮件修改(针对ms918平台修改)
	{
		if(FPI_LINEIN_STORAGE == linein || FPI_LINEIN_KTV == linein)
		{
			st_mute.e_level = EN_VIDEO_MUTE_LV_ANY;
		}

		fpi_video_mute(&st_mute);        
	}
	else 
  #endif  
	if(!(FPI_LINEIN_STORAGE == linein || FPI_LINEIN_KTV == linein))
	{
    		fpi_video_mute(&st_mute);
	}
	else
	{
		fpi_video_clear_mute_level();
	}

	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.chglinein",fpi_false);
  
	fpi_info("Exit %s,line = %d\n",__FUNCTION__,__LINE__);
}

static fpi_bool _linein_dtv_and_has_no_channel(fpi_linein_t linein )
{
	uint32_t count = 0; 
	if(linein == FPI_LINEIN_CDTV||linein == FPI_LINEIN_TDTV) 
	{
		EN_COUNT_PROGRAM_OPTION option = E_EXCLUDE_NOT_VISIBLE_AND_DELETED;
		if(db_dtv_get_cur_channel_type())
		{
			option = E_OP_SERVICE_VISIBLE_SELECTABLE;
		}
			
		uint32_t countD = (uint32_t)db_dtv_get_prog_count_by_type_option(EN_SERVICETYPE_DTV, option);
		uint32_t countR = (uint32_t)db_dtv_get_prog_count_by_type_option(EN_SERVICETYPE_RADIO, option);
		uint32_t countU = (uint32_t)db_dtv_get_prog_count_by_type_option(EN_SERVICETYPE_UNITED_TV, option);

		count = countD+countR+countU;
		if(count == 0)
			return fpi_true;
		else
			return fpi_false;
	}
	return fpi_false;
}
static void _linein_mute_previous(	fpi_linein_t linein )
{
//    if(EN_AREA_CN == uti_config_get_area())
	if( (E_HONGKONG == app_get_db_system_country() )||( E_CHINA == app_get_db_system_country()))//uti_config_get_area已经停用	
	{
		if(FPI_LINEIN_STORAGE == linein || FPI_LINEIN_KTV == linein)
		{
			fpi_video_color stColor = {0};
			fpi_video_set_mute_color(&stColor);
		}
		else if(FPI_LINEIN_STORAGE == s_current_linein || FPI_LINEIN_KTV == s_current_linein)
		{
			fpi_video_set_default_mute_color();
		}
	}
    
    //如果一次信源切换都未完成，就不存在close上一次
    //如果第一次启动是dtv，且无频道，则也需要做相关mute
	if((fpi_common_get_first_time_input_finish_status() == fpi_true)
		|| ( _linein_dtv_and_has_no_channel(linein) == fpi_true))
    	{
        
        	linein_av_mute(); 
    	}
}

static void _linein_close_previous(	fpi_linein_t linein )
{
	fpi_trace("function = %s,line = %d\n",__FUNCTION__, __LINE__ );
	//如果一次信源切换都未完成，就不存在close上一次
	//clear  blockstate
	tvhsignal_set_lockstate(fpi_false);

	if(fpi_common_get_first_time_input_finish_status() == fpi_true)
	{
		fpi_trace("function = %s, s_current_linein=%d\n", __FUNCTION__,s_current_linein);
		if (FPI_LINEIN_INVALID != s_current_linein)
		{
			/*maybe should be add condition for current state is playing -- ???*/
			//切换信源的时候，推出出routine的所有运行状态

			tvhsignal_stop_manager();       // shane.xie 20131105 add for 停止信号检测

			//先关闭相应的信源
			switch (s_current_linein)
			{
				case FPI_LINEIN_CATV:
				case FPI_LINEIN_TATV:
//#ifndef SCART_ENABLE
					if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_false )
                			{
                				fpi_channel_atv_stop();
					}
					else
					{
#ifdef SUBTITLE_ENABLED
						fpi_info("function = %s,line = %d\n",__FUNCTION__,__LINE__);
						fpi_program_set_sbt_enable_monitor(fpi_false);
						fpi_program_switch_analog_sub(fpi_false);
#endif				
					}
//#endif


					fpi_trace("fpp_linein_close_atv\n");
					fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);

					fpi_info("function = %s,line = %d,close cc and disable monitor\n",__FUNCTION__,__LINE__);
					fpi_cc_enable_monitor(fpi_false);
					fpi_cc_close();

					break;
				case FPI_LINEIN_CDTV:
				case FPI_LINEIN_TDTV:
                			fpi_trace("function = %s,line = %d\n",__FUNCTION__, __LINE__ );
//#ifndef SCART_ENABLE
					if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_false )
					{
						/*add this by wangtexin for the change linein
						when dtv close ,it will term the DTV driver,
						and if MHEG call any av function when drvier close
						it will brack down, the better way is the dtv driver
						can do better,but now we mend it by this*/
			                    tvhdtv_terminate_play();
			    #ifdef MHEG5_ENABLED
			                    fpi_mheg_isDtvDriverStart(fpi_false);
			    #endif
			                    fpi_demod_set_active(E_FPI_DTV_STREAM_PORT_0, E_FPI_DTV_DELIVERY_TYPE_INVALID,fpi_false);

                    
					}
					else
					{
						fpi_video_mute_config_t video_mute = {0};

						video_mute.e_level = EN_VIDEO_MUTE_DECODER;
						video_mute.b_mute = fpi_false;	
						fpi_video_mute(&video_mute);
					}
//#endif

#ifdef SUBTITLE_ENABLED
					fpi_program_set_sbt_enable_monitor(fpi_false);
					fpi_program_close_subtitle();
#endif
    
					fpi_info("function = %s,line = %d,close cc and disable monitor\n",__FUNCTION__,__LINE__);
					fpi_cc_enable_monitor(fpi_false);
					fpi_cc_close();

					fpi_trace("fpp_linein_close_dtv\n");
					fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					break;
                    
				case FPI_LINEIN_CVBS1:
				case FPI_LINEIN_CVBS2:
				case FPI_LINEIN_CVBS3:
				case FPI_LINEIN_CVBS4:
					{
						fpi_info("function = %s,line = %d,close cc and disable monitor\n",__FUNCTION__,__LINE__);
						fpi_cc_enable_monitor(fpi_false);
						fpi_cc_close();
						fpi_trace("fpp_linein_close_cvbs\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					}
					break;
    
				case FPI_LINEIN_COMPONENT1:
				case FPI_LINEIN_COMPONENT2:
				case FPI_LINEIN_COMPONENT3:
				case FPI_LINEIN_COMPONENT4:
					{
						fpi_trace("fpp_linein_close_component\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					}
					break;
                
				case FPI_LINEIN_PC1:
				case FPI_LINEIN_PC2:
					{
						fpi_trace("fpp_linein_close_pc\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					}
					break;
            
				case FPI_LINEIN_HDMI1:
				case FPI_LINEIN_HDMI2:
				case FPI_LINEIN_HDMI3:
				case FPI_LINEIN_HDMI4:
					{
						fpi_trace("fpp_linein_close_hdmi\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					}
					break;
    
				case FPI_LINEIN_SCART1:
				case FPI_LINEIN_SCART2:
					{
						fpi_trace("fpp_linein_close_scart\n");
#ifdef SUBTITLE_ENABLED
						fpi_info("function = %s,line = %d\n",__FUNCTION__,__LINE__);
						fpi_program_set_sbt_enable_monitor(fpi_false);
						fpi_program_switch_analog_sub(fpi_false);
#endif
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein);
					}
					break;
					
				case FPI_LINEIN_STORAGE:
					{
						fpi_trace("fpp_linein_close_storage\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein) ;
					}
					break;
				case FPI_LINEIN_KTV:
					{
						fpi_trace("fpp_linein_close_ktv\n");
						fpp_linein_close((EN_FPP_LINEIN_TYPE_T)s_current_linein) ;
					}
					break;
			}
		}
	}
	else
	{
		 fpi_trace("fpp_linein_close for boot video,current_open_linein =%x,linein =%x\n",current_open_linein,linein);
		if (FPI_LINEIN_INVALID != current_open_linein&&linein!= current_open_linein)
		{
		 
		   fpi_trace("fpp_linein_close for boot video\n");
		   fpp_linein_close((EN_FPP_LINEIN_TYPE_T)current_open_linein);
		   current_open_linein = FPI_LINEIN_INVALID;
		}
	}
}


//#ifdef SCART_ENABLE
static void _linein_scart_out_finish(fpi_linein_t linein)
{
	//change linein to atv/dtv/mm,should stop previous tv_source
	if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
	{
		fpi_linein_t u32ScartOutLinein=db_get_scart_out_linein();
		if(linein == FPI_LINEIN_CDTV || linein == FPI_LINEIN_TDTV
			||linein == FPI_LINEIN_CATV ||linein == FPI_LINEIN_TATV ||linein == FPI_LINEIN_STORAGE)
		{
			DEBUG_LINEIN("function = %s, change linein to atv/dtv/mm \n",__FUNCTION__);
			fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_LINEIN);
        
			if(u32ScartOutLinein == FPI_LINEIN_CATV ||u32ScartOutLinein == FPI_LINEIN_TATV)
			{
				fpi_channel_atv_stop();
			}
			else if(u32ScartOutLinein == FPI_LINEIN_CDTV ||u32ScartOutLinein == FPI_LINEIN_TDTV)
			{
#ifdef SUBTITLE_ENABLED
				fpi_program_close_subtitle();//linshunda adding
#endif            
				/*add this by wangtexin for the change linein
				when dtv close ,it will term the DTV driver,
				and if MHEG call any av function when drvier close
				it will brack down, the better way is the dtv driver
				can do better,but now we mend it by this*/
				tvhdtv_terminate_play();
#ifdef MHEG5_ENABLED
				fpi_mheg_isDtvDriverStart(fpi_false);
#endif
				fpi_demod_set_active(E_FPI_DTV_STREAM_PORT_0, E_FPI_DTV_DELIVERY_TYPE_INVALID,fpi_false);
			}
		}  

	fpi_video_mute_config_t st_mute = {fpi_false, EN_VIDEO_MUTE_SCART};
        
	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.scart",fpi_false);

	fpi_video_mute(&st_mute);
    	}
}
//#endif

static void *fpi_line_update_thread_run(void *var)
{
	//uint8_t u8InputSrc;
	fpi_linein_t linein = *(fpi_linein_t*)var;
	fpi_video_update(fpi_false,linein);
	fpi_info("%s end\n", __FUNCTION__);
	return NULL;
}

fpi_error fpi_line_update_thread(fpi_linein_t linein) 
{
	os_thread_handle_t cur_thread_id = OS_THREAD_INVALID_ID;

	cur_thread_id = os_thread_create(fpi_line_update_thread_run, &linein, 0, OS_PRIORITY_MIDDLE, (char*)"fpi_line_update");

	if(OS_THREAD_INVALID_ID == cur_thread_id)
	{
		fpi_err("FATAL ERROR!! %s create \n", __FUNCTION__);
		fpi_video_update(fpi_false,linein);
	}
	fpi_info("%s end\n", __FUNCTION__);
	return FPI_ERROR_SUCCESS;
}

/******************************************************************************
*Function: fpi_linein_get_changing_status
*Description: 获取中间件是否正处于信源切换状态
*Input:    none: 
*Output:   
*Return:  	fpi_true---中间件正在切换信源
		fpi_false---中间件不处于信源切换状态
*Others:
******************************************************************************/
fpi_bool fpi_linein_get_changing_status(void)
{
	return is_fpi_linein_changing;
}

static void fpi_linein_set_changing_status(fpi_bool var)
{
	is_fpi_linein_changing = var;
}

/******************************************************************************
*Function: fpi_linein_changeto
*Description: 切换信源主要函数，会记录当前在播放的频道，切换信源后会进行信号检测
           进入tvh的信号检测状态 。
*Input:    linein: 要切换的信源 。
*Output:   
*Return:  是否切换成功
*Others:
******************************************************************************/

fpi_error fpi_linein_changeto(	fpi_linein_t linein )
{
	fpi_linein_set_changing_status(fpi_true);
	if(tvhsignal_get_processing_lock_status())
	{
		int cnt = 200;
		while((cnt-- > 0) && tvhsignal_get_processing_lock_status())
		{
			usleep(10000);
		}
	}
	
	fpi_error error = FPI_ERROR_LINEIN_FAIL;
	if(FPI_LINEIN_INVALID == linein)
	{
		fpi_alarm("fpi_linein_changeto_v1 ,linein = FPI_LINEIN_INVALID!!! \n");
		fpi_linein_set_changing_status(fpi_false);
		return FPI_ERROR_LINEIN_FAIL;
	}
	tvh_notify_func(FPI_NOTIFY_LINEIN_CHANGE_BEFORE_ACTIVE,0,0 ) ; //linshunda test

	fpi_info("enter fpi_linein_changeto_v1, current_linein=0x%x ,linein to=0x%x\n",s_current_linein,linein);

	if(linein == FPI_LINEIN_TDTV)
	{
		linein = FPI_LINEIN_CDTV;
	}

	//if(s_previous_linein == FPI_LINEIN_STORAGE)
	{
		fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"app.media",fpi_false);
	}
	
	os_mutex_obtain(fpi_linein_get_change_linein_mutex(), OS_WAIT_FOREVER); 
	
	if(linein == s_current_linein)
	{
		fpi_alarm("function = %s , linein == s_current_linein return !!!\n",__FUNCTION__);
		fpi_linein_set_changing_status(fpi_false);
		os_mutex_release(fpi_linein_get_change_linein_mutex());
		return FPI_ERROR_LINEIN_INVALID_PARAMETER;
	}

	fpi_common_set_common_thread_enable(fpi_false);
	_linein_mute_previous(linein);
	
	{//ct 2014.5.6 set 3d mode to none when change input source
		int32_t en3dtype = FPI_3D_NONE;
		fpi_get_current_3d_mode(&en3dtype);  
		fpi_trace("ct test .... 3d = %d\r\n",en3dtype);

		if(en3dtype > FPI_3D_NONE)
		{
			fpi_set_3d_mode(FPI_3D_NONE);
		}
	}


	//#ifdef SCART_ENABLE
	_linein_scart_out_finish(linein);
	//#endif
    
	if((FPI_LINEIN_CATV != linein) && (FPI_LINEIN_TATV != linein))
	{     
		fpi_audio_set_mts_thread_detect_enable(fpi_false);
	}
	
	   _linein_close_previous(linein);

	{
		fpi_bool b_freeze = fpi_false;    
		fpi_video_is_freeze(&b_freeze);

		if(b_freeze)
		{
			fpi_video_freeze(fpi_false);
		}
	}
	s_previous_linein = s_current_linein;

	{ // 2015-11-27 临时措施，还要去扑掉 
		fpi_bool bmute = fpi_true;
		fpi_video_mute_config_t st_mute= {fpi_false, EN_VIDEO_MUTE_APP};
		fpi_video_get_mute_state(EN_VIDEO_MUTE_APP, &bmute);
		if(bmute)
		{
			fpi_video_mute(&st_mute);
		}
	}
    
	//打开对应的信源,打开信源后会进入信号检测的routine状态
	//    if(FPI_LINEIN_STORAGE != linein && FPI_LINEIN_KTV != linein)	//USB下也需要检测scart pin8
	{
		tvhsignal_start_manager(linein);
	}
    
	switch (linein)
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			{
				//           #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_atv_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_atv_out_mute()) ;    
				//           #endif
				DEBUG_LINEIN("fpp_linein_open_atv\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_atv, ret=%d\n", error );
				fpi_channel_atv_set_play_type(E_ATV_PLAY_LINEIN_CH);
			}
			break;
        
		case FPI_LINEIN_CDTV:
		case FPI_LINEIN_TDTV:
			{
				//            #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_dtv_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_dtv_out_mute()) ; 
				//            #endif
				DEBUG_LINEIN("fpp_linein_open_dtv\n");
				/////////////////////////////

				error = fpi_linein_open(linein);
				fpi_demod_set_active(E_FPI_DTV_STREAM_PORT_0, (fpi_dtv_delivery_type_t)db_dtv_get_route(), fpi_true);

				DEBUG_LINEIN("fpp_linein_open_dtv,ret=%d\n",error);
				
				fpi_dtv_set_scart_out_mode(SCART_OUT_MODE_FRONT);
			}
			break;
        
		case FPI_LINEIN_CVBS1:
		case FPI_LINEIN_CVBS2:
		case FPI_LINEIN_CVBS3:
		case FPI_LINEIN_CVBS4:
			{
				//            #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ; 
				//           #endif
				DEBUG_LINEIN("fpp_linein_open_cvbs\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_cvbs,ret=%d\n",error );
				fpi_info("function = %s,line = %d,change to av,enable monitor\n",__FUNCTION__,__LINE__);
				fpi_cc_enable_monitor(fpi_true);
			}
			break;
        
		case FPI_LINEIN_SVIDEO1:
		case FPI_LINEIN_SVIDEO2:
			{
				//           #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ; 
				//            #endif
				DEBUG_LINEIN("fpp_linein_open_svideo\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_svideo,ret=%d\n",error);
			}
			break;
        
		case FPI_LINEIN_COMPONENT1:
		case FPI_LINEIN_COMPONENT2:
		case FPI_LINEIN_COMPONENT3:
		case FPI_LINEIN_COMPONENT4:
			{
				//           #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_cmp_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_cmp_out_mute()) ; 
				//            #endif
				DEBUG_LINEIN("fpp_linein_open_component\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_component,ret=%d\n", error );
			}
			break;
        
		case FPI_LINEIN_PC1:
		case FPI_LINEIN_PC2:
			{
				//           #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_vga_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_vga_out_mute()) ; 
				//            #endif
				DEBUG_LINEIN("fpp_linein_open_pc\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_pc,ret=%d\n", error);
			}
			break;
        
		case FPI_LINEIN_HDMI1:
		case FPI_LINEIN_HDMI2:
		case FPI_LINEIN_HDMI3:
		case FPI_LINEIN_HDMI4:
			{
				//          #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_hdmi_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_hdmi_out_mute()) ; 
				//           #endif
				DEBUG_LINEIN("fpp_linein_open_hdmi\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_hdmi,ret=%d\n",error);
			}
			break;

		case FPI_LINEIN_SCART1:
		case FPI_LINEIN_SCART2:
			{
				//            #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_scart_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_scart_out_mute()) ; 
				//            #endif

#ifdef SUBTITLE_ENABLED
				fpi_program_set_sbt_enable_monitor(fpi_true);
#endif
				DEBUG_LINEIN("fpp_linein_open_scart\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("fpp_linein_open_scart,ret=%d\n",error);
			}
			break;
        
		case FPI_LINEIN_STORAGE:
			{
				//           #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ; 
				//            #endif
				DEBUG_LINEIN("fpp_linein_open_STORAGE\n");
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("error=%d\n", error );
			}
			break;
        
		case FPI_LINEIN_KTV:
			{
				DEBUG_LINEIN("fpp_linein_open_ktv\n");

				//   #ifndef SCART_ENABLE
				fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ;
				fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ; 
				//    #endif
				error = fpi_linein_open(linein);
				DEBUG_LINEIN("error=%d\n", error );
			}
			break;

		default:
			{
				DEBUG_LINEIN("linein_open_, FPI_ERROR_LINEIN_NOT_SUPPORT\n");
				error = FPI_ERROR_LINEIN_NOT_SUPPORT;
			}
			break;
	}
	DEBUG_LINEIN("ret=%d\n",error);
	if (error == FPI_ERROR_LINEIN_SUCCESS)
	{
		tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_VIDEO_ACTION),
		E_TVH_VIDEO_MSG_UPDATE_4K1K, linein, MEMC_DELAY_TIMER_NORMAL);

		s_current_linein = linein;
		fpi_set_target_linein(linein);
		//app_save_db_lastest_linein(s_current_linein);
		//app_save_db_current_linein(s_current_linein);

		fpi_audio_set_track(linein,EN_FPI_AUDIO_TRACK_STEREO);
		fpi_zoom_reset_level();

		fpi_audio_spdif_delay_sync();
		
		if((FPI_LINEIN_CDTV != linein) && (FPI_LINEIN_TDTV != linein)) 
		{   //dtv source will do it after the audio normal event
			fpi_audio_set_delay(AUDIO_DELAY_EXCEPT_TV_SOURCE,0xff);
		}
        
		if(fpi_common_get_first_time_input_finish_status() == fpi_true)
		{
			EN_PICTURE_SIZE enPictureSize;
			fpi_bool bAutoFormat;
			ZOOM_VIEW_MODE enPictureView;
			int32_t val=0;
			//fpi_zoom_set_small_window_state(fpi_false);

			val = app_get_pic_mode_element(E_PIC_MODE_PIC_SIZE);
			enPictureSize=(EN_PICTURE_SIZE)val;

			val= app_get_pic_mode_element(E_PIC_MODE_AUTO_FORMAT);
			bAutoFormat=val;
			if(enPictureSize == E_AR_AUTO)
			{
	        		bAutoFormat=fpi_true;
			}
			else
			{
				//patch: bug id 0044907 连续调用两次linein预览模式，会导致比例模式错误
				if(E_CHINA == app_get_db_system_country() || E_HONGKONG == app_get_db_system_country())
				{
					bAutoFormat=fpi_false;
				}
			}
			val = app_get_pic_mode_element(E_PIC_MODE_PIC_VIEW);
			enPictureView = (ZOOM_VIEW_MODE)val;
			
			fpi_zoom_set_mode(enPictureSize, enPictureView);

			fpi_zoom_set_auto_format(bAutoFormat);
			
			if((FPI_LINEIN_CATV == linein) || (FPI_LINEIN_TATV == linein))
			{
				fpi_zoom_refresh_current(E_ZOOM_REFRESH_MUTE);
			}
		}

	        if(FPI_LINEIN_STORAGE == linein || FPI_LINEIN_KTV == linein)
	        {
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.sync",fpi_false);
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.scart",fpi_false);
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.chgchannel",fpi_false);

			linein_av_unmute(linein);
			tvhoad_stop_manager();

			//tvhsignal_start_src_insert_manager();
			// fpi_video_update(fpi_false, FPI_LINEIN_STORAGE);
			tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_VIDEO_ACTION),
				E_TVH_VIDEO_MSG_CHANGE_SRC, FPI_LINEIN_STORAGE, s_previous_linein);

			//fpi_line_update_thread(FPI_LINEIN_STORAGE);
			//fpi_common_set_common_thread_enable(fpi_true); // shane.xie 20140725 for detect hp plugin in USB
	        }
	        else
	        {
			if(FPI_LINEIN_CDTV == linein || FPI_LINEIN_TDTV == linein)
			{
				/*add this by wangtexin for the change linein
				when dtv close ,it will term the DTV driver,
				and if MHEG call any av function when drvier close
				it will brack down, the better way is the dtv driver
				can do better,but now we mend it by this*/
#ifdef MHEG5_ENABLED
				fpi_mheg_isDtvDriverStart(fpi_true);
#endif
				tvhoad_start_manager();
				tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_VIDEO_ACTION),
					 E_TVH_VIDEO_MSG_CHANGE_SRC, linein, s_previous_linein);
			}
			else if(FPI_LINEIN_CATV == linein || FPI_LINEIN_TATV == linein)
			{
				fpi_channel_atv_play_snowflake_check();
				tvhoad_stop_manager();
			}
			else
			{
				fpi_bool bmute = fpi_true;
				fpi_video_mute_config_t st_mute= {fpi_false, EN_VIDEO_MUTE_PLAY};
				fpi_video_get_mute_state(EN_VIDEO_MUTE_PLAY, &bmute);
				if(bmute)
				{
					fpi_video_mute(&st_mute);
				}
				tvhoad_stop_manager();
			}
		}

		fpi_cec_routing_change(fpi_linein_get_previous(),s_current_linein);

#ifdef FPI_CIPLUS
		//信源切换成功后，通知CI信源改变
		tvh_ci_notify_linein_change(s_current_linein);
#endif
		
		if(s_current_linein == FPI_LINEIN_STORAGE)
		{		
			fpi_trace("app_input_source,ttx_stop\n");
			fpi_ttx_off();
			fpi_ttx_stop();
		}
		else
		{
			fpi_printf("app_input_source,ttx_reset\n");	
			fpi_ttx_off();
			fpi_ttx_reset();
		}

	//    #ifdef SCART_ENABLE
		if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
		{
			tvh_scart_notify_linein_change(s_current_linein);
		}
	//    #endif

	}
	else
	{
		fpi_alarm("linein_open_, linein=0x%x, FPI_ERROR_LINEIN_FAILED!!!\n",linein);
		fpi_linein_t previousLinein= fpi_linein_get_previous();
		if(FPI_LINEIN_STORAGE != previousLinein && FPI_LINEIN_KTV != previousLinein)
		{
			tvhsignal_start_manager(previousLinein);
		}
	}
    
	fpi_common_set_common_thread_enable(fpi_true); 

	os_mutex_release(fpi_linein_get_change_linein_mutex());
	fpi_linein_set_changing_status(fpi_false);
	fpi_info("exit %s\n",__FUNCTION__);
	return error;
}
	

static fpi_error 	tvh_linein_open_atv(fpi_linein_t linein)
{
 	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_atv_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_atv_out_mute()) ;	

	fpi_info("fpp_linein_open_atv\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open atv success\n");
	}
	fpi_channel_atv_set_play_type(E_ATV_PLAY_LINEIN_CH);
	return error;
}

static fpi_error 	tvh_linein_open_dtv(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_dtv_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_dtv_out_mute()) ; 
	fpi_info("fpp_linein_open_dtv\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open dtv success\n");
	}
	fpi_demod_set_active(E_FPI_DTV_STREAM_PORT_0, (fpi_dtv_delivery_type_t)db_dtv_get_route(), fpi_true);
	fpi_dtv_set_scart_out_mode(SCART_OUT_MODE_FRONT);
	return error;
}

static fpi_error 	tvh_linein_open_cvbs(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ; 

	fpi_info("fpp_linein_open_cvbs\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open cvbs success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_svideo(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_av_out_mute()) ; 

	fpi_info("fpp_linein_open_svideo\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open svideo success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_comp(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_cmp_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_cmp_out_mute()) ; 

	fpi_info("fpp_linein_open_component\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open comp success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_pc(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_vga_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_vga_out_mute()) ; 
	fpi_info("fpp_linein_open_pc\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open pc success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_hdmi(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_hdmi_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_hdmi_out_mute()) ; 

	fpi_info("fpp_linein_open_hdmi\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open hdmi success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_scart(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_scart_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_scart_out_mute()) ; 
	
#ifdef SUBTITLE_ENABLED
	fpi_program_set_sbt_enable_monitor(fpi_true);
#endif
	fpi_info("fpi_linein_open_scart\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open scart success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_storge(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ; 

	fpi_info("fpp_linein_open_STORAGE\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open storge success\n");
	}
	return error;
}

static fpi_error 	tvh_linein_open_ktv(fpi_linein_t linein)
{
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;
	fpi_video_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ;
	fpi_audio_out_mute_output(EN_AV_OUT_MUTE_LINEIN,uti_config_get_mm_out_mute()) ; 

	fpi_info("fpp_linein_open_ktv\n");
	error = fpi_linein_open(linein);
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpi_linein_open ktv success\n");
	}
	return error;

}




static void tvh_linein_changeto_success(fpi_linein_t linein,fpi_linein_t before_linein)
{
	fpi_info("Enter %s,line = %d,linein = 0x%x\n",__FUNCTION__,__LINE__,linein);
		
        fpi_audio_set_track(linein,EN_FPI_AUDIO_TRACK_STEREO);
        fpi_zoom_reset_level();
	 fpi_audio_spdif_delay_sync();
        
	if(fpi_common_get_first_time_input_finish_status() == fpi_true)
	{
		EN_PICTURE_SIZE enPictureSize;
		fpi_bool bAutoFormat;
		int32_t val=0;
		ZOOM_VIEW_MODE enPictureView;
		//fpi_zoom_set_small_window_state(fpi_false);

		val = app_get_pic_mode_element(E_PIC_MODE_PIC_SIZE);
		enPictureSize = (EN_PICTURE_SIZE)val;
		val = app_get_pic_mode_element(E_PIC_MODE_AUTO_FORMAT);
		bAutoFormat = val;
		if(enPictureSize == E_AR_AUTO)
		{
			bAutoFormat=fpi_true;
		}

		val = app_get_pic_mode_element(E_PIC_MODE_PIC_VIEW);
		enPictureView = (ZOOM_VIEW_MODE)val;			
		fpi_zoom_set_mode(enPictureSize, enPictureView);
		
		fpi_zoom_set_auto_format(bAutoFormat);
		if((FPI_LINEIN_CATV == linein) || (FPI_LINEIN_TATV == linein))
		{
			fpi_zoom_refresh_current(E_ZOOM_REFRESH_MUTE);
		}

        
	        if(FPI_LINEIN_STORAGE == linein || FPI_LINEIN_KTV == linein)
	        {
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.sync",fpi_false);
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.scart",fpi_false);
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.chgchannel",fpi_false);

			tvhoad_stop_manager();
			linein_av_unmute(linein);

			fpi_video_update(fpi_false, FPI_LINEIN_STORAGE);
	            //fpi_common_set_common_thread_enable(fpi_true); // shane.xie 20140725 for detect hp plugin in USB
	        }
       	 else
	        {
			if(FPI_LINEIN_CDTV == linein || FPI_LINEIN_TDTV == linein)
			{
				/*add this by wangtexin for the change linein
				when dtv close ,it will term the DTV driver,
				and if MHEG call any av function when drvier close
				it will brack down, the better way is the dtv driver
				can do better,but now we mend it by this*/
		            
#ifdef MHEG5_ENABLED
				fpi_mheg_isDtvDriverStart(fpi_true);
#endif
				tvhoad_start_manager();
			}
			else if(FPI_LINEIN_CATV == linein || FPI_LINEIN_TATV == linein)
			{
				fpi_channel_atv_play_snowflake_check();
				tvhoad_stop_manager();
			}
			else
			{
				fpi_bool bmute = fpi_true;
				fpi_video_mute_config_t st_mute= {fpi_false, EN_VIDEO_MUTE_PLAY};
				fpi_video_get_mute_state(EN_VIDEO_MUTE_PLAY, &bmute);
				if(bmute)
				{
					fpi_video_mute(&st_mute);
				}
	                
				tvhoad_stop_manager();
			}
		}

		fpi_cec_routing_change(fpi_linein_get_previous(),s_current_linein);
#ifdef FPI_CIPLUS
		//信源切换成功后，通知CI信源改变
		tvh_ci_notify_linein_change(s_current_linein);
#endif

		if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
		{
			tvh_scart_notify_linein_change(s_current_linein);
		}
		/*
		if(linein==FPI_LINEIN_STORAGE||s_previous_linein==FPI_LINEIN_STORAGE)
			fpi_video_update_memc_value(0,MEMC_DELAY_TIMER_USB);
		else
			fpi_video_update_memc_value(0,MEMC_DELAY_TIMER_NORMAL);
		*/
	}
    
	fpi_common_set_common_thread_enable(fpi_true); 
	

	fpi_info("Exit %s,line = %d\n",__FUNCTION__,__LINE__);
	
}

static void tvh_linein_changeto_failed(fpi_linein_t linein,fpi_linein_t before_linein)
{
			
	fpi_linein_t previousLinein= fpi_linein_get_previous();
	if(FPI_LINEIN_STORAGE != previousLinein && FPI_LINEIN_KTV != previousLinein)
	{
		tvhsignal_start_manager(previousLinein);
	}

	fpi_common_set_common_thread_enable(fpi_true); 

	if((FPI_LINEIN_CATV != linein) && (FPI_LINEIN_TATV != linein))
	{     
		fpi_audio_set_mts_thread_detect_enable(fpi_false);
	}
}


//void tvh_linein_mngr_proc(TVHMGR_Message_t *message)
void fpi_linein_mngr_proc(uint32_t msg_type,uint32_t param1,uint32_t param2)
{       
    switch(msg_type)
    {
    	
        case E_TVH_LINEIN_MSG_CHANGETO_BEFORE:
			fpi_video_update_sport_enhance(param1,MEMC_DELAY_TIMER_USB);

			{//ct 2014.5.6 set 3d mode to none when change input source
           		    int32_t en3dtype = FPI_3D_NONE;
		           fpi_get_current_3d_mode(&en3dtype);  
		           fpi_trace("ct test .... 3d = %d\r\n",en3dtype);
		       
		           if(en3dtype > FPI_3D_NONE)
		           {
		               fpi_set_3d_mode(FPI_3D_NONE);
		           }
       		}
			
			 _linein_scart_out_finish(param1);
			break;
		case E_TVH_LINEIN_MSG_CLOSE:
			{
				
			        fpi_bool bmute = fpi_true;
			        fpi_video_mute_config_t st_mute= {fpi_false, EN_VIDEO_MUTE_APP};
			        fpi_video_get_mute_state(EN_VIDEO_MUTE_APP, &bmute);
			        if(bmute)
			        {
			            fpi_video_mute(&st_mute);
			        }
			}
			break;
		case E_TVH_LINEIN_MSG_CHANGETO_SUCCESS:
			tvh_linein_changeto_success(param1,param2);
			break;
		case E_TVH_LINEIN_MSG_CHANGETO_FAILED:
			tvh_linein_changeto_failed(param1,param2);
			break;
		
		default:
			break;
    }
}
void app_souce_send_message(TVH_LINEIN_ObjectMsgType_t type,int arg1,int art2);

fpi_error fpi_linein_changeto_v2(	fpi_linein_t linein )
{

	fpi_error error = FPI_ERROR_LINEIN_FAIL;
	if(FPI_LINEIN_INVALID == linein)
	{
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"FPI_LINEIN_INVALID\n");
		return FPI_ERROR_LINEIN_FAIL;
	}   
    
	fpi_info("enter fpi_linein_changeto_v2, current_linein=0x%x ,target_linein to=0x%x\n",s_current_linein,linein);

	if(linein == FPI_LINEIN_TDTV)
	{
		linein = FPI_LINEIN_CDTV;
	}
	if(linein == s_current_linein)
	{
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"target_linein == current_linein ,no need change,return\n");
		return FPI_ERROR_LINEIN_INVALID_PARAMETER;
	}
	
	fpi_audio_set_mts_thread_detect_enable(fpi_false);
	fpi_common_set_common_thread_enable(fpi_false);
	_linein_mute_previous(linein);
	
	//   tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_LINEIN_ACTION),
	//	E_TVH_LINEIN_MSG_CHANGETO_BEFORE, linein, s_current_linein);	
	app_souce_send_message(E_TVH_LINEIN_MSG_CHANGETO_BEFORE, linein, s_current_linein);

	_linein_close_previous(linein);
	s_previous_linein = s_current_linein; 
    
//	tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_LINEIN_ACTION),
//		E_TVH_LINEIN_MSG_CLOSE, linein, s_previous_linein);
	app_souce_send_message(E_TVH_LINEIN_MSG_CLOSE, linein, s_previous_linein);

	//打开对应的信源,打开信源后会进入信号检测的routine状态
	 if(FPI_LINEIN_STORAGE != linein && FPI_LINEIN_KTV != linein)
	 {
	  	tvhsignal_start_manager(linein);
	 }
				
	if( (FPI_LINEIN_ATV_ALL&linein) != 0 )				error=tvh_linein_open_atv(linein);
	else if( (FPI_LINEIN_DTV_ALL&linein) != 0 ) 			error=tvh_linein_open_dtv(linein);
	else if( (FPI_LINEIN_CVBS_ALL&linein) != 0 )			error=tvh_linein_open_cvbs(linein);
	else if( (FPI_LINEIN_SVIDEO_ALL&linein) != 0 )		error=tvh_linein_open_svideo(linein);
	else if( (FPI_LINEIN_COMPONENT_ALL&linein) != 0 )	error=tvh_linein_open_comp(linein);
	else if( (FPI_LINEIN_PC_ALL&linein) != 0 )			error=tvh_linein_open_pc(linein);
	else if( (FPI_LINEIN_HDMI_ALL&linein) != 0 )			error=tvh_linein_open_hdmi(linein);
	else if( (FPI_LINEIN_SCART_ALL&linein) != 0 )		error=tvh_linein_open_scart(linein);
	else if( (FPI_LINEIN_STORAGE&linein) != 0 )			error=tvh_linein_open_storge(linein);
	else if( (FPI_LINEIN_KTV&linein) != 0 )				error=tvh_linein_open_ktv(linein);
	else
	{
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"INVALID_PARAMETER,linein=%d\n",linein );
		error= FPI_ERROR_LINEIN_INVALID_PARAMETER;
	}

	//切换完信源的其它事情在消息里面执行
	if( error == FPI_ERROR_LINEIN_SUCCESS)
	{
		s_current_linein = linein;
		fpi_set_target_linein(linein);
 //   tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_LINEIN_ACTION), 
//		E_TVH_LINEIN_MSG_CHANGETO_SUCCESS, s_current_linein, s_previous_linein);
		app_souce_send_message(E_TVH_LINEIN_MSG_CHANGETO_SUCCESS, s_current_linein, s_previous_linein);	
	}
	else
	{   
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"tvh_linein_open fail,linein=%d\n",linein );
   // tvhmgr_send_message_ex(tvhmgr_get_handle_by_objid(E_TVHMGR_CHILD_OBJECTID_LINEIN_ACTION),
//		E_TVH_LINEIN_MSG_CHANGETO_FAILED, s_current_linein, s_previous_linein);
		app_souce_send_message(E_TVH_LINEIN_MSG_CHANGETO_FAILED, s_current_linein, s_previous_linein);
	}

	fpi_info("Exit fpi_linein_changeto_v2\n");
	
    return error;
}

/******************************************************************************
*Function: fpi_linein_get_current
*Description: 得到当前的信源号
*Input: 无
*Output: p_linein : 现在的信源
*Return: 是否得到信源
*Others:
******************************************************************************/
fpi_error fpi_linein_get_current(fpi_linein_t *p_linein)
{
	//    *p_linein = fpp_get_current_linein();  //mstar 自己增加的获取当前信源没有多媒体接口，故先注释掉
	//    fpi_trace("current linein=%d\n", *p_linein );
	//    if ( *p_linein == FPI_LINEIN_INVALID)
	{
		*p_linein = s_current_linein ;
	//fpi_trace("s_current_linein linein=%d\n", s_current_linein );
	//     return FPI_ERROR_FAIL ;
	}
      return FPI_ERROR_LINEIN_SUCCESS ;
}


/******************************************************************************
*Function: fpi_linein_get_previous
*Description: 获取上一次信源值
*Input:     NONE
*Output:    NONE
*Return:    上一次信源值，若上一次信源值为无效，则返回ATV
*Others:
******************************************************************************/
fpi_linein_t fpi_linein_get_previous(void)
{
	if(FPI_LINEIN_INVALID != s_previous_linein)
	{
		return s_previous_linein;
	}
	else
	{
		return FPI_LINEIN_CATV;
	}
}


/******************************************************************************
*Function: fpi_linein_video_freeze
*Description: 冻结此时的视频图像
*Input:  b_freeze 是否要冻结图像
*Output: 无
*Return: 是否支持冻结图像
*Others:
******************************************************************************/
/* //此接口以及没有使用了。
static fpi_bool g_freeze_state ;
fpi_error fpi_linein_video_freeze(fpi_bool b_freeze)
{
    if( (s_current_linein == FPI_LINEIN_CDTV) || (s_current_linein == FPI_LINEIN_TDTV) )
    {
        fpp_dtv_video_set_freeze(b_freeze);
        g_freeze_state = b_freeze ;
    }
	return FPI_ERROR_SUCCESS;
}

fpi_bool fpi_linein_get_freeze_state( void )
{
    return g_freeze_state ;
}
*/

fpi_error fpi_dtv_get_video_status(   fpi_bool *status )
{
	*status = fpi_true ; //应该有更好的办法，除了subtitel，现在这个函数没有其它地方使用。
	// fpp_dtv_get_video_status(status ) ;
	return FPI_ERROR_SUCCESS ;
}

fpi_error fpi_linein_src_insert_check(fpi_linein_t linein_current, fpi_bool *is_src_insert)
{
	fpi_error ret = FPI_ERROR_FAIL;
	EN_FPP_LINEIN_SRC_STATUS_T  un8src_insert ;
	fpi_trace("src_insert_check fpi_linein_src_insert_check, linein_current = %x\n", linein_current);
	//ret = fpp_linein_src_insert_check(linein_current, is_src_insert);
	ret= fpp_linein_src_insert_check((EN_FPP_LINEIN_TYPE_T)linein_current, &un8src_insert);
	if( un8src_insert == EN_FPP_LINEIN_LOCK )
	{
		*is_src_insert = fpi_true;
	}
	else
	{
		*is_src_insert = fpi_false ;
	}

	fpi_trace("src_insert_check fpi_linein_src_insert_check, is_insert = %d,ret = %d\n", un8src_insert,ret);
	return ret;
}

static EN_CURVE_SOURCE _linein_init_curve_source_revert(fpi_linein_t linein)
{
	EN_CURVE_SOURCE curve_src = E_SOURCE_DTV;
	switch(linein)
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			curve_src = E_SOURCE_ATV;
			break;  
		case FPI_LINEIN_CDTV:
		case FPI_LINEIN_TDTV:
			curve_src = E_SOURCE_DTV;
			break; 
		case FPI_LINEIN_SCART1:
		case FPI_LINEIN_SCART2:
		case FPI_LINEIN_SVIDEO1:
		case FPI_LINEIN_SVIDEO2:
			curve_src = E_SOURCE_AV1;
			break; 
		case FPI_LINEIN_CVBS1:
		case FPI_LINEIN_CVBS2:
		case FPI_LINEIN_CVBS3:
		case FPI_LINEIN_CVBS4:
			curve_src = E_SOURCE_AV2;
			break; 
		case FPI_LINEIN_COMPONENT1:
		case FPI_LINEIN_COMPONENT2:
		case FPI_LINEIN_COMPONENT3:
		case FPI_LINEIN_COMPONENT4:
			curve_src = E_SOURCE_YPbPr2;
			break; 
		case FPI_LINEIN_PC1:
		case FPI_LINEIN_PC2:
			curve_src = E_SOURCE_VGA;
			break; 
		case FPI_LINEIN_HDMI1:
			curve_src = E_SOURCE_HDMI1;
			break; 
		case FPI_LINEIN_HDMI2:
			curve_src = E_SOURCE_HDMI2;
			break; 
		case FPI_LINEIN_HDMI3:
		case FPI_LINEIN_HDMI4:
			curve_src = E_SOURCE_HDMI3;
			break; 
		case FPI_LINEIN_STORAGE:
		case FPI_LINEIN_KTV:
			curve_src = E_SOURCE_ATV;
			break;		
		default:
			curve_src = E_SOURCE_ATV;
			break;
	} 
	return curve_src;
}
    
static void _linein_init_children_lock(fpi_linein_t linein)
{
	//儿童锁
	fpi_video_mute_config_t mute_config;
	fpi_bool children_lock = db_get_children_lock();
	fpi_audio_common_config_t p_config;    
	memset(&p_config,0,sizeof(p_config)); 
	memset(&mute_config, 0, sizeof(fpi_video_mute_config_t));

	if( children_lock == fpi_true )
	{
	        mute_config.b_mute = fpi_true ;
	        mute_config.e_level = EN_VIDEO_MUTE_CHILDREN_LOCK ;
	        if(FPI_ERROR_SUCCESS != fpi_video_mute( &mute_config ))
	        {
	            fpi_err("fpi_linein_init , mute video error!\n");
	        }
        
		fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.childlock",fpi_true);
	}
}


static void _linein_init_backlight_process(fpi_linein_t linein)
{
	USR_STBC_DATA usr_stb_data;
	fpi_file_write_read_setting file_setting;
	//fpi_bool b_state = fpi_true;

	memset(&usr_stb_data,0,sizeof(USR_STBC_DATA));
	memset(&file_setting, 0, sizeof(fpi_file_write_read_setting));
	memcpy(file_setting.f_path, USR_STBC_BIN, strlen(USR_STBC_BIN));
	memcpy(file_setting.p_path, USR_STBC_DATA_PATH, strlen(USR_STBC_DATA_PATH));
	file_setting.ui1_len = sizeof(USR_STBC_DATA);
	if(FPI_ERROR_SUCCESS == fpi_factory_read_data_from_file(&file_setting))
	{
		memcpy(&usr_stb_data, file_setting.p_buf, sizeof(USR_STBC_DATA));
		//b_state = (usr_stb_data.BacklightOnFlag == BACKLIGHT_ON) ? fpi_true : fpi_false;
	}

	if(BACKLIGHT_OFF == usr_stb_data.BacklightOnFlag)
	{
	        POWER_WAKEUP_SOURCE_e   wakeup_src = POWER_WAKEUPSRC_NONE;

	        fpi_power_get_wakeup_source(&wakeup_src);
	        if (POWER_WAKEUPSRC_RTC2 == wakeup_src)
	        {
			//当自动开机黑屏模式时静音
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL, (char*)"tos.standby.record",fpi_true);
			fpi_info("function = %s, line = %d, close backlight for standby recording!\n",__FUNCTION__,__LINE__);
	        }
		else
		{
			//b_state = fpi_true;//modified by yanmh 2014/11/13
		}
	}

	//fpi_power_set_backlight(&b_state);
	
	return ;
}

#if 0
static void _linein_init_zoom(fpi_linein_t linein)
{
	//en_result ret=db_false;	
  //  fpi_pic_setting pic_setting_info={0};
    fpi_bool bAutoFormat = fpi_false;
    uint8_t Overscan = 1;
  //  int32_t val=0;
    EN_PICTURE_SIZE picSize = E_AR_16x9;
    ZOOM_VIEW_MODE picView = ZOOM_VIEW_NORMAL;
    
    if((FPI_LINEIN_INVALID == linein) || ((-1) == linein))
    {
        fpi_zoom_init(fpi_false, fpi_true, E_AR_16x9, ZOOM_VIEW_NORMAL);
    }
    else
    {
    #if 0
    if(E_HONGKONG != db_get_system_country())
    {
		fpi_get_pic_mode_element((E_PIC_MODE_ELEM)E_PIC_MODE_PIC_SIZE,&val);
		picSize=(EN_PICTURE_SIZE)val;
		fpi_get_pic_mode_element((E_PIC_MODE_ELEM)E_PIC_MODE_AUTO_FORMAT,&val);
		bAutoFormat=val;
		picView=(ZOOM_VIEW_MODE)fpi_get_video_overscan_enable();
    }
	#endif
	
		fpi_zoom_get_database_picSize(linein, &picSize, &picView, &bAutoFormat);
	
		if(E_HONGKONG == db_get_system_country() || E_CHINA == db_get_system_country())
	    {
	      	if(picSize == E_AR_AUTO)
				bAutoFormat=fpi_true;
			else
				bAutoFormat=fpi_false;
		}


    	fpi_info("[_linein_init_zoom] auto-%d, overscan-%d, pisSize-%d, pisView-%d, linein-%d\n",bAutoFormat, Overscan, picSize, picView, linein);
    	fpi_zoom_init(bAutoFormat, Overscan, picSize, picView);
    }
    //    fpi_zoom_set_mode(pic_setting_info.enPictureSize, pic_setting_info.u8PictureView);
}
#endif
static void _linein_init_audio_init_pre(fpi_linein_t linein)
{
	fpi_sound_setting sound_setting;
	memset(&sound_setting,0,sizeof(fpi_sound_setting));
	PRINTF_RUN_TIME("_linein_init_audio_init_pre.c, statr\n");

	db_get_sound_setting(&sound_setting,(EN_VIDEO_DB_TYPE)fpi_get_mapped_linein(STORAGE_BY_NOTHING));

	//audio scene power on init
	if(FPI_ERROR_FAIL== fpi_audio_set_scene(sound_setting.audioScene))
	{
		DEBUG_LINEIN("_linein_init_audio_init fpi_audio_set_scene fail\n");
	}
	
	{//set sound mode
		fpi_equalizer_setting_t equalizer_setting;
		memset(&equalizer_setting,0,sizeof(fpi_equalizer_setting_t));
		equalizer_setting.un8_band_equalizer[0] = sound_setting.st5BalanceData[sound_setting.enSoundPreset].i8Balance100 ;
		equalizer_setting.un8_band_equalizer[1] = sound_setting.st5BalanceData[sound_setting.enSoundPreset].i8Balance300;
		equalizer_setting.un8_band_equalizer[2] = sound_setting.st5BalanceData[sound_setting.enSoundPreset].i8Balance1K;
		equalizer_setting.un8_band_equalizer[3] = sound_setting.st5BalanceData[sound_setting.enSoundPreset].i8Balance3K;
		equalizer_setting.un8_band_equalizer[4] = sound_setting.st5BalanceData[sound_setting.enSoundPreset].i8Balance10K;
		
		equalizer_setting.n32_audio_source = linein ;
	//add by @hh
	#if 0		
		if((FactoryHotelSetting.m_ModelEnabled) &&(FactoryHotelSetting.m_autoSetEnabled))
		{
			sound_setting.enSoundPreset = FactoryHotelSetting.m_soundMod;
		}
	#endif		
	//end by @hh
		equalizer_setting.un8_audio_mode = sound_setting.enSoundPreset;
		equalizer_setting.un8_count = FPI_AUDIO_EQUALIZER_COUNT ;
		equalizer_setting.un8_length = sizeof(fpi_equalizer_setting_t) ;

		fpi_audio_set_equalizer( &equalizer_setting );
	}
	
	//auto volume control power on init
	{
		fpi_audio_common_config_t audio;
		audio.n32_audio_source = linein;
		audio.b_enable = sound_setting.bAutoVolumeControl;
		fpi_audio_enable_avl(&audio); 
	}
		
	//refresh the tcl sound effect ctrl status to audio dsp
	fpi_audio_set_dsp_algorithm(EN_FPI_AUDIO_DSP_INTELLIGENT_VOLUME,sound_setting.bAutoVolumeControl);
	fpi_audio_set_dsp_algorithm(EN_FPI_AUDIO_DSP_VIRTUAL_BASS,sound_setting.bVirtualBass);
	//sound spdif power on init
	{
		EN_SPDIF_TYPE spdif_type = (EN_SPDIF_TYPE)db_get_spdif_type();
		DEBUG_LINEIN("_linein_init_audio_init, spdif= %d\n", spdif_type);
		if( fpi_audio_set_SPDIF_type(spdif_type) != FPI_ERROR_SUCCESS)
		{
			fpi_warn("ERROR:%s\n",__FUNCTION__) ;
		}
	}
	// srs thsd init	   
	DEBUG_LINEIN("_linein_init_audio_init.c, audio power on init u8WideStereo = %d\n", sound_setting.u8WideStereo);
	fpi_audio_set_stereo((AUDIO_STEREO_TYPE)sound_setting.u8WideStereo);
	
	
	//added by luhm 2014.10.13 for IR4005 CN 
	//sound balance power on init
	DEBUG_LINEIN("function = %s, use_balance=%d\n", __FUNCTION__,sound_setting.s8Balance);
	{
		fpi_audio_balance_t t_balance;
		memset(&t_balance,0,sizeof(t_balance));
	
		t_balance.n8_balance = sound_setting.s8Balance;
		fpi_audio_set_balance_ex(EN_AUDIO_DEVICE_TYPE_MAIN,&t_balance);
	
		t_balance.n8_balance = sound_setting.s8HpBalance;
		fpi_audio_set_balance_ex(EN_AUDIO_DEVICE_TYPE_HEADPHONE,&t_balance);
	}
	
		
		
		
	if(fpi_audio_get_ms12_enable() == fpi_true)
	{
		fpi_audio_set_ms12_DAP_status((fpi_bool)sound_setting.u16SPOnOff);
	}
	//sound mode power on init
	PRINTF_RUN_TIME("_linein_init_audio_init_pre.c end\n");
}

static void _linein_init_audio_init(fpi_linein_t linein)   //audio 开机初始化
{
	DEBUG_LINEIN("_linein_init_audio_init enter\n");

	fpi_sound_setting sound_setting;
	fpi_sound_setting sound_setting_source;

	memset(&sound_setting,0,sizeof(fpi_sound_setting));
	memset(&sound_setting_source,0,sizeof(sound_setting_source));

	db_get_sound_setting(&sound_setting,(EN_VIDEO_DB_TYPE)fpi_get_mapped_linein(STORAGE_BY_NOTHING));
	db_get_sound_setting(&sound_setting_source,(EN_VIDEO_DB_TYPE)fpi_get_mapped_linein(STORAGE_BY_SOURCE));

	if( (E_HONGKONG == app_get_db_system_country() )||( E_CHINA == app_get_db_system_country()) )//uti_config_get_area已经停用
	{

	}
	else
	{
		//取消区域信息，EU,AU，init more   		
		if(sound_setting.u16SPOnOff == EN_FPI_AUDIO_OUTPUT_OFF)//sound_setting.u16SpeakerMixType == EN_FPI_AUDIO_CHANNEL_OFF|| 
		{
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_MAIN,(char*) "app.ui.sk",fpi_true);
		}

		if( sound_setting.u16HPOnOff == EN_FPI_AUDIO_OUTPUT_OFF)//sound_setting.u16HPMixType == EN_FPI_AUDIO_CHANNEL_OFF ||
		{
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_HEADPHONE,(char*) "app.ui.hp",fpi_true);
		}

		if( fpi_audio_set_SPDIF_delay(sound_setting_source.spdifDelay) != FPI_ERROR_SUCCESS)
		{
		    fpi_warn("ERROR:%s fpi_audio_set_SPDIF_delay \n",__FUNCTION__) ;
		}

		if(fpi_audio_set_ddp(sound_setting.bSpdifDdpEnable) != FPI_ERROR_SUCCESS)
		{
		    fpi_warn("ERROR:%s fpi_audio_set_ddp\n",__FUNCTION__) ;
		}	
			
		fpi_audio_set_headphone_option(sound_setting.audioSpeakerEnable?E_HP_SPEAKER:E_HP_ONLY);				
		//added by luhm 2014.10.13 for IR4005 CN 	

		if(db_get_current_linein() & FPI_LINEIN_DTV_ALL)
		{
			if((sound_setting.u16SpeakerMixType != EN_FPI_AUDIO_CHANNEL_OFF) || (sound_setting.u16HPMixType != EN_FPI_AUDIO_CHANNEL_OFF))
			{
				fpi_audio_set_output_device_mix_type(EN_AUDIO_DEVICE_TYPE_MAIN,sound_setting.u16SpeakerMixType);
			}
	     	}
		DEBUG_LINEIN("_linein_init_audio_init.c, audio power on init AudioDescription = %d\n", sound_setting.VisualImpaired.AudioDescription);

		if(sound_setting.VisualImpaired.AudioDescription)
		{
			DEBUG_LINEIN("_linein_init_audio_init.c, audio power on init MixingLevel = %d\n", sound_setting.VisualImpaired.MixingLevel);
			if( fpi_audio_set_AD_volume(sound_setting.VisualImpaired.MixingLevel) != FPI_ERROR_SUCCESS)
			{
				fpi_warn("ERROR:%s\n",__FUNCTION__) ;
			}
		}
	}

	{// set volume
		fpi_audio_volume_t st_volume;
		fpi_service_user_nonlinear_curve st_curve;
		EN_AUDIO_INPUT_TYPE en_input_type = EN_AUDIO_INPUT_TYPE_MAIN;

		if(sound_setting.Volume > 100)
			sound_setting.Volume = 100;

		if(!db_get_factory_sound_curve_setting(&st_curve,_linein_init_curve_source_revert(linein)))
		{
			db_get_factory_sound_curve_setting(&st_curve, E_SOURCE_ATV);
		}
        
		st_volume.un8_volume_curve[0] = st_curve.u8OSD_0 ; 
		st_volume.un8_volume_curve[1] = st_curve.u8OSD_25 ; 
		st_volume.un8_volume_curve[2] = st_curve.u8OSD_50 ; 
		st_volume.un8_volume_curve[3] = st_curve.u8OSD_75 ; 
		st_volume.un8_volume_curve[4] = st_curve.u8OSD_100 ; 

		st_volume.un8_length = 5;
		st_volume.n32_audio_source = linein;

		{
			st_volume.un8_volume = sound_setting.Volume;
			if(FPI_ERROR_SUCCESS != fpi_set_volume_for_device(EN_AUDIO_DEVICE_TYPE_MAIN,en_input_type,&st_volume)) 
			{
				fpi_err("_linein_init_audio_init, set speaker audio volume error!!\n");
			}

			st_volume.un8_volume = sound_setting.u8HpVolume;
			if(FPI_ERROR_SUCCESS != fpi_set_volume_for_device(EN_AUDIO_DEVICE_TYPE_HEADPHONE,en_input_type,&st_volume))
			{
				fpi_err("_linein_init_audio_init, set headphone audio volume error!!\n");
			}

			st_volume.un8_volume = sound_setting.u8BluetoothVolume;
			if(FPI_ERROR_SUCCESS != fpi_set_volume_for_device(EN_AUDIO_DEVICE_TYPE_CAPTURE,en_input_type,&st_volume))
			{
				fpi_err("[_linein_init_audio_init] set bluetooth audio volume error!!\n");
			}
		    
			//SPDIF volume curve table 不设置会导致底层最终设到硬件的Gain值为0,导致spdif无声
			st_volume.un8_volume = sound_setting.u8SpdifVolume;
			if(FPI_ERROR_SUCCESS != fpi_set_volume_for_device(EN_AUDIO_DEVICE_TYPE_SPDIF,en_input_type,&st_volume))
			{
				fpi_err("_linein_init_audio_init, set spdif audio volume error!!\n");
			}

			st_volume.un8_volume = sound_setting.Volume;
			if(FPI_ERROR_SUCCESS != fpi_set_volume_for_device(EN_AUDIO_DEVICE_TYPE_AVOUT,en_input_type,&st_volume)) 
			{
				fpi_err("_linein_init_audio_init, set speaker audio volume error!!\n");
			}
		}
    }
    DEBUG_LINEIN("_linein_init_audio_init end\n");
}



static fpi_bool _linein_init_get_lock_state(fpi_linein_t linein)
{
	fpi_bool ret = fpi_false;
	fpi_input_source_lock input_source_lock;

	//MEMBER_COUNTRY country = db_get_system_country();

	memset(&input_source_lock, 0, sizeof(fpi_input_source_lock));
	db_get_input_source_lock_setting( &input_source_lock);  
	switch(linein)
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			ret = input_source_lock.inputSourceAtvLock;
			break;
		case FPI_LINEIN_CDTV:
		case FPI_LINEIN_TDTV:
			ret = input_source_lock.inputSourceDtvLock;
			break;
		case FPI_LINEIN_CVBS1:
			ret = input_source_lock.inputSourceAvILock;
			break;
		case FPI_LINEIN_CVBS2:
			ret = input_source_lock.inputSourceAvIILock;
			break;
		case FPI_LINEIN_COMPONENT1:
			ret = input_source_lock.inputSourceYPBPRLock;
			break;
		case FPI_LINEIN_PC1:
			ret = input_source_lock.inputSourcePCLock;
			break;
		case FPI_LINEIN_HDMI1:
			ret = input_source_lock.inputSourceHDMIILock;
			break;
		case FPI_LINEIN_HDMI2:
			ret = input_source_lock.inputSourceHDMIIILock;
			break;
		case FPI_LINEIN_HDMI3:
			ret = input_source_lock.inputSourceHDMIIIILock;
			break;
		case FPI_LINEIN_SCART1:
			ret = input_source_lock.inputSourceScartLock;
			break;
		case FPI_LINEIN_HDMI4:
			ret = input_source_lock.inputSourceHDMI4Lock;
			break;
		default:
		break;            
	}

	return ret;    
}

static void _linein_init_lock_mute(fpi_linein_t linein)
{
	fpi_audio_common_config_t p_config;  
	fpi_video_mute_config_t st_mute;
	memset(&p_config,0,sizeof(fpi_audio_common_config_t)); 
	memset(&st_mute,0,sizeof(fpi_video_mute_config_t)); 

	//audio mute
	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.lock",fpi_true);

    
	//video mute
	st_mute.b_mute = fpi_true;
	st_mute.e_level = EN_VIDEO_MUTE_LOCK;
	fpi_video_mute(&st_mute);
    
	switch(linein)
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			{
			//        #ifdef SCART_ENABLE
			fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_LOCK); 
			//        #endif
			// app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_INPUT_BLOCK, EN_ATV);
			break;
			}
		default:
			// app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_INPUT_BLOCK, 0);
			break;
	}
}

static void _linein_init_ttx_reset(fpi_linein_t linein)
{
	//teletext part will be changed 
	//   app_teletext_off();
	//   fpi_teletext_reset();
}

static void _linein_init_av_mute(fpi_linein_t linein)
{
	fpi_video_mute_config_t st_mute = {fpi_true, EN_VIDEO_MUTE_SYNC};
    
	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.sync",fpi_true);
	fpi_video_mute(&st_mute);
}
static void _linein_init_play(fpi_linein_t linein)
{
	if(_linein_init_get_lock_state(linein))
	{
		_linein_init_lock_mute(linein);
	}
	//add by @hh
#if 0
	fpi_factory_hotel_setting FactoryHotelSetting;
	db_get_factory_hotel_setting(&FactoryHotelSetting);		
	uint16_t current_program_num;
#endif
	//end by @hh
	if((linein==FPI_LINEIN_CDTV) || (linein==FPI_LINEIN_TDTV))
	{
		fpi_dtv_play_by_power_on(0,linein);		
	}
	else
	{ 
		if( linein == FPI_LINEIN_CATV || linein == FPI_LINEIN_TATV )
		{
			//add by @hh
			#if 0
			if(FactoryHotelSetting.m_ModelEnabled)
			{
				db_atv_get_current_program(&current_program_num);
				current_program_num = (uint16_t)FactoryHotelSetting.m_PowerAtvCh;
				db_atv_set_current_program(current_program_num);
			}
			#endif
			//end by @hh			
		
			/*加锁 dtv切换到atv需要发送 EN_ATV EN_SS_COMMON_VIDEO 通知*/// shane.xie 20131014 add
			if(!_linein_init_get_lock_state(linein))
			{
			//  app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, EN_ATV);
			}
			fpi_channel_atv_play_current_program();
			// app_channel_atv_play_current_program();
		}
	}
        
}


//#ifdef SCART_ENABLE
static void _linein_scart_out_av_mute(void)
{
	fpi_video_mute_config_t st_mute = {fpi_true, EN_VIDEO_MUTE_SCART};
    
	fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.scart",fpi_true);
	
	fpi_video_mute(&st_mute);

}

static void _linein_recovery_scart_out(void)
{
	//get scart out source linein
	fpi_linein_t u32ScartOutLinein;
	u32ScartOutLinein = db_get_scart_out_linein();
	if(u32ScartOutLinein!=FPI_LINEIN_CDTV&&u32ScartOutLinein!=FPI_LINEIN_TDTV
		&&u32ScartOutLinein!=FPI_LINEIN_CATV&&u32ScartOutLinein!=FPI_LINEIN_TATV)
	{
		//DTV for default
		u32ScartOutLinein = FPI_LINEIN_CDTV;
	}
    
	if(FPI_ERROR_LINEIN_SUCCESS == fpi_linein_changeto(u32ScartOutLinein))
	{
		DEBUG_LINEIN("function = %s, line = %d, set tv input to 0x%08x\n",__FUNCTION__,__LINE__,u32ScartOutLinein);
		fpi_common_set_first_time_input_finish_status(fpi_true);
		_linein_scart_out_av_mute();
		_linein_init_play(u32ScartOutLinein);
		db_set_current_linein(u32ScartOutLinein, u32ScartOutLinein);

		#if 0        
		if(u32ScartOutLinein == FPI_LINEIN_CDTV || u32ScartOutLinein == FPI_LINEIN_TDTV)
		{
			//delay 1.5s,make sure that dtv has played
			os_msleep(1500);
			//av mute of dtv is managered by itself,so when change linein from dtv to another,should umute av managered by dtv
			fpi_audio_common_config_t stAudioconfig = {0, fpi_false, AUDIO_MUTE_CHANGE_CHANNEL}; 
			fpi_video_mute_config_t st_mute = {fpi_false,EN_VIDEO_MUTE_PLAY};       
			fpi_audio_mute(&stAudioconfig);
			fpi_video_mute(&st_mute);

		}
		#else
		if(u32ScartOutLinein == FPI_LINEIN_CDTV || u32ScartOutLinein == FPI_LINEIN_TDTV)
		{
			//delay 3s,make sure that dtv(include 1080i) has played
			os_msleep(3000);        
			//av mute of dtv is managered by itself,so when change linein from dtv to another,should umute av managered by dtv
			fpi_video_mute_config_t st_mute = {fpi_false,EN_VIDEO_MUTE_PLAY};       
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*) "tos.chgchannel",fpi_false);
			fpi_video_mute(&st_mute);        
		}
		else if(u32ScartOutLinein == FPI_LINEIN_CATV || u32ScartOutLinein == FPI_LINEIN_TATV)
		{
			fpi_video_mute_config_t st_mute = {fpi_false,EN_VIDEO_MUTE_PLAY};       
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"tos.chgchannel",fpi_false);

			fpi_video_mute(&st_mute);
		}
    		#endif

	}
                
}
//#endif

static void _linein_init_check_power_on_channel(void)
{
	EN_FPP_POWER_WAKEUP_SOURCE_T wakeup_src = POWER_WAKEUPSRC_NONE;
	UN_FPP_POWER_WAKEUP_PARAM param;
	uint8_t delivery_type = 0;
	uint16_t dtv_count=0,atv_count=0,play_num=-1;
	uint32_t last_service_type = 0;
	en_result ret;
	EN_MEMBER_SERVICETYPE service_type = EN_SERVICETYPE_INVALID;
	fpi_linein_t input = FPI_LINEIN_INVALID, last_input = FPI_LINEIN_INVALID;

	//fpi_power_get_wakeup_source(&wakeup_src);
	if(FPI_ERROR_NOT_IMPLEMENT == fpp_power_get_poweron_source(&wakeup_src, &param))
	{
	    fpp_power_get_wakeup_source(&wakeup_src);
	}

	play_num = param.un16IR;

	fpi_info("_linein_init_check_power_on_channel, play_num =%d\n",param.un16IR); 
	switch(wakeup_src)
	{
		case EN_FPP_PM_WAKEUPSRC_DIGITAL_KEY:
			if((0 < play_num) && (play_num < 10))
			{
				delivery_type = db_dtv_get_route();
				ret = db_dtv_get_all_channel_count(&dtv_count,delivery_type,EN_SERVICETYPE_INVALID);
				atv_count = db_atv_get_channel_count_by_turner(delivery_type);
				if(ret == db_false)
				{
					dtv_count = 0;
				}
				//get last Tv Source and change to
				last_service_type = db_get_lastest_service_type();

				if(last_service_type == EN_SERVICETYPE_ATV)
				{
					input = FPI_LINEIN_CATV;
				}
				else
				{
					input = FPI_LINEIN_CDTV;
				}
				
				fpi_info("channel num power on, play_num =%d, dtv_count= %d, atv_count=%d\n",play_num,dtv_count,atv_count);	

				if(dtv_count > 0 || atv_count > 0)
				{
					ST_DVB_MUX_INFO mux_info = {0};
					fpi_channel_info_t channel_info = {0};
			
					if (db_dtv_get_mux_info_by_type_num_opt(&mux_info, EN_SERVICETYPE_DTV, 
																play_num, E_EXCLUDE_NOT_VISIBLE_AND_DELETED))
					{
						fpi_info("find a valid channel,DTV\n");
			
						db_set_lastest_service_type(EN_SERVICETYPE_DTV);
						db_dtv_set_current_program(EN_SERVICETYPE_DTV, play_num, fpi_false);						
						app_user_setting_set_last_service_type( EN_SERVICETYPE_DTV);
						//change linein to DTV
						input = FPI_LINEIN_CDTV;
					}
					else if (db_dtv_get_mux_info_by_type_num_opt(&mux_info, EN_SERVICETYPE_RADIO, 
																play_num, E_EXCLUDE_NOT_VISIBLE_AND_DELETED))
					{
						fpi_info("find a valid channel,Radio\n");
			
						db_set_lastest_service_type(EN_SERVICETYPE_RADIO);
						db_dtv_set_current_program(EN_SERVICETYPE_RADIO, play_num, fpi_false);
						app_user_setting_set_last_service_type( EN_SERVICETYPE_RADIO);
						//change linein to DTV
						input = FPI_LINEIN_CDTV;
					}					
					else if(db_atv_get_proginfo_by_num(&channel_info, play_num))
					{
						fpi_info("find a valid channel,ATV, num = %d,%d\n", channel_info.program_no,play_num);				
			
						db_set_lastest_service_type(service_type);
						db_atv_set_current_program(play_num);	
						app_user_setting_set_last_service_type( service_type);
						//change linein to ATV
						input = FPI_LINEIN_CATV;
					}
				}
				else
				{
			
					fpi_info("channel num power on, all of atv and dtv lists are empty");
				}
								
				last_input = db_get_current_linein();
				db_set_lastest_linein(input);
				db_set_current_linein(input, last_input);
				
			}
			else
			{
				DEBUG_LINEIN("_linein_init_check_power_on_channel, play_index is illegal!!");
			}

			break;
		case EN_FPP_PM_WAKEUPSRC_RTC2:
			if (1 == db_get_channel_power_on_channel_select_mode())
			{
				power_on_channel powerOnChannel = {0};

				
				fpi_info("power on channel mode is user select\n");
				db_get_power_on_channel(&powerOnChannel);        
				service_type = (EN_MEMBER_SERVICETYPE)powerOnChannel.serviceType;
				if (EN_SERVICETYPE_ATV != service_type)
				{
					ST_DVB_MUX_INFO mux_info = {0};
					//fpi_dtv_delivery_type_t delivery_type = E_FPI_DTV_DELIVERY_TYPE_INVALID;

					if (db_dtv_get_mux_info_by_type_num_opt(&mux_info, (uint8_t)powerOnChannel.serviceType, 
								(uint16_t)powerOnChannel.num, E_EXCLUDE_NOT_VISIBLE_AND_DELETED))
					{
						fpi_info("find a valid power on channel,DTV\n");
						//delivery_type = (fpi_dtv_delivery_type_t)mux_info.u8DtvRoute;
						input = (fpi_linein_t)FPI_LINEIN_CDTV;
						last_input = db_get_current_linein();
						db_set_lastest_linein(input);//起机之后目的信源也切为要播的信源
						db_set_current_linein(input, last_input);
						db_set_lastest_service_type(service_type);
						db_dtv_set_current_program((uint8_t)powerOnChannel.serviceType, (uint16_t)powerOnChannel.num, fpi_false);
						app_user_setting_set_last_service_type( service_type);
					}
				}
				else
				{
					fpi_channel_info_t channel_info = {0};
					
					if (db_atv_get_proginfo_by_num(&channel_info, powerOnChannel.num))
					{
						fpi_info("find a valid power on channel,ATV, num = %d,%d\n", channel_info.program_no, powerOnChannel.num);                
						input = FPI_LINEIN_CATV;
						last_input = db_get_current_linein();
						db_set_lastest_linein(input);
						db_set_current_linein(input, last_input);
						db_set_lastest_service_type(service_type);
						db_atv_set_current_program(powerOnChannel.num);
						app_user_setting_set_last_service_type( service_type);
					}
				}
			}
			else
			{
				fpi_trace("power channel mode is last status\n");
			}
			break;
		default:
			fpi_info("not number wakeup mode and do not change channel \n");
			break;
	}
		
	 
}

/******************************************************************************
*Function: fpi_itv_platform_isItv
*Description: 判断当前是否在ITV中
*Input:     NONE
*Output:    NONE
*Return:    FPI_ERROR_SUCCESS - 表示表示当前在ITV中
                FPI_ERROR_FAIL - 表示不在ITV中
*Others:
******************************************************************************/
fpi_error fpi_itv_platform_isItv(fpi_bool *status)
{
	if(itv_platform_isItv())
	{
		*status = fpi_true ;
		return FPI_ERROR_SUCCESS;
	}
	else
	{
		*status = fpi_false;
		return FPI_ERROR_FAIL;
	}
}

/******************************************************************************
*Function: fpi_itv_platform_offItv
*Description: 释放ITV资源
*Input:     NONE
*Output:    NONE
*Return:    FPI_ERROR_SUCCESS - 表示操作成功
                FPI_ERROR_FAIL - 表示操作失败
*Others:
******************************************************************************/
fpi_error fpi_itv_platform_offItv(fpi_bool *status)
{
	if(itv_platform_offItv())
	{
		*status = fpi_true ;
		return FPI_ERROR_SUCCESS;
	}
	else
	{
		*status = fpi_false;
		return FPI_ERROR_FAIL;
	}

}


fpi_error fpi_linein_netflix_changeto(fpi_linein_t input)//input is last input source
{
	int boot_source = 0;
	//fpi_linein_t lastInput = FPI_LINEIN_INVALID;
	DEBUG_LINEIN("pre_s \n");

	extern int get_netflix_key_boot_flag(void);
	boot_source = get_netflix_key_boot_flag();
	fpi_info("%s boot_source = %d, input=%d \n", __FUNCTION__, boot_source, input);
	if(boot_source == EN_FPP_PM_WAKEUPSRC_NETFLIX)
	{
		//switch & mute.
		if(FPI_ERROR_LINEIN_SUCCESS == fpi_linein_changeto(FPI_LINEIN_STORAGE))
		{
			db_set_current_linein(FPI_LINEIN_STORAGE,FPI_LINEIN_STORAGE);
		}
	
		DEBUG_LINEIN("pre_nflx");
		
		int fd = -1;
		fd = open(BOOT_WAKEUP_FLAG_FILE, O_WRONLY|O_CREAT);
		write(fd, "netflix_boot", strlen("netflix_boot"));
		close(fd);
		
		return FPI_ERROR_SUCCESS;
		
	}
	else
	{
		sita_property_set("app.ui.netflix.boot", "false");		
		return FPI_ERROR_FAIL;  
	}
	
	return FPI_ERROR_FAIL; 
}

fpi_error fpi_edid_init(void)
{
	// init hdmi edid ver
    {
        EN_VIDEO_DB_TYPE db_line_in[4] = {E_VIDEO_DB_HDMI1, E_VIDEO_DB_HDMI2, E_VIDEO_DB_HDMI3, E_VIDEO_DB_HDMI4};
        fpi_linein_t line_in[4] = {FPI_LINEIN_HDMI1, FPI_LINEIN_HDMI2, FPI_LINEIN_HDMI3, FPI_LINEIN_HDMI4};
        int32_t i;
        int32_t hdmi_ver;

        for(i = 0; i < 4; ++i)
        {
            hdmi_ver = 0xff;
            hdmi_ver = db_get_hdmi_version(db_line_in[i]);
            if(hdmi_ver != 0xff)
            {
                fpi_input_set_hdmi_edid_ver(line_in[i], hdmi_ver);
            }
			else
			{
				fpi_err("fpi_edid_init, need not init hdmi[%d]!", i);
			}
        }
    }
	return FPI_ERROR_SUCCESS;
	
}


/******************************************************************************
*Function: fpi_linein_init
*Description: FPI中对信源的初始化。原来开机过程中信源切换由app完成，但因android系统中app启动比较慢，
            所以修改为由FPI中间件来进行信源方面的初始化处理
*Input:     none
*Output:    none
*Return:   FPI_ERROR_FAIL--中间件中信源初始化失败，
           FPI_ERROR_SUCCESS--中间件中信源初始化成功
*Others:
******************************************************************************/
fpi_error fpi_linein_init(void)
{
	bool bNetflix = false;
	fpi_linein_t input = FPI_LINEIN_INVALID;
	linein_init_by_mid= LINEIN_INIT_BY_MID_ING;
	//uint32_t handle;

	if(OS_MUTEX_INVALID_ID == change_linein_mux)
		change_linein_mux = os_mutex_create((char*)"change_linein_mux");

	fpi_trace("%s  start \n",__FUNCTION__ );
	add_linein_test( ) ;
	// if(tvhmgr_create_object(E_TVHMGR_CHILD_OBJECTID_LINEIN_ACTION, E_TVHMGR_OBJECT_TYPE_CHILD, tvh_linein_mngr_proc, &handle)!=FPI_ERROR_SUCCESS)
    	{
  		//      fpi_err_code(FPI_ERROR_LINEIN_NOT_INITIALIZED,"tvhmgr_create linein object error\n");
        
    	}
	//set power on channel
	_linein_init_check_power_on_channel();

    
	//add by @hh
#if 0	
	//input = db_get_current_linein();
	fpi_factory_hotel_setting FactoryHotelSetting;
	db_get_factory_hotel_setting(&FactoryHotelSetting);
#endif
	//end by @hh
	if(!strcmp(sita_property_get(BOOT_SOURCE_KEY,"0"),"11")){
		input = FPI_LINEIN_STORAGE;
		db_set_current_linein(input, input);
		fpi_info("fpi_linein_init, FPI_LINEIN_STORAGE\n");
	}
	else
	{
		
		{
			input = db_get_current_linein(); 

		}//end by @hh
		
		//input = db_get_current_linein(); 

		fpi_info("fpi_linein_init, input:%x\n",input);
		    
		//如果获取用户设置失败，就通知由app再次进行信源切换操作；
		if((FPI_LINEIN_INVALID == input) || ((-1) == input))
		{
			fpi_info("fpi_linein_init, db not init\n");
			linein_init_by_mid= LINEIN_INIT_BY_MID_DB_NO_INIT;
			input = FPI_LINEIN_CDTV;
			if(FPI_ERROR_LINEIN_SUCCESS != fpi_linein_changeto(input))
			{
				linein_init_by_mid= LINEIN_INIT_BY_MID_FAILED;
			}
			//_linein_init_zoom(input);
			else
			{
				db_set_current_linein(input,input);
			}
			fpi_common_set_first_time_input_finish_status(fpi_true);
			if(sys_cfg_get_func_enable(FUNC_CFG_BOOT_VIDEO))
			{
				fpi_info("fpi_linein_init,EN_COMPLETED_AD\n");
				tvh_boot_video_set_completed_state(EN_COMPLETED_AD);
			}
			return FPI_ERROR_FAIL; 
		}
		fpi_linein_init_zoom();
		/*add for netflix */
		extern int get_netflix_key_boot_flag(void);
		if((sys_cfg_get_func_enable(FUNC_CFG_NETFLIX) == fpi_true) && get_netflix_key_boot_flag() == EN_FPP_PM_WAKEUPSRC_NETFLIX)
		{
			 bNetflix = true;
		}
		
		 //   printf("@@[fpi_linein_init] input:%x storage = %x \n",input,FPI_LINEIN_STORAGE);

		if(FPI_LINEIN_STORAGE == input || FPI_LINEIN_KTV== input)
		{        
			input = db_get_lastest_linein();
			fpi_info("fpi_linein_init, last input = %x \n",input);
			if(FPI_LINEIN_INVALID == input)
			{
				input = FPI_LINEIN_CDTV;
			}
			db_set_current_linein(input, input);
		}

		if(!bNetflix)
		{		 	
			//#ifdef SCART_ENABLE
			if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
			{
				///fix bug(EU_6139),if pin8 high,should change to scart
				fpi_scart_system_on_detect();
				fpi_linein_t new_linein = fpi_scart_get_linein_by_pin8_level();
				if(FPI_LINEIN_INVALID != new_linein)
				{
					db_set_lastest_linein(input);
					db_set_current_linein(new_linein, input);
					input = new_linein; 
					fpi_info("function = %s, line = %d, linein changed from 0x%x to 0x%x by scart pin8!\n",__FUNCTION__,__LINE__,input,new_linein);
				}

				//fix the bug,when TV boot up at TV_source,scart out is abnormal
				DEBUG_LINEIN("function = %s, when start up,mute scart out(LINEIN/GEN) \n",__FUNCTION__);
				fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_GEN);
				fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_LINEIN);

				//if TV start up without tv_source,should change to tv source to enalbe scart out
				if(input!=FPI_LINEIN_CDTV && input != FPI_LINEIN_TDTV &&
				input!=FPI_LINEIN_CATV && input != FPI_LINEIN_TATV )
				{
					DEBUG_LINEIN("function = %s, TV start up without tv,should change to tv and enable scart out\n",__FUNCTION__);
					_linein_recovery_scart_out();
				}  
			}
		//#endif   
		}
	}
	//_linein_init_zoom(input);
	fpi_set_target_linein(input);
	_linein_init_av_mute(input);
	_linein_init_backlight_process(input);    

	if(!bNetflix)
	{
		if(FPI_ERROR_LINEIN_SUCCESS != fpi_linein_changeto(input))
		{
		    linein_init_by_mid= LINEIN_INIT_BY_MID_FAILED;
		    fpi_common_set_first_time_input_finish_status(fpi_true);
		    return FPI_ERROR_FAIL; 
		}
		db_set_current_linein(input,input);
	}
	else
	{
		fpi_linein_netflix_changeto(input);
	}
    
	_linein_init_audio_init(input);
	_linein_init_ttx_reset(input);
   // _linein_init_video_init(input);
   
	if(!bNetflix)
	{
		_linein_init_children_lock(input);
		_linein_init_play(input);
	}

	fpi_info("fpi_linein_init finished! \n");
	fpi_common_set_first_time_input_finish_status(fpi_true);
	linein_init_by_mid= LINEIN_INIT_BY_MID_SUCCESSED;    
	return FPI_ERROR_SUCCESS; 
}


/******************************************************************************
*Function: fpi_linein_get_mid_initlinein_status
*Description: 获取中间件中信源初始化状态
*Input: none
*Output:    *status 中间件初始化的状态值，包括LINEIN_INIT_BY_MID_NONE、LINEIN_INIT_BY_MID_ING
            LINEIN_INIT_BY_MID_FAILED、 LINEIN_INIT_BY_MID_SUCCESSED                           
*Return:    FPI_ERROR_SUCCESS-- 成功的获取状态
*Others:
******************************************************************************/
fpi_error fpi_linein_get_mid_initlinein_status(LINEIN_INIT_BY_MID_TYPE *status)
{
	*status = linein_init_by_mid;
	return FPI_ERROR_SUCCESS; 
}


os_mutex_handle_t fpi_linein_get_change_linein_mutex(void)
{
	return change_linein_mux;
}

  /******************************************************************************
  *Function: fpi_map_linein_to_input_src
  *Description: 
  *Input: 
  *Output: none
  *Return: 
  *Others: none
  ******************************************************************************/
  EN_INPUT_SOURCE_TYPE fpi_map_linein_to_input_src(uint32_t u32LineIn)
  {
	EN_INPUT_SOURCE_TYPE input_src_type=E_INPUT_SOURCE_NONE;
	switch(u32LineIn)
	{
		case FPI_LINEIN_CATV:
			input_src_type = E_INPUT_SOURCE_CATV;
			break;
		case FPI_LINEIN_TATV:
			input_src_type = E_INPUT_SOURCE_TATV;
			break;
		case FPI_LINEIN_CDTV:
			input_src_type = E_INPUT_SOURCE_CDTV;
			break;
		case FPI_LINEIN_TDTV:
			input_src_type = E_INPUT_SOURCE_TDTV;
			break;
		case FPI_LINEIN_CVBS1:
			input_src_type = E_INPUT_SOURCE_CVBS1;
			break;
		case FPI_LINEIN_CVBS2:
			input_src_type = E_INPUT_SOURCE_CVBS2;
			break;
		case FPI_LINEIN_CVBS3:
			input_src_type = E_INPUT_SOURCE_CVBS3;
			break;
		case FPI_LINEIN_CVBS4:
			input_src_type = E_INPUT_SOURCE_CVBS4;
			break;
		case FPI_LINEIN_SVIDEO1:
			input_src_type = E_INPUT_SOURCE_SVIDEO1;
			break;
		case FPI_LINEIN_SVIDEO2:
			input_src_type = E_INPUT_SOURCE_SVIDEO2;
			break;
		case FPI_LINEIN_COMPONENT1:
			input_src_type = E_INPUT_SOURCE_YPBPR1;
			break;
		case FPI_LINEIN_COMPONENT2:
			input_src_type = E_INPUT_SOURCE_YPBPR2;
			break;
		case FPI_LINEIN_COMPONENT3:
			input_src_type = E_INPUT_SOURCE_YPBPR3;
			break;
		case FPI_LINEIN_COMPONENT4:
			input_src_type = E_INPUT_SOURCE_YPBPR4;
			break;
		case FPI_LINEIN_PC1:
			input_src_type = E_INPUT_SOURCE_PC1;
			break;
		case FPI_LINEIN_PC2:
			input_src_type = E_INPUT_SOURCE_PC2;
			break;
		case FPI_LINEIN_HDMI1:
			input_src_type = E_INPUT_SOURCE_HDMI1;
			break;
		case FPI_LINEIN_HDMI2:
			input_src_type = E_INPUT_SOURCE_HDMI2;
			break;
		case FPI_LINEIN_HDMI3:
			input_src_type = E_INPUT_SOURCE_HDMI3;
			break;
		case FPI_LINEIN_HDMI4:
			input_src_type = E_INPUT_SOURCE_HDMI4;
			break;		  
		case FPI_LINEIN_SCART1:
			input_src_type = E_INPUT_SOURCE_SCART;
			break;
		case FPI_LINEIN_SCART2:
			input_src_type = E_INPUT_SOURCE_SCART2;
			break;
		case FPI_LINEIN_STORAGE:
		case FPI_LINEIN_KTV:
			input_src_type = E_INPUT_SOURCE_STORAGE;
			break;
		default:			 
			break;
	}

	return input_src_type;
  }

EN_INPUT_SOURCE_TYPE fpi_get_mapped_linein(LINEIN_AUDIO_STORAGE_TYPE e_storage_type)
{
	uint32_t src_type = 0;
	EN_INPUT_SOURCE_TYPE enSrcDb = E_INPUT_SOURCE_CATV;

	if(e_storage_type == STORAGE_BY_SOURCE)
	{
		fpi_linein_get_current(&src_type);
		enSrcDb=fpi_map_linein_to_input_src(src_type); //kevin.L0610
	}

	return enSrcDb;
}

void fpi_set_target_linein(fpi_linein_t linein)
{
	s_target_source = linein;
}

fpi_linein_t fpi_get_target_linein()
{
	return s_target_source;
}
fpi_error fpi_input_set_hdmi_edid_ver(fpi_linein_t linein, int32_t ver)
{
	EN_FPP_SYETEM_HDMI_VERSION_T version;
	char section[20] = "HDMI_EDID_1";
	char key[20] = "HDMI_EDID_File_1_4";
	char buf[2][128] = {{0}, {0}};
	char *address[2];

	switch(linein)
	{
		case FPI_LINEIN_HDMI1:
			{
				//section[10] = '1';
			}
			break;
		case FPI_LINEIN_HDMI2:
			{
				section[10] = '2';
			}
			break;
		case FPI_LINEIN_HDMI3:
			{
				section[10] = '3';
			}
			break;
		case FPI_LINEIN_HDMI4:
			{
				section[10] = '4';
			}
			break;
		default:
			{
				//section[10] = '1';
			}
			break;
	}

	switch(ver)
	{
		case E_HDMI_EDID_AUTO:
			{
				version = EN_SYSTEM_HDMI_VERSION_AUTO;
			}
			break;
		case E_HDMI_EDID_V1_4:
			{
				version = EN_SYSTEM_HDMI_VERSION_14;
			}
			break;
		case E_HDMI_EDID_V2_0:
			{
				version = EN_SYSTEM_HDMI_VERSION_20;
				key[15] = '2';
				key[17] = '0';
			}
			break;
		default:
			{
				fpi_info(" version error, ver = %d \n", ver);
				return FPI_ERROR_FAIL;
			}
			break;
	}
	sys_cfg_get_string(e_model_ini, section, key, buf[0], 128);
	if(EN_SYSTEM_HDMI_VERSION_AUTO == version)
	{
		key[15] = '2';
		key[17] = '0';
		sys_cfg_get_string(e_model_ini, section, key, buf[1], 128);
	}
	address[0] = buf[0];
	address[1] = buf[1];
	fpi_info("fpi_input_set_hdmi_edid_ver, lin = 0x%x, ver = %d, addr = %s \n", linein, version, buf[0]);
	return fpp_system_set_hdmi_version(linein, version, address);
}

static void test_linein( unsigned char *u8Para )
{
	if(u8Para[0]==0xff)
	{
		fpi_info("./dbm linein [current_linein(1<<N)] \n");
		fpi_info("FPI_LINEIN_CATV=0\n" );
		fpi_info("FPI_LINEIN_TATV=1\n" );
		fpi_info("FPI_LINEIN_CDTV=2\n" );
		fpi_info("FPI_LINEIN_TDTV=3\n" );
		fpi_info("FPI_LINEIN_CVBS1=4\n" );
		fpi_info("FPI_LINEIN_CVBS2=5\n" );
		fpi_info("FPI_LINEIN_CVBS3=6\n" );
		fpi_info("FPI_LINEIN_CVBS4=7\n" );
		fpi_info("FPI_LINEIN_SVIDEO1=8\n" );
		fpi_info("FPI_LINEIN_SVIDEO2=9\n" );
		fpi_info("FPI_LINEIN_COMPONENT1=10\n" );
		fpi_info("FPI_LINEIN_COMPONENT2=11\n" );
		fpi_info("FPI_LINEIN_COMPONENT3=12\n" );
		fpi_info("FPI_LINEIN_COMPONENT4=13\n" );
		fpi_info("FPI_LINEIN_PC1=14\n" );
		fpi_info("FPI_LINEIN_PC2=15\n" );
		fpi_info("FPI_LINEIN_HDMI1=16\n" );
		fpi_info("FPI_LINEIN_HDMI2=17\n" );
		fpi_info("FPI_LINEIN_HDMI3=18\n" );
		fpi_info("FPI_LINEIN_HDMI4=19\n" );
		fpi_info("FPI_LINEIN_SCART1=20\n" );
		fpi_info("FPI_LINEIN_SCART2=21\n" );
		fpi_info("FPI_LINEIN_STORAGE=22\n" );
	}
	else
	{
		fpi_linein_t CurrentInputSource = FPI_LINEIN_INVALID;
		fpi_linein_get_current(&CurrentInputSource);
		fpi_info("curSrc = 0x%x ,u8Para[0] = 0x%x\n",  CurrentInputSource, u8Para[0]);  
		CurrentInputSource = 0x1;
		CurrentInputSource <<=u8Para[0] ;
		fpi_info("%s CurrentInputSource = %d\n", __FUNCTION__, CurrentInputSource);
		fpi_linein_changeto(CurrentInputSource ) ;
	}
}
void add_linein_test( void )
{    
	ADD_TEST("changeto", test_linein ) ;
}

void fpi_linein_init_zoom(void)
{
	fpi_bool bAutoFormat = fpi_false;
	uint8_t Overscan = 1;
	EN_PICTURE_SIZE picSize = E_AR_16x9;
	uint8_t picView = 1;

	picSize = (EN_PICTURE_SIZE) fpi_zoom_get_db_param(E_PIC_MODE_PIC_SIZE);
	bAutoFormat = fpi_zoom_get_db_param(E_PIC_MODE_AUTO_FORMAT);
	picView=fpi_zoom_get_db_param(E_PIC_MODE_PIC_VIEW);

	Overscan = picView; 
	if(E_HONGKONG == db_get_system_country() || E_CHINA == db_get_system_country())
	{
		if(picSize == E_AR_AUTO)
		{
			bAutoFormat = fpi_true;
		}
		else
		{
			bAutoFormat = fpi_false;
		}
	}

	u8_timing_distinguish = sys_cfg_get_integer(e_overscan_ini, "TIMING_DISTINGUISH", "TIMING_FUN_DISTINGUISH",0);


	fpi_trace("[fpi_linein_init_zoom] auto-%d, overscan-%d, pisSize-%d, pisView-%d,u8_timing_distinguish-%d\n",bAutoFormat, Overscan, picSize, (ZOOM_VIEW_MODE)picView,u8_timing_distinguish);
	fpi_zoom_init(bAutoFormat, Overscan, picSize, (ZOOM_VIEW_MODE)picView);

}

uint8_t fpi_get_timing_distinguish_state(void)
{
	return u8_timing_distinguish;
}

fpi_error fpi_linein_init_pre(void)
{
	bool bNetflix = false;
	fpi_linein_t input = FPI_LINEIN_INVALID;
	linein_init_by_mid= LINEIN_INIT_BY_MID_ING;
	//uint32_t handle;
	PRINTF_RUN_TIME("fpi_linein_init_pre start");

	if(OS_MUTEX_INVALID_ID == change_linein_mux)
		change_linein_mux = os_mutex_create((char*)"change_linein_mux");

	fpi_trace("%s  start \n",__FUNCTION__ );
	add_linein_test( ) ;

	//set power on channel
	_linein_init_check_power_on_channel();

	if(!strcmp(sita_property_get(BOOT_SOURCE_KEY,"0"),"11")){
	   input = FPI_LINEIN_STORAGE;
	   db_set_current_linein(input, input);
	   fpi_info("fpi_linein_init_pre, FPI_LINEIN_STORAGE\n");
	}
	else
	{
		input = db_get_current_linein(); 
		
		fpi_info("fpi_linein_init_pre, input:%x\n",input);


		//如果获取用户设置失败，就通知由app再次进行信源切换操作；
		if((FPI_LINEIN_INVALID == input) || ((-1) == input))
		{
			fpi_info("fpi_linein_init_late, db not init\n");
			linein_init_by_mid= LINEIN_INIT_BY_MID_DB_NO_INIT;
			input = FPI_LINEIN_CDTV;			
			db_set_current_linein(input,input);					
		}
		    
		fpi_linein_init_zoom();
		/*add for netflix */
		extern int get_netflix_key_boot_flag(void);
		if((sys_cfg_get_func_enable(FUNC_CFG_NETFLIX) == fpi_true) && get_netflix_key_boot_flag() == EN_FPP_PM_WAKEUPSRC_NETFLIX)
		{
			 bNetflix = true;
		}
		
		 //   printf("@@[fpi_linein_init] input:%x storage = %x \n",input,FPI_LINEIN_STORAGE);

		if(FPI_LINEIN_STORAGE == input || FPI_LINEIN_KTV== input)
		{        
			input = db_get_lastest_linein();
			fpi_info("fpi_linein_init_pre, last input = %x \n",input);
			if(FPI_LINEIN_INVALID == input)
			{
				input = FPI_LINEIN_CDTV;
			}
			db_set_current_linein(input, input);
		}

		if(!bNetflix)
		{		 	
			if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
			{
				///fix bug(EU_6139),if pin8 high,should change to scart
				fpi_scart_system_on_detect();
				fpi_linein_t new_linein = fpi_scart_get_linein_by_pin8_level();
				if(FPI_LINEIN_INVALID != new_linein)
				{
					db_set_lastest_linein(input);
					db_set_current_linein(new_linein, input);
					input = new_linein; 
					fpi_info("function = %s, line = %d, linein changed from 0x%x to 0x%x by scart pin8!\n",__FUNCTION__,__LINE__,input,new_linein);
				}
 
			} 
		}
	}
	fpi_set_target_linein(input);
	 _linein_init_backlight_process(input); 
	if((input==FPI_LINEIN_CDTV) || (input==FPI_LINEIN_TDTV))
	{
		//demod pre 切信源判断如果是开机视频 且当前信源为DTV 则屏蔽掉此功能
		fpi_demod_set_active(E_FPI_DTV_STREAM_PORT_0, (fpi_dtv_delivery_type_t)db_dtv_get_route(), fpi_true);
		uint8_t service_type;
		uint16_t current_program_num;
		fpi_bool bOpService=db_dtv_get_cur_channel_type();
		
		if(db_dtv_get_current_program(&service_type, &current_program_num,bOpService) == db_true)
		{
			if(CI_PROGRAM_NUMBER == current_program_num)
			{
				fpi_channel_dtv_play_prepare_program(fpi_false);
			}
			else
			{
				fpi_channel_dtv_play_prepare_program(fpi_true);
			}
	    }

	}
	_linein_init_audio_init_pre(input);
	fpi_info("fpi_linein_init_pre finished! \n");
	PRINTF_RUN_TIME("fpi_linein_init_pre end");	
	return FPI_ERROR_SUCCESS; 

}

fpi_error fpi_linein_init_post(void)
{
	fpi_linein_t input = FPI_LINEIN_INVALID;
	bool bNetflix = false;	
	//uint8_t state;
	PRINTF_RUN_TIME("fpi_linein_init_late start");
	fpi_info("fpi_linein_init_late start! \n");
	input = db_get_current_linein(); 

    _linein_init_av_mute(input); 

    extern int get_netflix_key_boot_flag(void);
    if((sys_cfg_get_func_enable(FUNC_CFG_NETFLIX) == fpi_true) && get_netflix_key_boot_flag() == EN_FPP_PM_WAKEUPSRC_NETFLIX)
    {
 		bNetflix = true;
    }
 
 	if(!bNetflix)
 	{
 		if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
 		{
 			//fix the bug,when TV boot up at TV_source,scart out is abnormal
 			DEBUG_LINEIN("function = %s, when start up,mute scart out(LINEIN/GEN) \n",__FUNCTION__);
 			fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_GEN);
 			fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_LINEIN);
 
 			//if TV start up without tv_source,should change to tv source to enalbe scart out
 			if(input!=FPI_LINEIN_CDTV && input != FPI_LINEIN_TDTV &&
 			input!=FPI_LINEIN_CATV && input != FPI_LINEIN_TATV )
 			{
 				DEBUG_LINEIN("function = %s, TV start up without tv,should change to tv and enable scart out\n",__FUNCTION__);
 				_linein_recovery_scart_out();
 			} 
 		}
 		
 		if(FPI_ERROR_LINEIN_SUCCESS != fpi_linein_changeto(input))
 		{
 		    linein_init_by_mid= LINEIN_INIT_BY_MID_FAILED;
 		    fpi_common_set_first_time_input_finish_status(fpi_true);
 		    return FPI_ERROR_FAIL; 
 		}
 		db_set_current_linein(input,input);
 	}
 	else
 	{
 		fpi_linein_netflix_changeto(input);
 	}
	    
		_linein_init_audio_init(input);
		//_linein_init_ttx_reset(input);
	   // _linein_init_video_init(input);
	   // dtv_source_for_bootvideo = fpi_false;
		if(!bNetflix)
		{
			_linein_init_children_lock(input);
			_linein_init_play(input);
		}

		fpi_info("fpi_linein_init_late finished! \n");
		fpi_common_set_first_time_input_finish_status(fpi_true);
		linein_init_by_mid= LINEIN_INIT_BY_MID_SUCCESSED;  
		
		PRINTF_RUN_TIME("fpi_linein_init_late end");
		return FPI_ERROR_SUCCESS; 
}


fpi_error 	fpi_linein_open(fpi_linein_t open_linein)
{
	fpi_info("fpi_linein_open start,current_open_linein = %x,open_linein = %x\n",current_open_linein,open_linein);
	fpi_error error = FPI_ERROR_LINEIN_SUCCESS;

	if(current_open_linein!=open_linein)
	{
		fpi_info("fpp_linein_open start\n");
	    error = fpp_linein_open((EN_FPP_LINEIN_TYPE_T)open_linein, (EN_FPP_LINEIN_TYPE_T)current_open_linein);
	}
	if( error != FPI_ERROR_LINEIN_SUCCESS )
	{
		fpi_err_code(FPI_ERROR_LINEIN_SOC_ABNORMAL,"fpp driver return error=%d\n",error ) ;
	}
	else
	{
		fpi_info("fpp_linein_open atv success\n");
        current_open_linein = open_linein;
	}


	return error;
	
}
