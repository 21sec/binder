/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_satellite.sidl
 */
 

#define LOG_TAG     "sbinder_satellite"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_satellite.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PLAY);


#define SERVICE_DESCRIPTOR                      "3a4b7776-d364-11e4-a6ad-005056a86db3"
#define SERVICE_NAME                            "sbinder_satellite"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_satellite_get_operator_count FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_satellite_get_operator_list FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_satellite_get_satellite_count_by_operator FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_satellite_get_satellite_list_by_operator FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_satellite_set_satellite_info FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_satellite_lock_freqency FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_satellite_get_antenna_info FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_satellite_set_antenna_info FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_satellite_get_band_freq_count FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_satellite_get_band_freq_list FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_satellite_set_band_freq FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_satellite_get_searched_satellite_count FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_satellite_get_satellite_id_info_list FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_satellite_set_user_select_satellite_id FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_satellite_get_user_select_satellite_id FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_satellite_get_satellite_info FIRST_CALL_TRANSACTION + 16

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_satellite.h"


class sbinder_satellite_service : public BBinder  
{  
private:
    static sbinder_satellite_service* _instance;

    sbinder_satellite_service(){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_satellite_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_satellite_service();
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

            case TRANSACTION_tos_satellite_get_operator_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_operator_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _operatorCount_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* operatorCount = NULL;
				Parcel::WritableBlob _operatorCount_wblob;
				
                if(_operatorCount_len > 0) {
                    reply->writeInt32(_operatorCount_len);
                    reply->writeBlob(_operatorCount_len,&_operatorCount_wblob);
                    operatorCount = (int32_t*)_operatorCount_wblob.data();
                }

                fpi_error _result = tos_satellite_get_operator_count( operatorCount );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_operator_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_operator_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_operator_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t operatorCount = (int32_t)data.readInt32();  //int32_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_operator_info_t* operatorListBuff = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    operatorListBuff = (tos_operator_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_satellite_get_operator_list( operatorCount, operatorListBuff );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_operator_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_satellite_count_by_operator:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_satellite_count_by_operator here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t operatorIndex = (int32_t)data.readInt32();  //int32_t as input paramter

                int _satellCount_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* satellCount = NULL;
				Parcel::WritableBlob _satellCount_wblob;
				
                if(_satellCount_len > 0) {
                    reply->writeInt32(_satellCount_len);
                    reply->writeBlob(_satellCount_len,&_satellCount_wblob);
                    satellCount = (int32_t*)_satellCount_wblob.data();
                }

                fpi_error _result = tos_satellite_get_satellite_count_by_operator( operatorIndex, satellCount );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_satellite_count_by_operator here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_satellite_list_by_operator:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_satellite_list_by_operator here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t operatorIndex = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t satellCount = (int32_t)data.readInt32();  //int32_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_satellite_info_t* satelliteList = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    satelliteList = (tos_satellite_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_satellite_get_satellite_list_by_operator( operatorIndex, satellCount, satelliteList );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_satellite_list_by_operator here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_set_satellite_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_set_satellite_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t satelliteID = (int32_t)data.readInt32();  //int32_t as input paramter
				tos_satellite_info_t *satelliteInfo = NULL;

                int _pin_len = data.readInt32(); //read length, only 32bits length support yet

				if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					satelliteInfo = (tos_satellite_info_t *)_pin_rblob.data();
                }

                fpi_error _result = tos_satellite_set_satellite_info( satelliteID, satelliteInfo);

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_set_satellite_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_lock_freqency:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_lock_freqency here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t satelliteID = (int32_t)data.readInt32();  //int32_t as input paramter

