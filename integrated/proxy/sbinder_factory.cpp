/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_factory.sidl
 */
 

#define LOG_TAG     "sbinder_factory"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>


#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_factory.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_FACTORY);



#define SERVICE_DESCRIPTOR                      "04bbca00-f882-11e4-912b-005056a84a3b"
#define SERVICE_NAME                            "sbinder_factory"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_factory_get_work_mode FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_factory_set_work_mode FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_factory_get_system_info FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_factory_get_version FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_factory_get_project_id FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_factory_set_project_id FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_factory_usb_clone FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_factory_usb_upgrade FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_factory_reset FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_factory_preset_channel FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_factory_get_preset_area FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_factory_get_power_on_mode FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_factory_set_power_on_mode FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_factory_get_picture_curve FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_factory_set_picture_curve FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_factory_get_sound_curve FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_factory_set_sound_curve FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_factory_get_ssc_setting FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_factory_set_ssc_setting FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_factory_get_overscan FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_factory_set_overscan FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_factory_get_wb_setting FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_factory_set_wb_setting FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_factory_record_ts_stream FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_factory_update_e_sticker FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_factory_test_device_id FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_factory_erase_ci_key FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_factory_get_func_enable FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_factory_set_func_enable FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_factory_get_dbc_setting FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_factory_set_dbc_setting FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_factory_get_light_sensor_setting FIRST_CALL_TRANSACTION + 32
#define TRANSACTION_tos_factory_set_light_sensor_setting FIRST_CALL_TRANSACTION + 33
#define TRANSACTION_tos_factory_set_power_on_logo FIRST_CALL_TRANSACTION + 34
#define TRANSACTION_tos_factory_get_ci_key_name FIRST_CALL_TRANSACTION + 35
#define TRANSACTION_tos_factory_get_statu FIRST_CALL_TRANSACTION + 36
#define TRANSACTION_tos_factory_set_statu FIRST_CALL_TRANSACTION + 37
#define TRANSACTION_tos_factory_get_t2_support_state FIRST_CALL_TRANSACTION + 38
#define TRANSACTION_tos_factory_set_t2_support_state FIRST_CALL_TRANSACTION + 39
#define TRANSACTION_tos_factory_get_product_info FIRST_CALL_TRANSACTION + 40
#define TRANSACTION_tos_factory_set_mute_color FIRST_CALL_TRANSACTION + 41
#define TRANSACTION_tos_factory_get_bluetooth_3d_state FIRST_CALL_TRANSACTION + 42
#define TRANSACTION_tos_factory_set_bluetooth_3d_sync_state FIRST_CALL_TRANSACTION + 43
#define TRANSACTION_tos_factory_get_current_operator_name FIRST_CALL_TRANSACTION + 44
#define TRANSACTION_tos_factory_set_operator_on_off FIRST_CALL_TRANSACTION + 45
#define TRANSACTION_tos_factory_get_10p_data FIRST_CALL_TRANSACTION + 46
#define TRANSACTION_tos_factory_set_10p_data FIRST_CALL_TRANSACTION + 47
#define TRANSACTION_tos_factory_reset_10p_data FIRST_CALL_TRANSACTION + 48
#define TRANSACTION_tos_factory_get_usb_state FIRST_CALL_TRANSACTION + 49
#define TRANSACTION_tos_factory_get_upgrade_file_number FIRST_CALL_TRANSACTION + 50
#define TRANSACTION_tos_factory_remote_pro FIRST_CALL_TRANSACTION + 51
//add by @hh with qiyx's modify
#define TRANSACTION_tos_factory_cmds_addcallback FIRST_CALL_TRANSACTION + 52	
#define TRANSACTION_tos_factory_cmds_removecallback FIRST_CALL_TRANSACTION + 53
#define TRANSACTION_tos_factory_erase_netflix FIRST_CALL_TRANSACTION + 54

//#define TRANSACTION_tos_faccmds_confirm FIRST_CALL_TRANSACTION + 54
#define TRANSACTION_tos_factory_get_panel_id FIRST_CALL_TRANSACTION + 55  //Amy
#define TRANSACTION_tos_factory_set_panel_id FIRST_CALL_TRANSACTION + 56  //Amy	
#define TRANSACTION_tos_factory_get_panel_name FIRST_CALL_TRANSACTION + 60  //Amy	
//add by @wujy's modify
#define TRANSACTION_tos_factory_wb_setting_init FIRST_CALL_TRANSACTION + 57
#define TRANSACTION_tos_factory_get_gamma_offset FIRST_CALL_TRANSACTION + 58
#define TRANSACTION_tos_factory_get_projectID_array FIRST_CALL_TRANSACTION + 59
//add by @hh with qiyx's modify
#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_msg_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;


#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_factory.h"
#include <sbinder/RemoteCallbackList.h>//add by @hh with qiyx's modify
//add by @hh with qiyx's modify
class sbinder_factory_service : public BBinder  
{  
private:
    static sbinder_factory_service* _instance;
    RemoteCallbackList _cbList;
    bool _first;

    sbinder_factory_service():_first(true){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_factory_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

    static int message_callback(TOS_FACCMDS_CMD_PARAM_S msg,void* userdata) {
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        int _result = 0;
        int size = rcbl->beginBroadcast();
        TOSLOGV(SERVICE_NAME"_service message_callback start");
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);

            if(binder != NULL) {
                Parcel data, reply;
                Parcel::WritableBlob blob;
                data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

	        	data.writeInt32((1) * sizeof(TOS_FACCMDS_CMD_PARAM_S));
	            Parcel::WritableBlob _param_wblob;
	            data.writeBlob((1) * sizeof(TOS_FACCMDS_CMD_PARAM_S),&_param_wblob);
	            memcpy(_param_wblob.data(), &msg, (1) * sizeof(TOS_FACCMDS_CMD_PARAM_S));					

				data.writeInt64((int64_t)userdata);
                
                binder->transact(TRANSACTION_CALLBACK_msg_callback, data, &reply, 0);

                if(reply.readExceptionCode() == 0) {//fix check
                    _result += reply.readInt32();//int as return value
                }
            }
        }
        rcbl->finishBroadcast();

