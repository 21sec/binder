/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_clog_proxy.sidl
 */
 

#define LOG_TAG     "remote_clog_proxy"

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>



#include "clog.h"
#include "_clog.h"


#define SERVICE_DESCRIPTOR                      "525bc250-a09f-11e4-82b1-005056a84a3b"
#define SERVICE_NAME                            "remote_clog_proxy"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION__clog_write FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_clog_startlogsave FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_clog_stoplogsave FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_clog_setlevel FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_clog_addsavetriger FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_clog_removesavetriger FIRST_CALL_TRANSACTION + 6
#define TRANSACTION__clog_addsynccallback FIRST_CALL_TRANSACTION + 7
#define TRANSACTION__clog_removesynccallback FIRST_CALL_TRANSACTION + 8
#define TRANSACTION__clog_getTagTable FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_clog_getDefaultLevel FIRST_CALL_TRANSACTION + 10


#define FIRST_TRIGGER_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_Triger_callback FIRST_TRIGGER_CALLBACK_TRANSACTION + 1

#define FIRST_SYNC_CALLBACK_TRANSACTION                  (1)
#define TRANSACTION_CALLBACK_Sync_callback FIRST_SYNC_CALLBACK_TRANSACTION + 1



using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "remote_clog_proxy.h"
#include <sbinder/RemoteCallbackList.h>

extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);


class remote_clog_proxy_service : public BBinder  
{  
private:
	class RemoteCallbackListClog: public RemoteCallbackList
	{
	public:
		void onCallbackDied(sp<IBinder> binder,void* cookie) {
			CLOG_PRINT("onCallbackDied cookie(filterstring):%s\n",(char*)cookie);
			clog_removesavetriger( (char*) cookie, remote_clog_proxy_service::Triger_callback,binder.get());
			_clog_removesynccallback( remote_clog_proxy_service::Sync_callback ,binder.get() );
			if (cookie != NULL){
				free((char*)cookie);
			}
		}
	};

	
    static remote_clog_proxy_service* _instance;
	RemoteCallbackListClog _Triger_cbList;
	RemoteCallbackListClog _Sync_cbList;
    bool _first;

    remote_clog_proxy_service():
		_first(false){
        CLOG_PRINT(SERVICE_NAME"_service create");
    }
    
    virtual ~remote_clog_proxy_service() {
        CLOG_PRINT(SERVICE_NAME"_service destory");
    }

    static void Triger_callback(const char* tag,int level,const char* log,const char *filterString,void* userdata) {
		CLOG_PRINT("Triger_callback \n");
		RemoteCallbackListClog* rcbl = &(_instance->_Triger_cbList);
		IBinder* orgBinder = (IBinder* )userdata;
		int size = rcbl->beginBroadcast();
		for(int i=0;i<size;i++) {

			sp<IBinder> binder = rcbl->getBroadcastItem(i);
			if (binder.get() == orgBinder){
				if(binder != NULL && binder->isBinderAlive() == true) {
		            Parcel data, reply;
					data.writeInterfaceToken(String16(SERVICE_NAME"trigger_callback"));//lihui:name
		            data.writeCString(tag);
					data.writeInt32(level);
		            data.writeCString(log);
		            data.writeCString(filterString);
					CLOG_PRINT("Triger_callback do transact \n");
		            binder->transact(TRANSACTION_CALLBACK_Triger_callback, data, &reply, 0);
		            if(reply.readExceptionCode() == 0) {
		                reply.readInt32();
		            }
		        }
			}
		}
		rcbl->finishBroadcast();
        CLOG_PRINT(SERVICE_NAME"trigger_callback Triger_callback end");
    }	

