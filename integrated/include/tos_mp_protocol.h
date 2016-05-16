/**@defgroup tos_mp_protocol
@{

@brief 媒体播放器协议模块,用于自定义媒体源

@history 2014/12/17 初稿
*/

#ifndef __TOS_MP_PROTOCOL_H__
#define __TOS_MP_PROTOCOL_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"

#ifdef __cplusplus
extern "C" {
#endif


#define FPI_MP_PROTOCOL_ERROR_NOERROR       0   ///< 成功
#define FPI_MP_PROTOCOL_ERROR_UNKNOWN       -1  ///< 未知错误
#define FPI_MP_PROTOCOL_ERROR_NOSUPPORT     -2  ///< 不支持
#define FPI_MP_PROTOCOL_ERROR_TIMEOUT       -3  ///< 超时
#define FPI_MP_PROTOCOL_ERROR_EAGAIN        -4  ///< 暂时没有数据


/**
@brief 定义URL协议结构
*/
typedef struct {
    int size;           ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_URLProtocol_S)
    const char *name;   ///< 协议头的字符串,建议指向一个字符串常量地址,以便指针保持有效
    int     (*url_open)(const char *url, void *userData);    ///< 连接数据源;失败返回错误码
    int     (*url_read)(unsigned char *buf, int size, void *userData);      ///< 读取数据,在短时间内(100ms)必须立即返回;失败返回错误码
    int64_t (*url_seek)(int64_t offset, int whence, void *userData);   ///< 定位到指定时间点;成功返回相对于开始位置的偏移时间点;失败返回错误码
    int     (*url_close)(void *userData);   ///< 关闭数据源;失败返回错误码
    void *userData;     ///< 用户数据
} FPI_MP_URLProtocol_S;


/**
@brief 注册FPI_MP_URLProtocol_S协议

@param[in] protocol FPI_MP_URLProtocol_S结构体地址
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_register_protocol(FPI_MP_URLProtocol_S *protocol);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
