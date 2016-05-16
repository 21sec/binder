/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_atv_scan.sidl
 */
 

#define LOG_TAG     "sbinder_atv_scan"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_atv_scan.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_CHANNEL_SCAN);


#define SERVICE_DESCRIPTOR                      "d437c1c2-1720-11e6-9850-005056a86db3"
#define SERVICE_NAME                            "sbinder_atv_scan"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_atv_start_auto_scan FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_atv_start_manual_scan FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_atv_start_update_scan FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_atv_set_fine_tune_by_frequency FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_atv_fine_tune FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_atv_manual_scan_save FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_atv_get_audio_standard FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_atv_get_video_standard FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_atv_set_audio_standard FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_atv_set_video_standard FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_atv_get_current_scaned_program_info FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_atv_get_aft_enable FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_atv_get_current_frequency FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_atv_scan_get_status FIRST_CALL_TRANSACTION + 14

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_atv_scan.h"

class sbinder_atv_scan_service : public BBinder  
{  
private:
    static sbinder_atv_scan_service* _instance;

    sbinder_atv_scan_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_atv_scan_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_atv_scan_service();
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

            case TRANSACTION_tos_atv_start_auto_scan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_start_auto_scan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_start_auto_scan(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_start_auto_scan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_start_manual_scan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_start_manual_scan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t start_frequency = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t end_frequency = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_start_manual_scan( start_frequency, end_frequency );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_start_manual_scan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_start_update_scan:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_start_update_scan here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_start_update_scan(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_start_update_scan here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_set_fine_tune_by_frequency:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_set_fine_tune_by_frequency here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t toFreqency = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_set_fine_tune_by_frequency( programNum, toFreqency, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_set_fine_tune_by_frequency here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_fine_tune:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_fine_tune here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_FINE_TUNE_MODE ftMode = (EN_FINE_TUNE_MODE)data.readInt32();  //EN_FINE_TUNE_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_fine_tune( programNum, ftMode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_fine_tune here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_manual_scan_save:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_manual_scan_save here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_ATV_SCAN_CTRL action = (EN_ATV_SCAN_CTRL)data.readInt32();  //EN_ATV_SCAN_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_manual_scan_save( action );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_manual_scan_save here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_get_audio_standard:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_audio_standard here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                int _aStdType_len = data.readInt32(); //read length, only 32bits length support yet
                EN_SOUND_SYSTEM_T* aStdType = NULL;

                Parcel::WritableBlob _aStdType_wblob;

                if(_aStdType_len > 0) {
                    reply->writeInt32(_aStdType_len);
                    reply->writeBlob(_aStdType_len,&_aStdType_wblob);
                    aStdType = (EN_SOUND_SYSTEM_T*)_aStdType_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                aStdType = (EN_SOUND_SYSTEM_T*)_aStdType_wblob.data();
                fpi_error _result = tos_atv_get_audio_standard( programNum, aStdType );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_audio_standard here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_get_video_standard:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_video_standard here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                int _cSysType_len = data.readInt32(); //read length, only 32bits length support yet
                EN_COLOR_SYSTEM_T* cSysType = NULL;

                Parcel::WritableBlob _cSysType_wblob;

                if(_cSysType_len > 0) {
                    reply->writeInt32(_cSysType_len);
                    reply->writeBlob(_cSysType_len,&_cSysType_wblob);
                    cSysType = (EN_COLOR_SYSTEM_T*)_cSysType_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                cSysType = (EN_COLOR_SYSTEM_T*)_cSysType_wblob.data();
                fpi_error _result = tos_atv_get_video_standard( programNum, cSysType );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_video_standard here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_set_audio_standard:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_set_audio_standard here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_SOUND_SYSTEM_T aStdType = (EN_SOUND_SYSTEM_T)data.readInt32();  //EN_SOUND_SYSTEM_T as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_set_audio_standard( programNum, aStdType, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_set_audio_standard here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_set_video_standard:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_set_video_standard here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_COLOR_SYSTEM_T vStdType = (EN_COLOR_SYSTEM_T)data.readInt32();  //EN_COLOR_SYSTEM_T as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_atv_set_video_standard( programNum, vStdType, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_set_video_standard here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_get_current_scaned_program_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_current_scaned_program_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _scanning_info_len = data.readInt32(); //read length, only 32bits length support yet
                st_api_scanning_info_t* scanning_info = NULL;

                Parcel::WritableBlob _scanning_info_wblob;

                if(_scanning_info_len > 0) {
                    reply->writeInt32(_scanning_info_len);
                    reply->writeBlob(_scanning_info_len,&_scanning_info_wblob);
                    scanning_info = (st_api_scanning_info_t*)_scanning_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                scanning_info = (st_api_scanning_info_t*)_scanning_info_wblob.data();
				fpi_warn(SERVICE_NAME"TRANSACTION_tos_atv_get_current_scaned_program_info()000000000000000000000");
                fpi_error _result = tos_atv_get_current_scaned_program_info( scanning_info );

				fpi_warn(SERVICE_NAME"TRANSACTION_tos_atv_get_current_scaned_program_info()11111111111111111111,_result=%d",_result);
                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_current_scaned_program_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_get_aft_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_aft_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t programNum = (int32_t)data.readInt32();  //int32_t as input paramter

                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* enable = NULL;

                Parcel::WritableBlob _enable_wblob;

                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (fpi_bool*)_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enable = (fpi_bool*)_enable_wblob.data();
                fpi_error _result = tos_atv_get_aft_enable( programNum, enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_aft_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_get_current_frequency:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_get_current_frequency here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _freq_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* freq = NULL;

                Parcel::WritableBlob _freq_wblob;

                if(_freq_len > 0) {
                    reply->writeInt32(_freq_len);
                    reply->writeBlob(_freq_len,&_freq_wblob);
                    freq = (int32_t*)_freq_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                freq = (int32_t*)_freq_wblob.data();
                fpi_error _result = tos_atv_get_current_frequency( freq );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_get_current_frequency here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_atv_scan_get_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_atv_scan_get_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _status_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_DTV_SCAN_STATUS* status = NULL;

                Parcel::WritableBlob _status_wblob;

                if(_status_len > 0) {
                    reply->writeInt32(_status_len);
                    reply->writeBlob(_status_len,&_status_wblob);
                    status = (EN_TOS_DTV_SCAN_STATUS*)_status_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                status = (EN_TOS_DTV_SCAN_STATUS*)_status_wblob.data();
                fpi_error _result = tos_atv_scan_get_status( status );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_atv_scan_get_status here --
                return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_atv_scan_service_add() {
    sbinder_atv_scan_service::Instance();
    return 0;
}

sbinder_atv_scan_service* sbinder_atv_scan_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_atv_scan_client  
{  
private:
    static sbinder_atv_scan_client* _instance;
    sp<IBinder> _binder;

    sbinder_atv_scan_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_atv_scan_client() {
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
    static sbinder_atv_scan_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_atv_scan_client();
        }

        return _instance;
    }

    fpi_error tos_atv_start_auto_scan(  ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_start_auto_scan here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_atv_start_auto_scan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_start_auto_scan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_start_auto_scan error");
        }

        return _result;
        /*-- add you code for tos_atv_start_auto_scan here --*/
    }

    fpi_error tos_atv_start_manual_scan( int32_t start_frequency, int32_t end_frequency ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_start_manual_scan here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(start_frequency);  //int32_t as input paramter

            data.writeInt32(end_frequency);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_atv_start_manual_scan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_start_manual_scan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_start_manual_scan error");
        }

        return _result;
        /*-- add you code for tos_atv_start_manual_scan here --*/
    }

    fpi_error tos_atv_start_update_scan(  ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_start_update_scan here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_atv_start_update_scan,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_start_update_scan error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_start_update_scan error");
        }

        return _result;
        /*-- add you code for tos_atv_start_update_scan here --*/
    }

    fpi_error tos_atv_set_fine_tune_by_frequency( int32_t programNum, int32_t toFreqency, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_set_fine_tune_by_frequency here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            data.writeInt32(toFreqency);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_atv_set_fine_tune_by_frequency,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_set_fine_tune_by_frequency error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_set_fine_tune_by_frequency error");
        }

        return _result;
        /*-- add you code for tos_atv_set_fine_tune_by_frequency here --*/
    }

    fpi_error tos_atv_fine_tune( int32_t programNum, EN_FINE_TUNE_MODE ftMode ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_fine_tune here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            data.writeInt32(ftMode);  //EN_FINE_TUNE_MODE as input paramter

            _binder->transact(TRANSACTION_tos_atv_fine_tune,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_fine_tune error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_fine_tune error");
        }

        return _result;
        /*-- add you code for tos_atv_fine_tune here --*/
    }

    fpi_error tos_atv_manual_scan_save( EN_ATV_SCAN_CTRL action ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_manual_scan_save here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(action);  //EN_ATV_SCAN_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_atv_manual_scan_save,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_manual_scan_save error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_manual_scan_save error");
        }

        return _result;
        /*-- add you code for tos_atv_manual_scan_save here --*/
    }

    fpi_error tos_atv_get_audio_standard( int32_t programNum, EN_SOUND_SYSTEM_T* aStdType ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_audio_standard here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (aStdType == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_SOUND_SYSTEM_T));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_atv_get_audio_standard,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (aStdType != NULL) {
                    int _aStdType_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _aStdType_rblob;
                    reply.readBlob(_aStdType_len,&_aStdType_rblob);
                    memcpy(aStdType,_aStdType_rblob.data(),_aStdType_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_get_audio_standard error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_get_audio_standard error");
        }

        return _result;
        /*-- add you code for tos_atv_get_audio_standard here --*/
    }

    fpi_error tos_atv_get_video_standard( int32_t programNum, EN_COLOR_SYSTEM_T* cSysType ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_video_standard here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (cSysType == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_COLOR_SYSTEM_T));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_atv_get_video_standard,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (cSysType != NULL) {
                    int _cSysType_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _cSysType_rblob;
                    reply.readBlob(_cSysType_len,&_cSysType_rblob);
                    memcpy(cSysType,_cSysType_rblob.data(),_cSysType_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_get_video_standard error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_get_video_standard error");
        }

        return _result;
        /*-- add you code for tos_atv_get_video_standard here --*/
    }

    fpi_error tos_atv_set_audio_standard( int32_t programNum, EN_SOUND_SYSTEM_T aStdType, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_set_audio_standard here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            data.writeInt32(aStdType);  //EN_SOUND_SYSTEM_T as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_atv_set_audio_standard,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_set_audio_standard error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_set_audio_standard error");
        }

        return _result;
        /*-- add you code for tos_atv_set_audio_standard here --*/
    }

    fpi_error tos_atv_set_video_standard( int32_t programNum, EN_COLOR_SYSTEM_T vStdType, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_set_video_standard here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            data.writeInt32(vStdType);  //EN_COLOR_SYSTEM_T as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_atv_set_video_standard,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_set_video_standard error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_set_video_standard error");
        }

        return _result;
        /*-- add you code for tos_atv_set_video_standard here --*/
    }

    fpi_error tos_atv_get_current_scaned_program_info( st_api_scanning_info_t* scanning_info ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_current_scaned_program_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
		fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()000000000000000000000");
        if(!getService()) {
			fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()11111111111111111111");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
			fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()2222222222222222222222");
            if (scanning_info == NULL) {
                data.writeInt32(-1);
            }
            else {
				fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()33333333333333333");
                data.writeInt32((int)(1) * sizeof(st_api_scanning_info_t));//write length, only support 32 bits length yet
                
            }

            int temp = _binder->transact(TRANSACTION_tos_atv_get_current_scaned_program_info,data, &reply,0);

			fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()444444444444444444444,temp=%d",temp);
            if(reply.readExceptionCode() == 0) {//fix check

				fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()5555555555555555555");
                if (scanning_info != NULL) {
                    int _scanning_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _scanning_info_rblob;
                    reply.readBlob(_scanning_info_len,&_scanning_info_rblob);
                    memcpy(scanning_info,_scanning_info_rblob.data(),_scanning_info_len);
					fpi_warn(SERVICE_NAME"tos_atv_get_current_scaned_program_info()666666666666666666");
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_get_current_scaned_program_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_get_current_scaned_program_info error");
        }

        return _result;
        /*-- add you code for tos_atv_get_current_scaned_program_info here --*/
    }

    fpi_error tos_atv_get_aft_enable( int32_t programNum, fpi_bool* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_aft_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(programNum);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_atv_get_aft_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_get_aft_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_get_aft_enable error");
        }

        return _result;
        /*-- add you code for tos_atv_get_aft_enable here --*/
    }

    fpi_error tos_atv_get_current_frequency( int32_t* freq ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_get_current_frequency here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (freq == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_atv_get_current_frequency,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (freq != NULL) {
                    int _freq_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _freq_rblob;
                    reply.readBlob(_freq_len,&_freq_rblob);
                    memcpy(freq,_freq_rblob.data(),_freq_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_get_current_frequency error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_get_current_frequency error");
        }

        return _result;
        /*-- add you code for tos_atv_get_current_frequency here --*/
    }

    fpi_error tos_atv_scan_get_status( EN_TOS_DTV_SCAN_STATUS* status ) {
        Parcel data, reply;

        /*-- add you code for tos_atv_scan_get_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (status == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_DTV_SCAN_STATUS));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_atv_scan_get_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (status != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(status,_status_rblob.data(),_status_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_atv_scan_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_atv_scan_get_status error");
        }

        return _result;
        /*-- add you code for tos_atv_scan_get_status here --*/
    }
};

sbinder_atv_scan_client* sbinder_atv_scan_client::_instance = NULL;

fpi_error tos_atv_start_auto_scan(  ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_start_auto_scan();
}
fpi_error tos_atv_start_manual_scan( int32_t start_frequency, int32_t end_frequency ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_start_manual_scan(start_frequency, end_frequency);
}
fpi_error tos_atv_start_update_scan(  ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_start_update_scan();
}
fpi_error tos_atv_set_fine_tune_by_frequency( int32_t programNum, int32_t toFreqency, EN_ACT_CTRL act ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_set_fine_tune_by_frequency(programNum, toFreqency, act);
}
fpi_error tos_atv_fine_tune( int32_t programNum, EN_FINE_TUNE_MODE ftMode ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_fine_tune(programNum, ftMode);
}
fpi_error tos_atv_manual_scan_save( EN_ATV_SCAN_CTRL action ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_manual_scan_save(action);
}
fpi_error tos_atv_get_audio_standard( int32_t programNum, EN_SOUND_SYSTEM_T* aStdType ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_get_audio_standard(programNum, aStdType);
}
fpi_error tos_atv_get_video_standard( int32_t programNum, EN_COLOR_SYSTEM_T* cSysType ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_get_video_standard(programNum, cSysType);
}
fpi_error tos_atv_set_audio_standard( int32_t programNum, EN_SOUND_SYSTEM_T aStdType, EN_ACT_CTRL act ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_set_audio_standard(programNum, aStdType, act);
}
fpi_error tos_atv_set_video_standard( int32_t programNum, EN_COLOR_SYSTEM_T vStdType, EN_ACT_CTRL act ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_set_video_standard(programNum, vStdType, act);
}
fpi_error tos_atv_get_current_scaned_program_info( st_api_scanning_info_t* scanning_info ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_get_current_scaned_program_info(scanning_info);
}
fpi_error tos_atv_get_aft_enable( int32_t programNum, fpi_bool* enable ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_get_aft_enable(programNum, enable);
}
fpi_error tos_atv_get_current_frequency( int32_t* freq ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_get_current_frequency(freq);
}
fpi_error tos_atv_scan_get_status( EN_TOS_DTV_SCAN_STATUS* status ) {
    return sbinder_atv_scan_client::Instance()->tos_atv_scan_get_status(status);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