        TOSLOGV(SERVICE_NAME"_service message_callback end");
        return _result;
    }
    

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_factory_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_debug(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_debug(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_factory_get_work_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_work_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

				

                //begin paramters list
            	EN_FAC_WORK_MODE e_work_mode = (EN_FAC_WORK_MODE)data.readInt32();

                int _ui1_mode_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* ui1_mode = NULL;
				

                Parcel::WritableBlob _ui1_mode_wblob;

                if(_ui1_mode_len > 0) {
                    reply->writeInt32(_ui1_mode_len);
                    reply->writeBlob(_ui1_mode_len,&_ui1_mode_wblob);
                    ui1_mode = (uint8_t*)_ui1_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ui1_mode = (uint8_t*)_ui1_mode_wblob.data();
                fpi_error _result = tos_factory_get_work_mode( e_work_mode, ui1_mode );

				reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_get_work_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_work_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_work_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_WORK_MODE e_work_mode = (EN_FAC_WORK_MODE)data.readInt32();

                uint8_t ui1_mode = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_work_mode( e_work_mode, ui1_mode );

                reply->writeInt32(_result);

                //-- end code for tos_factory_set_work_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_system_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_system_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_SYSTEM_INFO_TYPE e_info_type = (EN_FAC_SYSTEM_INFO_TYPE)data.readInt32();

                int _ps_info_len = data.readInt32(); //read length, only 32bits length support yet
                char* ps_info = NULL;

                Parcel::WritableBlob _ps_info_wblob;

                if(_ps_info_len > 0) {
                    reply->writeInt32(_ps_info_len);
                    reply->writeBlob(_ps_info_len,&_ps_info_wblob);
                    ps_info = (char*)_ps_info_wblob.data();
                }

                int32_t i4_len = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                ps_info = (char*)_ps_info_wblob.data();
				memset(ps_info,0,i4_len);//add by @hh with qiyx's modify
                fpi_error _result = tos_factory_get_system_info( e_info_type, ps_info, i4_len );

                reply->writeInt32(_result);

                //-- end code for tos_factory_get_system_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_version:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_version here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_FIRMWARE_TYPE e_fr_type = (EN_FAC_FIRMWARE_TYPE)data.readInt32();

                int _ps_version_len = data.readInt32(); //read length, only 32bits length support yet
                char* ps_version = NULL;

                Parcel::WritableBlob _ps_version_wblob;

                if(_ps_version_len > 0) {
                    reply->writeInt32(_ps_version_len);
                    reply->writeBlob(_ps_version_len,&_ps_version_wblob);
                    ps_version = (char*)_ps_version_wblob.data();
                }

                int32_t i4_len = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                ps_version = (char*)_ps_version_wblob.data();
                fpi_error _result = tos_factory_get_version( e_fr_type, ps_version, i4_len );

				reply->writeInt32(_result);

                //-- end code for tos_factory_get_version here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_project_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_project_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ui2_id_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* ui2_id = NULL;

                Parcel::WritableBlob _ui2_id_wblob;

                if(_ui2_id_len > 0) {
                    reply->writeInt32(_ui2_id_len);
                    reply->writeBlob(_ui2_id_len,&_ui2_id_wblob);
                    ui2_id = (uint16_t*)_ui2_id_wblob.data();
                }

                int _ui2_max_id_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* ui2_max_id = NULL;

                Parcel::WritableBlob _ui2_max_id_wblob;

                if(_ui2_max_id_len > 0) {
                    reply->writeInt32(_ui2_max_id_len);
                    reply->writeBlob(_ui2_max_id_len,&_ui2_max_id_wblob);
                    ui2_max_id = (uint16_t*)_ui2_max_id_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ui2_id = (uint16_t*)_ui2_id_wblob.data();
                ui2_max_id = (uint16_t*)_ui2_max_id_wblob.data();
                fpi_error _result = tos_factory_get_project_id( ui2_id, ui2_max_id );

                reply->writeInt32(_result);

                //-- end code for tos_factory_get_project_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_project_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_project_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t ui2_id = (uint16_t)data.readInt32();  //uint16_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_project_id( ui2_id );

                reply->writeInt32(_result);

                //-- end code for tos_factory_set_project_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_usb_clone:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_usb_clone here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_CLONE_DIRECTION e_direction = (EN_FAC_CLONE_DIRECTION)data.readInt32();

				EN_FAC_CLONE_CONTENT e_content = (EN_FAC_CLONE_CONTENT)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_usb_clone( e_direction, e_content );

                reply->writeInt32(_result);

                //-- end code for tos_factory_usb_clone here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_usb_upgrade:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_usb_upgrade here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_UPGRADE_TYPE e_upgrade_type = (EN_FAC_UPGRADE_TYPE)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_usb_upgrade( e_upgrade_type );

                reply->writeInt32(_result);

                //-- end code for tos_factory_usb_upgrade here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_reset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_reset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	EN_FAC_RESET_TYPE e_reset_type = (EN_FAC_RESET_TYPE)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_reset( e_reset_type );

                reply->writeInt32(_result);

                //-- end code for tos_factory_reset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_preset_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_preset_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_PRESET_AREA e_preset_area = (EN_FAC_PRESET_AREA)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_preset_channel( e_preset_area );

                reply->writeInt32(_result);

                //-- end code for tos_factory_preset_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_preset_area:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_preset_area here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FAC_PRESET_AREA* pe_preset_area = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    pe_preset_area = (EN_FAC_PRESET_AREA*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_preset_area( pe_preset_area );

                reply->writeInt32(_result);

                //-- end code for tos_factory_get_preset_area here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_power_on_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_power_on_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FAC_POWER_ON_MODE* e_power_mode = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    e_power_mode = (EN_FAC_POWER_ON_MODE*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_power_on_mode( e_power_mode );

                reply->writeInt32(_result);

                //-- end code for tos_factory_get_power_on_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_power_on_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_power_on_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_POWER_ON_MODE e_power_mode = (EN_FAC_POWER_ON_MODE)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_power_on_mode( e_power_mode );

                reply->writeInt32(_result);

                //-- end code for tos_factory_set_power_on_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_picture_curve:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_picture_curve here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_PICTURE_CURVE_TYPE e_curve_type = (EN_FAC_PICTURE_CURVE_TYPE)data.readInt32();
					
                int _pt_curve_len = data.readInt32(); //read length, only 32bits length support yet
                TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve = NULL;
                if(_pt_curve_len > 0) {
                    reply->writeInt32(_pt_curve_len);
                    Parcel::WritableBlob _pt_curve_wblob;
                    reply->writeBlob(_pt_curve_len,&_pt_curve_wblob);
                    pt_curve = (TOS_SERVICE_USER_NONLINEAR_CURVE_T*)_pt_curve_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_picture_curve( e_curve_type, pt_curve );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_picture_curve here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_picture_curve:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_picture_curve here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_PICTURE_CURVE_TYPE e_curve_type = (EN_FAC_PICTURE_CURVE_TYPE)data.readInt32();

                uint8_t ui1_item = (uint8_t)data.readInt32();  //uint8_t as input paramter

                uint8_t ui1_val = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_picture_curve( e_curve_type, ui1_item, ui1_val );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_picture_curve here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_sound_curve:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_sound_curve here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int _pt_curve_len = data.readInt32(); //read length, only 32bits length support yet
                TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve = NULL;
                if(_pt_curve_len > 0) {
                    reply->writeInt32(_pt_curve_len);
                    Parcel::WritableBlob _pt_curve_wblob;
                    reply->writeBlob(_pt_curve_len,&_pt_curve_wblob);
                    pt_curve = (TOS_SERVICE_USER_NONLINEAR_CURVE_T*)_pt_curve_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_sound_curve( pt_curve );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_sound_curve here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_sound_curve:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_sound_curve here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t ui1_curve_item = (uint8_t)data.readInt32();  //uint8_t as input paramter

                uint8_t ui1_val = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_sound_curve( ui1_curve_item, ui1_val );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_sound_curve here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_ssc_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_ssc_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_SSC_TYPE e_ssc_type = (EN_FAC_SSC_TYPE)data.readInt32();
				
				int _pt_ssc_arg_len = data.readInt32(); //read length, only 32bits length support yet
				TOS_FAC_SSC_SETTING_T* pt_ssc_arg = NULL;
				if(_pt_ssc_arg_len > 0) {
					reply->writeInt32(_pt_ssc_arg_len);
					Parcel::WritableBlob _pt_ssc_arg_wblob;
					reply->writeBlob(_pt_ssc_arg_len,&_pt_ssc_arg_wblob);
					pt_ssc_arg = (TOS_FAC_SSC_SETTING_T*)_pt_ssc_arg_wblob.data();
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_ssc_setting( e_ssc_type, pt_ssc_arg );
				
				reply->writeInt32(_result);
                //-- end code for tos_factory_get_ssc_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_ssc_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_ssc_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_SSC_TYPE e_ssc_type = (EN_FAC_SSC_TYPE)data.readInt32();

				int t_ssc_arg_len = data.readInt32();
				TOS_FAC_SSC_SETTING_T t_ssc_arg;

				if(t_ssc_arg_len > 0) {
					Parcel::ReadableBlob _t_ssc_arg_rblob;
                    data.readBlob(t_ssc_arg_len,&_t_ssc_arg_rblob);
					if( t_ssc_arg_len == sizeof(TOS_FAC_SSC_SETTING_T) )
					{
						memcpy(&t_ssc_arg,_t_ssc_arg_rblob.data(), t_ssc_arg_len );
					}
					else
					{
					    //to be done
                    }
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_ssc_setting( e_ssc_type, t_ssc_arg );

                reply->writeInt32(_result);

                //-- end code for tos_factory_set_ssc_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_overscan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_overscan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_OVERSCAN_ITEM e_item = (EN_FAC_OVERSCAN_ITEM)data.readInt32();

                int _i4_val_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* i4_val = NULL;

                Parcel::WritableBlob _i4_val_wblob;

                if(_i4_val_len > 0) {
                    reply->writeInt32(_i4_val_len);
                    reply->writeBlob(_i4_val_len,&_i4_val_wblob);
                    i4_val = (int32_t*)_i4_val_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                i4_val = (int32_t*)_i4_val_wblob.data();
                fpi_error _result = tos_factory_get_overscan( e_item, i4_val );

				reply->writeInt32(_result);

                //-- end code for tos_factory_get_overscan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_overscan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_overscan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_OVERSCAN_ITEM e_item = (EN_FAC_OVERSCAN_ITEM)data.readInt32();

                uint8_t ui1_val = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_overscan( e_item, ui1_val );

				reply->writeInt32(_result);

                //-- end code for tos_factory_set_overscan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_wb_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_wb_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_COLOR_TEMP e_color_temp = (EN_FAC_COLOR_TEMP)data.readInt32();
			
				int _pt_wb_len = data.readInt32(); //read length, only 32bits length support yet
				TOS_FAC_WHITE_BALANCE_T* pt_wb = NULL;
				if(_pt_wb_len  > 0) {
					reply->writeInt32(_pt_wb_len );
					Parcel::WritableBlob _pt_wb_wblob;
					reply->writeBlob(_pt_wb_len ,&_pt_wb_wblob);
					pt_wb  = (TOS_FAC_WHITE_BALANCE_T*)_pt_wb_wblob.data();
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_wb_setting( e_color_temp, pt_wb );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_wb_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_wb_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_wb_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	EN_FAC_COLOR_TEMP e_color_temp = (EN_FAC_COLOR_TEMP)data.readInt32();
			
                EN_FAC_WB_ITEM curve_item = (EN_FAC_WB_ITEM)data.readInt32();  //int8_t as input paramter

                int32_t value = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_wb_setting( e_color_temp, curve_item, value );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_wb_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_record_ts_stream:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_record_ts_stream here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_record_ts_stream(  );

				reply->writeInt32(_result);
                //-- end code for tos_factory_record_ts_stream here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_update_e_sticker:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_update_e_sticker here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_update_e_sticker(  );

				reply->writeInt32(_result);
                //-- end code for tos_factory_update_e_sticker here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_test_device_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_test_device_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
       
				int _len = data.readInt32(); //read length, only 32bits length support yet
				fpi_bool* b_success = NULL;
				if(_len  > 0) {
					reply->writeInt32(_len );
					Parcel::WritableBlob _wblob;
					reply->writeBlob(_len ,&_wblob);
					b_success = (fpi_bool*)_wblob.data();
				}
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_test_device_id( b_success );

				reply->writeInt32(_result);
                //-- end code for tos_factory_test_device_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_erase_ci_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_erase_ci_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_erase_ci_key(  );
				
				reply->writeInt32(_result);
                //-- end code for tos_factory_erase_ci_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_func_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_func_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_FUNC_TYPE e_fun_type = (EN_FAC_FUNC_TYPE)data.readInt32();
				
				int _len = data.readInt32(); //read length, only 32bits length support yet
				fpi_bool* b_enable = NULL;
				if(_len  > 0) {
					reply->writeInt32(_len );
					Parcel::WritableBlob _wblob;
					reply->writeBlob(_len ,&_wblob);
					b_enable = (fpi_bool*)_wblob.data();
				}
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_func_enable( e_fun_type, b_enable );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_func_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_func_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_func_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_FUNC_TYPE e_fun_type = (EN_FAC_FUNC_TYPE)data.readInt32();

				fpi_bool b_enable = (fpi_bool)data.readInt32();
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_func_enable( e_fun_type, b_enable );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_func_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_dbc_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_dbc_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int _pt_dbc_setting_len = data.readInt32(); //read length, only 32bits length support yet
				TOS_FAC_DBC_SETTING_T* pt_dbc_setting = NULL;
				if(_pt_dbc_setting_len  > 0) {
					reply->writeInt32(_pt_dbc_setting_len );
					Parcel::WritableBlob _pt_dbc_setting_wblob;
					reply->writeBlob(_pt_dbc_setting_len ,&_pt_dbc_setting_wblob);
					pt_dbc_setting  = (TOS_FAC_DBC_SETTING_T*)_pt_dbc_setting_wblob.data();
				}
	
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_dbc_setting( pt_dbc_setting );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_dbc_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_dbc_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_dbc_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int t_dbc_setting_len = data.readInt32();
				TOS_FAC_DBC_SETTING_T t_dbc_setting;

				if(t_dbc_setting_len > 0) {
					Parcel::ReadableBlob _t_dbc_setting_rblob;
                    data.readBlob(t_dbc_setting_len,&_t_dbc_setting_rblob);
					if( t_dbc_setting_len == sizeof(TOS_FAC_DBC_SETTING_T) )
					{
						memcpy(&t_dbc_setting,_t_dbc_setting_rblob.data(), t_dbc_setting_len);
					}
					else
					{
					    //to be done
                    }
				}
				
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_dbc_setting( t_dbc_setting );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_dbc_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_light_sensor_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_light_sensor_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list 
				int _pt_sensor_arg_len = data.readInt32(); //read length, only 32bits length support yet
				TOS_FAC_LIGHT_SENSOR_ARG_T* pt_sensor_arg = NULL;
				if(_pt_sensor_arg_len  > 0) {
					reply->writeInt32(_pt_sensor_arg_len);
					Parcel::WritableBlob _pt_sensor_arg_wblob;
					reply->writeBlob(_pt_sensor_arg_len ,&_pt_sensor_arg_wblob);
					pt_sensor_arg  = (TOS_FAC_LIGHT_SENSOR_ARG_T*)_pt_sensor_arg_wblob.data();
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_light_sensor_setting( pt_sensor_arg );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_light_sensor_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_light_sensor_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_light_sensor_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int t_sensor_arg_len = data.readInt32();
				TOS_FAC_LIGHT_SENSOR_ARG_T t_sensor_arg;

				if(t_sensor_arg_len > 0) {
					Parcel::ReadableBlob _t_sensor_arg_rblob;
                    data.readBlob(t_sensor_arg_len,&_t_sensor_arg_rblob);
					if( t_sensor_arg_len == sizeof(TOS_FAC_LIGHT_SENSOR_ARG_T) )
					{
						memcpy(&t_sensor_arg,_t_sensor_arg_rblob.data(), t_sensor_arg_len);
					}
					else
					{
					    //to be done
                    }
				}
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_light_sensor_setting( t_sensor_arg );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_light_sensor_setting here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_power_on_logo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_power_on_logo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_power_on_logo(  );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_power_on_logo here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_ci_key_name:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_ci_key_name here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ps_name_len = data.readInt32(); //read length, only 32bits length support yet
                char* ps_name = NULL;

                Parcel::WritableBlob _ps_name_wblob;

                if(_ps_name_len > 0) {
                    reply->writeInt32(_ps_name_len);
                    reply->writeBlob(_ps_name_len,&_ps_name_wblob);
                    ps_name = (char*)_ps_name_wblob.data();
                }

                int32_t i4_ret = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                ps_name = (char*)_ps_name_wblob.data();
				memset(ps_name,0,_ps_name_len);
				
                fpi_error _result = tos_factory_get_ci_key_name( ps_name, i4_ret );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_ci_key_name here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_statu:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_statu here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_QUERY_TYPE e_type = (EN_FAC_QUERY_TYPE)data.readInt32();
       
				int _len = data.readInt32(); //read length, only 32bits length support yet
				fpi_bool* b_state = NULL;
				if(_len  > 0) {
					reply->writeInt32(_len );
					Parcel::WritableBlob _wblob;
					reply->writeBlob(_len ,&_wblob);
					b_state = (fpi_bool*)_wblob.data();
				}
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_statu( e_type, b_state );
			
				reply->writeInt32(_result);
                //-- end code for tos_factory_get_statu here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_statu:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_statu here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_FAC_QUERY_TYPE e_type = (EN_FAC_QUERY_TYPE)data.readInt32();

				fpi_bool b_state = (fpi_bool)data.readInt32();
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_statu( e_type, b_state );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_statu here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_t2_support_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_t2_support_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int _value_len = data.readInt32();
				EN_T2_SUPPORT_STATE* pe_state = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    pe_state = (EN_T2_SUPPORT_STATE*)_value_wblob.data();
                }				
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_t2_support_state( pe_state );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_t2_support_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_t2_support_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_t2_support_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_T2_SUPPORT_STATE e_state = (EN_T2_SUPPORT_STATE)data.readInt32();
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_t2_support_state( e_state );

				reply->writeInt32(_result);
                //-- end code for tos_factory_set_t2_support_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_product_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_product_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				int _value_len = data.readInt32();
				fac_product_info_data_t* pt_info = NULL;
				if(_value_len > 0) 
				{
					reply->writeInt32(_value_len);
					Parcel::WritableBlob _value_wBlob;
					reply->writeBlob(_value_len, &_value_wBlob);
					pt_info = (fac_product_info_data_t*)_value_wBlob.data();
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_get_product_info( pt_info );

				reply->writeInt32(_result);
                //-- end code for tos_factory_get_product_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			case TRANSACTION_tos_factory_set_mute_color:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_project_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				
                //begin paramters list
                uint32_t ui4_color = (uint32_t)data.readInt32();  //uint16_t as input paramter

				fpi_bool b_mute = (fpi_bool)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_mute_color(ui4_color, b_mute);

                reply->writeInt32(_result);

                //-- end code for tos_factory_set_project_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			case TRANSACTION_tos_factory_get_bluetooth_3d_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_bluetooth_3d_sync_state here, will auoto generated but may change yourself if need --
				
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				EN_TOS_FAC_BLUETOOTH_STATE_TYPE e_type = (EN_TOS_FAC_BLUETOOTH_STATE_TYPE)data.readInt32();
				
                int _ui1_state_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* ui1_state = NULL;

                Parcel::WritableBlob _ui1_state_wblob;

                if(_ui1_state_len > 0) {
                    reply->writeInt32(_ui1_state_len);
                    reply->writeBlob(_ui1_state_len,&_ui1_state_wblob);
                    ui1_state = (uint8_t*)_ui1_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ui1_state = (uint8_t*)_ui1_state_wblob.data();
                fpi_error _result = tos_factory_get_bluetooth_3d_state( e_type, ui1_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_get_bluetooth_3d_sync_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_bluetooth_3d_sync_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_bluetooth_3d_sync_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_FAC_BLUETOOTH_STATE_TYPE e_type = (EN_TOS_FAC_BLUETOOTH_STATE_TYPE)data.readInt32();
                uint8_t ui1_state = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_bluetooth_3d_state(e_type, ui1_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_set_bluetooth_3d_sync_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_current_operator_name:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_current_operator_name here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ui1_operator_name_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* ui1_operator_name = NULL;

                Parcel::WritableBlob _ui1_operator_name_wblob;

                if(_ui1_operator_name_len > 0) {
                    reply->writeInt32(_ui1_operator_name_len);
                    reply->writeBlob(_ui1_operator_name_len,&_ui1_operator_name_wblob);
                    ui1_operator_name = (uint8_t*)_ui1_operator_name_wblob.data();
                }

				// re-get all pointers from blob to fix realloc issue in Parcel
				ui1_operator_name = (uint8_t*)_ui1_operator_name_wblob.data();
				memset(ui1_operator_name,0,_ui1_operator_name_len);//add by @hh with qiyx's modify
				fpi_error _result = tos_factory_get_current_operator_name( ui1_operator_name );
				// fpi_error _result = 0;
				//	memset(ui1_operator_name,0,128);

				reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_get_current_operator_name here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_operator_on_off:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_operator_on_off here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool b_flag = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_set_operator_on_off( b_flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_set_operator_on_off here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            case TRANSACTION_tos_factory_get_10p_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_10p_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pt_data_len = data.readInt32(); //read length, only 32bits length support yet
                TOS_TEN_P_DATA_T* pt_data = NULL;

                Parcel::WritableBlob _pt_data_wblob;

                if(_pt_data_len > 0) {
                    reply->writeInt32(_pt_data_len);
                    reply->writeBlob(_pt_data_len,&_pt_data_wblob);
                    pt_data = (TOS_TEN_P_DATA_T*)_pt_data_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pt_data = (TOS_TEN_P_DATA_T*)_pt_data_wblob.data();
                fpi_error _result = tos_factory_get_10p_data( pt_data );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_get_10p_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_set_10p_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_set_10p_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pt_data_len = data.readInt32(); //read length, only 32bits length support yet
                TOS_TEN_P_DATA_T* pt_data = NULL;

                Parcel::ReadableBlob _pt_data_rblob;

                if(_pt_data_len > 0) {
                    data.readBlob(_pt_data_len,&_pt_data_rblob);
                    pt_data = (TOS_TEN_P_DATA_T*)_pt_data_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pt_data = (TOS_TEN_P_DATA_T*)_pt_data_rblob.data();
                fpi_error _result = tos_factory_set_10p_data( pt_data );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_set_10p_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_reset_10p_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_reset_10p_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_reset_10p_data(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_reset_10p_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            case TRANSACTION_tos_factory_get_usb_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_usb_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _b_value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* b_value = NULL;

                Parcel::WritableBlob _b_value_wblob;

                if(_b_value_len > 0) {
                    reply->writeInt32(_b_value_len);
                    reply->writeBlob(_b_value_len,&_b_value_wblob);
                    b_value = (fpi_bool*)_b_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                b_value = (fpi_bool*)_b_value_wblob.data();
                fpi_error _result = tos_factory_get_usb_state( b_value );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_get_usb_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_get_upgrade_file_number:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_upgrade_file_number here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _ui1_number_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* ui1_number = NULL;

                Parcel::WritableBlob _ui1_number_wblob;

                if(_ui1_number_len > 0) {
                    reply->writeInt32(_ui1_number_len);
                    reply->writeBlob(_ui1_number_len,&_ui1_number_wblob);
                    ui1_number = (uint8_t*)_ui1_number_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ui1_number = (uint8_t*)_ui1_number_wblob.data();
                fpi_error _result = tos_factory_get_upgrade_file_number( ui1_number );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_get_upgrade_file_number here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_factory_remote_pro:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_remote_pro here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int ui4_key_code = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_factory_remote_pro( ui4_key_code );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_factory_remote_pro here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			//add by @hh with qiyx's modify
            case TRANSACTION_tos_factory_cmds_addcallback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for cb_add here, will auoto generated but may change yourself if need --
                
                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
                
                sp<IBinder> binder = data.readStrongBinder();

                if(binder != NULL) {

                    int _result = FPI_ERROR_SUCCESS;

					void *userdata = (void *)data.readInt64();
                        
                    if(_first) {
                        _result = tos_factory_cmds_addcallback(sbinder_factory_service::message_callback, userdata);
                        if(_result == FPI_ERROR_SUCCESS) {
                            _first = false;
                        }
                    }

                    if(_result == FPI_ERROR_SUCCESS) {
                        if(_cbList.registerCallback(binder,NULL)) {
                            reply->writeNoException();
                            reply->writeInt32(_result); //int as return value
                        }
                        else {
                            reply->writeInt32(-3);//Exception
                        }
                    }
                    else {
                        reply->writeInt32(-2);//Exception
                    }
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                //-- end code for cb_add here --
            	fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            }break;
			//add by @hh with qiyx's modify
            case TRANSACTION_tos_factory_cmds_removecallback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check


                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //-- begin code for cb_add here, will auoto generated but may change yourself if need --
                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                //-- end code for cb_add here --      
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            }break;
/*          
            case TRANSACTION_tos_faccmds_confirm:
            {
            }break;
*/          case TRANSACTION_tos_factory_erase_netflix:            
            {                
               data.enforceInterface(String16(SERVICE_NAME));  //fixed check                
               //-- begin code for tos_factory_erase_netflix here, will auoto generated but may change yourself if need --  
               //skip Exception and result first to write output paramters                
               reply->writeNoException();               
               //skip Exception and result first end               
               //begin paramters list               
               // re-get all pointers from blob to fix realloc issue in Parcel                
               fpi_error _result = tos_factory_erase_netflix();               
               reply->writeInt32(_result); //fpi_error as return value                
               //-- end code for tos_factory_erase_netflix here --                
               fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            
            } break;
//====Amy Start for PANEL ID ===================================================
			case TRANSACTION_tos_factory_get_panel_id:
			{
				data.enforceInterface(String16(SERVICE_NAME));	//fixed check

				//-- begin code for tos_factory_get_panel_id here, will auoto generated but may change yourself if need --

				//skip Exception and result first to write output paramters
				reply->writeNoException();
				//skip Exception and result first end

				//begin paramters list
				int _ui2_id_len = data.readInt32(); //read length, only 32bits length support yet
				uint16_t* ui2_id = NULL;

				Parcel::WritableBlob _ui2_id_wblob;

				if(_ui2_id_len > 0) {
					reply->writeInt32(_ui2_id_len);
					reply->writeBlob(_ui2_id_len,&_ui2_id_wblob);
					ui2_id = (uint16_t*)_ui2_id_wblob.data();
				}

				int _ui2_max_id_len = data.readInt32(); //read length, only 32bits length support yet
				uint16_t* ui2_max_id = NULL;

				Parcel::WritableBlob _ui2_max_id_wblob;

				if(_ui2_max_id_len > 0) {
					reply->writeInt32(_ui2_max_id_len);
					reply->writeBlob(_ui2_max_id_len,&_ui2_max_id_wblob);
					ui2_max_id = (uint16_t*)_ui2_max_id_wblob.data();
				}

				// re-get all pointers from blob to fix realloc issue in Parcel
				ui2_id = (uint16_t*)_ui2_id_wblob.data();
				ui2_max_id = (uint16_t*)_ui2_max_id_wblob.data();
				fpi_error _result = tos_factory_get_panel_id( ui2_id, ui2_max_id );

				reply->writeInt32(_result);

				//-- end code for tos_factory_get_panel_id here --
				               fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            

			} break;

			case TRANSACTION_tos_factory_set_panel_id:
			{
				data.enforceInterface(String16(SERVICE_NAME));	//fixed check

				//-- begin code for tos_factory_set_panel_id here, will auoto generated but may change yourself if need --

				//skip Exception and result first to write output paramters
				reply->writeNoException();
				//skip Exception and result first end

				//begin paramters list
				uint16_t ui2_id = (uint16_t)data.readInt32();  //uint16_t as input paramter

				// re-get all pointers from blob to fix realloc issue in Parcel
				fpi_error _result = tos_factory_set_panel_id( ui2_id );

				reply->writeInt32(_result);

				//-- end code for tos_factory_set_panel_id here --
				               fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            

			} break;

            case TRANSACTION_tos_factory_get_panel_name:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_ci_key_name here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _panelName_len = data.readInt32(); //read length, only 32bits length support yet
                char* panelName = NULL;

                Parcel::WritableBlob _panelName_wblob;

                if(_panelName_len > 0) {
                    reply->writeInt32(_panelName_len);
                    reply->writeBlob(_panelName_len,&_panelName_wblob);
                    panelName = (char*)_panelName_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                panelName = (char*)_panelName_wblob.data();
				memset(panelName,0,_panelName_len);
                fpi_error _result = tos_factory_get_panel_name( panelName );
				reply->writeInt32(_result);
                //-- end code for tos_factory_get_panel_name here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;			

//====Amy END for PANEL ID =====================================================
//====wujy START for WB init=====================================================
			case TRANSACTION_tos_factory_wb_setting_init:
			{
				fpi_info("wujy TRANSACTION_tos_factory_wb_setting_init");
				data.enforceInterface(String16(SERVICE_NAME));	//fixed check

				//-- begin code for tos_factory_wb_setting_init here, will auoto generated but may change yourself if need --

				//skip Exception and result first to write output paramters
				reply->writeNoException();
				//skip Exception and result first end

				//begin paramters list

				// re-get all pointers from blob to fix realloc issue in Parcel
				fpi_error _result = tos_factory_wb_setting_init();

				reply->writeInt32(_result);

				//-- end code for tos_factory_wb_setting_init here --
               fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;            

			} break;
//====wujy END for WB init=====================================================
			case TRANSACTION_tos_factory_get_gamma_offset:
			{
				fpi_info("TRANSACTION_tos_factory_get_gamma_offset\n");
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_gamma_offset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _offset_len = data.readInt32(); //read length, only 32bits length support yet
                int* offset = NULL;

                Parcel::WritableBlob _offset_wblob;

                if(_offset_len > 0) {
                    reply->writeInt32(_offset_len);
                    reply->writeBlob(_offset_len,&_offset_wblob);
                    offset = (int*)_offset_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                offset = (int*)_offset_wblob.data();
                fpi_error _result = tos_factory_get_gamma_offset( offset );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_get_gamma_offset here --
                return NO_ERROR;
			} break;
			case TRANSACTION_tos_factory_get_projectID_array:
			{   
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_factory_get_projectID_array here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _buf_len = data.readInt32(); //read length, only 32bits length support yet
                int* buf = NULL;

                Parcel::ReadableBlob _buf_rblob;

                Parcel::WritableBlob _buf_wblob;

                if(_buf_len > 0) {
                    data.readBlob(_buf_len,&_buf_rblob);

                    reply->writeInt32(_buf_len);
                    reply->writeBlob(_buf_len,&_buf_wblob);
                    buf = (int*)_buf_wblob.data();

                    memcpy(buf,_buf_rblob.data(),_buf_len);
                }                
				int _count_len = data.readInt32(); //read length, only 32bits length support yet
                int* count = NULL;

                Parcel::ReadableBlob _count_rblob;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    data.readBlob(_count_len,&_count_rblob);

                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (int*)_count_wblob.data();

                    memcpy(count,_count_rblob.data(),_count_len);
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                buf = (int*)_buf_wblob.data();
                count = (int*)_count_wblob.data();
                fpi_error _result = tos_factory_get_projectID_array( buf, count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_factory_get_projectID_array here --
                return NO_ERROR;
			} break;
			
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_debug(SERVICE_NAME"_service end");
    }
}; 

int sbinder_factory_service_add() {
    sbinder_factory_service::Instance();
    return 0;
}

sbinder_factory_service* sbinder_factory_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>//add by @hh with qiyx's modify
//add by @hh with qiyx's modify
class sbinder_factory_client  
{  
private:
    static sbinder_factory_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_factory_client()
        :_binder(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_factory_client() {
        TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    class Callback : public ICallbackList::ICallback {
    public:
        Callback(void* cb,void* cookie)
            :ICallback(cb,cookie) {
            _descriptor = String16(SERVICE_NAME"_callback");
        }

        ~Callback() {
        }

        virtual status_t onTransact( uint32_t code,
                const Parcel& data,Parcel* reply,uint32_t flags = 0) {
            TOSLOGV(SERVICE_NAME"_client onTransact code=%d\n",code);
            //__android_log_print(4,"sitatvservice", "_client onTransact code=%d\n",code);
            
            switch (code){
            case TRANSACTION_CALLBACK_msg_callback:
            {
                if (!data.checkInterface(this)) {
                    TOSLOGW(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }  

                if(_callback != NULL) {
					
                    int msg_length = data.readInt32(); 
                    TOS_FACCMDS_CMD_PARAM_S msg;
                    
                    if(msg_length > 0) {
                    	Parcel::ReadableBlob _msg_rblob;
                        data.readBlob(msg_length, &_msg_rblob);
						memcpy(&msg,_msg_rblob.data(),sizeof(TOS_FACCMDS_CMD_PARAM_S));
                    };

					void* userdata = (void *)data.readInt64();

                    int _result = ((tos_faccmds_oncommand)_callback)(msg, userdata);

                    reply->writeNoException();
                    reply->writeInt32(_result);
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                break;
            }

            default:
                return BBinder::onTransact(code, data, reply, flags);
            }

            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };
 
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
    static sbinder_factory_client* Instance() {
        if(_instance == NULL) {
            fpi_debug(SERVICE_NAME"_client Instance");
            _instance = new sbinder_factory_client();
        }

        return _instance;
    }

    fpi_error tos_factory_get_work_mode( EN_FAC_WORK_MODE e_work_mode, uint8_t* ui1_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_work_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_work_mode);

            //for out only, only write length ; for in, alloc and copy
            if (ui1_mode == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_work_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui1_mode != NULL) {
                    int _ui1_mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui1_mode_rblob;
                    reply.readBlob(_ui1_mode_len,&_ui1_mode_rblob);
                    memcpy(ui1_mode,_ui1_mode_rblob.data(),_ui1_mode_len);
                } 

				_result = (typeof(_result))reply.readInt32(); //int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_work_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_work_mode error");
        }

        return _result;
        /*-- add you code for tos_factory_get_work_mode here --*/
    }

    fpi_error tos_factory_set_work_mode( EN_FAC_WORK_MODE e_work_mode, uint8_t ui1_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_work_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_work_mode);

            data.writeInt32(ui1_mode);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_work_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32(); //int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_work_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_work_mode error");
        }

        return _result;
        /*-- add you code for tos_factory_set_work_mode here --*/
    }

    fpi_error tos_factory_get_system_info( EN_FAC_SYSTEM_INFO_TYPE e_info_type, char* ps_info, int32_t i4_len ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_system_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_info_type);

            //for out only, only write length ; for in, alloc and copy
            if (ps_info == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(i4_len) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(i4_len);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_get_system_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ps_info != NULL) {
                    int _ps_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ps_info_rblob;
                    reply.readBlob(_ps_info_len,&_ps_info_rblob);
                    memcpy(ps_info,_ps_info_rblob.data(),_ps_info_len);
                }

				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_system_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_system_info error");
        }

        return _result;
        /*-- add you code for tos_factory_get_system_info here --*/
    }

    fpi_error tos_factory_get_version( EN_FAC_FIRMWARE_TYPE e_fr_type, char* ps_version, int32_t i4_len ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_version here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_fr_type);

            //for out only, only write length ; for in, alloc and copy
            if (ps_version == NULL || i4_len <= 0) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(i4_len) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(i4_len);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_get_version,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ps_version != NULL) {
                    int _ps_version_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ps_version_rblob;
                    reply.readBlob(_ps_version_len,&_ps_version_rblob);
                    memcpy(ps_version,_ps_version_rblob.data(),_ps_version_len);
                } 
				
				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_version error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_version error");
        }

        return _result;
        /*-- add you code for tos_factory_get_version here --*/
    }

    fpi_error tos_factory_get_project_id( uint16_t* ui2_id, uint16_t* ui2_max_id ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_project_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ui2_id == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (ui2_max_id == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_project_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui2_id != NULL) {
                    int _ui2_id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_id_rblob;
                    reply.readBlob(_ui2_id_len,&_ui2_id_rblob);
                    memcpy(ui2_id,_ui2_id_rblob.data(),_ui2_id_len);
                }
                if (ui2_max_id != NULL) {
                    int _ui2_max_id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_max_id_rblob;
                    reply.readBlob(_ui2_max_id_len,&_ui2_max_id_rblob);
                    memcpy(ui2_max_id,_ui2_max_id_rblob.data(),_ui2_max_id_len);
                } 

				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_project_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_project_id error");
        }

        return _result;
        /*-- add you code for tos_factory_get_project_id here --*/
    }

    fpi_error tos_factory_set_project_id( uint16_t ui2_id ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_project_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui2_id);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_project_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_project_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_project_id error");
        }

        return _result;
        /*-- add you code for tos_factory_set_project_id here --*/
    }

    fpi_error tos_factory_usb_clone( EN_FAC_CLONE_DIRECTION e_direction, EN_FAC_CLONE_CONTENT e_content ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_usb_clone here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_direction);

			data.writeInt32(e_content);

            _binder->transact(TRANSACTION_tos_factory_usb_clone,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_usb_clone error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_usb_clone error");
        }

        return _result;
        /*-- add you code for tos_factory_usb_clone here --*/
    }

    fpi_error tos_factory_usb_upgrade( EN_FAC_UPGRADE_TYPE e_upgrade_type ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_usb_upgrade here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_upgrade_type);

            _binder->transact(TRANSACTION_tos_factory_usb_upgrade,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_usb_upgrade error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_usb_upgrade error");
        }

        return _result;
        /*-- add you code for tos_factory_usb_upgrade here --*/
    }

    fpi_error tos_factory_reset( EN_FAC_RESET_TYPE e_reset_type ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_reset here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_reset_type);

            _binder->transact(TRANSACTION_tos_factory_reset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_reset error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_reset error");
        }

        return _result;
        /*-- add you code for tos_factory_reset here --*/
    }

	fpi_error tos_factory_wb_setting_init(  ) {
        Parcel data, reply;
        /*-- add you code for tos_factory_wb_setting_init here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_wb_setting_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_wb_setting_init error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_wb_setting_init error");
        }

        return _result;
        /*-- add you code for tos_factory_wb_setting_init here --*/
    }
	fpi_error tos_factory_get_gamma_offset( int* offset ) {
		Parcel data, reply;
		/*-- add you code for tos_factory_get_gamma_offset here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (offset == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet

            }

            _binder->transact(TRANSACTION_tos_factory_get_gamma_offset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (offset != NULL) {
                    int _offset_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _offset_rblob;
                    reply.readBlob(_offset_len,&_offset_rblob);
                    memcpy(offset,_offset_rblob.data(),_offset_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_factory_get_gamma_offset error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_factory_get_gamma_offset error");
        }

        return _result;
        /*-- add you code for tos_factory_get_gamma_offset here --*/
	}
	fpi_error tos_factory_get_projectID_array( int* buf, int* count ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_projectID_array here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (buf == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(*count) * sizeof(int));//write length, only support 32 bits length yet

                Parcel::WritableBlob _buf_wblob;
                data.writeBlob((*count) * sizeof(int),&_buf_wblob);
                memcpy(_buf_wblob.data(),buf,(*count)* sizeof(int));
            }

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                Parcel::WritableBlob _count_wblob;
                data.writeBlob((1) * sizeof(int),&_count_wblob);
                memcpy(_count_wblob.data(),count,(1)* sizeof(int));

            }

            _binder->transact(TRANSACTION_tos_factory_get_projectID_array,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (buf != NULL) {
                    int _buf_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _buf_rblob;
                    reply.readBlob(_buf_len,&_buf_rblob);
                    memcpy(buf,_buf_rblob.data(),_buf_len);
                }
                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_factory_get_projectID_array error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_factory_get_projectID_array error");
        }

        return _result;
        /*-- add you code for tos_factory_get_projectID_array here --*/
    }
    fpi_error tos_factory_preset_channel( EN_FAC_PRESET_AREA e_preset_area ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_preset_channel here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_preset_area);

            _binder->transact(TRANSACTION_tos_factory_preset_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_preset_channel error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_preset_channel error");
        }

        return _result;
        /*-- add you code for tos_factory_preset_channel here --*/
    }

    fpi_error tos_factory_get_preset_area( EN_FAC_PRESET_AREA* pe_preset_area ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_preset_area here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pe_preset_area == NULL){
				return FPI_ERROR_FAIL;
			}
			else {
				data.writeInt32((int)1*sizeof(EN_FAC_PRESET_AREA));
			}

            _binder->transact(TRANSACTION_tos_factory_get_preset_area,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if(pe_preset_area != NULL) {
					int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(pe_preset_area,_value_rblob.data(),_value_len);
                }

				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_preset_area error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_preset_area error");
        }

        return _result;
        /*-- add you code for tos_factory_get_preset_area here --*/
    }

    fpi_error tos_factory_get_power_on_mode( EN_FAC_POWER_ON_MODE* e_power_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_power_on_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if(e_power_mode == NULL){
				return FPI_ERROR_FAIL;
			}
			else {
				data.writeInt32((int)1*sizeof(EN_FAC_POWER_ON_MODE));
			}

            _binder->transact(TRANSACTION_tos_factory_get_power_on_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if(e_power_mode != NULL) {
					int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(e_power_mode,_value_rblob.data(),_value_len);
                }

				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_power_on_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_power_on_mode error");
        }

        return _result;
        /*-- add you code for tos_factory_get_power_on_mode here --*/
    }

    fpi_error tos_factory_set_power_on_mode( EN_FAC_POWER_ON_MODE e_power_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_power_on_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_power_mode);

            _binder->transact(TRANSACTION_tos_factory_set_power_on_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_power_on_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_power_on_mode error");
        }

        return _result;
        /*-- add you code for tos_factory_set_power_on_mode here --*/
    }

    fpi_error tos_factory_get_picture_curve( EN_FAC_PICTURE_CURVE_TYPE e_curve_type, TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_picture_curve here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
       
			data.writeInt32(e_curve_type);
			
            data.writeInt32((int)1*sizeof(TOS_SERVICE_USER_NONLINEAR_CURVE_T));

            _binder->transact(TRANSACTION_tos_factory_get_picture_curve,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_curve != NULL) {
                    int _pt_curve_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_curve_rblob;
                    reply.readBlob(_pt_curve_len,&_pt_curve_rblob);
                    memcpy(pt_curve,_pt_curve_rblob.data(),_pt_curve_len);
                } 

				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_picture_curve error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_picture_curve error");
        }

        return _result;
        /*-- add you code for tos_factory_get_picture_curve here --*/
    }

    fpi_error tos_factory_set_picture_curve( EN_FAC_PICTURE_CURVE_TYPE e_curve_type, uint8_t ui1_item, uint8_t ui1_val ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_picture_curve here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_curve_type);
	
            data.writeInt32(ui1_item);  //uint8_t as input paramter

            data.writeInt32(ui1_val);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_picture_curve,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_picture_curve error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_picture_curve error");
        }

        return _result;
        /*-- add you code for tos_factory_set_picture_curve here --*/
    }

    fpi_error tos_factory_get_sound_curve( TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_sound_curve here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pt_curve == NULL) {
				return FPI_ERROR_FAIL;
			}else {
				data.writeInt32((int)1*sizeof(TOS_SERVICE_USER_NONLINEAR_CURVE_T));
			}
			

            _binder->transact(TRANSACTION_tos_factory_get_sound_curve,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_curve != NULL) {
                    int _pt_curve_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_curve_rblob;
                    reply.readBlob(_pt_curve_len,&_pt_curve_rblob);
                    memcpy(pt_curve,_pt_curve_rblob.data(),_pt_curve_len);
                } 

				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_sound_curve error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_sound_curve error");
        }

        return _result;
        /*-- add you code for tos_factory_get_sound_curve here --*/
    }

    fpi_error tos_factory_set_sound_curve( uint8_t ui1_curve_item, uint8_t ui1_val ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_sound_curve here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui1_curve_item);  //uint8_t as input paramter

            data.writeInt32(ui1_val);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_sound_curve,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_sound_curve error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_sound_curve error");
        }

        return _result;
        /*-- add you code for tos_factory_set_sound_curve here --*/
    }

    fpi_error tos_factory_get_ssc_setting( EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T* pt_ssc_arg ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_ssc_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_ssc_type);
			
			if(pt_ssc_arg == NULL) {
				return FPI_ERROR_FAIL;
			}else {
				data.writeInt32((int)1*sizeof(TOS_FAC_SSC_SETTING_T));
			}

            _binder->transact(TRANSACTION_tos_factory_get_ssc_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_ssc_arg != NULL) {
                    int _pt_ssc_arg_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_ssc_arg_rblob;
                    reply.readBlob(_pt_ssc_arg_len,&_pt_ssc_arg_rblob);
                    memcpy(pt_ssc_arg,_pt_ssc_arg_rblob.data(),_pt_ssc_arg_len);
                } 

				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_ssc_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_ssc_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_get_ssc_setting here --*/
    }

    fpi_error tos_factory_set_ssc_setting( EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T t_ssc_arg ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_ssc_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_ssc_type);

			data.writeInt32((int)1 * sizeof(TOS_FAC_SSC_SETTING_T));

			Parcel::WritableBlob _ssc_arg_wblob;
            data.writeBlob((int)1 * sizeof(TOS_FAC_SSC_SETTING_T),&_ssc_arg_wblob);
            memcpy(_ssc_arg_wblob.data(),&t_ssc_arg,(int)1* sizeof(TOS_FAC_SSC_SETTING_T));

            _binder->transact(TRANSACTION_tos_factory_set_ssc_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_ssc_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_ssc_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_set_ssc_setting here --*/
    }

    fpi_error tos_factory_get_overscan( EN_FAC_OVERSCAN_ITEM e_item, int32_t* i4_val ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_overscan here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_item);

            //for out only, only write length ; for in, alloc and copy
            if (i4_val == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_overscan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (i4_val != NULL) {
                    int _i4_val_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _i4_val_rblob;
                    reply.readBlob(_i4_val_len,&_i4_val_rblob);
                    memcpy(i4_val,_i4_val_rblob.data(),_i4_val_len);
                } 
				
				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_overscan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_overscan error");
        }

        return _result;
        /*-- add you code for tos_factory_get_overscan here --*/
    }

    fpi_error tos_factory_set_overscan( EN_FAC_OVERSCAN_ITEM e_item, uint8_t ui1_val ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_overscan here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_item);

            data.writeInt32(ui1_val);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_overscan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_overscan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_overscan error");
        }

        return _result;
        /*-- add you code for tos_factory_set_overscan here --*/
    }
	

    fpi_error tos_factory_get_wb_setting( EN_FAC_COLOR_TEMP e_color_temp, TOS_FAC_WHITE_BALANCE_T* pt_wb ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_wb_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            
			data.writeInt32(e_color_temp);

			if(pt_wb == NULL) {
				return FPI_ERROR_FAIL;
			}else {
				data.writeInt32((int)1*sizeof(TOS_FAC_WHITE_BALANCE_T));
			}

            _binder->transact(TRANSACTION_tos_factory_get_wb_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_wb != NULL) {
                    int _pt_wb_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_wb_rblob;
                    reply.readBlob(_pt_wb_len,&_pt_wb_rblob);
                    memcpy(pt_wb,_pt_wb_rblob.data(),_pt_wb_len);
                } 

				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_wb_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_wb_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_get_wb_setting here --*/
    }

    fpi_error tos_factory_set_wb_setting( EN_FAC_COLOR_TEMP e_color_temp, EN_FAC_WB_ITEM curve_item, int32_t value ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_wb_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_color_temp);
			
            data.writeInt32(curve_item);  //int8_t as input paramter

            data.writeInt32(value);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_wb_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_wb_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_wb_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_set_wb_setting here --*/
    }

    fpi_error tos_factory_record_ts_stream(  ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_record_ts_stream here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_record_ts_stream,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_record_ts_stream error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_record_ts_stream error");
        }

        return _result;
        /*-- add you code for tos_factory_record_ts_stream here --*/
    }

    fpi_error tos_factory_update_e_sticker(  ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_update_e_sticker here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_update_e_sticker,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_update_e_sticker error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_update_e_sticker error");
        }

        return _result;
        /*-- add you code for tos_factory_update_e_sticker here --*/
    }

    fpi_error tos_factory_test_device_id( fpi_bool* b_success ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_test_device_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(b_success == NULL)
			{
				return FPI_ERROR_FAIL;
			}else {
				data.writeInt32((int)1 * sizeof(fpi_bool));
			}
			
            _binder->transact(TRANSACTION_tos_factory_test_device_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (b_success != NULL) {
                    int _len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _rblob;
                    reply.readBlob(_len,&_rblob);
                    memcpy(b_success,_rblob.data(),_len);
				 }
				 
				 _result = (typeof(_result))reply.readInt32();//int as return value
                
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_test_device_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_test_device_id error");
        }

        return _result;
        /*-- add you code for tos_factory_test_device_id here --*/
    }

    fpi_error tos_factory_erase_ci_key(  ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_erase_ci_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_erase_ci_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_erase_ci_key error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_erase_ci_key error");
        }

        return _result;
        /*-- add you code for tos_factory_erase_ci_key here --*/
    }

    fpi_error tos_factory_get_func_enable( EN_FAC_FUNC_TYPE e_fun_type, fpi_bool* b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_func_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_fun_type);

			if(b_enable == NULL)
			{
				return FPI_ERROR_FAIL;
			}
			else
			{
				data.writeInt32((int)1 * sizeof(fpi_bool));
			}

            _binder->transact(TRANSACTION_tos_factory_get_func_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
				if (b_enable != NULL) {
                    int _len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _rblob;
                    reply.readBlob(_len,&_rblob);
                    memcpy(b_enable,_rblob.data(),_len);
				 }
				 
				 _result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_func_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_func_enable error");
        }

        return _result;
        /*-- add you code for tos_factory_get_func_enable here --*/
    }

    fpi_error tos_factory_set_func_enable( EN_FAC_FUNC_TYPE e_fun_type, fpi_bool b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_func_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_fun_type);

			data.writeInt32(b_enable);
            _binder->transact(TRANSACTION_tos_factory_set_func_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_func_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_func_enable error");
        }

        return _result;
        /*-- add you code for tos_factory_set_func_enable here --*/
    }

    fpi_error tos_factory_get_dbc_setting( TOS_FAC_DBC_SETTING_T* pt_dbc_setting ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_dbc_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pt_dbc_setting == NULL)
			{
				return FPI_ERROR_FAIL;
			}
			else
			{
				data.writeInt32((int)1 * sizeof(TOS_FAC_DBC_SETTING_T));
			}

            _binder->transact(TRANSACTION_tos_factory_get_dbc_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_dbc_setting != NULL) {
                    int _pt_dbc_setting_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_dbc_setting_rblob;
                    reply.readBlob(_pt_dbc_setting_len,&_pt_dbc_setting_rblob);
                    memcpy(pt_dbc_setting,_pt_dbc_setting_rblob.data(),_pt_dbc_setting_len);
                }
				
				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_dbc_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_dbc_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_get_dbc_setting here --*/
    }

    fpi_error tos_factory_set_dbc_setting( TOS_FAC_DBC_SETTING_T t_dbc_setting ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_dbc_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32((int)1 * sizeof(TOS_FAC_DBC_SETTING_T));
			
            Parcel::WritableBlob _t_dbc_setting_wblob;
            data.writeBlob((int)1 * sizeof(TOS_FAC_DBC_SETTING_T),&_t_dbc_setting_wblob);
            memcpy(_t_dbc_setting_wblob.data(),&t_dbc_setting,(int)1* sizeof(TOS_FAC_DBC_SETTING_T));

            _binder->transact(TRANSACTION_tos_factory_set_dbc_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_dbc_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_dbc_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_set_dbc_setting here --*/
    }

    fpi_error tos_factory_get_light_sensor_setting( TOS_FAC_LIGHT_SENSOR_ARG_T* pt_sensor_arg ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_light_sensor_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pt_sensor_arg == NULL) {
				return FPI_ERROR_FAIL;
			} else {
				data.writeInt32((int)1 * sizeof(TOS_FAC_LIGHT_SENSOR_ARG_T));
				
			}
			
	        _binder->transact(TRANSACTION_tos_factory_get_light_sensor_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_sensor_arg != NULL) {
                    int _pt_sensor_arg_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_sensor_arg_rblob;
                    reply.readBlob(_pt_sensor_arg_len,&_pt_sensor_arg_rblob);
                    memcpy(pt_sensor_arg,_pt_sensor_arg_rblob.data(),_pt_sensor_arg_len);
                } 

				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_light_sensor_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_light_sensor_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_get_light_sensor_setting here --*/
    }

    fpi_error tos_factory_set_light_sensor_setting( TOS_FAC_LIGHT_SENSOR_ARG_T t_sensor_arg ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_light_sensor_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)1 * sizeof(TOS_FAC_LIGHT_SENSOR_ARG_T));
			
            Parcel::WritableBlob _t_sensor_arg_wblob;
            data.writeBlob((int)1 * sizeof(TOS_FAC_LIGHT_SENSOR_ARG_T),&_t_sensor_arg_wblob);
            memcpy(_t_sensor_arg_wblob.data(),&t_sensor_arg,(int)1* sizeof(TOS_FAC_LIGHT_SENSOR_ARG_T));

            _binder->transact(TRANSACTION_tos_factory_set_light_sensor_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_light_sensor_setting error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_light_sensor_setting error");
        }

        return _result;
        /*-- add you code for tos_factory_set_light_sensor_setting here --*/
    }

    fpi_error tos_factory_set_power_on_logo(  ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_power_on_logo here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_set_power_on_logo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_power_on_logo error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_power_on_logo error");
        }

        return _result;
        /*-- add you code for tos_factory_set_power_on_logo here --*/
    }

    fpi_error tos_factory_get_ci_key_name( char* ps_name, int32_t i4_ret ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_ci_key_name here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ps_name == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)( i4_ret) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(i4_ret);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_get_ci_key_name,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ps_name != NULL) {
                    int _ps_name_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ps_name_rblob;
                    reply.readBlob(_ps_name_len,&_ps_name_rblob);
                    memcpy(ps_name,_ps_name_rblob.data(),_ps_name_len);
                }

				_result = (typeof(_result))reply.readInt32();//int as return value
				
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_ci_key_name error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_ci_key_name error");
        }

        return _result;
        /*-- add you code for tos_factory_get_ci_key_name here --*/
    }

    fpi_error tos_factory_get_statu( EN_FAC_QUERY_TYPE e_type, fpi_bool* b_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_statu here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_type);
			
			if(b_state == NULL)
			{
				return FPI_ERROR_FAIL;
			}
			else
			{
				data.writeInt32((int)1 * sizeof(fpi_bool));
			}
			
            _binder->transact(TRANSACTION_tos_factory_get_statu,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				if (b_state != NULL) {
                    int _len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _rblob;
                    reply.readBlob(_len,&_rblob);
                    memcpy(b_state,_rblob.data(),_len);
				 }

				 _result = (typeof(_result))reply.readInt32();//int as return value
				
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_statu error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_statu error");
        }

        return _result;
        /*-- add you code for tos_factory_get_statu here --*/
    }

    fpi_error tos_factory_set_statu( EN_FAC_QUERY_TYPE e_type, fpi_bool b_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_statu here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(e_type);

			data.writeInt32(b_state);

			_binder->transact(TRANSACTION_tos_factory_set_statu,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				 _result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_statu error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_statu error");
        }

        return _result;
        /*-- add you code for tos_factory_set_statu here --*/
    }

    fpi_error tos_factory_get_t2_support_state( EN_T2_SUPPORT_STATE* pe_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_t2_support_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pe_state == NULL)
			{
				return FPI_ERROR_FAIL;
			}
			else
			{
				data.writeInt32((int)1 * sizeof(EN_T2_SUPPORT_STATE));
			}
			
            _binder->transact(TRANSACTION_tos_factory_get_t2_support_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if(pe_state != NULL) {
					int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(pe_state,_value_rblob.data(),_value_len);
                }

				 _result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_t2_support_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_t2_support_state error");
        }

        return _result;
        /*-- add you code for tos_factory_get_t2_support_state here --*/
    }

    fpi_error tos_factory_set_t2_support_state( EN_T2_SUPPORT_STATE e_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_t2_support_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_state);

            _binder->transact(TRANSACTION_tos_factory_set_t2_support_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_t2_support_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_t2_support_state error");
        }

        return _result;
        /*-- add you code for tos_factory_set_t2_support_state here --*/
    }

    fpi_error tos_factory_get_product_info( fac_product_info_data_t* pt_info ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_product_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if(pt_info == NULL)
			{
				return FPI_ERROR_FAIL;
			}
			else
			{
				data.writeInt32((int)1 * sizeof(fac_product_info_data_t));
			}

            _binder->transact(TRANSACTION_tos_factory_get_product_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_info != NULL) {
                    int _pt_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_info_rblob;
                    reply.readBlob(_pt_info_len,&_pt_info_rblob);
                    memcpy(pt_info,_pt_info_rblob.data(),_pt_info_len);
                }

				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_product_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_product_info error");
        }

        return _result;
        /*-- add you code for tos_factory_get_product_info here --*/
    }

	fpi_error tos_factory_set_mute_color(uint32_t ui4_color, fpi_bool b_mute) {
		Parcel data, reply;

        /*-- add you code for tos_factory_set_t2_support_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui4_color);

			data.writeInt32(b_mute);

            _binder->transact(TRANSACTION_tos_factory_set_mute_color,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_t2_support_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_t2_support_state error");
        }

        return _result;
	}

	fpi_error tos_factory_get_bluetooth_3d_state(EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t* ui1_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_bluetooth_3d_sync_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(en_type);
            //for out only, only write length ; for in, alloc and copy
            if (ui1_state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_bluetooth_3d_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui1_state != NULL) {
                    int _ui1_state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui1_state_rblob;
                    reply.readBlob(_ui1_state_len,&_ui1_state_rblob);
                    memcpy(ui1_state,_ui1_state_rblob.data(),_ui1_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_bluetooth_3d_sync_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_bluetooth_3d_sync_state error");
        }

        return _result;
        /*-- add you code for tos_factory_get_bluetooth_3d_sync_state here --*/
    }

    fpi_error tos_factory_set_bluetooth_3d_state( EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t ui1_state ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_bluetooth_3d_sync_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(en_type);
            data.writeInt32(ui1_state);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_bluetooth_3d_sync_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_bluetooth_3d_sync_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_bluetooth_3d_sync_state error");
        }

        return _result;
        /*-- add you code for tos_factory_set_bluetooth_3d_sync_state here --*/
    }

    fpi_error tos_factory_get_current_operator_name( uint8_t* ui1_operator_name ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_current_operator_name here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ui1_operator_name == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(64)*sizeof(uint8_t));//write length, only support 32 bits length yet//qiyx mod 150829
                //data.writeInt32((int)(128) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }
		//	data.writeInt32(128);
            _binder->transact(TRANSACTION_tos_factory_get_current_operator_name,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui1_operator_name != NULL) {
                    int _ui1_operator_name_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui1_operator_name_rblob;
                    reply.readBlob(_ui1_operator_name_len,&_ui1_operator_name_rblob);
                    memcpy(ui1_operator_name,_ui1_operator_name_rblob.data(),_ui1_operator_name_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_current_operator_name error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_current_operator_name error");
        }

        return _result;
        /*-- add you code for tos_factory_get_current_operator_name here --*/
    }

    fpi_error tos_factory_set_operator_on_off( fpi_bool b_flag ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_operator_on_off here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(b_flag);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_operator_on_off,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_operator_on_off error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_operator_on_off error");
        }

        return _result;
        /*-- add you code for tos_factory_set_operator_on_off here --*/
    }

    fpi_error tos_factory_get_10p_data( TOS_TEN_P_DATA_T* pt_data ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_10p_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pt_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(TOS_TEN_P_DATA_T));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_10p_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pt_data != NULL) {
                    int _pt_data_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pt_data_rblob;
                    reply.readBlob(_pt_data_len,&_pt_data_rblob);
                    memcpy(pt_data,_pt_data_rblob.data(),_pt_data_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_10p_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_10p_data error");
        }

        return _result;
        /*-- add you code for tos_factory_get_10p_data here --*/
    }

    fpi_error tos_factory_set_10p_data( TOS_TEN_P_DATA_T* pt_data ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_10p_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pt_data == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(TOS_TEN_P_DATA_T));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pt_data_wblob;
                data.writeBlob((1) * sizeof(TOS_TEN_P_DATA_T),&_pt_data_wblob);
                memcpy(_pt_data_wblob.data(),pt_data,(1)* sizeof(TOS_TEN_P_DATA_T));
            }

            _binder->transact(TRANSACTION_tos_factory_set_10p_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_10p_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_10p_data error");
        }

        return _result;
        /*-- add you code for tos_factory_set_10p_data here --*/
    }

    fpi_error tos_factory_reset_10p_data(  ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_reset_10p_data here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_factory_reset_10p_data,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_reset_10p_data error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_reset_10p_data error");
        }

        return _result;
        /*-- add you code for tos_factory_reset_10p_data here --*/
    }

    fpi_error tos_factory_get_usb_state( fpi_bool* b_value ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_usb_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (b_value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_usb_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (b_value != NULL) {
                    int _b_value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _b_value_rblob;
                    reply.readBlob(_b_value_len,&_b_value_rblob);
                    memcpy(b_value,_b_value_rblob.data(),_b_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_usb_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_usb_state error");
        }

        return _result;
        /*-- add you code for tos_factory_get_usb_state here --*/
    }

    fpi_error tos_factory_get_upgrade_file_number( uint8_t* ui1_number ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_upgrade_file_number here --*/
        fpi_error _result = FPI_ERROR_FAIL;;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ui1_number == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_upgrade_file_number,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui1_number != NULL) {
                    int _ui1_number_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui1_number_rblob;
                    reply.readBlob(_ui1_number_len,&_ui1_number_rblob);
                    memcpy(ui1_number,_ui1_number_rblob.data(),_ui1_number_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_upgrade_file_number error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_upgrade_file_number error");
        }

        return _result;
        /*-- add you code for tos_factory_get_upgrade_file_number here --*/
    }
    
    fpi_error tos_factory_remote_pro( uint32_t ui4_key_code ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_remote_pro here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui4_key_code);  //int as input paramter

            _binder->transact(TRANSACTION_tos_factory_remote_pro,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_remote_pro error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_remote_pro error");
        }

        return _result;
        /*-- add you code for tos_factory_remote_pro here --*/
    }	
	//add by @hh with qiyx's modify
    fpi_error tos_factory_cmds_addcallback(tos_faccmds_oncommand oncommand,void* userdata) {
        Parcel data, reply;

        /*-- add you code for tos_factory_remote_pro here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
		
        if(_CBList.findCallback((void*)oncommand, NULL) != NULL) {
            TOSLOGW(SERVICE_NAME"_client tos_channel_play_add_callback cb arleady added");
            return _result;
        }        

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            
            sp<Callback> ccb = new Callback((void*)oncommand, NULL);
            data.writeStrongBinder(ccb);
			data.writeInt64((int64_t)userdata);

            _binder->transact(TRANSACTION_tos_factory_cmds_addcallback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value
                if(_result == FPI_ERROR_SUCCESS){
					_CBList.addCallback(ccb);	//qiyx mod 160325
				}
            } else {
                TOSLOGW(SERVICE_NAME"_client tos_factory_remote_pro error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_factory_remote_pro error");
        }

        return _result;
        /*-- add you code for tos_factory_remote_pro here --*/
    }	
	//add by @hh with qiyx's modify	
    fpi_error tos_factory_cmds_removecallback(tos_faccmds_oncommand oncommand,void* userdata) {
        Parcel data, reply;

        /*-- add you code for tos_factory_remote_pro here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

		if (NULL == oncommand)
		{
            TOSLOGW(SERVICE_NAME"_client tos_channel_play_remove_callback NULL callbak or error port");
            return _result;
		}
        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)oncommand, (void*)NULL);
        if(ccb == NULL) {
            TOSLOGW(SERVICE_NAME"_client tos_channel_play_remove_callback cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_factory_cmds_removecallback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                }
            } else {
                TOSLOGW(SERVICE_NAME"_client tos_channel_play_remove_callback error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_channel_play_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_factory_remote_pro here --*/
    }	
    //add by @hh with qiyx's modify
	#if 0
    fpi_error tos_faccmds_confirm(unsigned long token,TOS_FACCMDS_CMD_RESULT_S* result) {
        Parcel data, reply;

        /*-- add you code for tos_factory_remote_pro here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui4_key_code);  //int as input paramter

            _binder->transact(TRANSACTION_tos_factory_remote_pro,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_factory_remote_pro error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_factory_remote_pro error");
        }

        return _result;
        /*-- add you code for tos_factory_remote_pro here --*/
    }
	#endif  
    fpi_error tos_factory_erase_netflix(  ) 
    {       
       Parcel data, reply;        
       /*-- add you code for tos_factory_erase_netflix here --*/        
       fpi_error _result = FPI_ERROR_FAIL;       
       if(!getService()) {            
        return _result;        
       }        
       try {           
          data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check         
           _binder->transact(TRANSACTION_tos_factory_erase_netflix,data, &reply,0);       
          if(reply.readExceptionCode() == 0) {//fix check          
            _result = (typeof(_result))reply.readInt32();//int as return value    
          } else {              
            TOSLOGW(SERVICE_NAME"_client tos_factory_erase_netflix error");          
          }        
      }catch(...) {     
        TOSLOGW(SERVICE_NAME"_client tos_factory_erase_netflix error");        
      }        
       return _result;        
       /*-- add you code for tos_factory_erase_netflix here --*/   
   }
//======================Amy START for PANEL ID============================================
    fpi_error tos_factory_get_panel_id( uint16_t* ui2_id, uint16_t* ui2_max_id ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_panel_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (ui2_id == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (ui2_max_id == NULL) {
                return FPI_ERROR_FAIL;
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_factory_get_panel_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui2_id != NULL) {
                    int _ui2_id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_id_rblob;
                    reply.readBlob(_ui2_id_len,&_ui2_id_rblob);
                    memcpy(ui2_id,_ui2_id_rblob.data(),_ui2_id_len);
                }
                if (ui2_max_id != NULL) {
                    int _ui2_max_id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_max_id_rblob;
                    reply.readBlob(_ui2_max_id_len,&_ui2_max_id_rblob);
                    memcpy(ui2_max_id,_ui2_max_id_rblob.data(),_ui2_max_id_len);
                } 

				_result = (typeof(_result))reply.readInt32();

            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_panel_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_panel_id error");
        }

        return _result;
        /*-- add you code for tos_factory_get_panel_id here --*/
    }

    fpi_error tos_factory_set_panel_id( uint16_t ui2_id ) {
        Parcel data, reply;

        /*-- add you code for tos_factory_set_panel_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(ui2_id);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_factory_set_panel_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_set_panel_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_set_panel_id error");
        }

        return _result;
        /*-- add you code for tos_factory_set_panel_id here --*/
    }
	
    fpi_error tos_factory_get_panel_name( char* panelName) {
        Parcel data, reply;

        /*-- add you code for tos_factory_get_panel_id_name here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			data.writeInt32(sizeof(panelName));
            //for out only, only write length ; for in, alloc and copy
            if (panelName == NULL) {
                return FPI_ERROR_FAIL;
            }

            _binder->transact(TRANSACTION_tos_factory_get_panel_name,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                if (panelName != NULL) {
                    int _panelName_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _paneName_rblob;
                    reply.readBlob(_panelName_len,&_paneName_rblob);
                    memcpy(panelName,_paneName_rblob.data(),_panelName_len);
                }

				_result = (typeof(_result))reply.readInt32();//int as return value
            } else {
                fpi_warn(SERVICE_NAME"_client tos_factory_get_panel_id_name error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_factory_get_panel_id_name error");
        }

        return _result;
        /*-- add you code for tos_factory_get_panel_id_name here --*/
    }	

//======================Amy END for PANEL ID============================================
	
};

