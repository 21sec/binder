#ifndef __TOS_MP_LYRIC_H__
#define __TOS_MP_LYRIC_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct 
{
    char ar_text[64];
    char al_text[64];
    char ti_text[64];
    char by_text[64];
}FPI_LRC_TITLE_INFO_S;

typedef struct 
{
    int index;
    int min;
    int sec;
    char data[200];
}FPI_LRC_TEXT_S;

typedef struct 
{
    FPI_LRC_TITLE_INFO_S title_info;
    int total_lines;
	int malloc_lines; 
    FPI_LRC_TEXT_S lrc_text_array[200];
}FPI_LRC_INFO_S;

/**
@brief ���ø���ļ�

@param[in] filepath����ļ�·��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_lyric_file(char* filepath);


/**
@brief ��ø���ļ�����Ϣ

@param[in] info�����洢����ļ�����Ϣ

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_lyric_info(FPI_LRC_INFO_S** info);

/**
@brief ���ָ��λ�õĸ����Ϣ

@param  [in]startIndex, ָ����ʼ����
		[in]numbers, ָ����Ŀ
		[out] arrays�����洢����ļ�����Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_lyric_arrays(int32_t startIndex, int32_t numbers, FPI_LRC_TEXT_S **arrays);


/**
@brief ��õ�ǰʱ�������Ҫ��ʾ�ĸ������

@param  [in] time, ��ǰ���ŵ�ʱ��
		[out] index���������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_lyric_current_index(int64_t time, int32_t* index);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
