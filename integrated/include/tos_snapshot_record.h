/**@defgroup ����¼��ģ��
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
@brief ��������
*/
typedef struct MY_RECT
{
	uint32_t un32_hposition;
	uint32_t un32_vposition;
	uint32_t un32_hsize;
	uint32_t un32_vsize;
	
}ST_SNAPSHOT_RECT;

/** 
@brief �ֱ�������
*/
typedef struct MY_RESOLUTION
{
	uint32_t un32_width;/**<����ID*/
	uint32_t un32_height;/**<����ID*/
}ST_SNAPSHOT_RESOLUTION;

typedef enum{
	EN_RECORD_MODE_OSD,
	EN_RECORD_MODE_VIDEO,
	EN_RECORD_MODE_OSD_VIDEO,
	EN_RECORD_MODE_AUDIO
}EN_RECORD_MODE;

/**
 * @brief ��ָ��window��������н�����������������������ͼƬ�ļ����浽ָ�����ļ�·����
 * @param windowId - ��Ҫ������window��idֵ��Ĭ�ϴ�255���ɱ�ʾȫ��
 * @param rect - ��Ҫ��ȡ�����򣬴�null��ʾָ��window�Ľ�ͼ
 * @param filePath - ��ȡ��ͼƬ������·�����������ļ�������������ļ������ڣ�����´���������������Ѿ����ڣ����串��
 * @param mode - ����ģʽ��ȡֵ�μ�{@link Screenshot#MODE_XXX}
 * @param resolution - �Խ�ȡ��ͼ��֡��ָ����С�����Ŵ���, ��ֵ��ʾͼ��֡��Ⱥ͸߶�
 * @return �ɹ�����true��ʧ�ܷ���false
 */
 
fpi_error tos_snapshot(uint32_t windowId, ST_SNAPSHOT_RECT  *rect,const char* path, uint32_t mode,ST_SNAPSHOT_RESOLUTION *resolution);

/**
 * @briefָ��¼���ܵ��ļ�·��
 * @param mode - ģʽ����enum EN_RECORD_MODE
 * @param filepath - ¼���ܵ��ļ�·��
 */
fpi_error tos_record_set_output_file(EN_RECORD_MODE mode, const char* filepath);

/**
 * @briefָ��¼����Ƶ¼�Ʋ���
 * @param windowId - ��Ҫ������window��idֵ��Ĭ�ϴ�255���ɱ�ʾȫ��
 * @param:resolution - - �ֱ���
 * @param:frame_rate - - ֡��ֵ
 * @param:rect --  ��ȡ��ָ���������Ƶ���ݣ���Ϊ����window
 */
fpi_error tos_record_set_video_param(uint32_t window_id,
										   EN_RECORD_MODE mode,
										   ST_SNAPSHOT_RESOLUTION *resolution,
										   uint32_t frame_rate,
										   ST_SNAPSHOT_RECT *rect);

/**
  * @brief����¼�Ƶ���Ƶ�Ĳ���
  * @param:sampleRate - - �����Ĳ�����
  * @param:sampleBit --  �����ı�����
  */
fpi_error tos_record_set_audio_param(uint32_t sample_rate,uint32_t simple_bit);

/**
  * @brief ��ʼ¼��
  * @param mode - ģʽ����enum EN_RECORD_MODE
  */
fpi_error tos_record_start_screen(EN_RECORD_MODE mode);

/**
  * @brief ֹͣ¼��
  * @param mode - ģʽ����enum EN_RECORD_MODE
  */
fpi_error tos_record_stop_screen(EN_RECORD_MODE mode);

/**
  * @brief ��ͣ¼��
  * @param mode - ģʽ����enum EN_RECORD_MODE
  */
fpi_error tos_record_pause_screen(EN_RECORD_MODE mode);

/**
  * @brief �ָ�¼��
  * @param mode - ģʽ����enum EN_RECORD_MODE
  */
fpi_error tos_record_resume_screen(EN_RECORD_MODE mode);

/**
  * @brief ����¼�ƣ������ӿڣ�δʵ��
  * @param mode - ģʽ����enum EN_RECORD_MODE
  */
fpi_error tos_record_reset_screen(EN_RECORD_MODE mode);

#ifdef __cplusplus
}
#endif

#endif 
