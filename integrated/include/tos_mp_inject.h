/**@defgroup tos_mp_inject
@{

@brief 基于tos_mp_prorocol封装了层注入播放的应用接口

@code 常见使用场景示例
//开始播放
tos_mp_set_datasource(x,"blob:http://xxx");//blob:http://是自定义的一个协议头
tos_mp_prepare(x);
tos_mp_play(x);

tos_mp_send_buffer(x, buffer, length);

//暂停播放器
tos_mp_pause(x);

//停止
tos_mp_stop(x);

//释放
tos_mp_stop(x);
tos_mp_release(x);
@endcode

@history 2015/1/12 初稿
*/

#ifndef __TOS_MP_INJECT_H__
#define __TOS_MP_INJECT_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"
#include "tos_mp_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 定义Buffer Command枚举
*/
typedef enum {
    EN_FPI_MP_BUFFER_CMD_EOS,              ///< EOS
    EN_FPI_MP_BUFFER_CMD_UNKNOW            ///< UNKNOW 
}FPI_MP_BUFFER_CMD_E;

/**
@brief 向指定player注入音视频数据

@param[in] srcId  Source Buffer ID.
@param[in] buffer 要注入的音视频数据
@param[in] length 要注入的音视频数据的长度
@param[in] timeOffset 要注入的音视频数据的时间偏移
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_send_buffer(unsigned int srcId, const char *buffer, int length, unsigned long timeOffset);

/**
@brief 清空向指定player注入的音视频数据

@param[in] srcId  Source Buffer ID.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_clear_buffer(unsigned int srcId);

/**
@brief 创建新的source buffer

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 成功返回source buffer ID;失败返回0
*/
int tos_mp_create_buffer(unsigned int playerId);

/**
@brief 创建新的source buffer

@param[in] srcId  Source Buffer ID.
@param[in] cmd  command 类型.
@return 成功返回0;失败返回-1
*/
fpi_error tos_mp_buffer_command(unsigned int srcId, FPI_MP_BUFFER_CMD_E cmd);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
