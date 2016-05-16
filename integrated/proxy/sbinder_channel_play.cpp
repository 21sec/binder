/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_channel_play.sidl
 */
 

#define LOG_TAG     "sbinder_channel_play"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_channel_play.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PLAY);


#define SERVICE_DESCRIPTOR                      "b53854fe-c2e3-11e4-9cb0-005056a84a3b"
#define SERVICE_NAME                            "sbinder_channel_play"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_channel_play_get_current_channel_info FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_channel_play_get_current_channel_id FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_channel_play FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_channel_play_delivery FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_channel_play_unlock FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_channel_play_relock FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_channel_play_set_lock_status FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_channel_play_stop FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_channel_play_get_status FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_channel_play_get_srceen_mode_info FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_channel_play_add_callback FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_channel_play_remove_callback FIRST_CALL_TRANSACTION + 12

#define TRANSACTION_tos_channel_play_stream FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_channel_play_get_current_stream_info FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_channel_play_stop_stream  FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_channel_play_set_flag  FIRST_CALL_TRANSACTION + 16

#define TRANSACTION_tos_dtv_set_channel_play_update_status FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_dtv_get_channel_play_update_status FIRST_CALL_TRANSACTION + 18

 


#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_tos_channel_play_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_channel_play.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

class sbinder_channel_play_service : public BBinder  
{  
private:
    static sbinder_channel_play_service* _instance;

    RemoteCallbackList _cbList;
    bool _first;

