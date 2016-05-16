#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "fpi_debug_helper.h"

#include "fpi_linein.h"
#include "fpi_teletext.h"
#include "app_user_setting.h"
#include "app_input_source.h"
#include "app_channel_manager.h"
#include "app_channel_dtv_play.h"
#include "app_channel_atv_play.h"
#include "app_audio.h"
#include "app_video.h"
#include "fpi_notify_event.h"
#include "app_msg_manager.h"
#include "app_teletext.h"
#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)
#include "app_hbbtv.h"
#endif
#include "app_3d.h"

#ifdef FPI_CIPLUS
#include "fpi_ci.h"
#include "db_dtv.h"
#endif
#include "db_user_setting.h"
#include "fpi_zoom.h"

#include "fpi_scart.h"
#include "fpi_pvr.h"
#include "app_power.h"
#include "app_signal.h"
#include "os.h"
#include "app_channel_dtv_scan.h"
#include "fpi_program_play_subtitle.h"
#include "uti_config.h"
#include "app_common.h"
#include "app_factory.h"
#include "app_channel.h"
#include "tvh_mngr.h"
#include "tos_input_source.h"

SET_MODEL_ID(SITA_MODULE_LINEIN);

#define APP_INPUT_SOURCE_TRACE(fmt, arg...)       	fpi_trace(fmt, ##arg)
#define APP_INPUT_SOURCE_INFO(fmt, arg...)       	fpi_info(fmt, ##arg)
#define APP_INPUT_SOURCE_ALARM(fmt, arg...)       	fpi_alarm(fmt, ##arg)

/********************************************************************************/
#define INPUT_LOCK_ATV      	0x0001
#define INPUT_LOCK_DTV      	0x0002
#define INPUT_LOCK_AV1      	0x0004
#define INPUT_LOCK_AV2      	0x0008
#define INPUT_LOCK_YPBPR    	0x0010
#define INPUT_LOCK_PC       	0x0020
#define INPUT_LOCK_HDMI1    	0x0040
#define INPUT_LOCK_HDMI2    	0x0080
#define INPUT_LOCK_HDMI3    	0x0100
#define INPUT_LOCK_SCART    	0x0200
#define INPUT_LOCK_HDMI4    	0x0400


static fpi_bool s_bInputSrcUnLockedState = fpi_false;	//针对法国对信源锁的特殊性增加一个单独的变量来临时记录当前锁状态

static fpi_linein_t g_current_pre_lineins=FPI_LINEIN_INVALID; //预存当前节目，由于当前节目由数据库存储会比较慢
//当再取的时候以及是切换成功后的结果了。

static uint32_t gu32InputSourceLockState = 0;
static fpi_bool sourceInit = fpi_true;


//#ifdef SCART_ENABLE
void app_input_source_scart_out_recovery(void)
{
	//get scart out source linein    
	APP_INPUT_SOURCE_INFO("function = %s, line = %d, set tv input\n",__FUNCTION__,__LINE__);
	fpi_linein_t u32ScartOutLinein;
	app_get_db_scart_out_source(&u32ScartOutLinein);
	if(u32ScartOutLinein != FPI_LINEIN_CDTV&&u32ScartOutLinein != FPI_LINEIN_TDTV
		&&u32ScartOutLinein != FPI_LINEIN_CATV&&u32ScartOutLinein != FPI_LINEIN_TATV)
	{
		//DTV for default
		u32ScartOutLinein = FPI_LINEIN_CDTV;
	}
    
	if(FPI_ERROR_LINEIN_SUCCESS == fpi_linein_changeto(u32ScartOutLinein))
	{
		APP_INPUT_SOURCE_INFO("function = %s, line = %d, set tv input to 0x%08x\n",__FUNCTION__,__LINE__,u32ScartOutLinein);
		app_save_db_current_linein(u32ScartOutLinein);
		app_get_and_set_all_volume();
		app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.scart",fpi_true);
		app_set_video_mute_ex(EN_VIDEO_MUTE_SCART, fpi_true);
                
		if( u32ScartOutLinein == FPI_LINEIN_CDTV || u32ScartOutLinein == FPI_LINEIN_TDTV )
		{
        		#ifdef FPI_CIPLUS //开机时或切换信源到DTV时，如果当前节目号是10000,则播放下一个节目
            			APP_INPUT_SOURCE_TRACE("function = %s, line = %d,CI+ Define\n",__FUNCTION__,__LINE__);
            			uint8_t enCurSerType;
				uint16_t u16CurProgNum;
				if(app_get_current_program_type_num(&enCurSerType, &u16CurProgNum))
            			{
					if(CI_PROGRAM_NUMBER == u16CurProgNum)
					{
						app_channel_dtv_play_next_program();
					}
					else
					{
						app_channel_dtv_play_current(); 
					}
        
            			}
		       #else
		       	app_channel_dtv_play_current(); 
		       #endif   
	        }
	        else
	        {
			if(app_input_source_get_unlock_state(u32ScartOutLinein))
			{
				app_input_source_lock_mute();
			}
            
            		if( u32ScartOutLinein == FPI_LINEIN_CATV || u32ScartOutLinein == FPI_LINEIN_TATV )
            		{
                		/*加锁 dtv切换到atv需要发送 EN_ATV EN_SS_COMMON_VIDEO 通知*/// shane.xie 20131014 add
                		if(!app_input_source_get_unlock_state(u32ScartOutLinein))
                		{
                    			app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
                		}
                		app_channel_atv_play_current_program();
            		}
        	}

    		app_teletext_reset();

		if(u32ScartOutLinein == FPI_LINEIN_CDTV || u32ScartOutLinein == FPI_LINEIN_TDTV)
		{
			//delay 1.5s,make sure that dtv has played
			os_msleep(1500);
			app_set_video_mute_ex(EN_VIDEO_MUTE_PLAY, fpi_false);
			app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.chgchannel",fpi_false);
			fpi_scart_out_set_mute(fpi_false, VIDEO_OUT_MUTE_GEN);
		}

	}
                
}
//#endif

