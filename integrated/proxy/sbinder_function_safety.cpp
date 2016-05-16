/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_function_safety.sidl
 */
 

#define LOG_TAG     "sbinder_function_safety"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_function_safety.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_SAFETY);


#define SERVICE_DESCRIPTOR                      "c4367c3a-a1da-11e4-a420-005056a84a3b"
#define SERVICE_NAME                            "sbinder_function_safety"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_safety_get_password FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_safety_set_password FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_safety_check_password FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_safety_get_parental_rating FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_safety_set_parental_rating FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_safety_set_lock FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_safety_get_lock FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_safety_set_source_lock FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_safety_get_source_lock FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_safety_set_time_interval_lock FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_safety_get_time_interval_lock FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_safety_clean_all_lock FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_safety_get_content_lock_level FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_safety_set_content_lock_level FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_safety_set_vchip_rating FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_safety_get_vchip_rating FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_safety_get_vchip_open_available FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_safety_get_vchip_open_region_num FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_safety_get_vchip_open_region_info FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_safety_get_vchip_open_dimension_info FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_safety_get_vchip_open_level_info FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_safety_get_vchip_block_data FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_safety_set_vchip_block_data FIRST_CALL_TRANSACTION + 23

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_function_safety.h"

class sbinder_function_safety_service : public BBinder  
{  
private:
    static sbinder_function_safety_service* _instance;

    sbinder_function_safety_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_function_safety_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_function_safety_service();
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

            case TRANSACTION_tos_safety_get_password:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_password here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_LOCK_TYPE type = (EN_LOCK_TYPE)data.readInt32();  //EN_LOCK_TYPE as input paramter

                int _pass_len = data.readInt32(); //read length, only 32bits length support yet
                char* pass = NULL;
                if(_pass_len > 0) {
                    reply->writeInt32(_pass_len);
                    Parcel::WritableBlob _pass_wblob;
                    reply->writeBlob(_pass_len,&_pass_wblob);
                    pass = (char*)_pass_wblob.data();
                }

                int16_t size = (int16_t)data.readInt32();  //int16_t as input paramter

                fpi_error _result = tos_safety_get_password( type, pass, size );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_password here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_password:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_password here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_LOCK_TYPE type = (EN_LOCK_TYPE)data.readInt32();  //EN_LOCK_TYPE as input paramter

                int _pass_len = data.readInt32(); //read length, only 32bits length support yet
                const char* pass = NULL;
                if(_pass_len > 0) {
                    Parcel::ReadableBlob _pass_rblob;
                    data.readBlob(_pass_len,&_pass_rblob);
                    pass = (const char*)_pass_rblob.data();
                }

                fpi_error _result = tos_safety_set_password( type, pass );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_password here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_check_password:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_check_password here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_LOCK_TYPE type = (EN_LOCK_TYPE)data.readInt32();  //EN_LOCK_TYPE as input paramter

