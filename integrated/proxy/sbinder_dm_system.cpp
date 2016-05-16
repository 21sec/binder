/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: tmp/sbinder_dm_system.sidl
 */
 

#define LOG_TAG     "sbinder_dm_system"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include <stdlib.h>
#include "sbinder_dm_system.h"
#include "tos_dtv_basetype.h"
#include "tos_dm_system.h"
#include "tos_tcli.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PLAY);


#define SERVICE_DESCRIPTOR                      "9deb7e44-cc7e-11e4-b7f0-005056a84a3b"
#define SERVICE_NAME                            "sbinder_dm_system"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_channel_set_power_on_play_channel FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_channel_get_power_on_play_channel_info FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_system_get_power_on_select_mode FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_system_set_power_on_select_mode FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_channel_set_system_country FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_channel_get_system_country FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_tuner_get_delivery_type FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_tuner_set_delivery_type FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_set_pvr_time_shift_enable_status FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_get_pvr_time_shift_enable_status FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_set_first_audio_language FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_get_first_audio_language FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_set_second_audio_language FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_get_second_audio_language FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_channel_set_channel_list_type FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_channel_get_channel_list_type FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_ci_op_get_channel_list_type FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_ci_op_set_channel_list_type FIRST_CALL_TRANSACTION + 18

using namespace sita_android;

#if defined(BINDER_SERVICE)

class sbinder_dm_system_service : public BBinder  
{  
private:
    static sbinder_dm_system_service* _instance;

    sbinder_dm_system_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_dm_system_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_dm_system_service();
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

            case TRANSACTION_tos_channel_set_power_on_play_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				uint32_t channelId = data.readInt32();
                fpi_error _result = tos_channel_set_power_on_play_channel( channelId );
				reply->writeInt32(_result);
                
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_power_on_play_channel_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
				
				int _pout_len = data.readInt32(); //read count

				tos_channel_info_t *channelInfoRet = NULL;
				Parcel::WritableBlob _pout_rblob;
				
				if (_pout_len > 0)
				{
					reply->writeInt32(_pout_len);
					reply->writeBlob(_pout_len, &_pout_rblob);
					channelInfoRet = (tos_channel_info_t*)_pout_rblob.data();
				}
				
                fpi_error _result = tos_channel_get_power_on_play_channel_info( channelInfoRet );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_system_get_power_on_select_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				EN_TOS_CHANNEL_SELECT_MODE retSelectMode;
				
                fpi_error _result = tos_system_get_power_on_select_mode( &retSelectMode );

                reply->writeInt32(retSelectMode);
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_system_set_power_on_select_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				EN_TOS_CHANNEL_SELECT_MODE selectMode = (EN_TOS_CHANNEL_SELECT_MODE)data.readInt32();
				
                fpi_error _result = tos_system_set_power_on_select_mode( selectMode );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_set_system_country:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				MEMBER_COUNTRY sysCountry = (MEMBER_COUNTRY)data.readInt32();
				
                fpi_error _result = tos_channel_set_system_country( sysCountry );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_system_country:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				MEMBER_COUNTRY retSysCountry;
				
                fpi_error _result = tos_channel_get_system_country( &retSysCountry );
				reply->writeInt32(retSysCountry);
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tuner_get_delivery_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				fpi_dtv_delivery_type_t retDeliveryType;
				
                fpi_error _result = tos_tuner_get_delivery_type( &retDeliveryType );

                reply->writeInt32(retDeliveryType);
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tuner_set_delivery_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				fpi_dtv_delivery_type_t deliveryType = (fpi_dtv_delivery_type_t)data.readInt32();
				
                fpi_error _result = tos_tuner_set_delivery_type( deliveryType );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_set_pvr_time_shift_enable_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				fpi_bool statusValue = data.readInt32();
				
                fpi_error _result = tos_set_pvr_time_shift_enable_status( statusValue );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_get_pvr_time_shift_enable_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				fpi_bool retStatus = fpi_false;
				
                fpi_error _result = tos_get_pvr_time_shift_enable_status( &retStatus );

				reply->writeInt32(retStatus);
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_set_first_audio_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
				
                MEMBER_LANGUAGE language = (MEMBER_LANGUAGE)data.readInt32();
				
                fpi_error _result = tos_set_first_audio_language( language );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_get_first_audio_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
                
				MEMBER_LANGUAGE languageValue; 
                
                fpi_error _result = tos_get_first_audio_language( &languageValue );
				
				reply->writeInt32(languageValue);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_set_second_audio_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				MEMBER_LANGUAGE language = (MEMBER_LANGUAGE)data.readInt32();
				
                fpi_error _result = tos_set_second_audio_language( language );
                reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_get_second_audio_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				MEMBER_LANGUAGE languageValue; 

