/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_function_setting.sidl
 */
 

#define LOG_TAG     "sbinder_function_setting"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_function_setting.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_SETTING);


#define SERVICE_DESCRIPTOR                      "93331b28-d6bb-11e4-b83b-005056a84a3b"
#define SERVICE_NAME                            "sbinder_function_setting"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_setting_get_menu_language FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_setting_set_menu_language FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_setting_get_time_zone FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_setting_set_time_zone FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_setting_get_region FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_setting_set_region FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_setting_get_time_sync FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_setting_set_time_sync FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_setting_get_time FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_setting_set_time FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_setting_updating FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_setting_get_update_info FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_setting_set_update_info FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_setting_updating_is_running FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_setting_reset_default FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_setting_get_download_file_size FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_setting_get_ui_content FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_setting_set_ui_content FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_setting_get_location FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_setting_set_location FIRST_CALL_TRANSACTION + 20

#define TRANSACTION_tos_setting_get_current_base_time  FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_setting_get_current_base_time_without_offset FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_setting_get_clock_offset FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_setting_utility_second_to_time FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_setting_get_time_dst_state FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_setting_set_time_dst_state FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_setting_set_special_mode_enable FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_setting_get_special_mode_enable FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_setting_set_net_wakeup_mode FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_setting_get_net_wakeup_mode FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_setting_get_state FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_function_set_user_defined_logo FIRST_CALL_TRANSACTION +32
#define TRANSACTION_tos_setting_time_blocktag FIRST_CALL_TRANSACTION + 33


using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_function_setting.h"

class sbinder_function_setting_service : public BBinder  
{  
private:
    static sbinder_function_setting_service* _instance;

    sbinder_function_setting_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_function_setting_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_function_setting_service();
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

