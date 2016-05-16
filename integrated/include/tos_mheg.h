/**@defgroup MHEGģ��

@{
@brief ���ڿ��Ƶ�����MHEG��ز���

@version 1.0.0
**/

#ifndef __TOS_MHEG_H__
#define __TOS_MHEG_H__
#include "tos_dtv_basetype.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
@brief ��MHEG5
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mheg_start(void);

/**
@brief ֹͣMHEG5
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mheg_stop(void);

/**
@brief �ж�MHEG�Ƿ��
@param[out] value �ж�MHEG�Ƿ��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mheg_is_open(fpi_bool *value);


/**
@brief MHEG��ֵ�ַ�
@param[in] keycode �ַ��ļ�ֵ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mheg_dispatch_key_code(uint32_t keycode);


/**
@brief MHEG��ȡ�û�����״̬
@param[in] value �û�����״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mheg_get_userinput_state(uint8_t *value);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
