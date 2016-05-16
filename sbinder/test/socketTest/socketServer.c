#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define UNIX_DOMAIN "/tmp/UNIX.domain"

#define BUFSIZE (1024*10)
int main(int argc,char** argv)
{
    if (argc<2){
	printf("server error: arg must >2\n");
	return -1;
    }
    int count = atoi(argv[1]);

    printf("server count = %d\n",count);
    //socklen_t clt_addr_len;
    int listen_fd;
    int com_fd;
    int ret;
    int i;
    static char rws_buf[BUFSIZE];
    socklen_t len;
    struct sockaddr_un clt_addr;
    struct sockaddr_un srv_addr;
    listen_fd=socket(PF_UNIX,SOCK_STREAM,0);
    if(listen_fd<0)
    {
        printf("server error:cannot create communication socket\n");
        return 1;
    }
    //set server addr_param
    srv_addr.sun_family=AF_UNIX;
    strncpy(srv_addr.sun_path,UNIX_DOMAIN,sizeof(srv_addr.sun_path)-1);
    unlink(UNIX_DOMAIN);
    //bind sockfd & addr
    ret=bind(listen_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));
    if(ret==-1)
    {
        printf("server error:cannot bind server socket\n");
        close(listen_fd);
        unlink(UNIX_DOMAIN);
        return 1;
    }
    //listen sockfd
    ret=listen(listen_fd,1);
    if(ret==-1)
    {
        printf("server error:cannot listen the client connect request\n");
        close(listen_fd);
        unlink(UNIX_DOMAIN);
        return 1;
    }
    //have connect request use accept
    len=(socklen_t)sizeof(clt_addr);
    static int n = 11;
    com_fd=accept(listen_fd,(struct sockaddr*)&clt_addr,&len);
    if(com_fd<0)
    {
        printf("server error:cannot accept client connect request\n");
        close(listen_fd);
        unlink(UNIX_DOMAIN);
        return 1;
    }
        //read and printf sent client info
    printf("\n=server====info=====\n");
    for(i=0;i<count;i++){
        memset(rws_buf,0,BUFSIZE) ;
        read(com_fd,rws_buf,BUFSIZE);
	write(com_fd,&n,sizeof(int));
    }
    printf("server close com_fd\n");
    close(com_fd);
    printf("server close listen_fd\n");
    close(listen_fd);
    printf("server unlink \n");
    unlink(UNIX_DOMAIN);
    printf("server end\n");
    return 0;
}


