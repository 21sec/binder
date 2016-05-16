
#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"
#include "fpi_debug_helper.h"


#include "tos_input_source.h"
#include "tos_atv_scan.h"

int main(int arg, char** argv) {

	if (arg <3){
		printf("must set param one: ./xxxx  x\n");
		return 0;
	}

    int var= atoi(argv[1]);
    int var2= atoi(argv[2]);

    printf("@@ var::%d\n",var);
	
   // int result = -1;
    sbinder_start( );
        
	
    switch(var)
    {
        case 0:
            printf("hello\n");
            break;
        case 1:
            printf("run linein change\n");
            tos_source_set_input((EN_API_SOURCE_INPUT)var2   ,EN_ACT_EXEC_SAVE );
            break;
        case 2:
            printf("run tos atv autoscan\n");
             tos_atv_start_auto_scan();
            break;
        case 3:
            printf("run tos atv manualscan\n");
            tos_atv_start_manual_scan(50,200);
            break;
        default:
            break;
    }


	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif

