/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_subtitle.sidl
 */
 

#define LOG_TAG     "sbinder_subtitle"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#include "tos_subtitle.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_SUBTITLE);


#define SERVICE_DESCRIPTOR                      "6833d8f6-d6aa-11e4-8c5f-005056a84a3b"
#define SERVICE_NAME                            "sbinder_subtitle"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_subtitle_get_info FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_subtitle_open FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_subtitle_set_visibility FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_subtitle_get_status FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_subtitle_set_status FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_subtitle_get_mode FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_subtitle_set_mode FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_subtitle_get_prefer_language FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_subtitle_set_prefer_language FIRST_CALL_TRANSACTION + 9

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_subtitle.h"

class sbinder_subtitle_service : public BBinder  
{  
private:
    static sbinder_subtitle_service* _instance;

    sbinder_subtitle_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_subtitle_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_subtitle_service();
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

            case TRANSACTION_tos_subtitle_get_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_get_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //#error not support un-plat struct sttInfo yet, please add code yourself
                int _pout_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_subtitle_info_t* sttInfo = NULL;
                if(_pout_len > 0) {
                    reply->writeInt32(_pout_len);
                    Parcel::WritableBlob _pout_wblob;
                    reply->writeBlob(_pout_len,&_pout_wblob);
                    sttInfo = (fpi_subtitle_info_t*)_pout_wblob.data();
                }
                fpi_error _result = tos_subtitle_get_info( sttInfo );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_get_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t index = (uint8_t)data.readInt32();  //uint8_t as input paramter

                fpi_error _result = tos_subtitle_open( index );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_set_visibility:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_set_visibility here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SUBTITLE_VISIBLE_LEVEL level = (EN_FPI_SUBTITLE_VISIBLE_LEVEL)data.readInt32();  //EN_FPI_SUBTITLE_VISIBLE_LEVEL as input paramter

