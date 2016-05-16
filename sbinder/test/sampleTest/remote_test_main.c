#include <stdio.h>

#include "sample_module.h"
#include "servicemanager/service_manager.h"
#include "sbinder/sbinderServ.h"

#include "../stubs.h"

#if defined(BINDER_SERVICE)

#include "remote_sample_module.h"
int main(int arg, char** argv) {
    ServiceManager_start();
    remote_sample_module_service_add();
    return sbinder_serv();
}

#elif defined(BINDER_CLIENT)
#include <time.h>
#include <stdlib.h>

long getCurrentTime()  
{  
	struct timespec times;
	clock_gettime(CLOCK_MONOTONIC, &times); 
    return times.tv_sec * 1000 + times.tv_nsec / 1000000;  
}

static void testint1(void) {
    int in = 1;
    int pin = 2;
    int pout = 3;
    int pinout = 4;

    sample_int_prt_1(in,&pin,&pout,&pinout);
    
    //printf("test sample_int_prt_1 in=%d,pin=%d,pout=%d,pinout=%d,ret=%d\n",in,pin,pout,pinout,ret);
}

/*static void testint16l(void) {

	uint16_t in = 1;
	uint16_t pin[2] = {2,3};
	uint16_t pout[2] = {4,5};
	uint16_t pinout[2] = {5,6};
	
	uint16_t ret = sample_uint16_t_prt_len(in,pin,pout,pinout,2);
	
	printf("test sample_uint16_t_prt_len in=%d,pin=%d,%d,pout=%d,%d,pinout=%d,%d ret=%d\n",in,pin[0],pin[1],pout[0],pout[1],pinout[0],pinout[1],ret);
	
}*/
int main(int arg, char** argv) {


	if (arg <2){
		printf("must set param one: ./xxxx  1000\n");
		return 0;
	}


	
	int count = atoi(argv[1]);
	printf("main count 1 = %d\n", count);
	
    sbinder_start();

	long cur = getCurrentTime();
	int i;
	for(i=0;i<count;i++) {
    	testint1();
  	}

	printf ("sitaout total time = %ld\n",getCurrentTime() - cur);
    

    return 0;
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
