/**@defgroup KTV�������
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/


#ifndef __TOS_KTV_SETTING_H__
#define __TOS_KTV_SETTING_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif



/**
@brief ��ʼ��ȡ��˷�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_start_obtain_mic_data(char* path);


/**
@brief ֹͣ��ȡ��˷�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_stop_obtain_mic_data(char* path);

	
/**
@brief ������Чģʽ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_set_echo_mode(uint32_t enable,uint32_t mode);


/**
@brief ��ȡ���ݿ��е���ԴID

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_set_key_shift(uint32_t enable,uint32_t mode);


/**
@brief ��KTV

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_open_ktv(void);


/**
@brief �ر�KTV

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ktv_close_ktv(void);



#ifdef __cplusplus
}
#endif
/** @} */

#endif

