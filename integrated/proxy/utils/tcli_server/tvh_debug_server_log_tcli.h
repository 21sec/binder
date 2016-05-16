#ifndef _TVH_DEBUG_SERVER_LOG_H_
#define _TVH_DEBUG_SERVER_LOG_H_

#include "fpi_error_code.h"

#define OPEND_LOG 1
#define CLOSE_LOG 0
int send_log_msg(const char *buf, int len);

void set_socket_accept_flag(int flag);

void tprint(const char *str,...);

//fpi_error tvh_debug_register_fun(const char *type,const char *model, const char *content, p_callback fun) ;
void *tvh_debug_service_log_run_tcli(void *var) ;
#endif // _TVH_DEBUG_SERVER_LOG_H_