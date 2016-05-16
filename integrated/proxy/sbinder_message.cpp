

#define LOG_TAG     "sbinder_message"

#include <clog.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <utils/Mutex.h>

#include "tos_message.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_MSG);


#define SERVICE_DESCRIPTOR                      "f09d65ae-8687-11e4-ac97-7831c1c50acc"
#define SERVICE_NAME                            "sbinder_message"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_msg_add_callback FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_msg_remove_callback FIRST_CALL_TRANSACTION + 2


#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_msg_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_message.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

class sbinder_message_service : public BBinder  
{  
private:
    static sbinder_message_service* _instance;

    RemoteCallbackList _cbList;
    bool _first;

    sbinder_message_service()
        :_first(true) {
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_message_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

    static int message_callback(st_msg_notify_t* msg,void* userdata) {
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        int _result = 0;
        int size = rcbl->beginBroadcast();
        fpi_trace(SERVICE_NAME"_service message_callback start");
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);

            if(binder != NULL && msg) {
                Parcel data, reply;
                Parcel::WritableBlob blob;
                data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                data.writeInt32(msg->msg);
                data.writeInt32(msg->data1);
                data.writeInt32(msg->data2);
                data.writeInt32(msg->datasize);

                if(msg->datasize >0) {
                    data.writeBlob(msg->datasize, &blob);
                    memcpy(blob.data(),msg->data,msg->datasize);
                }
                
                binder->transact(TRANSACTION_CALLBACK_msg_callback, data, &reply, 0);

                if(reply.readExceptionCode() == 0) {//fix check
                    _result += reply.readInt32();//int as return value
                }
            }
        }
        rcbl->finishBroadcast();

        fpi_trace(SERVICE_NAME"_service message_callback end");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_message_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_trace(SERVICE_NAME"_service ret = %d", ret);  
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_info(SERVICE_NAME"_service - onTransact code=%d",code);
        switch(code)  {

            case TRANSACTION_tos_msg_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for cb_add here, will auoto generated but may change yourself if need --
                sp<IBinder> binder = data.readStrongBinder();

                if(binder != NULL) {

                    int _result = 0;
                        
                    if(_first) {
                        _result = tos_msg_add_callback(sbinder_message_service::message_callback, NULL);
                        if(_result == 0) {
                            _first = false;
                        }
                    }

                    if(_result == 0) {
                        if(_cbList.registerCallback(binder,NULL)) {
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
                //-- end code for cb_add here --
            } break;
            
            case TRANSACTION_tos_msg_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for cb_remove here, will auoto generated but may change yourself if need --
                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                //-- end code for cb_remove here --
            } break;		
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
        fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
    }
}; 

int sbinder_message_service_serv()
{
    sp<ProcessState> proc(ProcessState::self());

    int ret = sbinder_message_service::Instance();
    fpi_trace("server - sbinder_message__service::Instance return %d", ret);

    ProcessState::self()->startThreadPool();
    fpi_trace("server -> enter loop ...");
    IPCThreadState::self()->joinThreadPool();
    fpi_trace("server -> return");
    return ret;
}

int sbinder_message_service_add() {
    sbinder_message_service::Instance();
    return 0;
}

sbinder_message_service* sbinder_message_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>

class sbinder_message_client  
{  
private:
    static sbinder_message_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_message_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_message_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
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
            fpi_debug(SERVICE_NAME"_client onTransact code=%d\n",code);
            
            switch (code){
            case TRANSACTION_CALLBACK_msg_callback:
            {
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
                    st_msg_notify_t msg;
                    Parcel::ReadableBlob outBlob;
                    memset(&msg,0,sizeof(msg));

                    msg.msg = data.readInt32();
                    msg.data1 = data.readInt32();
                    msg.data2 = data.readInt32();
                    msg.datasize = data.readInt32();
                    if(msg.datasize > 0) {
                        data.readBlob(msg.datasize, &outBlob);
                        msg.data = (void*)outBlob.data();
                    };

                    int _result = ((tos_msg_cb)_callback)(&msg, _cookie);

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
    static sbinder_message_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_message_client();
        }

        return _instance;
    }

    fpi_error tos_msg_add_callback(tos_msg_cb callback,void* userdata)
    {
        Parcel data, reply;

        /*-- add you code for cb_add here --*/
        int _result = -1;
        if(_binder == NULL || callback == NULL) {
            fpi_err(SERVICE_NAME"_client _binder or cb null");
            return _result;
        }

        if(_CBList.findCallback((void*)callback, userdata) != NULL) {
            fpi_err(SERVICE_NAME"_client cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            sp<Callback> ccb = new Callback((void*)callback, userdata);
            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_msg_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == 0) { //success
                    _CBList.addCallback(ccb);
                }
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_msg_add_callback error");
        }

        return _result;
        /*-- add you code for cb_add here --*/
    }

    fpi_error tos_msg_remove_callback(tos_msg_cb callback,void* userdata) 
    {
        Parcel data, reply;

        /*-- add you code for cb_remove here --*/
        int _result = -1;
        if(_binder == NULL || callback == NULL) {
            fpi_err(SERVICE_NAME"_client _binder or cb null");
            return _result;
        }

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)callback, userdata);
        if( ccb == NULL) {
            fpi_err(SERVICE_NAME"_client cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_msg_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == 0) { //success
                    _CBList.removeCallback(ccb);
                }
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_msg_remove_callback error");
        }

        return _result;
        /*-- add you code for cb_remove here --*/
    }
};

sbinder_message_client* sbinder_message_client::_instance = NULL;

fpi_error tos_msg_add_callback(tos_msg_cb callback,void* userdata)
{
    fpi_info(SERVICE_NAME"tos_msg_add_callback");

    return sbinder_message_client::Instance()->tos_msg_add_callback(callback, userdata);
}

fpi_error tos_msg_remove_callback(tos_msg_cb callback,void* userdata)
{
    return sbinder_message_client::Instance()->tos_msg_remove_callback(callback, userdata);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
