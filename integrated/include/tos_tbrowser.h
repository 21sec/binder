
#ifndef __TOS_TBROWSER_H__
#define __TOS_TBROWSER_H__

#include "tos_key_code.h"

#ifndef CLOG_TAG
#define CLOG_TAG "clog_tbrowser"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 打开指定页面

@param[in] url 页面地址
@return 成功返回0;失败返回其他
*/
int tos_tbrowser_load_url(const char * url);


/**
@brief 向页面发送按键事件

@param[in] keyType:按键类型，取值TOS_KeyAction
@param[in] keyCode:键值，具体是sdl类型的键值，keyCode的取值参见tos_key_code.h的按键键值定义
@return 成功返回0;失败返回其他
*/
int tos_tbrowser_push_event(TOS_KeyAction keyType ,int keyCode);

/**
@brief 退出销毁浏览器
@return 成功返回0;失败返回其他
*/
int tos_tbrowser_destory();

#ifdef __cplusplus
}
#endif
/** @} */
#endif