            case TRANSACTION_tos_setting_get_menu_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_menu_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                MEMBER_LANGUAGE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (MEMBER_LANGUAGE*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_menu_language( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_menu_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_menu_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_menu_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                MEMBER_LANGUAGE language = (MEMBER_LANGUAGE)data.readInt32();  //MEMBER_LANGUAGE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_menu_language( language, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_menu_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_time_zone:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_time_zone here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_TIME_ZONE* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_TIME_ZONE*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_time_zone( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_time_zone here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_time_zone:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_time_zone here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_TIME_ZONE timezone = (EN_FPI_TIME_ZONE)data.readInt32();  //EN_FPI_TIME_ZONE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_time_zone( timezone, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_time_zone here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_region:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_region here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_REGION_TYPE region = (EN_REGION_TYPE)data.readInt32();  //EN_REGION_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_region( region, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_region here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_region:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_region here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_REGION_TYPE region_country = (EN_REGION_TYPE)data.readInt32();  //EN_REGION_TYPE as input paramter

                int32_t region = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_region( region_country, region, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_region here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_time_sync:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_time_sync here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_time_sync( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_time_sync here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_time_sync:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_time_sync here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t autosync = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_time_sync( autosync, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_time_sync here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_time here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_SETTING_TIME_CTRL type = (EN_SETTING_TIME_CTRL)data.readInt32();  //EN_SETTING_TIME_CTRL as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_date* value = NULL;
				Parcel::WritableBlob _value_wblob;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (st_fpi_date*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_time( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_time here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_time here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_SETTING_TIME_CTRL type = (EN_SETTING_TIME_CTRL)data.readInt32();  //EN_SETTING_TIME_CTRL as input paramter

                int _pst_date_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_date* pst_date = NULL;
				Parcel::ReadableBlob _pst_date_rblob;
				
                if(_pst_date_len > 0) {
                    data.readBlob(_pst_date_len,&_pst_date_rblob);
                    pst_date = (st_fpi_date*)_pst_date_rblob.data();
                }

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

				fpi_error _result ;
				if( pst_date != NULL ){
                _result = tos_setting_set_time( type, pst_date, act );
					}else{
					_result = FPI_ERROR_FAIL ;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_time here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_updating:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_updating here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SOFTWARE_UPDATE updateMode = (EN_FPI_SOFTWARE_UPDATE)data.readInt32();  //EN_FPI_SOFTWARE_UPDATE as input paramter

                EN_UPDATE_ACTION_CTRL action = (EN_UPDATE_ACTION_CTRL)data.readInt32();  //EN_UPDATE_ACTION_CTRL as input paramter

                fpi_error _result = tos_setting_updating( updateMode, action );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_updating here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_update_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_update_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SOFTWARE_UPDATE updateMode = (EN_FPI_SOFTWARE_UPDATE)data.readInt32();  //EN_FPI_SOFTWARE_UPDATE as input paramter

                int _pInfo_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_net_update_info* pInfo = NULL;
                if(_pInfo_len > 0) {
                    reply->writeInt32(_pInfo_len);
                    Parcel::WritableBlob _pInfo_wblob;
                    reply->writeBlob(_pInfo_len,&_pInfo_wblob);
                    pInfo = (st_fpi_net_update_info*)_pInfo_wblob.data();
                }

                fpi_error _result = tos_setting_get_update_info( updateMode, pInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_update_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_update_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_update_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SOFTWARE_UPDATE updateMode = (EN_FPI_SOFTWARE_UPDATE)data.readInt32();  //EN_FPI_SOFTWARE_UPDATE as input paramter

                int _pInfo_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_net_update_info* pInfo = NULL;
                if(_pInfo_len > 0) {
                    Parcel::ReadableBlob _pInfo_rblob;
                    data.readBlob(_pInfo_len,&_pInfo_rblob);
                    pInfo = (st_fpi_net_update_info*)_pInfo_rblob.data();
                }

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_update_info( updateMode, pInfo, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_update_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_updating_is_running:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_updating_is_running here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SOFTWARE_UPDATE updateMode = (EN_FPI_SOFTWARE_UPDATE)data.readInt32();  //EN_FPI_SOFTWARE_UPDATE as input paramter

                int _running_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* running = NULL;
                if(_running_len > 0) {
                    reply->writeInt32(_running_len);
                    Parcel::WritableBlob _running_wblob;
                    reply->writeBlob(_running_len,&_running_wblob);
                    running = (int32_t*)_running_wblob.data();
                }

                fpi_error _result = tos_setting_updating_is_running( updateMode, running );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_updating_is_running here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_reset_default:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_reset_default here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_setting_reset_default(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_reset_default here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_download_file_size:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_download_file_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t _size_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* size = NULL;

                Parcel::WritableBlob _size_wblob;

                if(_size_len > 0) {
                    reply->writeInt32(_size_len);
                    reply->writeBlob(_size_len,&_size_wblob);
                    size = (int32_t*)_size_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                size = (int32_t*)_size_wblob.data();
                fpi_error _result = tos_setting_get_download_file_size( size );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_setting_get_download_file_size here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_ui_content:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_ui_content here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_UI_CONTENT e_content = (EN_UI_CONTENT)data.readInt32();  //int as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t * value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int32_t*)_value_wblob.data();
                fpi_error _result = tos_setting_get_ui_content( e_content, value );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_setting_get_ui_content here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_ui_content:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_ui_content here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_UI_CONTENT e_content = (EN_UI_CONTENT)data.readInt32();  //int as input paramter

                int32_t value = (int32_t)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_setting_set_ui_content( e_content, value );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_setting_set_ui_content here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_get_location:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_get_location here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_LOCATION* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_LOCATION*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_location( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_get_location here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_setting_set_location:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_location here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_LOCATION location = (EN_FPI_LOCATION)data.readInt32();  //EN_FPI_LOCATION as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_setting_set_location( location, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_setting_set_location here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_setting_get_current_base_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_get_current_base_time( value );
                reply->writeInt32(_result); //fpi_error as return value
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_setting_get_current_base_time_without_offset:
            {
		data.enforceInterface(String16(SERVICE_NAME));	//fixed check
		
		   //skip Exception and result first to write output paramters
		   reply->writeNoException();
		   //skip Exception and result first end
		
		   //begin paramters list
		   int _value_len = data.readInt32(); //read length, only 32bits length support yet
		   int32_t* value = NULL;
		   Parcel::WritableBlob _value_wblob;
		   
		   if(_value_len > 0) {
			   reply->writeInt32(_value_len);
			   reply->writeBlob(_value_len,&_value_wblob);
			   value = (int32_t*)_value_wblob.data();
		   }
		
		   fpi_error _result = tos_setting_get_current_base_time_without_offset( value );
		   reply->writeInt32(_result); //fpi_error as return value
		   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;

            } break;
            case TRANSACTION_tos_setting_get_clock_offset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
		int _value_len = data.readInt32(); //read length, only 32bits length support yet
		int32_t* value = NULL;
		Parcel::WritableBlob _value_wblob;
		
		if(_value_len > 0) {
			reply->writeInt32(_value_len);
			reply->writeBlob(_value_len,&_value_wblob);
			value = (int32_t*)_value_wblob.data();
		}
		
		fpi_error _result = tos_setting_get_clock_offset( value );
		reply->writeInt32(_result); //fpi_error as return value
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_setting_utility_second_to_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                int32_t seconds = (int32_t)data.readInt32();  //EN_REGION_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_date* value = NULL;
				Parcel::WritableBlob _value_wblob;
				
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (st_fpi_date*)_value_wblob.data();
                }

                fpi_error _result = tos_setting_utility_second_to_time(seconds, value );
                reply->writeInt32(_result); //fpi_error as return value

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_setting_set_time_dst_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                //begin paramters list
                fpi_bool bEnable = (fpi_bool)data.readInt32();  //EN_FPI_LOCATION as input paramter
                fpi_error _result = tos_setting_set_time_dst_state(bEnable);

                reply->writeInt32(_result); //fpi_error as return value
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_setting_get_time_dst_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
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
                fpi_error _result ;
                if( value!= NULL ){
                _result = tos_setting_get_time_dst_state( value );
                	}else{
                	_result = FPI_ERROR_FAIL ;
                		}

                reply->writeInt32(_result); //fpi_error as return value
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			case TRANSACTION_tos_setting_set_special_mode_enable:            
            {                
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check               
                //-- begin code for tos_setting_set_special_mode_enable here, will auoto generated but may change yourself if need -- 
                //skip Exception and result first to write output paramters               
                reply->writeNoException();                
                //skip Exception and result first end                
                //begin paramters list                
                EN_TOS_SPECIAL_MODE e_param = (EN_TOS_SPECIAL_MODE)data.readInt32();  
                //EN_TOS_SPECIAL_MODE as input paramter                
                int32_t value = (int32_t)data.readInt32(); 
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter
                //fpi_bool as input paramter               
                // re-get all pointers from blob to fix realloc issue in Parcel      
                fpi_error _result = tos_setting_set_special_mode_enable( e_param, value, act);     
                reply->writeInt32(_result); //fpi_error as return value            
                //-- end code for tos_setting_set_special_mode_enable here --        
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            
             } break;                        
            case TRANSACTION_tos_setting_get_special_mode_enable:           
            {               
                data.enforceInterface(String16(SERVICE_NAME));  
                //fixed check               
                //-- begin code for tos_setting_get_special_mode_enable here, will auoto generated but may change yourself if need -- 
                //skip Exception and result first to write output paramters          
                reply->writeNoException();               
                //skip Exception and result first end              
                //begin paramters list               
                EN_TOS_SPECIAL_MODE e_param = (EN_TOS_SPECIAL_MODE)data.readInt32(); 
                //EN_TOS_SPECIAL_MODE as input paramter 
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t *value = NULL;
                Parcel::WritableBlob _value_wblob;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t *)_value_wblob.data();
                }   
                // re-get all pointers from blob to fix realloc issue in Parcel             
                fpi_error _result = tos_setting_get_special_mode_enable( e_param, value);        
                reply->writeInt32(_result); //fpi_error as return value            
                //-- end code for tos_setting_get_special_mode_enable here --         
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            
              } break;
			case TRANSACTION_tos_setting_set_net_wakeup_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_setting_set_net_wakeup_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode = (EN_FUNC_NET_WAKEUP_MODE)data.readInt32();

                uint8_t mode = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_setting_set_net_wakeup_mode( e_wakeup_mode, mode );

                reply->writeInt32(_result);

                //-- end code for tos_setting_set_net_wakeup_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            }         
            case TRANSACTION_tos_setting_get_net_wakeup_mode:           
            {               
                data.enforceInterface(String16(SERVICE_NAME));  
                //fixed check               
                //-- begin code for tos_setting_get_net_wakeup_mode here, will auoto generated but may change yourself if need -- 
                //skip Exception and result first to write output paramters          
                reply->writeNoException();               
                //skip Exception and result first end              
                //begin paramters list               
                EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode = (EN_FUNC_NET_WAKEUP_MODE)data.readInt32(); 
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t *mode = NULL;
                Parcel::WritableBlob _value_wblob;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    mode = (uint8_t *)_value_wblob.data();
                }   
                // re-get all pointers from blob to fix realloc issue in Parcel             
                fpi_error _result = tos_setting_get_net_wakeup_mode( e_wakeup_mode, mode);        
                reply->writeInt32(_result); //fpi_error as return value            
                //-- end code for tos_setting_get_net_wakeup_mode here --         
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            
              } break;
			 case TRANSACTION_tos_setting_get_state:
			 {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_aft_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end             
				EN_FUNC_STATE_TYPE eState = (EN_FUNC_STATE_TYPE)data.readInt32();
				
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* enable = NULL;
                Parcel::WritableBlob _enable_wblob;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (fpi_bool*)_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enable = (fpi_bool*)_enable_wblob.data();
                fpi_error _result = tos_setting_get_state(eState, enable);
				fpi_info(SERVICE_NAME"_service TRANSACTION_tos_setting_get_state *enable = %d \n", *enable);
                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_aft_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            }
			break;
            case TRANSACTION_tos_function_set_user_defined_logo:            
            {                
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check                
                //-- begin code for tos_function_set_user_defined_logo here, will auoto generated but may change yourself if need --  
                //skip Exception and result first to write output paramters               
                reply->writeNoException();              
                //skip Exception and result first end              
                //begin paramters list                
                int _logo_path_len = data.readInt32(); //read length, only 32bits length support yet           
                char* logo_path = NULL;                
                Parcel::ReadableBlob _logo_path_rblob;                
                if(_logo_path_len > 0) {                   
                    data.readBlob(_logo_path_len,&_logo_path_rblob);           
                    logo_path = (char*)_logo_path_rblob.data();              
                    }               
                // re-get all pointers from blob to fix realloc issue in Parcel          
                logo_path = (char*)_logo_path_rblob.data();            
                fpi_error _result = tos_function_set_user_defined_logo( logo_path );    
                reply->writeInt32(_result); //fpi_error as return value         
                //-- end code for tos_function_set_user_defined_logo here --       
                return NO_ERROR;            
             } break;
		  case TRANSACTION_tos_setting_time_blocktag:
		  {
			 data.enforceInterface(String16(SERVICE_NAME));  //fixed check
		 
			 //-- begin code for tos_atv_get_aft_enable here, will auoto generated but may change yourself if need --
		 
			 //skip Exception and result first to write output paramters
			 reply->writeNoException();
			 
			 fpi_bool bBlockToModifyTime = (fpi_bool)data.readInt32(); //read length, only 32bits length support yet

			 fpi_error _result = tos_setting_time_blocktag( bBlockToModifyTime );

			 reply->writeInt32(_result); //fpi_error as return value
		 
			 return NO_ERROR;
			 //-- end code for tos_atv_get_aft_enable here --
		 }break;	
          
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_function_setting_service_add() {
    sbinder_function_setting_service::Instance();
    return 0;
}

sbinder_function_setting_service* sbinder_function_setting_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_function_setting_client  
{  
private:
    static sbinder_function_setting_client* _instance;
    sp<IBinder> _binder;

    sbinder_function_setting_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_function_setting_client() {
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
    static sbinder_function_setting_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_function_setting_client();
        }

        return _instance;
    }

    fpi_error tos_setting_get_menu_language( MEMBER_LANGUAGE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_menu_language here --*/
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
                data.writeInt32((int)(1) * sizeof(MEMBER_LANGUAGE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_menu_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_menu_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_menu_language error");
        }

        return _result;
        /*-- add you code for tos_setting_get_menu_language here --*/
    }

    fpi_error tos_setting_set_menu_language( MEMBER_LANGUAGE language, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_menu_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(language);  //MEMBER_LANGUAGE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_menu_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_menu_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_menu_language error");
        }

        return _result;
        /*-- add you code for tos_setting_set_menu_language here --*/
    }

    fpi_error tos_setting_get_time_zone( EN_FPI_TIME_ZONE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_time_zone here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_TIME_ZONE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_time_zone,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_time_zone error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_time_zone error");
        }

        return _result;
        /*-- add you code for tos_setting_get_time_zone here --*/
    }

    fpi_error tos_setting_set_time_zone( EN_FPI_TIME_ZONE timezone, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_time_zone here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(timezone);  //EN_FPI_TIME_ZONE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_time_zone,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_time_zone error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_time_zone error");
        }

        return _result;
        /*-- add you code for tos_setting_set_time_zone here --*/
    }

    fpi_error tos_setting_get_region( EN_REGION_TYPE region, int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_region here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(region);  //EN_REGION_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_region,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_region error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_region error");
        }

        return _result;
        /*-- add you code for tos_setting_get_region here --*/
    }

    fpi_error tos_setting_set_region( EN_REGION_TYPE region_country, int32_t region, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_region here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(region_country);  //EN_REGION_TYPE as input paramter

            data.writeInt32(region);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_region,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_region error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_region error");
        }

        return _result;
        /*-- add you code for tos_setting_set_region here --*/
    }

    fpi_error tos_setting_get_time_sync( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_time_sync here --*/
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
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_time_sync,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_time_sync error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_time_sync error");
        }

        return _result;
        /*-- add you code for tos_setting_get_time_sync here --*/
    }

    fpi_error tos_setting_set_time_sync( int32_t autosync, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_time_sync here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(autosync);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_time_sync,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_time_sync error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_time_sync error");
        }

        return _result;
        /*-- add you code for tos_setting_set_time_sync here --*/
    }

    fpi_error tos_setting_get_time( EN_SETTING_TIME_CTRL type, st_fpi_date* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_time here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_SETTING_TIME_CTRL as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_fpi_date));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_time,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_time error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_time error");
        }

        return _result;
        /*-- add you code for tos_setting_get_time here --*/
    }

