/**@defgroup ��������ģ��
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
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
@brief ���һ�������
**/
typedef enum
{
	EN_REGION_SPAIN,		///<������
	EN_REGION_AUSTRALIA,	///<�Ĵ�����
}EN_REGION_TYPE;

/**
@brief ���ʲô״̬�µ�ʱ��
**/
typedef enum
{
	EN_SETTING_TIME_CURRENT, 	///<��ǰʱ�� ��
	EN_SETTING_TIME_POWERON,		///<����ʱ��
	EN_SETTING_TIME_POWEROFF,		///<�ػ�ʱ��
	EN_SETTING_TIME_SLEEP,		///<˯��ʱ��
	EN_SETTING_TIME_AUTO_STANDBY,
	EN_SETTING_TIME_RUNINGTIME,
}EN_SETTING_TIME_CTRL;


/**
@brief �������̶���
**/
typedef enum
{
	EN_DOWNLOAD_START,  ///<��ʼ
	EN_DOWNLOAD_PAUSE,  ///<��ͣ
	EN_DOWNLOAD_RESTART,
	EN_DOWNLOAD_STOP, ///<ֹͣ,���Զ�ɾ�����ص����,restar = stop + start .

	EN_UPDATE_START,
	EN_UPDATE_STOP,

    EN_UPDATE_CHECK,   //����Ƿ���������
    EN_UPDATE_WITHOUT_REMIND,
	EN_UPDATE_FUTURE_START,	
	EN_UPDATE_FUTURE_CANCEL
}EN_UPDATE_ACTION_CTRL;

/**
@brief ���������򵼵ĸ���ģʽ��������
**/
typedef enum
{
    EN_GUIDE_MODE_NONE_MODE,  ///<������ִ�п�����
    EN_GUIDE_MODE_TV_MODE,
    EN_GUIDE_MODE_ESTICKER_MODE,
    EN_GUIDE_MODE_HOMEPAGE_MODE,
    EN_GUIDE_MODE_INITTIAL_MODE,
} EN_GUIDE_MODE;

/**
@brief �����򵼾��е�һЩ������ģ��
**/
typedef enum
{
	EN_GUIDE_MODULAR_QUICK_SCAN, ///<�Ƿ��п�����̨
	EN_GUIDE_MODULAR_NETWORK,///<�Ƿ�������ģ��
}EN_GUIDE_MODULAR ;

/**
@brief ʱ��
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
@brief �������
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
 @brief ������Ϣ
 **/
 typedef struct
{
    char fileName[API_SW_FILE_NAME_LEN+1];	//full path name (eg: /data/oad_udpate/oad.bin)
    char version[API_SW_VER_LEN];
    char note[API_SW_NOTE_LEN];
    char size[API_SW_FILE_SIZE];
}st_fpi_net_update_info;
 /**
 @brief �豸ʹ�ó���
 **/
