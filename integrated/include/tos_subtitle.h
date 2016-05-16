/**@defgroup SUBTITLE模块

@{
@brief 用于控制电视中字幕相关的操作

@version 1.0.0
**/
#ifndef __TOS_SUBTITLE_H__
#define __TOS_SUBTITLE_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#ifdef __cplusplus
extern "C" 
{
#endif

#define FPI_SUBTITLE_SERVICES_NUMS   64

typedef enum
{
    E_SUBTITLE_PREFER_LANGUAGE_FIRST,       ///< 第一语言
    E_SUBTITLE_PREFER_LANGUAGE_SECOND,      ///< 第二语言
    E_SUBTITLE_PREFER_LANGUAGE_NUM,
} EN_FPI_SUBTITLE_PREFER_LANGUAGE;

typedef enum
{
    E_SUBTITLE_MODE_NORMAL,                ///< 正常模式
    E_SUBTITLE_MODE_HEARING_IMPAIRED,      ///< 听力障碍模式
    E_SUBTITLE_MODE_NUM,
} EN_FPI_SUBTITLE_MODE;

typedef enum
{
    SUBTITLE_VISIBLE_UI = 0x1, //for ui to control subtitle display or not
    SUBTITLE_VISIBLE_APP= 0x2,  //not used
    SUBTITLE_VISIBLE_ALL = 0xffff,
}EN_FPI_SUBTITLE_VISIBLE_LEVEL;


typedef struct st_fpi_menu_subtitle_service
{
    int32_t eLanguage;                     ///< 语言索引，对应语言枚举
    EN_FPI_SUBTITLE_MODE  enSubtitleMode;  ///< subtitle的模式，正常、听力障碍
   // uint8_t  u8RefCount;                 ///< subtitle服务相关个数，未使用
    uint8_t  StringCodes[4];               ///< the  ISO 639 字符串
} fpi_menu_subtitle_service_t;

typedef struct st_fpi_subtitle_info
{
    fpi_menu_subtitle_service_t menuSubtitle[FPI_SUBTITLE_SERVICES_NUMS]; ///< subtitle菜单信息
    uint8_t currentSubtitleIndex; ///< 当前的subtitle对应索引，255 means has subtitle but not open
    uint8_t subtitleNumber;   ///< 当前节目支持的subtitle个数
    fpi_bool bSubtitleOn;  ///< subtitle是否打开或关闭
} fpi_subtitle_info_t;

/**
@brief 获取当前正在播放节目的subtitle 信息
@param[out] sttInfo 当前节目的subtitle 信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_get_info(fpi_subtitle_info_t *sttInfo);

/**
@brief 设置更改subtitle 显示，按索引进行选择显示，按subtitle键切换及subtitle列表选择时使用
设置后对应fpi_subtitle_info_t结构中currentSubtitleIndex
@param[in] index 打开subtitle的索引操作，0xff时默认，中间件自行处理
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_open(uint8_t index);

/**
@brief 设置subtitle可见，给应用使用，控制Ui进行subtitle的可见或隐藏，
区别于subtitle的打开和关闭，仅用于控制Ui进行subtitle的可见或隐藏
@param[in] flag 是否隐藏
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_set_visibility(EN_FPI_SUBTITLE_VISIBLE_LEVEL level,fpi_bool flag);

/**
@brief 获取subtitle 显示状态，是否打开或关闭
@param[out] flag 获取subtitle操作状态指针，fpi_true打开、fpi_false关闭
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_get_status(fpi_bool *flag);

/**
@brief 设置subtitle 显示状态
该接口会进行保存操作，重启后状态保持
@param[in] flag 设置更改subtitle操作状态，fpi_true打开、fpi_false关闭
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_set_status(fpi_bool flag);

/**
@brief 获取subtitle 模式，正常或听力障碍
@param[out] mode 获取subtitle 模式状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_get_mode(EN_FPI_SUBTITLE_MODE *mode);

/**
@brief 设置subtitle 模式，正常或听力障碍
当subtitle打开时进行选择，需要进行保存操作
@param[in] mode 设置subtitle 模式
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_set_mode(EN_FPI_SUBTITLE_MODE mode);

/**
@brief 获取subtitle第一第二语言
当subtitle打开时进行选择
@param[in] type 设置subtitle第一或第二语言类型
@param[out] language 获取subtitle第一或第二语言对应的语言枚举指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_get_prefer_language(EN_FPI_SUBTITLE_PREFER_LANGUAGE type,MEMBER_LANGUAGE *language);

/**
@brief 设置subtitle第一第二语言
当subtitle打开时进行选择，需要进行保存操作
@param[in] type 设置subtitle第一或第二语言类型
@param[in] language 设置subtitle第一或第二语言对应的语言枚举
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_subtitle_set_prefer_language(EN_FPI_SUBTITLE_PREFER_LANGUAGE type,MEMBER_LANGUAGE language);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