                fpi_error _result = tos_satellite_lock_freqency( satelliteID );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_lock_freqency here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_antenna_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_antenna_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_satellite_antenna_info_t* info = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    info = (fpi_satellite_antenna_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_satellite_get_antenna_info( info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_antenna_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_set_antenna_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_set_antenna_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_satellite_antenna_info_t info ;
                if(_pin_len > 0) {
                    Parcel::ReadableBlob _pin_rblob;
                    data.readBlob(_pin_len,&_pin_rblob);
					if( _pin_len == sizeof(fpi_satellite_antenna_info_t) )
					{
						memcpy(&info,_pin_rblob.data(), _pin_len );
					}
					else
					{
					    //to be done
                    }
                }

                fpi_error _result = tos_satellite_set_antenna_info( &info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_set_antenna_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_band_freq_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_band_freq_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				uint32_t band_index  = data.readInt32();
                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* count = NULL;
				Parcel::WritableBlob _count_wblob;
				
                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (uint32_t*)_count_wblob.data();
                }

                fpi_error _result = tos_satellite_get_band_freq_count(band_index, count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_band_freq_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_band_freq_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_band_freq_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				uint32_t band_index = (uint32_t)data.readInt32(); 
                uint32_t count = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _frequencyList_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* frequencyList = NULL;
				Parcel::WritableBlob _frequencyList_wblob;
				
                if(_frequencyList_len > 0) {
                    reply->writeInt32(_frequencyList_len);
                    reply->writeBlob(_frequencyList_len,&_frequencyList_wblob);
                    frequencyList = (uint32_t*)_frequencyList_wblob.data();
                }

                fpi_error _result = tos_satellite_get_band_freq_list( band_index,count, frequencyList );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_band_freq_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_set_band_freq:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_set_band_freq here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
				uint32_t band_index = (uint32_t)data.readInt32();
                uint32_t index = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t frequency = (uint32_t)data.readInt32();  //uint32_t as input paramter

                fpi_error _result = tos_satellite_set_band_freq(band_index, index, frequency );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_set_band_freq here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_searched_satellite_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_searched_satellite_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* count = NULL;
				Parcel::WritableBlob _count_wblob;
				
                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (int32_t*)_count_wblob.data();
                }

                fpi_error _result = tos_satellite_get_searched_satellite_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_searched_satellite_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_satellite_id_info_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_satellite_id_info_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t satelliteCount = (int32_t)data.readInt32();  //uint32_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_satellite_id_info_t* satelliteIdInfolist = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    satelliteIdInfolist = (tos_satellite_id_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_satellite_get_satellite_id_info_list( satelliteCount, satelliteIdInfolist );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_satellite_id_info_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_set_user_select_satellite_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_set_user_select_satellite_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t satelliteId = (uint32_t)data.readInt32();  //uint32_t as input paramter

                fpi_error _result = tos_satellite_set_user_select_satellite_id( satelliteId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_set_user_select_satellite_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_satellite_get_user_select_satellite_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_user_select_satellite_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _satelliteId_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* satelliteId = NULL;
				Parcel::WritableBlob _satelliteId_wblob;
				
                if(_satelliteId_len > 0) {
                    reply->writeInt32(_satelliteId_len);
                    reply->writeBlob(_satelliteId_len,&_satelliteId_wblob);
                    satelliteId = (uint32_t*)_satelliteId_wblob.data();
                }

                fpi_error _result = tos_satellite_get_user_select_satellite_id( satelliteId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_user_select_satellite_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_satellite_get_satellite_info:
			{
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_satellite_get_satellite_id_info_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t satelliteID = (int32_t)data.readInt32();  //uint32_t as input paramter

                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                tos_satellite_info_t* satelliteInfo = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    satelliteInfo = (tos_satellite_info_t*)_pout_wblob.data();
                }

                fpi_error _result = tos_satellite_get_satellite_info( satelliteID, satelliteInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_satellite_get_satellite_id_info_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        	}break;
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_satellite_service_add() {
    sbinder_satellite_service::Instance();
    return 0;
}

sbinder_satellite_service* sbinder_satellite_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_satellite_client  
{  
private:
    static sbinder_satellite_client* _instance;
    sp<IBinder> _binder;

    sbinder_satellite_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_satellite_client() {
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
    static sbinder_satellite_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_satellite_client();
        }

        return _instance;
    }

    fpi_error tos_satellite_get_operator_count( int32_t* operatorCount ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_operator_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (operatorCount == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_operator_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (operatorCount != NULL) {
                    int _operatorCount_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _operatorCount_rblob;
                    reply.readBlob(_operatorCount_len,&_operatorCount_rblob);
                    memcpy(operatorCount,_operatorCount_rblob.data(),_operatorCount_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_operator_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_operator_count error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_operator_count here --*/
    }

    fpi_error tos_satellite_get_operator_list( int32_t operatorCount, tos_operator_info_t* operatorListBuff ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_operator_list here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(operatorCount);  //int32_t as input paramter

            data.writeInt32((int)(operatorCount) * sizeof(tos_operator_info_t));

            _binder->transact(TRANSACTION_tos_satellite_get_operator_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (operatorListBuff != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(operatorListBuff,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_operator_list error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_operator_list error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_operator_list here --*/
    }

    fpi_error tos_satellite_get_satellite_count_by_operator( int32_t operatorIndex, int32_t* satellCount ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_satellite_count_by_operator here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(operatorIndex);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (satellCount == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_satellite_count_by_operator,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (satellCount != NULL) {
                    int _satellCount_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _satellCount_rblob;
                    reply.readBlob(_satellCount_len,&_satellCount_rblob);
                    memcpy(satellCount,_satellCount_rblob.data(),_satellCount_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_count_by_operator error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_count_by_operator error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_satellite_count_by_operator here --*/
    }

    fpi_error tos_satellite_get_satellite_list_by_operator( int32_t operatorIndex, int32_t satellCount, tos_satellite_info_t* satelliteList ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_satellite_list_by_operator here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(operatorIndex);  //int32_t as input paramter

            data.writeInt32(satellCount);  //int32_t as input paramter

            data.writeInt32((int)(satellCount) * sizeof(tos_satellite_info_t));

            _binder->transact(TRANSACTION_tos_satellite_get_satellite_list_by_operator,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (satelliteList != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(satelliteList,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_list_by_operator error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_list_by_operator error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_satellite_list_by_operator here --*/
    }

    fpi_error tos_satellite_set_satellite_info( int32_t satelliteID, tos_satellite_info_t* satelliteInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_set_satellite_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(satelliteID);  //int32_t as input paramter

			if (NULL == satelliteInfo)
			{
                data.writeInt32(-1);
			}
			else
			{
                data.writeInt32((int)(1) * sizeof(tos_satellite_info_t));

	            Parcel::WritableBlob _pin_wblob;
	            data.writeBlob((1) * sizeof(tos_satellite_info_t),&_pin_wblob);
	            memcpy(_pin_wblob.data(),satelliteInfo,(1)* sizeof(tos_satellite_info_t));
			}

            _binder->transact(TRANSACTION_tos_satellite_set_satellite_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
 				_result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_set_satellite_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_set_satellite_info error");
        }

        return _result;
        /*-- add you code for tos_satellite_set_satellite_info here --*/
    }

    fpi_error tos_satellite_lock_freqency( int32_t satelliteID ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_lock_freqency here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(satelliteID);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_satellite_lock_freqency,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_lock_freqency error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_lock_freqency error");
        }

        return _result;
        /*-- add you code for tos_satellite_lock_freqency here --*/
    }

    fpi_error tos_satellite_get_antenna_info( fpi_satellite_antenna_info_t* info ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_antenna_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(fpi_satellite_antenna_info_t));

            _binder->transact(TRANSACTION_tos_satellite_get_antenna_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (info != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(info,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_antenna_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_antenna_info error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_antenna_info here --*/
    }

    fpi_error tos_satellite_set_antenna_info( fpi_satellite_antenna_info_t *info ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_set_antenna_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((int)(1) * sizeof(fpi_satellite_antenna_info_t));//write length, only support 32 bits length yet
                
            Parcel::WritableBlob _pin_wblob;
            data.writeBlob((1) * sizeof(fpi_satellite_antenna_info_t),&_pin_wblob);
            memcpy(_pin_wblob.data(),info,(1)* sizeof(fpi_satellite_antenna_info_t));

            _binder->transact(TRANSACTION_tos_satellite_set_antenna_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_set_antenna_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_set_antenna_info error");
        }

        return _result;
        /*-- add you code for tos_satellite_set_antenna_info here --*/
    }

    fpi_error tos_satellite_get_band_freq_count(uint32_t band_index, uint32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_band_freq_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_band_freq_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_band_freq_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_band_freq_count error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_band_freq_count here --*/
    }

    fpi_error tos_satellite_get_band_freq_list( uint32_t band_index, uint32_t count, uint32_t* frequencyList ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_band_freq_list here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(count);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (frequencyList == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(count) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_band_freq_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (frequencyList != NULL) {
                    int _frequencyList_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _frequencyList_rblob;
                    reply.readBlob(_frequencyList_len,&_frequencyList_rblob);
                    memcpy(frequencyList,_frequencyList_rblob.data(),_frequencyList_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_band_freq_list error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_band_freq_list error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_band_freq_list here --*/
    }

    fpi_error tos_satellite_set_band_freq(uint32_t band_index, uint32_t index, uint32_t frequency ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_set_band_freq here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(band_index);  //uint32_t as input paramter

            data.writeInt32(index);  //uint32_t as input paramter

            data.writeInt32(frequency);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_satellite_set_band_freq,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_set_band_freq error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_set_band_freq error");
        }

        return _result;
        /*-- add you code for tos_satellite_set_band_freq here --*/
    }

    fpi_error tos_satellite_get_searched_satellite_count( int32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_searched_satellite_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_searched_satellite_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_searched_satellite_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_searched_satellite_count error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_searched_satellite_count here --*/
    }

    fpi_error tos_satellite_get_satellite_id_info_list( int32_t satelliteCount, tos_satellite_id_info_t* satelliteIdInfolist ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_satellite_id_info_list here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(satelliteCount);  //int32_t as input paramter

            data.writeInt32((int)(satelliteCount) * sizeof(tos_satellite_id_info_t));

            _binder->transact(TRANSACTION_tos_satellite_get_satellite_id_info_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (satelliteIdInfolist != NULL) {
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(satelliteIdInfolist,_pout_rblob.data(),_pout_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_id_info_list error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_id_info_list error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_satellite_id_info_list here --*/
    }

    fpi_error tos_satellite_set_user_select_satellite_id( uint32_t satelliteId ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_set_user_select_satellite_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(satelliteId);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_satellite_set_user_select_satellite_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_set_user_select_satellite_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_set_user_select_satellite_id error");
        }

        return _result;
        /*-- add you code for tos_satellite_set_user_select_satellite_id here --*/
    }

    fpi_error tos_satellite_get_user_select_satellite_id( uint32_t* satelliteId ) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_user_select_satellite_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (satelliteId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_satellite_get_user_select_satellite_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (satelliteId != NULL) {
                    int _satelliteId_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _satelliteId_rblob;
                    reply.readBlob(_satelliteId_len,&_satelliteId_rblob);
                    memcpy(satelliteId,_satelliteId_rblob.data(),_satelliteId_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_user_select_satellite_id error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_user_select_satellite_id error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_user_select_satellite_id here --*/
    }

    fpi_error tos_satellite_get_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo) {
        Parcel data, reply;

        /*-- add you code for tos_satellite_get_user_select_satellite_id here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			data.writeInt32(satelliteID);
            //for out only, only write length ; for in, alloc and copy
            if (satelliteInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_satellite_info_t));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_tos_satellite_get_satellite_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (satelliteInfo != NULL) {
                    int _satelliteId_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _satelliteId_rblob;
                    reply.readBlob(_satelliteId_len,&_satelliteId_rblob);
                    memcpy(satelliteInfo,_satelliteId_rblob.data(),_satelliteId_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_satellite_get_satellite_info error");
        }

        return _result;
        /*-- add you code for tos_satellite_get_user_select_satellite_id here --*/
    }
};

sbinder_satellite_client* sbinder_satellite_client::_instance = NULL;

fpi_error tos_satellite_get_operator_count( int32_t* operatorCount ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_operator_count(operatorCount);
}
fpi_error tos_satellite_get_operator_list( int32_t operatorCount, tos_operator_info_t* operatorListBuff ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_operator_list(operatorCount, operatorListBuff);
}
fpi_error tos_satellite_get_satellite_count_by_operator( int32_t operatorIndex, int32_t* satellCount ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_satellite_count_by_operator(operatorIndex, satellCount);
}
fpi_error tos_satellite_get_satellite_list_by_operator( int32_t operatorIndex, int32_t satellCount, tos_satellite_info_t* satelliteList ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_satellite_list_by_operator(operatorIndex, satellCount, satelliteList);
}
fpi_error tos_satellite_set_satellite_info( int32_t satelliteID, tos_satellite_info_t* satelliteInfo ) {
    return sbinder_satellite_client::Instance()->tos_satellite_set_satellite_info(satelliteID, satelliteInfo);
}
fpi_error tos_satellite_lock_freqency( int32_t satelliteID ) {
    return sbinder_satellite_client::Instance()->tos_satellite_lock_freqency(satelliteID);
}
fpi_error tos_satellite_get_antenna_info( fpi_satellite_antenna_info_t* info ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_antenna_info(info);
}
fpi_error tos_satellite_set_antenna_info( fpi_satellite_antenna_info_t *info ) {
    return sbinder_satellite_client::Instance()->tos_satellite_set_antenna_info(info);
}
fpi_error tos_satellite_get_band_freq_count(uint32_t band_index, uint32_t* count ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_band_freq_count(band_index,count);
}
fpi_error tos_satellite_get_band_freq_list(uint32_t band_index, uint32_t count, uint32_t* frequencyList ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_band_freq_list(band_index,count, frequencyList);
}
fpi_error tos_satellite_set_band_freq(uint32_t band_index, uint32_t index, uint32_t frequency ) {
    return sbinder_satellite_client::Instance()->tos_satellite_set_band_freq(band_index,index, frequency);
}
fpi_error tos_satellite_get_searched_satellite_count( int32_t* count ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_searched_satellite_count(count);
}
fpi_error tos_satellite_get_satellite_id_info_list( int32_t satelliteCount, tos_satellite_id_info_t* satelliteIdInfolist ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_satellite_id_info_list(satelliteCount, satelliteIdInfolist);
}
fpi_error tos_satellite_set_user_select_satellite_id( uint32_t satelliteId ) {
    return sbinder_satellite_client::Instance()->tos_satellite_set_user_select_satellite_id(satelliteId);
}
fpi_error tos_satellite_get_user_select_satellite_id( uint32_t* satelliteId ) {
    return sbinder_satellite_client::Instance()->tos_satellite_get_user_select_satellite_id(satelliteId);
}

fpi_error tos_satellite_get_satellite_info(int32_t satelliteID, tos_satellite_info_t *satelliteInfo){
    return sbinder_satellite_client::Instance()->tos_satellite_get_satellite_info(satelliteID,satelliteInfo);
}
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
