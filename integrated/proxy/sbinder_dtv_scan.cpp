/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_dtv_scan.sidl
 */
 

#define LOG_TAG     "sbinder_dtv_scan"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_dtv_scan.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_CHANNEL_SCAN);


#define SERVICE_DESCRIPTOR                      "0d12814a-b326-11e4-b1d9-005056a84a3b"
#define SERVICE_NAME                            "sbinder_dtv_scan"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_dtv_scan_start FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_tv_scan_pause FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_tv_scan_resume FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_tv_scan_stop FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_dtv_scan_db_save FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_dtv_scan_db_clear FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_dtv_scan_get_status FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_dtv_scan_get_current_scan_info FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_dtv_scan_add_callback FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_dtv_scan_remove_callback FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_dtv_scan_get_multi_network_list FIRST_CALL_TRANSACTION + 11



#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_tos_dtv_scan_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_dtv_scan.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>

class sbinder_dtv_scan_service : public BBinder  
{  
private:
    static sbinder_dtv_scan_service* _instance;

    RemoteCallbackList _cbList;
    bool _first_array[E_FPI_DTV_STREAM_PORT_MAX];

    sbinder_dtv_scan_service(){
		for (int index = 0; index < E_FPI_DTV_STREAM_PORT_MAX; index ++)
		{
			_first_array[index] = true;
		}
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_dtv_scan_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

    static fpi_error module_callback(fpi_dtv_stream_port_t port, const tos_dtv_scanning_info_t *info, void* userdata)
	{
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        fpi_error _result = 0;
        int size = rcbl->beginBroadcast();
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);
			void *userdata_save = rcbl->getBroadcastCookie(i);

            if(binder != NULL) {
                Parcel data, reply;
                data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));

                data.writeInt32(port);

				Parcel::WritableBlob _param_wblob;

				if (NULL == info)
				{
                	data.writeInt32(-1);
				}
				else
				{
                	data.writeInt32((1) * sizeof(tos_dtv_scanning_info_t));
	                data.writeBlob((1) * sizeof(tos_dtv_scanning_info_t),&_param_wblob);
	                memcpy(_param_wblob.data(), info, (1) * sizeof(tos_dtv_scan_param_t));
				}

				data.writeInt64((int64_t)userdata_save);

                binder->transact(TRANSACTION_CALLBACK_tos_dtv_scan_callback, data, &reply, 0);

