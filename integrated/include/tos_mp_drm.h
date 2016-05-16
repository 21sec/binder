#ifndef __TOS_MP_DRM_H__
#define __TOS_MP_DRM_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t DRM_CLIENT_HANDLE;

typedef enum _DRM_CALLBACK_EVENT_TYPE_s
{
   DRM_MESSAGE_RESULT = 0,
   DRM_SYS_STATUS_CHANGE = 1,
   DRM_SYS_MSG = 2,
}DRM_CALLBACK_EVENT_TYPE_e;

/**
@brief 播放器DRM 模块的回调函数类型定义
@param[in] handle DRM模块的句柄.
@param[in] event 产生的事件类型枚举，详情见DRM_CALLBACK_EVENT_TYPE_e定义
@param[in] code 产生的事件类型枚举，事件的具体值
@param[in] userData 用户数据,其值为调用tos_mp_drm_add_callback时传入的用户数据
*/
typedef void (*tos_mp_drm_callback) (DRM_IPC_CLIENT_HANDLE handle, DRM_CALLBACK_EVENT_TYPE_e event, int code, void *userData);


/**
@brief 创建一个DRM会话
@return 成功返回DRM会话的ID; 失败返回0
*/
DRM_CLIENT_HANDLE tos_mp_drm_open();

/**
@brief 关闭一个DRM会话
@param[in] handle DRM会话的ID.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_drm_close(DRM_IPC_CLIENT_HANDLE handle);

/**
@brief 设置DRM会话的获取LICENSE的URL
@param[in] handle DRM会话的ID.
@param[in] url LICENSE的URL.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_drm_setDRMLicenseAcqURL(DRM_IPC_CLIENT_HANDLE handle, const char* url);

/**
@brief 设置DRM会话的获取LICENSE的URL
@param[in] handle DRM会话的ID.
@param[in] msg_type，消息类型，如同， application/vnd.ms-playready.initiator+xml.
@param[in] msg 消息的具体值. 如同，{"<?xml version=\"1.0\" encoding=\"utf-8\"?><PlayReadyInitiator xmlns=\"http://schemas.microsoft.com/DRM/2007/03/protocols/\"><LicenseAcquisition><Header><WRMHEADER xmlns=\"http://schemas.microsoft.com/DRM/2007/03/PlayReadyHeader\" version=\"4.0.0.0\"><DATA><PROTECTINFO><KEYLEN>16</KEYLEN><ALGID>AESCTR</ALGID></PROTECTINFO><LA_URL>http://drmtests.farncombe.eu/playready/rightsmanager.asmx</LA_URL><KID>wv45XhRB4RGrGY6/RyQBmw==</KID></DATA></WRMHEADER></Header></LicenseAcquisition></PlayReadyInitiator>"}
@param[in] drm_sys_id DRM的系统ID，如，"urn:dvb:casystemid:19219"
@param[in] msg_id DRM的消息ID，目前没有用.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_drm_send_msg(DRM_IPC_CLIENT_HANDLE handle, const char *msg_type, const char *msg, const char *drm_sys_id, const char *msg_id);

/**
@brief 设置DRM会话的消息回调函数
@param[in] handle DRM会话的ID.
@param[in] callback 消息回调函数.
@param[in] userData 用户数据
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_drm_add_callback(DRM_IPC_CLIENT_HANDLE handle, tos_mp_drm_callback callback, void* userData);

#ifdef __cplusplus
}
#endif

#endif
