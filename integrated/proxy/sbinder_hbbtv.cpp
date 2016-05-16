/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_hbbtv.sidl
 */
 

#define LOG_TAG     "sbinder_hbbtv"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_hbbtv.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_HBBTV);


#define SERVICE_DESCRIPTOR                      "fcb84220-9f0c-11e5-87e5-005056a86db3"
#define SERVICE_NAME                            "sbinder_hbbtv"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_hbbtv_is_exist FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_hbbtv_open FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_hbbtv_close FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_hbbtv_get_state FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_hbbtv_handle_key FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_hbbtv_get_mode FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_hbbtv_set_mode FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_hbbtv_get_cookie_mode FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_hbbtv_set_cookie_mode FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_hbbtv_teletext_is_exist FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_hbbtv_teletext_is_open FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_hbbtv_teletext_open FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_hbbtv_teletext_close FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_hbbtv_open_portal FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_hbbtv_close_portal FIRST_CALL_TRANSACTION + 15


using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_hbbtv.h"

class sbinder_hbbtv_service : public BBinder  
{  
private:
    static sbinder_hbbtv_service* _instance;

    sbinder_hbbtv_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_hbbtv_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_hbbtv_service();
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

            case TRANSACTION_tos_hbbtv_is_exist:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_is_exist here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _exist_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* exist = NULL;

                Parcel::WritableBlob _exist_wblob;

