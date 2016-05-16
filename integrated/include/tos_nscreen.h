/**@defgroup tos_nscreen
@{

@brief 

@author xiewx (xiewx@tcl.com)

@note 

@version 1.0.0 
@history 2015/6/9 15:00:40 ����
@history 2015/7/7 ��������������tos_nscreen_get_device_count, tos_nscreen_get_device_list �ӿ�
*/

#ifndef __TOS_NSCREEN_H__
#define __TOS_NSCREEN_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C"{
#endif

//#define NSCREEN_ENABLE	/*!< NSCREEN_ENABLE */

#define NSCREEN_FILE_SIZE_1024		1024	/*!< NSCREEN�ļ�����Ϊ1024 */

#define DMR_STATUS_DISCONNECT			0
#define DMR_STATUS_CONNECT				1

/**
@brief ����nsrceen�ص��¼�ö��
*/
typedef enum _NSCREEN_EVENT_E
{
   	EN_NSCREEN_EVENT_STOP, /// <����ֹͣ
    EN_NSCREEN_EVENT_DEVICE_INSERT = 100, /// <DMS insert (dmp moudel)
    EN_NSCREEN_EVENT_DEVICE_REMOVE, /// <DMS remove (dmp moudel)
    EN_NSCREEN_EVENT_DMR_PUSH = 150, /// <DMR PUSH  (param:NSCREEN_CONTENTTYPE_E)
    EN_NSCREEN_EVENT_DMR_STATUS, /// < DMR Status (param: 1-connect, 0-disconnect #define DMR_STATUS_XXX)
    EN_NSCREEN_EVENT_MIRACAST_STATUS = 200,   /// <miracast status
    EN_NSCREEN_EVENT_AIRPLAY_STATUS = 300,   /// <Airpaly status
	EN_NSCREEN_EVENT_RM_STATUS = 400,   /// <Remote ctrl status
	EN_NSCREEN_EVENT_EXTERN = 500,   ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN1,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN2,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN3,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN4,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN5,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN6,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN7,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN8,  ///< Ԥ������
	EN_NSCREEN_EVENT_EXTERN9,  ///< Ԥ������
}NSCREEN_EVENT_E;

/**
@brief ����Э������ö��
@��Ҫͬ����fpi_error��,ʹ��ͳһ��fpi_error_code
*/
typedef enum _NSCREEN_PROTOCOL_E
{
	EN_NSCREEN_NONE,
	EN_NSCREEN_DLNA,	///< DLNA
	EN_NSCREEN_MIRACAST, ///< miracast
	EN_NSCREEN_AIRPLAY,	///< airplay
	EN_NSCREEN_REMOTECTRL,	///< remote ctrl
	EN_NSCREEN_PROTOCOL_MAX
}NSCREEN_PROTOCOL_E;

/**
@brief enumerate to indicate the function error type
*/
typedef enum _EN_NSCREEN_ERR_E
{
    EN_NSCREEN_ERROR_SUCCESS = 0,          /*!< Success */
    EN_NSCREEN_ERROR_FAILED,               /*!< Failed */
    EN_NSCREEN_ERROR_NOT_SUPPORT,          /*!< Not Support/Implement */
    EN_NSCREEN_ERROR_NO_SERVER,            /*!< No Server */
    EN_NSCREEN_ERROR_NO_FILE,              /*!< No File */
    EN_NSCREEN_ERROR_MAX
} EN_NSCREEN_ERR_E;

typedef enum _EN_NSCREEN_SYNC_STATUS_E
{
    EN_NSCREEN_SYNC_PLAY = 100,
    EN_NSCREEN_SYNC_PAUSE,
    EN_NSCREEN_SYNC_STOP,
    EN_NSCREEN_SYNC_RESUME,
    EN_NSCREEN_SYNC_SEEK,  
    EN_NSCREEN_SYNC_PLAY_CUR_TIME,
    EN_NSCREEN_SYNC_PLAY_DURATION,
    EN_NSCREEN_SYNC_PLAY_ERROR,
	EN_NSCREEN_SYNC_EXTERN0,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN1,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN2,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN3,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN4,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN5,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN6,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN7,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN8,  ///< Ԥ������
	EN_NSCREEN_SYNC_EXTERN9,  ///< Ԥ������
	
	EN_NSCREEN_SYNC_AV = 1000, ///< a/v sync
}NSCREEN_SYNC_STATUS_E;

/**
@brief ������������ö��
@note ����ʹ�û����
*/
typedef enum _NSCREEN_CONTENTTYPE_E
{
	EN_NSCREEN_CONTENTTYPE_UNKNOWN 	= 0,
	EN_NSCREEN_CONTENTTYPE_DIR 		= 0x01,	///< �ļ���
	EN_NSCREEN_CONTENTTYPE_IMAGE 	= 0x02,	///< ͼƬ
	EN_NSCREEN_CONTENTTYPE_VIDEO 	= 0x04,	///< ��Ƶ
	EN_NSCREEN_CONTENTTYPE_AUDIO 	= 0x08,	///< ��Ƶ
	EN_NSCREEN_CONTENTTYPE_FILE		= 0x10,	///< �ļ�
	EN_NSCREEN_CONTENTTYPE_PLAYLIST	= 0x20,	///< �����б�
	
	EN_NSCREEN_CONTENTTYPE_RESERVED0 = 0x40,   ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED1 = 0x80,   ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED2 = 0x100,  ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED3 = 0x200,  ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED4 = 0x400,  ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED5 = 0x800,   ///< Ԥ������

    EN_NSCREEN_CONTENTTYPE_NAME = 0x1000,               ///< �������ݵ�����
    EN_NSCREEN_CONTENTTYPE_REMOTENAME = 0x2000,          ///< �ƶ��豸������
	
    EN_NSCREEN_CONTENTTYPE_RESERVED6 = 0x4000,           ///< Ԥ������
	EN_NSCREEN_CONTENTTYPE_RESERVED7 = 0x8000,  ///< Ԥ������
}NSCREEN_CONTENTTYPE_E;

