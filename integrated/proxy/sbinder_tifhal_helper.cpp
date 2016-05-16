/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_tifhal_helper.sidl
 */
 

#define LOG_TAG     "sbinder_tifhal_helper"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "tos_tifhal_helper.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "4df1a012-5ba8-11e5-a10a-005056a86db3"
#define SERVICE_NAME                            "sbinder_tifhal_helper"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_tifhal_hdmicec_init FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_tifhal_hdmicec_term FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_tifhal_hdmicec_add_logical_address FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_tifhal_hdmicec_clear_logical_address FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_tifhal_get_physical_address FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_tifhal_hdmicec_send_message FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_tifhal_hdmicec_add_callback FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_tifhal_hdmicec_remove_callback FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_tifhal_get_version FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_tifhal_get_vendor_id FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_tifhal_get_port_info FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_tifhal_hdmicec_set_option FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_tifhal_hdmicec_set_audio_return_channel FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_tifhal_hdmicec_is_connected FIRST_CALL_TRANSACTION + 14

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_tifhal_helper.h"

class sbinder_tifhal_helper_service : public BBinder  
{  
private:
    static sbinder_tifhal_helper_service* _instance;
	static sp<IBinder> _callback;
    sbinder_tifhal_helper_service(){
        TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_tifhal_helper_service() {
        TOSLOGI(SERVICE_NAME"_service destory\n");
    }

		static void tifhal_hdmicec_callback(int type, void* param, void *userdata) {
		TOSLOGI(SERVICE_NAME"_service tifhal_input_callback type=%d\n",type);
		
        if(_callback != NULL && _callback->isBinderAlive()) {
            Parcel data, reply;
            data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
			
            data.writeInt32(type);

			//note:this module need be called from 64bits process to 32bits, so we should not use memcpy
			switch(type) {
				case TOS_TIFHAL_HDMICEC_EVENT_CEC_MESSAGE:
				 {
					ST_FPP_CEC_RX_DATA_T * rxData = (ST_FPP_CEC_RX_DATA_T*)param;
					TOSLOGI("tifhal_hdmicec_callback un8TxLogAddr=%d un8RxLogAddr=%d un8Msg=0x%x un8DataLen=%d \n",rxData->un8TxLogAddr,rxData->un8RxLogAddr,rxData->un8Msg,rxData->un8DataLen);
					data.writeInt32(rxData->un8TxLogAddr);
					data.writeInt32(rxData->un8RxLogAddr);
					data.writeInt32(rxData->un8Msg);
					data.writeInt32(rxData->un8DataLen);
					data.write(rxData->arrun8Operand, FPI_CEC_MAX_OPERAND_BYTES);
					data.write(rxData->arrun8Reserved, FPI_CEC_RESERVED_BYTES);
				}
				break;
			
				case TOS_TIFHAL_HDMICEC_EVENT_HOT_PLUG:
				{
					TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T * result = (TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T*)param;					
					TOSLOGI("tifhal_hdmicec_callback connected=%d portId=%d\n",result->connected,result->portId);
					data.writeInt32(result->connected);
					data.writeInt32(result->portId);
				}
				break;

				default:
					CLOG_ASSERT(0,"tifhal_hdmicec_callback client unknown msg type %d",type);
			}			
			
            _callback->transact(TRANSACTION_tos_tifhal_hdmicec_add_callback, data, &reply, 0);

            int err = reply.readExceptionCode();
			CLOG_ASSERT(err == 0,SERVICE_NAME"_callback exception %d",err);
        }
	}
		
public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_tifhal_helper_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            TOSLOGI(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        TOSLOGI(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_tifhal_hdmicec_init:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_init here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_init(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_init here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_term:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_term here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_term(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_term here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_add_logical_address:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_add_logical_address here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPP_CEC_DEVICE_LOG_ADDR_T addr = (EN_FPP_CEC_DEVICE_LOG_ADDR_T)data.readInt32();  //EN_FPP_CEC_DEVICE_LOG_ADDR_T as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_add_logical_address( addr );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_add_logical_address here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_clear_logical_address:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_clear_logical_address here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_clear_logical_address(  );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_clear_logical_address here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_get_physical_address:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_get_physical_address here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _physicalAddress_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* physicalAddress = NULL;

                Parcel::WritableBlob _physicalAddress_wblob;

                if(_physicalAddress_len > 0) {
                    reply->writeInt32(_physicalAddress_len);
                    reply->writeBlob(_physicalAddress_len,&_physicalAddress_wblob);
                    physicalAddress = (uint16_t*)_physicalAddress_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                physicalAddress = (uint16_t*)_physicalAddress_wblob.data();
                int _result = tos_tifhal_get_physical_address( physicalAddress );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_get_physical_address here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_send_message:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_send_message here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _msg_len = data.readInt32(); //read length, only 32bits length support yet
                ST_FPP_CEC_RX_DATA_T* msg = NULL;

                Parcel::ReadableBlob _msg_rblob;

                if(_msg_len > 0) {
                    data.readBlob(_msg_len,&_msg_rblob);
                    msg = (ST_FPP_CEC_RX_DATA_T*)_msg_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                msg = (ST_FPP_CEC_RX_DATA_T*)_msg_rblob.data();
                int _result = tos_tifhal_hdmicec_send_message( msg );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_send_message here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_tifhal_hdmicec_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				//begin paramters list
             	sp<IBinder> binder = data.readStrongBinder();

				sp<IBinder> _oldcb = _callback;
				_callback = binder;
                //begin paramters list
            //#error not support this type of paramter tos_tifhal_hdmicec_callback callback yet, please add code yourself

            //#error not support this type of paramter void userdata yet, please add code yourself

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_add_callback( tifhal_hdmicec_callback, NULL );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
       
            case TRANSACTION_tos_tifhal_hdmicec_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                sp<IBinder> binder = data.readStrongBinder();

				sp<IBinder> _oldcb = _callback;
				_callback = binder;
           // #error not support this type of paramter tos_tifhal_hdmicec_callback callback yet, please add code yourself

           // #error not support this type of paramter void userdata yet, please add code yourself

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_remove_callback( tifhal_hdmicec_callback, NULL );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
        
            case TRANSACTION_tos_tifhal_get_version:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_get_version here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _cecVersion_len = data.readInt32(); //read length, only 32bits length support yet
                int* cecVersion = NULL;

                Parcel::WritableBlob _cecVersion_wblob;

                if(_cecVersion_len > 0) {
                    reply->writeInt32(_cecVersion_len);
                    reply->writeBlob(_cecVersion_len,&_cecVersion_wblob);
                    cecVersion = (int*)_cecVersion_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                cecVersion = (int*)_cecVersion_wblob.data();
                int _result = tos_tifhal_get_version( cecVersion );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_get_version here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_get_vendor_id:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_get_vendor_id here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _vendorId_len = data.readInt32(); //read length, only 32bits length support yet
                int* vendorId = NULL;

                Parcel::WritableBlob _vendorId_wblob;

                if(_vendorId_len > 0) {
                    reply->writeInt32(_vendorId_len);
                    reply->writeBlob(_vendorId_len,&_vendorId_wblob);
                    vendorId = (int*)_vendorId_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                vendorId = (int*)_vendorId_wblob.data();
                int _result = tos_tifhal_get_vendor_id( vendorId );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_get_vendor_id here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_get_port_info:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_get_port_info here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _portInfo_len = data.readInt32(); //read length, only 32bits length support yet
                TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T* portInfo = NULL;

                Parcel::WritableBlob _portInfo_wblob;

                if(_portInfo_len > 0) {
                    reply->writeInt32(_portInfo_len);
                    reply->writeBlob(_portInfo_len,&_portInfo_wblob);
                    portInfo = (TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T*)_portInfo_wblob.data();
                }

                int maxCount = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                portInfo = (TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T*)_portInfo_wblob.data();
                int _result = tos_tifhal_get_port_info( portInfo, maxCount );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_get_port_info here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_set_option:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_set_option here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int flag = (int)data.readInt32();  //int as input paramter

                int value = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_set_option( flag, value );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_set_option here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_set_audio_return_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_set_audio_return_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int portId = (int)data.readInt32();  //int as input paramter

                int flag = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_set_audio_return_channel( portId, flag );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_set_audio_return_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_tifhal_hdmicec_is_connected:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_tifhal_hdmicec_is_connected here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int portId = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                int _result = tos_tifhal_hdmicec_is_connected( portId );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_tifhal_hdmicec_is_connected here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        TOSLOGI(SERVICE_NAME"_service end");
    }
}; 

int sbinder_tifhal_helper_service_add() {
    sbinder_tifhal_helper_service::Instance();
    return 0;
}

sbinder_tifhal_helper_service* sbinder_tifhal_helper_service::_instance = NULL;
sp<IBinder> sbinder_tifhal_helper_service::_callback = NULL;


#elif defined(BINDER_CLIENT)
#include <sbinder/ICallbackList.h>

class sbinder_tifhal_helper_client  
{  
private:
    static sbinder_tifhal_helper_client* _instance;
    sp<IBinder> _binder;

	class Callback;

	sp<Callback> _callback;
	
    sbinder_tifhal_helper_client()
        :_binder(NULL) ,_callback(NULL){
        TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_tifhal_helper_client() {
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
            TOSLOGV(SERVICE_NAME"_client onTransact code=%d\n",code);

            switch (code){
            case TRANSACTION_tos_tifhal_hdmicec_add_callback:{
                if (!data.checkInterface(this)) {
                    TOSLOGW(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
                    int type = (int)data.readInt32();  //int as input paramter
					
					switch(type) 
					{
						case TOS_TIFHAL_HDMICEC_EVENT_CEC_MESSAGE:{
							ST_FPP_CEC_RX_DATA_T rxData;
							memset(&rxData,0,sizeof(rxData));
							rxData.un8TxLogAddr = (int)data.readInt32();
							rxData.un8RxLogAddr = (int)data.readInt32();
							rxData.un8Msg = (int)data.readInt32();
							rxData.un8DataLen = (int)data.readInt32();
							(int)data.read(rxData.arrun8Operand,FPI_CEC_MAX_OPERAND_BYTES);
							(int)data.read(rxData.arrun8Reserved, FPI_CEC_RESERVED_BYTES);
							TOSLOGI("tos_tifhal_hdmicec_callback client un8TxLogAddr=%d un8RxLogAddr=%d un8Msg=0x%x un8DataLen=%d \n",rxData.un8TxLogAddr,rxData.un8RxLogAddr,rxData.un8Msg,rxData.un8DataLen);

							((tos_tifhal_hdmicec_callback)_callback)(type,&rxData,_cookie);
						}
						break;
					
						case TOS_TIFHAL_HDMICEC_EVENT_HOT_PLUG:
						 {
							TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T result;
							memset(&result,0,sizeof(result));
							result.connected = (int)data.readInt32();
							result.portId = (int)data.readInt32();
							
							TOSLOGI("tifhal_hdmicec_callback connected=%d portId=%d\n",result.connected,result.portId);
							
							((tos_tifhal_hdmicec_callback)_callback)(type,&result,_cookie);
						}
						break;

						default:
							CLOG_ASSERT(0,"tos_tifhal_hdmicec_callback client unknown msg type %d",type);							
							((tos_tifhal_hdmicec_callback)_callback)(type,NULL,_cookie);
						break;
					}			

                    reply->writeNoException();
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
    static sbinder_tifhal_helper_client* Instance() {
        if(_instance == NULL) {
            TOSLOGI(SERVICE_NAME"_client Instance");
            _instance = new sbinder_tifhal_helper_client();
        }

        return _instance;
    }

    int tos_tifhal_hdmicec_init(  ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_init here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_init,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_init error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_init error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_init here --*/
    }

    int tos_tifhal_hdmicec_term(  ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_term here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_term,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_term error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_term error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_term here --*/
    }

    int tos_tifhal_hdmicec_add_logical_address( EN_FPP_CEC_DEVICE_LOG_ADDR_T addr ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_add_logical_address here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(addr);  //EN_FPP_CEC_DEVICE_LOG_ADDR_T as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_add_logical_address,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_add_logical_address error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_add_logical_address error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_add_logical_address here --*/
    }

    int tos_tifhal_hdmicec_clear_logical_address(  ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_clear_logical_address here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_clear_logical_address,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_clear_logical_address error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_clear_logical_address error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_clear_logical_address here --*/
    }

    int tos_tifhal_get_physical_address( uint16_t* physicalAddress ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_get_physical_address here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (physicalAddress == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_tifhal_get_physical_address,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (physicalAddress != NULL) {
                    int _physicalAddress_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _physicalAddress_rblob;
                    reply.readBlob(_physicalAddress_len,&_physicalAddress_rblob);
                    memcpy(physicalAddress,_physicalAddress_rblob.data(),_physicalAddress_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_physical_address error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_physical_address error");
        }

        return _result;
        /*-- add you code for tos_tifhal_get_physical_address here --*/
    }

    int tos_tifhal_hdmicec_send_message( ST_FPP_CEC_RX_DATA_T* msg ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_send_message here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (msg == NULL) {
                data.writeInt32(-1);
            }
            else {
				int lenght = 1;
                data.writeInt32((int)((lenght)) * sizeof(ST_FPP_CEC_RX_DATA_T));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _msg_wblob;
                data.writeBlob(((lenght)) * sizeof(ST_FPP_CEC_RX_DATA_T),&_msg_wblob);
                memcpy(_msg_wblob.data(),msg,((lenght))* sizeof(ST_FPP_CEC_RX_DATA_T));
            }

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_send_message,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_send_message error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_send_message error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_send_message here --*/
    }

    int tos_tifhal_hdmicec_add_callback( tos_tifhal_hdmicec_callback callback, void* userdata ) {

		Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_add_callback here --*/
		int _result = TIFHAL_ERROR_OTHER_ERROR;
		
			  //
			  if(callback == NULL) {
				  CLOGW_WITHCODE(TIFHAL_ERROR_PARAMTER_ERROR," tos_tifhal_hdmicec_add_callback failed cb=%p ud=%p\n",callback,userdata);
				  return TIFHAL_ERROR_PARAMTER_ERROR;
			  }
			  
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

           // #error not support this type of paramter tos_tifhal_hdmicec_callback callback yet, please add code yourself

            //#error not support this type of paramter void userdata yet, please add code yourself
			sp<Callback> ccb = new Callback((void*)callback,userdata);
            data.writeStrongBinder(ccb);
		   
            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if(_result == TIFHAL_ERROR_NO_ERROR) {
					_callback = ccb;
					}

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_add_callback error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_add_callback error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_add_callback here --*/

return 0;
    }

    int tos_tifhal_hdmicec_remove_callback( tos_tifhal_hdmicec_callback callback, void* userdata ) {

		Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_remove_callback here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;


		if(callback == NULL) {
			CLOGW_WITHCODE(TIFHAL_ERROR_PARAMTER_ERROR,"remote tos_tifhal_hdmicec_remove_callback failed cb=%p ud=%p\n",callback,userdata);
			return TIFHAL_ERROR_PARAMTER_ERROR;
		}
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //#error not support this type of paramter tos_tifhal_hdmicec_callback callback yet, please add code yourself

            //#error not support this type of paramter void userdata yet, please add code yourself
			sp<Callback> ccb = new Callback((void*)callback,userdata);
            data.writeStrongBinder(ccb);
            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if(_result == TIFHAL_ERROR_NO_ERROR) {
					_callback = ccb;
				}

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_remove_callback error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_remove_callback error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_remove_callback here --*/

return 0;
    }

    int tos_tifhal_get_version( int* cecVersion ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_get_version here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (cecVersion == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_tifhal_get_version,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (cecVersion != NULL) {
                    int _cecVersion_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _cecVersion_rblob;
                    reply.readBlob(_cecVersion_len,&_cecVersion_rblob);
                    memcpy(cecVersion,_cecVersion_rblob.data(),_cecVersion_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_version error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_version error");
        }

        return _result;
        /*-- add you code for tos_tifhal_get_version here --*/
    }

    int tos_tifhal_get_vendor_id( int* vendorId ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_get_vendor_id here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (vendorId == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_tifhal_get_vendor_id,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (vendorId != NULL) {
                    int _vendorId_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _vendorId_rblob;
                    reply.readBlob(_vendorId_len,&_vendorId_rblob);
                    memcpy(vendorId,_vendorId_rblob.data(),_vendorId_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_vendor_id error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_vendor_id error");
        }

        return _result;
        /*-- add you code for tos_tifhal_get_vendor_id here --*/
    }

    int tos_tifhal_get_port_info( TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T* portInfo, int maxCount ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_get_port_info here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (portInfo == NULL) {
                data.writeInt32(-1);
            }
            else {
				int lenght = 1;
                data.writeInt32((int)((lenght)) * sizeof(TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(maxCount);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_get_port_info,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (portInfo != NULL) {
                    int _portInfo_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _portInfo_rblob;
                    reply.readBlob(_portInfo_len,&_portInfo_rblob);
                    memcpy(portInfo,_portInfo_rblob.data(),_portInfo_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_port_info error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_get_port_info error");
        }

        return _result;
        /*-- add you code for tos_tifhal_get_port_info here --*/
    }

    int tos_tifhal_hdmicec_set_option( int flag, int value ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_set_option here --*/
        int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(flag);  //int as input paramter

            data.writeInt32(value);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_set_option,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_set_option error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_set_option error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_set_option here --*/
    }

    int tos_tifhal_hdmicec_set_audio_return_channel( int portId, int flag ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_set_audio_return_channel here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(portId);  //int as input paramter

            data.writeInt32(flag);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_set_audio_return_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_set_audio_return_channel error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_set_audio_return_channel error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_set_audio_return_channel here --*/
    }

    int tos_tifhal_hdmicec_is_connected( int portId ) {
        Parcel data, reply;

        /*-- add you code for tos_tifhal_hdmicec_is_connected here --*/
         int _result = TIFHAL_ERROR_OTHER_ERROR;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(portId);  //int as input paramter

            _binder->transact(TRANSACTION_tos_tifhal_hdmicec_is_connected,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_is_connected error");
            }
        }catch(...) {
            TOSLOGW(SERVICE_NAME"_client tos_tifhal_hdmicec_is_connected error");
        }

        return _result;
        /*-- add you code for tos_tifhal_hdmicec_is_connected here --*/
    }
};

sbinder_tifhal_helper_client* sbinder_tifhal_helper_client::_instance = NULL;

int tos_tifhal_hdmicec_init(  ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_init();
}
int tos_tifhal_hdmicec_term(  ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_term();
}
int tos_tifhal_hdmicec_add_logical_address( EN_FPP_CEC_DEVICE_LOG_ADDR_T addr ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_add_logical_address(addr);
}
int tos_tifhal_hdmicec_clear_logical_address(  ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_clear_logical_address();
}
int tos_tifhal_get_physical_address( uint16_t* physicalAddress ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_get_physical_address(physicalAddress);
}
int tos_tifhal_hdmicec_send_message( ST_FPP_CEC_RX_DATA_T* msg ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_send_message(msg);
}
int tos_tifhal_hdmicec_add_callback( tos_tifhal_hdmicec_callback callback, void* userdata ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_add_callback(callback, userdata);
}
int tos_tifhal_hdmicec_remove_callback( tos_tifhal_hdmicec_callback callback, void* userdata ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_remove_callback(callback, userdata);
}
int tos_tifhal_get_version( int* cecVersion ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_get_version(cecVersion);
}
int tos_tifhal_get_vendor_id( int* vendorId ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_get_vendor_id(vendorId);
}
int tos_tifhal_get_port_info( TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T* portInfo, int maxCount ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_get_port_info(portInfo, maxCount);
}
int tos_tifhal_hdmicec_set_option( int flag, int value ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_set_option(flag, value);
}
int tos_tifhal_hdmicec_set_audio_return_channel( int portId, int flag ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_set_audio_return_channel(portId, flag);
}
int tos_tifhal_hdmicec_is_connected( int portId ) {
    return sbinder_tifhal_helper_client::Instance()->tos_tifhal_hdmicec_is_connected(portId);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
