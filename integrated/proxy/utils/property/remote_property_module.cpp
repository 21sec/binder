/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_property_module.sidl
 */
 

#define LOG_TAG     "remote_property_module"

#include "clog.h"
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "fpi_error_code.h"
#include "fpi_debug_helper.h"
#include "tos_property.h"

SET_MODEL_ID(SITA_MODULE_PROPERTY);

#define SERVICE_DESCRIPTOR                      "1b5acbd0-90cc-11e4-a5ff-005056a84a3b"
#define SERVICE_NAME                            "remote_property_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_property_set FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_property_get FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_property_remove FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_property_reset FIRST_CALL_TRANSACTION + 4

using namespace sita_android;




#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "remote_property_module.h"

class remote_property_module_service : public BBinder  
{  
private:
    static remote_property_module_service* _instance;

    remote_property_module_service(){
        fpi_debug(SERVICE_NAME"_service create");
    }
    
    virtual ~remote_property_module_service() {
        fpi_debug(SERVICE_NAME"_service destory");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_debug(SERVICE_NAME"_service Instance");
            _instance = new remote_property_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_debug(SERVICE_NAME"_service ret = %d", ret);  
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_debug(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_property_set:
            {
                if ( !data.enforceInterface(String16(SERVICE_NAME))){
					fpi_err_code(FPI_ERROR_PROXY_TOKEN_ERROR,"enforceInterface error");
					return FPI_ERROR_PROXY_TOKEN_ERROR;
				}
				fpi_debug("server TRANSACTION_tos_property_set\n");

                //-- begin code for tos_property_set here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _key_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_debug("stps11122 key_len = %d\n",_key_len);
                const char* key = NULL;
                if(_key_len > 0) {
                    Parcel::ReadableBlob _key_rblob;
                    data.readBlob(_key_len,&_key_rblob);
                    key = (const char*)_key_rblob.data();
                }

                int _value_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_debug("stps11122 1 key = %s, _value_len = %d\n",key,_value_len);
                const char* value = NULL;
                if(_value_len > 0) {
                    Parcel::ReadableBlob _value_rblob;
                    data.readBlob(_value_len,&_value_rblob);
                    value = (const char*)_value_rblob.data();
                }

				fpi_debug("stps11122 key = %s, value = %s\n",key,value);
                int _result = tos_property_set( key, value );
				fpi_debug("stps11122 2 key= %s ,_result = %d\n",key,_result);

				fpi_debug("stps11122 3 key= %s ,tos_property_get = %s\n",key,tos_property_get(key, value));
                reply->writeInt32(_result); //int as return value

                //-- end code for tos_property_set here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_property_get:
            {
                if ( !data.enforceInterface(String16(SERVICE_NAME))){
					fpi_err_code(FPI_ERROR_PROXY_TOKEN_ERROR,"enforceInterface error");
					return FPI_ERROR_PROXY_TOKEN_ERROR;
				}

                //-- begin code for tos_property_get here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _key_len = data.readInt32(); //read length, only 32bits length support yet
                const char* key = NULL;
                if(_key_len > 0) {
                    Parcel::ReadableBlob _key_rblob;
                    data.readBlob(_key_len,&_key_rblob);
                    key = (const char*)_key_rblob.data();
                }

                int _defValue_len = data.readInt32(); //read length, only 32bits length support yet
                const char* defValue = NULL;
                if(_defValue_len > 0) {
                    Parcel::ReadableBlob _defValue_rblob;
                    data.readBlob(_defValue_len,&_defValue_rblob);
                    defValue = (const char*)_defValue_rblob.data();
                }

				

				fpi_debug("server121212 TRANSACTION_tos_property_get 1 key= (%s),defValue = (%s) ,defValuelen = %d\n",key,defValue,_defValue_len);

                const char* _result = tos_property_get( key, defValue );

				fpi_debug("server TRANSACTION_tos_property_get 2 key= %s ,get value = (%s)\n",key,_result);
				if (_result !=NULL){
					reply->writeInt32((int)(strlen(_result)) * sizeof(char));
					fpi_debug("server TRANSACTION_tos_property_get 3 key= %s ,len = %d\n",key,(int)(strlen(_result)) * sizeof(char));
                	Parcel::WritableBlob _defValue_wblob;
                	reply->writeBlob((int)(strlen(_result)+1) * sizeof(char),&_defValue_wblob);
					memcpy(_defValue_wblob.data(),_result,(int)(strlen(_result)+1) * sizeof(char));
				}else{
					reply->writeInt32(-1);
				}
                //-- end code for tos_property_get here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_property_remove:
            {
                if ( !data.enforceInterface(String16(SERVICE_NAME))){
					fpi_err_code(FPI_ERROR_PROXY_TOKEN_ERROR,"enforceInterface error");
					return FPI_ERROR_PROXY_TOKEN_ERROR;
				}

                //-- begin code for tos_property_remove here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _key_len = data.readInt32(); //read length, only 32bits length support yet
                const char* key = NULL;
                if(_key_len > 0) {
                    Parcel::ReadableBlob _key_rblob;
                    data.readBlob(_key_len,&_key_rblob);
                    key = (const char*)_key_rblob.data();
                }

                int _result = tos_property_remove( key );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_property_remove here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_property_reset:
            {
                if ( !data.enforceInterface(String16(SERVICE_NAME))){
					fpi_err_code(FPI_ERROR_PROXY_TOKEN_ERROR,"enforceInterface error");
					return FPI_ERROR_PROXY_TOKEN_ERROR;
				}

                //-- begin code for tos_property_reset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _result = tos_property_reset(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_property_reset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
				fpi_err_code(FPI_ERROR_PROXY_UNKNOW,"default unkown error!!");
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_debug(SERVICE_NAME"_service end");
    }
}; 

int remote_property_module_service_add() {
    remote_property_module_service::Instance();
    return 0;
}

remote_property_module_service* remote_property_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)


#include "stringspool.h"

extern "C" const char* strings_pool_get(const char *key);
//void clog_printf(const char* tag,int level,const char* format,...){}

class remote_property_module_client  
{  
private:
    static remote_property_module_client* _instance;
    sp<IBinder> _binder;

    remote_property_module_client() {
        fpi_debug(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
		if (_binder == NULL){
			fpi_err_code(FPI_ERROR_PROXY_GETSERVICE_ERROR,"getservice _binder is null");
		}
    }
    
    virtual ~remote_property_module_client() {
        fpi_debug(SERVICE_NAME"_client destory\n");
    }

public:  
    static remote_property_module_client* Instance() {
        if(_instance == NULL) {
            fpi_debug(SERVICE_NAME"_client Instance");
            _instance = new remote_property_module_client();
        }

        return _instance;
    }

    int tos_property_set( const char* key, const char* value ) {
        Parcel data, reply;

        /*-- add you code for tos_property_set here --*/
        int _result = -1;
        if(_binder == NULL) {
			fpi_err_code(FPI_ERROR_PROXY_SBINDER_NULL,"tos_property_set binder is null");
            return _result;
        }
		fpi_debug("client tos_property_set \n");

        try {
        				
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (key == NULL) {
				fpi_debug("client tos_property_set key is null \n");
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(key)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _key_wblob;
                data.writeBlob((int)(strlen(key)+1) * sizeof(char),&_key_wblob);
                memcpy(_key_wblob.data(),key,(int)(strlen(key)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (value == NULL) {
				fpi_debug("client tos_property_set value is null \n");
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(value)+1) * sizeof(char));//write length, only support 32 bits length yet
                fpi_debug("ctps key = %s,value = (%s),valLen=%d\n",key,value,(int)(strlen(value)) * sizeof(char));
                Parcel::WritableBlob _value_wblob;
                data.writeBlob((int)(strlen(value)+1) * sizeof(char),&_value_wblob);
                memcpy(_value_wblob.data(),value,(int)(strlen(value)+1)* sizeof(char));
            }
			fpi_debug("ctps 111key = %s,value = (%s),valLen=%d\n",key,value,strlen(value));

            _binder->transact(TRANSACTION_tos_property_set,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				fpi_debug("client tos_property_set  _result= %d\n",_result);
            }else{
				fpi_err_code(FPI_ERROR_PROXY_EXCEPTION_ERROR,SERVICE_NAME"_client tos_property_set error");
			}
        }catch(...) {
			fpi_err_code(FPI_ERROR_PROXY_TRANSACTION_ERROR,SERVICE_NAME"_client tos_property_set error");
        }

        return _result;
        /*-- add you code for tos_property_set here --*/
    }

    const char* tos_property_get( const char* key, const char* defValue ) {
        Parcel data, reply;

        /*-- add you code for tos_property_get here --*/
        const char* _result = defValue;
        if(_binder == NULL) {
			fpi_err_code(FPI_ERROR_PROXY_SBINDER_NULL,"tos_property_get binder is null");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (key == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(key)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _key_wblob;
                data.writeBlob((int)(strlen(key)+1) * sizeof(char),&_key_wblob);
                memcpy(_key_wblob.data(),key,(int)(strlen(key)+1)* sizeof(char));
            }

            //for out only, only write length ; for in, alloc and copy
            if (defValue == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(defValue)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _defValue_wblob;
                data.writeBlob((int)(strlen(defValue)+1) * sizeof(char),&_defValue_wblob);
                memcpy(_defValue_wblob.data(),defValue,(int)(strlen(defValue)+1)* sizeof(char));
            }


			fpi_debug("client tos_property_get 1 key= %s ,value = %s\n",key,defValue);
			
            status_t ret = _binder->transact(TRANSACTION_tos_property_get,data, &reply,0);

			if(ret==NO_ERROR)
			{
	            if(reply.readExceptionCode() == 0) {//fix check

	                int _defValue_len = reply.readInt32(); //read length, only 32bits length support yet
	                fpi_debug("client tos_property_get 2 _defValue_len= %d\n",_defValue_len);
	                if(_defValue_len > 0) {
	                    Parcel::ReadableBlob _defValue_rblob;
	                    reply.readBlob(_defValue_len,&_defValue_rblob);
	                    _result = (const char*)_defValue_rblob.data();
						fpi_debug("client tos_property_get 3 key= %s ,value = %s\n",key,_result);
	                    _result=strings_pool_get(_result);
	                }
	            }else{
					fpi_err_code(FPI_ERROR_PROXY_EXCEPTION_ERROR,"readExceptionCode return must be 0!!");
				}
			}
			else
			{
				fpi_err_code(FPI_ERROR_PROXY_TRANSACTION_ERROR,SERVICE_NAME"_client tos_property_get error");
			}
        }catch(...) {
       		fpi_err_code(FPI_ERROR_PROXY_TRANSACTION_ERROR,SERVICE_NAME"_client tos_property_get error");
        }

        return _result;
        /*-- add you code for tos_property_get here --*/
    }

    int tos_property_remove( const char* key ) {
        Parcel data, reply;

        /*-- add you code for tos_property_remove here --*/
        int _result = -1;
        if(_binder == NULL) {
			fpi_err_code(FPI_ERROR_PROXY_SBINDER_NULL,"tos_property_remove binder is null");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (key == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(strlen(key)+1) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _key_wblob;
                data.writeBlob((int)(strlen(key)+1) * sizeof(char),&_key_wblob);
                memcpy(_key_wblob.data(),key,(int)(strlen(key)+1)* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_property_remove,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            }else{
				fpi_err_code(FPI_ERROR_PROXY_EXCEPTION_ERROR,"readExceptionCode return must be 0!!");
			}
        }catch(...) {
            fpi_err_code(FPI_ERROR_PROXY_TRANSACTION_ERROR,SERVICE_NAME"_client tos_property_remove error");
        }

        return _result;
        /*-- add you code for tos_property_remove here --*/
    }

    int tos_property_reset(  ) {
        Parcel data, reply;

        /*-- add you code for tos_property_reset here --*/
        int _result = -1;
        if(_binder == NULL) {
			fpi_err_code(FPI_ERROR_PROXY_SBINDER_NULL,"tos_property_reset binder is null");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_property_reset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {

                _result = (typeof(_result))reply.readInt32();//int as return value
            }else{
				fpi_err_code(FPI_ERROR_PROXY_EXCEPTION_ERROR,"readExceptionCode return must be 0!!");
			}
        }catch(...) {
            fpi_err_code(FPI_ERROR_PROXY_TRANSACTION_ERROR,SERVICE_NAME"_client tos_property_reset error");
        }

        return _result;
        /*-- add you code for tos_property_reset here --*/
    }
};

remote_property_module_client* remote_property_module_client::_instance = NULL;

int tos_property_set( const char* key, const char* value ) {
    return remote_property_module_client::Instance()->tos_property_set(key, value);
}
const char* tos_property_get( const char* key, const char* defValue ) {
    return remote_property_module_client::Instance()->tos_property_get(key, defValue);
}
int tos_property_remove( const char* key ) {
    return remote_property_module_client::Instance()->tos_property_remove(key);
}
int tos_property_reset(  ) {
    return remote_property_module_client::Instance()->tos_property_reset();
}




#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
