/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_mheg.sidl
 */
 

#define LOG_TAG     "sbinder_mheg"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#include "tos_mheg.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_MHEG5);

#define SERVICE_DESCRIPTOR                      "efb6b40c-4229-11e5-b033-005056a86db3"
#define SERVICE_NAME                            "sbinder_mheg"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_mheg_is_open FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_mheg_dispatch_key_code FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_mheg_get_userinput_state FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_mheg_stop FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_mheg_start FIRST_CALL_TRANSACTION + 5

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_mheg.h"

class sbinder_mheg_service : public BBinder  
{  
private:
    static sbinder_mheg_service* _instance;

    sbinder_mheg_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_mheg_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_mheg_service();
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

            case TRANSACTION_tos_mheg_is_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mheg_is_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_mheg_is_open( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mheg_is_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mheg_dispatch_key_code:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mheg_dispatch_key_code here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t keycode = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_mheg_dispatch_key_code( keycode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mheg_dispatch_key_code here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mheg_get_userinput_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mheg_get_userinput_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint8_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (uint8_t*)_value_wblob.data();
                fpi_error _result = tos_mheg_get_userinput_state( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mheg_get_userinput_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mheg_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mheg_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_mheg_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mheg_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mheg_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mheg_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_mheg_start(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mheg_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_mheg_service_add() {
    sbinder_mheg_service::Instance();
    return 0;
}

sbinder_mheg_service* sbinder_mheg_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_mheg_client  
{  
private:
    static sbinder_mheg_client* _instance;
    sp<IBinder> _binder;

    sbinder_mheg_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_mheg_client() {
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
    static sbinder_mheg_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_mheg_client();
        }

        return _instance;
    }

    fpi_error tos_mheg_is_open( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_mheg_is_open here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_mheg_is_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_mheg_is_open error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mheg_is_open error");
        }

        return _result;
        /*-- add you code for tos_mheg_is_open here --*/
    }

    fpi_error tos_mheg_dispatch_key_code( uint32_t keycode ) {
        Parcel data, reply;

        /*-- add you code for tos_mheg_dispatch_key_code here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(keycode);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_mheg_dispatch_key_code,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_mheg_dispatch_key_code error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mheg_dispatch_key_code error");
        }

        return _result;
        /*-- add you code for tos_mheg_dispatch_key_code here --*/
    }

    fpi_error tos_mheg_get_userinput_state( uint8_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_mheg_get_userinput_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_mheg_get_userinput_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_mheg_get_userinput_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mheg_get_userinput_state error");
        }

        return _result;
        /*-- add you code for tos_mheg_get_userinput_state here --*/
    }

    fpi_error tos_mheg_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_mheg_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_mheg_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_mheg_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mheg_stop error");
        }

        return _result;
        /*-- add you code for tos_mheg_stop here --*/
    }

    fpi_error tos_mheg_start(  ) {
        Parcel data, reply;

        /*-- add you code for tos_mheg_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_mheg_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_mheg_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mheg_start error");
        }

        return _result;
        /*-- add you code for tos_mheg_start here --*/
    }
};

sbinder_mheg_client* sbinder_mheg_client::_instance = NULL;

fpi_error tos_mheg_is_open( fpi_bool* value ) {
    return sbinder_mheg_client::Instance()->tos_mheg_is_open(value);
}
fpi_error tos_mheg_dispatch_key_code( uint32_t keycode ) {
    return sbinder_mheg_client::Instance()->tos_mheg_dispatch_key_code(keycode);
}
fpi_error tos_mheg_get_userinput_state( uint8_t* value ) {
    return sbinder_mheg_client::Instance()->tos_mheg_get_userinput_state(value);
}
fpi_error tos_mheg_stop(  ) {
    return sbinder_mheg_client::Instance()->tos_mheg_stop();
}
fpi_error tos_mheg_start(  ) {
    return sbinder_mheg_client::Instance()->tos_mheg_start();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
