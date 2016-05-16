/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_signal.sidl
 */
 

#define LOG_TAG     "sbinder_signal"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_signal.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_SIGNAL);


#define SERVICE_DESCRIPTOR                      "d443efb6-398f-11e5-ab68-005056a86db3"
#define SERVICE_NAME                            "sbinder_signal"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_signal_get_state FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_signal_get_current_info FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_signal_get_timing_info FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_signal_get_extra_info FIRST_CALL_TRANSACTION + 4

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_signal.h"

class sbinder_signal_service : public BBinder  
{  
private:
    static sbinder_signal_service* _instance;

    sbinder_signal_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_signal_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_signal_service();
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

            case TRANSACTION_tos_signal_get_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_signal_get_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_SIGNAL_STATUS_TYPE* state = NULL;

                Parcel::WritableBlob _state_wblob;

                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (EN_FPI_SIGNAL_STATUS_TYPE*)_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                state = (EN_FPI_SIGNAL_STATUS_TYPE*)_state_wblob.data();
                fpi_error _result = tos_signal_get_state( state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_signal_get_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_signal_get_current_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_signal_get_current_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _signaInfo_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_signal_info_t* signaInfo = NULL;

                Parcel::WritableBlob _signaInfo_wblob;

                if(_signaInfo_len > 0) {
                    reply->writeInt32(_signaInfo_len);
                    reply->writeBlob(_signaInfo_len,&_signaInfo_wblob);
                    signaInfo = (st_fpi_signal_info_t*)_signaInfo_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                signaInfo = (st_fpi_signal_info_t*)_signaInfo_wblob.data();
                fpi_error _result = tos_signal_get_current_info( signaInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_signal_get_current_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_signal_get_timing_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_signal_get_timing_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_signal_timing_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (st_fpi_signal_timing_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (st_fpi_signal_timing_t*)_value_wblob.data();
                fpi_error _result = tos_signal_get_timing_info( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_signal_get_timing_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_signal_get_extra_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_signal_get_extra_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SIGNAL_INFO_TYPE type = (EN_FPI_SIGNAL_INFO_TYPE)data.readInt32();  //EN_FPI_SIGNAL_INFO_TYPE as input paramter

           // #error not support this type of paramter void param yet, please add code yourself
			int _ui2_param_len = data.readInt32(); //read length, only 32bits length support yet
			int32_t* param = NULL;
			
			Parcel::WritableBlob _ui2_param_wblob;
			
			if(_ui2_param_len > 0) {
				reply->writeInt32(_ui2_param_len);
				reply->writeBlob(_ui2_param_len,&_ui2_param_wblob);
				param = (int32_t*)_ui2_param_wblob.data();
			}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_signal_get_extra_info( type, param );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_signal_get_extra_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_signal_service_add() {
    sbinder_signal_service::Instance();
    return 0;
}

sbinder_signal_service* sbinder_signal_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_signal_client  
{  
private:
    static sbinder_signal_client* _instance;
    sp<IBinder> _binder;

    sbinder_signal_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_signal_client() {
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
    static sbinder_signal_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_signal_client();
        }

        return _instance;
    }

    fpi_error tos_signal_get_state( EN_FPI_SIGNAL_STATUS_TYPE* state ) {
        Parcel data, reply;

        /*-- add you code for tos_signal_get_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_SIGNAL_STATUS_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_signal_get_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_signal_get_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_signal_get_state error");
        }

        return _result;
        /*-- add you code for tos_signal_get_state here --*/
    }

    fpi_error tos_signal_get_current_info( st_fpi_signal_info_t* signaInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_signal_get_current_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (signaInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_fpi_signal_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_signal_get_current_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (signaInfo != NULL) {
                    int _signaInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _signaInfo_rblob;
                    reply.readBlob(_signaInfo_len,&_signaInfo_rblob);
                    memcpy(signaInfo,_signaInfo_rblob.data(),_signaInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_signal_get_current_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_signal_get_current_info error");
        }

        return _result;
        /*-- add you code for tos_signal_get_current_info here --*/
    }

    fpi_error tos_signal_get_timing_info( st_fpi_signal_timing_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_signal_get_timing_info here --*/
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
                data.writeInt32((int)(1) * sizeof(st_fpi_signal_timing_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_signal_get_timing_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_signal_get_timing_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_signal_get_timing_info error");
        }

        return _result;
        /*-- add you code for tos_signal_get_timing_info here --*/
    }

    fpi_error tos_signal_get_extra_info( EN_FPI_SIGNAL_INFO_TYPE type, void* param ) {
        Parcel data, reply;

        /*-- add you code for tos_signal_get_extra_info here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_FPI_SIGNAL_INFO_TYPE as input paramter
            if (param == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

           // #error not support this type of paramter void param yet, please add code yourself

            _binder->transact(TRANSACTION_tos_signal_get_extra_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

            //    #error not support this type of output paramter void param yet, please add code yourself
                if (param != NULL) {
                    int _ui2_id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_id_rblob;
                    reply.readBlob(_ui2_id_len,&_ui2_id_rblob);
                    memcpy(param,_ui2_id_rblob.data(),_ui2_id_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_signal_get_extra_info error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_signal_get_extra_info error");
        }

        return _result;
        /*-- add you code for tos_signal_get_extra_info here --*/
    }
};

sbinder_signal_client* sbinder_signal_client::_instance = NULL;

fpi_error tos_signal_get_state( EN_FPI_SIGNAL_STATUS_TYPE* state ) {
    return sbinder_signal_client::Instance()->tos_signal_get_state(state);
}
fpi_error tos_signal_get_current_info( st_fpi_signal_info_t* signaInfo ) {
    return sbinder_signal_client::Instance()->tos_signal_get_current_info(signaInfo);
}
fpi_error tos_signal_get_timing_info( st_fpi_signal_timing_t* value ) {
    return sbinder_signal_client::Instance()->tos_signal_get_timing_info(value);
}
fpi_error tos_signal_get_extra_info( EN_FPI_SIGNAL_INFO_TYPE type, void* param ) {
    return sbinder_signal_client::Instance()->tos_signal_get_extra_info(type, param);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
