/**@defgroup PVRģ��

@{
@brief ���ڿ��Ƶ����н�Ŀ¼�ƣ�ʱ�Ƶ���ز���

@version 1.0.0 2015/01/21 ����
@version 1.0.1 2016/02/26 ����tos_pvr_timeshift_start_v2�ӿ�
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
    E_PVR_PAUSE,   ///< ��ǰ���ŵĶ�������ͣ״̬
    E_PVR_NORMAL,  ///< ��ǰ���ŵĶ�������������״̬
    E_PVR_FF_2X,   ///< ��ǰ���ŵĶ�����2X���״̬
    E_PVR_FF_4X,   ///< ��ǰ���ŵĶ�����4X���״̬
    E_PVR_FF_8X,   ///< ��ǰ���ŵĶ�����8X���״̬
    E_PVR_FF_16X,  ///< ��ǰ���ŵĶ�����16X���״̬
    E_PVR_FF_32X,  ///< ��ǰ���ŵĶ�����32X���״̬
    E_PVR_FB_2X,   ///< ��ǰ���ŵĶ�����2X����״̬
    E_PVR_FB_4X,   ///< ��ǰ���ŵĶ�����4X����״̬
    E_PVR_FB_8X,   ///< ��ǰ���ŵĶ�����8X����״̬
    E_PVR_FB_16X,  ///< ��ǰ���ŵĶ�����16X����״̬
    E_PVR_FB_32X,  ///< ��ǰ���ŵĶ�����32X����״̬
    E_PVR_SLOW_1_2_X, ///< ��ǰ���ŵĶ�����1/2����״̬
    E_PVR_SLOW_1_4_X, ///< ��ǰ���ŵĶ�����1/4����״̬
    E_PVR_SLOW_1_8_X, ///< ��ǰ���ŵĶ�����1/8����״̬
    E_PVR_SLOW_1_16_X,///< ��ǰ���ŵĶ�����1/16����״̬
    E_PVR_MOTION_NUM
} EN_TOS_PVR_MOTION;///< PVR���ŵĶ���

typedef enum
{
    E_PVR_PLAY_PREVIOUS, ///< ��һ���ļ�����
    E_PVR_PLAY_NEXT,     ///< ��һ���ļ�����
    E_PVR_PLAY_NUM
} EN_TOS_PVR_PLAY; 

typedef enum
{
    E_PLAY_MODE_NORMAL = 0,    ///< ��������
    E_PLAY_MODE_RANDOM,        ///< �������
    E_PLAY_MODE_REPEAT_ALL,    ///< ѭ������
    E_PLAY_MODE_REPEAT_ONE     ///< ����ѭ��
} EN_TOS_PVR_PLAY_REPEAT_MODE; ///< ����ѭ��ģʽ
typedef enum
{
	E_ORDER_NAME,               ///< ����������
	E_ORDER_DATE,               ///< ����������
	E_ORDER_NUM 
} EN_TOS_PVR_FILE_SORT_TYPE;  ///< �ļ���Ѱģʽ
typedef enum
{
	E_PVR_RECORDING,        ///< ¼��״̬
	E_PVR_TIMESHIFT,        ///< ʱ��״̬
	E_PVR_NUM
} EN_TOS_PVR_TYPE;   
typedef enum
{
	E_TIMESHIFT_WRITE_SPEED_TEST_START,    ///< д���̲��ٿ�ʼ����
	E_TIMESHIFT_WRITE_SPEED_PROGRESS,      ///< д���̲��ٹ���
	E_TIMESHIFT_WRITE_SPEED_STOP,          ///< д���̲���ֹͣ����
  E_TIMESHIFT_WRITE_SPEED_TEST_NUM
} EN_TOS_TIMESHIFT_WRITE_SPEED_TEST;
typedef enum
{
	E_RECORD_0,    ///< ��һ·¼��ͨ��ID
	E_RECORD_1,      ///< �ڶ�·¼��ͨ��ID
  E_RECORD_NUM    ///< ֧�ֵ�¼��ͨ������
} EN_TOS_PVR_RECORD_ID;

typedef struct
{
    char language[TOS_PVR_MAX_LANGUAGE_CODE];      ///< ��ǰ֧�ֵ����������б�����Ϊnum  /*!< ISO 639 3-letter language code (empty string if undefined) */
    MEMBER_LANGUAGE eLanguage;  ///<��ǰ����ö��
    int32_t id;        ///< ��ǰ֧�ֵ��������Ե�id
}tos_pvr_audio_stream_info_t;/*the same as APP_PVR_LANG_INFO*/

