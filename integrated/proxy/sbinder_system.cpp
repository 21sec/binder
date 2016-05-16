/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: integrated/sidl/sbinder_system.sidl
 */
 

#define LOG_TAG     "sbinder_system"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpp_system.h"


#define SERVICE_DESCRIPTOR                      "24a5c936-18d1-11e6-a6f9-005056a86db3"
#define SERVICE_NAME                            "sbinder_system"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_fpp_system_get_average_luma FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_fpp_system_get_luma_level_distribution FIRST_CALL_TRANSACTION + 2

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_system.h"

class sbinder_system_service : public BBinder  
{  
private:
    static sbinder_system_service* _instance;

    sbinder_system_service(){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_system_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_system_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        TOSLOGI(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_fpp_system_get_average_luma:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_system_get_average_luma here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _val_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* val = NULL;

                Parcel::WritableBlob _val_wblob;

                if(_val_len > 0) {
                    reply->writeInt32(_val_len);
                    reply->writeBlob(_val_len,&_val_wblob);
                    val = (uint8_t*)_val_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                val = (uint8_t*)_val_wblob.data();
                fpi_error _result = fpp_system_get_average_luma( val );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_system_get_average_luma here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_fpp_system_get_luma_level_distribution:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for fpp_system_get_luma_level_distribution here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _luma_distribution_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* luma_distribution = NULL;

                Parcel::WritableBlob _luma_distribution_wblob;

                if(_luma_distribution_len > 0) {
                    reply->writeInt32(_luma_distribution_len);
                    reply->writeBlob(_luma_distribution_len,&_luma_distribution_wblob);
                    luma_distribution = (uint16_t*)_luma_distribution_wblob.data();
                }

                uint8_t size = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                luma_distribution = (uint16_t*)_luma_distribution_wblob.data();
                fpi_error _result = fpp_system_get_luma_level_distribution( luma_distribution, size );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for fpp_system_get_luma_level_distribution here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_system_service_add() {
    sbinder_system_service::Instance();
    return 0;
}

sbinder_system_service* sbinder_system_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_system_client  
{  
private:
    static sbinder_system_client* _instance;
    sp<IBinder> _binder;

    sbinder_system_client()
        :_binder(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_system_client() {
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
    static sbinder_system_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_system_client();
        }

        return _instance;
    }

    fpi_error fpp_system_get_average_luma( uint8_t* val ) {
        Parcel data, reply;

        /*-- add you code for fpp_system_get_average_luma here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (val == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_fpp_system_get_average_luma,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (val != NULL) {
                    int _val_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _val_rblob;
                    reply.readBlob(_val_len,&_val_rblob);
                    memcpy(val,_val_rblob.data(),_val_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client fpp_system_get_average_luma error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client fpp_system_get_average_luma error");
        }

        return _result;
        /*-- add you code for fpp_system_get_average_luma here --*/
    }

    fpi_error fpp_system_get_luma_level_distribution( uint16_t* luma_distribution, uint8_t size ) {
        Parcel data, reply;

        /*-- add you code for fpp_system_get_luma_level_distribution here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (luma_distribution == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(size) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(size);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_fpp_system_get_luma_level_distribution,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (luma_distribution != NULL) {
                    int _luma_distribution_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _luma_distribution_rblob;
                    reply.readBlob(_luma_distribution_len,&_luma_distribution_rblob);
                    memcpy(luma_distribution,_luma_distribution_rblob.data(),_luma_distribution_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client fpp_system_get_luma_level_distribution error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client fpp_system_get_luma_level_distribution error");
        }

        return _result;
        /*-- add you code for fpp_system_get_luma_level_distribution here --*/
    }
};

sbinder_system_client* sbinder_system_client::_instance = NULL;

fpi_error fpp_system_get_average_luma( uint8_t* val ) {
    return sbinder_system_client::Instance()->fpp_system_get_average_luma(val);
}
fpi_error fpp_system_get_luma_level_distribution( uint16_t* luma_distribution, uint8_t size ) {
    return sbinder_system_client::Instance()->fpp_system_get_luma_level_distribution(luma_distribution, size);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
