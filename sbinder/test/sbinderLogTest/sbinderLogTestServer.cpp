#include <binder/IServiceManager.h>
#include <binder/IBinder.h>
#include <binder/Parcel.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <stdio.h>
#include <fcntl.h>

using namespace sita_android;
#define SAMPLE_SERIVCE_DES "sbinderTest.client"
#define FUNC_CALLFUNCTION 1
#define BUFSIZE 254

class SampleService: public BBinder {
public :
     SampleService() {
          mydescriptor = String16(SAMPLE_SERIVCE_DES);
	  fd = open("./log.txt",O_RDWR|O_APPEND|O_CREAT,0777);
     }
     
     virtual ~SampleService() {
	 close(fd);
     }

      virtual const String16& getInterfaceDescriptor() const {
           return mydescriptor;
     }
     
protected :
     

      virtual status_t onTransact(uint32_t code, const Parcel& data,
              Parcel* reply, uint32_t flags = 0) {
          //printf( "Service onTransact, code = %d\n" , code);
          switch (code) {
          case FUNC_CALLFUNCTION:{

		Parcel::ReadableBlob _rblob;
    		data.readBlob(BUFSIZE,&_rblob);
	        //printf("server readblob: %s\n\n",(char*)_rblob.data());
	
		/*Parcel::WritableBlob _wblob;
    		reply->writeBlob(BUFSIZE,&_wblob);

    		memcpy(_wblob.data(),_rblob.data(),BUFSIZE);*/
                write(fd,_rblob.data(),45);
		reply->writeInt32(1);
                break;
	  }
          default:
                return BBinder::onTransact(code, data, reply, flags);
          }
          return 0;
     }
private :
     int fd;
     String16 mydescriptor;
};

int main() {
     sp < IServiceManager > sm = defaultServiceManager();
     SampleService* samServ = new SampleService();
     status_t ret = sm->addService(String16(SAMPLE_SERIVCE_DES), samServ);
     printf( "server addservice return %d\n", ret);
     ProcessState::self()->startThreadPool();
     IPCThreadState::self()->joinThreadPool( true);
     return 0;
}
