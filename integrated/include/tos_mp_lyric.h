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
@brief 设置歌词文件

@param[in] filepath歌词文件路径

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_lyric_file(char* filepath);


/**
@brief 获得歌词文件的信息

@param[in] info用来存储歌词文件的信息

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_lyric_info(FPI_LRC_INFO_S** info);

/**
@brief 获得指定位置的歌词信息

@param  [in]startIndex, 指定起始索引
		[in]numbers, 指定数目
		[out] arrays用来存储歌词文件的信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_lyric_arrays(int32_t startIndex, int32_t numbers, FPI_LRC_TEXT_S **arrays);


/**
@brief 获得当前时间点上需要显示的歌词索引

@param  [in] time, 当前播放的时间
		[out] index，歌词索引

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_lyric_current_index(int64_t time, int32_t* index);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
