/**@defgroup tos_mp_web_audio.h
@{

@brief 
*/

#ifndef __TOS_MP_WEB_AUDIO_H__
#define __TOS_MP_WEB_AUDIO_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 对传入的音频数据进行解码

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] buffer 音频数据首地址.
@param[in] buffer_size 音频数据长度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
int tos_mp_audio_decode(unsigned char* buffer, uint32_t buffer_size);

/**
@brief 初始化mp_audio模块

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_audio_init();

/**
@brief 反初始化mp_audio模块

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_audio_uninit();

/**
@brief 播放指定的数据

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_audio_play(int decoder_id);

/**
@brief 停止播放

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_audio_stop();

#ifdef __cplusplus
}
#endif
/** @} */
#endif
