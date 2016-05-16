/**@defgroup ÊÓÆµ3DÄ£¿é
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ³õ¸å
*/



#ifndef __TOS_3D_H__
#define __TOS_3D_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 3DdµÄÄ£Ê½
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
@brief 3DÆÁµÄÀàGÍ
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
@brief »ñÈ¡3DµÄ¾°Éî

@param [out] depth ¾°ÉîÖµ£¬·¶Î§Ò»°ãÎª0-30

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_get_depth_of_field(int16_t *depth);

/** 
@brief ÉèÖÃ3DµÄ¾°Éî

@param [in] depth ¾°ÉîÖµ£¬·¶Î§Ò»°ãÎª0-30

@param [in] EN_ACT_CTRL º¯ÊiÖ´GGµÄÀàGÍ(Ö»Ö´GG£¬Ö»±£´æ£¬Ö´GGºó±£´æ)

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_set_depth_of_field(int16_t depth,EN_ACT_CTRL act);

/** 
@brief »ñµÃ3DÊÓÆµ×ª»»Îª2DµÄÄ£Ê½

@param [out] mode È¡Öµ·¶Î§¼ûEN_FPI_3D_VIDEO_DIAPLAY_FORMAT Ã¶¾Ù

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_get_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *mode);

/** 
@brief ÉèÖÃ3DÊÓÆµ×ª»»Îª2DµÄÄ£Ê½

@param [in] mode È¡Öµ·¶Î§¼ûEN_FPI_3D_VIDEO_DIAPLAY_FORMAT Ã¶¾Ù

@param [in] EN_ACT_CTRL º¯ÊiÖ´GGµÄÀàGÍ(Ö»Ö´GG£¬Ö»±£´æ£¬Ö´GGºó±£´æ)

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_set_3dto2d_mode(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode,EN_ACT_CTRL act);

/** 
@brief »ñµÃµ±Ç°µÄ3DÏÔÊ¾¸ñÊ½

@param [out] mode È¡Öµ·¶Î§¼ûEN_FPI_3D_VIDEO_DIAPLAY_FORMAT Ã¶¾Ù

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_get_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT *format);

/** 
@brief ÉèÖÃµ±Ç°µÄ3DÏÔÊ¾¸ñÊ½

@param [in] mode È¡Öµ·¶Î§¼ûEN_FPI_3D_VIDEO_DIAPLAY_FORMAT Ã¶¾Ù

@param [in] EN_ACT_CTRL º¯ÊiÖ´GGµÄÀàGÍ(Ö»Ö´GG£¬Ö»±£´æ£¬Ö´GGºó±£´æ)

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_set_display_format(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT displayFormat,EN_ACT_CTRL act);

/** 
@brief »ñÈ¡3D×óÓÒ¸ñÊ½µÄÇG»»µÄ×´Ì¬

@param [out] lrswitch 0ÎªL/R,1ÎªR/L£¬¾ßÌå»¹µÃ¿´model.iniµÄlrÅäÖÃ

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_get_left_right_switch(int16_t *lrswitch);

/** 
@brief ÉèÖÃ3DÊÓÆµµÄ×óÓÒ¸ñÊ½ÇG»»

@param [in] lrswitch 0ÎªL/R,1ÎªR/L£¬¾ßÌå»¹µÃ¿´model.iniµÄlrÅäÖÃ

@param [in] EN_ACT_CTRL º¯ÊiÖ´GGµÄÀàGÍ(Ö»Ö´GG£¬Ö»±£´æ£¬Ö´GGºó±£´æ)

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/

fpi_error tos_3d_set_left_right_switch(int16_t lrswitch,EN_ACT_CTRL act);

/** 
@brief »ñÈ¡µ±Ç°²¥·ÅÊÓÆµstreamÊÇ·ñÎªframe packing

@param [out] 0Îªfalse£¬1Îªtrue

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_is_framepacking_mode(int16_t *mode);

/** 
@brief ÉèÖÃ3D navigationÄ£Ê½

@param [in] mode È¡Öµ·¶Î§Çë¿´EN_3D_NAVIGATIONÃ¶¾ÙÃèÊö

@param [in] EN_ACT_CTRL º¯ÊiÖ´GGµÄÀàGÍ(Ö»Ö´GG£¬Ö»±£´æ£¬Ö´GGºó±£´æ)

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_set_navigation(int16_t mode,EN_ACT_CTRL act);

/** 
@brief »ñÈ¡3D navigationÄ£Ê½

@param [out] mode È¡Öµ·¶Î§Çë¿´EN_3D_NAVIGATIONÃ¶¾ÙÃèÊö

@retval  ³É¹¦·µ»ØFPI_ERROR_SUCCESS;

@retval  Ê§°Ü·µ»ØÆäËûÖµ
*/
fpi_error tos_3d_get_navigation(int16_t *mode);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
