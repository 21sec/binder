
#ifndef __TOS_TBROWSER_H__
#define __TOS_TBROWSER_H__

#include "tos_key_code.h"

#ifndef CLOG_TAG
#define CLOG_TAG "clog_tbrowser"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ��ָ��ҳ��

@param[in] url ҳ���ַ
@return �ɹ�����0;ʧ�ܷ�������
*/
int tos_tbrowser_load_url(const char * url);


/**
@brief ��ҳ�淢�Ͱ����¼�

@param[in] keyType:�������ͣ�ȡֵTOS_KeyAction
@param[in] keyCode:��ֵ��������sdl���͵ļ�ֵ��keyCode��ȡֵ�μ�tos_key_code.h�İ�����ֵ����
@return �ɹ�����0;ʧ�ܷ�������
*/
int tos_tbrowser_push_event(TOS_KeyAction keyType ,int keyCode);

/**
@brief �˳����������
@return �ɹ�����0;ʧ�ܷ�������
*/
int tos_tbrowser_destory();

#ifdef __cplusplus
}
#endif
/** @} */
#endif