    fpi_error tos_setting_set_time( EN_SETTING_TIME_CTRL type, st_fpi_date* pst_date, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_time here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_SETTING_TIME_CTRL as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pst_date == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_fpi_date));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pst_date_wblob;
                data.writeBlob((1) * sizeof(st_fpi_date),&_pst_date_wblob);
                memcpy(_pst_date_wblob.data(),pst_date,(1)* sizeof(st_fpi_date));
            }

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_time,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_time error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_time error");
        }

        return _result;
        /*-- add you code for tos_setting_set_time here --*/
    }

    fpi_error tos_setting_updating( EN_FPI_SOFTWARE_UPDATE updateMode, EN_UPDATE_ACTION_CTRL action ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_updating here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(updateMode);  //EN_FPI_SOFTWARE_UPDATE as input paramter

            data.writeInt32(action);  //EN_UPDATE_ACTION_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_updating,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_updating error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_updating error");
        }

        return _result;
        /*-- add you code for tos_setting_updating here --*/
    }

    fpi_error tos_setting_get_update_info( EN_FPI_SOFTWARE_UPDATE updateMode, st_fpi_net_update_info* pInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_update_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(updateMode);  //EN_FPI_SOFTWARE_UPDATE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_fpi_net_update_info));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_update_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pInfo != NULL) {
                    int _pInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pInfo_rblob;
                    reply.readBlob(_pInfo_len,&_pInfo_rblob);
                    memcpy(pInfo,_pInfo_rblob.data(),_pInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_update_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_update_info error");
        }

        return _result;
        /*-- add you code for tos_setting_get_update_info here --*/
    }

    fpi_error tos_setting_set_update_info( EN_FPI_SOFTWARE_UPDATE updateMode, st_fpi_net_update_info* pInfo, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_update_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(updateMode);  //EN_FPI_SOFTWARE_UPDATE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_fpi_net_update_info));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pInfo_wblob;
                data.writeBlob((1) * sizeof(st_fpi_net_update_info),&_pInfo_wblob);
                memcpy(_pInfo_wblob.data(),pInfo,(1)* sizeof(st_fpi_net_update_info));
            }

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_update_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_update_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_update_info error");
        }

        return _result;
        /*-- add you code for tos_setting_set_update_info here --*/
    }

    fpi_error tos_setting_updating_is_running( EN_FPI_SOFTWARE_UPDATE updateMode, int32_t* running ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_updating_is_running here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(updateMode);  //EN_FPI_SOFTWARE_UPDATE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (running == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_updating_is_running,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (running != NULL) {
                    int _running_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _running_rblob;
                    reply.readBlob(_running_len,&_running_rblob);
                    memcpy(running,_running_rblob.data(),_running_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_updating_is_running error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_updating_is_running error");
        }

        return _result;
        /*-- add you code for tos_setting_updating_is_running here --*/
    }

    fpi_error tos_setting_reset_default(  ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_reset_default here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_setting_reset_default,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_reset_default error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_reset_default error");
        }

        return _result;
        /*-- add you code for tos_setting_reset_default here --*/
    }

    fpi_error tos_setting_get_download_file_size( int32_t * size ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_download_file_size here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (size == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_download_file_size,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (size != NULL) {
                    int _size_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _size_rblob;
                    reply.readBlob(_size_len,&_size_rblob);
                    memcpy(size,_size_rblob.data(),_size_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_download_file_size error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_download_file_size error");
        }

        return _result;
        /*-- add you code for tos_setting_get_download_file_size here --*/
    }

    fpi_error tos_setting_get_ui_content( EN_UI_CONTENT e_content, int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_ui_content here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_content);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_ui_content,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_ui_content error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_ui_content error");
        }

        return _result;
        /*-- add you code for tos_setting_get_ui_content here --*/
    }

    fpi_error tos_setting_set_ui_content( EN_UI_CONTENT e_content, int32_t value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_ui_content here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_content);  //int as input paramter

            data.writeInt32(value);  //int as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_ui_content,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_ui_content error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_ui_content error");
        }

        return _result;
        /*-- add you code for tos_setting_set_ui_content here --*/
    }

    fpi_error tos_setting_get_location( EN_FPI_LOCATION* value ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_location here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_LOCATION));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_setting_get_location,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_get_location error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_get_location error");
        }

        return _result;
        /*-- add you code for tos_setting_get_location here --*/
    }

    fpi_error tos_setting_set_location( EN_FPI_LOCATION location, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_location here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(location);  //EN_FPI_LOCATION as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_setting_set_location,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_setting_set_location error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_location error");
        }

        return _result;
        /*-- add you code for tos_setting_set_location here --*/
    }

