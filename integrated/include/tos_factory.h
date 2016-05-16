#ifndef __TOS_FACTORY_H__
#define __TOS_FACTORY_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" 
{
#endif

#define F1_STRING_NUM 64


typedef struct {		//qiyx add 150817
    int type;               
    int code;               
    unsigned long token;     
    int data1;               
    int data2;              
    void* obj1;              
    void* obj2;              
}TOS_FACCMDS_CMD_PARAM_S;

typedef struct {
    int result;             
    int errCode;            
}TOS_FACCMDS_CMD_RESULT_S;

typedef int (*tos_faccmds_oncommand)(TOS_FACCMDS_CMD_PARAM_S param,void* userdata);

typedef struct
{
	int r_gain;
	int g_gain;
	int b_gain;
	int r_offset;
	int g_offset;
	int b_offset;
} TOS_FAC_WHITE_BALANCE_T;

typedef enum
{
    WB_R_GAIN,
    WB_G_GAIN,
    WB_B_GAIN,
    WB_R_OFFSET,
    WB_G_OFFSET,
    WB_B_OFFSET
}EN_FAC_WB_ITEM;

typedef enum
{
    CONTENT_ALL,          // ��¡all
    CONTENT_CHANNEL,      // ��¡Ƶ���б�
    CONTENT_SYS_SETTING,  //
    CONTENT_USER_SETTING, // ��¡�û�����
	CONTENT_HOTEL_DATA,   // �����Ƶ��¡������
    CONTENT_324_IMAGE_BACKUP
}EN_FAC_CLONE_CONTENT;

typedef enum
{
    DIRECTION_TV_TO_USB,  // TV �� USB
    DIRECTION_USB_TO_TV   // USB�� TV
}EN_FAC_CLONE_DIRECTION;

typedef enum
{
    SYSTEM_INFO_SERIAL_NUMBER, // ���к�
    SYSTEM_INFO_REGISTER_CODE, // ע����
    SYSTEM_INFO_CLIENT_TYPE,   // Client type
    SYSTEM_INFO_DEVICE_ID,     // Device ID
    SYSTEM_INFO_USER_ID,       // User ID
    SYSTEM_INFO_MAC_ADDR,      // MAC��ַ
    SYSTEM_INFO_NETFIX_ESN,    // ESN Key
    SYSTEM_INFO_BUILD_TIME,    // ����ʱ��
	SYSTEM_INFO_HDCP_TYPE_1, //HDCPkey1.0 
	SYSTEM_INFO_HDCP_TYPE_2, //HDCPkey2.0 
	SYSTEM_INFO_CI_KEY, 	//CIKey
    SYSTEM_INFO_TYPE_NUM
}EN_FAC_SYSTEM_INFO_TYPE;

typedef enum
{
    TYPE_MAIN_VERSION,  // ������汾�� 
    TYPE_FRC_VERSION,   // FRC�汾�� 
    TYPE_UBOOT_VERSION, // UBOOT�汾��
    TYPE_STBC_VERSION,   // STBC�汾��
    TYPE_SITAS_VERSION,//�м���汾��
    TYPE_SITAS_BUILD, //�м��build��
    TYPE_LOCAL_DIMMING_VERSION  //local dimming�汾��
}EN_FAC_FIRMWARE_TYPE;

typedef enum
{
    WORK_MODE_D_MODE,      // ���ʦģʽ��1950����
    WORK_MODE_P_MODE,      // ����ģʽ, 9735
    WORK_MODE_PS_MODE,     // ��������ģʽ
    WORK_MODE_WARM_UP_MODE, // �ϻ�ģʽ
    WORK_MODE_PANEL_TEST_MODE,	//  ��������¼��л���ͬ��ɫ
    WORK_MODE_KEYPAD_TEST_MODE	// ÿ��������Ӧһ����ɫ
}EN_FAC_WORK_MODE;

typedef enum
{
    UPGRADE_TYPE_MEMC,        // USB����FRC
    UPGRADE_TYPE_MBOOT,       // USB����MBOOOT
    UPGRADE_TYPE_MAC_ADDR,    // USB����MAC��ַ
    UPGRADE_TYPE_ESN_KEY,     // USB����ESN Key
    UPGRADE_TYPE_HDCP_KEY,    // USB����HDCP KEY
    UPGRADE_TYPE_CI_PLUS_KEY,  // USB����CI PLUS KEY
    //add by @hh
    UPGRADE_TYPE_MAIN_UPGRADE,	//USB����MAIN������ 
    UPGRADE_TYPE_NVM_UPGRADE,	//��USB��¡�����ݿ�
    UPGRADE_TYPE_NVM_BACKUP,	//�������ݿ⵽USB
    UPGRADE_TYPE_CH_LIST_UPGRADE,	//��USB��¡Ƶ����Ϣ
    UPGRADE_TYPE_CH_LIST_BACKUP,	//����Ƶ����Ϣ��USB
    UPGRADE_TYPE_FRC_IMAGE_UPGRADE,	//USB����FRC_IMAGE
    UPGRADE_TYPE_FRC_IMAGE_BACKUP,	//����FRC_IMAGE��USB
	UPGRADE_TYPE_USER_SETTING_UPGRADE,	//��USB��¡�û����ݵ�����
	UPGRADE_TYPE_USER_SETTING_BACKUP,	//�����û����ݵ�USB
	UPGRADE_TYPE_HDCP_KEY_2_0,	// USB����HDCP KEY2.0
	//end by @hh
	//add by @dmt.zhy
	UPGRADE_TYPE_LOCAL_DIMMING	// USB���� local dimming
	//end by @dmt.zhy
}EN_FAC_UPGRADE_TYPE;

typedef enum
{
    RESET_SHOP,  // Reset shop
    NVM_RESET,  // Nvm Reset in Factory
    RESET_ALL,    // Reset all in other Menu
    RESET_USERDATA,	//add by @hh for userdata reset
	RESET_CHANNEL,	//add by @hh for channel reset
	RESET_NETWORK,	//add by @hh for network reset
	RESET_OTHER,		//add by @hh for other data reset
	RESET_USER_PARTITION//add linshund ,��λ�û�����
}EN_FAC_RESET_TYPE;

typedef enum
{
    AREA_HUIZHOU_FACTORY,  		//���ݹ���
    AREA_POLAND_FACTORY,   		//��������
    AREA_MONGOLIA_FACTORY, 		//���ɹŹ���
	AREA_WUXI_FACTORY,			//��������		
	AREA_PRESET_FACTORY,		//Ĭ��Ԥ��
	AREA_ALGERIA_FACTORY,  //5	//���������ǹ���
    AREA_ODM_FACTORY,       	//ODM���� 
    AREA_YN_FACTORY,  			//Խ�Ϲ���
    AREA_TH_FACTORY, 			//̩������
    AREA_PH_FACTORY, 			//PH����
    AREA_IN_FACTORY,	   //10 	//IN����
    AREA_RU_FACTORY, 			//RU����
    AREA_CVT_FACTORY,			//CVT����
	AREA_TUNISIA_FACTORY, 		//ͻ��˹����, 12��1.0�м����CVTռ�ã�Ϊ�˱����ص���ʱʹ��13��֮��������м������ͬ������
	AREA_RU_PKV_FACTORY,		//����˹�ͻ�PKV����
	AREA_NA_MEXICO_FACTORY,//15	//���� ī���繤��
}EN_FAC_PRESET_AREA;

typedef enum
{
    POWER_ON_MODE_ON,
    POWER_ON_MODE_STB,
    POWER_ON_MODE_LAST
}EN_FAC_POWER_ON_MODE;

typedef enum
{
    CURVE_TYPE_BACKLIGHT,
    CURVE_TYPE_BRIGHTNESS,
    CURVE_TYPE_CONTRAST,
    CURVE_TYPE_SATURATION,
    CURVE_TYPE_SHARPNESS,
    CURVE_TYPE_TINT
}EN_FAC_PICTURE_CURVE_TYPE;

typedef struct
{
    uint8_t u8OSD_0;
    uint8_t u8OSD_25;
    uint8_t u8OSD_50;
    uint8_t u8OSD_75;
    uint8_t u8OSD_100;
} TOS_SERVICE_USER_NONLINEAR_CURVE_T;

typedef struct
{
    fpi_bool b_enable;
    uint16_t ui2_modulation; // SSC span
    uint16_t ui2_percentage; // SSC step
}TOS_FAC_SSC_SETTING_T;

typedef enum
{
    SSC_TYPE_DDR,
    SSC_TYPE_FRC,
    SSC_TYPE_LVDS,
    SSC_TYPE_OSD
}EN_FAC_SSC_TYPE;

typedef enum
{
    H_POSITION,
    H_SIZE,
    V_POSITION,
    V_SIZE
}EN_FAC_OVERSCAN_ITEM;

typedef enum
{
	EN_FAC_COLOR_TEMP_COOL = 0,
	EN_FAC_COLOR_TEMP_STD,
	EN_FAC_COLOR_TEMP_WARM,
	EN_FAC_COLOR_TEMP_PERSONAL,
    EN_FAC_COLOR_TEMP_CUSTOM_1,
	EN_FAC_COLOR_TEMP_NUM
}EN_FAC_COLOR_TEMP;

typedef enum
{
    FUNC_TYPE_UART_DEBUG,   // ���ڵ���
    FUNC_TYPE_WSS_AFD,      // WSS��AFD
    FUNC_TYPE_BGM,          // BGM����
    FUNC_TYPE_4K1K,         // 4K1K����
    FUNC_TYPE_WATCH_DOG,    // ���Ź�
    FUNC_TYPE_PVR,          // PVR
    FUNC_TYPE_PANEL_KEY,    //��尴��
    FUNC_TYPE_GREY_CTRL,    // ����SHOPģʽ��Picture�˵��Ƿ��ѡ
    FUNC_TYPE_CHILD_MODE,    //��ͯģʽ
    FUNC_TYPE_LOG_SAVE,     //��LOG�����FLASH ��
    FUNC_TYPE_LOG_COPY,		//��LOG��������
}EN_FAC_FUNC_TYPE;

typedef struct
{
    uint8_t low_apl1;    //for CN means bke
    uint8_t low_apl1_bl; //for CN means bke_std
    uint8_t low_k;       //Not used for CN
    uint8_t low_apl2; 
    uint8_t low_bp;     
    uint8_t high_apl1;    //Not used for CN
    uint8_t high_apl1_bl; //Not used for CN
    uint8_t high_k;       //Not used for CN
    uint8_t high_apl2;    //Not used for CN
    uint8_t high_bp;      //Not used for CN
    uint8_t dbc_mode;
    fpi_bool dbc_enable;
    fpi_bool b_print_enable;
}TOS_FAC_DBC_SETTING_T;

typedef struct
{
    uint8_t adc_min;
    uint8_t adc_max;
    uint8_t bright_low;
}TOS_FAC_LIGHT_SENSOR_ARG_T;

typedef enum
{
    TYPE_USER_ID,
    TYPE_CI_KEY_UPGRADED,
    TYPE_SHOP_INIT,
    TYPE_INTERNAL_PATTERN
}EN_FAC_QUERY_TYPE;

typedef enum
{
	EN_T2_SUPPORT_OFF= 0,
	EN_T2_SUPPORT_ON,
	EN_T2_SUPPORT_BY_COUNTRY,
    EN_T2_SUPPORT_NUMBER
}EN_T2_SUPPORT_STATE;

typedef enum 
{
   EN_TOS_FAC_BLUETOOTH_3D_WORK,
   EN_TOS_FAC_BLUETOOTH_3D_SYNC
}EN_TOS_FAC_BLUETOOTH_STATE_TYPE;

typedef struct
{
    char project_name[F1_STRING_NUM];
    char siacp_ver[F1_STRING_NUM];
    char compile_date[F1_STRING_NUM];
    char panel_name[F1_STRING_NUM];
    char chassis[F1_STRING_NUM];
    char manufacturer[F1_STRING_NUM];
    char rcu_name[F1_STRING_NUM];
    char region[F1_STRING_NUM];
    char psu_name[F1_STRING_NUM];
}fac_product_info_data_t;

#define TOS_DATA_NUM  10

typedef struct
{
    uint8_t red_gain;
    uint8_t green_gain;
    uint8_t blue_gain;
}TOS_RGB_DATA_T;

typedef struct
{
    uint8_t ui1_idx;
    TOS_RGB_DATA_T rgb_data[TOS_DATA_NUM];
}TOS_TEN_P_DATA_T;



/** 
@brief ��ȡ���̲˵��еĸ���ģʽ��״̬����:����ģʽ(Pģʽ)�����ʦģʽ(Dģʽ)���ϻ�ģʽ
@param[in] e_work_mode ��ʾҪ��ȡ�ĸ�ģʽ��״̬
@param[out] ui1_mode ����ȡ����״̬��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_work_mode(EN_FAC_WORK_MODE e_work_mode, uint8_t *ui1_mode);

/** 
@brief ���ù��̲˵��еĸ���ģʽ����:����ģʽ(Pģʽ)�����ʦģʽ(Dģʽ)���ϻ�ģʽ
@param[in] e_work_mode ��ʾҪ��ȡ�ĸ�ģʽ��״̬
@param[in] ui1_mode Ҫ���õ�״̬
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_work_mode(EN_FAC_WORK_MODE e_work_mode, uint8_t ui1_mode);

/** 
@brief ��ȡ���кš�ע���롢Client type��Device ID��MAC��ַ��ϵͳ��Ϣ
@param[in] e_info_type ��ʾҪ��ȡ������Ϣ
@param[out] ps_info ����ȡ������Ϣ��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_system_info(EN_FAC_SYSTEM_INFO_TYPE e_info_type, char *ps_info, int32_t i4_len);

/** 
@brief ��ȡ������汾����������Э��汾��FRC����汾��
@param[in] e_info_type ��ʾҪ��ȡ������Ϣ
@param[out] ps_version ����ȡ���İ汾��Ϣ��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_version(EN_FAC_FIRMWARE_TYPE e_fr_type, char * ps_version, int32_t i4_len);

//====================Amy start Panel ID==========================================
/** 
@brief ��ȡPanel ID
@param[out] ui2_id ����ȡ����ID
@param[out] ui2_id ����ID��
@return FPI_ERROR_SUCCESS:��ȡ�ɹ�;
		FPI_ERROR_FAIL:��ȡʧ��
		FPI_ERROR_PANEL_ID_NOT_SUPPORT :��֧��PANEL ID��������֮ǰ����project id��û��Panel id������������ж�	*/
fpi_error tos_factory_get_panel_id(uint16_t *ui2_id, uint16_t *ui2_max_id);

/** 
@brief ����Panel ID
@param[out] ui2_id ��Ҫ���õ�ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_panel_id(uint16_t ui2_id);

/** 
@brief ��ȡPanel NAME
@param[out] panelName ����ȡ����ӦID��PanelName
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_panel_name(char* panelName);


//====================Amy end Panel ID==========================================


/** 
@brief ��ȡProject ID
@param[out] ui2_id ����ȡ����ID
@param[out] ui2_id ����ID��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_project_id(uint16_t *ui2_id, uint16_t *ui2_max_id);

/** 
@brief ����Project ID
@param[out] ui2_id ��Ҫ���õ�ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_project_id(uint16_t ui2_id);

/** 
@brief USB��¡,ͨ��USB�������ļ��е����ÿ�¡��TV��
@param[in] e_direction  FAC_CLONE_TV_TO_USB: ��ʾ��TV��¡��USBUSB��¡��TV
                        FAC_CLONE_USB_TO_TV: ��ʾ��USB��¡��TV
@param[in]e_content ��ʾ��¡������,������Ŀ�б�/ϵͳ����/�û����õ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_usb_clone(EN_FAC_CLONE_DIRECTION e_direction, EN_FAC_CLONE_CONTENT e_content);

/** 
@brief ͨ��USB�����������MEMC��MBOOT��MAC��ַ��ESN/HDCP/CI+ Key��
@param[in] e_upgrade_type ��ʾҪͨ��USB�������ļ�������
@param
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_usb_upgrade(EN_FAC_UPGRADE_TYPE e_upgrade_type);


/** 
@brief ͨ��USB�����������MEMC��MBOOT��MAC��ַ��ESN/HDCP/CI+ Key��
@param[in] e_reset_type RESET_SHOP ��ʾ��λ�û�����
@param                  RESET_ALL  ��ʾ��λ�û������Լ���������(MAC/HDCP/SN�ȹ̻����ݳ���)
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_reset(EN_FAC_RESET_TYPE e_reset_type);

/** 
@brief ��ƽ�������ʼ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_wb_setting_init(void);

/** 
@brief Ƶ��Ԥ��
@param[in] e_preset_area ���ݲ�ͬ������Ԥ�ò�ͬ�Ľ�Ŀ�б�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_preset_channel(EN_FAC_PRESET_AREA e_preset_area);

/** 
@brief ��ȡƵ��Ԥ�õ�����
@param[out] pe_preset_area ��ǰԤ��Ƶ��������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_preset_area(EN_FAC_PRESET_AREA *pe_preset_area);

/** 
@brief ��ȡ�ϵ�ģʽ
@param[in] e_power_mode  POWERON_MODE_ON    �ϵ翪��      
                         POWERON_MODE_STB   �ϵ����
                         POWERON_MODE_LAST  �ϵ�����ϴιػ���״̬
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_power_on_mode(EN_FAC_POWER_ON_MODE *e_power_mode);

/** 
@brief �����ϵ�ģʽ
@param[in] e_power_mode  POWERON_MODE_ON    �ϵ翪��      
                         POWERON_MODE_STB   �ϵ����
                         POWERON_MODE_LAST  �ϵ�����ϴιػ���״̬
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_power_on_mode(EN_FAC_POWER_ON_MODE e_power_mode);

/** 
@brief ��ȡͼ�������и�ѡ������ߣ�����Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_type :Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[out] pt_curve  :��ȡ��������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_picture_curve(EN_FAC_PICTURE_CURVE_TYPE e_curve_type, TOS_SERVICE_USER_NONLINEAR_CURVE_T *pt_curve);

/** 
@brief ����ͼ�������и�ѡ������ߣ�����Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_type :Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_item :�������Ա��� ,0/25/50/75/100�����
@param[in] value      :Ҫ���õ����߽ڵ�ֵ0-100
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_picture_curve(EN_FAC_PICTURE_CURVE_TYPE e_curve_type, uint8_t ui1_item, uint8_t ui1_val);

/** 
@brief ��ȡ��������
@param[out] pt_curve  :��ȡ��������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_sound_curve(TOS_SERVICE_USER_NONLINEAR_CURVE_T *pt_curve);

/** 
@brief ������������
@param[in] ui1_curve_item  : �������Ա��� ,0/25/50/75/100�����
@param[in] ui1_val         :Ҫ���õ����߽ڵ�ֵ0-100
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_sound_curve(uint8_t ui1_curve_item, uint8_t ui1_val);


/** 
@brief ��ȡչƵ����
@param[in] e_ssc_type: SSC_TYPE_DDR��SSC_TYPE_FRC��SSC_TYPE_LVDS��SSC_TYPE_OSD
@param[out]pt_ssc_val:  typedef struct
                        {
                            fpi_bool b_enable;
                            uint16_t ui2_modulation; // SSC span
                            uint16_t ui2_percentage; // SSC step
                        }TOS_FAC_SSC_SETTING_T;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_ssc_setting(EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T *pt_ssc_arg);

/** 
@brief ����չƵ����
@param[in] e_ssc_type: SSC_TYPE_DDR��SSC_TYPE_FRC��SSC_TYPE_LVDS��SSC_TYPE_OSD
@param[in] pt_ssc_val: typedef struct
                       {
                           fpi_bool b_enable;
                           uint16_t ui2_modulation; // SSC span
                           uint16_t ui2_percentage; // SSC step
                       }TOS_FAC_SSC_SETTING_T;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_ssc_setting(EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T t_ssc_arg);

/** 
@brief ��ȡoverscan�ĵ�ǰ����
@param[in] e_item : H_POSITION, H_SIZE, V_POSITION, V_SIZE
@param[out] i4_val: ��ȡ���Ĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_overscan(EN_FAC_OVERSCAN_ITEM e_item, int32_t *i4_val);

/** 
@brief ����overscan
@param[in] e_item : H_POSITION, H_SIZE, V_POSITION, V_SIZE
@param[in] ui1_val: Ҫ���õĲ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_overscan(EN_FAC_OVERSCAN_ITEM e_item, uint8_t ui1_val);

/** 
@brief ��ȡ������ƽ������
@param[in] e_color_temp : ɫ��cool/standard/warm
@param[out] pt_wb: ��ȡ��������
                    int r_gain:-128-127
                	  int g_gain:-128-127
                	  int b_gain:-128-127
                	  int r_offset:-128-127
                	  int g_offset:-128-127
                	  int b_offset:-128-127//�����hdmi��dtv��Դ�µı�׼ɫ���£�����0-255
                	  int brightness:0-255
                	  int contrast:0-255
                	  int saturation:0-255
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_wb_setting(EN_FAC_COLOR_TEMP e_color_temp, TOS_FAC_WHITE_BALANCE_T *pt_wb);

/** 
@brief ���ù�����ƽ������
@param[in] e_color_temp : ɫ��cool/standard/warm
@param[in] curve_item   : R/G/B/ Gain & Offset
@param[in] value        : ��Ҫ���õ�ֵ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_wb_setting(EN_FAC_COLOR_TEMP e_color_temp, EN_FAC_WB_ITEM curve_item, int32_t value);

/** 
@brief ¼��TS��
@param[in]��
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_record_ts_stream(void);

/** 
@brief ����E_Sticker
@param[in]��
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_update_e_sticker(void);

/** 
@brief ����Device ID�Ƿ�OK
@param[in]��
@param[out]b_success :fpi_true���Գɹ���fpi_false:����ʧ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_test_device_id(fpi_bool *b_success);

/** 
@brief ����CI Key
@param[in]��
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_erase_ci_key(void);

/** 
@brief �ӹ����˵��л�ȡĳЩ����ʹ�ܻ��߽��õ�״̬
@param[in] e_fun_type:
            typedef enum
            {
                FUNC_TYPE_UART_DEBUG,   //���ڵ���
                FUNC_TYPE_WSS_AFD,      //WSS��AFD
                FUNC_TYPE_BGM,          //BGM����
                FUNC_TYPE_4K1K,         // 4K1K����
                FUNC_TYPE_WATCH_DOG,    // ���Ź�
                FUNC_TYPE_PVR           // PVR
                FUNC_TYPE_PANEL_KEY,    //��尴��
                FUNC_TYPE_GREY_CTRL     //����SHOPģʽ��Picture�˵��Ƿ��ѡ
            }EN_FAC_FUNC_TYPE;
@param[in] b_enable: fpi_trueΪʹ�ܸù��ܣ�fpi_falseΪ���øù���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_func_enable(EN_FAC_FUNC_TYPE e_fun_type, fpi_bool *b_enable);

/** 
@brief �ӹ����˵��н�ĳЩ����ʹ�ܻ��߽���
@param[in] e_fun_type:
            typedef enum
            {
                FUNC_TYPE_UART_DEBUG,   //���ڵ���
                FUNC_TYPE_WSS_AFD,      //WSS��AFD
                FUNC_TYPE_BGM,          //BGM����
                FUNC_TYPE_4K1K,         // 4K1K����
                FUNC_TYPE_WATCH_DOG,    // ���Ź�
                FUNC_TYPE_PVR           // PVR
                FUNC_TYPE_PANEL_KEY,    //��尴��
                FUNC_TYPE_GREY_CTRL     //����SHOPģʽ��Picture�˵��Ƿ��ѡ
            }EN_FAC_FUNC_TYPE;
@param[in] b_enable: fpi_trueΪʹ�ܸù��ܣ�fpi_falseΪ���øù���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_func_enable(EN_FAC_FUNC_TYPE e_fun_type, fpi_bool b_enable);

/** 
@brief ��ȡ��̬�������
@param[out] pt_dbc_setting
                    uint8_t low_apl1;    //for CN means bke
                    uint8_t low_apl1_bl; //for CN means bke_std
                    uint8_t low_k;       //Not used for CN
                    uint8_t low_apl2; 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_dbc_setting(TOS_FAC_DBC_SETTING_T *pt_dbc_setting);

/** 
@brief ���ö�̬������Ҫ�õ��Ĳ���
@param[in] t_dbc_setting
                    uint8_t low_apl1;    //for CN means bke
                    uint8_t low_apl1_bl; //for CN means bke_std
                    uint8_t low_k;       //Not used for CN
                    uint8_t low_apl2; 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_dbc_setting(TOS_FAC_DBC_SETTING_T t_dbc_setting);

/** 
@brief ��ȡlight sensor������������
@param[out] pt_sensor_arg
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_light_sensor_setting(TOS_FAC_LIGHT_SENSOR_ARG_T *pt_sensor_arg);

/** 
@brief ����light sensor������������
@param[in] t_sensor_arg
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_light_sensor_setting(TOS_FAC_LIGHT_SENSOR_ARG_T t_sensor_arg);

/** 
@brief ���ÿ���logo
@param[in]��
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_power_on_logo(void);
    
/** 
@brief ��ȡCI Key������
@param[out] ps_name 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_ci_key_name(char * ps_name, int32_t i4_ret);

/** 
@brief ��ȡCI KEY��USER ID��д״̬����������״̬��Reset shop״̬
@param[in] e_type :
            typedef enum
            {
                TYPE_USER_ID,
                TYPE_CI_KEY,
                TYPE_BLUE_SYNC,
                TYPE_BLUE_TOOTH_WORK,    
                TYPE_SHOP_INIT
            }EN_FAC_QUERY_TYPE;
@param[out] b_state 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_statu(EN_FAC_QUERY_TYPE e_type, fpi_bool * b_state);

/** 
@brief ����CI KEY��USER ID��д״̬����������״̬��Reset shop״̬
@param[in] e_type :
            typedef enum
            {
                TYPE_USER_ID,
                TYPE_CI_KEY,
                TYPE_BLUE_SYNC,
                TYPE_BLUE_TOOTH_WORK,    
                TYPE_SHOP_INIT
            }EN_FAC_QUERY_TYPE;
@param[out] b_state 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_statu(EN_FAC_QUERY_TYPE e_type, fpi_bool b_state);

/** 
@brief ��ȡDVB T2��֧��״̬��
@param[out] pe_state
            typedef enum
            {
                EN_T2_SUPPORT_OFF= 0,     // ��֧��T2
                EN_T2_SUPPORT_ON,         // ֧��T2
                EN_T2_SUPPORT_BY_COUNTRY, // ���ݹ����ж��Ƿ�֧��T2
                EN_T2_SUPPORT_NUMBER
            }EN_T2_SUPPORT_STATE;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_t2_support_state(EN_T2_SUPPORT_STATE *pe_state);

/** 
@brief ����DVB T2��֧��״̬��
@param[in]e_state
            typedef enum
            {
                EN_T2_SUPPORT_OFF= 0,     // ��֧��T2
                EN_T2_SUPPORT_ON,         // ֧��T2
                EN_T2_SUPPORT_BY_COUNTRY, // ���ݹ����ж��Ƿ�֧��T2
                EN_T2_SUPPORT_NUMBER
            }EN_T2_SUPPORT_STATE;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_t2_support_state(EN_T2_SUPPORT_STATE e_state);

/** 
@brief ��ȡд�������ļ�ini�еĲ�Ʒ��Ϣ
@param[in]��
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_product_info(fac_product_info_data_t * pt_info);

/** 
@brief ������Ļmute����ɫ����������ģ���ϻ�ģʽ�Լ�����pattern�л�����
@param[in]ui4_color
                #define SCREEN_MUTE_BLACK       0x0
                #define SCREEN_MUTE_RED         0xff000000
                #define SCREEN_MUTE_GREEN       0x00ff0000
                #define SCREEN_MUTE_BLUE        0x0000ff00
                #define SCREEN_MUTE_WHITE       0xffffffff
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_mute_color(uint32_t ui4_color, fpi_bool b_mute);

/** 
@brief ��ȡ3D�����۾���ͬ��״̬
@param[out]*ui1_state
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_bluetooth_3d_state(EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t *ui1_state);

/** 
@brief ����3D�����۾���ͬ��״̬
@param[in]ui1_state
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_bluetooth_3d_state(EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t ui1_state);

/** 
@brief ��ȡ��ǰ��Ӫ�̵�����
@param[in]��
@param[out]ui1_operator_name
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_current_operator_name(uint8_t * ui1_operator_name);

/** 
@brief ѡ�����õ�ǰ��Ӫ�̣���Ҫ������Ӫ��ѡ���б��а����Ҽ�ѡ����Ӫ�̵�ʱ�����
@param[in]b_flag
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_operator_on_off(fpi_bool b_flag);

/** 
@brief ��ȡ10P��ƽ������
@param[in]��
@param[out]pt_data
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_10p_data(TOS_TEN_P_DATA_T *pt_data);

/** 
@brief ����10P��ƽ������
@param[in]pt_data
@param[out]
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_set_10p_data(TOS_TEN_P_DATA_T *pt_data);

/** 
@brief ��10P��ƽ�����ݸ�λΪĬ��ֵ
@param[in]pt_data
@param[out]
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_reset_10p_data(void);

/** 
@brief ��ȡ�Ƿ���U�̲��ϵ�״̬
@param[in]��
@param[out]b_value
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_usb_state(fpi_bool *b_value);

/** 
@brief ��ȡ�����ļ�������
@param[in]��
@param[out]ui1_number
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_upgrade_file_number(uint8_t *ui1_number);

/** 
@brief �м����ȡң������ֵ
@param[in] ui4_key_code
@param[out]b_value
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_remote_pro(uint32_t ui4_key_code);

/** 
@brief �м����ӻص�����
@param[in] oncommand
@param[out]userdata
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_cmds_addcallback(tos_faccmds_oncommand oncommand,void* userdata);
 
/** 
@brief �м��ɾ���ص�����
@param[in] oncommand
@param[out]userdata
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_cmds_removecallback(tos_faccmds_oncommand oncommand,void* userdata);

//fpi_error tos_faccmds_confirm(unsigned long token,TOS_FACCMDS_CMD_RESULT_S* result);

/** 
@brief  ���netflix ��Ϣ
@param NONE
@return      FPI_ERROR_SUCCESS�����ɹ�;
             FPI_ERROR_FAIL  ����ʧ��*/ 

fpi_error tos_factory_erase_netflix(void);

/** 
@brief ��ȡgamma offsetֵ
@param[in] ��
@param[out]offset
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_factory_get_gamma_offset(int * offset);


/**
@brief ��ȡproject id�б�

@param[in, out] int *buf , int *count

@note ����project id �����������ڽ��̼�ͨ�ŵ�ʱ����Ҫ֪��buf�Ĵ�С
@note ʹ��ʱ��Ҫ�������δ˺�������һ�λ�ȡ�ܸ������ڶ��δ�count��Ԫ�ص�buf����
@note buf == NULL����project id �ܸ�����ֵ��count
@note buf != NULL����ÿһ��project id ��ֵ��buf(��ʱcountΪbuf��Ԫ�ظ���)
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_factory_get_projectID_array(int *buf, int *count);    

#ifdef __cplusplus
}
#endif


#endif


