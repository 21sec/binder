/**@defgroup cec 和mhl 
@{

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
*/


#ifndef __TOS_CEC__
#define __TOS_CEC__

#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief CEC控制电源的动作
**/
typedef enum
{
	EN_CEC_POWER_POWERON,
	EN_CEC_POWER_STANDBY,
}EN_CEC_POWER_TYPE;

/**
@brief 设置CEC设备的功能
**/
typedef enum{
	EN_CEC_VALUE_VOLUME,	
	EN_CEC_VALUE_MUTE,
}EN_CEC_VALUE_TYPE;

#define MAX_OSD_NAME_LEN   15

/**
@brief CEC设备的信息
**/
typedef struct
{
    uint8_t un8DevLogAddr;
    uint8_t un8DevPhyAddr;
    uint8_t un8DevNum;
    uint8_t un8DevType;
    char szDevName[MAX_OSD_NAME_LEN];
}st_fpi_cec_dev_base;

/**
@brief MHL消息类型
**/
typedef enum
{
	EN_MHL_MSCE		= 0x02,
	EN_MHL_RCP		= 0x10,
	EN_MHL_RCPK		= 0x11,
	EN_MHL_RCPE		= 0x12,
	EN_MHL_RAP		= 0x20,
	EN_MHL_RAPK		= 0x21,
	EN_MHL_UCP		= 0x30,
	EN_MHL_UCPK		= 0x31,
	EN_MHL_UCPE		= 0x32,
	EN_NONE_CMD		= 0xff,	// not any cmd from mobile.
}EN_MHL_MSC_TOTV_CMD_TYPE;

/**
@brief MHL设备拔插状态
**/
typedef enum
{
	EN_MHL_CABLE			=0,
	EN_NOT_MHL_CABLE		=1,
}EN_MHL_PORT_STAT;

/**
@brief MHL信号状态
**/
typedef enum
{
	EN_MHL_SIGNALS		=0,
	EN_NO_SIGNAL			=1,
}EN_MHL_SIGNAL_STAT;

/**
@brief MHL消息类型
**/
typedef struct
{
    EN_MHL_MSC_TOTV_CMD_TYPE 	mhlMscSubCmdType;
    uint8_t 					un8cmd;		//follow MHL2.0 spec. the range is 0~255;
}st_fpi_mhl_msc_cmd;

typedef struct
{
    EN_MHL_PORT_STAT 			un8MhlCable;	// 1: mhl cable connect,  	0: not mhl cable, 	other: not mhl cable
    EN_MHL_SIGNAL_STAT 			un8MhlSignal;	// 1: is mhl signal,		0: not mhl signal, 	other: not mhl signal, 
    st_fpi_mhl_msc_cmd                 tvgetMHLcmd;
}st_fpi_tvget_mhl_dev_info; 

/**
@brief           CEC功能开关，设置T-link状态

@param[in]	enable	CEC功能开关标志，enable==1表示CEC功能开， enable==0表示CEC功能开关
@param [in]	act  接口执行的状态，该参数暂时没有用到

@param[out]    NONE

@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  

*/
fpi_error tos_cec_set_enable(int32_t enable,EN_ACT_CTRL act);


