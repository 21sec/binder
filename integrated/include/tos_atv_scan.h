
/**@defgroup ATV搜台管理
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda 初稿
*/




#ifndef __TOS_ATV_H__
#define __TOS_ATV_H__

#include "fpi_error_code.h"
#include "fpi_base_type.h"
#include "fpi_adapter.h"
#include "tos_channel_common.h"
#include "tos_dtv_scan.h"


#ifdef __cplusplus
extern "C" {
#endif



/**
@brief ATV 自动搜台开始接口函数

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_start_auto_scan(void);

 
/**
@brief 启动ATV手动搜台

@note loat frequency;用户输入频点，在自动搜台的advance时需要，如果不是advance则默认传0 ,取值范围[45,870] 单位MHZ 
         float end_frequency 用户输入频点,用户输入截止频点。暂时为0

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_start_manual_scan(int32_t start_frequency,int32_t end_frequency);

/**
@brief ATV 节目自动更新

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_start_update_scan(void);

/**
@brief 获取atv搜台的状态

@note status 返回搜台状态的指针

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_scan_get_status(EN_TOS_DTV_SCAN_STATUS *status);

/**
@brief 获取atv当前频道的频率

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_get_current_frequency( int32_t* freq );


/**
@brief ATV 微调

@note 频率UI来做计算后传下来，步频通常为50HZ

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_set_fine_tune_by_frequency(int32_t programNum, int32_t toFreqency,EN_ACT_CTRL act);

/**
@brief ATV 微调

@note 中间件自己计算频率

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_fine_tune(int32_t programNum, EN_FINE_TUNE_MODE ftMode);




	
/**
@brief 对搜台频道的控制，包括另外存储新的台、覆盖现有的台或取消保存

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_manual_scan_save(EN_ATV_SCAN_CTRL action);

/**
@brief 获取atv指定频道的声音制式

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_get_audio_standard(int32_t programNum, EN_SOUND_SYSTEM_T *aStdType);

/**
@brief 获取指定atv频道的彩色制式(一般是从数据库中读取)

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_get_video_standard(int32_t programNum, EN_COLOR_SYSTEM_T *cSysType);



/**
@brief 设置ATV伴音制式

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_set_audio_standard(int32_t programNum, EN_SOUND_SYSTEM_T aStdType,EN_ACT_CTRL act);


/**
@brief 设置ATV 节目彩色制式

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_atv_set_video_standard(int32_t programNum, EN_COLOR_SYSTEM_T vStdType,EN_ACT_CTRL act);

   /**
 @brief 获取搜台过程中的进度信息
 
 @note 
 
 @note 
 
 @return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
 */ 
 fpi_error tos_atv_get_current_scaned_program_info(st_api_scanning_info_t *scanning_info);


   /**
 @brief 获取指定的atv频道是否能进行aft频率自动校正
 
 @note 
 
 @note 
 
 @return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
 */ 
 fpi_error tos_atv_get_aft_enable(int32_t programNum,fpi_bool *enable);
#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_CHANNEL_H__