fpi_error tos_setting_get_current_base_time( int32_t *seconds){
    Parcel data, reply;
	fpi_error _result = FPI_ERROR_FAIL;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
		//for out only, only write length ; for in, alloc and copy
		if (seconds == NULL) {
			data.writeInt32(-1);
		}
		else {
			data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
		}

		_binder->transact(TRANSACTION_tos_setting_get_current_base_time,data, &reply,0);
		if(reply.readExceptionCode() == 0) {//fix check

			if (seconds != NULL) {
				int _value_len = reply.readInt32(); //read length, only 32bits length support yet
				Parcel::ReadableBlob _value_rblob;
				reply.readBlob(_value_len,&_value_rblob);
				memcpy(seconds,_value_rblob.data(),_value_len);
			}
			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			fpi_warn(SERVICE_NAME"_client tos_setting_get_current_base_time error");
		}
	}catch(...) {
		fpi_warn(SERVICE_NAME"_client tos_setting_get_current_base_time error");
	}
	return _result;
}
fpi_error tos_setting_get_current_base_time_without_offset( int32_t *seconds){
    Parcel data, reply;
	fpi_error _result = FPI_ERROR_FAIL;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
		//for out only, only write length ; for in, alloc and copy
		if (seconds == NULL) {
			data.writeInt32(-1);
		}
		else {
			data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
		}

		_binder->transact(TRANSACTION_tos_setting_get_current_base_time_without_offset,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check

			if (seconds != NULL) {
				int _value_len = reply.readInt32(); //read length, only 32bits length support yet
				Parcel::ReadableBlob _value_rblob;
				reply.readBlob(_value_len,&_value_rblob);
				memcpy(seconds,_value_rblob.data(),_value_len);
			}
			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			fpi_warn(SERVICE_NAME"_client tos_setting_get_current_base_time_without_offset error");
		}
	}catch(...) {
		fpi_warn(SERVICE_NAME"_client tos_setting_get_current_base_time_without_offset error");
	}
	return _result;
}