	static void Sync_callback(const char* tag,int level,void* userdata) {
		RemoteCallbackListClog* rcbl = &(_instance->_Sync_cbList);
		IBinder* orgBinder = (IBinder*)userdata;
		int size = rcbl->beginBroadcast();
		for(int i=0;i<size;i++) {
			sp<IBinder> binder = rcbl->getBroadcastItem(i);
			if (binder.get() == orgBinder){
				if(binder != NULL && binder->isBinderAlive() == true) {
		            Parcel data, reply;
					data.writeInterfaceToken(String16(SERVICE_NAME"sync_callback"));//lihui:name
		            data.writeCString(tag);
					data.writeInt32(level);
					binder->transact(TRANSACTION_CALLBACK_Sync_callback, data, &reply, 0);
					if(reply.readExceptionCode() == 0) {
		                reply.readInt32();
		            }
		        }
			}
		}
		rcbl->finishBroadcast();
        CLOG_PRINT(SERVICE_NAME"sync_callback Triger_callback end");
	}

public:  
    static int Instance() {
        if(_instance == NULL) {
            CLOG_PRINT(SERVICE_NAME"_service Instance");
            _instance = new remote_clog_proxy_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            CLOG_PRINT("_service ret = %d", ret);  
            return ret;  
        }

        return -1;
    }

	static bool tag_foreach_callback(void* tag,void* level,void* context){
		Parcel* reply = (Parcel* )context;
		reply->writeCString((const char*)tag);
		reply->writeInt32((intptr_t)level);
		return 1;
	}
	
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        CLOG_PRINT(SERVICE_NAME"_service - onTransact code=%d",code);
        switch(code)  {

            case TRANSACTION__clog_write:
            {
                data.enforceInterface(String16(SERVICE_NAME));  
                const char* tag = data.readCString();
                int level = (int)data.readInt32(); 
                const char* buf = data.readCString();
				CLOG_PRINT("transaction _clog_write ----");
                int _result = _clog_write( tag, level, buf );
				CLOG_PRINT("CLOG_TRANS_SERVER _clog_write aaaaa");
				reply->writeNoException();
				reply->writeInt32(_result);
                return NO_ERROR;
            } break;
            
            case TRANSACTION_clog_startlogsave:
            {
                data.enforceInterface(String16(SERVICE_NAME)); 
                const char* path = data.readCString();
                int rotateSize = (int)data.readInt32();
                int rotateCount = (int)data.readInt32(); 
                int _result = clog_startlogsave( path, rotateSize, rotateCount );
				reply->writeNoException();
				reply->writeInt32(_result); 
                return NO_ERROR;
            } break;
            
            case TRANSACTION_clog_stoplogsave:
            {
                data.enforceInterface(String16(SERVICE_NAME)); 
                reply->writeNoException();
                int _result = clog_stoplogsave(  );
                reply->writeInt32(_result);
                return NO_ERROR;
            } break;
            
            case TRANSACTION_clog_setlevel:
            {
                data.enforceInterface(String16(SERVICE_NAME));
                reply->writeNoException(); 
                const char* tag = data.readCString();
                int level = (int)data.readInt32(); 
                int _result = clog_setlevel( tag, level );
                reply->writeInt32(_result);
                return NO_ERROR;
            } break;
            
            case TRANSACTION_clog_addsavetriger:
            {
                data.enforceInterface(String16(SERVICE_NAME)); 
				reply->writeNoException();
                const char* filterString = strdup(data.readCString());
				CLOG_PRINT("TRANSACTION_clog_addsavetriger %s\n",filterString);
	            sp<IBinder> binder = data.readStrongBinder();
				if (_Triger_cbList.registerCallback(binder,(void*)filterString)){
	                int _result = clog_addsavetriger( filterString, remote_clog_proxy_service::Triger_callback, binder.get() );
	                reply->writeInt32(_result); 
				}else{
					CLOG_PRINT("_Triger_cbList registerCallback error\n");
					reply->writeInt32(-1); 
				}
                return NO_ERROR;
            } break;
            
            case TRANSACTION_clog_removesavetriger:
            {
                data.enforceInterface(String16(SERVICE_NAME)); 
				reply->writeNoException();
                const char* filterString = data.readCString();
          		sp<IBinder> binder = data.readStrongBinder();
				if(_Triger_cbList.unregisterCallback(binder)) {				
	                int _result = clog_removesavetriger( filterString, remote_clog_proxy_service::Triger_callback,binder.get());
					//binder->decStrong(binder.get());
	                reply->writeInt32(_result); 
				}else{
					CLOG_PRINT("_Triger_cbList unregisterCallback error\n");
					reply->writeInt32(-1);
				}
                return NO_ERROR;
            } break;
            

            case TRANSACTION__clog_addsynccallback:
            {
                data.enforceInterface(String16(SERVICE_NAME));  
				reply->writeNoException();
				sp<IBinder> binder = data.readStrongBinder();
				if (_Sync_cbList.registerCallback(binder,NULL)){		
					int _result = _clog_addsynccallback( remote_clog_proxy_service::Sync_callback, binder.get() );
					reply->writeInt32(_result);
				}else{
					CLOG_PRINT("_Sync_cbList.registerCallback error\n");
					reply->writeInt32(-1);
				}
                
                return NO_ERROR;
            } break;
            
            case TRANSACTION__clog_removesynccallback:
            {
                data.enforceInterface(String16(SERVICE_NAME));
                reply->writeNoException();
				sp<IBinder> binder = data.readStrongBinder();
				if(_Sync_cbList.unregisterCallback(binder)) {			
	                int _result = _clog_removesynccallback( remote_clog_proxy_service::Sync_callback ,binder.get() );
	                reply->writeInt32(_result);
				}else{
					CLOG_PRINT("_Sync_cbList.unregisterCallback error\n");
					reply->writeInt32(-1);
				}
                return NO_ERROR;
            } break;
            
            case TRANSACTION__clog_getTagTable:
            {
                data.enforceInterface(String16(SERVICE_NAME)); 
                reply->writeNoException();
                Hashmap* table  = _clog_share_getTagTable();
				int size = hashmapSize(table);
				reply->writeInt32(size );
				CLOG_PRINT("TRANSACTION__clog_getTagTable 4 %d\n",size);
				hashmapForEach(table,tag_foreach_callback,(void*)reply);
                return NO_ERROR;
            } break;
            case TRANSACTION_clog_getDefaultLevel:
			{
                data.enforceInterface(String16(SERVICE_NAME)); 
                reply->writeNoException();
                int defaultLevel  = _clog_share_getDefaultLevel();
				reply->writeInt32(defaultLevel);
                return NO_ERROR;
            } break;	
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }	
        CLOG_PRINT(SERVICE_NAME"_service end");
    }
}; 

