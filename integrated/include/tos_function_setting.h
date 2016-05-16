/**@defgroup 功能设置模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
*/



#ifndef __TOS_SETTING_H__
#define __TOS_SETTING_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

//net update
#define API_SW_VER_LEN 30
#define API_SW_NOTE_LEN 300
#define API_SW_FILE_NAME_LEN 256
#define API_SW_FILE_SIZE 30

/**
@brief 国家或者区域
**/
typedef enum
{
	EN_REGION_SPAIN,		///<西班牙
	EN_REGION_AUSTRALIA,	///<澳大利亚
}EN_REGION_TYPE;

/**
@brief 获得什么状态下的时间
**/
typedef enum
{
	EN_SETTING_TIME_CURRENT, 	///<当前时间 。
	EN_SETTING_TIME_POWERON,		///<开机时间
	EN_SETTING_TIME_POWEROFF,		///<关机时间
	EN_SETTING_TIME_SLEEP,		///<睡眠时间
	EN_SETTING_TIME_AUTO_STANDBY,
	EN_SETTING_TIME_RUNINGTIME,
}EN_SETTING_TIME_CTRL;


/**
@brief 升级过程动作
**/
typedef enum
{
	EN_DOWNLOAD_START,  ///<开始
	EN_DOWNLOAD_PAUSE,  ///<暂停
	EN_DOWNLOAD_RESTART,
	EN_DOWNLOAD_STOP, ///<停止,会自动删除下载的软件,restar = stop + start .

	EN_UPDATE_START,
	EN_UPDATE_STOP,

    EN_UPDATE_CHECK,   //检测是否有升级包
    EN_UPDATE_WITHOUT_REMIND,
	EN_UPDATE_FUTURE_START,	
	EN_UPDATE_FUTURE_CANCEL
}EN_UPDATE_ACTION_CTRL;

/**
@brief 开机设置向导的各种模式或者类型
**/
typedef enum
{
    EN_GUIDE_MODE_NONE_MODE,  ///<开机不执行开机向导
    EN_GUIDE_MODE_TV_MODE,
    EN_GUIDE_MODE_ESTICKER_MODE,
    EN_GUIDE_MODE_HOMEPAGE_MODE,
    EN_GUIDE_MODE_INITTIAL_MODE,
} EN_GUIDE_MODE;

/**
@brief 开机向导具有的一些可配置模块
**/
typedef enum
{
	EN_GUIDE_MODULAR_QUICK_SCAN, ///<是否有快速搜台
	EN_GUIDE_MODULAR_NETWORK,///<是否有网络模块
}EN_GUIDE_MODULAR ;

/**
@brief 时区
**/	
typedef enum
{
    E_TIME_ZONE_AS_BROADCASTER, // GMT   
    E_TIME_ZONE_GMT_0, // GMT + 1    
    E_TIME_ZONE_GMT_1, // GMT + 2    
    E_TIME_ZONE_GMT_2, // GMT + 3    
    E_TIME_ZONE_GMT_3, // GMT + 3:00    
    E_TIME_ZONE_GMT_3_30,    // GMT + 3:30    
    E_TIME_ZONE_GMT_4, // GMT + 4:00       
    E_TIME_ZONE_GMT_4_30, // GMT + 4:30       
    E_TIME_ZONE_GMT_5, // GMT + 5:00        
    E_TIME_ZONE_GMT_5_30, // GMT + 5:30          
    E_TIME_ZONE_GMT_5_45, //GMT + 5:45        
    E_TIME_ZONE_GMT_6, // GMT + 6   
    E_TIME_ZONE_GMT_6_30, // GMT + 6:30        
    E_TIME_ZONE_GMT_7, // GMT + 7	    
    E_TIME_ZONE_GMT_8, // GMT + 8        	    
    E_TIME_ZONE_GMT_9, // GMT + 9    	    
    E_TIME_ZONE_GMT_9_30, // GMT + 9:30		
    E_TIME_ZONE_GMT_10, // GMT + 10    	    
    E_TIME_ZONE_GMT_11, // GMT + 11    	   
    E_TIME_ZONE_GMT_12, // GMT +12             
    E_TIME_ZONE_GMT_12_45,  // GMT +12:45	    	
    E_TIME_ZONE_GMT_13,// GMT +13		
    E_TIME_ZONE_GMT_NEG_12, // GMT -12	
    E_TIME_ZONE_GMT_NEG_11, // GMT -11	
    E_TIME_ZONE_GMT_NEG_10,	// GMT -10    	
    E_TIME_ZONE_GMT_NEG_9,	// GMT -9    		
    E_TIME_ZONE_GMT_NEG_8,// GMT -8    		
    E_TIME_ZONE_GMT_NEG_7,// GMT -7    		
    E_TIME_ZONE_GMT_NEG_6,// GMT -6    		
    E_TIME_ZONE_GMT_NEG_5,	// GMT -5    		
    E_TIME_ZONE_GMT_NEG_4,// GMT -4    		
    E_TIME_ZONE_GMT_NEG_3_30,// GMT -3:30    		
    E_TIME_ZONE_GMT_NEG_3,// GMT -3    	
    E_TIME_ZONE_GMT_NEG_2,	// GMT -2      		
    E_TIME_ZONE_GMT_NEG_1,  // GMT -1    
    E_TIME_ZONE_GMT_10_30, // GMT + 10:30  
    E_TIME_ZONE_NUM, //E_TIME_ZONE MAX
} EN_FPI_TIME_ZONE;
/**
@brief the period of power on/off timer
**/	
typedef enum
{
   // sleep timer off
   EN_SLEEP_TIMER_OFF,
   // 10 mins to sleep
   EN_SLEEP_TIMER_10MIN,
   // 20 mins to sleep
   EN_SLEEP_TIMER_20MIN,
   // 30 mins to sleep
   EN_SLEEP_TIMER_30MIN,
   // 40 mins to sleep
   EN_SLEEP_TIMER_40MIN,
   // 50 mins to sleep
   EN_SLEEP_TIMER_50MIN,
   // 60 mins to sleep
   EN_SLEEP_TIMER_60MIN,
   // 90 mins to sleep
  EN_SLEEP_TIMER_90MIN,
   // 120 mins to sleep
   EN_SLEEP_TIMER_120MIN,
   // 240 mins to sleep
   EN_SLEEP_TIMER_240MIN,
   // counts of this enum
   EN_SLEEP_TIMER_NUM
} EN_FPI_SLEEP_TIMER_STATE;



