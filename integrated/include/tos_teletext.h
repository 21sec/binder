/**@defgroup Teletext模块

@{
@brief 用于控制电视中Teletext相关操作

@version 1.0.0
**/

#ifndef __TOS_TELETEXT_H__
#define __TOS_TELETEXT_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#ifdef __cplusplus
extern "C" 
{
#endif

typedef enum
{
	E_TELETEXT_STATE_OFF = 0x1,              ///< 关闭teletext后的状态
	E_TELETEXT_STATE_ON = 0x2,               ///< teletext处于打开时的状态
	E_TELETEXT_STATE_SMALL_WINDOW = 0x3,     ///< teletext处于半屏时的状态
	E_TELETEXT_STATE_ALL_MIX = 0x4,          ///< teletext播放newsflash或alarmpage时的状态
    E_TELETEXT_STATE_SUBTITLE = 0x5,         ///< teletext播放字幕时的状态
} EN_FPI_TELETEXT_STATE;

 typedef enum
{
	E_TELETEXT_LANG_WEST,
	E_TELETEXT_LANG_EAST,
	E_TELETEXT_LANG_RUSSIAN,
	E_TELETEXT_LANG_ARABIC_HEBREW,
	E_TELETEXT_LANG_FARSI,
	E_TELETEXT_LANG_ARABIC,
	E_TELETEXT_LANG_BYELORUSSIAN
}EN_FPI_DECODE_PAGE_LANGUAGE;

typedef struct
{
	int32_t reVealState;
	int32_t cycleSubPageState;
	int32_t newsFlashState;
    int32_t alarmpageState;
} fpi_teletext_show_state;


/**
@brief teletext的初始状态为E_TELETEXT_STATE_OFF , 调用该接口， 打开teletext
@param[in] none
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_on();

/**
@brief teletext的状态为E_TELETEXT_STATE_HALF_MIX 时，调用该接口，关闭 teletext
@param[in] none
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_off();

/**
@brief teletext的状态为E_TELETEXT_STATE_ON 、E_TELETEXT_STATE_ALL_MIX或者E_TELETEXT_STATE_SUBTITLE时，调用该接口， 打开small screen teletext
@note 注意: output window teletext目前有half screen teletext
@param[in] x 与 y:output window 起始坐标；width  与height:output window 的长与宽；
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_set_output_window(int32_t x,int32_t y,int32_t width,int32_t height);

/**
@brief 获取teletext状态
@param[in] state 输入的指针用于 获取teletext当前的状态EN_FPI_TELETEXT_STATE
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_get_state(EN_FPI_TELETEXT_STATE *state);


/**
@brief 获取当前节目是否有 teletext
@param[in] value 输入的指针用于 获取是否有teletext
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_is_available(fpi_bool *value);

/**
@brief 获取当前teletext 页是否有subpage
@param[in] value 输入的指针用于 获取当前teletext 页是否有subpage
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_subpage_is_available(fpi_bool *value);

/**
@brief 获取当前teletext 页是否是newsflash
@param[in] value 输入的指针用于 获取当前teletext 页是否是newsflash
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_newsflash_is_available(fpi_bool *value);

/**
@brief 获取当前teletext 页是否有alarmpage 子页
@param[in] value 输入的指针用于 获取当前teletext 页是否有alarmpage
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_alarmpage_is_available(fpi_bool *value);

/**
@brief 获取当前teletext 的reveal状态是否打开(打开的话，会有些隐藏字符显示出来)
@param[in] value 输入的指针用于 获取当前teletext页的reveal 是否打开
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_reveal_is_on(fpi_bool *value);

/**
@brief 获取当前teletext 的subpage cycle是否打开(打开的话，subpage自动循环切换)
@param[in] value 输入的指针用于 获取当前teletext页的subpage cycle是否打开
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_subpage_cycle_is_on(fpi_bool *value);

/**
@brief 切换当前teletext 页的reveal状态(on or off)
@param[in] none
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_toggle_reveal();

/**
@brief 设置当前teletext 页的reveal状态(on or off)
@param[in] revealMode teletext 页的reveal状态
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_set_reveal_mode(fpi_bool revealMode);

/**
@brief 切换当前teletext 的subpage 是否是循环播放(on or off)
@param[in] none
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_toggle_subpage_cycle_model();

/**
@brief 设置当前teletext 的subpage 循环播放(on or off)
@param[in] subpageMode teletext 的subpage 循环播放状态
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_set_subpage_cycle_mode(fpi_bool subpageMode);

/**
@brief 设置当前teletext语言组
@note 需要保存操作
@param[in] groupId language teletext设置的语言组
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_set_language_group(uint8_t groupId);

/**
@brief 获取当前teletext语言组
@param[in] groupId 输入的指针用于获取当前teletext 语言组
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_get_language_group(uint8_t *groupId);

/**
@brief 设置teltext 语言
@param[in] language MEMBER_LANGUAGE language 语言枚举值，参照MEMBER_LANGUAGE枚举值
@param[out] none
@return fpi_error:  FPI_ERROR_SUCCESS -- get success; FPI_ERROR_FAIL  -- get fail
*/
fpi_error tos_teletext_set_digital_language(MEMBER_LANGUAGE language);

/**
@brief 获取teltext语言
@param[in] language MEMBER_LANGUAGE *language, 语言枚举值指针:枚举参照MEMBER_LANGUAGE枚举值
@param[out] none
@return fpi_error:  FPI_ERROR_SUCCESS -- get success; FPI_ERROR_FAIL  -- get fail
*/
fpi_error tos_teletext_get_digital_language(MEMBER_LANGUAGE *language);

/**
@brief 将遥控器键值交由teletext 模块处理.
@note注意: 并不是所有的键值都要teletext 模块来处理的, 需要传给teletext 的键值包括: 上下左
右方向键、确定键、数字键、红绿黄蓝颜色键、上下翻页键
@param[in] keyCode 遥控器键值，可以由中间件定义公共使用的键值
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_handle_key(int keyCode);

/**
@brief 当前teletext 页是newsflash 页时，按确定键设置调用该接口
@note 注意:newsflash是特殊的teletext页，当前teletext 页是newsflash 页时，teletext设置菜单会弹出并显示
光标显示在newsflash ok设置栏上，按确定键确定newsflash,当newsflash刷新时,显示newsflash。
@param[in] none                        
@param[out] none   
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_open_newsflash();

/**
@brief 当前teletext 页有alarmpage 子页时，设置输入时间后调用该接口
@note 注意:alarmpage是特殊的teletext 子页，当前teletext 页有alarmpage 页时，teletext设置菜单中alarmpage设置栏
可以输入时间，设置好输入时间后，当设置好teletext alarmpage到来时，会显示设置的alarmpage。
@param[in] t_time 输入的 时间，对应着teletext的特殊子页，
其输入形式为:输入的千位与百位对应时间的小时，十位与个位对应时间的分钟，如0938对应时间09:38                      
@param[out] none
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_teletext_open_alarmpage(uint16_t t_time);


#ifdef __cplusplus
}
#endif

#endif

