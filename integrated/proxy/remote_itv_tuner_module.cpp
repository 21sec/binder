/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_tuner_module.sidl
 */
 

#define LOG_TAG     "remote_itv_tuner_module"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "itv_defines.h"
#include "itv_tuner.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_PROXY);


#define SERVICE_DESCRIPTOR                      "6a0184de-130f-11e5-b102-d4ae5265f343"
#define SERVICE_NAME                            "remote_itv_tuner_module"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_itv_tuner_get_device_count FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_itv_tuner_lock FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_itv_tuner_get_lock_state FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_itv_tuner_get_signal_quality FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_itv_tuner_get_signal_strength FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_itv_tuner_get_signal_ber FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_itv_tuner_get_signal_level FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_itv_tuner_get_signal_snr FIRST_CALL_TRANSACTION + 8

using namespace sita_android;

#if defined(BINDER_SERVICE)

#define CLOG_TAG "remote_itv_tuner_module"

#include <stdlib.h>

#include "clog.h"
#include "remote_itv_tuner_module.h"

class remote_itv_tuner_module_service : public BBinder  
{  
private:
    static remote_itv_tuner_module_service* _instance;

    remote_itv_tuner_module_service(){
        // TOSLOGI(SERVICE_NAME"_service create\n");
    }
    
    virtual ~remote_itv_tuner_module_service() {
        // TOSLOGI(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new remote_itv_tuner_module_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            // TOSLOGI(SERVICE_NAME"_service Instance ret = %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
		//TOSLOGI(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_itv_tuner_get_device_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_device_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer count is not NULL.
                int _cnt = 0;
                int* count = (_flag > 0) ? &_cnt : NULL;

                int _result = itv_tuner_get_device_count( count );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0) {
					reply->writeInt32(*count); //int as return value
                }

                //-- end code for itv_tuner_get_device_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_lock:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_lock here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

				int _flag = data.readInt32();	 // Just a flag.  if this flag >0, then can tell that the pointer delivery is not NULL.
				itv_delivery_t _delivery_Struct;
				memset(&_delivery_Struct,0,sizeof(itv_delivery_t));
				const itv_delivery_t* delivery = NULL;

				if(_flag > 0) {
					_delivery_Struct.type = (itv_delivery_type_t)data.readInt32();  //itv_delivery_type_t as input paramter
					if(_delivery_Struct.type == E_ITV_TUNER_TYPE_CABLE) {
						_delivery_Struct.delivery.cable.frequency = (unsigned int)data.readInt32();
						_delivery_Struct.delivery.cable.symbol = (unsigned int)data.readInt32();
						_delivery_Struct.delivery.cable.modulation = (itv_qam_mode_t)data.readInt32();
					}else if(_delivery_Struct.type == E_ITV_TUNER_TYPE_DTMB) {
						_delivery_Struct.delivery.dtmb.frequency = (unsigned int)data.readInt32();
					}
						
					delivery = &_delivery_Struct;
				}
				
				int _result = itv_tuner_lock( tunerId, delivery );

                reply->writeInt32(_result); //int as return value

                //-- end code for itv_tuner_lock here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_lock_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_lock_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter
				
				int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer state is not NULL.
				itv_bool_t _state = ITV_FALSE;
                itv_bool_t* state = (_flag > 0) ? &_state : NULL;

