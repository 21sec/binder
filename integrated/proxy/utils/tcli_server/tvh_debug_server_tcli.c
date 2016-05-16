#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <string.h>        // for bzero
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>

#include "tvh_debug_common_tcli.h"
#include "tvh_debug_server_tcli.h"
#include "tvh_debug_server_log_tcli.h"
#include "fpi_debug_helper.h"
#include "tos_tcli.h"
#include "fpi_log.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define HELLO_WORLD_SERVER_PORT    6667
#define LENGTH_OF_LISTEN_QUEUE 20


static int new_server_socket;
int server_socket_6669;

char buffer[BUFFER_SIZE];
char buffer_send[BUFFER_SIZE];
char para_buf[ROW_NUM][BUFFER_SIZE_128];
char fun_buf[FUN_ROW_NUM][BUFFER_SIZE_256];

struct timeval p_start_time;
struct timeval p_end_time;

tvh_route_para *g_tvh_route_para;
 
int arr_fun_maps_num;
// fpi_error tvh_debug_init_fun_map( void ) ;

#if 0
static void tcli_clog_callback(const char* tag,int level,const char* log,const char *filterString,void* userdata)
{	
//	if(tag != NULL && strcmp(tag,TAG_TEST_TCLI_LOG) == 0 && log != NULL)
    if(tag != NULL && log != NULL)
	{
		send_log_msg(log,strlen(log));
	}
}
#endif


static void log_send(const char* prompt,void* userdata) {
	
	if(prompt != NULL) {
		send_log_msg(prompt, strlen(prompt));
	}
	
}

static void help_cmd_send(const char* prompt,void* userdata) {
	if(prompt != NULL) {
		send_msg(prompt, strlen(prompt));
	}
}

static int tvh_debug_tcli_execute(const char* cmd,tos_tcli_onOutput out,void* userdata) {
	 printf("%s...\n",__FUNCTION__);
	 if(cmd == NULL) {
		 printf("%s cmd null\n",__FUNCTION__);
		 return 2;
	 }
 
	 char cmdcopy[TOS_TCLI_CMD_MAX_LEN];
	 strncpy(cmdcopy,cmd,TOS_TCLI_CMD_MAX_LEN);
	 cmdcopy[TOS_TCLI_CMD_MAX_LEN-1] = 0;
	 printf("%s cmd=[%s]\n",__FUNCTION__,cmdcopy);
 
	 int argc = 0;
	 const char* argv[16] = {NULL};
	 const char delim[] = " \t";
	 char *token;
	 
	 token = strtok(cmdcopy, delim);
	 while( token != NULL ) {
		 argv[argc++] = token;
 
		 token = strtok(NULL, delim);
	 }
 
	 int i;
	 for (i = 0; i < argc; i++)
	 {
		 printf("argv: %s\n", argv[i]);
	 }
 
	 return tos_tcli_executeByargs(argc,argv,out,userdata);
 }


 void *tvh_debug_service_run_tcli(void *var) 
//int main(int argc, char **argv)
{
    //设置一个socket地址结构server_addr,代表服务器internet地址, 端口
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr)); //把一段内存区的内容全部设置为0
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(HELLO_WORLD_SERVER_PORT);

	 printf("****debug_service_run 1111*******\n");

    //tvh_debug_init_fun_map( ) ;
    //创建用于internet的流协议(TCP)socket,用server_socket代表服务器socket
    int server_socket = socket(PF_INET,SOCK_STREAM,0);
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


	//TODO: use code in logcat.cpp to get all logs and send to win client instand
	//clog_addsavetriger("r:.*",tcli_clog_callback,NULL);
	
	printf("server is listening ......\n");
	
    while (1) //服务器端要一直运行
    {
        //定义客户端的socket地址结构client_addr
        struct sockaddr_in client_addr;
        socklen_t length = sizeof(client_addr);
 
        //接受一个到server_socket代表的socket的一个连接
        //如果没有连接请求,就等待到有连接请求--这是accept函数的特性
        //accept函数返回一个新的socket,这个socket(new_server_socket)用于同连接到的客户的通信
        //new_server_socket代表了服务器和客户端之间的一个通信通道
        //accept函数把连接到的客户端信息填写到客户端的socket地址结构client_addr中
       // int new_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
		new_server_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
			
		printf("debug_service_run new_server_socket = %d\n", new_server_socket);
        if ( new_server_socket < 0)
        {
            printf("debug_service_run Server Accept Failed!\n");
            break;
        }
		
        // setsockopt(server_socket,SOL_SOCKET,SO_SNDBUF,buffer,sizeof(int));
		 
		 while (1)
		 {
        
			bzero(buffer, BUFFER_SIZE);
			int bytes_recv = recv(new_server_socket,buffer,BUFFER_SIZE,0);
			if (bytes_recv <= 0)
			{
				printf("debug_service_run Server Recieve Data Failed! r: %s\n", strerror(errno));
				break;
			}
			
			printf("Server Recieve Data bytes : %d\n", bytes_recv);
		  
			char to_client_buf[BUFFER_SIZE];
			int to_client_buf_len = 0;
			//解析指令,执行指令，返回执行结果
			printf("******fun:%s,line:%d********\n", __FUNCTION__,__LINE__);
			parase_command_tcli(buffer, bytes_recv, to_client_buf, &to_client_buf_len);

		}
		
        //关闭与客户端的连接
        close(new_server_socket);
    }
    //关闭监听用的socket
    close(server_socket);
    return 0;
}