fpi_error tos_setting_get_clock_offset( int32_t *seconds){
    Parcel data, reply;
	fpi_error _result = FPI_ERROR_FAIL;
	if(!getService()) {
		return _result;
	}
	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
		//for out only, only write length ; for in, alloc and copy
		if (seconds == NULL) {
			data.writeInt32(-1);
		}
		else {
			data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
		}

		_binder->transact(TRANSACTION_tos_setting_get_clock_offset,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check

			if (seconds != NULL) {
				int _value_len = reply.readInt32(); //read length, only 32bits length support yet
				Parcel::ReadableBlob _value_rblob;
				reply.readBlob(_value_len,&_value_rblob);
				memcpy(seconds,_value_rblob.data(),_value_len);
			}
			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			fpi_warn(SERVICE_NAME"_client tos_setting_get_clock_offset error");
		}
	}catch(...) {
		fpi_warn(SERVICE_NAME"_client tos_setting_get_clock_offset error");
	}
	return _result;
}

fpi_error tos_setting_utility_second_to_time(int32_t seconds, st_fpi_date *time) {
    Parcel data, reply;
	fpi_error _result = FPI_ERROR_FAIL;
	if(!getService()) {
	   return _result;
	}

	try {
	   data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

	   data.writeInt32(seconds);  //EN_SETTING_TIME_CTRL as input paramter

	   //for out only, only write length ; for in, alloc and copy
	   if (time == NULL) {
		   data.writeInt32(-1);
	   }
	   else {
		   data.writeInt32((int)(1) * sizeof(st_fpi_date));//write length, only support 32 bits length yet
		   
	   }

	   _binder->transact(TRANSACTION_tos_setting_utility_second_to_time,data, &reply,0);

	   if(reply.readExceptionCode() == 0) {//fix check

		   if (time != NULL) {
			   int _value_len = reply.readInt32(); //read length, only 32bits length support yet
			   Parcel::ReadableBlob _value_rblob;
			   reply.readBlob(_value_len,&_value_rblob);
			   memcpy(time,_value_rblob.data(),_value_len);
		   }
		   _result = (typeof(_result))reply.readInt32();//int as return value

	   } else {
		   fpi_warn(SERVICE_NAME"_client tos_setting_utility_second_to_time error");
	   }
	}catch(...) {
	   fpi_warn(SERVICE_NAME"_client tos_setting_utility_second_to_time error");
	}

	return _result;
}

