#ifndef _TVH_DEBUG_TEST_SERVER_
#define _TVH_DEBUG_TEST_SERVER_

#include <stdio.h>
/**
*发送命令结果消息给客户端
*/
int send_msg(const char *buf, int len);
int parase_command_tcli(char *buf_command, int len, char *ret_buf, int *ret_len) ;
int decode_single_command_tcli(char *buf_com, int buf_len);
int decode_para_lists(char *para_list, int para_len);

void open_log();

void *tvh_debug_service_run_tcli(void *var) ;

//void print_log(char *);

#endif //_TVH_DEBUG_TEST_SERVER_