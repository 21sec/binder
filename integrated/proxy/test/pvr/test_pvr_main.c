#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"
#include "fpi_debug_helper.h"
#include "tos_pvr.h"

int main(int arg, char** argv) {

    if (arg <2){
        printf("must set param one: ./xxxx  x\n");
        return 0;
    }

    int count = atoi(argv[1]);
    fpi_bool bExist=fpi_false;

    printf("main count = %d\n", count);
	
    sbinder_start( );

    tos_pvr_is_record_file_exist(NULL,&bExist);
    printf("tos_pvr_is_record_file_exist, bExist= %d\n", bExist);
	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