fpi_error  tos_setting_set_time_dst_state(fpi_bool  bEnable) {
    Parcel data, reply;

    fpi_error _result = FPI_ERROR_FAIL;
    if(!getService()) {
        return _result;
    }

    try {
        data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

        data.writeInt32(bEnable);  //EN_FPI_LOCATION as input paramter

        _binder->transact(TRANSACTION_tos_setting_set_time_dst_state,data, &reply,0);

        if(reply.readExceptionCode() == 0) {//fix check

            _result = (typeof(_result))reply.readInt32();//int as return value

        } else {
            fpi_warn(SERVICE_NAME"_client tos_setting_set_time_dst_state error");
        }
    }catch(...) {
        fpi_warn(SERVICE_NAME"_client tos_setting_set_time_dst_state error");
    }

    return _result;
}

fpi_error tos_setting_get_time_dst_state(fpi_bool  *bEnable) {
    Parcel data, reply;
	fpi_error _result = FPI_ERROR_FAIL;
	if(!getService()) {
		return _result;
	}

	try {
	data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
	//for out only, only write length ; for in, alloc and copy
	if (bEnable == NULL) {
		data.writeInt32(-1);
	}
	else {
		data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
	}

	_binder->transact(TRANSACTION_tos_setting_get_time_dst_state,data, &reply,0);

	if(reply.readExceptionCode() == 0) {//fix check

		if (bEnable != NULL) {
			int _value_len = reply.readInt32(); //read length, only 32bits length support yet
			Parcel::ReadableBlob _value_rblob;
			reply.readBlob(_value_len,&_value_rblob);
			memcpy(bEnable,_value_rblob.data(),_value_len);
		}
		_result = (typeof(_result))reply.readInt32();//int as return value

	} else {
		fpi_warn(SERVICE_NAME"_client tos_setting_get_time_dst_state error");
	}
	}catch(...) {
	fpi_warn(SERVICE_NAME"_client tos_setting_get_time_dst_state error");
	}
	return _result;
};

fpi_error tos_setting_set_special_mode_enable( EN_TOS_SPECIAL_MODE e_param, int32_t value, EN_ACT_CTRL act ) {       
    Parcel data, reply;        
    /*-- add you code for tos_setting_set_special_mode_enable here --*/        
    fpi_error _result = FPI_ERROR_FAIL;        
    if(!getService()) {            
        return _result;        
    }        

    try {            
        data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check            
        data.writeInt32(e_param);  //EN_TOS_SPECIAL_MODE as input paramter            
        data.writeInt32(value);  //int32_t as input paramter  
        data.writeInt32(act);  //EN_ACT_CTRL as input paramter
        _binder->transact(TRANSACTION_tos_setting_set_special_mode_enable,data, &reply,0);            
        if(reply.readExceptionCode() == 0) {//fix check                
            _result = (typeof(_result))reply.readInt32();//int as return value           
            } else {                
            TOSLOGW(SERVICE_NAME"_client tos_setting_set_special_mode_enable error");            
            }        
         }catch(...) {            
         TOSLOGW(SERVICE_NAME"_client tos_setting_set_special_mode_enable error");        
         }       
         return _result;        
         /*-- add you code for tos_setting_set_special_mode_enable here --*/    
         }    
fpi_error tos_setting_get_special_mode_enable( EN_TOS_SPECIAL_MODE e_param, int32_t *value ) {        
    Parcel data, reply;        
    /*-- add you code for tos_setting_get_special_mode_enable here --*/        
    fpi_error _result = FPI_ERROR_FAIL;         
    if(!getService()) {            
        return _result;        
    }        

    try {            
        data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check            
        data.writeInt32(e_param);  //EN_TOS_SPECIAL_MODE as input paramter            

        if (value == NULL) {		
            data.writeInt32(-1);    
        }   
        else {      
            data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet    
        }         
        _binder->transact(TRANSACTION_tos_setting_get_special_mode_enable,data, &reply,0);            
        if(reply.readExceptionCode() == 0) {//fix check                

        if (value != NULL) {			
            int _value_len = reply.readInt32(); //read length, only 32bits length support yet 
            Parcel::ReadableBlob _value_rblob;       
            reply.readBlob(_value_len,&_value_rblob);        
            memcpy(value,_value_rblob.data(),_value_len);     
        }
        		
        _result = (typeof(_result))reply.readInt32();//int as return value            
        } else {                
        TOSLOGW(SERVICE_NAME"_client tos_setting_get_special_mode_enable error");            
          }        
        }catch(...) {            
        TOSLOGW(SERVICE_NAME"_client tos_setting_get_special_mode_enable error");        
        }       
        return _result;       
        /*-- add you code for tos_setting_get_special_mode_enable here --*/    
        }


