/**@defgroup 节目预约模块
@{

@brief 用于控制节目预约相关的接口函数
**/

#ifndef __TOS_BOOKING_H__
#define __TOS_BOOKING_H__

#include "fpi_error_code.h"
//#include "tos_dm_channel.h"
#include "tos_function_safety.h"
#include "tos_demod.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    EN_REPEAT_MODE_ONCE = 0,
    EN_REPEAT_MODE_DAILY,
    EN_REPEAT_MODE_WEEKLY
} EN_TOS_BOOKING_REPEAT_MODE;

typedef enum
{
    EN_SCHEDULE_MODE_RECORD = 0,
    EN_SCHEDULE_MODE_REMINDER
} EN_TOS_BOOKING_MODE;

typedef enum
{
    EN_BOOKING_TYPE_PLAY,
    EN_BOOKING_TYPE_RECORD,
    EN_BOOKING_TYPE_POWER_OFF,
    EN_BOOKING_TYPE_POWER_ON,
} EN_TOS_BOOKING_TYPE;

typedef enum
{
    BOOKING_NO_ERROR = 0,
    BOOKING_CONFLICT,
    BOOKING_BEYOND_MAX_NUM,
    BOOKING_INVALID_DURATION,
    BOOKING_INVALID_TUNER_MODE,
    BOOKING_INVALID_DATE,
    BOOKING_NOT_INITIALIZED
} EN_TOS_BOOKING_ERROR_e;

typedef struct
{
    int32_t schedule_id;
    fpi_dtv_delivery_type_t tuner_mode;
    int32_t channel_num;
    int32_t service_type;//EN_API_SERVICE_TYPE
    char channel_name[64];//CHANNEL_NAME_SIZE
    char program_title[64];//CHANNEL_NAME_SIZE
    st_api_date start_time;
    int32_t duration;
    EN_TOS_BOOKING_REPEAT_MODE repeat_mode;
    EN_TOS_BOOKING_MODE schedule_mode;
    uint16_t channel_index;
}tos_schedule_info_t;

typedef struct
{
    int32_t channel_num;
    int32_t service_type;//EN_API_SERVICE_TYPE
    st_api_date start_time;
    int32_t duration;
} tos_schedule_detect_para;


typedef struct
{
    EN_TOS_BOOKING_TYPE book_type;
    int32_t schedule_id;
    fpi_bool is_booked;
} tos_schedule_detect_result;

/**
@brief 追加预约节目
@param[in] bookInfo 预约节目信息指针
@param[out] state 追加成功与否，state为0成功
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_add_item(tos_schedule_info_t *bookInfo, EN_TOS_BOOKING_ERROR_e *state);

/**
@brief 编辑预约节目
@param[in] bookInfo 预约节目信息指针
@param[out] state 追加成功与否，state为0成功
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_set_item(tos_schedule_info_t *bookInfo, EN_TOS_BOOKING_ERROR_e *state);

/**
@brief 获取预约节目个数
@param[out] count 节目预约个数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_get_count(uint8_t* count);

/**
@brief 获取预约节目信息列表
@param[in] itemCount 预约节目个数
@param[out] bookInfo 预约节目信息列表指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_get_item_list(uint8_t itemCount, tos_schedule_info_t *bookInfoList);

/**
@brief 删除指定节目预约
@param[in] scheduleId 节目预约ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_delete_item(uint8_t scheduleId);

/**
@brief 获取预约节目信息
@param[in] index 预约节目索引，从0开始
@param[out] bookInfo 预约节目信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_get_item_by_index(uint8_t index, tos_schedule_info_t *bookInfo);

/**
@brief 获取预约节目信息
@param[in] scheduleId 节目预约ID
@param[out] bookInfo 预约节目信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_get_item_by_schedule_id(uint8_t scheduleId, tos_schedule_info_t *bookInfo);

/**
@brief 获取预约节目开始的倒计时时间
@param[in] scheduleId 节目预约ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_get_ahead_second(uint32_t *sec);

/**
@brief 选择是否执行预约的动作，换台、录制或者自动开关机等
@param[in] start_flg 是否开始标记
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_start(fpi_bool start_flg);

/**
@brief 检查指定时间段event是否与现有预约冲突
@param[in] detectPara 检查参数，包括节目类型、节目号及时间段等
@param[out] detectRet 返回检查状态，是否冲突及冲突的预约ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_booking_event_detect(tos_schedule_detect_para *detectPara, tos_schedule_detect_result *detectRet);



#ifdef __cplusplus
}
#endif
/** @} */
#endif
