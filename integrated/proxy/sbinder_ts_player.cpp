/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_ts_player.sidl
 */
 

#define LOG_TAG     "sbinder_ts_player"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_ts_player.h"
#include "fpi_error_code.h"
#include "fpi_base_type.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PLAY);


#define SERVICE_DESCRIPTOR                      "b9cd1fa8-b370-11e5-ad4d-005056a86db3"
#define SERVICE_NAME                            "sbinder_ts_player"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_ts_play_create_fifo FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_ts_play_env_init FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_ts_play_env_uninit FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_ts_play_init FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_ts_play_uninit FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_ts_play_set_param FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_ts_play_start FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_ts_play_pause FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_ts_play_resume FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_ts_play_stop FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_ts_play_push_data FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_ts_play_get_pts FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_ts_play_add_callback FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_ts_play_remove_callback FIRST_CALL_TRANSACTION + 14

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_tos_ts_player_callback_fn FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_ts_player.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>



class sbinder_ts_player_service : public BBinder  
{  
private:
    static sbinder_ts_player_service* _instance;
    RemoteCallbackList _cbList;
    bool _first;
    sbinder_ts_player_service():_first(true){
        CLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_ts_player_service() {
        CLOGI(SERVICE_NAME"_service destory\n");
    }

    static fpi_error module_callback(tos_en_play_event event,void *userData)
	{
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        fpi_error _result = 0;
        int size = rcbl->beginBroadcast();
        fpi_warn("module_callback 2 %d",size);
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);
			//void *param_save = rcbl->getBroadcastCookie(i);
	     void *userdata_save = rcbl->getBroadcastCookie(i);

            if(binder != NULL) {
                Parcel parcel_data, parcel_reply;

                parcel_data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                parcel_data.writeInt32(event);
                parcel_data.writeInt64((intptr_t)userdata_save);
			   
		  fpi_warn(SERVICE_NAME"event = %d userdata = %p", event, userData);
                fpi_warn("module_callback transact begin");
                binder->transact(TRANSACTION_CALLBACK_tos_ts_player_callback_fn, parcel_data, &parcel_reply, 0);
                fpi_warn("module_callback transact after");

                if(parcel_reply.readExceptionCode() == 0) {//fix check
                	_result = (typeof(_result))parcel_reply.readInt32();//int as return value
	            } else {
	                fpi_warn(SERVICE_NAME"_service module_callback return error");
	            }
            }
        }
        rcbl->finishBroadcast();

        fpi_warn(SERVICE_NAME"_service module_callback end");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_ts_player_service();
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

