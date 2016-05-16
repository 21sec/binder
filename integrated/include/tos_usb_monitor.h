/**@defgroup tos_usb_monitor
@{

@brief usb设备管理


@history 2015/04/16 初稿
@history 2015/04/20 根据组内评审意见修改:增加REMOVE_CURRENT_DISK事件枚举;在usb设备分区信息结构体中增加free_size和total_size ; 
                                 完善接口名字和注释.

@history 2015/04/22 根据部门评审意见修改:  删掉REMOVE_CURRENT_DISK事件枚举;   
                                在usb设备分区信息结构体中增加usb设备分区的唯一标识id ;   
                                删除tos_usb_get_last_partition_count ()接口等
**/

#ifndef __TOS_USB_MONITOR_H__
#define __TOS_USB_MONITOR_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 定义usb 设备事件枚举
*/
typedef enum{
	FPI_USB_CB_EVENT_REMOVE_DISK,				        ///<卸载usb设备	
	FPI_USB_CB_EVENT_ADD_DISK      					///<挂载usb设备	
}FPI_USB_CB_EVENT_E;

#define TOS_USB_FILE_PATH_SIZE 1024

/**
@brief 定义usb 设备分区信息结构体
*/
typedef struct
{
    int  id;                                ///<usb 设备分区标识id
    char label[TOS_USB_FILE_PATH_SIZE];        					///<usb 设备分区卷标
    char mountpath[TOS_USB_FILE_PATH_SIZE];    					///<usb 设备分区挂载路径
    uint64_t free_size;				///<usb 设备分区的剩余空间
    uint64_t total_size;				///<usb 设备分区的总空间
}FPI_USB_Partition_Info_S;


/**
@brief usb 的回调函数类型定义

@param[in] event 产生的事件类型枚举
@param[in] param usb 设备分区信息
@param[in] userData 用户数据,其值为调用tos_usb_add_callback时传入的用户数据
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
typedef fpi_error (*tos_usb_callback_fn)(FPI_USB_CB_EVENT_E event, void* param, void *userData);

/**
@brief 添加usb 回调函数

@param[in] cb 回调函数指针
@param[in] userData 用户数据,会在回调函数中抛出
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_usb_add_callback(tos_usb_callback_fn cb, void* userData);

/**
@brief 删除usb 回调函数

@param[in] cb 回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_usb_remove_callback(tos_usb_callback_fn cb);



/**
@brief 启动usb设备管理

@note 此接口开机启动后，无需退出

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_usb_monitor_start();

/**
@brief 获取系统挂载的usb存储设备分区的总个数

@note 此接口需要在tos_usb_monitor_start 后调用

@return 系统挂载的usb存储设备分区的总个数
*/
int tos_usb_get_partition_count();


/**
@brief 获取usb 设备分区的挂载信息(挂载路径和usb 的卷标)

@note 此接口需和tos_usb_get_partition_count 一起使用;
@note 获取指定usb 的信息: partition_idx = 指定usb 设备分区的序号;

@param[in] partition_idx usb设备分区的序号，如partition_idx = 2，表示第二个usb设备分区(partition_idx < 挂载的usb设备分区总数)
@param[out] info 输出参数,usb 设备分区的信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_usb_get_partition_info(int partition_idx, FPI_USB_Partition_Info_S* info);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
