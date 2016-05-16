
/**
@defgroup 信号处理
@

@brief 

@author 

@note 

@version 1.0.0 2015/1/14 linshunda 初稿
*/



#ifndef __TOS_SIGNAL_H__
#define __TOS_SIGNAL_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"



#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 信号状态
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
	uint16_t quality;     ///< 信号质量
	uint16_t strength;    ///< 信号强度
	uint8_t sigBer;       ///< 信号Bar
}st_fpi_signal_info_t;

/**
@brief signal timing的信息
**/
typedef struct
{
    // Video Horizontal direction size
    int hResolution;
    // Videro vertical direction size
    int vResolution;
    //The video image refresh speed per second
    int frameRate;//刷新频率
    //Video signal scan type progressive or interlaced
    fpi_bool bInterlaced;
    fpi_bool isHD;//is high display
    fpi_bool isDvi;/* 0 - means hdmi, 1 - means dvi, this flag is valid in hdmi linein */  	
	fpi_bool isXVYCC;
}st_fpi_signal_timing_t;

typedef enum
{
	EN_FPI_SIGNAL_INCLUDE_XVYCC ,/**当出入此值时，info传入bool型指针变量，true表示包含此信号，false表示不包含*/
	EN_FPI_SIGNAL_GET_DYNAMIC_RANGE,/**<获取信号动态色域，当输出该枚举时，info返回EN_FPP_SIGNAL_DYNAMIC_RANGE_TYPE_T的枚举定义*/
	EN_FPI_SIGNAL_GET_FRAME_RATE,/**<获取当前信号去掉信号中重复帧后的刷新频率，当出入改枚举时，info 返回刷新频率值，单位HZ*/
	EN_FPI_SIGNAL_INCLUDE_MAX
}EN_FPI_SIGNAL_INFO_TYPE;

/**
@brief 获得当前的输入信源的信号状态

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS,失败返回其他值
*/
fpi_error tos_signal_get_state(EN_FPI_SIGNAL_STATUS_TYPE *state);




/**
@brief 返回当前信号的质量强度信息
@param[out] signaInfo  返回当前信号的质量强度的指针
@return 成功返回FPI_ERROR_SUCCESS,失败返回其他值
*/
fpi_error tos_signal_get_current_info(st_fpi_signal_info_t *signaInfo);
 





/**
@brief 获得当前的输入信源的timing信息

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS,失败返回其他值
*/
fpi_error tos_signal_get_timing_info(st_fpi_signal_timing_t *value);

/**
@brief 返回当前信号的相关标志的状态
@param[out] param  返回当前信号的相关标志的状态  [in]相关标志的名称type
@return 成功返回FPI_ERROR_SUCCESS,失败返回其他值
*/

fpi_error tos_signal_get_extra_info(EN_FPI_SIGNAL_INFO_TYPE type,void* param);


#ifdef __cplusplus
}
#endif
/**  */

#endif





