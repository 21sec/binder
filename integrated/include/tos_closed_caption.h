/**@defgroup Closed Captionģ��

@{
@brief ���ڿ��Ƶ�����Closed Caption��صĲ���

@version 1.0.0
**/

#ifndef __TOS_CLOSED_CAPTION__
#define __TOS_CLOSED_CAPTION__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" 
{
#endif

#if 0
/**
@brief ִ�е�״̬
**/
typedef enum
{
	EN_ACT_EXEC,///< ִֻ��
	EN_ACT_SAVE, ///<ֻ����
	EN_ACT_EXEC_SAVE,///<ִ�к󱣴�
}EN_ACT_CTRL;
#endif

/**
@brief UI��APP���ڿ���Closed Caption����ʾ������
*/
typedef enum
{
    EN_CC_VISIBLE_UI = 0x0001,///< UI���ڿ���Closed Caption����ʾ������
    EN_CC_VISIBLE_APP= 0x0002,///< �ݲ�ʹ�ã�APP����Closed Caption����ʾ������
    EN_CC_VISIBLE_SMALL_WINDOW = 0x0004,
    EN_CC_VISIBLE_ALL = 0xffff,
}EN_CC_VISIBLE_LEVEL;


/**
@brief ���ÿ���CC��ģʽ
*/
typedef enum
{   
    EN_CC_OFF,///< �ص�CC
    EN_CC_ON,///< ��CC��CCһֱ��ʾ
    EN_CC_ON_WHEN_MUTE,///< ��CC����TV����ʱ��ʾCC
}EN_CC_ENABLE_MODE;


/**
@brief ���ƿ�������(TSC/ISDB) CC����
*/
typedef enum
{
    EN_DIGITAL_CC_OFF,///< �ر�ISDB��ATSC CC
    EN_DIGITAL_CC_S1,///< ��ATSC&&ISDB Service1 CC
    EN_DIGITAL_CC_S2,///< ��ATSC&&ISDB Service2 CC
    EN_DIGITAL_CC_S3,///< ��ATSC&&ISDB Service3 CC
    EN_DIGITAL_CC_S4,///< ��ATSC&&ISDB Service4 CC
    EN_DIGITAL_CC_S5,///< ��ATSC&&ISDB Service5 CC
    EN_DIGITAL_CC_S6,///< ��ATSC&&ISDB Service6 CC
    EN_DIGITAL_CC_S7,///< ��ISDB Service7 CC
    EN_DIGITAL_CC_S8,///< ��ISDB Service8 CC
}EN_DIGITAL_CC_TYPE;


/**
@brief ���ƿ���ģ��(NTSC)CC����
*/
typedef enum
{
    EN_ANALOG_CC_OFF,///< �ر�ģ��CC
    EN_ANALOG_CC_CC1,///< ��ģ��CC1
    EN_ANALOG_CC_CC2,///< ��ģ��CC2
    EN_ANALOG_CC_CC3,///< ��ģ��CC3
    EN_ANALOG_CC_CC4,///< ��ģ��CC4
    EN_ANALOG_CC_TEXT1,///< ��ģ��TEXT1
    EN_ANALOG_CC_TEXT2,///< ��ģ��TEXT2
    EN_ANALOG_CC_TEXT3,///< ��ģ��TEXT3
    EN_ANALOG_CC_TEXT4,///< ��ģ��TEXT4
    EN_ANALOG_CC_XDS,///< ��ģ��XDS,�ݲ�֧��
}EN_ANALOG_CC_TYPE;


/**
@brief ������ʾATSC CC��ʽ
*/
typedef enum
{
    EN_CC_PRESET_DEFAULT,///< ��������ԭ�и�ʽ��ʾATSC CC
    EN_CC_PRESET_CUSTOM,///< �����û�������ʾATSC CC
}EN_CC_PRESET_MODE;


/**
@brief ��ʾATSC CC FONT��С
*/
typedef enum
{
    EN_CC_FONT_SIZE_DEFAULT,///< ��������ԭ��������ʾATSC CC
    EN_CC_FONT_SIZE_SMALL,///< ����Small Font��ʾATSC CC
    EN_CC_FONT_SIZE_STANDARD,///< ����Normal Font��ʾATSC CC
    EN_CC_FONT_SIZE_LARGE,///< ����Large Font��ʾATSC CC   
}EN_CC_FONT_SIZE;


/**
@brief ��ʾATSC CC FONT���
*/
typedef enum
{
    EN_CC_FONT_STYLE_DEFAULT,///< undefined
    EN_CC_FONT_STYLE_FONT1,///< Monospaced with serifs(similar to Courier)
    EN_CC_FONT_STYLE_FONT2,///< Proportionally spaced with serifs(similar to Times New Roman)
    EN_CC_FONT_STYLE_FONT3,///< Monospaced without serifs(similar to Helvetica Monospaced)
    EN_CC_FONT_STYLE_FONT4,///< Proportionally without serifs(similar to Arial and Swiss)
    EN_CC_FONT_STYLE_FONT5,///< Casual font type(similar to Dom and Impress)
    EN_CC_FONT_STYLE_FONT6,///< Cursive font type(similar to Coronet and Marigold)
    EN_CC_FONT_STYLE_FONT7,///< Small capitals(similar to Engravers Gothic)
}EN_CC_FONT_STYLE;


/**
@brief ��ʾATSC CC FONT EDGE���
*/
typedef enum
{
    EN_CC_FONT_EDGE_STYLE_DEFAULT,///< ��������ԭ�и�ʽ��ʾATSC CC
    EN_CC_FONT_EDGE_STYLE_NONE,
    EN_CC_FONT_EDGE_STYLE_RAISED,
    EN_CC_FONT_EDGE_STYLE_DEPRESSED,
    EN_CC_FONT_EDGE_STYLE_UNIFORM,
    EN_CC_FONT_EDGE_STYLE_LEFT_SHADOW,
    EN_CC_FONT_EDGE_STYLE_RIGHT_SHADOW,
}EN_CC_FONT_EDGE_STYLE;


/**
@brief ��ʾATSC CC COLOR TYPE,����������ɫ������ɫ��ǰ��ɫ
*/
typedef enum
{
    EN_CC_COLOR_DEFAULT,///< ��������ԭ�и�ʽ��ʾATSC CC
    EN_CC_COLOR_BLACK,///< ���ú�ɫ��ʾATSC CC
    EN_CC_COLOR_WHITE,///< ���ð�ɫ��ʾATSC CC    
    EN_CC_COLOR_GREEN,///< ������ɫ��ʾATSC CC
    EN_CC_COLOR_BLUE,///< ������ɫ��ʾATSC CC
    EN_CC_COLOR_RED,///< ���ú�ɫ��ʾATSC CC
    EN_CC_COLOR_CRAN,///< ������ɫ��ʾATSC CC
    EN_CC_COLOR_YELLOW,///< ���û�ɫ��ʾATSC CC
    EN_CC_COLOR_MAGENTA,///< �����Ϻ�ɫ��ʾATSC CC    
}EN_CC_COLOR;


/**
@brief ��ʾATSC CC OPACITY����������͸���ȣ�����͸���ȣ�ǰ��͸����
*/
typedef enum
{
    EN_CC_OPACITY_DEFAULT,///< ��������ԭ�и�ʽ��ʾATSC CC
    EN_CC_SOLID,///< ��͸��
    EN_CC_TRANSLUCENT,///< ��͸��
    EN_CC_TRANSPARENT,///< ͸��   
    EN_CC_FLASHING,///< ��˸
}EN_CC_OPACITY;


/**
@brief �û�����ATSC CC ��ʾѡ��ö��
*/
typedef enum
{    
    EN_CC_STYLE_FONT_STYLE= 0x0001,///< set st_cc_style.font_style
    EN_CC_STYLE_FONT_SIZE  = 0x0002,///< set st_cc_style.font_size
    EN_CC_STYLE_FONT_COLOR = 0x0004,///< set st_cc_style.font_color
    EN_CC_STYLE_FONT_OPACITY = 0x0008,///< set st_cc_style.font_opacity
    
    EN_CC_STYLE_FONT_EDGE_STYLE = 0x0010,///< set st_cc_style.font_edge_style
    EN_CC_STYLE_FONT_EDGE_COLOR = 0x0020,///< set st_cc_style.font_edge_color

    EN_CC_STYLE_FG_COLOR = 0x0040,///< set st_cc_style.fg_color
    EN_CC_STYLE_FG_OPACITY =0x0080,///< set st_cc_style.fg_opacity

    EN_CC_STYLE_BG_COLOR = 0x0100,///< set st_cc_style.bg_color
    EN_CC_STYLE_BG_OPACITY = 0x0200,///< set st_cc_style.bg_color
    
    EN_CC_STYLE_ALL = 0xFFFF ///< set st_cc_style   
}EN_CC_STYLE_TYPE;


/**
@brief �û�����ATSC CC ��ʾѡ��
*/
typedef struct
{    
    EN_CC_FONT_STYLE font_style;
    EN_CC_FONT_SIZE font_size;
    EN_CC_COLOR font_color;
    EN_CC_OPACITY font_opacity;
    
    EN_CC_FONT_EDGE_STYLE font_edge_style;
    EN_CC_COLOR font_edge_color;

    EN_CC_COLOR fg_color;
    EN_CC_OPACITY fg_opacity;
        
    EN_CC_COLOR bg_color;
    EN_CC_OPACITY bg_opacity;    
}st_cc_style;


/**
@brief ��ȡ��ǰ��Ŀ���Ƿ���CC��������ʾCCͼ��
@param[out] available ��ȡ��ǰ��Ŀ���Ƿ���CC
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_is_available(fpi_bool *available);


/**
@brief UI && APP������ʾ����CC
@param[in] level ������ʾ����CC����
@param[in] show fpi_true��ʾCC��������CC
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_set_visibility(EN_CC_VISIBLE_LEVEL level,fpi_bool show);


/**
@brief ���ÿ���CC��ģʽ
@param[in] cmd ִ�е�״̬,���ö�ٶ���
@param[in] mode ����CC��ģʽ�����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_set_cc_enable_mode(EN_ACT_CTRL cmd,EN_CC_ENABLE_MODE mode);


/**
@brief ��ȡ����CC��ģʽ������UI��ʾ
@param[out] mode ��ȡ����CC��ģʽ�����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_get_cc_enable_mode(EN_CC_ENABLE_MODE  *mode);


/**
@brief ��������(ISDB && ATSC)CC������
@param[in] cmd ִ�е�״̬,���ö�ٶ���
@param[in] type ����(ISDB && ATSC)CC�����ͣ����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_switch_digital_cc(EN_ACT_CTRL cmd,EN_DIGITAL_CC_TYPE type);


/**
@brief ��ȡ����(ISDB && ATSC)CC�����ͣ�����UI��ʾ
@param[out] type ��ȡ����(ISDB && ATSC)CC�����ͣ����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_get_digital_cc_type(EN_DIGITAL_CC_TYPE *type);


/**
@brief ����ģ��CC������
@param[in] cmd ִ�е�״̬,���ö�ٶ���
@param[in] type ģ��CC�����ͣ����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_switch_analog_cc(EN_ACT_CTRL cmd,EN_ANALOG_CC_TYPE type);


/**
@brief ��ȡģ��CC�����ͣ�����UI��ʾ
@param[out] type ��ȡģ��CC�����ͣ����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_get_analog_cc_type(EN_ANALOG_CC_TYPE *type);


/**
@brief ����CC��Ԥ����ģʽ
@param[in] cmd ִ�е�״̬,���ö�ٶ���
@param[in] preset CCԤ���õ�ģʽ�����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_set_cc_preset_mode(EN_ACT_CTRL cmd,EN_CC_PRESET_MODE preset);


/**
@brief ��ȡCC��Ԥ����ģʽ
@param[out] preset ��ȡCCԤ���õ�ģʽ�����ö�ٶ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_get_cc_preset_mode(EN_CC_PRESET_MODE *preset);


/**
@brief ����CC����ʾ��񣬸����û�������ʾATSC CC
@param[in] cmd ִ�е�״̬,���ö�ٶ���
@param[in] style_type ����CC Style�ľ���ѡ��
@param[in] cc_style ����CC����ʾ�������ṹ�嶨��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_set_cc_style(EN_ACT_CTRL cmd,EN_CC_STYLE_TYPE style_type,st_cc_style cc_style);


/**
@brief ��ȡ�û����õ�CC��ʾ���
@param[out] cc_style ��ȡ�û����õ�CC��ʾ�������ṹ�嶨��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_cc_get_cc_style(st_cc_style *cc_style);

#ifdef __cplusplus
}
#endif

#endif
