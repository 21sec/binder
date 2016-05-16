
/**@defgroup 蓝牙模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda 初稿
*/


#ifndef __TOS_BLUETOOTH_H__
#define __TOS_BLUETOOTH_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 配对的模式
**/
typedef enum   
{
    E_BT_GLASS_MATCH_ON,      
    E_BT_GLASS_MATCH_OFF,      
    E_BT_GLASS_MATCH_PPPOE
}API_BT_GLASS_MATCH;


/**
@brief 设置蓝牙眼镜配对的模式

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_bluetooth_set_master(API_BT_GLASS_MATCH api_bt_glass);

#ifdef __cplusplus
}
#endif
/** @} */

#endif  //_BLUETOOTH_GLASS_H_




