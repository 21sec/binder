/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_tifhal_helper.sidl
 */
 

#define LOG_TAG     "remote_tifhal_helper"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_tifhal_helper.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "4c1d19c8-4718-11e5-ad6b-005056a86db3"
#define SERVICE_NAME                            "remote_tifhal_helper"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_tifhal_tvinput_initialize FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_tifhal_tvinput_get_stream_count FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_tifhal_tvinput_get_stream_configurations FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_tifhal_tvinput_request_capture FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_tifhal_tvinput_cancel_capture FIRST_CALL_TRANSACTION + 5


#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "remote_tifhal_helper.h"

class remote_tifhal_helper_service : public BBinder  
{  
private:
    static remote_tifhal_helper_service* _instance;
	static sp<IBinder> _callback;

    remote_tifhal_helper_service(){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_tifhal_helper_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

	static void tifhal_input_callback(int type, void* param, void *userdata) {
		TOSLOGI(SERVICE_NAME"_service tifhal_input_callback type=%d\n",type);
		
        if(_callback != NULL && _callback->isBinderAlive()) {
            Parcel data, reply;
            data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
			
            data.writeInt32(type);

			//note:this module need be called from 64bits process to 32bits, so we should not use memcpy
			switch(type) {
				case TOS_TIFHAL_TVINPUT_EVENT_DEVICE_AVAILABLE:
				case TOS_TIFHAL_TVINPUT_EVENT_DEVICE_UNAVAILABLE:
				case TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED: {
					tos_tifhal_tvinput_device_info_t * info = (tos_tifhal_tvinput_device_info_t*)param;
					TOSLOGI("tifhal_input_callback deviceId=0x%x(%d) type=%d portId=%d\n",info->deviceId,info->deviceId,info->type,info->portId);
					data.writeInt32(info->deviceId);
					data.writeInt32(info->type);
					data.writeInt32(info->portId);
				}
				break;
			
				case TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_SUCCEEDED:
				case TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED: {
					tos_tifhal_tvinput_capture_result_t * result = (tos_tifhal_tvinput_capture_result_t*)param;					
					TOSLOGI("tifhal_input_callback deviceId=0x%x(%d) streamId=0x%x sequence=%d errCode=%d\n",result->deviceId,result->deviceId,result->streamId,result->sequence,result->errCode);
					data.writeInt32(result->deviceId);
					data.writeInt32(result->streamId);
					data.writeInt32(result->sequence);
					data.writeInt32(result->errCode);
				}
				break;

				default:
					CLOG_ASSERT(0,"tifhal_input_callback client unknown msg type %d",type);
			}			
			
            _callback->transact(TRANSACTION_CALLBACK_callback, data, &reply, 0);

            int err = reply.readExceptionCode();
			CLOG_ASSERT(err == 0,SERVICE_NAME"_callback exception %d",err);
        }
	}

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_tifhal_helper_service();
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

            case TRANSACTION_tos_tifhal_tvinput_initialize:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_tvinput_initialize here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
             	sp<IBinder> binder = data.readStrongBinder();

                // re-get all pointers from blob to fix realloc issue in Parcel

				sp<IBinder> _oldcb = _callback;
				_callback = binder;
				
                int _result = tos_tifhal_tvinput_initialize( tifhal_input_callback, NULL );

				if(_result != TIFHAL_ERROR_NO_ERROR) {
					_callback = _oldcb;
				}

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_tvinput_initialize here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_tvinput_get_stream_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_tvinput_get_stream_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int deviceId = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_tvinput_get_stream_count( deviceId );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_tvinput_get_stream_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_tvinput_get_stream_configurations:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_tvinput_get_stream_configurations here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int deviceId = (int)data.readInt32();  //int as input paramter

                int _configs_cnt = data.readInt32(); //read count for 32-64 bits 
                tos_tifhal_tvinput_tv_stream_config_t* pconfigs = NULL;

				tos_tifhal_tvinput_tv_stream_config_t configs[64];
				const int rmc = sizeof(configs)/sizeof(configs[0]);
				CLOG_ASSERT(_configs_cnt <= rmc,"Not Supported maxCount %d, should <= %d",_configs_cnt,rmc);				
				
				memset(configs,0,sizeof(configs));
				if(_configs_cnt >= 0) {
					pconfigs = configs;
				}

                int maxCount = (int)data.readInt32();  //int as input paramter

                int _result = tos_tifhal_tvinput_get_stream_configurations( deviceId, pconfigs, maxCount );

                reply->writeInt32(_result); //int as return value
			
				for(int i=0;i<_result;i++) {
					reply->writeInt32(pconfigs[i].streamId);
					reply->writeInt32(pconfigs[i].maxVideoWidth);
					reply->writeInt32(pconfigs[i].maxVideoHeight);
				}
                //-- end code for tos_tifhal_tvinput_get_stream_configurations here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_tvinput_request_capture:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_tvinput_request_capture here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int deviceId = (int)data.readInt32();  //int as input paramter

                int streamId = (int)data.readInt32();  //int as input paramter

                int sequence = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_tvinput_request_capture( deviceId, streamId, sequence );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_tvinput_request_capture here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_tvinput_cancel_capture:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_tvinput_cancel_capture here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int deviceId = (int)data.readInt32();  //int as input paramter

                int streamId = (int)data.readInt32();  //int as input paramter

                int sequence = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_tvinput_cancel_capture( deviceId, streamId, sequence );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_tvinput_cancel_capture here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int remote_tifhal_helper_service_add() {
    remote_tifhal_helper_service::Instance();
    return 0;
}

remote_tifhal_helper_service* remote_tifhal_helper_service::_instance = NULL;
sp<IBinder> remote_tifhal_helper_service::_callback = NULL;


#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>

class remote_tifhal_helper_client  
{  
private:
    static remote_tifhal_helper_client* _instance;
    sp<IBinder> _binder;

	class Callback;

	sp<Callback> _callback;

    remote_tifhal_helper_client()
        :_binder(NULL),_callback(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_tifhal_helper_client() {
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
	

    class Callback : public ICallbackList::ICallback {
    public:
        Callback(void* cb,void* cookie)
            :ICallback(cb,cookie) {
            _descriptor = String16(SERVICE_NAME"_callback");
        }

        ~Callback() {
        }

        virtual status_t onTransact( uint32_t code,
                const Parcel& data,Parcel* reply,uint32_t flags = 0) {
            TOSLOGV(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_callback:
            {
                if (!data.checkInterface(this)) {
                    TOSLOGW(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
                    int type = (int)data.readInt32();  //int as input paramter
					
					switch(type) {
						case TOS_TIFHAL_TVINPUT_EVENT_DEVICE_AVAILABLE:
						case TOS_TIFHAL_TVINPUT_EVENT_DEVICE_UNAVAILABLE:
						case TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED: {
							tos_tifhal_tvinput_device_info_t info;
							memset(&info,0,sizeof(info));
							info.deviceId = (int)data.readInt32();
							info.type = (int)data.readInt32();
							info.portId = (int)data.readInt32();
							TOSLOGI("tifhal_input_callback client deviceId=0x%x(%d) type=%d portId=%d\n",info.deviceId,info.deviceId,info.type,info.portId);

							((tos_tifhal_tvinput_notify)_callback)(type,&info,_cookie);
						}
						break;
					
						case TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_SUCCEEDED:
						case TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED: {
							tos_tifhal_tvinput_capture_result_t result;
							memset(&result,0,sizeof(result));
							result.deviceId = (int)data.readInt32();
							result.streamId = (int)data.readInt32();
							result.sequence = (int)data.readInt32();
							result.errCode = (int)data.readInt32();
							TOSLOGI("tifhal_input_callback client deviceId=0x%x(%d) streamId=0x%x sequence=%d errCode=%d\n",result.deviceId,result.deviceId,result.streamId,result.sequence,result.errCode);
							
							((tos_tifhal_tvinput_notify)_callback)(type,&result,_cookie);
						}
						break;

						default:
							CLOG_ASSERT(0,"tifhal_input_callback client unknown msg type %d",type);							
							((tos_tifhal_tvinput_notify)_callback)(type,NULL,_cookie);
						break;
					}			

                    reply->writeNoException();
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                break;
            }

            default:
                return BBinder::onTransact(code, data, reply, flags);
            }

            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };

	

public:  
    static remote_tifhal_helper_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance");
            _instance = new remote_tifhal_helper_client();
        }

        return _instance;
    }

    int tos_tifhal_tvinput_initialize( tos_tifhal_tvinput_notify callback, void* userdata ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_tvinput_initialize here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;

		//
		if(callback == NULL) {
			CLOGW_WITHCODE(TIFHAL_ERROR_PARAMTER_ERROR,"remote tos_tifhal_tvinput_initialize failed cb=%p ud=%p\n",callback,userdata);
			return TIFHAL_ERROR_PARAMTER_ERROR;
		}
		
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
            sp<Callback> ccb = new Callback((void*)callback,userdata);
            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_tifhal_tvinput_initialize,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if(_result == TIFHAL_ERROR_NO_ERROR) {
					_callback = ccb;
				}
            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_initialize error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_initialize error");
        }

        return _result;
        /*-- add you code for tos_tifhal_tvinput_initialize here --*/
    }

    int tos_tifhal_tvinput_get_stream_count( int deviceId ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_tvinput_get_stream_count here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(deviceId);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_tvinput_get_stream_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_get_stream_count error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_get_stream_count error");
        }

        return _result;
        /*-- add you code for tos_tifhal_tvinput_get_stream_count here --*/
    }

    int tos_tifhal_tvinput_get_stream_configurations( int deviceId, tos_tifhal_tvinput_tv_stream_config_t* configs, int maxCount ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_tvinput_get_stream_configurations here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(deviceId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (configs == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(maxCount));//write count, not the length, to use on 32-64bits
            }

            data.writeInt32(maxCount);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_tvinput_get_stream_configurations,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
                _result = (typeof(_result))reply.readInt32();//int as return value

                if (configs != NULL) {
					for(int i=0;i<_result && i<maxCount;i++) {
						configs[i].streamId = reply.readInt32();
						configs[i].maxVideoWidth= reply.readInt32();
						configs[i].maxVideoHeight= reply.readInt32();
					}
                }
            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_get_stream_configurations error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_get_stream_configurations error");
        }

        return _result;
        /*-- add you code for tos_tifhal_tvinput_get_stream_configurations here --*/
    }

    int tos_tifhal_tvinput_request_capture( int deviceId, int streamId, int sequence ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_tvinput_request_capture here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(deviceId);  //int as input paramter

            data.writeInt32(streamId);  //int as input paramter

            data.writeInt32(sequence);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_tvinput_request_capture,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_request_capture error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_request_capture error");
        }

        return _result;
        /*-- add you code for tos_tifhal_tvinput_request_capture here --*/
    }

    int tos_tifhal_tvinput_cancel_capture( int deviceId, int streamId, int sequence ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_tvinput_cancel_capture here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(deviceId);  //int as input paramter

            data.writeInt32(streamId);  //int as input paramter

            data.writeInt32(sequence);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_tvinput_cancel_capture,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_cancel_capture error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_tvinput_cancel_capture error");
        }

        return _result;
        /*-- add you code for tos_tifhal_tvinput_cancel_capture here --*/
    }
};

