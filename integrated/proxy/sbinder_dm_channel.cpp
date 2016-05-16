/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: tmp/sbinder_dm_channel.sidl
 */
 

#define LOG_TAG     "sbinder_dm_channel"

#include "tos_tcli.h"
#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include <stdlib.h>
#include "sbinder_dm_channel.h"
#include "fpi_debug_helper.h"

#define SERVICE_DESCRIPTOR                      "32f3d786-a2ac-11e4-8913-005056a84a3b"
#define SERVICE_NAME                            "sbinder_dm_channel"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_channel_get_channelId_by_number FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_channel_get_channel_info_by_id FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_channel_get_channellist_by_mask FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_channel_get_channel_count_by_mask FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_channel_set_channel_info FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_channel_get_channel_list_version FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_channel_get_operator_list FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_channel_get_operator_count FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_channel_set_fav_networkId FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_channel_get_fav_networkId FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_channel_get_muxInfo FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_channel_clean_channel_list FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_channel_db_update FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_channel_get_program_number_by_same_lcn FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_channel_move_program_by_index FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_channel_get_last_service_type  FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_channel_play_get_current_by_servicetype  FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_channel_list_channel_insert  FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_channel_get_first_index_by_rf_number  FIRST_CALL_TRANSACTION + 19


using namespace sita_android;
SET_MODEL_ID(SITA_MODULE_PLAY);

#if defined(BINDER_SERVICE)

class sbinder_dm_channel_service : public BBinder  
{  
private:
    static sbinder_dm_channel_service* _instance;

    sbinder_dm_channel_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_dm_channel_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_dm_channel_service();
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

			case TRANSACTION_tos_channel_get_channelId_by_number:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                EN_TOS_SERVICE_TYPE serviceType = (EN_TOS_SERVICE_TYPE)data.readInt32();  //TOS_SERVICE_TYPE_E as input paramter

                uint16_t channelNumber = (uint16_t)data.readInt32();  //uint16_t as input paramter

                uint32_t nChannelId = 0;

                fpi_error _result = tos_channel_get_channelId_by_number( serviceType, channelNumber, &nChannelId );
			
				reply->writeInt32(_result);
				reply->writeInt32(nChannelId);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_channel_info_by_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint32_t channelId = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _pout_len = data.readInt32(); //read count
				
				tos_channel_info_t *channelInfoRet = NULL;
				Parcel::WritableBlob _pout_wblob;  
				if (_pout_len > 0)
				{
					reply->writeInt32(_pout_len);                 
					reply->writeBlob(_pout_len, &_pout_wblob);
					channelInfoRet = (tos_channel_info_t*)_pout_wblob.data();
				}

                fpi_error _result = tos_channel_get_channel_info_by_id( channelId, channelInfoRet );
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_channellist_by_mask:
            {	//Todo
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

				reply->writeNoException();
				uint32_t nChannelCount = 0;

				uint32_t mask = (uint32_t)data.readInt32();  //uint32_t as input paramter

				int _count_len = data.readInt32();
				int _channelList_len = data.readInt32();
				tos_channel_info_t* channelInfoList = NULL;
				nChannelCount = _count_len;

				Parcel::WritableBlob _pout_wblob; 

				if (_channelList_len > 0)
				{
					reply->writeInt32(_channelList_len);               
					reply->writeBlob(_channelList_len, &_pout_wblob);
					channelInfoList = (tos_channel_info_t*)_pout_wblob.data();
				}

				fpi_error _result = tos_channel_get_channellist_by_mask( mask, channelInfoList, &nChannelCount );

				if (_count_len > 0)
				{
					reply->writeInt32(nChannelCount);
				}
				reply->writeInt32(_result);

				fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			} break;
            
			case TRANSACTION_tos_channel_get_channel_count_by_mask:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint32_t mask = (uint32_t)data.readInt32();  //uint32_t as input paramter

				uint32_t _pCount_in = (uint32_t)data.readInt32();
                uint32_t nCount = 0;
				uint32_t *pCount = NULL;
				if (_pCount_in > 0)
				{
					pCount = &nCount;
				}
           
                fpi_error _result = tos_channel_get_channel_count_by_mask( mask, pCount);
				reply->writeInt32(nCount);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_set_channel_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                int _pin_len = data.readInt32(); //read count
                tos_channel_info_t _pin_S;           
				memset(&_pin_S,0,sizeof(_pin_S));

				tos_channel_info_t* pin = NULL;
				Parcel::ReadableBlob _pin_rblob;
				
				if (_pin_len > 0)
				{
					data.readBlob(_pin_len, &_pin_rblob);
					pin = (tos_channel_info_t*)_pin_rblob.data();
				}
				
