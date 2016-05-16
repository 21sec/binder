/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_hbbtv_browser.sidl
 */
 

#define LOG_TAG     "sbinder_hbbtv_browser"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_hbbtv_browser.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_HBBTV);

#define SERVICE_DESCRIPTOR                      "26501694-f54d-11e5-9e86-005056a86db3"
#define SERVICE_NAME                            "sbinder_hbbtv_browser"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_hbbtv_browser_handle_key FIRST_CALL_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_hbbtv_browser.h"

class sbinder_hbbtv_browser_service : public BBinder  
{  
private:
    static sbinder_hbbtv_browser_service* _instance;

    sbinder_hbbtv_browser_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_hbbtv_browser_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_hbbtv_browser_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_info(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_info(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_hbbtv_browser_handle_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_browser_handle_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t keyCode = (uint16_t)data.readInt32();  //uint16_t as input paramter

                uint16_t keyType = (uint16_t)data.readInt32();  //uint16_t as input paramter

                int _isHandle_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* isHandle = NULL;

                Parcel::WritableBlob _isHandle_wblob;

                if(_isHandle_len > 0) {
                    reply->writeInt32(_isHandle_len);
                    reply->writeBlob(_isHandle_len,&_isHandle_wblob);
                    isHandle = (fpi_bool*)_isHandle_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                isHandle = (fpi_bool*)_isHandle_wblob.data();
                fpi_error _result = tos_hbbtv_browser_handle_key( keyCode, keyType, isHandle );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_browser_handle_key here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_hbbtv_browser_service_add() {
    sbinder_hbbtv_browser_service::Instance();
    return 0;
}

sbinder_hbbtv_browser_service* sbinder_hbbtv_browser_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_hbbtv_browser_client  
{  
private:
    static sbinder_hbbtv_browser_client* _instance;
    sp<IBinder> _binder;

    sbinder_hbbtv_browser_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_hbbtv_browser_client() {
        fpi_info(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            fpi_warn(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static sbinder_hbbtv_browser_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_hbbtv_browser_client();
        }

        return _instance;
    }

    fpi_error tos_hbbtv_browser_handle_key( uint16_t keyCode, uint16_t keyType, fpi_bool* isHandle ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_browser_handle_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(keyCode);  //uint16_t as input paramter

            data.writeInt32(keyType);  //uint16_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (isHandle == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_browser_handle_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (isHandle != NULL) {
                    int _isHandle_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _isHandle_rblob;
                    reply.readBlob(_isHandle_len,&_isHandle_rblob);
                    memcpy(isHandle,_isHandle_rblob.data(),_isHandle_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_browser_handle_key error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_browser_handle_key error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_browser_handle_key here --*/
    }
};

sbinder_hbbtv_browser_client* sbinder_hbbtv_browser_client::_instance = NULL;

fpi_error tos_hbbtv_browser_handle_key( uint16_t keyCode, uint16_t keyType, fpi_bool* isHandle ) {
    return sbinder_hbbtv_browser_client::Instance()->tos_hbbtv_browser_handle_key(keyCode, keyType, isHandle);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