/**
@brief 升级类别
**/	
typedef enum
{
    E_UPDATE_BY_USB,
    E_UPDATE_BY_NETWORK,
    E_UPDATE_BY_CHANNEL, // oad scan by channel
    E_UPDATE_BY_OAD,	//backgroud oad monitor
    E_BLIND_UPDATE
} EN_FPI_SOFTWARE_UPDATE; 
 /**
 @brief 升级信息
 **/
 typedef struct
{
    char fileName[API_SW_FILE_NAME_LEN+1];	//full path name (eg: /data/oad_udpate/oad.bin)
    char version[API_SW_VER_LEN];
    char note[API_SW_NOTE_LEN];
    char size[API_SW_FILE_SIZE];
}st_fpi_net_update_info;
 /**
 @brief 设备使用场合
 **/
typedef enum
{
	E_API_HOME,
	E_API_SHOP,
	E_API_SHOP_WITH_DEMO,
}EN_FPI_LOCATION;
 /**
 @brief 键盘编码
 **/
 typedef enum
{
    E_API_KEYBOARD_LAYOUT_AZERTY = 0,
    E_API_KEYBOARD_LAYOUT_QWERTY	
} EN_FPI_USB_KEYBOARD_LAYOUT;
 /**
 @brief 直接控制硬件
 **/
typedef enum
{
	EN_DIRECT_CTRL_2D_120HZ_ENABLE,
}EN_DIRECT_CTRL;

typedef enum
{
    CNT_DOWNLOAD_BUTTON,
    CNT_UPGRADE_BUTTON,
    CNT_SOFTWARE_VERSION
}EN_UI_CONTENT;

typedef enum
{
    EN_TOS_BUTTON_VAL_DEFAULT = 0,
    EN_TOS_BUTTON_VAL_LATER,
    EN_TOS_BUTTON_VAL_NEVER
}EN_BUTTON_VALUE;

typedef enum
{
    EN_TOS_STADIUM_MODE
}EN_TOS_SPECIAL_MODE;



typedef enum
{
    EN_WIRELESS_WAKEUP_MODE,
	EN_ETHERNET_WAKEUP_MODE,
	EN_WAKEUP_MODE_NUMS
}EN_FUNC_NET_WAKEUP_MODE;

/**
@brief 中间件初始化状态
**/
typedef enum
{
	 EN_FUNC_STATE_UNKNOWN,  
	 EN_FUNC_STATE_INIT_FINISH,  // 中间件初始化完成，可以进行调用tos接口，切换信源等操作
         
}EN_FUNC_STATE_TYPE;


typedef struct
{
    uint8_t   hour;
    uint8_t   minute;
    uint8_t   second;
    uint8_t   reserve[1];
} st_fpi_time;

typedef struct
{
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     minute;
    uint32_t     second;
    uint8_t     weekday;
} st_fpi_date;

