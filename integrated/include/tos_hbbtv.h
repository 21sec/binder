/**@defgroup HBBTVģ��

@{
@brief ���ڿ��Ƶ�����HBBTV��ز���

@version 1.0.0
**/

#ifndef __TOS_HBBTV_H__
#define __TOS_HBBTV_H__

#include "tos_dtv_basetype.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" 
{
#endif


typedef enum
{
    EN_TOS_HBBTV_OFF = 0x0,                  ///< hbbtv�ر�״̬
    EN_TOS_HBBTV_RED_BUTTON = 0x1,            ///<hbbtv��������ʾΪ��ɫ��ť
    EN_TOS_HBBTV_FULLSCREEN_NO_VOD = 0x2,    ///< hbbtv��������ʾȫ����û�в���VOD
	EN_TOS_HBBTV_FULLSCREEN_VOD = 0x3,       ///< hbbtv��������ʾȫ����������VOD
	EN_TOS_HBBTV_INVALID,                    ///< ��Ч
} EN_TOS_HBBTV_STATE;   


/**
@brief �жϵ�ǰƵ���Ƿ���HbbTv
@param[out] exist ��HbbTv����fpi_true;û��HbbTv����fpi_false
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_is_exist(fpi_bool *exist);

/**
@brief ����HbbTv
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_open();

/**
@brief �ر�HbbTv
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_close();

/**
@brief ��ȡhbbtv�ĵ�ǰ����״̬
@param[out] state hbbtv��״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_get_state(EN_TOS_HBBTV_STATE *state);

/**
@brief ���հ���
@param[in] keyCode ��ֵ;keyType ��������
@param[out] isHandle HbbTv�����˸ð�������fpi_true;��֮����fpi_false
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_handle_key(uint16_t keyCode,uint16_t keyType,fpi_bool* isHandle);

/**
@brief ��ȡhbbtv �û����ص�״̬
@param[out] mode hbbtv ���ص�״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_get_mode(fpi_bool *mode);

/**
@brief ����hbbtv �û�����
@param[in] mode hbbtv ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_set_mode(fpi_bool mode);

/**
@brief ��ȡhbbtv cookie �û�����״̬
@param[out] mode hbbtv cookie���ص�״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_get_cookie_mode(fpi_bool *mode);

/**
@brief ����hbbtv cookie �û�����
@param[in] mode hbbtv cookie����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_set_cookie_mode(fpi_bool mode);

/**
@brief �жϵ�ǰƵ���Ƿ���HbbTV��Teletext
@param[out] exist ����fpi_true;û��fpi_false
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_teletext_is_exist(fpi_bool *exist);

/**
@brief �ж�HbbTV��Teletext�Ƿ��ѱ���
@param[out] open �Ѵ�fpi_true;û�д�fpi_false
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_teletext_is_open(fpi_bool *open);

/**
@brief ����HbbTV��Teletext
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_teletext_open();

/**
@brief �ر�HbbTV��Teletext
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_teletext_close();

/**
@brief ��һ��hbbtv Ӧ��
@param[in] webPortalURL:Ҫ�򿪵�hbbtv��url
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_open_portal(char* webPortalURL);

/**
@brief �ر�hbbtv Ӧ��
@param[in] void
@return FPI_ERROR_SUCCESS�ɹ�;ʧ�ܷ�������ֵ
*/
fpi_error tos_hbbtv_close_portal(void);

#ifdef __cplusplus
}
#endif
/** @} */
#endif