fpi_error tos_setting_set_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t mode) {
        Parcel data, reply;

        /*-- add you code for tos_setting_set_net_wakeup_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            data.writeInt32(e_wakeup_mode);
            data.writeInt32(mode);  //uint8_t as input paramter
            _binder->transact(TRANSACTION_tos_setting_set_net_wakeup_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32(); //int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_work_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_work_mode error");
        }

        return _result;
        /*-- add you code for tos_setting_set_net_wakeup_mode here --*/
    }

fpi_error tos_setting_get_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t* mode) {
        Parcel data, reply;

        /*-- add you code for tos_setting_get_net_wakeup_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {            
	        data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check            
	        data.writeInt32(e_wakeup_mode);  //EN_TOS_SPECIAL_MODE as input paramter            

	        if (mode == NULL) {		
	            data.writeInt32(-1);    
	        }   
	        else {      
	            data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet    
	        }         
	        _binder->transact(TRANSACTION_tos_setting_get_net_wakeup_mode,data, &reply,0);            
	        if(reply.readExceptionCode() == 0) {//fix check                

	        if (mode != NULL) {			
	            int _value_len = reply.readInt32(); //read length, only 32bits length support yet 
	            Parcel::ReadableBlob _value_rblob;       
	            reply.readBlob(_value_len,&_value_rblob);        
	            memcpy(mode,_value_rblob.data(),_value_len);     
	        }
	        		
	        _result = (typeof(_result))reply.readInt32();//int as return value            
	        } else {                
	        TOSLOGW(SERVICE_NAME"_client tos_setting_get_net_wakeup_mode error");            
	          }        
	        }
			catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_setting_get_net_wakeup_mode error");
        }

        return _result;
        /*-- add you code for tos_setting_get_net_wakeup_mode here --*/
    }

	fpi_error tos_setting_get_state(EN_FUNC_STATE_TYPE eState, fpi_bool* enable) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_aft_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check           
			data.writeInt32(eState);
            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet                
            }

            _binder->transact(TRANSACTION_tos_setting_get_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value
				TOSLOGW(SERVICE_NAME"_client enable=%d \n", *enable);
            } else {
                TOSLOGW(SERVICE_NAME"_client tos_setting_get_state error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_setting_get_state error");
        }

        return _result;
        /*-- add you code for tos_atv_get_aft_enable here --*/
    }
    
    fpi_error tos_function_set_user_defined_logo( char* logo_path ) {      
        Parcel data, reply;        
        /*-- add you code for tos_function_set_user_defined_logo here --*/        
        fpi_error _result= FPI_ERROR_FAIL;        
        if(!getService()) {            
            return _result;        
        }        
        try {            
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check         
            //for out only, only write length ; for in, alloc and copy         
            if (logo_path == NULL) {               
                data.writeInt32(-1);           
            }           
            else {               
                data.writeInt32((int)(strlen(logo_path)+1) * sizeof(char));
                //write length, only support 32 bits length yet                     
                Parcel::WritableBlob _logo_path_wblob;             
                data.writeBlob((strlen(logo_path)+1) * sizeof(char),&_logo_path_wblob);       
                memcpy(_logo_path_wblob.data(),logo_path,(strlen(logo_path)+1)* sizeof(char));    
            }           
            _binder->transact(TRANSACTION_tos_function_set_user_defined_logo,data, &reply,0);
            
            if(reply.readExceptionCode() == 0) {//fix check           
              _result = (typeof(_result))reply.readInt32();//int as return value      
            } else {               
              TOSLOGW(SERVICE_NAME"_client tos_function_set_user_defined_logo error");       
             }      
           }catch(...) {          
              TOSLOGW(SERVICE_NAME"_client tos_function_set_user_defined_logo error");     
             }      
           return _result;       
           /*-- add you code for tos_function_set_user_defined_logo here --*/   
       }

	fpi_error tos_setting_time_blocktag(fpi_bool bBlockToModifyTime) {
		Parcel data, reply;
		/*-- add you code for tos_atv_get_aft_enable here --*/
		fpi_error _result = FPI_ERROR_FAIL;
		if(!getService()) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check			 
			data.writeInt32(bBlockToModifyTime);
			//for out only, only write length ; for in, alloc and copy

			_binder->transact(TRANSACTION_tos_setting_time_blocktag,data, &reply,0);

			if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
			} else {
				CLOGW(SERVICE_NAME"_client tos_setting_time_blocktag error");
			}
		}catch(...) {
			CLOGW(SERVICE_NAME"_client tos_setting_time_blocktag error");
		}

		return _result;
		/*-- add you code for tos_atv_get_aft_enable here --*/
	}

};

