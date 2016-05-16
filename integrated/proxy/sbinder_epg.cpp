/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_epg.sidl
 */
 

#define LOG_TAG     "sbinder_epg"

#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <sbinder/RemoteCallbackList.h>
#include <sbinder/ICallbackList.h>

#include "tos_epg.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_EPG);


#define SERVICE_DESCRIPTOR                      "4c9fc6be-acd8-11e4-9277-005056a84a3b"
#define SERVICE_NAME                            "sbinder_epg"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_epg_get_pf_events FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_epg_get_schedule_event_count FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_epg_get_schedule_events FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_epg_get_event_short_description FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_epg_get_event_extend_description FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_channel_enter_epg_check_epg_linkage FIRST_CALL_TRANSACTION + 6

#define TRANSACTION_tos_epg_add_callback FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_epg_remove_callback FIRST_CALL_TRANSACTION + 8

#define FIRST_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_callback FIRST_CALLBACK_TRANSACTION + 1


using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_epg.h"

class sbinder_epg_service : public BBinder  
{  
private:
    static sbinder_epg_service* _instance;
    RemoteCallbackList _cbList;
    bool _first;
    sbinder_epg_service():_first(true){
        fpi_trace(SERVICE_NAME"_service create");
    }
    
    virtual ~sbinder_epg_service() {
        fpi_trace(SERVICE_NAME"_service destory");
    }
    static int module_callback(int cb_type, int cb_code, int cb_data, void* userdata) {
        RemoteCallbackList* rcbl = &(_instance->_cbList);
        int _result = 0;
        int size = rcbl->beginBroadcast();
        for(int i=0;i<size;i++) {

            sp<IBinder> binder = rcbl->getBroadcastItem(i);

            if(binder != NULL) {
                Parcel data, reply;
                data.writeInterfaceToken(String16(SERVICE_NAME"_callback"));
                data.writeInt32(cb_type);
				data.writeInt32(cb_code);
				data.writeInt32(cb_data);

				if (userdata == NULL)
				{
					data.writeInt32(-1);
				}
				else
				{
					data.writeInt32((int)(1));//write length, only support 32 bits length yet
				}
                binder->transact(TRANSACTION_CALLBACK_callback, data, &reply, 0);

                if(reply.readExceptionCode() == 0) {//fix check
                    _result += reply.readInt32();//int as return value
                }
            }
        }
        rcbl->finishBroadcast();

        fpi_trace(SERVICE_NAME"_service module_callback end");
        return _result;
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            fpi_trace(SERVICE_NAME"_service Instance");
            _instance = new sbinder_epg_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_trace(SERVICE_NAME"_service ret = %d", ret);  
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_info(SERVICE_NAME"_service - onTransact code=%d",code);

        switch(code)  {

            case TRANSACTION_tos_epg_get_pf_events:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_pf_events here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int channelId = (int)data.readInt32();  //int as input paramter

				int event_len = data.readInt32();
                tos_event_info_t *eventList =NULL;
				Parcel::WritableBlob _pout_wblob;
				
				if(event_len > 0)
				{
					reply->writeInt32(event_len);
                    reply->writeBlob(event_len,&_pout_wblob);
                    eventList = (tos_event_info_t*)_pout_wblob.data();
				}
				
                int listSize = data.readInt32(); //read length, only 32bits length support yet;

                int _result = tos_epg_get_pf_events( channelId, eventList, &listSize );
				reply->writeInt32(listSize); //int as return value
                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_pf_events here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_epg_get_schedule_event_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_schedule_event_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int channelId = (int)data.readInt32();  //int as input paramter

                int startTime = (int)data.readInt64();  //int as input paramter

                int endTime = (int)data.readInt64();  //int as input paramter

                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                int* count = NULL;
				Parcel::WritableBlob _count_wblob;
				
                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (int*)_count_wblob.data();
                }

                int _result = tos_epg_get_schedule_event_count( channelId, startTime, endTime, count );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_schedule_event_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_epg_get_schedule_events:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_schedule_events here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int channelId = (int)data.readInt32();  //int as input paramter

                uint64_t startTime = (uint64_t)data.readInt64();  //uint64_t as input paramter

                int endTime = (int)data.readInt64();  //int as input paramter

				int event_len = data.readInt32();
				tos_event_info_t *eventList =NULL;
				Parcel::WritableBlob _pout_wblob;
				
				if(event_len > 0)
				{
					reply->writeInt32(event_len);
					reply->writeBlob(event_len,&_pout_wblob);
					eventList = (tos_event_info_t*)_pout_wblob.data();
				}
				
                int _listSize = data.readInt32(); //read length, only 32bits length support yet

                int _result = tos_epg_get_schedule_events( channelId, startTime, endTime, eventList, &_listSize );

				reply->writeInt32(_listSize); //int as return value
                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_schedule_events here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_epg_get_event_short_description:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_event_short_description here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int channelId = (int)data.readInt32();  //int as input paramter

                int eventid = (int)data.readInt32();  //int as input paramter

                int _description_len = data.readInt32(); //read length, only 32bits length support yet
                unsigned char* description = NULL;
				Parcel::WritableBlob _description_wblob;
				
                if(_description_len > 0) {
                    reply->writeInt32(_description_len);
                    reply->writeBlob(_description_len,&_description_wblob);
                    description = (unsigned char*)_description_wblob.data();
                }

                int descriptionLength = (int)data.readInt32();  //int as input paramter

                int _result = tos_epg_get_event_short_description( channelId, eventid, description, descriptionLength );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_event_short_description here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_epg_get_event_extend_description:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_event_extend_description here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int channelId = (int)data.readInt32();  //int as input paramter

                int eventid = (int)data.readInt32();  //int as input paramter

                int _description_len = data.readInt32(); //read length, only 32bits length support yet
                unsigned char* description = NULL;
				Parcel::WritableBlob _description_wblob;
				
                if(_description_len > 0) {
                    reply->writeInt32(_description_len);
                    reply->writeBlob(_description_len,&_description_wblob);
                    description = (unsigned char*)_description_wblob.data();
                }

                int descriptionLength = (int)data.readInt32();  //int as input paramter

                int _result = tos_epg_get_event_extend_description( channelId, eventid, description, descriptionLength );

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_event_extend_description here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
			
             case TRANSACTION_tos_channel_enter_epg_check_epg_linkage:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_get_event_extend_description here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
               	uint8_t epg_enter_flag = (uint8_t)data.readInt32();  //int as input paramter

                int _result = tos_channel_enter_epg_check_epg_linkage(epg_enter_flag);

                reply->writeInt32(_result); //int as return value

                //-- end code for tos_epg_get_event_extend_description here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;          
            case TRANSACTION_tos_epg_add_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_add_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
				sp<IBinder> binder = data.readStrongBinder();
				 if(binder != NULL) {
					int _userdata_len = data.readInt32(); //read length, only 32bits length support yet
	                void* userdata = NULL;
					Parcel::WritableBlob _description_wblob;
					
	                if(_userdata_len > 0) {
	                    reply->writeInt32(_userdata_len);
	                    reply->writeBlob(_userdata_len,&_description_wblob);
	                    userdata = (unsigned char*)_description_wblob.data();
	                }
                    int _result = 0;  
                    if(_first) {
                        _result = tos_epg_add_callback( sbinder_epg_service::module_callback,userdata);
                        if(_result == 0) {
                            _first = false;
                        }
                    }

                    if(_result == 0) {
                        if(_cbList.registerCallback(binder,NULL)) {
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

                //-- end code for tos_epg_add_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_epg_remove_callback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_epg_remove_callback here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                sp<IBinder> binder = data.readStrongBinder();

                if(_cbList.unregisterCallback(binder)) {
                    reply->writeNoException();
                    reply->writeInt32(0);//result
                }
                else {
                    reply->writeInt32(-1);//Exception
                }

                //-- end code for tos_epg_remove_callback here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_trace(SERVICE_NAME"_service end");
    }
}; 

int sbinder_epg_service_add() {
    sbinder_epg_service::Instance();
    return 0;
}

sbinder_epg_service* sbinder_epg_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_epg_client  
{  
private:
    static sbinder_epg_client* _instance;
    sp<IBinder> _binder;
    ICallbackList _CBList;
	
    sbinder_epg_client() {
        fpi_trace(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
    }
    
    virtual ~sbinder_epg_client() {
        fpi_trace(SERVICE_NAME"_client destory\n");
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
            case TRANSACTION_CALLBACK_callback:
            {
                if (!data.checkInterface(this)) {
                    fpi_warn(SERVICE_NAME"_client onTransact Interface error\n");
                    return -1;
                }

                if(_callback != NULL) {
                    int cb_type = (int)data.readInt32();  //int as input paramter
                    int cb_code = (int)data.readInt32();
					int cb_data = (int)data.readInt32();
					int userdata_len = data.readInt32();
	                void *userdata =NULL;
					Parcel::WritableBlob _pout_wblob;
					
					if(userdata_len > 0)
					{
						reply->writeInt32(userdata_len);
	                    reply->writeBlob(userdata_len,&_pout_wblob);
	                    userdata = (void*)_pout_wblob.data();
					}
                    int _result = ((tos_epg_update)_callback)(cb_type,cb_code,cb_data,userdata);

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
    static sbinder_epg_client* Instance() {
        if(_instance == NULL) {
            fpi_err(SERVICE_NAME"_client Instance");
            _instance = new sbinder_epg_client();
        }

        return _instance;
    }

    int tos_epg_get_pf_events( uint32_t channelId, tos_event_info_t* eventList, int* listSize ) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_pf_events here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

			if (eventList == NULL)
			{
				data.writeInt32(-1);
			}
			else
			{
				data.writeInt32((*listSize)*sizeof(tos_event_info_t));//write length, only support 32 bits length yet
			}
 
            //for out only, only write length ; for in, alloc and copy
            if (listSize == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(*listSize);//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_epg_get_pf_events,data, &reply,0);

            if(reply.readExceptionCode() == 0) 
			{//fix check

				if(eventList != NULL)
				{
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(eventList,_pout_rblob.data(),_pout_len);
				}

                if(listSize != NULL) 
				{
					*listSize = reply.readInt32();
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_pf_events error");
        }

        return _result;
        /*-- add you code for tos_epg_get_pf_events here --*/
    }

    int tos_epg_get_schedule_event_count( uint32_t channelId, uint64_t startTime, uint64_t endTime, int* count ) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_schedule_event_count here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

            data.writeInt64(startTime);  //int as input paramter

            data.writeInt64(endTime);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (count == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_epg_get_schedule_event_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_schedule_event_count error");
        }

        return _result;
        /*-- add you code for tos_epg_get_schedule_event_count here --*/
    }

    int tos_epg_get_schedule_events( uint32_t channelId, uint64_t startTime, uint64_t endTime, tos_event_info_t* eventList, int* listSize ) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_schedule_events here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

            data.writeInt64(startTime);  //uint64_t as input paramter

            data.writeInt64(endTime);  //int as input paramter

            if(eventList == NULL)
            {
            	data.writeInt32(-1);
            }
			else
			{
				data.writeInt32((*listSize) * sizeof(tos_event_info_t));//write length, only support 32 bits length yet
			}

            //for out only, only write length ; for in, alloc and copy
            if (listSize == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(*listSize);//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_epg_get_schedule_events,data, &reply,0);

            if(reply.readExceptionCode() == 0) 
			{//fix check
				if(eventList != NULL)
				{
                    int _pout_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pout_rblob;
                    reply.readBlob(_pout_len,&_pout_rblob);
                    memcpy(eventList,_pout_rblob.data(),_pout_len);
				}

                if (listSize != NULL) {
					*listSize = reply.readInt32();
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_schedule_events error");
        }

        return _result;
        /*-- add you code for tos_epg_get_schedule_events here --*/
    }

    int tos_epg_get_event_short_description( uint32_t channelId, int eventid, unsigned char* description, int descriptionLength ) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_event_short_description here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

            data.writeInt32(eventid);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (description == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(descriptionLength * sizeof(unsigned char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(descriptionLength);  //int as input paramter

            _binder->transact(TRANSACTION_tos_epg_get_event_short_description,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (description != NULL) {
                    int _description_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _description_rblob;
                    reply.readBlob(_description_len,&_description_rblob);
                    memcpy(description,_description_rblob.data(),_description_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_event_short_description error");
        }

        return _result;
        /*-- add you code for tos_epg_get_event_short_description here --*/
    }

    int tos_epg_get_event_extend_description( uint32_t channelId, int eventid, unsigned char* description, int descriptionLength ) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_event_extend_description here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(channelId);  //int as input paramter

            data.writeInt32(eventid);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (description == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32(descriptionLength * sizeof(unsigned char));//write length, only support 32 bits length yet
                
            }

            data.writeInt32(descriptionLength);  //int as input paramter

            _binder->transact(TRANSACTION_tos_epg_get_event_extend_description,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (description != NULL) {
                    int _description_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _description_rblob;
                    reply.readBlob(_description_len,&_description_rblob);
                    memcpy(description,_description_rblob.data(),_description_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_event_extend_description error");
        }

        return _result;
        /*-- add you code for tos_epg_get_event_extend_description here --*/
    }
    int tos_channel_enter_epg_check_epg_linkage(uint8_t enter_epg_flag) {
        Parcel data, reply;

        /*-- add you code for tos_epg_get_event_extend_description here --*/
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32((uint32_t)enter_epg_flag);  //int as input paramter

            _binder->transact(TRANSACTION_tos_channel_enter_epg_check_epg_linkage,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_epg_get_event_extend_description error");
        }

        return _result;
        /*-- add you code for tos_epg_get_event_extend_description here --*/
    }


    int tos_epg_add_callback( tos_epg_update callback, void* userdata ) {
        Parcel data, reply;

        /*-- add you code for cb_add here --*/
        int _result = -1;
        if(_binder == NULL || callback == NULL) {
            fpi_err(SERVICE_NAME"_client _binder or cb null");
            return _result;
        }

        if(_CBList.findCallback((void*)callback,NULL) != NULL) {
            fpi_err(SERVICE_NAME"_client cb arleady added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            sp<Callback> ccb = new Callback((void*)callback,NULL);
            data.writeStrongBinder(ccb);
            if (userdata == NULL) 
			{
                data.writeInt32(-1);
            }
            else 
			{
                data.writeInt32((int)(1));//write length, only support 32 bits length yet
                Parcel::WritableBlob _pin_wblob;
            	data.writeBlob((1),&_pin_wblob);
            	memcpy(_pin_wblob.data(),userdata,(1));
                
            }

            _binder->transact(TRANSACTION_tos_epg_add_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check
                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == 0) { //success
                    _CBList.addCallback(ccb);
                }
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client cb_add error");
        }

        return _result;
        /*-- add you code for cb_add here --*/
    }

    int tos_epg_remove_callback( tos_epg_update callback ) {
        Parcel data, reply;

        /*-- add you code for cb_remove here --*/
        int _result = -1;
        if(_binder == NULL || callback == NULL) {
            fpi_err(SERVICE_NAME"_client _binder or cb null");
            return _result;
        }

        sp<ICallbackList::ICallback> ccb = _CBList.findCallback((void*)callback,NULL);
        if( ccb == NULL) {
            fpi_err(SERVICE_NAME"_client cb not added");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeStrongBinder(ccb);

            _binder->transact(TRANSACTION_tos_epg_remove_callback,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

                if(_result == 0) { //success
                    _CBList.removeCallback(ccb);
                }
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client cb_remove error");
        }

        return _result;
        /*-- add you code for cb_remove here --*/
    }
};

sbinder_epg_client* sbinder_epg_client::_instance = NULL;

int tos_epg_get_pf_events( uint32_t channelId, tos_event_info_t* eventList, int* listSize ) {
    return sbinder_epg_client::Instance()->tos_epg_get_pf_events(channelId, eventList, listSize);
}
int tos_epg_get_schedule_event_count( uint32_t channelId, uint64_t startTime, uint64_t endTime, int* count ) {
    return sbinder_epg_client::Instance()->tos_epg_get_schedule_event_count(channelId, startTime, endTime, count);
}
int tos_epg_get_schedule_events( uint32_t channelId, uint64_t startTime, uint64_t endTime, tos_event_info_t* eventList, int* listSize ) {
    return sbinder_epg_client::Instance()->tos_epg_get_schedule_events(channelId, startTime, endTime, eventList, listSize);
}
int tos_epg_get_event_short_description( uint32_t channelId, int eventid, unsigned char* description, int descriptionLength ) {
    return sbinder_epg_client::Instance()->tos_epg_get_event_short_description(channelId, eventid, description, descriptionLength);
}
int tos_epg_get_event_extend_description( uint32_t channelId, int eventid, unsigned char* description, int descriptionLength ) {
    return sbinder_epg_client::Instance()->tos_epg_get_event_extend_description(channelId, eventid, description, descriptionLength);
}

int tos_channel_enter_epg_check_epg_linkage(uint8_t enter_epg_flag) {
    return sbinder_epg_client::Instance()->tos_channel_enter_epg_check_epg_linkage(enter_epg_flag);
}

int tos_epg_add_callback( tos_epg_update callback, void* userdata ) {
    return sbinder_epg_client::Instance()->tos_epg_add_callback(callback, userdata);
}
int tos_epg_remove_callback( tos_epg_update callback ) {
    return sbinder_epg_client::Instance()->tos_epg_remove_callback(callback);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
