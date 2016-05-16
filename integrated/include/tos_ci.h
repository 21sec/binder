/**@defgroup CIģ��

@{
@brief ���ڿ��Ƶ�����CI��ز���

@version 1.0.0
**/

#ifndef __TOS_CI_H__
#define __TOS_CI_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif



/** @brief CI�˵�ÿ����֧�ֵ�����ַ�������*/
#define FPI_CI_MMI_ITEM_LEN_MAX 256

/** @brief CI�˵���֧�ֵ����Item ����*/
#define FPI_CI_MMI_ITEM_NUM_MAX 128

/** @brief CI OP Name ��֧�ֵ�����ַ�������*/
#define FPI_CI_OP_NAME_LENGTH  48


/** @brief �˵�����ö��*/
typedef enum
{
    E_MMI_TYPE_MENU, /**< Menu�˵�*/
    E_MMI_TYPE_ENQ   /**< Enq�˵�*/
} EN_FPI_MMI_TYPE;

/** @brief CAM��״̬*/
typedef enum
{
    E_CARD_EXTRACTED,   /**<���Ѱγ�*/
	E_CARD_INSERTED,    /**<���Ѳ���*/
	E_CARD_ACTIVE,      /**<������*/
} EN_FPI_CI_CARD_STATE;

/** @brief CI Certficate����*/
typedef enum
{
    E_CI_CERT_TEST = 0x00,/**<����Key*/
    E_CI_CERT_PRODUCTION = 0x01,/**<����Key*/
}EN_FPI_CI_CERT_TYPE;

/**
@brief ����CAM״̬�ص��¼�ö��
*/
typedef enum {
    EN_FPI_CI_EVENT_CARD_INSERTED,         ///< ��ʾCAM������
    EN_FPI_CI_EVENT_CARD_REMOVED,          ///< ��ʾCAM���γ�
    EN_FPI_CI_EVENT_MMI_DATA_READY,     ///< ��ʾCam������Ҫ��ʾ
    EN_FPI_CI_EVENT_MMI_CLOSE,          ///< �û��ر�Ci�˵���ص���������Uiˢ������
    EN_FPI_CI_EVENT_UPGR_INPROGRESS,       ///< �û�CI+���������̣������������û������ػ�������������������
    EN_FPI_CI_EVENT_UPGR_FINISH,           ///< �û�CI+��������ɻص���ȡ����������
    EN_FPI_CI_EVENT_OP_UPDATE_CHANNEL,  ///< CI+����Ƶ��������Ui��ʾ
    EN_FPI_CI_EVENT_OP_UPDATE_NIT,      ///< CI+����nit������Ui��ʾ
    EN_FPI_CI_EVENT_OP_UPDATE_INFO,     ///< CI+����op��Ϣ
    EN_FPI_CI_EVENT_AMMI_MHEG_OPEN,        ///< CI+ application man-machine interface,��Ҫ��������Ҫ��ֵ������Ӧ�ô��ݼ�ֵ���м��
    EN_FPI_CI_EVENT_AMMI_MHEG_CLOSE,       ///< CI+��Ҫȡ����ֵ����
    EN_FPI_CI_EVENT_AI_NAME_READY,      ///< ����AI infolist�˵��ص���Ȼ�������ʾai������
    EN_FPI_CI_EVENT_PROGRAM_CHANGED,      ///< ֪ͨUI CI�ѻ�̨�����ȡ���Ž�Ŀ��INFO������ʾ
    EN_FPI_CI_EVENT_NUM
}FPI_CI_CB_EVENT_E;

/** @brief CI�ַ�����ʾ��Ϣ*/
typedef struct
{
    unsigned char buf[FPI_CI_MMI_ITEM_LEN_MAX]; /**<����ʾ���ַ���*/
    uint16_t length;                          /**<����ʾ���ַ�������*/
}fpi_ci_string_t;

/** @brief CI Menu �˵���ʾ��Ϣ*/
typedef struct
{
    fpi_ci_string_t title;      /**<CI Title*/
    fpi_ci_string_t subtitle;   /**<CI SubTitle*/
    fpi_ci_string_t bottom;     /**<CI Bottom*/
    fpi_ci_string_t item[FPI_CI_MMI_ITEM_NUM_MAX];   /**<CI Item*/
    uint8_t item_count;       /**<CI  item count*/
}fpi_ci_mmi_menu_t;


/** @brief CI Enq �˵���ʾ��Ϣ*/
typedef struct
{
    uint8_t ansLen;           ///< answer�ĳ���
    uint8_t blindAns;         ///< �Ƿ�ɼ�
    fpi_ci_string_t title;  ///< title string
}fpi_ci_mmi_enq_t;


/** @brief CI certificate��Ϣ*/
typedef struct
{
    uint8_t *filePath;          ///< cert·�����ļ���
    EN_FPI_CI_CERT_TYPE cerType;///< production or test
}fpi_ci_cert_info_t;


/** @brief CI msg��Ϣ*/
typedef struct
{
    uint32_t msg_type; ///< CI��Ϣö��ֵ
    uint8_t resend_flag;///< resend flag
}fpi_ci_msg_info_t;


