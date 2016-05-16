/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_teletext.sidl
 */
 

#define LOG_TAG     "sbinder_teletext"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_teletext.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_TELETEXT);


#define SERVICE_DESCRIPTOR                      "725a125c-0515-11e5-965a-005056a86db3"
#define SERVICE_NAME                            "sbinder_teletext"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_teletext_on FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_teletext_off FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_teletext_set_output_window FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_teletext_get_state FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_teletext_is_available FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_teletext_subpage_is_available FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_teletext_newsflash_is_available FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_teletext_alarmpage_is_available FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_teletext_reveal_is_on FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_teletext_subpage_cycle_is_on FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_teletext_toggle_reveal FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_teletext_toggle_subpage_cycle_model FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_teletext_set_language_group FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_teletext_get_language_group FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_teletext_set_digital_language FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_teletext_get_digital_language FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_teletext_handle_key FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_teletext_open_newsflash FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_teletext_open_alarmpage FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_teletext_set_reveal_mode FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_teletext_set_subpage_cycle_mode FIRST_CALL_TRANSACTION + 21



using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_teletext.h"

class sbinder_teletext_service : public BBinder  
{  
private:
    static sbinder_teletext_service* _instance;

    sbinder_teletext_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_teletext_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_teletext_service();
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

            case TRANSACTION_tos_teletext_on:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_on here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_on(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_on here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_off:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_off here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_off(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_off here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_set_output_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_set_output_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t x = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t y = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t width = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t height = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_set_output_window( x, y, width, height );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_set_output_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_get_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_get_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_TELETEXT_STATE* state = NULL;

                Parcel::WritableBlob _state_wblob;

                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (EN_FPI_TELETEXT_STATE*)_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                state = (EN_FPI_TELETEXT_STATE*)_state_wblob.data();
                fpi_error _result = tos_teletext_get_state( state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_get_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_is_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_is_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_is_available( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_is_available here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_subpage_is_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_subpage_is_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_subpage_is_available( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_subpage_is_available here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_newsflash_is_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_newsflash_is_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_newsflash_is_available( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_newsflash_is_available here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_alarmpage_is_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_alarmpage_is_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_alarmpage_is_available( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_alarmpage_is_available here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_reveal_is_on:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_reveal_is_on here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_reveal_is_on( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_reveal_is_on here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_subpage_cycle_is_on:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_subpage_cycle_is_on here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_teletext_subpage_cycle_is_on( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_subpage_cycle_is_on here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_toggle_reveal:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_toggle_reveal here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_toggle_reveal(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_toggle_reveal here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_toggle_subpage_cycle_model:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_toggle_subpage_cycle_model here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_toggle_subpage_cycle_model(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_toggle_subpage_cycle_model here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_set_language_group:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_set_language_group here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t groupId = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_set_language_group( groupId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_set_language_group here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_get_language_group:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_get_language_group here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _groupId_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* groupId = NULL;

                Parcel::WritableBlob _groupId_wblob;

                if(_groupId_len > 0) {
                    reply->writeInt32(_groupId_len);
                    reply->writeBlob(_groupId_len,&_groupId_wblob);
                    groupId = (uint8_t*)_groupId_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                groupId = (uint8_t*)_groupId_wblob.data();
                fpi_error _result = tos_teletext_get_language_group( groupId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_get_language_group here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_set_digital_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_set_digital_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                MEMBER_LANGUAGE language = (MEMBER_LANGUAGE)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_set_digital_language( language );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_set_digital_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_get_digital_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_get_digital_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _language_len = data.readInt32(); //read length, only 32bits length support yet
                MEMBER_LANGUAGE* language = NULL;

                Parcel::WritableBlob _language_wblob;

                if(_language_len > 0) {
                    reply->writeInt32(_language_len);
                    reply->writeBlob(_language_len,&_language_wblob);
                    language = (MEMBER_LANGUAGE*)_language_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                language = (MEMBER_LANGUAGE*)_language_wblob.data();
                fpi_error _result = tos_teletext_get_digital_language( language );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_get_digital_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_handle_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_handle_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int keyCode = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_handle_key( keyCode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_handle_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_open_newsflash:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_open_newsflash here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_open_newsflash(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_open_newsflash here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_teletext_open_alarmpage:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_open_alarmpage here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t t_time = (uint16_t)data.readInt32();  //uint16_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_open_alarmpage( t_time );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_open_alarmpage here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			 
            case TRANSACTION_tos_teletext_set_reveal_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_toggle_reveal here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

				//begin paramters list
                fpi_bool reveal_mode = (fpi_bool)data.readInt32();  //uint16_t as input paramter
                
                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_set_reveal_mode( reveal_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_toggle_reveal here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            case TRANSACTION_tos_teletext_set_subpage_cycle_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_teletext_toggle_reveal here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

				//begin paramters list
                fpi_bool subpage_mode = (fpi_bool)data.readInt32();  //uint16_t as input paramter
                
                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_teletext_set_subpage_cycle_mode( subpage_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_teletext_toggle_reveal here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;				
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_teletext_service_add() {
    sbinder_teletext_service::Instance();
    return 0;
}

sbinder_teletext_service* sbinder_teletext_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_teletext_client  
{  
private:
    static sbinder_teletext_client* _instance;
    sp<IBinder> _binder;

    sbinder_teletext_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_teletext_client() {
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
    static sbinder_teletext_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_teletext_client();
        }

        return _instance;
    }

    fpi_error tos_teletext_on(  ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_on here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_teletext_on,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_on error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_on error");
        }

        return _result;
        /*-- add you code for tos_teletext_on here --*/
    }

    fpi_error tos_teletext_off(  ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_off here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_teletext_off,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_off error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_off error");
        }

        return _result;
        /*-- add you code for tos_teletext_off here --*/
    }

    fpi_error tos_teletext_set_output_window( int32_t x, int32_t y, int32_t width, int32_t height ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_set_output_window here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(x);  //int32_t as input paramter

            data.writeInt32(y);  //int32_t as input paramter

            data.writeInt32(width);  //int32_t as input paramter

            data.writeInt32(height);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_teletext_set_output_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_set_output_window error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_set_output_window error");
        }

        return _result;
        /*-- add you code for tos_teletext_set_output_window here --*/
    }

    fpi_error tos_teletext_get_state( EN_FPI_TELETEXT_STATE* state ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_get_state here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_TELETEXT_STATE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_get_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_get_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_get_state error");
        }

        return _result;
        /*-- add you code for tos_teletext_get_state here --*/
    }

    fpi_error tos_teletext_is_available( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_is_available here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_is_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_is_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_is_available error");
        }

        return _result;
        /*-- add you code for tos_teletext_is_available here --*/
    }

    fpi_error tos_teletext_subpage_is_available( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_subpage_is_available here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_subpage_is_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_subpage_is_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_subpage_is_available error");
        }

        return _result;
        /*-- add you code for tos_teletext_subpage_is_available here --*/
    }

    fpi_error tos_teletext_newsflash_is_available( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_newsflash_is_available here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_newsflash_is_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_newsflash_is_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_newsflash_is_available error");
        }

        return _result;
        /*-- add you code for tos_teletext_newsflash_is_available here --*/
    }

    fpi_error tos_teletext_alarmpage_is_available( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_alarmpage_is_available here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_alarmpage_is_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_alarmpage_is_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_alarmpage_is_available error");
        }

        return _result;
        /*-- add you code for tos_teletext_alarmpage_is_available here --*/
    }

    fpi_error tos_teletext_reveal_is_on( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_reveal_is_on here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_reveal_is_on,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_reveal_is_on error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_reveal_is_on error");
        }

        return _result;
        /*-- add you code for tos_teletext_reveal_is_on here --*/
    }

    fpi_error tos_teletext_subpage_cycle_is_on( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_subpage_cycle_is_on here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_subpage_cycle_is_on,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_subpage_cycle_is_on error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_subpage_cycle_is_on error");
        }

        return _result;
        /*-- add you code for tos_teletext_subpage_cycle_is_on here --*/
    }

    fpi_error tos_teletext_toggle_reveal(  ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_toggle_reveal here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_teletext_toggle_reveal,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_toggle_reveal error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_toggle_reveal error");
        }

        return _result;
        /*-- add you code for tos_teletext_toggle_reveal here --*/
    }
	
	fpi_error tos_teletext_set_reveal_mode(fpi_bool revealMode) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_toggle_reveal here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(revealMode);

            _binder->transact(TRANSACTION_tos_teletext_set_reveal_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_set_reveal_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_set_reveal_mode error");
        }

        return _result;
        /*-- add you code for tos_teletext_toggle_reveal here --*/
    }

    fpi_error tos_teletext_toggle_subpage_cycle_model(  ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_toggle_subpage_cycle_model here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_teletext_toggle_subpage_cycle_model,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_toggle_subpage_cycle_model error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_toggle_subpage_cycle_model error");
        }

        return _result;
        /*-- add you code for tos_teletext_toggle_subpage_cycle_model here --*/
    }
	
	fpi_error tos_teletext_set_subpage_cycle_mode(fpi_bool subpageMode) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_toggle_reveal here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(subpageMode);

            _binder->transact(TRANSACTION_tos_teletext_set_subpage_cycle_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_set_subpage_cycle_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_set_subpage_cycle_mode error");
        }

        return _result;
        /*-- add you code for tos_teletext_toggle_reveal here --*/
    }

    fpi_error tos_teletext_set_language_group( uint8_t groupId ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_set_language_group here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(groupId);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_teletext_set_language_group,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_set_language_group error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_set_language_group error");
        }

        return _result;
        /*-- add you code for tos_teletext_set_language_group here --*/
    }

    fpi_error tos_teletext_get_language_group( uint8_t* groupId ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_get_language_group here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (groupId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_get_language_group,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (groupId != NULL) {
                    int _groupId_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _groupId_rblob;
                    reply.readBlob(_groupId_len,&_groupId_rblob);
                    memcpy(groupId,_groupId_rblob.data(),_groupId_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_get_language_group error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_get_language_group error");
        }

        return _result;
        /*-- add you code for tos_teletext_get_language_group here --*/
    }

    fpi_error tos_teletext_set_digital_language( MEMBER_LANGUAGE language ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_set_digital_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(language);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_teletext_set_digital_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_set_digital_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_set_digital_language error");
        }

        return _result;
        /*-- add you code for tos_teletext_set_digital_language here --*/
    }

    fpi_error tos_teletext_get_digital_language( MEMBER_LANGUAGE* language ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_get_digital_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (language == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(MEMBER_LANGUAGE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_teletext_get_digital_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (language != NULL) {
                    int _language_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _language_rblob;
                    reply.readBlob(_language_len,&_language_rblob);
                    memcpy(language,_language_rblob.data(),_language_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_get_digital_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_get_digital_language error");
        }

        return _result;
        /*-- add you code for tos_teletext_get_digital_language here --*/
    }

    fpi_error tos_teletext_handle_key( int keyCode ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_handle_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(keyCode);  //int as input paramter

            _binder->transact(TRANSACTION_tos_teletext_handle_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_handle_key error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_handle_key error");
        }

        return _result;
        /*-- add you code for tos_teletext_handle_key here --*/
    }

    fpi_error tos_teletext_open_newsflash(  ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_open_newsflash here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_teletext_open_newsflash,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_open_newsflash error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_open_newsflash error");
        }

        return _result;
        /*-- add you code for tos_teletext_open_newsflash here --*/
    }

    fpi_error tos_teletext_open_alarmpage( uint16_t t_time ) {
        Parcel data, reply;

        /*-- add you code for tos_teletext_open_alarmpage here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(t_time);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_teletext_open_alarmpage,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_teletext_open_alarmpage error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_teletext_open_alarmpage error");
        }

        return _result;
        /*-- add you code for tos_teletext_open_alarmpage here --*/
    }
};

sbinder_teletext_client* sbinder_teletext_client::_instance = NULL;

fpi_error tos_teletext_on(  ) {
    return sbinder_teletext_client::Instance()->tos_teletext_on();
}
fpi_error tos_teletext_off(  ) {
    return sbinder_teletext_client::Instance()->tos_teletext_off();
}
fpi_error tos_teletext_set_output_window( int32_t x, int32_t y, int32_t width, int32_t height ) {
    return sbinder_teletext_client::Instance()->tos_teletext_set_output_window(x, y, width, height);
}
fpi_error tos_teletext_get_state( EN_FPI_TELETEXT_STATE* state ) {
    return sbinder_teletext_client::Instance()->tos_teletext_get_state(state);
}
fpi_error tos_teletext_is_available( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_is_available(value);
}
fpi_error tos_teletext_subpage_is_available( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_subpage_is_available(value);
}
fpi_error tos_teletext_newsflash_is_available( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_newsflash_is_available(value);
}
fpi_error tos_teletext_alarmpage_is_available( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_alarmpage_is_available(value);
}
fpi_error tos_teletext_reveal_is_on( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_reveal_is_on(value);
}
fpi_error tos_teletext_subpage_cycle_is_on( fpi_bool* value ) {
    return sbinder_teletext_client::Instance()->tos_teletext_subpage_cycle_is_on(value);
}
fpi_error tos_teletext_toggle_reveal(  ) {
    return sbinder_teletext_client::Instance()->tos_teletext_toggle_reveal();
}
fpi_error tos_teletext_set_reveal_mode( fpi_bool revalMode ) {
    return sbinder_teletext_client::Instance()->tos_teletext_set_reveal_mode(revalMode);
}
fpi_error tos_teletext_toggle_subpage_cycle_model(  ) {
    return sbinder_teletext_client::Instance()->tos_teletext_toggle_subpage_cycle_model();
}
fpi_error tos_teletext_set_subpage_cycle_mode( fpi_bool subpageMode ) {
    return sbinder_teletext_client::Instance()->tos_teletext_set_subpage_cycle_mode(subpageMode);
}
fpi_error tos_teletext_set_language_group( uint8_t groupId ) {
    return sbinder_teletext_client::Instance()->tos_teletext_set_language_group(groupId);
}
fpi_error tos_teletext_get_language_group( uint8_t* groupId ) {
    return sbinder_teletext_client::Instance()->tos_teletext_get_language_group(groupId);
}
fpi_error tos_teletext_set_digital_language( MEMBER_LANGUAGE language ) {
    return sbinder_teletext_client::Instance()->tos_teletext_set_digital_language(language);
}
fpi_error tos_teletext_get_digital_language( MEMBER_LANGUAGE* language ) {
    return sbinder_teletext_client::Instance()->tos_teletext_get_digital_language(language);
}
fpi_error tos_teletext_handle_key( int keyCode ) {
    return sbinder_teletext_client::Instance()->tos_teletext_handle_key(keyCode);
}
fpi_error tos_teletext_open_newsflash(  ) {
    return sbinder_teletext_client::Instance()->tos_teletext_open_newsflash();
}
fpi_error tos_teletext_open_alarmpage( uint16_t t_time ) {
    return sbinder_teletext_client::Instance()->tos_teletext_open_alarmpage(t_time);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
