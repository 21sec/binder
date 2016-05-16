#include "tos_tcli.h"
#include <stdio.h>
#include <string.h>
#include "sbinder/sbinderServ.h"
#include <proxy.h>

static void my_output(const char* prompt,void* userdata) {
    printf("%s",prompt);
}


static int _endwith(const char *str, const char *substr) {
    int nsub_len = strlen (substr);
    int nlen = strlen (str);

    if (nsub_len > nlen)
    {
        return 0;
    }

    if (memcmp (str + nlen - nsub_len, substr, nsub_len) == 0)
    {
        return 1;
    }
    return 0;
}

int main(int argc,char* argv[]) {
	proxy_init();
	
	//printf("tcli begin \n");
    if(_endwith(argv[0],"/tcli") || strcmp(argv[0],"tcli") == 0) {
		//printf("tcli equal tcli \n");
        return tos_tcli_executeByargs(argc-1,(const char**)argv+1,my_output,NULL);
    }
    else {
		//printf("tcli uuuuuuuuuuuuuuuuuequal tcli \n");
        return tos_tcli_executeByargs(argc,(const char**)argv,my_output,NULL);
    }
}


