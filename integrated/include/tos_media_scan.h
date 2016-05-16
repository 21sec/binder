/**@defgroup tos_media_scan
@{

@brief 多媒体文件扫描

@code 常见使用场景示例
//扫描文件并获取文件信息:
tos_ms_start_scan_file(x)
tos_ms_set_scan_mode(x)
tos_ms_get_file_count(x,x)
tos_ms_get_file_list_by_type(x,x,x,x)

@endcode

@history 2015/04/16 初稿
@history 2015/04/20  根据组内评审意见修改:增加文件排列方式枚举;完善接口名字和注释.
@history 2015/04/22 根据部门评审意见修改:删除FPI_MS_File_Node_S 文件信息结构体中的next;
                    tos_ms_start_scan_file 接口定为异步接口;
                    增加回调函数等.
*/


#ifndef __TOS_MEDIA_SCAN_H__
#define __TOS_MEDIA_SCAN_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 定义文件类型枚举
*/
typedef enum 
{
    EN_FPI_MS_FILE_TYPE_DIR = 1,       ///<文件类型为目录
    EN_FPI_MS_FILE_TYPE_PICTURE = 2,   ///<文件类型为图片
    EN_FPI_MS_FILE_TYPE_VIDEO = 4,     ///<文件类型为视频
    EN_FPI_MS_FILE_TYPE_MUSIC = 8,     ///<文件类型为音乐
    EN_FPI_MS_FILE_TYPE_OTHER = 16      ///<文件类型为其他
}FPI_MS_FILE_TYPE_E;

/**
@brief 定义文件扫描方式枚举
*/
typedef enum 
{
    EN_FPI_MS_SCAN_MODE_NORMAL,      ///<按标准方式扫描
    EN_FPI_MS_SCAN_MODE_RECURSIVE    ///<按递归方式扫描
}FPI_MS_SCAN_MODE_E;

/**
@brief 定义文件排列方式枚举
*/
typedef enum 
{
    EN_FPI_MS_SORT_MODE_NAME,       ///<按名字排序
    EN_FPI_MS_SORT_MODE_TIME      ///<按时间排序
}FPI_MS_SORT_MODE_E;



/**
@brief 定义文件扫描事件枚举
*/
typedef enum 
{
    EN_FPI_MS_CB_EVENT_SCAN_STARTED,          ///<文件扫描开始
    EN_FPI_MS_CB_EVENT_SCAN_FINISHED,          ///<文件扫描完成
    EN_FPI_MS_CB_EVENT_SCAN_THUMBNAIL          ///<文件缩略图获取成功
}FPI_MS_CB_EVENT_E;


#define MEDIA_FILE_PATH_SIZE 1024

/**
@brief 定义媒体文件信息结构体
*/
typedef struct
{
    char path[MEDIA_FILE_PATH_SIZE];									///<文件路径
    char name[MEDIA_FILE_PATH_SIZE];									///<文件名
    FPI_MS_FILE_TYPE_E type;                    ///< 文件类型:Dir, picture, video, music, other
    long filesize;                              ///<文件大小
    long time;                                  ///<文件最后修改时间
}FPI_MS_File_Node_S;



/**
@brief 文件扫描的回调函数类型定义

@param[in] event 产生的事件类型枚举
@param[in] userData 用户数据,其值为调用fpi_mp_add_callback时传入的用户数据
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
typedef fpi_error (*tos_ms_callback_fn)(FPI_MS_CB_EVENT_E event, void *userData);


/**
@brief 添加指定文件扫描的回调函数

@param[in] cb 回调函数指针
@param[in] userData 用户数据,会在回调函数中抛出
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_add_callback(tos_ms_callback_fn cb, void* userData);


/**
@brief 删除指定文件扫描的回调函数

@param[in] cb 回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_remove_callback(tos_ms_callback_fn cb);



/**
@brief  开始扫描文件路径

@note 此接口为异步

@param[in] path 文件路径 .
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_start_scan_file(const char *path);


/**
@brief 退出媒体文件扫描，停止正在进行的文件扫描；

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_cancel_scan_file();


/**
@brief 根据文件类型获取文件列表

@note 对文件有sort、目录切换、文件类型切换等情况都要调用这个接口来更新文件列表

@param[in] mode 文件排列方式
@param[in] path 要扫描的目录
@param[in] type 要扫描的文件类型(video, audio, picture, all files)
@param[out] list 媒体文件list
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_get_file_list_by_type(FPI_MS_SORT_MODE_E mode, const char *path, FPI_MS_FILE_TYPE_E type, FPI_MS_File_Node_S *list);



/**
@brief 获取指定类型媒体文件的个数

@param[in] path 文件路径
@param[in] type 要获取个数的媒体类型(Dir, picture, vide, music, other)
@return 媒体文件的个数
*/
int tos_ms_get_file_count(const char *path, FPI_MS_FILE_TYPE_E type);



/**
@brief 设置文件扫描方式

@param[in] mode 文件扫描方式(normal,recursive)
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_set_scan_mode(FPI_MS_SCAN_MODE_E mode);


/**
@brief 创建缩略图task

@param[in] path 媒体文件的路径
@param[in] type 媒体文件类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_create_tmb_task(const char *path, FPI_MS_FILE_TYPE_E type);


/**
@brief 结束缩略图task

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ms_stop_tmb_task();




#ifdef __cplusplus
}
#endif
/** @} */
#endif
