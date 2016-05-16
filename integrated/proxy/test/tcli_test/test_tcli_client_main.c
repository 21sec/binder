#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include <proxy.h>
#include "os.h"
#include "fpi_debug_helper.h"
#include "tos_dm_channel.h"

int main(int arg, char** argv) {

	printf("-------tcli client test start------\n");
	
	proxy_init();
	
	while (1)
	{
		sleep(60);
	}
	
  return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
