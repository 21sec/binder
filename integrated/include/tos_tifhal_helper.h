/**@defgroup TIFHAL_HELPER [TIF HAL Helper] �򻯲�Ʒ�����м���ӿ�ʵ��TIF HAL��ĸ���ģ��

@note ��ģ�������м��TOS�ӿ�ʵ������TIF�е�tv_input.h��hdmi_cec.h�ж���Ľӿڣ��򻯻���TIF��Ŀ�Ŀ�����

@version 0.1 2015/07/28 Created
@{
*/

#ifndef _TOS_TIFHAL_H_
#define _TOS_TIFHAL_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "fpp_cec.h"


#define TIFHAL_ERROR_NO_ERROR				(0)
#define TIFHAL_ERROR_OTHER_ERROR			(-1)
#define TIFHAL_ERROR_PARAMTER_ERROR			(-2)
#define TIFHAL_ERROR_LOOPER_ERROR			(-3)
#define TIFHAL_ERROR_THREAD_ERROR			(-4)
#define TIFHAL_ERROR_DEVICENOTFOUND_ERROR	(-5)
#define TIFHAL_ERROR_STREAMCOUNT_ERROR		(-6)
#define TIFHAL_ERROR_NOTIMP_ERROR			(-7)
#define TIFHAL_ERROR_SENDMSG_ERROR			(-8)
#define TIFHAL_ERROR_STREAMNOTFOUND_ERROR	(-9)

/*
 @brief TVINPUT�ص�����

 @param[in] type ��Ϣ���ͣ�ȡֵΪTOS_TIFHAL_TVINPUT_EVENT_TYPE_E��
 @param[in] param ��Ϣ��Ӧ�Ĳ����������ͼ�ȡֵ��TOS_TIFHAL_TVINPUT_EVENT_TYPE_E��˵��
 @param[in] userdata �û����ݣ�tos_tifhal_tvinput_initialize��userdata����ԭ������
 */
typedef void (*tos_tifhal_tvinput_notify)(int type, void* param, void *userdata);

/*
 @brief tv input��Ϣ����
 */
enum TOS_TIFHAL_TVINPUT_EVENT_TYPE_E {
	/*
	 @brief �豸����ʱ����������Ϣ֪ͨ�ϲ㡣

	 ����ʱΪ����������Դ��������Ϣ��
	 ����USB Tuner�������豸����ʱ��������Ϣ��
	 ��Ϣ��Ӧ��param����Ϊtos_tifhal_tvinput_device_info_tָ�롣
	 @note �β�HDMI�ߵ���ΪӦ�ò���TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED��Ϣ�����Ǵ���Ϣ��
	*/
	TOS_TIFHAL_TVINPUT_EVENT_DEVICE_AVAILABLE = 1,

	/*
	 @brief �豸��ò�����ʱ����������Ϣ֪ͨ�ϲ㡣

	 ����USB Tuner�������豸�γ�ʱ��������Ϣ��
	 ��Ϣ��Ӧ��param����Ϊtos_tifhal_tvinput_device_info_tָ�롣
	 @note �β�HDMI�ߵ���ΪӦ�ò���TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED��Ϣ�����Ǵ���Ϣ��
	*/
	TOS_TIFHAL_TVINPUT_EVENT_DEVICE_UNAVAILABLE = 2,

	/*
	 @brief stream������Ϣ�仯��Ϣ��
 
	 ��������Ϣ�󣬶�Ӧ�������б��򿪵�stream�Զ���Ϊ�ر�״̬��������Ҫ�ϲ������´����ǡ�
	 ���͵Ĳ�������Ϣ�ĳ������źŵķֱ��ʱ仯���ź��߰γ��ȡ�
	 ���ź��߰γ�ʱ����Ӧ�豸��stream��Ϊ0.
	 ��Ϣ��Ӧ��param����Ϊtos_tifhal_tvinput_device_info_tָ�롣
	*/
	TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED = 3,

	/*
	 @brief �����ɹ���Ϣ����δʵ�֣�Ŀǰ�����������Ϣ��
	*/
	TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_SUCCEEDED = 4,

	/*
	 @brief ����ʧ����Ϣ��Ŀǰtos_tifhal_tvinput_request_capture���ǲ�������Ϣ��
 
	 ��Ϣ��Ӧ��param����Ϊtos_tifhal_tvinput_capture_result_tָ�롣
	*/
	TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED = 5,

	/*
	 @brief ��Ϣ���ޣ������������Ϣ��
	*/
	TOS_TIFHAL_TVINPUT_EVENT_MAX
};

/*
 @brief �豸����
 */
