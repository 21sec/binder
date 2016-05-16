/**@defgroup Closed Caption模块

@{
@brief 用于控制电视中Closed Caption相关的操作

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
@brief 执行的状态
**/
typedef enum
{
	EN_ACT_EXEC,///< 只执行
	EN_ACT_SAVE, ///<只保存
	EN_ACT_EXEC_SAVE,///<执行后保存
}EN_ACT_CTRL;
#endif

/**
@brief UI和APP用于控制Closed Caption的显示与隐藏
*/
typedef enum
{
    EN_CC_VISIBLE_UI = 0x0001,///< UI用于控制Closed Caption的显示与隐藏
    EN_CC_VISIBLE_APP= 0x0002,///< 暂不使用，APP控制Closed Caption的显示与隐藏
    EN_CC_VISIBLE_SMALL_WINDOW = 0x0004,
    EN_CC_VISIBLE_ALL = 0xffff,
}EN_CC_VISIBLE_LEVEL;


/**
@brief 设置开关CC的模式
*/
typedef enum
{   
    EN_CC_OFF,///< 关掉CC
    EN_CC_ON,///< 打开CC，CC一直显示
    EN_CC_ON_WHEN_MUTE,///< 打开CC，当TV静音时显示CC
}EN_CC_ENABLE_MODE;


/**
@brief 控制开关数字(TSC/ISDB) CC类型
*/
typedef enum
{
    EN_DIGITAL_CC_OFF,///< 关闭ISDB和ATSC CC
    EN_DIGITAL_CC_S1,///< 打开ATSC&&ISDB Service1 CC
    EN_DIGITAL_CC_S2,///< 打开ATSC&&ISDB Service2 CC
    EN_DIGITAL_CC_S3,///< 打开ATSC&&ISDB Service3 CC
    EN_DIGITAL_CC_S4,///< 打开ATSC&&ISDB Service4 CC
    EN_DIGITAL_CC_S5,///< 打开ATSC&&ISDB Service5 CC
    EN_DIGITAL_CC_S6,///< 打开ATSC&&ISDB Service6 CC
    EN_DIGITAL_CC_S7,///< 打开ISDB Service7 CC
    EN_DIGITAL_CC_S8,///< 打开ISDB Service8 CC
}EN_DIGITAL_CC_TYPE;


/**
@brief 控制开关模拟(NTSC)CC类型
*/
typedef enum
{
    EN_ANALOG_CC_OFF,///< 关闭模拟CC
    EN_ANALOG_CC_CC1,///< 打开模拟CC1
    EN_ANALOG_CC_CC2,///< 打开模拟CC2
    EN_ANALOG_CC_CC3,///< 打开模拟CC3
    EN_ANALOG_CC_CC4,///< 打开模拟CC4
    EN_ANALOG_CC_TEXT1,///< 打开模拟TEXT1
    EN_ANALOG_CC_TEXT2,///< 打开模拟TEXT2
    EN_ANALOG_CC_TEXT3,///< 打开模拟TEXT3
    EN_ANALOG_CC_TEXT4,///< 打开模拟TEXT4
    EN_ANALOG_CC_XDS,///< 打开模拟XDS,暂不支持
}EN_ANALOG_CC_TYPE;


/**
@brief 设置显示ATSC CC方式
*/
typedef enum
{
    EN_CC_PRESET_DEFAULT,///< 采用码流原有格式显示ATSC CC
    EN_CC_PRESET_CUSTOM,///< 采用用户设置显示ATSC CC
}EN_CC_PRESET_MODE;


/**
@brief 显示ATSC CC FONT大小
*/
typedef enum
{
    EN_CC_FONT_SIZE_DEFAULT,///< 采用码流原有字体显示ATSC CC
    EN_CC_FONT_SIZE_SMALL,///< 采用Small Font显示ATSC CC
    EN_CC_FONT_SIZE_STANDARD,///< 采用Normal Font显示ATSC CC
    EN_CC_FONT_SIZE_LARGE,///< 采用Large Font显示ATSC CC   
}EN_CC_FONT_SIZE;


/**
@brief 显示ATSC CC FONT风格
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
@brief 显示ATSC CC FONT EDGE风格
*/
typedef enum
{
    EN_CC_FONT_EDGE_STYLE_DEFAULT,///< 采用码流原有格式显示ATSC CC
    EN_CC_FONT_EDGE_STYLE_NONE,
    EN_CC_FONT_EDGE_STYLE_RAISED,
    EN_CC_FONT_EDGE_STYLE_DEPRESSED,
    EN_CC_FONT_EDGE_STYLE_UNIFORM,
    EN_CC_FONT_EDGE_STYLE_LEFT_SHADOW,
    EN_CC_FONT_EDGE_STYLE_RIGHT_SHADOW,
}EN_CC_FONT_EDGE_STYLE;


