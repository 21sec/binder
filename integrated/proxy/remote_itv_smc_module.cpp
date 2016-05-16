/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_smc_module.sidl
 */
 

#define LOG_TAG     "remote_itv_smc_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_defines.h"
#include "itv_smc.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "5b2bf26a-133b-11e5-a8cc-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_smc_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_smc_open FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_smc_close FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_smc_reset FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_smc_transfer_data FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_smc_send FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_itv_smc_receive FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_itv_smc_get_info FIRST_CALL_TRANSACTION + 7

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_callback FIRST_CALLBACK_TRANSACTION + 1

using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG     "remote_itv_smc_module"

#include <stdlib.h>
#include "remote_itv_smc_module.h"
#include <sbinder/RemoteCallbackList.h>
#include <utils/KeyedVector.h>
#include "clog.h"

class remote_itv_smc_module_service : public BBinder  
{  
private:
    static remote_itv_smc_module_service* _instance;
	
	sp<IBinder> _cbbinder;

    remote_itv_smc_module_service()
	{
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_smc_module_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }
	
	static unsigned int module_callback(itv_handle_t handle, itv_smc_status_t status) {
        TOSLOGI(SERVICE_NAME"_service module_callback start\n");
        int _result = 0;

        if(_instance->_cbbinder != NULL && _instance->_cbbinder->isBinderAlive()) {
            Parcel data, reply;
            data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
            
			//************** Add call back functions's param
			data.writeInt32(handle);
			data.writeInt32(status);
			TOSLOGI(SERVICE_NAME"_service module_callback transact\n");
            _instance->_cbbinder->transact(TRANSACTION_CALLBACK_callback, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = reply.readInt32();//int as return value
            }
        }

        TOSLOGI(SERVICE_NAME"_service module_callback end\n");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_smc_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        TOSLOGI(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_smc_open:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_open here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int smcId = (int)data.readInt32();  //int as input paramter

                itv_smc_open_param_t _param_Struct;
				memset(&_param_Struct, 0, sizeof(itv_smc_open_param_t));
				const itv_smc_open_param_t* pParams = NULL;

				int _param_len = data.readInt32();  //int as input paramter
				if(_param_len > 0) {
					_param_Struct.clockFrequency = (unsigned int)data.readInt32(); 
					_param_Struct.baudRate = (unsigned int)data.readInt32(); 
					_param_Struct.enmProtocol = (itv_smc_protocol_t)data.readInt32(); 
					_param_Struct.enmStandard = (itv_smc_standard_t)data.readInt32(); 
					_param_Struct.pfnStatusCallback = NULL;
					int _smc_cb_flag = data.readInt32();
					if(_smc_cb_flag > 0) {
						_param_Struct.pfnStatusCallback = remote_itv_smc_module_service::module_callback;
						_cbbinder = data.readStrongBinder();	// call back function
					}
					pParams = &_param_Struct;
				}

				int _handle_len = data.readInt32(); //read length, only 32bits length support yet
				itv_handle_t* pOutSmcHandle = NULL;
				Parcel::WritableBlob _handle_wblob;
				if(_handle_len > 0) {
					reply->writeInt32(_handle_len);
					reply->writeBlob(_handle_len,&_handle_wblob);
					pOutSmcHandle = (itv_handle_t*)_handle_wblob.data();
				}

				int _result = itv_smc_open( smcId, pParams, pOutSmcHandle );
				reply->writeInt32(_result); //int as return value
					
                //-- end code for itv_smc_open here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_smc_close( handle );

				//_cbList.registerCallback()
				if(_result == ITV_SUCCESS) {
					TOSLOGI(SERVICE_NAME"_service itv_smc_close Success\n");
					_cbbinder = NULL;
                }

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_smc_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_reset:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_reset here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _pMsgATR_flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer pMsgATR is not NULL.
                unsigned char* pMsgATR = NULL;
				Parcel::WritableBlob _pMsgATR_wblob;

				int _msglen_flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer msglength is not NULL.
				unsigned int _msglen = 0;
				unsigned int _len = 0;
				unsigned int* _pmsglength = NULL;
				if(_msglen_flag > 0) {
					_msglen = data.readInt32();
					_msglen = (_msglen > 32) ? 32 : _msglen;	// ATR's length is smaller than 32

					if(_pMsgATR_flag > 0) {
						reply->writeInt32(_msglen);
	                    reply->writeBlob(_msglen,&_pMsgATR_wblob);
	                    pMsgATR = (unsigned char*)_pMsgATR_wblob.data();
					}
					
					_pmsglength = &_msglen;
					_len = _msglen;
				}
				
				// re-get all pointers from blob to fix realloc issue in Parcel
                pMsgATR = (unsigned char*)_pMsgATR_wblob.data();
				
                unsigned char coldreset = (unsigned char)data.readInt32();  //unsigned char as input paramter

                int _result = itv_smc_reset( handle, pMsgATR, _pmsglength, coldreset );

                reply->writeInt32(_result); //int as return value
                if(_msglen_flag > 0) {
					reply->writeInt32((*_pmsglength < _len) ? *_pmsglength : _len); //int as return value
				}

                //-- end code for itv_smc_reset here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_transfer_data:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_transfer_data here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter
				
                int _pReqdata_len = data.readInt32(); //read length, only 32bits length support yet
                const unsigned char* pReqdata = NULL;
                Parcel::ReadableBlob _pReqdata_rblob;
                if(_pReqdata_len > 0) {
                    data.readBlob(_pReqdata_len,&_pReqdata_rblob);
                    pReqdata = (const unsigned char*)_pReqdata_rblob.data();
                }

                unsigned int reqlen = (unsigned int)data.readInt32();  //unsigned int as input paramter

				int _pRepdata_flag = data.readInt32();// Just a flag.  if this flag >0, then can tell that the pointer pRepdata is not NULL.
				unsigned char* pRepdata = NULL;
                Parcel::WritableBlob _pRepdata_wblob;

				// TODO:replen应作为输入输出参数
				int _replen_flag = data.readInt32();// Just a flag.  if this flag >0, then can tell that the pointer replen is not NULL. 
				unsigned char buffer[512];
				unsigned int bufferLen = 512;
				if(_replen_flag > 0) {
					data.readInt32();
				}

				int _pStatusword_flag = data.readInt32();// Just a flag.  if this flag >0, then can tell that the pointer pStatusword is not NULL. 
                unsigned short int _statusword = 0;
				unsigned short int* pStatusword = (_pStatusword_flag > 0) ? &_statusword : NULL;
				
				int _result = itv_smc_transfer_data( handle, pReqdata, reqlen, buffer, &bufferLen, pStatusword );
				
				TOSLOGW(SERVICE_NAME" transter data bufferLen = %u\n", bufferLen);
				if(_pRepdata_flag > 0) {
                    reply->writeInt32(bufferLen);
                    reply->writeBlob(bufferLen,&_pRepdata_wblob);
					pRepdata = (unsigned char*)_pRepdata_wblob.data();
					memcpy(pRepdata, buffer, bufferLen);
                }
				
				reply->writeInt32(_result); //int as return value

				if(_replen_flag > 0){
					reply->writeInt32(bufferLen);
				}
				
				if(_pStatusword_flag > 0){
					reply->writeInt32(*pStatusword);
				}

                //-- end code for itv_smc_transfer_data here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_send:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_send here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _pBuffer_len = data.readInt32(); //read length, only 32bits length support yet
                const unsigned char* pBuffer = NULL;

                Parcel::ReadableBlob _pBuffer_rblob;

                if(_pBuffer_len > 0) {
                    data.readBlob(_pBuffer_len,&_pBuffer_rblob);
                    pBuffer = (const unsigned char*)_pBuffer_rblob.data();
                }

                unsigned int numToWrite = (unsigned int)data.readInt32();  //unsigned int as input paramter

				int _flag = data.readInt32();// Just a flag.  if this flag >0, then can tell that the pointer pNumberWritten is not NULL. 
				unsigned int _numberWritten = 0;
				unsigned int* pNumberWritten = (_flag > 0) ? &_numberWritten : NULL;

                unsigned int timeout = (unsigned int)data.readInt32();  //unsigned int as input paramter

                int _result = itv_smc_send( handle, pBuffer, numToWrite, pNumberWritten, timeout );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0) {
                	reply->writeInt32(*pNumberWritten); //int as return value
                }

                //-- end code for itv_smc_send here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_receive:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_receive here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

                int _pBuffer_len = data.readInt32(); //read length, only 32bits length support yet
                unsigned char* pBuffer = NULL;

                Parcel::WritableBlob _pBuffer_wblob;

                if(_pBuffer_len > 0) {
                    reply->writeInt32(_pBuffer_len);
                    reply->writeBlob(_pBuffer_len,&_pBuffer_wblob);
                    pBuffer = (unsigned char*)_pBuffer_wblob.data();
                }

                unsigned int numberToRead = (unsigned int)data.readInt32();  //unsigned int as input paramter

				int _flag = data.readInt32();	// Just a flag.  if this flag >0, then can tell that the pointer pNumberReaded is not NULL. 
                unsigned int _numberReaded = 0;
				unsigned int* pNumberReaded = _flag > 0 ? &_numberReaded : NULL;

                unsigned int timeout = (unsigned int)data.readInt32();  //unsigned int as input paramter

                int _result = itv_smc_receive( handle, pBuffer, numberToRead, pNumberReaded, timeout );

                reply->writeInt32(_result); //int as return value
				if(_flag > 0) {
					reply->writeInt32(*pNumberReaded); //int as return value
				}

                //-- end code for itv_smc_receive here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_smc_get_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_smc_get_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                itv_handle_t handle = (itv_handle_t)data.readInt32();  //itv_handle_t as input paramter

				int _flag = data.readInt32();
				itv_smc_info_t _smcInfo;
				memset(&_smcInfo,0,sizeof(itv_smc_info_t));
				itv_smc_info_t* pOutSmcInfo = (_flag > 0) ? &_smcInfo : NULL;

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = itv_smc_get_info( handle, pOutSmcInfo );
				
                reply->writeInt32(_result); //int as return value
				if(_flag > 0) {
					reply->writeInt32(pOutSmcInfo->clockFrequency);
					reply->writeInt32(pOutSmcInfo->baudRate);
					reply->writeInt32(pOutSmcInfo->enmProtocol);
					reply->writeInt32(pOutSmcInfo->enmStandard);
					reply->writeInt32(pOutSmcInfo->enmStatus);
				}

                //-- end code for itv_smc_get_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_smc_module_service_add() {
    remote_itv_smc_module_service::Instance();
    return 0;
}

remote_itv_smc_module_service* remote_itv_smc_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include "clog.h"
#include <sbinder/ICallbackList.h>

class remote_itv_smc_module_client  
{  
private:
	class  Callback;
    static remote_itv_smc_module_client* _instance;
    sp<IBinder> _binder;
	sp<Callback> _spcallback;
	
