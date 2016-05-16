#ifndef _TCL_PLAYREADY_IMP_H_
#define _TCL_PLAYREADY_IMP_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include "fpi_error_code.h"
#include "fpi_base_type.h"


typedef void* fpi_playready_context;

typedef enum _FPI_SUPPORTED_CIPHERS_s
{
    PR_INVALID_CIPHER    = 0,
    PR_RC4_CIPHER        = 1,
    PR_AES_CTR_CIPHER    = 2,
    PR_AES_CBC_CIPHER    = 3,//for 128 bit
    PR_AES_CTR128_CIPHER = 4,
}FPI_SUPPORTED_CIPHERS_e;


/**
@brief :����Context;
@param[in] PR_SUPPORTED_CIPHERS_e: ��������;
@param[in] initIV:AES���ܳ�ʼ������;
@param[in] nInitIVLen: ��ʼ��������С(bytes);
@param[in] blockOffset:�������ݵ�block ���;
@param[in] byteOffset:�������ݵ�block ƫ��;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

typedef struct _FPI_MP_DECRYPT_CONTEXT_s
{		
	FPI_SUPPORTED_CIPHERS_e  type;
	const unsigned char		 *initIV;
	int						 nInitIVLen;
	int64_t					 blockOffset; 
	unsigned char			 byteOffset;
}FPI_DECRYPT_CONTEXT_t;


/**
@brief ��ʼ������ȡcontext;
@param[in] strPathDir: ָ��һ������·�����PLAYREADY��ص�֤���ļ�;
@param[out] context: ��ʼ���ɹ���ȡ��context;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_init(const char *strPathDir,fpi_playready_context *context);


/**
@brief :����ʼ�����ͷų�ʼ���������Դ��
@param[in] context: ��ʼ����Ӧ��context;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_uninit(fpi_playready_context context);


/**
@brief :������PLAYREADY����������LICENSE����Ҫ��CHALLENGE ��PLAYREADY'S SERVER URL��
@param[in] context: ��ʼ����Ӧ��context;
@param[in] pDrmHeaderBuf: ��ȡLICENSE����Ҫ������ͷBUFFER;
@param[in] drmHeaderBufSize:����ͷBUFFER�Ĵ�С;
@param[in] pCustomData: ��ȡLICENSE�����CUSTOM DATA��BUFFER;
@param[in] customDataSize: CUSTOM DATA�Ĵ�С;
@param[out] pChallenge: �����������LICENSE����Ҫ��CHALLENGE ��BUFFER;
@param[out] challengeSize: CHALLENGE�Ĵ�С;
@param[out] pServerURL: �����������LICENSE����Ҫ��PLAYREADY'S SERVER URL��BUFFER;
@param[out] serverURLSize: PLAYREADY'S SERVER URL�Ĵ�С;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_generate_request(fpi_playready_context context,
                                  const unsigned char *pDrmHeaderBuf, 
                                  int drmHeaderBufSize, 
                                  const unsigned char *pCustomData, 
                                  int customDataSize,
                                  unsigned char **pChallenge, 
                                  int *challengeSize,
                                  char **pServerURL, 
                                  int *serverURLSize);


/**
@brief :�ͷ�PLAYREADY�����������LICENSE����Ҫ��CHALLENGE ��PLAYREADY'S SERVER URL;
@param[in] pChallenge: �����������LICENSE����Ҫ��CHALLENGE ��BUFFER;;
@param[in] pServerURL: �����������LICENSE����Ҫ��PLAYREADY'S SERVER URL��BUFFER;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_free_request(unsigned char *pChallenge,char *pServerURL);


/**
@brief :����PLAYREADY'S SERVER��RESPONSE;
@param[in] context: ��ʼ����Ӧ��context;
@param[in] pResponseBuf:PLAYREADY'S SERVER��RESPONSE buffer;
@param[in] nBufSize: RESPONSE buffer ��С;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_update(fpi_playready_context context,const unsigned char *pResponseBuf,int nBufSize);


/**
@brief :���ܼ�������;
@param[in] context: ��ʼ����Ӧ��context;
@param[in&out] pEnBuf:��������buffer;
@param[in] nEnBufSize: �������� ��С;
@param[in] decryptContext:���MP_DECRYPT_CONTEXT_t����;
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_playready_decrypt(fpi_playready_context context,
										unsigned char *pEnBuf,
										int nEnBufSize,
										FPI_DECRYPT_CONTEXT_t *decryptContext); 



#ifdef __cplusplus
}
#endif

#endif //_TCL_PLAYREADY_IMP_H_
