/**@defgroup 电源和任务管理模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda 初稿
*/



#ifndef _TOS_POWER_SUSPEND_H_
#define _TOS_POWER_SUSPEND_H_
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 在系统支持快速开机的情况下，设置快速开机的开关是开还是关

@note  input :flag-- fpi_true->fast boot switch on;  fpi_false->fast boot switch off

@note 

@return always FPI_ERROR_SUCCESS;
*/
fpi_error tos_power_suspend_set_onoff_status(fpi_bool flag);


/**
@brief 获取快速开机的开关是开还是关

@note  

@note 

@return always FPI_ERROR_SUCCESS;
*/
fpi_error tos_power_suspend_get_onoff_status(fpi_bool *flag);

/**
@brief 设置开关机模式

@note  input :mode-- 0->no str    1->str_suspend   2->str_resume   3->std_suspend   4->std_resume

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_power_suspend_set_mode(EN_POWER_SUSPEND_WORK_MODE mode);

/**
@brief 用于模块内部测试

@note  var :

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_suspend_set_str_debug_val(int var);

/**
@brief 获得系统是否支持STR，或STR支持的类G?

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_suspend_get_support_status(EN_POWER_SUSPEND_SUPPORT *type);

/**
@brief 获得系统当前的suspend/resume工作模式

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_suspend_get_current_work_mode(EN_POWER_SUSPEND_WORK_MODE *mode);

/**
@brief 获得系统的USB模块是否还处于STR启动的resume状态

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_power_suspend_get_usb_device_resuming_status(fpi_bool *flag);

#ifdef __cplusplus
}
#endif
/** @} */

#endif //_TOS_POWER_SUSPEND_H_