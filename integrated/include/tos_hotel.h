#ifndef __TOS_HOTEL_H__
#define __TOS_HOTEL_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" 
{
#endif

typedef enum
{
    TYPE_LOCK_TUNER,     //锁住Tuner type
    TYPE_LOCK_MENU,      //锁住菜单
    TYPE_LOCK_USB,       //锁住USB功能
    TYPE_LOCK_SOURCE,    //锁住信源
    TYPE_LOCK_PANEL_KEY, //锁住面板按键
    TYPE_LOCK_CHANNEL    //锁住频道
}EN_TOS_LOCK_TYPE;

typedef enum
{
    FUNC_TYPE_AUTO_SET,     //Auto set开关
    FUNC_TYPE_FAV_LIST,     //喜爱节目列表开关
    FUNC_TYPE_POWER_ON_LOGO //开机logo功能开关
}EN_TOS_FUNCTION_TYPE;

typedef enum
{
    TYPE_POWER_ON_VOLUME,     //酒店模式下的开机音量
    TYPE_MAX_VOLUME           //酒店模式下的最大音量
}EN_TOS_VOLUME_TYPE;

typedef enum
{
	EN_TOS_HOTEL_SND_MODE_MUSIC,
	EN_TOS_HOTEL_SND_MODE_MOVIE,
	EN_TOS_HOTEL_SND_MODE_NEWS,
	EN_TOS_HOTEL_SND_MODE_STANDARD,
	EN_TOS_HOTEL_SND_MODE_USER,         
	EN_TOS_HOTEL_SND_MODE_SUBWOFOFER,         
  EN_TOS_HOTEL_SND_MODE_STADIUM,    
  EN_TOS_HOTEL_SND_MODE_NUM
}EN_TOS_HOTEL_SOUND_MODE;

typedef enum
{
    E_TOS_HOTEL_POWER_ON_MODE_ON,
    E_TOS_HOTEL_POWER_ON_MODE_STB,
    E_TOS_HOTEL_POWER_ON_MODE_LAST
}EN_TOS_HOTEL_POWER_ON_MODE;



/**
@brief 图像模式
**/
typedef enum
{
	E_TOS_HOTEL_MODE_STANDARD= 0, // Dynamic
	E_TOS_HOTEL_MODE_BRIGHT,
	E_TOS_HOTEL_MODE_SOFT,     //Movie
	E_TOS_HOTEL_MODE_STUDIO,
    E_TOS_HOTEL_MODE_USER,    //Personal  
           E_TOS_HOTEL_MODE_EX1,     
	E_TOS_HOTEL_MODE_NUM
}EN_TOS_HOTEL_PICTURE_MODE;

/** 
@brief 获取酒店模式打开关闭的状态
@param[out] *b_enable : fpi_true为开；fpi_false为关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_hotel_mode(fpi_bool *b_enable);

/** 
@brief 打开或者关闭酒店模式
@param[in] b_enable:fpi_true为开；fpi_false为关
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_hotel_mode(fpi_bool b_enable);

/** 
@brief 获取酒店模式下的开机音量以及最大音量
@param[in] ui2_volume
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_volume(EN_TOS_VOLUME_TYPE e_type, uint16_t *ui2_volume);

/** 
@brief 设置酒店模式下的开机音量以及最大音量
@param[in] ui2_volume
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_volume(EN_TOS_VOLUME_TYPE e_type, uint16_t ui2_volume);

/** 
@brief 获取酒店模式下的开机信源
@param[out] e_source
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_source(EN_API_SOURCE_INPUT *pe_source);

/** 
@brief 设置酒店模式下的开机信源
@param[out] e_source
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_source(EN_API_SOURCE_INPUT e_source);

/** 
@brief 获取酒店模式下的声音模式
@param[out] pe_snd_mode
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_sound_mode(EN_TOS_HOTEL_SOUND_MODE *pe_snd_mode);

/** 
@brief 设置酒店模式下的声音模式
@param[in] e_snd_mode
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_sound_mode(EN_TOS_HOTEL_SOUND_MODE e_snd_mode);

/** 
@brief 获取酒店模式下的图效模式
@param[out] pe_pic_mode
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_picture_mode(EN_TOS_HOTEL_PICTURE_MODE *pe_pic_mode);

/** 
@brief 设置酒店模式下的音量以及最大音量
@param[in] e_pic_mode
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_picture_mode(EN_TOS_HOTEL_PICTURE_MODE e_pic_mode);

/** 
@brief 酒店模式下获取酒店模式/Auto set功能/喜爱节目列表/开机logo功能的开关状态
@param[out] b_enable :fpi_true为打开;fpi_false为关闭
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_function_enable(EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool *b_enable);

/** 
@brief 酒店模式下设置酒店模式/Auto set功能/喜爱节目列表/开机Logo功能的开关状态
@param[in] b_enable :fpi_true为打开;fpi_false为关闭
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_function_enable(EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool b_enable);

/** 
@brief 获取酒店模式下的开机频道，配合tos_hotel_get_source()使用，以区分ATV/DTV等
@param[out] i4_channel 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_power_on_channel(int32_t *i4_channel);

/** 
@brief 设置酒店模式下的开机频道，配合tos_hotel_get_source()使用，以区分ATV/DTV等
@param[in] i4_channel 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_power_on_channel(int32_t i4_channel);

/** 
@brief 获取酒店模式下的上电模式
@param[out] *e_power_mode  POWERON_MODE_ON    上电开机      
                         POWERON_MODE_STB   上电待机
                         POWERON_MODE_LAST  上电采用上次关机的状态
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_power_on_mode(EN_TOS_HOTEL_POWER_ON_MODE *e_power_mode);

/** 
@brief 设置酒店模式下的上电模式
@param[in] e_power_mode  POWERON_MODE_ON    上电开机      
                         POWERON_MODE_STB   上电待机
                         POWERON_MODE_LAST  上电采用上次关机的状态
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_power_on_mode(EN_TOS_HOTEL_POWER_ON_MODE e_power_mode);


/** 
@brief 获取酒店模式下某些功能是否处于上锁状态
@param[in] e_type :
                typedef enum
                {
                    TYPE_LOCK_TUNER,
                    TYPE_LOCK_MENU,
                    TYPE_LOCK_USB,
                    TYPE_LOCK_SOURCE,
                    TYPE_LOCK_PANEL_KEY,
                    TYPE_LOCK_CHANNEL
                }EN_TOS_LOCK_TYPE;
@param[out] b_state 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_get_lock_state(EN_TOS_LOCK_TYPE e_type, fpi_bool *b_state);

/** 
@brief 酒店模式下锁定某些功能，不让用户操作
@param[in] e_type :
                typedef enum
                {
                    TYPE_LOCK_TUNER,
                    TYPE_LOCK_MENU,
                    TYPE_LOCK_USB,
                    TYPE_LOCK_SOURCE,
                    TYPE_LOCK_PANEL_KEY,
                    TYPE_LOCK_CHANNEL
                }EN_TOS_LOCK_TYPE;
@param[in] b_state 
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_hotel_set_lock_state(EN_TOS_LOCK_TYPE e_type, fpi_bool b_state);

#ifdef __cplusplus
}
#endif


#endif


