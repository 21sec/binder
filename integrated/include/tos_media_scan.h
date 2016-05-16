/**@defgroup tos_media_scan
@{

@brief ��ý���ļ�ɨ��

@code ����ʹ�ó���ʾ��
//ɨ���ļ�����ȡ�ļ���Ϣ:
tos_ms_start_scan_file(x)
tos_ms_set_scan_mode(x)
tos_ms_get_file_count(x,x)
tos_ms_get_file_list_by_type(x,x,x,x)

@endcode

@history 2015/04/16 ����
@history 2015/04/20  ����������������޸�:�����ļ����з�ʽö��;���ƽӿ����ֺ�ע��.
@history 2015/04/22 ���ݲ�����������޸�:ɾ��FPI_MS_File_Node_S �ļ���Ϣ�ṹ���е�next;
                    tos_ms_start_scan_file �ӿڶ�Ϊ�첽�ӿ�;
                    ���ӻص�������.
*/


#ifndef __TOS_MEDIA_SCAN_H__
#define __TOS_MEDIA_SCAN_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
@brief �����ļ�����ö��
*/
typedef enum 
{
    EN_FPI_MS_FILE_TYPE_DIR = 1,       ///<�ļ�����ΪĿ¼
    EN_FPI_MS_FILE_TYPE_PICTURE = 2,   ///<�ļ�����ΪͼƬ
    EN_FPI_MS_FILE_TYPE_VIDEO = 4,     ///<�ļ�����Ϊ��Ƶ
    EN_FPI_MS_FILE_TYPE_MUSIC = 8,     ///<�ļ�����Ϊ����
    EN_FPI_MS_FILE_TYPE_OTHER = 16      ///<�ļ�����Ϊ����
}FPI_MS_FILE_TYPE_E;

/**
@brief �����ļ�ɨ�跽ʽö��
*/
typedef enum 
{
    EN_FPI_MS_SCAN_MODE_NORMAL,      ///<����׼��ʽɨ��
    EN_FPI_MS_SCAN_MODE_RECURSIVE    ///<���ݹ鷽ʽɨ��
}FPI_MS_SCAN_MODE_E;

/**
@brief �����ļ����з�ʽö��
*/
typedef enum 
{
    EN_FPI_MS_SORT_MODE_NAME,       ///<����������
    EN_FPI_MS_SORT_MODE_TIME      ///<��ʱ������
}FPI_MS_SORT_MODE_E;



/**
@brief �����ļ�ɨ���¼�ö��
*/
typedef enum 
{
    EN_FPI_MS_CB_EVENT_SCAN_STARTED,          ///<�ļ�ɨ�迪ʼ
    EN_FPI_MS_CB_EVENT_SCAN_FINISHED,          ///<�ļ�ɨ�����
    EN_FPI_MS_CB_EVENT_SCAN_THUMBNAIL          ///<�ļ�����ͼ��ȡ�ɹ�
}FPI_MS_CB_EVENT_E;


#define MEDIA_FILE_PATH_SIZE 1024

/**
@brief ����ý���ļ���Ϣ�ṹ��
*/
typedef struct
{
    char path[MEDIA_FILE_PATH_SIZE];									///<�ļ�·��
    char name[MEDIA_FILE_PATH_SIZE];									///<�ļ���
    FPI_MS_FILE_TYPE_E type;                    ///< �ļ�����:Dir, picture, video, music, other
    long filesize;                              ///<�ļ���С
    long time;                                  ///<�ļ�����޸�ʱ��
}FPI_MS_File_Node_S;



/**
@brief �ļ�ɨ��Ļص��������Ͷ���

@param[in] event �������¼�����ö��
@param[in] userData �û�����,��ֵΪ����fpi_mp_add_callbackʱ������û�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
typedef fpi_error (*tos_ms_callback_fn)(FPI_MS_CB_EVENT_E event, void *userData);


/**
@brief ���ָ���ļ�ɨ��Ļص�����

@param[in] cb �ص�����ָ��
@param[in] userData �û�����,���ڻص��������׳�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_add_callback(tos_ms_callback_fn cb, void* userData);


/**
@brief ɾ��ָ���ļ�ɨ��Ļص�����

@param[in] cb �ص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_remove_callback(tos_ms_callback_fn cb);



/**
@brief  ��ʼɨ���ļ�·��

@note �˽ӿ�Ϊ�첽

@param[in] path �ļ�·�� .
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_start_scan_file(const char *path);


/**
@brief �˳�ý���ļ�ɨ�裬ֹͣ���ڽ��е��ļ�ɨ�裻

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_cancel_scan_file();


/**
@brief �����ļ����ͻ�ȡ�ļ��б�

@note ���ļ���sort��Ŀ¼�л����ļ������л��������Ҫ��������ӿ��������ļ��б�

@param[in] mode �ļ����з�ʽ
@param[in] path Ҫɨ���Ŀ¼
@param[in] type Ҫɨ����ļ�����(video, audio, picture, all files)
@param[out] list ý���ļ�list
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_get_file_list_by_type(FPI_MS_SORT_MODE_E mode, const char *path, FPI_MS_FILE_TYPE_E type, FPI_MS_File_Node_S *list);



/**
@brief ��ȡָ������ý���ļ��ĸ���

@param[in] path �ļ�·��
@param[in] type Ҫ��ȡ������ý������(Dir, picture, vide, music, other)
@return ý���ļ��ĸ���
*/
int tos_ms_get_file_count(const char *path, FPI_MS_FILE_TYPE_E type);



/**
@brief �����ļ�ɨ�跽ʽ

@param[in] mode �ļ�ɨ�跽ʽ(normal,recursive)
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_set_scan_mode(FPI_MS_SCAN_MODE_E mode);


/**
@brief ��������ͼtask

@param[in] path ý���ļ���·��
@param[in] type ý���ļ�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_create_tmb_task(const char *path, FPI_MS_FILE_TYPE_E type);


/**
@brief ��������ͼtask

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ms_stop_tmb_task();




#ifdef __cplusplus
}
#endif
/** @} */
#endif