                int _result = itv_tuner_get_lock_state( tunerId, state );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0) {
					reply->writeInt32(*state); 
                }

                //-- end code for itv_tuner_get_lock_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_signal_quality:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_signal_quality here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

				int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer quality is not NULL.
				int _quality = 0;
                int* quality = (_flag > 0) ? &_quality : NULL;

                int _result = itv_tuner_get_signal_quality( tunerId, quality );

                reply->writeInt32(_result); //int as return value
				if(_flag > 0){
					reply->writeInt32(*quality);
				}
					
                //-- end code for itv_tuner_get_signal_quality here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_signal_strength:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_signal_strength here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

                int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer strength is not NULL.
				int _strength = 0;
                int* strength = (_flag > 0) ? &_strength : NULL;
                
                int _result = itv_tuner_get_signal_strength( tunerId, strength );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0){
					reply->writeInt32(*strength);
				}
		
                //-- end code for itv_tuner_get_signal_strength here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_signal_ber:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_signal_ber here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

				int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer ber is not NULL.
				float _ber = 0;
                float* ber = (_flag > 0) ? &_ber : NULL;
                
                int _result = itv_tuner_get_signal_ber( tunerId, ber );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0){
					reply->writeFloat(*ber);	// Float as a Int32 return value
				}

                //-- end code for itv_tuner_get_signal_ber here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_signal_level:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_signal_level here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

				int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer level is not NULL.
				int _level = 0;
                int* level = (_flag > 0) ? &_level : NULL;

                int _result = itv_tuner_get_signal_level( tunerId, level );

                reply->writeInt32(_result); //int as return value
                if(_flag > 0){
					reply->writeInt32(*level);	
				}

                //-- end code for itv_tuner_get_signal_level here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_itv_tuner_get_signal_snr:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for itv_tuner_get_signal_snr here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int tunerId = (int)data.readInt32();  //int as input paramter

				int _flag = data.readInt32(); // Just a flag.  if this flag >0, then can tell that the pointer snr is not NULL.
				int _snr = 0;
                int* snr = (_flag > 0) ? &_snr : NULL;
				
                int _result = itv_tuner_get_signal_snr( tunerId, snr );

                reply->writeInt32(_result); //int as return value
                
				if(_flag > 0){
					reply->writeInt32(*snr);	
				}

                //-- end code for itv_tuner_get_signal_snr here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

		// TOSLOGI(SERVICE_NAME"_service end\n");
    }
}; 

int remote_itv_tuner_module_service_add() {
    remote_itv_tuner_module_service::Instance();
    return 0;
}

remote_itv_tuner_module_service* remote_itv_tuner_module_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#define CLOG_TAG "remote_itv_tuner_module"

#include "clog.h"

class remote_itv_tuner_module_client  
{  
private:
    static remote_itv_tuner_module_client* _instance;
    sp<IBinder> _binder;

    remote_itv_tuner_module_client()
        :_binder(NULL) {
        // TOSLOGI(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~remote_itv_tuner_module_client() {
        // TOSLOGI(SERVICE_NAME"_client destory\n");
    }

    inline bool getService(void) {
        if(_binder == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
            _binder = sm->getService(String16(SERVICE_NAME));
        }

        if(_binder == NULL) {
            // TOSLOGI(SERVICE_NAME"_client getFailed!\n");
        }

        return (_binder != NULL);
    }

public:  
    static remote_itv_tuner_module_client* Instance() {
        if(_instance == NULL) {
            // TOSLOGI(SERVICE_NAME"_client Instance\n");
            _instance = new remote_itv_tuner_module_client();
        }

        return _instance;
    }

    int itv_tuner_get_device_count( int* count ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_device_count()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_device_count here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_tuner_get_device_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                
                _result = (typeof(_result))reply.readInt32();//int as return value

				if (count != NULL) {
                    *count = reply.readInt32(); //read length, only 32bits length support yet
                }

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_device_count error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_device_count error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_device_count here --*/
    }

    int itv_tuner_lock( int tunerId, const itv_delivery_t* delivery ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_lock()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_lock here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

			if (delivery == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_delivery_t));	//write length, only support 32 bits length yet
                