    remote_itv_smc_module_client()
        :_binder(NULL),_spcallback(NULL) {
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_smc_module_client() {
        TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            TOSLOGW(SERVICE_NAME"_client getFailed!\n");
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
            TOSLOGI(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_CALLBACK_callback:
            {
                if (!data.checkInterface(this)) {
                    TOSLOGW(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {

					itv_handle_t handle = (itv_handle_t)data.readInt32();
					itv_smc_status_t status = (itv_smc_status_t)data.readInt32();
					TOSLOGI(SERVICE_NAME"_client Ready to CallBack ...\n");
                    int _result = ((smc_status_callback)_callback)(handle, status);

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
    static remote_itv_smc_module_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_smc_module_client();
        }

        return _instance;
    }

    int itv_smc_open( int smcId, const itv_smc_open_param_t* pParams, itv_handle_t* pOutSmcHandle ) {
		TOSLOGI(SERVICE_NAME"_client itv_smc_open()\n");
        Parcel data, reply;

        /*-- add you code for itv_smc_open here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
			TOSLOGW(SERVICE_NAME"_client _binder\n");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(smcId);  //int as input paramter

			sp<Callback> ccb = NULL;
			if (pParams == NULL) {
				data.writeInt32(-1);
			}
			else {
				data.writeInt32((int)(1) * sizeof(itv_smc_open_param_t));//write length, only support 32 bits length yet   

				data.writeInt32(pParams->clockFrequency);
				data.writeInt32(pParams->baudRate);
				data.writeInt32(pParams->enmProtocol);
				data.writeInt32(pParams->enmStandard);
				if(pParams->pfnStatusCallback == NULL) {	// call back function 
					data.writeInt32(-1);
				}
				else {
					data.writeInt32(1);
					ccb = new Callback((void*)pParams->pfnStatusCallback,NULL);
					data.writeStrongBinder(ccb);
				}
			}

			if (pOutSmcHandle == NULL) {
				data.writeInt32(-1);
			}
			else {
				data.writeInt32((int)(1) * sizeof(itv_handle_t));//write length, only support 32 bits length yet   
			}
			
            _binder->transact(TRANSACTION_itv_smc_open, data, &reply, 0);

            if(reply.readExceptionCode() == 0) {//fix check
            	if(pOutSmcHandle != NULL) {
					int _handle_len = reply.readInt32(); //read length, only 32bits length support yet                    
					Parcel::ReadableBlob _handle_rblob;                    
					reply.readBlob(_handle_len,&_handle_rblob);                    
					memcpy(pOutSmcHandle,_handle_rblob.data(),_handle_len);
            	}
                
                _result = (typeof(_result))reply.readInt32();//int as return value
                
                if (_result == ITV_SUCCESS){
					_spcallback = ccb;
                }
            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_open error");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_open error\n");
        }

        return _result;
        /*-- add you code for itv_smc_open here --*/
    }

    int itv_smc_close( itv_handle_t handle ) {
        Parcel data, reply;

        /*-- add you code for itv_smc_close here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            _binder->transact(TRANSACTION_itv_smc_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value
                if(_result == ITV_SUCCESS) {
					TOSLOGI(SERVICE_NAME"_client itv_smc_close Success\n");
					_spcallback = NULL;
                }
            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_close error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_close error\n");
        }

        return _result;
        /*-- add you code for itv_smc_close here --*/
    }

    int itv_smc_reset( itv_handle_t handle, unsigned char* pMsgATR, unsigned int* msglength, unsigned char coldreset ) {
        Parcel data, reply;

        /*-- add you code for itv_smc_reset here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pMsgATR == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(1);//write a flag that pMsgATR is not NULL
            }

			if (msglength == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_reset  msglength = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag that msglength is not NULL
                TOSLOGI(SERVICE_NAME"_client itv_smc_reset  msglength = %d\n", *msglength);
				data.writeInt32(*msglength);
            }

            data.writeInt32(coldreset);  //unsigned char as input paramter

            _binder->transact(TRANSACTION_itv_smc_reset,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                if (pMsgATR != NULL) {
					if (msglength != NULL) {
	                    int _pMsgATR_len = reply.readInt32(); //read length, only 32bits length support yet
	                    Parcel::ReadableBlob _pMsgATR_rblob;
	                    reply.readBlob(_pMsgATR_len,&_pMsgATR_rblob);
	                    memcpy(pMsgATR,_pMsgATR_rblob.data(),_pMsgATR_len);
					}
                }
				
                _result = (typeof(_result))reply.readInt32();//int as return value
                
                if (msglength != NULL) {
					*msglength = (unsigned int)reply.readInt32();
                }
            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_reset error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_reset error\n");
        }

        return _result;
        /*-- add you code for itv_smc_reset here --*/
    }

    int itv_smc_transfer_data( itv_handle_t handle, const unsigned char* pReqdata, unsigned int reqlen, unsigned char* pRepdata, unsigned int* replen, unsigned short int* pStatusword ) {
		TOSLOGI(SERVICE_NAME"_client itv_smc_transfer_data\n");
		Parcel data, reply;

        /*-- add you code for itv_smc_transfer_data here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }
		
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pReqdata == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_transfer_data  pReqdata = NULL!!!\n");
            }
            else {
                data.writeInt32((int)(reqlen) * sizeof(unsigned char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pReqdata_wblob;
                data.writeBlob((reqlen) * sizeof(unsigned char),&_pReqdata_wblob);
                memcpy(_pReqdata_wblob.data(),pReqdata,(reqlen)* sizeof(unsigned char));
				
            }

			data.writeInt32(reqlen);  //unsigned int as input paramter

			if (pRepdata == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_transfer_data  pRepdata = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag that pRepdata is not NULL
            }
			if (replen == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_transfer_data  replen = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag that replen is not NULL
                data.writeInt32(*replen);
				TOSLOGI(SERVICE_NAME"_client itv_smc_transfer_data  *replen = %d\n", *replen);
            }
            if (pStatusword == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_transfer_data  pStatusword = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag that pStatusword is not NULL
            }

            _binder->transact(TRANSACTION_itv_smc_transfer_data,data, &reply,0);

			TOSLOGI(SERVICE_NAME"_client itv_smc_transfer_data  handle = %d!!!\n",handle);

            if(reply.readExceptionCode() == 0) {//fix check
            
            	if (pRepdata != NULL) { 
					if (replen != NULL) {
		                int _pRepdata_len = reply.readInt32(); //read length, only 32bits length support yet
		                if(_pRepdata_len > 0) {
		                    Parcel::ReadableBlob _pRepdata_rblob;
		                    reply.readBlob(_pRepdata_len,&_pRepdata_rblob);
		                    memcpy(pRepdata,_pRepdata_rblob.data(),_pRepdata_len);
		                }
					}
            	}

				_result = (typeof(_result))reply.readInt32();//int as return value
				
				if (replen != NULL) {
					*replen = (unsigned int)reply.readInt32();
            	}

				if (pStatusword != NULL) {
					*pStatusword = (unsigned short int)reply.readInt32();
            	}
            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_transfer_data error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_transfer_data error\n");
        }

        return _result;
        /*-- add you code for itv_smc_transfer_data here --*/
    }

    int itv_smc_send( itv_handle_t handle, const unsigned char* pBuffer, unsigned int numToWrite, unsigned int* pNumberWritten, unsigned int timeout ) {
        Parcel data, reply;

        /*-- add you code for itv_smc_send here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pBuffer == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(numToWrite) * sizeof(unsigned char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pBuffer_wblob;
                data.writeBlob((numToWrite) * sizeof(unsigned char),&_pBuffer_wblob);
                memcpy(_pBuffer_wblob.data(),pBuffer,(numToWrite)* sizeof(unsigned char));
            }

            data.writeInt32(numToWrite);  //unsigned int as input paramter

			if (pNumberWritten == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_send  pNumberWritten = NULL!!!\n");
            }
            else {
				data.writeInt32(1);//write a flag
            }

            data.writeInt32(timeout);  //unsigned int as input paramter

            _binder->transact(TRANSACTION_itv_smc_send,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if(pNumberWritten != NULL) {
                	*pNumberWritten = (unsigned int)reply.readInt32();//int as return value
				}

            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_send error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_send error\n");
        }

        return _result;
        /*-- add you code for itv_smc_send here --*/
    }

    int itv_smc_receive( itv_handle_t handle, unsigned char* pBuffer, unsigned int numberToRead, unsigned int* pNumberReaded, unsigned int timeout ) {
        Parcel data, reply;

        /*-- add you code for itv_smc_receive here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pBuffer == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(numberToRead) * sizeof(unsigned char));//write length, only support 32 bits length yet
                
            }
			
            data.writeInt32(numberToRead);  //unsigned int as input paramter

			if (pBuffer == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_send  pNumberWritten = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag
            }

            data.writeInt32(timeout);  //unsigned int as input paramter

            _binder->transact(TRANSACTION_itv_smc_receive,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
            	if(pBuffer != NULL) {
	                int _pBuffer_len = reply.readInt32(); //read length, only 32bits length support yet
	                Parcel::ReadableBlob _pBuffer_rblob;
	                reply.readBlob(_pBuffer_len,&_pBuffer_rblob);
	                memcpy(pBuffer,_pBuffer_rblob.data(),_pBuffer_len);
            	}

                _result = (typeof(_result))reply.readInt32();//int as return value

				if (pNumberReaded != NULL) {
					*pNumberReaded = (unsigned int)reply.readInt32();//int as return value
				}

            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_receive error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_receive error\n");
        }

        return _result;
        /*-- add you code for itv_smc_receive here --*/
    }

    int itv_smc_get_info( itv_handle_t handle, itv_smc_info_t* pOutSmcInfo ) {
        Parcel data, reply;

        /*-- add you code for itv_smc_get_info here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(handle);  //itv_handle_t as input paramter

			if (pOutSmcInfo == NULL) {
                data.writeInt32(-1);
				TOSLOGW(SERVICE_NAME"_client itv_smc_get_info  pOutSmcInfo = NULL!!!\n");
            }
            else {
                data.writeInt32(1);//write a flag
            }

            _binder->transact(TRANSACTION_itv_smc_get_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
				_result = (typeof(_result))reply.readInt32();//int as return value

				if(pOutSmcInfo != NULL) {
					pOutSmcInfo->clockFrequency = (unsigned int)reply.readInt32();
					pOutSmcInfo->baudRate = (unsigned int)reply.readInt32();
					pOutSmcInfo->enmProtocol = (itv_smc_protocol_t)reply.readInt32();
					pOutSmcInfo->enmStandard = (itv_smc_standard_t)reply.readInt32();
					pOutSmcInfo->enmStatus = (itv_smc_status_t)reply.readInt32();
				}
            } else {
                TOSLOGW(SERVICE_NAME"_client itv_smc_get_info error\n");
            }
        }catch(...) {
            TOSLOGE(SERVICE_NAME"_client itv_smc_get_info error\n");
        }

        return _result;
        /*-- add you code for itv_smc_get_info here --*/
    }
};

remote_itv_smc_module_client* remote_itv_smc_module_client::_instance = NULL;

int itv_smc_open( int smcId, const itv_smc_open_param_t* pParams, itv_handle_t* pOutSmcHandle ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_open(smcId, pParams, pOutSmcHandle);
}
int itv_smc_close( itv_handle_t handle ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_close(handle);
}
int itv_smc_reset( itv_handle_t handle, unsigned char* pMsgATR, unsigned int* msglength, unsigned char coldreset ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_reset(handle, pMsgATR, msglength, coldreset);
}
int itv_smc_transfer_data( itv_handle_t handle, const unsigned char* pReqdata, unsigned int reqlen, unsigned char* pRepdata, unsigned int* replen, unsigned short int* pStatusword ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_transfer_data(handle, pReqdata, reqlen, pRepdata, replen, pStatusword);
}
int itv_smc_send( itv_handle_t handle, const unsigned char* pBuffer, unsigned int numToWrite, unsigned int* pNumberWritten, unsigned int timeout ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_send(handle, pBuffer, numToWrite, pNumberWritten, timeout);
}
int itv_smc_receive( itv_handle_t handle, unsigned char* pBuffer, unsigned int numberToRead, unsigned int* pNumberReaded, unsigned int timeout ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_receive(handle, pBuffer, numberToRead, pNumberReaded, timeout);
}
int itv_smc_get_info( itv_handle_t handle, itv_smc_info_t* pOutSmcInfo ) {
    return remote_itv_smc_module_client::Instance()->itv_smc_get_info(handle, pOutSmcInfo);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
