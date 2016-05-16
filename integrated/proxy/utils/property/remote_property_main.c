#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include "tos_property.h"
#include <pthread.h>
#include <unistd.h>
#include "os.h"
#include "fpi_debug_helper.h"

long getCurrentTime()
{
    struct timespec times;
    clock_gettime(CLOCK_MONOTONIC, &times);
    return times.tv_sec * 1000 + times.tv_nsec / 1000000;
}

int main(int arg, char** argv) {

	if (arg <3){
		printf("must set param one: ./PROPERTYCLIENT  times key value\n");
		return 0;
	}

	int count = atoi(argv[1]);

	printf("main count = %d\n", count);
	
    int result = -1;

    sbinder_start();

    const char* key = argv[2];
    const char* value = argv[3];

	int i = 0;

	long time1 = getCurrentTime();

	
	for(;i<count;i++){
    		result = tos_property_set(key,value);
	}
	long time2 = getCurrentTime();

	
    printf("main setproperty ljtime ==== = %ld\n",(time2 - time1));
	
    printf("tos_property_set result = %d\n",result);
    
    const char* ret = tos_property_get(key,value);

    
    printf("tos_property_get value ========= %s\n",ret);
    
    result = tos_property_remove(key);
    
    printf("tos_property_remove result = %d\n",result);
    
    result = tos_property_reset(); //be cationed to call, all tos property will reset
    
	printf("tos_property_reset result = %d\n",result);
	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
