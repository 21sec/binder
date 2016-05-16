/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_ci.sidl
 */
 

#define LOG_TAG     "sbinder_ci"

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
#include "tos_ci.h"
#include "fpi_debug_helper.h"
SET_MODEL_ID(SITA_MODULE_CI);


#define SERVICE_DESCRIPTOR                      "11a4ecc0-de87-11e4-a8c9-005056a84a3b"
#define SERVICE_NAME                            "sbinder_ci"

#define FIRST_CALL_TRANSACTION                  (1)
#define TRANSACTION_tos_ci_get_card_state FIRST_CALL_TRANSACTION + 1
#define TRANSACTION_tos_ci_ai_get_count FIRST_CALL_TRANSACTION + 2
#define TRANSACTION_tos_ci_ai_get_name FIRST_CALL_TRANSACTION + 3
#define TRANSACTION_tos_ci_mmi_enter FIRST_CALL_TRANSACTION + 4
#define TRANSACTION_tos_ci_mmi_back FIRST_CALL_TRANSACTION + 5
#define TRANSACTION_tos_ci_mmi_close FIRST_CALL_TRANSACTION + 6
#define TRANSACTION_tos_ci_mmi_get_type FIRST_CALL_TRANSACTION + 7
#define TRANSACTION_tos_ci_mmi_get_menu FIRST_CALL_TRANSACTION + 8
#define TRANSACTION_tos_ci_mmi_select_item FIRST_CALL_TRANSACTION + 9
#define TRANSACTION_tos_ci_mmi_get_enq FIRST_CALL_TRANSACTION + 10
#define TRANSACTION_tos_ci_mmi_answer_enq FIRST_CALL_TRANSACTION + 11
#define TRANSACTION_tos_ci_ammi_get_mheg5_state FIRST_CALL_TRANSACTION + 12
#define TRANSACTION_tos_ci_op_is_exist FIRST_CALL_TRANSACTION + 13
#define TRANSACTION_tos_ci_op_get_name FIRST_CALL_TRANSACTION + 14
#define TRANSACTION_tos_ci_op_handle_channel_update FIRST_CALL_TRANSACTION + 15
#define TRANSACTION_tos_ci_op_handle_nit_update FIRST_CALL_TRANSACTION + 16
#define TRANSACTION_tos_ci_op_delete_all_channel FIRST_CALL_TRANSACTION + 17
#define TRANSACTION_tos_ci_cert_update FIRST_CALL_TRANSACTION + 18
#define TRANSACTION_tos_ci_cert_erase FIRST_CALL_TRANSACTION + 19
#define TRANSACTION_tos_ci_cert_get_custom_code FIRST_CALL_TRANSACTION + 20
#define TRANSACTION_tos_ci_msg_resend FIRST_CALL_TRANSACTION + 21
#define TRANSACTION_tos_ci_msg_set_resend_flag FIRST_CALL_TRANSACTION + 22

using namespace sita_android;

#if defined(BINDER_SERVICE)

#include <stdlib.h>
#include "sbinder_ci.h"

class sbinder_ci_service : public BBinder  
{  
private:
    static sbinder_ci_service* _instance;

    sbinder_ci_service(){
        fpi_info(SERVICE_NAME"_service create\n");
    }
    
    virtual ~sbinder_ci_service() {
        fpi_info(SERVICE_NAME"_service destory\n");
    }

public:  
    static int Instance() {
        if(_instance == NULL) {
            _instance = new sbinder_ci_service();
            int ret = defaultServiceManager()->addService(  
                String16(SERVICE_NAME), _instance );  
            fpi_info(SERVICE_NAME"_service Instance %d\n",ret);
            return ret;  
        }

        return -1;
    }
    
