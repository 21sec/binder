/**@defgroup 电源和任务管理模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda 初稿
*/



#ifndef _FUNCTION_POWER_H_
#define _FUNCTION_POWER_H_
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 开机关机过程
**/
typedef enum
{
	EN_SETTING_POWER_ON,		///<开机
	EN_SETTING_POWER_OFF,		///<关机
}EN_SETTING_POWER_CTRL;


/**
@brief 关掉子服务线程的模式
**/
typedef enum{
	EN_SUBSERVICE_SOME, ///<关掉的子服务的选项
}EN_SUBSERVICE_TYPE;

/**
@brief 电源控制模式
**/
typedef enum
{
    EN_POWER_TIMER_OFF,
    EN_POWER_TIMER_EVERYDAY,
    EN_POWER_TIMER_ONCE
} EN_POWER_TIMER_MODE;

typedef enum
{
	EN_PRE_POWEROFF, ///<准备关机
	EN_PRE_REBOOT,  ///<准备重启
	EN_NORMAL_POWEROFF,	///if hardware support str and str swith is on,then execute str poweroff,else execute really poweroff				EN_REAL_POWEROFF
	EN_FORCE_POWEROFF,	///force to execute really poweroff,next power will cold poweron,
}EN_POWEROFF_TYPE;

/**
@brief 设置开关机模式

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_set_mode(EN_SETTING_POWER_CTRL type,EN_POWER_TIMER_MODE mode);


/**
@brief 获得电源控制模式

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_get_mode(EN_SETTING_POWER_CTRL type,EN_POWER_TIMER_MODE *mode);

 /**
@brief 关机

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_off(EN_POWEROFF_TYPE type);

 /**
@brief 取消关机

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cancel_power_off(void);

 






#ifdef __cplusplus
}
#endif
/** @} */

#endif //_FUNCTION_SETTING_H_
