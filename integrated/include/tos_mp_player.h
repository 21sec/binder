/**@defgroup tos_mp_player
@{

@brief 媒体播放器模块,用于控制播放各种媒体源,暂不考虑PIP

目前支持的媒体源类型包括:
 - 网络媒体: 如http://xxx等
 - 本地媒体: 如file:///xxx等.

@code 常见使用场景示例
//播放网络VOD
tos_mp_set_datasource(x,"http://xxx");
tos_mp_prepare(x);
tos_mp_play(x);

//从播放网络VOD的应用切走
//或释放多媒体播放器
tos_mp_stop(x);
tos_mp_release(x);

//切换USB设备中的影片
tos_mp_stop(x);
tos_mp_set_datasource(x,"file:///xxx");
tos_mp_prepare(x);
tos_mp_play(x);
@endcode

播放器状态机如下：
<img src="doc-files/mediaplayer.pdf">

@history 2014/12/17 初稿
@history 2014/12/25 根据评审意见修改,添加PREPARING和PLAYBACK_COMPLETED两个状态
*/

#ifndef __TOS_MP_PLAYER_H__
#define __TOS_MP_PLAYER_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 定义播放器状态枚举
*/
typedef enum {
    EN_FPI_MP_STATE_IDLE,               ///< 初始状态
    EN_FPI_MP_STATE_PREPARING,          ///< 准备中状态
    EN_FPI_MP_STATE_PREPARED,           ///< 准备就绪状态
    EN_FPI_MP_STATE_STARTED,            ///< 开始状态
    EN_FPI_MP_STATE_PAUSED,             ///< 暂停状态
    EN_FPI_MP_STATE_TRICKMODE,          ///< 快进快退状态
    EN_FPI_MP_STATE_PLAYBACK_COMPLETED  ///< 播放完毕状态
}FPI_MP_STATE_E;


/**
@brief 定义播放器回调事件枚举
*/
typedef enum {
    EN_FPI_MP_EVENT_BUFFERING_UPDATE,       ///< 缓冲百分比变化,此时code表示已经缓冲了的百分比,取值0~100
    EN_FPI_MP_EVENT_BUFFERING_START,        ///< 暂停播放,开始缓冲数据
    EN_FPI_MP_EVENT_BUFFERING_END,          ///< 缓冲到了足够的数据,开始重新播放
    EN_FPI_MP_EVENT_PREPARED_COMPLETED,     ///< 播放器进入PREPARED状态并开始播放的时候触发
    EN_FPI_MP_EVENT_VIDEO_PLAY_SUCCESS,     ///< 视频播放成功,表示开始渲染第一帧
    EN_FPI_MP_EVENT_VIDEO_PLAY_FAILED,      ///< 视频播放失败,此时code表示失败原因,取值为FPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_AUDIO_PLAY_SUCCESS,     ///< 音频播放成功
    EN_FPI_MP_EVENT_AUDIO_PLAY_FAILED,      ///< 音频播放失败,此时code表示失败原因,取值为FPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_SEEK_COMPLETED,         ///< 定位播放操作完成后触发
    EN_FPI_MP_EVENT_PAUSE_COMPLETED,        ///< 暂停播放操作完成后触发
    EN_FPI_MP_EVENT_RATE_CHANGED,           ///< 播放器速率发生变化,此时code表示新的速率
    EN_FPI_MP_EVENT_REWIND_TO_HEAD,         ///< 回退到起始端
    EN_FPI_MP_EVENT_FORWARD_TO_END,         ///< 快进到结尾
    EN_FPI_MP_EVENT_PLAY_TO_END,            ///< 正常播放到结尾
    EN_FPI_MP_EVENT_SERVER_DIED,            ///< 与数据源服务器交互失败,此时code表示失败原因,取值为FPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_NOT_SEEKABLE,           ///< 媒体不支持seek,例如直播流
    EN_FPI_MP_EVENT_NOT_CHANGE_RATE,        ///< 媒体不支持快进快退
    EN_FPI_MP_EVENT_FIND_AUDIO_STREAM,      ///< 检测到音频流信息,具体信息通过fpi_mp_avformat.h中的相关接口来获取
    EN_FPI_MP_EVENT_FIND_VIDEO_STREAM,      ///< 检测到视频流信息,具体信息通过fpi_mp_avformat.h中的相关接口来获取
    EN_FPI_MP_EVENT_FIND_SUBTITLE,          ///< 检测到字幕信息,具体信息通过fpi_mp_avformat.h中的相关接口来获取
    EN_FPI_MP_EVENT_TIME_UPDATE,            ///< 播放时间更新,每秒发送一次,此时code表示相对于起始播放时间的偏移,单位是毫秒
    EN_FPI_MP_EVENT_STOP_COMPLETED,         ///< 停止播放成功
    EN_FPI_MP_EVENT_RELEASE_COMPLETED,      ///< 释放播放器成功
    EN_FPI_MP_EVENT_MEDIA_PARSE,            ///< 媒体信息解析
    EN_FPI_MP_EVENT_MEDIA_REMOVE,           ///< 媒体信息移除
    EN_FPI_MP_EVENT_VIDEO_IN,               ///<视频播放开始，表示可以开画
    EN_FPI_MP_EVENT_VIDEO_OUT,              ///<视频播放结束，表示可以关画
    EN_FPI_MP_EVENT_AUDIO_MUTE,             ///<音频播放结束，表示可以关声音
    EN_FPI_MP_EVENT_AUDIO_UNMUTE,           ///<音频播放开始，表示可以开声音
    EN_FPI_MP_EVENT_AV_SYNC_DONE,
    EN_FPI_MP_EVENT_HDCP_OK,                ///<HDCP认证成功
    EN_FPI_MP_EVENT_HDCP_FAIURE,            ///<HDCP认证失败
    EN_FPI_MP_EVENT_HDCP_NEED,              ///<需要HDCP认证
    EN_FPI_MP_EVENT_THUMBNAIL_CREATE,       ///<缩略图创建完成
}FPI_MP_CB_EVENT_E;


