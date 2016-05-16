/**@defgroup ���ֵ�������ģ��
@{

@brief ���ڿ��Ƶ���������ģ����صĲ���
**/

#ifndef __TOS_SATELLITE_H__
#define __TOS_SATELLITE_H__

#include "fpi_error_code.h"
#include "fpi_dtv_base.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint32_t satellite_id;
    char satellite_name[FPI_SATELLITE_INFO_MAX_NAME_LEN];
}tos_satellite_id_info_t;      ///< satellite info

typedef struct
{  
    uint32_t operator_id;                    ///< current item's operator id
    uint16_t network_id;                     ///< operator network id
    char operator_name[MAX_OPERATOR_NAME];   ///< string
}tos_operator_info_t;

typedef struct
{
    int32_t satellite_id;
    char satellite_name[FPI_SATELLITE_INFO_MAX_NAME_LEN];
    fpi_bool selected;
    fpi_satellite_position_t position;
    fpi_bool lnb_power;
    fpi_satellite_lnb_type_t lnb_freq;
    fpi_satellite_diseqc_version_t diseqc_version;
    fpi_satellite_diseqc_com_t diseqc_com;
    fpi_satellite_22k_switch_t tone_mode;
    fpi_satellite_tone_burst_t tone_burst;
    int32_t scan_frequency;
    int32_t symbol_rate;
    fpi_satellite_polairze_type_t polarization;
}tos_satellite_info_t;


/**
@brief ����tuner��ȡ��Ӫ�̵ĸ���
@param[out] ��ȡ��Ӫ�̸���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_operator_count(int32_t *operatorCount);


/**
@brief ����tuner��ȡ��Ӫ�̵��б�
@param[in] operatorCount ��Ӫ���б���
@param[out] operatorListBuff, ��ȡ��Ӫ���б�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_operator_list(int32_t operatorCount, tos_operator_info_t *operatorListBuff);


/**
@brief ������Ӫ��ID��ȡ���Ǹ���
@param[in]  operatorIndex  ��Ӫ��ID
@param[out] satellCount, ��Ӫ�̵����Ǹ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_satellite_count_by_operator(int32_t operatorIndex, int32_t *satellCount);


/**
@brief ������Ӫ��ID��ȡ�����б�
@param[in] operatorIndex, ��Ӫ��ID
@param[in] satellCount, ��Ӫ�̵����Ǹ���
@param[out] satelliteList, ��Ӫ�̵������б�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_satellite_list_by_operator(int32_t operatorIndex, int32_t satellCount, tos_satellite_info_t *satelliteList);

/**
@brief ���ݴ��������ID���ø����ǵ�polarization����
@param[in] satelliteID, ��Ҫ�������Ե�����ID
@param[in] satelliteInfo, ������Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_set_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo);

/**
@brief ���ݴ��������ID������Ƶ��
@param[in] satelliteID, ��ҪlockƵ�ʵ�����ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_lock_freqency(int32_t satelliteID);


/**
@brief ��ȡ����antenna ��Ϣ
@param[out] st_tos_satellite_antenna_info, ��ȡ��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_antenna_info(fpi_satellite_antenna_info_t *info);


/**
@brief ��������antenna ��Ϣ
@param[in] info, st_tos_satellite_antenna_info, antenna ��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_set_antenna_info(fpi_satellite_antenna_info_t *info);


/**
@brief ��ȡ����band freq count,ֻ����sigle cable��ʹ��
@param[out] count,��ȡcountָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_band_freq_count(uint32_t band_index,uint32_t *count);


/**
@brief ��ȡ����band freq list��ֻ����sigle cable��ʹ��
@param[in] band_index,count,freq band count
@param[out] frequencyList,��ȡ�б��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_band_freq_list(uint32_t band_index,uint32_t count, uint32_t *freq_list);


/**
@brief ��������band freq��ֻ����sigle cable��ʹ��
@param[in] index, freq��frequencyList��index
@param[in] frequency,��Ҫ���õ�frequency(MHZ)
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_set_band_freq(uint32_t band_index,uint32_t band__freq_index, uint32_t freq);


/**
@brief ��ȡ���Ǹ��� (���ǽ�Ŀ�б�����Ҫ�����ѵ�̨�����Ǹ���)
@param[out]  count ��ȡ�ѵ���Ŀ�����Ǹ�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_searched_satellite_count(int32_t *count);


/**
@brief ��ȡ����id ��id��Ӧ����list(���ǽ�Ŀ�б�����Ҫ�����ѵ�̨������)
@param[in] satelliteCount ��Ҫ��ȡ����id list count,tos_satellite_get_satellite_count��ȡ
@param[out] satelliteIdInfolist ��ȡ���� id info list��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_satellite_id_info_list(int32_t satelliteCount, tos_satellite_id_info_t *satelliteIdInfolist);


/**
@brief �����û�ѡ��ĳ�����ǵ�ID
@param[in] satelliteId �û�ѡ��ĳ�����ǵ�ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_set_user_select_satellite_id(uint32_t satelliteId);


/**
@brief ��ȡ�û�ѡ��ĳ�����ǵ�ID
@param[out] satelliteId �û�ѡ��ĳ�����ǵ�ID
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_user_select_satellite_id(uint32_t *satelliteId);




/**
@brief ���ݴ��������ID���ø����ǵ�polarization����
@param[in] satelliteID, ��Ҫ�������Ե�����ID
@param[in] satelliteInfo, ������Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_satellite_get_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
