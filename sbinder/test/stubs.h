#ifndef __BINDER_STUB_H__
#define __BINDER_STUB_H__

//stubs for binder test

#include <stdarg.h>

extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
/*
void clog_printf(const char* tag,int level,const char* format,...) {
    char buf[1024];
	
    va_list ap;
    va_start(ap, format);
	vsnprintf(buf,sizeof(buf),format,ap);
    va_end(ap);

#ifdef NDK_COMPILING
	__android_log_print(7,"sitatvservice","%s",buf);
#else
	printf("%s",buf);
#endif
}
*/
void tos_tcli_printf(const char* fmt,...) {
}


#endif