/**
@brief 定义播放失败原因枚举
*/
typedef enum {
    EN_FPI_MP_REASON_UNKNOWN,               ///< 未知原因
    EN_FPI_MP_REASON_CONNECT_FAILED,        ///< 连接数据源失败
    EN_FPI_MP_REASON_FORMAT_NOT_SUPPORT,    ///< 视频/音频格式不支持
    EN_FPI_MP_REASON_UNAUTHORIZED,          ///< 未授权
	EN_FPI_MP_REASON_EXPIRED,				///< 已经过期
    EN_FPI_MP_REASON_CACHE_FAILED,          ///< 缓冲失败
    EN_FPI_MP_REASON_NO_VIDEO,              ///< 没有视频
    EN_FPI_MP_REASON_NO_AUIDO,              ///< 没有音频
    EN_FPI_MP_REASON_INITSEG_PARSED,        ///< 媒体信息头解析完成
    EN_FPI_MP_REASON_SAMPLE_PARSED,         ///< 媒体sample解析完成
    EN_FPI_MP_REASON_NEEDKEY_PARSED,        ///< NK信息解析完成
    EN_FPI_MP_REASON_PARSE_COMPLETED,       ///< 媒体数据全部解析完成
}FPI_MP_PLAY_FAILED_REASON_E;

/**
@brief 定义播放器类型枚举
*/
typedef enum {
    EN_FPI_MP_TYPE_GST,                     ///< gstreamer播放器
    EN_FPI_MP_TYPE_FFMPEG,                  ///< ffmpeg播放器
    EN_FPI_MP_TYPE_PICTURE,                 ///< 图片播放器
	EN_FPI_MP_TYPE_NUM
}FPI_MP_TYPE_E;

/**
@brief 播放器的回调函数类型定义

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] event 产生的事件类型枚举
@param[in] code 产生的事件码值,根据event类型不同有不同的定义,详细见FPI_MP_CB_EVENT_E中每个类型的定义说明
@param[in] data 产生的事件附带数据,根据event类型不同有不同的定义,详细见FPI_MP_CB_EVENT_E中每个类型的定义说明
@param[in] userData 用户数据,其值为调用fpi_mp_add_callback时传入的用户数据
*/
typedef void (*tos_mp_callback_fn)(unsigned int playerId, FPI_MP_CB_EVENT_E event, int code, void* data, void *userData);


/**
@brief 创建媒体播放器

完成此播放器的初始化动作；但是不会在此时申请任何资源

@param[in] type 取FPI_MP_TYPE_E枚举中的值，表示需要创建的播放器类型.
@return 成功返回媒体播放器ID, 唯一标示一个播放器; 失败返回0
*/
unsigned int tos_mp_create_mediaplayer(FPI_MP_TYPE_E type);


/**
@brief 销毁指定的媒体播放器

此接口为同步,调用完后,此播放器被销毁

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_destroy_mediaplayer(unsigned int playerId);


/**
@brief 添加指定播放器的回调函数

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] cb 回调函数指针
@param[in] userData 用户数据,会在回调函数中抛出
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_add_callback(unsigned int playerId, tos_mp_callback_fn cb, void* userData);


/**
@brief 删除指定播放器的回调函数

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] cb 回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_remove_callback(unsigned int playerId, tos_mp_callback_fn cb);


/**
@brief 设置媒体播放器的数据源参数

此接口可以用于设置任何类型的数据源.目前支持的URL格式包括:
- http:// 播放网络媒体类数据源
- file:/// 播放本地媒体类数据源

@note 如果本地文件是ts文件,则可以在url后添加附带programNumber参数表示播放此ts的哪个节目,格式如下: file:///xxx.ts?programNumber=xx

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] url 希望播放的目标数据源对应的url
@return  成功返回sourceId,  失败返回-1.
*/
int tos_mp_set_datasource(unsigned int playerId, const char* url);