int remote_clog_proxy_service_add() {
    remote_clog_proxy_service::Instance();
    return 0;
}

remote_clog_proxy_service* remote_clog_proxy_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

#include <sbinder/ICallbackList.h>


class remote_clog_proxy_client  
{  
private:
    static remote_clog_proxy_client* _instance;
    sp<IBinder> _binder;
	ICallbackList _trigger_CBList;
	ICallbackList _sync_CBList;

    remote_clog_proxy_client() {
        CLOG_PRINT(SERVICE_NAME"_client create\n");
        sp<IServiceManager> sm = defaultServiceManager();
        _binder = sm->getService(String16(SERVICE_NAME));
		
		CLOG_PRINT("CLOG_PRINT remote_clog_proxy_client %p\n",_binder.get());
    }
    
    virtual ~remote_clog_proxy_client() {
		
        CLOG_PRINT(SERVICE_NAME"_client destory\n");
    }


	class TriggerCallback : public ICallbackList::ICallback {
	public:
		TriggerCallback(void* cb,void* cookie)
			:ICallback(cb,cookie) {
			_descriptor = String16(SERVICE_NAME"trigger_callback");
		}

		virtual status_t onTransact( uint32_t code,
				const Parcel& data,Parcel* reply,uint32_t flags = 0) {
				
			CLOG_PRINT(SERVICE_NAME"_client TriggerCallback onTransact code=%d\n",code);
			switch (code){
			case TRANSACTION_CALLBACK_Triger_callback:
			{
				CLOG_PRINT("client callback transact\n");
				if (!data.checkInterface(this)) {
					CLOG_PRINT(SERVICE_NAME"_client TriggerCallback onTransact Interface error\n");
					return -1;
				}
				CLOG_PRINT("client callback transact 1\n");
				if(_callback != NULL) {
					const char* tag = data.readCString();
					int level = data.readInt32();
		            const char* log = data.readCString();
		            const char* filterString = data.readCString();
					CLOG_PRINT("client _callback do call triger %s,%d,%s,%s\n",tag,level,log,filterString);
					((clog_ontriger)_callback)(tag,level,log,filterString,_cookie);
					reply->writeNoException();
					reply->writeInt32(0);
				}
				else {
					CLOG_PRINT("client _callback is null\n");
					reply->writeInt32(-1);
				}
				break;
			}
			default:
				return BBinder::onTransact(code, data, reply, flags);
			}

			return NO_ERROR;
		}
	};
	