typedef struct
{
    char language[TOS_PVR_MAX_LANGUAGE_CODE];    ///< ��ǰ֧�ֵ�subtitle�����б� /*!< ISO 639 3-letter language code (empty string if undefined) */
    MEMBER_LANGUAGE eLanguage;  ///<��ǰ����ö��
    int32_t id;      ///< ��ǰ֧�ֵ�subtitle���Ե�id
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
	unsigned char name[TOS_PVR_FILE_NAME];      ///< �����ļ�����
	unsigned char url[TOS_PVR_FILE_PATH];      ///< ���̹���·��
} tos_pvr_recording_file_info_t;

typedef struct
{
	unsigned char name[TOS_PVR_FILE_NAME];      ///< �����ļ�����
	unsigned char url[TOS_PVR_FILE_PATH];      ///< ���̹���·��
	int  channelNum;                            ///< Ƶ����
	unsigned char channelName[TOS_PVR_CHANNEL_NAME];  ///< Ƶ������
	unsigned char eventName[TOS_PVR_EVENT_NAME];  ///< �¼�����
	tos_pvr_time time;///< ¼��ʱ��
	int64_t size;                               ///< �ļ���С����byteΪ��λ
	int32_t duration;                           ///< ʱ������λ��
} tos_pvr_recording_info_t;     

typedef struct
{
	EN_TOS_PVR_RECORD_ID eRecordId;      ///< ¼��ͨ��ID,��Ϊ��չ˫ͨ��¼��Ԥ��
	fpi_bool bIsBackground;      ///< �Ƿ��̨���У���������ʱ�Ƿ��������Ƶfreeze
	fpi_bool bAutoExit;    ///< �طŹ�����û���㹻�Ļ����Ƿ������Զ��˳���ֱ�������������ӽ�ֱ���������Ԥ��
} tos_pvr_timeshift_start_params_t;                         