sbinder_factory_client* sbinder_factory_client::_instance = NULL;

fpi_error tos_factory_get_work_mode( EN_FAC_WORK_MODE e_work_mode, uint8_t* ui1_mode ) {
    return sbinder_factory_client::Instance()->tos_factory_get_work_mode(e_work_mode, ui1_mode);
}
fpi_error tos_factory_set_work_mode( EN_FAC_WORK_MODE e_work_mode, uint8_t ui1_mode ) {
    return sbinder_factory_client::Instance()->tos_factory_set_work_mode(e_work_mode, ui1_mode);
}
fpi_error tos_factory_get_system_info( EN_FAC_SYSTEM_INFO_TYPE e_info_type, char* ps_info, int32_t i4_len ) {
    return sbinder_factory_client::Instance()->tos_factory_get_system_info(e_info_type, ps_info, i4_len);
}
fpi_error tos_factory_get_version( EN_FAC_FIRMWARE_TYPE e_fr_type, char* ps_version, int32_t i4_len ) {
    return sbinder_factory_client::Instance()->tos_factory_get_version(e_fr_type, ps_version, i4_len);
}
fpi_error tos_factory_get_project_id( uint16_t* ui2_id, uint16_t* ui2_max_id ) {
    return sbinder_factory_client::Instance()->tos_factory_get_project_id(ui2_id, ui2_max_id);
}
fpi_error tos_factory_set_project_id( uint16_t ui2_id ) {
    return sbinder_factory_client::Instance()->tos_factory_set_project_id(ui2_id);
}
fpi_error tos_factory_usb_clone( EN_FAC_CLONE_DIRECTION e_direction, EN_FAC_CLONE_CONTENT e_content ) {
    return sbinder_factory_client::Instance()->tos_factory_usb_clone(e_direction, e_content);
}
fpi_error tos_factory_usb_upgrade( EN_FAC_UPGRADE_TYPE e_upgrade_type ) {
    return sbinder_factory_client::Instance()->tos_factory_usb_upgrade(e_upgrade_type);
}
fpi_error tos_factory_reset( EN_FAC_RESET_TYPE e_reset_type ) {
    return sbinder_factory_client::Instance()->tos_factory_reset(e_reset_type);
}
fpi_error tos_factory_wb_setting_init() {
    return sbinder_factory_client::Instance()->tos_factory_wb_setting_init();
}
fpi_error tos_factory_preset_channel( EN_FAC_PRESET_AREA e_preset_area ) {
    return sbinder_factory_client::Instance()->tos_factory_preset_channel(e_preset_area);
}
fpi_error tos_factory_get_preset_area( EN_FAC_PRESET_AREA* pe_preset_area ) {
    return sbinder_factory_client::Instance()->tos_factory_get_preset_area(pe_preset_area);
}
fpi_error tos_factory_get_power_on_mode( EN_FAC_POWER_ON_MODE* e_power_mode ) {
    return sbinder_factory_client::Instance()->tos_factory_get_power_on_mode(e_power_mode);
}
fpi_error tos_factory_set_power_on_mode( EN_FAC_POWER_ON_MODE e_power_mode ) {
    return sbinder_factory_client::Instance()->tos_factory_set_power_on_mode(e_power_mode);
}
fpi_error tos_factory_get_picture_curve( EN_FAC_PICTURE_CURVE_TYPE e_curve_type, TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve ) {
    return sbinder_factory_client::Instance()->tos_factory_get_picture_curve(e_curve_type, pt_curve);
}
fpi_error tos_factory_set_picture_curve( EN_FAC_PICTURE_CURVE_TYPE e_curve_type, uint8_t ui1_item, uint8_t ui1_val ) {
    return sbinder_factory_client::Instance()->tos_factory_set_picture_curve(e_curve_type, ui1_item, ui1_val);
}
fpi_error tos_factory_get_sound_curve( TOS_SERVICE_USER_NONLINEAR_CURVE_T* pt_curve ) {
    return sbinder_factory_client::Instance()->tos_factory_get_sound_curve(pt_curve);
}
fpi_error tos_factory_set_sound_curve( uint8_t ui1_curve_item, uint8_t ui1_val ) {
    return sbinder_factory_client::Instance()->tos_factory_set_sound_curve(ui1_curve_item, ui1_val);
}
fpi_error tos_factory_get_ssc_setting( EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T* pt_ssc_arg ) {
    return sbinder_factory_client::Instance()->tos_factory_get_ssc_setting(e_ssc_type, pt_ssc_arg);
}
fpi_error tos_factory_set_ssc_setting( EN_FAC_SSC_TYPE e_ssc_type, TOS_FAC_SSC_SETTING_T t_ssc_arg ) {
    return sbinder_factory_client::Instance()->tos_factory_set_ssc_setting(e_ssc_type, t_ssc_arg);
}
fpi_error tos_factory_get_overscan( EN_FAC_OVERSCAN_ITEM e_item, int32_t* i4_val ) {
    return sbinder_factory_client::Instance()->tos_factory_get_overscan(e_item, i4_val);
}
fpi_error tos_factory_set_overscan( EN_FAC_OVERSCAN_ITEM e_item, uint8_t ui1_val ) {
    return sbinder_factory_client::Instance()->tos_factory_set_overscan(e_item, ui1_val);
}
fpi_error tos_factory_get_wb_setting( EN_FAC_COLOR_TEMP e_color_temp, TOS_FAC_WHITE_BALANCE_T* pt_wb ) {
    return sbinder_factory_client::Instance()->tos_factory_get_wb_setting(e_color_temp, pt_wb);
}
fpi_error tos_factory_set_wb_setting( EN_FAC_COLOR_TEMP e_color_temp, EN_FAC_WB_ITEM curve_item, int32_t value ) {
    return sbinder_factory_client::Instance()->tos_factory_set_wb_setting(e_color_temp, curve_item, value);
}
fpi_error tos_factory_record_ts_stream(  ) {
    return sbinder_factory_client::Instance()->tos_factory_record_ts_stream();
}
fpi_error tos_factory_update_e_sticker(  ) {
    return sbinder_factory_client::Instance()->tos_factory_update_e_sticker();
}
fpi_error tos_factory_test_device_id( fpi_bool* b_success ) {
    return sbinder_factory_client::Instance()->tos_factory_test_device_id(b_success);
}
fpi_error tos_factory_erase_ci_key(  ) {
    return sbinder_factory_client::Instance()->tos_factory_erase_ci_key();
}
fpi_error tos_factory_get_func_enable( EN_FAC_FUNC_TYPE e_fun_type, fpi_bool* b_enable ) {
    return sbinder_factory_client::Instance()->tos_factory_get_func_enable(e_fun_type, b_enable);
}
fpi_error tos_factory_set_func_enable( EN_FAC_FUNC_TYPE e_fun_type, fpi_bool b_enable ) {
    return sbinder_factory_client::Instance()->tos_factory_set_func_enable(e_fun_type, b_enable);
}
fpi_error tos_factory_get_dbc_setting( TOS_FAC_DBC_SETTING_T* pt_dbc_setting ) {
    return sbinder_factory_client::Instance()->tos_factory_get_dbc_setting(pt_dbc_setting);
}
fpi_error tos_factory_set_dbc_setting( TOS_FAC_DBC_SETTING_T t_dbc_setting ) {
    return sbinder_factory_client::Instance()->tos_factory_set_dbc_setting(t_dbc_setting);
}
fpi_error tos_factory_get_light_sensor_setting( TOS_FAC_LIGHT_SENSOR_ARG_T* pt_sensor_arg ) {
    return sbinder_factory_client::Instance()->tos_factory_get_light_sensor_setting(pt_sensor_arg);
}
fpi_error tos_factory_set_light_sensor_setting( TOS_FAC_LIGHT_SENSOR_ARG_T t_sensor_arg ) {
    return sbinder_factory_client::Instance()->tos_factory_set_light_sensor_setting(t_sensor_arg);
}
fpi_error tos_factory_set_power_on_logo(  ) {
    return sbinder_factory_client::Instance()->tos_factory_set_power_on_logo();
}
fpi_error tos_factory_get_ci_key_name( char* ps_name, int32_t i4_ret ) {
    return sbinder_factory_client::Instance()->tos_factory_get_ci_key_name(ps_name, i4_ret);
}
fpi_error tos_factory_get_statu( EN_FAC_QUERY_TYPE e_type, fpi_bool* b_state ) {
    return sbinder_factory_client::Instance()->tos_factory_get_statu(e_type, b_state);
}
fpi_error tos_factory_set_statu( EN_FAC_QUERY_TYPE e_type, fpi_bool b_state ) {
    return sbinder_factory_client::Instance()->tos_factory_set_statu(e_type, b_state);
}
fpi_error tos_factory_get_t2_support_state( EN_T2_SUPPORT_STATE* pe_state ) {
    return sbinder_factory_client::Instance()->tos_factory_get_t2_support_state(pe_state);
}
fpi_error tos_factory_set_t2_support_state( EN_T2_SUPPORT_STATE e_state ) {
    return sbinder_factory_client::Instance()->tos_factory_set_t2_support_state(e_state);
}
fpi_error tos_factory_get_product_info( fac_product_info_data_t* pt_info ) {
    return sbinder_factory_client::Instance()->tos_factory_get_product_info(pt_info);
}
fpi_error tos_factory_set_mute_color(uint32_t ui4_color, fpi_bool b_mute) {
	return sbinder_factory_client::Instance()->tos_factory_set_mute_color(ui4_color,b_mute);
}
fpi_error tos_factory_get_bluetooth_3d_state( EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t* ui1_state ) {
    return sbinder_factory_client::Instance()->tos_factory_get_bluetooth_3d_state(en_type, ui1_state);
}
fpi_error tos_factory_set_bluetooth_3d_state( EN_TOS_FAC_BLUETOOTH_STATE_TYPE en_type, uint8_t ui1_state ) {
    return sbinder_factory_client::Instance()->tos_factory_set_bluetooth_3d_state(en_type, ui1_state);
}
fpi_error tos_factory_get_current_operator_name( uint8_t* ui1_operator_name ) {
    return sbinder_factory_client::Instance()->tos_factory_get_current_operator_name(ui1_operator_name);
}
fpi_error tos_factory_set_operator_on_off( fpi_bool b_flag ) {
    return sbinder_factory_client::Instance()->tos_factory_set_operator_on_off(b_flag);
}
fpi_error tos_factory_get_10p_data( TOS_TEN_P_DATA_T* pt_data ) {
    return sbinder_factory_client::Instance()->tos_factory_get_10p_data(pt_data);
}
fpi_error tos_factory_set_10p_data( TOS_TEN_P_DATA_T* pt_data ) {
    return sbinder_factory_client::Instance()->tos_factory_set_10p_data(pt_data);
}
fpi_error tos_factory_reset_10p_data(  ) {
    return sbinder_factory_client::Instance()->tos_factory_reset_10p_data();
}
fpi_error tos_factory_get_usb_state( fpi_bool* b_value ) {
    return sbinder_factory_client::Instance()->tos_factory_get_usb_state(b_value);
}
fpi_error tos_factory_get_upgrade_file_number( uint8_t* ui1_number ) {
    return sbinder_factory_client::Instance()->tos_factory_get_upgrade_file_number(ui1_number);
}
fpi_error tos_factory_remote_pro( uint32_t ui4_key_code ) {
    return sbinder_factory_client::Instance()->tos_factory_remote_pro(ui4_key_code);
}
//add by @hh with qiyx's modify
fpi_error tos_factory_cmds_addcallback(tos_faccmds_oncommand oncommand,void* userdata){
	return sbinder_factory_client::Instance()->tos_factory_cmds_addcallback(oncommand,userdata);
}
fpi_error tos_factory_cmds_removecallback(tos_faccmds_oncommand oncommand,void* userdata){
	return sbinder_factory_client::Instance()->tos_factory_cmds_removecallback(oncommand,userdata);
}
//end by @hh
/*
fpi_error tos_faccmds_confirm(unsigned long token,TOS_FACCMDS_CMD_RESULT_S* result){
	return sbinder_factory_client::Instance()->tos_faccmds_confirm(token,result);
}
*/
fpi_error tos_factory_erase_netflix(  ) {    
    return sbinder_factory_client::Instance()->tos_factory_erase_netflix();
}

//====Amy START for PANEL ID==================================================
fpi_error tos_factory_get_panel_id( uint16_t* ui2_id, uint16_t* ui2_max_id ) {
	return sbinder_factory_client::Instance()->tos_factory_get_panel_id(ui2_id, ui2_max_id);
}
fpi_error tos_factory_set_panel_id( uint16_t ui2_id ) {
	return sbinder_factory_client::Instance()->tos_factory_set_panel_id(ui2_id);
}

fpi_error tos_factory_get_panel_name( char* panelName ) {
	return sbinder_factory_client::Instance()->tos_factory_get_panel_name(panelName);
}
//====Amy END for PANEL ID==================================================

fpi_error tos_factory_get_gamma_offset( int* offset ) {
    return sbinder_factory_client::Instance()->tos_factory_get_gamma_offset(offset);
}

fpi_error tos_factory_get_projectID_array( int* buf, int* count ) {
    return sbinder_factory_client::Instance()->tos_factory_get_projectID_array(buf, count);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
