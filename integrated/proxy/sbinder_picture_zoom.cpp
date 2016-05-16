/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_picture_zoom.sidl
 */
 

#define LOG_TAG     "sbinder_picture_zoom"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_picture_zoom.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_ZOOM);


#define SERVICE_DESCRIPTOR                      "eb191148-c3b1-11e4-aff2-005056a84a3b"
#define SERVICE_NAME                            "sbinder_picture_zoom"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_zoom_set_size FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_zoom_get_size FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_zoom_set_appear FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_zoom_get_appear FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_zoom_get_video_zoom FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_zoom_get_current_window FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_zoom_set_scale_window FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_zoom_get_small_window_state FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_zoom_get_window FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_zoom_set_crop_window FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_zoom_set_display_window FIRST_CALL_TRANSACTION + 11



using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_picture_zoom.h"

class sbinder_picture_zoom_service : public BBinder  
{  
private:
    static sbinder_picture_zoom_service* _instance;

    sbinder_picture_zoom_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_picture_zoom_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_picture_zoom_service();
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

            case TRANSACTION_tos_zoom_set_size:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_set_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_video_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                EN_FPI_PIC_SIZE e_picture_mode = (EN_FPI_PIC_SIZE)data.readInt32();  //EN_FPI_PIC_SIZE as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_zoom_set_size( e_video_mode, e_picture_mode, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_set_size here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_get_size:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_MODE e_video_mode = (EN_VIDEO_MODE)data.readInt32();  //EN_VIDEO_MODE as input paramter

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PIC_SIZE* value = NULL;
                if(_value_len > 0) {
                    reply->writeInt32(_value_len);
                    Parcel::WritableBlob _value_wblob;
                    reply->writeBlob(_value_len,&_value_wblob);
                    value = (EN_FPI_PIC_SIZE*)_value_wblob.data();
                }

                fpi_error _result = tos_zoom_get_size( e_video_mode, value );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_size here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_set_appear:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_set_appear here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_APPEAR_TYPE e_type = (EN_VIDEO_APPEAR_TYPE)data.readInt32();  //EN_VIDEO_APPEAR_TYPE as input paramter

