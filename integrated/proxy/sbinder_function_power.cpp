/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_function_power.sidl
 */
 

#define LOG_TAG     "sbinder_function_power"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_power_suspend.h"
#include "tos_function_power.h"
#include "tos_tcli.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_POWER);


#define SERVICE_DESCRIPTOR                      "c09ae19a-a542-11e4-8541-005056a84a3b"
#define SERVICE_NAME                            "sbinder_function_power"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_power_set_mode FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_power_get_mode FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_power_off FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_cancel_power_off FIRST_CALL_TRANSACTION + 4

#define TRANSACTION_tos_power_suspend_set_onoff_status FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_power_suspend_get_onoff_status FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_power_suspend_set_str_debug_val FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_power_suspend_set_mode FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_power_suspend_get_support_status FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_power_suspend_get_current_work_mode FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_power_suspend_get_usb_device_resuming_status FIRST_CALL_TRANSACTION + 11

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_function_power.h"

class sbinder_function_power_service : public BBinder  
{  
private:
    static sbinder_function_power_service* _instance;

    sbinder_function_power_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_function_power_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_function_power_service();
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
			case TRANSACTION_tos_power_suspend_set_onoff_status:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_set_onoff_status here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   fpi_bool flag = (fpi_bool)data.readInt32();	//fpi_bool as input paramter
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   fpi_error _result = tos_power_suspend_set_onoff_status( flag );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_set_onoff_status here --
				   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			   } break;
			   
			   case TRANSACTION_tos_power_suspend_get_onoff_status:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_get_onoff_status here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   int _flag_len = data.readInt32(); //read length, only 32bits length support yet
				   fpi_bool* flag = NULL;
			
				   Parcel::WritableBlob _flag_wblob;
			
				   if(_flag_len > 0) {
					   reply->writeInt32(_flag_len);
					   reply->writeBlob(_flag_len,&_flag_wblob);
					   flag = (fpi_bool*)_flag_wblob.data();
				   }
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   flag = (fpi_bool*)_flag_wblob.data();
				   fpi_error _result = tos_power_suspend_get_onoff_status( flag );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_get_onoff_status here --
				   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			   } break;
			   
			   case TRANSACTION_tos_power_suspend_set_str_debug_val:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_set_str_debug_val here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   int var = (int)data.readInt32();  //int as input paramter
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   fpi_error _result = tos_power_suspend_set_str_debug_val( var );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_set_str_debug_val here --
				   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			   } break;

			   /*
			   case TRANSACTION_tos_power_suspend_set_mode:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_set_mode here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   EN_POWER_SUSPEND_WORK_MODE mode = (EN_POWER_SUSPEND_WORK_MODE)data.readInt32();	//EN_POWER_SUSPEND_WORK_MODE as input paramter
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   fpi_error _result = tos_power_suspend_set_mode( mode );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_set_mode here --
				   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			   } break;
			   */
			   case TRANSACTION_tos_power_suspend_get_support_status:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_get_support_status here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   int _type_len = data.readInt32(); //read length, only 32bits length support yet
				   EN_POWER_SUSPEND_SUPPORT* type = NULL;
			
				   Parcel::WritableBlob _type_wblob;
			
				   if(_type_len > 0) {
					   reply->writeInt32(_type_len);
					   reply->writeBlob(_type_len,&_type_wblob);
					   type = (EN_POWER_SUSPEND_SUPPORT*)_type_wblob.data();
				   }
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   type = (EN_POWER_SUSPEND_SUPPORT*)_type_wblob.data();
				   fpi_error _result = tos_power_suspend_get_support_status( type );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_get_support_status here --
				   return NO_ERROR;
			   } break;

			   case TRANSACTION_tos_power_suspend_get_current_work_mode:
	           {
	                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

	                //-- begin code for tos_power_suspend_get_current_work_mode here, will auoto generated but may change yourself if need --

	                //skip Exception and result first to write output paramters
	                reply->writeNoException();
	                //skip Exception and result first end

	                //begin paramters list
	                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
	                EN_POWER_SUSPEND_WORK_MODE* mode = NULL;

	                Parcel::WritableBlob _mode_wblob;

	                if(_mode_len > 0) {
	                    reply->writeInt32(_mode_len);
	                    reply->writeBlob(_mode_len,&_mode_wblob);
	                    mode = (EN_POWER_SUSPEND_WORK_MODE*)_mode_wblob.data();
	                }

	                // re-get all pointers from blob to fix realloc issue in Parcel
	                mode = (EN_POWER_SUSPEND_WORK_MODE*)_mode_wblob.data();
	                fpi_error _result = tos_power_suspend_get_current_work_mode( mode );

	                reply->writeInt32(_result); //fpi_error as return value

	                //-- end code for tos_power_suspend_get_current_work_mode here --
	                return NO_ERROR;
	           } break;
			   
			   case TRANSACTION_tos_power_suspend_get_usb_device_resuming_status:
			   {
				   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
			
				   //-- begin code for tos_power_suspend_get_usb_device_resuming_status here, will auoto generated but may change yourself if need --
			
				   //skip Exception and result first to write output paramters
				   reply->writeNoException();
				   //skip Exception and result first end
			
				   //begin paramters list
				   int _flag_len = data.readInt32(); //read length, only 32bits length support yet
				   fpi_bool* flag = NULL;
			
				   Parcel::WritableBlob _flag_wblob;
			
				   if(_flag_len > 0) {
					   reply->writeInt32(_flag_len);
					   reply->writeBlob(_flag_len,&_flag_wblob);
					   flag = (fpi_bool*)_flag_wblob.data();
				   }
			
				   // re-get all pointers from blob to fix realloc issue in Parcel
				   flag = (fpi_bool*)_flag_wblob.data();
				   fpi_error _result = tos_power_suspend_get_usb_device_resuming_status( flag );
			
				   reply->writeInt32(_result); //fpi_error as return value
			
				   //-- end code for tos_power_suspend_get_usb_device_resuming_status here --
				   return NO_ERROR;
			   } break;
			   

            case TRANSACTION_tos_power_set_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_power_set_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_SETTING_POWER_CTRL type = (EN_SETTING_POWER_CTRL)data.readInt32();
                EN_POWER_TIMER_MODE mode = (EN_POWER_TIMER_MODE)data.readInt32();
                
                fpi_error _result = tos_power_set_mode( type, mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_power_set_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_power_get_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_power_get_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_SETTING_POWER_CTRL type = (EN_SETTING_POWER_CTRL)data.readInt32();
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_POWER_TIMER_MODE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_POWER_TIMER_MODE*)_value_wblob.data();
                }
				fpi_error _result;
				if( value != NULL ){
                _result = tos_power_get_mode( type, value );
					}else{
					_result = FPI_ERROR_FAIL;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_power_get_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_power_off:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_power_off here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_POWEROFF_TYPE type = (EN_POWEROFF_TYPE)data.readInt32();

                fpi_error _result = tos_power_off( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_power_off here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cancel_power_off:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cancel_power_off here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_cancel_power_off(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cancel_power_off here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_function_power_service_add() {
    sbinder_function_power_service::Instance();
    return 0;
}

sbinder_function_power_service* sbinder_function_power_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_function_power_client  
{  
private:
    static sbinder_function_power_client* _instance;
    sp<IBinder> _binder;

    sbinder_function_power_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_function_power_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_function_power_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_function_power_client();
        }

        return _instance;
    }

    fpi_error tos_power_set_mode( EN_SETTING_POWER_CTRL type, EN_POWER_TIMER_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_power_set_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_SETTING_POWER_CTRL as input paramter

            data.writeInt32(mode);  //EN_POWER_TIMER_MODE as input paramter

            _binder->transact(TRANSACTION_tos_power_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_power_set_mode error");
        }

        return _result;
        /*-- add you code for tos_power_set_mode here --*/
    }

    fpi_error tos_power_get_mode( EN_SETTING_POWER_CTRL type, EN_POWER_TIMER_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_power_get_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_SETTING_POWER_CTRL as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)1 * sizeof(EN_POWER_TIMER_MODE));//write length, only support 32 bits length yet
                
            }
            _binder->transact(TRANSACTION_tos_power_get_mode,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_power_get_mode error");
        }

        return _result;
        /*-- add you code for tos_power_get_mode here --*/
    }

    fpi_error tos_power_off( EN_POWEROFF_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_power_off here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_POWEROFF_TYPE as input paramter

            _binder->transact(TRANSACTION_tos_power_off,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_power_off error");
        }

        return _result;
        /*-- add you code for tos_power_off here --*/
    }

    fpi_error tos_cancel_power_off(  ) {
        Parcel data, reply;

        /*-- add you code for tos_cancel_power_off here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_cancel_power_off,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cancel_power_off error");
        }

        return _result;
        /*-- add you code for tos_cancel_power_off here --*/
    }
	  fpi_error tos_power_suspend_set_onoff_status( fpi_bool flag ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_set_onoff_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(flag);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_power_suspend_set_onoff_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_set_onoff_status error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_set_onoff_status error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_set_onoff_status here --*/
    }

    fpi_error tos_power_suspend_get_onoff_status( fpi_bool* flag ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_get_onoff_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (flag == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_power_suspend_get_onoff_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (flag != NULL) {
                    int _flag_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _flag_rblob;
                    reply.readBlob(_flag_len,&_flag_rblob);
                    memcpy(flag,_flag_rblob.data(),_flag_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_get_onoff_status error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_get_onoff_status error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_get_onoff_status here --*/
    }

    fpi_error tos_power_suspend_set_str_debug_val( int var ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_set_str_debug_val here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(var);  //int as input paramter

            _binder->transact(TRANSACTION_tos_power_suspend_set_str_debug_val,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_set_str_debug_val error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_set_str_debug_val error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_set_str_debug_val here --*/
    }
/*
    fpi_error tos_power_suspend_set_mode( EN_POWER_SUSPEND_WORK_MODE mode ) {
        Parcel data, reply;

        //-- add you code for tos_power_suspend_set_mode here 
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_POWER_SUSPEND_WORK_MODE as input paramter

            _binder->transact(TRANSACTION_tos_power_suspend_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_set_mode error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_set_mode error");
        }

        return _result;
        //-- add you code for tos_power_suspend_set_mode here --
    }
*/
    fpi_error tos_power_suspend_get_support_status( EN_POWER_SUSPEND_SUPPORT* type ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_get_support_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_POWER_SUSPEND_SUPPORT));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_power_suspend_get_support_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (type != NULL) {
                    int _type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _type_rblob;
                    reply.readBlob(_type_len,&_type_rblob);
                    memcpy(type,_type_rblob.data(),_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_get_support_status error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_get_support_status error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_get_support_status here --*/
    }


    fpi_error tos_power_suspend_get_current_work_mode( EN_POWER_SUSPEND_WORK_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_get_current_work_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_POWER_SUSPEND_WORK_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_power_suspend_get_current_work_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_power_suspend_get_current_work_mode error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_power_suspend_get_current_work_mode error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_get_current_work_mode here --*/
    }


    fpi_error tos_power_suspend_get_usb_device_resuming_status( fpi_bool* flag ) {
        Parcel data, reply;

        /*-- add you code for tos_power_suspend_get_usb_device_resuming_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (flag == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_power_suspend_get_usb_device_resuming_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (flag != NULL) {
                    int _flag_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _flag_rblob;
                    reply.readBlob(_flag_len,&_flag_rblob);
                    memcpy(flag,_flag_rblob.data(),_flag_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                CLOGW(SERVICE_NAME"_client tos_power_suspend_get_usb_device_resuming_status error");
            }
        }catch(...) {
            CLOGW(SERVICE_NAME"_client tos_power_suspend_get_usb_device_resuming_status error");
        }

        return _result;
        /*-- add you code for tos_power_suspend_get_usb_device_resuming_status here --*/
    }
};

sbinder_function_power_client* sbinder_function_power_client::_instance = NULL;

fpi_error tos_power_set_mode( EN_SETTING_POWER_CTRL type, EN_POWER_TIMER_MODE mode ) {
    return sbinder_function_power_client::Instance()->tos_power_set_mode(type, mode);
}
fpi_error tos_power_get_mode( EN_SETTING_POWER_CTRL type, EN_POWER_TIMER_MODE* value ) {
    return sbinder_function_power_client::Instance()->tos_power_get_mode(type, value);
}
fpi_error tos_power_off( EN_POWEROFF_TYPE type ) {
    return sbinder_function_power_client::Instance()->tos_power_off(type);
}
fpi_error tos_cancel_power_off(  ) {
    return sbinder_function_power_client::Instance()->tos_cancel_power_off();
}
fpi_error tos_power_suspend_set_onoff_status( fpi_bool flag ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_set_onoff_status(flag);
}
fpi_error tos_power_suspend_get_onoff_status( fpi_bool* flag ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_get_onoff_status(flag);
}
fpi_error tos_power_suspend_set_str_debug_val( int var ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_set_str_debug_val(var);
}
/*
fpi_error tos_power_suspend_set_mode( EN_POWER_SUSPEND_WORK_MODE mode ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_set_mode(mode);
}
*/
fpi_error tos_power_suspend_get_support_status( EN_POWER_SUSPEND_SUPPORT* type ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_get_support_status(type);
}

fpi_error tos_power_suspend_get_current_work_mode( EN_POWER_SUSPEND_WORK_MODE* mode ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_get_current_work_mode(mode);
}

fpi_error tos_power_suspend_get_usb_device_resuming_status( fpi_bool* flag ) {
    return sbinder_function_power_client::Instance()->tos_power_suspend_get_usb_device_resuming_status(flag);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
