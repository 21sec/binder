/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_errorcode.sidl
 */
 

#define LOG_TAG     "sbinder_errorcode"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);



#define SERVICE_DESCRIPTOR                      "12466d86-8385-11e5-ad14-005056a86db3"
#define SERVICE_NAME                            "sbinder_errorcode"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_log_set_errcode FIRST_CALL_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_errorcode.h"

class sbinder_errorcode_service : public BBinder  
{  
private:
    static sbinder_errorcode_service* _instance;

    sbinder_errorcode_service(){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_errorcode_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_errorcode_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        TOSLOGI(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_log_set_errcode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_log_set_errcode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                unsigned int code = (unsigned int)data.readInt32();  //unsigned int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                tos_log_set_errcode( id, code );

                //-- end code for tos_log_set_errcode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_errorcode_service_add() {
    sbinder_errorcode_service::Instance();
    return 0;
}

sbinder_errorcode_service* sbinder_errorcode_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_errorcode_client  
{  
private:
    static sbinder_errorcode_client* _instance;
    sp<IBinder> _binder;

    sbinder_errorcode_client()
        :_binder(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_errorcode_client() {
        TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            TOSLOGW(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static sbinder_errorcode_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_errorcode_client();
        }

        return _instance;
    }

    void tos_log_set_errcode( int id, unsigned int code ) {
        Parcel data, reply;

        /*-- add you code for tos_log_set_errcode here --*/
        if(!getService()) {
            return;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            data.writeInt32(code);  //unsigned int as input paramter

            _binder->transact(TRANSACTION_tos_log_set_errcode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_log_set_errcode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_log_set_errcode error");
        }

        
        /*-- add you code for tos_log_set_errcode here --*/
    }
};

sbinder_errorcode_client* sbinder_errorcode_client::_instance = NULL;

void tos_log_set_errcode( int id, unsigned int code ) {
    return sbinder_errorcode_client::Instance()->tos_log_set_errcode(id, code);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
