/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_desc_module.sidl
 */
 

#define LOG_TAG     "remote_itv_desc_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_defines.h"
#include "itv_desc.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "be9e2a46-130b-11e5-b322-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_desc_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_desc_open_descrambler FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_desc_close_descrambler FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_desc_set_descrambler_pid FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_desc_set_descrambler_key FIRST_CALL_TRANSACTION + 4

using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG     "remote_itv_desc_module"

#include <stdlib.h>

#include "clog.h"
#include "remote_itv_desc_module.h"

class remote_itv_desc_module_service : public BBinder  
{  
private:
    static remote_itv_desc_module_service* _instance;

    remote_itv_desc_module_service(){
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_desc_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_desc_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            // TOSLOGI(SERVICE_NAME"_service Instance ret = %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        ALOGD(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_desc_open_descrambler:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_desc_open_descrambler here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_desc_stream_type_t stream_type = (itv_desc_stream_type_t)data.readInt32();  //itv_desc_stream_type_t as input paramter

                int _descrambler_len = data.readInt32(); //read length, only 32bits length support yet
                itv_handle_t* descrambler = NULL;

                Parcel::WritableBlob _descrambler_wblob;

                if(_descrambler_len > 0) {
                    reply->writeInt32(_descrambler_len);
                    reply->writeBlob(_descrambler_len,&_descrambler_wblob);
                    descrambler = (itv_handle_t*)_descrambler_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                descrambler = (itv_handle_t*)_descrambler_wblob.data();
                int _result = itv_desc_open_descrambler( stream_type, descrambler );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_desc_open_descrambler here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_desc_close_descrambler:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_desc_close_descrambler here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t descrambler = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_desc_close_descrambler( descrambler );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_desc_close_descrambler here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_desc_set_descrambler_pid:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_desc_set_descrambler_pid here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t descrambler = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int pid = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_desc_set_descrambler_pid( descrambler, pid );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_desc_set_descrambler_pid here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_desc_set_descrambler_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_desc_set_descrambler_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t descrambler = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                itv_desc_key_type_t keyType = (itv_desc_key_type_t)data.readInt32();  //itv_desc_key_type_t as input paramter

                int _key_len = data.readInt32(); //read length, only 32bits length support yet
                const unsigned char* key = NULL;

                Parcel::ReadableBlob _key_rblob;

                if(_key_len > 0) {
                    data.readBlob(_key_len,&_key_rblob);
                    key = (const unsigned char*)_key_rblob.data();
                }

                const int keyLen = (const int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                key = (const unsigned char*)_key_rblob.data();
                int _result = itv_desc_set_descrambler_key( descrambler, keyType, key, keyLen );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_desc_set_descrambler_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        ALOGD(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_desc_module_service_add() {
    remote_itv_desc_module_service::Instance();
    return 0;
}

remote_itv_desc_module_service* remote_itv_desc_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG     "remote_itv_desc_module"

#include "clog.h"

class remote_itv_desc_module_client  
{  
private:
    static remote_itv_desc_module_client* _instance;
    sp<IBinder> _binder;

    remote_itv_desc_module_client()
        :_binder(NULL) {
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_desc_module_client() {
        // TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            // TOSLOGW(SERVICE_NAME"_client getFailed!\n\n");
        }

        return (_binder != NULL);
    }

public:  
    static remote_itv_desc_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_desc_module_client();
        }

        return _instance;
    }

    int itv_desc_open_descrambler( itv_desc_stream_type_t stream_type, itv_handle_t* descrambler ) {
		// TOSLOGI(SERVICE_NAME"_client itv_desc_open_descrambler()\n");
        Parcel data, reply;

        /*-- add you code for itv_desc_open_descrambler here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(stream_type);  //itv_desc_stream_type_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (descrambler == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_handle_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_itv_desc_open_descrambler,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (descrambler != NULL) {
                    int _descrambler_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _descrambler_rblob;
                    reply.readBlob(_descrambler_len,&_descrambler_rblob);
                    memcpy(descrambler,_descrambler_rblob.data(),_descrambler_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_desc_open_descrambler error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_desc_open_descrambler error\n");
        }

        return _result;
        /*-- add you code for itv_desc_open_descrambler here --*/
    }

    int itv_desc_close_descrambler( itv_handle_t descrambler ) {
		// TOSLOGI(SERVICE_NAME"_client itv_desc_close_descrambler()\n");
        Parcel data, reply;

        /*-- add you code for itv_desc_close_descrambler here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(descrambler);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_desc_close_descrambler,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_desc_close_descrambler error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_desc_close_descrambler error\n");
        }

        return _result;
        /*-- add you code for itv_desc_close_descrambler here --*/
    }

    int itv_desc_set_descrambler_pid( itv_handle_t descrambler, int pid ) {
		// TOSLOGI(SERVICE_NAME"_client itv_desc_set_descrambler_pid()\n");
        Parcel data, reply;

        /*-- add you code for itv_desc_set_descrambler_pid here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(descrambler);  //itv_handle_t as input paramter

            data.writeInt32(pid);  //int as input paramter

            _binder->transact(TRANSACTION_itv_desc_set_descrambler_pid,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_desc_set_descrambler_pid error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_desc_set_descrambler_pid error\n");
        }

        return _result;
        /*-- add you code for itv_desc_set_descrambler_pid here --*/
    }

    int itv_desc_set_descrambler_key( itv_handle_t descrambler, itv_desc_key_type_t keyType, const unsigned char* key, const int keyLen ) {
		// TOSLOGI(SERVICE_NAME"_client itv_desc_set_descrambler_key()\n");
        Parcel data, reply;

        /*-- add you code for itv_desc_set_descrambler_key here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(descrambler);  //itv_handle_t as input paramter

            data.writeInt32(keyType);  //itv_desc_key_type_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (key == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(keyLen) * sizeof(unsigned char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _key_wblob;
                data.writeBlob((keyLen) * sizeof(unsigned char),&_key_wblob);
                memcpy(_key_wblob.data(),key,(keyLen)* sizeof(unsigned char));
            }

            data.writeInt32(keyLen);  //int as input paramter

            _binder->transact(TRANSACTION_itv_desc_set_descrambler_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_desc_set_descrambler_key error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_desc_set_descrambler_key error\n");
        }

        return _result;
        /*-- add you code for itv_desc_set_descrambler_key here --*/
    }
};

remote_itv_desc_module_client* remote_itv_desc_module_client::_instance = NULL;

int itv_desc_open_descrambler( itv_desc_stream_type_t stream_type, itv_handle_t* descrambler ) {
    return remote_itv_desc_module_client::Instance()->itv_desc_open_descrambler(stream_type, descrambler);
}
int itv_desc_close_descrambler( itv_handle_t descrambler ) {
    return remote_itv_desc_module_client::Instance()->itv_desc_close_descrambler(descrambler);
}
int itv_desc_set_descrambler_pid( itv_handle_t descrambler, int pid ) {
    return remote_itv_desc_module_client::Instance()->itv_desc_set_descrambler_pid(descrambler, pid);
}
int itv_desc_set_descrambler_key( itv_handle_t descrambler, itv_desc_key_type_t keyType, const unsigned char* key, const int keyLen ) {
    return remote_itv_desc_module_client::Instance()->itv_desc_set_descrambler_key(descrambler, keyType, key, keyLen);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
