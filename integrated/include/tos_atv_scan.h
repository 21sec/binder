
/**@defgroup ATV��̨����
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda ����
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
@brief ATV �Զ���̨��ʼ�ӿں���

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_start_auto_scan(void);

 
/**
@brief ����ATV�ֶ���̨

@note loat frequency;�û�����Ƶ�㣬���Զ���̨��advanceʱ��Ҫ���������advance��Ĭ�ϴ�0 ,ȡֵ��Χ[45,870] ��λMHZ 
         float end_frequency �û�����Ƶ��,�û������ֹƵ�㡣��ʱΪ0

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_start_manual_scan(int32_t start_frequency,int32_t end_frequency);

/**
@brief ATV ��Ŀ�Զ�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_start_update_scan(void);

/**
@brief ��ȡatv��̨��״̬

@note status ������̨״̬��ָ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_scan_get_status(EN_TOS_DTV_SCAN_STATUS *status);

/**
@brief ��ȡatv��ǰƵ����Ƶ��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_get_current_frequency( int32_t* freq );


/**
@brief ATV ΢��

@note Ƶ��UI�����������������Ƶͨ��Ϊ50HZ

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_set_fine_tune_by_frequency(int32_t programNum, int32_t toFreqency,EN_ACT_CTRL act);

/**
@brief ATV ΢��

@note �м���Լ�����Ƶ��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_fine_tune(int32_t programNum, EN_FINE_TUNE_MODE ftMode);




	
/**
@brief ����̨Ƶ���Ŀ��ƣ���������洢�µ�̨���������е�̨��ȡ������

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_manual_scan_save(EN_ATV_SCAN_CTRL action);

/**
@brief ��ȡatvָ��Ƶ����������ʽ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_get_audio_standard(int32_t programNum, EN_SOUND_SYSTEM_T *aStdType);

/**
@brief ��ȡָ��atvƵ���Ĳ�ɫ��ʽ(һ���Ǵ����ݿ��ж�ȡ)

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_get_video_standard(int32_t programNum, EN_COLOR_SYSTEM_T *cSysType);



/**
@brief ����ATV������ʽ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_set_audio_standard(int32_t programNum, EN_SOUND_SYSTEM_T aStdType,EN_ACT_CTRL act);


/**
@brief ����ATV ��Ŀ��ɫ��ʽ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_atv_set_video_standard(int32_t programNum, EN_COLOR_SYSTEM_T vStdType,EN_ACT_CTRL act);

   /**
 @brief ��ȡ��̨�����еĽ�����Ϣ
 
 @note 
 
 @note 
 
 @return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
 */ 
 fpi_error tos_atv_get_current_scaned_program_info(st_api_scanning_info_t *scanning_info);


   /**
 @brief ��ȡָ����atvƵ���Ƿ��ܽ���aftƵ���Զ�У��
 
 @note 
 
 @note 
 
 @return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
 */ 
 fpi_error tos_atv_get_aft_enable(int32_t programNum,fpi_bool *enable);
#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_CHANNEL_H__