/**
@brief ��ȡCI����״̬
@param[out] card_state CI����״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_get_card_state(EN_FPI_CI_CARD_STATE *card_state);

/**
@brief ��ȡai����
ai: application information
Ӧ���յ��ص���Ϣ����ΪFPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_AI_NAME_READYʱ���е���
@param[out] count CI �˵�����������ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_ai_get_count(uint16_t *count);

/**
@brief ����Index,��ȡai name
ai: application information
Ӧ���յ��ص���Ϣ����ΪFPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_AI_NAME_READYʱ���е���
@param[in] index ��Ҫ��ȡ��name��index��[0��count-1]
@param[out] pstr name����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_ai_get_name(uint8_t index, fpi_ci_string_t* name);

/**
@brief ��Ӧ����CI��CIPLUS ���˵�
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[in] index �û���ѡ���ѡ�����       
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_enter(int id, uint8_t index);

/**
@brief ��Ӧ�˵���������һ���˵�
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
@deprecated ������Ŀ�в���ʹ�øýӿ�
*/
fpi_error tos_ci_mmi_back(int id);

/**
@brief ��Ӧ���ؼ��˳�CI����
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_close(int id);

/**
@brief ��ȡ�˵�����
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[out] mmi_type EN_FPI_MMI_TYPE ָ��: E_MMI_TYPE_NONE,
                               E_MMI_TYPE_MENU, 
                               E_MMI_TYPE_LIST,
                               E_MMI_TYPE_ENQ,
                               E_MMI_TYPE_TEXT
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_get_type(int id, EN_FPI_MMI_TYPE *mmi_type);

/**
@brief ��ȡmmi menu����
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[out] menu mmi menu����ָ�룬fpi_ci_mmi_menu_t������title subtitle bottom item choiceNumber��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_get_menu(int id, fpi_ci_mmi_menu_t *menu);

/**
@brief ��ӦOK(ȷ��)��������һ���˵�
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[in] index ��ǰci�˵��Ĳ˵������� ,������0��ʼ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_select_item(int id, uint8_t index);

/**
@brief ��ȡmmi enq����
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[out] enq mmi enq����ָ�룬fpi_ci_mmi_enq_t������blandAns AnsLen AnsText��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_get_enq(int id,fpi_ci_mmi_enq_t *enq);

/**
@brief ����û����������
�ص�ʱ�ش�id
@param[in] id ��ʾ��Ҫ����ҳ���id�����ݻص����ص�id����
@param[in] pin �����ַ���ָ��
@param[out] value fpi_ture -- ������ȷ��fpi_false �������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_mmi_answer_enq(int id, char* pin);

/**
@brief ��ȡCI_MHEG5��״̬
�ж�mheg�Ƿ�򿪣�����򿪣�Ӧ�ô��ݼ�ֵ���м������
@param[out] mheg5_state fpi_ture -- mehg �򿪣�fpi_false mehg �ر�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_ammi_get_mheg5_state(fpi_bool *mheg5_state);

/**
@brief ��ȡCI op��״̬
�������Ƶ���б��Ƿ����opƵ���б�
@param[out] exist fpi_ture--op���ڣ�fpi_false--op������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_is_exist(fpi_bool *exist);

/**
@brief ��ȡci op channellist����
@param[out] profile_name profile name,utf-8
@param[in] len profile name����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_get_name(fpi_ci_string_t *profile_name);


/**
@brief ����CI CHANNEL
Ӧ���յ��ص���Ϣ����ΪFPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_UI_OP_UPDATE_CHANNELʱ���е���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_handle_channel_update();

/**
@brief ����CI nit
����ci�ص���Ϣ������ʾ��Ӧ���յ��ص���Ϣ����ΪFPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_UI_OP_UPDATE_NITʱ���е���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_handle_nit_update();

/**
@brief ɾ��CI��Ŀ�б�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_op_delete_all_channel();

/**
@brief ����CIPlus Certificate
�����˵���дCI+��keyʹ��
@param[in] certInfo cert·�����ļ���������ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_cert_update(fpi_ci_cert_info_t *cert_info);

/**
@brief ����CIPlus Certificate
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_cert_erase(void);

/**
@brief ��ȡCertificate�е�Custom Code��Ϣ
���ڲ˵���ʾ
@param[out] custom_code Certificate�е�Custom Code��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_cert_get_custom_code(fpi_ci_string_t* custom_code);

/**
@brief ��ȡCertificate��Device Cert��Serial Num��Ϣ
���ڲ˵���ʾ
@param[out] Device  Certificate�е�Serial Num��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_cert_get_serial_num(fpi_ci_string_t* serial_num);


/**
@brief ����CIģ�����·�����Ϣ������Androidϵͳʹ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_msg_resend(void);

/**
@brief Ӧ�ý��յ�CI��Ϣ�����ö�Ӧ��Ϣ��Resend Flag,����Androidϵͳʹ��
@param[in] ci_msg CI��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_msg_set_resend_flag(fpi_ci_msg_info_t ci_msg);

/**
@brief CIģ�鴦��ص�
@param[in] eventType �������¼�����ö��FPI_CI_CB_EVENT_E
@param[in] data1 �������¼���������,
@param[in] data1 �������¼���������,
@param[in] id Cam������
@param[in] userdata Ϊ�û�ע�����ݣ��ص�ʱԭ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
typedef int32_t (*fpi_dtv_ci_callback)(FPI_CI_CB_EVENT_E event_type, int data1,int data2, int id, void* userdata);

/**
@brief ���Dtv CIģ�鴦��ص�
��CI��״̬�����仯ʱ���м�������Ӧ��ע��ı��ӿ���������Ӧ�Ĳ����Ĺ���.

@param[in] callbakc ���Żص�����ָ��
@param[in] userdata �û�����,ע��˻ص�ʱ��userdata����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_ci_add_callback(fpi_dtv_ci_callback callback, void* userdata);


/**
@brief ɾ��CIģ��ص�����

@param[in] callbakc Dtv CI�ص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_ci_remove_callback(fpi_dtv_ci_callback callback);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
