/**@defgroup hbbtv
@{

@author 

@note 

@version 1.0.0 2016/04/06 liujian 初稿
*/

#ifndef __TOS_TBROWSER_TEST_H__
#define __TOS_TBROWSER_TEST_H__

#ifndef CLOG_TAG
#define CLOG_TAG "clog_tbrowser"
#endif

#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif
/** 
@brief：响应按键事件 (针对Android平台，hbbtv按键直接传送给hbbtv进程，不经过中间件)
@param[in] keyCode：键值；keyType:按键事件类型；
@param[out] isHandle：hbbtv是否使用该按键，处理了该按键返回fpi_true;反之返回fpi_false
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值 
*/ 
fpi_error tos_hbbtv_browser_handle_key(uint16_t keyCode,uint16_t keyType,fpi_bool* isHandle);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