	class SyncCallback : public ICallbackList::ICallback {
	public:
		SyncCallback(void* cb,void* cookie)
			:ICallback(cb,cookie) {
			_descriptor = String16(SERVICE_NAME"sync_callback");
		}

		virtual status_t onTransact( uint32_t code,
				const Parcel& data,Parcel* reply,uint32_t flags = 0) {
			CLOG_PRINT(SERVICE_NAME"_client SyncCallback onTransact code=%d\n",code);
			switch (code){
			case TRANSACTION_CALLBACK_Sync_callback:
			{
				if (!data.checkInterface(this)) {
					CLOG_PRINT(SERVICE_NAME"_client SyncCallback onTransact Interface error\n");
					return -1;
				}
				if(_callback != NULL) {
					const char* tag = data.readCString();
					int level = (int)data.readInt32(); 
					((_clog_sync_callback)_callback)(tag,level,_cookie);
					reply->writeNoException();
					reply->writeInt32(0);
				}
				else {
					reply->writeInt32(-1);//Exception
				}
				break;
			}

			default:
				return BBinder::onTransact(code, data, reply, flags);
			}

			return NO_ERROR;
		}
	};


public:  
    static remote_clog_proxy_client* Instance() {
        if(_instance == NULL) {
            CLOG_PRINT("_client Instance");
            _instance = new remote_clog_proxy_client();
	 		_clog_init();
        }
        return _instance;
    }

    int _clog_write( const char* tag, int level, const char* buf ) {
        Parcel data, reply;
		int _result;
		CLOG_PRINT("clog write --------------tag = %s,level=%d,buf=%s\n",tag,level,buf);
        if(_binder == NULL) {
			sp<IServiceManager> sm = defaultServiceManager();
        	_binder = sm->getService(String16(SERVICE_NAME));
			if (_binder == NULL){
				CLOG_PRINT("clog write ----binder is null\n");
            	return -1;
			}
        }
		if (tag == NULL){
			CLOG_PRINT("clog write ----tag is null\n");
		}
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            data.writeCString(tag);
            data.writeInt32(level); 
            data.writeCString(buf);
			CLOG_PRINT("CLOG_PRINT	1111ccccc _clog_write\n");

            _binder->transact(TRANSACTION__clog_write,data, &reply,0);
			CLOG_PRINT("CLOG_PRINT	c2222cccc _clog_write\n");

            if(reply.readExceptionCode() == 0) {
				_result = (typeof(_result))reply.readInt32();
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client _clog_write error");
        }

		return 0;
    }

    int clog_startlogsave( const char* path, int rotateSize, int rotateCount ) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL||path == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
        	_binder = sm->getService(String16(SERVICE_NAME));
			if (_binder == NULL){
				CLOG_PRINT("clog stargtlogsave ----binder is null\n");
            	return -1;
			}
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            data.writeCString(path);

