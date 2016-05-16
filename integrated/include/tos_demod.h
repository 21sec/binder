/**@defgroup 数字锁频模块
@{

@brief 用于控制
**/

#ifndef __TOS_DEMOD_H__
#define __TOS_DEMOD_H__

#include "fpi_error_code.h"
#include "fpi_dtv_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 根据传入的参数锁定指定的频点
@param[in] dtv_delivery, 锁频的参数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_demod_lock_freqency(fpi_dtv_delivery_t *dtv_delivery);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