                if(_exist_len > 0) {
                    reply->writeInt32(_exist_len);
                    reply->writeBlob(_exist_len,&_exist_wblob);
                    exist = (fpi_bool*)_exist_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                exist = (fpi_bool*)_exist_wblob.data();
                fpi_error _result = tos_hbbtv_is_exist( exist );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_is_exist here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_open(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_close(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_get_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_get_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_HBBTV_STATE* state = NULL;

                Parcel::WritableBlob _state_wblob;

                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (EN_TOS_HBBTV_STATE*)_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                state = (EN_TOS_HBBTV_STATE*)_state_wblob.data();
                fpi_error _result = tos_hbbtv_get_state( state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_get_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_handle_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_handle_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t keyCode = (uint16_t)data.readInt32();  //uint16_t as input paramter

                uint16_t keyType = (uint16_t)data.readInt32();  //uint16_t as input paramter

                int _isHandle_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* isHandle = NULL;

                Parcel::WritableBlob _isHandle_wblob;

                if(_isHandle_len > 0) {
                    reply->writeInt32(_isHandle_len);
                    reply->writeBlob(_isHandle_len,&_isHandle_wblob);
                    isHandle = (fpi_bool*)_isHandle_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                isHandle = (fpi_bool*)_isHandle_wblob.data();
                fpi_error _result = tos_hbbtv_handle_key( keyCode, keyType, isHandle );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_handle_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_get_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_get_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (fpi_bool*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (fpi_bool*)_mode_wblob.data();
                fpi_error _result = tos_hbbtv_get_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_get_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_set_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_set_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool mode = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_set_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_set_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_get_cookie_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_get_cookie_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (fpi_bool*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (fpi_bool*)_mode_wblob.data();
                fpi_error _result = tos_hbbtv_get_cookie_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_get_cookie_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_set_cookie_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_set_cookie_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool mode = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_set_cookie_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_set_cookie_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_teletext_is_exist:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_teletext_is_exist here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _exist_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* exist = NULL;

                Parcel::WritableBlob _exist_wblob;

                if(_exist_len > 0) {
                    reply->writeInt32(_exist_len);
                    reply->writeBlob(_exist_len,&_exist_wblob);
                    exist = (fpi_bool*)_exist_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                exist = (fpi_bool*)_exist_wblob.data();
                fpi_error _result = tos_hbbtv_teletext_is_exist( exist );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_teletext_is_exist here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_teletext_is_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_teletext_is_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _open_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* open = NULL;

                Parcel::WritableBlob _open_wblob;

                if(_open_len > 0) {
                    reply->writeInt32(_open_len);
                    reply->writeBlob(_open_len,&_open_wblob);
                    open = (fpi_bool*)_open_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                open = (fpi_bool*)_open_wblob.data();
                fpi_error _result = tos_hbbtv_teletext_is_open( open );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_teletext_is_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_teletext_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_teletext_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_teletext_open(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_teletext_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hbbtv_teletext_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_teletext_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_teletext_close(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_teletext_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            case TRANSACTION_tos_hbbtv_open_portal:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_open_portal here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _webPortalURL_len = data.readInt32(); //read length, only 32bits length support yet
                char* webPortalURL = NULL;

                Parcel::ReadableBlob _webPortalURL_rblob;

                if(_webPortalURL_len > 0) {
                    data.readBlob(_webPortalURL_len,&_webPortalURL_rblob);
                    webPortalURL = (char*)_webPortalURL_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                webPortalURL = (char*)_webPortalURL_rblob.data();
                fpi_error _result = tos_hbbtv_open_portal( webPortalURL );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_open_portal here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);
                return NO_ERROR;
            } break;

			case TRANSACTION_tos_hbbtv_close_portal:
            {
                 data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hbbtv_close_portal here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hbbtv_close_portal(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hbbtv_close_portal here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);
				return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_hbbtv_service_add() {
    sbinder_hbbtv_service::Instance();
    return 0;
}

sbinder_hbbtv_service* sbinder_hbbtv_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_hbbtv_client  
{  
private:
    static sbinder_hbbtv_client* _instance;
    sp<IBinder> _binder;

    sbinder_hbbtv_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_hbbtv_client() {
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

public:  
    static sbinder_hbbtv_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_hbbtv_client();
        }

        return _instance;
    }

    fpi_error tos_hbbtv_is_exist( fpi_bool* exist ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_is_exist here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (exist == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_is_exist,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (exist != NULL) {
                    int _exist_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _exist_rblob;
                    reply.readBlob(_exist_len,&_exist_rblob);
                    memcpy(exist,_exist_rblob.data(),_exist_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_is_exist error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_is_exist error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_is_exist here --*/
    }

    fpi_error tos_hbbtv_open(  ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_open here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_hbbtv_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_open error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_open error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_open here --*/
    }

    fpi_error tos_hbbtv_close(  ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_close here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_hbbtv_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_close error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_close error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_close here --*/
    }

    fpi_error tos_hbbtv_get_state( EN_TOS_HBBTV_STATE* state ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_get_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_HBBTV_STATE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_get_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_state error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_get_state here --*/
    }

    fpi_error tos_hbbtv_handle_key( uint16_t keyCode, uint16_t keyType, fpi_bool* isHandle ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_handle_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(keyCode);  //uint16_t as input paramter

            data.writeInt32(keyType);  //uint16_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (isHandle == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_handle_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (isHandle != NULL) {
                    int _isHandle_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _isHandle_rblob;
                    reply.readBlob(_isHandle_len,&_isHandle_rblob);
                    memcpy(isHandle,_isHandle_rblob.data(),_isHandle_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_handle_key error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_handle_key error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_handle_key here --*/
    }

    fpi_error tos_hbbtv_get_mode( fpi_bool* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_get_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_get_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_mode error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_get_mode here --*/
    }

    fpi_error tos_hbbtv_set_mode( fpi_bool mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_set_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_hbbtv_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_set_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_set_mode error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_set_mode here --*/
    }

    fpi_error tos_hbbtv_get_cookie_mode( fpi_bool* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_get_cookie_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_get_cookie_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_cookie_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_get_cookie_mode error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_get_cookie_mode here --*/
    }

    fpi_error tos_hbbtv_set_cookie_mode( fpi_bool mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_set_cookie_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_hbbtv_set_cookie_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_set_cookie_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_set_cookie_mode error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_set_cookie_mode here --*/
    }

    fpi_error tos_hbbtv_teletext_is_exist( fpi_bool* exist ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_teletext_is_exist here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (exist == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_teletext_is_exist,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (exist != NULL) {
                    int _exist_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _exist_rblob;
                    reply.readBlob(_exist_len,&_exist_rblob);
                    memcpy(exist,_exist_rblob.data(),_exist_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_is_exist error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_is_exist error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_teletext_is_exist here --*/
    }

    fpi_error tos_hbbtv_teletext_is_open( fpi_bool* open ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_teletext_is_open here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (open == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hbbtv_teletext_is_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (open != NULL) {
                    int _open_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _open_rblob;
                    reply.readBlob(_open_len,&_open_rblob);
                    memcpy(open,_open_rblob.data(),_open_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_is_open error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_is_open error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_teletext_is_open here --*/
    }

    fpi_error tos_hbbtv_teletext_open(  ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_teletext_open here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_hbbtv_teletext_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_open error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hbbtv_teletext_open error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_teletext_open here --*/
    }

    fpi_error tos_hbbtv_teletext_close(  ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_teletext_close here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_hbbtv_teletext_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_hbbtv_teletext_close error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_hbbtv_teletext_close error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_teletext_close here --*/
    }

    fpi_error tos_hbbtv_open_portal( char* webPortalURL ) {
        Parcel data, reply;
		int len = 0;

        /*-- add you code for tos_hbbtv_open_portal here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (NULL == webPortalURL || 0 == strlen(webPortalURL)) {
                data.writeInt32(-1);
            } else {
                data.writeInt32((int)(1024) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _webPortalURL_wblob;
                data.writeBlob((1024) * sizeof(char),&_webPortalURL_wblob);
				
				if (NULL == _webPortalURL_wblob.data())
				{
					TOSLOGW(SERVICE_NAME"_client tos_hbbtv_open_portal error");
					return _result;
				}
				
				len = strlen(webPortalURL) + 1;
				if (len > 1024) {
					len = 1024;
				}
				
				memset(_webPortalURL_wblob.data(), 0, (1024)* sizeof(char));
                memcpy(_webPortalURL_wblob.data(), webPortalURL, len);
            }

            _binder->transact(TRANSACTION_tos_hbbtv_open_portal,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_hbbtv_open_portal error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_hbbtv_open_portal error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_open_portal here --*/
    }

	
    fpi_error tos_hbbtv_close_portal(  ) {
        Parcel data, reply;

        /*-- add you code for tos_hbbtv_close_portal here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_hbbtv_close_portal,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_hbbtv_close_portal error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_hbbtv_close_portal error");
        }

        return _result;
        /*-- add you code for tos_hbbtv_close_portal here --*/
    }
};

sbinder_hbbtv_client* sbinder_hbbtv_client::_instance = NULL;

fpi_error tos_hbbtv_is_exist( fpi_bool* exist ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_is_exist(exist);
}
fpi_error tos_hbbtv_open(  ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_open();
}
fpi_error tos_hbbtv_close(  ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_close();
}
fpi_error tos_hbbtv_get_state( EN_TOS_HBBTV_STATE* state ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_get_state(state);
}
fpi_error tos_hbbtv_handle_key( uint16_t keyCode, uint16_t keyType, fpi_bool* isHandle ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_handle_key(keyCode, keyType, isHandle);
}
fpi_error tos_hbbtv_get_mode( fpi_bool* mode ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_get_mode(mode);
}
fpi_error tos_hbbtv_set_mode( fpi_bool mode ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_set_mode(mode);
}
fpi_error tos_hbbtv_get_cookie_mode( fpi_bool* mode ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_get_cookie_mode(mode);
}
fpi_error tos_hbbtv_set_cookie_mode( fpi_bool mode ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_set_cookie_mode(mode);
}
fpi_error tos_hbbtv_teletext_is_exist( fpi_bool* exist ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_teletext_is_exist(exist);
}
fpi_error tos_hbbtv_teletext_is_open( fpi_bool* open ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_teletext_is_open(open);
}
fpi_error tos_hbbtv_teletext_open(  ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_teletext_open();
}
fpi_error tos_hbbtv_teletext_close(  ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_teletext_close();
}
fpi_error tos_hbbtv_open_portal( char* webPortalURL ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_open_portal(webPortalURL);
}
fpi_error tos_hbbtv_close_portal(  ) {
    return sbinder_hbbtv_client::Instance()->tos_hbbtv_close_portal();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