                fpi_error _result = tos_channel_set_channel_info( pin );
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_channel_list_version:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint32_t nChListVersion = 0;

                fpi_error _result = tos_channel_get_channel_list_version( &nChListVersion );

				reply->writeInt32(nChListVersion);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_operator_list:
            {	//Todo
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

				int _operatorList_len = data.readInt32();		
                uint32_t nCount = 0;
				
				tos_channel_operator_info_t* pOperatorList = NULL;
				Parcel::WritableBlob _pin_rblob;
				
				if (_operatorList_len > 0)
				{
					reply->writeInt32(_operatorList_len);
					reply->writeBlob(_operatorList_len, &_pin_rblob);
					pOperatorList= (tos_channel_operator_info_t*)_pin_rblob.data();
				}
                fpi_error _result = tos_channel_get_operator_list( pOperatorList, &nCount );
				reply->writeInt32(nCount);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_operator_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint32_t nCount = 0;

                fpi_error _result = tos_channel_get_operator_count( &nCount );
                reply->writeInt32(nCount);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_set_fav_networkId:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                reply->writeNoException();
				
                uint16_t networkId = (uint16_t)data.readInt32();  //uint16_t as input paramter

                fpi_error _result = tos_channel_set_fav_networkId( networkId );
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
			case TRANSACTION_tos_channel_get_fav_networkId:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint16_t nNetworkId = 0;
				
                fpi_error _result = tos_channel_get_fav_networkId( &nNetworkId );

				reply->writeInt32(nNetworkId);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			} break;

			case TRANSACTION_tos_channel_get_last_service_type:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                EN_TOS_SERVICE_TYPE type = E_TOS_SERVICE_TYPE_ATV;
				
                fpi_error _result = tos_channel_get_last_service_type(&type );


				reply->writeInt32(type);
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;           

			case TRANSACTION_tos_channel_get_muxInfo:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                int32_t muxId = (int32_t)data.readInt32();  //int32_t as input paramter

				int _pout_len = data.readInt32(); //read count

				tos_dtv_mux_info_t* muxInfoRet = NULL;
				Parcel::WritableBlob _pout_wblob;

				if(_pout_len > 0) 
				{
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    muxInfoRet = (tos_dtv_mux_info_t*)_pout_wblob.data();
                }
                fpi_error _result = tos_channel_get_muxInfo( muxId, muxInfoRet );
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_clean_channel_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                fpi_dtv_delivery_type_t deliveryType = (fpi_dtv_delivery_type_t)(data.readInt32());

                fpi_error _result = tos_channel_clean_channel_list( deliveryType );
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_db_update:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();
                fpi_error _result = tos_channel_db_update();
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_channel_get_program_number_by_same_lcn:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                int32_t _pstChannelNumber_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t nChannelNumber = 0;

                fpi_error _result = tos_channel_get_program_number_by_same_lcn( &nChannelNumber );			
                if(_pstChannelNumber_len > 0) {
					reply->writeInt32(nChannelNumber);				
                }
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

			case TRANSACTION_tos_channel_move_program_by_index:
			{
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                int32_t srcChIndex = data.readInt32();
                int32_t dstChIndex = data.readInt32();

                fpi_error _result = tos_channel_move_program_by_index(srcChIndex, dstChIndex);
				reply->writeInt32(_result);
				
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			}
			break;

			case TRANSACTION_tos_channel_list_channel_insert:
			{
				data.enforceInterface(String16(SERVICE_NAME));	//fixed check

				reply->writeNoException();

				int32_t srcChIndex = data.readInt32();
				int32_t dstChIndex = data.readInt32();

				fpi_error _result = tos_channel_list_channel_insert(srcChIndex, dstChIndex);
				reply->writeInt32(_result);

				fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			}
			break;
				
			case TRANSACTION_tos_channel_play_get_current_by_servicetype:
			{
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check

				reply->writeNoException();

				uint32_t serviceType_mask = data.readInt32();  //service type mask
				uint32_t nChannelId = 0;

				fpi_error _result = tos_channel_get_current_channelId_by_servicetype( serviceType_mask, &nChannelId );

				reply->writeInt32(_result);
				reply->writeInt32(nChannelId);
				fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;		
            }

            case TRANSACTION_tos_channel_get_first_index_by_rf_number:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                reply->writeNoException();

                uint8_t u8_rf_number = (uint8_t)data.readInt32(); //read length, only 32bits length support yet
                uint16_t u16_channel_index = 0;
                int32_t i32_channel_index_length = data.readInt32();

