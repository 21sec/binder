/**@defgroup 频道相关数据的管理
主要是频道数据库相关的操作

@{
@brief 用于控制电视中播放相关的操作及获取频道信息相关操作

@version 1.0.0
**/

#ifndef __TOS_DM_CHANNEL_H__
#define __TOS_DM_CHANNEL_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_dtv_basetype.h"


#ifdef __cplusplus
extern "C" {
#endif

#define TOS_CHANNEL_ATTRIBUTE_FAVOR      (0x01<<0)   ///< 可读写，喜好频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_FAVOR)>>0
#define TOS_CHANNEL_ATTRIBUTE_LOCK       (0x01<<1)   ///< 可读写，(optionMask&&TOS_CHANNEL_ATTRIBUTE_LOCK)>>1
#define TOS_CHANNEL_ATTRIBUTE_SKIP       (0x01<<2)   ///< 可读写，跳过频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_SKIP)>>2
#define TOS_CHANNEL_ATTRIBUTE_DELETE     (0x01<<3)   ///< 可读写，删除频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_MASK)>>3
#define TOS_CHANNEL_ATTRIBUTE_HIDE       (0x01<<4)   ///< 可读写，隐藏频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_HIDE)>>4
#define TOS_CHANNEL_ATTRIBUTE_SCRAMBLED (0x01<<5)   //可读写，加密频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_SCRAMBLED)>>5
#define TOS_CHANNEL_ATTRIBUTE_HD         (0x01<<6)   ///< 只读，高清频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_HD)>>6
#define TOS_CHANNEL_ATTRIBUTE_FREE       (0x01<<7)   ///< 只读，明流频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_FREE)>>7
#define TOS_CHANNEL_ATTRIBUTE_CI_OP      (0x01<<8)   ///< 只读，CI_OP的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_CI_OP)>>8
#define TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG (0x01<<9) ///< 只读，频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG)>>9
#define TOS_CHANNEL_ATTRIBUTE_NOT_NUMERICAL (0x01<<10)  ///< 只读，numerical 频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG)>>10, 指定该位表示包含is_numeric为false的节目

#define TOS_CHANNEL_DELIVERYTYPE_OFFSET_BIT     12
#define TOS_CHANNEL_SERVICETYPE_OFFSET_BIT     16
#define TOS_CHANNEL_SELECT_SAT_OFFSET_BIT       21

#define TOS_CHANNEL_ATTRIBUTE_MASK     		(0xFFF) 
#define TOS_CHANNEL_DILIVERYTYPE_MASK     (0x0F<<TOS_CHANNEL_DELIVERYTYPE_OFFSET_BIT) ///< 从mask第十二位到十五位取出，表示diliverytype,等同于EN_FPI_TUNER_MODE
#define TOS_CHANNEL_SERVICETYPE_MASK    	(0x1F<<TOS_CHANNEL_SERVICETYPE_OFFSET_BIT)///< 从mask第十六位到十九位取出，表示servicetype
#define TOS_CHANNEL_SELECT_SATELLITE_MASK (0x01<<TOS_CHANNEL_SELECT_SAT_OFFSET_BIT) ///< 从mask第二十位取出，表示选中某种卫星

typedef struct
{
    uint16_t networkId;                    ///< 运营商ID
    unsigned char  operatorName[NETWORK_NAME_SIZE]; ///< 运营商名称，配置文件进行配置
} tos_channel_operator_info_t;


/**
@brief 根据频道号获取对应的频道索引ID
便于应用通过serviceType及number找到对应的索引ID
@param[in] serviceType  指定的频道类型,Invalid表示所有类型
@param[in] channelNumber  指定的频道号
@param[out] channelId   获取指定频道号对应的频道ID指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channelId_by_number(EN_TOS_SERVICE_TYPE serviceType, uint16_t channelNumber,uint32_t* channelId);
/**
@brief 根据SERVICE TYPE获取对应的频道索引ID
便于应用通过serviceType找到对应的索引ID
@param[in] service_type_mask  指定的频道类型集合(例如ATV+DTV 则service_type_mask=(1<<E_TOS_SERVICE_TYPE_ATV) | (1<<E_TOS_SERVICE_TYPE_DTV)
@param[in] channelId  返回指定的频道ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_current_channelId_by_servicetype(uint32_t service_type_mask,uint32_t *channelId);
/**
@brief 根据频道索引获取频道信息
@param[in] channelIndex  指定的频道索引，唯一标识ID
@param[out] channelInfo  返回对应的频道信息指针，如果索引不在有效的频道列表内，则返回空
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channel_info_by_id(uint32_t channelId, tos_channel_info_t* channelInfo);


/**
@brief 根据频道mask获取对应的频道列表
@param[in] mask 频道的mask过滤条件，根据给出的mask获取频道列表的类型，包含喜好、diliverty、servictType、选中的卫星等
#define TOS_CHANNEL_ATTRIBUTE_FAVOR      (0x01<<0)   ///< 喜好频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_FAVOR)>>0
#define TOS_CHANNEL_ATTRIBUTE_LOCK       (0x01<<1)   ///< 锁定频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_LOCK)>>1
#define TOS_CHANNEL_ATTRIBUTE_SKIP       (0x01<<2)   ///< 跳过频道的属性偏移，为TRUE则需要包含跳过频道，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_SKIP)>>2
#define TOS_CHANNEL_ATTRIBUTE_DELETE     (0x01<<3)   ///< 删除频道的属性偏移，为TRUE则需要包含删除频道，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_MASK)>>3
#define TOS_CHANNEL_ATTRIBUTE_HIDE       (0x01<<4)   ///< 隐藏频道的属性偏移，为TRUE则需要包含隐藏频道，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_HIDE)>>4
#define TOS_CHANNEL_ATTRIBUTE_SCRAMBLED  (0x01<<5)   ///< 付费频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_SCRAMBLED)>>5
#define TOS_CHANNEL_ATTRIBUTE_HD         (0x01<<6)   ///< 高清频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_HD)>>6
#define TOS_CHANNEL_ATTRIBUTE_FREE       (0x01<<7)   ///< 明流频道的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_FREE)>>7
#define TOS_CHANNEL_ATTRIBUTE_CI_OP      (0x01<<8)   ///< CI_OP的属性偏移，频道信息中optionMask获取，(optionMask&&TOS_CHANNEL_ATTRIBUTE_CI_OP)>>8

#define TOS_CHANNEL_ATTRIBUTE_MASK     		(0xFFF) 
#define TOS_CHANNEL_DILIVERYTYPE_MASK     (0x0F<<12) ///< 从mask第十二位到十五位取出，表示diliverytype，对应枚举类型顺序，bit为1表示选择，0表示未选择
#define TOS_CHANNEL_SERVICETYPE_MASK    	(0x0F<<16)///< 从mask第十六位到十九位取出，表示servicetype,对应枚举类型
#define TOS_CHANNEL_SELECT_SATELLITE_MASK (0x0F<<20) ///< 从mask第二十位取出，表示选中某种卫星

@param[out] list  获取的频道列表指针
@param[in/out] count  in：给定频道列表的空间大小，可以出入较大的值512,或者获取的个数
                      out:获取的频道列表的实际长度对应的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channellist_by_mask(uint32_t mask, tos_channel_info_t *list,uint32_t *count);

/**
@brief  mask 频道的mask过滤条件，根据给出的mask获取频道列表的类型，包含喜好、diliverty、servictType、选中的卫星等
@param[in] mask 设置的频道列表类型
@param[out] count  返回的频道个数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channel_count_by_mask(uint32_t mask,uint32_t *count);

/**
@brief 节目的编辑操作
只进行缓存操作
当编辑一个频道时，直接调用，当移动或交换操作，需要编辑多个频道时，进行多次调用
@param[in] info  需要编辑的频道信息指针，包含编辑频道号 频道名称 频道属性等
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_set_channel_info(tos_channel_info_t *info);

/**
@brief 获取节目列表的版本号
出厂时版本号未0，当频道数据库发生变化，如频道编辑，版本号会发生变化
例如使用场景：ipepg发布版本号给到服务器，数据库变化时版本号变化，ipepg通知网络服务器。
@param[out] chListVersion  获取节目列表的版本号指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_channel_list_version(uint32_t *chListVersion);

/**
@brief 获取运营商列表
@param[out] networkList  运营商信息列表指针
@param[in/out] count  in：传入运营商的个数，通过tos_channel_dtv_get_operator_count获取
                      out:返回运营商实际个数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_operator_list(tos_channel_operator_info_t* networkList, uint32_t *count);

/**
@brief 获取运营商个数
@param[count] count  运营商个数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_operator_count(uint32_t *count);

/**
待定
@brief 设置当前运营商信息
根据用户选择的运营商以后，搜台或节目更新后，根据喜好运营商进行一些处理，比如排序优先
@param[in] networkId  设置运营商信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_set_fav_networkId(uint16_t networkId);

/**
待定
@brief 获取当前运营商信息
根据用户选择的运营商以后，搜台或节目更新后，根据喜好运营商进行一些处理，比如排序优先
@param[out] networkId  运营商Id指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_fav_networkId(uint16_t *networkId);
/*
@brief 返回最后一次节目的类型
@param[in]	无
@param[out]EN_TOS_SERVICE_TYPE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_last_service_type(EN_TOS_SERVICE_TYPE *type);


/**
@brief 根据muxId获取demux的信息
@param[in] muxId  指定的muxId
@param[out] muxInfo  返回指定muxId对应的信息，如果不是有效的muxId，则返回空
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_muxInfo(int32_t muxId, tos_dtv_mux_info_t *muxInfo);


/**
@brief 清除频道列表
只进行缓存操作
@param[in] deliverytype  对应EN_FPI_DEVILITY_TYPE枚举,E_DEVILITY_TYPE_INVALID表示全部删除
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_clean_channel_list(fpi_dtv_delivery_type_t deliverytype);

/**
@brief 数据库更新操作
当频道数据编辑及删除后，只进行缓存操作，当调用本接口时，将缓存保存数据库
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_db_update();

/**
待定
@brief 获取与当前节目相同LCN的节目号
@param[out] pstChannelNumber  返回与当前节目相同LCN的节目号
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_get_program_number_by_same_lcn(uint16_t *pstChannelNumber);

/*
@brief 把源节目移动到目标节目的位置
@param[in]	srcChIndex 源节目的索引位置，dstChIndex 目标节目的索引位置
@param[out]	无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_move_program_by_index(uint32_t srcChIndex, uint32_t dstChIndex);

/*
@brief 把源节目插入到目标节目的位置
@param[in]	srcChIndex 源节目的索引位置，dstChIndex 目标节目的索引位置
@param[out]	无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_channel_list_channel_insert(uint32_t srcChIndex, uint32_t dstChIndex);

/******************************************************************************
*Function: tos_channel_play_set_audio_delay
*Description:
*Input: none
*Param:
    channelId:the channel's id;if channel_id==-1 then set audio delay to current play channel
    audio_delay_ms: audio delay's time
*Return: fpi_error:  FPI_ERROR_SUCCESS -- set audio delay success
                     FPI_ERROR_FAIL  -- set channel audio delay failure
*Others: none
******************************************************************************/
fpi_error tos_channel_play_set_audio_delay(uint16_t channelId,int32_t  audio_delay_ms);

/******************************************************************************
*Function: tos_channel_play_set_audio_delay
*Description:
    get channel's audio play
*Input: none
*Param:
    channelId:the channel's id;if channel_id==-1 then set audio delay to current play channel
    p_audio_delay_ms: return audio delay's time
*Return: fpi_error:  FPI_ERROR_SUCCESS -- set audio delay success
                     FPI_ERROR_FAIL  -- set channel audio delay failure
*Others: none
******************************************************************************/
fpi_error tos_channel_play_get_audio_delay(uint16_t channelId,int32_t* p_audio_delay_ms);


/******************************************************************************
*Function: tos_channel_get_first_index_by_rf_number
*Description;根据rf_number获取与之匹配的第一个channel index
*Input: uint8_t u8_rf_number,频道信息中的rf_number
       uint16_t* channel_index，获取channel num对应的channel index
*Return: fpi_error:  FPI_ERROR_SUCCESS -- get success
                     FPI_ERROR_FAIL  -- get fail 
*Others: none
******************************************************************************/
fpi_error tos_channel_get_first_index_by_rf_number(uint8_t u8_rf_number, uint16_t* channel_index);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
