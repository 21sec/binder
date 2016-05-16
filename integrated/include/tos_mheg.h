/**@defgroup MHEG模块

@{
@brief 用于控制电视中MHEG相关操作

@version 1.0.0
**/

#ifndef __TOS_MHEG_H__
#define __TOS_MHEG_H__
#include "tos_dtv_basetype.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
@brief 打开MHEG5
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mheg_start(void);

/**
@brief 停止MHEG5
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mheg_stop(void);

/**
@brief 判断MHEG是否打开
@param[out] value 判断MHEG是否打开指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mheg_is_open(fpi_bool *value);


/**
@brief MHEG键值分发
@param[in] keycode 分发的键值
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mheg_dispatch_key_code(uint32_t keycode);


/**
@brief MHEG获取用户输入状态
@param[in] value 用户输入状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mheg_get_userinput_state(uint8_t *value);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
