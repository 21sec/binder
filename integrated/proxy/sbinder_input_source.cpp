/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_input_source.sidl
 */
 

#define LOG_TAG     "sbinder_input_source"

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_session.h"
#include "tos_input_source.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_LINEIN);


#define SERVICE_DESCRIPTOR                      "d920c2b2-8d1c-11e5-a23d-005056a86db3"
#define SERVICE_NAME                            "sbinder_input_source"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_source_set_input FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_source_get_input FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_source_is_insert FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_source_set_input_async FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_source_get_hdmi_edid_ver FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_input_set_hdmi_edid_ver FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_source_set_bootinput FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_source_set_input_with_session FIRST_CALL_TRANSACTION+8
#define TRANSACTION_tos_session_request FIRST_CALL_TRANSACTION+9
#define TRANSACTION_tos_session_release FIRST_CALL_TRANSACTION+10
#define TRANSACTION_tos_source_is_itv FIRST_CALL_TRANSACTION+11

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_input_source.h"

class sbinder_input_source_service : public BBinder  
{  
private:
    static sbinder_input_source_service* _instance;

    sbinder_input_source_service(){
        fpi_debug(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_input_source_service() {
        fpi_debug(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_input_source_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_info(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_debug(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_source_set_input:
            {
				fpi_info(SERVICE_NAME"_service - onTransact code=%d",code);
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_set_input here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_set_input( input, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_set_input here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_source_get_input:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_get_input here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_SOURCE_SAVE_TYPE type = (EN_SOURCE_SAVE_TYPE)data.readInt32();  //EN_SOURCE_SAVE_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_API_SOURCE_INPUT* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_API_SOURCE_INPUT*)_value_wblob.data();
                }
				fpi_error _result ;
				if( value != NULL ){
                _result = tos_source_get_input( type, value );
					}else{
					_result = FPI_ERROR_FAIL;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_get_input here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_source_is_insert:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_is_insert here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT inSource = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int* state = NULL;
                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    Parcel::WritableBlob _state_wblob;
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (int*)_state_wblob.data();
                }
				fpi_error _result;
				if( state!=NULL){
                _result = tos_source_is_insert( inSource, state );
					}else{
					_result = FPI_ERROR_FAIL ;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_is_insert here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_source_set_input_async:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_set_input_async here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_set_input_async( input, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_set_input_async here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_source_get_hdmi_edid_ver:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_get_hdmi_edid_ver here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                int _ver_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* ver = NULL;

                Parcel::WritableBlob _ver_wblob;

                if(_ver_len > 0) {
                    reply->writeInt32(_ver_len);
                    reply->writeBlob(_ver_len,&_ver_wblob);
                    ver = (int32_t*)_ver_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ver = (int32_t*)_ver_wblob.data();
                fpi_error _result = tos_source_get_hdmi_edid_ver( input, ver );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_get_hdmi_edid_ver here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_input_set_hdmi_edid_ver:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_input_set_hdmi_edid_ver here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                int32_t ver = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_set_hdmi_edid_ver( input, ver );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_input_set_hdmi_edid_ver here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
      	    case TRANSACTION_tos_source_set_bootinput:
	    {
		data.enforceInterface(String16(SERVICE_NAME));  //fixed check
		//-- begin code for tos_source_set_input here, will auoto generated but may change yourself if need --

		//skip Exception and result first to write output paramters
		reply->writeNoException();
		EN_TOS_SOURCE_BOOT_INPUT bootSource = (EN_TOS_SOURCE_BOOT_INPUT)data.readInt32();

		fpi_error _result = tos_source_set_bootinput(bootSource);

		reply->writeInt32(_result); //fpi_error as return value
		fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
	    }break; 
	    case TRANSACTION_tos_source_set_input_with_session:
	    {
		data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_set_input here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t session_id = (uint32_t)data.readInt32();  //int32_t as input paramter
                 
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter
		 
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_set_input_with_session(session_id, input, act);

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_set_input here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
	    }break;

	    case TRANSACTION_tos_session_request:
	    {
		  data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_set_input here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				
                uint32_t session_id = (uint32_t)data.readInt32();  //int32_t as input paramter
		 
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_request(session_id);

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_set_input here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
	    }break;

	    case TRANSACTION_tos_session_release:
	    {
		  data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_set_input here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				
                uint32_t session_id = (uint32_t)data.readInt32();  //int32_t as input paramter
		 
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_source_release(session_id);

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_set_input here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
	    }break;

		 case TRANSACTION_tos_source_is_itv:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_source_is_itv here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _isitv_len = data.readInt32(); //read length, only 32bits length support yet
                int* isitv = NULL;

                Parcel::WritableBlob _isitv_wblob;

                if(_isitv_len > 0) {
                    reply->writeInt32(_isitv_len);
                    reply->writeBlob(_isitv_len,&_isitv_wblob);
                    isitv = (int*)_isitv_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                isitv = (int*)_isitv_wblob.data();
                fpi_error _result = tos_source_is_itv( isitv );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_source_is_itv here --
                return NO_ERROR;
            } break;
		
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_debug(SERVICE_NAME"_service end");
    }
}; 

int sbinder_input_source_service_add() {
    sbinder_input_source_service::Instance();
    return 0;
}

sbinder_input_source_service* sbinder_input_source_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_input_source_client  
{  
private:
    static sbinder_input_source_client* _instance;
    sp<IBinder> _binder;

    sbinder_input_source_client()
        :_binder(NULL) {
        fpi_debug(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_input_source_client() {
        fpi_debug(SERVICE_NAME"_client destory\n");
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
    static sbinder_input_source_client* Instance() {
        if(_instance == NULL) {
            fpi_warn(SERVICE_NAME"_client Instance");
            _instance = new sbinder_input_source_client();
        }

        return _instance;
    }

    fpi_error tos_source_set_input( EN_API_SOURCE_INPUT input, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_source_set_input here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_source_set_input,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_set_input error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_set_input error");
        }

        return _result;
        /*-- add you code for tos_source_set_input here --*/
    }
	
fpi_error tos_source_set_input_with_session(uint32_t session_id, EN_API_SOURCE_INPUT input, EN_ACT_CTRL act){
Parcel data, reply;

/*-- add you code for tos_source_get_input_with_session here --*/
 fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

	     data.writeInt32(session_id); //int32_t as input paramter
		 
            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_source_set_input_with_session,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_set_input error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_set_input error");
        }

        return _result;
        /*-- add you code for tos_source_set_input here --*/
}

fpi_error tos_source_request(uint32_t session_id){
Parcel data, reply;

/*-- add you code for tos_session_request here --*/
 fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

	     data.writeInt32(session_id); //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_session_request,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_session_request error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_session_request error");
        }

        return _result;
        /*-- add you code for tos_session_request here --*/
}

fpi_error tos_source_release(uint32_t session_id){
Parcel data, reply;

/*-- add you code for tos_session_release here --*/
 fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

	     data.writeInt32(session_id); //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_session_release,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_session_release error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_session_release error");
        }

        return _result;
        /*-- add you code for tos_session_release here --*/
}

    fpi_error tos_source_get_input( EN_SOURCE_SAVE_TYPE type, EN_API_SOURCE_INPUT* value ) {
        Parcel data, reply;

        /*-- add you code for tos_source_get_input here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_SOURCE_SAVE_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_API_SOURCE_INPUT));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_source_get_input,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_get_input error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_get_input error");
        }

        return _result;
        /*-- add you code for tos_source_get_input here --*/
    }
    fpi_error tos_source_set_bootinput(EN_TOS_SOURCE_BOOT_INPUT bootSource) {
	Parcel data, reply;
	
	/*-- add you code for tos_source_set_input here --*/
	fpi_error _result = FPI_ERROR_FAIL;
	if(_binder == NULL) {
		return _result;
	}
	try {        
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
                data.writeInt32(bootSource);  //EN_TOS_SOURCE_BOOT_INPUT as input paramter
                _binder->transact(TRANSACTION_tos_source_set_bootinput,data, &reply,0);
                if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
	}catch(...) {
		fpi_warn(SERVICE_NAME"_client tos_source_set_bootinput error");
	}
	return _result;
    }

    fpi_error tos_source_is_insert( EN_API_SOURCE_INPUT inSource, int* state ) {
        Parcel data, reply;

        /*-- add you code for tos_source_is_insert here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(inSource);  //EN_API_SOURCE_INPUT as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_source_is_insert,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_is_insert error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_is_insert error");
        }

        return _result;
        /*-- add you code for tos_source_is_insert here --*/
    }

    fpi_error tos_source_set_input_async( EN_API_SOURCE_INPUT input, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_source_set_input_async here --*/
	    fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_source_set_input_async,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_set_input_async error");
            }
        }catch(...) {
	        fpi_warn(SERVICE_NAME"_client tos_source_set_input error");
        }

        return _result;
        /*-- add you code for tos_source_set_input_async here --*/
    }

    fpi_error tos_source_get_hdmi_edid_ver( EN_API_SOURCE_INPUT input, int32_t* ver ) {
        Parcel data, reply;

        /*-- add you code for tos_source_get_hdmi_edid_ver here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ver == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_source_get_hdmi_edid_ver,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ver != NULL) {
                    int _ver_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ver_rblob;
                    reply.readBlob(_ver_len,&_ver_rblob);
                    memcpy(ver,_ver_rblob.data(),_ver_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_get_hdmi_edid_ver error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_get_hdmi_edid_ver error");
        }

        return _result;
        /*-- add you code for tos_source_get_hdmi_edid_ver here --*/
    }

    fpi_error tos_source_set_hdmi_edid_ver( EN_API_SOURCE_INPUT input, int32_t ver ) {
        Parcel data, reply;

        /*-- add you code for tos_input_set_hdmi_edid_ver here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            data.writeInt32(ver);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_input_set_hdmi_edid_ver,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_source_set_hdmi_edid_ver error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_source_set_hdmi_edid_ver error");
        }

        return _result;
        /*-- add you code for tos_input_set_hdmi_edid_ver here --*/
    }
	
	fpi_error tos_source_is_itv( int* isitv ) {
        Parcel data, reply;

        /*-- add you code for tos_source_is_itv here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (isitv == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_source_is_itv,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (isitv != NULL) {
                    int _isitv_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _isitv_rblob;
                    reply.readBlob(_isitv_len,&_isitv_rblob);
                    memcpy(isitv,_isitv_rblob.data(),_isitv_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_source_is_itv error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_source_is_itv error");
        }

        return _result;
        /*-- add you code for tos_source_is_itv here --*/
    }
};

sbinder_input_source_client* sbinder_input_source_client::_instance = NULL;

fpi_error tos_source_set_input( EN_API_SOURCE_INPUT input, EN_ACT_CTRL act ) {
    return sbinder_input_source_client::Instance()->tos_source_set_input(input, act);
}

fpi_error tos_source_set_input_with_session(uint32_t session_id, EN_API_SOURCE_INPUT input, EN_ACT_CTRL act){
    return sbinder_input_source_client::Instance()->tos_source_set_input_with_session(session_id, input, act);
}

fpi_error tos_source_release(uint32_t session_id){
   return sbinder_input_source_client::Instance()->tos_source_release(session_id);
}
fpi_error tos_source_request(uint32_t session_id){
   return sbinder_input_source_client::Instance()->tos_source_request(session_id);
}
fpi_error tos_source_get_input( EN_SOURCE_SAVE_TYPE type, EN_API_SOURCE_INPUT* value ) {
    return sbinder_input_source_client::Instance()->tos_source_get_input(type, value);
}
fpi_error tos_source_is_insert( EN_API_SOURCE_INPUT inSource, int* state ) {
    return sbinder_input_source_client::Instance()->tos_source_is_insert(inSource, state);
}
fpi_error tos_source_set_input_async( EN_API_SOURCE_INPUT input, EN_ACT_CTRL act ) {
    return sbinder_input_source_client::Instance()->tos_source_set_input_async(input, act);
}
fpi_error tos_source_get_hdmi_edid_ver( EN_API_SOURCE_INPUT input, int32_t* ver ) {
    return sbinder_input_source_client::Instance()->tos_source_get_hdmi_edid_ver(input, ver);
}
fpi_error tos_source_set_hdmi_edid_ver( EN_API_SOURCE_INPUT input, int32_t ver ) {
    return sbinder_input_source_client::Instance()->tos_source_set_hdmi_edid_ver(input, ver);
}
fpi_error tos_source_set_bootinput(EN_TOS_SOURCE_BOOT_INPUT bootSource) {
    return sbinder_input_source_client::Instance()->tos_source_set_bootinput(bootSource);	
}
fpi_error tos_source_is_itv( int* isitv ) {
    return sbinder_input_source_client::Instance()->tos_source_is_itv(isitv);
}
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
