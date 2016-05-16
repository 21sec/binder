/**@defgroup tos_mp_avformat
@{

@brief 媒体播放器流信息控制模块,包括音频流、视频流、字幕流等;用于管理播放器的音视频控制

@history 2014/12/18 初稿
@history 2014/12/25 根据评审意见,去除除了音频流相关接口之外的其他音视频设置接口,统一放到ATV音视频控制模块处理
*/

#ifndef __TOS_MP_AVFORMAT_H__
#define __TOS_MP_AVFORMAT_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"
//#include "media_type.h"

#include "tos_mp_player.h"

#ifdef __cplusplus
extern "C" {
#endif


#define TOS_MP_STRING_LENGTH_8          8       ///< 字符串长度值8
#define TOS_MP_STRING_LENGTH_128        128     ///< 字符串长度值128

/**
@brief 定义容器类型枚举
*/
typedef enum {
    EN_FPI_MP_CONTAINER_TYPE_MKV,               ///< MKV类型容器
    EN_FPI_MP_CONTAINER_TYPE_AVI                ///< AVI类型容器
}FPI_MP_CONTAINER_TYPE_E;

/**
@brief 定义字幕类型枚举
*/
typedef enum {
    EN_FPI_MP_SUBTITLE_TYPE_CC,                 ///< CloseCaption类型字幕
    EN_FPI_MP_SUBTITLE_TYPE_SUBTITLE            ///< Subtitle类型字幕
}FPI_MP_SUBTITLE_TYPE_E;

/* drm divx activity state*/
typedef enum
{
    EN_FPI_MP_DRM_DIVX_ACTIVATE_FIRST_TIME,   /*!< first time registeration */
    EN_FPI_MP_DRM_DIVX_ACTIVATED_STATE,       /*!< The device is in activated state */
    EN_FPI_MP_DRM_DIVX_DEACTIVATED_STATE,    /*!< The device is in deactivated state */
}FPI_MP_DIVXDRM_ACTIVITYSTATE_E;

typedef enum
{
    EN_FPI_MP_DIVXDRM_CP_TYPE_BASE = 1,
    EN_FPI_MP_DIVXDRM_CP_TYPE_ACTIVATION_PURCHASE,
    EN_FPI_MP_DIVXDRM_CP_TYPE_ACTIVATION_RENTAL,
    EN_FPI_MP_DIVXDRM_CP_TYPE_PURCHASE,
    EN_FPI_MP_DIVXDRM_CP_TYPE_RENTAL,
    EN_FPI_MP_DIVXDRM_CP_TYPE_ENCRYPTED_AUDIO
}FPI_MP_DIVXDRM_CP_TYPE_E;

/*DRM Copy Protection Status*/
typedef enum
{
    EN_FPI_MP_DIVXDRM_CP_STATUS_ERROR_NONE = 1,
    EN_FPI_MP_DIVXDRM_CP_STATUS_NOT_AUTH_USER,
    EN_FPI_MP_DIVXDRM_CP_STATUS_RENTAL_EXPIRED,
    EN_FPI_MP_DIVXDRM_CP_STATUS_UNRECOGNIZED_DRM_MODE,
    EN_FPI_MP_DIVXDRM_CP_STATUS_NOT_LIMITED_RENTAL_TYPE,
}FPI_MP_DIVXDRM_CP_STATUS_E;


/**
@brief 定义媒体sample的描述信息
*/
typedef struct {
    uint32_t track_id;                          ///< track id      
    uint32_t  duration;                         ///< sample 的duration             
    uint32_t  size;                             ///< sample 的大小 
    uint32_t  composition_time_offset;          ///< time offset
    uint32_t  time_scale;                       ///< time scale
}FPI_MP_Sample_S;


/**
@brief 定义媒体文件容器信息结构体
*/
typedef struct {
    int size;                                               ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_ContainerInfo_S)
    int id;                                                 ///< MSE & EME 存放buffer id，其它存放playerid
    FPI_MP_CONTAINER_TYPE_E type;                           ///< 容器类型
    bool seekable;                                          ///< 是否支持定位播放,true表示支持,false表示不支持
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 名字
    unsigned char rating[TOS_MP_STRING_LENGTH_8];           ///< 等级

    uint32_t  sample_count;                                 ///< sample 数目
    FPI_MP_Sample_S *samples;                               ///< sample的描述信息，使用完后要记得free
}FPI_MP_ContainerInfo_S;