                fpi_error _result = tos_channel_get_first_index_by_rf_number(u8_rf_number, &u16_channel_index);			
                if(i32_channel_index_length > 0) {
					reply->writeInt32((int32_t)u16_channel_index);				
                }
				reply->writeInt32(_result);

                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;

            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_dm_channel_service_add() {
    sbinder_dm_channel_service::Instance();
    return 0;
}

sbinder_dm_channel_service* sbinder_dm_channel_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_dm_channel_client  
{  
private:
    static sbinder_dm_channel_client* _instance;
    sp<IBinder> _binder;

    sbinder_dm_channel_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_dm_channel_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
    }

public:  
    static sbinder_dm_channel_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_dm_channel_client();
        }

        return _instance;
    }

    fpi_error tos_channel_get_channelId_by_number( EN_TOS_SERVICE_TYPE serviceType, uint16_t channelNumber, uint32_t* channelId ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(serviceType);  //TOS_SERVICE_TYPE_E as input paramter
            data.writeInt32(channelNumber);  //uint16_t as input paramter

            if (channelId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_channelId_by_number,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
                if (channelId != NULL) {
                    *channelId = reply.readInt32();
                }
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_channelId_by_number error");
        }

        return _result;
    }

    fpi_error tos_channel_get_current_channelId_by_servicetype( uint32_t service_type_mask, uint32_t* channelId ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(service_type_mask);  //TOS_SERVICE_TYPE_E mask information as input paramter
          
            if (channelId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_play_get_current_by_servicetype,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
                if (channelId != NULL) {
                    *channelId = reply.readInt32();
                }
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_channelId_by_number error");
        }

        return _result;
    }
	
    fpi_error tos_channel_get_channel_info_by_id( uint32_t channelId, tos_channel_info_t* channelInfo ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //uint32_t as input paramter

			if (channelInfo == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(tos_channel_info_t));
			}

            _binder->transact(TRANSACTION_tos_channel_get_channel_info_by_id, data, &reply, 0);

            if(reply.readExceptionCode() == 0)
			{
				if (channelInfo != NULL)
				{
					int _pout_len = reply.readInt32();
					Parcel::ReadableBlob _pout_rblob;
					reply.readBlob(_pout_len, &_pout_rblob);
					memcpy(channelInfo, _pout_rblob.data(), _pout_len);
				}
            	_result= reply.readInt32();
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_get_channel_info_by_id error");
        }

        return _result;
    }

    fpi_error tos_channel_get_channellist_by_mask( uint32_t mask, tos_channel_info_t* list, uint32_t* count ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mask);  //uint32_t as input paramter
			
            if (count == NULL) 
			{
                data.writeInt32(-1);
            }
            else 
			{
                data.writeInt32((*count));//write length, only support 32 bits length yet 
            }

            if (list != NULL && count != NULL && *count > 0)
            {
            	data.writeInt32((*count)*(sizeof(tos_channel_info_t)));
        	}
			else
			{
            	data.writeInt32(-1);
			}
			
            _binder->transact(TRANSACTION_tos_channel_get_channellist_by_mask, data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (list != NULL)
				{
					int _pout_len = reply.readInt32();
					Parcel::ReadableBlob _pout_rblob;
					reply.readBlob(_pout_len, &_pout_rblob);
					memcpy(list, _pout_rblob.data(), _pout_len);
				}
                if (count != NULL) {
					*count = reply.readInt32();
                }
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_channel_get_channellist_by_mask error");
        }

        return _result;
    }

    fpi_error tos_channel_get_channel_count_by_mask( uint32_t mask, uint32_t* count ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mask);  //uint32_t as input paramter

            if (count == NULL) 
			{
                data.writeInt32(-1);
            }
            else 
			{
                data.writeInt32(sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_channel_count_by_mask,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (count != NULL)
				{
					*count = reply.readInt32();
				}
            	_result = reply.readInt32();

            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_channel_count_by_mask error");
        }

        return _result;
    }

    fpi_error tos_channel_set_channel_info( tos_channel_info_t* info ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
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
				Parcel::WritableBlob _pin_wblob;                    
				data.writeBlob(sizeof(tos_channel_info_t), &_pin_wblob);
				memcpy(_pin_wblob.data(), info, sizeof(tos_channel_info_t));				
			}
			
            _binder->transact(TRANSACTION_tos_channel_set_channel_info, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_set_channel_info error");
        }

        return _result;
    }

    fpi_error tos_channel_get_channel_list_version( uint32_t* chListVersion ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (chListVersion == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_channel_list_version, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				*chListVersion = reply.readInt32();
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_channel_list_version error");
        }

        return _result;
    }

    fpi_error tos_channel_get_operator_list( tos_channel_operator_info_t* networkList, uint32_t* count ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (networkList == NULL)
        	{
        		data.writeInt32(-1);
        	}
			else
			{
        		data.writeInt32((*count)*(sizeof(tos_channel_operator_info_t)));
			}
            if (count == NULL) 
			{
                data.writeInt32(-1);
            }
            else 
			{
                data.writeInt32(sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_operator_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            	
				if (networkList != NULL)
				{
					int _pout_len = reply.readInt32();
					Parcel::ReadableBlob _pout_rblob;
					reply.readBlob(_pout_len, &_pout_rblob);
					memcpy(networkList, _pout_rblob.data(), _pout_len);
				}
                if (count != NULL) {
					*count = reply.readInt32();
                }
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_operator_list error");
        }

        return _result;
    }

    fpi_error tos_channel_get_operator_count( uint32_t* count ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(uint32_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_operator_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				*count = reply.readInt32();
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_operator_count error");
        }

        return _result;
    }

    fpi_error tos_channel_set_fav_networkId( uint16_t networkId ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(networkId);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_channel_set_fav_networkId, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_set_fav_networkId error");
        }

        return _result;
    }

    fpi_error tos_channel_get_fav_networkId( uint16_t* networkId ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (networkId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(uint16_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_fav_networkId,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				*networkId = reply.readInt32();
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_fav_networkId error");
        }

        return _result;
    }

    fpi_error tos_channel_get_last_service_type(EN_TOS_SERVICE_TYPE *type ) {
        Parcel data, reply;
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            if (type == NULL) {
                data.writeInt32(E_TOS_SERVICE_TYPE_INVALID);
            }
            else {
                data.writeInt32(sizeof(uint16_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_last_service_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				*type =(EN_TOS_SERVICE_TYPE) reply.readInt32();
	
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_last_service_type error");
        }

        return _result;
    }



    fpi_error tos_channel_get_muxInfo( int32_t muxId, tos_dtv_mux_info_t* muxInfo ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(muxId);  //int32_t as input paramter

			if (muxInfo == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32(sizeof(tos_dtv_mux_info_t));
			}

            _binder->transact(TRANSACTION_tos_channel_get_muxInfo,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (muxInfo != NULL)
				{
					int _pout_len = reply.readInt32();
					Parcel::ReadableBlob _pout_rblob;
					reply.readBlob(_pout_len, &_pout_rblob);
					memcpy(muxInfo, _pout_rblob.data(), _pout_len);
				}
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_muxInfo error");
        }

        return _result;
    }

    fpi_error tos_channel_clean_channel_list( fpi_dtv_delivery_type_t deliverytype ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(deliverytype);

            _binder->transact(TRANSACTION_tos_channel_clean_channel_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_clean_channel_list error");
        }

        return _result;
    }

    fpi_error tos_channel_db_update(  ) {
        Parcel data, reply;

        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_channel_db_update,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_db_update error");
        }

        return _result;
    }

    fpi_error tos_channel_get_program_number_by_same_lcn( uint16_t* pstChannelNumber ) {
        Parcel data, reply;
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
            if (pstChannelNumber == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_channel_get_program_number_by_same_lcn,data, &reply,0);
			
            if(reply.readExceptionCode() == 0) {//fix check
				*pstChannelNumber = reply.readInt32();
            	_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_get_program_number_by_same_lcn error");
        }

        return _result;
    }

	fpi_error tos_channel_move_program_by_index(uint32_t srcChIndex, uint32_t dstChIndex) {
		Parcel data, reply;
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
			data.writeInt32(srcChIndex);
			data.writeInt32(dstChIndex);

            _binder->transact(TRANSACTION_tos_channel_move_program_by_index, data, &reply,0);
			
            if(reply.readExceptionCode() == 0) {//fix check
            	_result = reply.readInt32();
            }
        }catch(...) {
            fpi_err(SERVICE_NAME"_client tos_channel_move_program_by_index error");
        }

        return _result;
	}
	
	fpi_error tos_channel_list_channel_insert(uint32_t srcChIndex, uint32_t dstChIndex) {
		Parcel data, reply;
		fpi_error _result = FPI_ERROR_FAIL;
		if(_binder == NULL) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
			data.writeInt32(srcChIndex);
			data.writeInt32(dstChIndex);

			_binder->transact(TRANSACTION_tos_channel_list_channel_insert, data, &reply,0);
			
			if(reply.readExceptionCode() == 0) {//fix check
				_result = reply.readInt32();
			}
		}catch(...) {
			fpi_err(SERVICE_NAME"_client  tos_channel_list_channel_insert  error");
		}
		return _result;
	}	

	fpi_error tos_channel_get_first_index_by_rf_number(uint8_t u8_rf_number, uint16_t* channel_index) {
		Parcel data, reply;
		fpi_error _result = FPI_ERROR_FAIL;
		if(_binder == NULL) {
			return _result;
		}

		try {
			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
			data.writeInt32((int32_t)u8_rf_number);
			if (NULL == channel_index)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32((int32_t)sizeof(uint16_t));
			}

			_binder->transact(TRANSACTION_tos_channel_get_first_index_by_rf_number, data, &reply,0);
			
			if(reply.readExceptionCode() == 0) {//fix check
				if (NULL != channel_index)
				{
					*channel_index = (uint16_t)reply.readInt32();
				}
				_result = reply.readInt32();
			}
		}catch(...) {
			fpi_err(SERVICE_NAME"_client  tos_channel_list_channel_insert  error");
		}
		return _result;
	}	

	
};

