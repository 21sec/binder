/**@defgroup KTV功能相关
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
*/


#ifndef __TOS_KTV_SETTING_H__
#define __TOS_KTV_SETTING_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif



/**
@brief 开始获取麦克风数据

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_start_obtain_mic_data(char* path);


/**
@brief 停止获取麦克风数据

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_stop_obtain_mic_data(char* path);

	
/**
@brief 设置音效模式

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_set_echo_mode(uint32_t enable,uint32_t mode);


/**
@brief 获取数据库中的信源ID

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_set_key_shift(uint32_t enable,uint32_t mode);


/**
@brief 打开KTV

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_open_ktv(void);


/**
@brief 关闭KTV

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ktv_close_ktv(void);



#ifdef __cplusplus
}
#endif
/** @} */

#endif

