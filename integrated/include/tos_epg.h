/**@defgroup ���ֵ���Epgģ��
@{

@brief ���ڿ��Ƶ�����EPG��صĲ���


@version 1.0.0 2014/12/16 ����
**/

#ifndef __tos_epg_H__
#define __tos_epg_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EPG_EVENT_NAME_LENGTH 64

#define EPG_COMPONENT_SUBTITLE_MASK 0x01
#define EPG_CONPONENT_TELETEXT_MASK 0x02


typedef struct
{
	int eventId;                             ///< �¼���ID
	int duration;                       ///< �¼��ĳ���ʱ��,��λ����
	uint64_t startTime;                      ///< �¼��Ŀ�ʼʱ��,��ʾ��1970��1��1�յ�����(����ʱ��).
	unsigned char eventName[EPG_EVENT_NAME_LENGTH];  ///< �¼��ı���,utf-8�����ʽ
	
	char iso639LanguageCode[3];      ///< �¼���������Ϣ,����ж�����,��ֵ��ʾĬ�����ȵ�һ��
	
	uint8_t runnintStatus;                   ///< ����״̬����ǰ����״̬0x04

	uint8_t parentalRate;                    ///< ���˼���
	uint8_t contentType;                     ///< ��Ŀ���ͣ���Ҫ��Ӻ궨��˵��
	
	fpi_bool freeCaMode;                     ///< �Ƿ����
	fpi_bool teletextStatus;                 ///< �Ƿ�teletext,������epgҳ����һЩ��ʾ
	fpi_bool subtitleStatus;                 ///< �Ƿ�subtitle��������epgҳ����һЩ��ʾ
	fpi_bool hardHearingStatus;              ///< �Ƿ��������ϰ���������epgҳ����һЩ��ʾ
}tos_event_info_t;


/**
@brief ��ȡepg��pf��Ϣ

@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@param[out] eventList ��ȡ��Ӧ��Ŀ��pf��Ϣ�ı���������ַ
@param[in/out] listSize �������������ʾ�����eventList��size;�������������ʾʵ������eventList��size�����ڶ����ԣ����ܲ�ֹ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_get_pf_events(uint32_t channelId, tos_event_info_t *eventList, int *listSize);

/**
@brief ��ȡepg��ָ��ʱ�䷶Χ��schedule����

@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@param[in] startTime ��ȡschedule�б�Ŀ�ʼʱ�䣬����Ϊ��λ����ʾ��1970��1��1�յ�����
@param[in] endTime   ��ȡschedule�б�Ľ���ʱ�䣬����Ϊ��λ����ʾ��1970��1��1�յ�����
@param[out] count ��ȡһ��ʱ���ڵ�event�б�ָ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_get_schedule_event_count(uint32_t channelId, uint64_t startTime, uint64_t endTime, int *count);

/**
@brief ��ȡepg��schedule��Ϣ

ֻҪ��ʼ���ţ��Զ�����EPG��Ϣ

@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@param[in] startTime ��ȡschedule�б�Ŀ�ʼʱ�䣬����Ϊ��λ����ʾ��1970��1��1�յ�����
@param[in] endTime   ��ȡschedule�б�Ľ���ʱ�䣬����Ϊ��λ����ʾ��1970��1��1�յ�����
@param[out] eventList ��ȡһ��ʱ���ڵ�event�б�ָ������
@param[in/out] listSize �������������ʾ�����eventList��size;�������������ʾʵ������eventList��size
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_get_schedule_events(uint32_t channelId, uint64_t startTime, uint64_t endTime, tos_event_info_t *eventList, int *listSize);

/**
@brief ��ȡepg��ָ��event��short��Ϣ
@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@param[in] eventid ָ���ض���Ŀĳ��event��id
@param[out] description ��Ŀ��ϸ��Ϣ�������ݵ�ָ��
@param[in] descriptionLength �����description�ĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_get_event_short_description(uint32_t channelId, int eventid, unsigned char *description, int descriptionLength);

/**
@brief ��ȡepg��ָ��event��������Ϣ
@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@param[in] eventid ָ���ض���Ŀĳ��event��id
@param[out] description ��Ŀ��ϸ��Ϣ�������ݵ�ָ��
@param[in] descriptionLength �����description�ĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_get_event_extend_description(uint32_t channelId, int eventid, unsigned char *description, int descriptionLength);

/**
@brief ����EPG����Ƿ���epg linkage
@param[in] ����EPGҳ������enter_epg_falg ΪTRUE,�˳�EPGҳ������enter_epg_falg ΪFALSE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ

*/
fpi_error tos_channel_enter_epg_check_epg_linkage(uint8_t enter_epg_flag);

/**
@brief Epgģ�鴦��ص�
���м������Epg���µ���Ϣʱ,��������Ϣ����

@param[in] type ����������schedule����pf�Ļص�,0����PF����,1����schedule����
@param[in] code �������¼���ֵ,����type���Ͳ�ͬ�в�ͬ�Ķ���
@param[in] data �������¼���������,����type���Ͳ�ͬ�в�ͬ�Ķ���
@param[in] userdata �û�ע������ݣ��ص���ԭ������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

typedef int (*tos_epg_update)(int cb_type, int cb_code, int cb_data, void* userdata);



/**
@brief ���Epgģ�鴦��ص�
���м����Ҫ����Epg���µ���Ϣʱ,�����Ӧ��ע��ı��ӿ���������Ӧ�Ĳ����Ĺ���.

@param[in] callback Epg������Ϣ�ص�����ָ��
@param[in] userdata �û�����,ע��˻ص�ʱ��userdata����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_epg_add_callback(tos_epg_update callback, void* userdata);


/**
@brief ɾ��EPG���µĻص�����

@param[in] callback Epg������Ϣ�ص�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_epg_remove_callback(tos_epg_update callbakc);


#ifdef __cplusplus
}
#endif
/** @} */
#endif