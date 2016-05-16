#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"
#include "fpi_debug_helper.h"
#include "tos_dm_channel.h"

int main(int arg, char** argv) {

	if (arg <2){
		printf("must set param one: ./xxxx  x\n");
		return 0;
	}
	
	//int channelNumber = atoi(argv[1]);
	//uint32_t channelId = 0;
	uint16_t pstChannelNumber = 0;
	
	//printf("main linein = %d\n", channelNumber);
	
   // int result = -1;
    sbinder_start( );
	
	tos_channel_get_program_number_by_same_lcn(&pstChannelNumber);
	
	printf("...........pstChannelNumber = %d \n\n", pstChannelNumber);
	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
