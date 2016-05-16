/**@defgroup ���ֵ���Ƶ������ģ��
@{

@brief ���ڿ��Ƶ����в�����ز���

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
@brief ���岥�����ص��¼�ö��
*/
typedef enum {
    EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_SUCCESS,     ///< ��Ƶ���ųɹ�,��ʾ��ʼ��Ⱦ��һ֡,������ɺ�, �ײ���Ҫһ����ʱ�����жϵ�ǰ��Ŀ�Ĳ��Ž����
                                                  ///<  ����Ϣ����ǰ, ��Ƶ״̬�ǲ�ȷ����(������Ƶ�ȳ�����, ��״̬�ӳ�), Ӧ�ò�
                                                  ///<  ���������, ������һ��ʱ��Ĺ��ȡ�
                                                  ///<  ��EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_SUCCESS����EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_FAILEDһ����������һ��
    EN_TOS_DTV_PLAY_EVENT_VIDEO_PLAY_FAILED,      ///< ��Ƶ����ʧ��,��ʱcode��ʾʧ��ԭ��,ȡֵΪFPI_MP_PLAY_FAILED_REASON_E
    EN_TOS_DTV_PLAY_EVENT_AUDIO_PLAY_SUCCESS,     ///< ��Ƶ���ųɹ�
    EN_TOS_DTV_PLAY_EVENT_AUDIO_PLAY_FAILED,      ///< ��Ƶ����ʧ��,��ʱcode��ʾʧ��ԭ��,ȡֵΪFPI_MP_PLAY_FAILED_REASON_E
    EN_TOS_DTV_PLAY_EVENT_CHANNEL_UPDATE          ///< Ƶ����Ҫ����
}EN_TOS_DTV_PLAY_CB_EVENT_E;


/**
@brief ���岥��ʧ��ԭ��ö��
*/
typedef enum {
    EN_TOS_DTV_PLAY_REASON_UNKNOWN,               ///< δ֪ԭ��
    EN_TOS_DTV_PLAY_REASON_CONNECT_FAILED,        ///< ��Ƶʧ��
    EN_TOS_DTV_PLAY_REASON_FORMAT_NOT_SUPPORT,    ///< ��Ƶ/��Ƶ��ʽ��֧��
    EN_TOS_DTV_PLAY_REASON_UNAUTHORIZED,          ///< δ��Ȩ
    EN_TOS_DTV_PLAY_REASON_CHANNEL_NOT_EXIST,     ///< ��ӦƵ�����޴˽�Ŀ������û���ṩ����ƵPID
    EN_TOS_DTV_PLAY_REASON_CHANNEL_LOCKED,        ///< ��Ŀ���˽�Ŀ��
    EN_TOS_DTV_PLAY_REASON_PARENTAL_LOCKED,       ///< ��Ŀ���˸�ĸ��
    EN_TOS_DTV_PLAY_REASON_NO_VIDEO,              ///< ��Ŀû����Ƶ
    EN_TOS_DTV_PLAY_REASON_NO_AUDIO               ///< ��Ŀû����Ƶ
}EN_TOS_DTV_PLAY_FAILED_REASON_E;

typedef enum
{
    E_DTV_PLAY_IDLE,        ///< ֹͣ����״̬
    E_DTV_PLAY_PLAYING      ///< ����״̬
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

    E_DTV_SS_RUNNING_STATUS_NOT_RUNNING, //add by lwf 2013.11.28 ��ͣ, sdt �����нӲ���״̬��û�в��ţ���Ŀͣ��
    E_DTV_SS_MAX
} EN_TOS_DTV_SS_MODE;

typedef enum {
        EN_TOS_DTV_PLAY_ID_MAIN,               //������
        EN_TOS_DTV_PLAY_ID_SUB,        //�Ӵ���
		EN_TOS_DTV_PLAY_AV_SYNC_TIMEOUT,
        EN_TOS_DTV_PLAY_ID_MAX           
}EN_TOS_DTV_PLAY_ID_E;

typedef enum {
        EN_TOS_DTV_PLAY_STOP_TYPE_ONLY_AUDIO,               //ֻͣ��ǰaudio
        EN_TOS_DTV_PLAY_STOP_TYPE_ONLY_VIDEO,        //ֻͣvideo
        EN_TOS_DTV_PLAY_STOP_TYPE_ALL,    //��ǰ����Ƶ��ͣ
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
	int audioPid; // 0x1fff ���ԣ�������audio�Ҳ�֮ͣǰ�ڲ���audio
	fpi_audio_type_t  audioType;
	int videoPid;// 0x1fff ���ԣ�������video�Ҳ�֮ͣǰ�ڲ���video	
	fpi_video_type_t videoType;   
        int         pcr_pid;
} tos_channel_play_stream_info;


