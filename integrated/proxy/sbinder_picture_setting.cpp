/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_picture_setting.sidl
 */
 

#define LOG_TAG     "sbinder_picture_setting"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_picture_setting.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_VIDEO);


#define SERVICE_DESCRIPTOR                      "e7b9869e-e4aa-11e4-9a9a-005056a84a3b"
#define SERVICE_NAME                            "sbinder_picture_setting"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_picture_set_mode FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_picture_get_mode FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_picture_set_backlight FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_picture_get_backlight FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_picture_set_brightness FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_picture_get_brightness FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_picture_set_contrast FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_picture_get_contrast FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_picture_set_sharpness FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_picture_get_sharpness FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_picture_set_saturation FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_picture_get_saturation FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_picture_set_hue FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_picture_get_hue FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_picture_set_energy_saving FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_picture_get_energy_saving FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_picture_set_backlight_state FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_picture_get_backlight_state FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_picture_get_video_freeze FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_picture_set_video_freeze FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_picture_reset FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_picture_set_hdmi_type FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_picture_get_hdmi_type FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_picture_enter_resolution_mode FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_picture_exit_resolution_mode FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_picture_is_resolution_mode FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_picture_get_pixel_info FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_picture_set_display_condition FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_picture_get_display_condition FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_picture_get_video_info FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_picture_vga_set_para FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_picture_get_vga_para FIRST_CALL_TRANSACTION + 32
#define TRANSACTION_tos_picture_memc_bypass_osd FIRST_CALL_TRANSACTION + 33
#define TRANSACTION_tos_picture_video_mute FIRST_CALL_TRANSACTION + 34
#define TRANSACTION_tos_picture_set_video_mute_with_reason FIRST_CALL_TRANSACTION + 35

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_picture_setting.h"

class sbinder_picture_setting_service : public BBinder  
{  
private:
    static sbinder_picture_setting_service* _instance;

    sbinder_picture_setting_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_picture_setting_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_picture_setting_service();
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

            case TRANSACTION_tos_picture_set_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_SOURCE_TYPE e_src_type = (EN_TOS_SOURCE_TYPE)data.readInt32();  //EN_TOS_SOURCE_TYPE as input paramter

                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                EN_FPI_PICTURE_MODE mode = (EN_FPI_PICTURE_MODE)data.readInt32();  //EN_FPI_PICTURE_MODE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_mode( e_src_type, e_mode, mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_SOURCE_TYPE e_src_type = (EN_TOS_SOURCE_TYPE)data.readInt32();  //EN_TOS_SOURCE_TYPE as input paramter

                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