/**
@brief 定义音频流信息结构体
*/
typedef struct {
    int size;                                               ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_AudioStream_S)
    int id;                                                 ///< 音频流ID值
    unsigned char codec[TOS_MP_STRING_LENGTH_8];            ///< 编码名称
    unsigned char language[TOS_MP_STRING_LENGTH_8];         ///< ISO 639 3-letter language code (empty string if undefined)
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 音频流名字
    int channelCount;                                       ///< 声道个数
}FPI_MP_AudioStream_S;

/**
@brief 定义视频流信息结构体
*/
typedef struct {
    int size;                                               ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_VideoStream_S)
    int id;                                                 ///< 视频流ID值
    unsigned int width;
    unsigned int height;
    unsigned char codec[TOS_MP_STRING_LENGTH_8];            ///< 编码名称
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 视频流名字
}FPI_MP_VideoStream_S;

/**
@brief 定义字幕信息结构体
*/
typedef struct {
    int size;                                               ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_SubtitleInfo_S)
    FPI_MP_SUBTITLE_TYPE_E type;                            ///< 字幕类型
    unsigned char language[TOS_MP_STRING_LENGTH_8];         ///< ISO 639 3-letter language code (empty string if undefined)
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 字幕名字
    unsigned char displayname[TOS_MP_STRING_LENGTH_8*2];    ///< 字幕名字
}FPI_MP_SubtitleInfo_S;

/**
@brief 定义章节信息结构体
*/
typedef struct {
    int id;                                                 ///< 章节id值
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 章节名字
}FPI_MP_ChapterInfo_S;

typedef struct
{
    int  DRMflag;  /*is drm file*/
    FPI_MP_DIVXDRM_CP_TYPE_E   drmType;              /*drm protected mode*/
    FPI_MP_DIVXDRM_CP_STATUS_E drmStatus;            /*drm protected status*/
    unsigned int      numRentalPlays;       /*used times*/
    unsigned int      TotalNumPlays;        /*total times*/
    unsigned char     isAudioProtected;     /*audio protected status*/
} FPI_MP_DivxDRM_CopyProtectionInfo_S;

/**
@brief 获取正在播放的媒体的容器信息

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[out] containerInfo 输出参数,容器的信息.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_container_info(unsigned int playerId, FPI_MP_ContainerInfo_S* containerInfo);


/**
@brief 获取当前播放的媒体的音频流个数

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的音频流个数
*/
int tos_mp_get_audio_stream_count(unsigned int playerId);


/**
@brief 获取指定索引的音频流信息

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index 音频流的索引.
@param[out] audioStream 输出参数,音频流的信息.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_audio_stream(unsigned int playerId, int index, FPI_MP_AudioStream_S* audioStream);


/**
@brief 设置播放指定索引的音频流

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index 音频流的索引.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_audio_stream(unsigned int playerId, int index);


/**
@brief 获取当前播放的媒体的音频流索引

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的音频流索引
*/
int tos_mp_get_current_audio_stream(unsigned int playerId);


/**
@brief 获取当前播放器中视频流个数

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的视频流个数
*/
int tos_mp_get_video_stream_count(unsigned int playerId);

/**
@brief 获取指定索引的视频流信息

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index 视频流的索引.
@param[out] videoStream 输出参数,视频流的信息.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_video_stream(unsigned int playerId, int index, FPI_MP_VideoStream_S* videoStream);


/**
@brief 设置外挂字幕的URI

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] uri 外挂字幕文件的路径
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_subtitle_uri(unsigned int playerId, const char* uri);


/**
@brief 获取当前播放的媒体的subtitle个数

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的subtitle个数
*/
int tos_mp_get_subtitle_count(unsigned int playerId);


