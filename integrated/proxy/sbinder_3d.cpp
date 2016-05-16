/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_3d.sidl
 */
 

#define LOG_TAG     "sbinder_3d"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_3d.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_3D);


#define SERVICE_DESCRIPTOR                      "a633ca86-ed88-11e4-afb3-005056a84a3b"
#define SERVICE_NAME                            "sbinder_3d"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_3d_get_depth_of_field FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_3d_set_depth_of_field FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_3d_get_3dto2d_mode FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_3d_set_3dto2d_mode FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_3d_get_display_format FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_3d_set_display_format FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_3d_get_left_right_switch FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_3d_set_left_right_switch FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_3d_is_framepacking_mode FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_3d_get_navigation FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_3d_set_navigation FIRST_CALL_TRANSACTION + 11

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_3d.h"

class sbinder_3d_service : public BBinder  
{  
private:
    static sbinder_3d_service* _instance;

    sbinder_3d_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_3d_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_3d_service();
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

            case TRANSACTION_tos_3d_get_depth_of_field:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_get_depth_of_field here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _depth_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* depth = NULL;

                Parcel::WritableBlob _depth_wblob;

                if(_depth_len > 0) {
                    reply->writeInt32(_depth_len);
                    reply->writeBlob(_depth_len,&_depth_wblob);
                    depth = (int16_t*)_depth_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                depth = (int16_t*)_depth_wblob.data();
                fpi_error _result = tos_3d_get_depth_of_field( depth );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_get_depth_of_field here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_set_depth_of_field:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_set_depth_of_field here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t depth = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_set_depth_of_field( depth, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_set_depth_of_field here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_get_3dto2d_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_get_3dto2d_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode = NULL;
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_FPI_3D_VIDEO_DIAPLAY_FORMAT*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_get_3dto2d_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_get_3dto2d_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_set_3dto2d_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_set_3dto2d_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode = (EN_FPI_3D_VIDEO_DIAPLAY_FORMAT)data.readInt32();  //EN_FPI_3D_VIDEO_DIAPLAY_FORMAT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_set_3dto2d_mode( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_set_3dto2d_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_get_display_format:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_get_display_format here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode= NULL;
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_FPI_3D_VIDEO_DIAPLAY_FORMAT*)_mode_wblob.data();
                }
				fpi_error _result;
                // re-get all pointers from blob to fix realloc issue in Parcel
                if( mode != NULL ){
                _result = tos_3d_get_display_format( mode );
                	}else{
                	_result = FPI_ERROR_FAIL;
                		}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_get_display_format here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_set_display_format:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_set_display_format here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode = (EN_FPI_3D_VIDEO_DIAPLAY_FORMAT)data.readInt32();  //EN_FPI_3D_VIDEO_DIAPLAY_FORMAT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_set_display_format( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_set_display_format here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_get_left_right_switch:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_get_left_right_switch here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _lrswitch_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* lrswitch = NULL;

                Parcel::WritableBlob _lrswitch_wblob;