           		// #error not support this type of paramter EN_FPI_PICTURE_MODE mode yet, please add code yourself
	//			EN_FPI_PICTURE_MODE mode = (EN_FPI_PICTURE_MODE)data.readInt32();
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PICTURE_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_PICTURE_MODE*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_mode(e_src_type, e_mode, value);

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_backlight:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_backlight here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_backlight( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_backlight here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_backlight:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_backlight here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_backlight( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_backlight here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_brightness:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_brightness here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_brightness( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_brightness here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_brightness:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_brightness here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_brightness( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_brightness here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_contrast:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_contrast here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_contrast( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_contrast here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_contrast:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_contrast here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_contrast( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_contrast here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_sharpness:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_sharpness here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_sharpness( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_sharpness here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_sharpness:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_sharpness here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_sharpness( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_sharpness here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_saturation:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_saturation here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_saturation( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_saturation here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_saturation:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_saturation here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_saturation( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_saturation here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_hue:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_hue here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_hue( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_hue here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_hue:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_hue here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_hue( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_hue here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_energy_saving:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_energy_saving here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_ENERGY_SAVING level = (EN_FPI_ENERGY_SAVING)data.readInt32();  //EN_FPI_ENERGY_SAVING as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_energy_saving( level, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_energy_saving here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_energy_saving:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_energy_saving here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
          //  #error not support this type of paramter EN_FPI_ENERGY_SAVING vaule yet, please add code yourself
          
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_ENERGY_SAVING* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_ENERGY_SAVING*)_value_wblob.data();
                }     
//		EN_FPI_ENERGY_SAVING vaule = (EN_FPI_ENERGY_SAVING)data.readInt32();

                fpi_error _result = tos_picture_get_energy_saving( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_energy_saving here --            
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_backlight_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_backlight_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_BACKLIGHT_STATE state = (EN_BACKLIGHT_STATE)data.readInt32();  //EN_BACKLIGHT_STATE as input paramter

                int16_t bOnOff = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_backlight_state( state, bOnOff, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_backlight_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_backlight_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_backlight_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_BACKLIGHT_STATE state = (EN_BACKLIGHT_STATE)data.readInt32();  //EN_BACKLIGHT_STATE as input paramter

                int _bOnOff_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* bOnOff = NULL;
                if(_bOnOff_len > 0) {
                    reply->writeInt32(_bOnOff_len);
                    Parcel::WritableBlob _bOnOff_wblob;
                    reply->writeBlob(_bOnOff_len,&_bOnOff_wblob);
                    bOnOff = (int16_t*)_bOnOff_wblob.data();
                }

                fpi_error _result = tos_picture_get_backlight_state( state, bOnOff );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_backlight_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_video_freeze:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_video_freeze here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* state = NULL;
                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    Parcel::WritableBlob _state_wblob;
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (int16_t*)_state_wblob.data();
                }

                fpi_error _result = tos_picture_get_video_freeze( state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_video_freeze here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_video_freeze:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_video_freeze here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t state = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_video_freeze( state, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_video_freeze here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_reset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_reset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_PICTURE_TYPE type = (EN_PICTURE_TYPE)data.readInt32();  //EN_PICTURE_TYPE as input paramter

                fpi_error _result = tos_picture_reset( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_reset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_hdmi_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_hdmi_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_PICTURE_TYPE type = (EN_FPI_PICTURE_TYPE)data.readInt32();  //EN_FPI_PICTURE_TYPE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_hdmi_type( type, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_hdmi_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_hdmi_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_hdmi_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
      //      #error not support this type of paramter EN_FPI_PICTURE_TYPE type yet, please add code yourself
	//	EN_FPI_PICTURE_TYPE type = (EN_FPI_PICTURE_TYPE)data.readInt32();
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PICTURE_TYPE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_PICTURE_TYPE*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_hdmi_type( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_hdmi_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_enter_resolution_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_enter_resolution_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RESOLUTION_TYPE type = (EN_RESOLUTION_TYPE)data.readInt32();  //EN_RESOLUTION_TYPE as input paramter

                int32_t mode = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_enter_resolution_mode( type, mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_enter_resolution_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_exit_resolution_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_exit_resolution_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RESOLUTION_TYPE type = (EN_RESOLUTION_TYPE)data.readInt32();  //EN_RESOLUTION_TYPE as input paramter

                int32_t mode = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_exit_resolution_mode( type, mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_exit_resolution_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_is_resolution_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_is_resolution_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RESOLUTION_TYPE type = (EN_RESOLUTION_TYPE)data.readInt32();  //EN_RESOLUTION_TYPE as input paramter

                int _flag_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* flag = NULL;
                if(_flag_len > 0) {
                    reply->writeInt32(_flag_len);
                    Parcel::WritableBlob _flag_wblob;
                    reply->writeBlob(_flag_len,&_flag_wblob);
                    flag = (int16_t*)_flag_wblob.data();
                }

                fpi_error _result = tos_picture_is_resolution_mode( type, flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_is_resolution_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_pixel_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_pixel_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t startX = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t startY = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t endX = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t endY = (int32_t)data.readInt32();  //int32_t as input paramter

       //         #error not support un-plat struct info yet, please add code yourself
       //         #if your struct is plat, do not mark it as a struct
		int _info_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_screen_pixel_info* info = NULL;
                if(_info_len > 0) {
                    reply->writeInt32(_info_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_info_len,&_value_wblob);
                    info = (st_fpi_screen_pixel_info*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_pixel_info( startX, startY, endX, endY, info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_pixel_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_display_condition:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_display_condition here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_MSG_TO_DBC msg = (EN_TOS_MSG_TO_DBC)data.readInt32();  //EN_TOS_MSG_TO_DBC as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_set_display_condition( msg, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_display_condition here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_display_condition:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_display_condition here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
      //      #error not support this type of paramter EN_TOS_MSG_TO_DBC msg yet, please add code yourself
		EN_TOS_MSG_TO_DBC msg = (EN_TOS_MSG_TO_DBC)data.readInt32();

                fpi_error _result = tos_picture_get_display_condition( &msg );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_display_condition here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
#if 0           
            case TRANSACTION_tos_picture_get_video_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_video_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            //    #error not support un-plat struct value yet, please add code yourself
            //    #if your struct is plat, do not mark it as a struct

		int _value_len = data.readInt32(); //read length, only 32bits length support yet
		st_fpi_video_info* value = NULL;
		if(_value_len > 0) {
			reply->writeInt32(_value_len);
			Parcel::WritableBlob _value_wblob;
			reply->writeBlob(_value_len,&_value_wblob);
			value = (st_fpi_video_info*)_value_wblob.data();
		}

                fpi_error _result = tos_picture_get_video_info( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_video_info here --
                return NO_ERROR;
            } break;
#endif         
            case TRANSACTION_tos_picture_vga_set_para:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_vga_set_para here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VGA_PARA_CTRL type = (EN_VGA_PARA_CTRL)data.readInt32();  //EN_VGA_PARA_CTRL as input paramter

                uint16_t value = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_picture_vga_set_para( type, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_vga_set_para here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_get_vga_para:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_get_vga_para here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VGA_PARA_CTRL type = (EN_VGA_PARA_CTRL)data.readInt32();  //EN_VGA_PARA_CTRL as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_picture_get_vga_para( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_get_vga_para here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_memc_bypass_osd:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_memc_bypass_osd here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               // #error not support un-plat struct stOsdWindow yet, please add code yourself
                //#if your struct is plat, do not mark it as a struct
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_osd_window stOsdWindow = {0};
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(st_fpi_osd_window) )
					{
						memcpy(&stOsdWindow,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
					}
                }

                int8_t mode = (int8_t)data.readInt32();  //int8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_picture_memc_bypass_osd( &stOsdWindow, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_memc_bypass_osd here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_video_mute:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_video_mute here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t mute_mask = (uint32_t)data.readInt32();  //uint32_t as input paramter

                fpi_bool b_mute = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_picture_video_mute( mute_mask, b_mute );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_video_mute here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_picture_set_video_mute_with_reason:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_picture_set_video_mute_with_reason here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _reason_len = data.readInt32(); //read length, only 32bits length support yet
                char* reason = NULL;

                Parcel::ReadableBlob _reason_rblob;

                if(_reason_len > 0) {
                    data.readBlob(_reason_len,&_reason_rblob);
                    reason = (char*)_reason_rblob.data();
                }

                fpi_bool b_mute = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                reason = (char*)_reason_rblob.data();
                fpi_error _result = tos_picture_set_video_mute_with_reason( reason, b_mute );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_picture_set_video_mute_with_reason here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_picture_setting_service_add() {
    sbinder_picture_setting_service::Instance();
    return 0;
}

sbinder_picture_setting_service* sbinder_picture_setting_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_picture_setting_client  
{  
private:
    static sbinder_picture_setting_client* _instance;
    sp<IBinder> _binder;

    sbinder_picture_setting_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_picture_setting_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_picture_setting_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_picture_setting_client();
        }

        return _instance;
    }

    fpi_error tos_picture_set_mode( EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode, EN_FPI_PICTURE_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_src_type);  //EN_TOS_SOURCE_TYPE as input paramter

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(mode);  //EN_FPI_PICTURE_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_mode error");
        }

        return _result;
        /*-- add you code for tos_picture_set_mode here --*/
    }

    fpi_error tos_picture_get_mode( EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode, EN_FPI_PICTURE_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_src_type);  //EN_TOS_SOURCE_TYPE as input paramter

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

          //  #error not support this type of paramter EN_FPI_PICTURE_MODE mode yet, please add code yourself
	  if (mode == NULL) {
		  data.writeInt32(-1);
	  }
	  else {
		  data.writeInt32((int)(1) * sizeof(EN_FPI_PICTURE_MODE));//write length, only support 32 bits length yet
		  
	  }


            _binder->transact(TRANSACTION_tos_picture_get_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

          //      #error not support this type of output paramter EN_FPI_PICTURE_MODE mode yet, please add code yourself
		  if (mode != NULL) {
			  int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
			  Parcel::ReadableBlob _value_rblob;
			  reply.readBlob(_mode_len,&_value_rblob);
			  memcpy(mode,_value_rblob.data(),_mode_len);
		  }


                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_mode error");
        }

        return _result;
        /*-- add you code for tos_picture_get_mode here --*/
    }

    fpi_error tos_picture_set_backlight( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_backlight here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_backlight,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_backlight error");
        }

        return _result;
        /*-- add you code for tos_picture_set_backlight here --*/
    }

    fpi_error tos_picture_get_backlight( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_backlight here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_backlight,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_backlight error");
        }

        return _result;
        /*-- add you code for tos_picture_get_backlight here --*/
    }

    fpi_error tos_picture_set_brightness( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_brightness here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_brightness,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_brightness error");
        }

        return _result;
        /*-- add you code for tos_picture_set_brightness here --*/
    }

    fpi_error tos_picture_get_brightness( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_brightness here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_brightness,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_brightness error");
        }

        return _result;
        /*-- add you code for tos_picture_get_brightness here --*/
    }

    fpi_error tos_picture_set_contrast( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_contrast here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_contrast,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_contrast error");
        }

        return _result;
        /*-- add you code for tos_picture_set_contrast here --*/
    }

    fpi_error tos_picture_get_contrast( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_contrast here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_contrast,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_contrast error");
        }

        return _result;
        /*-- add you code for tos_picture_get_contrast here --*/
    }

    fpi_error tos_picture_set_sharpness( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_sharpness here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_sharpness,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_sharpness error");
        }

        return _result;
        /*-- add you code for tos_picture_set_sharpness here --*/
    }

    fpi_error tos_picture_get_sharpness( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_sharpness here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_sharpness,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_sharpness error");
        }

        return _result;
        /*-- add you code for tos_picture_get_sharpness here --*/
    }

    fpi_error tos_picture_set_saturation( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_saturation here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_saturation,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_saturation error");
        }

        return _result;
        /*-- add you code for tos_picture_set_saturation here --*/
    }

    fpi_error tos_picture_get_saturation( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_saturation here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_saturation,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_saturation error");
        }

        return _result;
        /*-- add you code for tos_picture_get_saturation here --*/
    }

    fpi_error tos_picture_set_hue( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_hue here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_hue,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_hue error");
        }

        return _result;
        /*-- add you code for tos_picture_set_hue here --*/
    }

    fpi_error tos_picture_get_hue( EN_VIDEO_MODE e_mode, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_hue here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_hue,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_hue error");
        }

        return _result;
        /*-- add you code for tos_picture_get_hue here --*/
    }

    fpi_error tos_picture_set_energy_saving( EN_FPI_ENERGY_SAVING level, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_energy_saving here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(level);  //EN_FPI_ENERGY_SAVING as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_energy_saving,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_energy_saving error");
        }

        return _result;
        /*-- add you code for tos_picture_set_energy_saving here --*/
    }

    fpi_error tos_picture_get_energy_saving( EN_FPI_ENERGY_SAVING* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_energy_saving here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

         //   #error not support this type of paramter EN_FPI_ENERGY_SAVING vaule yet, please add code yourself
		 if (value == NULL) {
			 data.writeInt32(-1);
		 }
		 else {
			 data.writeInt32((int)(1) * sizeof(EN_FPI_ENERGY_SAVING));//write length, only support 32 bits length yet
			 
		 }


            _binder->transact(TRANSACTION_tos_picture_get_energy_saving,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

         //       #error not support this type of output paramter EN_FPI_ENERGY_SAVING vaule yet, please add code yourself
		 if (value != NULL) {
			 int _value_len = reply.readInt32(); //read length, only 32bits length support yet
			 Parcel::ReadableBlob _value_rblob;
			 reply.readBlob(_value_len,&_value_rblob);
			 memcpy(value,_value_rblob.data(),_value_len);
		 }


                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_energy_saving error");
        }

        return _result;
        /*-- add you code for tos_picture_get_energy_saving here --*/
    }

    fpi_error tos_picture_set_backlight_state( EN_BACKLIGHT_STATE state, int16_t bOnOff, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_backlight_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(state);  //EN_BACKLIGHT_STATE as input paramter

            data.writeInt32(bOnOff);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_backlight_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_backlight_state error");
        }

        return _result;
        /*-- add you code for tos_picture_set_backlight_state here --*/
    }

    fpi_error tos_picture_get_backlight_state( EN_BACKLIGHT_STATE state, int16_t* bOnOff ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_backlight_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(state);  //EN_BACKLIGHT_STATE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (bOnOff == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_backlight_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (bOnOff != NULL) {
                    int _bOnOff_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _bOnOff_rblob;
                    reply.readBlob(_bOnOff_len,&_bOnOff_rblob);
                    memcpy(bOnOff,_bOnOff_rblob.data(),_bOnOff_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_backlight_state error");
        }

        return _result;
        /*-- add you code for tos_picture_get_backlight_state here --*/
    }

    fpi_error tos_picture_get_video_freeze( int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_video_freeze here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_video_freeze,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_video_freeze error");
        }

        return _result;
        /*-- add you code for tos_picture_get_video_freeze here --*/
    }

    fpi_error tos_picture_set_video_freeze( int16_t state, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_video_freeze here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(state);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_video_freeze,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_video_freeze error");
        }

        return _result;
        /*-- add you code for tos_picture_set_video_freeze here --*/
    }

    fpi_error tos_picture_reset( EN_PICTURE_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_reset here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_PICTURE_TYPE as input paramter

            _binder->transact(TRANSACTION_tos_picture_reset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_reset error");
        }

        return _result;
        /*-- add you code for tos_picture_reset here --*/
    }

    fpi_error tos_picture_set_hdmi_type( EN_FPI_PICTURE_TYPE type, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_hdmi_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_FPI_PICTURE_TYPE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_hdmi_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_hdmi_type error");
        }

        return _result;
        /*-- add you code for tos_picture_set_hdmi_type here --*/
    }