/**
@brief 获取指定索引的subtitle信息

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index subtitle的索引.
@param[out] subtitleInfo 输出参数,subtitle的信息.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_subtitle(unsigned int playerId, int index, FPI_MP_SubtitleInfo_S* subtitleInfo);


/**
@brief 设置播放指定索引的subtitle

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index subtitle的索引.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_subtitle(unsigned int playerId, int index);


/**
@brief 获取当前播放的媒体的subtitle索引

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的subtitle索引
*/
int tos_mp_get_current_subtitle(unsigned int playerId);


/**
@brief 设置字幕是否显示

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] visible true表示显示字幕;false表示隐藏字幕.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_subtitle_visible(unsigned int playerId, bool visible);



/**
@brief 获取当前播放的媒体的章节个数

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的章节个数
*/
int tos_mp_get_chapter_count(unsigned int playerId);


/**
@brief 获取指定索引的章节信息

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index 章节的索引.
@param[out] chapterInfo 输出参数,章节的信息.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_chapter(unsigned int playerId, int index, FPI_MP_ChapterInfo_S* chapterInfo);


/**
@brief 设置播放指定索引的章节

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] index 章节的索引.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_chapter(unsigned int playerId, int index);


/**
@brief 获取当前播放的媒体的章节索引

@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@return 当前正在播放的媒体的章节索引
*/
int tos_mp_get_current_chapter(unsigned int playerId);



/**
@brief 定义媒体INIT DATA 类型枚举
*/
typedef enum {
    EN_FPI_MP_CENC,               ///<CENC
    EN_FPI_MP_KEYID,                ///< KEYID
    EN_FPI_MP_WEBM,                ///< WEBM
}FPI_MP_INIT_DATA_TYPE_E;

/**
@brief 定义媒体INIT DATA 类型枚举
*/
typedef enum {
    EN_FPI_MP_CLEARKEY,               ///<CLEARKEY
    EN_FPI_MP_PLAYREADY,              ///< PLAYREADY
    EN_FPI_MP_WIDEVINE,               ///< WIDEVINE
}FPI_MP_DRM_TYPE_E;


/**
@brief 获取媒体INIT DATA

@param[in] playerId 媒体播放器ID，如果是MSE&EME则是SourceBufferID
@param[in] type INIT data 类型
@param[in] size  INIT data 大小
@param[in] data INIT data

@return 成功返回: 0，失败返回: -1
*/
int tos_mp_get_init_data(unsigned int playerId, FPI_MP_INIT_DATA_TYPE_E *init_type, unsigned int *size, void** data);

/**
@brief 更新drm解扰信息

@param[in] playerId 媒体播放器ID, 如果是MSE&EME则是SourceBufferID
@param[in] type INIT data 类型
@param[in] 更新数据
@param[in] 数据大小

@return 成功返回: 0，失败返回: -1
*/
int tos_mp_update_drm(unsigned int playerId, FPI_MP_DRM_TYPE_E drm, void *data, unsigned int len);

/**
@brief 定义章节信息结构体
*/
typedef struct {
    int id;                                                 ///< 章节id值
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< 章节名字
}FPI_MP_TitleInfo_S;

typedef struct
{
    char Identify[4];
    char Title[100];
    char Artist[100];
    char Album[100];
    char Year[20];
    char Comment[200];
    char genre[100];
} FPI_MP_ID3_S;

typedef struct
{
	int32_t width;
	int32_t height;
	int64_t time;
	char *thumbnail_url;
} FPI_MP_Thunmnail_S;


/**
@brief 查询当前文件的TITLE个数
@note
@return 当前正在播放的媒体的TITLE个数
*/
int tos_mp_get_title_count(unsigned int playerId);

