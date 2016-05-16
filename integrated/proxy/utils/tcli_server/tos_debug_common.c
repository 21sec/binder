#include "tos_tcli.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sbinder/sbinderServ.h"
#include <proxy.h>
#include <pthread.h>
#include "tvh_debug_server_tcli.h"
#include "tvh_debug_server_log_tcli.h"

fpi_error tos_test_start(char *addr)
{
	if( addr == NULL )return FPI_ERROR_FAIL;


	
	pthread_t thd_debug_server, thd_debug_server_log;
	printf("create thd_debug_server_log thread\n");
	int ret = pthread_create(&thd_debug_server_log, NULL, tvh_debug_service_log_run_tcli, NULL);
	if (ret != 0)
	{
		printf("create thread:debug_service_log_run failed");
		
	}

	printf("create thd_debug_server thread\n");
	ret = pthread_create(&thd_debug_server, NULL, tvh_debug_service_run_tcli, NULL);
	if (ret != 0)
	{
		printf("create thread: thd_debug_server failed");
		
	}


	return FPI_ERROR_SUCCESS;
}




