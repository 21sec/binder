/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_hotel.sidl
 */
 

#define LOG_TAG     "sbinder_hotel"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_hotel.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_FACTORY);



#define SERVICE_DESCRIPTOR                      "5a772930-002f-11e5-b285-005056a84a3b"
#define SERVICE_NAME                            "sbinder_hotel"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_hotel_get_hotel_mode FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_hotel_set_hotel_mode FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_hotel_get_volume FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_hotel_set_volume FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_hotel_get_source FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_hotel_set_source FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_hotel_get_sound_mode FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_hotel_set_sound_mode FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_hotel_get_picture_mode FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_hotel_set_picture_mode FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_hotel_get_function_enable FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_hotel_set_function_enable FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_hotel_get_power_on_channel FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_hotel_set_power_on_channel FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_hotel_get_power_on_mode FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_hotel_set_power_on_mode FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_hotel_get_lock_state FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_hotel_set_lock_state FIRST_CALL_TRANSACTION + 18

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_hotel.h"

class sbinder_hotel_service : public BBinder  
{  
private:
    static sbinder_hotel_service* _instance;

    sbinder_hotel_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_hotel_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_hotel_service();
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

            case TRANSACTION_tos_hotel_get_hotel_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_hotel_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _b_enable_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* b_enable = NULL;

                Parcel::WritableBlob _b_enable_wblob;

