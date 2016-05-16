/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_sound_setting.sidl
 */
 

#define LOG_TAG     "sbinder_sound_setting"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_sound_setting.h"
#include "tos_input_source.h"
#include "tos_function_safety.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_AUDIO);



#define SERVICE_DESCRIPTOR                      "894022a6-ed6c-11e4-a9bd-005056a84a3b"
#define SERVICE_NAME                            "sbinder_sound_setting"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_audio_set_mute FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_audio_get_mute FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_audio_set_volume FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_audio_get_volume FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_audio_set_mute_ex FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_audio_get_mute_ex FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_audio_set_volume_ex FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_audio_get_volume_ex FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_audio_get_max_volume FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_audio_set_max_volume FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_audio_set_input_mute FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_audio_get_input_mute FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_audio_set_input_volume FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_audio_get_input_volume FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_audio_set_equalizer_mode FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_audio_get_equalizer_mode FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_audio_set_equalizer FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_audio_get_equalizer FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_audio_set_balance FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_audio_get_balance FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_audio_set_auto_volume FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_audio_get_auto_volume FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_audio_set_delay FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_audio_get_delay FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_audio_set_wide_stereo FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_audio_get_wide_stereo FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_audio_set_spdif_type FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_audio_get_spdif_type FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_audio_get_visual_impaired FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_audio_set_visual_impaired FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_audio_set_audio_description FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_audio_get_audio_description FIRST_CALL_TRANSACTION + 32
#define TRANSACTION_tos_audio_set_audio_description_mix_level FIRST_CALL_TRANSACTION + 33
#define TRANSACTION_tos_audio_get_audio_description_mix_level FIRST_CALL_TRANSACTION + 34
#define TRANSACTION_tos_audio_get_mts_info FIRST_CALL_TRANSACTION + 35
#define TRANSACTION_tos_audio_set_mts_info FIRST_CALL_TRANSACTION + 36
#define TRANSACTION_tos_audio_get_language_info FIRST_CALL_TRANSACTION + 37
#define TRANSACTION_tos_audio_set_language_index FIRST_CALL_TRANSACTION + 38
#define TRANSACTION_tos_audio_get_scene FIRST_CALL_TRANSACTION + 39
#define TRANSACTION_tos_audio_set_scene FIRST_CALL_TRANSACTION + 40
#define TRANSACTION_tos_audio_get_dev_plugin FIRST_CALL_TRANSACTION + 41
#define TRANSACTION_tos_audio_get_source_info FIRST_CALL_TRANSACTION + 42
#define TRANSACTION_tos_audio_get_language_information FIRST_CALL_TRANSACTION + 43
#define TRANSACTION_tos_audio_set_language_information FIRST_CALL_TRANSACTION + 44
#define TRANSACTION_tos_audio_set_speaker_enable FIRST_CALL_TRANSACTION + 45
#define TRANSACTION_tos_audio_get_speaker_enable FIRST_CALL_TRANSACTION + 46
#define TRANSACTION_tos_audio_set_dtv_stereo_sound_mode FIRST_CALL_TRANSACTION + 47
#define TRANSACTION_tos_audio_set_output_device_mix_type FIRST_CALL_TRANSACTION + 48
#define TRANSACTION_tos_audio_get_output_device_mix_type FIRST_CALL_TRANSACTION + 49
#define TRANSACTION_tos_audio_set_audDevice_output_onOff FIRST_CALL_TRANSACTION + 50
#define TRANSACTION_tos_audio_get_audDevice_output_onOff FIRST_CALL_TRANSACTION + 51
#define TRANSACTION_tos_audio_set_value FIRST_CALL_TRANSACTION + 52
#define TRANSACTION_tos_audio_get_value FIRST_CALL_TRANSACTION + 53
#define TRANSACTION_tos_audio_set_tcl_sound_effects_mode FIRST_CALL_TRANSACTION + 54
#define TRANSACTION_tos_audio_get_tcl_sound_effects_mode FIRST_CALL_TRANSACTION + 55
#define TRANSACTION_tos_audio_set_spdif_dobly_digital_plus_mode FIRST_CALL_TRANSACTION + 56
#define TRANSACTION_tos_audio_get_spdif_dobly_digital_plus_mode FIRST_CALL_TRANSACTION + 57
#define TRANSACTION_tos_audio_set_dobly_ms12_setting FIRST_CALL_TRANSACTION + 58
#define TRANSACTION_tos_audio_get_dobly_ms12_setting FIRST_CALL_TRANSACTION + 59
#define TRANSACTION_tos_audio_reset_sound_setting FIRST_CALL_TRANSACTION + 60

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_sound_setting.h"

class sbinder_sound_setting_service : public BBinder  
{  
private:
    static sbinder_sound_setting_service* _instance;

    sbinder_sound_setting_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_sound_setting_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_sound_setting_service();
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

            case TRANSACTION_tos_audio_set_mute:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_mute here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t mute_level = (int16_t)data.readInt32();  //int16_t as input paramter

