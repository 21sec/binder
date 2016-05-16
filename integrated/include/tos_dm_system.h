/**@defgroup ���ݿ�ϵͳ�����Ϣ

@{
@brief ���ڿ��Ƶ��������ݿ�ϵͳ��ص�����

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
    E_TOS_LAST_STATUS,              ///< ���һ�α����״̬
    E_TOS_UER_SELECT,               ///< �û�ѡ��״̬
} EN_TOS_CHANNEL_SELECT_MODE;   ///< ѡ�񿪻�Ƶ��ģʽ

typedef enum
{
    E_DTV_CHANNEL_LIST_TYPE_BROADCAST    = 0x00,
    E_DTV_CHANNEL_LIST_TYPE_CI_OP
}EN_TOS_CI_OP_CHANNEL_LIST_TYPE;


/**
@brief ���ÿ���Ƶ��
һ������Ӧ���ڿ���Ƶ��ѡ��ģʽΪ�û�ѡ��ʱ���������ÿ���Ƶ��
@param[in] info  ���ÿ���Ƶ������Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_set_power_on_play_channel(uint32_t channelIndex);

/**
@brief ��ȡ����Ƶ������Ϣ
һ������Ӧ���ڿ���Ƶ��ѡ��ģʽΪ�û�ѡ��ʱ����ȡ����Ƶ��
@param[out] info  ����Ƶ������Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_power_on_play_channel_info(tos_channel_info_t *info);

/**
@brief ��ȡ����Ƶ����ѡ������

@param[out] mode  ���صĿ���Ƶ��ѡ�����͵�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_system_get_power_on_select_mode(EN_TOS_CHANNEL_SELECT_MODE *mode);

/**
@brief ���ÿ���Ƶ����ѡ������
@param[in] mode  ���ÿ���Ƶ��ѡ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_system_set_power_on_select_mode(EN_TOS_CHANNEL_SELECT_MODE mode);

/**
@brief ���ù��ҵ���
@param[in] country ��Ҫ���õĹ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_set_system_country(MEMBER_COUNTRY country);

/**
@brief ��ȡ��ǰ�Ĺ���

@param[out] country ��ȡ��ǰ�Ĺ���ָ��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_system_country(MEMBER_COUNTRY *country);

/**
@brief ��ȡtuner����
@param[out] mode ���ػ�ȡ����tuner����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_tuner_get_delivery_type(fpi_dtv_delivery_type_t *mode);

/**
@brief ����tuner����
@param[in] mode ��Ҫ���õ�tuner����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_tuner_set_delivery_type(fpi_dtv_delivery_type_t mode);

/**
����
@brief ����ʱ��״̬�Ŀ���
@param[in] value ʱ��״̬�Ŀ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_set_pvr_time_shift_enable_status(fpi_bool status); 

/**
����
@brief ��ȡʱ��״̬�Ŀ���
@param[out] value ʱ��״̬�Ŀ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_get_pvr_time_shift_enable_status(fpi_bool *status); 

/**
����
@brief ���õ�һ��������
@param[in] value ʱ��״̬�Ŀ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_set_first_audio_language(MEMBER_LANGUAGE language);

/**
����
@brief ��ȡ��һ��������
@param[in] value ʱ��״̬�Ŀ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_get_first_audio_language(MEMBER_LANGUAGE *value);

/**
����
@brief ���õڶ���������
@param[in] value ʱ��״̬�Ŀ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_set_second_audio_language(MEMBER_LANGUAGE language);

/**
����
@brief ��ȡ�ڶ���������
@param[in] value ʱ��״̬�Ŀ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_get_second_audio_language(MEMBER_LANGUAGE *value);

/**
@brief ����Ƶ���б�����
����
@param[in] type  ���õ�Ƶ���б�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_set_channel_list_type(EN_TOS_CHANEL_LIST_TYPE type);

/**
����
@brief ��ȡƵ���б�����
@param[out] type  ���ص�Ƶ���б����͵�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channel_list_type(EN_TOS_CHANEL_LIST_TYPE* type);

/**
@brief ��ȡci op channel ״̬
@param[out] value EN_TOS_CI_OP_CHANNEL_LIST_TYPE
                  E_DTV_CHANNEL_LIST_TYPE_BROADCAST,
                  E_DTV_CHANNEL_LIST_TYPE_CI_OP
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_get_channel_list_type(EN_TOS_CI_OP_CHANNEL_LIST_TYPE *value);

/**
@brief ����CI OP״̬
@param[in] value EN_TOS_CI_OP_CHANNEL_LIST_TYPE
                  E_DTV_CHANNEL_LIST_TYPE_BROADCAST,
                  E_DTV_CHANNEL_LIST_TYPE_CI_OP
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_set_channel_list_type(EN_TOS_CI_OP_CHANNEL_LIST_TYPE type);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
