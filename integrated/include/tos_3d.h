/**@defgroup 视频3D模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
*/



#ifndef __TOS_3D_H__
#define __TOS_3D_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 3Dd的模式
**/
typedef enum
{
    EN_3D_DISPLAY_NONE,  // 3D OFF
    EN_3D_DISPLAY_2D_TO_3D,
    EN_3D_DISPLAY_ALTERNATIVE,
    EN_3D_DISPLAY_CHECK_BOARD,
    EN_3D_DISPLAY_SENSIO,
    EN_3D_DISPLAY_AUTO,
    EN_3D_DISPLAY_LINE_ALTERNATIVE,
    EN_3D_DISPLAY_PIXEL_ALTERNATIVE,
    EN_3D_DISPLAY_SIDE_BY_SIDE,
    EN_3D_DISPLAY_TOP_BOTTOM,
    EN_3D_DISPLAY_FRAME_PACKING,
    EN_3D_DISPLAY_FRAME_SEQUENCE,
    EN_3D_DISPLAY_MAX,
} EN_FPI_3D_VIDEO_DIAPLAY_FORMAT;

/**
@brief 3D屏的类G�
**/
typedef enum
{
    EN_TOS_3D_PANEL_OFF,
    EN_TOS_3D_PANEL_SG,
    EN_TOS_3D_PANEL_PR,
    EN_TOS_3D_PANEL_MAX
} EN_TOS_PANEL_3D_TYPE;

typedef enum
{
    EN_TOS_3D_PIC_SIZE_16_9,
    EN_TOS_3D_PIC_SIZE_4_3,
    EN_TOS_3D_PIC_SIZE_AUTO,
    EN_TOS_3D_PIC_SIZE_MAX
} EN_TOS_3D_PICTURE_SIZE;

typedef enum
{
    EN_TOS_3D_PIC_MODE_STANDARD,
    EN_TOS_3D_PIC_MODE_USER,
    EN_TOS_3D_PIC_MODE_MAX
} EN_TOS_3D_PICTURE_MODE;

typedef enum
{
    EN_TOS_3D_NAVIGATION_MANAUL,
    EN_TOS_3D_NAVIGATION_AUTO,
    EN_TOS_3D_NAVIGATION_SEMI_AUTO,
    EN_TOS_3D_NAVIGATION_AUTO_3D_TO_2D,
    EN_TOS_3D_NAVIGATION_MAX
} EN_TOS_3D_NAVIGATION;

typedef enum
{
    EN_TOS_3D_COLOR_TEMP_COOL,
    EN_TOS_3D_COLOR_TEMP_STANDARD,
    EN_TOS_3D_COLOR_TEMPE_WARM,
    EN_TOS_3D_COLOR_TEMP_NUM
} EN_TOS_3D_COLOR_TEMPERATURE;

/** 
@brief 获取3D的景深

@param [out] depth 景深值，范围一般为0-30

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_get_depth_of_field(int16_t *depth);

/** 
@brief 设置3D的景深

@param [in] depth 景深值，范围一般为0-30

@param [in] EN_ACT_CTRL 函蔵执GG的类G�(只执GG，只保存，执GG后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_set_depth_of_field(int16_t depth,EN_ACT_CTRL act);

/** 
@brief 获得3D视频转换为2D的模式

@param [out] mode 取值范围见EN_FPI_3D_VIDEO_DIAPLAY_FORMAT 枚举

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_get_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *mode);

/** 
@brief 设置3D视频转换为2D的模式

@param [in] mode 取值范围见EN_FPI_3D_VIDEO_DIAPLAY_FORMAT 枚举

@param [in] EN_ACT_CTRL 函蔵执GG的类G�(只执GG，只保存，执GG后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_set_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode,EN_ACT_CTRL act);

/** 
@brief 获得当前的3D显示格式

@param [out] mode 取值范围见EN_FPI_3D_VIDEO_DIAPLAY_FORMAT 枚举

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_get_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *format);

/** 
@brief 设置当前的3D显示格式

@param [in] mode 取值范围见EN_FPI_3D_VIDEO_DIAPLAY_FORMAT 枚举

@param [in] EN_ACT_CTRL 函蔵执GG的类G�(只执GG，只保存，执GG后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_set_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT displayFormat,EN_ACT_CTRL act);

/** 
@brief 获取3D左右格式的荊换的状态

@param [out] lrswitch 0为L/R,1为R/L，具体还得看model.ini的lr配置

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_get_left_right_switch(int16_t *lrswitch);

/** 
@brief 设置3D视频的左右格式荊换

@param [in] lrswitch 0为L/R,1为R/L，具体还得看model.ini的lr配置

@param [in] EN_ACT_CTRL 函蔵执GG的类G�(只执GG，只保存，执GG后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/

fpi_error tos_3d_set_left_right_switch(int16_t lrswitch,EN_ACT_CTRL act);

/** 
@brief 获取当前播放视频stream是否为frame packing

@param [out] 0为false，1为true

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_is_framepacking_mode(int16_t *mode);

/** 
@brief 设置3D navigation模式

@param [in] mode 取值范围请看EN_3D_NAVIGATION枚举描述

@param [in] EN_ACT_CTRL 函蔵执GG的类G�(只执GG，只保存，执GG后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_set_navigation(int16_t mode,EN_ACT_CTRL act);

/** 
@brief 获取3D navigation模式

@param [out] mode 取值范围请看EN_3D_NAVIGATION枚举描述

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_3d_get_navigation(int16_t *mode);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
