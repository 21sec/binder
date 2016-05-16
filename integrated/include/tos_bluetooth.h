
/**@defgroup ����ģ��
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda ����
*/


#ifndef __TOS_BLUETOOTH_H__
#define __TOS_BLUETOOTH_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief ��Ե�ģʽ
**/
typedef enum   
{
    E_BT_GLASS_MATCH_ON,      
    E_BT_GLASS_MATCH_OFF,      
    E_BT_GLASS_MATCH_PPPOE
}API_BT_GLASS_MATCH;


/**
@brief ���������۾���Ե�ģʽ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_bluetooth_set_master(API_BT_GLASS_MATCH api_bt_glass);

#ifdef __cplusplus
}
#endif
/** @} */

#endif  //_BLUETOOTH_GLASS_H_