fpi_bool app_input_source_init(void)
{
	fpi_user_sys_setting stUsrSysSetting = {0};
	fpi_linein_t input = FPI_LINEIN_INVALID;
	BACKLIGHT_FLAG_E backlight_flg;
	LINEIN_INIT_BY_MID_TYPE mid_init_linein_status;
	fpi_bool need_app_init_linein = fpi_true;

	fpi_trace("%s== start \n",__FUNCTION__ );

	//added by luhm 2015.03.19 for E_SND_MODE_SUBWOFOFER set 100hz gain
	app_audio_load_ini_init();
	
	app_get_user_sys_setting(&stUsrSysSetting);

	//add by @hh that this part is not used for other module
#if 0	
	//input = stUsrSysSetting.u32CurrentLinein;
		fpi_factory_hotel_setting FactoryHotelSetting = {0};
	uint8_t service_type;
	uint16_t current_program_num;
	app_get_factory_hotel_setting(&FactoryHotelSetting);
	if(FactoryHotelSetting.m_ModelEnabled)
	{
		switch(FactoryHotelSetting.m_PowerSignalType)
		{
			case  E_INPUT_SOURCE_CATV:
				input = FPI_LINEIN_CATV;
				break;
			case  E_INPUT_SOURCE_TATV:
				input = FPI_LINEIN_TATV;
				break;					
			case E_INPUT_SOURCE_CDTV:
				input = FPI_LINEIN_CDTV;
				break;
			case E_INPUT_SOURCE_TDTV:
				input = FPI_LINEIN_TDTV;
				break;
			case E_INPUT_SOURCE_SCART:
				input = FPI_LINEIN_SCART1;
				break; 
			case E_INPUT_SOURCE_CVBS1:
				input = FPI_LINEIN_CVBS1;
				break; 
			case E_INPUT_SOURCE_YPBPR1:
				input = FPI_LINEIN_COMPONENT1;
				break; 
			case E_INPUT_SOURCE_PC1:
				input = FPI_LINEIN_PC1;
				break; 
			case E_INPUT_SOURCE_HDMI1:
				input = FPI_LINEIN_HDMI1;
				break;
			case E_INPUT_SOURCE_HDMI2:
				input = FPI_LINEIN_HDMI2;		
				break;
			case E_INPUT_SOURCE_HDMI3:
				input = FPI_LINEIN_HDMI3;		
				break; 
			case E_INPUT_SOURCE_HDMI4:
				input = FPI_LINEIN_HDMI4;
				break;
			default:	
				input = FPI_LINEIN_INVALID;
				break; 
		}
		app_save_db_current_linein(input);
		if(app_get_current_program_type_num(&service_type, &current_program_num) == db_true)
		{
			current_program_num = (uint16_t)FactoryHotelSetting.m_PowerAtvCh;
			app_set_current_program_type_num(service_type, current_program_num);
		}
	}
	else
#endif		
	{
		input = stUsrSysSetting.u32CurrentLinein;
	}
	//end by @hh
	if(FPI_LINEIN_STORAGE == input || FPI_LINEIN_KTV == input)
	{        
		input = stUsrSysSetting.u32LastLinein;
	}

	app_input_source_lock_state_update();

	if(app_mutex_input_source_get()==OS_MUTEX_INVALID_ID)
	{
		fpi_info("app input source init allocate mutex failure\n");
		return fpi_false;
	}
	
	app_factory_get_backlight_flag(&backlight_flg);
	if(BACKLIGHT_OFF == backlight_flg)
	{
		POWER_WAKEUP_SOURCE_e   wakeup_src = POWER_WAKEUPSRC_NONE;

		fpi_power_get_wakeup_source(&wakeup_src);
		if (POWER_WAKEUPSRC_RTC2 == wakeup_src)
		{
			//当自动开机黑屏模式时静音
			app_power_set_pvr_backlight_state(fpi_false);
		}
		else
		{
			app_power_set_pvr_backlight_state(fpi_true);//other wakeup src
		}
	}
	else
	{
		app_power_set_pvr_backlight_state(fpi_true);
	}

	{//儿童锁
		fpi_bool bChildrenLock ;
		app_get_children_lock( &bChildrenLock ) ;
		if(bChildrenLock)
		{
			app_enable_children_lock(bChildrenLock);
		}
	}
    

	//add this for set zoom in tv power up, we need to set the zoom mode,before tv channel play
	//the better way is put it into the channel play mode. but now i add it here first.by wangtexin
	EN_INPUT_SOURCE_TYPE source;
	//fpi_pic_mode_data  stPicMode;
	source = db_map_fpi_linein_to_input_src(input);
	fpi_trace("source = %d\n", source);
	if(source != E_INPUT_SOURCE_NONE)
	{  
		//stPicMode= stUsrSysSetting.stUserPicSetting[source].stPicModeData[VIDEO_MODE_USER_IDX];
		//app_get_video_mode_preset(source,stUsrSysSetting.stUserPicSetting[source].enPicMode,&stPicMode);
		// fpi_trace("stUsrSysSetting.stUserPicSetting[source].enPictureSize = %d\n", stUsrSysSetting.stUserPicSetting[source].stPicModeData[stUsrSysSetting.stUserPicSetting[source].enPicMode].enPictureSize);
      	 	uint8_t u8PictureView;
	
/*
		if(EN_AREA_CN != uti_config_get_area())
		{
		u8PictureView=ZOOM_VIEW_FULL;
		}
		else
		app_get_video_view(&u8PictureView);
*///修改为下面的代码

		if( (E_HONGKONG == app_get_db_system_country() )||( E_CHINA == app_get_db_system_country()) )
		{
			app_get_video_view(&u8PictureView);
		}
		else
		{
			u8PictureView=ZOOM_VIEW_FULL;
		}
		
		fpi_zoom_set_mode((EN_PICTURE_SIZE)app_get_pic_mode_element(E_PIC_MODE_PIC_SIZE), (ZOOM_VIEW_MODE)u8PictureView);
	}

	if(0)//(stUsrSysSetting.fRunInstallationGuide == fpi_false) //如果开机初始化没完成，而搜台完成，则需要做处理
	{
		app_channel_data_reset_defualt();
	}

	//开机机过程中，判断中间件是否已经做过信源初始化，
	//如果开机过程中，中间件已经做过了信源切换，app中就不用再做信源切换
	fpi_linein_get_mid_initlinein_status(&mid_init_linein_status);
	fpi_info("get mid init linein status = %d\n",mid_init_linein_status);
	if(LINEIN_INIT_BY_MID_ING == mid_init_linein_status) 
	{
		os_msleep(200);
		fpi_linein_get_mid_initlinein_status(&mid_init_linein_status);
		if(LINEIN_INIT_BY_MID_ING == mid_init_linein_status) 
		{
			os_msleep(200);
			fpi_linein_get_mid_initlinein_status(&mid_init_linein_status);
		}
	}  

	//开机过程中，中间件已经做过了信源切换
	if(LINEIN_INIT_BY_MID_SUCCESSED == mid_init_linein_status)
	{
//		app_audio_init();	//del by luhm 2014.10.13
		need_app_init_linein = fpi_false;
	}

	if(fpi_false == need_app_init_linein)
	{
		sourceInit = fpi_true;
		fpi_info("app_input_source_init, input init exit!\n");
		return fpi_true;
	}
    
	app_set_input_source(input);
	sourceInit = fpi_true;
	// to start auido power on init
	//	app_audio_init();	//del by luhm 2014.10.13
	app_refresh_video_size();

	if((input == FPI_LINEIN_CDTV) ||(input == FPI_LINEIN_TDTV))
	{
		#ifdef FPI_CIPLUS //开机时或切换信源到DTV时，如果当前节目号是10000,则播放下一个节目
			fpi_trace("function = %s, line = %d, CI+ Define\n",__FUNCTION__,__LINE__);
			uint8_t enCurSerType;
			uint16_t u16CurProgNum;
			if(app_get_current_program_type_num(&enCurSerType, &u16CurProgNum))
			{
				if(CI_PROGRAM_NUMBER == u16CurProgNum)
				{
					app_channel_dtv_play_next_program();
				}
				else
				{
					app_channel_dtv_play_current(); 
				}

			}
			else
			{
				app_set_video_mute_ex(EN_VIDEO_MUTE_PLAY, fpi_true);
			}
    		#else
			app_channel_dtv_play_current(); 
		#endif   
	}
	else
	{
	        if(app_input_source_get_unlock_state(input))
	        {
	            app_input_source_lock_mute();
	        }
        
	        if( input == FPI_LINEIN_CATV || input == FPI_LINEIN_TATV )
	        {
			/*加锁 dtv切换到atv需要发送 EN_ATV EN_SS_COMMON_VIDEO 通知*/// shane.xie 20131014 add
			if(!app_input_source_get_unlock_state(input))
			{
				app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
			}

			app_channel_atv_play_current_program();
	        }
    }
    
    return fpi_true;
}