            case TRANSACTION_tos_ts_play_create_fifo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_create_fifo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_create_fifo(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_create_fifo here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_env_init:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_env_init here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_env_init(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_env_init here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_env_uninit:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_env_uninit here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_env_uninit(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_env_uninit here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_init:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_init here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_init(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_init here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_uninit:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_uninit here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_uninit(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_uninit here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_set_param:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_set_param here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t video_pid = (uint16_t)data.readInt32();  //uint16_t as input paramter

                uint16_t audio_pid = (uint16_t)data.readInt32();  //uint16_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_set_param( video_pid, audio_pid );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_set_param here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_start(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_start here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_pause(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_pause here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_resume(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_resume here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_stop here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_push_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_push_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t data_len = (uint16_t)data.readInt32();  //uint16_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_push_data( data_len );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_push_data here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_get_pts:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_play_get_pts here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _n32_pts_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* n32_pts = NULL;

                Parcel::WritableBlob _n32_pts_wblob;

                if(_n32_pts_len > 0) {
                    reply->writeInt32(_n32_pts_len);
                    reply->writeBlob(_n32_pts_len,&_n32_pts_wblob);
                    n32_pts = (int32_t*)_n32_pts_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                n32_pts = (int32_t*)_n32_pts_wblob.data();
                fpi_error _result = tos_ts_play_get_pts( n32_pts );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ts_play_get_pts here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_player_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

		sp<IBinder> binder = data.readStrongBinder();
				
   		#if 0
                //begin paramters list
                tos_event_handle_t cb = (tos_event_handle_t)data.readInt32();  //tos_event_handle_t as input paramter

                int _userData_len = data.readInt32(); //read length, only 32bits length support yet
                void* userData = NULL;

                Parcel::ReadableBlob _userData_rblob;

                if(_userData_len > 0) {
                    data.readBlob(_userData_len,&_userData_rblob);
                    userData = (void*)_userData_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                userData = (void*)_userData_rblob.data();
                fpi_error _result = tos_ts_play_add_callback( cb, userData );

                reply->writeInt32(_result); //fpi_error as return value
                #endif
		  if (binder != NULL)
				{
                    fpi_error _result = FPI_ERROR_SUCCESS;

                    //void *param = (void *)data.readIntPtr();
					void *userdata = (void *)data.readInt64();

                    if(_first) {
                        _result = tos_ts_play_add_callback(sbinder_ts_player_service::module_callback, userdata);
                        if(_result == FPI_ERROR_SUCCESS) {
                            _first = false;
                        }
                    }

                    if(_result == FPI_ERROR_SUCCESS) {
                        if(_cbList.registerCallback(binder,userdata)) {
                            reply->writeNoException();
                            reply->writeInt32(_result); //int as return value
                        }
                        else {
                            reply->writeInt32(-3);//Exception
                        }
                    }
                    else {
                        reply->writeInt32(-2);//Exception
                    }
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_ts_player_add_callback here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ts_play_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ts_player_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                #if 0
                //begin paramters list
                tos_event_handle_t cb = (tos_event_handle_t)data.readInt32();  //tos_event_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ts_play_remove_callback( cb );

                reply->writeInt32(_result); //fpi_error as return value
                #endif
                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                    _first = true;
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_ts_player_remove_callback here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        CLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_ts_player_service_add() {
    sbinder_ts_player_service::Instance();
    return 0;
}

sbinder_ts_player_service* sbinder_ts_player_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>


class sbinder_ts_player_client  
{  
private:
    static sbinder_ts_player_client* _instance;
    sp<IBinder> _binder;
	ICallbackList _CBList;
    sbinder_ts_player_client()
        :_binder(NULL) {
        CLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_ts_player_client() {
        CLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            CLOGW(SERVICE_NAME"_client getFailed!\n");
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

        virtual status_t onTransact( uint32_t code,const Parcel& data,Parcel* reply,uint32_t flags = 0) {
            fpi_warn(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_tos_ts_player_callback_fn:
            {
                fpi_warn("ontransact callback fn");
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					fpi_error _result = FPI_ERROR_SUCCESS;
                    fpi_warn("ontransact callback fn 1");
			tos_en_play_event event = (tos_en_play_event)data.readInt32();
			
                    void *userdata = (void *)data.readIntPtr();


	                    _result = ((tos_event_handle_t)_callback)(event, userdata);
					//}

                    reply->writeNoException();
                    reply->writeInt32(_result);
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                break;
            }

            default:
                return BBinder::onTransact(code, data, reply, flags);
            }

            fpi_warn(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };

public:  
    static sbinder_ts_player_client* Instance() {
        if(_instance == NULL) {
            CLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_ts_player_client();
        }

        return _instance;
    }

    fpi_error tos_ts_play_create_fifo(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_create_fifo here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_create_fifo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_create_fifo error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_create_fifo error");
        }

        return _result;
        /*-- add you code for tos_ts_play_create_fifo here --*/
    }

    fpi_error tos_ts_play_env_init(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_env_init here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_env_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_env_init error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_env_init error");
        }

        return _result;
        /*-- add you code for tos_ts_play_env_init here --*/
    }

    fpi_error tos_ts_play_env_uninit(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_env_uninit here --*/
        fpi_error _result= FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_env_uninit,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_env_uninit error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_env_uninit error");
        }

        return _result;
        /*-- add you code for tos_ts_play_env_uninit here --*/
    }

    fpi_error tos_ts_play_init(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_init here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_init error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_init error");
        }

        return _result;
        /*-- add you code for tos_ts_play_init here --*/
    }

    fpi_error tos_ts_play_uninit(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_uninit here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_uninit,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_uninit error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_uninit error");
        }

        return _result;
        /*-- add you code for tos_ts_play_uninit here --*/
    }

    fpi_error tos_ts_play_set_param( uint16_t video_pid, uint16_t audio_pid ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_set_param here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(video_pid);  //uint16_t as input paramter

            data.writeInt32(audio_pid);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_ts_play_set_param,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_set_param error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_set_param error");
        }

        return _result;
        /*-- add you code for tos_ts_play_set_param here --*/
    }

    fpi_error tos_ts_play_start(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_start error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_start error");
        }

        return _result;
        /*-- add you code for tos_ts_play_start here --*/
    }

    fpi_error tos_ts_play_pause(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_pause here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_pause error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_pause error");
        }

        return _result;
        /*-- add you code for tos_ts_play_pause here --*/
    }

    fpi_error tos_ts_play_resume(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_resume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_resume error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_resume error");
        }

        return _result;
        /*-- add you code for tos_ts_play_resume here --*/
    }

    fpi_error tos_ts_play_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ts_play_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_stop error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_stop error");
        }

        return _result;
        /*-- add you code for tos_ts_play_stop here --*/
    }

    fpi_error tos_ts_play_push_data( uint16_t data_len ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_push_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(data_len);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_ts_play_push_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_push_data error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_push_data error");
        }

        return _result;
        /*-- add you code for tos_ts_play_push_data here --*/
    }

