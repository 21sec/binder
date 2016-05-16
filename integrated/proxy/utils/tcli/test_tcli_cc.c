#include <stdio.h>
#include "tos_tcli.h"
#include <string.h>
#include <sbinder/sbinderServ.h>
#include <proxy.h>

static void run_my_cmd(int i,char* s) {
    tos_tcli_printf("i=%d\n",i);
    tos_tcli_printf("s=%s\n",s);
}
TOS_TCLI_COMMAND(mycmdclient,"my command client","long help\n of my command\n","is",run_my_cmd);

static int s_myvaluec = 0;
TOS_TCLI_INTERGER(s_myvaluec,"short help of s_currentValue","long help\nof s_currentValue");


int main(  ) {
    printf("tcli client test\n");
	proxy_init();
	while(1);
	return 0;
}