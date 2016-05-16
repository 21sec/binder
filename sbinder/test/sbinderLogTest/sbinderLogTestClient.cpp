#include <binder/IServiceManager.h>
#include <binder/IBinder.h>
#include <binder/Parcel.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <private/binder/binder_module.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace sita_android;

#define SAMPLE_SERIVCE_DES "sbinderTest.client"
#define FUNC_CALLFUNCTION 1
#define BUFSIZE 256

long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}


int main(int argc,char** argv)
{
    if (argc <2){
	printf("client error: argc <2\n");
	return -1;
    }
    int count = atoi(argv[1]);

    printf("client count = %d\n",count);
    char rwc_buf[BUFSIZE];
    memset(rwc_buf,0,sizeof(rwc_buf));
    strncpy(rwc_buf,"main---------ddddddddddddddddd-------------\n",sizeof(rwc_buf));

    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> ibinder = sm->getService(String16(SAMPLE_SERIVCE_DES));
    if (ibinder == NULL){
	printf("client error: ibinder is NULL\n");
        return -1;
    }

    Parcel _data,_reply;

    Parcel::WritableBlob _wblob;
    _data.writeBlob(sizeof(rwc_buf),&_wblob);
    memcpy(_wblob.data(),rwc_buf,1* sizeof(rwc_buf));


    long time1 = getCurrentTime();

    for(int i =0 ;i<count;i++){
	ibinder->transact(FUNC_CALLFUNCTION, _data, &_reply, 0);
	
    	/*Parcel::ReadableBlob _rblob;
    	_reply.readBlob(BUFSIZE,&_rblob);

	if( count <10){
    	    printf("client readblob = %s\n",(const char*)_rblob.data());
	}*/
	int a = _reply.readInt32();

	if( count <10){
    	    printf("client readInt  = %d\n",a);
	}
    
    }
    printf("client total time = %ld\n",(getCurrentTime()-time1));
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