enum TOS_TIFHAL_TVINPUT_TYPE_E {
    /* Generic hardware. */
    TOS_TIFHAL_TVINPUT_TYPE_OTHER_HARDWARE = 1,
    /* Tuner. (e.g. built-in terrestrial tuner) */
    TOS_TIFHAL_TVINPUT_TYPE_TUNER = 2,
    TOS_TIFHAL_TVINPUT_TYPE_COMPOSITE = 3,
    TOS_TIFHAL_TVINPUT_TYPE_SVIDEO = 4,
    TOS_TIFHAL_TVINPUT_TYPE_SCART = 5,
    TOS_TIFHAL_TVINPUT_TYPE_COMPONENT = 6,
    TOS_TIFHAL_TVINPUT_TYPE_VGA = 7,
    TOS_TIFHAL_TVINPUT_TYPE_DVI = 8,
    /* Physical HDMI port. (e.g. HDMI 1) */
    TOS_TIFHAL_TVINPUT_TYPE_HDMI = 9,
    TOS_TIFHAL_TVINPUT_TYPE_DISPLAY_PORT = 10,

    TOS_TIFHAL_TVINPUT_TYPE_MAX
};

typedef struct {
	int deviceId;	///< ȫ��Ψһ���豸ID

	int type;	///< �豸���ͣ�ȡֵΪTOS_TIFHAL_TVINPUT_TYPE_E

	int portId;	///< ���豸�ţ���HDMI1��HDMI2,AV1,AV2��,һ���1��ʼ��
}tos_tifhal_tvinput_device_info_t;

typedef struct {
	int deviceId;	///< ȫ��Ψһ���豸ID������tos_tifhal_tvinput_request_capture��deviceId����

    int streamId;	///< ��ID������tos_tifhal_tvinput_request_capture��streamId������

    int sequence;	///< �������кţ�����tos_tifhal_tvinput_request_capture��sequence������

    int errCode;	///< �ɹ�Ϊ0��ʧ��Ϊ<0�Ĵ�����롣
}tos_tifhal_tvinput_capture_result_t;

typedef struct {
	int streamId;	///< ȫ��Ψһ���豸ID���ɵײ����

	int maxVideoWidth;	///< �����ܵ���Ƶ���
	int maxVideoHeight;	///< �����ܵ���Ƶ���
}tos_tifhal_tvinput_tv_stream_config_t;

/*
 @brief TVINPUT�ص�����

 @note �ڶ��δε��ñ��ӿ�ʱ�Ḳ��֮ǰ��״̬

 @param[in] type ��Ϣ���ͣ�ȡֵΪTOS_TIFHAL_TVINPUT_EVENT_TYPE_E��
 @param[in] param ��Ϣ��Ӧ�Ĳ����������ͼ�ȡֵ��TOS_TIFHAL_TVINPUT_EVENT_TYPE_E��˵��
 @param[in] userdata �û����ݣ�tos_tifhal_tvinput_initialize��userdata����ԭ������
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_tvinput_initialize(tos_tifhal_tvinput_notify callback,void* userdata);

/*
 @brief ��ȡ�豸��������

 @param[in] deviceId �豸id��ͬtos_tifhal_tvinput_device_info_t��deviceId.
 @return �ɹ������豸������������ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_tvinput_get_stream_count(int deviceId);

/*
 @brief ��ȡ�豸����������Ϣ

 @code ������÷�ʽ
 tos_tifhal_tvinput_tv_stream_config_t* pCconfig = NULL;
 int deviceId = xxx;
 int count = tos_tifhal_tvinput_get_stream_count(deviceId);
 pCconfig = (tos_tifhal_tvinput_tv_stream_config_t*)malloc(sizeof(tos_tifhal_tvinput_tv_stream_config_t)*count);
 assert(pCconfig != NULL);
 tos_tifhal_tvinput_get_stream_configurations(deviceId,pCconfig,count);
 @endcode

 @param[in] deviceId �豸id��ͬtos_tifhal_tvinput_device_info_t��deviceId.
 @param[in] configs �ṹ������ָ�룬�û��洢������Ϣ.
 @param[in] maxCount ��������ɵ���������������ڵ���tos_tifhal_tvinput_get_stream_count�ķ���ֵ,���򱾽ӿڷ���ʧ��.
 @return �ɹ������豸������������ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_tvinput_get_stream_configurations(int deviceId,tos_tifhal_tvinput_tv_stream_config_t *configs, int maxCount);

/*
 @brief �����ͼ

 @note �ýӿ���δʵ�֣�ֻ�����TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED��Ϣ��
 @note ���ص����ݿ�����tos_tifhal_tvinput_capture_result_t������FIFO����ͼƬ�ļ�·����

 @param[in] deviceId �豸id��ͬtos_tifhal_tvinput_device_info_t��deviceId.
 @param[in] streamId ��ID����tos_tifhal_tvinput_get_stream_configurations��ȡ��
 @param[in] sequence ��������кţ�����Ψһ��ʶһ�����󼰱�ʶ��Ӧ�ķ�����Ϣ��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_tvinput_request_capture(int deviceId,int streamId,int sequence);

/*
 @brief ȡ�������ͼ

 @param[in] deviceId �豸id��ͬtos_tifhal_tvinput_device_info_t��deviceId.
 @param[in] streamId ��ID����tos_tifhal_tvinput_get_stream_configurations��ȡ��
 @param[in] sequence ��������кţ�����Ψһ��ʶһ�����󼰱�ʶ��Ӧ�ķ�����Ϣ��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_tvinput_cancel_capture(int deviceId,int streamId,int sequence);

/*
 @brief TIF HDMI CEC�ص�����

 @param[in] type ��Ϣ���ͣ�ȡֵΪTOS_TIFHAL_HDMICEC_EVENT_TYPE_E
 @param[in] param ��Ϣ��Ӧ�Ĳ����������ͼ�ȡֵ��TOS_TIFHAL_HDMICEC_EVENT_TYPE_E��˵��
 @param[in] userdata �û����ݣ�tos_tifhal_hdmicec_add_callback����ԭ������
 */
