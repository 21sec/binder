/**@defgroup 数字电视Epg模块
@{

@brief 用于控制电视中EPG相关的操作


@version 1.0.0 2014/12/16 初稿
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
	int eventId;                             ///< 事件的ID
	int duration;                       ///< 事件的持续时间,单位是秒
	uint64_t startTime;                      ///< 事件的开始时间,表示到1970年1月1日的秒数(绝对时间).
	unsigned char eventName[EPG_EVENT_NAME_LENGTH];  ///< 事件的标题,utf-8编码格式
	
	char iso639LanguageCode[3];      ///< 事件的语言信息,如果有多语言,此值表示默认优先的一种
	
	uint8_t runnintStatus;                   ///< 运行状态，当前播放状态0x04

	uint8_t parentalRate;                    ///< 成人级别
	uint8_t contentType;                     ///< 节目类型，需要添加宏定义说明
	
	fpi_bool freeCaMode;                     ///< 是否加密
	fpi_bool teletextStatus;                 ///< 是否含teletext,用于在epg页面做一些显示
	fpi_bool subtitleStatus;                 ///< 是否含subtitle，用于在epg页面做一些显示
	fpi_bool hardHearingStatus;              ///< 是否是视听障碍，用于在epg页面做一些显示
}tos_event_info_t;


/**
@brief 获取epg的pf信息

@param[in] channelId 要播放的节目的唯一标识
@param[out] eventList 获取对应节目的pf信息的保存的数组地址
@param[in/out] listSize 对于输入参数表示传入的eventList的size;对于输出参数表示实际填充的eventList的size。对于多语言，可能不止两个
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_get_pf_events(uint32_t channelId, tos_event_info_t *eventList, int *listSize);

/**
@brief 获取epg的指定时间范围的schedule个数

@param[in] channelId 要播放的节目的唯一标识
@param[in] startTime 获取schedule列表的开始时间，以秒为单位，表示到1970年1月1日的秒数
@param[in] endTime   获取schedule列表的结束时间，以秒为单位，表示到1970年1月1日的秒数
@param[out] count 获取一段时间内的event列表，指针类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_get_schedule_event_count(uint32_t channelId, uint64_t startTime, uint64_t endTime, int *count);

/**
@brief 获取epg的schedule信息

只要开始播放，自动缓存EPG信息

@param[in] channelId 要播放的节目的唯一标识
@param[in] startTime 获取schedule列表的开始时间，以秒为单位，表示到1970年1月1日的秒数
@param[in] endTime   获取schedule列表的结束时间，以秒为单位，表示到1970年1月1日的秒数
@param[out] eventList 获取一段时间内的event列表，指针类型
@param[in/out] listSize 对于输入参数表示传入的eventList的size;对于输出参数表示实际填充的eventList的size
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_get_schedule_events(uint32_t channelId, uint64_t startTime, uint64_t endTime, tos_event_info_t *eventList, int *listSize);

/**
@brief 获取epg的指定event的short信息
@param[in] channelId 要播放的节目的唯一标识
@param[in] eventid 指定特定节目某个event的id
@param[out] description 节目详细信息描述内容的指针
@param[in] descriptionLength 传入的description的长度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_get_event_short_description(uint32_t channelId, int eventid, unsigned char *description, int descriptionLength);

/**
@brief 获取epg的指定event的详情信息
@param[in] channelId 要播放的节目的唯一标识
@param[in] eventid 指定特定节目某个event的id
@param[out] description 节目详细信息描述内容的指针
@param[in] descriptionLength 传入的description的长度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_get_event_extend_description(uint32_t channelId, int eventid, unsigned char *description, int descriptionLength);

/**
@brief 进入EPG检测是否有epg linkage
@param[in] 进入EPG页面设置enter_epg_falg 为TRUE,退出EPG页面设置enter_epg_falg 为FALSE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值

*/
fpi_error tos_channel_enter_epg_check_epg_linkage(uint8_t enter_epg_flag);

/**
@brief Epg模块处理回调
当中间件发送Epg更新的消息时,包含的消息内容

@param[in] type 用于区分是schedule或者pf的回掉,0代表PF更新,1代表schedule更新
@param[in] code 产生的事件码值,根据type类型不同有不同的定义
@param[in] data 产生的事件附带数据,根据type类型不同有不同的定义
@param[in] userdata 用户注册的数据，回调中原样返回

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

typedef int (*tos_epg_update)(int cb_type, int cb_code, int cb_data, void* userdata);



/**
@brief 添加Epg模块处理回调
当中间件需要发送Epg更新的消息时,会调用应用注册的本接口配合完成相应的操作的功能.

@param[in] callback Epg更新消息回调函数指针
@param[in] userdata 用户数据,注册此回调时的userdata参数.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_epg_add_callback(tos_epg_update callback, void* userdata);


/**
@brief 删除EPG更新的回调函数

@param[in] callback Epg更新消息回调函数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_epg_remove_callback(tos_epg_update callbakc);


#ifdef __cplusplus
}
#endif
/** @} */
#endif