/**@defgroup 公用数据管理
主要是各模块公共使用的数据结构，不包含接口

@{
@brief 用于控制电视中公用数据结构管理

@version 1.0.0
**/
#ifndef __TOS_DTV_BASETYPE_H__
#define __TOS_DTV_BASETYPE_H__

/*****************************************************/
#include "fpi_dtv_base.h"
/*****************************************************/

#define CHANNEL_NAME_SIZE 64
#define NETWORK_NAME_SIZE 48


#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{   
    E_TOS_SERVICE_TYPE_ATV,              ///< 模拟频道
    E_TOS_SERVICE_TYPE_DTV,              ///< 数字频道
    E_TOS_SERVICE_TYPE_RADIO,            ///< 广播频道
    E_TOS_SERVICE_TYPE_DATA,             ///< 数据
    E_TOS_SERVICE_TYPE_UNITED_TV,        ///< 数字频道，除广播及数据外
    E_TOS_SERVICE_TYPE_INVALID
} EN_TOS_SERVICE_TYPE;

typedef enum
{
    E_TOS_CHANNEL_ALL,                   ///< 全部频道类型
    E_TOS_CHANNEL_DIGINAL,               ///< 数字频道类型
    E_TOS_CHANNEL_ANALOGUE,              ///< 模拟频道类型
    E_TOS_CHANNEL_RAIDO,                 ///< 广播频道类型
    E_TOS_CHANNEL_FREE,                  ///< 模拟频道+明流的数字及广播频道
    E_TOS_CHANNEL_FAVORITES,             ///< 模拟频道和数字频道中的属性为喜好的频道
    E_TOS_CHANNEL_SINGLE_SATELLITE,      ///< 单一卫星频道  用于卫星节目
    E_TOS_CHANNEL_DATA_OTHERS,		       ///< 数据类型
    E_TOS_CHANNEL_NUM
} EN_TOS_CHANEL_LIST_TYPE;           ///< 频道列表类型

typedef enum
{
    E_TUNER_MODE_CABLE, // dtvc
    E_TUNER_MODE_AIR, //dvbt
    E_TUNER_MODE_SATELLITE,
    E_TUNER_MODE_DVBT2,
    E_TUNER_MODE_DTMB, //add by lwf 2014.02.05
    E_TUNER_MODE_INVALID
} EN_API_TUNER_MODE;


typedef struct
{
    fpi_dtv_delivery_type_t deliveryType; ///< deliveryType
    uint32_t satelliteId;            ///< 卫星Id
    uint16_t networkId;              ///< 运营商Id
    uint16_t originalNetworkId;      ///< originalNetworkId
    uint16_t transportStreamId;      ///< transportStreamId
    uint32_t frequency;              ///< frequency KHZ
    uint32_t symbolRate;             ///< symbolRate bps
    fpi_dtv_qam_mode_t qamMod;   ///< qamMod 枚举
    uint8_t bandWidth;               ///< bandWidth
    unsigned char networkName[NETWORK_NAME_SIZE];	///< 流解析出来的networkName
} tos_dtv_mux_info_t;

typedef struct
{
    EN_TOS_SERVICE_TYPE serviceType;     ///< 频道类型
    fpi_dtv_delivery_type_t  deliveryType;    ///< 传输类型，对应枚举EN_FPI_DELIVERY_TYPE
    uint32_t channelId;                  ///< 频道ID，可以唯一标识一个频道
    uint32_t optionMask;                 ///< 频道的属性
    uint16_t channelNumber;                    ///< 频道号,对于ATSC和ISDB高8位对应MAJOR 低8位对应MIRROR CHANNEL NO。
    unsigned char channelName[CHANNEL_NAME_SIZE];       ///< 频道名称，编码格式utf-8
    int32_t frequency;                  ///< 频率信息KHz，跟servictType关联，区分ATV DTV
    uint32_t satelliteId;            ///< 卫星Id
    
    uint16_t audioPid;                  ///<  audioPid
    uint16_t videoPid;                  ///<  videoPid
    uint16_t muxInfoId;                 ///< 唯一确定频点的信息
    uint16_t originalNetworkId;      ///< originalNetworkId
    uint16_t transportStreamId;      ///< transportStreamId
    uint32_t serviceId;                 ///< serviceID
    uint8_t real_service_type;//real service type which received from ts
    /*************channel edit attribute**************/
    fpi_bool is_ci_op;//is CI op service
    fpi_bool is_favor;
    fpi_bool is_skip;
    fpi_bool is_lock;
    fpi_bool is_hd;//is HD service
    fpi_bool is_have_unlocked;//current program is have been unlocked
    fpi_bool is_deleted;
    fpi_bool is_scramble;
    fpi_bool is_numeric;//fpi_false:just can be select by numerical;fpi_true:can be select any state
    // for epg show subtitle or teletext is exit state
    fpi_bool is_subtitle_on;
    // for epg show subtitle or teletext is exit state
    fpi_bool is_teletext_on;
    /****以下为atv特有频道相关属性***/
    
    uint8_t colorSystem;               ///< 彩色制式
    uint8_t soundSystem;               ///< 声音制式
    int32_t db_primary_key;//database primary key in database
} tos_channel_info_t;


#ifdef __cplusplus
}
#endif
/** @} */
#endif
