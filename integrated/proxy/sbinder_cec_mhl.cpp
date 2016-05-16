/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_cec_mhl.sidl
 */
 

#define LOG_TAG     "sbinder_cec_mhl"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_cec_mhl.h"
#include "clog.h"

#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_CEC);


#define SERVICE_DESCRIPTOR                      "a3984866-a6b5-11e4-b189-005056a84a3b"
#define SERVICE_NAME                            "sbinder_cec_mhl"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_cec_set_enable FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_cec_get_enable FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_cec_send_key FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_cec_get_arc_status FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_cec_set_arc_status FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_cec_get_device_total_number FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_cec_get_dev_info FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_cec_get_device_volume FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_cec_get_device_mute_status FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_cec_get_arc_support_status FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_cec_power_device FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_cec_set_auto_power_mode FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_cec_get_auto_power_mode FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_mhl_send_key FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_mhl_get_mhl_dev_info FIRST_CALL_TRANSACTION + 15

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_cec_mhl.h"


class sbinder_cec_mhl_service : public BBinder  
{  
private:
    static sbinder_cec_mhl_service* _instance;

    sbinder_cec_mhl_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_cec_mhl_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_cec_mhl_service();
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

            case TRANSACTION_tos_cec_set_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_set_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t enable = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_cec_set_enable( enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_set_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* enable = NULL;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    Parcel::WritableBlob _enable_wblob;
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int32_t*)_enable_wblob.data();
                }

                fpi_error _result = tos_cec_get_enable( enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_send_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_send_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t un16UiKey = (uint16_t)data.readInt32();  //uint16_t as input paramter

                fpi_error _result = tos_cec_send_key( un16UiKey );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_send_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_arc_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_arc_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _pbStatus_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* pbStatus = NULL;
                if(_pbStatus_len > 0) {
                    reply->writeInt32(_pbStatus_len);
                    Parcel::WritableBlob _pbStatus_wblob;
                    reply->writeBlob(_pbStatus_len,&_pbStatus_wblob);
                    pbStatus = (int16_t*)_pbStatus_wblob.data();
                }
				fpi_error _result;
				if( pbStatus != NULL){
                _result = tos_cec_get_arc_status( un8Num, pbStatus );
					}else{
					_result = FPI_ERROR_FAIL ;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_arc_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_set_arc_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_set_arc_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int16_t bStatus = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_cec_set_arc_status( un8Num, bStatus, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_set_arc_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_device_total_number:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_device_total_number here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _totalNum_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* totalNum = NULL;
                if(_totalNum_len > 0) {
                    reply->writeInt32(_totalNum_len);
                    Parcel::WritableBlob _totalNum_wblob;
                    reply->writeBlob(_totalNum_len,&_totalNum_wblob);
                    totalNum = (uint8_t*)_totalNum_wblob.data();
                }
				fpi_error _result  ;
				if( totalNum != NULL){
                _result = tos_cec_get_device_total_number( totalNum );
					}else{
					_result = FPI_ERROR_FAIL;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_device_total_number here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_dev_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_dev_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            //#error not support this type of paramter st_fpi_cec_dev_base pDevInfo yet, please add code yourself
            int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_cec_dev_base* pDevInfo = NULL;
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    Parcel::WritableBlob _pout_wblob;
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    pDevInfo = (st_fpi_cec_dev_base*)_pout_wblob.data();
                }
				fpi_error _result ;
				if( pDevInfo != NULL ){
                _result = tos_cec_get_dev_info( pDevInfo );
					}else{
					_result = FPI_ERROR_FAIL ;
						}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_dev_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_device_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_user_value here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (uint16_t*)_value_wblob.data();
                }

                fpi_error _result = tos_cec_get_device_volume( un8Num, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_user_value here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			case TRANSACTION_tos_cec_get_device_mute_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_user_value here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                fpi_error _result = tos_cec_get_device_mute_status( un8Num, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_user_value here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_arc_support_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_arc_support_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _un8Flag_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* un8Flag = NULL;
                if(_un8Flag_len > 0) {
                    reply->writeInt32(_un8Flag_len);
                    Parcel::WritableBlob _un8Flag_wblob;
                    reply->writeBlob(_un8Flag_len,&_un8Flag_wblob);
                    un8Flag = (uint8_t*)_un8Flag_wblob.data();
                }

                fpi_error _result = tos_cec_get_arc_support_status( un8Num, un8Flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_arc_support_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_power_device:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_power_device here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t un8Num = (uint8_t)data.readInt32();  //uint8_t as input paramter

                EN_CEC_POWER_TYPE type = (EN_CEC_POWER_TYPE)data.readInt32();  //EN_CEC_POWER_TYPE as input paramter

                int16_t b_OnOff = (int16_t)data.readInt32();  //int16_t as input paramter

                fpi_error _result = tos_cec_power_device( un8Num, type, b_OnOff );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_power_device here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_set_auto_power_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_set_auto_power_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_CEC_POWER_TYPE type = (EN_CEC_POWER_TYPE)data.readInt32();  //EN_CEC_POWER_TYPE as input paramter

                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_cec_set_auto_power_mode( type, enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_set_auto_power_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_cec_get_auto_power_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_cec_get_auto_power_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_CEC_POWER_TYPE type = (EN_CEC_POWER_TYPE)data.readInt32();  //EN_CEC_POWER_TYPE as input paramter

                int _p_enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* p_enable = NULL;
                if(_p_enable_len > 0) {
                    reply->writeInt32(_p_enable_len);
                    Parcel::WritableBlob _p_enable_wblob;
                    reply->writeBlob(_p_enable_len,&_p_enable_wblob);
                    p_enable = (int16_t*)_p_enable_wblob.data();
                }

                fpi_error _result = tos_cec_get_auto_power_mode( type, p_enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_cec_get_auto_power_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mhl_send_key:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mhl_send_key here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint16_t un16UiKey = (uint16_t)data.readInt32();  //uint16_t as input paramter

                fpi_error _result = tos_mhl_send_key( un16UiKey );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mhl_send_key here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_mhl_get_mhl_dev_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_mhl_get_mhl_dev_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
            //#error not support this type of paramter st_fpi_tvget_mhl_dev_info pDevInfo yet, please add code yourself
              int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                st_fpi_tvget_mhl_dev_info* pDevInfo = NULL;
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    Parcel::WritableBlob _pout_wblob;
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    pDevInfo = (st_fpi_tvget_mhl_dev_info*)_pout_wblob.data();
                }
                fpi_error _result = tos_mhl_get_mhl_dev_info( pDevInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_mhl_get_mhl_dev_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_cec_mhl_service_add() {
    sbinder_cec_mhl_service::Instance();
    return 0;
}

sbinder_cec_mhl_service* sbinder_cec_mhl_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_cec_mhl_client  
{  
private:
    static sbinder_cec_mhl_client* _instance;
    sp<IBinder> _binder;

    sbinder_cec_mhl_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_cec_mhl_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_cec_mhl_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_cec_mhl_client();
        }

        return _instance;
    }

    fpi_error tos_cec_set_enable( int32_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_set_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(enable);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_cec_set_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_set_enable error");
        }

        return _result;
        /*-- add you code for tos_cec_set_enable here --*/
    }

    fpi_error tos_cec_get_enable( int32_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_enable here --*/
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
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_enable,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_cec_get_enable error");
        }

        return _result;
        /*-- add you code for tos_cec_get_enable here --*/
    }

    fpi_error tos_cec_send_key( uint16_t un16UiKey ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_send_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un16UiKey);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_cec_send_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_send_key error");
        }

        return _result;
        /*-- add you code for tos_cec_send_key here --*/
    }

    fpi_error tos_cec_get_arc_status( uint8_t un8Num, int16_t* pbStatus ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_arc_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pbStatus == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_arc_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pbStatus != NULL) {
                    int _pbStatus_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pbStatus_rblob;
                    reply.readBlob(_pbStatus_len,&_pbStatus_rblob);
                    memcpy(pbStatus,_pbStatus_rblob.data(),_pbStatus_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_get_arc_status error");
        }

        return _result;
        /*-- add you code for tos_cec_get_arc_status here --*/
    }

    fpi_error tos_cec_set_arc_status( uint8_t un8Num, int16_t bStatus, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_set_arc_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            data.writeInt32(bStatus);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_cec_set_arc_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_set_arc_status error");
        }

        return _result;
        /*-- add you code for tos_cec_set_arc_status here --*/
    }

    fpi_error tos_cec_get_device_total_number( uint8_t* totalNum ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_device_total_number here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (totalNum == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_device_total_number,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (totalNum != NULL) {
                    int _totalNum_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _totalNum_rblob;
                    reply.readBlob(_totalNum_len,&_totalNum_rblob);
                    memcpy(totalNum,_totalNum_rblob.data(),_totalNum_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_get_device_total_number error");
        }

        return _result;
        /*-- add you code for tos_cec_get_device_total_number here --*/
    }

    fpi_error tos_cec_get_dev_info( st_fpi_cec_dev_base* pDevInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_dev_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter st_fpi_cec_dev_base pDevInfo yet, please add code yourself
            data.writeInt32((int)(1) * sizeof(st_fpi_cec_dev_base));
            _binder->transact(TRANSACTION_tos_cec_get_dev_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter st_fpi_cec_dev_base pDevInfo yet, please add code yourself
                if (pDevInfo != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(pDevInfo,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_get_dev_info error");
        }

        return _result;
        /*-- add you code for tos_cec_get_dev_info here --*/
    }

    fpi_error tos_cec_get_device_volume( uint8_t un8Num, uint16_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_user_value here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_device_volume,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_cec_get_user_value error");
        }

        return _result;
        /*-- add you code for tos_cec_get_user_value here --*/
    }

	fpi_error tos_cec_get_device_mute_status( uint8_t un8Num, fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_user_value here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_device_mute_status,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_cec_get_user_value error");
        }

        return _result;
        /*-- add you code for tos_cec_get_user_value here --*/
    }
	
    fpi_error tos_cec_get_arc_support_status( uint8_t un8Num, uint8_t* un8Flag ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_arc_support_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (un8Flag == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_arc_support_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (un8Flag != NULL) {
                    int _un8Flag_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _un8Flag_rblob;
                    reply.readBlob(_un8Flag_len,&_un8Flag_rblob);
                    memcpy(un8Flag,_un8Flag_rblob.data(),_un8Flag_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_get_arc_support_status error");
        }

        return _result;
        /*-- add you code for tos_cec_get_arc_support_status here --*/
    }

    fpi_error tos_cec_power_device( uint8_t un8Num, EN_CEC_POWER_TYPE type, int16_t b_OnOff ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_power_device here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un8Num);  //uint8_t as input paramter

            data.writeInt32(type);  //EN_CEC_POWER_TYPE as input paramter

            data.writeInt32(b_OnOff);  //int16_t as input paramter

            _binder->transact(TRANSACTION_tos_cec_power_device,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_power_device error");
        }

        return _result;
        /*-- add you code for tos_cec_power_device here --*/
    }

    fpi_error tos_cec_set_auto_power_mode( EN_CEC_POWER_TYPE type, int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_set_auto_power_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_CEC_POWER_TYPE as input paramter

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_cec_set_auto_power_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_set_auto_power_mode error");
        }

        return _result;
        /*-- add you code for tos_cec_set_auto_power_mode here --*/
    }

    fpi_error tos_cec_get_auto_power_mode( EN_CEC_POWER_TYPE type, int16_t* p_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_cec_get_auto_power_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_CEC_POWER_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (p_enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_cec_get_auto_power_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (p_enable != NULL) {
                    int _p_enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _p_enable_rblob;
                    reply.readBlob(_p_enable_len,&_p_enable_rblob);
                    memcpy(p_enable,_p_enable_rblob.data(),_p_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_cec_get_auto_power_mode error");
        }

        return _result;
        /*-- add you code for tos_cec_get_auto_power_mode here --*/
    }

    fpi_error tos_mhl_send_key( uint16_t un16UiKey ) {
        Parcel data, reply;

        /*-- add you code for tos_mhl_send_key here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un16UiKey);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_mhl_send_key,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mhl_send_key error");
        }

        return _result;
        /*-- add you code for tos_mhl_send_key here --*/
    }

    fpi_error tos_mhl_get_mhl_dev_info( st_fpi_tvget_mhl_dev_info* pDevInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_mhl_get_mhl_dev_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter st_fpi_tvget_mhl_dev_info pDevInfo yet, please add code yourself
            data.writeInt32((int)(1) * sizeof(st_fpi_tvget_mhl_dev_info));
            _binder->transact(TRANSACTION_tos_mhl_get_mhl_dev_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                //#error not support this type of output paramter st_fpi_tvget_mhl_dev_info pDevInfo yet, please add code yourself
                if (pDevInfo != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(pDevInfo,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_mhl_get_mhl_dev_info error");
        }

        return _result;
        /*-- add you code for tos_mhl_get_mhl_dev_info here --*/
    }
};

sbinder_cec_mhl_client* sbinder_cec_mhl_client::_instance = NULL;

fpi_error tos_cec_set_enable( int32_t enable, EN_ACT_CTRL act ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_set_enable(enable, act);
}
fpi_error tos_cec_get_enable( int32_t* enable ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_enable(enable);
}
fpi_error tos_cec_send_key( uint16_t un16UiKey ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_send_key(un16UiKey);
}
fpi_error tos_cec_get_arc_status( uint8_t un8Num, int16_t* pbStatus ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_arc_status(un8Num, pbStatus);
}
fpi_error tos_cec_set_arc_status( uint8_t un8Num, int16_t bStatus, EN_ACT_CTRL act ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_set_arc_status(un8Num, bStatus, act);
}
fpi_error tos_cec_get_device_total_number( uint8_t* totalNum ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_device_total_number(totalNum);
}
fpi_error tos_cec_get_dev_info( st_fpi_cec_dev_base* pDevInfo ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_dev_info(pDevInfo);
}

fpi_error tos_cec_get_device_volume(uint8_t un8Num, uint16_t* value) {
	return sbinder_cec_mhl_client::Instance()->tos_cec_get_device_volume(un8Num, value);
}

fpi_error tos_cec_get_device_mute_status(uint8_t un8Num,fpi_bool * pIsMute) {
	return sbinder_cec_mhl_client::Instance()->tos_cec_get_device_mute_status(un8Num, pIsMute);
}

fpi_error tos_cec_get_arc_support_status( uint8_t un8Num, uint8_t* un8Flag ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_arc_support_status(un8Num, un8Flag);
}
fpi_error tos_cec_power_device( uint8_t un8Num, EN_CEC_POWER_TYPE type, int16_t b_OnOff ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_power_device(un8Num, type, b_OnOff);
}
fpi_error tos_cec_set_auto_power_mode( EN_CEC_POWER_TYPE type, int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_set_auto_power_mode(type, enable, act);
}
fpi_error tos_cec_get_auto_power_mode( EN_CEC_POWER_TYPE type, int16_t* p_enable ) {
    return sbinder_cec_mhl_client::Instance()->tos_cec_get_auto_power_mode(type, p_enable);
}

fpi_error tos_mhl_send_key( uint16_t un16UiKey ) {
    return sbinder_cec_mhl_client::Instance()->tos_mhl_send_key(un16UiKey);
}
fpi_error tos_mhl_get_mhl_dev_info( st_fpi_tvget_mhl_dev_info* pDevInfo ) {
    return sbinder_cec_mhl_client::Instance()->tos_mhl_get_mhl_dev_info(pDevInfo);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
