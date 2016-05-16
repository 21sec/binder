
/**
@defgroup �źŴ���
@

@brief 

@author 

@note 

@version 1.0.0 2015/1/14 linshunda ����
*/



#ifndef __TOS_SIGNAL_H__
#define __TOS_SIGNAL_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"



#ifdef __cplusplus
extern "C" {
#endif

/**
@brief �ź�״̬
**/
typedef enum
{
    E_TCL_NULL, //can't get the sinal status
    E_TCL_NO_SIGNAL, // there isn't signal  //unlock
    E_TCL_STABLE,// there's signal and signal stable //lock
    E_TCL_UNSTABLE,//there's signal but signal is not stable
    E_TCL_UNSUPPORTED, // this signal is not support format
    E_TCL_MAX,
} EN_FPI_SIGNAL_STATUS_TYPE;

typedef struct
{
	uint16_t quality;     ///< �ź�����
	uint16_t strength;    ///< �ź�ǿ��
	uint8_t sigBer;       ///< �ź�Bar
}st_fpi_signal_info_t;

/**
@brief signal timing����Ϣ
**/
typedef struct
{
    // Video Horizontal direction size
    int hResolution;
    // Videro vertical direction size
    int vResolution;
    //The video image refresh speed per second
    int frameRate;//ˢ��Ƶ��
    //Video signal scan type progressive or interlaced
    fpi_bool bInterlaced;
    fpi_bool isHD;//is high display
    fpi_bool isDvi;/* 0 - means hdmi, 1 - means dvi, this flag is valid in hdmi linein */  	
	fpi_bool isXVYCC;
}st_fpi_signal_timing_t;

typedef enum
{
	EN_FPI_SIGNAL_INCLUDE_XVYCC ,/**�������ֵʱ��info����bool��ָ�������true��ʾ�������źţ�false��ʾ������*/
	EN_FPI_SIGNAL_GET_DYNAMIC_RANGE,/**<��ȡ�źŶ�̬ɫ�򣬵������ö��ʱ��info����EN_FPP_SIGNAL_DYNAMIC_RANGE_TYPE_T��ö�ٶ���*/
	EN_FPI_SIGNAL_GET_FRAME_RATE,/**<��ȡ��ǰ�ź�ȥ���ź����ظ�֡���ˢ��Ƶ�ʣ��������ö��ʱ��info ����ˢ��Ƶ��ֵ����λHZ*/
	EN_FPI_SIGNAL_INCLUDE_MAX
}EN_FPI_SIGNAL_INFO_TYPE;

/**
@brief ��õ�ǰ��������Դ���ź�״̬

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS,ʧ�ܷ�������ֵ
*/
fpi_error tos_signal_get_state(EN_FPI_SIGNAL_STATUS_TYPE *state);




/**
@brief ���ص�ǰ�źŵ�����ǿ����Ϣ
@param[out] signaInfo  ���ص�ǰ�źŵ�����ǿ�ȵ�ָ��
@return �ɹ�����FPI_ERROR_SUCCESS,ʧ�ܷ�������ֵ
*/
fpi_error tos_signal_get_current_info(st_fpi_signal_info_t *signaInfo);
 





/**
@brief ��õ�ǰ��������Դ��timing��Ϣ

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS,ʧ�ܷ�������ֵ
*/
fpi_error tos_signal_get_timing_info(st_fpi_signal_timing_t *value);

/**
@brief ���ص�ǰ�źŵ���ر�־��״̬
@param[out] param  ���ص�ǰ�źŵ���ر�־��״̬  [in]��ر�־������type
@return �ɹ�����FPI_ERROR_SUCCESS,ʧ�ܷ�������ֵ
*/

fpi_error tos_signal_get_extra_info(EN_FPI_SIGNAL_INFO_TYPE type,void* param);


#ifdef __cplusplus
}
#endif
/**  */

#endif