    virtual status_t onTransact(uint32_t code , const Parcel& data , Parcel* reply, uint32_t flags) {
        fpi_info(SERVICE_NAME"_service - onTransact code=%d\n",code);

        switch(code)  {

            case TRANSACTION_tos_ci_get_card_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_get_card_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _card_state_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_CI_CARD_STATE* card_state = NULL;

                Parcel::WritableBlob _card_state_wblob;

                if(_card_state_len > 0) {
                    reply->writeInt32(_card_state_len);
                    reply->writeBlob(_card_state_len,&_card_state_wblob);
                    card_state = (EN_FPI_CI_CARD_STATE*)_card_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                card_state = (EN_FPI_CI_CARD_STATE*)_card_state_wblob.data();
                fpi_error _result = tos_ci_get_card_state( card_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_get_card_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_ai_get_count:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_ai_get_count here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _count_len = data.readInt32(); //read length, only 32bits length support yet
                uint16_t* count = NULL;

                Parcel::WritableBlob _count_wblob;

                if(_count_len > 0) {
                    reply->writeInt32(_count_len);
                    reply->writeBlob(_count_len,&_count_wblob);
                    count = (uint16_t*)_count_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                count = (uint16_t*)_count_wblob.data();
                fpi_error _result = tos_ci_ai_get_count( count );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_ai_get_count here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_ai_get_name:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_ai_get_name here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                uint8_t index = (uint8_t)data.readInt32();  //uint8_t as input paramter

                int _name_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_string_t* name = NULL;

                Parcel::WritableBlob _name_wblob;

                if(_name_len > 0) {
                    reply->writeInt32(_name_len);
                    reply->writeBlob(_name_len,&_name_wblob);
                    name = (fpi_ci_string_t*)_name_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                name = (fpi_ci_string_t*)_name_wblob.data();
                fpi_error _result = tos_ci_ai_get_name( index, name );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_ai_get_name here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_enter:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_enter here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                uint8_t index = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_mmi_enter( id, index );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_enter here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_back:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_back here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_mmi_back( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_back here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_close:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_close here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_mmi_close( id );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_close here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_get_type:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_get_type here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                int _mmi_type_len = data.readInt32(); //read length, only 32bits length support yet
                EN_FPI_MMI_TYPE* mmi_type = NULL;

                Parcel::WritableBlob _mmi_type_wblob;

                if(_mmi_type_len > 0) {
                    reply->writeInt32(_mmi_type_len);
                    reply->writeBlob(_mmi_type_len,&_mmi_type_wblob);
                    mmi_type = (EN_FPI_MMI_TYPE*)_mmi_type_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mmi_type = (EN_FPI_MMI_TYPE*)_mmi_type_wblob.data();
                fpi_error _result = tos_ci_mmi_get_type( id, mmi_type );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_get_type here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_get_menu:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_get_menu here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                int _menu_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_mmi_menu_t* menu = NULL;

                Parcel::WritableBlob _menu_wblob;

                if(_menu_len > 0) {
                    reply->writeInt32(_menu_len);
                    reply->writeBlob(_menu_len,&_menu_wblob);
                    menu = (fpi_ci_mmi_menu_t*)_menu_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                menu = (fpi_ci_mmi_menu_t*)_menu_wblob.data();
                fpi_error _result = tos_ci_mmi_get_menu( id, menu );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_get_menu here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_select_item:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_select_item here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                uint8_t index = (uint8_t)data.readInt32();  //uint8_t as input paramter

                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_mmi_select_item( id, index );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_select_item here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_get_enq:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_get_enq here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                int _enq_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_mmi_enq_t* enq = NULL;

                Parcel::WritableBlob _enq_wblob;

                if(_enq_len > 0) {
                    reply->writeInt32(_enq_len);
                    reply->writeBlob(_enq_len,&_enq_wblob);
                    enq = (fpi_ci_mmi_enq_t*)_enq_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                enq = (fpi_ci_mmi_enq_t*)_enq_wblob.data();
                fpi_error _result = tos_ci_mmi_get_enq( id, enq );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_get_enq here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_mmi_answer_enq:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_mmi_answer_enq here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int id = (int)data.readInt32();  //int as input paramter

                int _pin_len = data.readInt32(); //read length, only 32bits length support yet
                char* pin = NULL;

                Parcel::ReadableBlob _pin_rblob;

                if(_pin_len > 0) {
                    data.readBlob(_pin_len,&_pin_rblob);
                    pin = (char*)_pin_rblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pin = (char*)_pin_rblob.data();
                fpi_error _result = tos_ci_mmi_answer_enq( id, pin );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_mmi_answer_enq here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_ammi_get_mheg5_state:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_ammi_get_mheg5_state here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _mheg5_state_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* mheg5_state = NULL;

                Parcel::WritableBlob _mheg5_state_wblob;

                if(_mheg5_state_len > 0) {
                    reply->writeInt32(_mheg5_state_len);
                    reply->writeBlob(_mheg5_state_len,&_mheg5_state_wblob);
                    mheg5_state = (fpi_bool*)_mheg5_state_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                mheg5_state = (fpi_bool*)_mheg5_state_wblob.data();
                fpi_error _result = tos_ci_ammi_get_mheg5_state( mheg5_state );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_ammi_get_mheg5_state here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_is_exist:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_op_is_exist here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _exist_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_bool* exist = NULL;

                Parcel::WritableBlob _exist_wblob;

                if(_exist_len > 0) {
                    reply->writeInt32(_exist_len);
                    reply->writeBlob(_exist_len,&_exist_wblob);
                    exist = (fpi_bool*)_exist_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                exist = (fpi_bool*)_exist_wblob.data();
                fpi_error _result = tos_ci_op_is_exist( exist );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_op_is_exist here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_get_name:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_op_get_name here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _profile_name_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_string_t* profile_name = NULL;

                Parcel::WritableBlob _profile_name_wblob;

                if(_profile_name_len > 0) {
                    reply->writeInt32(_profile_name_len);
                    reply->writeBlob(_profile_name_len,&_profile_name_wblob);
                    profile_name = (fpi_ci_string_t*)_profile_name_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                profile_name = (fpi_ci_string_t*)_profile_name_wblob.data();
                fpi_error _result = tos_ci_op_get_name( profile_name );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_op_get_name here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_handle_channel_update:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_op_handle_channel_update here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_op_handle_channel_update(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_op_handle_channel_update here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_handle_nit_update:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_op_handle_nit_update here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_op_handle_nit_update(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_op_handle_nit_update here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_op_delete_all_channel:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_op_delete_all_channel here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_op_delete_all_channel(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_op_delete_all_channel here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_cert_update:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_cert_update here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _cert_info_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_cert_info_t* cert_info = NULL;

                Parcel::WritableBlob _cert_info_wblob;

                if(_cert_info_len > 0) {
                    reply->writeInt32(_cert_info_len);
                    reply->writeBlob(_cert_info_len,&_cert_info_wblob);
                    cert_info = (fpi_ci_cert_info_t*)_cert_info_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                cert_info = (fpi_ci_cert_info_t*)_cert_info_wblob.data();
                fpi_error _result = tos_ci_cert_update( cert_info );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_cert_update here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_cert_erase:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_cert_erase here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_cert_erase(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_cert_erase here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_cert_get_custom_code:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_cert_get_custom_code here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                int _pstr_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_string_t* pstr = NULL;

                Parcel::WritableBlob _pstr_wblob;

                if(_pstr_len > 0) {
                    reply->writeInt32(_pstr_len);
                    reply->writeBlob(_pstr_len,&_pstr_wblob);
                    pstr = (fpi_ci_string_t*)_pstr_wblob.data();
                }

                // re-get all pointers from blob to fix realloc issue in Parcel
                pstr = (fpi_ci_string_t*)_pstr_wblob.data();
                fpi_error _result = tos_ci_cert_get_custom_code( pstr );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_cert_get_custom_code here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_msg_resend:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_msg_resend here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_msg_resend(  );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_msg_resend here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            case TRANSACTION_tos_ci_msg_set_resend_flag:
            {
                data.enforceInterface(String16(SERVICE_NAME));  //fixed check

                //-- begin code for tos_ci_msg_set_resend_flag here, will auoto generated but may change yourself if need --

                //skip Exception and result first to write output paramters
                reply->writeNoException();
                //skip Exception and result first end

                //begin paramters list
                //fpi_ci_msg_info_t ci_msg = (fpi_ci_msg_info_t)data.readInt32();  //fpi_ci_msg_info_t as input paramter
                int ci_msg_len = data.readInt32(); //read length, only 32bits length support yet
                fpi_ci_msg_info_t ci_msg;
                if(ci_msg_len > 0) {
                    Parcel::ReadableBlob _info_rblob;
                    data.readBlob(ci_msg_len,&_info_rblob);
                    ci_msg = *((fpi_ci_msg_info_t *)_info_rblob.data());
                }
                // re-get all pointers from blob to fix realloc issue in Parcel
                fpi_error _result = tos_ci_msg_set_resend_flag( ci_msg );

                reply->writeInt32(_result); //fpi_error as return value

                //-- end code for tos_ci_msg_set_resend_flag here --
                fpi_trace(SERVICE_NAME" end(code=%d)\n",code);return NO_ERROR;
            } break;
            
            default:  
                return BBinder::onTransact(code, data, reply, flags);
        
        }

        fpi_info(SERVICE_NAME"_service end");
    }
}; 

int sbinder_ci_service_add() {
    sbinder_ci_service::Instance();
    return 0;
}

sbinder_ci_service* sbinder_ci_service::_instance = NULL;

#elif defined(BINDER_CLIENT)

class sbinder_ci_client  
{  
private:
    static sbinder_ci_client* _instance;
    sp<IBinder> _binder;

    sbinder_ci_client()
        :_binder(NULL) {
        fpi_info(SERVICE_NAME"_client create\n");
        getService();
    }
    
    virtual ~sbinder_ci_client() {
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
    static sbinder_ci_client* Instance() {
        if(_instance == NULL) {
            fpi_info(SERVICE_NAME"_client Instance");
            _instance = new sbinder_ci_client();
        }

        return _instance;
    }

    fpi_error tos_ci_get_card_state( EN_FPI_CI_CARD_STATE* card_state ) {
        Parcel data, reply;
		fpi_info(SERVICE_NAME"_service - tos_ci_get_card_state\n");

        /*-- add you code for tos_ci_get_card_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
			fpi_err(SERVICE_NAME"_service - tos_ci_get_card_state err\n");
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (card_state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_CI_CARD_STATE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_get_card_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (card_state != NULL) {
                    int _card_state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _card_state_rblob;
                    reply.readBlob(_card_state_len,&_card_state_rblob);
                    memcpy(card_state,_card_state_rblob.data(),_card_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_get_card_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_get_card_state error");
        }

        return _result;
        /*-- add you code for tos_ci_get_card_state here --*/
    }

    fpi_error tos_ci_ai_get_count( uint16_t* count ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_ai_get_count here --*/
        fpi_error _result = FPI_ERROR_FAIL;
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
                data.writeInt32((int)(1) * sizeof(uint16_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_ai_get_count,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (count != NULL) {
                    int _count_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _count_rblob;
                    reply.readBlob(_count_len,&_count_rblob);
                    memcpy(count,_count_rblob.data(),_count_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_ai_get_count error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_ai_get_count error");
        }

        return _result;
        /*-- add you code for tos_ci_ai_get_count here --*/
    }

    fpi_error tos_ci_ai_get_name( uint8_t index, fpi_ci_string_t* name ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_ai_get_name here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(index);  //uint8_t as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (name == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_string_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_ai_get_name,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (name != NULL) {
                    int _name_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _name_rblob;
                    reply.readBlob(_name_len,&_name_rblob);
                    memcpy(name,_name_rblob.data(),_name_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_ai_get_name error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_ai_get_name error");
        }

        return _result;
        /*-- add you code for tos_ci_ai_get_name here --*/
    }

    fpi_error tos_ci_mmi_enter( int id, uint8_t index ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_enter here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            data.writeInt32(index);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_ci_mmi_enter,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_enter error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_enter error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_enter here --*/
    }

    fpi_error tos_ci_mmi_back( int id ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_back here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            _binder->transact(TRANSACTION_tos_ci_mmi_back,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_back error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_back error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_back here --*/
    }

    fpi_error tos_ci_mmi_close( int id ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_close here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            _binder->transact(TRANSACTION_tos_ci_mmi_close,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_close error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_close error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_close here --*/
    }

    fpi_error tos_ci_mmi_get_type( int id, EN_FPI_MMI_TYPE* mmi_type ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_get_type here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (mmi_type == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(EN_FPI_MMI_TYPE));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_mmi_get_type,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mmi_type != NULL) {
                    int _mmi_type_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mmi_type_rblob;
                    reply.readBlob(_mmi_type_len,&_mmi_type_rblob);
                    memcpy(mmi_type,_mmi_type_rblob.data(),_mmi_type_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_type error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_type error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_get_type here --*/
    }

    fpi_error tos_ci_mmi_get_menu( int id, fpi_ci_mmi_menu_t* menu ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_get_menu here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (menu == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_mmi_menu_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_mmi_get_menu,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (menu != NULL) {
                    int _menu_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _menu_rblob;
                    reply.readBlob(_menu_len,&_menu_rblob);
                    memcpy(menu,_menu_rblob.data(),_menu_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_menu error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_menu error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_get_menu here --*/
    }

    fpi_error tos_ci_mmi_select_item( int id, uint8_t index ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_select_item here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            data.writeInt32(index);  //uint8_t as input paramter

            _binder->transact(TRANSACTION_tos_ci_mmi_select_item,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_select_item error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_select_item error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_select_item here --*/
    }

    fpi_error tos_ci_mmi_get_enq( int id, fpi_ci_mmi_enq_t* enq ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_get_enq here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (enq == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_mmi_enq_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_mmi_get_enq,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (enq != NULL) {
                    int _enq_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _enq_rblob;
                    reply.readBlob(_enq_len,&_enq_rblob);
                    memcpy(enq,_enq_rblob.data(),_enq_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_enq error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_get_enq error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_get_enq here --*/
    }

    fpi_error tos_ci_mmi_answer_enq( int id, char* pin ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_mmi_answer_enq here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            data.writeInt32(id);  //int as input paramter

            //for out only, only write length ; for in, alloc and copy
            if (pin == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)((1+strlen(pin))) * sizeof(char));//write length, only support 32 bits length yet
                
                Parcel::WritableBlob _pin_wblob;
                data.writeBlob(((1+strlen(pin))) * sizeof(char),&_pin_wblob);
                memcpy(_pin_wblob.data(),pin,(strlen(pin))* sizeof(char));
            }

            _binder->transact(TRANSACTION_tos_ci_mmi_answer_enq,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_mmi_answer_enq error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_mmi_answer_enq error");
        }

        return _result;
        /*-- add you code for tos_ci_mmi_answer_enq here --*/
    }

    fpi_error tos_ci_ammi_get_mheg5_state( fpi_bool* mheg5_state ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_ammi_get_mheg5_state here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (mheg5_state == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_ammi_get_mheg5_state,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (mheg5_state != NULL) {
                    int _mheg5_state_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _mheg5_state_rblob;
                    reply.readBlob(_mheg5_state_len,&_mheg5_state_rblob);
                    memcpy(mheg5_state,_mheg5_state_rblob.data(),_mheg5_state_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_ammi_get_mheg5_state error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_ammi_get_mheg5_state error");
        }

        return _result;
        /*-- add you code for tos_ci_ammi_get_mheg5_state here --*/
    }

    fpi_error tos_ci_op_is_exist( fpi_bool* exist ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_op_is_exist here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (exist == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_bool));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_op_is_exist,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (exist != NULL) {
                    int _exist_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _exist_rblob;
                    reply.readBlob(_exist_len,&_exist_rblob);
                    memcpy(exist,_exist_rblob.data(),_exist_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_op_is_exist error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_op_is_exist error");
        }

        return _result;
        /*-- add you code for tos_ci_op_is_exist here --*/
    }

    fpi_error tos_ci_op_get_name( fpi_ci_string_t* profile_name ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_op_get_name here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (profile_name == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_string_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_op_get_name,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (profile_name != NULL) {
                    int _profile_name_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _profile_name_rblob;
                    reply.readBlob(_profile_name_len,&_profile_name_rblob);
                    memcpy(profile_name,_profile_name_rblob.data(),_profile_name_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_op_get_name error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_op_get_name error");
        }

        return _result;
        /*-- add you code for tos_ci_op_get_name here --*/
    }

    fpi_error tos_ci_op_handle_channel_update(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_op_handle_channel_update here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ci_op_handle_channel_update,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_op_handle_channel_update error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_op_handle_channel_update error");
        }

        return _result;
        /*-- add you code for tos_ci_op_handle_channel_update here --*/
    }

    fpi_error tos_ci_op_handle_nit_update(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_op_handle_nit_update here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ci_op_handle_nit_update,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_op_handle_nit_update error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_op_handle_nit_update error");
        }

        return _result;
        /*-- add you code for tos_ci_op_handle_nit_update here --*/
    }

    fpi_error tos_ci_op_delete_all_channel(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_op_delete_all_channel here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ci_op_delete_all_channel,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_op_delete_all_channel error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_op_delete_all_channel error");
        }

        return _result;
        /*-- add you code for tos_ci_op_delete_all_channel here --*/
    }

    fpi_error tos_ci_cert_update( fpi_ci_cert_info_t* cert_info ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_cert_update here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (cert_info == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_cert_info_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_cert_update,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (cert_info != NULL) {
                    int _cert_info_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _cert_info_rblob;
                    reply.readBlob(_cert_info_len,&_cert_info_rblob);
                    memcpy(cert_info,_cert_info_rblob.data(),_cert_info_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_cert_update error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_cert_update error");
        }

        return _result;
        /*-- add you code for tos_ci_cert_update here --*/
    }

    fpi_error tos_ci_cert_erase(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_cert_erase here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ci_cert_erase,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_cert_erase error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_cert_erase error");
        }

        return _result;
        /*-- add you code for tos_ci_cert_erase here --*/
    }

    fpi_error tos_ci_cert_get_custom_code( fpi_ci_string_t* pstr ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_cert_get_custom_code here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //for out only, only write length ; for in, alloc and copy
            if (pstr == NULL) {
                data.writeInt32(-1);
            }
            else {
                data.writeInt32((int)(1) * sizeof(fpi_ci_string_t));//write length, only support 32 bits length yet
                
            }

            _binder->transact(TRANSACTION_tos_ci_cert_get_custom_code,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                if (pstr != NULL) {
                    int _pstr_len = reply.readInt32(); //read length, only 32bits length support yet
                    Parcel::ReadableBlob _pstr_rblob;
                    reply.readBlob(_pstr_len,&_pstr_rblob);
                    memcpy(pstr,_pstr_rblob.data(),_pstr_len);
                }
                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_cert_get_custom_code error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_cert_get_custom_code error");
        }

        return _result;
        /*-- add you code for tos_ci_cert_get_custom_code here --*/
    }

	
	fpi_error tos_ci_cert_get_serial_num( fpi_ci_string_t* pstr ) {
		   Parcel data, reply;
	
		   /*-- add you code for tos_ci_cert_get_serial_num here --*/
		   fpi_error _result = FPI_ERROR_FAIL;
		   if(!getService()) {
			   return _result;
		   }
	
		   try {
			   data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check
	
			   //for out only, only write length ; for in, alloc and copy
			   if (pstr == NULL) {
				   data.writeInt32(-1);
			   }
			   else {
				   data.writeInt32((int)(1) * sizeof(fpi_ci_string_t));//write length, only support 32 bits length yet
				   
			   }
	
			   _binder->transact(TRANSACTION_tos_ci_cert_get_custom_code,data, &reply,0);
	
			   if(reply.readExceptionCode() == 0) {//fix check
	
				   if (pstr != NULL) {
					   int _pstr_len = reply.readInt32(); //read length, only 32bits length support yet
					   Parcel::ReadableBlob _pstr_rblob;
					   reply.readBlob(_pstr_len,&_pstr_rblob);
					   memcpy(pstr,_pstr_rblob.data(),_pstr_len);
				   }
				   _result = (typeof(_result))reply.readInt32();//int as return value
	
			   } else {
				   fpi_warn(SERVICE_NAME"_client tos_ci_cert_get_serial_num error");
			   }
		   }catch(...) {
			   fpi_warn(SERVICE_NAME"_client tos_ci_cert_get_serial_num error");
		   }
	
		   return _result;
		   /*-- add you code for tos_ci_cert_get_serial_num here --*/
	   }

    fpi_error tos_ci_msg_resend(  ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_msg_resend here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            _binder->transact(TRANSACTION_tos_ci_msg_resend,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_msg_resend error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_msg_resend error");
        }

        return _result;
        /*-- add you code for tos_ci_msg_resend here --*/
    }

    fpi_error tos_ci_msg_set_resend_flag( fpi_ci_msg_info_t ci_msg ) {
        Parcel data, reply;

        /*-- add you code for tos_ci_msg_set_resend_flag here --*/
        fpi_error _result = FPI_ERROR_FAIL;
        if(!getService()) {
            return _result;
        }

        try {
            data.writeInterfaceToken(String16(SERVICE_NAME));//fixed check

            //data.writeInt32(ci_msg);  //fpi_ci_msg_info_t as input paramter
            data.writeInt32((int)(1) * sizeof(fpi_ci_msg_info_t));//write length, only support 32 bits length yet
                
            Parcel::WritableBlob _info_wblob;
            data.writeBlob((1) * sizeof(fpi_ci_msg_info_t),&_info_wblob);
            memcpy(_info_wblob.data(),&ci_msg,(1)* sizeof(fpi_ci_msg_info_t));
            _binder->transact(TRANSACTION_tos_ci_msg_set_resend_flag,data, &reply,0);

            if(reply.readExceptionCode() == 0) {//fix check

                _result = (typeof(_result))reply.readInt32();//int as return value

            } else {
                fpi_warn(SERVICE_NAME"_client tos_ci_msg_set_resend_flag error");
            }
        }catch(...) {
            fpi_warn(SERVICE_NAME"_client tos_ci_msg_set_resend_flag error");
        }

        return _result;
        /*-- add you code for tos_ci_msg_set_resend_flag here --*/
    }
};

sbinder_ci_client* sbinder_ci_client::_instance = NULL;

fpi_error tos_ci_get_card_state( EN_FPI_CI_CARD_STATE* card_state ) {
    return sbinder_ci_client::Instance()->tos_ci_get_card_state(card_state);
}
fpi_error tos_ci_ai_get_count( uint16_t* count ) {
    return sbinder_ci_client::Instance()->tos_ci_ai_get_count(count);
}
fpi_error tos_ci_ai_get_name( uint8_t index, fpi_ci_string_t* name ) {
    return sbinder_ci_client::Instance()->tos_ci_ai_get_name(index, name);
}
fpi_error tos_ci_mmi_enter( int id, uint8_t index ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_enter(id, index);
}
fpi_error tos_ci_mmi_back( int id ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_back(id);
}
fpi_error tos_ci_mmi_close( int id ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_close(id);
}
fpi_error tos_ci_mmi_get_type( int id, EN_FPI_MMI_TYPE* mmi_type ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_get_type(id, mmi_type);
}
fpi_error tos_ci_mmi_get_menu( int id, fpi_ci_mmi_menu_t* menu ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_get_menu(id, menu);
}
fpi_error tos_ci_mmi_select_item( int id, uint8_t index ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_select_item(id, index);
}
fpi_error tos_ci_mmi_get_enq( int id, fpi_ci_mmi_enq_t* enq ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_get_enq(id, enq);
}
fpi_error tos_ci_mmi_answer_enq( int id, char* pin ) {
    return sbinder_ci_client::Instance()->tos_ci_mmi_answer_enq(id, pin);
}
fpi_error tos_ci_ammi_get_mheg5_state( fpi_bool* mheg5_state ) {
    return sbinder_ci_client::Instance()->tos_ci_ammi_get_mheg5_state(mheg5_state);
}
fpi_error tos_ci_op_is_exist( fpi_bool* exist ) {
    return sbinder_ci_client::Instance()->tos_ci_op_is_exist(exist);
}
fpi_error tos_ci_op_get_name( fpi_ci_string_t* profile_name ) {
    return sbinder_ci_client::Instance()->tos_ci_op_get_name(profile_name);
}
fpi_error tos_ci_op_handle_channel_update(  ) {
    return sbinder_ci_client::Instance()->tos_ci_op_handle_channel_update();
}
fpi_error tos_ci_op_handle_nit_update(  ) {
    return sbinder_ci_client::Instance()->tos_ci_op_handle_nit_update();
}
fpi_error tos_ci_op_delete_all_channel(  ) {
    return sbinder_ci_client::Instance()->tos_ci_op_delete_all_channel();
}
fpi_error tos_ci_cert_update( fpi_ci_cert_info_t* cert_info ) {
    return sbinder_ci_client::Instance()->tos_ci_cert_update(cert_info);
}
fpi_error tos_ci_cert_erase(  ) {
    return sbinder_ci_client::Instance()->tos_ci_cert_erase();
}
fpi_error tos_ci_cert_get_custom_code( fpi_ci_string_t* pstr ) {
    return sbinder_ci_client::Instance()->tos_ci_cert_get_custom_code(pstr);
}
fpi_error tos_ci_cert_get_serial_num( fpi_ci_string_t* pstr ) {
    return sbinder_ci_client::Instance()->tos_ci_cert_get_serial_num(pstr);
}

fpi_error tos_ci_msg_resend(  ) {
    return sbinder_ci_client::Instance()->tos_ci_msg_resend();
}
fpi_error tos_ci_msg_set_resend_flag( fpi_ci_msg_info_t ci_msg ) {
    return sbinder_ci_client::Instance()->tos_ci_msg_set_resend_flag(ci_msg);
}

#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif
