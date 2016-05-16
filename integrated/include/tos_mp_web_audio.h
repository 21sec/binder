/**@defgroup tos_mp_web_audio.h
@{

@brief 
*/

#ifndef __TOS_MP_WEB_AUDIO_H__
#define __TOS_MP_WEB_AUDIO_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief �Դ������Ƶ���ݽ��н���

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] buffer ��Ƶ�����׵�ַ.
@param[in] buffer_size ��Ƶ���ݳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
int tos_mp_audio_decode(unsigned char* buffer, uint32_t buffer_size);

/**
@brief ��ʼ��mp_audioģ��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_audio_init();

/**
@brief ����ʼ��mp_audioģ��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_audio_uninit();

/**
@brief ����ָ��������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_audio_play(int decoder_id);

/**
@brief ֹͣ����

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_audio_stop();

#ifdef __cplusplus
}
#endif
/** @} */
#endif
