/**@defgroup �Ự����ģ��
@{

@brief ���ڴ������ٻỰ,����Ự���ʹ��,�����ɸ�ģ�����о���,��ģ�����Ϊ����ģ��Э������Ψһ�ĻỰID

@author lihui02@tcl.com

@version 1.0.0 2015/12/16 ����
*/

#ifndef __TOS_SESSION_H__
#define __TOS_SESSION_H__

#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	SESSION_CREATED,
	SESSION_DESTROYED,
	SESSION_REQUESTED,
	SESSION_RELEASED,
}EN_SESSION_STATUS;

typedef enum
{
	SESSION_TYPE_INPUT_SOURCE,
	SESSION_TYPE_INVALID,
}EM_SESSION_TYPE;

/**
@brief �����Ự�����ڻ����Դ���豸�Ŀ���Ȩ�������в�����
*/
fpi_error tos_session_create(EM_SESSION_TYPE source_type, uint32_t* session_id);

/**
@brief ���ٻỰ������ǰ���Զ��ͷŻػ���Ӧ�豸�Ŀ���Ȩ��
*/
fpi_error tos_session_destory(uint32_t session_id);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