                int16_t enable = (int16_t)data.readInt32();  //int16_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_zoom_set_appear( e_type, enable, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_set_appear here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_get_appear:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_appear here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_VIDEO_APPEAR_TYPE e_type = (EN_VIDEO_APPEAR_TYPE)data.readInt32();  //EN_VIDEO_APPEAR_TYPE as input paramter

                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    Parcel::WritableBlob _enable_wblob;
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                fpi_error _result = tos_zoom_get_appear( e_type, enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_appear here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_get_video_zoom:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_video_zoom here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_PIC_SIZE pic_size = (EN_FPI_PIC_SIZE)data.readInt32();  //EN_FPI_PIC_SIZE as input paramter

                int _enable_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* enable = NULL;
                if(_enable_len > 0) {
                    reply->writeInt32(_enable_len);
                    Parcel::WritableBlob _enable_wblob;
                    reply->writeBlob(_enable_len,&_enable_wblob);
                    enable = (int16_t*)_enable_wblob.data();
                }

                fpi_error _result ;
				if(enable !=NULL ){
					_result= tos_zoom_get_video_zoom( pic_size, enable );
					}
				else{
					_result = FPI_ERROR_FAIL ;
					}

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_video_zoom here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_get_current_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_current_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _start_x_len = data.readInt32(); //read length, only 32bits length support yet
                Parcel::WritableBlob _start_x_wblob;
				Parcel::WritableBlob _start_y_wblob;
				Parcel::WritableBlob _width_wblob;
				Parcel::WritableBlob _height_wblob;
                int32_t* start_x = NULL;
                if(_start_x_len > 0) {
                    reply->writeInt32(_start_x_len);
                    //Parcel::WritableBlob _start_x_wblob;
                    reply->writeBlob(_start_x_len,&_start_x_wblob);
                    //start_x = (int32_t*)_start_x_wblob.data();
                }

                int _start_y_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* start_y = NULL;
                if(_start_y_len > 0) {
                    reply->writeInt32(_start_y_len);
                    //Parcel::WritableBlob _start_y_wblob;
                    reply->writeBlob(_start_y_len,&_start_y_wblob);
                    //start_y = (int32_t*)_start_y_wblob.data();
                }

                int _width_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* width = NULL;
                if(_width_len > 0) {
                    reply->writeInt32(_width_len);
                    //Parcel::WritableBlob _width_wblob;
                    reply->writeBlob(_width_len,&_width_wblob);
                    //width = (int32_t*)_width_wblob.data();
                }

                int _height_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* height = NULL;
                if(_height_len > 0) {
                    reply->writeInt32(_height_len);
                    //Parcel::WritableBlob _height_wblob;
                    reply->writeBlob(_height_len,&_height_wblob);
                    //height = (int32_t*)_height_wblob.data();
                }

				start_x = (int32_t*)_start_x_wblob.data();
				start_y = (int32_t*)_start_y_wblob.data();
				width = (int32_t*)_width_wblob.data();
				height = (int32_t*)_height_wblob.data();
				
                fpi_error _result = tos_zoom_get_current_window( start_x, start_y, width, height );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_current_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_set_scale_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_set_scale_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t x = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t y = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t width = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t height = (int32_t)data.readInt32();  //int32_t as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                fpi_error _result = tos_zoom_set_scale_window( x, y, width, height, act );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_set_scale_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_zoom_get_small_window_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_small_window_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _state_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* state = NULL;
                if(_state_len > 0) {
                    reply->writeInt32(_state_len);
                    Parcel::WritableBlob _state_wblob;
                    reply->writeBlob(_state_len,&_state_wblob);
                    state = (int16_t*)_state_wblob.data();
                }

                fpi_error _result ;
				if(state != NULL ){
					_result = tos_zoom_get_small_window_state( state );
					}else{
					_result = FPI_ERROR_FAIL; }

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_small_window_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_zoom_get_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_get_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_ZOOM_WINDOW_TYPE mode = (EN_ZOOM_WINDOW_TYPE)data.readInt32();  //EN_ZOOM_WINDOW_TYPE as input paramter

           // #error not support this type of paramter st_tos_zoom_window pstWindow yet, please add code yourself
			    int _pin_len = data.readInt32(); //read length, only 32bits length support yet
			st_tos_zoom_window* pstZoomWindow = NULL;

			
            Parcel::WritableBlob _Info_wblob;
			if(_pin_len > 0) {
		                reply->writeInt32(_pin_len);
                    reply->writeBlob(_pin_len,&_Info_wblob);
                    pstZoomWindow = (st_tos_zoom_window*)_Info_wblob.data();
			  }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_zoom_get_window( mode, pstZoomWindow );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_get_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			case TRANSACTION_tos_zoom_set_crop_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_set_scale_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t un32_windowId = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_hposition = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_vposition = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_hsize = (int32_t)data.readInt32();  //int32_t as input paramter

				int32_t un32_vsize = (int32_t)data.readInt32();
				
                fpi_error _result = tos_zoom_set_crop_window( un32_windowId, un32_hposition, un32_vposition, un32_hsize, un32_vsize );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_set_crop_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			case TRANSACTION_tos_zoom_set_display_window:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_zoom_set_scale_window here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                
                int32_t un32_windowId = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_hposition = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_vposition = (int32_t)data.readInt32();  //int32_t as input paramter

                int32_t un32_hsize = (int32_t)data.readInt32();  //int32_t as input paramter

				int32_t un32_vsize = (int32_t)data.readInt32();
				
                fpi_error _result = tos_zoom_set_display_window( un32_windowId, un32_hposition, un32_vposition, un32_hsize, un32_vsize );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_zoom_set_display_window here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_picture_zoom_service_add() {
    sbinder_picture_zoom_service::Instance();
    return 0;
}

sbinder_picture_zoom_service* sbinder_picture_zoom_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_picture_zoom_client  
{  
private:
    static sbinder_picture_zoom_client* _instance;
    sp<IBinder> _binder;

    sbinder_picture_zoom_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_picture_zoom_client() {
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
    static sbinder_picture_zoom_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_picture_zoom_client();
        }

        return _instance;
    }

    fpi_error tos_zoom_set_size( EN_VIDEO_MODE e_video_mode, EN_FPI_PIC_SIZE e_picture_mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_set_size here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_video_mode);  //EN_VIDEO_MODE as input paramter

            data.writeInt32(e_picture_mode);  //EN_FPI_PIC_SIZE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_zoom_set_size,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_set_size error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_set_size error");
        }