typedef void (*tos_tifhal_hdmicec_callback)(int type, void* param, void* userdata);


typedef struct {
    int connected;  ///< 1��ʾ�����ӣ�0��ʾδ���ӣ�һ����˵��Ӳ����5V��ѹ�ж�
    int portId;    ///< HDMI��portId��ͬtos_tifhal_tvinput_device_info_t
} TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T;

typedef struct {
    int type;	///< ����������ͣ�0-����;1-���
    int portId; ///< ͬtos_tifhal_tvinput_device_info_t��portId����
    int isCecSupported; ///< �Ƿ�֧��CEC,0-��֧��;����-֧��
    int isArcSupported; ///< �Ƿ�֧��ARC,0-��֧��;����-֧��
    uint16_t physicalAddress;  ///< �˿ڵ������ַ
} TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T;

/*
 @brief HDMI CEC�ص�����ö��
 */
enum TOS_TIFHAL_HDMICEC_EVENT_TYPE_E {
    /*
     @brief CEC��Ϣ
 
     ��Ϣ��Ӧ��param����ΪST_FPP_CEC_RX_DATA_Tָ��
    */
    TOS_TIFHAL_HDMICEC_EVENT_CEC_MESSAGE = 1,

    /*
     @brief HDMI CE�Ȱβ���Ϣ
 
     ��Ϣ��Ӧ��param����ΪTOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_Tָ��
    */
    TOS_TIFHAL_HDMICEC_EVENT_HOT_PLUG = 2,
};

enum TOS_TIFHAL_HDMICEC_OPTION_FLAG_E{

    /*
     @brief �����Զ����ѹ��ܿ���
 
     ��ѡ������Ϊ0ʱ��ϵͳ���ᱻCEC�豸���ѣ�Ϊ1ʱ���Ա�CEC�豸���ѡ�
     Ĭ��ֵΪ1.

     ��ѡ����Ҫ�����û��ڲ˵��д򿪹ر�CECѡ���ʱ��
    */
    TOS_TIFHAL_HDMICEC_OPTION_WAKEUP = 1,

    /*
     @brief ����CECʹ�ܿ��ء�
 
     ��ѡ������δ0ʱ���������е�CEC���Ϊ1ʱ��������������ס�
     Ĭ��ֵΪ1.

     ��ѡ����Ҫ�����û��ڲ˵��д򿪹ر�CECѡ���ʱ��
    */
    TOS_TIFHAL_HDMICEC_OPTION_ENABLE_CEC = 2,

    /*
     @brief ����TIF����CECʹ�ܿ��ء�
 
     ��ѡ������δ0ʱ��TIF��CECģ��ֹͣ�������ɵײ��ṩCEC����Ϊ1ʱ��������������ף���TIF�ṩCEC����
     Ĭ��ֵΪ0.

     ��ѡ����Ҫ���ڴ���ʱ��CEC���������ν�ĵײ㴦����ָ�м���������Ǵ���CPU����
    */
    TOS_TIFHAL_HDMICEC_OPTION_SYSTEM_CEC_CONTROL = 3,