/**
@brief 显示ATSC CC COLOR TYPE,包括字体颜色，背景色，前景色
*/
typedef enum
{
    EN_CC_COLOR_DEFAULT,///< 采用码流原有格式显示ATSC CC
    EN_CC_COLOR_BLACK,///< 采用黑色显示ATSC CC
    EN_CC_COLOR_WHITE,///< 采用白色显示ATSC CC    
    EN_CC_COLOR_GREEN,///< 采用绿色显示ATSC CC
    EN_CC_COLOR_BLUE,///< 采用蓝色显示ATSC CC
    EN_CC_COLOR_RED,///< 采用红色显示ATSC CC
    EN_CC_COLOR_CRAN,///< 采用青色显示ATSC CC
    EN_CC_COLOR_YELLOW,///< 采用黄色显示ATSC CC
    EN_CC_COLOR_MAGENTA,///< 采用紫红色显示ATSC CC    
}EN_CC_COLOR;


/**
@brief 显示ATSC CC OPACITY，包括字体透明度，背景透明度，前景透明度
*/
typedef enum
{
    EN_CC_OPACITY_DEFAULT,///< 采用码流原有格式显示ATSC CC
    EN_CC_SOLID,///< 不透明
    EN_CC_TRANSLUCENT,///< 半透明
    EN_CC_TRANSPARENT,///< 透明   
    EN_CC_FLASHING,///< 闪烁
}EN_CC_OPACITY;


/**
@brief 用户设置ATSC CC 显示选项枚举
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
@brief 用户设置ATSC CC 显示选项
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
@brief 获取当前节目中是否有CC，用于显示CC图标
@param[out] available 获取当前节目中是否有CC
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_is_available(fpi_bool *available);


/**
@brief UI && APP控制显示隐藏CC
@param[in] level 控制显示隐藏CC级别
@param[in] show fpi_true显示CC否则隐藏CC
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_set_visibility(EN_CC_VISIBLE_LEVEL level,fpi_bool show);


/**
@brief 设置开关CC的模式
@param[in] cmd 执行的状态,详见枚举定义
@param[in] mode 开关CC的模式，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_set_cc_enable_mode(EN_ACT_CTRL cmd,EN_CC_ENABLE_MODE mode);


/**
@brief 获取开关CC的模式，用于UI显示
@param[out] mode 获取开关CC的模式，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_get_cc_enable_mode(EN_CC_ENABLE_MODE  *mode);


/**
@brief 设置数字(ISDB && ATSC)CC的类型
@param[in] cmd 执行的状态,详见枚举定义
@param[in] type 数字(ISDB && ATSC)CC的类型，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_switch_digital_cc(EN_ACT_CTRL cmd,EN_DIGITAL_CC_TYPE type);


/**
@brief 获取数字(ISDB && ATSC)CC的类型，用于UI显示
@param[out] type 获取数字(ISDB && ATSC)CC的类型，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_get_digital_cc_type(EN_DIGITAL_CC_TYPE *type);


/**
@brief 设置模拟CC的类型
@param[in] cmd 执行的状态,详见枚举定义
@param[in] type 模拟CC的类型，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_switch_analog_cc(EN_ACT_CTRL cmd,EN_ANALOG_CC_TYPE type);


/**
@brief 获取模拟CC的类型，用于UI显示
@param[out] type 获取模拟CC的类型，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_get_analog_cc_type(EN_ANALOG_CC_TYPE *type);


/**
@brief 设置CC的预设置模式
@param[in] cmd 执行的状态,详见枚举定义
@param[in] preset CC预设置的模式，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_set_cc_preset_mode(EN_ACT_CTRL cmd,EN_CC_PRESET_MODE preset);


/**
@brief 获取CC的预设置模式
@param[out] preset 获取CC预设置的模式，详见枚举定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_get_cc_preset_mode(EN_CC_PRESET_MODE *preset);


/**
@brief 设置CC的显示风格，根据用户设置显示ATSC CC
@param[in] cmd 执行的状态,详见枚举定义
@param[in] style_type 设置CC Style的具体选项
@param[in] cc_style 设置CC的显示风格，详见结构体定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_set_cc_style(EN_ACT_CTRL cmd,EN_CC_STYLE_TYPE style_type,st_cc_style cc_style);


/**
@brief 获取用户设置的CC显示风格
@param[out] cc_style 获取用户设置的CC显示风格，详见结构体定义
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_cc_get_cc_style(st_cc_style *cc_style);

#ifdef __cplusplus
}
#endif

#endif