/**
@brief ����ָ���Ľ�Ŀ,�˽ӿ�Ϊ�첽����,���Ź����е���Ϣͨ���ص������׳�

@param[in] channelId Ҫ���ŵĽ�Ŀ��Ψһ��ʶ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play(uint32_t channelId);


/** 
@brief ͨ��PID����TV�е�ĳ�� stream.����ѡ���audio

@param[in] play_id ,p_stream_info Ŀ������PID��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_channel_play_stream(EN_TOS_DTV_PLAY_ID_E play_id ,tos_channel_play_stream_info *p_stream_info);

/** 
@brief ��ȡ��ǰTV���ڲ��ŵ�stream component ����Ϣ������pid��stream type����Ϣ

@param[in] play_id��type
@param[out] p_stream_info :
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_channel_play_get_current_stream_info(EN_TOS_DTV_PLAY_ID_E play_id ,EN_TOS_DTV_PLAY_TYPE_E type,tos_channel_stream_info *p_stream_info);

/** 
@brief ֹͣ��ǰ���ڲ��ŵ�stream

@param[in] play_id,stop_type
@param[out] ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_channel_play_stop_stream(EN_TOS_DTV_PLAY_ID_E  play_id,EN_TOS_DTV_PLAY_STOP_TYPE_E stop_type);

/**
@brief ��ȡ��ǰ���ŵĽ�Ŀ��Ϣ

@param[out] play_info ��ǰ���ŵĽ�Ŀ����Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_get_current_channel_info(tos_dtv_play_info_t *play_info);

/**
@brief ��ȡ��ǰ���Ž�Ŀ��channelId
@param[out] channelId ��ǰ�����ŵĽ�Ŀ��Ψһ��ʶ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_get_current_channel_id(uint32_t *channelId);

/**
@brief �������ŵ�ǰ�ļ���Ƶ��(������Ŀ���͸�ĸ��)

ֻҪ�����˴˽ӿڣ�������(������Ŀ���͸�ĸ��)�����⿪

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_unlock();

/**
@brief ������ǰ���ڲ��ŵĽ�Ŀ��������洢���ݿ⣩���ر�����Ƶ

ֻ���ڵ�ǰ���ڲ��ŵĽ�Ŀ�����������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_relock();

/**
@brief ���Ƽ�ʹ�á��������ŵ�ǰ�ļ���Ƶ������������ǰ��Ƶ��

@param[in] locked   false��ʾֻҪ�����˴˽ӿڣ�������(������Ŀ���͸�ĸ��)�����⿪
                    true��ʾ������ǰ���ڲ��ŵĽ�Ŀ��������洢���ݿ⣩���ر�����Ƶ

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_set_lock_status(fpi_bool locked);

/**
@brief ֹͣ���ŵ�ǰ��Ŀ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_stop();

/**
@brief ��ȡ��ǰ��Ŀ�Ĳ���״̬
��Ŀδ���š�������
@param[out] status  ���ص�ǰ��Ŀ����״̬��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_get_status(EN_FPI_DTV_PLAY_STATE *status);

/**
@brief ��ȡ��ǰ��Ŀ�Ĳ���״̬srceen_mode_info

@param[out] mode  ���ص�ǰ��Ŀ����״̬��srceen_mode_info
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_get_srceen_mode_info(EN_TOS_DTV_SS_MODE *mode);

/**
@brief Ƶ��ģ�鴦��ص�
@param[in] eventType �������¼�����ö��@see EN_TOS_DTV_PLAY_CB_EVENT_E
@param[in] code �������¼���ֵ,����eventType���Ͳ�ͬ�в�ͬ�Ķ���,��ϸ��FPI_DTV_PLAY_CB_EVENT_E��ÿ�����͵Ķ���˵��
@param[in] data �������¼���������,����eventType���Ͳ�ͬ�в�ͬ�Ķ���,��ϸ��FPI_DTV_PLAY_CB_EVENT_E��ÿ�����͵Ķ���˵��
@param[in] userdata Ϊ�û�ע�����ݣ��ص�ʱԭ������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
typedef int32_t (*tos_dtv_channel_callback)(EN_TOS_DTV_PLAY_CB_EVENT_E eventType, int code, int data, void* userdata);

/**
@brief ���Dtv����ģ�鴦��ص�,���ƽ�ʹ��
�����ŵ�״̬�����仯ʱ���м�������Ӧ��ע��ı��ӿ���������Ӧ�Ĳ����Ĺ���.

@param[in] callback ���Żص�����ָ��
@param[in] userdata �û�����,ע��˻ص�ʱ��userdata����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_channel_play_add_callback(tos_dtv_channel_callback callback, void* userdata);


/**
@brief ɾ��DTV����ģ��ص�����,���ƽ�ʹ��

@param[in] callback Dtv���Żص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_remove_callback(tos_dtv_channel_callback callback);

/**
@brief ����DTV ��Ŀ���Ÿ��¿���״̬,���ƽ�ʹ��

@param[in] flag DTV ��Ŀ���Ÿ��¿��أ�fpi_false : �ر�    fpi_true : ��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_set_channel_play_update_status(fpi_bool flag);


/**
@brief ��ȡDTV ��Ŀ���Ÿ��¿���״̬

@param[in] ��

@return ����DTV ��Ŀ���Ÿ��¿���״̬
*/
fpi_bool tos_dtv_get_channel_play_update_status(void);

/*
@brief ��δʵ��
@param[in] ��
@return 
*/
fpi_error tos_channel_play_set_flag(EN_TOS_DTV_PLAY_ID_E  id,int *param0,int *param1);


/**
@brief ��δʵ��,����ָ���Ľ�Ŀ,�˽ӿ�Ϊ�첽����,���Ź����е���Ϣͨ���ص������׳�
@param[in] info Ҫ���ŵĽ�Ŀ��Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_channel_play_delivery(const tos_dtv_play_info_t *info);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