    sbinder_channel_play_service():_first(true) {
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_channel_play_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

    static fpi_error module_callback(EN_TOS_DTV_PLAY_CB_EVENT_E eventType, int code, int data, void* userdata)
	{
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        fpi_error _result = FPI_ERROR_FAIL ;
        int size = rcbl->beginBroadcast();
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);
			void *userdata_save = rcbl->getBroadcastCookie(i);

            if(binder != NULL) {
                Parcel parcel_data, parcel_reply;

                parcel_data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                parcel_data.writeInt32(eventType);
                parcel_data.writeInt32(code);
                parcel_data.writeInt32(data);

				parcel_data.writeInt64((intptr_t)userdata_save);

                binder->transact(TRANSACTION_CALLBACK_tos_channel_play_callback, parcel_data, &parcel_reply, 0);

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
            _instance = new sbinder_channel_play_service();
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

            case TRANSACTION_tos_channel_play_get_current_channel_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_get_current_channel_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _play_info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_dtv_play_info_t* play_info = NULL;
				Parcel::WritableBlob _play_info_wblob;

                if(_play_info_len > 0) {
                    reply->writeInt32(_play_info_len);
                    reply->writeBlob(_play_info_len,&_play_info_wblob);
                    play_info = (tos_dtv_play_info_t*)_play_info_wblob.data();
                }

                fpi_error _result = tos_channel_play_get_current_channel_info( play_info );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_get_current_channel_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_stream:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
              //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				EN_TOS_DTV_PLAY_ID_E play_id =(EN_TOS_DTV_PLAY_ID_E)data.readInt32();

                //begin paramters list
                int _play_info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_channel_play_stream_info * play_info = NULL;
					Parcel::ReadableBlob _pin_rblob;
				if (_play_info_len > 0)
				{
		
					data.readBlob(_play_info_len, &_pin_rblob);
					play_info = (tos_channel_play_stream_info*)_pin_rblob.data();
				}
                fpi_error _result = tos_channel_play_stream( play_id,play_info);
                reply->writeInt32(_result); //int as return value

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_channel_play_get_current_stream_info:
            {
			data.enforceInterface(String16(SERVICE_NAME));	//fixed check
			//skip Exception and result first to write output paramters
			reply->writeNoException();
			//skip Exception and result first end
			EN_TOS_DTV_PLAY_ID_E play_id =(EN_TOS_DTV_PLAY_ID_E)data.readInt32();
			
			EN_TOS_DTV_PLAY_TYPE_E type =(EN_TOS_DTV_PLAY_TYPE_E)data.readInt32();
			//begin paramters list
			int _play_info_len = data.readInt32(); //read length, only 32bits length support yet
			tos_channel_stream_info * play_info = NULL;
			Parcel::WritableBlob _play_info_wblob;
			if(_play_info_len > 0) {
				reply->writeInt32(_play_info_len);
				
				reply->writeBlob(_play_info_len,&_play_info_wblob);
				play_info = (tos_channel_stream_info*)_play_info_wblob.data();
			}
			fpi_error _result = tos_channel_play_get_current_stream_info( play_id,type,play_info);

			reply->writeInt32(_result); //int as return value
                	fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_channel_play_stop_stream:
            {
			data.enforceInterface(String16(SERVICE_NAME));	//fixed check
			//skip Exception and result first to write output paramters
			reply->writeNoException();
			//skip Exception and result first end
			EN_TOS_DTV_PLAY_ID_E play_id =(EN_TOS_DTV_PLAY_ID_E)data.readInt32();
			//begin paramters list
			EN_TOS_DTV_PLAY_STOP_TYPE_E stop_type=(EN_TOS_DTV_PLAY_STOP_TYPE_E)data.readInt32();

			fpi_error _result = tos_channel_play_stop_stream( play_id,stop_type);
			
			reply->writeInt32(_result); //int as return value
			fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;

            } break;

			
            case TRANSACTION_tos_channel_play_get_current_channel_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                int _channelId_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t channelId = 0;
				uint32_t *pId = NULL;
				if (_channelId_len > 0)
				{
					pId = &channelId;
				}

                fpi_error _result  = tos_channel_play_get_current_channel_id( pId );
				reply->writeInt32(*pId); 
                reply->writeInt32(_result); //int as return value

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t channelId = (int)data.readInt32();  //int as input paramter

                fpi_error _result = tos_channel_play( channelId );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_delivery:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_delivery here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_dtv_play_info_t* info = NULL;
				Parcel::ReadableBlob _info_rblob;

                if(_info_len > 0) {
                    data.readBlob(_info_len,&_info_rblob);
                    info = (tos_dtv_play_info_t*)_info_rblob.data();
                }

                fpi_error _result = tos_channel_play_delivery( info );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_delivery here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_unlock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_unlock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_channel_play_unlock(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_unlock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_relock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_relock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_channel_play_relock(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_relock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_set_lock_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_set_lock_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool locked = (int)data.readInt32();  //int as input paramter

                fpi_error _result = tos_channel_play_set_lock_status( locked );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_set_lock_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_channel_play_stop(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_get_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_get_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _status_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_DTV_PLAY_STATE* status = NULL;
				Parcel::WritableBlob _status_wblob;

                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    reply->writeBlob(_status_len,&_status_wblob);
                    status = (EN_FPI_DTV_PLAY_STATE*)_status_wblob.data();
                }

                fpi_error _result = tos_channel_play_get_status( status );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_get_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_channel_play_set_flag:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_get_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                int playid = data.readInt32(); //read length, only 32bits length support yet

                //begin paramters list
                int _status_len = data.readInt32(); //read length, only 32bits length support yet
                int* b_allow_video = NULL;
		Parcel::WritableBlob _status_wblob;

                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    reply->writeBlob(_status_len,&_status_wblob);
                    b_allow_video = (int*)_status_wblob.data();
                }
                 _status_len = data.readInt32(); //read length, only 32bits length support yet
				
                int* b_allow_audio = NULL;
		Parcel::WritableBlob _status_wblob2;
                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    reply->writeBlob(_status_len,&_status_wblob2);
                    b_allow_audio = (int*)_status_wblob2.data();
                }
                fpi_error _result = tos_channel_play_set_flag((EN_TOS_DTV_PLAY_ID_E) playid,b_allow_video,b_allow_audio);
                reply->writeInt32(_result); //int as return value
                //-- end code for tos_channel_play_get_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			
            case TRANSACTION_tos_channel_play_get_srceen_mode_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_channel_play_get_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _status_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_DTV_SS_MODE *mode = NULL;
				Parcel::WritableBlob _status_wblob;

                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    reply->writeBlob(_status_len,&_status_wblob);
                    mode = (EN_TOS_DTV_SS_MODE*)_status_wblob.data();
                }

                fpi_error _result = tos_channel_play_get_srceen_mode_info( mode );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_channel_play_get_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_channel_play_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                sp<IBinder> binder = data.readStrongBinder();

                if (binder != NULL)
				{
                    fpi_error _result = FPI_ERROR_SUCCESS;

					void *userdata = (void *)data.readInt64();

                    if(_first) {
                        _result = tos_channel_play_add_callback(sbinder_channel_play_service::module_callback, userdata);
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

                //-- end code for tos_dtv_scan_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_play_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_dtv_scan_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_set_channel_play_update_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_set_channel_play_update_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool status_flag = (fpi_bool)data.readInt32();  //int as input paramter

                fpi_error _result = tos_dtv_set_channel_play_update_status(status_flag);

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tv_scan_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            case TRANSACTION_tos_dtv_get_channel_play_update_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_get_channel_play_update_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end


                fpi_bool _result = tos_dtv_get_channel_play_update_status();

                reply->writeInt32((int32_t)_result); //int as return value

                //-- end code for tos_tv_scan_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_channel_play_service_add() {
    sbinder_channel_play_service::Instance();
    return 0;
}

sbinder_channel_play_service* sbinder_channel_play_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>

class sbinder_channel_play_client  
{  
private:
    static sbinder_channel_play_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_channel_play_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_channel_play_client() {
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
            fpi_info(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_tos_channel_play_callback:
            {
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					fpi_error _result = FPI_ERROR_SUCCESS;

					EN_TOS_DTV_PLAY_CB_EVENT_E eventType = (EN_TOS_DTV_PLAY_CB_EVENT_E)data.readInt32();
					int int_code = data.readInt32();
					int int_data = data.readInt32();
					void *userdata = (void *)data.readIntPtr();

					if (userdata == _cookie)
					{
	                   			 _result = ((tos_dtv_channel_callback)_callback)(eventType, int_code, int_data, userdata);
					}

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

            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };

public:  
    static sbinder_channel_play_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_channel_play_client();
        }

        return _instance;
    }

    fpi_error tos_channel_play_get_current_channel_info( tos_dtv_play_info_t* play_info ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_get_current_channel_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (play_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(tos_dtv_play_info_t));//write length, only support 32 bits length yet              
            }

            _binder->transact(TRANSACTION_tos_channel_play_get_current_channel_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (play_info != NULL) {
                    int _play_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _play_info_rblob;
                    reply.readBlob(_play_info_len,&_play_info_rblob);
                    memcpy(play_info,_play_info_rblob.data(),_play_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_get_current_channel_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_get_current_channel_info error");
        }

        return _result;
        /*-- add you code for tos_channel_play_get_current_channel_info here --*/
    }

    fpi_error tos_channel_play_get_current_channel_id( uint32_t* channelId ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_get_current_channel_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (channelId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(uint32_t));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_channel_play_get_current_channel_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				*channelId = reply.readInt32();
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_get_current_channel_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_get_current_channel_id error");
        }

        return _result;
        /*-- add you code for tos_channel_play_get_current_channel_id here --*/
    }

    fpi_error tos_channel_play( uint32_t channelId ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

            _binder->transact(TRANSACTION_tos_channel_play,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play error");
        }

        return _result;
        /*-- add you code for tos_channel_play here --*/
    }

    fpi_error tos_channel_play_delivery( const tos_dtv_play_info_t* info ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_delivery here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			Parcel::WritableBlob _info_wblob;

            //for out only, only write length ; for in, alloc and copy
            if (info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_dtv_play_info_t));//write length, only support 32 bits length yet
                
                data.writeBlob((1) * sizeof(tos_dtv_play_info_t),&_info_wblob);
                memcpy(_info_wblob.data(),info,(1)* sizeof(tos_dtv_play_info_t));
            }

            _binder->transact(TRANSACTION_tos_channel_play_delivery,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_delivery error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_delivery error");
        }

        return _result;
        /*-- add you code for tos_channel_play_delivery here --*/
    }

    fpi_error tos_channel_play_unlock(  ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_unlock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_channel_play_unlock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_unlock error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_unlock error");
        }

        return _result;
        /*-- add you code for tos_channel_play_unlock here --*/
    }

    fpi_error tos_channel_play_relock(  ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_relock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_channel_play_relock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_relock error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_relock error");
        }

        return _result;
        /*-- add you code for tos_channel_play_relock here --*/
    }

