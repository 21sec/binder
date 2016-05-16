/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_cc.sidl
 */
 

#define LOG_TAG     "sbinder_cc"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#include "tos_closed_caption.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_CC);

#define SERVICE_DESCRIPTOR                      "744990de-2bb1-11e5-bb2f-005056a86db3"
#define SERVICE_NAME                            "sbinder_cc"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_cc_is_available FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_cc_set_visibility FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_cc_set_cc_enable_mode FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_cc_get_cc_enable_mode FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_cc_switch_digital_cc FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_cc_get_digital_cc_type FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_cc_switch_analog_cc FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_cc_get_analog_cc_type FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_cc_set_cc_preset_mode FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_cc_get_cc_preset_mode FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_cc_set_cc_style FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_cc_get_cc_style FIRST_CALL_TRANSACTION + 12

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_cc.h"

class sbinder_cc_service : public BBinder  
{  
private:
    static sbinder_cc_service* _instance;

    sbinder_cc_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_cc_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_cc_service();
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

            case TRANSACTION_tos_cc_is_available:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_is_available here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _available_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* available = NULL;

                Parcel::WritableBlob _available_wblob;

                if(_available_len > 0) {
                    reply->writeInt32(_available_len);
                    reply->writeBlob(_available_len,&_available_wblob);
                    available = (fpi_bool*)_available_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                available = (fpi_bool*)_available_wblob.data();
                fpi_error _result = tos_cc_is_available( available );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_is_available here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_set_visibility:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_set_visibility here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_CC_VISIBLE_LEVEL level yet, please add code yourself
                EN_CC_VISIBLE_LEVEL level = (EN_CC_VISIBLE_LEVEL)data.readInt32();  //uint32_t as input paramter

	            //#error not support this type of paramter fpi_bool show yet, please add code yourself
				fpi_bool show = (fpi_bool)data.readInt32();	//uint32_t as input paramter
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_set_visibility( level, show );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_set_visibility here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_set_cc_enable_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_set_cc_enable_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
                EN_ACT_CTRL cmd = (EN_ACT_CTRL)data.readInt32();  //uint32_t as input paramter

            	//#error not support this type of paramter EN_CC_ENABLE_MODE mode yet, please add code yourself
                EN_CC_ENABLE_MODE mode = (EN_CC_ENABLE_MODE)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_set_cc_enable_mode( cmd, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_set_cc_enable_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_get_cc_enable_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_get_cc_enable_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_CC_ENABLE_MODE* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_CC_ENABLE_MODE*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (EN_CC_ENABLE_MODE*)_mode_wblob.data();
                fpi_error _result = tos_cc_get_cc_enable_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_get_cc_enable_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_switch_digital_cc:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_switch_digital_cc here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
                EN_ACT_CTRL cmd = (EN_ACT_CTRL)data.readInt32();  //uint32_t as input paramter

	            //#error not support this type of paramter EN_DIGITAL_CC_TYPE type yet, please add code yourself
                EN_DIGITAL_CC_TYPE type = (EN_DIGITAL_CC_TYPE)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_switch_digital_cc( cmd, type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_switch_digital_cc here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_get_digital_cc_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_get_digital_cc_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _type_len = data.readInt32(); //read length, only 32bits length support yet
                EN_DIGITAL_CC_TYPE* type = NULL;

                Parcel::WritableBlob _type_wblob;

                if(_type_len > 0) {
                    reply->writeInt32(_type_len);
                    reply->writeBlob(_type_len,&_type_wblob);
                    type = (EN_DIGITAL_CC_TYPE*)_type_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                type = (EN_DIGITAL_CC_TYPE*)_type_wblob.data();
                fpi_error _result = tos_cc_get_digital_cc_type( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_get_digital_cc_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_switch_analog_cc:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_switch_analog_cc here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
                EN_ACT_CTRL cmd = (EN_ACT_CTRL)data.readInt32();  //uint32_t as input paramter

            	//#error not support this type of paramter EN_ANALOG_CC_TYPE type yet, please add code yourself
                EN_ANALOG_CC_TYPE type = (EN_ANALOG_CC_TYPE)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_switch_analog_cc( cmd, type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_switch_analog_cc here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_get_analog_cc_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_get_analog_cc_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _type_len = data.readInt32(); //read length, only 32bits length support yet
                EN_ANALOG_CC_TYPE* type = NULL;

                Parcel::WritableBlob _type_wblob;

                if(_type_len > 0) {
                    reply->writeInt32(_type_len);
                    reply->writeBlob(_type_len,&_type_wblob);
                    type = (EN_ANALOG_CC_TYPE*)_type_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                type = (EN_ANALOG_CC_TYPE*)_type_wblob.data();
                fpi_error _result = tos_cc_get_analog_cc_type( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_get_analog_cc_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_set_cc_preset_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_set_cc_preset_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
                EN_ACT_CTRL cmd = (EN_ACT_CTRL)data.readInt32();  //uint32_t as input paramter

            	//#error not support this type of paramter EN_CC_PRESET_MODE preset yet, please add code yourself
                EN_CC_PRESET_MODE preset = (EN_CC_PRESET_MODE)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_set_cc_preset_mode( cmd, preset );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_set_cc_preset_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_get_cc_preset_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_get_cc_preset_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _preset_len = data.readInt32(); //read length, only 32bits length support yet
                EN_CC_PRESET_MODE* preset = NULL;

                Parcel::WritableBlob _preset_wblob;

                if(_preset_len > 0) {
                    reply->writeInt32(_preset_len);
                    reply->writeBlob(_preset_len,&_preset_wblob);
                    preset = (EN_CC_PRESET_MODE*)_preset_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                preset = (EN_CC_PRESET_MODE*)_preset_wblob.data();
                fpi_error _result = tos_cc_get_cc_preset_mode( preset );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_get_cc_preset_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_set_cc_style:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_set_cc_style here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            	//#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
                EN_ACT_CTRL cmd = (EN_ACT_CTRL)data.readInt32();  //uint32_t as input paramter

            	//#error not support this type of paramter EN_CC_STYLE_TYPE style_type yet, please add code yourself
                EN_CC_STYLE_TYPE style_type = (EN_CC_STYLE_TYPE)data.readInt32();  //uint32_t as input paramter

            	//#error not support this type of paramter st_cc_style cc_style yet, please add code yourself
                st_cc_style cc_style;  //uint32_t as input paramter
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
				if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(cc_style) )
					{
						memcpy(&cc_style,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
					}
                }
				//fpi_info("closedcaption %s,font_sytle = %d\n",__FUNCTION__,cc_style.font_style);
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_cc_set_cc_style( cmd, style_type, cc_style );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_set_cc_style here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cc_get_cc_style:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cc_get_cc_style here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _cc_style_len = data.readInt32(); //read length, only 32bits length support yet
                st_cc_style* cc_style = NULL;

                Parcel::WritableBlob _cc_style_wblob;

                if(_cc_style_len > 0) {
                    reply->writeInt32(_cc_style_len);
                    reply->writeBlob(_cc_style_len,&_cc_style_wblob);
                    cc_style = (st_cc_style*)_cc_style_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                cc_style = (st_cc_style*)_cc_style_wblob.data();
                fpi_error _result = tos_cc_get_cc_style( cc_style );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cc_get_cc_style here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_cc_service_add() {
    sbinder_cc_service::Instance();
    return 0;
}

sbinder_cc_service* sbinder_cc_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_cc_client  
{  
private:
    static sbinder_cc_client* _instance;
    sp<IBinder> _binder;

    sbinder_cc_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_cc_client() {
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
    static sbinder_cc_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_cc_client();
        }

        return _instance;
    }

    fpi_error tos_cc_is_available( fpi_bool* available ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_is_available here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (available == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_is_available,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (available != NULL) {
                    int _available_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _available_rblob;
                    reply.readBlob(_available_len,&_available_rblob);
                    memcpy(available,_available_rblob.data(),_available_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_is_available error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_is_available error");
        }

        return _result;
        /*-- add you code for tos_cc_is_available here --*/
    }

    fpi_error tos_cc_set_visibility( EN_CC_VISIBLE_LEVEL level, fpi_bool show ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_set_visibility here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_CC_VISIBLE_LEVEL level yet, please add code yourself
			data.writeInt32(level);
			
            //#error not support this type of paramter fpi_bool show yet, please add code yourself
			data.writeInt32(show);
			
            _binder->transact(TRANSACTION_tos_cc_set_visibility,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_set_visibility error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_set_visibility error");
        }

        return _result;
        /*-- add you code for tos_cc_set_visibility here --*/
    }

    fpi_error tos_cc_set_cc_enable_mode( EN_ACT_CTRL cmd, EN_CC_ENABLE_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_set_cc_enable_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
			data.writeInt32(cmd);
            //#error not support this type of paramter EN_CC_ENABLE_MODE mode yet, please add code yourself
			data.writeInt32(mode);
            _binder->transact(TRANSACTION_tos_cc_set_cc_enable_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_enable_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_enable_mode error");
        }

        return _result;
        /*-- add you code for tos_cc_set_cc_enable_mode here --*/
    }

    fpi_error tos_cc_get_cc_enable_mode( EN_CC_ENABLE_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_get_cc_enable_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_CC_ENABLE_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_get_cc_enable_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_enable_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_enable_mode error");
        }

        return _result;
        /*-- add you code for tos_cc_get_cc_enable_mode here --*/
    }

    fpi_error tos_cc_switch_digital_cc( EN_ACT_CTRL cmd, EN_DIGITAL_CC_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_switch_digital_cc here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
			data.writeInt32(cmd);
            //#error not support this type of paramter EN_DIGITAL_CC_TYPE type yet, please add code yourself
			data.writeInt32(type);
            _binder->transact(TRANSACTION_tos_cc_switch_digital_cc,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_switch_digital_cc error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_switch_digital_cc error");
        }

        return _result;
        /*-- add you code for tos_cc_switch_digital_cc here --*/
    }

    fpi_error tos_cc_get_digital_cc_type( EN_DIGITAL_CC_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_get_digital_cc_type here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_DIGITAL_CC_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_get_digital_cc_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (type != NULL) {
                    int _type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _type_rblob;
                    reply.readBlob(_type_len,&_type_rblob);
                    memcpy(type,_type_rblob.data(),_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_get_digital_cc_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_get_digital_cc_type error");
        }

        return _result;
        /*-- add you code for tos_cc_get_digital_cc_type here --*/
    }

    fpi_error tos_cc_switch_analog_cc( EN_ACT_CTRL cmd, EN_ANALOG_CC_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_switch_analog_cc here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
			data.writeInt32(cmd);
            //#error not support this type of paramter EN_ANALOG_CC_TYPE type yet, please add code yourself
			data.writeInt32(type);
            _binder->transact(TRANSACTION_tos_cc_switch_analog_cc,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_switch_analog_cc error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_switch_analog_cc error");
        }

        return _result;
        /*-- add you code for tos_cc_switch_analog_cc here --*/
    }

    fpi_error tos_cc_get_analog_cc_type( EN_ANALOG_CC_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_get_analog_cc_type here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_ANALOG_CC_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_get_analog_cc_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (type != NULL) {
                    int _type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _type_rblob;
                    reply.readBlob(_type_len,&_type_rblob);
                    memcpy(type,_type_rblob.data(),_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_get_analog_cc_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_get_analog_cc_type error");
        }

        return _result;
        /*-- add you code for tos_cc_get_analog_cc_type here --*/
    }

    fpi_error tos_cc_set_cc_preset_mode( EN_ACT_CTRL cmd, EN_CC_PRESET_MODE preset ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_set_cc_preset_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
			data.writeInt32(cmd);
            //#error not support this type of paramter EN_CC_PRESET_MODE preset yet, please add code yourself
			data.writeInt32(preset);
            _binder->transact(TRANSACTION_tos_cc_set_cc_preset_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_preset_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_preset_mode error");
        }

        return _result;
        /*-- add you code for tos_cc_set_cc_preset_mode here --*/
    }

    fpi_error tos_cc_get_cc_preset_mode( EN_CC_PRESET_MODE* preset ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_get_cc_preset_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (preset == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_CC_PRESET_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_get_cc_preset_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (preset != NULL) {
                    int _preset_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _preset_rblob;
                    reply.readBlob(_preset_len,&_preset_rblob);
                    memcpy(preset,_preset_rblob.data(),_preset_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_preset_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_preset_mode error");
        }

        return _result;
        /*-- add you code for tos_cc_get_cc_preset_mode here --*/
    }

    fpi_error tos_cc_set_cc_style( EN_ACT_CTRL cmd, EN_CC_STYLE_TYPE style_type, st_cc_style cc_style ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_set_cc_style here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
			//fpi_info("closedcaption2222 %s,font_sytle = %d\n",__FUNCTION__,cc_style.font_style);
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter EN_ACT_CTRL cmd yet, please add code yourself
			data.writeInt32(cmd);
            //#error not support this type of paramter EN_CC_STYLE_TYPE style_type yet, please add code yourself
			data.writeInt32(style_type);
            //#error not support this type of paramter st_cc_style cc_style yet, please add code yourself
            Parcel::WritableBlob _pin_wblob;
			data.writeInt32((1) * sizeof(st_cc_style));
            data.writeBlob((1) * sizeof(st_cc_style),&_pin_wblob);
            memcpy(_pin_wblob.data(),&cc_style,(1)* sizeof(st_cc_style));
			
            _binder->transact(TRANSACTION_tos_cc_set_cc_style,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_style error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_set_cc_style error");
        }

        return _result;
        /*-- add you code for tos_cc_set_cc_style here --*/
    }

    fpi_error tos_cc_get_cc_style( st_cc_style* cc_style ) {
        Parcel data, reply;

        /*-- add you code for tos_cc_get_cc_style here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (cc_style == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_cc_style));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cc_get_cc_style,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (cc_style != NULL) {
                    int _cc_style_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _cc_style_rblob;
                    reply.readBlob(_cc_style_len,&_cc_style_rblob);
                    memcpy(cc_style,_cc_style_rblob.data(),_cc_style_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_style error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cc_get_cc_style error");
        }

        return _result;
        /*-- add you code for tos_cc_get_cc_style here --*/
    }
};

sbinder_cc_client* sbinder_cc_client::_instance = NULL;

fpi_error tos_cc_is_available( fpi_bool* available ) {
    return sbinder_cc_client::Instance()->tos_cc_is_available(available);
}
fpi_error tos_cc_set_visibility( EN_CC_VISIBLE_LEVEL level, fpi_bool show ) {
    return sbinder_cc_client::Instance()->tos_cc_set_visibility(level, show);
}
fpi_error tos_cc_set_cc_enable_mode( EN_ACT_CTRL cmd, EN_CC_ENABLE_MODE mode ) {
    return sbinder_cc_client::Instance()->tos_cc_set_cc_enable_mode(cmd, mode);
}
fpi_error tos_cc_get_cc_enable_mode( EN_CC_ENABLE_MODE* mode ) {
    return sbinder_cc_client::Instance()->tos_cc_get_cc_enable_mode(mode);
}
fpi_error tos_cc_switch_digital_cc( EN_ACT_CTRL cmd, EN_DIGITAL_CC_TYPE type ) {
    return sbinder_cc_client::Instance()->tos_cc_switch_digital_cc(cmd, type);
}
fpi_error tos_cc_get_digital_cc_type( EN_DIGITAL_CC_TYPE* type ) {
    return sbinder_cc_client::Instance()->tos_cc_get_digital_cc_type(type);
}
fpi_error tos_cc_switch_analog_cc( EN_ACT_CTRL cmd, EN_ANALOG_CC_TYPE type ) {
    return sbinder_cc_client::Instance()->tos_cc_switch_analog_cc(cmd, type);
}
fpi_error tos_cc_get_analog_cc_type( EN_ANALOG_CC_TYPE* type ) {
    return sbinder_cc_client::Instance()->tos_cc_get_analog_cc_type(type);
}
fpi_error tos_cc_set_cc_preset_mode( EN_ACT_CTRL cmd, EN_CC_PRESET_MODE preset ) {
    return sbinder_cc_client::Instance()->tos_cc_set_cc_preset_mode(cmd, preset);
}
fpi_error tos_cc_get_cc_preset_mode( EN_CC_PRESET_MODE* preset ) {
    return sbinder_cc_client::Instance()->tos_cc_get_cc_preset_mode(preset);
}
fpi_error tos_cc_set_cc_style( EN_ACT_CTRL cmd, EN_CC_STYLE_TYPE style_type, st_cc_style cc_style ) {
    return sbinder_cc_client::Instance()->tos_cc_set_cc_style(cmd, style_type, cc_style);
}
fpi_error tos_cc_get_cc_style( st_cc_style* cc_style ) {
    return sbinder_cc_client::Instance()->tos_cc_get_cc_style(cc_style);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
