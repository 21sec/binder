/**@defgroup ��Դ���������ģ��
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda ����
*/



#ifndef _TOS_POWER_SUSPEND_H_
#define _TOS_POWER_SUSPEND_H_
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ��ϵͳ֧�ֿ��ٿ���������£����ÿ��ٿ����Ŀ����ǿ����ǹ�

@note  input :flag-- fpi_true->fast boot switch on;  fpi_false->fast boot switch off

@note 

@return always FPI_ERROR_SUCCESS;
*/
fpi_error tos_power_suspend_set_onoff_status(fpi_bool flag);


/**
@brief ��ȡ���ٿ����Ŀ����ǿ����ǹ�

@note  

@note 

@return always FPI_ERROR_SUCCESS;
*/
fpi_error tos_power_suspend_get_onoff_status(fpi_bool *flag);

/**
@brief ���ÿ��ػ�ģʽ

@note  input :mode-- 0->no str    1->str_suspend   2->str_resume   3->std_suspend   4->std_resume

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
//fpi_error tos_power_suspend_set_mode(EN_POWER_SUSPEND_WORK_MODE mode);

/**
@brief ����ģ���ڲ�����

@note  var :

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_suspend_set_str_debug_val(int var);

/**
@brief ���ϵͳ�Ƿ�֧��STR����STR֧�ֵ���G?

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_suspend_get_support_status(EN_POWER_SUSPEND_SUPPORT *type);

/**
@brief ���ϵͳ��ǰ��suspend/resume����ģʽ

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_suspend_get_current_work_mode(EN_POWER_SUSPEND_WORK_MODE *mode);

/**
@brief ���ϵͳ��USBģ���Ƿ񻹴���STR������resume״̬

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_suspend_get_usb_device_resuming_status(fpi_bool *flag);

#ifdef __cplusplus
}
#endif
/** @} */

#endif //_TOS_POWER_SUSPEND_H_