    fpi_error tos_channel_play_set_lock_status( fpi_bool locked ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_set_lock_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(locked);  //int as input paramter

            _binder->transact(TRANSACTION_tos_channel_play_set_lock_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_set_lock_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_set_lock_status error");
        }

        return _result;
        /*-- add you code for tos_channel_play_set_lock_status here --*/
    }

    fpi_error tos_channel_play_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_channel_play_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_stop error");
        }

        return _result;
        /*-- add you code for tos_channel_play_stop here --*/
    }

    fpi_error tos_channel_play_get_status( EN_FPI_DTV_PLAY_STATE* status ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_get_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (status == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_channel_play_get_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (status != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(status,_status_rblob.data(),_status_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
        }

        return _result;
        /*-- add you code for tos_channel_play_get_status here --*/
    }
  fpi_error tos_channel_play_set_flag(EN_TOS_DTV_PLAY_ID_E play_id,int *b_allow_video,int *b_allow_audio){
        Parcel data, reply;

        /*-- add you code for tos_channel_play_get_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(play_id);

            //for out only, only write length ; for in, alloc and copy
            if (b_allow_video == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }
            if (b_allow_audio == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_channel_play_set_flag,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (b_allow_video != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(b_allow_video,_status_rblob.data(),_status_len);
                }
                if (b_allow_audio != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(b_allow_audio,_status_rblob.data(),_status_len);
                }				
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
        }

        return _result;
        /*-- add you code for tos_channel_play_get_status here --*/
    }    
		fpi_error tos_channel_play_get_srceen_mode_info(EN_TOS_DTV_SS_MODE *mode) {
        Parcel data, reply;

        /*-- add you code for tos_channel_play_get_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_channel_play_get_srceen_mode_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(mode,_status_rblob.data(),_status_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_get_status error");
        }

        return _result;
        /*-- add you code for tos_channel_play_get_status here --*/
    }

    fpi_error tos_channel_play_add_callback( tos_dtv_channel_callback callback, void* userdata ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_add_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

		if (NULL == callback)
		{
            fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback NULL callbak");
            return _result;
		}

        if(_CBList.findCallback((void*)callback, NULL) != NULL) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            sp<Callback> ccb = new Callback((void*)callback, NULL);
            data.writeStrongBinder(ccb);
			data.writeInt64((int64_t)userdata);

            _binder->transact(TRANSACTION_tos_channel_play_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SIGNAL_SUCCESS) { //success
                    _CBList.addCallback(ccb);
                }

            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_add_callback here --*/
    }

    fpi_error tos_channel_play_remove_callback( tos_dtv_channel_callback callback ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_remove_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

		if (NULL == callback)
		{
            fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback NULL callbak or error port");
            return _result;
		}

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)callback, (void*)NULL);
        if(ccb == NULL) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_channel_play_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_remove_callback here --*/
    }

	fpi_error tos_channel_play_stream(EN_TOS_DTV_PLAY_ID_E play_id ,tos_channel_play_stream_info *p_stream_info)  {
		Parcel data, reply;

		fpi_error _result = FPI_ERROR_FAIL;
		if(!getService()) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(play_id);  //int as input paramter
			Parcel::WritableBlob _info_wblob;

			//for out only, only write length ; for in, alloc and copy
			if (p_stream_info == NULL) {
				data.writeInt32(-1);
			}
			else {
				data.writeInt32((int)(1) * sizeof(tos_channel_play_stream_info));//write length, only support 32 bits length yet
				data.writeBlob((1) * sizeof(tos_channel_play_stream_info),&_info_wblob);
				memcpy(_info_wblob.data(),p_stream_info,(1)* sizeof(tos_channel_play_stream_info));
			}


			_binder->transact(TRANSACTION_tos_channel_play_stream,data, &reply,0);

			if(reply.readExceptionCode() == 0) {//fix check

				_result = (typeof(_result))reply.readInt32();//int as return value

			} else {
				TOSLOGW(SERVICE_NAME"_client tos_channel_play_stream error");
			}
		}catch(...) {
			TOSLOGW(SERVICE_NAME"_client tos_channel_play_stream error");
		}

		return _result;
	}

	fpi_error tos_channel_play_get_current_stream_info(EN_TOS_DTV_PLAY_ID_E play_id ,EN_TOS_DTV_PLAY_TYPE_E type,tos_channel_stream_info *p_stream_info)  {
		Parcel data, reply;

		fpi_error _result = FPI_ERROR_FAIL;
		if(!getService()) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(play_id);  //int as input paramter
			data.writeInt32(type);  //int as input paramter

			//for out only, only write length ; for in, alloc and copy
			if (p_stream_info == NULL) {
				data.writeInt32(-1);
			}
			else {
				data.writeInt32(sizeof(tos_channel_stream_info));//write length, only support 32 bits length yet			  
			}

			_binder->transact(TRANSACTION_tos_channel_play_get_current_stream_info,data, &reply,0);

			if(reply.readExceptionCode() == 0) {//fix check

				if (p_stream_info != NULL) {
					int _play_info_len = reply.readInt32(); //read length, only 32bits length support yet
					Parcel::ReadableBlob _play_info_rblob;
					reply.readBlob(_play_info_len,&_play_info_rblob);
					memcpy(p_stream_info,_play_info_rblob.data(),_play_info_len);
				}
				_result = (typeof(_result))reply.readInt32();//int as return value

			} else {
				TOSLOGW(SERVICE_NAME"_client tos_channel_play_get_current_stream_info error");
			}
		}catch(...) {
			TOSLOGW(SERVICE_NAME"_client tos_channel_play_get_current_stream_info error");
		}

		return _result;
	}

	fpi_error tos_channel_play_stop_stream(EN_TOS_DTV_PLAY_ID_E  play_id,EN_TOS_DTV_PLAY_STOP_TYPE_E stop_type)   {
		Parcel data, reply;

		fpi_error _result = FPI_ERROR_FAIL;
		if(!getService()) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(play_id);  //int as input paramter
			data.writeInt32(stop_type);  //int as input paramter

			_binder->transact(TRANSACTION_tos_channel_play_stop_stream,data, &reply,0);

			if(reply.readExceptionCode() == 0) {//fix check

				_result = (typeof(_result))reply.readInt32();//int as return value

			} else {
				TOSLOGW(SERVICE_NAME"_client tos_channel_play_stop_stream error");
			}
		}catch(...) {
			TOSLOGW(SERVICE_NAME"_client tos_channel_play_stop_stream error");
		}

		return _result;
		/*-- add you code for tos_channel_play_get_current_channel_info here --*/
	}

	fpi_error tos_dtv_set_channel_play_update_status(fpi_bool flag) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_set_channel_play_update_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int32_t)flag);  //int as input paramter

            _binder->transact(TRANSACTION_tos_dtv_set_channel_play_update_status, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_set_channel_play_update_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_set_channel_play_update_status error");
        }

        return _result;
        /*-- add you code for tos_dtv_set_channel_play_update_status here --*/
    }

	fpi_bool tos_dtv_get_channel_play_update_status(void) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_get_channel_play_update_status here --*/
        fpi_bool _result = fpi_true;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_dtv_get_channel_play_update_status, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_get_channel_play_update_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_get_channel_play_update_status error");
        }

        return _result;
        /*-- add you code for tos_dtv_get_channel_play_update_status here --*/
    }


};

