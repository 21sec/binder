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
@brief ������DRM ģ��Ļص��������Ͷ���
@param[in] handle DRMģ��ľ��.
@param[in] event �������¼�����ö�٣������DRM_CALLBACK_EVENT_TYPE_e����
@param[in] code �������¼�����ö�٣��¼��ľ���ֵ
@param[in] userData �û�����,��ֵΪ����tos_mp_drm_add_callbackʱ������û�����
*/
typedef void (*tos_mp_drm_callback) (DRM_IPC_CLIENT_HANDLE handle, DRM_CALLBACK_EVENT_TYPE_e event, int code, void *userData);


/**
@brief ����һ��DRM�Ự
@return �ɹ�����DRM�Ự��ID; ʧ�ܷ���0
*/
DRM_CLIENT_HANDLE tos_mp_drm_open();

/**
@brief �ر�һ��DRM�Ự
@param[in] handle DRM�Ự��ID.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_drm_close(DRM_IPC_CLIENT_HANDLE handle);

/**
@brief ����DRM�Ự�Ļ�ȡLICENSE��URL
@param[in] handle DRM�Ự��ID.
@param[in] url LICENSE��URL.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_drm_setDRMLicenseAcqURL(DRM_IPC_CLIENT_HANDLE handle, const char* url);

/**
@brief ����DRM�Ự�Ļ�ȡLICENSE��URL
@param[in] handle DRM�Ự��ID.
@param[in] msg_type����Ϣ���ͣ���ͬ�� application/vnd.ms-playready.initiator+xml.
@param[in] msg ��Ϣ�ľ���ֵ. ��ͬ��{"<?xml version=\"1.0\" encoding=\"utf-8\"?><PlayReadyInitiator xmlns=\"http://schemas.microsoft.com/DRM/2007/03/protocols/\"><LicenseAcquisition><Header><WRMHEADER xmlns=\"http://schemas.microsoft.com/DRM/2007/03/PlayReadyHeader\" version=\"4.0.0.0\"><DATA><PROTECTINFO><KEYLEN>16</KEYLEN><ALGID>AESCTR</ALGID></PROTECTINFO><LA_URL>http://drmtests.farncombe.eu/playready/rightsmanager.asmx</LA_URL><KID>wv45XhRB4RGrGY6/RyQBmw==</KID></DATA></WRMHEADER></Header></LicenseAcquisition></PlayReadyInitiator>"}
@param[in] drm_sys_id DRM��ϵͳID���磬"urn:dvb:casystemid:19219"
@param[in] msg_id DRM����ϢID��Ŀǰû����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_drm_send_msg(DRM_IPC_CLIENT_HANDLE handle, const char *msg_type, const char *msg, const char *drm_sys_id, const char *msg_id);

/**
@brief ����DRM�Ự����Ϣ�ص�����
@param[in] handle DRM�Ự��ID.
@param[in] callback ��Ϣ�ص�����.
@param[in] userData �û�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_drm_add_callback(DRM_IPC_CLIENT_HANDLE handle, tos_mp_drm_callback callback, void* userData);

#ifdef __cplusplus
}
#endif

#endif
