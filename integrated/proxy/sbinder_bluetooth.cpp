/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_bluetooth.sidl
 */
 

#define LOG_TAG     "sbinder_bluetooth"

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_bluetooth.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_BLUETOOTH);


#define SERVICE_DESCRIPTOR                      "7101a54a-a139-11e4-a776-005056a84a3b"
#define SERVICE_NAME                            "sbinder_bluetooth"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_bluetooth_set_master FIRST_CALL_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_bluetooth.h"

class sbinder_bluetooth_service : public BBinder  
{  
private:
    static sbinder_bluetooth_service* _instance;

    sbinder_bluetooth_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_bluetooth_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_bluetooth_service();
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

            case TRANSACTION_tos_bluetooth_set_master:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_bluetooth_set_master here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                API_BT_GLASS_MATCH api_bt_glass = (API_BT_GLASS_MATCH)data.readInt32();  //API_BT_GLASS_MATCH as input paramter

                fpi_error _result = tos_bluetooth_set_master( api_bt_glass );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_bluetooth_set_master here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_bluetooth_service_add() {
    sbinder_bluetooth_service::Instance();
    return 0;
}

sbinder_bluetooth_service* sbinder_bluetooth_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_bluetooth_client  
{  
private:
    static sbinder_bluetooth_client* _instance;
    sp<IBinder> _binder;

    sbinder_bluetooth_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_bluetooth_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_bluetooth_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_bluetooth_client();
        }

        return _instance;
    }

    fpi_error tos_bluetooth_set_master( API_BT_GLASS_MATCH api_bt_glass ) {
        Parcel data, reply;

        /*-- add you code for tos_bluetooth_set_master here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(api_bt_glass);  //API_BT_GLASS_MATCH as input paramter

            _binder->transact(TRANSACTION_tos_bluetooth_set_master,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_bluetooth_set_master error");
        }

        return _result;
        /*-- add you code for tos_bluetooth_set_master here --*/
    }
};

sbinder_bluetooth_client* sbinder_bluetooth_client::_instance = NULL;

fpi_error tos_bluetooth_set_master( API_BT_GLASS_MATCH api_bt_glass ) {
    return sbinder_bluetooth_client::Instance()->tos_bluetooth_set_master(api_bt_glass);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
