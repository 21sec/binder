/**@defgroup 数字电视频道播放模块
@{

@brief 用于控制电视中播放相关操作

**/

#ifndef __TOS_CHANNEL_PLAY_H__
#define __TOS_CHANNEL_PLAY_H__

#include "tos_dtv_basetype.h"
#include "fpi_error_code.h"
#include "fpi_dtv_base.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 定义播放器回调事件枚举
*/
typedef enum {
    EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_SUCCESS,     ///< 视频播放成功,表示开始渲染第一帧,播放完成后, 底层需要一定的时间来判断当前节目的播放结果。
                                                  ///<  该消息到来前, 视频状态是不确定的(可能视频先出来了, 但状态延迟), 应用层
                                                  ///<  需根据需求, 处理这一段时间的过度。
                                                  ///<  但EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_SUCCESS或者EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_FAILED一定会至少来一次
    EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_FAILED,      ///< 视频播放失败,此时code表示失败原因,取值为FPI_MP_PLAY_FAILED_REASON_E
    EN_TOS_DTV_PLAY_EVENT_AUDIO_PLAY_SUCCESS,     ///< 音频播放成功
    EN_TOS_DTV_PLAY_EVENT_AUDIO_PLAY_FAILED,      ///< 音频播放失败,此时code表示失败原因,取值为FPI_MP_PLAY_FAILED_REASON_E
    EN_TOS_DTV_PLAY_EVENT_CHANNEL_UPDATE          ///< 频道需要更新
}EN_TOS_DTV_PLAY_CB_EVENT_E;


/**
@brief 定义播放失败原因枚举
*/
typedef enum {
    EN_TOS_DTV_PLAY_REASON_UNKNOWN,               ///< 未知原因
    EN_TOS_DTV_PLAY_REASON_CONNECT_FAILED,        ///< 锁频失败
    EN_TOS_DTV_PLAY_REASON_FORMAT_NOT_SUPPORT,    ///< 视频/音频格式不支持
    EN_TOS_DTV_PLAY_REASON_UNAUTHORIZED,          ///< 未授权
    EN_TOS_DTV_PLAY_REASON_CHANNEL_NOT_EXIST,     ///< 对应频点下无此节目，并且没有提供音视频PID
    EN_TOS_DTV_PLAY_REASON_CHANNEL_LOCKED,        ///< 节目加了节目锁
    EN_TOS_DTV_PLAY_REASON_PARENTAL_LOCKED,       ///< 节目加了父母锁
    EN_TOS_DTV_PLAY_REASON_NO_VIDEO,              ///< 节目没有视频
    EN_TOS_DTV_PLAY_REASON_NO_AUDIO               ///< 节目没有音频
}EN_TOS_DTV_PLAY_FAILED_REASON_E;

typedef enum
{
    E_DTV_PLAY_IDLE,        ///< 停止播放状态
    E_DTV_PLAY_PLAYING      ///< 播放状态
} EN_FPI_DTV_PLAY_STATE;

typedef struct
{
    tos_dtv_mux_info_t deliveryInfo; ///< 
    int serviceId;
    int audioPID;
    int audioStreamType;
    int videoPID;
    int videoStreamType;
    int pcrPID;
	fpi_bool channelLocked;
    // for epg show subtitle or teletext is exit state
    fpi_bool is_subtitle_on;
    fpi_bool is_teletext_on;
}tos_dtv_play_info_t;

/// Screen Saver Mode
typedef enum
{
    /// The screen saver mode is invalid service.
    E_DTV_SS_INVALID_SERVICE,
    /// The screen saver mode is no CI module.
    E_DTV_SS_NO_CI_MODULE,
	/// The screen saver mode is CI+ Authentication.
    E_DTV_SS_CI_PLUS_AUTHENTICATION,
    /// The screen saver mode is scrambled program.
    E_DTV_SS_SCRAMBLED_PROGRAM,
    /// The screen saver mode is channel block.
    E_DTV_SS_CH_BLOCK,
    /// The screen saver mode is parental block.
    E_DTV_SS_PARENTAL_BLOCK,
    /// The screen saver mode is audio only.
    E_DTV_SS_AUDIO_ONLY,
    /// The screen saver mode is data only.
    E_DTV_SS_DATA_ONLY,
    E_DTV_SS_COMMON_VIDEO,
    #if 0
    EN_DTV_SS_NO_CHANNEL,
    #endif
    /// The screen saver mode is Unsupported Format.
    E_DTV_SS_UNSUPPORTED_FORMAT,
    E_DTV_SS_INVALID_PMT,
    /// The screen saver mode support type.

    /// The screen saver mode is input block. add by lwf 201311.05
    E_DTV_SS_INPUT_BLOCK,

    E_DTV_SS_RUNNING_STATUS_NOT_RUNNING, //add by lwf 2013.11.28 海停, sdt 表运行接播放状态，没有播放，节目停播
    E_DTV_SS_MAX
} EN_TOS_DTV_SS_MODE;

typedef enum {
        EN_TOS_DTV_PLAY_ID_MAIN,               //主窗口
        EN_TOS_DTV_PLAY_ID_SUB,        //子窗口
		EN_TOS_DTV_PLAY_AV_SYNC_TIMEOUT,
        EN_TOS_DTV_PLAY_ID_MAX           
}EN_TOS_DTV_PLAY_ID_E;

typedef enum {
        EN_TOS_DTV_PLAY_STOP_TYPE_ONLY_AUDIO,               //只停当前audio
        EN_TOS_DTV_PLAY_STOP_TYPE_ONLY_VIDEO,        //只停video
        EN_TOS_DTV_PLAY_STOP_TYPE_ALL,    //当前音视频都停
}EN_TOS_DTV_PLAY_STOP_TYPE_E;