                int16_t mute = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_mute( mute_level, mute, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_mute here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_mute:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_mute here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t mute_level = (int16_t)data.readInt32();  //int16_t as input paramter

                int _mute_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* mute = NULL;

                Parcel::WritableBlob _mute_wblob;

                if(_mute_len > 0) {
                    reply->writeInt32(_mute_len);
                    reply->writeBlob(_mute_len,&_mute_wblob);
                    mute = (int16_t*)_mute_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mute = (int16_t*)_mute_wblob.data();
                fpi_error _result = tos_audio_get_mute( mute_level, mute );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_mute here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t vol = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_volume( vol, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _soundValue_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* soundValue = NULL;

                Parcel::WritableBlob _soundValue_wblob;

                if(_soundValue_len > 0) {
                    reply->writeInt32(_soundValue_len);
                    reply->writeBlob(_soundValue_len,&_soundValue_wblob);
                    soundValue = (int16_t*)_soundValue_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                soundValue = (int16_t*)_soundValue_wblob.data();
                fpi_error _result = tos_audio_get_volume( soundValue );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_mute_ex:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_mute_ex here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE en_dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE en_dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
              //#error not support this type of paramter EN_TOS_AUDIO_INPUT_TYPE en_input yet, please add code yourself

                int _ch_reason_len = data.readInt32(); //read length, only 32bits length support yet
                char* ch_reason = NULL;

                Parcel::ReadableBlob _ch_reason_rblob;

                if(_ch_reason_len > 0) {
                    data.readBlob(_ch_reason_len,&_ch_reason_rblob);
                    ch_reason = (char*)_ch_reason_rblob.data();
                }

                int16_t b_mute = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                ch_reason = (char*)_ch_reason_rblob.data();
                fpi_error _result = tos_audio_set_mute_ex( en_dev, ch_reason, b_mute, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_mute_ex here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_mute_ex:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_mute_ex here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE en_dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE en_dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
              //#error not support this type of paramter EN_TOS_AUDIO_INPUT_TYPE en_input yet, please add code yourself

                int _mute_reason_len = data.readInt32(); //read length, only 32bits length support yet
                char* mute_reason = NULL;

                Parcel::ReadableBlob _mute_reason_rblob;

                if(_mute_reason_len > 0) {
                    data.readBlob(_mute_reason_len,&_mute_reason_rblob);
                    mute_reason = (char*)_mute_reason_rblob.data();
                }

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* state = NULL;

                Parcel::WritableBlob _state_wblob;

                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (int16_t*)_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mute_reason = (char*)_mute_reason_rblob.data();
                state = (int16_t*)_state_wblob.data();
                fpi_error _result = tos_audio_get_mute_ex( en_dev, mute_reason, state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_mute_ex here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_volume_ex:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_volume_ex here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
	          EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
             //#error not support this type of paramter EN_TOS_AUDIO_INPUT_TYPE input yet, please add code yourself
               EN_TOS_AUDIO_INPUT_TYPE input = (EN_TOS_AUDIO_INPUT_TYPE)data.readInt32();

                int16_t volume = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_volume_ex( dev, input, volume, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_volume_ex here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_volume_ex:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_volume_ex here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
	            EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
               //#error not support this type of paramter EN_TOS_AUDIO_INPUT_TYPE input yet, please add code yourself
               EN_TOS_AUDIO_INPUT_TYPE input = (EN_TOS_AUDIO_INPUT_TYPE)data.readInt32();

                int _volume_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* volume = NULL;

                Parcel::WritableBlob _volume_wblob;

                if(_volume_len > 0) {
                    reply->writeInt32(_volume_len);
                    reply->writeBlob(_volume_len,&_volume_wblob);
                    volume = (int16_t*)_volume_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                volume = (int16_t*)_volume_wblob.data();
                fpi_error _result = tos_audio_get_volume_ex( dev, input, volume );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_volume_ex here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_max_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_max_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
				
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_max_volume( dev, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_max_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_max_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_max_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
				
                int16_t maxVolume = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_max_volume( dev, maxVolume, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_max_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_input_mute:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_input_mute here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
                EN_TOS_AUDIO_INPUT input = (EN_TOS_AUDIO_INPUT)data.readInt32();
				
                int16_t mute = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_input_mute( input, mute, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_input_mute here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_input_mute:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_input_mute here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
                EN_TOS_AUDIO_INPUT input = (EN_TOS_AUDIO_INPUT)data.readInt32();
				
                int _mute_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* mute = NULL;

                Parcel::WritableBlob _mute_wblob;

                if(_mute_len > 0) {
                    reply->writeInt32(_mute_len);
                    reply->writeBlob(_mute_len,&_mute_wblob);
                    mute = (int16_t*)_mute_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mute = (int16_t*)_mute_wblob.data();
                fpi_error _result = tos_audio_get_input_mute( input, mute );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_input_mute here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_input_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_input_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
               EN_TOS_AUDIO_INPUT input = (EN_TOS_AUDIO_INPUT)data.readInt32();
				
                int16_t soundValue = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_input_volume( input, soundValue, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_input_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_input_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_input_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
               EN_TOS_AUDIO_INPUT input = (EN_TOS_AUDIO_INPUT)data.readInt32();
				
                int _soundValue_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* soundValue = NULL;

                Parcel::WritableBlob _soundValue_wblob;

                if(_soundValue_len > 0) {
                    reply->writeInt32(_soundValue_len);
                    reply->writeBlob(_soundValue_len,&_soundValue_wblob);
                    soundValue = (int16_t*)_soundValue_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                soundValue = (int16_t*)_soundValue_wblob.data();
                fpi_error _result = tos_audio_get_input_volume( input, soundValue );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_input_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_equalizer_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_equalizer_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_SOUND_MODE mode yet, please add code yourself
                EN_TOS_SOUND_MODE mode = (EN_TOS_SOUND_MODE)data.readInt32();
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_equalizer_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_equalizer_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_equalizer_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_equalizer_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                 //#error not support this type of paramter EN_TOS_SOUND_MODE value yet, please add code yourself
                 int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_SOUND_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_TOS_SOUND_MODE*)_value_wblob.data();
                }
				
                fpi_error _result = tos_audio_get_equalizer_mode( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_equalizer_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_equalizer:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_equalizer here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               // #error not support this type of paramter EN_TOS_SOUND_EQUALIZER_TYPE type yet, please add code yourself
               EN_TOS_SOUND_EQUALIZER_TYPE type = (EN_TOS_SOUND_EQUALIZER_TYPE)data.readInt32();
				
                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_equalizer( type, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_equalizer here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_equalizer:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_equalizer here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                 // #error not support this type of paramter EN_TOS_SOUND_EQUALIZER_TYPE type yet, please add code yourself
                EN_TOS_SOUND_EQUALIZER_TYPE type = (EN_TOS_SOUND_EQUALIZER_TYPE)data.readInt32();
				
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_equalizer( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_equalizer here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_balance:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_balance here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
				
                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_balance( dev, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_balance here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_balance:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_balance here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
				
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_balance( dev, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_balance here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_auto_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_auto_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_auto_volume( enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_auto_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_auto_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_auto_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;

                Parcel::WritableBlob _enable_wblob;

                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enable = (int16_t*)_enable_wblob.data();
                fpi_error _result = tos_audio_get_auto_volume( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_auto_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_delay:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_delay here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
			
                int32_t delay = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_delay( dev, delay, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_delay here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_delay:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_delay here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
             //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev = (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
                int _delay_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* delay = NULL;

                Parcel::WritableBlob _delay_wblob;

                if(_delay_len > 0) {
                    reply->writeInt32(_delay_len);
                    reply->writeBlob(_delay_len,&_delay_wblob);
                    delay = (int32_t*)_delay_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                delay = (int32_t*)_delay_wblob.data();
                fpi_error _result = tos_audio_get_delay( dev, delay );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_delay here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_wide_stereo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_wide_stereo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_STEREO_MODE mode yet, please add code yourself
                EN_TOS_STEREO_MODE mode = (EN_TOS_STEREO_MODE)data.readInt32();
			
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_wide_stereo( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_wide_stereo here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_wide_stereo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_wide_stereo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_STEREO_MODE value yet, please add code yourself
                 int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_STEREO_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_TOS_STEREO_MODE*)_value_wblob.data();
                }
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_wide_stereo( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_wide_stereo here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_spdif_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_spdif_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_SPDIF_TYPE type yet, please add code yourself
                EN_TOS_SPDIF_TYPE type = (EN_TOS_SPDIF_TYPE)data.readInt32();
				
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_spdif_type( type, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_spdif_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_spdif_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_spdif_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // #error not support this type of paramter EN_TOS_SPDIF_TYPE value yet, please add code yourself
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_SPDIF_TYPE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_TOS_SPDIF_TYPE*)_value_wblob.data();
                }
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_spdif_type( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_spdif_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_visual_impaired:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_visual_impaired here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* state = NULL;

                Parcel::WritableBlob _state_wblob;

                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (int16_t*)_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                state = (int16_t*)_state_wblob.data();
                fpi_error _result = tos_audio_get_visual_impaired( state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_visual_impaired here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_visual_impaired:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_visual_impaired here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t state = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_visual_impaired( state, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_visual_impaired here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_audio_description:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_audio_description here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_audio_description( enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_audio_description here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_audio_description:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_audio_description here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;

                Parcel::WritableBlob _enable_wblob;

                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enable = (int16_t*)_enable_wblob.data();
                fpi_error _result = tos_audio_get_audio_description( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_audio_description here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_audio_description_mix_level:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_audio_description_mix_level here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t level = (uint16_t)data.readInt32();  //uint16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_audio_description_mix_level( level, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_audio_description_mix_level here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_audio_description_mix_level:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_audio_description_mix_level here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (uint16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_audio_description_mix_level( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_audio_description_mix_level here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_mts_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_mts_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support un-plat struct audioInfo yet, please add code yourself
               // #if your struct is plat, do not mark it as a struct
                 int _audio_info_len = data.readInt32(); //read length, only 32bits length support yet
                st_tos_mts_info_t* audioInfo = NULL;
                if(_audio_info_len > 0) {
                    reply->writeInt32(_audio_info_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_audio_info_len,&_value_wblob);
                    audioInfo = (st_tos_mts_info_t*)_value_wblob.data();
                }
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result;
                if( audioInfo != NULL ){
                _result = tos_audio_get_mts_info( audioInfo );
                }
				else{
					_result = FPI_ERROR_PROXY_SBINDER_NULL ;
					}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_mts_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_mts_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_mts_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support un-plat struct audioInfo yet, please add code yourself
                //#if your struct is plat, do not mark it as a struct
                 int _audio_info_len = data.readInt32(); //read length, only 32bits length support yet
                 st_tos_mts_info_t* audioInfo = NULL;
				 
                 if(_audio_info_len > 0) {
                    Parcel::ReadableBlob _pass_rblob;
                    data.readBlob(_audio_info_len,&_pass_rblob);
                    audioInfo = (st_tos_mts_info_t*)_pass_rblob.data();
                }
				
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_mts_info( audioInfo, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_mts_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_language_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_language_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support un-plat struct info yet, please add code yourself
                //#if your struct is plat, do not mark it as a struct

                int16_t _aud_lang_len = (int16_t)data.readInt32();  //int16_t as input paramter
                st_tos_audio_language_info* info = NULL;
				
                if(_aud_lang_len > 0) {
                    reply->writeInt32(_aud_lang_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_aud_lang_len,&_value_wblob);
                    info = (st_tos_audio_language_info*)_value_wblob.data();
					memset(info, 0, _aud_lang_len);
                }
				// re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result ;
				if( info != NULL ){
					_result = tos_audio_get_language_info( info );
					}else{
					_result = FPI_ERROR_PROXY_SBINDER_NULL ;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_language_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_language_index:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_language_index here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t audioIndex = (uint8_t)data.readInt32();  //uint8_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_language_index( audioIndex, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_language_index here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_scene:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_scene here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_SCENE scene yet, please add code yourself
                 int _scene_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_AUDIO_SCENE* scene = NULL;
				
                if(_scene_len > 0) {
                    reply->writeInt32(_scene_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_scene_len,&_value_wblob);
                    scene = (EN_TOS_AUDIO_SCENE*)_value_wblob.data();
                }
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_scene( scene );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_scene here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_scene:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_scene here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              //#error not support this type of paramter EN_TOS_AUDIO_SCENE scene yet, please add code yourself
                EN_TOS_AUDIO_SCENE scene =(EN_TOS_AUDIO_SCENE)data.readInt32();
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_scene( scene, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_scene here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_dev_plugin:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_dev_plugin here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
              // #error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev =  (EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
                int _isplugin_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* isplugin = NULL;

                Parcel::WritableBlob _isplugin_wblob;

                if(_isplugin_len > 0) {
                    reply->writeInt32(_isplugin_len);
                    reply->writeBlob(_isplugin_len,&_isplugin_wblob);
                    isplugin = (int16_t*)_isplugin_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                isplugin = (int16_t*)_isplugin_wblob.data();
                fpi_error _result = tos_audio_get_dev_plugin( dev, isplugin );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_dev_plugin here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_source_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_source_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_AUDIO_INPUT_INFO type yet, please add code yourself
                EN_TOS_AUDIO_INPUT_INFO type = (EN_TOS_AUDIO_INPUT_INFO)data.readInt32();
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_source_info( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_source_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_language_information:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_language_information here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_API_SOURCE_INPUT input yet, please add code yourself
                EN_API_SOURCE_INPUT input =(EN_API_SOURCE_INPUT)data.readInt32();
               // #error not support un-plat struct dAudioInfo yet, please add code yourself
              //  #if your struct is plat, do not mark it as a struct
 
                int16_t _dAudio_info_len = (int16_t)data.readInt32();  //int16_t as input paramter

                 st_audio_language_information* dAudioInfo = NULL;
                if(_dAudio_info_len > 0) {
                    reply->writeInt32(_dAudio_info_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_dAudio_info_len,&_value_wblob);
                    dAudioInfo = (st_audio_language_information*)_value_wblob.data();
                }
				// re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_language_information( input, dAudioInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_language_information here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_language_information:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_language_information here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            //#error not support this type of paramter EN_API_SOURCE_INPUT input yet, please add code yourself
                EN_API_SOURCE_INPUT input =(EN_API_SOURCE_INPUT)data.readInt32();
              //  #error not support un-plat struct dAudioInfo yet, please add code yourself
               // #if your struct is plat, do not mark it as a struct
                int _dAudio_info_len = data.readInt32(); //read length, only 32bits length support yet
                 st_audio_language_information* dAudioInfo = NULL;
                if(_dAudio_info_len > 0) {
                    Parcel::ReadableBlob _pass_rblob;
                    data.readBlob(_dAudio_info_len,&_pass_rblob);
                    dAudioInfo = (st_audio_language_information*)_pass_rblob.data();
                }
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_language_information( input, dAudioInfo, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_language_information here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_audio_set_speaker_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_speaker_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_speaker_enable( enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_speaker_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_speaker_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_speaker_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;

                Parcel::WritableBlob _enable_wblob;

                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enable = (int16_t*)_enable_wblob.data();
                fpi_error _result = tos_audio_get_speaker_enable( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_speaker_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_dtv_stereo_sound_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_dtv_stereo_sound_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               //#error not support this type of paramter EN_TOS_DTV_STEREO_MODE mode yet, please add code yourself
                EN_TOS_DTV_STEREO_MODE mode =(EN_TOS_DTV_STEREO_MODE)data.readInt32();
				
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_dtv_stereo_sound_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_dtv_stereo_sound_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_output_device_mix_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_output_device_mix_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list

			    EN_TOS_AUDIO_DEVICE_TYPE dev =(EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
			    EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type =(EN_TOS_AUDIO_DECODER_CHANNEL_TYPE)data.readInt32();

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_output_device_mix_type( dev, decoder_type, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_output_device_mix_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_output_device_mix_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_output_device_mix_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_AUDIO_DEVICE_TYPE dev =(EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();

				int _decoder_type_len = data.readInt32(); //read length, only 32bits length support yet
				
                EN_TOS_AUDIO_DECODER_CHANNEL_TYPE* decoder_type = NULL;
				
                if(_decoder_type_len > 0) {
                    reply->writeInt32(_decoder_type_len);
                    Parcel::WritableBlob _decoder_type_wblob;
                    reply->writeBlob(_decoder_type_len,&_decoder_type_wblob);
                    decoder_type = (EN_TOS_AUDIO_DECODER_CHANNEL_TYPE*)_decoder_type_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_output_device_mix_type( dev, decoder_type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_output_device_mix_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_audDevice_output_onOff:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_audDevice_output_onOff here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
                EN_TOS_AUDIO_DEVICE_TYPE dev =(EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();
                //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status yet, please add code yourself
				EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status =(EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS)data.readInt32();
				
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_audDevice_output_onOff( dev, status, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_audDevice_output_onOff here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_audDevice_output_onOff:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_audDevice_output_onOff here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself

                //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status yet, please add code yourself

				//begin paramters list
                EN_TOS_AUDIO_DEVICE_TYPE dev =(EN_TOS_AUDIO_DEVICE_TYPE)data.readInt32();

				int _status_len = data.readInt32(); //read length, only 32bits length support yet
				
                EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS* status = NULL;
				
                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    Parcel::WritableBlob _status_wblob;
                    reply->writeBlob(_status_len,&_status_wblob);
                    status = (EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS*)_status_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_audDevice_output_onOff( dev, status );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_audDevice_output_onOff here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

		    case TRANSACTION_tos_audio_set_value:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_value here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_VALUE_TYPE type yet, please add code yourself
                EN_TOS_AUDIO_VALUE_TYPE type =(EN_TOS_AUDIO_VALUE_TYPE)data.readInt32();
                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_value( type, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_value here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_value:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_value here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_AUDIO_VALUE_TYPE type yet, please add code yourself
                EN_TOS_AUDIO_VALUE_TYPE type =(EN_TOS_AUDIO_VALUE_TYPE)data.readInt32();
				
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_value( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_value here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_tcl_sound_effects_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_tcl_sound_effects_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // #error not support this type of paramter EN_TOS_TCL_SUDEFFECT_TYPE type yet, please add code yourself
                EN_TOS_TCL_SUDEFFECT_TYPE type =(EN_TOS_TCL_SUDEFFECT_TYPE)data.readInt32();
                // #error not support this type of paramter EN_TOS_TCL_SUDEFFECT_MODE mode yet, please add code yourself
                EN_TOS_TCL_SUDEFFECT_MODE mode =(EN_TOS_TCL_SUDEFFECT_MODE)data.readInt32();
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_tcl_sound_effects_mode( type, mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_tcl_sound_effects_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_tcl_sound_effects_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_tcl_sound_effects_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_TCL_SUDEFFECT_TYPE type yet, please add code yourself
                EN_TOS_TCL_SUDEFFECT_TYPE type =(EN_TOS_TCL_SUDEFFECT_TYPE)data.readInt32();
				
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_TCL_SUDEFFECT_MODE* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_TOS_TCL_SUDEFFECT_MODE*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (EN_TOS_TCL_SUDEFFECT_MODE*)_mode_wblob.data();
                fpi_error _result = tos_audio_get_tcl_sound_effects_mode( type, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_tcl_sound_effects_mode here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_set_spdif_dobly_digital_plus_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_spdif_dobly_digital_plus_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_SPDIF_DDP_MODE mode yet, please add code yourself
                EN_TOS_SPDIF_DDP_MODE mode =(EN_TOS_SPDIF_DDP_MODE)data.readInt32();
			
                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_spdif_dobly_digital_plus_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_spdif_dobly_digital_plus_mode here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_spdif_dobly_digital_plus_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_spdif_dobly_digital_plus_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_SPDIF_DDP_MODE mode yet, please add code yourself
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
			    EN_TOS_SPDIF_DDP_MODE* mode = NULL;
				
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_TOS_SPDIF_DDP_MODE*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_get_spdif_dobly_digital_plus_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_spdif_dobly_digital_plus_mode here --
                return NO_ERROR;
            } break;
			
			 case TRANSACTION_tos_audio_set_dobly_ms12_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_set_dobly_ms12_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_DOLBY_MS12_SETTING_TYPE type yet, please add code yourself
                EN_TOS_DOLBY_MS12_SETTING_TYPE type =(EN_TOS_DOLBY_MS12_SETTING_TYPE)data.readInt32();
				
                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_set_dobly_ms12_setting( type, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_set_dobly_ms12_setting here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_get_dobly_ms12_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_get_dobly_ms12_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support this type of paramter EN_TOS_DOLBY_MS12_SETTING_TYPE type yet, please add code yourself
                EN_TOS_DOLBY_MS12_SETTING_TYPE type =(EN_TOS_DOLBY_MS12_SETTING_TYPE)data.readInt32();

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int16_t*)_value_wblob.data();
                fpi_error _result = tos_audio_get_dobly_ms12_setting( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_get_dobly_ms12_setting here --
                return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_audio_reset_sound_setting:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_audio_reset_sound_setting here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_audio_reset_sound_setting( );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_audio_reset_sound_setting here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_sound_setting_service_add() {
    sbinder_sound_setting_service::Instance();
    return 0;
}

sbinder_sound_setting_service* sbinder_sound_setting_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_sound_setting_client  
{  
private:
    static sbinder_sound_setting_client* _instance;
    sp<IBinder> _binder;

    sbinder_sound_setting_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_sound_setting_client() {
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
    static sbinder_sound_setting_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_sound_setting_client();
        }

        return _instance;
    }

    fpi_error tos_audio_set_mute( int16_t mute_level, int16_t mute, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_mute here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mute_level);  //int16_t as input paramter

            data.writeInt32(mute);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_mute,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_mute error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_mute error");
        }

        return _result;
        /*-- add you code for tos_audio_set_mute here --*/
    }

    fpi_error tos_audio_get_mute( int16_t mute_level, int16_t* mute ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_mute here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mute_level);  //int16_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (mute == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_mute,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mute != NULL) {
                    int _mute_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mute_rblob;
                    reply.readBlob(_mute_len,&_mute_rblob);
                    memcpy(mute,_mute_rblob.data(),_mute_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_mute error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_mute error");
        }

        return _result;
        /*-- add you code for tos_audio_get_mute here --*/
    }

    fpi_error tos_audio_set_volume( int16_t vol, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(vol);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_set_volume here --*/
    }

    fpi_error tos_audio_get_volume( int16_t* soundValue ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (soundValue == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (soundValue != NULL) {
                    int _soundValue_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _soundValue_rblob;
                    reply.readBlob(_soundValue_len,&_soundValue_rblob);
                    memcpy(soundValue,_soundValue_rblob.data(),_soundValue_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_get_volume here --*/
    }

    fpi_error tos_audio_set_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev,  char* ch_reason, int16_t b_mute, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_mute_ex here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

             //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE en_dev yet, please add code yourself
            data.writeInt32(en_dev);

            //for out only, only write length ; for in, alloc and copy
            if (ch_reason == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(ch_reason)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _ch_reason_wblob;
                data.writeBlob((strlen(ch_reason)+1) * sizeof(char),&_ch_reason_wblob);
                memcpy(_ch_reason_wblob.data(),ch_reason,(strlen(ch_reason)+1)* sizeof(char));
            }

            data.writeInt32(b_mute);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_mute_ex,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_mute_ex error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_mute_ex error");
        }

        return _result;
        /*-- add you code for tos_audio_set_mute_ex here --*/
    }

    fpi_error tos_audio_get_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev, char* mute_reason, int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_mute_ex here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE en_dev yet, please add code yourself
            data.writeInt32(en_dev);

            //for out only, only write length ; for in, alloc and copy
            if (mute_reason == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(mute_reason)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _mute_reason_wblob;
                data.writeBlob((strlen(mute_reason)+1) * sizeof(char),&_mute_reason_wblob);
                memcpy(_mute_reason_wblob.data(),mute_reason,(strlen(mute_reason)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_mute_ex,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_mute_ex error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_mute_ex error");
        }

        return _result;
        /*-- add you code for tos_audio_get_mute_ex here --*/
    }

    fpi_error tos_audio_set_volume_ex( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input, int16_t volume, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_volume_ex here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(dev);
            data.writeInt32(input);  //int16_t as input paramter

            data.writeInt32(volume);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_volume_ex,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_volume_ex error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_volume_ex error");
        }

        return _result;
        /*-- add you code for tos_audio_set_volume_ex here --*/
    }

    fpi_error tos_audio_get_volume_ex( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input, int16_t* volume ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_volume_ex here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(dev);
            data.writeInt32(input);  //int16_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (volume == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet 
            }

            _binder->transact(TRANSACTION_tos_audio_get_volume_ex,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (volume != NULL) {
                    int _volume_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _volume_rblob;
                    reply.readBlob(_volume_len,&_volume_rblob);
                    memcpy(volume,_volume_rblob.data(),_volume_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_volume_ex error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_volume_ex error");
        }

        return _result;
        /*-- add you code for tos_audio_get_volume_ex here --*/
    }

    fpi_error tos_audio_get_max_volume( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_max_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            data.writeInt32(dev);
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_audio_get_max_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_max_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_max_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_get_max_volume here --*/
    }

    fpi_error tos_audio_set_max_volume( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t maxVolume, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_max_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            data.writeInt32(dev);
            data.writeInt32(maxVolume);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_max_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_max_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_max_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_set_max_volume here --*/
    }

    fpi_error tos_audio_set_input_mute( EN_TOS_AUDIO_INPUT input, int16_t mute, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_input_mute here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
            data.writeInt32(input);
            data.writeInt32(mute);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_input_mute,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_input_mute error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_input_mute error");
        }

        return _result;
        /*-- add you code for tos_audio_set_input_mute here --*/
    }

    fpi_error tos_audio_get_input_mute( EN_TOS_AUDIO_INPUT input, int16_t* mute ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_input_mute here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            data.writeInt32(input);
           // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself

            //for out only, only write length ; for in, alloc and copy
            if (mute == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_input_mute,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mute != NULL) {
                    int _mute_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mute_rblob;
                    reply.readBlob(_mute_len,&_mute_rblob);
                    memcpy(mute,_mute_rblob.data(),_mute_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_input_mute error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_input_mute error");
        }

        return _result;
        /*-- add you code for tos_audio_get_input_mute here --*/
    }

    fpi_error tos_audio_set_input_volume( EN_TOS_AUDIO_INPUT input, int16_t soundValue, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_input_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
            data.writeInt32(input);
            data.writeInt32(soundValue);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_input_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_input_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_input_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_set_input_volume here --*/
    }

    fpi_error tos_audio_get_input_volume( EN_TOS_AUDIO_INPUT input, int16_t* soundValue ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_input_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_INPUT input yet, please add code yourself
           data.writeInt32(input);   
            //for out only, only write length ; for in, alloc and copy
            if (soundValue == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_input_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (soundValue != NULL) {
                    int _soundValue_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _soundValue_rblob;
                    reply.readBlob(_soundValue_len,&_soundValue_rblob);
                    memcpy(soundValue,_soundValue_rblob.data(),_soundValue_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_input_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_input_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_get_input_volume here --*/
    }

    fpi_error tos_audio_set_equalizer_mode( EN_TOS_SOUND_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_equalizer_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SOUND_MODE mode yet, please add code yourself
            data.writeInt32(mode);
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_equalizer_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_equalizer_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_equalizer_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_set_equalizer_mode here --*/
    }

    fpi_error tos_audio_get_equalizer_mode( EN_TOS_SOUND_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_equalizer_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SOUND_MODE value yet, please add code yourself
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_SOUND_MODE));//write length, only support 32 bits length yet  
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_equalizer_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter EN_TOS_SOUND_MODE value yet, please add code yourself
                 if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
				 
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_equalizer_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_equalizer_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_get_equalizer_mode here --*/
    }

    fpi_error tos_audio_set_equalizer( EN_TOS_SOUND_EQUALIZER_TYPE type, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_equalizer here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SOUND_EQUALIZER_TYPE type yet, please add code yourself
             data.writeInt32(type);
			
            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_equalizer,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_equalizer error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_equalizer error");
        }

        return _result;
        /*-- add you code for tos_audio_set_equalizer here --*/
    }

    fpi_error tos_audio_get_equalizer( EN_TOS_SOUND_EQUALIZER_TYPE type, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_equalizer here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SOUND_EQUALIZER_TYPE type yet, please add code yourself
             data.writeInt32(type);
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_equalizer,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_equalizer error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_equalizer error");
        }

        return _result;
        /*-- add you code for tos_audio_get_equalizer here --*/
    }

    fpi_error tos_audio_set_balance( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_balance here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            data.writeInt32(dev);
            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_balance,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_balance error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_balance error");
        }

        return _result;
        /*-- add you code for tos_audio_set_balance here --*/
    }

    fpi_error tos_audio_get_balance( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_balance here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
             data.writeInt32(dev);
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_balance,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_balance error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_balance error");
        }

        return _result;
        /*-- add you code for tos_audio_get_balance here --*/
    }

    fpi_error tos_audio_set_auto_volume( int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_auto_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_auto_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_auto_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_auto_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_set_auto_volume here --*/
    }

    fpi_error tos_audio_get_auto_volume( int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_auto_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_auto_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_auto_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_auto_volume error");
        }

        return _result;
        /*-- add you code for tos_audio_get_auto_volume here --*/
    }

    fpi_error tos_audio_set_delay( EN_TOS_AUDIO_DEVICE_TYPE dev, int32_t delay, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_delay here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            data.writeInt32(dev);
            data.writeInt32(delay);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_delay,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_delay error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_delay error");
        }

        return _result;
        /*-- add you code for tos_audio_set_delay here --*/
    }

    fpi_error tos_audio_get_delay( EN_TOS_AUDIO_DEVICE_TYPE dev, int32_t* delay ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_delay here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            data.writeInt32(dev);
            //for out only, only write length ; for in, alloc and copy
            if (delay == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_delay,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (delay != NULL) {
                    int _delay_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _delay_rblob;
                    reply.readBlob(_delay_len,&_delay_rblob);
                    memcpy(delay,_delay_rblob.data(),_delay_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_delay error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_delay error");
        }

        return _result;
        /*-- add you code for tos_audio_get_delay here --*/
    }

    fpi_error tos_audio_set_wide_stereo( EN_TOS_STEREO_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_wide_stereo here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_STEREO_MODE mode yet, please add code yourself
            data.writeInt32(mode);
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_wide_stereo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_wide_stereo error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_wide_stereo error");
        }

        return _result;
        /*-- add you code for tos_audio_set_wide_stereo here --*/
    }

    fpi_error tos_audio_get_wide_stereo( EN_TOS_STEREO_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_wide_stereo here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_STEREO_MODE value yet, please add code yourself
             if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_STEREO_MODE));//write length, only support 32 bits length yet  
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_wide_stereo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter EN_TOS_STEREO_MODE value yet, please add code yourself
                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }	
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_wide_stereo error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_wide_stereo error");
        }

        return _result;
        /*-- add you code for tos_audio_get_wide_stereo here --*/
    }

    fpi_error tos_audio_set_spdif_type( EN_TOS_SPDIF_TYPE type, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_spdif_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SPDIF_TYPE type yet, please add code yourself
             data.writeInt32(type);
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_spdif_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_spdif_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_spdif_type error");
        }

        return _result;
        /*-- add you code for tos_audio_set_spdif_type here --*/
    }

    fpi_error tos_audio_get_spdif_type( EN_TOS_SPDIF_TYPE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_spdif_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_SPDIF_TYPE value yet, please add code yourself
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_SPDIF_TYPE));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_spdif_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter EN_TOS_SPDIF_TYPE value yet, please add code yourself
                 if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_spdif_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_spdif_type error");
        }

        return _result;
        /*-- add you code for tos_audio_get_spdif_type here --*/
    }

    fpi_error tos_audio_get_visual_impaired( int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_visual_impaired here --*/
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
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_visual_impaired,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_visual_impaired error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_visual_impaired error");
        }

        return _result;
        /*-- add you code for tos_audio_get_visual_impaired here --*/
    }

    fpi_error tos_audio_set_visual_impaired( int16_t state, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_visual_impaired here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(state);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_visual_impaired,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_visual_impaired error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_visual_impaired error");
        }

        return _result;
        /*-- add you code for tos_audio_set_visual_impaired here --*/
    }

    fpi_error tos_audio_set_audio_description( int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_audio_description here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_audio_description,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_audio_description error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_audio_description error");
        }

        return _result;
        /*-- add you code for tos_audio_set_audio_description here --*/
    }

    fpi_error tos_audio_get_audio_description( int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_audio_description here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_audio_description,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_audio_description error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_audio_description error");
        }

        return _result;
        /*-- add you code for tos_audio_get_audio_description here --*/
    }

    fpi_error tos_audio_set_audio_description_mix_level( uint16_t level, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_audio_description_mix_level here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(level);  //uint16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_audio_description_mix_level,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_audio_description_mix_level error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_audio_description_mix_level error");
        }

        return _result;
        /*-- add you code for tos_audio_set_audio_description_mix_level here --*/
    }

    fpi_error tos_audio_get_audio_description_mix_level( uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_audio_description_mix_level here --*/
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
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_audio_description_mix_level,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_audio_description_mix_level error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_audio_description_mix_level error");
        }

        return _result;
        /*-- add you code for tos_audio_get_audio_description_mix_level here --*/
    }

    fpi_error tos_audio_get_mts_info( st_tos_mts_info_t* audioInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_mts_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support un-plat struct audioInfo yet, please add code yourself #if your struct is plat, do not mark it as a struct
             //for out only, only write length ; for in, alloc and copy
            if (audioInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1)*sizeof(st_tos_mts_info_t));//write length, only support 32 bits length yet
            }
	
            _binder->transact(TRANSACTION_tos_audio_get_mts_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (audioInfo != NULL) {
                    int _audioInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _audioInfo_rblob;
                    reply.readBlob(_audioInfo_len,&_audioInfo_rblob);
                    memcpy(audioInfo,_audioInfo_rblob.data(),_audioInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_mts_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_mts_info error");
        }

        return _result;
        /*-- add you code for tos_audio_get_mts_info here --*/
    }

    fpi_error tos_audio_set_mts_info( st_tos_mts_info_t* audioInfo, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_mts_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support un-plat struct audioInfo yet, please add code yourself
            //#if your struct is plat, do not mark it as a struct
                 //for out only, only write length ; for in, alloc and copy
            if (audioInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_tos_mts_info_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _audioInfo_wblob;
                data.writeBlob(sizeof(st_tos_mts_info_t),&_audioInfo_wblob);
                memcpy(_audioInfo_wblob.data(),audioInfo,(sizeof(st_tos_mts_info_t)));
            }
			
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_mts_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_mts_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_mts_info error");
        }

        return _result;
        /*-- add you code for tos_audio_set_mts_info here --*/
    }

    fpi_error tos_audio_get_language_info( st_tos_audio_language_info* info ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_language_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support un-plat struct info yet, please add code yourself #if your struct is plat, do not mark it as a struct
              if (info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1)*sizeof(st_tos_audio_language_info));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_audio_get_language_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (info != NULL) {
                    int _info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _info_rblob;
                    reply.readBlob(_info_len,&_info_rblob);
                    memcpy(info,_info_rblob.data(),_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_language_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_language_info error");
        }

        return _result;
        /*-- add you code for tos_audio_get_language_info here --*/
    }

    fpi_error tos_audio_set_language_index( uint8_t audioIndex, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_language_index here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(audioIndex);  //uint8_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_language_index,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_language_index error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_language_index error");
        }

        return _result;
        /*-- add you code for tos_audio_set_language_index here --*/
    }

    fpi_error tos_audio_get_scene( EN_TOS_AUDIO_SCENE* scene ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_scene here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_SCENE scene yet, please add code yourself
               if (scene == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1)*sizeof(EN_TOS_AUDIO_SCENE));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_scene,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

               // #error not support this type of output paramter EN_TOS_AUDIO_SCENE scene yet, please add code yourself
                  if (scene != NULL) {
                    int _info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _info_rblob;
                    reply.readBlob(_info_len,&_info_rblob);
                    memcpy(scene,_info_rblob.data(),_info_len);
                }
				  
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_scene error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_scene error");
        }

        return _result;
        /*-- add you code for tos_audio_get_scene here --*/
    }

    fpi_error tos_audio_set_scene( EN_TOS_AUDIO_SCENE scene, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_scene here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_SCENE scene yet, please add code yourself
            data.writeInt32(scene);
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_scene,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_scene error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_scene error");
        }

        return _result;
        /*-- add you code for tos_audio_set_scene here --*/
    }

    fpi_error tos_audio_get_dev_plugin( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* isplugin ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_dev_plugin here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
             data.writeInt32(dev);
            //for out only, only write length ; for in, alloc and copy
            if (isplugin == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_dev_plugin,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (isplugin != NULL) {
                    int _isplugin_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _isplugin_rblob;
                    reply.readBlob(_isplugin_len,&_isplugin_rblob);
                    memcpy(isplugin,_isplugin_rblob.data(),_isplugin_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_dev_plugin error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_dev_plugin error");
        }

        return _result;
        /*-- add you code for tos_audio_get_dev_plugin here --*/
    }

    fpi_error tos_audio_get_source_info( EN_TOS_AUDIO_INPUT_INFO type, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_source_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_AUDIO_INPUT_INFO type yet, please add code yourself
             data.writeInt32(type);
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_source_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_source_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_source_info error");
        }

        return _result;
        /*-- add you code for tos_audio_get_source_info here --*/
    }

    fpi_error tos_audio_get_language_information( EN_API_SOURCE_INPUT input, st_audio_language_information* dAudioInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_language_information here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_API_SOURCE_INPUT input yet, please add code yourself
            data.writeInt32(input);
           // #error not support un-plat struct dAudioInfo yet, please add code yourself #if your struct is plat, do not mark it as a struct

	     if (dAudioInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_audio_language_information));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_audio_get_language_information,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (dAudioInfo != NULL) {
                    int _dAudioInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _dAudioInfo_rblob;
                    reply.readBlob(_dAudioInfo_len,&_dAudioInfo_rblob);
                    memcpy(dAudioInfo,_dAudioInfo_rblob.data(),_dAudioInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_language_information error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_language_information error");
        }

        return _result;
        /*-- add you code for tos_audio_get_language_information here --*/
    }

    fpi_error tos_audio_set_language_information( EN_API_SOURCE_INPUT input, st_audio_language_information* dAudioInfo, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_language_information here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_API_SOURCE_INPUT input yet, please add code yourself
            data.writeInt32(input);
            //#error not support un-plat struct dAudioInfo yet, please add code yourself #if your struct is plat, do not mark it as a struct
	    if (dAudioInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_audio_language_information));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _lang_info_wblob;
                data.writeBlob(sizeof(st_audio_language_information),&_lang_info_wblob);
                memcpy(_lang_info_wblob.data(),dAudioInfo,(1)* sizeof(st_audio_language_information));
            }
			
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_language_information,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_language_information error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_language_information error");
        }

        return _result;
        /*-- add you code for tos_audio_set_language_information here --*/
    }

    fpi_error tos_audio_set_speaker_enable( int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_speaker_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_speaker_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_speaker_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_speaker_enable error");
        }

        return _result;
        /*-- add you code for tos_audio_set_speaker_enable here --*/
    }

    fpi_error tos_audio_get_speaker_enable( int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_speaker_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_speaker_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_speaker_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_speaker_enable error");
        }

        return _result;
        /*-- add you code for tos_audio_get_speaker_enable here --*/
    }

    fpi_error tos_audio_set_dtv_stereo_sound_mode( EN_TOS_DTV_STEREO_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_dtv_stereo_sound_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_DTV_STEREO_MODE mode yet, please add code yourself
            data.writeInt32(mode);  //int16_t as input paramter
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_dtv_stereo_sound_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_dtv_stereo_sound_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_dtv_stereo_sound_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_set_dtv_stereo_sound_mode here --*/
    }

    fpi_error tos_audio_set_output_device_mix_type( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_output_device_mix_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself

           // #error not support this type of paramter EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type yet, please add code yourself

			data.writeInt32(dev);  //int16_t as input paramter
            data.writeInt32(decoder_type);  //EN_ACT_CTRL as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_output_device_mix_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_set_output_device_mix_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_set_output_device_mix_type error");
        }

        return _result;
        /*-- add you code for tos_audio_set_output_device_mix_type here --*/
    }

    fpi_error tos_audio_get_output_device_mix_type( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DECODER_CHANNEL_TYPE* decoder_type ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_output_device_mix_type here --*/
       fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
			//#error not support this type of paramter EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type yet, please add code yourself
            data.writeInt32(dev);  //int16_t as input paramter

			if (decoder_type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_AUDIO_DECODER_CHANNEL_TYPE));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_output_device_mix_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                 if (decoder_type != NULL) {
                    int _decoder_type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _decoder_type_rblob;
                    reply.readBlob(_decoder_type_len,&_decoder_type_rblob);
                    memcpy(decoder_type,_decoder_type_rblob.data(),_decoder_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_audio_get_output_device_mix_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_audio_get_output_device_mix_type error");
        }

        return _result;
        /*-- add you code for tos_audio_get_output_device_mix_type here --*/
    }

   fpi_error tos_audio_set_audDevice_output_onOff( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status, EN_ACT_CTRL act ) {
        Parcel data, reply;

		 /*-- add you code for tos_audio_set_audDevice_output_onOff here --*/
		fpi_error _result = FPI_ERROR_FAIL;
		 if(!getService()) {
			 return _result;
		 }


        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself
            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status yet, please add code yourself
			data.writeInt32(dev);  //int16_t as input paramter
            data.writeInt32(status);  //EN_ACT_CTRL as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_audDevice_output_onOff,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_set_audDevice_output_onOff error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_set_audDevice_output_onOff error");
        }

        return _result;
        /*-- add you code for tos_audio_set_audDevice_output_onOff here --*/
    }

    fpi_error tos_audio_get_audDevice_output_onOff( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS* status ) {
        Parcel data, reply;

		 /*-- add you code for tos_audio_get_audDevice_output_onOff here --*/
		fpi_error _result = FPI_ERROR_FAIL;
		 if(!getService()) {
			 return _result;
		 }


        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_TYPE dev yet, please add code yourself

            //#error not support this type of paramter EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status yet, please add code yourself
            data.writeInt32(dev);  //int16_t as input paramter

			if (status == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_tos_audio_get_audDevice_output_onOff,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                 if (status != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(status,_status_rblob.data(),_status_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_get_audDevice_output_onOff error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_get_audDevice_output_onOff error");
        }

        return _result;
        /*-- add you code for tos_audio_get_audDevice_output_onOff here --*/
    }

    fpi_error tos_audio_set_value( EN_TOS_AUDIO_VALUE_TYPE type, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_value here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_VALUE_TYPE type yet, please add code yourself
            data.writeInt32(type); 
            
            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_value,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_set_value error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_set_value error");
        }

        return _result;
        /*-- add you code for tos_audio_set_value here --*/
    }

    fpi_error tos_audio_get_value( EN_TOS_AUDIO_VALUE_TYPE type, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_value here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_AUDIO_VALUE_TYPE type yet, please add code yourself
            data.writeInt32(type); 
			
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_value,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_get_value error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_get_value error");
        }

        return _result;
        /*-- add you code for tos_audio_get_value here --*/
    }

    fpi_error tos_audio_set_tcl_sound_effects_mode( EN_TOS_TCL_SUDEFFECT_TYPE type, EN_TOS_TCL_SUDEFFECT_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_tcl_sound_effects_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_TCL_SUDEFFECT_TYPE type yet, please add code yourself
            data.writeInt32(type);
            //error not support this type of paramter EN_TOS_TCL_SUDEFFECT_MODE mode yet, please add code yourself
            data.writeInt32(mode);
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_tcl_sound_effects_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_set_tcl_sound_effects_mode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_set_tcl_sound_effects_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_set_tcl_sound_effects_mode here --*/
    }

    fpi_error tos_audio_get_tcl_sound_effects_mode( EN_TOS_TCL_SUDEFFECT_TYPE type, EN_TOS_TCL_SUDEFFECT_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_tcl_sound_effects_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_TCL_SUDEFFECT_TYPE type yet, please add code yourself
            data.writeInt32(type);
            //for out only, only write length ; for in, alloc and copy
            if (mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_TCL_SUDEFFECT_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_tcl_sound_effects_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_get_tcl_sound_effects_mode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_get_tcl_sound_effects_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_get_tcl_sound_effects_mode here --*/
    }

    fpi_error tos_audio_set_spdif_dobly_digital_plus_mode( EN_TOS_SPDIF_DDP_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_spdif_dobly_digital_plus_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_SPDIF_DDP_MODE mode yet, please add code yourself
            data.writeInt32(mode);
			
            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_spdif_dobly_digital_plus_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_set_spdif_dobly_digital_plus_mode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_set_spdif_dobly_digital_plus_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_set_spdif_dobly_digital_plus_mode here --*/
    }

    fpi_error tos_audio_get_spdif_dobly_digital_plus_mode( EN_TOS_SPDIF_DDP_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_spdif_dobly_digital_plus_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter EN_TOS_SPDIF_DDP_MODE mode yet, please add code yourself
            if (mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_SPDIF_DDP_MODE));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_audio_get_spdif_dobly_digital_plus_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter EN_TOS_SPDIF_TYPE value yet, please add code yourself
                 if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_get_spdif_dobly_digital_plus_mode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_get_spdif_dobly_digital_plus_mode error");
        }

        return _result;
        /*-- add you code for tos_audio_get_spdif_dobly_digital_plus_mode here --*/
    }

    fpi_error tos_audio_set_dobly_ms12_setting( EN_TOS_DOLBY_MS12_SETTING_TYPE type, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_set_dobly_ms12_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_DOLBY_MS12_SETTING_TYPE type yet, please add code yourself
			data.writeInt32(type);
			
            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_audio_set_dobly_ms12_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_set_dobly_ms12_setting error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_set_dobly_ms12_setting error");
        }

        return _result;
        /*-- add you code for tos_audio_set_dobly_ms12_setting here --*/
    }

    fpi_error tos_audio_get_dobly_ms12_setting( EN_TOS_DOLBY_MS12_SETTING_TYPE type, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_get_dobly_ms12_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_TOS_DOLBY_MS12_SETTING_TYPE type yet, please add code yourself
			data.writeInt32(type);
			
            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_audio_get_dobly_ms12_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_get_dobly_ms12_setting error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_get_dobly_ms12_setting error");
        }

        return _result;
        /*-- add you code for tos_audio_get_dobly_ms12_setting here --*/
    }

    fpi_error tos_audio_reset_sound_setting(  ) {
        Parcel data, reply;

        /*-- add you code for tos_audio_reset_sound_setting here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_audio_reset_sound_setting,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_audio_reset_sound_setting error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_audio_reset_sound_setting error");
        }

        return _result;
        /*-- add you code for tos_audio_reset_sound_setting here --*/
    }
};

sbinder_sound_setting_client* sbinder_sound_setting_client::_instance = NULL;

fpi_error tos_audio_set_mute( int16_t mute_level, int16_t mute, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_mute(mute_level, mute, act);
}
fpi_error tos_audio_get_mute( int16_t mute_level, int16_t* mute ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_mute(mute_level, mute);
}
fpi_error tos_audio_set_volume( int16_t vol, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_volume(vol, act);
}
fpi_error tos_audio_get_volume( int16_t* soundValue ) {   
    return sbinder_sound_setting_client::Instance()->tos_audio_get_volume(soundValue);
}
fpi_error tos_audio_set_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev, char* ch_reason, int16_t b_mute, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_mute_ex(en_dev, ch_reason, b_mute, act);
}
fpi_error tos_audio_get_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev, char* mute_reason, int16_t* state ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_mute_ex(en_dev, mute_reason, state);
}
fpi_error tos_audio_set_volume_ex( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input, int16_t volume, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_volume_ex(dev, input, volume, act);
}
fpi_error tos_audio_get_volume_ex( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input, int16_t* volume ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_volume_ex(dev, input, volume);
}
fpi_error tos_audio_get_max_volume( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_max_volume(dev, value);
}
fpi_error tos_audio_set_max_volume( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t maxVolume, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_max_volume(dev, maxVolume, act);
}
fpi_error tos_audio_set_input_mute( EN_TOS_AUDIO_INPUT input, int16_t mute, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_input_mute(input, mute, act);
}
fpi_error tos_audio_get_input_mute( EN_TOS_AUDIO_INPUT input, int16_t* mute ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_input_mute(input, mute);
}
fpi_error tos_audio_set_input_volume( EN_TOS_AUDIO_INPUT input, int16_t soundValue, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_input_volume(input, soundValue, act);
}
fpi_error tos_audio_get_input_volume( EN_TOS_AUDIO_INPUT input, int16_t* soundValue ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_input_volume(input, soundValue);
}
fpi_error tos_audio_set_equalizer_mode( EN_TOS_SOUND_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_equalizer_mode(mode, act);
}
fpi_error tos_audio_get_equalizer_mode( EN_TOS_SOUND_MODE* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_equalizer_mode(value);
}
fpi_error tos_audio_set_equalizer( EN_TOS_SOUND_EQUALIZER_TYPE type, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_equalizer(type, value, act);
}
fpi_error tos_audio_get_equalizer( EN_TOS_SOUND_EQUALIZER_TYPE type, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_equalizer(type, value);
}
fpi_error tos_audio_set_balance( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_balance(dev, value, act);
}
fpi_error tos_audio_get_balance( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_balance(dev, value);
}
fpi_error tos_audio_set_auto_volume( int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_auto_volume(enable, act);
}
fpi_error tos_audio_get_auto_volume( int16_t* enable ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_auto_volume(enable);
}
fpi_error tos_audio_set_delay( EN_TOS_AUDIO_DEVICE_TYPE dev, int32_t delay, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_delay(dev, delay, act);
}
fpi_error tos_audio_get_delay( EN_TOS_AUDIO_DEVICE_TYPE dev, int32_t* delay ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_delay(dev, delay);
}
fpi_error tos_audio_set_wide_stereo( EN_TOS_STEREO_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_wide_stereo(mode, act);
}
fpi_error tos_audio_get_wide_stereo( EN_TOS_STEREO_MODE* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_wide_stereo(value);
}
fpi_error tos_audio_set_spdif_type( EN_TOS_SPDIF_TYPE type, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_spdif_type(type, act);
}
fpi_error tos_audio_get_spdif_type( EN_TOS_SPDIF_TYPE* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_spdif_type(value);
}
fpi_error tos_audio_get_visual_impaired( int16_t* state ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_visual_impaired(state);
}
fpi_error tos_audio_set_visual_impaired( int16_t state, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_visual_impaired(state, act);
}
fpi_error tos_audio_set_audio_description( int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_audio_description(enable, act);
}
fpi_error tos_audio_get_audio_description( int16_t* enable ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_audio_description(enable);
}
fpi_error tos_audio_set_audio_description_mix_level( uint16_t level, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_audio_description_mix_level(level, act);
}
fpi_error tos_audio_get_audio_description_mix_level( uint16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_audio_description_mix_level(value);
}
fpi_error tos_audio_get_mts_info( st_tos_mts_info_t* audioInfo ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_mts_info(audioInfo);
}
fpi_error tos_audio_set_mts_info( st_tos_mts_info_t* audioInfo, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_mts_info(audioInfo, act);
}
fpi_error tos_audio_get_language_info( st_tos_audio_language_info* info ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_language_info(info);
}
fpi_error tos_audio_set_language_index( uint8_t audioIndex, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_language_index(audioIndex, act);
}
fpi_error tos_audio_get_scene( EN_TOS_AUDIO_SCENE* scene ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_scene(scene);
}
fpi_error tos_audio_set_scene( EN_TOS_AUDIO_SCENE scene, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_scene(scene, act);
}
fpi_error tos_audio_get_dev_plugin( EN_TOS_AUDIO_DEVICE_TYPE dev, int16_t* isplugin ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_dev_plugin(dev, isplugin);
}
fpi_error tos_audio_get_source_info( EN_TOS_AUDIO_INPUT_INFO type, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_source_info(type, value);
}
fpi_error tos_audio_get_language_information( EN_API_SOURCE_INPUT input, st_audio_language_information* dAudioInfo ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_language_information(input, dAudioInfo);
}
fpi_error tos_audio_set_language_information( EN_API_SOURCE_INPUT input, st_audio_language_information* dAudioInfo, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_language_information(input, dAudioInfo, act);
}
fpi_error tos_audio_set_speaker_enable( int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_speaker_enable(enable, act);
}
fpi_error tos_audio_get_speaker_enable( int16_t* enable ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_speaker_enable(enable);
}
fpi_error tos_audio_set_dtv_stereo_sound_mode( EN_TOS_DTV_STEREO_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_dtv_stereo_sound_mode(mode, act);
}
fpi_error tos_audio_set_output_device_mix_type( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_output_device_mix_type(dev, decoder_type, act);
}
fpi_error tos_audio_get_output_device_mix_type( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DECODER_CHANNEL_TYPE* decoder_type ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_output_device_mix_type(dev, decoder_type);
}
fpi_error tos_audio_set_audDevice_output_onOff( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_audDevice_output_onOff(dev, status, act);
}
fpi_error tos_audio_get_audDevice_output_onOff( EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS* status ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_audDevice_output_onOff(dev, status);
}
fpi_error tos_audio_set_value( EN_TOS_AUDIO_VALUE_TYPE type, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_value(type, value, act);
}
fpi_error tos_audio_get_value( EN_TOS_AUDIO_VALUE_TYPE type, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_value(type, value);
}
fpi_error tos_audio_set_tcl_sound_effects_mode( EN_TOS_TCL_SUDEFFECT_TYPE type, EN_TOS_TCL_SUDEFFECT_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_tcl_sound_effects_mode(type, mode, act);
}
fpi_error tos_audio_get_tcl_sound_effects_mode( EN_TOS_TCL_SUDEFFECT_TYPE type, EN_TOS_TCL_SUDEFFECT_MODE* mode ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_tcl_sound_effects_mode(type, mode);
}
fpi_error tos_audio_set_spdif_dobly_digital_plus_mode( EN_TOS_SPDIF_DDP_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_spdif_dobly_digital_plus_mode(mode, act);
}
fpi_error tos_audio_get_spdif_dobly_digital_plus_mode( EN_TOS_SPDIF_DDP_MODE* mode ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_spdif_dobly_digital_plus_mode(mode);
}
fpi_error tos_audio_set_dobly_ms12_setting( EN_TOS_DOLBY_MS12_SETTING_TYPE type, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_set_dobly_ms12_setting(type, value, act);
}
fpi_error tos_audio_get_dobly_ms12_setting( EN_TOS_DOLBY_MS12_SETTING_TYPE type, int16_t* value ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_get_dobly_ms12_setting(type, value);
} 
fpi_error tos_audio_reset_sound_setting(  ) {
    return sbinder_sound_setting_client::Instance()->tos_audio_reset_sound_setting();
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