sbinder_channel_play_client* sbinder_channel_play_client::_instance = NULL;

fpi_error tos_channel_play_get_current_channel_info( tos_dtv_play_info_t* play_info ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_get_current_channel_info(play_info);
}
fpi_error tos_channel_play_get_current_channel_id( uint32_t* channelId ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_get_current_channel_id(channelId);
}
fpi_error tos_channel_play( uint32_t channelId ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play(channelId);
}
fpi_error tos_channel_play_delivery( const tos_dtv_play_info_t* info ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_delivery(info);
}
fpi_error tos_channel_play_unlock(  ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_unlock();
}
fpi_error tos_channel_play_relock(  ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_relock();
}
fpi_error tos_channel_play_set_lock_status( fpi_bool locked ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_set_lock_status(locked);
}
fpi_error tos_channel_play_stop(  ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_stop();
}
fpi_error tos_channel_play_get_status( EN_FPI_DTV_PLAY_STATE* status ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_get_status(status);
}
fpi_error tos_channel_play_get_srceen_mode_info(EN_TOS_DTV_SS_MODE *mode) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_get_srceen_mode_info(mode);
}
fpi_error tos_channel_play_add_callback( tos_dtv_channel_callback callback, void* userdata ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_add_callback(callback, userdata);
}
fpi_error tos_channel_play_remove_callback( tos_dtv_channel_callback callback ) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_remove_callback(callback);
}

