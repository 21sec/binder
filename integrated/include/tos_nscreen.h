/**@defgroup tos_nscreen
@{

@brief 

@author xiewx (xiewx@tcl.com)

@note 

@version 1.0.0 
@history 2015/6/9 15:00:40 初稿
@history 2015/7/7 按照评审建议新增tos_nscreen_get_device_count, tos_nscreen_get_device_list 接口
*/

#ifndef __TOS_NSCREEN_H__
#define __TOS_NSCREEN_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C"{
#endif

//#define NSCREEN_ENABLE	/*!< NSCREEN_ENABLE */

#define NSCREEN_FILE_SIZE_1024		1024	/*!< NSCREEN文件长度为1024 */

#define DMR_STATUS_DISCONNECT			0
#define DMR_STATUS_CONNECT				1

/**
@brief 定义nsrceen回调事件枚举
*/
typedef enum _NSCREEN_EVENT_E
{
   	EN_NSCREEN_EVENT_STOP, /// <意外停止
    EN_NSCREEN_EVENT_DEVICE_INSERT = 100, /// <DMS insert (dmp moudel)
    EN_NSCREEN_EVENT_DEVICE_REMOVE, /// <DMS remove (dmp moudel)
    EN_NSCREEN_EVENT_DMR_PUSH = 150, /// <DMR PUSH  (param:NSCREEN_CONTENTTYPE_E)
    EN_NSCREEN_EVENT_DMR_STATUS, /// < DMR Status (param: 1-connect, 0-disconnect #define DMR_STATUS_XXX)
    EN_NSCREEN_EVENT_MIRACAST_STATUS = 200,   /// <miracast status
    EN_NSCREEN_EVENT_AIRPLAY_STATUS = 300,   /// <Airpaly status
	EN_NSCREEN_EVENT_RM_STATUS = 400,   /// <Remote ctrl status
	EN_NSCREEN_EVENT_EXTERN = 500,   ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN1,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN2,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN3,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN4,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN5,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN6,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN7,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN8,  ///< 预留数据
	EN_NSCREEN_EVENT_EXTERN9,  ///< 预留数据
}NSCREEN_EVENT_E;

/**
@brief 定义协议类型枚举
@需要同步到fpi_error中,使用统一的fpi_error_code
*/
typedef enum _NSCREEN_PROTOCOL_E
{
	EN_NSCREEN_NONE,
	EN_NSCREEN_DLNA,	///< DLNA
	EN_NSCREEN_MIRACAST, ///< miracast
	EN_NSCREEN_AIRPLAY,	///< airplay
	EN_NSCREEN_REMOTECTRL,	///< remote ctrl
	EN_NSCREEN_PROTOCOL_MAX
}NSCREEN_PROTOCOL_E;

/**
@brief enumerate to indicate the function error type
*/
typedef enum _EN_NSCREEN_ERR_E
{
    EN_NSCREEN_ERROR_SUCCESS = 0,          /*!< Success */
    EN_NSCREEN_ERROR_FAILED,               /*!< Failed */
    EN_NSCREEN_ERROR_NOT_SUPPORT,          /*!< Not Support/Implement */
    EN_NSCREEN_ERROR_NO_SERVER,            /*!< No Server */
    EN_NSCREEN_ERROR_NO_FILE,              /*!< No File */
    EN_NSCREEN_ERROR_MAX
} EN_NSCREEN_ERR_E;

typedef enum _EN_NSCREEN_SYNC_STATUS_E
{
    EN_NSCREEN_SYNC_PLAY = 100,
    EN_NSCREEN_SYNC_PAUSE,
    EN_NSCREEN_SYNC_STOP,
    EN_NSCREEN_SYNC_RESUME,
    EN_NSCREEN_SYNC_SEEK,  
    EN_NSCREEN_SYNC_PLAY_CUR_TIME,
    EN_NSCREEN_SYNC_PLAY_DURATION,
    EN_NSCREEN_SYNC_PLAY_ERROR,
	EN_NSCREEN_SYNC_EXTERN0,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN1,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN2,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN3,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN4,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN5,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN6,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN7,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN8,  ///< 预留数据
	EN_NSCREEN_SYNC_EXTERN9,  ///< 预留数据
	
	EN_NSCREEN_SYNC_AV = 1000, ///< a/v sync
}NSCREEN_SYNC_STATUS_E;