                fpi_error _result = tos_get_second_audio_language( &languageValue );

				reply->writeInt32(languageValue);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_set_channel_list_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
				
				EN_TOS_CHANEL_LIST_TYPE listType = (EN_TOS_CHANEL_LIST_TYPE)data.readInt32();

                fpi_error _result = tos_channel_set_channel_list_type( listType );
				reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_channel_list_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				EN_TOS_CHANEL_LIST_TYPE listType;

                fpi_error _result = tos_channel_get_channel_list_type( &listType );

				reply->writeInt32(listType);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_get_channel_list_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				EN_TOS_CI_OP_CHANNEL_LIST_TYPE retValue;
				
                fpi_error _result = tos_ci_op_get_channel_list_type( &retValue );

				reply->writeInt32(retValue);
				reply->writeInt32(_result);
								
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_set_channel_list_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
				
				EN_TOS_CI_OP_CHANNEL_LIST_TYPE listType = (EN_TOS_CI_OP_CHANNEL_LIST_TYPE)data.readInt32();
			
                fpi_error _result = tos_ci_op_set_channel_list_type( listType );

				reply->writeInt32(listType);
				reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_dm_system_service_add() {
    sbinder_dm_system_service::Instance();
    return 0;
}

sbinder_dm_system_service* sbinder_dm_system_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_dm_system_client  
{  
private:
    static sbinder_dm_system_client* _instance;
    sp<IBinder> _binder;

    sbinder_dm_system_client() {
        fpi_info(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_dm_system_client() {
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
    static sbinder_dm_system_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_dm_system_client();
        }

        return _instance;
    }

    fpi_error tos_channel_set_power_on_play_channel(uint32_t channelId) {
        Parcel data, reply;

        /*-- add you code for tos_channel_set_power_on_play_channel here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(channelId);
				
            _binder->transact(TRANSACTION_tos_channel_set_power_on_play_channel, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_set_power_on_play_channel error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_set_power_on_play_channel error");
        }

        return _result;
        /*-- add you code for tos_channel_set_power_on_play_channel here --*/
    }

    fpi_error tos_channel_get_power_on_play_channel_info( tos_channel_info_t* info ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_get_power_on_play_channel_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (info == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(tos_channel_info_t));
			}

            _binder->transact(TRANSACTION_tos_channel_get_power_on_play_channel_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				if (info != NULL)
				{
					int _pout_len = reply.readInt32();
					Parcel::ReadableBlob _pout_rblob;
					reply.readBlob(_pout_len, &_pout_rblob);
					memcpy(info, _pout_rblob.data(), _pout_len);
				}
				_result= (typeof(_result))reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_get_power_on_play_channel_info error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_power_on_play_channel_info error");
        }

        return _result;
        /*-- add you code for tos_channel_get_power_on_play_channel_info here --*/
    }

    fpi_error tos_system_get_power_on_select_mode( EN_TOS_CHANNEL_SELECT_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_system_get_power_on_select_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (mode == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}

            _binder->transact(TRANSACTION_tos_system_get_power_on_select_mode, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (mode != NULL)
				{
					*mode = (EN_TOS_CHANNEL_SELECT_MODE)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_system_get_power_on_select_mode error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_system_get_power_on_select_mode error");
        }

        return _result;
        /*-- add you code for tos_system_get_power_on_select_mode here --*/
    }

    fpi_error tos_system_set_power_on_select_mode( EN_TOS_CHANNEL_SELECT_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_system_set_power_on_select_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(mode);

            _binder->transact(TRANSACTION_tos_system_set_power_on_select_mode, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_system_set_power_on_select_mode error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_system_set_power_on_select_mode error");
        }

        return _result;
        /*-- add you code for tos_system_set_power_on_select_mode here --*/
    }

    fpi_error tos_channel_set_system_country( MEMBER_COUNTRY country ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_set_system_country here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32((uint32_t)country);

            _binder->transact(TRANSACTION_tos_channel_set_system_country,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_set_system_country error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_set_system_country error");
        }

        return _result;
        /*-- add you code for tos_channel_set_system_country here --*/
    }

    fpi_error tos_channel_get_system_country( MEMBER_COUNTRY* country ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_get_system_country here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (country == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
			
            _binder->transact(TRANSACTION_tos_channel_get_system_country, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (country != NULL)
				{
					*country = (MEMBER_COUNTRY)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_get_system_country error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_system_country error");
        }

        return _result;
        /*-- add you code for tos_channel_get_system_country here --*/
    }

    fpi_error tos_tuner_get_delivery_type( fpi_dtv_delivery_type_t* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_tuner_get_delivery_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (mode == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
			
            _binder->transact(TRANSACTION_tos_tuner_get_delivery_type, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (mode != NULL)
				{
					*mode = (fpi_dtv_delivery_type_t)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_tuner_get_delivery_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_tuner_get_delivery_type error");
        }

        return _result;
        /*-- add you code for tos_tuner_get_delivery_type here --*/
    }

    fpi_error tos_tuner_set_delivery_type( fpi_dtv_delivery_type_t mode ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(mode);
			
            _binder->transact(TRANSACTION_tos_tuner_set_delivery_type, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_tuner_set_delivery_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_tuner_set_delivery_type error");
        }

        return _result;
        /*-- add you code for tos_tuner_set_delivery_type here --*/
    }

    fpi_error tos_set_pvr_time_shift_enable_status( fpi_bool status ) {
        Parcel data, reply;

        /*-- add you code for tos_set_pvr_time_shift_enable_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32((uint32_t)status);
			
            _binder->transact(TRANSACTION_tos_set_pvr_time_shift_enable_status, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_set_pvr_time_shift_enable_status error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_set_pvr_time_shift_enable_status error");
        }

        return _result;
        /*-- add you code for tos_set_pvr_time_shift_enable_status here --*/
    }

    fpi_error tos_get_pvr_time_shift_enable_status( fpi_bool* status ) {
        Parcel data, reply;

        /*-- add you code for tos_get_pvr_time_shift_enable_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (status == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
            _binder->transact(TRANSACTION_tos_get_pvr_time_shift_enable_status, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (status != NULL)
				{
					*status = reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_get_pvr_time_shift_enable_status error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_get_pvr_time_shift_enable_status error");
        }

        return _result;
        /*-- add you code for tos_get_pvr_time_shift_enable_status here --*/
    }

    fpi_error tos_set_first_audio_language( MEMBER_LANGUAGE language ) {
        Parcel data, reply;

        /*-- add you code for tos_set_first_audio_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(language);
			
            _binder->transact(TRANSACTION_tos_set_first_audio_language, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_set_first_audio_language error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_set_first_audio_language error");
        }

        return _result;
        /*-- add you code for tos_set_first_audio_language here --*/
    }

    fpi_error tos_get_first_audio_language( MEMBER_LANGUAGE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_get_first_audio_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (value == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
				
            _binder->transact(TRANSACTION_tos_get_first_audio_language, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (value != NULL)
				{
					*value = (MEMBER_LANGUAGE)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_get_first_audio_language error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_get_first_audio_language error");
        }

        return _result;
        /*-- add you code for tos_get_first_audio_language here --*/
    }

    fpi_error tos_set_second_audio_language( MEMBER_LANGUAGE language ) {
        Parcel data, reply;

        /*-- add you code for tos_set_second_audio_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(language);
			
            _binder->transact(TRANSACTION_tos_set_second_audio_language, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_set_second_audio_language error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_set_second_audio_language error");
        }

        return _result;
        /*-- add you code for tos_set_second_audio_language here --*/
    }

    fpi_error tos_get_second_audio_language( MEMBER_LANGUAGE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_get_second_audio_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (value == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
			
            _binder->transact(TRANSACTION_tos_get_second_audio_language, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (value != NULL)
				{
					*value = (MEMBER_LANGUAGE)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_get_second_audio_language error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_get_second_audio_language error");
        }

        return _result;
        /*-- add you code for tos_get_second_audio_language here --*/
    }

    fpi_error tos_channel_set_channel_list_type( EN_TOS_CHANEL_LIST_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_set_channel_list_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32((uint32_t)type);
			
            _binder->transact(TRANSACTION_tos_channel_set_channel_list_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_set_channel_list_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_set_channel_list_type error");
        }

        return _result;
        /*-- add you code for tos_channel_set_channel_list_type here --*/
    }

    fpi_error tos_channel_get_channel_list_type( EN_TOS_CHANEL_LIST_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_channel_get_channel_list_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (type == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}

            _binder->transact(TRANSACTION_tos_channel_get_channel_list_type, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (type != NULL)
				{
					*type = (EN_TOS_CHANEL_LIST_TYPE)reply.readInt32();
				}
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_channel_get_channel_list_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_channel_list_type error");
        }

        return _result;
        /*-- add you code for tos_channel_get_channel_list_type here --*/
    }

    fpi_error tos_ci_op_get_channel_list_type( EN_TOS_CI_OP_CHANNEL_LIST_TYPE* value ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (value == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(uint32_t));
			}
			
            _binder->transact(TRANSACTION_tos_ci_op_get_channel_list_type, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (value != NULL)
				{
					*value = (EN_TOS_CI_OP_CHANNEL_LIST_TYPE)reply.readInt32();
				}
            	_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_ci_op_get_channel_list_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_ci_op_get_channel_list_type error");
        }

        return _result;
        /*-- add you code for tos_ci_op_get_channel_list_type here --*/
    }

    fpi_error tos_ci_op_set_channel_list_type( EN_TOS_CI_OP_CHANNEL_LIST_TYPE type ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32((int32_t)type);

            _binder->transact(TRANSACTION_tos_ci_op_set_channel_list_type, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            } else {
                fpi_err(SERVICE_NAME"_client tos_ci_op_set_channel_list_type error");
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_ci_op_set_channel_list_type error");
        }

        return _result;
        /*-- add you code for tos_ci_op_set_channel_list_type here --*/
    }
};

sbinder_dm_system_client* sbinder_dm_system_client::_instance = NULL;

fpi_error tos_channel_set_power_on_play_channel(uint32_t channelId) {
    return sbinder_dm_system_client::Instance()->tos_channel_set_power_on_play_channel(channelId);
}
fpi_error tos_channel_get_power_on_play_channel_info( tos_channel_info_t* info ) {
    return sbinder_dm_system_client::Instance()->tos_channel_get_power_on_play_channel_info(info);
}
fpi_error tos_system_get_power_on_select_mode( EN_TOS_CHANNEL_SELECT_MODE* mode ) {
    return sbinder_dm_system_client::Instance()->tos_system_get_power_on_select_mode(mode);
}
fpi_error tos_system_set_power_on_select_mode( EN_TOS_CHANNEL_SELECT_MODE mode ) {
    return sbinder_dm_system_client::Instance()->tos_system_set_power_on_select_mode(mode);
}
fpi_error tos_channel_set_system_country( MEMBER_COUNTRY country ) {
    return sbinder_dm_system_client::Instance()->tos_channel_set_system_country(country);
}
fpi_error tos_channel_get_system_country( MEMBER_COUNTRY* country ) {
    return sbinder_dm_system_client::Instance()->tos_channel_get_system_country(country);
}
fpi_error tos_tuner_get_delivery_type(fpi_dtv_delivery_type_t* mode ) {
    return sbinder_dm_system_client::Instance()->tos_tuner_get_delivery_type(mode);
}
fpi_error tos_tuner_set_delivery_type( fpi_dtv_delivery_type_t mode ) {
    return sbinder_dm_system_client::Instance()->tos_tuner_set_delivery_type(mode);
}
fpi_error tos_set_pvr_time_shift_enable_status( fpi_bool status ) {
    return sbinder_dm_system_client::Instance()->tos_set_pvr_time_shift_enable_status(status);
}
fpi_error tos_get_pvr_time_shift_enable_status( fpi_bool* status ) {
    return sbinder_dm_system_client::Instance()->tos_get_pvr_time_shift_enable_status(status);
}
fpi_error tos_set_first_audio_language( MEMBER_LANGUAGE language ) {
    return sbinder_dm_system_client::Instance()->tos_set_first_audio_language(language);
}
fpi_error tos_get_first_audio_language( MEMBER_LANGUAGE* value ) {
    return sbinder_dm_system_client::Instance()->tos_get_first_audio_language(value);
}
fpi_error tos_set_second_audio_language( MEMBER_LANGUAGE language ) {
    return sbinder_dm_system_client::Instance()->tos_set_second_audio_language(language);
}
fpi_error tos_get_second_audio_language( MEMBER_LANGUAGE* value ) {
    return sbinder_dm_system_client::Instance()->tos_get_second_audio_language(value);
}
fpi_error tos_channel_set_channel_list_type( EN_TOS_CHANEL_LIST_TYPE type ) {
    return sbinder_dm_system_client::Instance()->tos_channel_set_channel_list_type(type);
}
fpi_error tos_channel_get_channel_list_type( EN_TOS_CHANEL_LIST_TYPE* type ) {
    return sbinder_dm_system_client::Instance()->tos_channel_get_channel_list_type(type);
}
fpi_error tos_ci_op_get_channel_list_type( EN_TOS_CI_OP_CHANNEL_LIST_TYPE* value ) {
    return sbinder_dm_system_client::Instance()->tos_ci_op_get_channel_list_type(value);
}
fpi_error tos_ci_op_set_channel_list_type( EN_TOS_CI_OP_CHANNEL_LIST_TYPE type ) {
    return sbinder_dm_system_client::Instance()->tos_ci_op_set_channel_list_type(type);
}


static void _test_get_system_country(void) {
	MEMBER_COUNTRY country = E_OTHERS;
	fpi_error err = tos_channel_get_system_country( &country );
	tos_tcli_printf("getSystemCountry err=%d country=%d\n", err, country);
}
TOS_TCLI_COMMAND(tos.system.getSystemCountry,"getSystemCountry","long help","",_test_get_system_country);


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
