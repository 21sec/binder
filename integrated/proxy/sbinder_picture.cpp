/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: ../../integrated/sidl/sbinder_picture.sidl
 */
 

#define LOG_TAG     "sbinder_picture"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpp_picture.h"


#define SERVICE_DESCRIPTOR                      "42fdc536-b80b-11e5-a6b7-005056a86db3"
#define SERVICE_NAME                            "sbinder_picture"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_fpp_picture_create FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_fpp_picture_delete FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_fpp_picture_push_data FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_fpp_picture_decode_data FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_fpp_picture_push_eos FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_fpp_picture_set_param FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_fpp_picture_show FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_fpp_picture_hide FIRST_CALL_TRANSACTION + 8

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_picture.h"

class sbinder_picture_service : public BBinder  
{  
private:
    static sbinder_picture_service* _instance;

    sbinder_picture_service(){
        CLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_picture_service() {
        CLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_picture_service();
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

            case TRANSACTION_fpp_picture_create:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_create here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _handle_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* handle = NULL;

                Parcel::WritableBlob _handle_wblob;

                if(_handle_len > 0) {
                    reply->writeInt32(_handle_len);
                    reply->writeBlob(_handle_len,&_handle_wblob);
                    handle = (uint32_t*)_handle_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                handle = (uint32_t*)_handle_wblob.data();
                fpi_error _result = fpp_picture_create( handle );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_create here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_delete:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_delete here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_picture_delete( handle );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_delete here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_push_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_push_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _pname_len = data.readInt32(); //read length, only 32bits length support yet
                char* pname = NULL;

                Parcel::ReadableBlob _pname_rblob;

                if(_pname_len > 0) {
                    data.readBlob(_pname_len,&_pname_rblob);
                    pname = (char*)_pname_rblob.data();
                }

                uint32_t size = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                pname = (char*)_pname_rblob.data();
                fpi_error _result = fpp_picture_push_data( handle, (uint8_t*)pname, size );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_push_data here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_decode_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_decode_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _pImgData_len = data.readInt32(); //read length, only 32bits length support yet
                const uint8_t* pImgData = NULL;

                Parcel::ReadableBlob _pImgData_rblob;

                if(_pImgData_len > 0) {
                    data.readBlob(_pImgData_len,&_pImgData_rblob);
                    pImgData = (const uint8_t*)_pImgData_rblob.data();
                }

                uint32_t size = (uint32_t)data.readInt32();  //uint32_t as input paramter

                 //begin paramters list
                //#error not support un-plat struct sttInfo yet, please add code yourself
                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                ST_FPP_PICTURE_RAW_BUFFER_T* pBuffer = NULL;
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    Parcel::WritableBlob _pout_wblob;
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    pBuffer = (ST_FPP_PICTURE_RAW_BUFFER_T*)_pout_wblob.data();
                }		

                // re-get all pointers from blob to fix realloc issue in Parcel
                pImgData = (const uint8_t*)_pImgData_rblob.data();
                fpi_error _result = fpp_picture_decode_data( handle, pImgData, size, pBuffer );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_decode_data here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_push_eos:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_push_eos here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_picture_push_eos( handle );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_push_eos here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_set_param:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_set_param here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPP_DISPLAY_TYPE type = (EN_FPP_DISPLAY_TYPE)data.readInt32();  //EN_FPP_DISPLAY_TYPE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_picture_set_param( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_set_param here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_show:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_show here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t windowID = (uint32_t)data.readInt32();  //uint32_t as input paramter

                //#error not support un-plat struct rect yet, please add code yourself
                ST_PICTURE_SHOW_RECT rect;
				memset(&rect,0,sizeof(rect)); 
				
				rect.x = data.readInt32();
				rect.y = data.readInt32();
				rect.width = (uint32_t)data.readInt32();
				rect.height = (uint32_t)data.readInt32();

                int32_t degree = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_picture_show( handle, windowID, rect, degree );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_show here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_picture_hide:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_picture_hide here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t handle = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t windowID = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_picture_hide( handle, windowID );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_picture_hide here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        CLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_picture_service_add() {
    sbinder_picture_service::Instance();
    return 0;
}

sbinder_picture_service* sbinder_picture_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_picture_client  
{  
private:
    static sbinder_picture_client* _instance;
    sp<IBinder> _binder;

    sbinder_picture_client()
        :_binder(NULL) {
        CLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_picture_client() {
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

public:  
    static sbinder_picture_client* Instance() {
        if(_instance == NULL) {
            CLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_picture_client();
        }

        return _instance;
    }

    fpi_error fpp_picture_create( uint32_t* handle ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_create here --*/
        fpi_error _result=FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_fpp_picture_create,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (handle != NULL) {
                    int _handle_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _handle_rblob;
                    reply.readBlob(_handle_len,&_handle_rblob);
                    memcpy(handle,_handle_rblob.data(),_handle_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_create error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_create error");
        }

        return _result;
        /*-- add you code for fpp_picture_create here --*/
    }

    fpi_error fpp_picture_delete( uint32_t handle ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_delete here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_picture_delete,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_delete error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_delete error");
        }

        return _result;
        /*-- add you code for fpp_picture_delete here --*/
    }

    fpi_error fpp_picture_push_data( uint32_t handle, const uint8_t* pname, uint32_t size ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_push_data here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            
            if (pname == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen((char*)pname)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pname_wblob;
                data.writeBlob((strlen((char*)pname)+1) * sizeof(char),&_pname_wblob);
                memcpy(_pname_wblob.data(),pname,(strlen((char*)pname)+1)* sizeof(char));
            }

            data.writeInt32(size);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_picture_push_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_push_data error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_push_data error");
        }

        return _result;
        /*-- add you code for fpp_picture_push_data here --*/
    }

    fpi_error fpp_picture_decode_data( uint32_t handle, const uint8_t* pImgData, uint32_t size, ST_FPP_PICTURE_RAW_BUFFER_T* pBuffer ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_decode_data here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pImgData == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pImgData_wblob;
                data.writeBlob((1) * sizeof(uint8_t),&_pImgData_wblob);
                memcpy(_pImgData_wblob.data(),pImgData,(1)* sizeof(uint8_t));
            }

            data.writeInt32(size);  //uint32_t as input paramter

            //#error not support un-plat struct sttInfo yet, please add code yourself
            data.writeInt32((int)(1) * sizeof(ST_FPP_PICTURE_RAW_BUFFER_T));

            _binder->transact(TRANSACTION_fpp_picture_decode_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pBuffer != NULL) {
                    int _pBuffer_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pBuffer_rblob;
                    reply.readBlob(_pBuffer_len,&_pBuffer_rblob);
                    memcpy(pBuffer,_pBuffer_rblob.data(),_pBuffer_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_decode_data error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_decode_data error");
        }

        return _result;
        /*-- add you code for fpp_picture_decode_data here --*/
    }

    fpi_error fpp_picture_push_eos( uint32_t handle ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_push_eos here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_picture_push_eos,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_push_eos error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_push_eos error");
        }

        return _result;
        /*-- add you code for fpp_picture_push_eos here --*/
    }

    fpi_error fpp_picture_set_param( EN_FPP_DISPLAY_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_set_param here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_FPP_DISPLAY_TYPE as input paramter

            _binder->transact(TRANSACTION_fpp_picture_set_param,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_set_param error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_set_param error");
        }

        return _result;
        /*-- add you code for fpp_picture_set_param here --*/
    }

    fpi_error fpp_picture_show( uint32_t handle, uint32_t windowID, ST_PICTURE_SHOW_RECT rect, int32_t degree ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_show here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            data.writeInt32(windowID);  //uint32_t as input paramter

            //#error not support un-plat struct rect yet, please add code yourself
            data.writeInt32(rect.x);
  	     data.writeInt32(rect.y);
  	     data.writeInt32((int32_t)rect.width);
	     data.writeInt32((int32_t)rect.height);
		 
            data.writeInt32(degree);  //int32_t as input paramter

            _binder->transact(TRANSACTION_fpp_picture_show,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_show error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_show error");
        }

        return _result;
        /*-- add you code for fpp_picture_show here --*/
    }

    fpi_error fpp_picture_hide( uint32_t handle, uint32_t windowID ) {
        Parcel data, reply;

        /*-- add you code for fpp_picture_hide here --*/
        fpi_error _result=FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //uint32_t as input paramter

            data.writeInt32(windowID);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_picture_hide,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_picture_hide error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_picture_hide error");
        }

        return _result;
        /*-- add you code for fpp_picture_hide here --*/
    }
};

sbinder_picture_client* sbinder_picture_client::_instance = NULL;

fpi_error fpp_picture_create( uint32_t* handle ) {
    return sbinder_picture_client::Instance()->fpp_picture_create(handle);
}
fpi_error fpp_picture_delete( uint32_t handle ) {
    return sbinder_picture_client::Instance()->fpp_picture_delete(handle);
}
fpi_error fpp_picture_push_data( uint32_t handle, const uint8_t* pname, uint32_t size ) {
    return sbinder_picture_client::Instance()->fpp_picture_push_data(handle, pname, size);
}
fpi_error fpp_picture_decode_data( uint32_t handle, const uint8_t* pImgData, uint32_t size, ST_FPP_PICTURE_RAW_BUFFER_T* pBuffer ) {
    return sbinder_picture_client::Instance()->fpp_picture_decode_data(handle, pImgData, size, pBuffer);
}
fpi_error fpp_picture_push_eos( uint32_t handle ) {
    return sbinder_picture_client::Instance()->fpp_picture_push_eos(handle);
}
fpi_error fpp_picture_set_param( EN_FPP_DISPLAY_TYPE type ) {
    return sbinder_picture_client::Instance()->fpp_picture_set_param(type);
}
fpi_error fpp_picture_show( uint32_t handle, uint32_t windowID, ST_PICTURE_SHOW_RECT rect, int32_t degree ) {
    return sbinder_picture_client::Instance()->fpp_picture_show(handle, windowID, rect, degree);
}
fpi_error fpp_picture_hide( uint32_t handle, uint32_t windowID ) {
    return sbinder_picture_client::Instance()->fpp_picture_hide(handle, windowID);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
