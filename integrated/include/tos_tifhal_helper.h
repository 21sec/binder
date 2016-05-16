/**@defgroup TIFHAL_HELPER [TIF HAL Helper] 简化产品利用中间件接口实现TIF HAL层的辅助模块

@note 本模块利用中间件TOS接口实现类似TIF中的tv_input.h及hdmi_cec.h中定义的接口，简化基于TIF项目的开发。

@version 0.1 2015/07/28 Created
@{
*/

#ifndef _TOS_TIFHAL_H_
#define _TOS_TIFHAL_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "fpp_cec.h"


#define TIFHAL_ERROR_NO_ERROR				(0)
#define TIFHAL_ERROR_OTHER_ERROR			(-1)
#define TIFHAL_ERROR_PARAMTER_ERROR			(-2)
#define TIFHAL_ERROR_LOOPER_ERROR			(-3)
#define TIFHAL_ERROR_THREAD_ERROR			(-4)
#define TIFHAL_ERROR_DEVICENOTFOUND_ERROR	(-5)
#define TIFHAL_ERROR_STREAMCOUNT_ERROR		(-6)
#define TIFHAL_ERROR_NOTIMP_ERROR			(-7)
#define TIFHAL_ERROR_SENDMSG_ERROR			(-8)
#define TIFHAL_ERROR_STREAMNOTFOUND_ERROR	(-9)

/*
 @brief TVINPUT回调函数

 @param[in] type 消息类型，取值为TOS_TIFHAL_TVINPUT_EVENT_TYPE_E。
 @param[in] param 消息对应的参数，其类型及取值见TOS_TIFHAL_TVINPUT_EVENT_TYPE_E中说明
 @param[in] userdata 用户数据，tos_tifhal_tvinput_initialize的userdata参数原样返回
 */
typedef void (*tos_tifhal_tvinput_notify)(int type, void* param, void *userdata);

/*
 @brief tv input消息类型
 */
enum TOS_TIFHAL_TVINPUT_EVENT_TYPE_E {
	/*
	 @brief 设备可用时，产生此消息通知上层。

	 开机时为所有内置信源产生此消息。
	 类似USB Tuner这样的设备插入时产生此消息。
	 消息对应的param参数为tos_tifhal_tvinput_device_info_t指针。
	 @note 拔插HDMI线等行为应该产生TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED消息而不是此消息。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_DEVICE_AVAILABLE = 1,

	/*
	 @brief 设备变得不可用时，产生此消息通知上层。

	 类似USB Tuner这样的设备拔出时产生此消息。
	 消息对应的param参数为tos_tifhal_tvinput_device_info_t指针。
	 @note 拔插HDMI线等行为应该产生TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED消息而不是此消息。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_DEVICE_UNAVAILABLE = 2,

	/*
	 @brief stream配置信息变化消息。
 
	 产生此消息后，对应设置所有被打开的stream自动变为关闭状态，如有需要上层需重新打开它们。
	 典型的产生此消息的场景有信号的分辨率变化，信号线拔出等。
	 当信号线拔出时，对应设备的stream数为0.
	 消息对应的param参数为tos_tifhal_tvinput_device_info_t指针。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_STREAM_CONFIGURATIONS_CHANGED = 3,

	/*
	 @brief 截屏成功消息，暂未实现，目前不会产生此消息。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_SUCCEEDED = 4,

	/*
	 @brief 截屏失败消息，目前tos_tifhal_tvinput_request_capture总是产生此消息。
 
	 消息对应的param参数为tos_tifhal_tvinput_capture_result_t指针。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED = 5,

	/*
	 @brief 消息上限，不会产生此消息。
	*/
	TOS_TIFHAL_TVINPUT_EVENT_MAX
};

/*
 @brief 设备类型
 */
