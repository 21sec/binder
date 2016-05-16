/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_audio_module.sidl
 */
 

#define LOG_TAG     "remote_itv_audio_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_defines.h"
#include "itv_audio.h"

#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);

#define SERVICE_DESCRIPTOR                      "5a6b1d26-1334-11e5-a92a-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_audio_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_audio_open FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_audio_close FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_audio_start FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_audio_stop FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_audio_pause FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_itv_audio_resume FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_itv_audio_set_sync FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_itv_audio_set_channel_mode FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_itv_audio_get_pts FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_itv_audio_set_source_type FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_itv_audio_get_frame_num FIRST_CALL_TRANSACTION + 11


using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG "remote_itv_audio_module"

#include <stdlib.h>

#include "clog.h"
#include "remote_itv_audio_module.h"

class remote_itv_audio_module_service : public BBinder  
{  
private:
    static remote_itv_audio_module_service* _instance;

    remote_itv_audio_module_service(){
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_audio_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_audio_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            // TOSLOGI(SERVICE_NAME"_service Instance ret = %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        // TOSLOGI(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_audio_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _handle_len = data.readInt32(); //read length, only 32bits length support yet
                itv_handle_t* handle = NULL;

                Parcel::WritableBlob _handle_wblob;

                if(_handle_len > 0) {
                    reply->writeInt32(_handle_len);
                    reply->writeBlob(_handle_len,&_handle_wblob);
                    handle = (itv_handle_t*)_handle_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                handle = (itv_handle_t*)_handle_wblob.data();
                int _result = itv_audio_open( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_close( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                itv_audio_start_param_t _param_Struct;
				memset(&_param_Struct, 0, sizeof(itv_audio_start_param_t));
				
				const itv_audio_start_param_t* param = NULL;
				
				int _flag = data.readInt32();
				if(_flag > 0) {
					_param_Struct.demuxId = data.readInt32();
					_param_Struct.aType = (itv_audio_stream_type_t)data.readInt32();
					param = &_param_Struct;
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_start( handle, param );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_stop( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_pause( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_resume( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_resume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_set_sync:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_set_sync here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter
				itv_av_sync_mode_t mode = (itv_av_sync_mode_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_set_sync( handle, mode );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_set_sync here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_set_channel_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_set_channel_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_channel_mode_t mode = (itv_channel_mode_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_set_channel_mode( handle, mode );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_set_channel_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_audio_get_pts:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_get_pts here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _pts_len = data.readInt32(); //read length, only 32bits length support yet
                unsigned long long* pts = NULL;

                Parcel::WritableBlob _pts_wblob;

                if(_pts_len > 0) {
                    reply->writeInt32(_pts_len);
                    reply->writeBlob(_pts_len,&_pts_wblob);
                    pts = (unsigned long long*)_pts_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pts = (unsigned long long*)_pts_wblob.data();
                int _result = itv_audio_get_pts( handle, pts );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_get_pts here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_itv_audio_set_source_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_set_channel_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

				itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_audio_source_type_t source_type = (itv_audio_source_type_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_audio_set_source_type(handle, source_type);

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_set_channel_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;

            } break;   
			case TRANSACTION_itv_audio_get_frame_num:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_get_frame_num here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _flag = data.readInt32(); //read length, only 32bits length support yet
                unsigned int _num = 0;
                unsigned int* num = (_flag > 0) ? &_num : NULL;

                int _result = itv_audio_get_frame_num( handle, num );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0) {
                    reply->writeInt32(*num); //int as return value
                }

                //-- end code for itv_audio_get_frame_num here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        // TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_audio_module_service_add() {
    remote_itv_audio_module_service::Instance();
    return 0;
}

remote_itv_audio_module_service* remote_itv_audio_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG "remote_itv_audio_module"

#include "clog.h"

class remote_itv_audio_module_client  
{  
private:
    static remote_itv_audio_module_client* _instance;
    sp<IBinder> _binder;

    remote_itv_audio_module_client()
        :_binder(NULL) {
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_audio_module_client() {
        // TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            // TOSLOGW(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static remote_itv_audio_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_audio_module_client();
        }

        return _instance;
    }

    int itv_audio_open( itv_handle_t* handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_open()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_open here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (handle == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_handle_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_itv_audio_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (handle != NULL) {
                    int _handle_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _handle_rblob;
                    reply.readBlob(_handle_len,&_handle_rblob);
                    memcpy(handle,_handle_rblob.data(),_handle_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_open error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_open error\n");
        }

        return _result;
        /*-- add you code for itv_audio_open here --*/
    }

    int itv_audio_close( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_close()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_close here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_audio_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_close error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_close error\n");
        }

        return _result;
        /*-- add you code for itv_audio_close here --*/
    }

    int itv_audio_start( itv_handle_t handle, const itv_audio_start_param_t* param ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_start()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_start here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            if (param == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_audio_start_param_t));//write length, only support 32 bits length yet
				data.writeInt32(param->demuxId);
                data.writeInt32(param->aType);
            }

            _binder->transact(TRANSACTION_itv_audio_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_start error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_start error\n");
        }

        return _result;
        /*-- add you code for itv_audio_start here --*/
    }

    int itv_audio_stop( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_stop()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_stop here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_audio_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_stop error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_stop error\n");
        }

        return _result;
        /*-- add you code for itv_audio_stop here --*/
    }

    int itv_audio_pause( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_pause()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_pause here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_audio_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_pause error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_pause error\n");
        }

        return _result;
        /*-- add you code for itv_audio_pause here --*/
    }

    int itv_audio_resume( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_resume()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_resume here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_audio_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_resume error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_resume error\n");
        }

        return _result;
        /*-- add you code for itv_audio_resume here --*/
    }

    int itv_audio_set_sync( itv_handle_t handle, itv_av_sync_mode_t mode ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_set_sync()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_set_sync here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(mode); 

            _binder->transact(TRANSACTION_itv_audio_set_sync,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_set_sync error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_set_sync error\n");
        }

        return _result;
        /*-- add you code for itv_audio_set_sync here --*/
    }

    int itv_audio_set_channel_mode( itv_handle_t handle, itv_channel_mode_t mode ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_set_channel_mode()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_set_channel_mode here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(mode); 

            _binder->transact(TRANSACTION_itv_audio_set_channel_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
        }

        return _result;
        /*-- add you code for itv_audio_set_channel_mode here --*/
    }

    int itv_audio_get_pts( itv_handle_t handle, unsigned long long* pts ) {
		// TOSLOGI(SERVICE_NAME"_client itv_audio_get_pts()\n");
        Parcel data, reply;

        /*-- add you code for itv_audio_get_pts here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pts == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(unsigned long long));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_itv_audio_get_pts,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pts != NULL) {
                    int _pts_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pts_rblob;
                    reply.readBlob(_pts_len,&_pts_rblob);
                    memcpy(pts,_pts_rblob.data(),_pts_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_audio_get_pts error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_audio_get_pts error\n");
        }

        return _result;
        /*-- add you code for itv_audio_get_pts here --*/
    }

int itv_audio_set_source_type( itv_handle_t handle, itv_audio_source_type_t source_type ) {
	// TOSLOGI(SERVICE_NAME"_client itv_audio_set_channel_mode()\n");
	Parcel data, reply;

	/*-- add you code for itv_audio_set_channel_mode here --*/
	int _result = ITV_ERR_FAILED;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

		data.writeInt32(handle);  //itv_handle_t as input paramter

		data.writeInt32(source_type); 

		_binder->transact(TRANSACTION_itv_audio_set_source_type,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check

			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			// TOSLOGW(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
		}
	}catch(...) {
		// TOSLOGE(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
	}

	return _result;
	/*-- add you code for itv_audio_set_channel_mode here --*/
}

int itv_audio_get_frame_num( itv_handle_t handle, unsigned int* num ) {
	// TOSLOGI(SERVICE_NAME"_client itv_video_get_frame_num()\n");
	Parcel data, reply;

	/*-- add you code for itv_video_get_frame_num here --*/
	int _result = ITV_ERR_FAILED;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

		data.writeInt32(handle);  //itv_handle_t as input paramter

		//for out only, only write length ; for in, alloc and copy
		if (num == NULL) {
			data.writeInt32(-1);
		}
		else {
			data.writeInt32((unsigned int)(1) * sizeof(unsigned int));//write length, only support 32 bits length yet
		}

		_binder->transact(TRANSACTION_itv_audio_get_frame_num,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check
		
			_result = (typeof(_result))reply.readInt32();//int as return value
			if (num != NULL) {
				*num = (unsigned int)reply.readInt32(); //read length, only 32bits length support yet
			}

		} else {
			// TOSLOGW(SERVICE_NAME"_client itv_audio_get_frame_num error\n");
		}
	}catch(...) {
		// TOSLOGE(SERVICE_NAME"_client itv_audio_get_frame_num error\n");
	}

	return _result;
	/*-- add you code for itv_audio_get_frame_num here --*/
}

};

remote_itv_audio_module_client* remote_itv_audio_module_client::_instance = NULL;

int itv_audio_open( itv_handle_t* handle ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_open(handle);
}
int itv_audio_close( itv_handle_t handle ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_close(handle);
}
int itv_audio_start( itv_handle_t handle, const itv_audio_start_param_t* param ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_start(handle, param);
}
int itv_audio_stop( itv_handle_t handle ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_stop(handle);
}
int itv_audio_pause( itv_handle_t handle ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_pause(handle);
}
int itv_audio_resume( itv_handle_t handle ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_resume(handle);
}
int itv_audio_set_sync( itv_handle_t handle, itv_av_sync_mode_t mode ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_set_sync(handle, mode);
}
int itv_audio_set_channel_mode( itv_handle_t handle, itv_channel_mode_t mode ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_set_channel_mode(handle, mode);
}
int itv_audio_get_pts( itv_handle_t handle, unsigned long long* pts ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_get_pts(handle, pts);
}

int itv_audio_set_source_type(itv_handle_t handle, itv_audio_source_type_t source_type) {
    return remote_itv_audio_module_client::Instance()->itv_audio_set_source_type(handle, source_type);
}

int itv_audio_get_frame_num( itv_handle_t handle, unsigned int* num ) {
    return remote_itv_audio_module_client::Instance()->itv_audio_get_frame_num(handle, num);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
