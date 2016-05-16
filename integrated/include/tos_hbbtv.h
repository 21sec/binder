/**@defgroup HBBTV模块

@{
@brief 用于控制电视中HBBTV相关操作

@version 1.0.0
**/

#ifndef __TOS_HBBTV_H__
#define __TOS_HBBTV_H__

#include "tos_dtv_basetype.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" 
{
#endif


typedef enum
{
    EN_TOS_HBBTV_OFF = 0x0,                  ///< hbbtv关闭状态
    EN_TOS_HBBTV_RED_BUTTON = 0x1,            ///<hbbtv开启，显示为红色按钮
    EN_TOS_HBBTV_FULLSCREEN_NO_VOD = 0x2,    ///< hbbtv开启，显示全屏，没有播放VOD
	EN_TOS_HBBTV_FULLSCREEN_VOD = 0x3,       ///< hbbtv开启，显示全屏，并播放VOD
	EN_TOS_HBBTV_INVALID,                    ///< 无效
} EN_TOS_HBBTV_STATE;   


/**
@brief 判断当前频道是否有HbbTv
@param[out] exist 有HbbTv返回fpi_true;没有HbbTv返回fpi_false
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_is_exist(fpi_bool *exist);

/**
@brief 开启HbbTv
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_open();

/**
@brief 关闭HbbTv
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_close();

/**
@brief 获取hbbtv的当前工作状态
@param[out] state hbbtv的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_get_state(EN_TOS_HBBTV_STATE *state);

/**
@brief 接收按键
@param[in] keyCode 键值;keyType 按键类型
@param[out] isHandle HbbTv处理了该按键返回fpi_true;反之返回fpi_false
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_handle_key(uint16_t keyCode,uint16_t keyType,fpi_bool* isHandle);

/**
@brief 获取hbbtv 用户开关的状态
@param[out] mode hbbtv 开关的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_get_mode(fpi_bool *mode);

/**
@brief 设置hbbtv 用户开关
@param[in] mode hbbtv 开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_set_mode(fpi_bool mode);

/**
@brief 获取hbbtv cookie 用户开关状态
@param[out] mode hbbtv cookie开关的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_get_cookie_mode(fpi_bool *mode);

/**
@brief 设置hbbtv cookie 用户开关
@param[in] mode hbbtv cookie开关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_hbbtv_set_cookie_mode(fpi_bool mode);

/**
@brief 判断当前频道是否有HbbTV的Teletext
@param[out] exist 存在fpi_true;没有fpi_false
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_teletext_is_exist(fpi_bool *exist);

/**
@brief 判断HbbTV的Teletext是否已被打开
@param[out] open 已打开fpi_true;没有打开fpi_false
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_teletext_is_open(fpi_bool *open);

/**
@brief 开启HbbTV的Teletext
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_teletext_open();

/**
@brief 关闭HbbTV的Teletext
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_teletext_close();

/**
@brief 打开一个hbbtv 应用
@param[in] webPortalURL:要打开的hbbtv的url
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_open_portal(char* webPortalURL);

/**
@brief 关闭hbbtv 应用
@param[in] void
@return FPI_ERROR_SUCCESS成功;失败返回其他值
*/
fpi_error tos_hbbtv_close_portal(void);

#ifdef __cplusplus
}
#endif
/** @} */
#endif


