/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_video_module.sidl
 */
 

#define LOG_TAG     "remote_itv_video_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_video.h"
#include "itv_defines.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "df206f34-1335-11e5-a610-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_video_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_video_open FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_video_close FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_video_start FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_video_stop FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_video_pause FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_itv_video_resume FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_itv_video_clear FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_itv_video_get_pts FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_itv_video_get_frame_num FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_itv_video_set_visible FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_itv_video_set_rect FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_itv_video_set_aspect FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_itv_video_set_trickmode FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_itv_video_set_fullview FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_itv_video_get_resolution FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_itv_video_set_source_type FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_itv_video_set_blank_when_nodata FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_itv_video_set_sync FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_itv_video_set_mute_color FIRST_CALL_TRANSACTION + 19



using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG "remote_itv_video_module"

#include <stdlib.h>

#include "clog.h"
#include "remote_itv_video_module.h"

class remote_itv_video_module_service : public BBinder  
{  
private:
    static remote_itv_video_module_service* _instance;

    remote_itv_video_module_service(){
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_video_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_video_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            // TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        // TOSLOGI(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_video_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _handle_len = data.readInt32(); //read length, only 32bits length support yet
                itv_handle_t* handle = NULL;

                Parcel::WritableBlob _handle_wblob;

                if(_handle_len > 0) {
                    reply->writeInt32(_handle_len);
                    reply->writeBlob(_handle_len,&_handle_wblob);
                    handle = (itv_handle_t*)_handle_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                handle = (itv_handle_t*)_handle_wblob.data();
                int _result = itv_video_open( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_close( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                itv_video_start_param_t _param_Struct;
				memset(&_param_Struct, 0, sizeof(itv_video_start_param_t));
				
				const itv_video_start_param_t* param = NULL;
				int _flag = data.readInt32();
				if(_flag > 0) {
					_param_Struct.demuxId = data.readInt32();
					_param_Struct.vType = (itv_video_stream_type_t)data.readInt32();
					param = &_param_Struct;
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_start( handle, param );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter
				
				itv_video_stop_mode_t stopMode = (itv_video_stop_mode_t)data.readInt32();	// itv_video_stop_mode_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_stop( handle, stopMode );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_pause( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_resume( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_resume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_clear:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_clear here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_clear( handle );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_clear here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_get_pts:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_get_pts here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _pts_len = data.readInt32(); //read length, only 32bits length support yet
                unsigned long long* pts = NULL;

                Parcel::WritableBlob _pts_wblob;

                if(_pts_len > 0) {
                    reply->writeInt32(_pts_len);
                    reply->writeBlob(_pts_len,&_pts_wblob);
                    pts = (unsigned long long*)_pts_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pts = (unsigned long long*)_pts_wblob.data();
                int _result = itv_video_get_pts( handle, pts );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_get_pts here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_get_frame_num:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_get_frame_num here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _flag = data.readInt32(); //read length, only 32bits length support yet
                unsigned int _num = 0;
                unsigned int* num = (_flag > 0) ? &_num : NULL;

                int _result = itv_video_get_frame_num( handle, num );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0) {
                    reply->writeInt32(*num); //int as return value
                }

                //-- end code for itv_video_get_frame_num here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_set_visible:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_visible here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_bool_t visible = (itv_bool_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_visible( handle, visible );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_visible here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_set_rect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_rect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_video_rect_t _param_Struct;
				memset(&_param_Struct, 0, sizeof(itv_video_rect_t));
				
				const itv_video_rect_t* rect = NULL;
				int _flag = data.readInt32();
				if(_flag > 0) {
					_param_Struct.x = data.readInt32();
					_param_Struct.y = data.readInt32();
					_param_Struct.width = data.readInt32();
					_param_Struct.height = data.readInt32();
					rect = &_param_Struct;
				}

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_rect( handle, rect );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_rect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_set_aspect:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_aspect here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_video_aspect_mode_t aspect = (itv_video_aspect_mode_t)data.readInt32(); 

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_aspect( handle, aspect );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_aspect here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_set_trickmode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_trickmode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_bool_t mode = (itv_bool_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_trickmode( handle, mode );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_trickmode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_set_fullview:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_fullview here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                itv_video_fullview_type_t type = (itv_video_fullview_type_t)data.readInt32();  //itv_video_fullview_type_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_fullview( handle, type );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_fullview here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_video_get_resolution:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_get_resolution here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _width_flag = data.readInt32(); //read length, only 32bits length support yet
                unsigned int _width = 0;
                unsigned int* pWidth = (_width_flag > 0) ? &_width : NULL;

                int _height_flag = data.readInt32(); //read length, only 32bits length support yet
                unsigned int _height = 0;
                unsigned int* pHeight = (_height_flag > 0) ? &_height : NULL;
				
                int _result = itv_video_get_resolution( pWidth, pHeight );
				
				if(_width_flag > 0) {
                    reply->writeInt32(*pWidth); //unsigned int as return value
                }
				if(_height_flag > 0) {
                    reply->writeInt32(*pHeight); //unsigned int as return value
                }
                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_get_resolution here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_itv_video_set_source_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_audio_set_channel_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				
				itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_video_source_type_t source_type = (itv_video_source_type_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_source_type(handle, source_type );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_audio_set_channel_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;

            } break;   
			case TRANSACTION_itv_video_set_blank_when_nodata:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                reply->writeNoException();


                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				itv_bool_t isBlank = (itv_bool_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_blank_when_nodata( handle, isBlank );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_visible here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			case TRANSACTION_itv_video_set_sync:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_video_set_sync here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter
				itv_av_sync_mode_t mode = (itv_av_sync_mode_t)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_sync( handle, mode );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_sync here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			case TRANSACTION_itv_video_set_mute_color:
			{
				data.enforceInterface(String16(SERVICE_NAME));  //fixed check
                reply->writeNoException();


                unsigned char red = (unsigned char)data.readInt32();  

				unsigned char green = (unsigned char)data.readInt32();

				unsigned char blue = (unsigned char)data.readInt32();

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_video_set_mute_color( red, green, blue );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_video_set_mute_color here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
			}break;
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        // TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_video_module_service_add() {
    remote_itv_video_module_service::Instance();
    return 0;
}

remote_itv_video_module_service* remote_itv_video_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG "remote_itv_video_module"

#include "clog.h"

class remote_itv_video_module_client  
{  
private:
    static remote_itv_video_module_client* _instance;
    sp<IBinder> _binder;

    remote_itv_video_module_client()
        :_binder(NULL) {
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_video_module_client() {
        // TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            // TOSLOGW(SERVICE_NAME"_client getFailed!\n\n");
        }

        return (_binder != NULL);
    }

public:  
    static remote_itv_video_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_video_module_client();
        }

        return _instance;
    }

    int itv_video_open( itv_handle_t* handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_open()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_open here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (handle == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_handle_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_itv_video_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (handle != NULL) {
                    int _handle_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _handle_rblob;
                    reply.readBlob(_handle_len,&_handle_rblob);
                    memcpy(handle,_handle_rblob.data(),_handle_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_open error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_open error\n");
        }

        return _result;
        /*-- add you code for itv_video_open here --*/
    }

    int itv_video_close( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_close()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_close here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_video_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_close error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_close error\n");
        }

        return _result;
        /*-- add you code for itv_video_close here --*/
    }

    int itv_video_start( itv_handle_t handle, const itv_video_start_param_t* param ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_start()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_start here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            if (param == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_video_start_param_t));//write length, only support 32 bits length yet
				data.writeInt32(param->demuxId);
				data.writeInt32(param->vType);
            }

            _binder->transact(TRANSACTION_itv_video_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_start error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_start error\n");
        }

        return _result;
        /*-- add you code for itv_video_start here --*/
    }

    int itv_video_stop( itv_handle_t handle, itv_video_stop_mode_t stopMode ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_stop()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_stop here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter
			
			data.writeInt32(stopMode);  //itv_video_stop_mode_t as input paramter

            _binder->transact(TRANSACTION_itv_video_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_stop error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_stop error\n");
        }

        return _result;
        /*-- add you code for itv_video_stop here --*/
    }

    int itv_video_pause( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_pause()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_pause here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_video_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_pause error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_pause error\n");
        }

        return _result;
        /*-- add you code for itv_video_pause here --*/
    }

    int itv_video_resume( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_resume()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_resume here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_video_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_resume error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_resume error\n");
        }

        return _result;
        /*-- add you code for itv_video_resume here --*/
    }

    int itv_video_clear( itv_handle_t handle ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_clear()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_clear here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_video_clear,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_clear error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_clear error\n");
        }

        return _result;
        /*-- add you code for itv_video_clear here --*/
    }

    int itv_video_get_pts( itv_handle_t handle, unsigned long long* pts ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_get_pts()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_get_pts here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pts == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(unsigned long long));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_itv_video_get_pts,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pts != NULL) {
                    int _pts_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pts_rblob;
                    reply.readBlob(_pts_len,&_pts_rblob);
                    memcpy(pts,_pts_rblob.data(),_pts_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_get_pts error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_get_pts error\n");
        }

        return _result;
        /*-- add you code for itv_video_get_pts here --*/
    }