/**
@brief 切换TITLE  播放
@note 

@param[in] title 
		
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_title(unsigned int playerId, int32_t title, int64_t time);


/**
@brief 查询当前正在播放的是第几个TITLE
@note
@param[out] titleinfo
		    数据结构:
				int titleid; TITLE ID
				char titleName[MM_TITLE_LENGTH]; TITLE的名字
				char titleLawRating[MM_LAW_RATING_LENGTH];TITLE的分级信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_title(unsigned int playerId, FPI_MP_TitleInfo_S * titleinfo);

/**
@brief 设置图片播放效果

@param[in] effect 图片播放效果参数

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_id3info(unsigned int playerId, char* filesrc, FPI_MP_ID3_S* info);


/**
@brief 获取指定媒体文件某个时间点的视频缩略图
@note
@param[in] width  图片宽度
@param[in] height 图片高度
@param[in] time 时间戳
@param[in]src_url 打开的图片路径
@param[out]thumbnail_url 保存的图片路径

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_create_thumbnail(unsigned int playerId, char* filesrc, FPI_MP_Thunmnail_S* info);


/**
@brief 检测divx的激活状态

@note

@param[out] state
		DRM_DIVX_ACTIVATE_FIRST_TIME,  --  首次激活
             DRM_DIVX_ACTIVATED_STATE,      --   已激活
             DRM_DIVX_DEACTIVATED_STATE,    --  未激活

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_divx_active_state(unsigned int playerId, FPI_MP_DIVXDRM_ACTIVITYSTATE_E *state);

/**
@brief 获取divx的注册码

@note

@param[out] buf 注册码数据
@param[in] buf_size 注册码长度
		
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_divx_regcode(unsigned int playerId, char *buf, uint32_t buf_size);

/**
@brief 获取divx的注销码

@note

@param[out] buf 注销码数据
@param[in] buf_size 注销码长度
		
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_divx_deactivecode(unsigned int playerId, char *buf, uint32_t buf_size);

/**
@brief 获取divx保护信息
@note

@param[out] info
		    数据结构:
		       int  DRMflag;                                  is drm file
                    FPI_MP_DIVXDRM_CP_TYPE_E   drmType;           drm protected mode
                    FPI_MP_DIVXDRM_CP_STATUS_E drmStatus;       drm protected status
                    unsigned int      numRentalPlays;        used times
                    unsigned int      TotalNumPlays;         total times
                    unsigned char     isAudioProtected;  audio protected status
		
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_divx_protectinfo(unsigned int playerId, FPI_MP_DivxDRM_CopyProtectionInfo_S *info);

/**
@brief 获取指定音频文件的cover
@note
@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] filepath 音频文件的路径
@param[out]cover_path 音频文件cover保存的路径

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_audio_cover(unsigned int playerId, char * filepath, char *cover_path);

typedef enum
{
	EN_FPI_MP_USER_CONFIG_DRM_UA,
	EN_FPI_MP_USER_CONFIG_NORMAL_UA,
	EN_FPI_MP_USER_CONFIG_MEDIA_UA,
	EN_FPI_MP_USER_CONFIG_CUSTOM_DATA
} FPI_MP_user_config_type;

/**
@brief 设置DRM的USER CONFIG数据,包含user agent 和 custom data
@note
@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] type user config 类型
@param[in] data,user config的具体数据
@param[in] data_size,user config的具体数据的长度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_user_config(unsigned int playerId, FPI_MP_user_config_type type, char *data, uint32_t data_size);


/**
@brief 设置输出窗口大小
@note
@param[in] playerId 媒体播放器ID, 唯一标示一个播放器.
@param[in] x, 输出窗口的X坐标
@param[in] y, 输出窗口的Y坐标
@param[in] width, 输出窗口的长
@param[in] height, 输出窗口的高
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_output_window(unsigned int playerId, int x, int y, int width, int height);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