fpi_bool app_is_current_linein_itv(void)
{
	fpi_bool is_current_linein_itv = fpi_false;
	fpi_itv_platform_isItv(&is_current_linein_itv);

	return is_current_linein_itv;
}

static fpi_error app_safe_linein_changeto(fpi_linein_t input)
{
	fpi_bool status = fpi_false;
	fpi_itv_platform_isItv(&status);

	if(status)
	{
		fpi_bool data;
		fpi_itv_platform_offItv(&data);
	}
	
       if (input == app_get_input_source())
       {
		//ITV->DTV
		if(status)
		{
			return FPI_ERROR_LINEIN_SUCCESS;
		}
		else
		{
			app_notify_event(APP_NOTIFY_LINEIN_CHANGE_FINISH, 0, 0);
			return FPI_ERROR_LINEIN_FAIL;
		}

	
    	}
       else
       {
    		if( sys_cfg_get_model_version(SITA_MODULE_LINEIN) == 2 )
		{
			return fpi_linein_changeto_v2(input);
		}
		else
		{
			return fpi_linein_changeto(input);
		}
	//return fpi_linein_changeto(input);
       }
}


fpi_bool app_set_input_source(fpi_linein_t input)
{ 
	fpi_bool hbbtv_mode;
	fpi_bool b_unlockstate = fpi_false;
	fpi_linein_t current_linein = app_get_input_source(); //引起锁死

	fpi_info("app set input source init flag=%d,target_input=%d,current_input=%d\n",sourceInit,input,current_linein);

	if(FPI_LINEIN_INVALID == input)
	{
		fpi_alarm("app_set_input_source , FPI_LINEIN_INVALID!!! \n");
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"LINEIN_INVALID_PARAMETER\n");
		return fpi_false;
	}

	if(sourceInit && (input == g_current_pre_lineins) && (input == current_linein)&&(input!=FPI_LINEIN_CDTV) && (input != FPI_LINEIN_TDTV))
	{
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"LINEIN_INVALID_PARAMETER\n");
		
		if(current_linein == FPI_LINEIN_STORAGE)
		{
			fpi_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP, (char*)"app.media",fpi_false);
		}
		
		app_save_db_current_linein(input);
		return fpi_false;
	}
	fpi_trace("app_set_input_source os_mutex_obtain\n");
	os_mutex_obtain(app_mutex_input_source_get(),OS_WAIT_FOREVER);
	g_current_pre_lineins = input ;
	s_bInputSrcUnLockedState = fpi_false;//add by hanx 2014/11/25
	fpi_trace("os_mutex_obtain  start\n");
	
#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)
	EN_HBBTV_STATE state;
	app_get_db_hbbtv_mode(&hbbtv_mode);
	if(hbbtv_mode)
	{
		if(current_linein == FPI_LINEIN_CDTV ||current_linein == FPI_LINEIN_TDTV)
		{			
			app_hbbtv_stop(fpi_false);
		}
		if(current_linein == FPI_LINEIN_STORAGE)
		{
			app_hbbtv_get_state(&state);
			if(state == EN_HBBTV_FULLSCREEN_VOD)
			{
				app_hbbtv_stop(fpi_false);
			}
		}
	}
	fpi_trace("HBBTV_IWEDIA_ENABLED end\n");
#endif
//#ifdef SCART_ENABLE

	if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true )
	{
   		 //if start up or current linein is mm, check if scart out need to recover
		fpi_trace("%s,SCART_ENABLE current linein = %d\n",__FUNCTION__, current_linein );
		if((!sourceInit)||(current_linein == FPI_LINEIN_STORAGE))
	    	{
	        	if(input != FPI_LINEIN_CDTV && input != FPI_LINEIN_TDTV &&
	            		input != FPI_LINEIN_CATV && input != FPI_LINEIN_TATV )
			{
				app_input_source_scart_out_recovery();
				//update current linein
				//     current_linein = app_get_input_source(); 
				fpi_linein_get_current( &current_linein ) ;
				fpi_trace("SCART_change Finnish the LINEIN=%d\n", current_linein );
				//delay 1.2s,make sure that atv/dtv has played and will success changed to other linein.
				os_msleep(1200);
	        	}
	    	}
	}