    int itv_video_get_frame_num( itv_handle_t handle, unsigned int* num ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_get_frame_num()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_get_frame_num here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (num == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((unsigned int)(1) * sizeof(unsigned int));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_video_get_frame_num,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            
                _result = (typeof(_result))reply.readInt32();//int as return value
                if (num != NULL) {
                    *num = (unsigned int)reply.readInt32(); //read length, only 32bits length support yet
                }

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_get_frame_num error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_get_frame_num error\n");
        }

        return _result;
        /*-- add you code for itv_video_get_frame_num here --*/
    }

    int itv_video_set_visible( itv_handle_t handle, itv_bool_t visible ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_visible()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_visible here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(visible); //itv_bool_t as input paramter

            _binder->transact(TRANSACTION_itv_video_set_visible,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_visible error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_visible error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_visible here --*/
    }

    int itv_video_set_rect( itv_handle_t handle, const itv_video_rect_t* rect ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_rect()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_rect here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            if (rect == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_video_rect_t));//write length, only support 32 bits length yet
                data.writeInt32(rect->x);
				data.writeInt32(rect->y);
				data.writeInt32(rect->width);
				data.writeInt32(rect->height);
				
            }

            _binder->transact(TRANSACTION_itv_video_set_rect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_rect error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_rect error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_rect here --*/
    }