/**
@brief ����ý���ļ�����ڵ���Ϣ�ṹ��
*/
typedef struct _nscreen_content_info_t
{
	char path[NSCREEN_FILE_SIZE_1024]; ///< �ļ�·��
	char name[NSCREEN_FILE_SIZE_1024];	///< �ļ���	
	NSCREEN_CONTENTTYPE_E type;				///< �ļ�����
	long filesize;							///< �ļ���С
	long time;								///< �ļ�����޸�ʱ��
}nscreen_content_info_t;

/**
@brief ����ý���豸��Ϣ�ṹ��
*/
typedef struct _nscreen_device_info_t
{
    int  id;       ///<�豸��ʶid
    char path[NSCREEN_FILE_SIZE_1024];    ///< �豸·��
    char name[NSCREEN_FILE_SIZE_1024];  ///< �豸����
    uint64_t reserved0;             ///< Ԥ������
    uint64_t reserved1;                ///< Ԥ������
}nscreen_device_info_t;

/**
@brief nscreen�Ļص��������Ͷ���

@param[in] event �������¼�����ö��
@param[in] code �������¼���ֵ,����event���Ͳ�ͬ�в�ͬ�Ķ���
@param[in] data �������¼���������,����event���Ͳ�ͬ�в�ͬ�Ķ���
@param[in] userData �û�����,��ֵΪ����tos_nscreen_add_callbackʱ������û�����
*/
typedef void (*tos_nscreen_callback)(NSCREEN_EVENT_E event, int code, int data, void *userData);

/**
@brief init the nscreen
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_init(void);

/**
@brief de-init the nscreen
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_terminate(void);

/**
@brief start the nscreen

@note

@param[in]  protocol ʹ�õ�Э�� 
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_start(NSCREEN_PROTOCOL_E protocol);

/**
@brief stop the nscreen

@note
@param[in]  protocol ʹ�õ�Э��  
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_stop(NSCREEN_PROTOCOL_E protocol);

/**
@brief ��ȡ�豸�ĸ���

@note ͨ����ȡ��������ʹ��tos_nscreen_get_device_list ��ȡ�����б�

@param[in]  protocol ʹ�õ�Э��
@param[out]	*count ����
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_get_device_count(NSCREEN_PROTOCOL_E protocol, int *count);

/**
@brief ��ȡ�豸���б�

@note ��ʹ��tos_nscreen_get_device_count��ȡ���������ٻ�ȡ�б�

@param[in]  protocol ʹ�õ�Э��
@param[out]	*list �б�
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_get_device_list(NSCREEN_PROTOCOL_E protocol, nscreen_device_info_t *list);

/**
@brief ��ȡ���ݵĸ���

@note ͨ����ȡ��������ʹ��tos_nscreen_get_content ��ȡ�����б�

@param[in]  protocol ʹ�õ�Э��
@param[in]	path ·��
@param[in]	type ��ȡ���ݵ�����
@param[out]	*count ����
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_get_content_count(NSCREEN_PROTOCOL_E protocol, const char *path, NSCREEN_CONTENTTYPE_E type, int *count);

/**
@brief ��ȡ���ݵ��б�

@note ��ʹ��tos_nscreen_get_content_count��ȡ���������ٻ�ȡ�����б�,����ȡ������������ʱָ��protocol,type���ɡ�

@param[in]  protocol ʹ�õ�Э��
@param[in]	path ·�� �����path��NULLʱ����ȡ��ǰ�ƶ������͵��ļ���
@param[in]	type ��ȡ���ݵ�����
@param[out]	*list ָ�����͵������б�
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_get_content(NSCREEN_PROTOCOL_E protocol, const char *path, NSCREEN_CONTENTTYPE_E type, nscreen_content_info_t *list);

/**
@brief sync_play_status for the nscreen if other app control mediaPlayer

@note

@param[in]  protocol ʹ�õ�Э�� 
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_sync_play_status(NSCREEN_PROTOCOL_E protocol, NSCREEN_SYNC_STATUS_E status, int64_t data);

/**
@brief ���ӻص�����

@param[in]	callback �ص�����ָ��
@param[in]	userdata �û����ݣ����ڻص��������׳�
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_add_callback(tos_nscreen_callback callback,void* userdata);

/**
@brief ɾ���ص�����

@param[in]	callback �ص�����ָ��
@param[in]	userdata �û�����
@return �ɹ����� EN_NSCREEN_ERROR_SUCCESS��ʧ�ܷ�������ֵ
*/
fpi_error tos_nscreen_remove_callback(tos_nscreen_callback callback,void* userdata);

#ifdef __cplusplus
}
#endif	

#endif //__TOS_NSCREEN_H__

/** @} */
