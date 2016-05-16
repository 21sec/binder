/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_picture_quality.sidl
 */
 

#define LOG_TAG     "sbinder_picture_quality"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_picture_quality.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_VIDEO);



#define SERVICE_DESCRIPTOR                      "014b5b10-a535-11e4-ac88-005056a84a3b"
#define SERVICE_NAME                            "sbinder_picture_quality"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_pq_set_colortemperature FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_pq_get_colortemperature FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_pq_set_pq_color_paramter FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_pq_get_pq_color_paramter FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_pq_set_gamma FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_pq_get_gamma FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_pq_set_white_balance_gain FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_pq_get_white_balance_gain FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_pq_set_white_balance_offset FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_pq_get_white_balance_offset FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_pq_get_special_effect FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_pq_set_special_effect FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_pq_set_rgb_mode FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_pq_get_rgb_mode FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_pq_set_mpeg_nr FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_pq_get_mpeg_nr FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_pq_set_noise_reduction FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_pq_get_noise_reduction FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_pq_get_memc_config FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_pq_set_memc_config FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_pq_get_memc_effect FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_pq_set_color_gamma_enable FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_pq_get_color_gamma_enable FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_pq_set_color_gamma_interval FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_pq_get_color_gamma_interval FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_pq_set_color_gamma FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_pq_get_color_gamma FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_pq_set_color_space_mode FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_pq_get_color_space_mode FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_pq_set_color_type FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_pq_get_color_type FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_pq_set_color_space FIRST_CALL_TRANSACTION + 32
#define TRANSACTION_tos_pq_get_color_space FIRST_CALL_TRANSACTION + 33
#define TRANSACTION_tos_pq_get_led_motion_clarity FIRST_CALL_TRANSACTION + 34
#define TRANSACTION_tos_pq_set_led_motion_clarity FIRST_CALL_TRANSACTION + 35
#define TRANSACTION_tos_pq_get_motion_mode_is_use FIRST_CALL_TRANSACTION + 36
#define TRANSACTION_tos_pq_set_PQ_demo FIRST_CALL_TRANSACTION + 37
#define TRANSACTION_tos_pq_get_PQ_demo FIRST_CALL_TRANSACTION + 38
#define TRANSACTION_tos_pq_set_memc_effect FIRST_CALL_TRANSACTION + 39

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_picture_quality.h"


class sbinder_picture_quality_service : public BBinder  
{  
private:
    static sbinder_picture_quality_service* _instance;

    sbinder_picture_quality_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_picture_quality_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_picture_quality_service();
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

            case TRANSACTION_tos_pq_set_colortemperature:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_colortemperature here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                EN_FPI_COLOR_TEMPERATURE mode = (EN_FPI_COLOR_TEMPERATURE)data.readInt32();  //EN_FPI_COLOR_TEMPERATURE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_colortemperature( e_mode, mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_colortemperature here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_colortemperature:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_colortemperature here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_COLOR_TEMPERATURE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_COLOR_TEMPERATURE*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_colortemperature( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_colortemperature here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_pq_color_paramter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_pq_color_paramter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_PQ_COLOR_PARAMTER color = (EN_FPI_PQ_COLOR_PARAMTER)data.readInt32();  //EN_FPI_PQ_COLOR_PARAMTER as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_pq_color_paramter( color, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_pq_color_paramter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_pq_color_paramter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_pq_color_paramter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _color_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PQ_COLOR_PARAMTER* color = NULL;
                if(_color_len > 0) {
                    reply->writeInt32(_color_len);
                    Parcel::WritableBlob _color_wblob;
                    reply->writeBlob(_color_len,&_color_wblob);
                    color = (EN_FPI_PQ_COLOR_PARAMTER*)_color_wblob.data();
                }

