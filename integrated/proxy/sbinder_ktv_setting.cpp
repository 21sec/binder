/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_ktv_setting.sidl
 */
 

#define LOG_TAG     "sbinder_ktv_setting"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_ktv_setting.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_KTV);

#define SERVICE_DESCRIPTOR                      "7bf698c0-c704-11e4-9f7f-005056a84a3b"
#define SERVICE_NAME                            "sbinder_ktv_setting"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_ktv_start_obtain_mic_data FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_ktv_stop_obtain_mic_data FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_ktv_set_echo_mode FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_ktv_set_key_shift FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_ktv_open_ktv FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_ktv_close_ktv FIRST_CALL_TRANSACTION + 6

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_ktv_setting.h"

class sbinder_ktv_setting_service : public BBinder  
{  
private:
    static sbinder_ktv_setting_service* _instance;

    sbinder_ktv_setting_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_ktv_setting_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_ktv_setting_service();
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

            case TRANSACTION_tos_ktv_start_obtain_mic_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_start_obtain_mic_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                char* path = NULL;
                if(_path_len > 0) {
                    Parcel::ReadableBlob _path_rblob;
                    data.readBlob(_path_len,&_path_rblob);
                    path = (char*)_path_rblob.data();
                }

                fpi_error _result = tos_ktv_start_obtain_mic_data( path );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_start_obtain_mic_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ktv_stop_obtain_mic_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_stop_obtain_mic_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                char* path = NULL;
                if(_path_len > 0) {
                    reply->writeInt32(_path_len);
                    Parcel::WritableBlob _path_wblob;
                    reply->writeBlob(_path_len,&_path_wblob);
                    path = (char*)_path_wblob.data();
                }

                fpi_error _result = tos_ktv_stop_obtain_mic_data( path );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_stop_obtain_mic_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ktv_set_echo_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_set_echo_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t enable = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t mode = (uint32_t)data.readInt32();  //uint32_t as input paramter

                fpi_error _result = tos_ktv_set_echo_mode( enable, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_set_echo_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ktv_set_key_shift:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_set_key_shift here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t enable = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t mode = (uint32_t)data.readInt32();  //uint32_t as input paramter

                fpi_error _result = tos_ktv_set_key_shift( enable, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_set_key_shift here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ktv_open_ktv:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_open_ktv here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_ktv_open_ktv(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_open_ktv here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ktv_close_ktv:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ktv_close_ktv here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_ktv_close_ktv(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ktv_close_ktv here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_ktv_setting_service_add() {
    sbinder_ktv_setting_service::Instance();
    return 0;
}

sbinder_ktv_setting_service* sbinder_ktv_setting_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_ktv_setting_client  
{  
private:
    static sbinder_ktv_setting_client* _instance;
    sp<IBinder> _binder;

    sbinder_ktv_setting_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_ktv_setting_client() {
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
    static sbinder_ktv_setting_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_ktv_setting_client();
        }

        return _instance;
    }

    fpi_error tos_ktv_start_obtain_mic_data( char* path ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_start_obtain_mic_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_ktv_start_obtain_mic_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_start_obtain_mic_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_start_obtain_mic_data error");
        }

        return _result;
        /*-- add you code for tos_ktv_start_obtain_mic_data here --*/
    }

    fpi_error tos_ktv_stop_obtain_mic_data( char* path ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_stop_obtain_mic_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ktv_stop_obtain_mic_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (path != NULL) {
                    int _path_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _path_rblob;
                    reply.readBlob(_path_len,&_path_rblob);
                    memcpy(path,_path_rblob.data(),_path_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_stop_obtain_mic_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_stop_obtain_mic_data error");
        }

        return _result;
        /*-- add you code for tos_ktv_stop_obtain_mic_data here --*/
    }

    fpi_error tos_ktv_set_echo_mode( uint32_t enable, uint32_t mode ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_set_echo_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //uint32_t as input paramter

            data.writeInt32(mode);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_ktv_set_echo_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_set_echo_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_set_echo_mode error");
        }

        return _result;
        /*-- add you code for tos_ktv_set_echo_mode here --*/
    }

    fpi_error tos_ktv_set_key_shift( uint32_t enable, uint32_t mode ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_set_key_shift here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //uint32_t as input paramter

            data.writeInt32(mode);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_ktv_set_key_shift,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_set_key_shift error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_set_key_shift error");
        }

        return _result;
        /*-- add you code for tos_ktv_set_key_shift here --*/
    }

    fpi_error tos_ktv_open_ktv(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_open_ktv here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ktv_open_ktv,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_open_ktv error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_open_ktv error");
        }

        return _result;
        /*-- add you code for tos_ktv_open_ktv here --*/
    }

    fpi_error tos_ktv_close_ktv(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ktv_close_ktv here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ktv_close_ktv,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ktv_close_ktv error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ktv_close_ktv error");
        }

        return _result;
        /*-- add you code for tos_ktv_close_ktv here --*/
    }
};

sbinder_ktv_setting_client* sbinder_ktv_setting_client::_instance = NULL;

fpi_error tos_ktv_start_obtain_mic_data( char* path ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_start_obtain_mic_data(path);
}
fpi_error tos_ktv_stop_obtain_mic_data( char* path ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_stop_obtain_mic_data(path);
}
fpi_error tos_ktv_set_echo_mode( uint32_t enable, uint32_t mode ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_set_echo_mode(enable, mode);
}
fpi_error tos_ktv_set_key_shift( uint32_t enable, uint32_t mode ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_set_key_shift(enable, mode);
}
fpi_error tos_ktv_open_ktv(  ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_open_ktv();
}
fpi_error tos_ktv_close_ktv(  ) {
    return sbinder_ktv_setting_client::Instance()->tos_ktv_close_ktv();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
