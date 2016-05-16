/**@defgroup ��Դ���������ģ��
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda ����
*/



#ifndef _FUNCTION_POWER_H_
#define _FUNCTION_POWER_H_
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief �����ػ�����
**/
typedef enum
{
	EN_SETTING_POWER_ON,		///<����
	EN_SETTING_POWER_OFF,		///<�ػ�
}EN_SETTING_POWER_CTRL;


/**
@brief �ص��ӷ����̵߳�ģʽ
**/
typedef enum{
	EN_SUBSERVICE_SOME, ///<�ص����ӷ����ѡ��
}EN_SUBSERVICE_TYPE;

/**
@brief ��Դ����ģʽ
**/
typedef enum
{
    EN_POWER_TIMER_OFF,
    EN_POWER_TIMER_EVERYDAY,
    EN_POWER_TIMER_ONCE
} EN_POWER_TIMER_MODE;

typedef enum
{
	EN_PRE_POWEROFF, ///<׼���ػ�
	EN_PRE_REBOOT,  ///<׼������
	EN_NORMAL_POWEROFF,	///if hardware support str and str swith is on,then execute str poweroff,else execute really poweroff				EN_REAL_POWEROFF
	EN_FORCE_POWEROFF,	///force to execute really poweroff,next power will cold poweron,
}EN_POWEROFF_TYPE;

/**
@brief ���ÿ��ػ�ģʽ

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_set_mode(EN_SETTING_POWER_CTRL type,EN_POWER_TIMER_MODE mode);


/**
@brief ��õ�Դ����ģʽ

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_get_mode(EN_SETTING_POWER_CTRL type,EN_POWER_TIMER_MODE *mode);

 /**
@brief �ػ�

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_power_off(EN_POWEROFF_TYPE type);

 /**
@brief ȡ���ػ�

@note  

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cancel_power_off(void);

 






#ifdef __cplusplus
}
#endif
/** @} */

#endif //_FUNCTION_SETTING_H_
