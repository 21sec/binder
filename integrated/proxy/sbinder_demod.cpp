/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_demod.sidl
 */
 

#define LOG_TAG     "sbinder_demod"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_demod.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PLAY);

#define SERVICE_DESCRIPTOR                      "5c4af91e-e705-11e4-b211-005056a86db3"
#define SERVICE_NAME                            "sbinder_demod"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_demod_lock_freqency FIRST_CALL_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_demod.h"

class sbinder_demod_service : public BBinder  
{  
private:
    static sbinder_demod_service* _instance;

    sbinder_demod_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_demod_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_demod_service();
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

            case TRANSACTION_tos_demod_lock_freqency:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_demod_lock_freqency here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_dtv_delivery_t dtv_delivery ;
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(fpi_dtv_delivery_t) )
					{
						memcpy(&dtv_delivery,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
                    }
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_demod_lock_freqency( &dtv_delivery );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_demod_lock_freqency here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_demod_service_add() {
    sbinder_demod_service::Instance();
    return 0;
}

sbinder_demod_service* sbinder_demod_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_demod_client  
{  
private:
    static sbinder_demod_client* _instance;
    sp<IBinder> _binder;

    sbinder_demod_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_demod_client() {
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
    static sbinder_demod_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_demod_client();
        }

        return _instance;
    }

    fpi_error tos_demod_lock_freqency( fpi_dtv_delivery_t *dtv_delivery ) {
        Parcel data, reply;

        /*-- add you code for tos_demod_lock_freqency here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(fpi_dtv_delivery_t));//write length, only support 32 bits length yet
                
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(fpi_dtv_delivery_t),&_pin_wblob);
            memcpy(_pin_wblob.data(),dtv_delivery,(1)* sizeof(fpi_dtv_delivery_t));

            _binder->transact(TRANSACTION_tos_demod_lock_freqency,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_demod_lock_freqency error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_demod_lock_freqency error");
        }

        return _result;
        /*-- add you code for tos_demod_lock_freqency here --*/
    }
};

sbinder_demod_client* sbinder_demod_client::_instance = NULL;

fpi_error tos_demod_lock_freqency( fpi_dtv_delivery_t *dtv_delivery ) {
    return sbinder_demod_client::Instance()->tos_demod_lock_freqency(dtv_delivery);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
