/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_snapshot_record.sidl
 */
 

#define LOG_TAG     "sbinder_snapshot_record"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_snapshot_record.h"
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_VIDEO);


#define SERVICE_DESCRIPTOR                      "fa3a558a-3d8f-11e5-b485-005056a86db3"
#define SERVICE_NAME                            "sbinder_snapshot_record"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_snapshot FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_record_set_output_file FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_record_set_video_param FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_record_set_audio_param FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_record_start_screen FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_record_stop_screen FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_record_pause_screen FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_record_resume_screen FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_record_reset_screen FIRST_CALL_TRANSACTION + 9

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_snapshot_record.h"

class sbinder_snapshot_record_service : public BBinder  
{  
private:
    static sbinder_snapshot_record_service* _instance;

    sbinder_snapshot_record_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_snapshot_record_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_snapshot_record_service();
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

            case TRANSACTION_tos_snapshot:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_snapshot here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t windowId = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _rect_len = data.readInt32(); //read length, only 32bits length support yet
                ST_SNAPSHOT_RECT* rect = NULL;

                Parcel::ReadableBlob _rect_rblob;

                if(_rect_len > 0) {
                    data.readBlob(_rect_len,&_rect_rblob);
                    rect = (ST_SNAPSHOT_RECT*)_rect_rblob.data();
                }

                int _path_len = data.readInt32(); //read length, only 32bits length support yet
                const char* path = NULL;

                Parcel::ReadableBlob _path_rblob;

                if(_path_len > 0) {
                    data.readBlob(_path_len,&_path_rblob);
                    path = (const char*)_path_rblob.data();
                }

                uint32_t mode = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _resolution_len = data.readInt32(); //read length, only 32bits length support yet
                ST_SNAPSHOT_RESOLUTION* resolution = NULL;

                Parcel::ReadableBlob _resolution_rblob;

                if(_resolution_len > 0) {
                    data.readBlob(_resolution_len,&_resolution_rblob);
                    resolution = (ST_SNAPSHOT_RESOLUTION*)_resolution_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                rect = (ST_SNAPSHOT_RECT*)_rect_rblob.data();
                path = (const char*)_path_rblob.data();
                resolution = (ST_SNAPSHOT_RESOLUTION*)_resolution_rblob.data();
                fpi_error _result = tos_snapshot( windowId, rect, path, mode, resolution );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_snapshot here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_set_output_file:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_set_output_file here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                int _filepath_len = data.readInt32(); //read length, only 32bits length support yet
                const char* filepath = NULL;

                Parcel::ReadableBlob _filepath_rblob;

                if(_filepath_len > 0) {
                    data.readBlob(_filepath_len,&_filepath_rblob);
                    filepath = (const char*)_filepath_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                filepath = (const char*)_filepath_rblob.data();
                fpi_error _result = tos_record_set_output_file( mode, filepath );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_set_output_file here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_set_video_param:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_set_video_param here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t window_id = (uint32_t)data.readInt32();  //uint32_t as input paramter

                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                int _resolution_len = data.readInt32(); //read length, only 32bits length support yet
                ST_SNAPSHOT_RESOLUTION* resolution = NULL;

                Parcel::ReadableBlob _resolution_rblob;

                if(_resolution_len > 0) {
                    data.readBlob(_resolution_len,&_resolution_rblob);
                    resolution = (ST_SNAPSHOT_RESOLUTION*)_resolution_rblob.data();
                }

                uint32_t frame_rate = (uint32_t)data.readInt32();  //uint32_t as input paramter

                int _rect_len = data.readInt32(); //read length, only 32bits length support yet
                ST_SNAPSHOT_RECT* rect = NULL;

                Parcel::ReadableBlob _rect_rblob;

                if(_rect_len > 0) {
                    data.readBlob(_rect_len,&_rect_rblob);
                    rect = (ST_SNAPSHOT_RECT*)_rect_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                resolution = (ST_SNAPSHOT_RESOLUTION*)_resolution_rblob.data();
                rect = (ST_SNAPSHOT_RECT*)_rect_rblob.data();
                fpi_error _result = tos_record_set_video_param( window_id, mode, resolution, frame_rate, rect );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_set_video_param here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_set_audio_param:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_set_audio_param here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint32_t sample_rate = (uint32_t)data.readInt32();  //uint32_t as input paramter

                uint32_t simple_bit = (uint32_t)data.readInt32();  //uint32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_set_audio_param( sample_rate, simple_bit );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_set_audio_param here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_start_screen:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_start_screen here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_start_screen( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_start_screen here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_stop_screen:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_stop_screen here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_stop_screen( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_stop_screen here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_pause_screen:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_pause_screen here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_pause_screen( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_pause_screen here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_resume_screen:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_resume_screen here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_resume_screen( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_resume_screen here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_record_reset_screen:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_record_reset_screen here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_RECORD_MODE mode = (EN_RECORD_MODE)data.readInt32();  //EN_RECORD_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_record_reset_screen( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_record_reset_screen here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_snapshot_record_service_add() {
    sbinder_snapshot_record_service::Instance();
    return 0;
}

sbinder_snapshot_record_service* sbinder_snapshot_record_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_snapshot_record_client  
{  
private:
    static sbinder_snapshot_record_client* _instance;
    sp<IBinder> _binder;

    sbinder_snapshot_record_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_snapshot_record_client() {
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
    static sbinder_snapshot_record_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_snapshot_record_client();
        }

        return _instance;
    }

    fpi_error tos_snapshot( uint32_t windowId, ST_SNAPSHOT_RECT* rect, const char* path, uint32_t mode, ST_SNAPSHOT_RESOLUTION* resolution ) {
        Parcel data, reply;

        /*-- add you code for tos_snapshot here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(windowId);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (rect == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(ST_SNAPSHOT_RECT));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _rect_wblob;
                data.writeBlob((1) * sizeof(ST_SNAPSHOT_RECT),&_rect_wblob);
                memcpy(_rect_wblob.data(),rect,(1)* sizeof(ST_SNAPSHOT_RECT));
            }

            //for out only, only write length ; for in, alloc and copy
            if (path == NULL) {
                data.writeInt32(-1);
            }
            else {
				int pathlen  = 0;
				pathlen  =  strlen(path)+1;
				
				fpi_info("****%s:%d --> path is %s, pathlen is %d\n",__FUNCTION__,__LINE__, path, pathlen);
				
                data.writeInt32(pathlen * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _path_wblob;
                data.writeBlob(pathlen * sizeof(char),&_path_wblob);
                memcpy(_path_wblob.data(),path,pathlen* sizeof(char));
            }

            data.writeInt32(mode);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (resolution == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(ST_SNAPSHOT_RESOLUTION));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _resolution_wblob;
                data.writeBlob((1) * sizeof(ST_SNAPSHOT_RESOLUTION),&_resolution_wblob);
                memcpy(_resolution_wblob.data(),resolution,(1)* sizeof(ST_SNAPSHOT_RESOLUTION));
            }

            _binder->transact(TRANSACTION_tos_snapshot,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_snapshot error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_snapshot error");
        }

        return _result;
        /*-- add you code for tos_snapshot here --*/
    }

    fpi_error tos_record_set_output_file( EN_RECORD_MODE mode, const char* filepath ) {
        Parcel data, reply;

        /*-- add you code for tos_record_set_output_file here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (filepath == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(256) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _filepath_wblob;
                data.writeBlob((256) * sizeof(char),&_filepath_wblob);
                memcpy(_filepath_wblob.data(),filepath,(256)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_record_set_output_file,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_set_output_file error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_set_output_file error");
        }

        return _result;
        /*-- add you code for tos_record_set_output_file here --*/
    }

    fpi_error tos_record_set_video_param( uint32_t window_id, EN_RECORD_MODE mode, ST_SNAPSHOT_RESOLUTION* resolution, uint32_t frame_rate, ST_SNAPSHOT_RECT* rect ) {
        Parcel data, reply;

        /*-- add you code for tos_record_set_video_param here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(window_id);  //uint32_t as input paramter

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (resolution == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(ST_SNAPSHOT_RESOLUTION));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _resolution_wblob;
                data.writeBlob((1) * sizeof(ST_SNAPSHOT_RESOLUTION),&_resolution_wblob);
                memcpy(_resolution_wblob.data(),resolution,(1)* sizeof(ST_SNAPSHOT_RESOLUTION));
            }

            data.writeInt32(frame_rate);  //uint32_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (rect == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(ST_SNAPSHOT_RECT));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _rect_wblob;
                data.writeBlob((1) * sizeof(ST_SNAPSHOT_RECT),&_rect_wblob);
                memcpy(_rect_wblob.data(),rect,(1)* sizeof(ST_SNAPSHOT_RECT));
            }

            _binder->transact(TRANSACTION_tos_record_set_video_param,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_set_video_param error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_set_video_param error");
        }

        return _result;
        /*-- add you code for tos_record_set_video_param here --*/
    }

    fpi_error tos_record_set_audio_param( uint32_t sample_rate, uint32_t simple_bit ) {
        Parcel data, reply;

        /*-- add you code for tos_record_set_audio_param here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(sample_rate);  //uint32_t as input paramter

            data.writeInt32(simple_bit);  //uint32_t as input paramter

            _binder->transact(TRANSACTION_tos_record_set_audio_param,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_set_audio_param error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_set_audio_param error");
        }

        return _result;
        /*-- add you code for tos_record_set_audio_param here --*/
    }

    fpi_error tos_record_start_screen( EN_RECORD_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_record_start_screen here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            _binder->transact(TRANSACTION_tos_record_start_screen,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_start_screen error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_start_screen error");
        }

        return _result;
        /*-- add you code for tos_record_start_screen here --*/
    }

    fpi_error tos_record_stop_screen( EN_RECORD_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_record_stop_screen here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            _binder->transact(TRANSACTION_tos_record_stop_screen,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_stop_screen error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_stop_screen error");
        }

        return _result;
        /*-- add you code for tos_record_stop_screen here --*/
    }

    fpi_error tos_record_pause_screen( EN_RECORD_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_record_pause_screen here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            _binder->transact(TRANSACTION_tos_record_pause_screen,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_pause_screen error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_pause_screen error");
        }

        return _result;
        /*-- add you code for tos_record_pause_screen here --*/
    }

    fpi_error tos_record_resume_screen( EN_RECORD_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_record_resume_screen here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            _binder->transact(TRANSACTION_tos_record_resume_screen,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_resume_screen error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_resume_screen error");
        }

        return _result;
        /*-- add you code for tos_record_resume_screen here --*/
    }

    fpi_error tos_record_reset_screen( EN_RECORD_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_record_reset_screen here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_RECORD_MODE as input paramter

            _binder->transact(TRANSACTION_tos_record_reset_screen,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_record_reset_screen error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_record_reset_screen error");
        }

        return _result;
        /*-- add you code for tos_record_reset_screen here --*/
    }
};

sbinder_snapshot_record_client* sbinder_snapshot_record_client::_instance = NULL;

fpi_error tos_snapshot( uint32_t windowId, ST_SNAPSHOT_RECT* rect, const char* path, uint32_t mode, ST_SNAPSHOT_RESOLUTION* resolution ) {
    return sbinder_snapshot_record_client::Instance()->tos_snapshot(windowId, rect, path, mode, resolution);
}
fpi_error tos_record_set_output_file( EN_RECORD_MODE mode, const char* filepath ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_set_output_file(mode, filepath);
}
fpi_error tos_record_set_video_param( uint32_t window_id, EN_RECORD_MODE mode, ST_SNAPSHOT_RESOLUTION* resolution, uint32_t frame_rate, ST_SNAPSHOT_RECT* rect ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_set_video_param(window_id, mode, resolution, frame_rate, rect);
}
fpi_error tos_record_set_audio_param( uint32_t sample_rate, uint32_t simple_bit ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_set_audio_param(sample_rate, simple_bit);
}
fpi_error tos_record_start_screen( EN_RECORD_MODE mode ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_start_screen(mode);
}
fpi_error tos_record_stop_screen( EN_RECORD_MODE mode ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_stop_screen(mode);
}
fpi_error tos_record_pause_screen( EN_RECORD_MODE mode ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_pause_screen(mode);
}
fpi_error tos_record_resume_screen( EN_RECORD_MODE mode ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_resume_screen(mode);
}
fpi_error tos_record_reset_screen( EN_RECORD_MODE mode ) {
    return sbinder_snapshot_record_client::Instance()->tos_record_reset_screen(mode);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
