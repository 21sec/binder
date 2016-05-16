/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_platform_module.sidl
 */
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_platform.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "be14ec64-132d-11e5-b3ef-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_platform_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_platform_init FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_platform_pause FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_platform_resume FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_platform_term FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_platform_setCallback FIRST_CALL_TRANSACTION + 5

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_callback FIRST_CALLBACK_TRANSACTION + 1


using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG "remote_itv_platform_module"

#include <stdlib.h>
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

#include "clog.h"
#include "remote_itv_platform_module.h"

class remote_itv_platform_module_service : public BBinder  
{  
private:
    static remote_itv_platform_module_service* _instance;

	sp<IBinder> _cbbinder;

    remote_itv_platform_module_service() {
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_platform_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }

	static void module_callback(int event,int param1,int param2) {
		// TOSLOGI(SERVICE_NAME"_service module_callback start\n");
		
        if(_instance->_cbbinder != NULL && _instance->_cbbinder->isBinderAlive()) {
            Parcel data, reply;
            data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
			
			data.writeInt32(event);
            data.writeInt32(param1);
			data.writeInt32(param2);

			// TOSLOGI(SERVICE_NAME"_service module_callback transact\n");
            _instance->_cbbinder->transact(TRANSACTION_CALLBACK_callback, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				
            }
        }

        // TOSLOGI(SERVICE_NAME"_service module_callback end\n");
        return ;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_platform_module_service();
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

            case TRANSACTION_itv_platform_init:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_platform_init here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_platform_init_param_t _param_Struct;
				memset(&_param_Struct,0,sizeof(itv_platform_init_param_t));
				
				const itv_platform_init_param_t* param = NULL;
				int _flag = data.readInt32();
				if(_flag > 0) {
					_param_Struct.reserved = data.readInt32();
					param = &_param_Struct;
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_platform_init( param );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_platform_init here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_platform_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_platform_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_platform_pause(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_platform_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_platform_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_platform_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_platform_resume(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_platform_resume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_platform_term:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_platform_term here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_platform_term(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_platform_term here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			case TRANSACTION_itv_platform_setCallback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_platform_term here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				
                //begin paramters list

				int _flag = data.readInt32();

				int _result = 0;
				if(_flag > 0) {
                	_cbbinder = data.readStrongBinder();
					// re-get all pointers from blob to fix realloc issue in Parcel
                 	_result = itv_platform_setCallback(remote_itv_platform_module_service::module_callback);
				}else{
					_cbbinder = NULL;
					_result = itv_platform_setCallback(NULL);
				}				
				
                reply->writeInt32(_result);//Exception

                //-- end code for itv_platform_term here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        // TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_platform_module_service_add() {
    remote_itv_platform_module_service::Instance();
    return 0;
}

remote_itv_platform_module_service* remote_itv_platform_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG "remote_itv_platform_module"

#include <proxy.h>
#include <sbinder/ICallbackList.h>

#include "clog.h"

class remote_itv_platform_module_client  
{  
private:
	class  Callback;
    static remote_itv_platform_module_client* _instance;
    sp<IBinder> _binder;
	

    remote_itv_platform_module_client()
        :_binder(NULL) {
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_platform_module_client() {
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
            // TOSLOGI(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_callback:
            {
                if (!data.checkInterface(this)) {
                    // TOSLOGW(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					int event = (int)data.readInt32();  //int as input paramter
                    int param1 = (int)data.readInt32();  //int as input paramter
                    int param2 = (int)data.readInt32();  //int as input paramter
					
                    ((itv_platform_eventCallback)_callback)(event, param1, param2);
					
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
    static remote_itv_platform_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_platform_module_client();
        }

        return _instance;
    }

    int itv_platform_init( const itv_platform_init_param_t* param ) {
		// TOSLOGI(SERVICE_NAME"_client itv_platform_init()\n");
        Parcel data, reply;

        /*-- add you code for itv_platform_init here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (param == NULL) {
                data.writeInt32(0);	// param can be NULL
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_platform_init_param_t));//write length, only support 32 bits length yet
                data.writeInt32(param->reserved);
            }

            _binder->transact(TRANSACTION_itv_platform_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_platform_init error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_platform_init error\n");
        }

        return _result;
        /*-- add you code for itv_platform_init here --*/
    }

    int itv_platform_pause(  ) {
		// TOSLOGI(SERVICE_NAME"_client itv_platform_pause()\n");
        Parcel data, reply;

        /*-- add you code for itv_platform_pause here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_itv_platform_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_platform_pause error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_platform_pause error\n");
        }

        return _result;
        /*-- add you code for itv_platform_pause here --*/
    }

    int itv_platform_resume(  ) {
		// TOSLOGI(SERVICE_NAME"_client itv_platform_resume()\n");
        Parcel data, reply;

        /*-- add you code for itv_platform_resume here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_itv_platform_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_platform_resume error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_platform_resume error\n");
        }

        return _result;
        /*-- add you code for itv_platform_resume here --*/
    }

    int itv_platform_term(  ) {
		// TOSLOGI(SERVICE_NAME"_client itv_platform_term()\n");
        Parcel data, reply;

        /*-- add you code for itv_platform_term here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_itv_platform_term,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_platform_term error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_platform_term error\n");
        }

        return _result;
        /*-- add you code for itv_platform_term here --*/
    }


	int itv_platform_setCallback( itv_platform_eventCallback callback ) {
		// TOSLOGI(SERVICE_NAME"_client itv_platform_setCallback()\n");
        Parcel data, reply;

        /*-- add you code for itv_platform_term here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }
		
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			sp<Callback> ccb = NULL;

			if(callback == NULL) {
				data.writeInt32(-1);
			}else{
				data.writeInt32(1);

				ccb = new Callback((void*)callback, NULL);
				data.writeStrongBinder(ccb);
			}

            _binder->transact(TRANSACTION_itv_platform_setCallback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if (_result == ITV_SUCCESS){
					// TOSLOGI(SERVICE_NAME"_client itv_platform_setCallback() Success\n");            
				}

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_platform_term error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_platform_term error\n");
        }

        return _result;
        /*-- add you code for itv_platform_term here --*/
    }

};

remote_itv_platform_module_client* remote_itv_platform_module_client::_instance = NULL;

int itv_platform_init( const itv_platform_init_param_t* param ) {
	// TOSLOGI("--------- client itv_platform_init ---------");
	proxy_init();
	// TOSLOGI("--------- client call proxy_init() ---------");
	return remote_itv_platform_module_client::Instance()->itv_platform_init(param);
}
int itv_platform_pause(  ) {
    return remote_itv_platform_module_client::Instance()->itv_platform_pause();
}
int itv_platform_resume(  ) {
    return remote_itv_platform_module_client::Instance()->itv_platform_resume();
}
int itv_platform_term(  ) {
	// TOSLOGI("--------- client itv_platform_term ---------");
    return remote_itv_platform_module_client::Instance()->itv_platform_term();
}

int itv_platform_setCallback( itv_platform_eventCallback callback ) {
    return remote_itv_platform_module_client::Instance()->itv_platform_setCallback(callback);
}



#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