            data.writeInt32(rotateSize); 
            data.writeInt32(rotateCount);  
            _binder->transact(TRANSACTION_clog_startlogsave,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = reply.readInt32();
            }
        }catch(...) {	
            CLOG_PRINT(SERVICE_NAME"_client clog_startlogsave error");
        }
        fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
    }

    int clog_stoplogsave(  ) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL) {
            fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            _binder->transact(TRANSACTION_clog_stoplogsave,data, &reply,0);

            if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readInt32();
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client clog_stoplogsave error");
        }

        fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
    }

    int clog_setlevel( const char* tag, int level ) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL||tag == NULL) {
            sp<IServiceManager> sm = defaultServiceManager();
        	_binder = sm->getService(String16(SERVICE_NAME));
			if (_binder == NULL){
				CLOG_PRINT("clog setlevel ----binder is null\n");
            	return -1;
			}
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            data.writeCString(tag);
            data.writeInt32(level); 
            _binder->transact(TRANSACTION_clog_setlevel,data, &reply,0);
			if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readInt32();
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client clog_setlevel error");
        }
        return _result;
    }

    int clog_addsavetriger( const char* filterString, clog_ontriger triger, void* userdata ) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL || triger == NULL||filterString == NULL) {
            CLOG_PRINT(SERVICE_NAME"_client _binder or triger null");
            return -1;
        }
        try {
	        if(_trigger_CBList.findCallback((void*)triger,userdata) != NULL) {
	            CLOG_PRINT(SERVICE_NAME"_client cb arleady added");
	            return _result;
	        }
            data.writeInterfaceToken(String16(SERVICE_NAME));
            data.writeCString(filterString);
            sp<TriggerCallback> ccb = new TriggerCallback((void*)triger,userdata); 
            data.writeStrongBinder(ccb);
			_binder->transact(TRANSACTION_clog_addsavetriger,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readInt32();
                if(_result == 0) { 
                    _trigger_CBList.addCallback(ccb);
                }
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client clog_addsavetriger error");
        }

        return _result;
    }

    int clog_removesavetriger( const char* filterString, clog_ontriger triger ,void* userdata) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL || triger == NULL) {
            CLOG_PRINT(SERVICE_NAME"_client _binder or cb null");
            return _result;
    	}
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            data.writeCString(filterString);

	        sp<ICallbackList::ICallback> ccb = _trigger_CBList.findCallback((void*)triger,userdata);
	        if( ccb == NULL) {
	            CLOG_PRINT(SERVICE_NAME"_client cb not added");
	            return _result;
	        }
            data.writeStrongBinder(ccb);
            _binder->transact(TRANSACTION_clog_removesavetriger,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readExceptionCode();
                if(_result == 0) { 
                    _trigger_CBList.removeCallback(ccb);
                }
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client clog_removesavetriger error");
        }

        return _result;
    }

    int _clog_addsynccallback( _clog_sync_callback callback, void* userdata ) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL) {
             sp<IServiceManager> sm = defaultServiceManager();
        	_binder = sm->getService(String16(SERVICE_NAME));
			if (_binder == NULL){
				CLOG_PRINT("clog addsyncallback ----binder is null\n");
            	return -1;
			}
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
	        if(_sync_CBList.findCallback((void*)callback,userdata) != NULL) {	
	            CLOG_PRINT(SERVICE_NAME"_client cb arleady added");
	            return _result;
	        }
            sp<SyncCallback> ccb = new SyncCallback((void*)callback,userdata);
            data.writeStrongBinder(ccb);
            _binder->transact(TRANSACTION__clog_addsynccallback,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readExceptionCode();
				if(_result == 0) { //success
                    _sync_CBList.addCallback(ccb);
                }
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client _clog_addsynccallback error");
        }

        return _result;
    }

    int _clog_removesynccallback( _clog_sync_callback callback ,void* userdata) {
        Parcel data, reply;
        int _result = -1;
        if(_binder == NULL) {
            return _result;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
	        sp<ICallbackList::ICallback> ccb = _sync_CBList.findCallback((void*)callback,userdata);
	        if( ccb == NULL) {
	            CLOG_PRINT(SERVICE_NAME"_client cb not added");
	            return _result;
	        }
            _binder->transact(TRANSACTION__clog_removesynccallback,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = (typeof(_result))reply.readExceptionCode();
				if(_result == 0) { //success
                    _sync_CBList.removeCallback(ccb);
                }
            }
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client _clog_removesynccallback error");
        }

        return _result;
    }

	int  _clog_getTagTable(Hashmap* tagTable) {
        Parcel data, reply;
        int _result = 0;
		
			CLOG_PRINT("_clog_getTagTable 0\n");
        if(_binder == NULL) {
			
			 sp<IServiceManager> sm = defaultServiceManager();
        	_binder = sm->getService(String16(SERVICE_NAME));
			if (_binder == NULL){
				CLOG_PRINT("clog gettagtable ----binder is null\n");
            	return -1;
			}
        }
        try {
			CLOG_PRINT("_clog_getTagTable 1\n");
            data.writeInterfaceToken(String16(SERVICE_NAME));
            _binder->transact(TRANSACTION__clog_getTagTable,data, &reply,0);
			
			CLOG_PRINT("_clog_getTagTable 2\n");
            if(reply.readExceptionCode() == 0) {
				
			CLOG_PRINT("_clog_getTagTable 3\n");
                int size = reply.readInt32();
				
			CLOG_PRINT("_clog_getTagTable 4 %d\n",size);
				for (int i =0;i<size;i++){
					const char* key = reply.readCString();
					int level = reply.readInt32();
					CLOG_PRINT("_clog_getTagTable 5 -----------key=%s---level=%d-------\n",key,level);
					hashmapPut(tagTable,(void*)key,(void*)level);
				}
            }else{
				_result = - -1;
			}
        }catch(...) {	
            CLOG_PRINT(SERVICE_NAME"_client _clog_getTagTable error");
        }
        return _result;
    }

	int _clog_getDefaultLevel(){
		Parcel data, reply;
        int _result = 0;
        if(_binder == NULL) {
            return -1;
        }
        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));
            _binder->transact(TRANSACTION_clog_getDefaultLevel,data, &reply,0);
            if(reply.readExceptionCode() == 0) {
                _result = reply.readInt32();
            }else{
				_result = - -1;
			}
        }catch(...) {
            CLOG_PRINT(SERVICE_NAME"_client _clog_getTagTable error");
        }
        return _result;
	}
};