typedef enum {
        EN_TOS_DTV_PLAY_TYPE_CURRENT_AUDIO,             
        EN_TOS_DTV_PLAY_TYPE_DEFAULT_AUDIO,        
        EN_TOS_DTV_PLAY_TYPE_CURRENT_VIDEO,             
        EN_TOS_DTV_PLAY_TYPE_DEFAULT_VIDEO,             
}EN_TOS_DTV_PLAY_TYPE_E;

typedef struct 
{
	int         Pid; 
	int        Stream_tag;//unique identifier for the audio/video stream
	int         ComponentTag;//component tag which from stream identiifier descriptor
	int         Stream_type;
} tos_channel_stream_info;


typedef struct 
{
	int audioPid; // 0x1fff 忽略，代表不播audio且不停之前在播的audio
	fpi_audio_type_t  audioType;
	int videoPid;// 0x1fff 忽略，代表不播video且不停之前在播的video	
	fpi_video_type_t videoType;   
        int         pcr_pid;
} tos_channel_play_stream_info;


/**
@brief 播放指定的节目,此接口为异步操作,播放过程中的消息通过回调函数抛出

@param[in] channelId 要播放的节目的唯一标识
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play(uint32_t channelId);


/** 
@brief 通过PID播放TV中的某个 stream.比如选择的audio

@param[in] play_id ,p_stream_info 目标流的PID信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_channel_play_stream(EN_TOS_DTV_PLAY_ID_E play_id ,tos_channel_play_stream_info *p_stream_info);

/** 
@brief 获取当前TV正在播放的stream component 的信息，包括pid，stream type等信息

@param[in] play_id，type
@param[out] p_stream_info :
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_channel_play_get_current_stream_info(EN_TOS_DTV_PLAY_ID_E play_id ,EN_TOS_DTV_PLAY_TYPE_E type,tos_channel_stream_info *p_stream_info);

/** 
@brief 停止当前正在播放的stream

@param[in] play_id,stop_type
@param[out] 无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_channel_play_stop_stream(EN_TOS_DTV_PLAY_ID_E  play_id,EN_TOS_DTV_PLAY_STOP_TYPE_E stop_type);

/**
@brief 获取当前播放的节目信息

@param[out] play_info 当前播放的节目的信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_get_current_channel_info(tos_dtv_play_info_t *play_info);

/**
@brief 获取当前播放节目的channelId
@param[out] channelId 当前正播放的节目的唯一标识
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_get_current_channel_id(uint32_t *channelId);

/**
@brief 解锁播放当前的加锁频道(包括节目锁和父母锁)

只要调用了此接口，所有锁(包括节目锁和父母锁)都被解开

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_unlock();

/**
@brief 锁定当前正在播放的节目（不负责存储数据库），关闭音视频

只用于当前正在播放的节目被加锁后调用

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_relock();

/**
@brief 不推荐使用。解锁播放当前的加锁频道或者锁定当前的频道

@param[in] locked   false表示只要调用了此接口，所有锁(包括节目锁和父母锁)都被解开
                    true表示锁定当前正在播放的节目（不负责存储数据库），关闭音视频

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_set_lock_status(fpi_bool locked);

/**
@brief 停止播放当前节目
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_stop();

/**
@brief 获取当前节目的播放状态
节目未播放、播放中
@param[out] status  返回当前节目播放状态的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_get_status(EN_FPI_DTV_PLAY_STATE *status);

/**
@brief 获取当前节目的播放状态srceen_mode_info

@param[out] mode  返回当前节目播放状态的srceen_mode_info
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_get_srceen_mode_info(EN_TOS_DTV_SS_MODE *mode);

/**
@brief 频道模块处理回调
@param[in] eventType 产生的事件类型枚举@see EN_TOS_DTV_PLAY_CB_EVENT_E
@param[in] code 产生的事件码值,根据eventType类型不同有不同的定义,详细见FPI_DTV_PLAY_CB_EVENT_E中每个类型的定义说明
@param[in] data 产生的事件附带数据,根据eventType类型不同有不同的定义,详细见FPI_DTV_PLAY_CB_EVENT_E中每个类型的定义说明
@param[in] userdata 为用户注册数据，回调时原样返回
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
typedef int32_t (*tos_dtv_channel_callback)(EN_TOS_DTV_PLAY_CB_EVENT_E eventType, int code, int data, void* userdata);

/**
@brief 添加Dtv播放模块处理回调,不推介使用
当播放的状态发生变化时，中间件会调用应用注册的本接口配合完成相应的操作的功能.

@param[in] callback 播放回调函数指针
@param[in] userdata 用户数据,注册此回调时的userdata参数.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_channel_play_add_callback(tos_dtv_channel_callback callback, void* userdata);


/**
@brief 删除DTV播放模块回调函数,不推介使用

@param[in] callback Dtv播放回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_remove_callback(tos_dtv_channel_callback callback);

/**
@brief 设置DTV 节目播放更新开关状态,不推介使用

@param[in] flag DTV 节目播放更新开关，fpi_false : 关闭    fpi_true : 开

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_set_channel_play_update_status(fpi_bool flag);


/**
@brief 获取DTV 节目播放更新开关状态

@param[in] 无

@return 返回DTV 节目播放更新开关状态
*/
fpi_bool tos_dtv_get_channel_play_update_status(void);

/*
@brief 暂未实现
@param[in] 无
@return 
*/
fpi_error tos_channel_play_set_flag(EN_TOS_DTV_PLAY_ID_E  id,int *param0,int *param1);


/**
@brief 暂未实现,播放指定的节目,此接口为异步操作,播放过程中的消息通过回调函数抛出
@param[in] info 要播放的节目信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_channel_play_delivery(const tos_dtv_play_info_t *info);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