                fpi_error _result = tos_pq_get_pq_color_paramter( color );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_pq_color_paramter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_gamma:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_gamma here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_gamma( e_mode, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_gamma here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_gamma:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_gamma here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_gamma( e_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_gamma here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_white_balance_gain:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_white_balance_gain here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t red = (int16_t)data.readInt32();  //int16_t as input paramter

                int16_t green = (int16_t)data.readInt32();  //int16_t as input paramter

                int16_t blue = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_white_balance_gain( red, green, blue, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_white_balance_gain here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_white_balance_gain:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_white_balance_gain here, will auoto generated but may change yourself if need --

  			//skip Exception and result first to write output paramters
				  reply->writeNoException();
				  //skip Exception and result first end

                //begin paramters list
                int _red_len = data.readInt32(); //read length, only 32bits length support yet
                Parcel::WritableBlob _red_wblob;
				  Parcel::WritableBlob _green_wblob;
				  Parcel::WritableBlob _blue_wblob;
                int16_t* red = NULL;
                if(_red_len > 0) {
                    reply->writeInt32(_red_len);
                    
                    reply->writeBlob(_red_len,&_red_wblob);
                    //red = (int16_t*)_red_wblob.data();
					//memset(red, 0, _red_len);
					//printf("\n-czy----red=%d\n",*red);
                }

                int _green_len = data.readInt32(); //read length, only 32bits length support yet
                
                int16_t* green = NULL;
                if(_green_len > 0) {
                    reply->writeInt32(_green_len);
                  
                    reply->writeBlob(_green_len,&_green_wblob);
                    //green = (int16_t*)_green_wblob.data();
					//memset(green, 0, _green_len);
                }


                int _blue_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* blue = NULL;
                if(_blue_len > 0) {
                    reply->writeInt32(_blue_len);
                  
                    reply->writeBlob(_blue_len,&_blue_wblob);
                    //blue = (int16_t*)_blue_wblob.data();
					//memset(blue, 0, _blue_len);
                }

				 red = (int16_t*)_red_wblob.data();
			     green = (int16_t*)_green_wblob.data();
				  blue = (int16_t*)_blue_wblob.data();
                fpi_error _result = tos_pq_get_white_balance_gain( red, green, blue );
	
                //_red_wblob.data()=*red;
                reply->writeInt32(_result); //fpi_error as return value
	

                //-- end code for tos_pq_get_white_balance_gain here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_white_balance_offset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_white_balance_offset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t red = (int16_t)data.readInt32();  //int16_t as input paramter

                int16_t green = (int16_t)data.readInt32();  //int16_t as input paramter

                int16_t blue = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_white_balance_offset( red, green, blue, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_white_balance_offset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_white_balance_offset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_white_balance_offset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _red_len = data.readInt32(); //read length, only 32bits length support yet
                  Parcel::WritableBlob _red_wblob;
				  Parcel::WritableBlob _green_wblob;
				  Parcel::WritableBlob _blue_wblob;
                int16_t* red = NULL;
                if(_red_len > 0) {
                    reply->writeInt32(_red_len);
                  
                    reply->writeBlob(_red_len,&_red_wblob);
                   
                }

                int _green_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* green = NULL;
                if(_green_len > 0) {
                    reply->writeInt32(_green_len);
                  
                    reply->writeBlob(_green_len,&_green_wblob);
                    
                }

                int _blue_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* blue = NULL;
                if(_blue_len > 0) {
                    reply->writeInt32(_blue_len);
                   
                    reply->writeBlob(_blue_len,&_blue_wblob);
                    
                }
                 red = (int16_t*)_red_wblob.data();
				 green = (int16_t*)_green_wblob.data();
				 blue = (int16_t*)_blue_wblob.data();
                fpi_error _result = tos_pq_get_white_balance_offset( red, green, blue );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_white_balance_offset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_special_effect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_special_effect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_EFFECT_TYPE e_type = (EN_VIDEO_EFFECT_TYPE)data.readInt32();  //EN_VIDEO_EFFECT_TYPE as input paramter

                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    Parcel::WritableBlob _enable_wblob;
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_get_special_effect( e_type, enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_special_effect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_special_effect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_special_effect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_EFFECT_TYPE e_type = (EN_VIDEO_EFFECT_TYPE)data.readInt32();  //EN_VIDEO_EFFECT_TYPE as input paramter

                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_special_effect( e_type, enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_special_effect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_rgb_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_rgb_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_COLOR_TYPE mode = (EN_COLOR_TYPE)data.readInt32();  //EN_COLOR_TYPE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_rgb_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_rgb_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_rgb_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_rgb_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_COLOR_TYPE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_COLOR_TYPE*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_rgb_mode( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_rgb_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_mpeg_nr:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_mpeg_nr here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_MPEG_NR_MODE level = (EN_FPI_MPEG_NR_MODE)data.readInt32();  //EN_FPI_MPEG_NR_MODE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_mpeg_nr( level, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_mpeg_nr here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_mpeg_nr:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_mpeg_nr here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_MPEG_NR_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_MPEG_NR_MODE*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_mpeg_nr( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_mpeg_nr here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_noise_reduction:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_noise_reduction here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_NOISE_REDUCTION_MODE level = (EN_FPI_NOISE_REDUCTION_MODE)data.readInt32();  //EN_FPI_NOISE_REDUCTION_MODE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_noise_reduction( level, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_noise_reduction here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_noise_reduction:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_noise_reduction here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_NOISE_REDUCTION_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_NOISE_REDUCTION_MODE*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_noise_reduction( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_noise_reduction here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_memc_config:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_memc_config here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _config_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_MEMC_CONFIG* config = NULL;
                if(_config_len > 0) {
                    reply->writeInt32(_config_len);
                    Parcel::WritableBlob _config_wblob;
                    reply->writeBlob(_config_len,&_config_wblob);
                    config = (EN_FPI_MEMC_CONFIG*)_config_wblob.data();
                }

                fpi_error _result = tos_pq_get_memc_config( config );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_memc_config here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_memc_config:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_memc_config here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_MEMC_CONFIG config = (EN_FPI_MEMC_CONFIG)data.readInt32();  //EN_FPI_MEMC_CONFIG as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_memc_config( config, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_memc_config here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_memc_effect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_memc_effect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_MEMC_EFFECT_TYPE type = (EN_MEMC_EFFECT_TYPE)data.readInt32();  //EN_MEMC_EFFECT_TYPE as input paramter

                int _level_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* level = NULL;
                if(_level_len > 0) {
                    reply->writeInt32(_level_len);
                    Parcel::WritableBlob _level_wblob;
                    reply->writeBlob(_level_len,&_level_wblob);
                    level = (int16_t*)_level_wblob.data();
                }

                fpi_error _result = tos_pq_get_memc_effect( type, level );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_memc_effect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_gamma_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_gamma_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_gamma_enable( enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_gamma_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_gamma_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_gamma_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    Parcel::WritableBlob _enable_wblob;
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_gamma_enable( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_gamma_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_gamma_interval:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_gamma_interval here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t interval = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_gamma_interval( interval, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_gamma_interval here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_gamma_interval:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_gamma_interval here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _interval_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* interval = NULL;
                if(_interval_len > 0) {
                    reply->writeInt32(_interval_len);
                    Parcel::WritableBlob _interval_wblob;
                    reply->writeBlob(_interval_len,&_interval_wblob);
                    interval = (int16_t*)_interval_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_gamma_interval( interval );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_gamma_interval here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_gamma:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_gamma here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_COLOR_TYPE color = (EN_COLOR_TYPE)data.readInt32();  //EN_COLOR_TYPE as input paramter

                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_gamma( color, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_gamma here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_gamma:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_gamma here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_COLOR_TYPE color = (EN_COLOR_TYPE)data.readInt32();  //EN_COLOR_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_gamma( color, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_gamma here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_space_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_space_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_COLOR_SPACE_MODE mode = (EN_FPI_COLOR_SPACE_MODE)data.readInt32();  //EN_FPI_COLOR_SPACE_MODE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_space_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_space_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_space_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_space_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_COLOR_SPACE_MODE* mode = NULL;
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_FPI_COLOR_SPACE_MODE*)_mode_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_space_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_space_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_CS_COLOR_MODE csMode = (EN_FPI_CS_COLOR_MODE)data.readInt32();  //EN_FPI_CS_COLOR_MODE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_type( csMode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _csMode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_CS_COLOR_MODE* csMode = NULL;
                if(_csMode_len > 0) {
                    reply->writeInt32(_csMode_len);
                    Parcel::WritableBlob _csMode_wblob;
                    reply->writeBlob(_csMode_len,&_csMode_wblob);
                    csMode = (EN_FPI_CS_COLOR_MODE*)_csMode_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_type( csMode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_color_space:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_color_space here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_COLOR_TYPE color = (EN_COLOR_TYPE)data.readInt32();  //EN_COLOR_TYPE as input paramter

                int16_t value = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_color_space( color, value, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_color_space here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_color_space:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_color_space here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_COLOR_TYPE color = (EN_COLOR_TYPE)data.readInt32();  //EN_COLOR_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_color_space( color, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_color_space here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_led_motion_clarity:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_led_motion_clarity here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _clarity_type_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_CLARITY_TYPE* clarity_type = NULL;
                if(_clarity_type_len > 0) {
                    reply->writeInt32(_clarity_type_len);
                    Parcel::WritableBlob _clarity_type_wblob;
                    reply->writeBlob(_clarity_type_len,&_clarity_type_wblob);
                    clarity_type = (EN_FPI_CLARITY_TYPE*)_clarity_type_wblob.data();
                }

                fpi_error _result = tos_pq_get_led_motion_clarity( clarity_type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_led_motion_clarity here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_led_motion_clarity:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_led_motion_clarity here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_CLARITY_TYPE clarity_type = (EN_FPI_CLARITY_TYPE)data.readInt32();  //EN_FPI_CLARITY_TYPE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_pq_set_led_motion_clarity( clarity_type, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_led_motion_clarity here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_motion_mode_is_use:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_motion_mode_is_use here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int16_t*)_value_wblob.data();
                }

                EN_FPI_MOTION_CLARITY_MODE motion_mode = (EN_FPI_MOTION_CLARITY_MODE)data.readInt32();  //EN_FPI_MEMC_CONFIG as input paramter

                fpi_error _result = tos_pq_get_motion_mode_is_use( value, motion_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_motion_mode_is_use here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_set_PQ_demo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_set_PQ_demo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_PQ_DEMO_MODE mode = (EN_FPI_PQ_DEMO_MODE)data.readInt32();  //EN_FPI_PQ_DEMO_MODE as input paramter

                fpi_error _result = tos_pq_set_PQ_demo( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_set_PQ_demo here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pq_get_PQ_demo:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pq_get_PQ_demo here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PQ_DEMO_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_PQ_DEMO_MODE*)_value_wblob.data();
                }

                fpi_error _result = tos_pq_get_PQ_demo( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pq_get_PQ_demo here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_pq_set_memc_effect:            
            {                
            	data.enforceInterface(String16(SERVICE_NAME));  //fixed check                

            	//-- begin code for tos_pq_set_memc_effect here, will auoto generated but may change yourself if need --  

            	//skip Exception and result first to write output paramters               
            	reply->writeNoException();               
            	//skip Exception and result first end               

            	//begin paramters list                
            	EN_MEMC_EFFECT_TYPE type = (EN_MEMC_EFFECT_TYPE)data.readInt32();  //EN_MEMC_EFFECT_TYPE as input paramter                
            	int16_t level = (int16_t)data.readInt32();  //int16_t as input paramter                
            	EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter                
            	fpi_error _result = tos_pq_set_memc_effect( type, level, act );                
            	reply->writeInt32(_result); //fpi_error as return value                

            	//-- end code for tos_pq_set_memc_effect here --                
            	fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;           
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_picture_quality_service_add() {
    sbinder_picture_quality_service::Instance();
    return 0;
}

sbinder_picture_quality_service* sbinder_picture_quality_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_picture_quality_client  
{  
private:
    static sbinder_picture_quality_client* _instance;
    sp<IBinder> _binder;

    sbinder_picture_quality_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_picture_quality_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_picture_quality_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_picture_quality_client();
        }

        return _instance;
    }

    fpi_error tos_pq_set_colortemperature( EN_VIDEO_MODE e_mode, EN_FPI_COLOR_TEMPERATURE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_colortemperature here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(mode);  //EN_FPI_COLOR_TEMPERATURE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_colortemperature,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_colortemperature error");
        }

        return _result;
        /*-- add you code for tos_pq_set_colortemperature here --*/
    }

    fpi_error tos_pq_get_colortemperature( EN_VIDEO_MODE e_mode, EN_FPI_COLOR_TEMPERATURE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_colortemperature here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_COLOR_TEMPERATURE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_colortemperature,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_colortemperature error");
        }

        return _result;
        /*-- add you code for tos_pq_get_colortemperature here --*/
    }

    fpi_error tos_pq_set_pq_color_paramter( EN_FPI_PQ_COLOR_PARAMTER color, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_pq_color_paramter here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(color);  //EN_FPI_PQ_COLOR_PARAMTER as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_pq_color_paramter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_pq_color_paramter error");
        }

        return _result;
        /*-- add you code for tos_pq_set_pq_color_paramter here --*/
    }

    fpi_error tos_pq_get_pq_color_paramter( EN_FPI_PQ_COLOR_PARAMTER* color ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_pq_color_paramter here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (color == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_PQ_COLOR_PARAMTER));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_pq_color_paramter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (color != NULL) {
                    int _color_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _color_rblob;
                    reply.readBlob(_color_len,&_color_rblob);
                    memcpy(color,_color_rblob.data(),_color_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_pq_color_paramter error");
        }

        return _result;
        /*-- add you code for tos_pq_get_pq_color_paramter here --*/
    }

    fpi_error tos_pq_set_gamma( EN_VIDEO_MODE e_mode, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_gamma here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_gamma,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_gamma error");
        }

        return _result;
        /*-- add you code for tos_pq_set_gamma here --*/
    }

    fpi_error tos_pq_get_gamma( EN_VIDEO_MODE e_mode, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_gamma here --*/
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
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_gamma,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_gamma error");
        }

        return _result;
        /*-- add you code for tos_pq_get_gamma here --*/
    }

    fpi_error tos_pq_set_white_balance_gain( int16_t red, int16_t green, int16_t blue, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_white_balance_gain here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(red);  //int16_t as input paramter

            data.writeInt32(green);  //int16_t as input paramter

            data.writeInt32(blue);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_white_balance_gain,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_white_balance_gain error");
        }

        return _result;
        /*-- add you code for tos_pq_set_white_balance_gain here --*/
    }

    fpi_error tos_pq_get_white_balance_gain( int16_t* red, int16_t* green, int16_t* blue ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_white_balance_gain here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
             Parcel::ReadableBlob _red_rblob;
			 Parcel::ReadableBlob _green_rblob;
			 Parcel::ReadableBlob _blue_rblob;
            //for out only, only write length ; for in, alloc and copy
            if (red == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (green == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (blue == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_white_balance_gain,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (red != NULL) {
                   int _red_len =reply.readInt32(); //read length, only 32bits length support yet                
                    reply.readBlob(_red_len,&_red_rblob);
                    memcpy(red,_red_rblob.data(),_red_len);

                }
                if (green != NULL) {
                    int _green_len = reply.readInt32(); //read length, only 32bits length support yet
                 
                    reply.readBlob(_green_len,&_green_rblob);
                    memcpy(green,_green_rblob.data(),_green_len);

                }
                if (blue != NULL) {
                    int _blue_len = reply.readInt32(); //read length, only 32bits length support yet
                
                    reply.readBlob(_blue_len,&_blue_rblob);
                    memcpy(blue,_blue_rblob.data(),_blue_len);
					
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_white_balance_gain error");
        }

        return _result;
        /*-- add you code for tos_pq_get_white_balance_gain here --*/
    }

    fpi_error tos_pq_set_white_balance_offset( int16_t red, int16_t green, int16_t blue, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_white_balance_offset here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(red);  //int16_t as input paramter

            data.writeInt32(green);  //int16_t as input paramter

            data.writeInt32(blue);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_white_balance_offset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_white_balance_offset error");
        }

        return _result;
        /*-- add you code for tos_pq_set_white_balance_offset here --*/
    }

    fpi_error tos_pq_get_white_balance_offset( int16_t* red, int16_t* green, int16_t* blue ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_white_balance_offset here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (red == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (green == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (blue == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_white_balance_offset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (red != NULL) {
                    int _red_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _red_rblob;
                    reply.readBlob(_red_len,&_red_rblob);
                    memcpy(red,_red_rblob.data(),_red_len);
                }
                if (green != NULL) {
                    int _green_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _green_rblob;
                    reply.readBlob(_green_len,&_green_rblob);
                    memcpy(green,_green_rblob.data(),_green_len);
                }
                if (blue != NULL) {
                    int _blue_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _blue_rblob;
                    reply.readBlob(_blue_len,&_blue_rblob);
                    memcpy(blue,_blue_rblob.data(),_blue_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_white_balance_offset error");
        }

        return _result;
        /*-- add you code for tos_pq_get_white_balance_offset here --*/
    }

    fpi_error tos_pq_get_special_effect( EN_VIDEO_EFFECT_TYPE e_type, int16_t* enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_special_effect here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_VIDEO_EFFECT_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_get_special_effect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_special_effect error");
        }

        return _result;
        /*-- add you code for tos_pq_get_special_effect here --*/
    }

    fpi_error tos_pq_set_special_effect( EN_VIDEO_EFFECT_TYPE e_type, int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_special_effect here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_VIDEO_EFFECT_TYPE as input paramter

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_special_effect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_special_effect error");
        }

        return _result;
        /*-- add you code for tos_pq_set_special_effect here --*/
    }

    fpi_error tos_pq_set_rgb_mode( EN_COLOR_TYPE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_rgb_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_COLOR_TYPE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_rgb_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_rgb_mode error");
        }

        return _result;
        /*-- add you code for tos_pq_set_rgb_mode here --*/
    }

    fpi_error tos_pq_get_rgb_mode( EN_COLOR_TYPE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_rgb_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_COLOR_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_rgb_mode,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_rgb_mode error");
        }

        return _result;
        /*-- add you code for tos_pq_get_rgb_mode here --*/
    }

    fpi_error tos_pq_set_mpeg_nr( EN_FPI_MPEG_NR_MODE level, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_mpeg_nr here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(level);  //EN_FPI_MPEG_NR_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_mpeg_nr,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_mpeg_nr error");
        }

        return _result;
        /*-- add you code for tos_pq_set_mpeg_nr here --*/
    }

    fpi_error tos_pq_get_mpeg_nr( EN_FPI_MPEG_NR_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_mpeg_nr here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_MPEG_NR_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_mpeg_nr,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_mpeg_nr error");
        }

        return _result;
        /*-- add you code for tos_pq_get_mpeg_nr here --*/
    }

    fpi_error tos_pq_set_noise_reduction( EN_FPI_NOISE_REDUCTION_MODE level, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_noise_reduction here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(level);  //EN_FPI_NOISE_REDUCTION_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_noise_reduction,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_noise_reduction error");
        }

        return _result;
        /*-- add you code for tos_pq_set_noise_reduction here --*/
    }

    fpi_error tos_pq_get_noise_reduction( EN_FPI_NOISE_REDUCTION_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_noise_reduction here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_NOISE_REDUCTION_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_noise_reduction,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_noise_reduction error");
        }

        return _result;
        /*-- add you code for tos_pq_get_noise_reduction here --*/
    }

    fpi_error tos_pq_get_memc_config( EN_FPI_MEMC_CONFIG* config ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_memc_config here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (config == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_MEMC_CONFIG));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_memc_config,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (config != NULL) {
                    int _config_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _config_rblob;
                    reply.readBlob(_config_len,&_config_rblob);
                    memcpy(config,_config_rblob.data(),_config_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_memc_config error");
        }

        return _result;
        /*-- add you code for tos_pq_get_memc_config here --*/
    }

    fpi_error tos_pq_set_memc_config( EN_FPI_MEMC_CONFIG config, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_memc_config here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(config);  //EN_FPI_MEMC_CONFIG as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_memc_config,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_memc_config error");
        }

        return _result;
        /*-- add you code for tos_pq_set_memc_config here --*/
    }

    fpi_error tos_pq_get_memc_effect( EN_MEMC_EFFECT_TYPE type, int16_t* level ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_memc_effect here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_MEMC_EFFECT_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (level == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_memc_effect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (level != NULL) {
                    int _level_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _level_rblob;
                    reply.readBlob(_level_len,&_level_rblob);
                    memcpy(level,_level_rblob.data(),_level_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_memc_effect error");
        }

        return _result;
        /*-- add you code for tos_pq_get_memc_effect here --*/
    }

    fpi_error tos_pq_set_color_gamma_enable( int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_gamma_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_gamma_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_gamma_enable error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_gamma_enable here --*/
    }

    fpi_error tos_pq_get_color_gamma_enable( int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_gamma_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
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

            _binder->transact(TRANSACTION_tos_pq_get_color_gamma_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_gamma_enable error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_gamma_enable here --*/
    }

    fpi_error tos_pq_set_color_gamma_interval( int16_t interval, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_gamma_interval here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(interval);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_gamma_interval,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_gamma_interval error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_gamma_interval here --*/
    }

    fpi_error tos_pq_get_color_gamma_interval( int16_t* interval ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_gamma_interval here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (interval == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_color_gamma_interval,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (interval != NULL) {
                    int _interval_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _interval_rblob;
                    reply.readBlob(_interval_len,&_interval_rblob);
                    memcpy(interval,_interval_rblob.data(),_interval_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_gamma_interval error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_gamma_interval here --*/
    }

    fpi_error tos_pq_set_color_gamma( EN_COLOR_TYPE color, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_gamma here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(color);  //EN_COLOR_TYPE as input paramter

            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_gamma,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_gamma error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_gamma here --*/
    }

    fpi_error tos_pq_get_color_gamma( EN_COLOR_TYPE color, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_gamma here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(color);  //EN_COLOR_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_color_gamma,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_gamma error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_gamma here --*/
    }

    fpi_error tos_pq_set_color_space_mode( EN_FPI_COLOR_SPACE_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_space_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_FPI_COLOR_SPACE_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_space_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_space_mode error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_space_mode here --*/
    }

    fpi_error tos_pq_get_color_space_mode( EN_FPI_COLOR_SPACE_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_space_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_COLOR_SPACE_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_color_space_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_space_mode error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_space_mode here --*/
    }

    fpi_error tos_pq_set_color_type( EN_FPI_CS_COLOR_MODE csMode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(csMode);  //EN_FPI_CS_COLOR_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_type error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_type here --*/
    }

    fpi_error tos_pq_get_color_type( EN_FPI_CS_COLOR_MODE* csMode ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (csMode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_CS_COLOR_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_color_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (csMode != NULL) {
                    int _csMode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _csMode_rblob;
                    reply.readBlob(_csMode_len,&_csMode_rblob);
                    memcpy(csMode,_csMode_rblob.data(),_csMode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_type error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_type here --*/
    }

    fpi_error tos_pq_set_color_space( EN_COLOR_TYPE color, int16_t value, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_color_space here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(color);  //EN_COLOR_TYPE as input paramter

            data.writeInt32(value);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_color_space,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_color_space error");
        }

        return _result;
        /*-- add you code for tos_pq_set_color_space here --*/
    }

    fpi_error tos_pq_get_color_space( EN_COLOR_TYPE color, int16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_color_space here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(color);  //EN_COLOR_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_color_space,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_color_space error");
        }

        return _result;
        /*-- add you code for tos_pq_get_color_space here --*/
    }

    fpi_error tos_pq_get_led_motion_clarity( EN_FPI_CLARITY_TYPE* clarity_type ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_led_motion_clarity here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (clarity_type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_CLARITY_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_led_motion_clarity,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (clarity_type != NULL) {
                    int _clarity_type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _clarity_type_rblob;
                    reply.readBlob(_clarity_type_len,&_clarity_type_rblob);
                    memcpy(clarity_type,_clarity_type_rblob.data(),_clarity_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_get_led_motion_clarity error");
        }

        return _result;
        /*-- add you code for tos_pq_get_led_motion_clarity here --*/
    }

    fpi_error tos_pq_set_led_motion_clarity( EN_FPI_CLARITY_TYPE clarity_type, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_led_motion_clarity here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(clarity_type);  //EN_FPI_CLARITY_TYPE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_led_motion_clarity,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_led_motion_clarity error");
        }

        return _result;
        /*-- add you code for tos_pq_set_led_motion_clarity here --*/
    }

    fpi_error tos_pq_get_motion_mode_is_use( int16_t* value, EN_FPI_MOTION_CLARITY_MODE motion_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_motion_mode_is_use here --*/
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
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(motion_mode);  //EN_FPI_MEMC_CONFIG as input paramter

            _binder->transact(TRANSACTION_tos_pq_get_motion_mode_is_use,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_motion_mode_is_use error");
        }

        return _result;
        /*-- add you code for tos_pq_get_motion_mode_is_use here --*/
    }

    fpi_error tos_pq_set_PQ_demo( EN_FPI_PQ_DEMO_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_PQ_demo here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_FPI_PQ_DEMO_MODE as input paramter

            _binder->transact(TRANSACTION_tos_pq_set_PQ_demo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pq_set_PQ_demo error");
        }

        return _result;
        /*-- add you code for tos_pq_set_PQ_demo here --*/
    }

    fpi_error tos_pq_get_PQ_demo( EN_FPI_PQ_DEMO_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_get_PQ_demo here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_PQ_DEMO_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pq_get_PQ_demo,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_pq_get_PQ_demo error");
        }

        return _result;
        /*-- add you code for tos_pq_get_PQ_demo here --*/
    }
    
    fpi_error tos_pq_set_memc_effect( EN_MEMC_EFFECT_TYPE type, int16_t level, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_pq_set_memc_effect here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
        	return _result;
        }
        
        try {
        	data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
        	
        	data.writeInt32(type);  //EN_MEMC_EFFECT_TYPE as input paramter
        	
        	data.writeInt32(level);  //int16_t as input paramter
        	
        	data.writeInt32(act);  //EN_ACT_CTRL as input paramter
        	
        	_binder->transact(TRANSACTION_tos_pq_set_memc_effect,data, &reply,0);
        	
        	if(reply.readExceptionCode() == 0) {//fix check
        	
       			_result = (typeof(_result))reply.readInt32();//int as return value
       			
        	}
        }catch(...) {
        	fpi_warn(SERVICE_NAME"_client tos_pq_set_memc_effect error");
        }
        return _result;        /*-- add you code for tos_pq_set_memc_effect here --*/
    }
};

sbinder_picture_quality_client* sbinder_picture_quality_client::_instance = NULL;

fpi_error tos_pq_set_colortemperature( EN_VIDEO_MODE e_mode, EN_FPI_COLOR_TEMPERATURE mode, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_colortemperature(e_mode, mode, act);
}
fpi_error tos_pq_get_colortemperature( EN_VIDEO_MODE e_mode, EN_FPI_COLOR_TEMPERATURE* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_colortemperature(e_mode, value);
}
fpi_error tos_pq_set_pq_color_paramter( EN_FPI_PQ_COLOR_PARAMTER color, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_pq_color_paramter(color, act);
}
fpi_error tos_pq_get_pq_color_paramter( EN_FPI_PQ_COLOR_PARAMTER* color ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_pq_color_paramter(color);
}
fpi_error tos_pq_set_gamma( EN_VIDEO_MODE e_mode, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_gamma(e_mode, value, act);
}
fpi_error tos_pq_get_gamma( EN_VIDEO_MODE e_mode, int16_t* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_gamma(e_mode, value);
}
fpi_error tos_pq_set_white_balance_gain( int16_t red, int16_t green, int16_t blue, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_white_balance_gain(red, green, blue, act);
}
fpi_error tos_pq_get_white_balance_gain( int16_t* red, int16_t* green, int16_t* blue ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_white_balance_gain(red, green, blue);
}
fpi_error tos_pq_set_white_balance_offset( int16_t red, int16_t green, int16_t blue, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_white_balance_offset(red, green, blue, act);
}
fpi_error tos_pq_get_white_balance_offset( int16_t* red, int16_t* green, int16_t* blue ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_white_balance_offset(red, green, blue);
}
fpi_error tos_pq_get_special_effect( EN_VIDEO_EFFECT_TYPE e_type, int16_t* enable, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_special_effect(e_type, enable, act);
}
fpi_error tos_pq_set_special_effect( EN_VIDEO_EFFECT_TYPE e_type, int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_special_effect(e_type, enable, act);
}
fpi_error tos_pq_set_rgb_mode( EN_COLOR_TYPE mode, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_rgb_mode(mode, act);
}
fpi_error tos_pq_get_rgb_mode( EN_COLOR_TYPE* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_rgb_mode(value);
}
fpi_error tos_pq_set_mpeg_nr( EN_FPI_MPEG_NR_MODE level, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_mpeg_nr(level, act);
}
fpi_error tos_pq_get_mpeg_nr( EN_FPI_MPEG_NR_MODE* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_mpeg_nr(value);
}
fpi_error tos_pq_set_noise_reduction( EN_FPI_NOISE_REDUCTION_MODE level, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_noise_reduction(level, act);
}
fpi_error tos_pq_get_noise_reduction( EN_FPI_NOISE_REDUCTION_MODE* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_noise_reduction(value);
}
fpi_error tos_pq_get_memc_config( EN_FPI_MEMC_CONFIG* config ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_memc_config(config);
}
fpi_error tos_pq_set_memc_config( EN_FPI_MEMC_CONFIG config, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_memc_config(config, act);
}
fpi_error tos_pq_get_memc_effect( EN_MEMC_EFFECT_TYPE type, int16_t* level ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_memc_effect(type, level);
}
fpi_error tos_pq_set_color_gamma_enable( int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_gamma_enable(enable, act);
}
fpi_error tos_pq_get_color_gamma_enable( int16_t* enable ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_gamma_enable(enable);
}
fpi_error tos_pq_set_color_gamma_interval( int16_t interval, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_gamma_interval(interval, act);
}
fpi_error tos_pq_get_color_gamma_interval( int16_t* interval ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_gamma_interval(interval);
}
fpi_error tos_pq_set_color_gamma( EN_COLOR_TYPE color, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_gamma(color, value, act);
}
fpi_error tos_pq_get_color_gamma( EN_COLOR_TYPE color, int16_t* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_gamma(color, value);
}
fpi_error tos_pq_set_color_space_mode( EN_FPI_COLOR_SPACE_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_space_mode(mode, act);
}
fpi_error tos_pq_get_color_space_mode( EN_FPI_COLOR_SPACE_MODE* mode ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_space_mode(mode);
}
fpi_error tos_pq_set_color_type( EN_FPI_CS_COLOR_MODE csMode, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_type(csMode, act);
}
fpi_error tos_pq_get_color_type( EN_FPI_CS_COLOR_MODE* csMode ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_type(csMode);
}
fpi_error tos_pq_set_color_space( EN_COLOR_TYPE color, int16_t value, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_color_space(color, value, act);
}
fpi_error tos_pq_get_color_space( EN_COLOR_TYPE color, int16_t* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_color_space(color, value);
}
fpi_error tos_pq_get_led_motion_clarity( EN_FPI_CLARITY_TYPE* clarity_type ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_led_motion_clarity(clarity_type);
}
fpi_error tos_pq_set_led_motion_clarity( EN_FPI_CLARITY_TYPE clarity_type, EN_ACT_CTRL act ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_led_motion_clarity(clarity_type, act);
}
fpi_error tos_pq_get_motion_mode_is_use( int16_t* value, EN_FPI_MOTION_CLARITY_MODE motion_mode ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_motion_mode_is_use(value, motion_mode);
}
fpi_error tos_pq_set_PQ_demo( EN_FPI_PQ_DEMO_MODE mode ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_set_PQ_demo(mode);
}
fpi_error tos_pq_get_PQ_demo( EN_FPI_PQ_DEMO_MODE* value ) {
    return sbinder_picture_quality_client::Instance()->tos_pq_get_PQ_demo(value);
}
fpi_error tos_pq_set_memc_effect( EN_MEMC_EFFECT_TYPE type, int16_t level, EN_ACT_CTRL act ) {
	return sbinder_picture_quality_client::Instance()->tos_pq_set_memc_effect(type, level, act);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