remote_clog_proxy_client* remote_clog_proxy_client::_instance = NULL;

int _clog_write( const char* tag, int level, const char* buf ) {
	CLOG_PRINT("CLOG_PRINT  ccccc _clog_write\n");
    return remote_clog_proxy_client::Instance()->_clog_write(tag, level, buf);
}
int clog_startlogsave( const char* path, int rotateSize, int rotateCount ) {
    return remote_clog_proxy_client::Instance()->clog_startlogsave(path, rotateSize, rotateCount);
}
int clog_stoplogsave(  ) {
    return remote_clog_proxy_client::Instance()->clog_stoplogsave();
}
int clog_setlevel( const char* tag, int level ) {
	CLOG_PRINT("CLOG_PRINT execcmdline ccccc clog_setlevel tag = %s,level=%d\n",tag,level);
    return remote_clog_proxy_client::Instance()->clog_setlevel(tag, level);
}
int clog_addsavetriger( const char* filterString, clog_ontriger triger, void* userdata ) {
    return remote_clog_proxy_client::Instance()->clog_addsavetriger(filterString, triger, userdata);
}
int clog_removesavetriger( const char* filterString, clog_ontriger triger ,void* userdata) {
    return remote_clog_proxy_client::Instance()->clog_removesavetriger(filterString, triger,userdata);
}
int _clog_addsynccallback( _clog_sync_callback callback, void* userdata ) {
    return remote_clog_proxy_client::Instance()->_clog_addsynccallback(callback, userdata);
}
int _clog_removesynccallback( _clog_sync_callback callback ,void* userdata) {
    return remote_clog_proxy_client::Instance()->_clog_removesynccallback(callback,userdata);
}

int _clog_getTagTable( Hashmap* tagTable ) {
    return remote_clog_proxy_client::Instance()->_clog_getTagTable(tagTable);
}

int _clog_getDefaultLevel(){
	return remote_clog_proxy_client::Instance()->_clog_getDefaultLevel();
}


#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
