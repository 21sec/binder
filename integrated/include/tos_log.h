/**@defgroup 日志输出模块
@{

@brief 用于日志输出

高性能,无需进行任何级别控制,全部输出
支持跨进程调用
来自android logcat

@version 1.0.0 2015/09/30 初稿
*/
#ifndef __TOS_LOG_H__
#define __TOS_LOG_H__

#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TOSLOG_TAG
#define TOSLOG_TAG __FILE__   ///< 默认模块名宏,建议在C/CPP文件的头部(引用本头文件前)定义,否则模块名会自动被定义为文件名.
#endif


/**
@brief id 为client端的代码，一般可为PID ，code对应了错误码
*/
void tos_log_set_errcode(int id,unsigned int code);


#define TOSLOGV(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_VERBOSE,  __VA_ARGS__))
#define TOSLOGD(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_DEBUG,    __VA_ARGS__))
#define TOSLOGI(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_INFO,     __VA_ARGS__))
#define TOSLOGW(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_WARN,     __VA_ARGS__))
#define TOSLOGE(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,    __VA_ARGS__))
#define TOSLOGF(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_FATAL,    __VA_ARGS__))

/**
@brief 带错误代码的WARN信息打印函数,建议所有函数返回错误前都调用本系列接口输出错误代码,以方便终端管理对这些错误进行监控和预警.
*/
#define TOSLOGW_WITHCODE(errCode,fmt,...)  (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_WARN,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__))  

/**
@brief 带错误代码的ERROR信息打印函数,建议所有函数返回错误前都调用本系列接口输出错误代码,以方便终端管理对这些错误进行监控和预警.
*/
#define TOSLOGE_WITHCODE(errCode,fmt,...)  {tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__);tos_log_set_errcode((int)getpid(),(errCode));}  

/**
@brief 带错误代码的FATAL信息打印函数,建议所有函数返回错误前都调用本系列接口输出错误代码,以方便终端管理对这些错误进行监控和预警.
*/
#define TOSLOGF_WITHCODE(errCode,fmt,...)  (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_FATAL,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__))  

#define TOSLOG_ASSERT(expr, fmt,...)  \
    if (!(expr)) { \
        tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,"<ERR:%d>FATAL: Assertion FAILED in '%s', line %d, func %s ('%s'): "#fmt"\n", \
               -2,__FILE__, __LINE__,__FUNCTION__, #expr, ##__VA_ARGS__);  \
    }do{}while(0)
    

/**
@brief 定义日志输出级别枚举,日志级别数字越大,表示对应的日志越重要
*/
typedef enum TOSLOG_LOGLEVEL{
	TOSLOG_LOGLVL_UNKNOWN,
    TOSLOG_LOGLVL_VERBOSE,            ///< 详细打印级别,一般来说模块内部描述软件的详细运行流程的日志使用此级别,如输出模块的大块数据等.
    TOSLOG_LOGLVL_DEBUG,              ///< 调试打印级别,一般来说模块内部描述软件的主要运行流程的日志使用此级别,如输出模块运行到某个流程中,某行代码等.
    TOSLOG_LOGLVL_INFO,               ///< 信息打印级别,一般来说为模块使用者提供模块运行状态的日志使用此级别,如XX模块启动成功等.
    TOSLOG_LOGLVL_WARN,               ///< 警告打印级别,一般来说用于提示模块使用者发生可恢复的内部错误,如输入参数非法等.
    TOSLOG_LOGLVL_ERROR,              ///< 错误打印级别,一般来说用于提示模块使用者发生不可恢复的内部错误,模块重新初始化前模块将不可使用,但不会引起死机,进程退出等情况.
    TOSLOG_LOGLVL_FATAL,              ///< 致命问题打印级别,一般来说用于提示模块使用者发生不可恢复的内部严重错误,输出此级别的日志后往往会引起死机,进程退出等情况.
    TOSLOG_LOGLVL_SILENT
} TOSLOG_LOGLEVEL;


//lihui02@tcl.com	let gcc check format like printf
#if defined(__GNUC__) && !defined(__printflike)
#define __printflike(x, y) __attribute__((__format__(printf, x, y)))
#endif


/**
@brief 为指定模块,以指定日志级别输出一条日志

@code 建议按以下方式调用此接口.
tos_log_printf("myModuleNmae",TOSLOG_LOGLVL_INFO,"Hello, I am %s\n",sMyName);
@endcode

@param[in] tag 输出日志的tag,一般代表输出日志的模块或子模块
@param[in] level 输出日志的级别
@param[in] format 日志内容,支持printf中的%d等参数
*/
void tos_log_printf(const char* tag,int level,const char* format,...) __printflike(3,4);

void tos_log_printfs(const char* tag,const char* tag2,int level,const char* format,...)  __printflike(4,5);

void clog_printf(const char* tag,int level,const char* format,...)  __printflike(3,4);

/**
@brief tos_log_printf的vprintf版本,用于封装第三方模块的日志输出函数.

@see vprintf
*/
void tos_log_vprintf(const char* tag,int level,const char* format,va_list arg)  __printflike(3,0);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