                if(_b_enable_len > 0) {
                    reply->writeInt32(_b_enable_len);
                    reply->writeBlob(_b_enable_len,&_b_enable_wblob);
                    b_enable = (fpi_bool*)_b_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                b_enable = (fpi_bool*)_b_enable_wblob.data();
                fpi_error _result = tos_hotel_get_hotel_mode( b_enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_hotel_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_hotel_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_hotel_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool b_enable = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_hotel_mode( b_enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_hotel_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_VOLUME_TYPE e_type = (EN_TOS_VOLUME_TYPE)data.readInt32();  //EN_TOS_VOLUME_TYPE as input paramter

                int _ui2_volume_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* ui2_volume = NULL;

                Parcel::WritableBlob _ui2_volume_wblob;

                if(_ui2_volume_len > 0) {
                    reply->writeInt32(_ui2_volume_len);
                    reply->writeBlob(_ui2_volume_len,&_ui2_volume_wblob);
                    ui2_volume = (uint16_t*)_ui2_volume_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                ui2_volume = (uint16_t*)_ui2_volume_wblob.data();
                fpi_error _result = tos_hotel_get_volume( e_type, ui2_volume );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_volume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_volume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_VOLUME_TYPE e_type = (EN_TOS_VOLUME_TYPE)data.readInt32();  //EN_TOS_VOLUME_TYPE as input paramter

                uint16_t ui2_volume = (uint16_t)data.readInt32();  //uint16_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_volume( e_type, ui2_volume );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_volume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_source:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_source here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pe_source_len = data.readInt32(); //read length, only 32bits length support yet
                EN_API_SOURCE_INPUT* pe_source = NULL;

                Parcel::WritableBlob _pe_source_wblob;

                if(_pe_source_len > 0) {
                    reply->writeInt32(_pe_source_len);
                    reply->writeBlob(_pe_source_len,&_pe_source_wblob);
                    pe_source = (EN_API_SOURCE_INPUT*)_pe_source_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pe_source = (EN_API_SOURCE_INPUT*)_pe_source_wblob.data();
                fpi_error _result = tos_hotel_get_source( pe_source );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_source here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_source:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_source here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_API_SOURCE_INPUT e_source = (EN_API_SOURCE_INPUT)data.readInt32();  //EN_API_SOURCE_INPUT as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_source( e_source );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_source here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_sound_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_sound_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pe_snd_mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_HOTEL_SOUND_MODE* pe_snd_mode = NULL;

                Parcel::WritableBlob _pe_snd_mode_wblob;

                if(_pe_snd_mode_len > 0) {
                    reply->writeInt32(_pe_snd_mode_len);
                    reply->writeBlob(_pe_snd_mode_len,&_pe_snd_mode_wblob);
                    pe_snd_mode = (EN_TOS_HOTEL_SOUND_MODE*)_pe_snd_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pe_snd_mode = (EN_TOS_HOTEL_SOUND_MODE*)_pe_snd_mode_wblob.data();
                fpi_error _result = tos_hotel_get_sound_mode( pe_snd_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_sound_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_sound_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_sound_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_HOTEL_SOUND_MODE e_snd_mode = (EN_TOS_HOTEL_SOUND_MODE)data.readInt32();  //EN_TOS_SOUND_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_sound_mode( e_snd_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_sound_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_picture_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_picture_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pe_pic_mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_HOTEL_PICTURE_MODE* pe_pic_mode = NULL;

                Parcel::WritableBlob _pe_pic_mode_wblob;

                if(_pe_pic_mode_len > 0) {
                    reply->writeInt32(_pe_pic_mode_len);
                    reply->writeBlob(_pe_pic_mode_len,&_pe_pic_mode_wblob);
                    pe_pic_mode = (EN_TOS_HOTEL_PICTURE_MODE*)_pe_pic_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pe_pic_mode = (EN_TOS_HOTEL_PICTURE_MODE*)_pe_pic_mode_wblob.data();
                fpi_error _result = tos_hotel_get_picture_mode( pe_pic_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_picture_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_picture_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_picture_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_HOTEL_PICTURE_MODE e_pic_mode = (EN_TOS_HOTEL_PICTURE_MODE)data.readInt32();  //EN_FPI_PICTURE_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_picture_mode( e_pic_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_picture_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_function_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_function_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_FUNCTION_TYPE e_fun_type = (EN_TOS_FUNCTION_TYPE)data.readInt32();  //EN_TOS_FUNCTION_TYPE as input paramter

                int _b_enable_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* b_enable = NULL;

                Parcel::WritableBlob _b_enable_wblob;

                if(_b_enable_len > 0) {
                    reply->writeInt32(_b_enable_len);
                    reply->writeBlob(_b_enable_len,&_b_enable_wblob);
                    b_enable = (fpi_bool*)_b_enable_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                b_enable = (fpi_bool*)_b_enable_wblob.data();
                fpi_error _result = tos_hotel_get_function_enable( e_fun_type, b_enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_function_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_function_enable:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_function_enable here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_FUNCTION_TYPE e_fun_type = (EN_TOS_FUNCTION_TYPE)data.readInt32();  //EN_TOS_FUNCTION_TYPE as input paramter

                fpi_bool b_enable = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_function_enable( e_fun_type, b_enable );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_function_enable here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_power_on_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_power_on_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _i4_channel_len = data.readInt32(); //read length, only 32bits length support yet
                int32_t* i4_channel = NULL;

                Parcel::WritableBlob _i4_channel_wblob;

                if(_i4_channel_len > 0) {
                    reply->writeInt32(_i4_channel_len);
                    reply->writeBlob(_i4_channel_len,&_i4_channel_wblob);
                    i4_channel = (int32_t*)_i4_channel_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                i4_channel = (int32_t*)_i4_channel_wblob.data();
                fpi_error _result = tos_hotel_get_power_on_channel( i4_channel );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_power_on_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_power_on_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_power_on_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int32_t i4_channel = (int32_t)data.readInt32();  //int32_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_power_on_channel( i4_channel );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_power_on_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_power_on_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_power_on_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _e_power_mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_TOS_HOTEL_POWER_ON_MODE* e_power_mode = NULL;

                Parcel::WritableBlob _e_power_mode_wblob;

                if(_e_power_mode_len > 0) {
                    reply->writeInt32(_e_power_mode_len);
                    reply->writeBlob(_e_power_mode_len,&_e_power_mode_wblob);
                    e_power_mode = (EN_TOS_HOTEL_POWER_ON_MODE*)_e_power_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                e_power_mode = (EN_TOS_HOTEL_POWER_ON_MODE*)_e_power_mode_wblob.data();
                fpi_error _result = tos_hotel_get_power_on_mode( e_power_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_power_on_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_power_on_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_power_on_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_HOTEL_POWER_ON_MODE e_power_mode = (EN_TOS_HOTEL_POWER_ON_MODE)data.readInt32();  //EN_FAC_POWER_ON_MODE as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_power_on_mode( e_power_mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_power_on_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_get_lock_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_get_lock_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_LOCK_TYPE e_type = (EN_TOS_LOCK_TYPE)data.readInt32();  //EN_TOS_LOCK_TYPE as input paramter

                int _b_state_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* b_state = NULL;

                Parcel::WritableBlob _b_state_wblob;

                if(_b_state_len > 0) {
                    reply->writeInt32(_b_state_len);
                    reply->writeBlob(_b_state_len,&_b_state_wblob);
                    b_state = (fpi_bool*)_b_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                b_state = (fpi_bool*)_b_state_wblob.data();
                fpi_error _result = tos_hotel_get_lock_state( e_type, b_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_get_lock_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_hotel_set_lock_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_hotel_set_lock_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_TOS_LOCK_TYPE e_type = (EN_TOS_LOCK_TYPE)data.readInt32();  //EN_TOS_LOCK_TYPE as input paramter

                fpi_bool b_state = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_hotel_set_lock_state( e_type, b_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_hotel_set_lock_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_hotel_service_add() {
    sbinder_hotel_service::Instance();
    return 0;
}

sbinder_hotel_service* sbinder_hotel_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_hotel_client  
{  
private:
    static sbinder_hotel_client* _instance;
    sp<IBinder> _binder;

    sbinder_hotel_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_hotel_client() {
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
    static sbinder_hotel_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_hotel_client();
        }

        return _instance;
    }

    fpi_error tos_hotel_get_hotel_mode( fpi_bool* b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_hotel_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (b_enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_hotel_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (b_enable != NULL) {
                    int _b_enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _b_enable_rblob;
                    reply.readBlob(_b_enable_len,&_b_enable_rblob);
                    memcpy(b_enable,_b_enable_rblob.data(),_b_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_hotel_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_hotel_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_hotel_mode here --*/
    }

    fpi_error tos_hotel_set_hotel_mode( fpi_bool b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_hotel_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(b_enable);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_hotel_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_hotel_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_hotel_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_hotel_mode here --*/
    }

    fpi_error tos_hotel_get_volume( EN_TOS_VOLUME_TYPE e_type, uint16_t* ui2_volume ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_TOS_VOLUME_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ui2_volume == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (ui2_volume != NULL) {
                    int _ui2_volume_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _ui2_volume_rblob;
                    reply.readBlob(_ui2_volume_len,&_ui2_volume_rblob);
                    memcpy(ui2_volume,_ui2_volume_rblob.data(),_ui2_volume_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_volume error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_volume here --*/
    }

    fpi_error tos_hotel_set_volume( EN_TOS_VOLUME_TYPE e_type, uint16_t ui2_volume ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_volume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_TOS_VOLUME_TYPE as input paramter

            data.writeInt32(ui2_volume);  //uint16_t as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_volume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_volume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_volume error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_volume here --*/
    }

    fpi_error tos_hotel_get_source( EN_API_SOURCE_INPUT* pe_source ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_source here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pe_source == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_API_SOURCE_INPUT));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_source,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pe_source != NULL) {
                    int _pe_source_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pe_source_rblob;
                    reply.readBlob(_pe_source_len,&_pe_source_rblob);
                    memcpy(pe_source,_pe_source_rblob.data(),_pe_source_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_source error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_source error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_source here --*/
    }

    fpi_error tos_hotel_set_source( EN_API_SOURCE_INPUT e_source ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_source here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_source);  //EN_API_SOURCE_INPUT as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_source,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_source error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_source error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_source here --*/
    }

    fpi_error tos_hotel_get_sound_mode( EN_TOS_HOTEL_SOUND_MODE* pe_snd_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_sound_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pe_snd_mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_HOTEL_SOUND_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_sound_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pe_snd_mode != NULL) {
                    int _pe_snd_mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pe_snd_mode_rblob;
                    reply.readBlob(_pe_snd_mode_len,&_pe_snd_mode_rblob);
                    memcpy(pe_snd_mode,_pe_snd_mode_rblob.data(),_pe_snd_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_sound_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_sound_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_sound_mode here --*/
    }

    fpi_error tos_hotel_set_sound_mode( EN_TOS_HOTEL_SOUND_MODE e_snd_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_sound_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_snd_mode);  //EN_TOS_SOUND_MODE as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_sound_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_sound_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_sound_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_sound_mode here --*/
    }

    fpi_error tos_hotel_get_picture_mode( EN_TOS_HOTEL_PICTURE_MODE* pe_pic_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_picture_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pe_pic_mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_HOTEL_PICTURE_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_picture_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pe_pic_mode != NULL) {
                    int _pe_pic_mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pe_pic_mode_rblob;
                    reply.readBlob(_pe_pic_mode_len,&_pe_pic_mode_rblob);
                    memcpy(pe_pic_mode,_pe_pic_mode_rblob.data(),_pe_pic_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_picture_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_picture_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_picture_mode here --*/
    }

    fpi_error tos_hotel_set_picture_mode( EN_TOS_HOTEL_PICTURE_MODE e_pic_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_picture_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_pic_mode);  //EN_FPI_PICTURE_MODE as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_picture_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_picture_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_picture_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_picture_mode here --*/
    }

    fpi_error tos_hotel_get_function_enable( EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool* b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_function_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_fun_type);  //EN_TOS_FUNCTION_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (b_enable == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_function_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (b_enable != NULL) {
                    int _b_enable_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _b_enable_rblob;
                    reply.readBlob(_b_enable_len,&_b_enable_rblob);
                    memcpy(b_enable,_b_enable_rblob.data(),_b_enable_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_function_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_function_enable error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_function_enable here --*/
    }

    fpi_error tos_hotel_set_function_enable( EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool b_enable ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_function_enable here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_fun_type);  //EN_TOS_FUNCTION_TYPE as input paramter

            data.writeInt32(b_enable);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_function_enable,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_function_enable error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_function_enable error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_function_enable here --*/
    }

    fpi_error tos_hotel_get_power_on_channel( int32_t* i4_channel ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_power_on_channel here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (i4_channel == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_power_on_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (i4_channel != NULL) {
                    int _i4_channel_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _i4_channel_rblob;
                    reply.readBlob(_i4_channel_len,&_i4_channel_rblob);
                    memcpy(i4_channel,_i4_channel_rblob.data(),_i4_channel_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_power_on_channel error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_power_on_channel error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_power_on_channel here --*/
    }

    fpi_error tos_hotel_set_power_on_channel( int32_t i4_channel ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_power_on_channel here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(i4_channel);  //int32_t as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_power_on_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_power_on_channel error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_power_on_channel error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_power_on_channel here --*/
    }

    fpi_error tos_hotel_get_power_on_mode( EN_TOS_HOTEL_POWER_ON_MODE* e_power_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_power_on_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (e_power_mode == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_TOS_HOTEL_POWER_ON_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_power_on_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (e_power_mode != NULL) {
                    int _e_power_mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _e_power_mode_rblob;
                    reply.readBlob(_e_power_mode_len,&_e_power_mode_rblob);
                    memcpy(e_power_mode,_e_power_mode_rblob.data(),_e_power_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_power_on_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_power_on_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_power_on_mode here --*/
    }

    fpi_error tos_hotel_set_power_on_mode( EN_TOS_HOTEL_POWER_ON_MODE e_power_mode ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_power_on_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_power_mode);  //EN_FAC_POWER_ON_MODE as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_power_on_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_power_on_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_power_on_mode error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_power_on_mode here --*/
    }

    fpi_error tos_hotel_get_lock_state( EN_TOS_LOCK_TYPE e_type, fpi_bool* b_state ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_get_lock_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_TOS_LOCK_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (b_state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_hotel_get_lock_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (b_state != NULL) {
                    int _b_state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _b_state_rblob;
                    reply.readBlob(_b_state_len,&_b_state_rblob);
                    memcpy(b_state,_b_state_rblob.data(),_b_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_get_lock_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_get_lock_state error");
        }

        return _result;
        /*-- add you code for tos_hotel_get_lock_state here --*/
    }

    fpi_error tos_hotel_set_lock_state( EN_TOS_LOCK_TYPE e_type, fpi_bool b_state ) {
        Parcel data, reply;

        /*-- add you code for tos_hotel_set_lock_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(e_type);  //EN_TOS_LOCK_TYPE as input paramter

            data.writeInt32(b_state);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_hotel_set_lock_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_hotel_set_lock_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_hotel_set_lock_state error");
        }

        return _result;
        /*-- add you code for tos_hotel_set_lock_state here --*/
    }
};

sbinder_hotel_client* sbinder_hotel_client::_instance = NULL;

fpi_error tos_hotel_get_hotel_mode( fpi_bool* b_enable ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_hotel_mode(b_enable);
}
fpi_error tos_hotel_set_hotel_mode( fpi_bool b_enable ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_hotel_mode(b_enable);
}
fpi_error tos_hotel_get_volume( EN_TOS_VOLUME_TYPE e_type, uint16_t* ui2_volume ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_volume(e_type, ui2_volume);
}
fpi_error tos_hotel_set_volume( EN_TOS_VOLUME_TYPE e_type, uint16_t ui2_volume ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_volume(e_type, ui2_volume);
}
fpi_error tos_hotel_get_source( EN_API_SOURCE_INPUT* pe_source ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_source(pe_source);
}
fpi_error tos_hotel_set_source( EN_API_SOURCE_INPUT e_source ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_source(e_source);
}
fpi_error tos_hotel_get_sound_mode( EN_TOS_HOTEL_SOUND_MODE* pe_snd_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_sound_mode(pe_snd_mode);
}
fpi_error tos_hotel_set_sound_mode( EN_TOS_HOTEL_SOUND_MODE e_snd_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_sound_mode(e_snd_mode);
}
fpi_error tos_hotel_get_picture_mode( EN_TOS_HOTEL_PICTURE_MODE* pe_pic_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_picture_mode(pe_pic_mode);
}
fpi_error tos_hotel_set_picture_mode( EN_TOS_HOTEL_PICTURE_MODE e_pic_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_picture_mode(e_pic_mode);
}
fpi_error tos_hotel_get_function_enable( EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool* b_enable ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_function_enable(e_fun_type, b_enable);
}
fpi_error tos_hotel_set_function_enable( EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool b_enable ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_function_enable(e_fun_type, b_enable);
}
fpi_error tos_hotel_get_power_on_channel( int32_t* i4_channel ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_power_on_channel(i4_channel);
}
fpi_error tos_hotel_set_power_on_channel( int32_t i4_channel ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_power_on_channel(i4_channel);
}
fpi_error tos_hotel_get_power_on_mode( EN_TOS_HOTEL_POWER_ON_MODE* e_power_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_power_on_mode(e_power_mode);
}
fpi_error tos_hotel_set_power_on_mode( EN_TOS_HOTEL_POWER_ON_MODE e_power_mode ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_power_on_mode(e_power_mode);
}
fpi_error tos_hotel_get_lock_state( EN_TOS_LOCK_TYPE e_type, fpi_bool* b_state ) {
    return sbinder_hotel_client::Instance()->tos_hotel_get_lock_state(e_type, b_state);
}
fpi_error tos_hotel_set_lock_state( EN_TOS_LOCK_TYPE e_type, fpi_bool b_state ) {
    return sbinder_hotel_client::Instance()->tos_hotel_set_lock_state(e_type, b_state);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