//#endif
	fpi_trace("fpi_linein_changeto start\n");
    	app_signal_reset_state();
	if(FPI_ERROR_LINEIN_SUCCESS == app_safe_linein_changeto(input))
	{
		app_notify_event(APP_NOTIFY_LINEIN_CHANGE_FINISH, 0, 0);
		//    app_save_db_lastest_linein(current_linein); //移动到fpi_linein_changto里面
		//app_save_db_lastest_linein(input);
		//app_save_db_current_linein(input);
		app_save_db_lastest_and_current_linein(input);	
		app_reset_video_size();//zoom reset
		app_video_reset_xvycc_flag();
#if(FAST_SIGINAL_DETECT == 1)
		//mark huang 20141107  芝勇认为usb下需要，其他信源可以不需要
		if((input == FPI_LINEIN_STORAGE) || (input == FPI_LINEIN_KTV))
#endif
		app_video_reset(input);
		fpi_info("app_set_input_source sourceInit==%d\n",sourceInit);        
		if(sourceInit)
		{
			/*shane.xie 20131107 add input lock function*/ // shane.xie 20131115 modify dtv deal with by dtv himself
			uint16_t current_channel_index = 0;
			uint8_t current_service_type =0;
			uint8_t condition = 0;
			fpi_channel_info_t chInfo;
			memset(&chInfo,0,sizeof(fpi_channel_info_t));
			app_channel_list_get_current_channel(&current_channel_index, &current_service_type);
			app_channel_list_get_channel_info_by_index(current_channel_index,&chInfo);
			if(chInfo.is_lock == 1 && chInfo.is_have_unlocked == 0)
			{
				condition = 1;
			}

			b_unlockstate = app_input_source_get_unlock_state(current_linein);
			APP_INPUT_SOURCE_INFO("app_set_input_source condition=%d,current_linein=%d,current_linein_unlockstate=%d\n",condition,current_linein,b_unlockstate); 
			if(b_unlockstate||condition)
			{                
				APP_INPUT_SOURCE_TRACE("enter %s ,input source unmute\n",__FUNCTION__);
				app_input_source_lock_unmute();
			}
            
			APP_INPUT_SOURCE_TRACE("E_SYNC_INPUT_SOURCE_CHANGE = %d\n", E_SYNC_INPUT_SOURCE_CHANGE);
			//fpi_data_sync(E_SYNC_INPUT_SOURCE_CHANGE,0,0);
			fpi_channel_sync_user_common_setting(E_SYNC_INPUT_SOURCE_CHANGE);

			if(current_linein == FPI_LINEIN_CDTV || current_linein == FPI_LINEIN_TDTV)
			{
				// app_set_video_mute(fpi_false);   
				app_set_video_mute_ex(EN_VIDEO_MUTE_PLAY, fpi_false);
				app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.chgchannel",fpi_false);
			}
			else if(current_linein == FPI_LINEIN_CATV || current_linein == FPI_LINEIN_TATV)
			{
				APP_INPUT_SOURCE_TRACE("linein atv re mute false\n");
				app_channel_atv_reset();
			}
		}

		//app_set_volume(app_get_volume()) ; //linshunda adding
		app_get_and_set_all_volume();
		app_audio_update_audio_delay();
		
		b_unlockstate = app_input_source_get_unlock_state(input);
		APP_INPUT_SOURCE_INFO("app_set_input_source target_linein=%d, target_linein_unlockstate=%d\n",input,b_unlockstate); 
		
		if( (input != FPI_LINEIN_CDTV) && (input != FPI_LINEIN_TDTV) )
        	{
			if(b_unlockstate)
			{
				app_input_source_lock_mute();
			}
            		else
			{
				if( input == FPI_LINEIN_CATV || input == FPI_LINEIN_TATV )
				{
					/*加锁 dtv切换到atv需要发送 EN_ATV EN_SS_COMMON_VIDEO 通知*/// shane.xie 20131014 add
					app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
				}
            		}
            
		}
		else
		{
			//check dtv channel list
			if(b_unlockstate)
			{
				app_input_source_lock_mute();
			}
			uint16_t total_num = 0;
			app_channel_list_get_total_by_type(E_APP_CHANNEL_LIST_TYPE_DTV_RADIO, &total_num, 0);
			if(0 == total_num)
			{
				APP_INPUT_SOURCE_INFO("DTV no program!\n");
				fpi_zoom_refresh_current(E_ZOOM_REFRESH_NORMAL);
			}
			
#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)	
			app_get_db_hbbtv_mode(&hbbtv_mode);
			if(hbbtv_mode)
			{
				app_hbbtv_start();
			}	
#endif 
		}
		//app_set_mutes(AUDIO_MUTE_CHANGE_CHANNEL,fpi_false);//在这里不合适，纯粹为了解决DTV切换信源后没声音的问题
		//app_set_mutes(AUDIO_MUTE_CHANGE_LINEIN,fpi_false) ; 		// shane.xie 20131017 等视频信号稳定才unmute

		os_mutex_release(app_mutex_input_source_get());
		return fpi_true;
	}
	
#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)	
	app_get_db_hbbtv_mode(&hbbtv_mode);
	if(hbbtv_mode)
	{
		if(input == FPI_LINEIN_CDTV || input == FPI_LINEIN_TDTV)
		{			
			app_hbbtv_start();
		}
	}	
#endif
    os_mutex_release(app_mutex_input_source_get());	
    return fpi_false;
}



fpi_error app_linein_changeto(fpi_linein_t input)
{
	fpi_error ret ;
	ret = fpi_linein_changeto(input) ;
	app_notify_event(APP_NOTIFY_LINEIN_CHANGE_FINISH, 0, 0);
	return ret;
}

fpi_error app_save_current_linein(fpi_linein_t input)
{
	if( app_save_db_current_linein(input) == fpi_true)
	{
		return FPI_ERROR_SUCCESS;
	}
	return FPI_ERROR_FAIL;
}