sbinder_dm_channel_client* sbinder_dm_channel_client::_instance = NULL;

fpi_error tos_channel_get_channelId_by_number( EN_TOS_SERVICE_TYPE serviceType, uint16_t channelNumber, uint32_t* channelId ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_channelId_by_number(serviceType, channelNumber, channelId);
}
fpi_error tos_channel_get_current_channelId_by_servicetype(uint32_t service_type_mask, uint32_t* channelId ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_current_channelId_by_servicetype(service_type_mask, channelId);
}
fpi_error tos_channel_get_channel_info_by_id( uint32_t channelId, tos_channel_info_t* channelInfo ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_channel_info_by_id(channelId, channelInfo);
}
fpi_error tos_channel_get_channellist_by_mask( uint32_t mask, tos_channel_info_t* list, uint32_t* count ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_channellist_by_mask(mask, list, count);
}
fpi_error tos_channel_get_channel_count_by_mask( uint32_t mask, uint32_t* count ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_channel_count_by_mask(mask, count);
}
fpi_error tos_channel_set_channel_info( tos_channel_info_t* info ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_set_channel_info(info);
}
fpi_error tos_channel_get_channel_list_version( uint32_t* chListVersion ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_channel_list_version(chListVersion);
}
fpi_error tos_channel_get_operator_list( tos_channel_operator_info_t* networkList, uint32_t* count ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_operator_list(networkList, count);
}
fpi_error tos_channel_get_operator_count( uint32_t* count ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_operator_count(count);
}
fpi_error tos_channel_set_fav_networkId( uint16_t networkId ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_set_fav_networkId(networkId);
}
fpi_error tos_channel_get_fav_networkId( uint16_t* networkId ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_fav_networkId(networkId);
}