typedef enum
{
	E_API_HOME,
	E_API_SHOP,
	E_API_SHOP_WITH_DEMO,
}EN_FPI_LOCATION;
 /**
 @brief ���̱���
 **/
 typedef enum
{
    E_API_KEYBOARD_LAYOUT_AZERTY = 0,
    E_API_KEYBOARD_LAYOUT_QWERTY	
} EN_FPI_USB_KEYBOARD_LAYOUT;
 /**
 @brief ֱ�ӿ���Ӳ��
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
@brief �м����ʼ��״̬
**/
typedef enum
{
	 EN_FUNC_STATE_UNKNOWN,  
	 EN_FUNC_STATE_INIT_FINISH,  // �м����ʼ����ɣ����Խ��е���tos�ӿڣ��л���Դ�Ȳ���
         
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
@brief ��ȡ�˵�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_menu_language(MEMBER_LANGUAGE *value);

/**
@brief ���ò˵�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_menu_language(MEMBER_LANGUAGE language,EN_ACT_CTRL act);


/**
@brief  ��ȡ��ǰʱ��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_time_zone(EN_FPI_TIME_ZONE *value);

/**
@brief ���õ�ǰʱ��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_time_zone(EN_FPI_TIME_ZONE timezone,EN_ACT_CTRL act);


/**
@brief ���ĳһ���ҵ�ʱ��

@note ʱ��value ���ݸù��Ҿ��嶨��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_region(EN_REGION_TYPE region,int32_t *value);


/**
@brief ����ĳһ���ҵ�ʱ��

@note ʱ��value ���ݸù��Ҿ��嶨��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_region(EN_REGION_TYPE region_country,int32_t region,EN_ACT_CTRL act);



/**
@brief  ��ȡ��ǰ�Ƿ���ʱ��ͬ��״̬

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_time_sync(int32_t *value);

/**
@brief	����ʱ��ͬ��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_time_sync(int32_t autosync,EN_ACT_CTRL act);




/**
@brief	���ʱ��

@note  �������ͻ�õ�ǰ�ģ�������ģ��ػ��ģ�˯�ߵ�ʱ�䡣

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_time(EN_SETTING_TIME_CTRL type,st_fpi_date *value);
/**
@brief	����ʱ��

@note  �������ͻ�õ�ǰ�ģ�������ģ��ػ��ģ�˯�ߵ�ʱ�䡣

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_time(EN_SETTING_TIME_CTRL type, st_fpi_date* pst_date,EN_ACT_CTRL act);

/**
@brief	��������

@note  ��ѡ�����������ͣ��Լ����������Ŀ�ʼ����ͣ��ֹͣ

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_updating(EN_FPI_SOFTWARE_UPDATE updateMode ,EN_UPDATE_ACTION_CTRL action );
/**
@brief	�����������Ϣ

@note  ����ȱ������Ϣ����ô��Ϊ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_update_info(EN_FPI_SOFTWARE_UPDATE updateMode,st_fpi_net_update_info *pInfo);
/**
@brief	������������Ϣ

@note  ����ȱ������Ϣ����ô��Ϊ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_update_info(EN_FPI_SOFTWARE_UPDATE updateMode,st_fpi_net_update_info *pInfo,EN_ACT_CTRL act);
/**
@brief	�ж������Ƿ���������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_updating_is_running(EN_FPI_SOFTWARE_UPDATE updateMode ,int32_t *running);


/**
@brief	�ָ���������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_reset_default();


/** 
@brief ��ȡ�Ѿ����ص������ļ��Ĵ�С
@param[in] ��
@param[out] size 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_setting_get_download_file_size(int32_t*size);

/** 
@brief ��ȡ������ʾ�Ի������û���ѡ��
@param[in] e_content 
              CNT_DOWNLOAD_BUTTON, //���ذ���(ѡ��)  
              CNT_UPGRADE_BUTTON,  //��������(ѡ��)
              CNT_SOFTWARE_VERSION //����汾��

@param[out] value     
            typedef enum
            {
                EN_TOS_BUTTON_VAL_DEFAULT = 0,
                EN_TOS_BUTTON_VAL_LATER,
                EN_TOS_BUTTON_VAL_NEVER
            }EN_BUTTON_VALUE;       
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_setting_get_ui_content(EN_UI_CONTENT e_content, int32_t *value);

/** 
@brief ����������ʾ�Ի������û���ѡ���������̸����û������ܲ�ͬ������
@param[in] e_content 
              CNT_DOWNLOAD_BUTTON, //���ذ���(ѡ��)  
              CNT_UPGRADE_BUTTON,  //��������(ѡ��)
              CNT_SOFTWARE_VERSION //����汾��
@param[in] value     
            typedef enum
            {
                EN_TOS_BUTTON_VAL_DEFAULT = 0,
                EN_TOS_BUTTON_VAL_LATER,
                EN_TOS_BUTTON_VAL_NEVER
            }EN_BUTTON_VALUE;   
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_setting_set_ui_content(EN_UI_CONTENT e_content, int32_t value);

/**
@brief	�õ�������ʹ�û���

@note  ����̳����Ƶ�� ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_get_location(EN_FPI_LOCATION *value);


/**
@brief	���û�����ʹ�û���

@note  ����̳����Ƶ�� ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_setting_set_location(EN_FPI_LOCATION location,EN_ACT_CTRL act);

/**
@brief	��ȡ��ǰ����ʱ��

@note  �Ѽ���ƫ�ơ�

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_get_current_base_time(int32_t *seconds);
/**
@brief	��ȡ��ǰ����ʱ��

@note  δ����ƫ�ơ�

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_get_current_base_time_without_offset(int32_t *seconds);
/**
@brief	��ȡ��ǰ��ƫ��ʱ��

@note  δ����ƫ�ơ�

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_get_clock_offset(int32_t *seconds);
/**
@brief	��ת��Ϊ����ʱ����

@note  δ����ƫ�ơ�

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_utility_second_to_time(int32_t seconds, st_fpi_date *time);
/**
@brief	��������ʱ����

@note  flase �أ�true ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/


fpi_error tos_setting_set_time_dst_state(fpi_bool  bEnable);
/**
@brief	��ȡ����ʱ����

@note  flase �أ�true ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_get_time_dst_state(fpi_bool  *bEnable);
/** 
@brief �г����������ģʽ
@param[in] e_param 
              EN_TOS_STADIUM_MODE

@param[out] value 1:on 0:off     
                 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_setting_get_special_mode_enable(EN_TOS_SPECIAL_MODE e_param, int32_t  *value);
/** 
@brief �г����������ģʽ
@param[in] e_param 
              EN_TOS_STADIUM_MODE
@param[in] value 1:on 0:off 
@param[in] act 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/


fpi_error tos_setting_set_special_mode_enable(EN_TOS_SPECIAL_MODE e_param, int32_t value, EN_ACT_CTRL act);

/** 
@brief �м�������Ƿ�֧�����绽��
@param[in] e_wakeup_mode mode
@param[out]null
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_setting_set_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t mode);


/** 
@brief �м����ȡ�Ƿ�֧�����绽��
@param[in] e_wakeup_mode 
@param[out]mode
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_setting_get_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t* mode);



/**
@brief	 ��ȡ������ģʽ

@note  û���򵼾�Ϊ E_INSTALL_GUIDE_NONE_MODE

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_get_guide_mode(EN_GUIDE_MODE *mode);


/**
@brief	���ÿ�����ģʽ

@note  ȡ���򵼾�Ϊ E_INSTALL_GUIDE_NONE_MODE

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_guide_mode(EN_GUIDE_MODE mode);


/**
@brief	��ÿ����򵼵�ĳһ�������Ƿ���Ч

@note  �����Ƿ������������û��߽��п�����̨��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_get_guide_modular( EN_GUIDE_MODULAR modular , int16_t *OnOff);
/**
@brief	���ÿ����򵼵�ĳһ�������Ƿ���Ч

@note  �����Ƿ������������û��߽��п�����̨��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_guide_modular( EN_GUIDE_MODULAR modular , int16_t OnOff);


/**
@brief	�õ����̵İ����������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_get_keyboard_layout(EN_FPI_USB_KEYBOARD_LAYOUT *value);
 

/**
@brief	���ü��̵İ����������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_keyboard_layout(EN_FPI_USB_KEYBOARD_LAYOUT layout);

/**
@brief	�õ����̵�ǰ������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_get_keyboard_current_lang(EN_FPI_LANGUAGE *CurKeyboardLang);	


/**
@brief	���ü��̵�ǰ������

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_keyboard_current_lang(EN_FPI_LANGUAGE CurKeyboardLang);	


/**
@brief	�õ�����֧�ֵ�����

@note  keyboardLanague ������EN_API_KEYBOARD_LANG_MAX ��С����ֵ��֧�ֵ�Ϊ1����֧�ֵ�Ϊ0

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
 //fpi_error tos_setting_get_keyboard_support_lang(EN_FPI_LANGUAGE *keyboardLanague);

/**
@brief	���ü���֧�ֵ�����

@note  keyboardLanague ������EN_API_KEYBOARD_LANG_MAX ��С����ֵ��֧�ֵ�Ϊ1����֧�ֵ�Ϊ0

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_keyboard_support_lang(EN_FPI_LANGUAGE *keyboardLanague);


/**
@brief	ֱ�ӿ���

@note  �����������м����ֱ�ӿռ�������Ӳ����

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_setting_set_direct_ctrl(EN_DIRECT_CTRL type,int16_t switchEnable);


/**
@brief ��ȡ�м����ʼ��״̬

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_setting_get_state(EN_FUNC_STATE_TYPE eState, fpi_bool* enable);

/**
@brief tos_function_set_user_defined_logo 
      �����û��Զ��忪��logoͼƬ

@param [in] logo_path �û�ͼƬָ��·��

@retval �ɹ����� FPI_ERROR_SUCCESS;
@retval ʧ�ܷ��� FPI_ERROR_FAIL
*/
fpi_error tos_function_set_user_defined_logo(char * logo_path);

/**
@brief  ���������޸�ʱ���־

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/


fpi_error tos_setting_time_blocktag(fpi_bool bBlockToModifyTime);

#ifdef __cplusplus
}
#endif
/** @} */

#endif //_FUNCTION_SETTING_H_
