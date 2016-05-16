/**@defgroup 数字电视卫星模块
@{

@brief 用于控制电视中卫星模块相关的操作
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
@brief 根据tuner获取运营商的个数
@param[out] 获取运营商个数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_operator_count(int32_t *operatorCount);


/**
@brief 根据tuner获取运营商的列表
@param[in] operatorCount 运营商列表长度
@param[out] operatorListBuff, 获取运营商列表指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_operator_list(int32_t operatorCount, tos_operator_info_t *operatorListBuff);


/**
@brief 根据运营商ID获取卫星个数
@param[in]  operatorIndex  运营商ID
@param[out] satellCount, 运营商的卫星个数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_satellite_count_by_operator(int32_t operatorIndex, int32_t *satellCount);


/**
@brief 根据运营商ID获取卫星列表
@param[in] operatorIndex, 运营商ID
@param[in] satellCount, 运营商的卫星个数
@param[out] satelliteList, 运营商的卫星列表指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_satellite_list_by_operator(int32_t operatorIndex, int32_t satellCount, tos_satellite_info_t *satelliteList);

/**
@brief 根据传入的卫星ID设置该卫星的polarization属性
@param[in] satelliteID, 需要设置属性的卫星ID
@param[in] satelliteInfo, 卫星信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_set_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo);

/**
@brief 根据传入的卫星ID锁定主频率
@param[in] satelliteID, 需要lock频率的卫星ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_lock_freqency(int32_t satelliteID);


/**
@brief 获取卫星antenna 信息
@param[out] st_tos_satellite_antenna_info, 获取信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_antenna_info(fpi_satellite_antenna_info_t *info);


/**
@brief 设置卫星antenna 信息
@param[in] info, st_tos_satellite_antenna_info, antenna 信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_set_antenna_info(fpi_satellite_antenna_info_t *info);


/**
@brief 获取卫星band freq count,只有在sigle cable下使用
@param[out] count,获取count指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_band_freq_count(uint32_t band_index,uint32_t *count);


/**
@brief 获取卫星band freq list，只有在sigle cable下使用
@param[in] band_index,count,freq band count
@param[out] frequencyList,获取列表的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_band_freq_list(uint32_t band_index,uint32_t count, uint32_t *freq_list);


/**
@brief 设置卫星band freq，只有在sigle cable下使用
@param[in] index, freq在frequencyList的index
@param[in] frequency,需要设置的frequency(MHZ)
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_set_band_freq(uint32_t band_index,uint32_t band__freq_index, uint32_t freq);


/**
@brief 获取卫星个数 (卫星节目列表中需要的有搜到台的卫星个数)
@param[out]  count 获取搜到节目的卫星个数的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_searched_satellite_count(int32_t *count);


/**
@brief 获取卫星id 及id对应名称list(卫星节目列表中需要的有搜到台的卫星)
@param[in] satelliteCount 需要获取卫星id list count,tos_satellite_get_satellite_count获取
@param[out] satelliteIdInfolist 获取卫星 id info list的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_satellite_id_info_list(int32_t satelliteCount, tos_satellite_id_info_t *satelliteIdInfolist);


/**
@brief 设置用户选择某个卫星的ID
@param[in] satelliteId 用户选择某个卫星的ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_set_user_select_satellite_id(uint32_t satelliteId);


/**
@brief 获取用户选择某个卫星的ID
@param[out] satelliteId 用户选择某个卫星的ID
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_user_select_satellite_id(uint32_t *satelliteId);




/**
@brief 根据传入的卫星ID设置该卫星的polarization属性
@param[in] satelliteID, 需要设置属性的卫星ID
@param[in] satelliteInfo, 卫星信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_satellite_get_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