                data.writeInt32(delivery->type);
				if(delivery->type == E_ITV_TUNER_TYPE_CABLE){
					data.writeInt32(delivery->delivery.cable.frequency);
					data.writeInt32(delivery->delivery.cable.symbol);
					data.writeInt32(delivery->delivery.cable.modulation);
				}else if(delivery->type == E_ITV_TUNER_TYPE_DTMB){
					data.writeInt32(delivery->delivery.dtmb.frequency);
				}
            }
			
            _binder->transact(TRANSACTION_itv_tuner_lock,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
			
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_lock error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_lock error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_lock here --*/
    }

    int itv_tuner_get_lock_state( int tunerId, itv_bool_t* state ) {
		//TOSLOGI(SERVICE_NAME"_client itv_tuner_get_lock_state()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_lock_state here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            if (state == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_lock_state state = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(itv_bool_t));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_itv_tuner_get_lock_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				_result = (typeof(_result))reply.readInt32();//int as return value

                if (state != NULL) {
                    *state = (itv_bool_t)reply.readInt32(); //read length, only 32bits length support yet
                }
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_lock_state error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_lock_state error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_lock_state here --*/
    }

    int itv_tuner_get_signal_quality( int tunerId, int* quality ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_signal_quality()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_signal_quality here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (quality == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_quality quality = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
            }
			
            _binder->transact(TRANSACTION_itv_tuner_get_signal_quality,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                
                _result = (typeof(_result))reply.readInt32();//int as return value

				if (quality != NULL) {
                    *quality = (int)reply.readInt32(); //read length, only 32bits length support yet
                }

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_quality error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_signal_quality error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_signal_quality here --*/
    }

    int itv_tuner_get_signal_strength( int tunerId, int* strength ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_signal_strength()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_signal_strength here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (strength == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_strength strength = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet                
            }

            _binder->transact(TRANSACTION_itv_tuner_get_signal_strength,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				_result = (typeof(_result))reply.readInt32();//int as return value

				if (strength != NULL) {
                    *strength = (int)reply.readInt32(); //read length, only 32bits length support yet
                }
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_strength error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_signal_strength error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_signal_strength here --*/
    }

    int itv_tuner_get_signal_ber( int tunerId, float* ber ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_signal_ber()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_signal_ber here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (ber == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_ber ber = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(float));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_tuner_get_signal_ber,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if (ber != NULL) {
                    *ber = (float)reply.readFloat(); //read length, only 32bits length support yet
                }
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_ber error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_signal_ber error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_signal_ber here --*/
    }

    int itv_tuner_get_signal_level( int tunerId, int* level ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_signal_level()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_signal_level here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (level == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_level level = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_tuner_get_signal_level,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if (level != NULL) {
                    *level = reply.readInt32(); //read length, only 32bits length support yet
                }

            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_level error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_signal_level error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_signal_level here --*/
    }

    int itv_tuner_get_signal_snr( int tunerId, int* snr ) {
		// TOSLOGI(SERVICE_NAME"_client itv_tuner_get_signal_snr()\n");
        Parcel data, reply;

        /*-- add you code for itv_tuner_get_signal_snr here --*/
        int _result = ITV_ERR_FAILED;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(tunerId);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (snr == NULL) {
                data.writeInt32(-1);
				// TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_snr snr = NULL !!!\n");
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
            }

            _binder->transact(TRANSACTION_itv_tuner_get_signal_snr,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

				if (snr != NULL) {
                    *snr = reply.readInt32(); //read length, only 32bits length support yet
                }
            } else {
                // TOSLOGW(SERVICE_NAME"_client itv_tuner_get_signal_snr error\n");
            }
        }catch(...) {
            // TOSLOGE(SERVICE_NAME"_client itv_tuner_get_signal_snr error\n");
        }

        return _result;
        /*-- add you code for itv_tuner_get_signal_snr here --*/
    }
};

remote_itv_tuner_module_client* remote_itv_tuner_module_client::_instance = NULL;

int itv_tuner_get_device_count( int* count ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_device_count(count);
}
int itv_tuner_lock( int tunerId, const itv_delivery_t* delivery ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_lock(tunerId, delivery);
}
int itv_tuner_get_lock_state( int tunerId, itv_bool_t* state ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_lock_state(tunerId, state);
}
int itv_tuner_get_signal_quality( int tunerId, int* quality ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_signal_quality(tunerId, quality);
}
int itv_tuner_get_signal_strength( int tunerId, int* strength ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_signal_strength(tunerId, strength);
}
int itv_tuner_get_signal_ber( int tunerId, float* ber ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_signal_ber(tunerId, ber);
}
int itv_tuner_get_signal_level( int tunerId, int* level ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_signal_level(tunerId, level);
}
int itv_tuner_get_signal_snr( int tunerId, int* snr ) {
    return remote_itv_tuner_module_client::Instance()->itv_tuner_get_signal_snr(tunerId, snr);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
