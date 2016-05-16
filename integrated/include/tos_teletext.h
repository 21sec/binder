/**@defgroup Teletextģ��

@{
@brief ���ڿ��Ƶ�����Teletext��ز���

@version 1.0.0
**/

#ifndef __TOS_TELETEXT_H__
#define __TOS_TELETEXT_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#ifdef __cplusplus
extern "C" 
{
#endif

typedef enum
{
	E_TELETEXT_STATE_OFF = 0x1,              ///< �ر�teletext���״̬
	E_TELETEXT_STATE_ON = 0x2,               ///< teletext���ڴ�ʱ��״̬
	E_TELETEXT_STATE_SMALL_WINDOW = 0x3,     ///< teletext���ڰ���ʱ��״̬
	E_TELETEXT_STATE_ALL_MIX = 0x4,          ///< teletext����newsflash��alarmpageʱ��״̬
    E_TELETEXT_STATE_SUBTITLE = 0x5,         ///< teletext������Ļʱ��״̬
} EN_FPI_TELETEXT_STATE;

 typedef enum
{
	E_TELETEXT_LANG_WEST,
	E_TELETEXT_LANG_EAST,
	E_TELETEXT_LANG_RUSSIAN,
	E_TELETEXT_LANG_ARABIC_HEBREW,
	E_TELETEXT_LANG_FARSI,
	E_TELETEXT_LANG_ARABIC,
	E_TELETEXT_LANG_BYELORUSSIAN
}EN_FPI_DECODE_PAGE_LANGUAGE;

typedef struct
{
	int32_t reVealState;
	int32_t cycleSubPageState;
	int32_t newsFlashState;
    int32_t alarmpageState;
} fpi_teletext_show_state;


/**
@brief teletext�ĳ�ʼ״̬ΪE_TELETEXT_STATE_OFF , ���øýӿڣ� ��teletext
@param[in] none
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_on();

/**
@brief teletext��״̬ΪE_TELETEXT_STATE_HALF_MIX ʱ�����øýӿڣ��ر� teletext
@param[in] none
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_off();

/**
@brief teletext��״̬ΪE_TELETEXT_STATE_ON ��E_TELETEXT_STATE_ALL_MIX����E_TELETEXT_STATE_SUBTITLEʱ�����øýӿڣ� ��small screen teletext
@note ע��: output window teletextĿǰ��half screen teletext
@param[in] x �� y:output window ��ʼ���ꣻwidth  ��height:output window �ĳ����
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_set_output_window(int32_t x,int32_t y,int32_t width,int32_t height);

/**
@brief ��ȡteletext״̬
@param[in] state �����ָ������ ��ȡteletext��ǰ��״̬EN_FPI_TELETEXT_STATE
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_get_state(EN_FPI_TELETEXT_STATE *state);


/**
@brief ��ȡ��ǰ��Ŀ�Ƿ��� teletext
@param[in] value �����ָ������ ��ȡ�Ƿ���teletext
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_is_available(fpi_bool *value);

/**
@brief ��ȡ��ǰteletext ҳ�Ƿ���subpage
@param[in] value �����ָ������ ��ȡ��ǰteletext ҳ�Ƿ���subpage
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_subpage_is_available(fpi_bool *value);

/**
@brief ��ȡ��ǰteletext ҳ�Ƿ���newsflash
@param[in] value �����ָ������ ��ȡ��ǰteletext ҳ�Ƿ���newsflash
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_newsflash_is_available(fpi_bool *value);

/**
@brief ��ȡ��ǰteletext ҳ�Ƿ���alarmpage ��ҳ
@param[in] value �����ָ������ ��ȡ��ǰteletext ҳ�Ƿ���alarmpage
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_alarmpage_is_available(fpi_bool *value);

/**
@brief ��ȡ��ǰteletext ��reveal״̬�Ƿ��(�򿪵Ļ�������Щ�����ַ���ʾ����)
@param[in] value �����ָ������ ��ȡ��ǰteletextҳ��reveal �Ƿ��
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_reveal_is_on(fpi_bool *value);

/**
@brief ��ȡ��ǰteletext ��subpage cycle�Ƿ��(�򿪵Ļ���subpage�Զ�ѭ���л�)
@param[in] value �����ָ������ ��ȡ��ǰteletextҳ��subpage cycle�Ƿ��
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_subpage_cycle_is_on(fpi_bool *value);

/**
@brief �л���ǰteletext ҳ��reveal״̬(on or off)
@param[in] none
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_toggle_reveal();

/**
@brief ���õ�ǰteletext ҳ��reveal״̬(on or off)
@param[in] revealMode teletext ҳ��reveal״̬
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_set_reveal_mode(fpi_bool revealMode);

/**
@brief �л���ǰteletext ��subpage �Ƿ���ѭ������(on or off)
@param[in] none
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_toggle_subpage_cycle_model();

/**
@brief ���õ�ǰteletext ��subpage ѭ������(on or off)
@param[in] subpageMode teletext ��subpage ѭ������״̬
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_set_subpage_cycle_mode(fpi_bool subpageMode);

/**
@brief ���õ�ǰteletext������
@note ��Ҫ�������
@param[in] groupId language teletext���õ�������
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_set_language_group(uint8_t groupId);

/**
@brief ��ȡ��ǰteletext������
@param[in] groupId �����ָ�����ڻ�ȡ��ǰteletext ������
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_get_language_group(uint8_t *groupId);

/**
@brief ����teltext ����
@param[in] language MEMBER_LANGUAGE language ����ö��ֵ������MEMBER_LANGUAGEö��ֵ
@param[out] none
@return fpi_error:  FPI_ERROR_SUCCESS -- get success; FPI_ERROR_FAIL  -- get fail
*/
fpi_error tos_teletext_set_digital_language(MEMBER_LANGUAGE language);

/**
@brief ��ȡteltext����
@param[in] language MEMBER_LANGUAGE *language, ����ö��ֵָ��:ö�ٲ���MEMBER_LANGUAGEö��ֵ
@param[out] none
@return fpi_error:  FPI_ERROR_SUCCESS -- get success; FPI_ERROR_FAIL  -- get fail
*/
fpi_error tos_teletext_get_digital_language(MEMBER_LANGUAGE *language);

/**
@brief ��ң������ֵ����teletext ģ�鴦��.
@noteע��: ���������еļ�ֵ��Ҫteletext ģ���������, ��Ҫ����teletext �ļ�ֵ����: ������
�ҷ������ȷ���������ּ������̻�����ɫ�������·�ҳ��
@param[in] keyCode ң������ֵ���������м�����幫��ʹ�õļ�ֵ
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_handle_key(int keyCode);

/**
@brief ��ǰteletext ҳ��newsflash ҳʱ����ȷ�������õ��øýӿ�
@note ע��:newsflash�������teletextҳ����ǰteletext ҳ��newsflash ҳʱ��teletext���ò˵��ᵯ������ʾ
�����ʾ��newsflash ok�������ϣ���ȷ����ȷ��newsflash,��newsflashˢ��ʱ,��ʾnewsflash��
@param[in] none                        
@param[out] none   
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_open_newsflash();

/**
@brief ��ǰteletext ҳ��alarmpage ��ҳʱ����������ʱ�����øýӿ�
@note ע��:alarmpage�������teletext ��ҳ����ǰteletext ҳ��alarmpage ҳʱ��teletext���ò˵���alarmpage������
��������ʱ�䣬���ú�����ʱ��󣬵����ú�teletext alarmpage����ʱ������ʾ���õ�alarmpage��
@param[in] t_time ����� ʱ�䣬��Ӧ��teletext��������ҳ��
��������ʽΪ:�����ǧλ���λ��Ӧʱ���Сʱ��ʮλ���λ��Ӧʱ��ķ��ӣ���0938��Ӧʱ��09:38                      
@param[out] none
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_teletext_open_alarmpage(uint16_t t_time);


#ifdef __cplusplus
}
#endif

#endif