                if(_lrswitch_len > 0) {
                    reply->writeInt32(_lrswitch_len);
                    reply->writeBlob(_lrswitch_len,&_lrswitch_wblob);
                    lrswitch = (int16_t*)_lrswitch_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                lrswitch = (int16_t*)_lrswitch_wblob.data();
                fpi_error _result = tos_3d_get_left_right_switch( lrswitch );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_get_left_right_switch here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_set_left_right_switch:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_set_left_right_switch here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t lrswitch = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_set_left_right_switch( lrswitch, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_set_left_right_switch here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_is_framepacking_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_is_framepacking_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (int16_t*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (int16_t*)_mode_wblob.data();
                fpi_error _result = tos_3d_is_framepacking_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_is_framepacking_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_get_navigation:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_get_navigation here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* mode = NULL;

                Parcel::WritableBlob _mode_wblob;

                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (int16_t*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mode = (int16_t*)_mode_wblob.data();
                fpi_error _result = tos_3d_get_navigation( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_get_navigation here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_3d_set_navigation:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_3d_set_navigation here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int16_t mode = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_3d_set_navigation( mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_3d_set_navigation here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_3d_service_add() {
    sbinder_3d_service::Instance();
    return 0;
}

sbinder_3d_service* sbinder_3d_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_3d_client  
{  
private:
    static sbinder_3d_client* _instance;
    sp<IBinder> _binder;

    sbinder_3d_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_3d_client() {
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
    static sbinder_3d_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_3d_client();
        }

        return _instance;
    }

    fpi_error tos_3d_get_depth_of_field( int16_t* depth ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_get_depth_of_field here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (depth == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_get_depth_of_field,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (depth != NULL) {
                    int _depth_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _depth_rblob;
                    reply.readBlob(_depth_len,&_depth_rblob);
                    memcpy(depth,_depth_rblob.data(),_depth_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_get_depth_of_field error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_get_depth_of_field error");
        }

        return _result;
        /*-- add you code for tos_3d_get_depth_of_field here --*/
    }

    fpi_error tos_3d_set_depth_of_field( int16_t depth, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_set_depth_of_field here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(depth);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_3d_set_depth_of_field,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_set_depth_of_field error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_set_depth_of_field error");
        }

        return _result;
        /*-- add you code for tos_3d_set_depth_of_field here --*/
    }

    fpi_error tos_3d_get_3dto2d_mode( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_get_3dto2d_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_get_3dto2d_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_get_3dto2d_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_get_3dto2d_mode error");
        }

        return _result;
        /*-- add you code for tos_3d_get_3dto2d_mode here --*/
    }

    fpi_error tos_3d_set_3dto2d_mode( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_set_3dto2d_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_FPI_3D_VIDEO_DIAPLAY_FORMAT as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_3d_set_3dto2d_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_set_3dto2d_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_set_3dto2d_mode error");
        }

        return _result;
        /*-- add you code for tos_3d_set_3dto2d_mode here --*/
    }

    fpi_error tos_3d_get_display_format( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_get_display_format here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_3D_VIDEO_DIAPLAY_FORMAT));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_get_display_format,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_get_display_format error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_get_display_format error");
        }

        return _result;
        /*-- add you code for tos_3d_get_display_format here --*/
    }

    fpi_error tos_3d_set_display_format( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_set_display_format here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_FPI_3D_VIDEO_DIAPLAY_FORMAT as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_3d_set_display_format,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_set_display_format error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_set_display_format error");
        }

        return _result;
        /*-- add you code for tos_3d_set_display_format here --*/
    }

    fpi_error tos_3d_get_left_right_switch( int16_t* lrswitch ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_get_left_right_switch here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (lrswitch == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_get_left_right_switch,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (lrswitch != NULL) {
                    int _lrswitch_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _lrswitch_rblob;
                    reply.readBlob(_lrswitch_len,&_lrswitch_rblob);
                    memcpy(lrswitch,_lrswitch_rblob.data(),_lrswitch_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_get_left_right_switch error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_get_left_right_switch error");
        }

        return _result;
        /*-- add you code for tos_3d_get_left_right_switch here --*/
    }

    fpi_error tos_3d_set_left_right_switch( int16_t lrswitch, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_set_left_right_switch here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(lrswitch);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_3d_set_left_right_switch,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_set_left_right_switch error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_set_left_right_switch error");
        }

        return _result;
        /*-- add you code for tos_3d_set_left_right_switch here --*/
    }

    fpi_error tos_3d_is_framepacking_mode( int16_t* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_is_framepacking_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_is_framepacking_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_is_framepacking_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_is_framepacking_mode error");
        }

        return _result;
        /*-- add you code for tos_3d_is_framepacking_mode here --*/
    }

    fpi_error tos_3d_get_navigation( int16_t* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_get_navigation here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_3d_get_navigation,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_get_navigation error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_get_navigation error");
        }

        return _result;
        /*-- add you code for tos_3d_get_navigation here --*/
    }

    fpi_error tos_3d_set_navigation( int16_t mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_3d_set_navigation here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_3d_set_navigation,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_3d_set_navigation error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_3d_set_navigation error");
        }

        return _result;
        /*-- add you code for tos_3d_set_navigation here --*/
    }
};

sbinder_3d_client* sbinder_3d_client::_instance = NULL;

fpi_error tos_3d_get_depth_of_field( int16_t* depth ) {
    return sbinder_3d_client::Instance()->tos_3d_get_depth_of_field(depth);
}
fpi_error tos_3d_set_depth_of_field( int16_t depth, EN_ACT_CTRL act ) {
    return sbinder_3d_client::Instance()->tos_3d_set_depth_of_field(depth, act);
}
fpi_error tos_3d_get_3dto2d_mode( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode ) {
    return sbinder_3d_client::Instance()->tos_3d_get_3dto2d_mode(mode);
}
fpi_error tos_3d_set_3dto2d_mode( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode, EN_ACT_CTRL act ) {
    return sbinder_3d_client::Instance()->tos_3d_set_3dto2d_mode(mode, act);
}
fpi_error tos_3d_get_display_format( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT* mode ) {
    return sbinder_3d_client::Instance()->tos_3d_get_display_format(mode);
}
fpi_error tos_3d_set_display_format( EN_FPI_3D_VIDEO_DIAPLAY_FORMAT mode, EN_ACT_CTRL act ) {
    return sbinder_3d_client::Instance()->tos_3d_set_display_format(mode, act);
}
fpi_error tos_3d_get_left_right_switch( int16_t* lrswitch ) {
    return sbinder_3d_client::Instance()->tos_3d_get_left_right_switch(lrswitch);
}
fpi_error tos_3d_set_left_right_switch( int16_t lrswitch, EN_ACT_CTRL act ) {
    return sbinder_3d_client::Instance()->tos_3d_set_left_right_switch(lrswitch, act);
}
fpi_error tos_3d_is_framepacking_mode( int16_t* mode ) {
    return sbinder_3d_client::Instance()->tos_3d_is_framepacking_mode(mode);
}
fpi_error tos_3d_get_navigation( int16_t* mode ) {
    return sbinder_3d_client::Instance()->tos_3d_get_navigation(mode);
}
fpi_error tos_3d_set_navigation( int16_t mode, EN_ACT_CTRL act ) {
    return sbinder_3d_client::Instance()->tos_3d_set_navigation(mode, act);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
