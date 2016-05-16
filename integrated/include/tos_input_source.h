/**@defgroup ��Դ
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/23 linshunda ����
*/


#ifndef __TOS_INPUTSOURCE_H__
#define __TOS_INPUTSOURCE_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ��Դ��״̬
**/
typedef enum
{
	EN_SOURCE_CURRENT,///<��ǰ��Դ
	EN_SOURCE_LASTEST,///<������Դ
	EN_SOURCE_TARGET,///<Ŀ����Դ
}EN_SOURCE_SAVE_TYPE;

/*
typedef enum
{
	SESSION_CREATED,
	SESSION_DESTROYED,
	SESSION_REQUESTED,
	SESSION_RELEASED,
}EN_SESSION_STATUS;


typedef struct
{
	int32_t session_id;
	EN_SESSION_STATUS session_status;
	EM_SOURCE_TYPE source_type;
}session_info;
*/
/**
@brief �첽�л�������Դ

@param input ����Դ,
@param	act ,ִ����Ϊ: ִֻ�У�ֻ���棬ִ�в�����
@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_source_set_input_async(EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);


/**
@brief �л�������Դ


@param input ����Դ,
@param  act ,ִ����Ϊ: ִֻ�У�ֻ���棬ִ�в�����


@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_set_input(EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);

/**
@brief ���������Դ

@param  type:EN_SOURCE_CURRENT: �е�ǰ��Դ,EN_SOURCE_LASTEST: ���±������Դ��

@retval value�ĸ���Դֵ

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_get_input(EN_SOURCE_SAVE_TYPE type,EN_API_SOURCE_INPUT *value);


/**
@brief ���ָ��������Դ�Ƿ��в��룬����һ����fpp�����ж��ź�״̬��

@param  inSource ����Դ,

@retval  state:0 , �޲��룬 1: ���� ��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_is_insert(EN_API_SOURCE_INPUT inSource, int *state);


/**
@brief ����session_id��Ӧ���豸�Ŀ���Ȩ
 
ֻ���Ȼ�ȡ����Ȩ����ʹ�ö�Ӧ��session_id�����豸��
ͬ���ӿڣ����ӿڷ��سɹ��󼴱�ʾ�ѳɹ���ÿ���Ȩ��ͬʱ�����첽��Ϣ֪֮ͨǰ���ڿ���Ȩ��session_id�Ŀ���Ȩ���ͷš�
����Ȩ��������ʱ�ǲ��ɾܾ�������ȷ�ϵġ���˭����������Ȩ��˭�ͻ��ÿ���Ȩ��
 
ÿ��session_idÿ�λ�ȡ������Ȩʱ����ǰ��Դ������뵽��ʼ״̬����ʱû���κ�ͨ������ͨ��û���κ��豸��ռ�ã�ʹ�������PQ������USB����״̬Ϊȫ����û���κ������ڲ��š�
*/
fpi_error tos_source_request(uint32_t session_id);
 
/**
@brief �ͷ�session_id��Ӧ���豸�Ŀ���Ȩ
 
����ʹ�ö�Ӧ�豸ʱ������ô˽ӿ��ͷſ���Ȩ��
ͬ���ӿڣ����ӿڷ��سɹ��󼴱�ʾ�ѳɹ��ͷſ���Ȩ��
 
ÿ��session_idÿ���ͷſ���Ȩʱ����ǰ��Դ������뵽��ʼ״̬����ʱû���κ�ͨ������ͨ��û���κ��豸��ռ�ã�ʹ�������PQ������USB����״̬Ϊȫ����û���κ������ڲ��š�
*/
fpi_error tos_source_release(uint32_t session_id);

/**
@brief �л���Դ��ָ������Դ
 
������Ӧsession_idӵ�п���Ȩʱ��Ч�����򷵻�ʧ�ܡ�
һ�����ӿڳɹ����أ�tos_source_get_input���ɼ��ɻ�ȡinputΪ��ǰ��Դ��������֮ǰ����ԴΪ��һ����Դ����ʵ���л�����ҪһЩʱ���첽��ִ�С�
ʵ���л���ɺ󣬻����ź���ص���Ϣ֪ͨ��Ӧ��Դ�Ƿ����ź��Լ��źŵ����ԡ�
*/
fpi_error tos_source_set_input_with_session(uint32_t session_id,EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);

/**
@brief ��ȡHDMI�İ汾�����

@param  input :��Դ,

@param  ver:�汾 : 0:�Զ�,1:1.4 ,2:2.0 ��


@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_get_hdmi_edid_ver(EN_API_SOURCE_INPUT input, int32_t *ver);

/**
@brief ����HDMI�İ汾��������� 1.4 �� 2.0 ������һ���޷��Զ��жϡ�

@param  input :��Դ,

@param  ver:�汾 : 0:�Զ�,1:1.4 ,2:2.0 ��


@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_set_hdmi_edid_ver(EN_API_SOURCE_INPUT input, int32_t ver);
/**
@brief ���ÿ�����������Դ

@param  bootSource:0 �Զ���������һ�ιػ���Դ������

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_set_bootinput(EN_TOS_SOURCE_BOOT_INPUT bootSource);

/**
@brief �жϵ�ǰ��Դ�Ƿ�ΪITV��Դ
@param  isitv:0 :��ǰ��Դ����itv
			1:��ǰ��Դ��itv

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_source_is_itv(int *isitv);
#ifdef __cplusplus
}
#endif
/** @} */

#endif 