/**
@brief 准备已设置的数据源

准备好播放需要用到的资源,可以开始去做缓冲的动作

@note 必须在fpi_mp_set_datasource接口之后调用.
@note 此接口为异步

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_prepare(unsigned int playerId);


/**
@brief 释放指定的媒体播放器所占用资源

@note 此接口为异步

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_release(unsigned int playerId);


/**
@brief 从指定时间开始播放数据源,打开音视频

成功调用后会开始播放.
@note 此接口是异步实现,播放是否真正成功需要回调消息确认.

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] timestamp 开始播放时间,单位是毫秒;对于点播类,表示从开始到目标位置的毫秒数(相对时间);对于时移类有时间基的媒体,表示起始播放时间到1997年7月1日的毫秒数(绝对时间).
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_play(unsigned int playerId, int64_t timestamp);


/**
@brief 停止播放数据源,关闭音视频

@note 此接口是异步实现,播放是否真正停止成功需要回调消息确认.

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_stop(unsigned int playerId);


/**
@brief 定位播放,从指定时间开始播放数据源

@note 此接口是异步实现,定位是否真正成功需要回调消息确认.
@note 此接口要做好多次频繁调用的相关处理

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] timestamp 开始播放时间,单位是毫秒;对于点播类,表示从开始到目标位置的毫秒数(相对时间);对于时移类有时间基的媒体,表示起始播放时间到1997年7月1日的毫秒数(绝对时间).
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_seek(unsigned int playerId, int64_t timestamp);


/**
@brief 暂停播放数据源

@note 此接口是异步实现,暂停是否真正成功需要回调消息确认.

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_pause(unsigned int playerId);


/**
@brief 恢复播放数据源

@note 此接口是异步实现,恢复是否真正成功需要回调消息确认.

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_resume(unsigned int playerId);


/**
@brief 设置播放速率,用来实现快进/快退/慢进/慢退等操作

@note 此接口是异步实现,是否真正成功需要回调消息确认.

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@param[in] rate 速率,大于0表示前进的速率;小于0表示后退的速率.0表示暂停状态的速率.
    为了采用int类型表示如0.5倍速的慢进慢退,针对rate的取值特做如下说明:
    1024表示1倍速,以此类推,512表示0.5倍速,2*1024表示2倍速,16*1024表示16倍速
    反之,-1024表示1倍速后退,-2*1024表示2倍速后退
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_rate(unsigned int playerId, int rate);


/**
@brief 获取当前播放速率

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 返回当前速率,大于0表示前进的速率;小于0表示后退的速率.0表示暂停状态的速率.
    为了采用int类型表示如0.5倍速的慢进慢退,针对rate的取值特做如下说明:
    1024表示1倍速,以此类推,512表示0.5倍速,2*1024表示2倍速,16*1024表示16倍速
    反之,-1024表示1倍速后退,-2*1024表示2倍速后退
*/
int tos_mp_get_rate(unsigned int playerId);


/**
@brief 获取播放器的当前播放状态

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 返回当前的状态
*/
FPI_MP_STATE_E tos_mp_get_current_state(unsigned int playerId);


/**
@brief 获取正在播放的媒体的总时长

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 单位是毫秒,返回当前媒体的总时长;如果无固定时长,则返回-1
*/
int64_t tos_mp_get_duration(unsigned int playerId);

/**
@brief 获取当前播放时间

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 返回当前播放时间,单位毫秒;对于点播类,表示从开始到目标位置的毫秒数(相对时间);对于时移类有时间基的媒体,表示起始播放时间到1997年7月1日的毫秒数(绝对时间).
*/
int64_t tos_mp_get_current_play_time(unsigned int playerId);


/**
@brief 获取正在播放的媒体的起始时间

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 单位是秒;对于点播类,应该返回0(相对时间);对于时移类有时间基的媒体,表示起始播放时间到1997年7月1日的秒数(绝对时间).
*/
int64_t tos_mp_get_start_time(unsigned int playerId);


/**
@brief 获取正在播放的媒体的结束时间

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 单位是秒;对于点播类,应该返回总时长(相对时间);对于时移类有时间基的媒体,表示起始播放时间到1997年7月1日的秒数(绝对时间).
*/
int64_t tos_mp_get_end_time(unsigned int playerId);


/**
@brief 获取目前已经缓冲的进度百分比

@param[in] playerId 媒体播放器ID,唯一标示一个播放器.
@return 缓冲的进度百分比,取值0~100.
*/
int tos_mp_get_buffer_progress(unsigned int playerId);


unsigned int  tos_mp_get_handle(unsigned int playerId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
