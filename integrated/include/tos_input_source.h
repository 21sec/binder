/**@defgroup 信源
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/23 linshunda 初稿
*/


#ifndef __TOS_INPUTSOURCE_H__
#define __TOS_INPUTSOURCE_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief 信源的状态
**/
typedef enum
{
	EN_SOURCE_CURRENT,///<当前信源
	EN_SOURCE_LASTEST,///<最新信源
	EN_SOURCE_TARGET,///<目标信源
}EN_SOURCE_SAVE_TYPE;

/*
typedef enum
{
	SESSION_CREATED,
	SESSION_DESTROYED,
	SESSION_REQUESTED,
	SESSION_RELEASED,
}EN_SESSION_STATUS;


typedef struct
{
	int32_t session_id;
	EN_SESSION_STATUS session_status;
	EM_SOURCE_TYPE source_type;
}session_info;
*/
/**
@brief 异步切换输入信源

@param input ，信源,
@param	act ,执行行为: 只执行，只保存，执行并保存
@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_source_set_input_async(EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);


/**
@brief 切换输入信源


@param input ，信源,
@param  act ,执行行为: 只执行，只保存，执行并保存


@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_set_input(EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);

/**
@brief 获得输入信源

@param  type:EN_SOURCE_CURRENT: 有当前信源,EN_SOURCE_LASTEST: 最新保存的信源。

@retval value哪个信源值

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_get_input(EN_SOURCE_SAVE_TYPE type,EN_API_SOURCE_INPUT *value);


/**
@brief 获得指定输入信源是否有插入，这里一般是fpp驱动判断信号状态。

@param  inSource ，信源,

@retval  state:0 , 无插入， 1: 插入 。

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_is_insert(EN_API_SOURCE_INPUT inSource, int *state);


/**
@brief 请求session_id对应的设备的控制权
 
只有先获取控制权才能使用对应的session_id操作设备。
同步接口，本接口返回成功后即表示已成功获得控制权。同时会有异步消息通知之前用于控制权的session_id的控制权被释放。
控制权的请求暂时是不可拒绝，无需确认的。即谁最后申请控制权，谁就会获得控制权。
 
每个session_id每次获取到控制权时，当前信源都会进入到初始状态，此时没有任何通道被打通，没有任何设备被占用，使用特殊的PQ参数（USB），状态为全屏，没有任何内容在播放。
*/
fpi_error tos_source_request(uint32_t session_id);
 
/**
@brief 释放session_id对应的设备的控制权
 
不再使用对应设备时，须调用此接口释放控制权。
同步接口，本接口返回成功后即表示已成功释放控制权。
 
每个session_id每次释放控制权时，当前信源都会进入到初始状态，此时没有任何通道被打通，没有任何设备被占用，使用特殊的PQ参数（USB），状态为全屏，没有任何内容在播放。
*/
fpi_error tos_source_release(uint32_t session_id);

/**
@brief 切换信源到指定的信源
 
仅当对应session_id拥有控制权时生效，否则返回失败。
一旦本接口成功返回，tos_source_get_input即可即可获取input为当前信源，而设置之前的信源为上一个信源，但实际切换还需要一些时间异步来执行。
实际切换完成后，会有信号相关的消息通知对应信源是否有信号以及信号的属性。
*/
fpi_error tos_source_set_input_with_session(uint32_t session_id,EN_API_SOURCE_INPUT input,EN_ACT_CTRL act);

/**
@brief 获取HDMI的版本情况。

@param  input :信源,

@param  ver:版本 : 0:自动,1:1.4 ,2:2.0 。


@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_get_hdmi_edid_ver(EN_API_SOURCE_INPUT input, int32_t *ver);

/**
@brief 设置HDMI的版本情况，由于 1.4 和 2.0 ，驱动一般无法自动判断。

@param  input :信源,

@param  ver:版本 : 0:自动,1:1.4 ,2:2.0 。


@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_set_hdmi_edid_ver(EN_API_SOURCE_INPUT input, int32_t ver);
/**
@brief 设置开机启动的信源

@param  bootSource:0 自动，根据上一次关机信源决定，

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_set_bootinput(EN_TOS_SOURCE_BOOT_INPUT bootSource);

/**
@brief 判断当前信源是否为ITV信源
@param  isitv:0 :当前信源不是itv
			1:当前信源是itv

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_source_is_itv(int *isitv);
#ifdef __cplusplus
}
#endif
/** @} */

#endif 