    fpi_error tos_picture_get_hdmi_type( EN_FPI_PICTURE_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_hdmi_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

         //   #error not support this type of paramter EN_FPI_PICTURE_TYPE type yet, please add code yourself
		 if (type == NULL) {
			 data.writeInt32(-1);
		 }
		 else {
			 data.writeInt32((int)(1) * sizeof(EN_FPI_PICTURE_TYPE));//write length, only support 32 bits length yet
			 
		 }


            _binder->transact(TRANSACTION_tos_picture_get_hdmi_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

            //    #error not support this type of output paramter EN_FPI_PICTURE_TYPE type yet, please add code yourself
			if (type != NULL) {
				int _type_len = reply.readInt32(); //read length, only 32bits length support yet
				Parcel::ReadableBlob _state_rblob;
				reply.readBlob(_type_len,&_state_rblob);
				memcpy(type,_state_rblob.data(),_type_len);
			}


                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_hdmi_type error");
        }

        return _result;
        /*-- add you code for tos_picture_get_hdmi_type here --*/
    }

    fpi_error tos_picture_enter_resolution_mode( EN_RESOLUTION_TYPE type, int32_t mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_enter_resolution_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_RESOLUTION_TYPE as input paramter

            data.writeInt32(mode);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_enter_resolution_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_enter_resolution_mode error");
        }

