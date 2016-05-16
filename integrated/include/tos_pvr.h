/**@defgroup PVR模块

@{
@brief 用于控制电视中节目录制，时移等相关操作

@version 1.0.0 2015/01/21 初稿
@version 1.0.1 2016/02/26 增加tos_pvr_timeshift_start_v2接口
**/
#ifndef __TOS_PVR_H__
#define __TOS_PVR_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" 
{
#endif

#define     TOS_PVR_FILE_NAME  256
#define     TOS_PVR_FILE_PATH  256
#define     TOS_PVR_CHANNEL_NAME 32
#define	    TOS_PVR_EVENT_NAME  32
#define     TOS_PVR_MAX_LANGUAGE_CODE 4

typedef enum
{
    E_PVR_PAUSE,   ///< 当前播放的动作，暂停状态
    E_PVR_NORMAL,  ///< 当前播放的动作，正常播放状态
    E_PVR_FF_2X,   ///< 当前播放的动作，2X快进状态
    E_PVR_FF_4X,   ///< 当前播放的动作，4X快进状态
    E_PVR_FF_8X,   ///< 当前播放的动作，8X快进状态
    E_PVR_FF_16X,  ///< 当前播放的动作，16X快进状态
    E_PVR_FF_32X,  ///< 当前播放的动作，32X快进状态
    E_PVR_FB_2X,   ///< 当前播放的动作，2X快退状态
    E_PVR_FB_4X,   ///< 当前播放的动作，4X快退状态
    E_PVR_FB_8X,   ///< 当前播放的动作，8X快退状态
    E_PVR_FB_16X,  ///< 当前播放的动作，16X快退状态
    E_PVR_FB_32X,  ///< 当前播放的动作，32X快退状态
    E_PVR_SLOW_1_2_X, ///< 当前播放的动作，1/2慢速状态
    E_PVR_SLOW_1_4_X, ///< 当前播放的动作，1/4慢速状态
    E_PVR_SLOW_1_8_X, ///< 当前播放的动作，1/8慢速状态
    E_PVR_SLOW_1_16_X,///< 当前播放的动作，1/16慢速状态
    E_PVR_MOTION_NUM
} EN_TOS_PVR_MOTION;///< PVR播放的动作

typedef enum
{
    E_PVR_PLAY_PREVIOUS, ///< 上一个文件播放
    E_PVR_PLAY_NEXT,     ///< 下一个文件播放
    E_PVR_PLAY_NUM
} EN_TOS_PVR_PLAY; 

typedef enum
{
    E_PLAY_MODE_NORMAL = 0,    ///< 正常播放
    E_PLAY_MODE_RANDOM,        ///< 随机播放
    E_PLAY_MODE_REPEAT_ALL,    ///< 循环播放
    E_PLAY_MODE_REPEAT_ONE     ///< 单曲循环
} EN_TOS_PVR_PLAY_REPEAT_MODE; ///< 播放循环模式
typedef enum
{
	E_ORDER_NAME,               ///< 按名称排序
	E_ORDER_DATE,               ///< 按日期排序
	E_ORDER_NUM 
} EN_TOS_PVR_FILE_SORT_TYPE;  ///< 文件拍寻模式
typedef enum
{
	E_PVR_RECORDING,        ///< 录制状态
	E_PVR_TIMESHIFT,        ///< 时移状态
	E_PVR_NUM
} EN_TOS_PVR_TYPE;   
typedef enum
{
	E_TIMESHIFT_WRITE_SPEED_TEST_START,    ///< 写磁盘测速开始动作
	E_TIMESHIFT_WRITE_SPEED_PROGRESS,      ///< 写磁盘测速过程
	E_TIMESHIFT_WRITE_SPEED_STOP,          ///< 写磁盘测速停止动作
  E_TIMESHIFT_WRITE_SPEED_TEST_NUM
} EN_TOS_TIMESHIFT_WRITE_SPEED_TEST;
typedef enum
{
	E_RECORD_0,    ///< 第一路录制通道ID
	E_RECORD_1,      ///< 第二路录制通道ID
  E_RECORD_NUM    ///< 支持的录制通道数量
} EN_TOS_PVR_RECORD_ID;

typedef struct
{
    char language[TOS_PVR_MAX_LANGUAGE_CODE];      ///< 当前支持的声音语言列表，长度为num  /*!< ISO 639 3-letter language code (empty string if undefined) */
    MEMBER_LANGUAGE eLanguage;  ///<当前语言枚举
    int32_t id;        ///< 当前支持的声音语言的id
}tos_pvr_audio_stream_info_t;/*the same as APP_PVR_LANG_INFO*/

typedef struct
{
    char language[TOS_PVR_MAX_LANGUAGE_CODE];    ///< 当前支持的subtitle语言列表， /*!< ISO 639 3-letter language code (empty string if undefined) */
    MEMBER_LANGUAGE eLanguage;  ///<当前语言枚举
    int32_t id;      ///< 当前支持的subtitle语言的id
}tos_pvr_subtitle_stream_info_t;/*the same as APP_PVR_LANG_INFO*/

typedef struct
{
    int16_t    year;
    int8_t     month;
    int8_t     date;
    int8_t     hour;
    int8_t     minute;
    int8_t     second;
} tos_pvr_time;

typedef struct
{
	unsigned char name[TOS_PVR_FILE_NAME];      ///< 磁盘文件名称
	unsigned char url[TOS_PVR_FILE_PATH];      ///< 磁盘挂载路径
} tos_pvr_recording_file_info_t;

typedef struct
{
	unsigned char name[TOS_PVR_FILE_NAME];      ///< 磁盘文件名称
	unsigned char url[TOS_PVR_FILE_PATH];      ///< 磁盘挂载路径
	int  channelNum;                            ///< 频道号
	unsigned char channelName[TOS_PVR_CHANNEL_NAME];  ///< 频道名称
	unsigned char eventName[TOS_PVR_EVENT_NAME];  ///< 事件名称
	tos_pvr_time time;///< 录制时间
	int64_t size;                               ///< 文件大小，以byte为单位
	int32_t duration;                           ///< 时长，单位秒
} tos_pvr_recording_info_t;     

typedef struct
{
	EN_TOS_PVR_RECORD_ID eRecordId;      ///< 录制通道ID,作为扩展双通道录制预留
	fpi_bool bIsBackground;      ///< 是否后台运行，决定触发时是否进行音视频freeze
	fpi_bool bAutoExit;    ///< 回放过程中没有足够的缓存是否允许自动退出到直播，例如快进到接近直播的情况，预留
} tos_pvr_timeshift_start_params_t;                         

/**
@brief 判断磁盘是否有录制文件存在,快速判断磁盘是否包含录制的PVR文件
@param[in] path 如果为空，中间件自行寻找磁盘，其他按照应用指定路径进行判断，如果存在多个磁盘，应用需要多次调用
@param[out] isExist 磁盘是否有录制文件，指针类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_is_record_file_exist(char *path,fpi_bool *isExist);

/**
@brief 扫描指定的磁盘路径，用于获取pvr录制的文件
@param[in] usbDiskPath 磁盘路径，pvr文件，如果为空，中间件自行寻找磁盘，其他按照应用指定路径进行判断，如果存在多个磁盘，应用需要多次调用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_scan_directory(char *usbDiskPath);

/**
@brief 释放磁盘扫描分配的资源，与tos_pvr_scan_directory配套使用,调用此接口后，扫描结果被释放，退出pvr list时调用，避免内存泄露
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_scan_resource_release(void);

/**
@brief 获取录制的列表的长度
需要扫描完成后，在进行获取列表长度，如果未扫描，则返回0.
如果扫描N个目录，则返回N个目录的列表总长度
@param[out] value 获取录制的列表的长度指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_recording_list_count(int32_t *value);

/**
@brief 获取指定起始位置指定个数的录制列表
列表排序方式按照当前排序接口进行
@param[in] startIndex 获取录制的列表的起始位置
@param[out] list 获取录制的列表指针
@param[in/out] count in:输入需要获取的列表长度
                     out:返回列表的实际长度指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_recording_list(int32_t startIndex,tos_pvr_recording_file_info_t *list,uint32_t *count);

/**
@brief 设置录制文件的排序方式
@param[in] type 当前录制文件的排序方式，EN_TOS_PVR_FILE_SORT_TYPE:
                    E_ORDER_NAME
                    E_ORDER_DATE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_set_file_sort_order(EN_TOS_PVR_FILE_SORT_TYPE type);

/**
@brief 获取录制文件的排序方式
@param[out] type 当前录制文件的排序方式指针，EN_TOS_PVR_FILE_SORT_TYPE:
                    E_ORDER_NAME
                    E_ORDER_DATE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_file_sort_order(EN_TOS_PVR_FILE_SORT_TYPE *type);

/**
@brief 获取指定录制文件的信息
@param[in] url 录制文件的地址,对应获取列表结构体tos_pvr_recording_file_info_t中url参数,utf8编码
@param[out] value 获取录制文件的信息指针，秒
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_recording_info(char *url, tos_pvr_recording_info_t *value);

/**
@brief 删除pvr的录制某一个
@param[in] url 录制节目地址指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_delete_recording(char *url);

/**
@brief 指定节目开始录制，一般为当前节目
@param[in] channelId 录制节目的频道id,当快速换台时，传入换完台后节目的信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_start(uint32_t channelId);

/**
@brief 暂停当前录制节目
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_pause(void);

/**
@brief 恢复暂停的录制节目
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_resume(void);

/**
@brief 停止录制节目
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_stop(void);

/**
@brief 判断当前是否在录制
@param[out] value 判断当前录制的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_recording_state(fpi_bool *value);//获取当前录制信息，是否提供

/**
@brief 获取当前录制的文件URL
通过URL找到对应的录制信息
@param[out] url 录制的文件的URL指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_current_recording_url(char *url);

/**
@brief 播放指定的录制文件
保存当前播放文件路径，type等信息。为控制循环逻辑做准备
播放之前，应用需要切换信源到dtv
@param[in] url 录制文件的地址,对应获取列表结构体tos_pvr_recording_info_t中url参数,utf8编码
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_file_start_play(char * url);

/**
@brief 停止播放当前播放的录制文件
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_file_stop_play(void);

/**
@brief 控制播放的操作
@param[in] motion 播放的动作，暂停，恢复播放，停止播放，快进，快退
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_set_motion(EN_TOS_PVR_MOTION motion);

/**
@brief 获取控制播放的操作
@param[out] motion 播放的动作指针，暂停，恢复播放，停止播放，快进，快退
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_current_motion(EN_TOS_PVR_MOTION *motion);

/**
@brief 设置播放的时间位置
跳到指定位置进行播放，如果起播位置不在当前播放的有效时间内，终止播放 
@param[in] seek 播放的位置，秒
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_seek(int32_t seek);

/**
@brief 获取当前播放的时间位置
@param[out] value 当前播放的时间位置，秒
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_current_play_time(int32_t *value);

/**
@brief 获取当前播放的文件URL信息
@param[out] url 当前播放的文件url指针,获取文件信息指针，包括文件路径，size等
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_file_url(char *url);

/**
@brief 获取当前正在播放录制文件的支持的音轨列表
@param[out] list 当前播放的文件的音轨列表信息指针,包含语言，及id信息
@param[in/out] count in:输入需要获取的列表长度
                     out:返回列表的实际长度指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_audio_track_info(tos_pvr_audio_stream_info_t *list,int32_t *count);

/**
@brief 获取当前正在播放录制文件的支持的音轨个数
@param[out] count 当前播放的文件支持的音轨个数，指针类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_audio_track_count(int32_t *count);

/**
@brief 获取当前正在播放录制文件的音轨id
@param[out] 返回当前播放的文件的音轨id
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_current_audio_track(int32_t *id);

/**
@brief 设置当前正在播放录制文件的音轨
@param[in] id 设置当前播放的文件的音轨,对应tos_pvr_audio_stream_info_t中音轨id
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_set_audio_track(int32_t id);

/**
@brief 打开或关闭subtitle
@param[in] bEnable 打开或关闭subtitle
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_enable_subtitle(fpi_bool bEnable);

/**
@brief 设置当前正在播放录制文件的subtitle列表信息
@param[out] list 当前播放的文件的subtitle列表信息指针,包含语言，及id信息
@param[in/out] count in:输入需要获取的列表长度
                     out:返回列表的实际长度指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_subtitle_info(tos_pvr_subtitle_stream_info_t* list,int32_t *count);

/**
@brief 获取当前正在播放录制文件的支持的subtitle个数
@param[out] count 当前播放的文件支持的subtitle个数，指针类型
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_subtitle_count(int32_t *count);

/**
@brief 获取当前正在播放录制文件的subtitle id
@param[out] 返回当前播放的文件的subtitle id
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_current_subtitle(int32_t *id);

/**
@brief 设置当前正在播放录制文件的subtitle
@param[in] id 设置当前播放的文件的subtitle的id,对应tos_pvr_subtitle_stream_info_t中id
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_set_subtitle(int32_t id);

/**
@brief 开始timeshift时移操作
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_start(void);

/**
@brief 开始timeshift时移操作
@param[in] pstStartParams timeshift的开始参数
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_start_v2(tos_pvr_timeshift_start_params_t* pstStartParams);

/**
@brief 停止timeshift时移操作
退出后，如果需要继续播放当前Dtv节目，需要应用调用播放接口
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_stop(void);

/**
@brief 获取时移文件的开始时间，单位为秒
当磁盘空间写满时，新注入的内容会将之前的内容覆盖掉，因此时移文件支持的播放开始时间在不断更新变化
@param[out] u32TimeInSeconds 时移播放文件的起始时间指针，单位是秒
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_get_start_time(uint32_t* u32TimeInSeconds);

/**
@brief 时移的磁盘文件是否初始化
如果初始化后，会有timeshift文件存在，否则，未进行初始化，调用下面初始化操作
@param[out] value 时移的磁盘文件是否初始化状态的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_is_file_exist(fpi_bool *value);

/**
@brief 初始化时移使用的磁盘大小，应用使用，用于选择文件空间的大小,MB
@param[in] u32SizeInMB 时移的磁盘文件空间大小
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_init_file(uint32_t u32SizeInMB);

/**
@brief 获取初始化时移使用的磁盘文件的进度
@param[out] u8Percent 时移的磁盘文件初始化进度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_timeshift_file_init_progress(uint8_t* u8Percent);

/**
@brief 时移的写磁盘测试速度操作
开一个线程操纵
@param[in] test 时移的写磁盘测试速度操作,开始、操作进度、停止
EN_FPI_TIMESHIFT_WRITE_SPEED_TEST：
	E_TIMESHIFT_WRITE_SPEED_TEST_START,
	E_TIMESHIFT_WRITE_SPEED_PROGRESS,
	E_TIMESHIFT_WRITE_SPEED_STOP,
  E_TIMESHIFT_WRITE_SPEED_TEST_NUM
@param[out] u8Percent 时移的写磁盘测试速度操作的测试进度指针，操作状态为开始和停止时，进度无意义，测试状态为PROGRESS时，返回测试的进度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_timeshift_write_speed_test(EN_TOS_TIMESHIFT_WRITE_SPEED_TEST test,uint8_t* u8Percent);

/**
@brief 获取时移写磁盘文件的速度
@param[out] u32SpeedInKBps 时移写磁盘文件的速度指针，kbps.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_timeshift_speed(uint32_t* u32SpeedInKBps);

/**
@brief 获取磁盘的剩余空间状态，判断磁盘是否有剩余空间用于录制或者时移
录制和timeshift剩余磁盘空间,录制需要几十M，时移需要512M
@param[in] type，当前是在录制或者时移状态
@param[out] value 判断磁盘是否有剩余空间的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_free_space_status(EN_TOS_PVR_TYPE type,fpi_bool *value);

/**
@brief 获取磁盘的剩余空间Mb
新项目不允许再使用，应用需自己实现此功能，后续此接口将废弃
@param[out] u32SizeInMB 磁盘是剩余空间大小的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_disk_free_space(uint32_t* u32SizeInMB);

/**
@brief 获取当前的磁盘信息
@param[out] pstrDevName设备挂载路径指针
@param[out] pstrDiskName磁盘名称指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_disk_info(char* pstrDevName,char* pstrDiskName);

/**
@brief 选择磁盘信息，当多个磁盘挂载时选择磁盘
@param[in] pstrDevName设备挂载路径
@param[in] pstrDiskName磁盘名称
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_select_disk(char* pstrDevName,char* pstrDiskName);

/**
@brief 根据指定的磁盘挂载路径及名称，进行磁盘格式化
当参数都为空时，表示中间件自行寻找路径格式化
新项目不允许再使用，应用需自己实现此功能，后续此接口将废弃
@param[in] pstrDevDiskName 磁盘名称
@param[in] strMountPath 挂载路径
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_disk_format(char *pstrDevDiskName,char *strMountPath);

/**
@brief 磁盘格式化进度
新项目不允许再使用，应用需自己实现此功能，后续此接口将废弃
@param[out] u8Percent 磁盘格式化进度指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_get_formating_progress(uint8_t* u8Percent);

/**
@brief 播放上一个或下一个文件
根据用户设置的播放方式，循环播放或顺序播放等进行上一个或下一个文件的播放
@param[in] play表示上一个或下一个文件的播放
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_file_play_by_mode(EN_TOS_PVR_PLAY play);

/**
@brief 获取当前正在播放录制文件的循环播放模式
@param[out] value 当前播放的循环模式指针，EN_FPI_PVR_PLAY_REPEAT_MODE
 																				E_PLAY_MODE_NORMAL = 0,
                                        E_PLAY_MODE_RANDOM,
                                        E_PLAY_MODE_REPEAT_ALL,
                                        E_PLAY_MODE_REPEAT_ONE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_repeat_mode(EN_TOS_PVR_PLAY_REPEAT_MODE *value);

/**
@brief 设置当前正在播放录制文件的循环播放模式
@param[in] repeatmode 当前播放的循环模式，EN_FPI_PVR_PLAY_REPEAT_MODE
 																				E_PLAY_MODE_NORMAL = 0,
                                        E_PLAY_MODE_RANDOM,
                                        E_PLAY_MODE_REPEAT_ALL,
                                        E_PLAY_MODE_REPEAT_ONE
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_set_repeat_mode(EN_TOS_PVR_PLAY_REPEAT_MODE repeatmode);

/**
@brief 获取当前正在播放录制文件所在列表位置
@param[out] value 当前播放的文件所在列表位置指针，这里指全部的录制文件列表中位置
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_play_get_file_position(int32_t *value);

/**
@brief 根据指定的文件地址，对当前播放节目所在的TS流进行整路录制
当参数为空时，表示中间件自行定义文件地址
@param[in] pstrFileName 录制文件的地址
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_ts_start(char *pstrFileName);

/**
@brief 停止录制TS流
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_pvr_record_ts_stop(void);

#ifdef __cplusplus
}
#endif
/** @} */
#endif 