typedef enum
{
	E_COUNTYR_REGION_0,
	E_COUNTYR_REGION_1,
	E_COUNTYR_REGION_2,
	E_COUNTYR_REGION_3,
	E_COUNTYR_REGION_4,    
	E_COUNTYR_REGION_5,
	E_COUNTYR_REGION_6,   
	E_COUNTYR_REGION_7,
	E_COUNTYR_REGION_8,  
	E_COUNTYR_REGION_9,
	E_COUNTYR_REGION_10,  
	E_COUNTYR_REGION_11,
	E_COUNTYR_REGION_12   
} EN_API_COUNTYR_REGION;

/**
@brief 获取菜单语言

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_menu_language(MEMBER_LANGUAGE *value);

/**
@brief 设置菜单语言

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_menu_language(MEMBER_LANGUAGE language,EN_ACT_CTRL act);


/**
@brief  获取当前时区

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_time_zone(EN_FPI_TIME_ZONE *value);

/**
@brief 设置当前时区

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_time_zone(EN_FPI_TIME_ZONE timezone,EN_ACT_CTRL act);


/**
@brief 获得某一国家的时区

@note 时区value 根据该国家具体定义

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_region(EN_REGION_TYPE region,int32_t *value);


/**
@brief 设置某一国家的时区

@note 时区value 根据该国家具体定义

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_region(EN_REGION_TYPE region_country,int32_t region,EN_ACT_CTRL act);



/**
@brief  获取当前是否是时间同步状态

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_time_sync(int32_t *value);

/**
@brief	设置时间同步

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_time_sync(int32_t autosync,EN_ACT_CTRL act);




/**
@brief	获得时间

@note  根据类型获得当前的，开机后的，关机的，睡眠的时间。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_time(EN_SETTING_TIME_CTRL type,st_fpi_date *value);
/**
@brief	设置时间

@note  根据类型获得当前的，开机后的，关机的，睡眠的时间。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_time(EN_SETTING_TIME_CTRL type, st_fpi_date* pst_date,EN_ACT_CTRL act);

/**
@brief	升级控制

@note  可选择升级的类型，以及控制升级的开始，暂停，停止

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_updating(EN_FPI_SOFTWARE_UPDATE updateMode ,EN_UPDATE_ACTION_CTRL action );
/**
@brief	获得升级的信息

@note  假如缺乏的信息，那么可为空

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_update_info(EN_FPI_SOFTWARE_UPDATE updateMode,st_fpi_net_update_info *pInfo);
/**
@brief	设置升级的信息

@note  假如缺乏的信息，那么可为空

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_update_info(EN_FPI_SOFTWARE_UPDATE updateMode,st_fpi_net_update_info *pInfo,EN_ACT_CTRL act);
/**
@brief	判断升级是否在运行中

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_updating_is_running(EN_FPI_SOFTWARE_UPDATE updateMode ,int32_t *running);


/**
@brief	恢复出厂设置

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_reset_default();


/** 
@brief 获取已经下载的升级文件的大小
@param[in] 无
@param[out] size 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_setting_get_download_file_size(int32_t*size);

/** 
@brief 获取升级提示对话框中用户的选择
@param[in] e_content 
              CNT_DOWNLOAD_BUTTON, //下载按键(选项)  
              CNT_UPGRADE_BUTTON,  //升级按键(选项)
              CNT_SOFTWARE_VERSION //软件版本号

@param[out] value     
            typedef enum
            {
                EN_TOS_BUTTON_VAL_DEFAULT = 0,
                EN_TOS_BUTTON_VAL_LATER,
                EN_TOS_BUTTON_VAL_NEVER
            }EN_BUTTON_VALUE;       
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_setting_get_ui_content(EN_UI_CONTENT e_content, int32_t *value);

/** 
@brief 设置升级提示对话框中用户的选择，升级流程根据用户设置跑不同的流程
@param[in] e_content 
              CNT_DOWNLOAD_BUTTON, //下载按键(选项)  
              CNT_UPGRADE_BUTTON,  //升级按键(选项)
              CNT_SOFTWARE_VERSION //软件版本号
@param[in] value     
            typedef enum
            {
                EN_TOS_BUTTON_VAL_DEFAULT = 0,
                EN_TOS_BUTTON_VAL_LATER,
                EN_TOS_BUTTON_VAL_NEVER
            }EN_BUTTON_VALUE;   
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_setting_set_ui_content(EN_UI_CONTENT e_content, int32_t value);

/**
@brief	得到机器的使用环境

@note  家里，商场，酒店等 。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_get_location(EN_FPI_LOCATION *value);


/**
@brief	设置机器的使用环境

@note  家里，商场，酒店等 。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_setting_set_location(EN_FPI_LOCATION location,EN_ACT_CTRL act);

/**
@brief	获取当前的秒时间

@note  已加上偏移。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_get_current_base_time(int32_t *seconds);
/**
@brief	获取当前的秒时间

@note  未加上偏移。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_get_current_base_time_without_offset(int32_t *seconds);
/**
@brief	获取当前的偏移时间

@note  未加上偏移。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_get_clock_offset(int32_t *seconds);
/**
@brief	秒转化为日期时分秒

@note  未加上偏移。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_utility_second_to_time(int32_t seconds, st_fpi_date *time);
/**
@brief	设置夏令时开关

@note  flase 关，true 开

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/


fpi_error tos_setting_set_time_dst_state(fpi_bool  bEnable);
/**
@brief	获取夏令时开关

@note  flase 关，true 开

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_get_time_dst_state(fpi_bool  *bEnable);
/** 
@brief 市场需求的特殊模式
@param[in] e_param 
              EN_TOS_STADIUM_MODE

@param[out] value 1:on 0:off     
                 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_setting_get_special_mode_enable(EN_TOS_SPECIAL_MODE e_param, int32_t  *value);
/** 
@brief 市场需求的特殊模式
@param[in] e_param 
              EN_TOS_STADIUM_MODE
@param[in] value 1:on 0:off 
@param[in] act 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/


fpi_error tos_setting_set_special_mode_enable(EN_TOS_SPECIAL_MODE e_param, int32_t value, EN_ACT_CTRL act);

/** 
@brief 中间件设置是否支持网络唤醒
@param[in] e_wakeup_mode mode
@param[out]null
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_setting_set_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t mode);


/** 
@brief 中间件获取是否支持网络唤醒
@param[in] e_wakeup_mode 
@param[out]mode
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_setting_get_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t* mode);



/**
@brief	 获取开机向导模式

@note  没有向导就为 E_INSTALL_GUIDE_NONE_MODE

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_get_guide_mode(EN_GUIDE_MODE *mode);


/**
@brief	设置开机向导模式

@note  取消向导就为 E_INSTALL_GUIDE_NONE_MODE

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_guide_mode(EN_GUIDE_MODE mode);


/**
@brief	获得开机向导的某一个功能是否有效

@note  比如是否进行网络的设置或者进行快速搜台等

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_get_guide_modular( EN_GUIDE_MODULAR modular , int16_t *OnOff);
/**
@brief	设置开机向导的某一个功能是否有效

@note  比如是否进行网络的设置或者进行快速搜台等

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_guide_modular( EN_GUIDE_MODULAR modular , int16_t OnOff);


/**
@brief	得到键盘的按键排列情况

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_get_keyboard_layout(EN_FPI_USB_KEYBOARD_LAYOUT *value);
 

/**
@brief	设置键盘的按键排列情况

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_keyboard_layout(EN_FPI_USB_KEYBOARD_LAYOUT layout);

/**
@brief	得到键盘当前的语言

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_get_keyboard_current_lang(EN_FPI_LANGUAGE *CurKeyboardLang);	


/**
@brief	设置键盘当前的语言

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_keyboard_current_lang(EN_FPI_LANGUAGE CurKeyboardLang);	


/**
@brief	得到键盘支持的语言

@note  keyboardLanague 必须是EN_API_KEYBOARD_LANG_MAX 大小的数值，支持的为1，不支持的为0

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 //fpi_error tos_setting_get_keyboard_support_lang(EN_FPI_LANGUAGE *keyboardLanague);

/**
@brief	设置键盘支持的语言

@note  keyboardLanague 必须是EN_API_KEYBOARD_LANG_MAX 大小的数值，支持的为1，不支持的为0

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_keyboard_support_lang(EN_FPI_LANGUAGE *keyboardLanague);


/**
@brief	直接控制

@note  基本不经过中间件，直接空间屏或者硬件。

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_setting_set_direct_ctrl(EN_DIRECT_CTRL type,int16_t switchEnable);


/**
@brief 获取中间件初始化状态

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_setting_get_state(EN_FUNC_STATE_TYPE eState, fpi_bool* enable);

/**
@brief tos_function_set_user_defined_logo 
      设置用户自定义开机logo图片

@param [in] logo_path 用户图片指定路径

@retval 成功返回 FPI_ERROR_SUCCESS;
@retval 失败返回 FPI_ERROR_FAIL
*/
fpi_error tos_function_set_user_defined_logo(char * logo_path);

/**
@brief  设置阻塞修改时间标志

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/


fpi_error tos_setting_time_blocktag(fpi_bool bBlockToModifyTime);

#ifdef __cplusplus
}
#endif
/** @} */

#endif //_FUNCTION_SETTING_H_
