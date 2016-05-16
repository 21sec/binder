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
    CONTENT_ALL,          // 克隆all
    CONTENT_CHANNEL,      // 克隆频道列表
    CONTENT_SYS_SETTING,  //
    CONTENT_USER_SETTING, // 克隆用户设置
	CONTENT_HOTEL_DATA,   // 工厂酒店克隆的数据
    CONTENT_324_IMAGE_BACKUP
}EN_FAC_CLONE_CONTENT;

typedef enum
{
    DIRECTION_TV_TO_USB,  // TV 到 USB
    DIRECTION_USB_TO_TV   // USB到 TV
}EN_FAC_CLONE_DIRECTION;

typedef enum
{
    SYSTEM_INFO_SERIAL_NUMBER, // 序列号
    SYSTEM_INFO_REGISTER_CODE, // 注册码
    SYSTEM_INFO_CLIENT_TYPE,   // Client type
    SYSTEM_INFO_DEVICE_ID,     // Device ID
    SYSTEM_INFO_USER_ID,       // User ID
    SYSTEM_INFO_MAC_ADDR,      // MAC地址
    SYSTEM_INFO_NETFIX_ESN,    // ESN Key
    SYSTEM_INFO_BUILD_TIME,    // 编译时间
	SYSTEM_INFO_HDCP_TYPE_1, //HDCPkey1.0 
	SYSTEM_INFO_HDCP_TYPE_2, //HDCPkey2.0 
	SYSTEM_INFO_CI_KEY, 	//CIKey
    SYSTEM_INFO_TYPE_NUM
}EN_FAC_SYSTEM_INFO_TYPE;

typedef enum
{
    TYPE_MAIN_VERSION,  // 主软件版本号 
    TYPE_FRC_VERSION,   // FRC版本号 
    TYPE_UBOOT_VERSION, // UBOOT版本号
    TYPE_STBC_VERSION,   // STBC版本号
    TYPE_SITAS_VERSION,//中间件版本号
    TYPE_SITAS_BUILD, //中间件build号
    TYPE_LOCAL_DIMMING_VERSION  //local dimming版本号
}EN_FAC_FIRMWARE_TYPE;

typedef enum
{
    WORK_MODE_D_MODE,      // 设计师模式，1950进入
    WORK_MODE_P_MODE,      // 工厂模式, 9735
    WORK_MODE_PS_MODE,     // 工厂调试模式
    WORK_MODE_WARM_UP_MODE, // 老化模式
    WORK_MODE_PANEL_TEST_MODE,	//  按面板上下键切换不同颜色
    WORK_MODE_KEYPAD_TEST_MODE	// 每个按键对应一种颜色
}EN_FAC_WORK_MODE;

typedef enum
{
    UPGRADE_TYPE_MEMC,        // USB升级FRC
    UPGRADE_TYPE_MBOOT,       // USB升级MBOOOT
    UPGRADE_TYPE_MAC_ADDR,    // USB升级MAC地址
    UPGRADE_TYPE_ESN_KEY,     // USB升级ESN Key
    UPGRADE_TYPE_HDCP_KEY,    // USB升级HDCP KEY
    UPGRADE_TYPE_CI_PLUS_KEY,  // USB升级CI PLUS KEY
    //add by @hh
    UPGRADE_TYPE_MAIN_UPGRADE,	//USB升级MAIN主程序 
    UPGRADE_TYPE_NVM_UPGRADE,	//从USB克隆到数据库
    UPGRADE_TYPE_NVM_BACKUP,	//复制数据库到USB
    UPGRADE_TYPE_CH_LIST_UPGRADE,	//从USB克隆频道信息
    UPGRADE_TYPE_CH_LIST_BACKUP,	//复制频道信息到USB
    UPGRADE_TYPE_FRC_IMAGE_UPGRADE,	//USB升级FRC_IMAGE
    UPGRADE_TYPE_FRC_IMAGE_BACKUP,	//复制FRC_IMAGE到USB
	UPGRADE_TYPE_USER_SETTING_UPGRADE,	//从USB克隆用户数据到电视
	UPGRADE_TYPE_USER_SETTING_BACKUP,	//复制用户数据到USB
	UPGRADE_TYPE_HDCP_KEY_2_0,	// USB升级HDCP KEY2.0
	//end by @hh
	//add by @dmt.zhy
	UPGRADE_TYPE_LOCAL_DIMMING	// USB升级 local dimming
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
	RESET_USER_PARTITION//add linshund ,复位用户分区
}EN_FAC_RESET_TYPE;