                int _pass_len = data.readInt32(); //read length, only 32bits length support yet
                const char* pass = NULL;
                if(_pass_len > 0) {
                    Parcel::ReadableBlob _pass_rblob;
                    data.readBlob(_pass_len,&_pass_rblob);
                    pass = (const char*)_pass_rblob.data();
                }

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_safety_check_password( type, pass, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_check_password here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_parental_rating:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_parental_rating here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                fpi_error _result = tos_safety_get_parental_rating( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_parental_rating here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_parental_rating:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_parental_rating here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t rating = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_safety_set_parental_rating( rating, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_parental_rating here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_safety_get_content_lock_level:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_content_lock_level here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                fpi_error _result = tos_safety_get_content_lock_level( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_content_lock_level here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_content_lock_level:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_content_lock_level here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t ContentLevel = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_safety_set_content_lock_level( ContentLevel, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_content_lock_level here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			
            case TRANSACTION_tos_safety_set_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_LOCK_TYPE type = (EN_LOCK_TYPE)data.readInt32();  //EN_LOCK_TYPE as input paramter

                int16_t state = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_safety_set_lock( type, state, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_LOCK_TYPE type = (EN_LOCK_TYPE)data.readInt32();  //EN_LOCK_TYPE as input paramter

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* state = NULL;
				int16_t tmpValue = 0;
                if(_state_len > 0) {
					state = &tmpValue;
                }
				fpi_error _result;
				if( state != NULL ){
                _result = tos_safety_get_lock( type, state);
					}else
					{
					_result = FPI_ERROR_FAIL ;
						}

                reply->writeInt32(_result); //fpi_error as return value
				reply->writeInt32(tmpValue); 

                //-- end code for tos_safety_get_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_source_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_source_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                int16_t state = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_safety_set_source_lock( input, state, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_source_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_source_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_source_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT input = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* resultState = NULL;
				int16_t tmpState = 0;
                if(_state_len > 0) {
					resultState = &tmpState;
                }

                fpi_error _result = tos_safety_get_source_lock( input, resultState);

                reply->writeInt32(_result); //fpi_error as return value
				reply->writeInt32(tmpState);

                //-- end code for tos_safety_get_source_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_time_interval_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_time_interval_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
      //      #error not support this type of paramter st_fpi_time_interval_lock_setting time_interval_lock yet, please add code yourself

				int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                st_tos_time_interval_lock_setting time_interval_lock ;
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(st_tos_time_interval_lock_setting) )
					{
						memcpy(&time_interval_lock,_pin_rblob.data(), _pin_len );
					}
					else
					{
					// TO DO ERROR 
						}
               //     time_interval_lock = (st_fpi_time_interval_lock_setting*)_pin_rblob.data();
                }
				
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_safety_set_time_interval_lock( time_interval_lock, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_time_interval_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_time_interval_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_time_interval_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
          //  #error not support this type of paramter st_fpi_time_interval_lock_setting time_interval_lock yet, please add code yourself
				int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                st_tos_time_interval_lock_setting* time_interval_lock = NULL;
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    Parcel::WritableBlob _pout_wblob;
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    time_interval_lock = (st_tos_time_interval_lock_setting*)_pout_wblob.data();
                }
				fpi_error _result ;
				if( time_interval_lock != NULL){
                _result = tos_safety_get_time_interval_lock( time_interval_lock );
					}else{
					_result = FPI_ERROR_FAIL;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_time_interval_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_clean_all_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_clean_all_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_safety_clean_all_lock(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_clean_all_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_safety_set_vchip_rating:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_vchip_rating here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                tos_safety_vchip_rating_type_t vchip_rating_type = (tos_safety_vchip_rating_type_t)data.readInt32();  //tos_safety_vchip_rating_type_t as input paramter

                uint32_t value = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_safety_set_vchip_rating( vchip_rating_type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_vchip_rating here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_rating:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_rating here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                tos_safety_vchip_rating_type_t vchip_rating_type = (tos_safety_vchip_rating_type_t)data.readInt32();  //tos_safety_vchip_rating_type_t as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint32_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (uint32_t*)_value_wblob.data();
                fpi_error _result = tos_safety_get_vchip_rating( vchip_rating_type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_rating here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_open_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_open_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _is_available_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* is_available = NULL;

                Parcel::WritableBlob _is_available_wblob;

                if(_is_available_len > 0) {
                    reply->writeInt32(_is_available_len);
                    reply->writeBlob(_is_available_len,&_is_available_wblob);
                    is_available = (fpi_bool*)_is_available_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                is_available = (fpi_bool*)_is_available_wblob.data();
                fpi_error _result = tos_safety_get_vchip_open_available( is_available );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_open_available here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_open_region_num:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_open_region_num here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ret_region_number_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* ret_region_number = NULL;

                Parcel::WritableBlob _ret_region_number_wblob;

                if(_ret_region_number_len > 0) {
                    reply->writeInt32(_ret_region_number_len);
                    reply->writeBlob(_ret_region_number_len,&_ret_region_number_wblob);
                    ret_region_number = (uint32_t*)_ret_region_number_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ret_region_number = (uint32_t*)_ret_region_number_wblob.data();
                fpi_error _result = tos_safety_get_vchip_open_region_num( ret_region_number );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_open_region_num here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_open_region_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_open_region_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t region_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _ret_region_info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_safety_vchip_region_info_t* ret_region_info = NULL;

                Parcel::WritableBlob _ret_region_info_wblob;

                if(_ret_region_info_len > 0) {
                    reply->writeInt32(_ret_region_info_len);
                    reply->writeBlob(_ret_region_info_len,&_ret_region_info_wblob);
                    ret_region_info = (tos_safety_vchip_region_info_t*)_ret_region_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ret_region_info = (tos_safety_vchip_region_info_t*)_ret_region_info_wblob.data();
                fpi_error _result = tos_safety_get_vchip_open_region_info( region_index, ret_region_info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_open_region_info here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_open_dimension_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_open_dimension_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t region_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t dimension_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _ret_dim_info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_safety_vchip_dimension_info_t* ret_dim_info = NULL;

                Parcel::WritableBlob _ret_dim_info_wblob;

                if(_ret_dim_info_len > 0) {
                    reply->writeInt32(_ret_dim_info_len);
                    reply->writeBlob(_ret_dim_info_len,&_ret_dim_info_wblob);
                    ret_dim_info = (tos_safety_vchip_dimension_info_t*)_ret_dim_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ret_dim_info = (tos_safety_vchip_dimension_info_t*)_ret_dim_info_wblob.data();
                fpi_error _result = tos_safety_get_vchip_open_dimension_info( region_index, dimension_index, ret_dim_info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_open_dimension_info here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_open_level_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_open_level_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t region_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t dimension_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t level_index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _ret_level_info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_safety_vchip_level_info_t* ret_level_info = NULL;

                Parcel::WritableBlob _ret_level_info_wblob;

                if(_ret_level_info_len > 0) {
                    reply->writeInt32(_ret_level_info_len);
                    reply->writeBlob(_ret_level_info_len,&_ret_level_info_wblob);
                    ret_level_info = (tos_safety_vchip_level_info_t*)_ret_level_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ret_level_info = (tos_safety_vchip_level_info_t*)_ret_level_info_wblob.data();
                fpi_error _result = tos_safety_get_vchip_open_level_info( region_index, dimension_index, level_index, ret_level_info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_open_level_info here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_get_vchip_block_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_get_vchip_block_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ret_block_data_len = data.readInt32(); //read length, only 32bits length support yet
                tos_safety_vchip_block_data_t* ret_block_data = NULL;

                Parcel::WritableBlob _ret_block_data_wblob;

                if(_ret_block_data_len > 0) {
                    reply->writeInt32(_ret_block_data_len);
                    reply->writeBlob(_ret_block_data_len,&_ret_block_data_wblob);
                    ret_block_data = (tos_safety_vchip_block_data_t*)_ret_block_data_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ret_block_data = (tos_safety_vchip_block_data_t*)_ret_block_data_wblob.data();
                fpi_error _result = tos_safety_get_vchip_block_data( ret_block_data );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_get_vchip_block_data here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_safety_set_vchip_block_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_safety_set_vchip_block_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _block_data_len = data.readInt32(); //read length, only 32bits length support yet
                tos_safety_vchip_block_data_t* block_data = NULL;

                Parcel::WritableBlob _block_data_wblob;

                if(_block_data_len > 0) {
                    reply->writeInt32(_block_data_len);
                    reply->writeBlob(_block_data_len,&_block_data_wblob);
                    block_data = (tos_safety_vchip_block_data_t*)_block_data_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                block_data = (tos_safety_vchip_block_data_t*)_block_data_wblob.data();
                fpi_error _result = tos_safety_set_vchip_block_data( block_data );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_safety_set_vchip_block_data here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_function_safety_service_add() {
    sbinder_function_safety_service::Instance();
    return 0;
}

sbinder_function_safety_service* sbinder_function_safety_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_function_safety_client  
{  
private:
    static sbinder_function_safety_client* _instance;
    sp<IBinder> _binder;

    sbinder_function_safety_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_function_safety_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_function_safety_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_function_safety_client();
        }

        return _instance;
    }

    fpi_error tos_safety_get_password( EN_LOCK_TYPE type, char* pass, int16_t size ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_password here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_LOCK_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pass == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)size * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(size);  //int16_t as input paramter

            _binder->transact(TRANSACTION_tos_safety_get_password,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pass != NULL) {
                    int _pass_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pass_rblob;
                    reply.readBlob(_pass_len,&_pass_rblob);
                    memcpy(pass,_pass_rblob.data(),_pass_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_password error");
        }

        return _result;
        /*-- add you code for tos_safety_get_password here --*/
    }

    fpi_error tos_safety_set_password( EN_LOCK_TYPE type, const char* pass ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_password here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_LOCK_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pass == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(4) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pass_wblob;
                data.writeBlob((4) * sizeof(char),&_pass_wblob);
                memcpy(_pass_wblob.data(),pass,(4)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_safety_set_password,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_password error");
        }

        return _result;
        /*-- add you code for tos_safety_set_password here --*/
    }

    fpi_error tos_safety_check_password( EN_LOCK_TYPE type, const char* pass, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_check_password here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_LOCK_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pass == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(pass)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pass_wblob;
                data.writeBlob((strlen(pass)+1) * sizeof(char),&_pass_wblob);
                memcpy(_pass_wblob.data(),pass,(strlen(pass)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_check_password,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_check_password error");
        }

        return _result;
        /*-- add you code for tos_safety_check_password here --*/
    }

    fpi_error tos_safety_get_parental_rating( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_parental_rating here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_parental_rating,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_parental_rating error");
        }

        return _result;
        /*-- add you code for tos_safety_get_parental_rating here --*/
    }

    fpi_error tos_safety_set_parental_rating( int32_t rating, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_parental_rating here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(rating);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_parental_rating,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_parental_rating error");
        }

        return _result;
        /*-- add you code for tos_safety_set_parental_rating here --*/
    }
    fpi_error tos_safety_get_content_lock_level( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_content_lock_level here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_content_lock_level,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_content_lock_level error");
        }

        return _result;
        /*-- add you code for tos_safety_get_content_lock_level here --*/
    }

    fpi_error tos_safety_set_content_lock_level( int32_t ContentLevel, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_content_lock_level here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ContentLevel);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_content_lock_level,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_content_lock_level error");
        }

        return _result;
        /*-- add you code for tos_safety_set_content_lock_level here --*/
    }

    fpi_error tos_safety_set_lock( EN_LOCK_TYPE type, int16_t state, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_LOCK_TYPE as input paramter

            data.writeInt32(state);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_set_lock here --*/
    }

    fpi_error tos_safety_get_lock( EN_LOCK_TYPE type, int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_LOCK_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_safety_get_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value
                if (_result == FPI_ERROR_SUCCESS)
            	{
	                if (state != NULL) {
	                    *state = reply.readInt32();
	                }
            	}

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_get_lock here --*/
    }

    fpi_error tos_safety_set_source_lock( EN_API_SOURCE_INPUT input, int16_t state, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_source_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            data.writeInt32(state);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_source_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_source_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_set_source_lock here --*/
    }

    fpi_error tos_safety_get_source_lock( EN_API_SOURCE_INPUT input, int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_source_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(input);  //EN_API_SOURCE_INPUT as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_source_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value
				if (_result == FPI_ERROR_SUCCESS)
            	{
	                if (state != NULL) {
	                    *state = reply.readInt32();
	                }
            	}
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_source_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_get_source_lock here --*/
    }

    fpi_error tos_safety_set_time_interval_lock( st_tos_time_interval_lock_setting time_interval_lock, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_time_interval_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

        //    #error not support this type of paramter st_fpi_time_interval_lock_setting time_interval_lock yet, please add code yourself
                data.writeInt32((int)(1) * sizeof(st_tos_time_interval_lock_setting));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pin_wblob;
                data.writeBlob((1) * sizeof(st_tos_time_interval_lock_setting),&_pin_wblob);
                memcpy(_pin_wblob.data(),&time_interval_lock,(1)* sizeof(st_tos_time_interval_lock_setting));


            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_time_interval_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_time_interval_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_set_time_interval_lock here --*/
    }

    fpi_error tos_safety_get_time_interval_lock( st_tos_time_interval_lock_setting* time_interval_lock ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_time_interval_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

       //     #error not support this type of paramter st_fpi_time_interval_lock_setting time_interval_lock yet, please add code yourself
			data.writeInt32((int)(1) * sizeof(st_tos_time_interval_lock_setting));

            _binder->transact(TRANSACTION_tos_safety_get_time_interval_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

            //    #error not support this type of output paramter st_fpi_time_interval_lock_setting time_interval_lock yet, please add code yourself
				 if (time_interval_lock != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(time_interval_lock,_pout_rblob.data(),_pout_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_time_interval_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_get_time_interval_lock here --*/
    }

    fpi_error tos_safety_clean_all_lock(  ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_clean_all_lock here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_safety_clean_all_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_clean_all_lock error");
        }

        return _result;
        /*-- add you code for tos_safety_clean_all_lock here --*/
    }


   fpi_error tos_safety_set_vchip_rating( tos_safety_vchip_rating_type_t vchip_rating_type, uint32_t value ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_vchip_rating here --*/
       fpi_error _result = FPI_ERROR_FAIL;
		
        if(_binder == NULL) {
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(vchip_rating_type);  //tos_safety_vchip_rating_type_t as input paramter

            data.writeInt32(value);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_safety_set_vchip_rating,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_set_vchip_rating error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_vchip_rating error");
        }

        return _result;
        /*-- add you code for tos_safety_set_vchip_rating here --*/
    }

    fpi_error tos_safety_get_vchip_rating( tos_safety_vchip_rating_type_t vchip_rating_type, uint32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_rating here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(vchip_rating_type);  //tos_safety_vchip_rating_type_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_rating,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_rating error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_rating error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_rating here --*/
    }

    fpi_error tos_safety_get_vchip_open_available( fpi_bool* is_available ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_open_available here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (is_available == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_open_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (is_available != NULL) {
                    int _is_available_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _is_available_rblob;
                    reply.readBlob(_is_available_len,&_is_available_rblob);
                    memcpy(is_available,_is_available_rblob.data(),_is_available_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_available error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_open_available here --*/
    }

    fpi_error tos_safety_get_vchip_open_region_num( uint32_t* ret_region_number ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_open_region_num here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ret_region_number == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_open_region_num,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ret_region_number != NULL) {
                    int _ret_region_number_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ret_region_number_rblob;
                    reply.readBlob(_ret_region_number_len,&_ret_region_number_rblob);
                    memcpy(ret_region_number,_ret_region_number_rblob.data(),_ret_region_number_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_region_num error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_region_num error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_open_region_num here --*/
    }

    fpi_error tos_safety_get_vchip_open_region_info( uint32_t region_index, tos_safety_vchip_region_info_t* ret_region_info ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_open_region_info here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(region_index);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ret_region_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_safety_vchip_region_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_open_region_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ret_region_info != NULL) {
                    int _ret_region_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ret_region_info_rblob;
                    reply.readBlob(_ret_region_info_len,&_ret_region_info_rblob);
                    memcpy(ret_region_info,_ret_region_info_rblob.data(),_ret_region_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_region_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_region_info error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_open_region_info here --*/
    }

    fpi_error tos_safety_get_vchip_open_dimension_info( uint32_t region_index, uint32_t dimension_index, tos_safety_vchip_dimension_info_t* ret_dim_info ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_open_dimension_info here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(region_index);  //uint32_t as input paramter

            data.writeInt32(dimension_index);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ret_dim_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_safety_vchip_dimension_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_open_dimension_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ret_dim_info != NULL) {
                    int _ret_dim_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ret_dim_info_rblob;
                    reply.readBlob(_ret_dim_info_len,&_ret_dim_info_rblob);
                    memcpy(ret_dim_info,_ret_dim_info_rblob.data(),_ret_dim_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_dimension_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_dimension_info error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_open_dimension_info here --*/
    }

    fpi_error tos_safety_get_vchip_open_level_info( uint32_t region_index, uint32_t dimension_index, uint32_t level_index, tos_safety_vchip_level_info_t* ret_level_info ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_open_level_info here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(region_index);  //uint32_t as input paramter

            data.writeInt32(dimension_index);  //uint32_t as input paramter

            data.writeInt32(level_index);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ret_level_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_safety_vchip_level_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_open_level_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ret_level_info != NULL) {
                    int _ret_level_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ret_level_info_rblob;
                    reply.readBlob(_ret_level_info_len,&_ret_level_info_rblob);
                    memcpy(ret_level_info,_ret_level_info_rblob.data(),_ret_level_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_level_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_open_level_info error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_open_level_info here --*/
    }

    fpi_error tos_safety_get_vchip_block_data( tos_safety_vchip_block_data_t* ret_block_data ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_get_vchip_block_data here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ret_block_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_safety_vchip_block_data_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_get_vchip_block_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ret_block_data != NULL) {
                    int _ret_block_data_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ret_block_data_rblob;
                    reply.readBlob(_ret_block_data_len,&_ret_block_data_rblob);
                    memcpy(ret_block_data,_ret_block_data_rblob.data(),_ret_block_data_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_block_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_get_vchip_block_data error");
        }

        return _result;
        /*-- add you code for tos_safety_get_vchip_block_data here --*/
    }

    fpi_error tos_safety_set_vchip_block_data( tos_safety_vchip_block_data_t* block_data ) {
        Parcel data, reply;

        /*-- add you code for tos_safety_set_vchip_block_data here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (block_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_safety_vchip_block_data_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_safety_set_vchip_block_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (block_data != NULL) {
                    int _block_data_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _block_data_rblob;
                    reply.readBlob(_block_data_len,&_block_data_rblob);
                    memcpy(block_data,_block_data_rblob.data(),_block_data_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_safety_set_vchip_block_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_safety_set_vchip_block_data error");
        }

        return _result;
        /*-- add you code for tos_safety_set_vchip_block_data here --*/
    }
};

sbinder_function_safety_client* sbinder_function_safety_client::_instance = NULL;

fpi_error tos_safety_get_password( EN_LOCK_TYPE type, char* pass, int16_t size ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_password(type, pass, size);
}
fpi_error tos_safety_set_password( EN_LOCK_TYPE type, const char* pass ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_password(type, pass);
}
fpi_error tos_safety_check_password( EN_LOCK_TYPE type, const char* pass, int16_t* value ) {
    return sbinder_function_safety_client::Instance()->tos_safety_check_password(type, pass, value);
}
fpi_error tos_safety_get_parental_rating( int32_t* value ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_parental_rating(value);
}
fpi_error tos_safety_set_parental_rating( int32_t rating, EN_ACT_CTRL act ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_parental_rating(rating, act);
}
fpi_error tos_safety_set_lock( EN_LOCK_TYPE type, int16_t state, EN_ACT_CTRL act ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_lock(type, state, act);
}
fpi_error tos_safety_get_lock( EN_LOCK_TYPE type, int16_t* state ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_lock(type, state);
}
fpi_error tos_safety_set_source_lock( EN_API_SOURCE_INPUT input, int16_t state, EN_ACT_CTRL act ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_source_lock(input, state, act);
}
fpi_error tos_safety_get_source_lock( EN_API_SOURCE_INPUT input, int16_t* state ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_source_lock(input, state);
}
fpi_error tos_safety_set_time_interval_lock( st_tos_time_interval_lock_setting time_interval_lock, EN_ACT_CTRL act ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_time_interval_lock(time_interval_lock, act);
}
fpi_error tos_safety_get_time_interval_lock( st_tos_time_interval_lock_setting* time_interval_lock ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_time_interval_lock(time_interval_lock);
}
fpi_error tos_safety_clean_all_lock(  ) {
    return sbinder_function_safety_client::Instance()->tos_safety_clean_all_lock();
}
fpi_error tos_safety_get_content_lock_level( int32_t* value ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_content_lock_level(value);
}
fpi_error tos_safety_set_content_lock_level( int32_t ContentLevel, EN_ACT_CTRL act ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_content_lock_level(ContentLevel, act);
}
fpi_error tos_safety_set_vchip_rating( tos_safety_vchip_rating_type_t vchip_rating_type, uint32_t value ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_vchip_rating(vchip_rating_type, value);
}
fpi_error tos_safety_get_vchip_rating( tos_safety_vchip_rating_type_t vchip_rating_type, uint32_t* value ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_rating(vchip_rating_type, value);
}
fpi_error tos_safety_get_vchip_open_available( fpi_bool* is_available ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_open_available(is_available);
}
fpi_error tos_safety_get_vchip_open_region_num( uint32_t* ret_region_number ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_open_region_num(ret_region_number);
}
fpi_error tos_safety_get_vchip_open_region_info( uint32_t region_index, tos_safety_vchip_region_info_t* ret_region_info ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_open_region_info(region_index, ret_region_info);
}
fpi_error tos_safety_get_vchip_open_dimension_info( uint32_t region_index, uint32_t dimension_index, tos_safety_vchip_dimension_info_t* ret_dim_info ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_open_dimension_info(region_index, dimension_index, ret_dim_info);
}
fpi_error tos_safety_get_vchip_open_level_info( uint32_t region_index, uint32_t dimension_index, uint32_t level_index, tos_safety_vchip_level_info_t* ret_level_info ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_open_level_info(region_index, dimension_index, level_index, ret_level_info);
}
fpi_error tos_safety_get_vchip_block_data( tos_safety_vchip_block_data_t* ret_block_data ) {
    return sbinder_function_safety_client::Instance()->tos_safety_get_vchip_block_data(ret_block_data);
}
fpi_error tos_safety_set_vchip_block_data( tos_safety_vchip_block_data_t* block_data ) {
    return sbinder_function_safety_client::Instance()->tos_safety_set_vchip_block_data(block_data);
}
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