    int itv_video_set_aspect( itv_handle_t handle, itv_video_aspect_mode_t aspect ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_aspect()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_aspect here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(aspect);  //itv_video_aspect_mode_t as input paramter

            _binder->transact(TRANSACTION_itv_video_set_aspect,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_aspect error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_aspect error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_aspect here --*/
    }

    int itv_video_set_trickmode( itv_handle_t handle, itv_bool_t mode ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_trickmode()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_trickmode here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(mode);  //itv_bool_t as input paramter

            _binder->transact(TRANSACTION_itv_video_set_trickmode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_trickmode error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_trickmode error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_trickmode here --*/
    }

    int itv_video_set_fullview( itv_handle_t handle, itv_video_fullview_type_t type ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_fullview()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_fullview here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(type);  //itv_video_fullview_type_t as input paramter

            _binder->transact(TRANSACTION_itv_video_set_fullview,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_fullview error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_fullview error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_fullview here --*/
    }

    int itv_video_get_resolution( unsigned int* pWidth, unsigned int* pHeight ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_get_resolution()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_get_resolution here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pWidth == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(unsigned int));//write length, only support 32 bits length yet
            }

            //for out only, only write length ; for in, alloc and copy
            if (pHeight == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(unsigned int));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_video_get_resolution,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                if (pWidth != NULL) {
                    *pWidth = (unsigned int)reply.readInt32(); //read length, only 32bits length support yet
                }
                if (pHeight != NULL) {
                    *pHeight = (unsigned int)reply.readInt32(); //read length, only 32bits length support yet
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_get_resolution error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_get_resolution error\n");
        }

        return _result;
        /*-- add you code for itv_video_get_resolution here --*/
    }

int itv_video_set_source_type( itv_handle_t handle, itv_video_source_type_t source_type ) {
	// TOSLOGI(SERVICE_NAME"_client itv_audio_set_channel_mode()\n");
	Parcel data, reply;

	/*-- add you code for itv_audio_set_channel_mode here --*/
	int _result = ITV_ERR_FAILED;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

		data.writeInt32(handle); 

		data.writeInt32(source_type); 

		_binder->transact(TRANSACTION_itv_video_set_source_type,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check

			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			// TOSLOGW(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
		}
	}catch(...) {
		// TOSLOGE(SERVICE_NAME"_client itv_audio_set_channel_mode error\n");
	}

	return _result;
	/*-- add you code for itv_audio_set_channel_mode here --*/
}

int itv_video_set_blank_when_nodata( itv_handle_t handle, itv_bool_t isBlank ) {

	Parcel data, reply;

	/*-- add you code for itv_video_set_visible here --*/
	int _result = ITV_ERR_FAILED;
	if(!getService()) {
		return _result;
	}

	try {
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

		data.writeInt32(handle);  //itv_handle_t as input paramter

		data.writeInt32(isBlank); //itv_bool_t as input paramter

		_binder->transact(TRANSACTION_itv_video_set_blank_when_nodata,data, &reply,0);

		if(reply.readExceptionCode() == 0) {//fix check

			_result = (typeof(_result))reply.readInt32();//int as return value

		} else {
			// TOSLOGW(SERVICE_NAME"_client itv_video_set_visible error\n");
		}
	}catch(...) {
		// TOSLOGE(SERVICE_NAME"_client itv_video_set_visible error\n");
	}

	return _result;
	/*-- add you code for itv_video_set_visible here --*/
}

int itv_video_set_sync( itv_handle_t handle, itv_av_sync_mode_t mode ) {
		// TOSLOGI(SERVICE_NAME"_client itv_video_set_sync()\n");
        Parcel data, reply;

        /*-- add you code for itv_video_set_sync here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            data.writeInt32(mode); 

            _binder->transact(TRANSACTION_itv_video_set_sync,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_video_set_sync error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_video_set_sync error\n");
        }

        return _result;
        /*-- add you code for itv_video_set_sync here --*/
    }

