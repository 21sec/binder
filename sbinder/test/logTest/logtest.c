#include <stdio.h>
#include <fcntl.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include "log/log.h"

#define BUFSIZE 256

long getCurrentTime()  
{  
	struct timespec times;
	clock_gettime(CLOCK_MONOTONIC, &times); 
    return times.tv_sec * 1000 + times.tv_nsec / 1000000;  

}


int main(int argc, char** argv)
{
    if (argc <2){
	printf("argc must >2\n");
	return 0;
    }
    
    char* pathname = argv[1];

    printf("pathname = %s\n",pathname);

    int y=0;
    char buf[BUFSIZE];
    
    /* This test is for printf */
    long tm0 = getCurrentTime();
    for(y=0 ;y<10000;y ++){
        printf("main---------ddddddddddddddddd-------------\n");
    }
    printf("total printf time = %ld ms\n",(getCurrentTime()-tm0));
    


    /* This test is for calculate time for alog */
    long tm = getCurrentTime();
    for(y=0 ;y<10000;y ++){
        ALOGI("main---------ddddddddddddddddd-------------\n");
    }
    printf("total alog time = %ld ms\n",(getCurrentTime()-tm));
    
    /* This is test for open file ,write in 10000 char, calculate tiem */
    long ltm = getCurrentTime();
    int fdd = open(pathname,O_RDWR |O_APPEND | O_CREAT);

    if (fdd < 0) {
        printf("fdd <0\n");
        return 0;
    }

    strncpy(buf,"main---------ddddddddddddddddd-------------\n",sizeof(buf));
    int ii = 0;
    for (ii =0; ii<10000;ii ++){
    	write(fdd,buf,sizeof(buf));
    }
    close(fdd);
    printf("total write time = %ld ms\n",(getCurrentTime()-ltm));

    /* This test is for multi-process write file with append */

    int fd = open(pathname,O_RDWR |O_APPEND | O_CREAT);
	
    if (fd < 0) {
	printf("fd <0\n");
        return 0;
    }

    int fd1 = dup(fd);
    int fd2 = dup(fd);
    int fd3 = dup(fd);
    int fd4 = dup(fd);

    
    int count = 100;
    
    int pid = fork();
    if(pid <0){
	printf("error pid<0\n");
        return 0;
    }else if (pid == 0){//son
        int spid = fork();
        if (spid <0){
	    printf("error fpid\n");
	    return 0 ;
	}else if (spid == 0){//son
			char temp = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
            memcpy(buf,temp,sizeof(temp));
	    int i = 0;
	    for(i =0;i<count ;i++){
    	        write(fd,buf,sizeof(buf));
	    }
            close(fd);
	}else {//father
    	    int j = 0;
			char temp = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n";
	    for(j =0;j<count ;j++){
                memcpy(buf,temp,sizeof(temp));
    	        write(fd1,buf,sizeof(buf));
	    }
            close(fd1);
	}
    }else{//father
        int ffpid = fork();
        if (ffpid <0){
	    printf("error fpid\n");
	    return 0 ;
	}else if (ffpid == 0){ //son
	    int n = 0;
		char temp = "ccccccccccccccccccccccccccccccccccccc\n";
	    for(n =0;n<count ;n++){
                memcpy(buf,temp,sizeof(temp));
    	        write(fd2,buf,sizeof(buf));
	    }
            close(fd2);
	}else {//father
            int fffpid = fork();
            if (fffpid <0){
	        printf("error fpid\n");
	        return 0 ;
	    }else if (fffpid == 0){ //son
		int m = 0;
	    	for(m =0;m<count ;m++){
                    strncpy(buf,"dddddddddddddddddddddddddddddddddddddddd\n",sizeof(buf));
    	            write(fd3,buf,sizeof(buf));
		}
                close(fd3);
	    }else {//father
                int o = 0;
	    	for(o =0;o<count ;o++){
                    strncpy(buf,"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n",sizeof(buf));
    	            write(fd4,buf,sizeof(buf));
		}
                close(fd4);
	    }
	}
    }




    return 0;
}
