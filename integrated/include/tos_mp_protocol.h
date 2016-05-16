/**@defgroup tos_mp_protocol
@{

@brief ý�岥����Э��ģ��,�����Զ���ý��Դ

@history 2014/12/17 ����
*/

#ifndef __TOS_MP_PROTOCOL_H__
#define __TOS_MP_PROTOCOL_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#include "tos_mp_player.h"

#ifdef __cplusplus
extern "C" {
#endif


#define FPI_MP_PROTOCOL_ERROR_NOERROR       0   ///< �ɹ�
#define FPI_MP_PROTOCOL_ERROR_UNKNOWN       -1  ///< δ֪����
#define FPI_MP_PROTOCOL_ERROR_NOSUPPORT     -2  ///< ��֧��
#define FPI_MP_PROTOCOL_ERROR_TIMEOUT       -3  ///< ��ʱ
#define FPI_MP_PROTOCOL_ERROR_EAGAIN        -4  ///< ��ʱû������


/**
@brief ����URLЭ��ṹ
*/
typedef struct {
    int size;           ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_URLProtocol_S)
    const char *name;   ///< Э��ͷ���ַ���,����ָ��һ���ַ���������ַ,�Ա�ָ�뱣����Ч
    int     (*url_open)(const char *url, void *userData);    ///< ��������Դ;ʧ�ܷ��ش�����
    int     (*url_read)(unsigned char *buf, int size, void *userData);      ///< ��ȡ����,�ڶ�ʱ����(100ms)������������;ʧ�ܷ��ش�����
    int64_t (*url_seek)(int64_t offset, int whence, void *userData);   ///< ��λ��ָ��ʱ���;�ɹ���������ڿ�ʼλ�õ�ƫ��ʱ���;ʧ�ܷ��ش�����
    int     (*url_close)(void *userData);   ///< �ر�����Դ;ʧ�ܷ��ش�����
    void *userData;     ///< �û�����
} FPI_MP_URLProtocol_S;


/**
@brief ע��FPI_MP_URLProtocol_SЭ��

@param[in] protocol FPI_MP_URLProtocol_S�ṹ���ַ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_register_protocol(FPI_MP_URLProtocol_S *protocol);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