enum TOS_TIFHAL_TVINPUT_TYPE_E {
    /* Generic hardware. */
    TOS_TIFHAL_TVINPUT_TYPE_OTHER_HARDWARE = 1,
    /* Tuner. (e.g. built-in terrestrial tuner) */
    TOS_TIFHAL_TVINPUT_TYPE_TUNER = 2,
    TOS_TIFHAL_TVINPUT_TYPE_COMPOSITE = 3,
    TOS_TIFHAL_TVINPUT_TYPE_SVIDEO = 4,
    TOS_TIFHAL_TVINPUT_TYPE_SCART = 5,
    TOS_TIFHAL_TVINPUT_TYPE_COMPONENT = 6,
    TOS_TIFHAL_TVINPUT_TYPE_VGA = 7,
    TOS_TIFHAL_TVINPUT_TYPE_DVI = 8,
    /* Physical HDMI port. (e.g. HDMI 1) */
    TOS_TIFHAL_TVINPUT_TYPE_HDMI = 9,
    TOS_TIFHAL_TVINPUT_TYPE_DISPLAY_PORT = 10,

    TOS_TIFHAL_TVINPUT_TYPE_MAX
};

typedef struct {
	int deviceId;	///< 全局唯一的设备ID

	int type;	///< 设备类型，取值为TOS_TIFHAL_TVINPUT_TYPE_E

	int portId;	///< 子设备号，如HDMI1，HDMI2,AV1,AV2等,一般从1开始。
}tos_tifhal_tvinput_device_info_t;

typedef struct {
	int deviceId;	///< 全局唯一的设备ID，等于tos_tifhal_tvinput_request_capture的deviceId参数

    int streamId;	///< 流ID，等于tos_tifhal_tvinput_request_capture的streamId参数。

    int sequence;	///< 调用序列号，等于tos_tifhal_tvinput_request_capture的sequence参数。

    int errCode;	///< 成功为0，失败为<0的错误代码。
}tos_tifhal_tvinput_capture_result_t;

typedef struct {
	int streamId;	///< 全局唯一的设备ID，由底层分配

	int maxVideoWidth;	///< 最大可能的视频宽度
	int maxVideoHeight;	///< 最大可能的视频宽度
}tos_tifhal_tvinput_tv_stream_config_t;

/*
 @brief TVINPUT回调函数

 @note 第二次次调用本接口时会覆盖之前的状态

 @param[in] type 消息类型，取值为TOS_TIFHAL_TVINPUT_EVENT_TYPE_E。
 @param[in] param 消息对应的参数，其类型及取值见TOS_TIFHAL_TVINPUT_EVENT_TYPE_E中说明
 @param[in] userdata 用户数据，tos_tifhal_tvinput_initialize的userdata参数原样返回
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_tvinput_initialize(tos_tifhal_tvinput_notify callback,void* userdata);

/*
 @brief 获取设备的流数量

 @param[in] deviceId 设备id，同tos_tifhal_tvinput_device_info_t的deviceId.
 @return 成功返回设备的流的数量，失败返回<0的错误代码。
 */
int tos_tifhal_tvinput_get_stream_count(int deviceId);

/*
 @brief 获取设备的流配置信息

 @code 建议调用方式
 tos_tifhal_tvinput_tv_stream_config_t* pCconfig = NULL;
 int deviceId = xxx;
 int count = tos_tifhal_tvinput_get_stream_count(deviceId);
 pCconfig = (tos_tifhal_tvinput_tv_stream_config_t*)malloc(sizeof(tos_tifhal_tvinput_tv_stream_config_t)*count);
 assert(pCconfig != NULL);
 tos_tifhal_tvinput_get_stream_configurations(deviceId,pCconfig,count);
 @endcode

 @param[in] deviceId 设备id，同tos_tifhal_tvinput_device_info_t的deviceId.
 @param[in] configs 结构体数组指针，用户存储配置信息.
 @param[in] maxCount 最多能容纳的配置数量，须大于等于tos_tifhal_tvinput_get_stream_count的返回值,否则本接口返回失败.
 @return 成功返回设备的流的数量，失败返回<0的错误代码。
 */
int tos_tifhal_tvinput_get_stream_configurations(int deviceId,tos_tifhal_tvinput_tv_stream_config_t *configs, int maxCount);

