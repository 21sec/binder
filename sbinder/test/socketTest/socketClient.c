#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define UNIX_DOMAIN "/tmp/UNIX.domain"
#define BUFSIZE (1024*10)


long getCurrentTime()
{
	struct timespec times;
	clock_gettime(CLOCK_MONOTONIC, &times); 
    return times.tv_sec * 1000 + times.tv_nsec / 1000000;  

}


int main(int argc,char** argv)
{

    if (argc <2){
        printf("client error: arg must >2\n");
	return -1;
    }

    int count = atoi(argv[1]);
    printf("client count = %d\n",count);

    int connect_fd;
    int ret;
    char rwc_buf[BUFSIZE];
    int i;
    static struct sockaddr_un srv_addr;
    //creat unix socket
    connect_fd=socket(PF_UNIX,SOCK_STREAM,0);
    if(connect_fd<0)
    {
	printf("client error: socket fd<0\n");
        return 1;
    }
    srv_addr.sun_family=AF_UNIX;
    strcpy(srv_addr.sun_path,UNIX_DOMAIN);
    //connect server
    for(i=0;i<BUFSIZE;i++) {
    	rwc_buf[i] = 'a';
    }
    int n = 0;
    ret=connect(connect_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));
    if(ret==-1)
    {
   	printf("client error: socket connect ret error\n");
        close(connect_fd);
        return 1;
    }
    memset(rwc_buf,0,BUFSIZE);

    long time1 = getCurrentTime();
    for(i=0;i<count;i++){
        write(connect_fd,rwc_buf,sizeof(rwc_buf));
	read(connect_fd,&n,sizeof(int));
    }
    printf("client total time is %ld\n",getCurrentTime()- time1);
    close(connect_fd);
    printf("client end\n");
    return 0;
}


