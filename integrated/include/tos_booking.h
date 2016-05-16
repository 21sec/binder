/**@defgroup ��ĿԤԼģ��
@{

@brief ���ڿ��ƽ�ĿԤԼ��صĽӿں���
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
@brief ׷��ԤԼ��Ŀ
@param[in] bookInfo ԤԼ��Ŀ��Ϣָ��
@param[out] state ׷�ӳɹ����stateΪ0�ɹ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_add_item(tos_schedule_info_t *bookInfo, EN_TOS_BOOKING_ERROR_e *state);

/**
@brief �༭ԤԼ��Ŀ
@param[in] bookInfo ԤԼ��Ŀ��Ϣָ��
@param[out] state ׷�ӳɹ����stateΪ0�ɹ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_set_item(tos_schedule_info_t *bookInfo, EN_TOS_BOOKING_ERROR_e *state);

/**
@brief ��ȡԤԼ��Ŀ����
@param[out] count ��ĿԤԼ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_get_count(uint8_t* count);

/**
@brief ��ȡԤԼ��Ŀ��Ϣ�б�
@param[in] itemCount ԤԼ��Ŀ����
@param[out] bookInfo ԤԼ��Ŀ��Ϣ�б�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_get_item_list(uint8_t itemCount, tos_schedule_info_t *bookInfoList);

/**
@brief ɾ��ָ����ĿԤԼ
@param[in] scheduleId ��ĿԤԼID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_delete_item(uint8_t scheduleId);

/**
@brief ��ȡԤԼ��Ŀ��Ϣ
@param[in] index ԤԼ��Ŀ��������0��ʼ
@param[out] bookInfo ԤԼ��Ŀ��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_get_item_by_index(uint8_t index, tos_schedule_info_t *bookInfo);

/**
@brief ��ȡԤԼ��Ŀ��Ϣ
@param[in] scheduleId ��ĿԤԼID
@param[out] bookInfo ԤԼ��Ŀ��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_get_item_by_schedule_id(uint8_t scheduleId, tos_schedule_info_t *bookInfo);

/**
@brief ��ȡԤԼ��Ŀ��ʼ�ĵ���ʱʱ��
@param[in] scheduleId ��ĿԤԼID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_get_ahead_second(uint32_t *sec);

/**
@brief ѡ���Ƿ�ִ��ԤԼ�Ķ�������̨��¼�ƻ����Զ����ػ���
@param[in] start_flg �Ƿ�ʼ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_start(fpi_bool start_flg);

/**
@brief ���ָ��ʱ���event�Ƿ�������ԤԼ��ͻ
@param[in] detectPara ��������������Ŀ���͡���Ŀ�ż�ʱ��ε�
@param[out] detectRet ���ؼ��״̬���Ƿ��ͻ����ͻ��ԤԼID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_booking_event_detect(tos_schedule_detect_para *detectPara, tos_schedule_detect_result *detectRet);



#ifdef __cplusplus
}
#endif
/** @} */
#endif