        return _result;
        /*-- add you code for tos_picture_enter_resolution_mode here --*/
    }

    fpi_error tos_picture_exit_resolution_mode( EN_RESOLUTION_TYPE type, int32_t mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_exit_resolution_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_RESOLUTION_TYPE as input paramter

            data.writeInt32(mode);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_exit_resolution_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_exit_resolution_mode error");
        }

        return _result;
        /*-- add you code for tos_picture_exit_resolution_mode here --*/
    }

    fpi_error tos_picture_is_resolution_mode( EN_RESOLUTION_TYPE type, int16_t* flag ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_is_resolution_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_RESOLUTION_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (flag == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_is_resolution_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (flag != NULL) {
                    int _flag_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _flag_rblob;
                    reply.readBlob(_flag_len,&_flag_rblob);
                    memcpy(flag,_flag_rblob.data(),_flag_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_is_resolution_mode error");
        }

        return _result;
        /*-- add you code for tos_picture_is_resolution_mode here --*/
    }

    fpi_error tos_picture_get_pixel_info( int32_t startX, int32_t startY, int32_t endX, int32_t endY, st_fpi_screen_pixel_info* info ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_pixel_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(startX);  //int32_t as input paramter

            data.writeInt32(startY);  //int32_t as input paramter

            data.writeInt32(endX);  //int32_t as input paramter

            data.writeInt32(endY);  //int32_t as input paramter

      //      #error not support un-plat struct info yet, please add code yourself
      //      #if your struct is plat, do not mark it as a struct

		if (info == NULL) 
		{
		   data.writeInt32(-1);
		}
		else 
		{
		    data.writeInt32((int)(1) * sizeof(st_fpi_screen_pixel_info));//write length, only support 32 bits length yet
		}

            _binder->transact(TRANSACTION_tos_picture_get_pixel_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (info != NULL) {
                    int _info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _info_rblob;
                    reply.readBlob(_info_len,&_info_rblob);
                    memcpy(info,_info_rblob.data(),_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_pixel_info error");
        }

        return _result;
        /*-- add you code for tos_picture_get_pixel_info here --*/
    }

    fpi_error tos_picture_set_display_condition( EN_TOS_MSG_TO_DBC msg, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_display_condition here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(msg);  //EN_TOS_MSG_TO_DBC as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_display_condition,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_display_condition error");
        }

        return _result;
        /*-- add you code for tos_picture_set_display_condition here --*/
    }

    fpi_error tos_picture_get_display_condition( EN_TOS_MSG_TO_DBC* msg ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_display_condition here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

        //    #error not support this type of paramter EN_TOS_MSG_TO_DBC msg yet, please add code yourself
		if (msg == NULL) {
			   data.writeInt32(-1);
		   }
		   else {
			   data.writeInt32((int)(1) * sizeof(EN_TOS_MSG_TO_DBC));//write length, only support 32 bits length yet
		   }


            _binder->transact(TRANSACTION_tos_picture_get_display_condition,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

           //     #error not support this type of output paramter EN_TOS_MSG_TO_DBC msg yet, please add code yourself
		   if (msg != NULL) {
			   int _msg_len = reply.readInt32(); //read length, only 32bits length support yet
			   Parcel::ReadableBlob _value_rblob;
			   reply.readBlob(_msg_len,&_value_rblob);
			   memcpy(msg,_value_rblob.data(),_msg_len);
		   }


                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_get_display_condition error");
        }

        return _result;
        /*-- add you code for tos_picture_get_display_condition here --*/
    }
#if 0
    fpi_error tos_picture_get_video_info( st_fpi_video_info* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_video_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

        //    #error not support un-plat struct value yet, please add code yourself
         //   #if your struct is plat, do not mark it as a struct
		if (value == NULL) {
			   data.writeInt32(-1);
		   }
		   else {
			   data.writeInt32((int)(1) * sizeof(st_fpi_video_info));//write length, only support 32 bits length yet
		   }

            _binder->transact(TRANSACTION_tos_picture_get_video_info,data, &reply,0);

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
            ALOGW(SERVICE_NAME"_client tos_picture_get_video_info error");
        }

        return _result;
        /*-- add you code for tos_picture_get_video_info here --*/
    }
#endif
    fpi_error tos_picture_vga_set_para( EN_VGA_PARA_CTRL type, uint16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_vga_set_para here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_VGA_PARA_CTRL as input paramter

            data.writeInt32(value);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_picture_vga_set_para,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_vga_set_para error");
        }

        return _result;
        /*-- add you code for tos_picture_vga_set_para here --*/
    }

    fpi_error tos_picture_get_vga_para( EN_VGA_PARA_CTRL type, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_get_vga_para here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_VGA_PARA_CTRL as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_picture_get_vga_para,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_picture_get_vga_para error");
        }

        return _result;
        /*-- add you code for tos_picture_get_vga_para here --*/
    }

    fpi_error tos_picture_memc_bypass_osd( st_fpi_osd_window* stOsdWindow, int8_t mode ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_memc_bypass_osd here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support un-plat struct stOsdWindow yet, please add code yourself
           // #if your struct is plat, do not mark it as a struct
            data.writeInt32((int)(1) * sizeof(st_fpi_osd_window));//write length, only support 32 bits length yet
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(st_fpi_osd_window),&_pin_wblob);
            memcpy(_pin_wblob.data(),stOsdWindow,(1)* sizeof(st_fpi_osd_window));


            data.writeInt32(mode);  //int8_t as input paramter

            _binder->transact(TRANSACTION_tos_picture_memc_bypass_osd,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_picture_memc_bypass_osd error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_memc_bypass_osd error");
        }

        return _result;
        /*-- add you code for tos_picture_memc_bypass_osd here --*/
    }

    fpi_error tos_picture_video_mute( uint32_t mute_mask, fpi_bool b_mute ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_video_mute here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mute_mask);  //uint32_t as input paramter

            data.writeInt32(b_mute);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_picture_video_mute,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_picture_video_mute error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_video_mute error");
        }

        return _result;
        /*-- add you code for tos_picture_video_mute here --*/
    }

    fpi_error tos_picture_set_video_mute_with_reason( char* reason, fpi_bool b_mute ) {
        Parcel data, reply;

        /*-- add you code for tos_picture_set_video_mute_with_reason here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (reason == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(reason)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _reason_wblob;
                data.writeBlob((strlen(reason)+1) * sizeof(char),&_reason_wblob);
                memcpy(_reason_wblob.data(),reason,(strlen(reason)+1)* sizeof(char));
            }

            data.writeInt32(b_mute);  //int16_t as input paramter

            _binder->transact(TRANSACTION_tos_picture_set_video_mute_with_reason,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_picture_set_video_mute_with_reason error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_picture_set_video_mute_with_reason error");
        }

        return _result;
        /*-- add you code for tos_picture_set_video_mute_with_reason here --*/
    }
};

