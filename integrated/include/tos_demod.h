/**@defgroup ������Ƶģ��
@{

@brief ���ڿ���
**/

#ifndef __TOS_DEMOD_H__
#define __TOS_DEMOD_H__

#include "fpi_error_code.h"
#include "fpi_dtv_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ���ݴ���Ĳ�������ָ����Ƶ��
@param[in] dtv_delivery, ��Ƶ�Ĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_demod_lock_freqency(fpi_dtv_delivery_t *dtv_delivery);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
