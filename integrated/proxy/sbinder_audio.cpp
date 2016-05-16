/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_audio.sidl
 */
 

#define LOG_TAG     "sbinder_audio"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpp_audio.h"

SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "834e1918-b394-11e5-8481-005056a81ef4"
#define SERVICE_NAME                            "sbinder_audio"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_fpp_audio_record_init FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_fpp_audio_set_record_param FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_fpp_audio_get_read_buffer_address FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_fpp_audio_get_buffer_real_size FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_fpp_audio_reset_buffer FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_fpp_audio_confirm_data FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_fpp_audio_record_control FIRST_CALL_TRANSACTION + 7

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_audio.h"

class sbinder_audio_service : public BBinder  
{  
private:
    static sbinder_audio_service* _instance;

    sbinder_audio_service(){
        CLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_audio_service() {
        CLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_audio_service();
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

            case TRANSACTION_fpp_audio_record_init:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_record_init here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t u32_buffersize = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_audio_record_init( u32_buffersize );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_record_init here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_set_record_param:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_set_record_param here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPP_LINEIN_TYPE_T en_linein = (EN_FPP_LINEIN_TYPE_T)data.readInt32();  //EN_FPP_LINEIN_TYPE_T as input paramter

                ST_RECORD_AUDIO_PARAM_T param;

				memset(&param,0,sizeof(param)); 
				
				param.audio_sample_rate = (EN_RECORD_AUDIO_SAMPLE_RATE_T)data.readInt32();
				param.audio_bit_rate = (EN_RECORD_AUDIO_SAMPLE_BIT_T)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_audio_set_record_param( en_linein, param );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_set_record_param here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_get_read_buffer_address:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_get_read_buffer_address here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _un32_addr_len = 0; //read length, only 32bits length support yet
                uint32_t* un32_addr = NULL;
				
				
				int _un32_size_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* un32_size = NULL;
				
				Parcel::WritableBlob _un32_size_wblob;
				
				if(_un32_size_len > 0) {
                    reply->writeInt32(_un32_size_len);
                    reply->writeBlob(_un32_size_len,&_un32_size_wblob);
                    un32_size = (uint32_t*)_un32_size_wblob.data();
                }
				
				fpi_error _result = fpp_audio_get_read_buffer_address( &un32_addr, un32_size );
				
				_un32_addr_len = data.readInt32();
				
                Parcel::WritableBlob _un32_addr_wblob;
				if(* un32_size <= 40 * 1024)
				{
					_un32_addr_len = * un32_size;
				}
				else
				{
					_un32_addr_len = 40 * 1024;
				}
                if(_un32_addr_len > 0) {
                    reply->writeInt32(_un32_addr_len);
                    reply->writeBlob(_un32_addr_len,&_un32_addr_wblob);
                    memcpy(_un32_addr_wblob.data(),un32_addr,_un32_addr_len);
                }

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_get_read_buffer_address here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_get_buffer_real_size:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_get_buffer_real_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _un32_realsize_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* un32_realsize = NULL;

                Parcel::WritableBlob _un32_realsize_wblob;

                if(_un32_realsize_len > 0) {
                    reply->writeInt32(_un32_realsize_len);
                    reply->writeBlob(_un32_realsize_len,&_un32_realsize_wblob);
                    un32_realsize = (uint32_t*)_un32_realsize_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                un32_realsize = (uint32_t*)_un32_realsize_wblob.data();
                fpi_error _result = fpp_audio_get_buffer_real_size( un32_realsize );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_get_buffer_real_size here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_reset_buffer:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_reset_buffer here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_audio_reset_buffer(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_reset_buffer here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_confirm_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_confirm_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t address = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t real_size = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_audio_confirm_data( address, real_size );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_confirm_data here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_audio_record_control:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_audio_record_control here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_CONTROL_TYPE_T en_control_type = (EN_CONTROL_TYPE_T)data.readInt32();  //EN_CONTROL_TYPE_T as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = fpp_audio_record_control( en_control_type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_audio_record_control here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        CLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_audio_service_add() {
    sbinder_audio_service::Instance();
    return 0;
}

sbinder_audio_service* sbinder_audio_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_audio_client  
{  
private:
    static sbinder_audio_client* _instance;
    sp<IBinder> _binder;

    sbinder_audio_client()
        :_binder(NULL) {
        CLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_audio_client() {
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
    static sbinder_audio_client* Instance() {
        if(_instance == NULL) {
            CLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_audio_client();
        }

        return _instance;
    }

    fpi_error fpp_audio_record_init( uint32_t u32_buffersize ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_record_init here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(u32_buffersize);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_audio_record_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_record_init error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_record_init error");
        }

        return _result;
        /*-- add you code for fpp_audio_record_init here --*/
    }

    fpi_error fpp_audio_set_record_param( EN_FPP_LINEIN_TYPE_T en_linein, ST_RECORD_AUDIO_PARAM_T param ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_set_record_param here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(en_linein);  //EN_FPP_LINEIN_TYPE_T as input paramter

            data.writeInt32(param.audio_sample_rate);
			
			data.writeInt32(param.audio_bit_rate);

            _binder->transact(TRANSACTION_fpp_audio_set_record_param,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_set_record_param error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_set_record_param error");
        }

        return _result;
        /*-- add you code for fpp_audio_set_record_param here --*/
    }

    fpi_error fpp_audio_get_read_buffer_address( uint32_t** un32_addr, uint32_t* un32_size ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_get_read_buffer_address here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
			
			if (un32_size == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }
			
            if (un32_addr == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(2*1024*1024) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_fpp_audio_get_read_buffer_address,data, &reply,0);

            if(reply.readExceptionCode() == 0) 
			{//fix check

		
				if (un32_size != NULL) 
				{
                    int _un32_size_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _un32_size_rblob;
                    reply.readBlob(_un32_size_len,&_un32_size_rblob);
                    memcpy(un32_size,_un32_size_rblob.data(),_un32_size_len);
                }
				
                if (un32_addr != NULL) 
				{
                    int _un32_addr_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _un32_addr_rblob;
                    reply.readBlob(_un32_addr_len,&_un32_addr_rblob);
                    
					*un32_addr = (uint32_t *)_un32_addr_rblob.data();
                }
                
                _result = (typeof(_result))reply.readInt32();//int as return value

            } 
			else 
			{
                CLOGW(SERVICE_NAME"_client fpp_audio_get_read_buffer_address error");
            }
        }
		catch(...) 
		{
            CLOGW(SERVICE_NAME"_client fpp_audio_get_read_buffer_address error");
        }

        return _result;
        /*-- add you code for fpp_audio_get_read_buffer_address here --*/
    }

    fpi_error fpp_audio_get_buffer_real_size( uint32_t* un32_realsize ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_get_buffer_real_size here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (un32_realsize == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_fpp_audio_get_buffer_real_size,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (un32_realsize != NULL) {
                    int _un32_realsize_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _un32_realsize_rblob;
                    reply.readBlob(_un32_realsize_len,&_un32_realsize_rblob);
                    memcpy(un32_realsize,_un32_realsize_rblob.data(),_un32_realsize_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_get_buffer_real_size error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_get_buffer_real_size error");
        }

        return _result;
        /*-- add you code for fpp_audio_get_buffer_real_size here --*/
    }

    fpi_error fpp_audio_reset_buffer(  ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_reset_buffer here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_fpp_audio_reset_buffer,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_reset_buffer error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_reset_buffer error");
        }

        return _result;
        /*-- add you code for fpp_audio_reset_buffer here --*/
    }

    fpi_error fpp_audio_confirm_data( uint32_t address, uint32_t real_size ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_confirm_data here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(address);  //uint32_t as input paramter

            data.writeInt32(real_size);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_fpp_audio_confirm_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_confirm_data error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_confirm_data error");
        }

        return _result;
        /*-- add you code for fpp_audio_confirm_data here --*/
    }

    fpi_error fpp_audio_record_control( EN_CONTROL_TYPE_T en_control_type ) {
        Parcel data, reply;

        /*-- add you code for fpp_audio_record_control here --*/
         fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(en_control_type);  //EN_CONTROL_TYPE_T as input paramter

            _binder->transact(TRANSACTION_fpp_audio_record_control,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client fpp_audio_record_control error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client fpp_audio_record_control error");
        }

        return _result;
        /*-- add you code for fpp_audio_record_control here --*/
    }
};

sbinder_audio_client* sbinder_audio_client::_instance = NULL;

fpi_error fpp_audio_record_init( uint32_t u32_buffersize ) {
    return sbinder_audio_client::Instance()->fpp_audio_record_init(u32_buffersize);
}
fpi_error fpp_audio_set_record_param( EN_FPP_LINEIN_TYPE_T en_linein, ST_RECORD_AUDIO_PARAM_T param ) {
    return sbinder_audio_client::Instance()->fpp_audio_set_record_param(en_linein, param);
}
fpi_error fpp_audio_get_read_buffer_address( uint32_t** un32_addr, uint32_t* un32_size ) {
    return sbinder_audio_client::Instance()->fpp_audio_get_read_buffer_address(un32_addr, un32_size);
}
fpi_error fpp_audio_get_buffer_real_size( uint32_t* un32_realsize ) {
    return sbinder_audio_client::Instance()->fpp_audio_get_buffer_real_size(un32_realsize);
}
fpi_error fpp_audio_reset_buffer(  ) {
    return sbinder_audio_client::Instance()->fpp_audio_reset_buffer();
}
fpi_error fpp_audio_confirm_data( uint32_t address, uint32_t real_size ) {
    return sbinder_audio_client::Instance()->fpp_audio_confirm_data(address, real_size);
}
fpi_error fpp_audio_record_control( EN_CONTROL_TYPE_T en_control_type ) {
    return sbinder_audio_client::Instance()->fpp_audio_record_control(en_control_type);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
