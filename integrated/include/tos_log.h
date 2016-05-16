/**@defgroup ��־���ģ��
@{

@brief ������־���

������,��������κμ������,ȫ�����
֧�ֿ���̵���
����android logcat

@version 1.0.0 2015/09/30 ����
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
#define TOSLOG_TAG __FILE__   ///< Ĭ��ģ������,������C/CPP�ļ���ͷ��(���ñ�ͷ�ļ�ǰ)����,����ģ�������Զ�������Ϊ�ļ���.
#endif


/**
@brief id Ϊclient�˵Ĵ��룬һ���ΪPID ��code��Ӧ�˴�����
*/
void tos_log_set_errcode(int id,unsigned int code);


#define TOSLOGV(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_VERBOSE,  __VA_ARGS__))
#define TOSLOGD(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_DEBUG,    __VA_ARGS__))
#define TOSLOGI(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_INFO,     __VA_ARGS__))
#define TOSLOGW(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_WARN,     __VA_ARGS__))
#define TOSLOGE(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,    __VA_ARGS__))
#define TOSLOGF(...)   (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_FATAL,    __VA_ARGS__))

/**
@brief ����������WARN��Ϣ��ӡ����,�������к������ش���ǰ�����ñ�ϵ�нӿ�����������,�Է����ն˹������Щ������м�غ�Ԥ��.
*/
#define TOSLOGW_WITHCODE(errCode,fmt,...)  (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_WARN,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__))  

/**
@brief ����������ERROR��Ϣ��ӡ����,�������к������ش���ǰ�����ñ�ϵ�нӿ�����������,�Է����ն˹������Щ������м�غ�Ԥ��.
*/
#define TOSLOGE_WITHCODE(errCode,fmt,...)  {tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__);tos_log_set_errcode((int)getpid(),(errCode));}  

/**
@brief ����������FATAL��Ϣ��ӡ����,�������к������ش���ǰ�����ñ�ϵ�нӿ�����������,�Է����ն˹������Щ������м�غ�Ԥ��.
*/
#define TOSLOGF_WITHCODE(errCode,fmt,...)  (tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_FATAL,"<ERR:%x>"#fmt,(errCode),##__VA_ARGS__))  

#define TOSLOG_ASSERT(expr, fmt,...)  \
    if (!(expr)) { \
        tos_log_printf(TOSLOG_TAG,TOSLOG_LOGLVL_ERROR,"<ERR:%d>FATAL: Assertion FAILED in '%s', line %d, func %s ('%s'): "#fmt"\n", \
               -2,__FILE__, __LINE__,__FUNCTION__, #expr, ##__VA_ARGS__);  \
    }do{}while(0)
    

/**
@brief ������־�������ö��,��־��������Խ��,��ʾ��Ӧ����־Խ��Ҫ
*/
typedef enum TOSLOG_LOGLEVEL{
	TOSLOG_LOGLVL_UNKNOWN,
    TOSLOG_LOGLVL_VERBOSE,            ///< ��ϸ��ӡ����,һ����˵ģ���ڲ������������ϸ�������̵���־ʹ�ô˼���,�����ģ��Ĵ�����ݵ�.
    TOSLOG_LOGLVL_DEBUG,              ///< ���Դ�ӡ����,һ����˵ģ���ڲ������������Ҫ�������̵���־ʹ�ô˼���,�����ģ�����е�ĳ��������,ĳ�д����.
    TOSLOG_LOGLVL_INFO,               ///< ��Ϣ��ӡ����,һ����˵Ϊģ��ʹ�����ṩģ������״̬����־ʹ�ô˼���,��XXģ�������ɹ���.
    TOSLOG_LOGLVL_WARN,               ///< �����ӡ����,һ����˵������ʾģ��ʹ���߷����ɻָ����ڲ�����,����������Ƿ���.
    TOSLOG_LOGLVL_ERROR,              ///< �����ӡ����,һ����˵������ʾģ��ʹ���߷������ɻָ����ڲ�����,ģ�����³�ʼ��ǰģ�齫����ʹ��,��������������,�����˳������.
    TOSLOG_LOGLVL_FATAL,              ///< ���������ӡ����,һ����˵������ʾģ��ʹ���߷������ɻָ����ڲ����ش���,����˼������־����������������,�����˳������.
    TOSLOG_LOGLVL_SILENT
} TOSLOG_LOGLEVEL;


//lihui02@tcl.com	let gcc check format like printf
#if defined(__GNUC__) && !defined(__printflike)
#define __printflike(x, y) __attribute__((__format__(printf, x, y)))
#endif


/**
@brief Ϊָ��ģ��,��ָ����־�������һ����־

@code ���鰴���·�ʽ���ô˽ӿ�.
tos_log_printf("myModuleNmae",TOSLOG_LOGLVL_INFO,"Hello, I am %s\n",sMyName);
@endcode

@param[in] tag �����־��tag,һ����������־��ģ�����ģ��
@param[in] level �����־�ļ���
@param[in] format ��־����,֧��printf�е�%d�Ȳ���
*/
void tos_log_printf(const char* tag,int level,const char* format,...) __printflike(3,4);

void tos_log_printfs(const char* tag,const char* tag2,int level,const char* format,...)  __printflike(4,5);

void clog_printf(const char* tag,int level,const char* format,...)  __printflike(3,4);

/**
@brief tos_log_printf��vprintf�汾,���ڷ�װ������ģ�����־�������.

@see vprintf
*/
void tos_log_vprintf(const char* tag,int level,const char* format,va_list arg)  __printflike(3,0);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