/**
@brief 			获取T-LINK状态

@param[in]		NONE

@param[out]	   	enable T-LINK状态

@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/
fpi_error tos_cec_get_enable(int32_t *enable);


/**
@brief		电视遥控器向CEC设备推送键值
			首先上层会截取按键值，对于android需要将自身的按键值映射成为HTML UI的值，linux则直接只用HTML UI值即可.
			将此HTML UI值传入此接口后，再映射为HDMI标准文档定义的CEC键值，从而实现遥控器控制CEC设备的功能.

@param[in] 	un16UiKey 传入HTML UI值

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_send_key(uint16_t un16UiKey);



/**
@brief 		获取功放的ARC(声音回传)开关状态

			ARC开关是ARC功能的最后一个开关，开启ARC功能需要保证开启了SAC功能和SPDIF功能

@param[in]    un8Num    目标设备的设备号，分别为1.2.3.4对应于HDMI1.2.3.4，   该参数暂时没有作用

@param[out]  pbStatus  目标设备的ARC开关状态，开 1，关 0.



@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_arc_status(uint8_t un8Num, int16_t *pbStatus);

/**
@brief 		设置功放的ARC(声音回传)开关状态

	    		ARC开关是ARC功能的最后一个开关，开启ARC功能需要保证开启了SAC功能和SPDIF功能

@param[in]    un8Num     目标设备的设备号，分别为1.2.3.4对应于HDMI1.2.3.4  ，  该参数暂时没有作用
@param[in]    pbStatus   目标设备待设定的ARC开关状态，开 1，关 0.
@param [in]	act  接口执行的状态，该参数暂时没有用到

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_set_arc_status(uint8_t un8Num, int16_t bStatus,EN_ACT_CTRL act);


/**
@brief 		由上层调用，用于获取当前接入TV的CEC设备总数

		      CEC设备总数是给UI进行遍历，显示CEC设备名称

@param [in]   NONE

@param[out] pun8TotalNum  设备总数

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_device_total_number(uint8_t *totalNum);


/**
@brief 		由上层调用，将设备信息上传给UI进行相应处理

@param [in]    NONE

@param[out] 	 pDevInfo，此参数包含如下内容:
						- un8DevLogAddr   当前CEC设备的逻辑地址
						- un8DevPhyAddr   当前CEC设备的物理地址
						- un8DevNum       当前CEC设备的设备号，对于HDMI1,2,3,4分别为1,2,3,4   ，  该参数暂时没有作用
						- un8DevType      CEC设备的设备类型
						- szDevName       CEC设备的名称

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_dev_info(st_fpi_cec_dev_base *pDevInfo);


/**
@brief 		  获取某一CEC设备静音状态

@param [in] 	  un8Num  表示HDMI口 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ，该参数暂时没有作用

@param[out]    pIsMute  是否静音 fpi_true 表示静音状态 fpi_false 表示非静音状态

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_device_mute_status(uint8_t un8Num, fpi_bool* pIsMute);

/**
@brief 		获取某一CEC设备的音量

@param [in]	un8Num  表示HDMI口 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ，该参数暂时没有作用

@param[out]	value  表示音量值 0 - 100
    
@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_device_volume(uint8_t un8Num, uint16_t *value);


/**
@brief		arc的支持状态 

@param [in]	un8Num  表示HDMI口 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ，  该参数暂时没有作用

@param[out]  un8Flag ARC支持状态

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_arc_support_status(uint8_t un8Num, uint8_t  *un8Flag);




/**
@brief 		开启或者唤醒CEC设备， 比如对于DVD设备和AMP设备有不同的唤醒方式

@param[in] 	un8Num  目标设备的设备号，分别为1.2.3.4对应于HDMI1.2.3.4
@param[in] 	type       CEC控制电源的动作，power on 或standby
@param[in]    b_OnOff  控制电源动作开关，暂时没有作用

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_power_device(uint8_t un8Num, EN_CEC_POWER_TYPE type,int16_t b_OnOff);



/**
@brief 		开启或关闭CEC唤醒TV 或者随着TV 自动待机的功能

@param[in]    type     CEC控制电源的动作，power on 或standby
@param[in]	enable   fpi_true, 开启功能；fpi_false，关闭功能
@param[in]	act  接口执行的状态，该参数暂时没有用到

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_set_auto_power_mode(EN_CEC_POWER_TYPE type,int16_t enable,EN_ACT_CTRL act);

/**
@brief 		得到开启或关闭CEC唤醒TV 或者随着TV 自动待机的功能状态

@param[in]    type     CEC控制电源的动作，power on 或standby		 

@param[out]  p_enable   相关功能开启关闭状态

@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_cec_get_auto_power_mode(EN_CEC_POWER_TYPE type,int16_t *p_enable);


/**
@brief 		向mhl设备发送按键

@param[in]	un16UiKey 传入HTML UI值

@param[out]	NONE


@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/
fpi_error tos_mhl_send_key(uint16_t un16UiKey);


/**
@brief 		获得mhl设备的信息，同时查询上一次send key命令的执行结果
			

@param[in]	NONE

@param[out]	pDevInfo MHL设备的信息及上一次send key命令的执行结果
			目前暂时不会查询该结果，因此获取到的结果不可用
			


@retval	    	 FPI_ERROR_SUCCESS    表示设置操作成功
@retval          FPI_ERROR_FAIL          表示设置操作失败
*/

fpi_error tos_mhl_get_mhl_dev_info(st_fpi_tvget_mhl_dev_info *pDevInfo);



#ifdef __cplusplus
}
#endif
/** @} */
#endif

