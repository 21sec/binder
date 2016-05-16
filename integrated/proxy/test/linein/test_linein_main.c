#include <stdio.h>
#include <sbinder/sbinderServ.h>
#include <unistd.h>
#include "tos_input_source.h"
#include "tos_log.h"
#include "tos_message.h"
#include "tos_notify.h"

static int  message_of_tos_process_callback(st_msg_notify_t *msgs,void* userdata) {
	    int msg = 0,p1 = 0, p2 = 0;
    msg = msgs->msg;
    p1 = msgs->data1;
    p2 = msgs->data2;

    if( msg == CMD_UI_NOTIFY_ERROR_CODE )
    {
    	printf(">>>>>>>>>>>>>>>>>[**PID=%d, ERRCODE=%d]\n",p1,p2);
    }
	return 0;
}
int main(int arg, char** argv) {

	if (arg <2){
		printf("must set param one: ./xxxx  x\n");
		return 0;
	}

	int count = atoi(argv[1]);

	printf("main linein = %d\n", count);
	
   // int result = -1;
    sbinder_start( );
    
    tos_msg_add_callback(message_of_tos_process_callback,	NULL);

	 while(1)
	 {
	 	int source;
	 	printf("input the source:");
	 	scanf("%d", &source );	
	 	tos_source_set_input((EN_API_SOURCE_INPUT)source   ,EN_ACT_EXEC_SAVE );
	 	
	 }

	
	
    //return sbinder_serv();
    return 0;
}