/*
 @brief 请求截图

 @note 该接口暂未实现，只会产生TOS_TIFHAL_TVINPUT_EVENT_CAPTURE_FAILED消息。
 @note 返回的数据考虑在tos_tifhal_tvinput_capture_result_t中增加FIFO或者图片文件路径。

 @param[in] deviceId 设备id，同tos_tifhal_tvinput_device_info_t的deviceId.
 @param[in] streamId 流ID，从tos_tifhal_tvinput_get_stream_configurations获取。
 @param[in] sequence 请求的序列号，用于唯一标识一次请求及标识对应的返回消息。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_tvinput_request_capture(int deviceId,int streamId,int sequence);

/*
 @brief 取消请求截图

 @param[in] deviceId 设备id，同tos_tifhal_tvinput_device_info_t的deviceId.
 @param[in] streamId 流ID，从tos_tifhal_tvinput_get_stream_configurations获取。
 @param[in] sequence 请求的序列号，用于唯一标识一次请求及标识对应的返回消息。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_tvinput_cancel_capture(int deviceId,int streamId,int sequence);

/*
 @brief TIF HDMI CEC回调函数

 @param[in] type 消息类型，取值为TOS_TIFHAL_HDMICEC_EVENT_TYPE_E
 @param[in] param 消息对应的参数，其类型及取值见TOS_TIFHAL_HDMICEC_EVENT_TYPE_E中说明
 @param[in] userdata 用户数据，tos_tifhal_hdmicec_add_callback参数原样返回
 */
typedef void (*tos_tifhal_hdmicec_callback)(int type, void* param, void* userdata);


typedef struct {
    int connected;  ///< 1表示已连接，0表示未连接，一般来说用硬件的5V电压判断
    int portId;    ///< HDMI的portId，同tos_tifhal_tvinput_device_info_t
} TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T;

typedef struct {
    int type;	///< 输入输出类型，0-输入;1-输出
    int portId; ///< 同tos_tifhal_tvinput_device_info_t的portId参数
    int isCecSupported; ///< 是否支持CEC,0-不支持;其它-支持
    int isArcSupported; ///< 是否支持ARC,0-不支持;其它-支持
    uint16_t physicalAddress;  ///< 端口的物理地址
} TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T;

/*
 @brief HDMI CEC回调类型枚举
 */
enum TOS_TIFHAL_HDMICEC_EVENT_TYPE_E {
    /*
     @brief CEC消息
 
     消息对应的param参数为ST_FPP_CEC_RX_DATA_T指针
    */
    TOS_TIFHAL_HDMICEC_EVENT_CEC_MESSAGE = 1,

    /*
     @brief HDMI CE热拔插消息
 
     消息对应的param参数为TOS_TIFHAL_HDMICEC_HOTPLUG_EVENT_T指针
    */
    TOS_TIFHAL_HDMICEC_EVENT_HOT_PLUG = 2,
};

enum TOS_TIFHAL_HDMICEC_OPTION_FLAG_E{

    /*
     @brief 设置自动唤醒功能开关
 
     此选择设置为0时，系统不会被CEC设备唤醒，为1时可以被CEC设备唤醒。
     默认值为1.

     此选项主要用于用户在菜单中打开关闭CEC选项功能时。
    */
    TOS_TIFHAL_HDMICEC_OPTION_WAKEUP = 1,

    /*
     @brief 设置CEC使能开关。
 
     此选择设置未0时，丢弃所有的CEC命令，为1时正常处理或者上抛。
     默认值为1.

     此选项主要用于用户在菜单中打开关闭CEC选项功能时。
    */
    TOS_TIFHAL_HDMICEC_OPTION_ENABLE_CEC = 2,

    /*
     @brief 设置TIF管理CEC使能开关。
 
     此选择设置未0时，TIF的CEC模块停止工作，由底层提供CEC服务，为1时正常处理或者上抛，由TIF提供CEC服务。
     默认值为0.

     此选项主要用于待机时的CEC处理，因此所谓的底层处理并非指中间件处理，而是待机CPU处理。
    */
    TOS_TIFHAL_HDMICEC_OPTION_SYSTEM_CEC_CONTROL = 3,

