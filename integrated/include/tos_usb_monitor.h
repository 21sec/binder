/**@defgroup tos_usb_monitor
@{

@brief usb�豸����


@history 2015/04/16 ����
@history 2015/04/20 ����������������޸�:����REMOVE_CURRENT_DISK�¼�ö��;��usb�豸������Ϣ�ṹ��������free_size��total_size ; 
                                 ���ƽӿ����ֺ�ע��.

@history 2015/04/22 ���ݲ�����������޸�:  ɾ��REMOVE_CURRENT_DISK�¼�ö��;   
                                ��usb�豸������Ϣ�ṹ��������usb�豸������Ψһ��ʶid ;   
                                ɾ��tos_usb_get_last_partition_count ()�ӿڵ�
**/

#ifndef __TOS_USB_MONITOR_H__
#define __TOS_USB_MONITOR_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ����usb �豸�¼�ö��
*/
typedef enum{
	FPI_USB_CB_EVENT_REMOVE_DISK,				        ///<ж��usb�豸	
	FPI_USB_CB_EVENT_ADD_DISK      					///<����usb�豸	
}FPI_USB_CB_EVENT_E;

#define TOS_USB_FILE_PATH_SIZE 1024

/**
@brief ����usb �豸������Ϣ�ṹ��
*/
typedef struct
{
    int  id;                                ///<usb �豸������ʶid
    char label[TOS_USB_FILE_PATH_SIZE];        					///<usb �豸�������
    char mountpath[TOS_USB_FILE_PATH_SIZE];    					///<usb �豸��������·��
    uint64_t free_size;				///<usb �豸������ʣ��ռ�
    uint64_t total_size;				///<usb �豸�������ܿռ�
}FPI_USB_Partition_Info_S;


/**
@brief usb �Ļص��������Ͷ���

@param[in] event �������¼�����ö��
@param[in] param usb �豸������Ϣ
@param[in] userData �û�����,��ֵΪ����tos_usb_add_callbackʱ������û�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
typedef fpi_error (*tos_usb_callback_fn)(FPI_USB_CB_EVENT_E event, void* param, void *userData);

/**
@brief ���usb �ص�����

@param[in] cb �ص�����ָ��
@param[in] userData �û�����,���ڻص��������׳�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_usb_add_callback(tos_usb_callback_fn cb, void* userData);

/**
@brief ɾ��usb �ص�����

@param[in] cb �ص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_usb_remove_callback(tos_usb_callback_fn cb);



/**
@brief ����usb�豸����

@note �˽ӿڿ��������������˳�

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_usb_monitor_start();

/**
@brief ��ȡϵͳ���ص�usb�洢�豸�������ܸ���

@note �˽ӿ���Ҫ��tos_usb_monitor_start �����

@return ϵͳ���ص�usb�洢�豸�������ܸ���
*/
int tos_usb_get_partition_count();


/**
@brief ��ȡusb �豸�����Ĺ�����Ϣ(����·����usb �ľ��)

@note �˽ӿ����tos_usb_get_partition_count һ��ʹ��;
@note ��ȡָ��usb ����Ϣ: partition_idx = ָ��usb �豸���������;

@param[in] partition_idx usb�豸��������ţ���partition_idx = 2����ʾ�ڶ���usb�豸����(partition_idx < ���ص�usb�豸��������)
@param[out] info �������,usb �豸��������Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_usb_get_partition_info(int partition_idx, FPI_USB_Partition_Info_S* info);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