sbinder_picture_setting_client* sbinder_picture_setting_client::_instance = NULL;

fpi_error tos_picture_set_mode( EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode, EN_FPI_PICTURE_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_mode(e_src_type, e_mode, mode, act);
}
fpi_error tos_picture_get_mode( EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode, EN_FPI_PICTURE_MODE* mode ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_mode(e_src_type, e_mode, mode);
}
fpi_error tos_picture_set_backlight( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_backlight(e_mode, value, act);
}
fpi_error tos_picture_get_backlight( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_backlight(e_mode, value);
}
fpi_error tos_picture_set_brightness( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_brightness(e_mode, value, act);
}
fpi_error tos_picture_get_brightness( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_brightness(e_mode, value);
}
fpi_error tos_picture_set_contrast( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_contrast(e_mode, value, act);
}
fpi_error tos_picture_get_contrast( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_contrast(e_mode, value);
}
fpi_error tos_picture_set_sharpness( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_sharpness(e_mode, value, act);
}
fpi_error tos_picture_get_sharpness( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_sharpness(e_mode, value);
}
fpi_error tos_picture_set_saturation( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_saturation(e_mode, value, act);
}
fpi_error tos_picture_get_saturation( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_saturation(e_mode, value);
}
fpi_error tos_picture_set_hue( EN_VIDEO_MODE e_mode, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_hue(e_mode, value, act);
}
fpi_error tos_picture_get_hue( EN_VIDEO_MODE e_mode, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_hue(e_mode, value);
}
fpi_error tos_picture_set_energy_saving( EN_FPI_ENERGY_SAVING level, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_energy_saving(level, act);
}
fpi_error tos_picture_get_energy_saving( EN_FPI_ENERGY_SAVING* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_energy_saving(value);
}
fpi_error tos_picture_set_backlight_state( EN_BACKLIGHT_STATE state, int16_t bOnOff, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_backlight_state(state, bOnOff, act);
}
fpi_error tos_picture_get_backlight_state( EN_BACKLIGHT_STATE state, int16_t* bOnOff ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_backlight_state(state, bOnOff);
}
fpi_error tos_picture_get_video_freeze( int16_t* state ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_video_freeze(state);
}
fpi_error tos_picture_set_video_freeze( int16_t state, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_video_freeze(state, act);
}
fpi_error tos_picture_reset( EN_PICTURE_TYPE type ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_reset(type);
}
fpi_error tos_picture_set_hdmi_type( EN_FPI_PICTURE_TYPE type, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_hdmi_type(type, act);
}
fpi_error tos_picture_get_hdmi_type( EN_FPI_PICTURE_TYPE* type ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_hdmi_type(type);
}
fpi_error tos_picture_enter_resolution_mode( EN_RESOLUTION_TYPE type, int32_t mode, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_enter_resolution_mode(type, mode, act);
}
fpi_error tos_picture_exit_resolution_mode( EN_RESOLUTION_TYPE type, int32_t mode, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_exit_resolution_mode(type, mode, act);
}
fpi_error tos_picture_is_resolution_mode( EN_RESOLUTION_TYPE type, int16_t* flag ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_is_resolution_mode(type, flag);
}
fpi_error tos_picture_get_pixel_info( int32_t startX, int32_t startY, int32_t endX, int32_t endY, st_fpi_screen_pixel_info* info ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_pixel_info(startX, startY, endX, endY, info);
}
fpi_error tos_picture_set_display_condition( EN_TOS_MSG_TO_DBC msg, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_display_condition(msg, act);
}
fpi_error tos_picture_get_display_condition( EN_TOS_MSG_TO_DBC* msg ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_display_condition(msg);
}
#if 0
fpi_error tos_picture_get_video_info( st_fpi_video_info* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_video_info(value);
}
#endif
fpi_error tos_picture_vga_set_para( EN_VGA_PARA_CTRL type, uint16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_vga_set_para(type, value, act);
}
fpi_error tos_picture_get_vga_para( EN_VGA_PARA_CTRL type, uint16_t* value ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_get_vga_para(type, value);
}
fpi_error tos_picture_memc_bypass_osd( st_fpi_osd_window* stOsdWindow, int8_t mode ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_memc_bypass_osd(stOsdWindow, mode);
}
fpi_error tos_picture_video_mute( uint32_t mute_mask, fpi_bool b_mute ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_video_mute(mute_mask, b_mute);
}
fpi_error tos_picture_set_video_mute_with_reason( char* reason, fpi_bool b_mute ) {
    return sbinder_picture_setting_client::Instance()->tos_picture_set_video_mute_with_reason(reason, b_mute);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