/**
*发送命令结果消息给客户端
*/
int send_msg(const char *buf, int len)
{
//	printf("enter send_msg ... len = %d\n", len);
	int i = 0; 
	for (i = 0; i < len; i++)
	{
		printf("%c", buf[i]);
	}
	
	printf("\n");
	
	int bytes_send = 0;
	
	bytes_send = send(new_server_socket,buf,len,0);
	if (bytes_send <= 0)
	{
		printf("Server send Data Failed! r: %s\n", strerror(errno));
	}
	else 
	{
	//	printf("bytes_send = %d", bytes_send);
	}
	return 0;
}

int parase_command_tcli(char *buf_command, int len, char *ret_buf, int *ret_len) 
{
	char buf[BUFFER_SIZE];
	
	strncpy(buf, buf_command, len);
	buf[len] = '\0';
	
	//单条命令
	printf("******fun:%s,line:%d********\n", __FUNCTION__,__LINE__);
	decode_single_command_tcli(buf_command, len);
		

	return 0;
}

void open_log() 
{
	set_socket_accept_flag(OPEND_LOG);
	tprint("---------start print---------\n");
}

//解析单条命令
int decode_single_command_tcli(char *buf_com, int buf_len)
{
	g_tvh_route_para = (tvh_route_para *)buf_com;

	printf("******fun:%s,line:%d********\n", __FUNCTION__,__LINE__);
	printf("un32_client_id : %d\n", g_tvh_route_para->un32_client_id);
	printf("un32_entry_id : %s\n", g_tvh_route_para->un32_entry_id);
	printf("un32_data_length : %d\n", g_tvh_route_para->un32_data_length);
	printf("request_result : %d\n", g_tvh_route_para->request_result);
	printf("exten_para : %d\n", g_tvh_route_para->exten_para);
	int i = 0;
	printf("para lists:");
	for (i = 0; i < g_tvh_route_para->un32_data_length; i++)
	{
		printf("%c", g_tvh_route_para->request_para[i]);
	}
	printf("\n");
	
	
	if (strcmp((char *)g_tvh_route_para->un32_entry_id, "open_socket_log") == 0)
	{
		//open
		pthread_t id1;
		pthread_create(&id1,NULL,(void *) open_log,NULL);
		send_msg("0eof",sizeof("0eof"));
		return 0;
	} 
	else if (strcmp((char *)g_tvh_route_para->un32_entry_id, "close_socket_log") == 0)
	{
		set_socket_accept_flag(CLOSE_LOG);
		send_msg("0eof",sizeof("0eof"));
		return 0;
	}

	printf("******fun:%s,line:%d********\n", __FUNCTION__,__LINE__);
	//int ret = 0;
	//printf("don't call tcli fuction\n");

	if (strcmp((char *)g_tvh_route_para->un32_entry_id, "tc.detail") == 0)
	{
		char buf[64] = {0};
		sprintf(buf, "[tcli_server_pid_start]%d[tcli_server_pid_end]", getpid());
		send_msg(buf, strlen(buf));
		tvh_debug_tcli_execute((char *)g_tvh_route_para->request_para, help_cmd_send, NULL);
	}
	else
	{
		gettimeofday(&p_start_time, NULL);
		int ret = tvh_debug_tcli_execute((char *)g_tvh_route_para->request_para, log_send, NULL);
		gettimeofday(&p_end_time, NULL);
		char buf[64]={0};
		
		long msec = (p_end_time.tv_sec - p_start_time.tv_sec)*1000 + (p_end_time.tv_usec - p_start_time.tv_usec)/1000;
		printf("ret-----------------:%d, time : %ld", ret, msec);
		sprintf(buf, "%d#%ldeof", ret, msec);
		send_msg(buf, 64);
	}

	return 0;
}

//解析参数到数组
int decode_para_lists(char *para_list, int para_len)
{
	bzero(para_buf, sizeof(para_buf));
	int i, j, k;
	
	for (i = 0; i < para_len; i++)
	{
		printf("0x%02x ", para_list[i]);
	}
	printf("\n");
	j = 0, k = 0;
	for (i = 0; i < para_len; i++)
	{
		if (para_list[i] == ',') 
		{
			para_buf[k][j++] = '\0';
			k++;
			j = 0;
		}
		else
		{
			para_buf[k][j++] = para_list[i];
		}
	}
	para_buf[k][j] = '\0';
	
	return k;
}