                if(reply.readExceptionCode() == 0) {//fix check
                	_result = (typeof(_result))reply.readInt32();//int as return value
	            } else {
	                fpi_warn(SERVICE_NAME"_service module_callback return error");
	            }
            }
        }
        rcbl->finishBroadcast();

        fpi_warn(SERVICE_NAME"_service module_callback end");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_dtv_scan_service();
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

            case TRANSACTION_tos_dtv_scan_start:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_start here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _param_len = data.readInt32(); //read length, only 32bits length support yet
                tos_dtv_scan_param_t* param = NULL;
				Parcel::ReadableBlob _param_rblob;

                if(_param_len > 0) {
                    data.readBlob(_param_len,&_param_rblob);
                    param = (tos_dtv_scan_param_t *)_param_rblob.data();
                }

                fpi_error _result = tos_dtv_scan_start( param );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_dtv_scan_start here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tv_scan_pause:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tv_scan_pause here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();  //int as input paramter

                fpi_error _result = tos_tv_scan_pause( port );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tv_scan_pause here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tv_scan_resume:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tv_scan_resume here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();  //int as input paramter

                fpi_error _result = tos_tv_scan_resume( port );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tv_scan_resume here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tv_scan_stop:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tv_scan_stop here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();  //int as input paramter

                fpi_error _result = tos_tv_scan_stop( port );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tv_scan_stop here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_db_save:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_db_save here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_dtv_scan_db_save(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_dtv_scan_db_save here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_db_clear:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_db_clear here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                fpi_error _result = tos_dtv_scan_db_clear(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_dtv_scan_db_clear here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_get_status:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_get_status here, will auoto generated but may change yourself if need --

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

                fpi_error _result = tos_dtv_scan_get_status( status );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_dtv_scan_get_status here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_get_current_scan_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_get_current_scan_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _info_len = data.readInt32(); //read length, only 32bits length support yet
                tos_dtv_scanning_info_t* info = NULL;
				Parcel::WritableBlob _info_wblob;

                if(_info_len > 0) {
                    reply->writeInt32(_info_len);
                    reply->writeBlob(_info_len,&_info_wblob);
                    info = (tos_dtv_scanning_info_t*)_info_wblob.data();
                }

                fpi_error _result = tos_dtv_scan_get_current_scan_info( info );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_dtv_scan_get_current_scan_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                sp<IBinder> binder = data.readStrongBinder();
				fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();

                if ((binder != NULL) && (port < E_FPI_DTV_STREAM_PORT_MAX))
				{
                    fpi_error _result = FPI_ERROR_SUCCESS;

					void *userdata = (void *)data.readInt64();

                    if(_first_array[port]) {
                        _result = tos_dtv_scan_add_callback(port, sbinder_dtv_scan_service::module_callback, userdata);
                        if(_result == FPI_ERROR_SUCCESS) {
                            _first_array[port] = false;
                        }
                    }

                    if(_result == FPI_ERROR_SUCCESS) {
                        if(_cbList.registerCallback(binder,userdata)) {
                            reply->writeNoException();
                            reply->writeInt32(_result); //int as return value
                        }
                        else {
                            reply->writeInt32(-3);//Exception
                        }
                    }
                    else {
                        reply->writeInt32(-2);//Exception
                    }
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_dtv_scan_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_dtv_scan_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_dtv_scan_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                sp<IBinder> binder = data.readStrongBinder();
				fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();

				(void)port;

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_dtv_scan_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;	
			case TRANSACTION_tos_dtv_scan_get_multi_network_list:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check   
                reply->writeNoException();
               
                int _pstNetworkList_len = data.readInt32(); //read length, only 32bits length support yet
                tos_dtv_muti_network_info* pstNetworkList = NULL;
				Parcel::WritableBlob _pout_wblob;
				
                if(_pstNetworkList_len > 0) {
					reply->writeInt32(_pstNetworkList_len);
					reply->writeBlob(_pstNetworkList_len,&_pout_wblob);
					pstNetworkList = (tos_dtv_muti_network_info*)_pout_wblob.data();	
                  
					if (pstNetworkList != NULL)
					{
						memset(pstNetworkList, 0, _pstNetworkList_len);
					}
                }

                int listSize = (int)data.readInt32();  //int as input paramter

                fpi_dtv_delivery_type_t deliveryType = (fpi_dtv_delivery_type_t)data.readInt32();  //fpi_dtv_delivery_type_t as input paramter

                uint32_t networkId = (uint32_t)data.readInt32();  //uint32_t as input paramter
                int _result = tos_dtv_scan_get_multi_network_list( pstNetworkList, listSize, deliveryType, networkId );
		
				fpi_trace(SERVICE_NAME" getmutil_network_list _result= %d\n", _result);
                reply->writeInt32(_result); //int as return value

                return NO_ERROR;
            }
			break;
			 default:  
                return BBinder::onTransact(code, data, reply, flags);
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_dtv_scan_service_add() {
    sbinder_dtv_scan_service::Instance();
    return 0;
}

sbinder_dtv_scan_service* sbinder_dtv_scan_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>

class sbinder_dtv_scan_client  
{  
private:
    static sbinder_dtv_scan_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;

    sbinder_dtv_scan_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_dtv_scan_client() {
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

    class Callback : public ICallbackList::ICallback {
    public:
        Callback(void* cb,void* cookie)
            :ICallback(cb,cookie) {
            _descriptor = String16(SERVICE_NAME"_callback");
        }

        ~Callback() {
        }

        virtual status_t onTransact( uint32_t code,
                const Parcel& data,Parcel* reply,uint32_t flags = 0) {
            fpi_info(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_tos_dtv_scan_callback:
            {
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
					fpi_error _result = FPI_ERROR_SUCCESS;

                    fpi_dtv_stream_port_t port_save = (fpi_dtv_stream_port_t)((long)_cookie);
                    fpi_dtv_stream_port_t port = (fpi_dtv_stream_port_t)data.readInt32();

					if (port_save == port)
					{
						tos_dtv_scanning_info_t *info = NULL;
						int info_length = data.readInt32();
						Parcel::ReadableBlob _info_rblob;

						if (info_length > 0)
						{
		                    data.readBlob(info_length, &_info_rblob);
		                    info = (tos_dtv_scanning_info_t*)_info_rblob.data();
						}

						void* userdata = (void *)data.readInt64();

	                    _result = ((tos_dtv_scan_callback)_callback)(port, info, userdata);
					}

                    reply->writeNoException();
                    reply->writeInt32(_result);
                }
                else {
                    reply->writeInt32(-1);//Exception
                }
                break;
            }

            default:
                return BBinder::onTransact(code, data, reply, flags);
            }

            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
    };

public:  
    static sbinder_dtv_scan_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_dtv_scan_client();
        }

        return _instance;
    }

    fpi_error tos_dtv_scan_start( tos_dtv_scan_param_t* param ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_start here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			Parcel::WritableBlob _param_wblob;

            //for out only, only write length ; for in, alloc and copy
            if (param == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_dtv_scan_param_t));//write length, only support 32 bits length yet
                
                data.writeBlob((1) * sizeof(tos_dtv_scan_param_t),&_param_wblob);
                memcpy(_param_wblob.data(),param,(1)* sizeof(tos_dtv_scan_param_t));
            }

            _binder->transact(TRANSACTION_tos_dtv_scan_start,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_start error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_start error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_start here --*/
    }

    fpi_error tos_tv_scan_pause( fpi_dtv_stream_port_t port ) {
        Parcel data, reply;

        /*-- add you code for tos_tv_scan_pause here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(port);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tv_scan_pause,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_tv_scan_pause error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_tv_scan_pause error");
        }

        return _result;
        /*-- add you code for tos_tv_scan_pause here --*/
    }

    fpi_error tos_tv_scan_resume( fpi_dtv_stream_port_t port ) {
        Parcel data, reply;

        /*-- add you code for tos_tv_scan_resume here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(port);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tv_scan_resume,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_tv_scan_resume error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_tv_scan_resume error");
        }

        return _result;
        /*-- add you code for tos_tv_scan_resume here --*/
    }

    fpi_error tos_tv_scan_stop( fpi_dtv_stream_port_t port ) {
        Parcel data, reply;

        /*-- add you code for tos_tv_scan_stop here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(port);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tv_scan_stop,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_tv_scan_stop error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_tv_scan_stop error");
        }

        return _result;
        /*-- add you code for tos_tv_scan_stop here --*/
    }

    fpi_error tos_dtv_scan_db_save(  ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_db_save here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_dtv_scan_db_save,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_db_save error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_db_save error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_db_save here --*/
    }

    fpi_error tos_dtv_scan_db_clear(  ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_db_clear here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_dtv_scan_db_clear,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_db_clear error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_db_clear error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_db_clear here --*/
    }

    fpi_error tos_dtv_scan_get_status( EN_TOS_DTV_SCAN_STATUS* status ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_get_status here --*/
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

            _binder->transact(TRANSACTION_tos_dtv_scan_get_status,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (status != NULL) {
                    int _status_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _status_rblob;
                    reply.readBlob(_status_len,&_status_rblob);
                    memcpy(status,_status_rblob.data(),_status_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_get_status error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_get_status error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_get_status here --*/
    }

    fpi_error tos_dtv_scan_get_current_scan_info( tos_dtv_scanning_info_t* info ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_get_current_scan_info here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(tos_dtv_scanning_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_dtv_scan_get_current_scan_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (info != NULL) {
                    int _info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _info_rblob;
                    reply.readBlob(_info_len,&_info_rblob);
                    memcpy(info,_info_rblob.data(),_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_get_current_scan_info error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_get_current_scan_info error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_get_current_scan_info here --*/
    }

    fpi_error tos_dtv_scan_add_callback( fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback, void* userdata ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_add_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

		if ((NULL == callback) || (E_FPI_DTV_STREAM_PORT_MAX <= port))
		{
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_add_callback NULL callbak or error port");
            return _result;
		}

        if(_CBList.findCallback((void*)callback, (void*)port) != NULL) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_add_callback cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            sp<Callback> ccb = new Callback((void*)callback, (void*)port);
            data.writeStrongBinder(ccb);
			data.writeInt32(port);
			data.writeInt64((int64_t)userdata);

            _binder->transact(TRANSACTION_tos_dtv_scan_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SIGNAL_SUCCESS) { //success
                    _CBList.addCallback(ccb);
                }

            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_add_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_add_callback error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_add_callback here --*/
    }

    fpi_error tos_dtv_scan_remove_callback( fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback ) {
        Parcel data, reply;

        /*-- add you code for tos_dtv_scan_remove_callback here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

		if ((NULL == callback) || (E_FPI_DTV_STREAM_PORT_MAX <= port))
		{
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_remove_callback NULL callbak or error port");
            return _result;
		}

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)callback, (void*)port);
        if(ccb == NULL) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_remove_callback cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);
			data.writeInt32(port);

            _binder->transact(TRANSACTION_tos_dtv_scan_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == FPI_ERROR_SUCCESS) { //success
                    _CBList.removeCallback(ccb);
                }
            } else {
                fpi_warn(SERVICE_NAME"_client tos_dtv_scan_remove_callback error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_dtv_scan_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_dtv_scan_remove_callback here --*/
    }

	int tos_dtv_scan_get_multi_network_list( tos_dtv_muti_network_info* pstNetworkList, int listSize, fpi_dtv_delivery_type_t deliveryType, uint32_t networkId )
	{
	    Parcel data, reply;

	    /*-- add you code for tos_dtv_scan_get_multi_network_list here --*/
		int _result = 0;
	    if(!getService()) {
	        return _result;
	    }
		
		if (pstNetworkList == NULL || listSize <= 0)
		{
			 fpi_warn(SERVICE_NAME"_client tos_dtv_scan_get_multi_network_list NULL pstNetworkList or listSize is error");
            return _result;
		}
		
	    try {
	        data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

	        //for out only, only write length ; for in, alloc and copy
	        if (pstNetworkList == NULL) {
	            data.writeInt32(-1);
	        }
	        else {
	            data.writeInt32((listSize) * sizeof(tos_dtv_muti_network_info));//write length, only support 32 bits length yet            
	   	    }

	        data.writeInt32(listSize);  //int as input paramter

	        data.writeInt32(deliveryType);  //fpi_dtv_delivery_type_t as input paramter

	        data.writeInt32(networkId);  //uint32_t as input paramter

			fpi_trace(SERVICE_NAME"_client get_multi_network_list, pstNetworkList len = %d, listSize = %d, deliveryType = %d, networkId = %d",  
				(listSize) * sizeof(tos_dtv_muti_network_info),listSize, deliveryType, networkId);
			
	        _binder->transact(TRANSACTION_tos_dtv_scan_get_multi_network_list,data, &reply,0);

	        if(reply.readExceptionCode() == 0) {//fix check
				if(pstNetworkList != NULL)
				{
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(pstNetworkList,_pout_rblob.data(),_pout_len);
				}
				
                _result = (typeof(_result))reply.readInt32();//int as return value
	        } else {
	            CLOGW(SERVICE_NAME"_client tos_dtv_scan_get_multi_network_list error");
	        }
	    }catch(...) {
	        CLOGW(SERVICE_NAME"_client tos_dtv_scan_get_multi_network_list error");
	    }

	    return _result;
	    /*-- add you code for tos_dtv_scan_get_multi_network_list here --*/
	}
};


sbinder_dtv_scan_client* sbinder_dtv_scan_client::_instance = NULL;

fpi_error tos_dtv_scan_start( tos_dtv_scan_param_t* param ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_start(param);
}
fpi_error tos_tv_scan_pause( fpi_dtv_stream_port_t port ) {
    return sbinder_dtv_scan_client::Instance()->tos_tv_scan_pause(port);
}
fpi_error tos_tv_scan_resume( fpi_dtv_stream_port_t port ) {
    return sbinder_dtv_scan_client::Instance()->tos_tv_scan_resume(port);
}
fpi_error tos_tv_scan_stop( fpi_dtv_stream_port_t port ) {
    return sbinder_dtv_scan_client::Instance()->tos_tv_scan_stop(port);
}
fpi_error tos_dtv_scan_db_save(  ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_db_save();
}
fpi_error tos_dtv_scan_db_clear(  ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_db_clear();
}
fpi_error tos_dtv_scan_get_status( EN_TOS_DTV_SCAN_STATUS* status ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_get_status(status);
}
fpi_error tos_dtv_scan_get_current_scan_info( tos_dtv_scanning_info_t* info ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_get_current_scan_info(info);
}
fpi_error tos_dtv_scan_add_callback( fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback, void* userdata ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_add_callback(port, callback, userdata);
}
fpi_error tos_dtv_scan_remove_callback( fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback ) {
    return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_remove_callback(port, callback);
}

int tos_dtv_scan_get_multi_network_list( tos_dtv_muti_network_info* pstNetworkList, int listSize, fpi_dtv_delivery_type_t deliveryType, uint32_t networkId ) 
{   
	return sbinder_dtv_scan_client::Instance()->tos_dtv_scan_get_multi_network_list(pstNetworkList, listSize, deliveryType, networkId);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
