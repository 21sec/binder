/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_media_scan.sidl
 */
 

#define LOG_TAG     "sbinder_media_scan"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_media_scan.h"
#include "fpi_error_code.h"
#include "fpi_base_type.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_MEDIA);


#define SERVICE_DESCRIPTOR                      "891afbae-1add-11e5-bde4-005056a86db3"
#define SERVICE_NAME                            "sbinder_media_scan"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_ms_add_callback FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_ms_remove_callback FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_ms_start_scan_file FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_ms_cancel_scan_file FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_ms_get_file_list_by_type FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_ms_get_file_count FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_ms_set_scan_mode FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_ms_create_tmb_task FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_ms_stop_tmb_task FIRST_CALL_TRANSACTION + 9

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_tos_ms_callback_fn FIRST_CALLBACK_TRANSACTION + 1


using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_media_scan.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

class sbinder_media_scan_service : public BBinder  
{  
private:
    static sbinder_media_scan_service* _instance;

    RemoteCallbackList _cbList;
    bool _first;

    sbinder_media_scan_service():_first(true){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_media_scan_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

    static fpi_error module_callback(FPI_MS_CB_EVENT_E event, void *userData)
	{
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        fpi_error _result = 0;
        int size = rcbl->beginBroadcast();
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);
			//void *userdata_save = rcbl->getBroadcastCookie(i);

            if(binder != NULL) {
                Parcel parcel_data, parcel_reply;

                parcel_data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                parcel_data.writeInt32(event);
				//parcel_data.writeIntPtr((intptr_t)userdata_save);
				/////////////////////////
                if (userData == NULL) 
    			{
                    parcel_data.writeInt32(-1);
                }
                else 
    			{
                    parcel_data.writeInt32((int)(sizeof(int)));//write length, only support 32 bits length yet
                    Parcel::WritableBlob _pin_wblob;
                	parcel_data.writeBlob((sizeof(int)),&_pin_wblob);
                	memcpy(_pin_wblob.data(),userData,(sizeof(int)));
                }

                fpi_warn(SERVICE_NAME"event = %d userdata = %p", event, userData);
                //////////////////////////
                binder->transact(TRANSACTION_CALLBACK_tos_ms_callback_fn, parcel_data, &parcel_reply, 0);

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
            _instance = new sbinder_media_scan_service();
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

            case TRANSACTION_tos_ms_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                /////////////////////////////////
                sp<IBinder> binder = data.readStrongBinder();
                
                if (binder != NULL)
				{
                    fpi_error _result = FPI_ERROR_SUCCESS;

					//void *userdata = (void *)data.readIntPtr();
					///////////////////
                    int _userdata_len = data.readInt32(); //read length, only 32bits length support yet
                    void* userdata = NULL;
    
                    Parcel::ReadableBlob _userdata_rblob;
    
                    if(_userdata_len > 0) {
                        data.readBlob(_userdata_len,&_userdata_rblob);
                        userdata = (void*)_userdata_rblob.data();
                    }
    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    userdata = (void*)_userdata_rblob.data();

                    fpi_warn(SERVICE_NAME"userdata = %p", userdata);
                    //////////////////

                    if(_first) {
                        _result = tos_ms_add_callback(sbinder_media_scan_service::module_callback, userdata);
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

                //-- end code for tos_ms_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_remove_callback here, will auoto generated but may change yourself if need --

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

                //-- end code for tos_ms_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_start_scan_file:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_start_scan_file here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                const char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (const char*)_path_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                path = (const char*)_path_rblob.data();
                fpi_error _result = tos_ms_start_scan_file( path );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_start_scan_file here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_cancel_scan_file:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_cancel_scan_file here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ms_cancel_scan_file(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_cancel_scan_file here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_get_file_list_by_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_get_file_list_by_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                FPI_MS_SORT_MODE_E mode = (FPI_MS_SORT_MODE_E)data.readInt32();  //FPI_MS_SORT_MODE_E as input paramter

                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                const char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (const char*)_path_rblob.data();
                }

                FPI_MS_FILE_TYPE_E type = (FPI_MS_FILE_TYPE_E)data.readInt32();  //FPI_MS_FILE_TYPE_E as input paramter

                int _list_len = data.readInt32(); //read length, only 32bits length support yet
                FPI_MS_File_Node_S* list = NULL;

                Parcel::WritableBlob _list_wblob;

                if(_list_len > 0) {
                    reply->writeInt32(_list_len);
                    reply->writeBlob(_list_len,&_list_wblob);
                    list = (FPI_MS_File_Node_S*)_list_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                path = (const char*)_path_rblob.data();
                list = (FPI_MS_File_Node_S*)_list_wblob.data();
                fpi_error _result = tos_ms_get_file_list_by_type( mode, path, type, list );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_get_file_list_by_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_get_file_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_get_file_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                const char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (const char*)_path_rblob.data();
                }

                FPI_MS_FILE_TYPE_E type = (FPI_MS_FILE_TYPE_E)data.readInt32();  //FPI_MS_FILE_TYPE_E as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                path = (const char*)_path_rblob.data();
                int _result = tos_ms_get_file_count( path, type );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_ms_get_file_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_set_scan_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_set_scan_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                FPI_MS_SCAN_MODE_E mode = (FPI_MS_SCAN_MODE_E)data.readInt32();  //FPI_MS_SCAN_MODE_E as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ms_set_scan_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_set_scan_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_create_tmb_task:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_create_tmb_task here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                const char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (const char*)_path_rblob.data();
                }

                FPI_MS_FILE_TYPE_E type = (FPI_MS_FILE_TYPE_E)data.readInt32();  //FPI_MS_FILE_TYPE_E as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                path = (const char*)_path_rblob.data();
                fpi_error _result = tos_ms_create_tmb_task( path, type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_create_tmb_task here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ms_stop_tmb_task:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ms_stop_tmb_task here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ms_stop_tmb_task(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ms_stop_tmb_task here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_media_scan_service_add() {
    sbinder_media_scan_service::Instance();
    return 0;
}

sbinder_media_scan_service* sbinder_media_scan_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>

class sbinder_media_scan_client  
{  
private:
    static sbinder_media_scan_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_media_scan_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_media_scan_client() {
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
            case TRANSACTION_CALLBACK_tos_ms_callback_fn:
            {
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					fpi_error _result = FPI_ERROR_SUCCESS;

					FPI_MS_CB_EVENT_E event = (FPI_MS_CB_EVENT_E)data.readInt32();
					//void *userdata = (void *)data.readIntPtr();
                    ///////////////////
                    int _userdata_len = data.readInt32(); //read length, only 32bits length support yet
                    void* userdata = NULL;
    
                    Parcel::ReadableBlob _userdata_rblob;
    
                    if(_userdata_len > 0) {
                        data.readBlob(_userdata_len,&_userdata_rblob);
                        userdata = (void*)_userdata_rblob.data();
                    }
    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    userdata = (void*)_userdata_rblob.data();
                    //////////////////
                    fpi_warn(SERVICE_NAME"event = %d userdata = %p", event, userdata);
					//if (userdata == _cookie)
					//{
	                    _result = ((tos_ms_callback_fn)_callback)(event, userdata);
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
    static sbinder_media_scan_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_media_scan_client();
        }

        return _instance;
    }

    fpi_error tos_ms_add_callback( tos_ms_callback_fn cb, void* userData ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_add_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        if (NULL == cb)
		{
            fpi_warn(SERVICE_NAME"_client tos_ms_add_callback NULL callbak");
            return _result;
		}

        if(_CBList.findCallback((void*)cb, NULL) != NULL) {
            fpi_warn(SERVICE_NAME"_client tos_ms_add_callback cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            ////////////////////////
            sp<Callback> ccb = new Callback((void*)cb, NULL);
            data.writeStrongBinder(ccb);
			//data.writeIntPtr((intptr_t)userData);
			if (userData == NULL) 
			{
                data.writeInt32(-1);
            }
            else 
			{
                data.writeInt32((int)(sizeof(int)));//write length, only support 32 bits length yet
                Parcel::WritableBlob _pin_wblob;
            	data.writeBlob((sizeof(int)),&_pin_wblob);
            	memcpy(_pin_wblob.data(),userData,(sizeof(int)));
            }
            /////////////////////////
            fpi_warn(SERVICE_NAME"_client tos_ms_add_callback NULL callbak userdata = %p", userData);
            _binder->transact(TRANSACTION_tos_ms_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                        _CBList.addCallback(ccb);
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_add_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_add_callback error");
        }

        return _result;
        /*-- add you code for tos_ms_add_callback here --*/
    }

    fpi_error tos_ms_remove_callback( tos_ms_callback_fn cb ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_remove_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        if (NULL == cb)
		{
            fpi_warn(SERVICE_NAME"_client tos_ms_remove_callback NULL callbak or error port");
            return _result;
		}

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)cb, (void*)NULL);
        if(ccb == NULL) {
            fpi_warn(SERVICE_NAME"_client tos_ms_remove_callback cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_ms_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                }

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_remove_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_ms_remove_callback here --*/
    }

    fpi_error tos_ms_start_scan_file( const char* path ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_start_scan_file here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }
            fpi_info(SERVICE_NAME"tos_ms_start_scan_file path = %s\n", path);
            _binder->transact(TRANSACTION_tos_ms_start_scan_file,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_start_scan_file error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_start_scan_file error");
        }

        return _result;
        /*-- add you code for tos_ms_start_scan_file here --*/
    }

    fpi_error tos_ms_cancel_scan_file(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_cancel_scan_file here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ms_cancel_scan_file,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_cancel_scan_file error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_cancel_scan_file error");
        }

        return _result;
        /*-- add you code for tos_ms_cancel_scan_file here --*/
    }

    fpi_error tos_ms_get_file_list_by_type( FPI_MS_SORT_MODE_E mode, const char* path, FPI_MS_FILE_TYPE_E type, FPI_MS_File_Node_S* list ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_get_file_list_by_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //FPI_MS_SORT_MODE_E as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }

            data.writeInt32(type);  //FPI_MS_FILE_TYPE_E as input paramter
            //printf("%s:%d:sbinder------tos_ms_get_file_list_by_type path = %s, type = %d.\n", __FUNCTION__, __LINE__,path, type);
            //for out only, only write length ; for in, alloc and copy
            if (list == NULL) {
                data.writeInt32(-1);
            }
            else {
                int count = tos_ms_get_file_count(path, type);
                //printf("%s:%d:sbinder------tos_ms_get_file_list_by_type count = %d\n", __FUNCTION__, __LINE__,count);
                //printf("%s:%d:sbinder------tos_ms_get_file_list_by_type sizeof(FPI_MS_File_Node_S) = %d\n", __FUNCTION__, __LINE__,sizeof(FPI_MS_File_Node_S));
                data.writeInt32((int)(count) * sizeof(FPI_MS_File_Node_S));//write length, only support 32 bits length yet
                //printf("%s:%d:sbinder------tos_ms_get_file_list_by_type (int)(count) * sizeof(FPI_MS_File_Node_S) = %d\n", __FUNCTION__, __LINE__,(int)(count) * sizeof(FPI_MS_File_Node_S));
            }
            
            _binder->transact(TRANSACTION_tos_ms_get_file_list_by_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (list != NULL) {
                    int _list_len = reply.readInt32(); //read length, only 32bits length support yet
                    //printf("%s:%d:sbinder------tos_ms_get_file_list_by_type _list_len = %d\n", __FUNCTION__, __LINE__,_list_len);
                    Parcel::ReadableBlob _list_rblob;
                    reply.readBlob(_list_len,&_list_rblob);
                    memcpy(list,_list_rblob.data(),_list_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_get_file_list_by_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_get_file_list_by_type error");
        }

        return _result;
        /*-- add you code for tos_ms_get_file_list_by_type here --*/
    }

    int tos_ms_get_file_count( const char* path, FPI_MS_FILE_TYPE_E type ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_get_file_count here --*/
        int _result = -1;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            
            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }

            
            data.writeInt32(type);  //FPI_MS_FILE_TYPE_E as input paramter

            _binder->transact(TRANSACTION_tos_ms_get_file_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_get_file_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_get_file_count error");
        }

        return _result;
        /*-- add you code for tos_ms_get_file_count here --*/
    }

    fpi_error tos_ms_set_scan_mode( FPI_MS_SCAN_MODE_E mode ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_set_scan_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //FPI_MS_SCAN_MODE_E as input paramter

            _binder->transact(TRANSACTION_tos_ms_set_scan_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_set_scan_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_set_scan_mode error");
        }

        return _result;
        /*-- add you code for tos_ms_set_scan_mode here --*/
    }

    fpi_error tos_ms_create_tmb_task( const char* path, FPI_MS_FILE_TYPE_E type ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_create_tmb_task here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }

            data.writeInt32(type);  //FPI_MS_FILE_TYPE_E as input paramter

            _binder->transact(TRANSACTION_tos_ms_create_tmb_task,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_create_tmb_task error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_create_tmb_task error");
        }

        return _result;
        /*-- add you code for tos_ms_create_tmb_task here --*/
    }

    fpi_error tos_ms_stop_tmb_task(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ms_stop_tmb_task here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ms_stop_tmb_task,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ms_stop_tmb_task error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ms_stop_tmb_task error");
        }

        return _result;
        /*-- add you code for tos_ms_stop_tmb_task here --*/
    }
};

sbinder_media_scan_client* sbinder_media_scan_client::_instance = NULL;

fpi_error tos_ms_add_callback( tos_ms_callback_fn cb, void* userData ) {
    return sbinder_media_scan_client::Instance()->tos_ms_add_callback(cb, userData);
}
fpi_error tos_ms_remove_callback( tos_ms_callback_fn cb ) {
    return sbinder_media_scan_client::Instance()->tos_ms_remove_callback(cb);
}
fpi_error tos_ms_start_scan_file( const char* path ) {
    return sbinder_media_scan_client::Instance()->tos_ms_start_scan_file(path);
}
fpi_error tos_ms_cancel_scan_file(  ) {
    return sbinder_media_scan_client::Instance()->tos_ms_cancel_scan_file();
}
fpi_error tos_ms_get_file_list_by_type( FPI_MS_SORT_MODE_E mode, const char* path, FPI_MS_FILE_TYPE_E type, FPI_MS_File_Node_S* list ) {
    return sbinder_media_scan_client::Instance()->tos_ms_get_file_list_by_type(mode, path, type, list);
}
int tos_ms_get_file_count( const char* path, FPI_MS_FILE_TYPE_E type ) {
    return sbinder_media_scan_client::Instance()->tos_ms_get_file_count(path, type);
}
fpi_error tos_ms_set_scan_mode( FPI_MS_SCAN_MODE_E mode ) {
    return sbinder_media_scan_client::Instance()->tos_ms_set_scan_mode(mode);
}
fpi_error tos_ms_create_tmb_task( const char* path, FPI_MS_FILE_TYPE_E type ) {
    return sbinder_media_scan_client::Instance()->tos_ms_create_tmb_task(path, type);
}
fpi_error tos_ms_stop_tmb_task(  ) {
    return sbinder_media_scan_client::Instance()->tos_ms_stop_tmb_task();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