/**
@brief 定义内容类型枚举
@note 可以使用或操作
*/
typedef enum _NSCREEN_CONTENTTYPE_E
{
	EN_NSCREEN_CONTENTTYPE_UNKNOWN 	= 0,
	EN_NSCREEN_CONTENTTYPE_DIR 		= 0x01,	///< 文件夹
	EN_NSCREEN_CONTENTTYPE_IMAGE 	= 0x02,	///< 图片
	EN_NSCREEN_CONTENTTYPE_VIDEO 	= 0x04,	///< 视频
	EN_NSCREEN_CONTENTTYPE_AUDIO 	= 0x08,	///< 音频
	EN_NSCREEN_CONTENTTYPE_FILE		= 0x10,	///< 文件
	EN_NSCREEN_CONTENTTYPE_PLAYLIST	= 0x20,	///< 播放列表
	
	EN_NSCREEN_CONTENTTYPE_RESERVED0 = 0x40,   ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED1 = 0x80,   ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED2 = 0x100,  ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED3 = 0x200,  ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED4 = 0x400,  ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED5 = 0x800,   ///< 预留数据

    EN_NSCREEN_CONTENTTYPE_NAME = 0x1000,               ///< 推送内容的名字
    EN_NSCREEN_CONTENTTYPE_REMOTENAME = 0x2000,          ///< 移动设备的名字
	
    EN_NSCREEN_CONTENTTYPE_RESERVED6 = 0x4000,           ///< 预留数据
	EN_NSCREEN_CONTENTTYPE_RESERVED7 = 0x8000,  ///< 预留数据
}NSCREEN_CONTENTTYPE_E;

/**
@brief 定义媒体文件链表节点信息结构体
*/
typedef struct _nscreen_content_info_t
{
	char path[NSCREEN_FILE_SIZE_1024]; ///< 文件路径
	char name[NSCREEN_FILE_SIZE_1024];	///< 文件名	
	NSCREEN_CONTENTTYPE_E type;				///< 文件类型
	long filesize;							///< 文件大小
	long time;								///< 文件最后修改时间
}nscreen_content_info_t;

/**
@brief 定义媒体设备信息结构体
*/
typedef struct _nscreen_device_info_t
{
    int  id;       ///<设备标识id
    char path[NSCREEN_FILE_SIZE_1024];    ///< 设备路径
    char name[NSCREEN_FILE_SIZE_1024];  ///< 设备名称
    uint64_t reserved0;             ///< 预留数据
    uint64_t reserved1;                ///< 预留数据
}nscreen_device_info_t;

/**
@brief nscreen的回调函数类型定义

@param[in] event 产生的事件类型枚举
@param[in] code 产生的事件码值,根据event类型不同有不同的定义
@param[in] data 产生的事件附带数据,根据event类型不同有不同的定义
@param[in] userData 用户数据,其值为调用tos_nscreen_add_callback时传入的用户数据
*/
typedef void (*tos_nscreen_callback)(NSCREEN_EVENT_E event, int code, int data, void *userData);

/**
@brief init the nscreen
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_init(void);

/**
@brief de-init the nscreen
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_terminate(void);

/**
@brief start the nscreen

@note

@param[in]  protocol 使用的协议 
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_start(NSCREEN_PROTOCOL_E protocol);

/**
@brief stop the nscreen

@note
@param[in]  protocol 使用的协议  
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_stop(NSCREEN_PROTOCOL_E protocol);

/**
@brief 获取设备的个数

@note 通过获取到个数再使用tos_nscreen_get_device_list 获取整个列表

@param[in]  protocol 使用的协议
@param[out]	*count 个数
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_get_device_count(NSCREEN_PROTOCOL_E protocol, int *count);

/**
@brief 获取设备的列表

@note 先使用tos_nscreen_get_device_count获取到个数后，再获取列表。

@param[in]  protocol 使用的协议
@param[out]	*list 列表
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_get_device_list(NSCREEN_PROTOCOL_E protocol, nscreen_device_info_t *list);

/**
@brief 获取内容的个数

@note 通过获取到个数再使用tos_nscreen_get_content 获取整个列表

@param[in]  protocol 使用的协议
@param[in]	path 路径
@param[in]	type 获取内容的类型
@param[out]	*count 个数
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_get_content_count(NSCREEN_PROTOCOL_E protocol, const char *path, NSCREEN_CONTENTTYPE_E type, int *count);

/**
@brief 获取内容的列表

@note 先使用tos_nscreen_get_content_count获取到个数后，再获取详情列表,当获取当个内容详情时指定protocol,type即可。

@param[in]  protocol 使用的协议
@param[in]	path 路径 ，如果path当NULL时，获取当前移动端推送的文件名
@param[in]	type 获取内容的类型
@param[out]	*list 指定类型的内容列表
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_get_content(NSCREEN_PROTOCOL_E protocol, const char *path, NSCREEN_CONTENTTYPE_E type, nscreen_content_info_t *list);

/**
@brief sync_play_status for the nscreen if other app control mediaPlayer

@note

@param[in]  protocol 使用的协议 
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_sync_play_status(NSCREEN_PROTOCOL_E protocol, NSCREEN_SYNC_STATUS_E status, int64_t data);

/**
@brief 增加回调函数

@param[in]	callback 回调函数指针
@param[in]	userdata 用户数据，会在回调函数中抛出
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_add_callback(tos_nscreen_callback callback,void* userdata);

/**
@brief 删除回调函数

@param[in]	callback 回调函数指针
@param[in]	userdata 用户数据
@return 成功返回 EN_NSCREEN_ERROR_SUCCESS；失败返回其他值
*/
fpi_error tos_nscreen_remove_callback(tos_nscreen_callback callback,void* userdata);

#ifdef __cplusplus
}
#endif	

#endif //__TOS_NSCREEN_H__

/** @} */
