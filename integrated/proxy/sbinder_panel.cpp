/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_panel.sidl
 */
 

#define LOG_TAG     "sbinder_panel"

#include <clog.h>
#include <string.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "tos_pannel.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_VIDEO);



#define SERVICE_DESCRIPTOR                      "eeedf924-2bbb-11e5-97ad-005056a86db3"
#define SERVICE_NAME                            "sbinder_panel"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_panel_get_type FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_panel_set_mode FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_panel_get_mode FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_panel_get_size FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_panel_get_refreshrate FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_panel_get_physical_size FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_panel_local_dimming_array_set FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_panel_local_dimming_ctrl FIRST_CALL_TRANSACTION + 8


using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_panel.h"

class sbinder_panel_service : public BBinder  
{  
private:
    static sbinder_panel_service* _instance;

    sbinder_panel_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_panel_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_panel_service();
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

            case TRANSACTION_tos_panel_get_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_get_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mode_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_PANEL_TYPE* panel_type = NULL;
                if(_mode_len > 0) {
                    reply->writeInt32(_mode_len);
                    Parcel::WritableBlob _mode_wblob;
                    reply->writeBlob(_mode_len,&_mode_wblob);
                    panel_type = (EN_FPI_PANEL_TYPE*)_mode_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_panel_get_type( panel_type );

                reply->writeInt32(_result); //fpi_error as return value


                //-- end code for tos_panel_get_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_panel_set_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_set_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                EN_FPI_PANEL_MODE mode = (EN_FPI_PANEL_MODE)data.readInt32();  //EN_FPI_3D_VIDEO_DIAPLAY_FORMAT as input paramter

                EN_ACT_CTRL act = (EN_ACT_CTRL)data.readInt32();  //EN_ACT_CTRL as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_panel_set_mode( mode, act );


                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_panel_set_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_panel_get_mode:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_get_mode here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end
				int _mode_len = data.readInt32(); //read length, only 32bits length support yet
			   EN_FPI_PANEL_MODE* mode = NULL;
			   if(_mode_len > 0) {
				   reply->writeInt32(_mode_len);
				   Parcel::WritableBlob _mode_wblob;
				   reply->writeBlob(_mode_len,&_mode_wblob);
				   mode = (EN_FPI_PANEL_MODE*)_mode_wblob.data();
			   }

                //begin paramters list

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_panel_get_mode( mode );


                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_panel_get_mode here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_panel_get_size:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_get_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list

				int _info_len = data.readInt32(); //read length, only 32bits length support yet 	
				st_fpi_panel_property* panel_pro = NULL;	
				if(_info_len > 0) {			
					reply->writeInt32(_info_len);	
					Parcel::WritableBlob _value_wblob; 		
					reply->writeBlob(_info_len,&_value_wblob);
					panel_pro = (st_fpi_panel_property*)_value_wblob.data(); 	
					}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_panel_get_size( panel_pro );

                
                reply->writeInt32(_result); //fpi_error as return value
                //-- end code for tos_panel_get_size here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_panel_get_refreshrate:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_get_refreshrate here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _panel_freq_len = data.readInt32(); //read length, only 32bits length support yet
                int16_t* panel_freq = NULL;

                Parcel::WritableBlob _panel_freq_wblob;

                if(_panel_freq_len > 0) {
                    reply->writeInt32(_panel_freq_len);
                    reply->writeBlob(_panel_freq_len,&_panel_freq_wblob);
                    panel_freq = (int16_t*)_panel_freq_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                panel_freq = (int16_t*)_panel_freq_wblob.data();
                fpi_error _result = tos_panel_get_refreshrate( panel_freq );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_panel_get_refreshrate here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            case TRANSACTION_tos_panel_get_physical_size:            
            {                
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check                
                //-- begin code for tos_setting_get_screen_size here, will auoto generated but may change yourself if need --  
                //skip Exception and result first to write output paramters                
                reply->writeNoException();                
                //skip Exception and result first end                
                //begin paramters list                
                int _width_len = data.readInt32(); //read length, only 32bits length support yet     
                int32_t* width = NULL;             
                Parcel::WritableBlob _width_wblob;           
                if(_width_len > 0) {                  
                    reply->writeInt32(_width_len);               
                    reply->writeBlob(_width_len,&_width_wblob);           
                    width = (int32_t*)_width_wblob.data();               
                }              
                int _height_len = data.readInt32(); //read length, only 32bits length support yet       
                int32_t* height = NULL;         
                Parcel::WritableBlob _height_wblob;          
                if(_height_len > 0) {               
                    reply->writeInt32(_height_len);          
                    reply->writeBlob(_height_len,&_height_wblob);       
                    height = (int32_t*)_height_wblob.data();              
                }              
                // re-get all pointers from blob to fix realloc issue in Parcel     
                width = (int32_t*)_width_wblob.data();              
                height = (int32_t*)_height_wblob.data();            
                fpi_error _result = tos_panel_get_physical_size( width, height );     
                reply->writeInt32(_result); //fpi_error as return value         
                //-- end code for tos_setting_get_screen_size here --            
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;           
            } break;
	   case TRANSACTION_tos_panel_local_dimming_array_set:
	   {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_panel_get_size here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list


		int _array_len = data.readInt32(); //read length, only 32bits length support yet  
		fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_array_set enter!333 _array_len = %d" , _array_len);

		ST_FPI_PANEL_LED_ARRAY_T panel_led_array; 
		memset(&panel_led_array, 0, sizeof(ST_FPI_PANEL_LED_ARRAY_T));
		if(_array_len > 0) {  
		 	Parcel::ReadableBlob _pin_rblob;
		 	data.readBlob(_array_len, &_pin_rblob);
			 if( _array_len == sizeof(ST_FPI_PANEL_LED_ARRAY_T))
			 {
				 memcpy(&panel_led_array, _pin_rblob.data(), _array_len);
				 fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_array_set enter!222");
			 }
			 else
			 {
				 //to be done
			 }
		}

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_panel_local_dimming_array_set(&panel_led_array);
                
                reply->writeInt32(_result); //fpi_error as return value
                //-- end code for tos_panel_get_size here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);
		return NO_ERROR;		
	   }break;
	   case TRANSACTION_tos_panel_local_dimming_ctrl:
	   {
		   data.enforceInterface(String16(SERVICE_NAME));  //fixed check
		   
		   fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_ctrl enter!");
   
		   //-- begin code for tos_panel_get_size here, will auoto generated but may change yourself if need --
   
		   //skip Exception and result first to write output paramters
		   reply->writeNoException();
		   //skip Exception and result first end
   
		   //begin paramters list
		   
		   int _info_len = data.readInt32(); //read length, only 32bits length support yet	
		   fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_ctrl enter!333 _info_len = %d" , _info_len);
		   
		   ST_FPI_PANEL_CTRL_INFO_T panel_ctrl_info; 
		   memset(&panel_ctrl_info, 0, sizeof(ST_FPI_PANEL_CTRL_INFO_T));
		   if(_info_len > 0) {	
			Parcel::ReadableBlob _pin_rblob;
			data.readBlob(_info_len, &_pin_rblob);
			if( _info_len == sizeof(ST_FPI_PANEL_CTRL_INFO_T))
			{
				memcpy(&panel_ctrl_info,_pin_rblob.data(), _info_len);
				fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_ctrl enter!222");
			}
			else
			{
				//to be done
			}
		   }
		   fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_ctrl enter!333");
		   // re-get all pointers from blob to fix realloc issue in Parcel
		   fpi_error _result = tos_panel_local_dimming_ctrl(&panel_ctrl_info);
   
		   
		   reply->writeInt32(_result); //fpi_error as return value
		   //-- end code for tos_panel_get_size here --
		   fpi_trace(SERVICE_NAME" end(code=%d)\n",code);
		
		   fpi_info(SERVICE_NAME"_service tos_panel_local_dimming_ctrl quit!");
		   
		   return NO_ERROR;    

	   }break;		
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_panel_service_add() {
    sbinder_panel_service::Instance();
    return 0;
}

sbinder_panel_service* sbinder_panel_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_panel_client  
{  
private:
    static sbinder_panel_client* _instance;
    sp<IBinder> _binder;

    sbinder_panel_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_panel_client() {
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
    static sbinder_panel_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_panel_client();
        }

        return _instance;
    }

    fpi_error tos_panel_get_type( EN_FPI_PANEL_TYPE* panel_type ) {
        Parcel data, reply;

        /*-- add you code for tos_panel_get_type here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			if (panel_type == NULL)		
			{		
				data.writeInt32(-1); 
			}	
			else	
			{		
				data.writeInt32((int)(1) * sizeof(EN_FPI_PANEL_TYPE));//write length, only support 32 bits length yet	
			}

            _binder->transact(TRANSACTION_tos_panel_get_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				if (panel_type != NULL)
				{		
					int _type_len = reply.readInt32(); //read length, only 32bits length support yet		
					Parcel::ReadableBlob _state_rblob;		
					reply.readBlob(_type_len,&_state_rblob);		
					memcpy(panel_type,_state_rblob.data(),_type_len);	
				}

                _result = (typeof(_result))reply.readInt32();//int as return value
       
            } else {
                fpi_warn(SERVICE_NAME"_client tos_panel_get_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_panel_get_type error");
        }

        return _result;
        /*-- add you code for tos_panel_get_type here --*/
    }

    fpi_error tos_panel_set_mode( EN_FPI_PANEL_MODE mode, EN_ACT_CTRL act ) {
        Parcel data, reply;

        /*-- add you code for tos_panel_set_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(mode);  //EN_API_PANEL_MODE as input paramter

            data.writeInt32(act);  //EN_ACT_CTRL as input paramter

            _binder->transact(TRANSACTION_tos_panel_set_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_panel_set_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_panel_set_mode error");
        }

        return _result;
        /*-- add you code for tos_panel_set_mode here --*/
    }

    fpi_error tos_panel_get_mode( EN_FPI_PANEL_MODE* mode ) {
        Parcel data, reply;

        /*-- add you code for tos_panel_get_mode here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
            
			if (mode == NULL)		
			{		
				data.writeInt32(-1); 
			}	
			else	
			{		
				data.writeInt32((int)(1) * sizeof(EN_FPI_PANEL_MODE));//write length, only support 32 bits length yet	
			}


            _binder->transact(TRANSACTION_tos_panel_get_mode,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

				if (mode != NULL)
				{		
					int _type_len = reply.readInt32(); //read length, only 32bits length support yet		
					Parcel::ReadableBlob _state_rblob;		
					reply.readBlob(_type_len,&_state_rblob);		
					memcpy(mode,_state_rblob.data(),_type_len); 
				}

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_panel_get_mode error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_panel_get_mode error");
        }

        return _result;
        /*-- add you code for tos_panel_get_mode here --*/
    }

    fpi_error tos_panel_get_size( st_fpi_panel_property* value ) {
        Parcel data, reply;

        /*-- add you code for tos_panel_get_size here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

			if (value == NULL)		
			{		
				data.writeInt32(-1); 
			}	
			else	
			{		
				data.writeInt32((int)(1) * sizeof(st_fpi_panel_property));//write length, only support 32 bits length yet	
			}

            _binder->transact(TRANSACTION_tos_panel_get_size,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (value != NULL) {
                    int _value_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _value_rblob;
                    reply.readBlob(_value_len,&_value_rblob);
                    memcpy(value,_value_rblob.data(),_value_len);
                } 
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_panel_get_size error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_panel_get_size error");
        }

        return _result;
        /*-- add you code for tos_panel_get_size here --*/
    }

    fpi_error tos_panel_get_refreshrate( int16_t* panel_freq ) {
        Parcel data, reply;

        /*-- add you code for tos_panel_get_refreshrate here --*/
        fpi_error _result = fpi_false;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (panel_freq == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(int16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_panel_get_refreshrate,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (panel_freq != NULL) {
                    int _panel_freq_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _panel_freq_rblob;
                    reply.readBlob(_panel_freq_len,&_panel_freq_rblob);
                    memcpy(panel_freq,_panel_freq_rblob.data(),_panel_freq_len);
                } 
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_panel_get_refreshrate error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_panel_get_refreshrate error");
        }

        return _result;
        /*-- add you code for tos_panel_get_refreshrate here --*/
    }

    
    fpi_error tos_panel_get_physical_size( int32_t* width, int32_t* height ) {        
        Parcel data, reply;        
        /*-- add you code for tos_setting_get_screen_size here --*/        
        fpi_error _result= fpi_false;        
        if(!getService()) 
       {            
         return _result;        
       }        
        try {            
         data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check          
         //for out only, only write length ; for in, alloc and copy           
         if (width == NULL) {               
            data.writeInt32(-1);            
         }          
         else {               
            data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet 
         }            //for out only, only write length ; for in, alloc and copy           
         if (height == NULL) {               
            data.writeInt32(-1);            
         }            
         else {               
            data.writeInt32((int)(1) * sizeof(int32_t));//write length, only support 32 bits length yet  
         }           
          _binder->transact(TRANSACTION_tos_panel_get_physical_size,data, &reply,0); 
         if(reply.readExceptionCode() == 0) {//fix check    
            if (width != NULL) {                
                int _width_len = reply.readInt32(); //read length, only 32bits length support yet 
                Parcel::ReadableBlob _width_rblob;                
                reply.readBlob(_width_len,&_width_rblob);          
                memcpy(width,_width_rblob.data(),_width_len);      
            }               
            if (height != NULL) {                   
                int _height_len = reply.readInt32(); //read length, only 32bits length support yet  
                Parcel::ReadableBlob _height_rblob;              
                reply.readBlob(_height_len,&_height_rblob);           
                memcpy(height,_height_rblob.data(),_height_len);               
            }              
         _result = (typeof(_result))reply.readInt32();//int as return value   
         } else {               
         TOSLOGW(SERVICE_NAME"_client tos_panel_get_physical_size error");       
          }        
         }catch(...) {          
         TOSLOGW(SERVICE_NAME"_client tos_panel_get_physical_size error");       
         }       
         return _result;      
         /*-- add you code for tos_panel_get_physical_size here --*/   
         }

	fpi_error tos_panel_local_dimming_array_set(ST_FPI_PANEL_LED_ARRAY_T* array) 
	{
		 Parcel data, reply;

	        /*-- add you code for tos_panel_get_size here --*/
	        fpi_error _result = fpi_false;
	        if(!getService()) {
	            return _result;
	        }
		if(!array)
		{
			fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_array_set array is null");
		}
		
		fpi_info("enter %s array->horizontal_control_point_num,=%d,array->vertical_control_point_num=%d)\n",__FUNCTION__, (int)array->horizontal_control_point_num, (int)array->vertical_control_point_num);

	        try {
	           		
		data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
		
		data.writeInt32((int)(1) * sizeof(ST_FPI_PANEL_LED_ARRAY_T));//write length, only support 32 bits length yet
		Parcel::WritableBlob _pin_wblob;
		data.writeBlob((1) * sizeof(ST_FPI_PANEL_LED_ARRAY_T), &_pin_wblob);
		memcpy(_pin_wblob.data(), array, (1)* sizeof(ST_FPI_PANEL_LED_ARRAY_T));

	            _binder->transact(TRANSACTION_tos_panel_local_dimming_array_set,data, &reply,0);

	            if(reply.readExceptionCode() == 0) {//fix check
	                _result = (typeof(_result))reply.readInt32();//int as return value

	            } else {
	                fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_array_set error");
	            }
	        }catch(...) {
	            fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_array_set error");
	        }

        /*-- add you code for tos_panel_get_size here --*/
		return _result; 
	}
	fpi_error  tos_panel_local_dimming_ctrl(ST_FPI_PANEL_CTRL_INFO_T* ctl_info_test)
	{   
		Parcel data, reply;

	        /*-- add you code for tos_panel_get_size here --*/
	        fpi_error _result = fpi_false;
	        if(!getService()) {
	            return _result;
	        }
		if(!ctl_info_test)
		{
			fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_ctrl info is null");
		}
		
		fpi_info("enter %s ctl_info_test.action=%d,ctl_info_test.dir=%d)\n",__FUNCTION__, (int)ctl_info_test->action, (int)ctl_info_test->dir);
		fpi_info("enter %s ctl_info_test.start_pos.pos = %d,ctl_info_test.start_pos.h_pos=%d,ctl_info_test.start_pos.v_pos=%d)\n",__FUNCTION__,(int)ctl_info_test->start_pos.pos, ctl_info_test->start_pos.h_pos, ctl_info_test->start_pos.v_pos);
		fpi_info("enter %s ctl_info_test.end_pos.pos = %d,ctl_info_test.end_pos.h_pos=%d,ctl_info_test.end_pos.v_pos=%d)\n",__FUNCTION__,(int)ctl_info_test->end_pos.pos, ctl_info_test->end_pos.h_pos, ctl_info_test->end_pos.v_pos);
			
		fpi_info(SERVICE_NAME"_client tos_panel_local_dimming_ctrl enter!");
	        try {

			data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
			
			data.writeInt32((int)(1) * sizeof(ST_FPI_PANEL_CTRL_INFO_T));//write length, only support 32 bits length yet
			Parcel::WritableBlob _pin_wblob;
			data.writeBlob((1) * sizeof(ST_FPI_PANEL_CTRL_INFO_T),&_pin_wblob);
			memcpy(_pin_wblob.data(), ctl_info_test, (1)* sizeof(ST_FPI_PANEL_CTRL_INFO_T));

	            _binder->transact(TRANSACTION_tos_panel_local_dimming_ctrl, data, &reply,0);

	            if(reply.readExceptionCode() == 0) {//fix check
	                _result = (typeof(_result))reply.readInt32();//int as return value

	            } else {
	                fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_ctrl error");
	            }
	        }catch(...) {
	            fpi_warn(SERVICE_NAME"_client tos_panel_local_dimming_ctrl error");
	        }
		fpi_info(SERVICE_NAME"_client tos_panel_local_dimming_ctrl quit!");

        /*-- add you code for tos_panel_get_size here --*/
		return _result; 
	}

	
	
	
    };


sbinder_panel_client* sbinder_panel_client::_instance = NULL;

fpi_error tos_panel_get_type( EN_FPI_PANEL_TYPE* panel_type ) {
    return sbinder_panel_client::Instance()->tos_panel_get_type(panel_type);
}
fpi_error tos_panel_set_mode( EN_FPI_PANEL_MODE mode, EN_ACT_CTRL act ) {
    return sbinder_panel_client::Instance()->tos_panel_set_mode(mode, act);
}
fpi_error tos_panel_get_mode( EN_FPI_PANEL_MODE* mode ) {
    return sbinder_panel_client::Instance()->tos_panel_get_mode(mode);
}
fpi_error tos_panel_get_size( st_fpi_panel_property* value ) {
    return sbinder_panel_client::Instance()->tos_panel_get_size(value);
}
fpi_error tos_panel_get_refreshrate( int16_t* panel_freq ) {
    return sbinder_panel_client::Instance()->tos_panel_get_refreshrate(panel_freq);
}
fpi_error tos_panel_get_physical_size( int32_t* width, int32_t* height ) {   
    return sbinder_panel_client::Instance()->tos_panel_get_physical_size(width, height);
}

fpi_error tos_panel_local_dimming_array_set(ST_FPI_PANEL_LED_ARRAY_T* array) {   
    return sbinder_panel_client::Instance()->tos_panel_local_dimming_array_set(array);
}
fpi_error  tos_panel_local_dimming_ctrl(ST_FPI_PANEL_CTRL_INFO_T* info) {   
    return sbinder_panel_client::Instance()->tos_panel_local_dimming_ctrl(info);
}



#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
