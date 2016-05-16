/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_network_setting.sidl
 */
 

#define LOG_TAG     "sbinder_network_setting"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_network_setting.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_NETWORK);


#define SERVICE_DESCRIPTOR                      "7ebe08e4-303c-11e5-87c6-005056a86db3"
#define SERVICE_NAME                            "sbinder_network_setting"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_network_get_hardware_status FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_network_wire_connect FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_network_wire_get_connect_type FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_network_get_connect_status FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_network_get_current_speed FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_network_wireless_get_current_signalquality FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_network_wireless_get_current_signalstrength FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_network_wireless_get_encryption_mode FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_network_wireless_get_encrypt_algorithm FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_network_wireless_get_channel FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_network_wireless_get_ap_count FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_network_wireless_start_scan FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_network_wireless_stop_scan FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_network_wireless_get_ap_list FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_network_wireless_get_last_connect_ap_info FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_network_wireless_connect_manual FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_network_wireless_connect_pbc FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_network_wireless_abort_pbc FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_network_wireless_connect_wps_pin FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_network_wireless_wps_pin_fresh FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_network_wireless_get_wps_pin FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_network_wireless_miracast_start FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_network_wireless_miracast_stop FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_network_get_info FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_network_local_connection_test FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_network_set_enable FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_network_get_enable FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_network_set_select_pattern FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_network_get_select_pattern FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_network_connection_test FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_network_change_notify FIRST_CALL_TRANSACTION + 31

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_network_setting.h"

class sbinder_network_setting_service : public BBinder  
{  
private:
    static sbinder_network_setting_service* _instance;

    sbinder_network_setting_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_network_setting_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_network_setting_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_info(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_debug(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_network_get_hardware_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_hardware_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
             //#error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
                EN_NETWORK_TYPE network_type = (EN_NETWORK_TYPE)data.readInt32();

                int32_t status = 0;
                fpi_error _result = tos_network_get_hardware_status( network_type, &status );
                reply->writeInt32(status);
                
                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_get_hardware_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wire_connect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wire_connect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // #error not support this type of paramter E_NETWORK_CONNECT_TYPE type yet, please add code yourself
                E_NETWORK_CONNECT_TYPE type = (E_NETWORK_CONNECT_TYPE)data.readInt32();
                // #error not support un-plat struct info yet, please add code yourself
                // #if your struct is plat, do not mark it as a struct

                int32_t _info_len = data.readInt32(); //read length, only 32bits length support yet
                st_wire_network_info* info = NULL;
				 
                 if(_info_len > 0) {
                    Parcel::ReadableBlob _info_rblob;
                    data.readBlob(_info_len,&_info_rblob);
                    info = (st_wire_network_info*)_info_rblob.data();

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_wire_connect( type, info );

                    reply->writeInt32(_result); //fpi_error as return value
                 }
                 else {
                    reply->writeInt32(fpi_false); //fpi_error as return value
                 }
		
                //-- end code for tos_network_wire_connect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wire_get_connect_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wire_get_connect_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
          //  #error not support this type of paramter E_NETWORK_CONNECT_TYPE type yet, please add code yourself
                //data.writeInt32(type);
                
                int _type_len = data.readInt32(); //read length, only 32bits length support yet
                E_NETWORK_CONNECT_TYPE* type = NULL;

                Parcel::WritableBlob _type_wblob;

                if(_type_len > 0) {
                    reply->writeInt32(_type_len);
                    reply->writeBlob(_type_len,&_type_wblob);
                    type = (E_NETWORK_CONNECT_TYPE*)_type_wblob.data();

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_wire_get_connect_type( type );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }
				

                //-- end code for tos_network_wire_get_connect_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_get_connect_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_connect_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
          //  #error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
                EN_NETWORK_TYPE network_type = (EN_NETWORK_TYPE)data.readInt32();  
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //value = (int32_t*)_value_wblob.data();
                    fpi_error _result = tos_network_get_connect_status( network_type, value );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_get_connect_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_get_current_speed:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_current_speed here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
           // #error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
             //  data.writeInt32(network_type);
                EN_NETWORK_TYPE network_type = (EN_NETWORK_TYPE)data.readInt32();  
                int32_t _speed_len = data.readInt32(); //read length, only 32bits length support yet
                _speed_len = data.readInt32();// this is the real speed char buffer max size
                char* speed = NULL;

                Parcel::WritableBlob _speed_wblob;

                if(_speed_len > 0) {
                    reply->writeInt32(_speed_len);
                    reply->writeBlob(_speed_len,&_speed_wblob);
                    speed = (char*)_speed_wblob.data();

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //speed = (char*)_speed_wblob.data();
                    fpi_error _result = tos_network_get_current_speed( network_type, speed, _speed_len );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }
                
                //-- end code for tos_network_get_current_speed here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_current_signalquality:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_current_signalquality here, will auoto generated but may change yourself if need --

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

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //value = (int32_t*)_value_wblob.data();
                    fpi_error _result = tos_network_wireless_get_current_signalquality( value );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_get_current_signalquality here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_current_signalstrength:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_current_signalstrength here, will auoto generated but may change yourself if need --

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

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //value = (int32_t*)_value_wblob.data();
                    fpi_error _result = tos_network_wireless_get_current_signalstrength( value );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }


                //-- end code for tos_network_wireless_get_current_signalstrength here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_encryption_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_encryption_mode here, will auoto generated but may change yourself if need --

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

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //value = (int32_t*)_value_wblob.data();
                    fpi_error _result = tos_network_wireless_get_encryption_mode( value );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }


                //-- end code for tos_network_wireless_get_encryption_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_encrypt_algorithm:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_encrypt_algorithm here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _encrypt_data_len = data.readInt32(); //read length, only 32bits length support yet
                _encrypt_data_len = data.readInt32();//this is the real char buffer max size
                char* encrypt_data = NULL;

                Parcel::WritableBlob _encrypt_data_wblob;

                if(_encrypt_data_len > 0) {
                    reply->writeInt32(_encrypt_data_len);
                    reply->writeBlob(_encrypt_data_len,&_encrypt_data_wblob);
                    encrypt_data = (char*)_encrypt_data_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //encrypt_data = (char*)_encrypt_data_wblob.data();
                    fpi_error _result = tos_network_wireless_get_encrypt_algorithm( encrypt_data, _encrypt_data_len );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_get_encrypt_algorithm here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _channel_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* channel = NULL;

                Parcel::WritableBlob _channel_wblob;

                if(_channel_len > 0) {
                    reply->writeInt32(_channel_len);
                    reply->writeBlob(_channel_len,&_channel_wblob);
                    channel = (int32_t*)_channel_wblob.data();
                }

                int _freq_len = data.readInt32(); //read length, only 32bits length support yet
                char freq_str[128] = {0};

                fpi_error _result = tos_network_wireless_get_channel( channel, freq_str );
                _freq_len = strlen(freq_str) + 1;
                
                Parcel::WritableBlob _freq_wblob;

                if(_freq_len > 0) {
                    reply->writeInt32(_freq_len);
                    reply->writeBlob(_freq_len,&_freq_wblob);
                    memcpy(_freq_wblob.data(), freq_str, _freq_len);
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //channel = (int32_t*)_channel_wblob.data();
                    //freq = (char*)_freq_wblob.data();
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }


                //-- end code for tos_network_wireless_get_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_ap_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_ap_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ap_data_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* ap_data = NULL;

                Parcel::WritableBlob _ap_data_wblob;

                if(_ap_data_len > 0) {
                    reply->writeInt32(_ap_data_len);
                    reply->writeBlob(_ap_data_len,&_ap_data_wblob);
                    ap_data = (int32_t*)_ap_data_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //ap_data = (int32_t*)_ap_data_wblob.data();
                    fpi_error _result = tos_network_wireless_get_ap_count( ap_data );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_get_ap_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_start_scan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_start_scan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_start_scan(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_start_scan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_stop_scan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_stop_scan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_stop_scan(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_stop_scan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_ap_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_ap_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t onePageApCount = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t pageIndex = (int32_t)data.readInt32();  //int32_t as input paramter

/*
                int32_t _pwireless_info_len = (int32_t)data.readInt32(); 
	        st_wireless_network_info* pwireless_info = NULL;
                //#error not support this type of paramter st_wireless_network_info pwireless_info yet, please add code yourself

		 Parcel::WritableBlob _pwireless_info_wblob;

                if(_pwireless_info_len > 0) {
                    reply->writeInt32(_pwireless_info_len);
                    reply->writeBlob(_pwireless_info_len,&_pwireless_info_wblob);
                    pwireless_info = (st_wireless_network_info*)_pwireless_info_wblob.data();
                }
		    pwireless_info = (st_wireless_network_info*)_pwireless_info_wblob.data();
		 
                int _pAvailableCount_len = data.readInt32(); //read length, only 32bits length support yet
                int* pAvailableCount = NULL;

                Parcel::WritableBlob _pAvailableCount_wblob;

                if(_pAvailableCount_len > 0) {
                    reply->writeInt32(_pAvailableCount_len);
                    reply->writeBlob(_pAvailableCount_len,&_pAvailableCount_wblob);
                    pAvailableCount = (int*)_pAvailableCount_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pAvailableCount = (int*)_pAvailableCount_wblob.data();
                */

                int32_t AvailableCount = 0;
                int32_t network_info_size = (int32_t)data.readInt32();
                st_wireless_network_info *p_network_info = NULL;
                Parcel::WritableBlob _pwireless_info_wblob;
                
                if(network_info_size > 0) {
                    reply->writeInt32(network_info_size);
                    reply->writeBlob(network_info_size,&_pwireless_info_wblob);
                    p_network_info = (st_wireless_network_info*)_pwireless_info_wblob.data();

                    fpi_error _result = tos_network_wireless_get_ap_list( onePageApCount, pageIndex, 
                                            p_network_info, &AvailableCount );

                    //#error not support this type of return yet, please add code for 'tos_network_wireless_get_ap_list' yourself

                    reply->writeInt32(AvailableCount);
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);//network_info_size
                    reply->writeInt32(0);//availableCount
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_get_ap_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_last_connect_ap_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_last_connect_ap_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              //#error not support this type of paramter st_ap_info api_ap_info yet, please add code yourself?
                int _api_ap_info_len = data.readInt32(); //read length, only 32bits length support yet
                st_ap_info* api_ap_info = NULL;

                Parcel::WritableBlob _api_ap_info_wblob;

                if(_api_ap_info_len > 0) {
                    reply->writeInt32(_api_ap_info_len);
                    reply->writeBlob(_api_ap_info_len,&_api_ap_info_wblob);
                    api_ap_info = (st_ap_info*)_api_ap_info_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //api_ap_info = (st_ap_info*)_api_ap_info_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_wireless_get_last_connect_ap_info( api_ap_info );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_get_last_connect_ap_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_connect_manual:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_connect_manual here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ssid_len = data.readInt32(); //read length, only 32bits length support yet
                char* ssid = NULL;

                Parcel::ReadableBlob _ssid_rblob;

                if(_ssid_len > 0) {
                    data.readBlob(_ssid_len,&_ssid_rblob);
                    ssid = (char*)_ssid_rblob.data();
                }

                int _psw_len = data.readInt32(); //read length, only 32bits length support yet
                char* psw = NULL;

                Parcel::ReadableBlob _psw_rblob;

                if(_psw_len > 0) {
                    data.readBlob(_psw_len,&_psw_rblob);
                    psw = (char*)_psw_rblob.data();
                }

           // #error not support this type of paramter API_WIFI_SECURITY_TYPE SECURITY yet, please add code yourself
                API_WIFI_SECURITY_TYPE SECURITY = (API_WIFI_SECURITY_TYPE)data.readInt32(); 
		   
                int _encryption_len = data.readInt32(); //read length, only 32bits length support yet
                char* encryption = NULL;

                Parcel::ReadableBlob _encryption_rblob;

                if(_encryption_len > 0) {
                    data.readBlob(_encryption_len,&_encryption_rblob);
                    encryption = (char*)_encryption_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                //ssid = (char*)_ssid_rblob.data();
                //psw = (char*)_psw_rblob.data();
                //encryption = (char*)_encryption_rblob.data();

                if((NULL != ssid) && (NULL != psw) && (NULL != encryption) ) {
                    fpi_error _result = tos_network_wireless_connect_manual( ssid, psw, SECURITY, encryption );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_wireless_connect_manual here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_connect_pbc:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_connect_pbc here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_connect_pbc(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_connect_pbc here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_abort_pbc:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_abort_pbc here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_abort_pbc(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_abort_pbc here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_connect_wps_pin:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_connect_wps_pin here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_in_len = data.readInt32(); //read length, only 32bits length support yet
                const char* pin_in = NULL;

                Parcel::ReadableBlob _pin_in_rblob;

                if(_pin_in_len > 0) {
                    data.readBlob(_pin_in_len,&_pin_in_rblob);
                    pin_in = (const char*)_pin_in_rblob.data();
                }

                int _pin_out_len = data.readInt32(); //read length, only 32bits length support yet
                char* pin_out = NULL;
                int32_t out_size = (int32_t)data.readInt32();  //int32_t as input paramter

                Parcel::WritableBlob _pin_out_wblob;

                if((_pin_out_len > 0) && (0 < out_size)) {
                    reply->writeInt32(out_size);
                    reply->writeBlob(out_size,&_pin_out_wblob);
                    pin_out = (char*)_pin_out_wblob.data();

                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //pin_in = (const char*)_pin_in_rblob.data();
                    //pin_out = (char*)_pin_out_wblob.data();
                    fpi_error _result = tos_network_wireless_connect_wps_pin( pin_in, pin_out, out_size );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }


                //-- end code for tos_network_wireless_connect_wps_pin here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_wps_pin_fresh:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_wps_pin_fresh here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_out_len = data.readInt32(); //read length, only 32bits length support yet
                char pin_out[128] = {0};

                fpi_error _result = tos_network_wireless_wps_pin_fresh( pin_out );
                _pin_out_len = strlen(pin_out) + 1;
                
                Parcel::WritableBlob _pin_out_wblob;

                if(_pin_out_len > 0) {
                    reply->writeInt32(_pin_out_len);
                    reply->writeBlob(_pin_out_len,&_pin_out_wblob);
                    memcpy(_pin_out_wblob.data(), pin_out, _pin_out_len);
                }
                else {
                    reply->writeInt32(0);
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                //pin_out = (char*)_pin_out_wblob.data();

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_wps_pin_fresh here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_get_wps_pin:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_get_wps_pin here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t _pin_out_len = data.readInt32(); //read length, only 32bits length support yet
                char* pin_out = NULL;
                int32_t size = (int32_t)data.readInt32();  //int32_t as input paramter

                Parcel::WritableBlob _pin_out_wblob;

                if((_pin_out_len > 0) && (0 < size)) {
                    reply->writeInt32(size);
                    reply->writeBlob(size,&_pin_out_wblob);
                    pin_out = (char*)_pin_out_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //pin_out = (char*)_pin_out_wblob.data();
                    fpi_error _result = tos_network_wireless_get_wps_pin( pin_out, size );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }


                //-- end code for tos_network_wireless_get_wps_pin here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_miracast_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_miracast_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_miracast_start(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_miracast_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_wireless_miracast_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_wireless_miracast_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_wireless_miracast_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_wireless_miracast_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_get_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                //st_wire_network_info* network_info
                //begin paramters list
                //#error not support this type of paramter st_wire_network_info network_info yet, please add code yourself

                int32_t _network_info_len = (int32_t)data.readInt32(); 
                st_wire_network_info* network_info = NULL;

                Parcel::WritableBlob _network_info_wblob;

                if(_network_info_len > 0) {
                    reply->writeInt32(_network_info_len);
                    reply->writeBlob(_network_info_len,&_network_info_wblob);
                    network_info = (st_wire_network_info*)_network_info_wblob.data();

                    //network_info = (st_wire_network_info*)_network_info_wblob.data();
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_get_info( network_info );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_get_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_local_connection_test:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_local_connection_test here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_local_connection_test(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_local_connection_test here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_connection_test:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
            
                //-- begin code for tos_network_connection_test here, will auoto generated but may change yourself if need --
            
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
            
                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_connection_test(  );
            
                reply->writeInt32(_result); //fpi_error as return value
            
                //-- end code for tos_network_connection_test here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_set_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_set_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool enable = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_set_enable( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_set_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_get_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter fpi_bool enable yet, please add code yourself
                int32_t _enable_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* enable = NULL;

                Parcel::WritableBlob _enable_wblob;

                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (fpi_bool*)_enable_wblob.data();
                    
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    //enable = (fpi_bool*)_enable_wblob.data();
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_get_enable( enable );

                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_get_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_set_select_pattern:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_set_select_pattern here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            //#error not support this type of paramter EN_NETWORK_TYPE connect_pattern yet, please add code yourself
                E_NETWORK_CONNECT_TYPE connect_pattern = (E_NETWORK_CONNECT_TYPE)data.readInt32();
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_set_select_pattern( connect_pattern );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_set_select_pattern here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_network_get_select_pattern:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_get_select_pattern here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
           // #error not support this type of paramter EN_NETWORK_TYPE connect_pattern yet, please add code yourself
                int _connect_pattern_len = data.readInt32(); //read length, only 32bits length support yet
                E_NETWORK_CONNECT_TYPE* connect_pattern = NULL;

                Parcel::WritableBlob _connect_pattern_wblob;

                if(_connect_pattern_len > 0) {
                    reply->writeInt32(_connect_pattern_len);
                    reply->writeBlob(_connect_pattern_len,&_connect_pattern_wblob);
                    connect_pattern = (E_NETWORK_CONNECT_TYPE*)_connect_pattern_wblob.data();

                    //connect_pattern = (EN_NETWORK_TYPE*)_connect_pattern_wblob.data();
                    // re-get all pointers from blob to fix realloc issue in Parcel
                    fpi_error _result = tos_network_get_select_pattern( connect_pattern );
                    
                    reply->writeInt32(_result); //fpi_error as return value
                }
                else {
                    reply->writeInt32(0);
                    reply->writeInt32(fpi_false); //fpi_error as return value
                }

                //-- end code for tos_network_get_select_pattern here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
             case TRANSACTION_tos_network_change_notify:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_network_change_notify here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_NETWORK_CHANGE_TYPE type = (EN_NETWORK_CHANGE_TYPE)data.readInt32();  //EN_NETWORK_CHANGE_TYPE as input paramter

                int32_t reserved_data = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_network_change_notify( type, reserved_data );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_network_change_notify here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_network_setting_service_add() {
    sbinder_network_setting_service::Instance();
    return 0;
}

sbinder_network_setting_service* sbinder_network_setting_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_network_setting_client  
{  
private:
    static sbinder_network_setting_client* _instance;
    sp<IBinder> _binder;

    sbinder_network_setting_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_network_setting_client() {
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
    static sbinder_network_setting_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_network_setting_client();
        }

        return _instance;
    }

    fpi_error tos_network_get_hardware_status( EN_NETWORK_TYPE network_type, int32_t* status ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_hardware_status here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
             data.writeInt32(network_type);
            //for out only, only write length ; for in, alloc and copy

            _binder->transact(TRANSACTION_tos_network_get_hardware_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (status != NULL) {
                    *status = reply.readInt32();
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((status != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *status = 0;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_hardware_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_hardware_status error");
        }

        return _result;
        /*-- add you code for tos_network_get_hardware_status here --*/
    }

    fpi_error tos_network_wire_connect( E_NETWORK_CONNECT_TYPE type, st_wire_network_info* info ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wire_connect here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
      
            //#error not support this type of paramter E_NETWORK_CONNECT_TYPE type yet, please add code yourself
             data.writeInt32(type);
            //#error not support un-plat struct info yet, please add code yourself
            //#if your struct is plat, do not mark it as a struct
              if (info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_wire_network_info));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _value_wblob;
                data.writeBlob(sizeof(st_wire_network_info),&_value_wblob);
                memcpy(_value_wblob.data(),info,(sizeof(st_wire_network_info)));
            }
			
            _binder->transact(TRANSACTION_tos_network_wire_connect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wire_connect error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wire_connect error");
        }

        return _result;
        /*-- add you code for tos_network_wire_connect here --*/
    }

    fpi_error tos_network_wire_get_connect_type( E_NETWORK_CONNECT_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wire_get_connect_type here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter E_NETWORK_CONNECT_TYPE type yet, please add code yourself
            if (type == NULL) {
                data.writeInt32(-1);
             }
            else {
                data.writeInt32( sizeof(E_NETWORK_CONNECT_TYPE));//write length, only support 32 bits length yet
                
            }
			
            _binder->transact(TRANSACTION_tos_network_wire_get_connect_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

               // #error not support this type of output paramter E_NETWORK_CONNECT_TYPE type yet, please add code yourself

                if (type != NULL) {
                    int32_t _type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _type_rblob;
                    reply.readBlob(_type_len,&_type_rblob);
                    memcpy(type,_type_rblob.data(),_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value
                
                if((type != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *type = E_NETWORK_AUTO;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wire_get_connect_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wire_get_connect_type error");
        }

        return _result;
        /*-- add you code for tos_network_wire_get_connect_type here --*/
    }

    fpi_error tos_network_get_connect_status( EN_NETWORK_TYPE network_type, int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_connect_status here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
           data.writeInt32(network_type);
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_network_get_connect_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int32_t _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((value != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *value = 0;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_connect_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_connect_status error");
        }

        return _result;
        /*-- add you code for tos_network_get_connect_status here --*/
    }

    fpi_error tos_network_get_current_speed( EN_NETWORK_TYPE network_type, char* speed, int32_t size ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_current_speed here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_NETWORK_TYPE network_type yet, please add code yourself
             data.writeInt32(network_type);
            //for out only, only write length ; for in, alloc and copy
            if (speed == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(size);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_network_get_current_speed,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (speed != NULL) {
                    int32_t _speed_len = reply.readInt32(); //read length, only 32bits length support yet

                    if(0 < _speed_len) {
                        int32_t str_len;
                        Parcel::ReadableBlob _speed_rblob;
                        
                        reply.readBlob(_speed_len,&_speed_rblob);
                        str_len = strlen((char*)_speed_rblob.data());
                        str_len = str_len > (_speed_len-1)? (_speed_len-1): str_len;
                        //memcpy(speed,_speed_rblob.data(),_speed_len);
                        strncpy(speed,(char*)_speed_rblob.data(),str_len);
                        speed[size-1] = '\0';
                    }
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((speed != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    speed[0] = '\0';
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_current_speed error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_current_speed error");
        }

        return _result;
        /*-- add you code for tos_network_get_current_speed here --*/
    }

    fpi_error tos_network_wireless_get_current_signalquality( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_current_signalquality here --*/
        fpi_error _result = fpi_false;
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

            _binder->transact(TRANSACTION_tos_network_wireless_get_current_signalquality,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int32_t _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((value != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *value = 0;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_current_signalquality error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_current_signalquality error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_current_signalquality here --*/
    }

    fpi_error tos_network_wireless_get_current_signalstrength( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_current_signalstrength here --*/
        fpi_error _result = fpi_false;
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

            _binder->transact(TRANSACTION_tos_network_wireless_get_current_signalstrength,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int32_t _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((value != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *value = 0;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_current_signalstrength error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_current_signalstrength error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_current_signalstrength here --*/
    }

    fpi_error tos_network_wireless_get_encryption_mode( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_encryption_mode here --*/
        fpi_error _result = fpi_false;
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

            _binder->transact(TRANSACTION_tos_network_wireless_get_encryption_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int32_t _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((value != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    *value = 0;
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_encryption_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_encryption_mode error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_encryption_mode here --*/
    }

    fpi_error tos_network_wireless_get_encrypt_algorithm( char* encrypt_data, int32_t size ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_encrypt_algorithm here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (encrypt_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(size);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_network_wireless_get_encrypt_algorithm,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (encrypt_data != NULL) {
                    int32_t str_len;
                    int _encrypt_data_len = reply.readInt32(); //read length, only 32bits length support yet
                    if(0 < _encrypt_data_len) {
                        Parcel::ReadableBlob _encrypt_data_rblob;
                        reply.readBlob(_encrypt_data_len,&_encrypt_data_rblob);
                        str_len = strlen((char*)_encrypt_data_rblob.data());
                        str_len= str_len > (size-1) ? (size-1): str_len;
                        //memcpy(encrypt_data,_encrypt_data_rblob.data(),(_encrypt_data_len>size?size:_encrypt_data_len)+1);
                        strncpy(encrypt_data,(char*)_encrypt_data_rblob.data(),str_len);
                        encrypt_data[size-1] = '\0';
                    }
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((encrypt_data != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    encrypt_data[0] = '\0';
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_encrypt_algorithm error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_encrypt_algorithm error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_encrypt_algorithm here --*/
    }

    fpi_error tos_network_wireless_get_channel( int32_t* channel, char* freq ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_channel here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (channel == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (freq == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_network_wireless_get_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (channel != NULL) {
                    int32_t _channel_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _channel_rblob;
                    reply.readBlob(_channel_len,&_channel_rblob);
                    memcpy(channel,_channel_rblob.data(),_channel_len);
                }
                if (freq != NULL) {
                    int32_t _freq_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _freq_rblob;
                    reply.readBlob(_freq_len,&_freq_rblob);
                    memcpy(freq,_freq_rblob.data(),_freq_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(channel != NULL)
                    {
                        *channel = 0;
                    }
                    if(freq != NULL)
                    {
                        freq[0] = '\0';
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_channel error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_channel error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_channel here --*/
    }

    fpi_error tos_network_wireless_get_ap_count( int32_t* ap_data ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_ap_count here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ap_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_network_wireless_get_ap_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ap_data != NULL) {
                    int32_t _ap_data_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ap_data_rblob;
                    reply.readBlob(_ap_data_len,&_ap_data_rblob);
                    memcpy(ap_data,_ap_data_rblob.data(),_ap_data_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(ap_data != NULL)
                    {
                        *ap_data = 0;
                    }
                }

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_ap_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_ap_count error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_ap_count here --*/
    }

    fpi_error tos_network_wireless_start_scan(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_start_scan here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_start_scan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_start_scan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_start_scan error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_start_scan here --*/
    }

    fpi_error tos_network_wireless_stop_scan(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_stop_scan here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_stop_scan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_stop_scan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_stop_scan error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_stop_scan here --*/
    }

    fpi_error tos_network_wireless_get_ap_list( int32_t onePageApCount, int32_t pageIndex, st_wireless_network_info* pwireless_info, int* pAvailableCount ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_ap_list here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(onePageApCount);  //int32_t as input paramter

            data.writeInt32(pageIndex);  //int32_t as input paramter

           // #error not support this type of paramter st_wireless_network_info pwireless_info yet, please add code yourself
                        //for out only, only write length ; for in, alloc and copy
            if (pwireless_info == NULL) {
                //data.writeInt32(-1);
                return BAD_VALUE;
            }
			/*
            else {
                data.writeInt32(sizeof(st_wireless_network_info));//write length, only support 32 bits length yet
            }
		   */
            //for out only, only write length ; for in, alloc and copy
            if (pAvailableCount == NULL) {
                //data.writeInt32(-1);
                return BAD_VALUE;
            }
            /*
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }
            */

            data.writeInt32( onePageApCount* sizeof(st_wireless_network_info));
            
            _binder->transact(TRANSACTION_tos_network_wireless_get_ap_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
                //#error not support this type of output paramter st_wireless_network_info pwireless_info yet, please add code yourself
                int32_t AvailableInfoSize = reply.readInt32();
                Parcel::ReadableBlob _pwireless_info_rblob;
                reply.readBlob(AvailableInfoSize,&_pwireless_info_rblob);
                memcpy(pwireless_info,_pwireless_info_rblob.data(), AvailableInfoSize);
				
                *pAvailableCount = reply.readInt32(); //read length, only 32bits length support yet
                //#error not support this type of return yet, please add code for 'tos_network_wireless_get_ap_list' yourself
                
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(pwireless_info != NULL)
                    {
                        memset(pwireless_info,0, onePageApCount* sizeof(st_wireless_network_info));
                    }
                    if(pAvailableCount != NULL)
                    {
                        *pAvailableCount = 0;
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_ap_list error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_ap_list error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_ap_list here --*/
    }

    fpi_error tos_network_wireless_get_last_connect_ap_info( st_ap_info* api_ap_info ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_last_connect_ap_info here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter st_ap_info api_ap_info yet, please add code yourself
             if (api_ap_info == NULL) {
                data.writeInt32(-1);
             }
            else {
                data.writeInt32( sizeof(st_ap_info));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_tos_network_wireless_get_last_connect_ap_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

              //  #error not support this type of output paramter st_ap_info api_ap_info yet, please add code yourself
                if (api_ap_info != NULL) {
                    int32_t _api_ap_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _api_ap_info_rblob;
                    reply.readBlob(_api_ap_info_len,&_api_ap_info_rblob);
                    memcpy(api_ap_info,_api_ap_info_rblob.data(),_api_ap_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if((api_ap_info != NULL)&&(FPI_ERROR_FAIL == _result))
                {
                    memset(api_ap_info,0,sizeof(st_ap_info));
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_last_connect_ap_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_last_connect_ap_info error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_last_connect_ap_info here --*/
    }

    fpi_error tos_network_wireless_connect_manual( char* ssid, char* psw, API_WIFI_SECURITY_TYPE SECURITY, char* encryption ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_connect_manual here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ssid == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(strlen(ssid)+1);//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _ssid_wblob;
                data.writeBlob(strlen(ssid)+1,&_ssid_wblob);
                memcpy(_ssid_wblob.data(), ssid,strlen(ssid)+1);
            }

            //for out only, only write length ; for in, alloc and copy
            if (psw == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(strlen(psw)+1);//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _psw_wblob;
                data.writeBlob(strlen(psw)+1,&_psw_wblob);
                memcpy(_psw_wblob.data(),psw,strlen(psw)+1);
            }

            //#error not support this type of paramter API_WIFI_SECURITY_TYPE SECURITY yet, please add code yourself
            data.writeInt32(SECURITY);
            //for out only, only write length ; for in, alloc and copy
            if (encryption == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(strlen(encryption)+1);//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _encryption_wblob;
                data.writeBlob(strlen(encryption)+1,&_encryption_wblob);
                memcpy(_encryption_wblob.data(),encryption,strlen(encryption)+1);
            }

            _binder->transact(TRANSACTION_tos_network_wireless_connect_manual,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_manual error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_manual error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_connect_manual here --*/
    }

    fpi_error tos_network_wireless_connect_pbc(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_connect_pbc here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_connect_pbc,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_pbc error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_pbc error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_connect_pbc here --*/
    }

    fpi_error tos_network_wireless_abort_pbc(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_abort_pbc here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_abort_pbc,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_abort_pbc error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_abort_pbc error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_abort_pbc here --*/
    }

    fpi_error tos_network_wireless_connect_wps_pin( const char* pin_in, char* pin_out, int32_t out_size ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_connect_wps_pin here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pin_in == NULL) {
                data.writeInt32(0);
            }
            else {
                data.writeInt32(strlen(pin_in)+1);//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pin_in_wblob;
                data.writeBlob(strlen(pin_in)+1,&_pin_in_wblob);
                memcpy(_pin_in_wblob.data(),pin_in,strlen(pin_in)+1);
            }

            //for out only, only write length ; for in, alloc and copy
            if (pin_out == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(out_size);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_network_wireless_connect_wps_pin,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pin_out != NULL) {
                    int32_t _pin_out_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pin_out_rblob;
                    reply.readBlob(_pin_out_len,&_pin_out_rblob);
                    memcpy(pin_out,_pin_out_rblob.data(),_pin_out_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(pin_out != NULL)
                    {
                        pin_out[0] = '\0';
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_wps_pin error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_connect_wps_pin error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_connect_wps_pin here --*/
    }

    fpi_error tos_network_wireless_wps_pin_fresh( char* pin_out ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_wps_pin_fresh here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pin_out == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_network_wireless_wps_pin_fresh,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pin_out != NULL) {
                    int32_t _pin_out_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pin_out_rblob;
                    reply.readBlob(_pin_out_len,&_pin_out_rblob);
                    memcpy(pin_out,_pin_out_rblob.data(),_pin_out_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(pin_out != NULL)
                    {
                        pin_out[0] = '\0';
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_wps_pin_fresh error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_wps_pin_fresh error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_wps_pin_fresh here --*/
    }

    fpi_error tos_network_wireless_get_wps_pin( char* pin_out, int32_t size ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_get_wps_pin here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pin_out == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(size);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_network_wireless_get_wps_pin,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pin_out != NULL) {
                    int32_t _pin_out_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pin_out_rblob;
                    reply.readBlob(_pin_out_len,&_pin_out_rblob);
                    memcpy(pin_out,_pin_out_rblob.data(),(_pin_out_len>size?size:_pin_out_len)+1);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(pin_out != NULL)
                    {
                        pin_out[0] = '\0';
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_wps_pin error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_get_wps_pin error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_get_wps_pin here --*/
    }

    fpi_error tos_network_wireless_miracast_start(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_miracast_start here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_miracast_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_miracast_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_miracast_start error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_miracast_start here --*/
    }

    fpi_error tos_network_wireless_miracast_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_wireless_miracast_stop here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_wireless_miracast_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_wireless_miracast_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_wireless_miracast_stop error");
        }

        return _result;
        /*-- add you code for tos_network_wireless_miracast_stop here --*/
    }

    fpi_error tos_network_get_info( st_wire_network_info* network_info ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_info here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter st_wire_network_info network_info yet, please add code yourself

	    if (network_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(st_wire_network_info));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_network_get_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

              //  #error not support this type of output paramter st_wire_network_info network_info yet, please add code yourself
                if (network_info != NULL) {
                    int32_t _network_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _network_info_rblob;
                    reply.readBlob(_network_info_len,&_network_info_rblob);
                    memcpy(network_info,_network_info_rblob.data(),_network_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(network_info != NULL)
                    {
                        memset(network_info, 0, sizeof(st_wire_network_info));
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_info error");
        }

        return _result;
        /*-- add you code for tos_network_get_info here --*/
    }

    fpi_error tos_network_local_connection_test(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_local_connection_test here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_local_connection_test,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_local_connection_test error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_local_connection_test error");
        }

        return _result;
        /*-- add you code for tos_network_local_connection_test here --*/
    }

    fpi_error tos_network_connection_test(  ) {
        Parcel data, reply;

        /*-- add you code for tos_network_connection_test here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_network_connection_test,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_connection_test error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_connection_test error");
        }

        return _result;
        /*-- add you code for tos_network_connection_test here --*/
    }

    fpi_error tos_network_set_enable( fpi_bool enable ) {
        Parcel data, reply;

        /*-- add you code for tos_network_set_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_network_set_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_set_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_set_enable error");
        }

        return _result;
        /*-- add you code for tos_network_set_enable here --*/
    }

    fpi_error tos_network_get_enable( fpi_bool* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter fpi_bool enable yet, please add code yourself
	    if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_tos_network_get_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

              //  #error not support this type of output paramter fpi_bool enable yet, please add code yourself
                if (enable != NULL) {
                    int32_t _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(enable != NULL)
                    {
                        *enable = fpi_false;
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_enable error");
        }

        return _result;
        /*-- add you code for tos_network_get_enable here --*/
    }

    fpi_error tos_network_set_select_pattern( E_NETWORK_CONNECT_TYPE connect_pattern ) {
        Parcel data, reply;

        /*-- add you code for tos_network_set_select_pattern here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_NETWORK_TYPE connect_pattern yet, please add code yourself
            data.writeInt32(connect_pattern);
            _binder->transact(TRANSACTION_tos_network_set_select_pattern,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_set_select_pattern error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_set_select_pattern error");
        }

        return _result;
        /*-- add you code for tos_network_set_select_pattern here --*/
    }

    fpi_error tos_network_get_select_pattern( E_NETWORK_CONNECT_TYPE* connect_pattern ) {
        Parcel data, reply;

        /*-- add you code for tos_network_get_select_pattern here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_NETWORK_TYPE connect_pattern yet, please add code yourself
	   
	     if (connect_pattern == NULL) {
                data.writeInt32(-1);
             }
            else {
                data.writeInt32( sizeof(E_NETWORK_CONNECT_TYPE));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_tos_network_get_select_pattern,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

               // #error not support this type of output paramter EN_NETWORK_TYPE connect_pattern yet, please add code yourself
                if (connect_pattern != NULL) {
                    int32_t _connect_pattern_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _connect_pattern_rblob;
                    reply.readBlob(_connect_pattern_len,&_connect_pattern_rblob);
                    memcpy(connect_pattern,_connect_pattern_rblob.data(), _connect_pattern_len);
                }
		 
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(FPI_ERROR_FAIL == _result)
                {
                    if(connect_pattern != NULL)
                    {
                        *connect_pattern = E_NETWORK_AUTO;
                    }
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_get_select_pattern error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_get_select_pattern error");
        }

        return _result;
        /*-- add you code for tos_network_get_select_pattern here --*/
    }

    fpi_error tos_network_change_notify( EN_NETWORK_CHANGE_TYPE type, int32_t reserved_data ) {
        Parcel data, reply;

        /*-- add you code for tos_network_change_notify here --*/
        fpi_error _result = FPI_ERROR_FAIL;;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_NETWORK_CHANGE_TYPE as input paramter

            data.writeInt32(reserved_data);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_network_change_notify,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_network_change_notify error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_network_change_notify error");
        }

        return _result;
        /*-- add you code for tos_network_change_notify here --*/
    }
};

sbinder_network_setting_client* sbinder_network_setting_client::_instance = NULL;

fpi_error tos_network_get_hardware_status( EN_NETWORK_TYPE network_type, int32_t* status ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_hardware_status(network_type, status);
}
fpi_error tos_network_wire_connect( E_NETWORK_CONNECT_TYPE type, st_wire_network_info* info ) {
    return sbinder_network_setting_client::Instance()->tos_network_wire_connect(type, info);
}
fpi_error tos_network_wire_get_connect_type( E_NETWORK_CONNECT_TYPE* type ) {
    return sbinder_network_setting_client::Instance()->tos_network_wire_get_connect_type(type);
}
fpi_error tos_network_get_connect_status( EN_NETWORK_TYPE network_type, int32_t* value ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_connect_status(network_type, value);
}
fpi_error tos_network_get_current_speed( EN_NETWORK_TYPE network_type, char* speed, int32_t size ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_current_speed(network_type, speed, size);
}
fpi_error tos_network_wireless_get_current_signalquality( int32_t* value ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_current_signalquality(value);
}
fpi_error tos_network_wireless_get_current_signalstrength( int32_t* value ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_current_signalstrength(value);
}
fpi_error tos_network_wireless_get_encryption_mode( int32_t* value ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_encryption_mode(value);
}
fpi_error tos_network_wireless_get_encrypt_algorithm( char* encrypt_data, int32_t size ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_encrypt_algorithm(encrypt_data, size);
}
fpi_error tos_network_wireless_get_channel( int32_t* channel, char* freq ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_channel(channel, freq);
}
fpi_error tos_network_wireless_get_ap_count( int32_t* ap_data ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_ap_count(ap_data);
}
fpi_error tos_network_wireless_start_scan(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_start_scan();
}
fpi_error tos_network_wireless_stop_scan(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_stop_scan();
}
fpi_error tos_network_wireless_get_ap_list( int32_t onePageApCount, int32_t pageIndex, st_wireless_network_info* pwireless_info, int* pAvailableCount ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_ap_list(onePageApCount, pageIndex, pwireless_info, pAvailableCount);
}
fpi_error tos_network_wireless_get_last_connect_ap_info( st_ap_info* api_ap_info ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_last_connect_ap_info(api_ap_info);
}
fpi_error tos_network_wireless_connect_manual( char* ssid, char* psw, API_WIFI_SECURITY_TYPE SECURITY, char* encryption ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_connect_manual(ssid, psw, SECURITY, encryption);
}
fpi_error tos_network_wireless_connect_pbc(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_connect_pbc();
}
fpi_error tos_network_wireless_abort_pbc(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_abort_pbc();
}
fpi_error tos_network_wireless_connect_wps_pin( const char* pin_in, char* pin_out, int32_t out_size ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_connect_wps_pin(pin_in, pin_out, out_size);
}
fpi_error tos_network_wireless_wps_pin_fresh( char* pin_out ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_wps_pin_fresh(pin_out);
}
fpi_error tos_network_wireless_get_wps_pin( char* pin_out, int32_t size ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_get_wps_pin(pin_out, size);
}
fpi_error tos_network_wireless_miracast_start(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_miracast_start();
}
fpi_error tos_network_wireless_miracast_stop(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_wireless_miracast_stop();
}
fpi_error tos_network_get_info( st_wire_network_info* network_info ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_info(network_info);
}
fpi_error tos_network_local_connection_test(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_local_connection_test();
}
fpi_error tos_network_connection_test(  ) {
    return sbinder_network_setting_client::Instance()->tos_network_connection_test();
}
fpi_error tos_network_set_enable( fpi_bool enable ) {
    return sbinder_network_setting_client::Instance()->tos_network_set_enable(enable);
}
fpi_error tos_network_get_enable( fpi_bool* enable ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_enable(enable);
}
fpi_error tos_network_set_select_pattern( E_NETWORK_CONNECT_TYPE connect_pattern ) {
    return sbinder_network_setting_client::Instance()->tos_network_set_select_pattern(connect_pattern);
}
fpi_error tos_network_get_select_pattern( E_NETWORK_CONNECT_TYPE* connect_pattern ) {
    return sbinder_network_setting_client::Instance()->tos_network_get_select_pattern(connect_pattern);
}
fpi_error tos_network_change_notify( EN_NETWORK_CHANGE_TYPE type, int32_t reserved_data ) {
    return sbinder_network_setting_client::Instance()->tos_network_change_notify(type, reserved_data);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
