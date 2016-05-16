/**@defgroup ��Ƶ3Dģ��
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/



#ifndef __TOS_3D_H__
#define __TOS_3D_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 3Dd��ģʽ
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
@brief 3D������G�
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
@brief ��ȡ3D�ľ���

@param [out] depth ����ֵ����Χһ��Ϊ0-30

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_get_depth_of_field(int16_t *depth);

/** 
@brief ����3D�ľ���

@param [in] depth ����ֵ����Χһ��Ϊ0-30

@param [in] EN_ACT_CTRL ���iִGG����G�(ִֻGG��ֻ���棬ִGG�󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_set_depth_of_field(int16_t depth,EN_ACT_CTRL act);

/** 
@brief ���3D��Ƶת��Ϊ2D��ģʽ

@param [out] mode ȡֵ��Χ��EN_FPI_3D_VIDEO_DIAPLAY_FORMAT ö��

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_get_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *mode);

/** 
@brief ����3D��Ƶת��Ϊ2D��ģʽ

@param [in] mode ȡֵ��Χ��EN_FPI_3D_VIDEO_DIAPLAY_FORMAT ö��

@param [in] EN_ACT_CTRL ���iִGG����G�(ִֻGG��ֻ���棬ִGG�󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_set_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode,EN_ACT_CTRL act);

/** 
@brief ��õ�ǰ��3D��ʾ��ʽ

@param [out] mode ȡֵ��Χ��EN_FPI_3D_VIDEO_DIAPLAY_FORMAT ö��

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_get_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *format);

/** 
@brief ���õ�ǰ��3D��ʾ��ʽ

@param [in] mode ȡֵ��Χ��EN_FPI_3D_VIDEO_DIAPLAY_FORMAT ö��

@param [in] EN_ACT_CTRL ���iִGG����G�(ִֻGG��ֻ���棬ִGG�󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_set_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT displayFormat,EN_ACT_CTRL act);

/** 
@brief ��ȡ3D���Ҹ�ʽ���G����״̬

@param [out] lrswitch 0ΪL/R,1ΪR/L�����廹�ÿ�model.ini��lr����

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_get_left_right_switch(int16_t *lrswitch);

/** 
@brief ����3D��Ƶ�����Ҹ�ʽ�G��

@param [in] lrswitch 0ΪL/R,1ΪR/L�����廹�ÿ�model.ini��lr����

@param [in] EN_ACT_CTRL ���iִGG����G�(ִֻGG��ֻ���棬ִGG�󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/

fpi_error tos_3d_set_left_right_switch(int16_t lrswitch,EN_ACT_CTRL act);

/** 
@brief ��ȡ��ǰ������Ƶstream�Ƿ�Ϊframe packing

@param [out] 0Ϊfalse��1Ϊtrue

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_is_framepacking_mode(int16_t *mode);

/** 
@brief ����3D navigationģʽ

@param [in] mode ȡֵ��Χ�뿴EN_3D_NAVIGATIONö������

@param [in] EN_ACT_CTRL ���iִGG����G�(ִֻGG��ֻ���棬ִGG�󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_set_navigation(int16_t mode,EN_ACT_CTRL act);

/** 
@brief ��ȡ3D navigationģʽ

@param [out] mode ȡֵ��Χ�뿴EN_3D_NAVIGATIONö������

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_3d_get_navigation(int16_t *mode);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