    /*
     @brief ����CEC���ԡ�

     ���ڴ���ʱ��Ӧ<Get Menu Language>���
 
     ��Ӧ��ֵΪISO/FDIS 639-2�����3�ֽڵ�ASCII�����룬��Ӣ��Ϊ0x656e67.
    */
    TOS_TIFHAL_HDMICEC_OPTION_SET_LANG = 5,
};


/*
 @brief ��ʼ��TIF��CECģʽ��ͬʱ�ر��м����HDMI-CEC������TIF������HDMI-CEC��Ϣ��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_init();

/*
 @brief ����ʼ��TIF��CECģʽ��ͬʱ�ָ��м����HDMI-CEC�������м��������HDMI-CEC��Ϣ��

 @note ����ʼ��������ע��Ļص�����ӵ������ַ�����õ�ѡ���ȫ����գ��ָ�Ĭ��ֵ��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_term();

/*
 @brief ��ӹ�ע���߼���ַ

 ֻ������˶�Ӧ�߼���ַ��CEC�豸����Ϣ�Ż�ص��������ߣ�������Ϣ�ᶪ��.
 Ĭ������²���ע�κ��߼���ַ��

 @note �˽ӿڿ��Ա��������ã���֧��ͬʱ��ע����߼���ַ��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_add_logical_address(EN_FPP_CEC_DEVICE_LOG_ADDR_T addr);

/*
 @brief ������е��߼���ַ��ע��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_clear_logical_address();

/*
 @brief ��ȡ�����߼���ַ

 @param[out] physicalAddress ����߼���ַ
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_get_physical_address(uint16_t* physicalAddress);

/*
 @brief ��HDMI�豸����CEC��Ϣ

 �ýӿڻ����ʵ���ʱ�򷵻�ʧ�ܣ�������һֱ������ֱ���ɹ�Ϊֹ��

 @param[in] msg CEC��Ϣ���ݽṹ
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_send_message(ST_FPP_CEC_RX_DATA_T* msg);

/*
 @brief ���HDMI CEC��Ϣ�ص�����

 ��ȫ��ͬ��callback��userdata�ᱻ��Ϊ����ͬ����ӣ��᷵��ʧ�ܾܾ��ظ���ӡ�

 @param[in] callback �ص�����ָ��
 @param[in] userdata �û����ݣ����ڻص�������userdata����
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_add_callback(tos_tifhal_hdmicec_callback callback, void* userdata);

/*
 @brief ���HDMI CEC��Ϣ�ص�����

 ֻ�е�callback��userdata����ͬʱ���ܳɹ�ɾ�������򷵻�ʧ��.

 @param[in] callback �ص�����ָ��
 @param[in] userdata �û����ݣ����ڻص�������userdata����
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_remove_callback(tos_tifhal_hdmicec_callback callback, void* userdata);

/*
 @brief ��ȡ����֧�ֵ�CEC�汾����HDMI�İ汾��

 @param[out] cecVersion ���CEC�汾��
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_get_version(int *cecVersion);

/*
 @brief ��ȡ������Ӧ��ID

 ����һ��24-bit����IEEE��֯����ĳ���Ψһ��š� 

 @param[out] vendorId �����Ӧ��ID
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_get_vendor_id(int *vendorId);

/*
 @brief ��ȡ��������HDMI�ӿ���Ϣ

 @param[out] portInfo �������HDMI�ӿ���Ϣ�Ľṹ������
 @param[in] maxCount portInfo��������ɵĽӿ�����
 @return �ɹ�����ʵ��HDMI�ӿ�����ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_get_port_info(TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T *portInfo,int maxCount);

/*
 @brief ����HDMI CECѡ��

 @param[in] flag ѡ���ȡֵΪTOS_TIFHAL_HDMICEC_OPTION_FLAG_E
 @param[in] value �û����ݣ����ڻص�������userdata����
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_set_option(int flag, int value);

/*
 @brief ��������/ֹͣARC�ķ���Ƶ������

 @param[in] portId HDMI��portId��ͬtos_tifhal_tvinput_device_info_t
 @param[in] value 1-������0-ֹͣ �˹���
 @return �ɹ�����0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_set_audio_return_channel(int portId,int flag);

/*
 @brief ��ѯHDMI�Ƿ�������

 һ����˵ʹ��Ӳ���ϵ�5V��ѹ���м��

 @param[in] portId HDMI��portId��ͬtos_tifhal_tvinput_device_info_t
 @return �����ӷ���1��δ���ӷ���0��ʧ�ܷ���<0�Ĵ�����롣
 */
int tos_tifhal_hdmicec_is_connected(int portId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif

