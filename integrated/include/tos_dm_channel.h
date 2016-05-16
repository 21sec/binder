/**@defgroup Ƶ��������ݵĹ���
��Ҫ��Ƶ�����ݿ���صĲ���

@{
@brief ���ڿ��Ƶ����в�����صĲ�������ȡƵ����Ϣ��ز���

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

#define TOS_CHANNEL_ATTRIBUTE_FAVOR      (0x01<<0)   ///< �ɶ�д��ϲ��Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_FAVOR)>>0
#define TOS_CHANNEL_ATTRIBUTE_LOCK       (0x01<<1)   ///< �ɶ�д��(optionMask&&TOS_CHANNEL_ATTRIBUTE_LOCK)>>1
#define TOS_CHANNEL_ATTRIBUTE_SKIP       (0x01<<2)   ///< �ɶ�д������Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_SKIP)>>2
#define TOS_CHANNEL_ATTRIBUTE_DELETE     (0x01<<3)   ///< �ɶ�д��ɾ��Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_MASK)>>3
#define TOS_CHANNEL_ATTRIBUTE_HIDE       (0x01<<4)   ///< �ɶ�д������Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_HIDE)>>4
#define TOS_CHANNEL_ATTRIBUTE_SCRAMBLED (0x01<<5)   //�ɶ�д������Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_SCRAMBLED)>>5
#define TOS_CHANNEL_ATTRIBUTE_HD         (0x01<<6)   ///< ֻ��������Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_HD)>>6
#define TOS_CHANNEL_ATTRIBUTE_FREE       (0x01<<7)   ///< ֻ��������Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_FREE)>>7
#define TOS_CHANNEL_ATTRIBUTE_CI_OP      (0x01<<8)   ///< ֻ����CI_OP������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_CI_OP)>>8
#define TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG (0x01<<9) ///< ֻ����Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG)>>9
#define TOS_CHANNEL_ATTRIBUTE_NOT_NUMERICAL (0x01<<10)  ///< ֻ����numerical Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_UNLOCK_FLAG)>>10, ָ����λ��ʾ����is_numericΪfalse�Ľ�Ŀ

#define TOS_CHANNEL_DELIVERYTYPE_OFFSET_BIT     12
#define TOS_CHANNEL_SERVICETYPE_OFFSET_BIT     16
#define TOS_CHANNEL_SELECT_SAT_OFFSET_BIT       21

#define TOS_CHANNEL_ATTRIBUTE_MASK     		(0xFFF) 
#define TOS_CHANNEL_DILIVERYTYPE_MASK     (0x0F<<TOS_CHANNEL_DELIVERYTYPE_OFFSET_BIT) ///< ��mask��ʮ��λ��ʮ��λȡ������ʾdiliverytype,��ͬ��EN_FPI_TUNER_MODE
#define TOS_CHANNEL_SERVICETYPE_MASK    	(0x1F<<TOS_CHANNEL_SERVICETYPE_OFFSET_BIT)///< ��mask��ʮ��λ��ʮ��λȡ������ʾservicetype
#define TOS_CHANNEL_SELECT_SATELLITE_MASK (0x01<<TOS_CHANNEL_SELECT_SAT_OFFSET_BIT) ///< ��mask�ڶ�ʮλȡ������ʾѡ��ĳ������

typedef struct
{
    uint16_t networkId;                    ///< ��Ӫ��ID
    unsigned char  operatorName[NETWORK_NAME_SIZE]; ///< ��Ӫ�����ƣ������ļ���������
} tos_channel_operator_info_t;


/**
@brief ����Ƶ���Ż�ȡ��Ӧ��Ƶ������ID
����Ӧ��ͨ��serviceType��number�ҵ���Ӧ������ID
@param[in] serviceType  ָ����Ƶ������,Invalid��ʾ��������
@param[in] channelNumber  ָ����Ƶ����
@param[out] channelId   ��ȡָ��Ƶ���Ŷ�Ӧ��Ƶ��IDָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channelId_by_number(EN_TOS_SERVICE_TYPE serviceType, uint16_t channelNumber,uint32_t* channelId);
/**
@brief ����SERVICE TYPE��ȡ��Ӧ��Ƶ������ID
����Ӧ��ͨ��serviceType�ҵ���Ӧ������ID
@param[in] service_type_mask  ָ����Ƶ�����ͼ���(����ATV+DTV ��service_type_mask=(1<<E_TOS_SERVICE_TYPE_ATV) | (1<<E_TOS_SERVICE_TYPE_DTV)
@param[in] channelId  ����ָ����Ƶ��ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_current_channelId_by_servicetype(uint32_t service_type_mask,uint32_t *channelId);
/**
@brief ����Ƶ��������ȡƵ����Ϣ
@param[in] channelIndex  ָ����Ƶ��������Ψһ��ʶID
@param[out] channelInfo  ���ض�Ӧ��Ƶ����Ϣָ�룬�������������Ч��Ƶ���б��ڣ��򷵻ؿ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channel_info_by_id(uint32_t channelId, tos_channel_info_t* channelInfo);


/**
@brief ����Ƶ��mask��ȡ��Ӧ��Ƶ���б�
@param[in] mask Ƶ����mask�������������ݸ�����mask��ȡƵ���б�����ͣ�����ϲ�á�diliverty��servictType��ѡ�е����ǵ�
#define TOS_CHANNEL_ATTRIBUTE_FAVOR      (0x01<<0)   ///< ϲ��Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_FAVOR)>>0
#define TOS_CHANNEL_ATTRIBUTE_LOCK       (0x01<<1)   ///< ����Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_LOCK)>>1
#define TOS_CHANNEL_ATTRIBUTE_SKIP       (0x01<<2)   ///< ����Ƶ��������ƫ�ƣ�ΪTRUE����Ҫ��������Ƶ����Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_SKIP)>>2
#define TOS_CHANNEL_ATTRIBUTE_DELETE     (0x01<<3)   ///< ɾ��Ƶ��������ƫ�ƣ�ΪTRUE����Ҫ����ɾ��Ƶ����Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_MASK)>>3
#define TOS_CHANNEL_ATTRIBUTE_HIDE       (0x01<<4)   ///< ����Ƶ��������ƫ�ƣ�ΪTRUE����Ҫ��������Ƶ����Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_HIDE)>>4
#define TOS_CHANNEL_ATTRIBUTE_SCRAMBLED  (0x01<<5)   ///< ����Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_SCRAMBLED)>>5
#define TOS_CHANNEL_ATTRIBUTE_HD         (0x01<<6)   ///< ����Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_HD)>>6
#define TOS_CHANNEL_ATTRIBUTE_FREE       (0x01<<7)   ///< ����Ƶ��������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_FREE)>>7
#define TOS_CHANNEL_ATTRIBUTE_CI_OP      (0x01<<8)   ///< CI_OP������ƫ�ƣ�Ƶ����Ϣ��optionMask��ȡ��(optionMask&&TOS_CHANNEL_ATTRIBUTE_CI_OP)>>8

#define TOS_CHANNEL_ATTRIBUTE_MASK     		(0xFFF) 
#define TOS_CHANNEL_DILIVERYTYPE_MASK     (0x0F<<12) ///< ��mask��ʮ��λ��ʮ��λȡ������ʾdiliverytype����Ӧö������˳��bitΪ1��ʾѡ��0��ʾδѡ��
#define TOS_CHANNEL_SERVICETYPE_MASK    	(0x0F<<16)///< ��mask��ʮ��λ��ʮ��λȡ������ʾservicetype,��Ӧö������
#define TOS_CHANNEL_SELECT_SATELLITE_MASK (0x0F<<20) ///< ��mask�ڶ�ʮλȡ������ʾѡ��ĳ������

@param[out] list  ��ȡ��Ƶ���б�ָ��
@param[in/out] count  in������Ƶ���б�Ŀռ��С�����Գ���ϴ��ֵ512,���߻�ȡ�ĸ���
                      out:��ȡ��Ƶ���б��ʵ�ʳ��ȶ�Ӧ��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channellist_by_mask(uint32_t mask, tos_channel_info_t *list,uint32_t *count);

/**
@brief  mask Ƶ����mask�������������ݸ�����mask��ȡƵ���б�����ͣ�����ϲ�á�diliverty��servictType��ѡ�е����ǵ�
@param[in] mask ���õ�Ƶ���б�����
@param[out] count  ���ص�Ƶ������ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channel_count_by_mask(uint32_t mask,uint32_t *count);

/**
@brief ��Ŀ�ı༭����
ֻ���л������
���༭һ��Ƶ��ʱ��ֱ�ӵ��ã����ƶ��򽻻���������Ҫ�༭���Ƶ��ʱ�����ж�ε���
@param[in] info  ��Ҫ�༭��Ƶ����Ϣָ�룬�����༭Ƶ���� Ƶ������ Ƶ�����Ե�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_set_channel_info(tos_channel_info_t *info);

/**
@brief ��ȡ��Ŀ�б�İ汾��
����ʱ�汾��δ0����Ƶ�����ݿⷢ���仯����Ƶ���༭���汾�Żᷢ���仯
����ʹ�ó�����ipepg�����汾�Ÿ��������������ݿ�仯ʱ�汾�ű仯��ipepg֪ͨ�����������
@param[out] chListVersion  ��ȡ��Ŀ�б�İ汾��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_channel_list_version(uint32_t *chListVersion);

/**
@brief ��ȡ��Ӫ���б�
@param[out] networkList  ��Ӫ����Ϣ�б�ָ��
@param[in/out] count  in��������Ӫ�̵ĸ�����ͨ��tos_channel_dtv_get_operator_count��ȡ
                      out:������Ӫ��ʵ�ʸ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_operator_list(tos_channel_operator_info_t* networkList, uint32_t *count);

/**
@brief ��ȡ��Ӫ�̸���
@param[count] count  ��Ӫ�̸���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_operator_count(uint32_t *count);

/**
����
@brief ���õ�ǰ��Ӫ����Ϣ
�����û�ѡ�����Ӫ���Ժ���̨���Ŀ���º󣬸���ϲ����Ӫ�̽���һЩ����������������
@param[in] networkId  ������Ӫ����Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_set_fav_networkId(uint16_t networkId);

/**
����
@brief ��ȡ��ǰ��Ӫ����Ϣ
�����û�ѡ�����Ӫ���Ժ���̨���Ŀ���º󣬸���ϲ����Ӫ�̽���һЩ����������������
@param[out] networkId  ��Ӫ��Idָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_fav_networkId(uint16_t *networkId);
/*
@brief �������һ�ν�Ŀ������
@param[in]	��
@param[out]EN_TOS_SERVICE_TYPE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_last_service_type(EN_TOS_SERVICE_TYPE *type);


/**
@brief ����muxId��ȡdemux����Ϣ
@param[in] muxId  ָ����muxId
@param[out] muxInfo  ����ָ��muxId��Ӧ����Ϣ�����������Ч��muxId���򷵻ؿ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_muxInfo(int32_t muxId, tos_dtv_mux_info_t *muxInfo);


/**
@brief ���Ƶ���б�
ֻ���л������
@param[in] deliverytype  ��ӦEN_FPI_DEVILITY_TYPEö��,E_DEVILITY_TYPE_INVALID��ʾȫ��ɾ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_clean_channel_list(fpi_dtv_delivery_type_t deliverytype);

/**
@brief ���ݿ���²���
��Ƶ�����ݱ༭��ɾ����ֻ���л�������������ñ��ӿ�ʱ�������汣�����ݿ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_db_update();

/**
����
@brief ��ȡ�뵱ǰ��Ŀ��ͬLCN�Ľ�Ŀ��
@param[out] pstChannelNumber  �����뵱ǰ��Ŀ��ͬLCN�Ľ�Ŀ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_get_program_number_by_same_lcn(uint16_t *pstChannelNumber);

/*
@brief ��Դ��Ŀ�ƶ���Ŀ���Ŀ��λ��
@param[in]	srcChIndex Դ��Ŀ������λ�ã�dstChIndex Ŀ���Ŀ������λ��
@param[out]	��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_move_program_by_index(uint32_t srcChIndex, uint32_t dstChIndex);

/*
@brief ��Դ��Ŀ���뵽Ŀ���Ŀ��λ��
@param[in]	srcChIndex Դ��Ŀ������λ�ã�dstChIndex Ŀ���Ŀ������λ��
@param[out]	��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
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
*Description;����rf_number��ȡ��֮ƥ��ĵ�һ��channel index
*Input: uint8_t u8_rf_number,Ƶ����Ϣ�е�rf_number
       uint16_t* channel_index����ȡchannel num��Ӧ��channel index
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
