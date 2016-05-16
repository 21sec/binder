/**@defgroup 数据库系统相关信息

@{
@brief 用于控制电视中数据库系统相关的配置

@version 1.0.0
**/

#ifndef __TOS_DM_SYSTEM_H__
#define __TOS_DM_SYSTEM_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_dtv_basetype.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    E_TOS_LAST_STATUS,              ///< 最后一次保存的状态
    E_TOS_UER_SELECT,               ///< 用户选择状态
} EN_TOS_CHANNEL_SELECT_MODE;   ///< 选择开机频道模式

typedef enum
{
    E_DTV_CHANNEL_LIST_TYPE_BROADCAST    = 0x00,
    E_DTV_CHANNEL_LIST_TYPE_CI_OP
}EN_TOS_CI_OP_CHANNEL_LIST_TYPE;


/**
@brief 设置开机频道
一般用于应用在开机频道选择模式为用户选择时，进行设置开机频道
@param[in] info  设置开机频道的信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_set_power_on_play_channel(uint32_t channelIndex);

/**
@brief 获取开机频道的信息
一般用于应用在开机频道选择模式为用户选择时，获取开机频道
@param[out] info  开机频道的信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_power_on_play_channel_info(tos_channel_info_t *info);

/**
@brief 获取开机频道的选择类型

@param[out] mode  返回的开机频道选择类型的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_system_get_power_on_select_mode(EN_TOS_CHANNEL_SELECT_MODE *mode);

/**
@brief 设置开机频道的选择类型
@param[in] mode  设置开机频道选择类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_system_set_power_on_select_mode(EN_TOS_CHANNEL_SELECT_MODE mode);

/**
@brief 设置国家地区
@param[in] country 需要设置的国家
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_set_system_country(MEMBER_COUNTRY country);

/**
@brief 获取当前的国家

@param[out] country 获取当前的国家指针

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_system_country(MEMBER_COUNTRY *country);

/**
@brief 获取tuner类型
@param[out] mode 返回获取到的tuner类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_tuner_get_delivery_type(fpi_dtv_delivery_type_t *mode);

/**
@brief 设置tuner类型
@param[in] mode 需要设置的tuner类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_tuner_set_delivery_type(fpi_dtv_delivery_type_t mode);

/**
待定
@brief 设置时移状态的开关
@param[in] value 时移状态的开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_set_pvr_time_shift_enable_status(fpi_bool status); 

/**
待定
@brief 获取时移状态的开关
@param[out] value 时移状态的开关指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_get_pvr_time_shift_enable_status(fpi_bool *status); 

/**
待定
@brief 设置第一声音语言
@param[in] value 时移状态的开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_set_first_audio_language(MEMBER_LANGUAGE language);

/**
待定
@brief 获取第一声音语言
@param[in] value 时移状态的开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_get_first_audio_language(MEMBER_LANGUAGE *value);

/**
待定
@brief 设置第二声音语言
@param[in] value 时移状态的开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_set_second_audio_language(MEMBER_LANGUAGE language);

/**
待定
@brief 获取第二声音语言
@param[in] value 时移状态的开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_get_second_audio_language(MEMBER_LANGUAGE *value);

/**
@brief 设置频道列表类型
待定
@param[in] type  设置的频道列表类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_set_channel_list_type(EN_TOS_CHANEL_LIST_TYPE type);

/**
待定
@brief 获取频道列表类型
@param[out] type  返回的频道列表类型的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channel_list_type(EN_TOS_CHANEL_LIST_TYPE* type);

/**
@brief 获取ci op channel 状态
@param[out] value EN_TOS_CI_OP_CHANNEL_LIST_TYPE
                  E_DTV_CHANNEL_LIST_TYPE_BROADCAST,
                  E_DTV_CHANNEL_LIST_TYPE_CI_OP
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_get_channel_list_type(EN_TOS_CI_OP_CHANNEL_LIST_TYPE *value);

/**
@brief 设置CI OP状态
@param[in] value EN_TOS_CI_OP_CHANNEL_LIST_TYPE
                  E_DTV_CHANNEL_LIST_TYPE_BROADCAST,
                  E_DTV_CHANNEL_LIST_TYPE_CI_OP
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_set_channel_list_type(EN_TOS_CI_OP_CHANNEL_LIST_TYPE type);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