remote_tifhal_helper_client* remote_tifhal_helper_client::_instance = NULL;

int tos_tifhal_tvinput_initialize( tos_tifhal_tvinput_notify callback, void* userdata ) {
    return remote_tifhal_helper_client::Instance()->tos_tifhal_tvinput_initialize(callback, userdata);
}
int tos_tifhal_tvinput_get_stream_count( int deviceId ) {
    return remote_tifhal_helper_client::Instance()->tos_tifhal_tvinput_get_stream_count(deviceId);
}
int tos_tifhal_tvinput_get_stream_configurations( int deviceId, tos_tifhal_tvinput_tv_stream_config_t* configs, int maxCount ) {
    return remote_tifhal_helper_client::Instance()->tos_tifhal_tvinput_get_stream_configurations(deviceId, configs, maxCount);
}
int tos_tifhal_tvinput_request_capture( int deviceId, int streamId, int sequence ) {
    return remote_tifhal_helper_client::Instance()->tos_tifhal_tvinput_request_capture(deviceId, streamId, sequence);
}
int tos_tifhal_tvinput_cancel_capture( int deviceId, int streamId, int sequence ) {
    return remote_tifhal_helper_client::Instance()->tos_tifhal_tvinput_cancel_capture(deviceId, streamId, sequence);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
