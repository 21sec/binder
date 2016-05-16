#include "tos_androidHandler.h"
#include "tos_handleHelper.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


#define TEST_MESSAGE_ONE 1
#define TEST_MESSAGE_TWO TEST_MESSAGE_ONE+1
#define TEST_MESSAGE_THR TEST_MESSAGE_TWO+1
#define TEST_MESSAGE_FOR TEST_MESSAGE_THR+1
#define TEST_MESSAGE_FIV TEST_MESSAGE_FOR+1


tos_Looper_T *s_TestLooperHandle = NULL;

#include <time.h>
#include <stdlib.h>

long getCurrentTime()  
{  
	struct timespec times;
	clock_gettime(CLOCK_MONOTONIC, &times); 
    return times.tv_sec * 1000 + times.tv_nsec / 1000000;  
}

static void* looper_tast(void* args)
{
	if(s_TestLooperHandle != NULL) {
		int ret = tos_androidHandler_loop(s_TestLooperHandle); 
		if (ret <0){
			printf("android handler LOOP looper failed,destroy looper and handler,now exit!\n");
			tos_androidHandler_quit(s_TestLooperHandle);
			tos_androidHandler_destroyLooper(s_TestLooperHandle);
			s_TestLooperHandle = NULL;
		}
	}
	return NULL;
}


void handleMessage(tos_Looper_T* looper,const tos_androidHandler_message* msg,void* userdata)
{
	switch (msg->what){
		case TEST_MESSAGE_ONE:
			printf("TEST_MESSAGE_ONE called!------------------success------1--------------\n");
			break;
		case TEST_MESSAGE_TWO:
			printf("TEST_MESSAGE_TWO called!------------------success------2----time_now:%ld\n",getCurrentTime());
			break;
		case TEST_MESSAGE_THR:
			printf("TEST_MESSAGE_THR called!------------------success------3--------------\n");
			break;
		case TEST_MESSAGE_FOR:
			printf("TEST_MESSAGE_THR called!------------------success------4--------------\n");
			break;
		case TEST_MESSAGE_FIV:
			printf("TEST_MESSAGE_THR called!------------------success------5--------------\n");
			break;
		default:
			printf("Oh,default,error or not, you must know by yourself.\n");
			break;
	}
	printf("You have successfully know how to use handler looper!\n");
}

void* sendmsg_fun(void* arg)
{
	tos_androidHandler_message msg;
	msg.what = TEST_MESSAGE_TWO;
	tos_androidHandler_sendMessageDelay(s_TestLooperHandle, &msg ,200);
	if (tos_androidHandler_hasMessages(s_TestLooperHandle,msg.what,(void*)&msg)){
		printf("Have message:TEST_MESSAGE_TWO-------,now remove!\n");
		//tos_androidHandler_removeEmptyMessages(s_TestLooperHandle,msg.what); //test OK!
		tos_androidHandler_removeMessages(s_TestLooperHandle,msg.what,NULL);
	}
	printf("sendmsg_fun, ---------------time_now= %ld\n",getCurrentTime());
	tos_androidHandler_sendMessageDelay(s_TestLooperHandle, &msg ,200);
	return NULL;
}

int main(int argc, char** argv){
	int ret = 0;
	//handler looper create.
	s_TestLooperHandle = tos_androidHandler_createLooper("TestMainLooper",20,handleMessage,NULL);
	if (s_TestLooperHandle == NULL){
		printf("android handler looper create failed,now exit!\n");
		return -1;
	}

	// we must start a thread to deal with messages.
	pthread_t thread_handle;
	if (pthread_create(&thread_handle, NULL, looper_tast, NULL) != 0)
	{
		printf("create thread failed,now exit!\n");
		return -1;
	}

	// we can send a message for test.
	tos_androidHandler_message msg;
	msg.what = TEST_MESSAGE_ONE;
	ret = tos_androidHandler_sendMessage(s_TestLooperHandle, &msg);

	// create thread, send a msg. test asynchronously send msg
	pthread_t thread_handle1;
	if (pthread_create(&thread_handle1, NULL, sendmsg_fun, NULL) != 0)
	{
		printf("create thread failed,now exit!\n");
		return -1;
	}

	// send another msg.
	tos_androidHandler_message msg1;
	msg1.what = TEST_MESSAGE_THR;
	ret = tos_androidHandler_sendMessage(s_TestLooperHandle, &msg1);

	//test send empty msg.
	tos_androidHandler_sendEmptyMessage(s_TestLooperHandle,TEST_MESSAGE_FOR);

	//test send empty msg delay then remove, then send again.
	tos_androidHandler_sendEmptyMessageDelayed(s_TestLooperHandle,TEST_MESSAGE_FIV,200);
	tos_androidHandler_removeEmptyMessages(s_TestLooperHandle,TEST_MESSAGE_FIV);
	tos_androidHandler_sendEmptyMessageDelayed(s_TestLooperHandle,TEST_MESSAGE_FIV,200);


	// we must stop here,if don't looper will destroy.
	while(1){
		sleep(1);
	}

	//s_TestLooperHandle must not be null.
	if ( s_TestLooperHandle == NULL){
		printf("no need to quit android destroy, looper handler is null,now exit!\n");
		return -1;
	}
	//Now quit and destroy  hanlder looper.
	ret = tos_androidHandler_quit(s_TestLooperHandle);
	if (ret <0){
		printf("android handler quit looper failed,now exit!\n");
		return -1;
	}
	ret = tos_androidHandler_destroyLooper(s_TestLooperHandle);
	if (ret <0){
		printf("android handler destroy looper failed,now exit!\n");
		return -1;
	}
	// global var need to be null.
	s_TestLooperHandle = NULL;
	return ret;
}