/**
@brief �жϴ����Ƿ���¼���ļ�����,�����жϴ����Ƿ����¼�Ƶ�PVR�ļ�
@param[in] path ���Ϊ�գ��м������Ѱ�Ҵ��̣���������Ӧ��ָ��·�������жϣ�������ڶ�����̣�Ӧ����Ҫ��ε���
@param[out] isExist �����Ƿ���¼���ļ���ָ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_is_record_file_exist(char *path,fpi_bool *isExist);

/**
@brief ɨ��ָ���Ĵ���·�������ڻ�ȡpvr¼�Ƶ��ļ�
@param[in] usbDiskPath ����·����pvr�ļ������Ϊ�գ��м������Ѱ�Ҵ��̣���������Ӧ��ָ��·�������жϣ�������ڶ�����̣�Ӧ����Ҫ��ε���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_scan_directory(char *usbDiskPath);

/**
@brief �ͷŴ���ɨ��������Դ����tos_pvr_scan_directory����ʹ��,���ô˽ӿں�ɨ�������ͷţ��˳�pvr listʱ���ã������ڴ�й¶
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_scan_resource_release(void);

/**
@brief ��ȡ¼�Ƶ��б�ĳ���
��Ҫɨ����ɺ��ڽ��л�ȡ�б��ȣ����δɨ�裬�򷵻�0.
���ɨ��N��Ŀ¼���򷵻�N��Ŀ¼���б��ܳ���
@param[out] value ��ȡ¼�Ƶ��б�ĳ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_recording_list_count(int32_t *value);

/**
@brief ��ȡָ����ʼλ��ָ��������¼���б�
�б�����ʽ���յ�ǰ����ӿڽ���
@param[in] startIndex ��ȡ¼�Ƶ��б����ʼλ��
@param[out] list ��ȡ¼�Ƶ��б�ָ��
@param[in/out] count in:������Ҫ��ȡ���б���
                     out:�����б��ʵ�ʳ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_recording_list(int32_t startIndex,tos_pvr_recording_file_info_t *list,uint32_t *count);

/**
@brief ����¼���ļ�������ʽ
@param[in] type ��ǰ¼���ļ�������ʽ��EN_TOS_PVR_FILE_SORT_TYPE:
                    E_ORDER_NAME
                    E_ORDER_DATE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_set_file_sort_order(EN_TOS_PVR_FILE_SORT_TYPE type);

/**
@brief ��ȡ¼���ļ�������ʽ
@param[out] type ��ǰ¼���ļ�������ʽָ�룬EN_TOS_PVR_FILE_SORT_TYPE:
                    E_ORDER_NAME
                    E_ORDER_DATE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_file_sort_order(EN_TOS_PVR_FILE_SORT_TYPE *type);

/**
@brief ��ȡָ��¼���ļ�����Ϣ
@param[in] url ¼���ļ��ĵ�ַ,��Ӧ��ȡ�б�ṹ��tos_pvr_recording_file_info_t��url����,utf8����
@param[out] value ��ȡ¼���ļ�����Ϣָ�룬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_recording_info(char *url, tos_pvr_recording_info_t *value);

/**
@brief ɾ��pvr��¼��ĳһ��
@param[in] url ¼�ƽ�Ŀ��ַָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_delete_recording(char *url);

/**
@brief ָ����Ŀ��ʼ¼�ƣ�һ��Ϊ��ǰ��Ŀ
@param[in] channelId ¼�ƽ�Ŀ��Ƶ��id,�����ٻ�̨ʱ�����뻻��̨���Ŀ����Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_start(uint32_t channelId);

/**
@brief ��ͣ��ǰ¼�ƽ�Ŀ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_pause(void);

/**
@brief �ָ���ͣ��¼�ƽ�Ŀ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_resume(void);

/**
@brief ֹͣ¼�ƽ�Ŀ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_stop(void);

/**
@brief �жϵ�ǰ�Ƿ���¼��
@param[out] value �жϵ�ǰ¼�Ƶ�״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_recording_state(fpi_bool *value);//��ȡ��ǰ¼����Ϣ���Ƿ��ṩ

/**
@brief ��ȡ��ǰ¼�Ƶ��ļ�URL
ͨ��URL�ҵ���Ӧ��¼����Ϣ
@param[out] url ¼�Ƶ��ļ���URLָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_current_recording_url(char *url);

/**
@brief ����ָ����¼���ļ�
���浱ǰ�����ļ�·����type����Ϣ��Ϊ����ѭ���߼���׼��
����֮ǰ��Ӧ����Ҫ�л���Դ��dtv
@param[in] url ¼���ļ��ĵ�ַ,��Ӧ��ȡ�б�ṹ��tos_pvr_recording_info_t��url����,utf8����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_file_start_play(char * url);

/**
@brief ֹͣ���ŵ�ǰ���ŵ�¼���ļ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_file_stop_play(void);

/**
@brief ���Ʋ��ŵĲ���
@param[in] motion ���ŵĶ�������ͣ���ָ����ţ�ֹͣ���ţ����������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_set_motion(EN_TOS_PVR_MOTION motion);

/**
@brief ��ȡ���Ʋ��ŵĲ���
@param[out] motion ���ŵĶ���ָ�룬��ͣ���ָ����ţ�ֹͣ���ţ����������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_current_motion(EN_TOS_PVR_MOTION *motion);

/**
@brief ���ò��ŵ�ʱ��λ��
����ָ��λ�ý��в��ţ������λ�ò��ڵ�ǰ���ŵ���Чʱ���ڣ���ֹ���� 
@param[in] seek ���ŵ�λ�ã���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_seek(int32_t seek);

/**
@brief ��ȡ��ǰ���ŵ�ʱ��λ��
@param[out] value ��ǰ���ŵ�ʱ��λ�ã���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_current_play_time(int32_t *value);

/**
@brief ��ȡ��ǰ���ŵ��ļ�URL��Ϣ
@param[out] url ��ǰ���ŵ��ļ�urlָ��,��ȡ�ļ���Ϣָ�룬�����ļ�·����size��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_file_url(char *url);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ���֧�ֵ������б�
@param[out] list ��ǰ���ŵ��ļ��������б���Ϣָ��,�������ԣ���id��Ϣ
@param[in/out] count in:������Ҫ��ȡ���б���
                     out:�����б��ʵ�ʳ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_audio_track_info(tos_pvr_audio_stream_info_t *list,int32_t *count);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ���֧�ֵ��������
@param[out] count ��ǰ���ŵ��ļ�֧�ֵ����������ָ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_audio_track_count(int32_t *count);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ�������id
@param[out] ���ص�ǰ���ŵ��ļ�������id
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_current_audio_track(int32_t *id);

/**
@brief ���õ�ǰ���ڲ���¼���ļ�������
@param[in] id ���õ�ǰ���ŵ��ļ�������,��Ӧtos_pvr_audio_stream_info_t������id
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_set_audio_track(int32_t id);

/**
@brief �򿪻�ر�subtitle
@param[in] bEnable �򿪻�ر�subtitle
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_enable_subtitle(fpi_bool bEnable);

/**
@brief ���õ�ǰ���ڲ���¼���ļ���subtitle�б���Ϣ
@param[out] list ��ǰ���ŵ��ļ���subtitle�б���Ϣָ��,�������ԣ���id��Ϣ
@param[in/out] count in:������Ҫ��ȡ���б���
                     out:�����б��ʵ�ʳ���ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_subtitle_info(tos_pvr_subtitle_stream_info_t* list,int32_t *count);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ���֧�ֵ�subtitle����
@param[out] count ��ǰ���ŵ��ļ�֧�ֵ�subtitle������ָ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_subtitle_count(int32_t *count);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ���subtitle id
@param[out] ���ص�ǰ���ŵ��ļ���subtitle id
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_current_subtitle(int32_t *id);

/**
@brief ���õ�ǰ���ڲ���¼���ļ���subtitle
@param[in] id ���õ�ǰ���ŵ��ļ���subtitle��id,��Ӧtos_pvr_subtitle_stream_info_t��id
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_set_subtitle(int32_t id);

/**
@brief ��ʼtimeshiftʱ�Ʋ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_start(void);

/**
@brief ��ʼtimeshiftʱ�Ʋ���
@param[in] pstStartParams timeshift�Ŀ�ʼ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_start_v2(tos_pvr_timeshift_start_params_t* pstStartParams);

/**
@brief ֹͣtimeshiftʱ�Ʋ���
�˳��������Ҫ�������ŵ�ǰDtv��Ŀ����ҪӦ�õ��ò��Žӿ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_stop(void);

/**
@brief ��ȡʱ���ļ��Ŀ�ʼʱ�䣬��λΪ��
�����̿ռ�д��ʱ����ע������ݻὫ֮ǰ�����ݸ��ǵ������ʱ���ļ�֧�ֵĲ��ſ�ʼʱ���ڲ��ϸ��±仯
@param[out] u32TimeInSeconds ʱ�Ʋ����ļ�����ʼʱ��ָ�룬��λ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_get_start_time(uint32_t* u32TimeInSeconds);

/**
@brief ʱ�ƵĴ����ļ��Ƿ��ʼ��
�����ʼ���󣬻���timeshift�ļ����ڣ�����δ���г�ʼ�������������ʼ������
@param[out] value ʱ�ƵĴ����ļ��Ƿ��ʼ��״̬��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_is_file_exist(fpi_bool *value);

/**
@brief ��ʼ��ʱ��ʹ�õĴ��̴�С��Ӧ��ʹ�ã�����ѡ���ļ��ռ�Ĵ�С,MB
@param[in] u32SizeInMB ʱ�ƵĴ����ļ��ռ��С
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_init_file(uint32_t u32SizeInMB);

/**
@brief ��ȡ��ʼ��ʱ��ʹ�õĴ����ļ��Ľ���
@param[out] u8Percent ʱ�ƵĴ����ļ���ʼ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_timeshift_file_init_progress(uint8_t* u8Percent);

/**
@brief ʱ�Ƶ�д���̲����ٶȲ���
��һ���̲߳���
@param[in] test ʱ�Ƶ�д���̲����ٶȲ���,��ʼ���������ȡ�ֹͣ
EN_FPI_TIMESHIFT_WRITE_SPEED_TEST��
	E_TIMESHIFT_WRITE_SPEED_TEST_START,
	E_TIMESHIFT_WRITE_SPEED_PROGRESS,
	E_TIMESHIFT_WRITE_SPEED_STOP,
  E_TIMESHIFT_WRITE_SPEED_TEST_NUM
@param[out] u8Percent ʱ�Ƶ�д���̲����ٶȲ����Ĳ��Խ���ָ�룬����״̬Ϊ��ʼ��ֹͣʱ�����������壬����״̬ΪPROGRESSʱ�����ز��ԵĽ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_timeshift_write_speed_test(EN_TOS_TIMESHIFT_WRITE_SPEED_TEST test,uint8_t* u8Percent);

/**
@brief ��ȡʱ��д�����ļ����ٶ�
@param[out] u32SpeedInKBps ʱ��д�����ļ����ٶ�ָ�룬kbps.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_timeshift_speed(uint32_t* u32SpeedInKBps);

/**
@brief ��ȡ���̵�ʣ��ռ�״̬���жϴ����Ƿ���ʣ��ռ�����¼�ƻ���ʱ��
¼�ƺ�timeshiftʣ����̿ռ�,¼����Ҫ��ʮM��ʱ����Ҫ512M
@param[in] type����ǰ����¼�ƻ���ʱ��״̬
@param[out] value �жϴ����Ƿ���ʣ��ռ��״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_free_space_status(EN_TOS_PVR_TYPE type,fpi_bool *value);

/**
@brief ��ȡ���̵�ʣ��ռ�Mb
����Ŀ��������ʹ�ã�Ӧ�����Լ�ʵ�ִ˹��ܣ������˽ӿڽ�����
@param[out] u32SizeInMB ������ʣ��ռ��С��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_disk_free_space(uint32_t* u32SizeInMB);

/**
@brief ��ȡ��ǰ�Ĵ�����Ϣ
@param[out] pstrDevName�豸����·��ָ��
@param[out] pstrDiskName��������ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_disk_info(char* pstrDevName,char* pstrDiskName);

/**
@brief ѡ�������Ϣ����������̹���ʱѡ�����
@param[in] pstrDevName�豸����·��
@param[in] pstrDiskName��������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_select_disk(char* pstrDevName,char* pstrDiskName);

/**
@brief ����ָ���Ĵ��̹���·�������ƣ����д��̸�ʽ��
��������Ϊ��ʱ����ʾ�м������Ѱ��·����ʽ��
����Ŀ��������ʹ�ã�Ӧ�����Լ�ʵ�ִ˹��ܣ������˽ӿڽ�����
@param[in] pstrDevDiskName ��������
@param[in] strMountPath ����·��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_disk_format(char *pstrDevDiskName,char *strMountPath);

/**
@brief ���̸�ʽ������
����Ŀ��������ʹ�ã�Ӧ�����Լ�ʵ�ִ˹��ܣ������˽ӿڽ�����
@param[out] u8Percent ���̸�ʽ������ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_get_formating_progress(uint8_t* u8Percent);

/**
@brief ������һ������һ���ļ�
�����û����õĲ��ŷ�ʽ��ѭ�����Ż�˳�򲥷ŵȽ�����һ������һ���ļ��Ĳ���
@param[in] play��ʾ��һ������һ���ļ��Ĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_file_play_by_mode(EN_TOS_PVR_PLAY play);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ���ѭ������ģʽ
@param[out] value ��ǰ���ŵ�ѭ��ģʽָ�룬EN_FPI_PVR_PLAY_REPEAT_MODE
 																				E_PLAY_MODE_NORMAL = 0,
                                        E_PLAY_MODE_RANDOM,
                                        E_PLAY_MODE_REPEAT_ALL,
                                        E_PLAY_MODE_REPEAT_ONE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_repeat_mode(EN_TOS_PVR_PLAY_REPEAT_MODE *value);

/**
@brief ���õ�ǰ���ڲ���¼���ļ���ѭ������ģʽ
@param[in] repeatmode ��ǰ���ŵ�ѭ��ģʽ��EN_FPI_PVR_PLAY_REPEAT_MODE
 																				E_PLAY_MODE_NORMAL = 0,
                                        E_PLAY_MODE_RANDOM,
                                        E_PLAY_MODE_REPEAT_ALL,
                                        E_PLAY_MODE_REPEAT_ONE
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_set_repeat_mode(EN_TOS_PVR_PLAY_REPEAT_MODE repeatmode);

/**
@brief ��ȡ��ǰ���ڲ���¼���ļ������б�λ��
@param[out] value ��ǰ���ŵ��ļ������б�λ��ָ�룬����ָȫ����¼���ļ��б���λ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_play_get_file_position(int32_t *value);

/**
@brief ����ָ�����ļ���ַ���Ե�ǰ���Ž�Ŀ���ڵ�TS��������·¼��
������Ϊ��ʱ����ʾ�м�����ж����ļ���ַ
@param[in] pstrFileName ¼���ļ��ĵ�ַ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_ts_start(char *pstrFileName);

/**
@brief ֹͣ¼��TS��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_pvr_record_ts_stop(void);

#ifdef __cplusplus
}
#endif
/** @} */
#endif 