    /*
     @brief 设置CEC语言。

     用于待机时响应<Get Menu Language>命令。
 
     对应的值为ISO/FDIS 639-2定义的3字节的ASCII语言码，如英语为0x656e67.
    */
    TOS_TIFHAL_HDMICEC_OPTION_SET_LANG = 5,
};


/*
 @brief 初始化TIF的CEC模式，同时关闭中间件的HDMI-CEC处理，由TIF来处理HDMI-CEC消息。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_init();

/*
 @brief 反初始化TIF的CEC模式，同时恢复中间件的HDMI-CEC处理，由中间件来处理HDMI-CEC消息。

 @note 反初始化后，所有注册的回调，添加的物理地址，设置的选项等全部清空，恢复默认值。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_term();

/*
 @brief 添加关注的逻辑地址

 只有添加了对应逻辑地址的CEC设备的消息才会回调给调用者，其他消息会丢弃.
 默认情况下不关注任何逻辑地址。

 @note 此接口可以被反复调用，以支持同时关注多个逻辑地址。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_add_logical_address(EN_FPP_CEC_DEVICE_LOG_ADDR_T addr);

/*
 @brief 清除所有的逻辑地址关注。
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_clear_logical_address();

/*
 @brief 获取本机逻辑地址

 @param[out] physicalAddress 输出逻辑地址
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_get_physical_address(uint16_t* physicalAddress);

/*
 @brief 向HDMI设备发送CEC消息

 该接口会在适当的时候返回失败，而不是一直不返回直到成功为止。

 @param[in] msg CEC消息数据结构
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_send_message(ST_FPP_CEC_RX_DATA_T* msg);

/*
 @brief 添加HDMI CEC消息回调函数

 完全相同的callback和userdata会被认为是相同的添加，会返回失败拒绝重复添加。

 @param[in] callback 回调函数指针
 @param[in] userdata 用户数据，等于回调函数的userdata参数
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_add_callback(tos_tifhal_hdmicec_callback callback, void* userdata);

/*
 @brief 添加HDMI CEC消息回调函数

 只有当callback和userdata都相同时才能成功删除，否则返回失败.

 @param[in] callback 回调函数指针
 @param[in] userdata 用户数据，等于回调函数的userdata参数
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_remove_callback(tos_tifhal_hdmicec_callback callback, void* userdata);

/*
 @brief 获取本机支持的CEC版本，即HDMI的版本号

 @param[out] cecVersion 输出CEC版本号
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_get_version(int *cecVersion);

/*
 @brief 获取本机供应商ID

 这是一个24-bit的由IEEE组织分配的厂商唯一编号。 

 @param[out] vendorId 输出供应商ID
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_get_vendor_id(int *vendorId);

/*
 @brief 获取本机所有HDMI接口信息

 @param[out] portInfo 用于输出HDMI接口信息的结构体数组
 @param[in] maxCount portInfo最大能容纳的接口数。
 @return 成功返回实际HDMI接口数，失败返回<0的错误代码。
 */
int tos_tifhal_get_port_info(TOS_TIFHAL_HDMICEC_HDMI_PORT_INFO_T *portInfo,int maxCount);

/*
 @brief 设置HDMI CEC选项

 @param[in] flag 选项，其取值为TOS_TIFHAL_HDMICEC_OPTION_FLAG_E
 @param[in] value 用户数据，等于回调函数的userdata参数
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_set_option(int flag, int value);

/*
 @brief 设置启动/停止ARC的返回频道功能

 @param[in] portId HDMI的portId，同tos_tifhal_tvinput_device_info_t
 @param[in] value 1-启动；0-停止 此功能
 @return 成功返回0，失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_set_audio_return_channel(int portId,int flag);

/*
 @brief 查询HDMI是否连接上

 一般来说使用硬件上的5V电压进行检测

 @param[in] portId HDMI的portId，同tos_tifhal_tvinput_device_info_t
 @return 已连接返回1，未连接返回0；失败返回<0的错误代码。
 */
int tos_tifhal_hdmicec_is_connected(int portId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif

