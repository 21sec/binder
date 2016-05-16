#include "tos_tcli.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sbinder/sbinderServ.h"
#include <proxy.h>
#include <pthread.h>
#include "tvh_debug_server_tcli.h"
#include "tvh_debug_server_log_tcli.h"

extern void debug_add_testcase_init();
static void initTest()
{
	debug_add_testcase_init();
}

int main(int argc,char* argv[]) {
	proxy_init();
	initTest();
	
	pthread_t thd_debug_server, thd_debug_server_log;
	printf("create thd_debug_server_log thread\n");
	int ret = pthread_create(&thd_debug_server_log, NULL, tvh_debug_service_log_run_tcli, NULL);
	if (ret != 0)
	{
		printf("create thread:debug_service_log_run failed");
		exit(-1);
	}

	printf("create thd_debug_server thread\n");
	ret = pthread_create(&thd_debug_server, NULL, tvh_debug_service_run_tcli, NULL);
	if (ret != 0)
	{
		printf("create thread: thd_debug_server failed");
		exit(-1);
	}
 
	pthread_join(thd_debug_server, NULL);
	pthread_join(thd_debug_server_log, NULL);

	return 0;
}




