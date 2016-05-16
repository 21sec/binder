/**@defgroup 截屏录流模块
@{

@brief 

@author 

@note 

@version 1.0.0 2015/8/10 
*/
#ifndef __TOS_SNAPSHOT_RECORD_H__
#define __TOS_SNAPSHOT_RECORD_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/** 
@brief 矩形区域
*/
typedef struct MY_RECT
{
	uint32_t un32_hposition;
	uint32_t un32_vposition;
	uint32_t un32_hsize;
	uint32_t un32_vsize;
	
}ST_SNAPSHOT_RECT;

/** 
@brief 分辨率描述
*/
typedef struct MY_RESOLUTION
{
	uint32_t un32_width;/**<窗口ID*/
	uint32_t un32_height;/**<窗口ID*/
}ST_SNAPSHOT_RESOLUTION;

typedef enum{
	EN_RECORD_MODE_OSD,
	EN_RECORD_MODE_VIDEO,
	EN_RECORD_MODE_OSD_VIDEO,
	EN_RECORD_MODE_AUDIO
}EN_RECORD_MODE;

/**
 * @brief 对指定window的区域进行截屏操作，并将截屏下来的图片文件保存到指定的文件路径下
 * @param windowId - 需要截屏的window的id值，默认传255即可表示全屏
 * @param rect - 需要截取的区域，传null表示指定window的截图
 * @param filePath - 截取的图片的完整路径（包含了文件名），如果此文件不存在，则会新创建；如果此问题已经存在，则将其覆盖
 * @param mode - 截屏模式，取值参见{@link Screenshot#MODE_XXX}
 * @param resolution - 对截取的图像帧做指定大小的缩放处理, 此值表示图像帧宽度和高度
 * @return 成功返回true；失败返回false
 */
 
fpi_error tos_snapshot(uint32_t windowId, ST_SNAPSHOT_RECT  *rect,const char* path, uint32_t mode,ST_SNAPSHOT_RESOLUTION *resolution);

/**
 * @brief指定录流管道文件路径
 * @param mode - 模式，见enum EN_RECORD_MODE
 * @param filepath - 录流管道文件路径
 */
fpi_error tos_record_set_output_file(EN_RECORD_MODE mode, const char* filepath);

/**
 * @brief指定录流视频录制参数
 * @param windowId - 需要截屏的window的id值，默认传255即可表示全屏
 * @param:resolution - - 分辨率
 * @param:frame_rate - - 帧率值
 * @param:rect --  截取的指定区域的视频数据，空为整个window
 */
fpi_error tos_record_set_video_param(uint32_t window_id,
										   EN_RECORD_MODE mode,
										   ST_SNAPSHOT_RESOLUTION *resolution,
										   uint32_t frame_rate,
										   ST_SNAPSHOT_RECT *rect);

/**
  * @brief设置录制的音频的参数
  * @param:sampleRate - - 声音的采样率
  * @param:sampleBit --  声音的比特率
  */
fpi_error tos_record_set_audio_param(uint32_t sample_rate,uint32_t simple_bit);

/**
  * @brief 开始录制
  * @param mode - 模式，见enum EN_RECORD_MODE
  */
fpi_error tos_record_start_screen(EN_RECORD_MODE mode);

/**
  * @brief 停止录制
  * @param mode - 模式，见enum EN_RECORD_MODE
  */
fpi_error tos_record_stop_screen(EN_RECORD_MODE mode);

/**
  * @brief 暂停录制
  * @param mode - 模式，见enum EN_RECORD_MODE
  */
fpi_error tos_record_pause_screen(EN_RECORD_MODE mode);

/**
  * @brief 恢复录制
  * @param mode - 模式，见enum EN_RECORD_MODE
  */
fpi_error tos_record_resume_screen(EN_RECORD_MODE mode);

/**
  * @brief 重置录制，保留接口，未实现
  * @param mode - 模式，见enum EN_RECORD_MODE
  */
fpi_error tos_record_reset_screen(EN_RECORD_MODE mode);

#ifdef __cplusplus
}
#endif

#endif 
