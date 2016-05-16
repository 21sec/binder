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
@brief :解密Context;
@param[in] PR_SUPPORTED_CIPHERS_e: 加密类型;
@param[in] initIV:AES解密初始化向量;
@param[in] nInitIVLen: 初始化向量大小(bytes);
@param[in] blockOffset:加密数据的block 序号;
@param[in] byteOffset:加密数据的block 偏移;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
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
@brief 初始化，获取context;
@param[in] strPathDir: 指定一个绝对路径存放PLAYREADY相关的证书文件;
@param[out] context: 初始化成功获取的context;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_playready_init(const char *strPathDir,fpi_playready_context *context);


/**
@brief :反初始化，释放初始化分配的资源；
@param[in] context: 初始化对应的context;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_playready_uninit(fpi_playready_context context);


/**
@brief :生产向PLAYREADY服务器请求LICENSE所需要的CHALLENGE 和PLAYREADY'S SERVER URL；
@param[in] context: 初始化对应的context;
@param[in] pDrmHeaderBuf: 获取LICENSE所需要的内容头BUFFER;
@param[in] drmHeaderBufSize:内容头BUFFER的大小;
@param[in] pCustomData: 获取LICENSE所需的CUSTOM DATA的BUFFER;
@param[in] customDataSize: CUSTOM DATA的大小;
@param[out] pChallenge: 向服务器请求LICENSE所需要的CHALLENGE 的BUFFER;
@param[out] challengeSize: CHALLENGE的大小;
@param[out] pServerURL: 向服务器请求LICENSE所需要的PLAYREADY'S SERVER URL的BUFFER;
@param[out] serverURLSize: PLAYREADY'S SERVER URL的大小;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
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
@brief :释放PLAYREADY向服务器请求LICENSE所需要的CHALLENGE 和PLAYREADY'S SERVER URL;
@param[in] pChallenge: 向服务器请求LICENSE所需要的CHALLENGE 的BUFFER;;
@param[in] pServerURL: 向服务器请求LICENSE所需要的PLAYREADY'S SERVER URL的BUFFER;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_playready_free_request(unsigned char *pChallenge,char *pServerURL);


/**
@brief :处理PLAYREADY'S SERVER的RESPONSE;
@param[in] context: 初始化对应的context;
@param[in] pResponseBuf:PLAYREADY'S SERVER的RESPONSE buffer;
@param[in] nBufSize: RESPONSE buffer 大小;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_playready_update(fpi_playready_context context,const unsigned char *pResponseBuf,int nBufSize);


/**
@brief :解密加密内容;
@param[in] context: 初始化对应的context;
@param[in&out] pEnBuf:加密数据buffer;
@param[in] nEnBufSize: 加密数据 大小;
@param[in] decryptContext:详见MP_DECRYPT_CONTEXT_t解析;
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_playready_decrypt(fpi_playready_context context,
										unsigned char *pEnBuf,
										int nEnBufSize,
										FPI_DECRYPT_CONTEXT_t *decryptContext); 



#ifdef __cplusplus
}
#endif

#endif //_TCL_PLAYREADY_IMP_H_
