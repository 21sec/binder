/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_booking.sidl
 */
 

#define LOG_TAG     "sbinder_booking"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_booking.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_BOOKING);


#define SERVICE_DESCRIPTOR                      "15af9886-a5c2-11e4-b5bd-005056a84a3b"
#define SERVICE_NAME                            "sbinder_booking"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_booking_add_item FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_booking_set_item FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_booking_get_count FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_booking_get_item_list FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_booking_delete_item FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_booking_get_item_by_index FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_booking_get_item_by_schedule_id FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_booking_get_ahead_second FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_booking_start FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_booking_event_detect FIRST_CALL_TRANSACTION + 10

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_booking.h"

class sbinder_booking_service : public BBinder  
{  
private:
    static sbinder_booking_service* _instance;

    sbinder_booking_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_booking_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_booking_service();
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

            case TRANSACTION_tos_booking_add_item:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_add_item here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_info_t bookInfo = {0};
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(tos_schedule_info_t) )
					{
						memcpy(&bookInfo,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
					}
                }

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_BOOKING_ERROR_e* state = NULL;
				Parcel::WritableBlob _state_wblob;
				
                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (EN_TOS_BOOKING_ERROR_e*)_state_wblob.data();
                }

                fpi_error _result = tos_booking_add_item( &bookInfo, state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_add_item here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_set_item:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_set_item here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_info_t bookInfo = {0};
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(tos_schedule_info_t) )
					{
						memcpy(&bookInfo,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
					}
                }

                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_BOOKING_ERROR_e* state = NULL;
				Parcel::WritableBlob _state_wblob;
				
                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (EN_TOS_BOOKING_ERROR_e*)_state_wblob.data();
                }

                fpi_error _result = tos_booking_set_item( &bookInfo, state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_set_item here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_get_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_get_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* count = NULL;
				Parcel::WritableBlob _count_wblob;
				
                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (uint8_t*)_count_wblob.data();
                }

                fpi_error _result = tos_booking_get_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_get_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_get_item_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_get_item_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t itemCount = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_info_t* bookInfoList = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    bookInfoList = (tos_schedule_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_booking_get_item_list( itemCount, bookInfoList );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_get_item_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_delete_item:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_delete_item here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t scheduleId = (uint8_t)data.readInt32();  //uint8_t as input paramter

                fpi_error _result = tos_booking_delete_item( scheduleId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_delete_item here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_get_item_by_index:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_get_item_by_index here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t index = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_info_t* bookInfo = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    bookInfo = (tos_schedule_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_booking_get_item_by_index( index, bookInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_get_item_by_index here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_get_item_by_schedule_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_get_item_by_schedule_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t schedule_id = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_info_t* bookInfo = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    bookInfo = (tos_schedule_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_booking_get_item_by_schedule_id( schedule_id, bookInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_get_item_by_schedule_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_get_ahead_second:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_get_ahead_second here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _sec_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* sec = NULL;
				Parcel::WritableBlob _sec_wblob;
				
                if(_sec_len > 0) {
                    reply->writeInt32(_sec_len);
                    reply->writeBlob(_sec_len,&_sec_wblob);
                    sec = (uint32_t*)_sec_wblob.data();
                }

                fpi_error _result = tos_booking_get_ahead_second( sec );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_get_ahead_second here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool start_flg = (fpi_bool)data.readInt32();

                fpi_error _result = tos_booking_start( start_flg );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_booking_event_detect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_booking_event_detect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_detect_para detectPara = {0};
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(tos_schedule_detect_para) )
					{
						memcpy(&detectPara,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
					}
                }

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_schedule_detect_result* detectRet = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    detectRet = (tos_schedule_detect_result*)_pout_wblob.data();
                }

                fpi_error _result = tos_booking_event_detect( &detectPara, detectRet );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_booking_event_detect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_booking_service_add() {
    sbinder_booking_service::Instance();
    return 0;
}

sbinder_booking_service* sbinder_booking_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_booking_client  
{  
private:
    static sbinder_booking_client* _instance;
    sp<IBinder> _binder;

    sbinder_booking_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_booking_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_booking_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_booking_client();
        }

        return _instance;
    }

    fpi_error tos_booking_add_item( tos_schedule_info_t* bookInfo, EN_TOS_BOOKING_ERROR_e* state ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_add_item here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(tos_schedule_info_t));//write length, only support 32 bits length yet
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(tos_schedule_info_t),&_pin_wblob);
            memcpy(_pin_wblob.data(),bookInfo,(1)* sizeof(tos_schedule_info_t));
                
            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_BOOKING_ERROR_e));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_booking_add_item,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_booking_add_item error");
        }

        return _result;
        /*-- add you code for tos_booking_add_item here --*/
    }

    fpi_error tos_booking_set_item( tos_schedule_info_t* bookInfo, EN_TOS_BOOKING_ERROR_e* state ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_set_item here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(tos_schedule_info_t));//write length, only support 32 bits length yet
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(tos_schedule_info_t),&_pin_wblob);
            memcpy(_pin_wblob.data(),bookInfo,(1)* sizeof(tos_schedule_info_t));

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_BOOKING_ERROR_e));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_booking_set_item,data, &reply,0);

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
            fpi_warn(SERVICE_NAME"_client tos_booking_set_item error");
        }

        return _result;
        /*-- add you code for tos_booking_set_item here --*/
    }

    fpi_error tos_booking_get_count( uint8_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_get_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_booking_get_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value
                
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_get_count error");
        }

        return _result;
        /*-- add you code for tos_booking_get_count here --*/
    }

    fpi_error tos_booking_get_item_list( uint8_t itemCount, tos_schedule_info_t* bookInfoList ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_get_item_list here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(itemCount);  //uint8_t as input paramter

            data.writeInt32((int)(itemCount) * sizeof(tos_schedule_info_t));
            
            _binder->transact(TRANSACTION_tos_booking_get_item_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (bookInfoList != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(bookInfoList,_pout_rblob.data(),_pout_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_get_item_list error");
        }

        return _result;
        /*-- add you code for tos_booking_get_item_list here --*/
    }

    fpi_error tos_booking_delete_item( uint8_t scheduleId ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_delete_item here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(scheduleId);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_booking_delete_item,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_delete_item error");
        }

        return _result;
        /*-- add you code for tos_booking_delete_item here --*/
    }

    fpi_error tos_booking_get_item_by_index( uint8_t index, tos_schedule_info_t* bookInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_get_item_by_index here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(index);  //uint8_t as input paramter

            data.writeInt32((int)(1) * sizeof(tos_schedule_info_t));

            _binder->transact(TRANSACTION_tos_booking_get_item_by_index,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (bookInfo != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(bookInfo,_pout_rblob.data(),_pout_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_get_item_by_index error");
        }

        return _result;
        /*-- add you code for tos_booking_get_item_by_index here --*/
    }

    fpi_error tos_booking_get_item_by_schedule_id( uint8_t schedule_id, tos_schedule_info_t* bookInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_get_item_by_schedule_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(schedule_id);  //uint8_t as input paramter

            data.writeInt32((int)(1) * sizeof(tos_schedule_info_t));

            _binder->transact(TRANSACTION_tos_booking_get_item_by_schedule_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (bookInfo != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(bookInfo,_pout_rblob.data(),_pout_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_get_item_by_schedule_id error");
        }

        return _result;
        /*-- add you code for tos_booking_get_item_by_schedule_id here --*/
    }

    fpi_error tos_booking_get_ahead_second( uint32_t* sec ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_get_ahead_second here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (sec == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_booking_get_ahead_second,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (sec != NULL) {
                    int _sec_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _sec_rblob;
                    reply.readBlob(_sec_len,&_sec_rblob);
                    memcpy(sec,_sec_rblob.data(),_sec_len);
                } 
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_get_ahead_second error");
        }

        return _result;
        /*-- add you code for tos_booking_get_ahead_second here --*/
    }

    fpi_error tos_booking_start( fpi_bool start_flg ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(start_flg);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_booking_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_start error");
        }

        return _result;
        /*-- add you code for tos_booking_start here --*/
    }

    fpi_error tos_booking_event_detect( tos_schedule_detect_para* detectPara, tos_schedule_detect_result* detectRet ) {
        Parcel data, reply;

        /*-- add you code for tos_booking_event_detect here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(tos_schedule_detect_para));//write length, only support 32 bits length yet
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(tos_schedule_detect_para),&_pin_wblob);
            memcpy(_pin_wblob.data(),detectPara,(1)* sizeof(tos_schedule_detect_para));

            data.writeInt32((int)(1) * sizeof(tos_schedule_detect_result));

            _binder->transact(TRANSACTION_tos_booking_event_detect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (detectRet != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(detectRet,_pout_rblob.data(),_pout_len);
                }

                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_booking_event_detect error");
        }

        return _result;
        /*-- add you code for tos_booking_event_detect here --*/
    }
};

sbinder_booking_client* sbinder_booking_client::_instance = NULL;

fpi_error tos_booking_add_item( tos_schedule_info_t* bookInfo, EN_TOS_BOOKING_ERROR_e* state ) {
    return sbinder_booking_client::Instance()->tos_booking_add_item(bookInfo, state);
}
fpi_error tos_booking_set_item( tos_schedule_info_t* bookInfo, EN_TOS_BOOKING_ERROR_e* state ) {
    return sbinder_booking_client::Instance()->tos_booking_set_item(bookInfo, state);
}
fpi_error tos_booking_get_count( uint8_t* count ) {
    return sbinder_booking_client::Instance()->tos_booking_get_count(count);
}
fpi_error tos_booking_get_item_list( uint8_t itemCount, tos_schedule_info_t* bookInfoList ) {
    return sbinder_booking_client::Instance()->tos_booking_get_item_list(itemCount, bookInfoList);
}
fpi_error tos_booking_delete_item( uint8_t scheduleId ) {
    return sbinder_booking_client::Instance()->tos_booking_delete_item(scheduleId);
}
fpi_error tos_booking_get_item_by_index( uint8_t index, tos_schedule_info_t* bookInfo ) {
    return sbinder_booking_client::Instance()->tos_booking_get_item_by_index(index, bookInfo);
}
fpi_error tos_booking_get_item_by_schedule_id( uint8_t schedule_id, tos_schedule_info_t* bookInfo ) {
    return sbinder_booking_client::Instance()->tos_booking_get_item_by_schedule_id(schedule_id, bookInfo);
}
fpi_error tos_booking_get_ahead_second( uint32_t* sec ) {
    return sbinder_booking_client::Instance()->tos_booking_get_ahead_second(sec);
}
fpi_error tos_booking_start( fpi_bool start_flg ) {
    return sbinder_booking_client::Instance()->tos_booking_start(start_flg);
}
fpi_error tos_booking_event_detect( tos_schedule_detect_para* detectPara, tos_schedule_detect_result* detectRet ) {
    return sbinder_booking_client::Instance()->tos_booking_event_detect(detectPara, detectRet);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