sbinder_function_setting_client* sbinder_function_setting_client::_instance = NULL;

fpi_error tos_setting_get_menu_language( MEMBER_LANGUAGE* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_menu_language(value);
}
fpi_error tos_setting_set_menu_language( MEMBER_LANGUAGE language, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_menu_language(language, act);
}
fpi_error tos_setting_get_time_zone( EN_FPI_TIME_ZONE* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_time_zone(value);
}
fpi_error tos_setting_set_time_zone( EN_FPI_TIME_ZONE timezone, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_time_zone(timezone, act);
}
fpi_error tos_setting_get_region( EN_REGION_TYPE region, int32_t* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_region(region, value);
}
fpi_error tos_setting_set_region( EN_REGION_TYPE region_country, int32_t region, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_region(region_country, region, act);
}
fpi_error tos_setting_get_time_sync( int32_t* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_time_sync(value);
}
fpi_error tos_setting_set_time_sync( int32_t autosync, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_time_sync(autosync, act);
}
fpi_error tos_setting_get_time( EN_SETTING_TIME_CTRL type, st_fpi_date* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_time(type, value);
}
fpi_error tos_setting_set_time( EN_SETTING_TIME_CTRL type, st_fpi_date* pst_date, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_time(type, pst_date, act);
}
fpi_error tos_setting_updating( EN_FPI_SOFTWARE_UPDATE updateMode, EN_UPDATE_ACTION_CTRL action ) {
    return sbinder_function_setting_client::Instance()->tos_setting_updating(updateMode, action);
}
fpi_error tos_setting_get_update_info( EN_FPI_SOFTWARE_UPDATE updateMode, st_fpi_net_update_info* pInfo ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_update_info(updateMode, pInfo);
}
fpi_error tos_setting_set_update_info( EN_FPI_SOFTWARE_UPDATE updateMode, st_fpi_net_update_info* pInfo, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_update_info(updateMode, pInfo, act);
}
fpi_error tos_setting_updating_is_running( EN_FPI_SOFTWARE_UPDATE updateMode, int32_t* running ) {
    return sbinder_function_setting_client::Instance()->tos_setting_updating_is_running(updateMode, running);
}
fpi_error tos_setting_reset_default(  ) {
    return sbinder_function_setting_client::Instance()->tos_setting_reset_default();
}
fpi_error tos_setting_get_download_file_size( int32_t * size ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_download_file_size(size);
}
fpi_error tos_setting_get_ui_content( EN_UI_CONTENT e_content, int32_t *value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_ui_content(e_content, value);
}
fpi_error tos_setting_set_ui_content( EN_UI_CONTENT e_content, int32_t value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_ui_content(e_content, value);
}
fpi_error tos_setting_get_location( EN_FPI_LOCATION* value ) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_location(value);
}
fpi_error tos_setting_set_location( EN_FPI_LOCATION location, EN_ACT_CTRL act ) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_location(location, act);
}
fpi_error tos_setting_get_current_base_time( int32_t *seconds) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_current_base_time(seconds);
}
fpi_error tos_setting_get_current_base_time_without_offset( int32_t *seconds) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_current_base_time_without_offset(seconds);
}
fpi_error tos_setting_get_clock_offset( int32_t *seconds) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_clock_offset(seconds);
}
fpi_error tos_setting_utility_second_to_time( int32_t seconds, st_fpi_date *time ) {
    return sbinder_function_setting_client::Instance()->tos_setting_utility_second_to_time(seconds, time);
}
fpi_error tos_setting_set_time_dst_state(fpi_bool  bEnable) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_time_dst_state(bEnable);
}
fpi_error tos_setting_get_time_dst_state(fpi_bool  *bEnable) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_time_dst_state(bEnable);
}
fpi_error tos_setting_set_special_mode_enable( EN_TOS_SPECIAL_MODE e_param, int32_t value , EN_ACT_CTRL act) {  
    return sbinder_function_setting_client::Instance()->tos_setting_set_special_mode_enable(e_param, value,act);
}
fpi_error tos_setting_get_special_mode_enable( EN_TOS_SPECIAL_MODE e_param, int32_t *value ) {    
    return sbinder_function_setting_client::Instance()->tos_setting_get_special_mode_enable(e_param, value);
}
fpi_error tos_setting_set_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t mode) {
    return sbinder_function_setting_client::Instance()->tos_setting_set_net_wakeup_mode(e_wakeup_mode, mode);
}
fpi_error tos_setting_get_net_wakeup_mode(EN_FUNC_NET_WAKEUP_MODE e_wakeup_mode , uint8_t* mode) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_net_wakeup_mode(e_wakeup_mode, mode);
}
fpi_error tos_setting_get_state(EN_FUNC_STATE_TYPE eState, fpi_bool* enable) {
    return sbinder_function_setting_client::Instance()->tos_setting_get_state(eState, enable);
}
fpi_error tos_function_set_user_defined_logo( char* logo_path ) {   
    return sbinder_function_setting_client::Instance()->tos_function_set_user_defined_logo(logo_path);
}
fpi_error tos_setting_time_blocktag(fpi_bool bBlockToModifyTime) {
	return sbinder_function_setting_client::Instance()->tos_setting_time_blocktag(bBlockToModifyTime);
}


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