fpi_error tos_channel_get_last_service_type( EN_TOS_SERVICE_TYPE *type ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_last_service_type(type);
}


fpi_error tos_channel_get_muxInfo( int32_t muxId, tos_dtv_mux_info_t* muxInfo ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_muxInfo(muxId, muxInfo);
}
fpi_error tos_channel_clean_channel_list( fpi_dtv_delivery_type_t deliverytype ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_clean_channel_list(deliverytype);
}
fpi_error tos_channel_db_update(  ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_db_update();
}

fpi_error tos_channel_get_program_number_by_same_lcn( uint16_t* pstChannelNumber ) {
    return sbinder_dm_channel_client::Instance()->tos_channel_get_program_number_by_same_lcn(pstChannelNumber);
}

fpi_error tos_channel_move_program_by_index(uint32_t srcChIndex, uint32_t dstChIndex) {
    return sbinder_dm_channel_client::Instance()->tos_channel_move_program_by_index(srcChIndex, dstChIndex);
}

fpi_error tos_channel_list_channel_insert(uint32_t srcChIndex, uint32_t dstChIndex) {
    return sbinder_dm_channel_client::Instance()->tos_channel_list_channel_insert(srcChIndex, dstChIndex);
}

fpi_error tos_channel_get_first_index_by_rf_number(uint8_t u8_rf_number, uint16_t* channel_index)
{
    return sbinder_dm_channel_client::Instance()->tos_channel_get_first_index_by_rf_number(u8_rf_number, channel_index);
}

static void _test_get_program_number_by_same_lcn(void) {
	uint16_t chnum = 0;
	fpi_error err = tos_channel_get_program_number_by_same_lcn(&chnum);
	tos_tcli_printf("getProgramNumberBySameLcn err=%d chNum=%d\n",err,chnum);
}
TOS_TCLI_COMMAND(mycmd,"short help","long help","",_test_get_program_number_by_same_lcn);


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
