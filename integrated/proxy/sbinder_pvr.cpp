/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_pvr.sidl
 */
 

#define LOG_TAG     "sbinder_pvr"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_pvr.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PVR);


#define SERVICE_DESCRIPTOR                      "a24dc9c2-f458-11e4-8731-005056a84a3b"
#define SERVICE_NAME                            "sbinder_pvr"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_pvr_is_record_file_exist FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_pvr_scan_directory FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_pvr_scan_resource_release FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_pvr_get_recording_list_count FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_pvr_get_recording_list FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_pvr_set_file_sort_order FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_pvr_get_file_sort_order FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_pvr_get_recording_info FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_pvr_delete_recording FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_pvr_record_start FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_pvr_record_pause FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_pvr_record_resume FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_pvr_record_stop FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_pvr_get_recording_state FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_pvr_get_current_recording_url FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_pvr_record_file_start_play FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_pvr_record_file_stop_play FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_pvr_play_set_motion FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_pvr_play_get_current_motion FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_pvr_play_seek FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_pvr_play_get_current_play_time FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_pvr_play_get_file_url FIRST_CALL_TRANSACTION + 22
#define TRANSACTION_tos_pvr_play_get_audio_track_info FIRST_CALL_TRANSACTION + 23
#define TRANSACTION_tos_pvr_play_get_audio_track_count FIRST_CALL_TRANSACTION + 24
#define TRANSACTION_tos_pvr_play_get_current_audio_track FIRST_CALL_TRANSACTION + 25
#define TRANSACTION_tos_pvr_play_set_audio_track FIRST_CALL_TRANSACTION + 26
#define TRANSACTION_tos_pvr_play_enable_subtitle FIRST_CALL_TRANSACTION + 27
#define TRANSACTION_tos_pvr_play_get_subtitle_info FIRST_CALL_TRANSACTION + 28
#define TRANSACTION_tos_pvr_play_get_subtitle_count FIRST_CALL_TRANSACTION + 29
#define TRANSACTION_tos_pvr_play_get_current_subtitle FIRST_CALL_TRANSACTION + 30
#define TRANSACTION_tos_pvr_play_set_subtitle FIRST_CALL_TRANSACTION + 31
#define TRANSACTION_tos_pvr_timeshift_start FIRST_CALL_TRANSACTION + 32
#define TRANSACTION_tos_pvr_timeshift_stop FIRST_CALL_TRANSACTION + 33
#define TRANSACTION_tos_pvr_timeshift_get_start_time FIRST_CALL_TRANSACTION + 34
#define TRANSACTION_tos_pvr_timeshift_is_file_exist FIRST_CALL_TRANSACTION + 35
#define TRANSACTION_tos_pvr_timeshift_init_file FIRST_CALL_TRANSACTION + 36
#define TRANSACTION_tos_pvr_get_timeshift_file_init_progress FIRST_CALL_TRANSACTION + 37
#define TRANSACTION_tos_pvr_timeshift_write_speed_test FIRST_CALL_TRANSACTION + 38
#define TRANSACTION_tos_pvr_get_timeshift_speed FIRST_CALL_TRANSACTION + 39
#define TRANSACTION_tos_pvr_get_free_space_status FIRST_CALL_TRANSACTION + 40
#define TRANSACTION_tos_pvr_get_disk_free_space FIRST_CALL_TRANSACTION + 41
#define TRANSACTION_tos_pvr_get_disk_info FIRST_CALL_TRANSACTION + 42
#define TRANSACTION_tos_pvr_select_disk FIRST_CALL_TRANSACTION + 43
#define TRANSACTION_tos_pvr_disk_format FIRST_CALL_TRANSACTION + 44
#define TRANSACTION_tos_pvr_get_formating_progress FIRST_CALL_TRANSACTION + 45
#define TRANSACTION_tos_pvr_record_file_play_by_mode FIRST_CALL_TRANSACTION + 46
#define TRANSACTION_tos_pvr_play_get_repeat_mode FIRST_CALL_TRANSACTION + 47
#define TRANSACTION_tos_pvr_play_set_repeat_mode FIRST_CALL_TRANSACTION + 48
#define TRANSACTION_tos_pvr_play_get_file_position FIRST_CALL_TRANSACTION + 49
#define TRANSACTION_tos_pvr_record_ts_start FIRST_CALL_TRANSACTION + 50
#define TRANSACTION_tos_pvr_record_ts_stop FIRST_CALL_TRANSACTION + 51
#define TRANSACTION_tos_pvr_timeshift_start_v2 FIRST_CALL_TRANSACTION + 52

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_pvr.h"

class sbinder_pvr_service : public BBinder  
{  
private:
    static sbinder_pvr_service* _instance;

    sbinder_pvr_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_pvr_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_pvr_service();
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

            case TRANSACTION_tos_pvr_is_record_file_exist:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_is_record_file_exist here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (char*)_path_rblob.data();
                }

                int _isExist_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* isExist = NULL;

                Parcel::WritableBlob _isExist_wblob;

                if(_isExist_len > 0) {
                    reply->writeInt32(_isExist_len);
                    reply->writeBlob(_isExist_len,&_isExist_wblob);
                    isExist = (fpi_bool*)_isExist_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                path = (char*)_path_rblob.data();
                isExist = (fpi_bool*)_isExist_wblob.data();
                fpi_error _result = tos_pvr_is_record_file_exist( path, isExist );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_is_record_file_exist here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_scan_directory:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_scan_directory here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _usbDiskPath_len = data.readInt32(); //read length, only 32bits length support yet
                char* usbDiskPath = NULL;

                Parcel::ReadableBlob _usbDiskPath_rblob;

                if(_usbDiskPath_len > 0) {
                    data.readBlob(_usbDiskPath_len,&_usbDiskPath_rblob);
                    usbDiskPath = (char*)_usbDiskPath_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                usbDiskPath = (char*)_usbDiskPath_rblob.data();
                fpi_error _result = tos_pvr_scan_directory( usbDiskPath );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_scan_directory here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_scan_resource_release:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_scan_resource_release here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_scan_resource_release(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_scan_resource_release here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_recording_list_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_recording_list_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int32_t*)_value_wblob.data();
                fpi_error _result = tos_pvr_get_recording_list_count( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_recording_list_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_recording_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_recording_list here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t startIndex = (int32_t)data.readInt32();  //int32_t as input paramter

                int _list_len = data.readInt32(); //read length, only 32bits length support yet
                tos_pvr_recording_file_info_t* list = NULL;

                Parcel::WritableBlob _list_wblob;

                if(_list_len > 0) {
                    reply->writeInt32(_list_len);
                    reply->writeBlob(_list_len,&_list_wblob);
                    list = (tos_pvr_recording_file_info_t*)_list_wblob.data();
                }

                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* count = NULL;

                Parcel::ReadableBlob _count_rblob;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    data.readBlob(_count_len,&_count_rblob);

                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (uint32_t*)_count_wblob.data();

                    memcpy(count,_count_rblob.data(),_count_len);
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                list = (tos_pvr_recording_file_info_t*)_list_wblob.data();
                count = (uint32_t*)_count_wblob.data();
                fpi_error _result = tos_pvr_get_recording_list( startIndex, list, count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_recording_list here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_set_file_sort_order:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_set_file_sort_order here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_PVR_FILE_SORT_TYPE type = (EN_TOS_PVR_FILE_SORT_TYPE)data.readInt32();  //EN_TOS_PVR_FILE_SORT_TYPE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_set_file_sort_order( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_set_file_sort_order here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_file_sort_order:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_file_sort_order here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _type_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_PVR_FILE_SORT_TYPE* type = NULL;

                Parcel::WritableBlob _type_wblob;

                if(_type_len > 0) {
                    reply->writeInt32(_type_len);
                    reply->writeBlob(_type_len,&_type_wblob);
                    type = (EN_TOS_PVR_FILE_SORT_TYPE*)_type_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                type = (EN_TOS_PVR_FILE_SORT_TYPE*)_type_wblob.data();
                fpi_error _result = tos_pvr_get_file_sort_order( type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_file_sort_order here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_recording_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_recording_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                char* url = NULL;

                Parcel::ReadableBlob _url_rblob;

                if(_url_len > 0) {
                    data.readBlob(_url_len,&_url_rblob);
                    url = (char*)_url_rblob.data();
                }

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                tos_pvr_recording_info_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (tos_pvr_recording_info_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (char*)_url_rblob.data();
                value = (tos_pvr_recording_info_t*)_value_wblob.data();
                fpi_error _result = tos_pvr_get_recording_info( url, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_recording_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_delete_recording:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_delete_recording here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                char* url = NULL;

                Parcel::ReadableBlob _url_rblob;

                if(_url_len > 0) {
                    data.readBlob(_url_len,&_url_rblob);
                    url = (char*)_url_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (char*)_url_rblob.data();
                fpi_error _result = tos_pvr_delete_recording( url );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_delete_recording here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t channelId = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_start( channelId );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_pause(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_resume(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_resume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_recording_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_recording_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_pvr_get_recording_state( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_recording_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_current_recording_url:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_current_recording_url here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                char* url = NULL;

                Parcel::WritableBlob _url_wblob;

                if(_url_len > 0) {
                    reply->writeInt32(_url_len);
                    reply->writeBlob(_url_len,&_url_wblob);
                    url = (char*)_url_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (char*)_url_wblob.data();
                fpi_error _result = tos_pvr_get_current_recording_url( url );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_current_recording_url here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_file_start_play:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_file_start_play here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                char* url = NULL;

                Parcel::ReadableBlob _url_rblob;

                if(_url_len > 0) {
                    data.readBlob(_url_len,&_url_rblob);
                    url = (char*)_url_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (char*)_url_rblob.data();
                fpi_error _result = tos_pvr_record_file_start_play( url );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_file_start_play here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_file_stop_play:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_file_stop_play here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_file_stop_play(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_file_stop_play here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_set_motion:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_set_motion here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_PVR_MOTION motion = (EN_TOS_PVR_MOTION)data.readInt32();  //EN_TOS_PVR_MOTION as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_set_motion( motion );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_set_motion here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_current_motion:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_current_motion here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _motion_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_PVR_MOTION* motion = NULL;

                Parcel::WritableBlob _motion_wblob;

                if(_motion_len > 0) {
                    reply->writeInt32(_motion_len);
                    reply->writeBlob(_motion_len,&_motion_wblob);
                    motion = (EN_TOS_PVR_MOTION*)_motion_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                motion = (EN_TOS_PVR_MOTION*)_motion_wblob.data();
                fpi_error _result = tos_pvr_play_get_current_motion( motion );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_current_motion here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_seek:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_seek here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t seek = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_seek( seek );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_seek here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_current_play_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_current_play_time here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int32_t*)_value_wblob.data();
                fpi_error _result = tos_pvr_play_get_current_play_time( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_current_play_time here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_file_url:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_file_url here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _url_len = data.readInt32(); //read length, only 32bits length support yet
                char* url = NULL;

                Parcel::WritableBlob _url_wblob;

                if(_url_len > 0) {
                    reply->writeInt32(_url_len);
                    reply->writeBlob(_url_len,&_url_wblob);
                    url = (char*)_url_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                url = (char*)_url_wblob.data();
                fpi_error _result = tos_pvr_play_get_file_url( url );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_file_url here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_audio_track_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_audio_track_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _list_len = data.readInt32(); //read length, only 32bits length support yet
                tos_pvr_audio_stream_info_t* list = NULL;

                Parcel::WritableBlob _list_wblob;

                if(_list_len > 0) {
                    reply->writeInt32(_list_len);
                    reply->writeBlob(_list_len,&_list_wblob);
                    list = (tos_pvr_audio_stream_info_t*)_list_wblob.data();
                }

                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* count = NULL;

                Parcel::ReadableBlob _count_rblob;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    data.readBlob(_count_len,&_count_rblob);

                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (int32_t*)_count_wblob.data();

                    memcpy(count,_count_rblob.data(),_count_len);
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                list = (tos_pvr_audio_stream_info_t*)_list_wblob.data();
                count = (int32_t*)_count_wblob.data();
                fpi_error _result = tos_pvr_play_get_audio_track_info( list, count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_audio_track_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_audio_track_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_audio_track_count here, will auoto generated but may change yourself if need --

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

                // re-get all pointers from blob to fix realloc issue in Parcel
                count = (int32_t*)_count_wblob.data();
                fpi_error _result = tos_pvr_play_get_audio_track_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_audio_track_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_current_audio_track:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_current_audio_track here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _id_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* id = NULL;

                Parcel::WritableBlob _id_wblob;

                if(_id_len > 0) {
                    reply->writeInt32(_id_len);
                    reply->writeBlob(_id_len,&_id_wblob);
                    id = (int32_t*)_id_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                id = (int32_t*)_id_wblob.data();
                fpi_error _result = tos_pvr_play_get_current_audio_track( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_current_audio_track here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_set_audio_track:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_set_audio_track here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t id = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_set_audio_track( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_set_audio_track here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_enable_subtitle:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_enable_subtitle here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool bEnable = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_enable_subtitle( bEnable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_enable_subtitle here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_subtitle_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_subtitle_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _list_len = data.readInt32(); //read length, only 32bits length support yet
                tos_pvr_subtitle_stream_info_t* list = NULL;

                Parcel::WritableBlob _list_wblob;

                if(_list_len > 0) {
                    reply->writeInt32(_list_len);
                    reply->writeBlob(_list_len,&_list_wblob);
                    list = (tos_pvr_subtitle_stream_info_t*)_list_wblob.data();
                }

                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* count = NULL;

                Parcel::ReadableBlob _count_rblob;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    data.readBlob(_count_len,&_count_rblob);

                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (int32_t*)_count_wblob.data();

                    memcpy(count,_count_rblob.data(),_count_len);
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                list = (tos_pvr_subtitle_stream_info_t*)_list_wblob.data();
                count = (int32_t*)_count_wblob.data();
                fpi_error _result = tos_pvr_play_get_subtitle_info( list, count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_subtitle_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_subtitle_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_subtitle_count here, will auoto generated but may change yourself if need --

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

                // re-get all pointers from blob to fix realloc issue in Parcel
                count = (int32_t*)_count_wblob.data();
                fpi_error _result = tos_pvr_play_get_subtitle_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_subtitle_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_current_subtitle:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_current_subtitle here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _id_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* id = NULL;

                Parcel::WritableBlob _id_wblob;

                if(_id_len > 0) {
                    reply->writeInt32(_id_len);
                    reply->writeBlob(_id_len,&_id_wblob);
                    id = (int32_t*)_id_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                id = (int32_t*)_id_wblob.data();
                fpi_error _result = tos_pvr_play_get_current_subtitle( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_current_subtitle here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_set_subtitle:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_set_subtitle here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t id = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_set_subtitle( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_set_subtitle here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_timeshift_start(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_timeshift_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_get_start_time:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_get_start_time here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _u32TimeInSeconds_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* u32TimeInSeconds = NULL;

                Parcel::WritableBlob _u32TimeInSeconds_wblob;

                if(_u32TimeInSeconds_len > 0) {
                    reply->writeInt32(_u32TimeInSeconds_len);
                    reply->writeBlob(_u32TimeInSeconds_len,&_u32TimeInSeconds_wblob);
                    u32TimeInSeconds = (uint32_t*)_u32TimeInSeconds_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u32TimeInSeconds = (uint32_t*)_u32TimeInSeconds_wblob.data();
                fpi_error _result = tos_pvr_timeshift_get_start_time( u32TimeInSeconds );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_get_start_time here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_is_file_exist:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_is_file_exist here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_pvr_timeshift_is_file_exist( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_is_file_exist here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_init_file:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_init_file here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t u32SizeInMB = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_timeshift_init_file( u32SizeInMB );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_init_file here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_timeshift_file_init_progress:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_timeshift_file_init_progress here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _u8Percent_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* u8Percent = NULL;

                Parcel::WritableBlob _u8Percent_wblob;

                if(_u8Percent_len > 0) {
                    reply->writeInt32(_u8Percent_len);
                    reply->writeBlob(_u8Percent_len,&_u8Percent_wblob);
                    u8Percent = (uint8_t*)_u8Percent_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u8Percent = (uint8_t*)_u8Percent_wblob.data();
                fpi_error _result = tos_pvr_get_timeshift_file_init_progress( u8Percent );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_timeshift_file_init_progress here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_write_speed_test:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_write_speed_test here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_TIMESHIFT_WRITE_SPEED_TEST test = (EN_TOS_TIMESHIFT_WRITE_SPEED_TEST)data.readInt32();  //EN_TOS_TIMESHIFT_WRITE_SPEED_TEST as input paramter

                int _u8Percent_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* u8Percent = NULL;

                Parcel::WritableBlob _u8Percent_wblob;

                if(_u8Percent_len > 0) {
                    reply->writeInt32(_u8Percent_len);
                    reply->writeBlob(_u8Percent_len,&_u8Percent_wblob);
                    u8Percent = (uint8_t*)_u8Percent_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u8Percent = (uint8_t*)_u8Percent_wblob.data();
                fpi_error _result = tos_pvr_timeshift_write_speed_test( test, u8Percent );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_write_speed_test here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_timeshift_speed:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_timeshift_speed here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _u32SpeedInKBps_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* u32SpeedInKBps = NULL;

                Parcel::WritableBlob _u32SpeedInKBps_wblob;

                if(_u32SpeedInKBps_len > 0) {
                    reply->writeInt32(_u32SpeedInKBps_len);
                    reply->writeBlob(_u32SpeedInKBps_len,&_u32SpeedInKBps_wblob);
                    u32SpeedInKBps = (uint32_t*)_u32SpeedInKBps_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u32SpeedInKBps = (uint32_t*)_u32SpeedInKBps_wblob.data();
                fpi_error _result = tos_pvr_get_timeshift_speed( u32SpeedInKBps );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_timeshift_speed here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_free_space_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_free_space_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_PVR_TYPE type = (EN_TOS_PVR_TYPE)data.readInt32();  //EN_TOS_PVR_TYPE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (fpi_bool*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (fpi_bool*)_value_wblob.data();
                fpi_error _result = tos_pvr_get_free_space_status( type, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_free_space_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_disk_free_space:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_disk_free_space here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _u32SizeInMB_len = data.readInt32(); //read length, only 32bits length support yet
                uint32_t* u32SizeInMB = NULL;

                Parcel::WritableBlob _u32SizeInMB_wblob;

                if(_u32SizeInMB_len > 0) {
                    reply->writeInt32(_u32SizeInMB_len);
                    reply->writeBlob(_u32SizeInMB_len,&_u32SizeInMB_wblob);
                    u32SizeInMB = (uint32_t*)_u32SizeInMB_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u32SizeInMB = (uint32_t*)_u32SizeInMB_wblob.data();
                fpi_error _result = tos_pvr_get_disk_free_space( u32SizeInMB );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_disk_free_space here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_disk_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_disk_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstrDevName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrDevName = NULL;

                Parcel::WritableBlob _pstrDevName_wblob;

                if(_pstrDevName_len > 0) {
                    reply->writeInt32(_pstrDevName_len);
                    reply->writeBlob(_pstrDevName_len,&_pstrDevName_wblob);
                    pstrDevName = (char*)_pstrDevName_wblob.data();
                }

                int _pstrDiskName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrDiskName = NULL;

                Parcel::WritableBlob _pstrDiskName_wblob;

                if(_pstrDiskName_len > 0) {
                    reply->writeInt32(_pstrDiskName_len);
                    reply->writeBlob(_pstrDiskName_len,&_pstrDiskName_wblob);
                    pstrDiskName = (char*)_pstrDiskName_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstrDevName = (char*)_pstrDevName_wblob.data();
                pstrDiskName = (char*)_pstrDiskName_wblob.data();
                fpi_error _result = tos_pvr_get_disk_info( pstrDevName, pstrDiskName );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_disk_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_select_disk:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_select_disk here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstrDevName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrDevName = NULL;

                Parcel::ReadableBlob _pstrDevName_rblob;

                if(_pstrDevName_len > 0) {
                    data.readBlob(_pstrDevName_len,&_pstrDevName_rblob);
                    pstrDevName = (char*)_pstrDevName_rblob.data();
                }

                int _pstrDiskName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrDiskName = NULL;

                Parcel::ReadableBlob _pstrDiskName_rblob;

                if(_pstrDiskName_len > 0) {
                    data.readBlob(_pstrDiskName_len,&_pstrDiskName_rblob);
                    pstrDiskName = (char*)_pstrDiskName_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstrDevName = (char*)_pstrDevName_rblob.data();
                pstrDiskName = (char*)_pstrDiskName_rblob.data();
                fpi_error _result = tos_pvr_select_disk( pstrDevName, pstrDiskName );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_select_disk here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_disk_format:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_disk_format here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstrDevDiskName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrDevDiskName = NULL;

                Parcel::ReadableBlob _pstrDevDiskName_rblob;

                if(_pstrDevDiskName_len > 0) {
                    data.readBlob(_pstrDevDiskName_len,&_pstrDevDiskName_rblob);
                    pstrDevDiskName = (char*)_pstrDevDiskName_rblob.data();
                }

                int _strMountPath_len = data.readInt32(); //read length, only 32bits length support yet
                char* strMountPath = NULL;

                Parcel::ReadableBlob _strMountPath_rblob;

                if(_strMountPath_len > 0) {
                    data.readBlob(_strMountPath_len,&_strMountPath_rblob);
                    strMountPath = (char*)_strMountPath_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstrDevDiskName = (char*)_pstrDevDiskName_rblob.data();
                strMountPath = (char*)_strMountPath_rblob.data();
                fpi_error _result = tos_pvr_disk_format( pstrDevDiskName, strMountPath );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_disk_format here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_get_formating_progress:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_get_formating_progress here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _u8Percent_len = data.readInt32(); //read length, only 32bits length support yet
                uint8_t* u8Percent = NULL;

                Parcel::WritableBlob _u8Percent_wblob;

                if(_u8Percent_len > 0) {
                    reply->writeInt32(_u8Percent_len);
                    reply->writeBlob(_u8Percent_len,&_u8Percent_wblob);
                    u8Percent = (uint8_t*)_u8Percent_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                u8Percent = (uint8_t*)_u8Percent_wblob.data();
                fpi_error _result = tos_pvr_get_formating_progress( u8Percent );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_get_formating_progress here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_file_play_by_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_file_play_by_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_PVR_PLAY play = (EN_TOS_PVR_PLAY)data.readInt32();  //EN_TOS_PVR_PLAY as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_file_play_by_mode( play );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_file_play_by_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_repeat_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_repeat_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_PVR_PLAY_REPEAT_MODE* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_TOS_PVR_PLAY_REPEAT_MODE*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (EN_TOS_PVR_PLAY_REPEAT_MODE*)_value_wblob.data();
                fpi_error _result = tos_pvr_play_get_repeat_mode( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_repeat_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_set_repeat_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_set_repeat_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_PVR_PLAY_REPEAT_MODE repeatmode = (EN_TOS_PVR_PLAY_REPEAT_MODE)data.readInt32();  //EN_TOS_PVR_PLAY_REPEAT_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_play_set_repeat_mode( repeatmode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_set_repeat_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_play_get_file_position:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_play_get_file_position here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* value = NULL;

                Parcel::WritableBlob _value_wblob;

                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (int32_t*)_value_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                value = (int32_t*)_value_wblob.data();
                fpi_error _result = tos_pvr_play_get_file_position( value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_play_get_file_position here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_ts_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_ts_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstrFileName_len = data.readInt32(); //read length, only 32bits length support yet
                char* pstrFileName = NULL;

                Parcel::ReadableBlob _pstrFileName_rblob;

                if(_pstrFileName_len > 0) {
                    data.readBlob(_pstrFileName_len,&_pstrFileName_rblob);
                    pstrFileName = (char*)_pstrFileName_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstrFileName = (char*)_pstrFileName_rblob.data();
                fpi_error _result = tos_pvr_record_ts_start( pstrFileName );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_ts_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_record_ts_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_record_ts_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_pvr_record_ts_stop(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_record_ts_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_pvr_timeshift_start_v2:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_pvr_timeshift_start_v2 here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstStartParams_len = data.readInt32(); //read length, only 32bits length support yet
                tos_pvr_timeshift_start_params_t* pstStartParams = NULL;

                Parcel::ReadableBlob _pstStartParams_rblob;

                if(_pstStartParams_len > 0) {
                    data.readBlob(_pstStartParams_len,&_pstStartParams_rblob);
                    pstStartParams = (tos_pvr_timeshift_start_params_t*)_pstStartParams_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstStartParams = (tos_pvr_timeshift_start_params_t*)_pstStartParams_rblob.data();
                fpi_error _result = tos_pvr_timeshift_start_v2( pstStartParams );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_pvr_timeshift_start_v2 here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_pvr_service_add() {
    sbinder_pvr_service::Instance();
    return 0;
}

sbinder_pvr_service* sbinder_pvr_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_pvr_client  
{  
private:
    static sbinder_pvr_client* _instance;
    sp<IBinder> _binder;

    sbinder_pvr_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_pvr_client() {
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
    static sbinder_pvr_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_pvr_client();
        }

        return _instance;
    }

    fpi_error tos_pvr_is_record_file_exist( char* path, fpi_bool* isExist ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_is_record_file_exist here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(path)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob((strlen(path)+1) * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,(strlen(path)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (isExist == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_is_record_file_exist,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (isExist != NULL) {
                    int _isExist_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _isExist_rblob;
                    reply.readBlob(_isExist_len,&_isExist_rblob);
                    memcpy(isExist,_isExist_rblob.data(),_isExist_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_is_record_file_exist error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_is_record_file_exist error");
        }

        return _result;
        /*-- add you code for tos_pvr_is_record_file_exist here --*/
    }

    fpi_error tos_pvr_scan_directory( char* usbDiskPath ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_scan_directory here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (usbDiskPath == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(usbDiskPath)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _usbDiskPath_wblob;
                data.writeBlob((strlen(usbDiskPath)+1) * sizeof(char),&_usbDiskPath_wblob);
                memcpy(_usbDiskPath_wblob.data(),usbDiskPath,(strlen(usbDiskPath)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_scan_directory,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_scan_directory error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_scan_directory error");
        }

        return _result;
        /*-- add you code for tos_pvr_scan_directory here --*/
    }

    fpi_error tos_pvr_scan_resource_release(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_scan_resource_release here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_scan_resource_release,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_scan_resource_release error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_scan_resource_release error");
        }

        return _result;
        /*-- add you code for tos_pvr_scan_resource_release here --*/
    }

    fpi_error tos_pvr_get_recording_list_count( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_recording_list_count here --*/
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
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_recording_list_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_list_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_list_count error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_recording_list_count here --*/
    }

    fpi_error tos_pvr_get_recording_list( int32_t startIndex, tos_pvr_recording_file_info_t* list, uint32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_recording_list here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(startIndex);  //int32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (list == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(*count) * sizeof(tos_pvr_recording_file_info_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _count_wblob;
                data.writeBlob((1) * sizeof(uint32_t),&_count_wblob);
                memcpy(_count_wblob.data(),count,(1)* sizeof(uint32_t));
            }

            _binder->transact(TRANSACTION_tos_pvr_get_recording_list,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (list != NULL) {
                    int _list_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _list_rblob;
                    reply.readBlob(_list_len,&_list_rblob);
                    memcpy(list,_list_rblob.data(),_list_len);
                }
                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_list error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_list error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_recording_list here --*/
    }

    fpi_error tos_pvr_set_file_sort_order( EN_TOS_PVR_FILE_SORT_TYPE type ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_set_file_sort_order here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_TOS_PVR_FILE_SORT_TYPE as input paramter

            _binder->transact(TRANSACTION_tos_pvr_set_file_sort_order,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_set_file_sort_order error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_set_file_sort_order error");
        }

        return _result;
        /*-- add you code for tos_pvr_set_file_sort_order here --*/
    }

    fpi_error tos_pvr_get_file_sort_order( EN_TOS_PVR_FILE_SORT_TYPE* type ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_file_sort_order here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(EN_TOS_PVR_FILE_SORT_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_file_sort_order,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (type != NULL) {
                    int _type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _type_rblob;
                    reply.readBlob(_type_len,&_type_rblob);
                    memcpy(type,_type_rblob.data(),_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_file_sort_order error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_file_sort_order error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_file_sort_order here --*/
    }

    fpi_error tos_pvr_get_recording_info( char* url, tos_pvr_recording_info_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_recording_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(url)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _url_wblob;
                data.writeBlob((strlen(url)+1) * sizeof(char),&_url_wblob);
                memcpy(_url_wblob.data(),url,(strlen(url)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_pvr_recording_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_recording_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_info error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_recording_info here --*/
    }

    fpi_error tos_pvr_delete_recording( char* url ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_delete_recording here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(url)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _url_wblob;
                data.writeBlob((strlen(url)+1) * sizeof(char),&_url_wblob);
                memcpy(_url_wblob.data(),url,(strlen(url)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_delete_recording,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_delete_recording error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_delete_recording error");
        }

        return _result;
        /*-- add you code for tos_pvr_delete_recording here --*/
    }

    fpi_error tos_pvr_record_start( uint32_t channelId ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_pvr_record_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_start error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_start here --*/
    }

    fpi_error tos_pvr_record_pause(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_pause here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_record_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_pause error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_pause error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_pause here --*/
    }

    fpi_error tos_pvr_record_resume(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_resume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_record_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_resume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_resume error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_resume here --*/
    }

    fpi_error tos_pvr_record_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_record_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_stop error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_stop here --*/
    }

    fpi_error tos_pvr_get_recording_state( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_recording_state here --*/
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
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_recording_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_recording_state error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_recording_state here --*/
    }

    fpi_error tos_pvr_get_current_recording_url( char* url ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_current_recording_url here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1024) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_current_recording_url,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (url != NULL) {
                    int _url_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _url_rblob;
                    reply.readBlob(_url_len,&_url_rblob);
                    //memcpy(url,_url_rblob.data(),_url_len);
                    strcpy(url,(char *)_url_rblob.data());
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_current_recording_url error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_current_recording_url error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_current_recording_url here --*/
    }

    fpi_error tos_pvr_record_file_start_play( char* url ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_file_start_play here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(url)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _url_wblob;
                data.writeBlob((strlen(url)+1) * sizeof(char),&_url_wblob);
                memcpy(_url_wblob.data(),url,(strlen(url)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_record_file_start_play,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_start_play error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_start_play error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_file_start_play here --*/
    }

    fpi_error tos_pvr_record_file_stop_play(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_file_stop_play here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_record_file_stop_play,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_stop_play error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_stop_play error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_file_stop_play here --*/
    }

    fpi_error tos_pvr_play_set_motion( EN_TOS_PVR_MOTION motion ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_set_motion here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(motion);  //EN_TOS_PVR_MOTION as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_set_motion,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_motion error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_motion error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_set_motion here --*/
    }

    fpi_error tos_pvr_play_get_current_motion( EN_TOS_PVR_MOTION* motion ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_current_motion here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (motion == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_PVR_MOTION));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_current_motion,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (motion != NULL) {
                    int _motion_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _motion_rblob;
                    reply.readBlob(_motion_len,&_motion_rblob);
                    memcpy(motion,_motion_rblob.data(),_motion_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_motion error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_motion error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_current_motion here --*/
    }

    fpi_error tos_pvr_play_seek( int32_t seek ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_seek here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(seek);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_seek,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_seek error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_seek error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_seek here --*/
    }

    fpi_error tos_pvr_play_get_current_play_time( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_current_play_time here --*/
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
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_current_play_time,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_play_time error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_play_time error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_current_play_time here --*/
    }

    fpi_error tos_pvr_play_get_file_url( char* url ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_file_url here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (url == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1024) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_file_url,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (url != NULL) {
                    int _url_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _url_rblob;
                    reply.readBlob(_url_len,&_url_rblob);
                    //memcpy(url,_url_rblob.data(),_url_len);
                    strcpy(url,(char*)_url_rblob.data());
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_file_url error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_file_url error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_file_url here --*/
    }

    fpi_error tos_pvr_play_get_audio_track_info( tos_pvr_audio_stream_info_t* list, int32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_audio_track_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (list == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(*count) * sizeof(tos_pvr_audio_stream_info_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _count_wblob;
                data.writeBlob((1) * sizeof(int32_t),&_count_wblob);
                memcpy(_count_wblob.data(),count,(1)* sizeof(int32_t));
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_audio_track_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (list != NULL) {
                    int _list_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _list_rblob;
                    reply.readBlob(_list_len,&_list_rblob);
                    memcpy(list,_list_rblob.data(),_list_len);
                }
                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_audio_track_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_audio_track_info error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_audio_track_info here --*/
    }

    fpi_error tos_pvr_play_get_audio_track_count( int32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_audio_track_count here --*/
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

            _binder->transact(TRANSACTION_tos_pvr_play_get_audio_track_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_audio_track_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_audio_track_count error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_audio_track_count here --*/
    }

    fpi_error tos_pvr_play_get_current_audio_track( int32_t* id ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_current_audio_track here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (id == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_current_audio_track,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (id != NULL) {
                    int _id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _id_rblob;
                    reply.readBlob(_id_len,&_id_rblob);
                    memcpy(id,_id_rblob.data(),_id_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_audio_track error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_audio_track error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_current_audio_track here --*/
    }

    fpi_error tos_pvr_play_set_audio_track( int32_t id ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_set_audio_track here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_set_audio_track,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_audio_track error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_audio_track error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_set_audio_track here --*/
    }

    fpi_error tos_pvr_play_enable_subtitle( fpi_bool bEnable ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_enable_subtitle here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(bEnable);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_enable_subtitle,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_enable_subtitle error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_enable_subtitle error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_enable_subtitle here --*/
    }

    fpi_error tos_pvr_play_get_subtitle_info( tos_pvr_subtitle_stream_info_t* list, int32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_subtitle_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (list == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(*count) * sizeof(tos_pvr_subtitle_stream_info_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _count_wblob;
                data.writeBlob((1) * sizeof(int32_t),&_count_wblob);
                memcpy(_count_wblob.data(),count,(1)* sizeof(int32_t));
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_subtitle_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (list != NULL) {
                    int _list_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _list_rblob;
                    reply.readBlob(_list_len,&_list_rblob);
                    memcpy(list,_list_rblob.data(),_list_len);
                }
                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_subtitle_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_subtitle_info error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_subtitle_info here --*/
    }

    fpi_error tos_pvr_play_get_subtitle_count( int32_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_subtitle_count here --*/
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

            _binder->transact(TRANSACTION_tos_pvr_play_get_subtitle_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_subtitle_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_subtitle_count error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_subtitle_count here --*/
    }

    fpi_error tos_pvr_play_get_current_subtitle( int32_t* id ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_current_subtitle here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (id == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_current_subtitle,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (id != NULL) {
                    int _id_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _id_rblob;
                    reply.readBlob(_id_len,&_id_rblob);
                    memcpy(id,_id_rblob.data(),_id_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_subtitle error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_current_subtitle error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_current_subtitle here --*/
    }

    fpi_error tos_pvr_play_set_subtitle( int32_t id ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_set_subtitle here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_set_subtitle,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_subtitle error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_subtitle error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_set_subtitle here --*/
    }

    fpi_error tos_pvr_timeshift_start(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_timeshift_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_start error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_start here --*/
    }

    fpi_error tos_pvr_timeshift_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_timeshift_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_stop error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_stop here --*/
    }

    fpi_error tos_pvr_timeshift_get_start_time( uint32_t* u32TimeInSeconds ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_get_start_time here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (u32TimeInSeconds == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_timeshift_get_start_time,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u32TimeInSeconds != NULL) {
                    int _u32TimeInSeconds_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u32TimeInSeconds_rblob;
                    reply.readBlob(_u32TimeInSeconds_len,&_u32TimeInSeconds_rblob);
                    memcpy(u32TimeInSeconds,_u32TimeInSeconds_rblob.data(),_u32TimeInSeconds_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_get_start_time error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_get_start_time error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_get_start_time here --*/
    }

    fpi_error tos_pvr_timeshift_is_file_exist( fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_is_file_exist here --*/
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
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_timeshift_is_file_exist,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_is_file_exist error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_is_file_exist error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_is_file_exist here --*/
    }

    fpi_error tos_pvr_timeshift_init_file( uint32_t u32SizeInMB ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_init_file here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(u32SizeInMB);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_pvr_timeshift_init_file,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_init_file error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_init_file error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_init_file here --*/
    }

    fpi_error tos_pvr_get_timeshift_file_init_progress( uint8_t* u8Percent ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_timeshift_file_init_progress here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (u8Percent == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_timeshift_file_init_progress,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u8Percent != NULL) {
                    int _u8Percent_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u8Percent_rblob;
                    reply.readBlob(_u8Percent_len,&_u8Percent_rblob);
                    memcpy(u8Percent,_u8Percent_rblob.data(),_u8Percent_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_timeshift_file_init_progress error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_timeshift_file_init_progress error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_timeshift_file_init_progress here --*/
    }

    fpi_error tos_pvr_timeshift_write_speed_test( EN_TOS_TIMESHIFT_WRITE_SPEED_TEST test, uint8_t* u8Percent ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_write_speed_test here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(test);  //EN_TOS_TIMESHIFT_WRITE_SPEED_TEST as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (u8Percent == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_timeshift_write_speed_test,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u8Percent != NULL) {
                    int _u8Percent_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u8Percent_rblob;
                    reply.readBlob(_u8Percent_len,&_u8Percent_rblob);
                    memcpy(u8Percent,_u8Percent_rblob.data(),_u8Percent_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_write_speed_test error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_write_speed_test error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_write_speed_test here --*/
    }

    fpi_error tos_pvr_get_timeshift_speed( uint32_t* u32SpeedInKBps ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_timeshift_speed here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (u32SpeedInKBps == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_timeshift_speed,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u32SpeedInKBps != NULL) {
                    int _u32SpeedInKBps_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u32SpeedInKBps_rblob;
                    reply.readBlob(_u32SpeedInKBps_len,&_u32SpeedInKBps_rblob);
                    memcpy(u32SpeedInKBps,_u32SpeedInKBps_rblob.data(),_u32SpeedInKBps_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_timeshift_speed error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_timeshift_speed error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_timeshift_speed here --*/
    }

    fpi_error tos_pvr_get_free_space_status( EN_TOS_PVR_TYPE type, fpi_bool* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_free_space_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_TOS_PVR_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_free_space_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_free_space_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_free_space_status error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_free_space_status here --*/
    }

    fpi_error tos_pvr_get_disk_free_space( uint32_t* u32SizeInMB ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_disk_free_space here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (u32SizeInMB == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_disk_free_space,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u32SizeInMB != NULL) {
                    int _u32SizeInMB_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u32SizeInMB_rblob;
                    reply.readBlob(_u32SizeInMB_len,&_u32SizeInMB_rblob);
                    memcpy(u32SizeInMB,_u32SizeInMB_rblob.data(),_u32SizeInMB_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_disk_free_space error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_disk_free_space error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_disk_free_space here --*/
    }

    fpi_error tos_pvr_get_disk_info( char* pstrDevName, char* pstrDiskName ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_disk_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstrDevName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1024) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (pstrDiskName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1024) * sizeof(char));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_disk_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pstrDevName != NULL) {
                    int _pstrDevName_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pstrDevName_rblob;
                    reply.readBlob(_pstrDevName_len,&_pstrDevName_rblob);
                    //memcpy(pstrDevName,_pstrDevName_rblob.data(),_pstrDevName_len);
                    strcpy(pstrDevName,(char *)_pstrDevName_rblob.data());
                }
                if (pstrDiskName != NULL) {
                    int _pstrDiskName_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pstrDiskName_rblob;
                    reply.readBlob(_pstrDiskName_len,&_pstrDiskName_rblob);
                    //memcpy(pstrDiskName,_pstrDiskName_rblob.data(),_pstrDiskName_len);
                    strcpy(pstrDiskName,(char *)_pstrDiskName_rblob.data());
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_disk_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_disk_info error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_disk_info here --*/
    }

    fpi_error tos_pvr_select_disk( char* pstrDevName, char* pstrDiskName ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_select_disk here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstrDevName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(pstrDevName)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pstrDevName_wblob;
                data.writeBlob((strlen(pstrDevName)+1) * sizeof(char),&_pstrDevName_wblob);
                memcpy(_pstrDevName_wblob.data(),pstrDevName,(strlen(pstrDevName)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (pstrDiskName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(pstrDiskName)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pstrDiskName_wblob;
                data.writeBlob((strlen(pstrDiskName)+1) * sizeof(char),&_pstrDiskName_wblob);
                memcpy(_pstrDiskName_wblob.data(),pstrDiskName,(strlen(pstrDiskName)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_select_disk,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_select_disk error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_select_disk error");
        }

        return _result;
        /*-- add you code for tos_pvr_select_disk here --*/
    }

    fpi_error tos_pvr_disk_format( char* pstrDevDiskName, char* strMountPath ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_disk_format here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstrDevDiskName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(pstrDevDiskName)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pstrDevDiskName_wblob;
                data.writeBlob((strlen(pstrDevDiskName)+1) * sizeof(char),&_pstrDevDiskName_wblob);
                memcpy(_pstrDevDiskName_wblob.data(),pstrDevDiskName,(strlen(pstrDevDiskName)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (strMountPath == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(strMountPath)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _strMountPath_wblob;
                data.writeBlob((strlen(strMountPath)+1) * sizeof(char),&_strMountPath_wblob);
                memcpy(_strMountPath_wblob.data(),strMountPath,(strlen(strMountPath)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_disk_format,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_disk_format error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_disk_format error");
        }

        return _result;
        /*-- add you code for tos_pvr_disk_format here --*/
    }

    fpi_error tos_pvr_get_formating_progress( uint8_t* u8Percent ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_get_formating_progress here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (u8Percent == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint8_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_get_formating_progress,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (u8Percent != NULL) {
                    int _u8Percent_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _u8Percent_rblob;
                    reply.readBlob(_u8Percent_len,&_u8Percent_rblob);
                    memcpy(u8Percent,_u8Percent_rblob.data(),_u8Percent_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_get_formating_progress error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_get_formating_progress error");
        }

        return _result;
        /*-- add you code for tos_pvr_get_formating_progress here --*/
    }

    fpi_error tos_pvr_record_file_play_by_mode( EN_TOS_PVR_PLAY play ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_file_play_by_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(play);  //EN_TOS_PVR_PLAY as input paramter

            _binder->transact(TRANSACTION_tos_pvr_record_file_play_by_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_play_by_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_file_play_by_mode error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_file_play_by_mode here --*/
    }

    fpi_error tos_pvr_play_get_repeat_mode( EN_TOS_PVR_PLAY_REPEAT_MODE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_repeat_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_TOS_PVR_PLAY_REPEAT_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_repeat_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_repeat_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_repeat_mode error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_repeat_mode here --*/
    }

    fpi_error tos_pvr_play_set_repeat_mode( EN_TOS_PVR_PLAY_REPEAT_MODE repeatmode ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_set_repeat_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(repeatmode);  //EN_TOS_PVR_PLAY_REPEAT_MODE as input paramter

            _binder->transact(TRANSACTION_tos_pvr_play_set_repeat_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_repeat_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_set_repeat_mode error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_set_repeat_mode here --*/
    }

    fpi_error tos_pvr_play_get_file_position( int32_t* value ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_play_get_file_position here --*/
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
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_pvr_play_get_file_position,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_file_position error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_play_get_file_position error");
        }

        return _result;
        /*-- add you code for tos_pvr_play_get_file_position here --*/
    }

    fpi_error tos_pvr_record_ts_start( char* pstrFileName ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_ts_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstrFileName == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(pstrFileName)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pstrFileName_wblob;
                data.writeBlob((strlen(pstrFileName)+1) * sizeof(char),&_pstrFileName_wblob);
                memcpy(_pstrFileName_wblob.data(),pstrFileName,(strlen(pstrFileName)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_pvr_record_ts_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_ts_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_ts_start error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_ts_start here --*/
    }

    fpi_error tos_pvr_record_ts_stop(  ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_record_ts_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_pvr_record_ts_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_record_ts_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_record_ts_stop error");
        }

        return _result;
        /*-- add you code for tos_pvr_record_ts_stop here --*/
    }

    fpi_error tos_pvr_timeshift_start_v2( tos_pvr_timeshift_start_params_t* pstStartParams ) {
        Parcel data, reply;

        /*-- add you code for tos_pvr_timeshift_start_v2 here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstStartParams == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(sizeof(tos_pvr_timeshift_start_params_t));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pstStartParams_wblob;
                data.writeBlob(sizeof(tos_pvr_timeshift_start_params_t),&_pstStartParams_wblob);
                memcpy(_pstStartParams_wblob.data(),pstStartParams,sizeof(tos_pvr_timeshift_start_params_t));
            }

            _binder->transact(TRANSACTION_tos_pvr_timeshift_start_v2,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_start_v2 error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_pvr_timeshift_start_v2 error");
        }

        return _result;
        /*-- add you code for tos_pvr_timeshift_start_v2 here --*/
    }
};

sbinder_pvr_client* sbinder_pvr_client::_instance = NULL;

fpi_error tos_pvr_is_record_file_exist( char* path, fpi_bool* isExist ) {
    return sbinder_pvr_client::Instance()->tos_pvr_is_record_file_exist(path, isExist);
}
fpi_error tos_pvr_scan_directory( char* usbDiskPath ) {
    return sbinder_pvr_client::Instance()->tos_pvr_scan_directory(usbDiskPath);
}
fpi_error tos_pvr_scan_resource_release(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_scan_resource_release();
}
fpi_error tos_pvr_get_recording_list_count( int32_t* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_recording_list_count(value);
}
fpi_error tos_pvr_get_recording_list( int32_t startIndex, tos_pvr_recording_file_info_t* list, uint32_t* count ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_recording_list(startIndex, list, count);
}
fpi_error tos_pvr_set_file_sort_order( EN_TOS_PVR_FILE_SORT_TYPE type ) {
    return sbinder_pvr_client::Instance()->tos_pvr_set_file_sort_order(type);
}
fpi_error tos_pvr_get_file_sort_order( EN_TOS_PVR_FILE_SORT_TYPE* type ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_file_sort_order(type);
}
fpi_error tos_pvr_get_recording_info( char* url, tos_pvr_recording_info_t* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_recording_info(url, value);
}
fpi_error tos_pvr_delete_recording( char* url ) {
    return sbinder_pvr_client::Instance()->tos_pvr_delete_recording(url);
}
fpi_error tos_pvr_record_start( uint32_t channelId ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_start(channelId);
}
fpi_error tos_pvr_record_pause(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_pause();
}
fpi_error tos_pvr_record_resume(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_resume();
}
fpi_error tos_pvr_record_stop(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_stop();
}
fpi_error tos_pvr_get_recording_state( fpi_bool* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_recording_state(value);
}
fpi_error tos_pvr_get_current_recording_url( char* url ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_current_recording_url(url);
}
fpi_error tos_pvr_record_file_start_play( char* url ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_file_start_play(url);
}
fpi_error tos_pvr_record_file_stop_play(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_file_stop_play();
}
fpi_error tos_pvr_play_set_motion( EN_TOS_PVR_MOTION motion ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_set_motion(motion);
}
fpi_error tos_pvr_play_get_current_motion( EN_TOS_PVR_MOTION* motion ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_current_motion(motion);
}
fpi_error tos_pvr_play_seek( int32_t seek ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_seek(seek);
}
fpi_error tos_pvr_play_get_current_play_time( int32_t* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_current_play_time(value);
}
fpi_error tos_pvr_play_get_file_url( char* url ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_file_url(url);
}
fpi_error tos_pvr_play_get_audio_track_info( tos_pvr_audio_stream_info_t* list, int32_t* count ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_audio_track_info(list, count);
}
fpi_error tos_pvr_play_get_audio_track_count( int32_t* count ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_audio_track_count(count);
}
fpi_error tos_pvr_play_get_current_audio_track( int32_t* id ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_current_audio_track(id);
}
fpi_error tos_pvr_play_set_audio_track( int32_t id ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_set_audio_track(id);
}
fpi_error tos_pvr_play_enable_subtitle( fpi_bool bEnable ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_enable_subtitle(bEnable);
}
fpi_error tos_pvr_play_get_subtitle_info( tos_pvr_subtitle_stream_info_t* list, int32_t* count ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_subtitle_info(list, count);
}
fpi_error tos_pvr_play_get_subtitle_count( int32_t* count ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_subtitle_count(count);
}
fpi_error tos_pvr_play_get_current_subtitle( int32_t* id ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_current_subtitle(id);
}
fpi_error tos_pvr_play_set_subtitle( int32_t id ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_set_subtitle(id);
}
fpi_error tos_pvr_timeshift_start(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_start();
}
fpi_error tos_pvr_timeshift_stop(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_stop();
}
fpi_error tos_pvr_timeshift_get_start_time( uint32_t* u32TimeInSeconds ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_get_start_time(u32TimeInSeconds);
}
fpi_error tos_pvr_timeshift_is_file_exist( fpi_bool* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_is_file_exist(value);
}
fpi_error tos_pvr_timeshift_init_file( uint32_t u32SizeInMB ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_init_file(u32SizeInMB);
}
fpi_error tos_pvr_get_timeshift_file_init_progress( uint8_t* u8Percent ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_timeshift_file_init_progress(u8Percent);
}
fpi_error tos_pvr_timeshift_write_speed_test( EN_TOS_TIMESHIFT_WRITE_SPEED_TEST test, uint8_t* u8Percent ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_write_speed_test(test, u8Percent);
}
fpi_error tos_pvr_get_timeshift_speed( uint32_t* u32SpeedInKBps ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_timeshift_speed(u32SpeedInKBps);
}
fpi_error tos_pvr_get_free_space_status( EN_TOS_PVR_TYPE type, fpi_bool* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_free_space_status(type, value);
}
fpi_error tos_pvr_get_disk_free_space( uint32_t* u32SizeInMB ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_disk_free_space(u32SizeInMB);
}
fpi_error tos_pvr_get_disk_info( char* pstrDevName, char* pstrDiskName ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_disk_info(pstrDevName, pstrDiskName);
}
fpi_error tos_pvr_select_disk( char* pstrDevName, char* pstrDiskName ) {
    return sbinder_pvr_client::Instance()->tos_pvr_select_disk(pstrDevName, pstrDiskName);
}
fpi_error tos_pvr_disk_format( char* pstrDevDiskName, char* strMountPath ) {
    return sbinder_pvr_client::Instance()->tos_pvr_disk_format(pstrDevDiskName, strMountPath);
}
fpi_error tos_pvr_get_formating_progress( uint8_t* u8Percent ) {
    return sbinder_pvr_client::Instance()->tos_pvr_get_formating_progress(u8Percent);
}
fpi_error tos_pvr_record_file_play_by_mode( EN_TOS_PVR_PLAY play ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_file_play_by_mode(play);
}
fpi_error tos_pvr_play_get_repeat_mode( EN_TOS_PVR_PLAY_REPEAT_MODE* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_repeat_mode(value);
}
fpi_error tos_pvr_play_set_repeat_mode( EN_TOS_PVR_PLAY_REPEAT_MODE repeatmode ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_set_repeat_mode(repeatmode);
}
fpi_error tos_pvr_play_get_file_position( int32_t* value ) {
    return sbinder_pvr_client::Instance()->tos_pvr_play_get_file_position(value);
}
fpi_error tos_pvr_record_ts_start( char* pstrFileName ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_ts_start(pstrFileName);
}
fpi_error tos_pvr_record_ts_stop(  ) {
    return sbinder_pvr_client::Instance()->tos_pvr_record_ts_stop();
}
fpi_error tos_pvr_timeshift_start_v2( tos_pvr_timeshift_start_params_t* pstStartParams ) {
    return sbinder_pvr_client::Instance()->tos_pvr_timeshift_start_v2(pstStartParams);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