fpi_linein_t app_get_input_source(void)
{
	uint32_t u32_linein;
	fpi_trace("function = %s line = %d\n",__FUNCTION__,__LINE__);
	//   os_mutex_obtain(app_mutex_input_source_get(),OS_WAIT_FOREVER);//如果正在set就不能 去读操作，以免不同步	

	fpi_linein_get_current( &u32_linein ) ;
	fpi_trace("get current source = 0x%x\n ", u32_linein );

	if( u32_linein == FPI_LINEIN_INVALID )
	{
		u32_linein = app_get_db_current_linein();
		fpi_trace("get current u32_linein from db = 0x%x\n ", u32_linein );
	}

	return u32_linein ;
}

fpi_linein_t app_get_input_sources(void)
{
	uint32_t u32_linein;
	fpi_trace("function = %s line = %d\n",__FUNCTION__,__LINE__);
	os_mutex_obtain(app_mutex_input_source_get(),OS_WAIT_FOREVER);
	u32_linein = app_get_input_source();
	os_mutex_release(app_mutex_input_source_get());
	return u32_linein ;
}


fpi_linein_t app_get_lastest_input_source()
{
	os_mutex_obtain(app_mutex_input_source_get(),OS_WAIT_FOREVER);
	uint32_t u32_linein;
	u32_linein = app_get_db_lastest_linein();
	os_mutex_release(app_mutex_input_source_get());
	return u32_linein;
}


fpi_linein_t app_get_pre_input_source( void )
{
	return g_current_pre_lineins ;
}

void app_set_pre_input_source(fpi_linein_t linein)
{
	g_current_pre_lineins = linein;
}

void app_input_source_lock_state_update(void)
{
	fpi_input_source_lock stInputSourceLock = {0};    
	app_get_db_user_source_lock(&stInputSourceLock);
    
	gu32InputSourceLockState = 0;
	s_bInputSrcUnLockedState = fpi_false;

	if(stInputSourceLock.inputSourceAtvLock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_ATV;
	}

	if(stInputSourceLock.inputSourceDtvLock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_DTV;
	}

	if(stInputSourceLock.inputSourceAvILock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_AV1;
	}

	if(stInputSourceLock.inputSourceAvIILock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_AV2;
	}

	if(stInputSourceLock.inputSourceYPBPRLock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_YPBPR;
	}

	if(stInputSourceLock.inputSourcePCLock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_PC;
	}

	if(stInputSourceLock.inputSourceHDMIILock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_HDMI1;
	}

	if(stInputSourceLock.inputSourceHDMIIILock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_HDMI2;
	}

	if(stInputSourceLock.inputSourceHDMIIIILock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_HDMI3;
	}
	
	if(stInputSourceLock.inputSourceScartLock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_SCART;
	}
	
	if(stInputSourceLock.inputSourceHDMI4Lock)
	{
		gu32InputSourceLockState |= INPUT_LOCK_HDMI4;
	}

	APP_INPUT_SOURCE_INFO("function = %s, gu32InputSourceLockState = 0x%x\n", __FUNCTION__, gu32InputSourceLockState);
    
}

fpi_bool app_input_source_get_unlock_state(fpi_linein_t linein)
{
	fpi_bool ret = fpi_false;
	fpi_input_source_lock stInputSourceLock = {0};
	MEMBER_COUNTRY country = app_get_db_system_country();

	app_get_db_user_source_lock(&stInputSourceLock);
    
	switch(linein)
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_ATV)?fpi_true:fpi_false;
			}
			else
			{
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceAtvLock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceAtvLock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceAtvLock,ret);
				/*if (s_bInputSrcUnLockedState)
	        		{
	        			s_bInputSrcUnLockedState = fpi_false;
	        			ret = fpi_false;
	        		}
				else
				{
		                	ret = stInputSourceLock.inputSourceAtvLock;
				}*/
			}
			break;
		case FPI_LINEIN_CDTV:
		case FPI_LINEIN_TDTV:
			//这里对DTV的解信源锁没有国家区分，只需要解一次就可以了
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_DTV)?fpi_true:fpi_false;
			}
			break;
		case FPI_LINEIN_CVBS1:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_AV1)?fpi_true:fpi_false;
			}
			else
			{     
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceAvILock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceAvILock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceAvILock,ret);
				//ret = stInputSourceLock.inputSourceAvILock;
			}
			break;
		case FPI_LINEIN_CVBS2:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_AV2)?fpi_true:fpi_false;
			}
			else
			{     
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceAvIILock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceAvIILock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceAvIILock,ret);
				//ret = stInputSourceLock.inputSourceAvIILock;
			}
			break;
		case FPI_LINEIN_COMPONENT1:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_YPBPR)?fpi_true:fpi_false;
			}
			else
			{   
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceYPBPRLock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceYPBPRLock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceYPBPRLock,ret);
				//ret = stInputSourceLock.inputSourceYPBPRLock;
			}
			break;
		case FPI_LINEIN_PC1:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_PC)?fpi_true:fpi_false;
			}
			else
			{    
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourcePCLock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourcePCLock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourcePCLock,ret);
				//ret = stInputSourceLock.inputSourcePCLock;
			}
			break;
		case FPI_LINEIN_HDMI1:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_HDMI1)?fpi_true:fpi_false;
			}
			else
			{   
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceHDMIILock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceHDMIILock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceHDMIILock,ret);
				//ret = stInputSourceLock.inputSourceHDMIILock;
			}
			break;
		case FPI_LINEIN_HDMI2:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_HDMI2)?fpi_true:fpi_false;
			}
			else
			{   
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceHDMIIILock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceHDMIIILock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceHDMIIILock,ret);
				//ret = stInputSourceLock.inputSourceHDMIIILock;
			}
			break;
		case FPI_LINEIN_HDMI3:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_HDMI3)?fpi_true:fpi_false;
			}
			else
			{    
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceHDMIIIILock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceHDMIIIILock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceHDMIIIILock,ret);
				//ret = stInputSourceLock.inputSourceHDMIIIILock;
			}
			break;
		case FPI_LINEIN_SCART1:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_SCART)?fpi_true:fpi_false;
			}
			else
			{   
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceScartLock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceScartLock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceScartLock,ret);
				//ret = stInputSourceLock.inputSourceScartLock;
			}
			break;
		case FPI_LINEIN_HDMI4:
			if(E_FRANCE != country)
			{
				ret = (gu32InputSourceLockState&INPUT_LOCK_HDMI4)?fpi_true:fpi_false;
			}
			else
			{   
				ret = ((s_bInputSrcUnLockedState==fpi_false)&&(stInputSourceLock.inputSourceHDMI4Lock==fpi_true));
				APP_INPUT_SOURCE_TRACE("get unlock state s_bInputSrcUnLockedState = %d,inputSourceHDMI4Lock = %d,ret = %d\n",
				s_bInputSrcUnLockedState,stInputSourceLock.inputSourceHDMI4Lock,ret);
				//ret = stInputSourceLock.inputSourceHDMI4Lock;
			}
			break;
            
		default:
			break;            
	}
	APP_INPUT_SOURCE_INFO("app_input_source_get_unlock_state =%d\n",ret);

	return ret;    
}

