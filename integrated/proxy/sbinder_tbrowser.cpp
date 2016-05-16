/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: /home/weigj/samba/sita/tbrowser/integrated/proxy/sbinder_tbrowser.sidl
 */

#define LOG_TAG     "sbinder_tbrowser"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_tbrowser.h"
#include "tos_key_code.h"



#define SERVICE_DESCRIPTOR                      "540451e0-f237-11e5-baea-005056a81ef4"
#define SERVICE_NAME                            "sbinder_tbrowser"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_tbrowser_load_url FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_tbrowser_push_event FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_tbrowser_destory FIRST_CALL_TRANSACTION + 3

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_tbrowser.h"
class sbinder_tbrowser_service : public BBinder  
{  
private:
    static sbinder_tbrowser_service* _instance;

    sbinder_tbrowser_service(){
        CLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_tbrowser_service() {
        CLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_tbrowser_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            CLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        CLOGI(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_tbrowser_load_url:
            {
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tbrowser_load_url here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                const char* url = NULL;

                Parcel::ReadableBlob _url_rblob;
                if(_url_len > 0) {
                    data.readBlob(_url_len,&_url_rblob);
                    url = (const char*)_url_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (const char*)_url_rblob.data();
                int _result = tos_tbrowser_load_url( url );
                reply->writeInt32(_result); //int as return value
                //-- end code for tos_tbrowser_load_url here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tbrowser_push_event:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tbrowser_push_event here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				
                //begin paramters list
            	//#error not support this type of paramter TOS_KeyAction keyType yet, please add code yourself
				TOS_KeyAction keyType = (TOS_KeyAction)data.readInt32();
				CLOGI(SERVICE_NAME"_service - onTransact keyType=%d",keyType);
                int keyCode = (int)data.readInt32();  //int as input paramter
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tbrowser_push_event( keyType, keyCode );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tbrowser_push_event here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tbrowser_destory:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tbrowser_destory here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tbrowser_destory(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tbrowser_destory here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

    }
}; 

int sbinder_tbrowser_service_add() {
    sbinder_tbrowser_service::Instance();
    return 0;
}

sbinder_tbrowser_service* sbinder_tbrowser_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_tbrowser_client  
{  
private:
    static sbinder_tbrowser_client* _instance;
    sp<IBinder> _binder;
    sbinder_tbrowser_client()
        :_binder(NULL) {
        CLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_tbrowser_client() {
        CLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
			_binder = sm->checkService(String16(SERVICE_NAME));
			if(_binder == NULL){
				CLOGI(SERVICE_NAME" is not exist");
			}else{
				CLOGI(SERVICE_NAME" is here");
			}
			
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            CLOGW(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static sbinder_tbrowser_client* Instance() {
        if(_instance == NULL) {
            CLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_tbrowser_client();
        }

        return _instance;
    }

    int tos_tbrowser_load_url( const char* url ) {
        Parcel data, reply;

        /*-- add you code for tos_tbrowser_loadURL here --*/
        int _result = 0;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
			
            else {
                data.writeInt32((int)((strlen(url)+1)) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _url_wblob;
                data.writeBlob(((strlen(url)+1)) * sizeof(char),&_url_wblob);
                memcpy(_url_wblob.data(),url,((strlen(url)+1))* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_tbrowser_load_url,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tbrowser_load_url error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tbrowser_load_url error");
        }

        return _result;
        /*-- add you code for tos_tbrowser_load_url here --*/
    }

    int tos_tbrowser_push_event( TOS_KeyAction keyType, int keyCode ) {
        Parcel data, reply;

        /*-- add you code for tos_tbrowser_push_event here --*/
        int _result = 0;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter TOS_KeyAction keyType yet, please add code yourself
			data.writeInt32(keyType);
            data.writeInt32(keyCode);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tbrowser_push_event,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_tbrowser_push_event error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_tbrowser_push_event error");
        }

        return _result;
        /*-- add you code for tos_tbrowser_push_event here --*/
    }

    int tos_tbrowser_destory(  ) {
        Parcel data, reply;

        /*-- add you code for tos_tbrowser_destory here --*/
        int _result = 0;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_tbrowser_destory,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_tbrowser_destory error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_tbrowser_destory error");
        }

        return _result;
        /*-- add you code for tos_tbrowser_destory here --*/
    }
};

sbinder_tbrowser_client* sbinder_tbrowser_client::_instance = NULL;

int tos_tbrowser_load_url( const char* url ) {
	CLOGI(SERVICE_NAME"_client int tos_tbrowser_load_url\n");
    return sbinder_tbrowser_client::Instance()->tos_tbrowser_load_url(url);
}
int tos_tbrowser_push_event( TOS_KeyAction keyType, int keyCode ) {
	CLOGI(SERVICE_NAME"_client tos_tbrowser_push_event\n");
    return sbinder_tbrowser_client::Instance()->tos_tbrowser_push_event(keyType, keyCode);
}
int tos_tbrowser_destory(  ) {
    return sbinder_tbrowser_client::Instance()->tos_tbrowser_destory();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