  int itv_video_set_mute_color(unsigned char red, unsigned char green, unsigned char blue) {
	  // TOSLOGI(SERVICE_NAME"_client itv_video_set_mute_color()\n");
	  Parcel data, reply;

	  /*-- add you code for itv_video_set_mute_color here --*/
	  int _result = ITV_ERR_FAILED;
	  if(!getService()) {
		  return _result;
	  }

	  try {
		  data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

		  data.writeInt32((int)red);	//itv_handle_t as input paramter

		  data.writeInt32((int)green); 
		  
		  data.writeInt32((int)blue); 

		  _binder->transact(TRANSACTION_itv_video_set_mute_color,data, &reply,0);

		  if(reply.readExceptionCode() == 0) {//fix check

			  _result = (typeof(_result))reply.readInt32();//int as return value

		  } else {
			  // TOSLOGW(SERVICE_NAME"_client itv_video_set_mute_color error\n");
		  }
	  }catch(...) {
		  // TOSLOGE(SERVICE_NAME"_client itv_video_set_mute_color error\n");
	  }

	  return _result;

  	}


};

remote_itv_video_module_client* remote_itv_video_module_client::_instance = NULL;

int itv_video_open( itv_handle_t* handle ) {
    return remote_itv_video_module_client::Instance()->itv_video_open(handle);
}
int itv_video_close( itv_handle_t handle ) {
    return remote_itv_video_module_client::Instance()->itv_video_close(handle);
}
int itv_video_start( itv_handle_t handle, const itv_video_start_param_t* param ) {
    return remote_itv_video_module_client::Instance()->itv_video_start(handle, param);
}
int itv_video_stop( itv_handle_t handle, itv_video_stop_mode_t stopMode ) {
    return remote_itv_video_module_client::Instance()->itv_video_stop(handle, stopMode);
}
int itv_video_pause( itv_handle_t handle ) {
    return remote_itv_video_module_client::Instance()->itv_video_pause(handle);
}
int itv_video_resume( itv_handle_t handle ) {
    return remote_itv_video_module_client::Instance()->itv_video_resume(handle);
}
int itv_video_clear( itv_handle_t handle ) {
    return remote_itv_video_module_client::Instance()->itv_video_clear(handle);
}
int itv_video_get_pts( itv_handle_t handle, unsigned long long* pts ) {
    return remote_itv_video_module_client::Instance()->itv_video_get_pts(handle, pts);
}
int itv_video_get_frame_num( itv_handle_t handle, unsigned int* num ) {
    return remote_itv_video_module_client::Instance()->itv_video_get_frame_num(handle, num);
}
int itv_video_set_visible( itv_handle_t handle, itv_bool_t visible ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_visible(handle, visible);
}
int itv_video_set_rect( itv_handle_t handle, const itv_video_rect_t* rect ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_rect(handle, rect);
}
int itv_video_set_aspect( itv_handle_t handle, itv_video_aspect_mode_t aspect ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_aspect(handle, aspect);
}
int itv_video_set_trickmode( itv_handle_t handle, itv_bool_t mode ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_trickmode(handle, mode);
}
int itv_video_set_fullview( itv_handle_t handle, itv_video_fullview_type_t type ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_fullview(handle, type);
}
int itv_video_get_resolution( unsigned int* pWidth, unsigned int* pHeight ) {
    return remote_itv_video_module_client::Instance()->itv_video_get_resolution(pWidth, pHeight);
}

int itv_video_set_source_type(itv_handle_t handle, itv_video_source_type_t source_type) {
    return remote_itv_video_module_client::Instance()->itv_video_set_source_type(handle, source_type);
}

int itv_video_set_blank_when_nodata( itv_handle_t handle, itv_bool_t isBlank ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_blank_when_nodata(handle, isBlank);
}

int itv_video_set_sync( itv_handle_t handle, itv_av_sync_mode_t mode ) {
    return remote_itv_video_module_client::Instance()->itv_video_set_sync(handle, mode);
}

int itv_video_set_mute_color(unsigned char red, unsigned char green, unsigned char blue) {
	return remote_itv_video_module_client::Instance()->itv_video_set_mute_color(red, green, blue);
}


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
