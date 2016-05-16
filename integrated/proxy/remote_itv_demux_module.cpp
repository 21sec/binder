/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_demux_module.sidl
 */
 

#define LOG_TAG     "remote_itv_demux_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_demux.h"
#include "itv_defines.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "1a6a6c2e-10df-11e5-a461-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_demux_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_demux_set_source_type FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_demux_set_filter_callback FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_demux_push_stream FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_demux_open_filter FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_demux_close_filter FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_itv_demux_set_filter FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_itv_demux_start_filter FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_itv_demux_stop_filter FIRST_CALL_TRANSACTION + 8

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG     "remote_itv_demux_module"

#include <stdlib.h>
#include "clog.h"
#include "remote_itv_demux_module.h"

class remote_itv_demux_module_service : public BBinder  
{  
private:
    static remote_itv_demux_module_service* _instance;
	
	sp<IBinder> _cbbinder;

    remote_itv_demux_module_service():_cbbinder(NULL){
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_demux_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }
	
	static int module_callback(const itv_demux_callback_param_t *param) {
        int _result = 0;
        Parcel data, reply;
        data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
        
        //************** Add call back functions's param
        if (param == NULL) 
        {
            data.writeInt32(-1);
        }
        else 
        {
            data.writeInt32(1); // Just write for Judge if param is NULL
            
            data.writeInt32(param->filter);
            
            if (param->data == NULL) 
            {
                data.writeInt32(-1);
            }
            else 
            {
                data.writeInt32((int)(param->dataLen) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pParamData_wblob;
                data.writeBlob((param->dataLen) * sizeof(char),&_pParamData_wblob);
                memcpy(_pParamData_wblob.data(),param->data,(param->dataLen) * sizeof(char));
            }
            data.writeInt32(param->dataLen);  //int as input paramter

            //data.writeInt32(param->userData);
        }

        if(_instance->_cbbinder != NULL && _instance->_cbbinder->isBinderAlive()) 
        {
            TOSLOGI(SERVICE_NAME"_service _instance->_cbbinder->transact start[0x%p]\n", _instance->_cbbinder.get());
            _instance->_cbbinder->transact(TRANSACTION_CALLBACK_callback, data, &reply, 0);  
            TOSLOGI(SERVICE_NAME"_service _instance->_cbbinder->transact end\n");
			if(reply.readExceptionCode() == 0) {//fix check
            	_result += reply.readInt32();//int as return value
        	}
        }
        else
        {
            TOSLOGI(SERVICE_NAME"_service _instance->_cbbinder is die.\n");
        }
        
        

        //TOSLOGI(SERVICE_NAME"_service module_callback end\n");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_demux_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            // TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        //TOSLOGI(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_demux_set_source_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_set_source_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int demuxId = (int)data.readInt32();  //int as input paramter

				itv_demux_source_type_t source = (itv_demux_source_type_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_demux_set_source_type( demuxId, source );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_set_source_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_set_filter_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_set_filter_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int demuxId = (int)data.readInt32();  //int as input paramter
				bool removeCallback = (bool)data.readInt32();

                int _result = 0;

                TOSLOGI(SERVICE_NAME"_service removeCallback[%d].\n", removeCallback);

				//_cbbinder is not array of sp<IBinder>, only one demux can be supported
				if (!removeCallback)
				{
					_cbbinder = data.readStrongBinder();
                    _result = itv_demux_set_filter_callback(demuxId,
                                                            remote_itv_demux_module_service::module_callback,
                                                            NULL );
				}
				else
				{
					_result = itv_demux_set_filter_callback(demuxId,NULL,NULL);
				}

    			if(_result == 0) {	// success
                    reply->writeNoException();
                    reply->writeInt32(_result); //int as return value
                }else{
                    reply->writeInt32(-1);//Exception
                }
                
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_push_stream:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_push_stream here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int demuxId = (int)data.readInt32();  //int as input paramter

                int _pBuff_len = data.readInt32(); //read length, only 32bits length support yet
                const char* pBuff = NULL;

                Parcel::ReadableBlob _pBuff_rblob;

                if(_pBuff_len > 0) {
                    data.readBlob(_pBuff_len,&_pBuff_rblob);
                    pBuff = (const char*)_pBuff_rblob.data();
                }

                int len = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                pBuff = (const char*)_pBuff_rblob.data();
                int _result = itv_demux_push_stream( demuxId, pBuff, len );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_push_stream here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_open_filter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_open_filter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int demuxId = (int)data.readInt32();  //int as input paramter

				itv_demux_filter_type_t filterType = (itv_demux_filter_type_t)data.readInt32();

                int _filter_len = data.readInt32(); //read length, only 32bits length support yet
                itv_handle_t* filter = NULL;

                Parcel::WritableBlob _filter_wblob;

                if(_filter_len > 0) {
                    reply->writeInt32(_filter_len);
                    reply->writeBlob(_filter_len,&_filter_wblob);
                    filter = (itv_handle_t*)_filter_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                filter = (itv_handle_t*)_filter_wblob.data();
                int _result = itv_demux_open_filter( demuxId, filterType, filter );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_open_filter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_close_filter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_close_filter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t filter = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_demux_close_filter( filter );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_close_filter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_set_filter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_set_filter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t filter = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_demux_filter_param_t _param_Struct;
				memset(&_param_Struct,0,sizeof(itv_demux_filter_param_t));
				const itv_demux_filter_param_t* param = NULL;
				
				int _flag = data.readInt32();
				if(_flag > 0) {
					_param_Struct.pid = (unsigned int)data.readInt32();
					_param_Struct.filter_buffer_size = (unsigned int)data.readInt32();
					_param_Struct.check_crc = (itv_bool_t)data.readInt32();
				
					int charLen = (int)ITV_FILTER_LEN*sizeof(char);
					Parcel::ReadableBlob _pParam_rblob1;
					data.readBlob(charLen,&_pParam_rblob1);
					memcpy(_param_Struct.mask,(unsigned char*)_pParam_rblob1.data(),charLen);
					Parcel::ReadableBlob _pParam_rblob2;
					data.readBlob(charLen,&_pParam_rblob2);
					memcpy(_param_Struct.coef,(unsigned char*)_pParam_rblob2.data(),charLen);
					Parcel::ReadableBlob _pParam_rblob3;
					data.readBlob(charLen,&_pParam_rblob3);
					memcpy(_param_Struct.excl,(unsigned char*)_pParam_rblob3.data(),charLen);
					
					_param_Struct.depth = (unsigned int)data.readInt32();
					
					param = &_param_Struct;
				}
				
                int _result = itv_demux_set_filter( filter, param );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_set_filter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_start_filter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_start_filter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t filter = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_demux_start_filter( filter );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_start_filter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_demux_stop_filter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_demux_stop_filter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t filter = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_demux_stop_filter( filter );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_demux_stop_filter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        // TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_demux_module_service_add() {
    remote_itv_demux_module_service::Instance();
    return 0;
}

remote_itv_demux_module_service* remote_itv_demux_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG     "remote_itv_demux_module"

#include <sbinder/ICallbackList.h>
#include "clog.h"

class remote_itv_demux_module_client  
{  
private:
    static remote_itv_demux_module_client* _instance;
    sp<IBinder> _binder;
	
	class Callback;
	sp<Callback> _spcallback;
	itv_demux_filter_callback _preCallBack;
	void* _preUserData;


    remote_itv_demux_module_client()
        :_binder(NULL),_spcallback(NULL),_preCallBack(NULL),_preUserData(NULL){
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_demux_module_client() {
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
					itv_demux_callback_param_t _param_Struct;
					memset(&_param_Struct,0,sizeof(itv_demux_callback_param_t));
					
					const itv_demux_callback_param_t* param = NULL;
					int _flag = data.readInt32();
					
					if(_flag > 0) {						
						_param_Struct.filter = (itv_handle_t)data.readInt32();
						
						int _pParamData_len = data.readInt32(); //read length, only 32bits length support yet
						//const char* pBuff = NULL;

						Parcel::ReadableBlob _pParamData_rblob;
						if(_pParamData_len > 0) {
							data.readBlob(_pParamData_len,&_pParamData_rblob);
							_param_Struct.data = (unsigned char*)_pParamData_rblob.data();
						}
						_param_Struct.dataLen = (unsigned int)data.readInt32();  //int as input paramter
						// re-get all pointers from blob to fix realloc issue in Parcel
						_param_Struct.data = (unsigned char*)_pParamData_rblob.data();

						//_param_Struct.userData = (void*)data.readInt32();
						
						param = &_param_Struct;
					}

                    int _result = ((itv_demux_filter_callback)_callback)(param);

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
    static remote_itv_demux_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_demux_module_client();
        }

        return _instance;
    }

    int itv_demux_set_source_type( int demuxId, itv_demux_source_type_t source ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_set_source_type()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_set_source_type here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(demuxId);  //int as input paramter

            data.writeInt32(source);  //int as input paramter

            _binder->transact(TRANSACTION_itv_demux_set_source_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_set_source_type error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_set_source_type error\n");
        }

        return _result;
        /*-- add you code for itv_demux_set_source_type here --*/
    }

	//static int itv_demux_filter_callback(const itv_demux_callback_param_t *param);

    int itv_demux_set_filter_callback( int demuxId, itv_demux_filter_callback cb, void* userData ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_set_filter_callback()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_set_filer_callback here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
			// TOSLOGW(SERVICE_NAME"_client _binder\n");
            return _result;
        }

		//if((_preCallBack == cb)&&(_preUserData ==userData)) {
        //    TOSLOGI(SERVICE_NAME"_client cb arleady added\n");
        //    return _result;
        //}

		//assert(demuxId == 0);
		
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            data.writeInt32(demuxId);  //int as input paramter
			bool removeCallback = (cb == NULL);
			data.writeInt32(removeCallback);
			
			sp<Callback> ccb = NULL;
			if (!removeCallback)
			{
				ccb = new Callback((void*)cb,userData);
            	data.writeStrongBinder(ccb);
			}
			
			//data.writeInt32(userData); //void * as input paramter

            _binder->transact(TRANSACTION_itv_demux_set_filter_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value
				if (_result == ITV_SUCCESS){
					_spcallback = ccb;
					_preCallBack = cb;
					_preUserData = userData;
                }
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_set_filer_callback error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_set_filer_callback error\n");
        }

        return _result;
        /*-- add you code for itv_demux_set_filer_callback here --*/
    }

    int itv_demux_push_stream( int demuxId, const char* pBuff, int len ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_push_stream()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_push_stream here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(demuxId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pBuff == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(len) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pBuff_wblob;
                data.writeBlob((len) * sizeof(char),&_pBuff_wblob);
                memcpy(_pBuff_wblob.data(),pBuff,(len)* sizeof(char));
            }

            data.writeInt32(len);  //int as input paramter

            _binder->transact(TRANSACTION_itv_demux_push_stream,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_push_stream error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_push_stream error\n");
        }

        return _result;
        /*-- add you code for itv_demux_push_stream here --*/
    }

    int itv_demux_open_filter( int demuxId, itv_demux_filter_type_t filterType, itv_handle_t* filter ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_open_filter()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_open_filter here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(demuxId);  //int as input paramter
			
			data.writeInt32(filterType);  //itv_demux_filter_type_t as input paramter

			if (filter == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_handle_t));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_itv_demux_open_filter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (filter != NULL) {
                    int _filter_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _filter_rblob;
                    reply.readBlob(_filter_len,&_filter_rblob);
                    memcpy(filter,_filter_rblob.data(),_filter_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_open_filter error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_open_filter error\n");
        }

        return _result;
        /*-- add you code for itv_demux_open_filter here --*/
    }

    int itv_demux_close_filter( itv_handle_t filter ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_close_filter()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_close_filter here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(filter);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_demux_close_filter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value
                
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_close_filter error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_close_filter error\n");
        }

        return _result;
        /*-- add you code for itv_demux_close_filter here --*/
    }

    int itv_demux_set_filter( itv_handle_t filter, const itv_demux_filter_param_t* param ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_set_filter()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_set_filter here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(filter);  //itv_handle_t as input paramter
			
            if (param == NULL) {
                data.writeInt32(-1);
            }
            else {
				data.writeInt32(1);	// Just write for Judge if param is NULL
				
                data.writeInt32(param->pid);
				data.writeInt32(param->filter_buffer_size);
				data.writeInt32(param->check_crc);
				
				int charLen = (int)ITV_FILTER_LEN*sizeof(char);
				Parcel::WritableBlob _pParam_wblob1;
                data.writeBlob(charLen,&_pParam_wblob1);
                memcpy(_pParam_wblob1.data(),param->mask,charLen);
				Parcel::WritableBlob _pParam_wblob2;
				data.writeBlob(charLen,&_pParam_wblob2);
                memcpy(_pParam_wblob2.data(),param->coef,charLen);
				Parcel::WritableBlob _pParam_wblob3;
				data.writeBlob(charLen,&_pParam_wblob3);
                memcpy(_pParam_wblob3.data(),param->excl,charLen);
				
				data.writeInt32(param->depth);
            }
			
            _binder->transact(TRANSACTION_itv_demux_set_filter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_set_filter error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_set_filter error\n");
        }

        return _result;
        /*-- add you code for itv_demux_set_filter here --*/
    }

    int itv_demux_start_filter( itv_handle_t filter ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_start_filter()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_start_filter here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(filter);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_demux_start_filter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_start_filter error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_start_filter error\n");
        }

        return _result;
        /*-- add you code for itv_demux_start_filter here --*/
    }

    int itv_demux_stop_filter( itv_handle_t filter ) {
		// TOSLOGI(SERVICE_NAME"_client itv_demux_stop_filter()\n");
        Parcel data, reply;

        /*-- add you code for itv_demux_stop_filter here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(filter);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_demux_stop_filter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_demux_stop_filter error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_demux_stop_filter error\n");
        }

        return _result;
        /*-- add you code for itv_demux_stop_filter here --*/
    }
};

remote_itv_demux_module_client* remote_itv_demux_module_client::_instance = NULL;

int itv_demux_set_source_type( int demuxId, itv_demux_source_type_t source ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_set_source_type(demuxId, source);
}
int itv_demux_set_filter_callback( int demuxId, itv_demux_filter_callback cb, void* userData ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_set_filter_callback(demuxId, cb, userData);
}
int itv_demux_push_stream( int demuxId, const char* pBuff, int len ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_push_stream(demuxId, pBuff, len);
}
int itv_demux_open_filter( int demuxId, itv_demux_filter_type_t filterType, itv_handle_t* filter ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_open_filter(demuxId, filterType, filter);
}
int itv_demux_close_filter( itv_handle_t filter ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_close_filter(filter);
}
int itv_demux_set_filter( itv_handle_t filter, const itv_demux_filter_param_t* param ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_set_filter(filter, param);
}
int itv_demux_start_filter( itv_handle_t filter ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_start_filter(filter);
}
int itv_demux_stop_filter( itv_handle_t filter ) {
    return remote_itv_demux_module_client::Instance()->itv_demux_stop_filter(filter);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
