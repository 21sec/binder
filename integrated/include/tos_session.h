/**@defgroup 会话管理模块
@{

@brief 用于创建销毁会话,具体会话如何使用,管理由个模块自行决定,本模块仅作为工具模块协助产生唯一的会话ID

@author lihui02@tcl.com

@version 1.0.0 2015/12/16 初稿
*/

#ifndef __TOS_SESSION_H__
#define __TOS_SESSION_H__

#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	SESSION_CREATED,
	SESSION_DESTROYED,
	SESSION_REQUESTED,
	SESSION_RELEASED,
}EN_SESSION_STATUS;

typedef enum
{
	SESSION_TYPE_INPUT_SOURCE,
	SESSION_TYPE_INVALID,
}EM_SESSION_TYPE;

/**
@brief 创建会话，用于获得信源等设备的控制权，并进行操作。
*/
fpi_error tos_session_create(EM_SESSION_TYPE source_type, uint32_t* session_id);

/**
@brief 销毁会话，销毁前会自动释放回话对应设备的控制权。
*/
fpi_error tos_session_destory(uint32_t session_id);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
