#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <string.h>        // for bzero
#include <errno.h>
#include <signal.h>
 #include <stdarg.h>

#include "tvh_debug_common_tcli.h"
#include "tvh_debug_server_log_tcli.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define HELLO_WORLD_SERVER_PORT    6667
#define SEND_MSG_TO_CLIENT_PORT    6668
#define LENGTH_OF_LISTEN_QUEUE 20


static int new_server_log_socket;
int server_socket_6669;
int server_socket;

int log_status = CLOSE_LOG;

char buffer[BUFFER_SIZE];
char buffer_send[BUFFER_SIZE];
char para_buf[ROW_NUM][BUFFER_SIZE_1024];

struct sockaddr_in client_addr;
static int log_accepted = 1;

void *tvh_debug_service_log_run_tcli(void *var) 
//int main(int argc, char **argv)
{
    //设置一个socket地址结构server_addr,代表服务器internet地址, 端口
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr)); //把一段内存区的内容全部设置为0
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(SEND_MSG_TO_CLIENT_PORT);
	printf("............tvh_debug_service_log_run11111......\n");
	
	signal(SIGPIPE, SIG_IGN);
	
    //创建用于internet的流协议(TCP)socket,用server_socket代表服务器socket
    server_socket = socket(PF_INET,SOCK_STREAM,0);
    if( server_socket < 0)
    {
        printf("Create Socket Failed!");
        exit(1);
    }
	{ 
	   int opt =1;
	   setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	}
     
    //把socket和socket地址结构联系起来
    if( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1)
    {
        printf("Server Bind Port : %d Failed!", HELLO_WORLD_SERVER_PORT); 
        exit(1);
    }
 
    //server_socket用于监听
    if ( listen(server_socket, LENGTH_OF_LISTEN_QUEUE) == -1)
    {
        printf("Server Listen Failed!"); 
        exit(1);
    }
	
	printf("server is listening ......\n");
	new_server_log_socket = -1;
    while (1) //服务器端要一直运行
    {
        //定义客户端的socket地址结构client_addr
        //struct sockaddr_in client_addr;
        socklen_t length = sizeof(client_addr);
 
        //接受一个到server_socket代表的socket的一个连接
        //如果没有连接请求,就等待到有连接请求--这是accept函数的特性
        //accept函数返回一个新的socket,这个socket(new_server_log_socket)用于同连接到的客户的通信
        //new_server_socket代表了服务器和客户端之间的一个通信通道
        //accept函数把连接到的客户端信息填写到客户端的socket地址结构client_addr中
        new_server_log_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
		
		printf("new_server_log_socket = %d\n", new_server_log_socket);
        if ( new_server_log_socket < 0)
        {
            printf("Server Accept Failed!\n");
            continue;
        }

		log_accepted = 1;
		
       // setsockopt(server_socket,SOL_SOCKET,SO_SNDBUF,buffer,sizeof(int));
		int port = ntohs(client_addr.sin_port);
		printf("port2: %d\n", port);

		while(log_accepted == 1)
		{
			sleep(1);
		}
	
		close(new_server_log_socket);
        //关闭与客户端的连接
       // close(new_server_log_socket);
    }
    //关闭监听用的socket
    close(server_socket);
    return 0;
}

/**
*发送命令结果消息给客户端
*/
int send_log_msg(const char *buf, int len)
{
//	printf("enter send_log_msg1 ... len = %d\n", len);
	
	if (log_status == CLOSE_LOG)
	{
		return -1;
	}
	
	if (new_server_log_socket < 0)
	{
		printf("client is not connected\n");
		return -1;
	}
	int i = 0; 
	for (i = 0; i < len; i++)
	{
		printf("%c", buf[i]);
	}
	
//	printf("\n");
	
	int bytes_send = 0;
	
	bytes_send = send(new_server_log_socket,buf,len,MSG_NOSIGNAL);
	if (bytes_send <= 0)
	{
		printf("Server log send Data Failed! r: %s\n", strerror(errno));
		if (strcmp("Broken pipe", strerror(errno)) == 0)
		{
			/*
			close(new_server_log_socket);
			socklen_t length = sizeof(client_addr);
			new_server_log_socket = -1;
			new_server_log_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
			*/
			log_accepted = 0;
		}
	}
	else 
	{
	//	printf("bytes_send = %d", bytes_send);
	}
	return 0;
}

void set_socket_accept_flag(int flag)
{
	log_status = flag;
}


void tprint(const char *str,...)
{
	 va_list list; 
	 va_start(list,str); 
	 char  sprint_buf[1024];
	 
	 vsnprintf(sprint_buf, sizeof(sprint_buf),str, list);
	 
	 va_end(list); 
	 printf("test_print sprint_buf: %s\n", sprint_buf);
	 send_log_msg(sprint_buf, strlen(sprint_buf));
	//send_msg_to_q(sprint_buf);
} 