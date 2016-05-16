/**@defgroup �������ݹ���
��Ҫ�Ǹ�ģ�鹫��ʹ�õ����ݽṹ���������ӿ�

@{
@brief ���ڿ��Ƶ����й������ݽṹ����

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
    E_TOS_SERVICE_TYPE_ATV,              ///< ģ��Ƶ��
    E_TOS_SERVICE_TYPE_DTV,              ///< ����Ƶ��
    E_TOS_SERVICE_TYPE_RADIO,            ///< �㲥Ƶ��
    E_TOS_SERVICE_TYPE_DATA,             ///< ����
    E_TOS_SERVICE_TYPE_UNITED_TV,        ///< ����Ƶ�������㲥��������
    E_TOS_SERVICE_TYPE_INVALID
} EN_TOS_SERVICE_TYPE;

typedef enum
{
    E_TOS_CHANNEL_ALL,                   ///< ȫ��Ƶ������
    E_TOS_CHANNEL_DIGINAL,               ///< ����Ƶ������
    E_TOS_CHANNEL_ANALOGUE,              ///< ģ��Ƶ������
    E_TOS_CHANNEL_RAIDO,                 ///< �㲥Ƶ������
    E_TOS_CHANNEL_FREE,                  ///< ģ��Ƶ��+���������ּ��㲥Ƶ��
    E_TOS_CHANNEL_FAVORITES,             ///< ģ��Ƶ��������Ƶ���е�����Ϊϲ�õ�Ƶ��
    E_TOS_CHANNEL_SINGLE_SATELLITE,      ///< ��һ����Ƶ��  �������ǽ�Ŀ
    E_TOS_CHANNEL_DATA_OTHERS,		       ///< ��������
    E_TOS_CHANNEL_NUM
} EN_TOS_CHANEL_LIST_TYPE;           ///< Ƶ���б�����

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
    uint32_t satelliteId;            ///< ����Id
    uint16_t networkId;              ///< ��Ӫ��Id
    uint16_t originalNetworkId;      ///< originalNetworkId
    uint16_t transportStreamId;      ///< transportStreamId
    uint32_t frequency;              ///< frequency KHZ
    uint32_t symbolRate;             ///< symbolRate bps
    fpi_dtv_qam_mode_t qamMod;   ///< qamMod ö��
    uint8_t bandWidth;               ///< bandWidth
    unsigned char networkName[NETWORK_NAME_SIZE];	///< ������������networkName
} tos_dtv_mux_info_t;

typedef struct
{
    EN_TOS_SERVICE_TYPE serviceType;     ///< Ƶ������
    fpi_dtv_delivery_type_t  deliveryType;    ///< �������ͣ���Ӧö��EN_FPI_DELIVERY_TYPE
    uint32_t channelId;                  ///< Ƶ��ID������Ψһ��ʶһ��Ƶ��
    uint32_t optionMask;                 ///< Ƶ��������
    uint16_t channelNumber;                    ///< Ƶ����,����ATSC��ISDB��8λ��ӦMAJOR ��8λ��ӦMIRROR CHANNEL NO��
    unsigned char channelName[CHANNEL_NAME_SIZE];       ///< Ƶ�����ƣ������ʽutf-8
    int32_t frequency;                  ///< Ƶ����ϢKHz����servictType����������ATV DTV
    uint32_t satelliteId;            ///< ����Id
    
    uint16_t audioPid;                  ///<  audioPid
    uint16_t videoPid;                  ///<  videoPid
    uint16_t muxInfoId;                 ///< Ψһȷ��Ƶ�����Ϣ
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
    /****����Ϊatv����Ƶ���������***/
    
    uint8_t colorSystem;               ///< ��ɫ��ʽ
    uint8_t soundSystem;               ///< ������ʽ
    int32_t db_primary_key;//database primary key in database
} tos_channel_info_t;


#ifdef __cplusplus
}
#endif
/** @} */
#endif