                fpi_bool flag = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                fpi_error _result = tos_subtitle_set_visibility( level, flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_set_visibility here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_get_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_get_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _flag_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* flag = NULL;
                if(_flag_len > 0) {
                    reply->writeInt32(_flag_len);
                    Parcel::WritableBlob _flag_wblob;
                    reply->writeBlob(_flag_len,&_flag_wblob);
                    flag = (fpi_bool*)_flag_wblob.data();
                }

                fpi_error _result = tos_subtitle_get_status( flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_get_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_set_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_set_status here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_bool flag = (fpi_bool)data.readInt32();  //fpi_bool as input paramter

                fpi_error _result = tos_subtitle_set_status( flag );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_set_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_get_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_get_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_SUBTITLE_MODE* mode = NULL;
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    mode = (EN_FPI_SUBTITLE_MODE*)_mode_wblob.data();
                }

                fpi_error _result = tos_subtitle_get_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_get_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_set_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_set_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SUBTITLE_MODE mode = (EN_FPI_SUBTITLE_MODE)data.readInt32();  //EN_FPI_SUBTITLE_MODE as input paramter

                fpi_error _result = tos_subtitle_set_mode( mode );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_set_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_get_prefer_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_get_prefer_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SUBTITLE_PREFER_LANGUAGE type = (EN_FPI_SUBTITLE_PREFER_LANGUAGE)data.readInt32();  //EN_FPI_SUBTITLE_PREFER_LANGUAGE as input paramter

                int _language_len = data.readInt32(); //read length, only 32bits length support yet
                MEMBER_LANGUAGE* language = NULL;
                if(_language_len > 0) {
                    reply->writeInt32(_language_len);
                    Parcel::WritableBlob _language_wblob;
                    reply->writeBlob(_language_len,&_language_wblob);
                    language = (MEMBER_LANGUAGE*)_language_wblob.data();
                }

                fpi_error _result = tos_subtitle_get_prefer_language( type, language );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_get_prefer_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_subtitle_set_prefer_language:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_subtitle_set_prefer_language here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_SUBTITLE_PREFER_LANGUAGE type = (EN_FPI_SUBTITLE_PREFER_LANGUAGE)data.readInt32();  //EN_FPI_SUBTITLE_PREFER_LANGUAGE as input paramter

                MEMBER_LANGUAGE language = (MEMBER_LANGUAGE)data.readInt32();  //MEMBER_LANGUAGE as input paramter

                fpi_error _result = tos_subtitle_set_prefer_language( type, language );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_subtitle_set_prefer_language here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_subtitle_service_add() {
    sbinder_subtitle_service::Instance();
    return 0;
}

sbinder_subtitle_service* sbinder_subtitle_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_subtitle_client  
{  
private:
    static sbinder_subtitle_client* _instance;
    sp<IBinder> _binder;

    sbinder_subtitle_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_subtitle_client() {
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
    static sbinder_subtitle_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_subtitle_client();
        }

        return _instance;
    }

    fpi_error tos_subtitle_get_info( fpi_subtitle_info_t* sttInfo ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_get_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support un-plat struct sttInfo yet, please add code yourself
            data.writeInt32((int)(1) * sizeof(fpi_subtitle_info_t));

            _binder->transact(TRANSACTION_tos_subtitle_get_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (sttInfo != NULL) {
                    int _sttInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _sttInfo_rblob;
                    reply.readBlob(_sttInfo_len,&_sttInfo_rblob);
                    memcpy(sttInfo,_sttInfo_rblob.data(),_sttInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_get_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_get_info error");
        }

        return _result;
        /*-- add you code for tos_subtitle_get_info here --*/
    }

    fpi_error tos_subtitle_open( uint8_t index ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_open here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(index);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_subtitle_open,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_open error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_open error");
        }

        return _result;
        /*-- add you code for tos_subtitle_open here --*/
    }

    fpi_error tos_subtitle_set_visibility( EN_FPI_SUBTITLE_VISIBLE_LEVEL level, fpi_bool flag ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_set_visibility here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(level);  //EN_FPI_SUBTITLE_VISIBLE_LEVEL as input paramter

            data.writeInt32(flag);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_subtitle_set_visibility,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_set_visibility error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_set_visibility error");
        }

        return _result;
        /*-- add you code for tos_subtitle_set_visibility here --*/
    }

    fpi_error tos_subtitle_get_status( fpi_bool* flag ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_get_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (flag == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_subtitle_get_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (flag != NULL) {
                    int _flag_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _flag_rblob;
                    reply.readBlob(_flag_len,&_flag_rblob);
                    memcpy(flag,_flag_rblob.data(),_flag_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_get_status error");
        }

        return _result;
        /*-- add you code for tos_subtitle_get_status here --*/
    }

    fpi_error tos_subtitle_set_status( fpi_bool flag ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_set_status here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(flag);  //fpi_bool as input paramter

            _binder->transact(TRANSACTION_tos_subtitle_set_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_set_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_set_status error");
        }

        return _result;
        /*-- add you code for tos_subtitle_set_status here --*/
    }

    fpi_error tos_subtitle_get_mode( EN_FPI_SUBTITLE_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_get_mode here --*/
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
                data.writeInt32((int)(1) * sizeof(EN_FPI_SUBTITLE_MODE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_subtitle_get_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mode != NULL) {
                    int _mode_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mode_rblob;
                    reply.readBlob(_mode_len,&_mode_rblob);
                    memcpy(mode,_mode_rblob.data(),_mode_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_get_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_get_mode error");
        }

        return _result;
        /*-- add you code for tos_subtitle_get_mode here --*/
    }

    fpi_error tos_subtitle_set_mode( EN_FPI_SUBTITLE_MODE mode ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_set_mode here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_FPI_SUBTITLE_MODE as input paramter

            _binder->transact(TRANSACTION_tos_subtitle_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_set_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_set_mode error");
        }

        return _result;
        /*-- add you code for tos_subtitle_set_mode here --*/
    }

    fpi_error tos_subtitle_get_prefer_language( EN_FPI_SUBTITLE_PREFER_LANGUAGE type, MEMBER_LANGUAGE* language ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_get_prefer_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_FPI_SUBTITLE_LANGUAGE_TYPE as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (language == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(MEMBER_LANGUAGE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_subtitle_get_prefer_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (language != NULL) {
                    int _language_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _language_rblob;
                    reply.readBlob(_language_len,&_language_rblob);
                    memcpy(language,_language_rblob.data(),_language_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_get_prefer_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_get_prefer_language error");
        }

        return _result;
        /*-- add you code for tos_subtitle_get_prefer_language here --*/
    }

    fpi_error tos_subtitle_set_prefer_language( EN_FPI_SUBTITLE_PREFER_LANGUAGE type, MEMBER_LANGUAGE language ) {
        Parcel data, reply;

        /*-- add you code for tos_subtitle_set_prefer_language here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(type);  //EN_FPI_SUBTITLE_LANGUAGE_TYPE as input paramter

            data.writeInt32(language);  //MEMBER_LANGUAGE as input paramter

            _binder->transact(TRANSACTION_tos_subtitle_set_prefer_language,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_subtitle_set_prefer_language error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_subtitle_set_prefer_language error");
        }

        return _result;
        /*-- add you code for tos_subtitle_set_prefer_language here --*/
    }
};

sbinder_subtitle_client* sbinder_subtitle_client::_instance = NULL;

fpi_error tos_subtitle_get_info( fpi_subtitle_info_t* sttInfo ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_get_info(sttInfo);
}
fpi_error tos_subtitle_open( uint8_t index ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_open(index);
}
fpi_error tos_subtitle_set_visibility( EN_FPI_SUBTITLE_VISIBLE_LEVEL level, fpi_bool flag ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_set_visibility(level, flag);
}
fpi_error tos_subtitle_get_status( fpi_bool* flag ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_get_status(flag);
}
fpi_error tos_subtitle_set_status( fpi_bool flag ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_set_status(flag);
}
fpi_error tos_subtitle_get_mode( EN_FPI_SUBTITLE_MODE* mode ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_get_mode(mode);
}
fpi_error tos_subtitle_set_mode( EN_FPI_SUBTITLE_MODE mode ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_set_mode(mode);
}
fpi_error tos_subtitle_get_prefer_language( EN_FPI_SUBTITLE_PREFER_LANGUAGE type, MEMBER_LANGUAGE* language ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_get_prefer_language(type, language);
}
fpi_error tos_subtitle_set_prefer_language( EN_FPI_SUBTITLE_PREFER_LANGUAGE type, MEMBER_LANGUAGE language ) {
    return sbinder_subtitle_client::Instance()->tos_subtitle_set_prefer_language(type, language);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