fpi_error tos_channel_play_stream(EN_TOS_DTV_PLAY_ID_E play_id ,tos_channel_play_stream_info *p_stream_info) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_stream(play_id,p_stream_info);
}
fpi_error tos_channel_play_get_current_stream_info(EN_TOS_DTV_PLAY_ID_E play_id ,EN_TOS_DTV_PLAY_TYPE_E type,tos_channel_stream_info *p_stream_info) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_get_current_stream_info(play_id,type,p_stream_info);
}
fpi_error tos_channel_play_stop_stream(EN_TOS_DTV_PLAY_ID_E  play_id,EN_TOS_DTV_PLAY_STOP_TYPE_E stop_type) {
    return sbinder_channel_play_client::Instance()->tos_channel_play_stop_stream(play_id, stop_type);
}
fpi_error tos_channel_play_set_flag(EN_TOS_DTV_PLAY_ID_E play_id,int *b_allow_video,int *b_allow_audio){
    return sbinder_channel_play_client::Instance()->tos_channel_play_set_flag(play_id,b_allow_video,b_allow_audio);
}
fpi_error tos_dtv_set_channel_play_update_status(fpi_bool flag) {
    return sbinder_channel_play_client::Instance()->tos_dtv_set_channel_play_update_status(flag);
}
fpi_bool tos_dtv_get_channel_play_update_status(void) {
    return sbinder_channel_play_client::Instance()->tos_dtv_get_channel_play_update_status();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
