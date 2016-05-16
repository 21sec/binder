/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_decoder.sidl
 */
 

#define LOG_TAG     "sbinder_decoder"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpp_decoder.h"

SET_MODEL_ID(SITA_MODULE_PROXY);

#define SERVICE_DESCRIPTOR                      "75c28dc2-e415-11e5-9808-005056a81ef4"
#define SERVICE_NAME                            "sbinder_decoder"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_fpp_decoder_get_device_count FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_fpp_decoder_get_device_info FIRST_CALL_TRANSACTION + 2

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_decoder.h"

class sbinder_decoder_service : public BBinder  
{  
private:
    static sbinder_decoder_service* _instance;

    sbinder_decoder_service(){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_decoder_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_decoder_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        TOSLOGD(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_fpp_decoder_get_device_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_decoder_get_device_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* count = NULL;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (uint32_t*)_count_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                count = (uint32_t*)_count_wblob.data();
                fpi_error _result = fpp_decoder_get_device_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_decoder_get_device_count here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_decoder_get_device_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_decoder_get_device_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int decoder_count = 0;
				fpi_error _result = fpp_decoder_get_device_count( (uint32_t*)&decoder_count );

				//TOSLOGD("decoder_count = %d\n",decoder_count);
				
				reply->writeInt32( decoder_count ); 

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _pst_decoderInfo_len = data.readInt32(); //read length, only 32bits length support yet
                //TOSLOGD("_pst_decoderInfo_len = %d\n",_pst_decoderInfo_len);
                _pst_decoderInfo_len = decoder_count * sizeof( ST_FPP_DECODER_INFO_T );
                //TOSLOGD("@_pst_decoderInfo_len = %d",_pst_decoderInfo_len);
	
                ST_FPP_DECODER_INFO_T* pst_decoderInfo = NULL;

                Parcel::WritableBlob _pst_decoderInfo_wblob;

                if(_pst_decoderInfo_len > 0) {
                    reply->writeInt32(_pst_decoderInfo_len);
                    reply->writeBlob(_pst_decoderInfo_len,&_pst_decoderInfo_wblob);
                    pst_decoderInfo = (ST_FPP_DECODER_INFO_T*)_pst_decoderInfo_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pst_decoderInfo = (ST_FPP_DECODER_INFO_T*)_pst_decoderInfo_wblob.data();
                _result = fpp_decoder_get_device_info( pst_decoderInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_decoder_get_device_info here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_decoder_service_add() {
    sbinder_decoder_service::Instance();
    return 0;
}

sbinder_decoder_service* sbinder_decoder_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_decoder_client  
{  
private:
    static sbinder_decoder_client* _instance;
    sp<IBinder> _binder;

    sbinder_decoder_client()
        :_binder(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_decoder_client() {
        TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            TOSLOGW(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static sbinder_decoder_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_decoder_client();
        }

        return _instance;
    }

    fpi_error fpp_decoder_get_device_count( uint32_t* count ) {
        Parcel data, reply;

        /*-- add you code for fpp_decoder_get_device_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_fpp_decoder_get_device_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client fpp_decoder_get_device_count error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client fpp_decoder_get_device_count error");
        }

        return _result;
        /*-- add you code for fpp_decoder_get_device_count here --*/
    }

    fpi_error fpp_decoder_get_device_info( ST_FPP_DECODER_INFO_T* pst_decoderInfo ) {
        Parcel data, reply;

        /*-- add you code for fpp_decoder_get_device_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;

        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy         
            if (pst_decoderInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)( 10 ) * sizeof(ST_FPP_DECODER_INFO_T));//write length, only support 32 bits length yet
                
            }

			_binder->transact(TRANSACTION_fpp_decoder_get_device_info,data, &reply,0);
			
            if(reply.readExceptionCode() == 0) {//fix check

                if (pst_decoderInfo != NULL) {
					
					int _count_len = 0;
					int _pst_decoderInfo_len = 0;
					_count_len = _count_len;
					_pst_decoderInfo_len = _pst_decoderInfo_len;
					_count_len =reply.readInt32(); //read length, only 32bits length support yet
					//TOSLOGD( "_count_len = %d\n",_count_len);
					_pst_decoderInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    //CLOGI( "_pst_decoderInfo_len = %d\n",_pst_decoderInfo_len);
					//CLOGI( "sizeof(ST_FPP_DECODER_INFO_T) = %d\n",sizeof(ST_FPP_DECODER_INFO_T));
                    Parcel::ReadableBlob _pst_decoderInfo_rblob;
                    reply.readBlob(_pst_decoderInfo_len,&_pst_decoderInfo_rblob);
                    memcpy(pst_decoderInfo,_pst_decoderInfo_rblob.data(),_pst_decoderInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client fpp_decoder_get_device_info error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client fpp_decoder_get_device_info error");
        }

        return _result;
        /*-- add you code for fpp_decoder_get_device_info here --*/
    }
};

sbinder_decoder_client* sbinder_decoder_client::_instance = NULL;

fpi_error fpp_decoder_get_device_count( uint32_t* count ) {
    return sbinder_decoder_client::Instance()->fpp_decoder_get_device_count(count);
}
fpi_error fpp_decoder_get_device_info( ST_FPP_DECODER_INFO_T* pst_decoderInfo ) {
    return sbinder_decoder_client::Instance()->fpp_decoder_get_device_info(pst_decoderInfo);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