fpi_bool app_input_source_set_lock_state(fpi_linein_t linein, fpi_bool islocked)
{
	fpi_bool ret = fpi_true;
	MEMBER_COUNTRY country = app_get_db_system_country();

	if(E_GERMANY == country)
	{
		if(islocked)
		{
			switch(linein)
			{
				case FPI_LINEIN_CATV:
				case FPI_LINEIN_TATV:
					gu32InputSourceLockState |= INPUT_LOCK_ATV;
					break;
				case FPI_LINEIN_CDTV:
				case FPI_LINEIN_TDTV:
					gu32InputSourceLockState |= INPUT_LOCK_DTV;
					break;
				case FPI_LINEIN_CVBS1:
					gu32InputSourceLockState |= INPUT_LOCK_AV1;
					break;
				case FPI_LINEIN_CVBS2:
					gu32InputSourceLockState |= INPUT_LOCK_AV2;
					break;
				case FPI_LINEIN_COMPONENT1:
					gu32InputSourceLockState |= INPUT_LOCK_YPBPR;
					break;
				case FPI_LINEIN_PC1:
					gu32InputSourceLockState |= INPUT_LOCK_PC;
					break;
				case FPI_LINEIN_HDMI1:
					gu32InputSourceLockState |= INPUT_LOCK_HDMI1;
					break;
				case FPI_LINEIN_HDMI2:
					gu32InputSourceLockState |= INPUT_LOCK_HDMI2;
					break;
				case FPI_LINEIN_HDMI3:
					gu32InputSourceLockState |= INPUT_LOCK_HDMI3;
					break;
				case FPI_LINEIN_HDMI4:
					gu32InputSourceLockState |= INPUT_LOCK_HDMI4;
					break;
				case FPI_LINEIN_SCART1:
					gu32InputSourceLockState |= INPUT_LOCK_SCART;
					break;
				default:
					ret = fpi_false;
					break;            
			}
		}
		else
		{
			gu32InputSourceLockState = 0;
		}
	}
	else if(E_FRANCE != country)
	{
		switch(linein)
		{
			case FPI_LINEIN_CATV:
			case FPI_LINEIN_TATV:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_ATV;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_ATV);
				}
				break;
			case FPI_LINEIN_CDTV:
			case FPI_LINEIN_TDTV:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_DTV;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_DTV);
				}
				break;
			case FPI_LINEIN_CVBS1:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_AV1;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_AV1);
				}
				break;
			case FPI_LINEIN_CVBS2:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_AV2;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_AV2);
				}
				break;
			case FPI_LINEIN_COMPONENT1:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_YPBPR;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_YPBPR);
				}
				break;
			case FPI_LINEIN_PC1:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_PC;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_PC);
				}
				break;
			case FPI_LINEIN_HDMI1:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_HDMI1;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_HDMI1);
				}
				break;
			case FPI_LINEIN_HDMI2:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_HDMI2;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_HDMI2);
				}
				break;
			case FPI_LINEIN_HDMI3:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_HDMI3;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_HDMI3);
				}
				break;
			case FPI_LINEIN_HDMI4:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_HDMI4;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_HDMI4);
				}
				break;   
			case FPI_LINEIN_SCART1:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_SCART;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_SCART);
				}
				break;    
			default:
				ret = fpi_false;
				break;            
		}
	}
	else if (E_FRANCE == country)
	{
		switch(linein)
    		{
			case FPI_LINEIN_CATV:
			case FPI_LINEIN_TATV:
				if(islocked)
				{
					s_bInputSrcUnLockedState = fpi_false; 
				}
				else
				{
					s_bInputSrcUnLockedState = fpi_true; 
				}
				break;
			case FPI_LINEIN_CDTV:
			case FPI_LINEIN_TDTV:
				if(islocked)
				{
					gu32InputSourceLockState |= INPUT_LOCK_DTV;
				}
				else
				{
					gu32InputSourceLockState &= (~INPUT_LOCK_DTV);
				}
				break;
			default:
				if(islocked)
				{
					s_bInputSrcUnLockedState = fpi_false; 
				}
				else
				{
					s_bInputSrcUnLockedState = fpi_true; 
				}
				break;
		}
	}
	return ret;    
}


void app_input_source_lock_mute(void)
{
	app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.lock",fpi_true);
	app_set_video_mute_ex(EN_VIDEO_MUTE_LOCK, fpi_true);
    
	switch(app_get_input_source())
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			{
			//    #ifdef SCART_ENABLE
			//atv input lock
			//printf("\n[%s,%d] mute == TRUE,mute_level == VIDEO_OUT_MUTE_LOCK\n\n",__FUNCTION__,__LINE__);
			fpi_scart_out_set_mute(fpi_true,VIDEO_OUT_MUTE_LOCK); 
			//    #endif
			app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_INPUT_BLOCK, (uint32_t)-1);
			break;
			}
		default:
			app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_INPUT_BLOCK, (uint32_t)-1);
			break;
	}
}

void app_input_source_lock_unmute(void)
{
	app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.lock",fpi_false);

	app_set_video_mute_ex(EN_VIDEO_MUTE_LOCK, fpi_false);

	switch(app_get_input_source())
	{
		case FPI_LINEIN_CATV:
		case FPI_LINEIN_TATV:
			{   
				fpi_scart_out_set_mute(fpi_false,VIDEO_OUT_MUTE_LOCK); 
				app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
			}
			break;
		default:
			app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
			break;
	}
}

