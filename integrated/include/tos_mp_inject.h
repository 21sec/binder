/**@defgroup tos_mp_inject
@{

@brief ����tos_mp_prorocol��װ�˲�ע�벥�ŵ�Ӧ�ýӿ�

@code ����ʹ�ó���ʾ��
//��ʼ����
tos_mp_set_datasource(x,"blob:http://xxx");//blob:http://���Զ����һ��Э��ͷ
tos_mp_prepare(x);
tos_mp_play(x);

tos_mp_send_buffer(x, buffer, length);

//��ͣ������
tos_mp_pause(x);

//ֹͣ
tos_mp_stop(x);

//�ͷ�
tos_mp_stop(x);
tos_mp_release(x);
@endcode

@history 2015/1/12 ����
*/

#ifndef __TOS_MP_INJECT_H__
#define __TOS_MP_INJECT_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"
#include "tos_mp_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ����Buffer Commandö��
*/
typedef enum {
    EN_FPI_MP_BUFFER_CMD_EOS,              ///< EOS
    EN_FPI_MP_BUFFER_CMD_UNKNOW            ///< UNKNOW 
}FPI_MP_BUFFER_CMD_E;

/**
@brief ��ָ��playerע������Ƶ����

@param[in] srcId  Source Buffer ID.
@param[in] buffer Ҫע�������Ƶ����
@param[in] length Ҫע�������Ƶ���ݵĳ���
@param[in] timeOffset Ҫע�������Ƶ���ݵ�ʱ��ƫ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_send_buffer(unsigned int srcId, const char *buffer, int length, unsigned long timeOffset);

/**
@brief �����ָ��playerע�������Ƶ����

@param[in] srcId  Source Buffer ID.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_clear_buffer(unsigned int srcId);

/**
@brief �����µ�source buffer

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return �ɹ�����source buffer ID;ʧ�ܷ���0
*/
int tos_mp_create_buffer(unsigned int playerId);

/**
@brief �����µ�source buffer

@param[in] srcId  Source Buffer ID.
@param[in] cmd  command ����.
@return �ɹ�����0;ʧ�ܷ���-1
*/
fpi_error tos_mp_buffer_command(unsigned int srcId, FPI_MP_BUFFER_CMD_E cmd);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