    fpi_error tos_ts_play_get_pts( int32_t* n32_pts ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_play_get_pts here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (n32_pts == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ts_play_get_pts,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (n32_pts != NULL) {
                    int _n32_pts_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _n32_pts_rblob;
                    reply.readBlob(_n32_pts_len,&_n32_pts_rblob);
                    memcpy(n32_pts,_n32_pts_rblob.data(),_n32_pts_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_play_get_pts error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_play_get_pts error");
        }

        return _result;
        /*-- add you code for tos_ts_play_get_pts here --*/
    }

    fpi_error tos_ts_play_add_callback( tos_event_handle_t cb, void* userData ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_player_add_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
	if (NULL == cb)
		{
            CLOGW(SERVICE_NAME"_client tos_ts_player_add_callback NULL callbak");
            return _result;
		}

        if(_CBList.findCallback((void*)cb, NULL) != NULL) {
            CLOGW(SERVICE_NAME"_client tos_ts_player_add_callback cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            sp<Callback> ccb = new Callback((void*)cb, NULL);
            data.writeStrongBinder(ccb);
	     data.writeInt64((int64_t)userData);

            //data.writeInt32(cb);  //tos_event_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            /*if (userData == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(void));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _userData_wblob;
                data.writeBlob((1) * sizeof(void),&_userData_wblob);
                memcpy(_userData_wblob.data(),userData,(1)* sizeof(void));
            }*/

            _binder->transact(TRANSACTION_tos_ts_play_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value
                if(_result == FPI_ERROR_SUCCESS) { //success
                        _CBList.addCallback(ccb);
                }

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_player_add_callback error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_player_add_callback error");
        }

        return _result;
        /*-- add you code for tos_ts_player_add_callback here --*/
    }

    fpi_error tos_ts_play_remove_callback( tos_event_handle_t cb ) {
        Parcel data, reply;

        /*-- add you code for tos_ts_player_remove_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
	sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)cb, (void*)NULL);
        if(ccb == NULL) {
            CLOGW(SERVICE_NAME"_client tos_ts_player_remove_callback cb not added");
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            data.writeStrongBinder(ccb);

            //data.writeInt32(cb);  //tos_event_handle_t as input paramter

            _binder->transact(TRANSACTION_tos_ts_play_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value
                if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                	}

            } else {
                CLOGW(SERVICE_NAME"_client tos_ts_player_remove_callback error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_ts_player_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_ts_player_remove_callback here --*/
    }
};

sbinder_ts_player_client* sbinder_ts_player_client::_instance = NULL;

fpi_error tos_ts_play_create_fifo(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_create_fifo();
}
fpi_error tos_ts_play_env_init(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_env_init();
}
fpi_error tos_ts_play_env_uninit(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_env_uninit();
}
fpi_error tos_ts_play_init(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_init();
}
fpi_error tos_ts_play_uninit(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_uninit();
}
fpi_error tos_ts_play_set_param( uint16_t video_pid, uint16_t audio_pid ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_set_param(video_pid, audio_pid);
}
fpi_error tos_ts_play_start(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_start();
}
fpi_error tos_ts_play_pause(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_pause();
}
fpi_error tos_ts_play_resume(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_resume();
}
fpi_error tos_ts_play_stop(  ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_stop();
}
fpi_error tos_ts_play_push_data( uint16_t data_len ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_push_data(data_len);
}
fpi_error tos_ts_play_get_pts( int32_t* n32_pts ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_get_pts(n32_pts);
}
fpi_error tos_ts_play_add_callback( tos_event_handle_t cb, void* userData ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_add_callback(cb, userData);
}
fpi_error tos_ts_play_remove_callback( tos_event_handle_t cb ) {
    return sbinder_ts_player_client::Instance()->tos_ts_play_remove_callback(cb);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