        return _result;
        /*-- add you code for tos_zoom_set_size here --*/
    }

    fpi_error tos_zoom_get_size( EN_VIDEO_MODE e_video_mode, EN_FPI_PIC_SIZE* value ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_size here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_video_mode);  //EN_VIDEO_MODE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_PIC_SIZE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_zoom_get_size,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_get_size error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_get_size error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_size here --*/
    }

    fpi_error tos_zoom_set_appear( EN_VIDEO_APPEAR_TYPE e_type, int16_t enable, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_set_appear here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }
		
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_VIDEO_APPEAR_TYPE as input paramter

            data.writeInt32(enable);  //int16_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_zoom_set_appear,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_set_appear error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_set_appear error");
        }

        return _result;
        /*-- add you code for tos_zoom_set_appear here --*/
    }

    fpi_error tos_zoom_get_appear( EN_VIDEO_APPEAR_TYPE e_type, int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_appear here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_VIDEO_APPEAR_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_zoom_get_appear,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_get_appear error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_get_appear error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_appear here --*/
    }

    fpi_error tos_zoom_get_video_zoom( EN_FPI_PIC_SIZE pic_size, int16_t* enable ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_video_zoom here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(pic_size);  //EN_FPI_PIC_SIZE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_zoom_get_video_zoom,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enable != NULL) {
                    int _enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enable_rblob;
                    reply.readBlob(_enable_len,&_enable_rblob);
                    memcpy(enable,_enable_rblob.data(),_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_get_video_zoom error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_get_video_zoom error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_video_zoom here --*/
    }

    fpi_error tos_zoom_get_current_window( int32_t* start_x, int32_t* start_y, int32_t* width, int32_t* height ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_current_window here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (start_x == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (start_y == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (width == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            //for out only, only write length ; for in, alloc and copy
            if (height == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_zoom_get_current_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (start_x != NULL) {
                    int _start_x_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _start_x_rblob;
                    reply.readBlob(_start_x_len,&_start_x_rblob);
                    memcpy(start_x,_start_x_rblob.data(),_start_x_len);
                }
                if (start_y != NULL) {
                    int _start_y_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _start_y_rblob;
                    reply.readBlob(_start_y_len,&_start_y_rblob);
                    memcpy(start_y,_start_y_rblob.data(),_start_y_len);
                }
                if (width != NULL) {
                    int _width_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _width_rblob;
                    reply.readBlob(_width_len,&_width_rblob);
                    memcpy(width,_width_rblob.data(),_width_len);
                }
                if (height != NULL) {
                    int _height_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _height_rblob;
                    reply.readBlob(_height_len,&_height_rblob);
                    memcpy(height,_height_rblob.data(),_height_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_get_current_window error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_get_current_window error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_current_window here --*/
    }

    fpi_error tos_zoom_set_scale_window( int32_t x, int32_t y, int32_t width, int32_t height, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_set_scale_window here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(x);  //int32_t as input paramter

            data.writeInt32(y);  //int32_t as input paramter

            data.writeInt32(width);  //int32_t as input paramter

            data.writeInt32(height);  //int32_t as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_zoom_set_scale_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_set_scale_window error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_set_scale_window error");
        }

        return _result;
        /*-- add you code for tos_zoom_set_scale_window here --*/
    }

    fpi_error tos_zoom_get_small_window_state( int16_t* state ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_small_window_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_zoom_get_small_window_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (state != NULL) {
                    int _state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _state_rblob;
                    reply.readBlob(_state_len,&_state_rblob);
                    memcpy(state,_state_rblob.data(),_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_get_small_window_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_get_small_window_state error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_small_window_state here --*/
    }
    fpi_error tos_zoom_get_window( EN_ZOOM_WINDOW_TYPE mode, st_tos_zoom_window* pstWindow ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_get_window here --*/
        fpi_error _result= FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_ZOOM_WINDOW_TYPE as input paramter
            if (pstWindow == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(st_tos_zoom_window));//write length, only support 32 bits length yet
                
            }

         //   #error not support this type of paramter st_tos_zoom_window pstWindow yet, please add code yourself

            _binder->transact(TRANSACTION_tos_zoom_get_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				if (pstWindow != NULL) {
					   int _pstWindow_len = reply.readInt32(); //read length, only 32bits length support yet
					   Parcel::ReadableBlob _pstWindow_rblob;
					   reply.readBlob(_pstWindow_len,&_pstWindow_rblob);
					   memcpy(pstWindow,_pstWindow_rblob.data(),_pstWindow_len);
				   }
				
                //#error not support this type of output paramter st_tos_zoom_window pstWindow yet, please add code yourself
				//data.writeInt32((int)(1) * sizeof(st_tos_zoom_window));//write length, only support 32 bits length yet
				//Parcel::WritableBlob _pin_wblob;
				//data.writeBlob((1) * sizeof(st_tos_zoom_window),&_pin_wblob);
				//memcpy(_pin_wblob.data(),pstWindow,(1)* sizeof(st_fpi_zoom_window));
              
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_zoom_get_window error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_zoom_get_window error");
        }

        return _result;
        /*-- add you code for tos_zoom_get_window here --*/
    }

	fpi_error tos_zoom_set_crop_window( uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_set_crop_window here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un32_windowId);  //int32_t as input paramter

            data.writeInt32(un32_hposition);  //int32_t as input paramter

            data.writeInt32(un32_vposition);  //int32_t as input paramter

            data.writeInt32(un32_hsize);  //int32_t as input paramter

            data.writeInt32(un32_vsize);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_zoom_set_crop_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_set_crop_window error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_set_crop_window error");
        }

        return _result;
        /*-- add you code for tos_zoom_set_crop_window here --*/
    }

	fpi_error tos_zoom_set_display_window( uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize ) {
        Parcel data, reply;

        /*-- add you code for tos_zoom_set_display_window here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(un32_windowId);  //int32_t as input paramter

            data.writeInt32(un32_hposition);  //int32_t as input paramter

            data.writeInt32(un32_vposition);  //int32_t as input paramter

            data.writeInt32(un32_hsize);  //int32_t as input paramter

            data.writeInt32(un32_vsize);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_zoom_set_display_window,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_zoom_set_display_window error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_zoom_set_display_window error");
        }

        return _result;
        /*-- add you code for tos_zoom_set_display_window here --*/
    }
};

sbinder_picture_zoom_client* sbinder_picture_zoom_client::_instance = NULL;

fpi_error tos_zoom_set_size( EN_VIDEO_MODE e_video_mode, EN_FPI_PIC_SIZE e_picture_mode, EN_ACT_CTRL act ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_set_size(e_video_mode, e_picture_mode, act);
}
fpi_error tos_zoom_get_size( EN_VIDEO_MODE e_video_mode, EN_FPI_PIC_SIZE* value ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_size(e_video_mode, value);
}
fpi_error tos_zoom_set_appear( EN_VIDEO_APPEAR_TYPE e_type, int16_t enable, EN_ACT_CTRL act ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_set_appear(e_type, enable, act);
}
fpi_error tos_zoom_get_appear( EN_VIDEO_APPEAR_TYPE e_type, int16_t* enable ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_appear(e_type, enable);
}
fpi_error tos_zoom_get_video_zoom( EN_FPI_PIC_SIZE pic_size, int16_t* enable ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_video_zoom(pic_size, enable);
}
fpi_error tos_zoom_get_current_window( int32_t* start_x, int32_t* start_y, int32_t* width, int32_t* height ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_current_window(start_x, start_y, width, height);
}
fpi_error tos_zoom_set_scale_window( int32_t x, int32_t y, int32_t width, int32_t height, EN_ACT_CTRL act ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_set_scale_window(x, y, width, height, act);
}
fpi_error tos_zoom_get_small_window_state( int16_t* state ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_small_window_state(state);
}
fpi_error tos_zoom_get_window( EN_ZOOM_WINDOW_TYPE mode, st_tos_zoom_window* pstWindow ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_get_window(mode, pstWindow);
}
fpi_error tos_zoom_set_crop_window( uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_set_crop_window(un32_windowId, un32_hposition, un32_vposition, un32_hsize, un32_vsize);
}
fpi_error tos_zoom_set_display_window( uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize ) {
    return sbinder_picture_zoom_client::Instance()->tos_zoom_set_display_window(un32_windowId, un32_hposition, un32_vposition, un32_hsize, un32_vsize);
}


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
