/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_usb_monitor.sidl
 */
 

#define LOG_TAG     "sbinder_usb_monitor"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_usb_monitor.h"
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_USB_MONITOR);


#define SERVICE_DESCRIPTOR                      "53e47e82-09c7-11e5-99ce-005056a86db3"
#define SERVICE_NAME                            "sbinder_usb_monitor"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_usb_add_callback FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_usb_remove_callback FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_usb_monitor_start FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_usb_get_partition_count FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_usb_get_partition_info FIRST_CALL_TRANSACTION + 5

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_tos_usb_callback_fn FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_usb_monitor.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

class sbinder_usb_monitor_service : public BBinder  
{  
private:
    static sbinder_usb_monitor_service* _instance;

	RemoteCallbackList _cbList;
    bool _first;
    sbinder_usb_monitor_service():_first(true) {
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_usb_monitor_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
	}

    static fpi_error module_callback(FPI_USB_CB_EVENT_E event, void* param, void *userData)
	{
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        fpi_error _result = 0;
        int size = rcbl->beginBroadcast();
        //CLOGW("module_callback 2 %d",size);
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);
			//void *param_save = rcbl->getBroadcastCookie(i);
			//void *userdata_save = rcbl->getBroadcastCookie(i);

            if(binder != NULL) {
                Parcel parcel_data, parcel_reply;

                parcel_data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                parcel_data.writeInt32(event);
                if (param == NULL) {
                    parcel_data.writeInt32(-1);
                }
                else {
					char* path = (char*)param;
                    parcel_data.writeInt32(strlen(path)+1);
                    
                    Parcel::WritableBlob _path_wblob;
                    parcel_data.writeBlob(strlen(path)+1,&_path_wblob);
                    memcpy(_path_wblob.data(),path,strlen(path)+1);
                }
                //parcel_data.writeInt64((intptr_t)param_save);
				//parcel_data.writeInt64((intptr_t)userdata_save);
                //CLOGW("module_callback transact begin");
                binder->transact(TRANSACTION_CALLBACK_tos_usb_callback_fn, parcel_data, &parcel_reply, 0);
                //CLOGW("module_callback transact after");

                if(parcel_reply.readExceptionCode() == 0) {//fix check
                	_result = (typeof(_result))parcel_reply.readInt32();//int as return value
	            } else {
	                //CLOGW(SERVICE_NAME"_service module_callback return error");
	            }
            }
        }
        rcbl->finishBroadcast();

        //CLOGW(SERVICE_NAME"_service module_callback end");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_usb_monitor_service();
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

            case TRANSACTION_tos_usb_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_usb_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                /////////////////////////////////
                sp<IBinder> binder = data.readStrongBinder();
                
                if (binder != NULL)
				{
                    fpi_error _result = FPI_ERROR_SUCCESS;

                    //void *param = (void *)data.readIntPtr();
					void *userdata = (void *)data.readInt64();

                    if(_first) {
                        _result = tos_usb_add_callback(sbinder_usb_monitor_service::module_callback, userdata);
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
                ///////////////////////////////////
                //-- end code for tos_usb_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_usb_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_usb_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                 ///////////////////////////
                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                ////////////////////////////
			   //-- end code for tos_usb_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_usb_monitor_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_usb_monitor_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_usb_monitor_start(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_usb_monitor_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_usb_get_partition_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_usb_get_partition_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_usb_get_partition_count(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_usb_get_partition_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_usb_get_partition_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_usb_get_partition_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int partition_idx = (int)data.readInt32();  //int as input paramter

                int _info_len = data.readInt32(); //read length, only 32bits length support yet
                FPI_USB_Partition_Info_S* info = NULL;

                Parcel::WritableBlob _info_wblob;

                if(_info_len > 0) {
                    reply->writeInt32(_info_len);
                    reply->writeBlob(_info_len,&_info_wblob);
                    info = (FPI_USB_Partition_Info_S*)_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                info = (FPI_USB_Partition_Info_S*)_info_wblob.data();
                fpi_error _result = tos_usb_get_partition_info( partition_idx, info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_usb_get_partition_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_usb_monitor_service_add() {
    sbinder_usb_monitor_service::Instance();
    return 0;
}

sbinder_usb_monitor_service* sbinder_usb_monitor_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>
class sbinder_usb_monitor_client  
{  
private:
    static sbinder_usb_monitor_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_usb_monitor_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_usb_monitor_client() {
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

        virtual status_t onTransact( uint32_t code,const Parcel& data,Parcel* reply,uint32_t flags = 0) {
            fpi_info(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_tos_usb_callback_fn:
            {
                //CLOGW("ontransact callback fn");
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					fpi_error _result = FPI_ERROR_SUCCESS;
                    Parcel::ReadableBlob outBlob;
                    //CLOGW("ontransact callback fn 1");
					FPI_USB_CB_EVENT_E event = (FPI_USB_CB_EVENT_E)data.readInt32();
                    //void *param = (void *)data.readIntPtr();
                    /////////////////
                    int param_len = data.readInt32();
                    void *param = NULL;
                    if(param_len > 0) {
                        data.readBlob(param_len, &outBlob);
                        param = (void*)outBlob.data();
                    };
                    ////////////////
					//void *userdata = (void *)data.readIntPtr();

					//if (userdata == _cookie)
					//{
					//CLOGW("ontransact callback fn 2 %s",(char*)param);
	                    _result = ((tos_usb_callback_fn)_callback)(event, param, NULL);
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

            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };
    
public:  
    static sbinder_usb_monitor_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_usb_monitor_client();
        }

        return _instance;
    }

    fpi_error tos_usb_add_callback( tos_usb_callback_fn cb, void* userData ) {
        Parcel data, reply;

        /*-- add you code for tos_usb_add_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        if (NULL == cb)
		{
            fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback NULL callbak");
            return _result;
		}

        if(_CBList.findCallback((void*)cb, NULL) != NULL) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_add_callback cb arleady added");
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            ////////////////////////
            sp<Callback> ccb = new Callback((void*)cb, NULL);
            data.writeStrongBinder(ccb);
			data.writeInt64((int64_t)userData);
            /////////////////////////

            _binder->transact(TRANSACTION_tos_usb_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                        _CBList.addCallback(ccb);
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_usb_add_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_usb_add_callback error");
        }

        return _result;
        /*-- add you code for tos_usb_add_callback here --*/
    }

    fpi_error tos_usb_remove_callback( tos_usb_callback_fn cb ) {
        Parcel data, reply;

        /*-- add you code for tos_usb_remove_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        if (NULL == cb)
		{
            fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback NULL callbak or error port");
            return _result;
		}

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)cb, (void*)NULL);
        if(ccb == NULL) {
            fpi_warn(SERVICE_NAME"_client tos_channel_play_remove_callback cb not added");
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_usb_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value
				if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                }

            } else {
                fpi_warn(SERVICE_NAME"_client tos_usb_remove_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_usb_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_usb_remove_callback here --*/
    }

    fpi_error tos_usb_monitor_start(  ) {
        Parcel data, reply;

        /*-- add you code for tos_usb_monitor_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            
            _binder->transact(TRANSACTION_tos_usb_monitor_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_usb_monitor_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_usb_monitor_start error");
        }

        return _result;
        /*-- add you code for tos_usb_monitor_start here --*/
    }

    int tos_usb_get_partition_count(  ) {
        Parcel data, reply;

        /*-- add you code for tos_usb_get_partition_count here --*/
        int _result = 0;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_usb_get_partition_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_usb_get_partition_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_usb_get_partition_count error");
        }

        return _result;
        /*-- add you code for tos_usb_get_partition_count here --*/
    }

    fpi_error tos_usb_get_partition_info( int partition_idx, FPI_USB_Partition_Info_S* info ) {
        Parcel data, reply;

        /*-- add you code for tos_usb_get_partition_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(partition_idx);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(FPI_USB_Partition_Info_S));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_usb_get_partition_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (info != NULL) {
                    int _info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _info_rblob;
                    reply.readBlob(_info_len,&_info_rblob);
                    memcpy(info,_info_rblob.data(),_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_usb_get_partition_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_usb_get_partition_info error");
        }

        return _result;
        /*-- add you code for tos_usb_get_partition_info here --*/
    }
};

sbinder_usb_monitor_client* sbinder_usb_monitor_client::_instance = NULL;

fpi_error tos_usb_add_callback( tos_usb_callback_fn cb, void* userData ) {
    return sbinder_usb_monitor_client::Instance()->tos_usb_add_callback(cb, userData);
}
fpi_error tos_usb_remove_callback( tos_usb_callback_fn cb ) {
    return sbinder_usb_monitor_client::Instance()->tos_usb_remove_callback(cb);
}
fpi_error tos_usb_monitor_start(  ) {
    return sbinder_usb_monitor_client::Instance()->tos_usb_monitor_start();
}
int tos_usb_get_partition_count(  ) {
    return sbinder_usb_monitor_client::Instance()->tos_usb_get_partition_count();
}
fpi_error tos_usb_get_partition_info( int partition_idx, FPI_USB_Partition_Info_S* info ) {
    return sbinder_usb_monitor_client::Instance()->tos_usb_get_partition_info(partition_idx, info);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