typedef enum
{
    AREA_HUIZHOU_FACTORY,  		//惠州工厂
    AREA_POLAND_FACTORY,   		//波兰工厂
    AREA_MONGOLIA_FACTORY, 		//内蒙古工厂
	AREA_WUXI_FACTORY,			//无锡工厂		
	AREA_PRESET_FACTORY,		//默认预留
	AREA_ALGERIA_FACTORY,  //5	//阿尔及利亚工厂
    AREA_ODM_FACTORY,       	//ODM工厂 
    AREA_YN_FACTORY,  			//越南工厂
    AREA_TH_FACTORY, 			//泰国工厂
    AREA_PH_FACTORY, 			//PH工厂
    AREA_IN_FACTORY,	   //10 	//IN工厂
    AREA_RU_FACTORY, 			//RU工厂
    AREA_CVT_FACTORY,			//CVT工厂
	AREA_TUNISIA_FACTORY, 		//突尼斯工厂, 12在1.0中间件被CVT占用，为了避免重叠暂时使用13，之后对三套中间件进行同步整理
	AREA_RU_PKV_FACTORY,		//俄罗斯客户PKV工厂
	AREA_NA_MEXICO_FACTORY,//15	//北美 墨西哥工厂
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
    FUNC_TYPE_UART_DEBUG,   // 串口调试
    FUNC_TYPE_WSS_AFD,      // WSS和AFD
    FUNC_TYPE_BGM,          // BGM功能
    FUNC_TYPE_4K1K,         // 4K1K功能
    FUNC_TYPE_WATCH_DOG,    // 看门狗
    FUNC_TYPE_PVR,          // PVR
    FUNC_TYPE_PANEL_KEY,    //面板按键
    FUNC_TYPE_GREY_CTRL,    // 控制SHOP模式下Picture菜单是否灰选
    FUNC_TYPE_CHILD_MODE,    //儿童模式
    FUNC_TYPE_LOG_SAVE,     //把LOG输出到FLASH 。
    FUNC_TYPE_LOG_COPY,		//把LOG拷贝出来
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
@brief 获取工程菜单中的各种模式的状态，如:工厂模式(P模式)、设计师模式(D模式)、老化模式
@param[in] e_work_mode 表示要获取哪个模式的状态
@param[out] ui1_mode 所获取到的状态的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_work_mode(EN_FAC_WORK_MODE e_work_mode, uint8_t *ui1_mode);

/** 
@brief 设置工程菜单中的各种模式，如:工厂模式(P模式)、设计师模式(D模式)、老化模式
@param[in] e_work_mode 表示要获取哪个模式的状态
@param[in] ui1_mode 要设置的状态
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_work_mode(EN_FAC_WORK_MODE e_work_mode, uint8_t ui1_mode);

/** 
@brief 获取序列号、注册码、Client type、Device ID、MAC地址等系统信息
@param[in] e_info_type 表示要获取何种信息
@param[out] ps_info 所获取到的信息的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_system_info(EN_FAC_SYSTEM_INFO_TYPE e_info_type, char *ps_info, int32_t i4_len);

/** 
@brief 获取主软件版本、工厂串口协议版本、FRC软件版本等
@param[in] e_info_type 表示要获取何种信息
@param[out] ps_version 所获取到的版本信息的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_version(EN_FAC_FIRMWARE_TYPE e_fr_type, char * ps_version, int32_t i4_len);

//====================Amy start Panel ID==========================================
/** 
@brief 获取Panel ID
@param[out] ui2_id 所获取到的ID
@param[out] ui2_id 最大的ID数
@return FPI_ERROR_SUCCESS:获取成功;
		FPI_ERROR_FAIL:获取失败
		FPI_ERROR_PANEL_ID_NOT_SUPPORT :不支持PANEL ID，用于与之前仅有project id，没有Panel id的软件做兼容判断	*/
fpi_error tos_factory_get_panel_id(uint16_t *ui2_id, uint16_t *ui2_max_id);

/** 
@brief 设置Panel ID
@param[out] ui2_id 所要设置的ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_panel_id(uint16_t ui2_id);

/** 
@brief 获取Panel NAME
@param[out] panelName 所获取到对应ID的PanelName
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_panel_name(char* panelName);


//====================Amy end Panel ID==========================================


/** 
@brief 获取Project ID
@param[out] ui2_id 所获取到的ID
@param[out] ui2_id 最大的ID数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_project_id(uint16_t *ui2_id, uint16_t *ui2_max_id);

/** 
@brief 设置Project ID
@param[out] ui2_id 所要设置的ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_project_id(uint16_t ui2_id);

/** 
@brief USB克隆,通过USB将种子文件中的设置克隆到TV上
@param[in] e_direction  FAC_CLONE_TV_TO_USB: 表示从TV克隆到USBUSB克隆到TV
                        FAC_CLONE_USB_TO_TV: 表示从USB克隆到TV
@param[in]e_content 表示克隆的内容,包括节目列表/系统设置/用户设置等
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_usb_clone(EN_FAC_CLONE_DIRECTION e_direction, EN_FAC_CLONE_CONTENT e_content);

/** 
@brief 通过USB升级主软件、MEMC、MBOOT、MAC地址、ESN/HDCP/CI+ Key等
@param[in] e_upgrade_type 表示要通过USB升级的文件的类型
@param
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_usb_upgrade(EN_FAC_UPGRADE_TYPE e_upgrade_type);


/** 
@brief 通过USB升级主软件、MEMC、MBOOT、MAC地址、ESN/HDCP/CI+ Key等
@param[in] e_reset_type RESET_SHOP 表示复位用户数据
@param                  RESET_ALL  表示复位用户数据以及工厂数据(MAC/HDCP/SN等固化数据除外)
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_reset(EN_FAC_RESET_TYPE e_reset_type);

/** 
@brief 白平衡参数初始化
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_wb_setting_init(void);

/** 
@brief 频道预置
@param[in] e_preset_area 根据不同的区域，预置不同的节目列表
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_preset_channel(EN_FAC_PRESET_AREA e_preset_area);

/** 
@brief 获取频道预置的区域
@param[out] pe_preset_area 当前预设频道的区域
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_preset_area(EN_FAC_PRESET_AREA *pe_preset_area);

/** 
@brief 获取上电模式
@param[in] e_power_mode  POWERON_MODE_ON    上电开机      
                         POWERON_MODE_STB   上电待机
                         POWERON_MODE_LAST  上电采用上次关机的状态
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_power_on_mode(EN_FAC_POWER_ON_MODE *e_power_mode);

/** 
@brief 设置上电模式
@param[in] e_power_mode  POWERON_MODE_ON    上电开机      
                         POWERON_MODE_STB   上电待机
                         POWERON_MODE_LAST  上电采用上次关机的状态
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_power_on_mode(EN_FAC_POWER_ON_MODE e_power_mode);

/** 
@brief 获取图像设置中各选项的曲线，包括Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_type :Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[out] pt_curve  :获取到的曲线
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_picture_curve(EN_FAC_PICTURE_CURVE_TYPE e_curve_type, TOS_SERVICE_USER_NONLINEAR_CURVE_T *pt_curve);

/** 
@brief 设置图像设置中各选项的曲线，包括Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_type :Backlight/Brightness/Contrast/Saturation/Sharpness/Tint
@param[in] curve_item :声音属性变量 ,0/25/50/75/100五个点
@param[in] value      :要设置的曲线节点值0-100
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_picture_curve(EN_FAC_PICTURE_CURVE_TYPE e_curve_type, uint8_t ui1_item, uint8_t ui1_val);

/** 
@brief 获取声音曲线
@param[out] pt_curve  :获取到的曲线
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_sound_curve(TOS_SERVICE_USER_NONLINEAR_CURVE_T *pt_curve);

/** 
@brief 设置声音曲线
@param[in] ui1_curve_item  : 声音属性变量 ,0/25/50/75/100五个点
@param[in] ui1_val         :要设置的曲线节点值0-100
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_sound_curve(uint8_t ui1_curve_item, uint8_t ui1_val);


/** 
@brief 获取展频参数
@param[in] e_ssc_type: SSC_TYPE_DDR、SSC_TYPE_FRC、SSC_TYPE_LVDS、SSC_TYPE_OSD
@param[out]pt_ssc_val:  typedef struct
                        {
                            fpi_bool b_enable;
                            uint16_t ui2_modulation; // SSC span
                            uint16_t ui2_percentage; // SSC step
                        }TOS_FAC_SSC_SETTING_T;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_ssc_setting(EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T *pt_ssc_arg);

/** 
@brief 设置展频参数
@param[in] e_ssc_type: SSC_TYPE_DDR、SSC_TYPE_FRC、SSC_TYPE_LVDS、SSC_TYPE_OSD
@param[in] pt_ssc_val: typedef struct
                       {
                           fpi_bool b_enable;
                           uint16_t ui2_modulation; // SSC span
                           uint16_t ui2_percentage; // SSC step
                       }TOS_FAC_SSC_SETTING_T;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_ssc_setting(EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T t_ssc_arg);

/** 
@brief 获取overscan的当前设置
@param[in] e_item : H_POSITION, H_SIZE, V_POSITION, V_SIZE
@param[out] i4_val: 获取到的参数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_overscan(EN_FAC_OVERSCAN_ITEM e_item, int32_t *i4_val);

/** 
@brief 设置overscan
@param[in] e_item : H_POSITION, H_SIZE, V_POSITION, V_SIZE
@param[in] ui1_val: 要设置的参数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_overscan(EN_FAC_OVERSCAN_ITEM e_item, uint8_t ui1_val);

/** 
@brief 获取工厂白平衡数据
@param[in] e_color_temp : 色温cool/standard/warm
@param[out] pt_wb: 获取到的数据
                    int r_gain:-128-127
                	  int g_gain:-128-127
                	  int b_gain:-128-127
                	  int r_offset:-128-127
                	  int g_offset:-128-127
                	  int b_offset:-128-127//如果是hdmi和dtv信源下的标准色温下，则是0-255
                	  int brightness:0-255
                	  int contrast:0-255
                	  int saturation:0-255
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_wb_setting(EN_FAC_COLOR_TEMP e_color_temp, TOS_FAC_WHITE_BALANCE_T *pt_wb);

/** 
@brief 设置工厂白平衡数据
@param[in] e_color_temp : 色温cool/standard/warm
@param[in] curve_item   : R/G/B/ Gain & Offset
@param[in] value        : 所要设置的值
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_wb_setting(EN_FAC_COLOR_TEMP e_color_temp, EN_FAC_WB_ITEM curve_item, int32_t value);

/** 
@brief 录制TS流
@param[in]无
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_record_ts_stream(void);

/** 
@brief 更新E_Sticker
@param[in]无
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_update_e_sticker(void);

/** 
@brief 测试Device ID是否OK
@param[in]无
@param[out]b_success :fpi_true测试成功；fpi_false:测试失败
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_test_device_id(fpi_bool *b_success);

/** 
@brief 擦除CI Key
@param[in]无
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_erase_ci_key(void);

/** 
@brief 从工厂菜单中获取某些功能使能或者禁用的状态
@param[in] e_fun_type:
            typedef enum
            {
                FUNC_TYPE_UART_DEBUG,   //串口调试
                FUNC_TYPE_WSS_AFD,      //WSS和AFD
                FUNC_TYPE_BGM,          //BGM功能
                FUNC_TYPE_4K1K,         // 4K1K功能
                FUNC_TYPE_WATCH_DOG,    // 看门狗
                FUNC_TYPE_PVR           // PVR
                FUNC_TYPE_PANEL_KEY,    //面板按键
                FUNC_TYPE_GREY_CTRL     //控制SHOP模式下Picture菜单是否灰选
            }EN_FAC_FUNC_TYPE;
@param[in] b_enable: fpi_true为使能该功能，fpi_false为禁用该功能
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_func_enable(EN_FAC_FUNC_TYPE e_fun_type, fpi_bool *b_enable);

/** 
@brief 从工厂菜单中将某些功能使能或者禁用
@param[in] e_fun_type:
            typedef enum
            {
                FUNC_TYPE_UART_DEBUG,   //串口调试
                FUNC_TYPE_WSS_AFD,      //WSS和AFD
                FUNC_TYPE_BGM,          //BGM功能
                FUNC_TYPE_4K1K,         // 4K1K功能
                FUNC_TYPE_WATCH_DOG,    // 看门狗
                FUNC_TYPE_PVR           // PVR
                FUNC_TYPE_PANEL_KEY,    //面板按键
                FUNC_TYPE_GREY_CTRL     //控制SHOP模式下Picture菜单是否灰选
            }EN_FAC_FUNC_TYPE;
@param[in] b_enable: fpi_true为使能该功能，fpi_false为禁用该功能
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_func_enable(EN_FAC_FUNC_TYPE e_fun_type, fpi_bool b_enable);

/** 
@brief 获取动态背光参数
@param[out] pt_dbc_setting
                    uint8_t low_apl1;    //for CN means bke
                    uint8_t low_apl1_bl; //for CN means bke_std
                    uint8_t low_k;       //Not used for CN
                    uint8_t low_apl2; 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_dbc_setting(TOS_FAC_DBC_SETTING_T *pt_dbc_setting);

/** 
@brief 设置动态背光需要用到的参数
@param[in] t_dbc_setting
                    uint8_t low_apl1;    //for CN means bke
                    uint8_t low_apl1_bl; //for CN means bke_std
                    uint8_t low_k;       //Not used for CN
                    uint8_t low_apl2; 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_dbc_setting(TOS_FAC_DBC_SETTING_T t_dbc_setting);

/** 
@brief 获取light sensor工厂参数设置
@param[out] pt_sensor_arg
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_light_sensor_setting(TOS_FAC_LIGHT_SENSOR_ARG_T *pt_sensor_arg);

/** 
@brief 设置light sensor工厂参数设置
@param[in] t_sensor_arg
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_light_sensor_setting(TOS_FAC_LIGHT_SENSOR_ARG_T t_sensor_arg);

/** 
@brief 设置开机logo
@param[in]无
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_power_on_logo(void);
    
/** 
@brief 获取CI Key的名字
@param[out] ps_name 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_ci_key_name(char * ps_name, int32_t i4_ret);

/** 
@brief 获取CI KEY、USER ID抄写状态、蓝牙工作状态、Reset shop状态
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
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_statu(EN_FAC_QUERY_TYPE e_type, fpi_bool * b_state);

/** 
@brief 设置CI KEY、USER ID抄写状态、蓝牙工作状态、Reset shop状态
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
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_statu(EN_FAC_QUERY_TYPE e_type, fpi_bool b_state);

/** 
@brief 获取DVB T2的支持状态，
@param[out] pe_state
            typedef enum
            {
                EN_T2_SUPPORT_OFF= 0,     // 不支持T2
                EN_T2_SUPPORT_ON,         // 支持T2
                EN_T2_SUPPORT_BY_COUNTRY, // 根据国家判断是否支持T2
                EN_T2_SUPPORT_NUMBER
            }EN_T2_SUPPORT_STATE;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_t2_support_state(EN_T2_SUPPORT_STATE *pe_state);

/** 
@brief 设置DVB T2的支持状态，
@param[in]e_state
            typedef enum
            {
                EN_T2_SUPPORT_OFF= 0,     // 不支持T2
                EN_T2_SUPPORT_ON,         // 支持T2
                EN_T2_SUPPORT_BY_COUNTRY, // 根据国家判断是否支持T2
                EN_T2_SUPPORT_NUMBER
            }EN_T2_SUPPORT_STATE;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_t2_support_state(EN_T2_SUPPORT_STATE e_state);

/** 
@brief 获取写在配置文件ini中的产品信息
@param[in]无
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_product_info(fac_product_info_data_t * pt_info);

/** 
@brief 设置屏幕mute的颜色，仅供工厂模块老化模式以及内置pattern切换调用
@param[in]ui4_color
                #define SCREEN_MUTE_BLACK       0x0
                #define SCREEN_MUTE_RED         0xff000000
                #define SCREEN_MUTE_GREEN       0x00ff0000
                #define SCREEN_MUTE_BLUE        0x0000ff00
                #define SCREEN_MUTE_WHITE       0xffffffff
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_mute_color(uint32_t ui4_color, fpi_bool b_mute);

/** 
@brief 获取3D蓝牙眼镜的同步状态
@param[out]*ui1_state
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_bluetooth_3d_state(EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t *ui1_state);

/** 
@brief 设置3D蓝牙眼镜的同步状态
@param[in]ui1_state
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_bluetooth_3d_state(EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t ui1_state);

/** 
@brief 获取当前运营商的名字
@param[in]无
@param[out]ui1_operator_name
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_current_operator_name(uint8_t * ui1_operator_name);

/** 
@brief 选择设置当前运营商，主要是在运营商选择列表中按左右键选择运营商的时候调用
@param[in]b_flag
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_operator_on_off(fpi_bool b_flag);

/** 
@brief 获取10P白平衡数据
@param[in]无
@param[out]pt_data
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_10p_data(TOS_TEN_P_DATA_T *pt_data);

/** 
@brief 设置10P白平衡数据
@param[in]pt_data
@param[out]
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_set_10p_data(TOS_TEN_P_DATA_T *pt_data);

/** 
@brief 将10P白平衡数据复位为默认值
@param[in]pt_data
@param[out]
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_reset_10p_data(void);

/** 
@brief 获取是否有U盘插上的状态
@param[in]无
@param[out]b_value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_usb_state(fpi_bool *b_value);

/** 
@brief 获取升级文件的数量
@param[in]无
@param[out]ui1_number
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_upgrade_file_number(uint8_t *ui1_number);

/** 
@brief 中间件获取遥控器键值
@param[in] ui4_key_code
@param[out]b_value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_remote_pro(uint32_t ui4_key_code);

/** 
@brief 中间件添加回调函数
@param[in] oncommand
@param[out]userdata
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_cmds_addcallback(tos_faccmds_oncommand oncommand,void* userdata);
 
/** 
@brief 中间件删除回调函数
@param[in] oncommand
@param[out]userdata
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_cmds_removecallback(tos_faccmds_oncommand oncommand,void* userdata);

//fpi_error tos_faccmds_confirm(unsigned long token,TOS_FACCMDS_CMD_RESULT_S* result);

/** 
@brief  清除netflix 信息
@param NONE
@return      FPI_ERROR_SUCCESS操作成功;
             FPI_ERROR_FAIL  操作失败*/ 

fpi_error tos_factory_erase_netflix(void);

/** 
@brief 获取gamma offset值
@param[in] 无
@param[out]offset
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_factory_get_gamma_offset(int * offset);


/**
@brief 获取project id列表

@param[in, out] int *buf , int *count

@note 由于project id 数量不定，在进程间通信的时候需要知道buf的大小
@note 使用时需要调用两次此函数，第一次获取总个数，第二次传count个元素的buf数组
@note buf == NULL，将project id 总个数赋值给count
@note buf != NULL，将每一个project id 赋值给buf(此时count为buf的元素个数)
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_factory_get_projectID_array(int *buf, int *count);    

#ifdef __cplusplus
}
#endif


#endif