fpi_bool app_input_source_is_init(void)
{
	return sourceInit;
}

fpi_error app_input_source_src_intert_check(fpi_linein_t input, fpi_bool *isInsert)
{
	return fpi_linein_src_insert_check(input, isInsert);
}

fpi_error app_input_source_reset(void)
{
	s_bInputSrcUnLockedState = fpi_false;
	gu32InputSourceLockState = 0;
	return FPI_ERROR_SUCCESS;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "tos_androidHandler.h"
tos_Looper_T *s_sourcechangeLooperHandle = NULL;

void app_souce_send_message(TVH_LINEIN_ObjectMsgType_t type,int arg1,int art2)
{
	tos_androidHandler_message msg;
	msg.what = type;
	msg.arg1 = arg1;
	msg.arg2 = art2;			
	tos_androidHandler_sendMessage(s_sourcechangeLooperHandle, &msg);
}

fpi_error app_source_set_input_async(EN_API_SOURCE_INPUT input,EN_ACT_CTRL act)
{
	tos_androidHandler_message msg;
	msg.what = E_INPUTSRC_CHANGE_SRC_ASNC;
	msg.arg1 = input;
	msg.arg2 = act;
	
	fpi_info("tos_source_set_input_async src ==%d,act=%d\n",input,act);
	tos_androidHandler_removeEmptyMessages(s_sourcechangeLooperHandle,E_INPUTSRC_CHANGE_SRC_ASNC);
	if(tos_androidHandler_sendMessageDelay(s_sourcechangeLooperHandle, &msg ,200)!= SITA_SUCCESS)
	{
		return FPI_ERROR_FAIL;
	}
	return FPI_ERROR_SUCCESS;
}



void app_line_change_success(fpi_linein_t input, fpi_linein_t current_linein )
{
	app_reset_video_size();//zoom reset
	
	app_video_reset_xvycc_flag();
	
	/*shane.xie 20131107 add input lock function*/ // shane.xie 20131115 modify dtv deal with by dtv himself
	uint16_t current_channel_index = 0;
	uint8_t current_service_type =0;
	uint8_t condition = 0;
	fpi_bool unlockstate = fpi_false;
	fpi_channel_info_t chInfo;
	memset(&chInfo,0,sizeof(fpi_channel_info_t));
	app_channel_list_get_current_channel(&current_channel_index, &current_service_type);
	app_channel_list_get_channel_info_by_index(current_channel_index,&chInfo);

	if(chInfo.is_lock == 1 && chInfo.is_have_unlocked == 0)
	{
		condition= 1;
	}

	unlockstate = app_input_source_get_unlock_state(current_linein);
		
	APP_INPUT_SOURCE_INFO("app_set_input_source condition=%d,unlockstate=%d,current_linein=%d\n",condition,unlockstate,current_linein); 
	if(unlockstate ||condition)
	{                
		APP_INPUT_SOURCE_INFO("enter %s ,input source unmute\n",__FUNCTION__);
		app_input_source_lock_unmute();
	}
            
	APP_INPUT_SOURCE_TRACE("E_SYNC_INPUT_SOURCE_CHANGE = %d\n", E_SYNC_INPUT_SOURCE_CHANGE);
	fpi_channel_sync_user_common_setting(E_SYNC_INPUT_SOURCE_CHANGE);

	if(current_linein == FPI_LINEIN_CDTV || current_linein == FPI_LINEIN_TDTV)
	{
		app_set_video_mute_ex(EN_VIDEO_MUTE_PLAY, fpi_false);
		app_set_mutes_for_device(EN_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP,(char*)"tos.chgchannel",fpi_false);
	}
	else if(current_linein == FPI_LINEIN_CATV || current_linein == FPI_LINEIN_TATV)
	{
		fpi_info("linein atv re mute false\n");
		app_channel_atv_reset();
	}
		
	app_get_and_set_all_volume();
	app_audio_update_audio_delay();

	unlockstate = app_input_source_get_unlock_state(input);
	APP_INPUT_SOURCE_INFO("unlockstate=%d,target_input=%d\n",unlockstate,input); 
		
	if( (input == FPI_LINEIN_CDTV) || (input == FPI_LINEIN_TDTV) )
        {
		//check dtv channel list
		if(unlockstate)
		{
			app_input_source_lock_mute();
		}
		uint16_t total_num = 0;
		app_channel_list_get_total_by_type(E_APP_CHANNEL_LIST_TYPE_DTV_RADIO, &total_num, 0);
		if(0 == total_num)
		{
			APP_INPUT_SOURCE_INFO("DTV no program!\n");
			fpi_zoom_refresh_current(E_ZOOM_REFRESH_NORMAL);
		}

#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)	
		fpi_bool hbbtv_mode = fpi_false;
		app_get_db_hbbtv_mode(&hbbtv_mode);
		if(hbbtv_mode)
		{
			app_hbbtv_start();
		}	
#endif	

        }
        else
        {
	        if(unlockstate)
	        {
	        	app_input_source_lock_mute();
	        }
		else
		{
			 if( input == FPI_LINEIN_CATV || input == FPI_LINEIN_TATV )
			 {
				/*加锁 dtv切换到atv需要发送 EN_ATV EN_SS_COMMON_VIDEO 通知*/// shane.xie 20131014 add
				app_notify_event(APP_NOTIFY_SCREEN_SAVER, (uint32_t)E_FPI_DTV_SCREEN_INFO_COMMON_VIDEO, (uint32_t)-1);
			 }
		}
        }
		
        if(input == FPI_LINEIN_STORAGE)
        {
		app_teletext_stop();
        }
        else
        {
		app_teletext_off();
		fpi_ttx_reset();
        }
}

void app_line_change_before_action(fpi_linein_t input, fpi_linein_t current_linein )
{
//    callback_param_t *p = (callback_param_t *)arg;
//	fpi_linein_t current_linein ;
//	fpi_linein_t input ;
	fpi_bool hbbtv_mode;

//	input = p->un32_p1;
//	current_linein = p->un32_p2;
	fpi_info("app_line_change_before_action ,current_linein=0x%x,target_linein=0x%x\n",current_linein,input );

#if defined(HBBTV_IWEDIA_ENABLED) || defined(HBBTV_OPERA_ENABLED)
	EN_HBBTV_STATE state;
	app_get_db_hbbtv_mode(&hbbtv_mode);
	if(hbbtv_mode)
	{
		if(current_linein == FPI_LINEIN_CDTV ||current_linein == FPI_LINEIN_TDTV)
		{			
			app_hbbtv_stop(fpi_false);
		}
		if(current_linein == FPI_LINEIN_STORAGE)
		{
			app_hbbtv_get_state(&state);
			if(state == EN_HBBTV_FULLSCREEN_VOD)
			{
				app_hbbtv_stop(fpi_false);
			}
		}
	}
#endif
#if 0 //不知道这个地方的作用，但这个地方要花费2 S 以上 。林舜大，路惠明，时剑
	if( sys_cfg_get_func_enable(FUNC_CFG_SCART) == fpi_true ){
    //if start up or current linein is mm, check if scart out need to recover
	    fpi_trace("%s*SCART_ENABLE get linein cur=%d\n",__FUNCTION__, current_linein );
	    if((!sourceInit)||(current_linein==FPI_LINEIN_STORAGE))
	    {
	        if(input!=FPI_LINEIN_CDTV && input != FPI_LINEIN_TDTV &&
	            input!=FPI_LINEIN_CATV && input != FPI_LINEIN_TATV )
	        {
	            app_input_source_scart_out_recovery();
	            //update current linein	       
	       		fpi_linein_get_current( &current_linein ) ;
	            fpi_trace("%s*SCART_ENABLE set LINEIN=%d\n",__FUNCTION__, current_linein );
	            //delay 1.2s,make sure that atv/dtv has played and will success changed to other linein.
	        //    os_msleep(1200);
	        }
	    }
	}
#endif	
}


static void* app_source_looper_tast(void* args)
{
	if(s_sourcechangeLooperHandle != NULL) {
		int ret = tos_androidHandler_loop(s_sourcechangeLooperHandle); 
		if (ret <0){
			tos_androidHandler_quit(s_sourcechangeLooperHandle);
			tos_androidHandler_destroyLooper(s_sourcechangeLooperHandle);
			s_sourcechangeLooperHandle = NULL;
		}
	}
	return NULL;
}

void app_source_handleMessage(tos_Looper_T* looper,const tos_androidHandler_message* msg,void* userdata)
{
	fpi_info("app_source_handleMessage type=%d,arg1=%d,arg2=%d\n",msg->what,msg->arg1,msg->arg2 );
	struct timespec times;
	struct timespec times2;
	int ms;
	clock_gettime(CLOCK_MONOTONIC, &times);
	switch (msg->what)
	{
		case E_TVH_LINEIN_MSG_CHANGETO_START:
				app_line_change_before_action((uint32_t)msg->arg1,(uint32_t)msg->arg2);
			break;
		case E_TVH_LINEIN_MSG_CHANGETO_APP_SUCCESS:
				app_line_change_success((uint32_t)msg->arg1,(uint32_t)msg->arg2);
			break;	
		case E_INPUTSRC_CHANGE_SRC_ASNC:
				tos_source_set_input((EN_API_SOURCE_INPUT)msg->arg1,(EN_ACT_CTRL)msg->arg2);
			break;
		default:
				fpi_linein_mngr_proc(msg->what,(uint32_t)msg->arg1,(uint32_t)msg->arg2);
			break;
	}
	clock_gettime(CLOCK_MONOTONIC, &times2);
	ms = (times2.tv_sec - times.tv_sec)*1000 + ((times2.tv_nsec - times.tv_nsec) / (1000*1000) );
	fpi_info("app_source_handleMessage=%d ms\n",ms );
}

fpi_error app_source_message_input_init()
{
	s_sourcechangeLooperHandle = tos_androidHandler_createLooper("InputSrcLooper",100,app_source_handleMessage,NULL);
	if (s_sourcechangeLooperHandle == NULL)
	{
		return FPI_ERROR_FAIL;
	}
	pthread_t thread_handle;
    
	app_input_source_lock_state_update();
	if (pthread_create(&thread_handle, NULL, app_source_looper_tast, NULL) != 0)
	{
		return FPI_ERROR_FAIL;
	}
	return FPI_ERROR_SUCCESS;
} 

fpi_error app_set_input_source_v2(fpi_linein_t input)
{
	fpi_error ret = FPI_ERROR_SUCCESS ;

	fpi_info("function = %s, line = %d, linein=0x%x\n",__FUNCTION__,__LINE__,input);

	fpi_linein_t current_linein ;
	fpi_linein_get_current( &current_linein) ;
    
	if(FPI_LINEIN_INVALID == input)
	{        
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"LINEIN_INVALID_PARAMETER\n");
		return FPI_ERROR_LINEIN_INVALID_PARAMETER;
	}

	if(input==current_linein)
	{
		fpi_warn("target_input=%d,current_input=%d , no need change\n",input,current_linein);
		fpi_err_code(FPI_ERROR_LINEIN_INVALID_PARAMETER,"LINEIN_INVALID_PARAMETER\n");
		return FPI_ERROR_LINEIN_INVALID_PARAMETER;
	}

	uint16_t nloop = 0;
	for(nloop = E_TVH_LINEIN_MSG_CHANGETO_START;nloop <= E_TVH_LINEIN_MSG_CHANGETO_END;nloop++)
	{
		tos_androidHandler_removeEmptyMessages(s_sourcechangeLooperHandle,nloop);
	}
	app_souce_send_message(E_TVH_LINEIN_MSG_CHANGETO_START,input,current_linein);
	os_mutex_obtain(app_mutex_input_source_get(),OS_WAIT_FOREVER);
    	app_signal_reset_state(); //基本不耗时，假如耗时使用通知处理 
    	
	if(FPI_ERROR_LINEIN_SUCCESS == app_safe_linein_changeto(input))
	{
		//app_save_db_lastest_linein(input);
		//app_save_db_current_linein(input);	
		app_save_db_lastest_and_current_linein(input);	
		app_souce_send_message(E_TVH_LINEIN_MSG_CHANGETO_APP_SUCCESS,input,current_linein);
	}
    
	app_notify_event(APP_NOTIFY_LINEIN_CHANGE_FINISH, input, current_linein);
	os_mutex_release(app_mutex_input_source_get());
	
    	return ret;
}

	
