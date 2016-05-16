/**@defgroup tos_mp_avformat
@{

@brief ý�岥��������Ϣ����ģ��,������Ƶ������Ƶ������Ļ����;���ڹ�������������Ƶ����

@history 2014/12/18 ����
@history 2014/12/25 �����������,ȥ��������Ƶ����ؽӿ�֮�����������Ƶ���ýӿ�,ͳһ�ŵ�ATV����Ƶ����ģ�鴦��
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


#define TOS_MP_STRING_LENGTH_8          8       ///< �ַ�������ֵ8
#define TOS_MP_STRING_LENGTH_128        128     ///< �ַ�������ֵ128

/**
@brief ������������ö��
*/
typedef enum {
    EN_FPI_MP_CONTAINER_TYPE_MKV,               ///< MKV��������
    EN_FPI_MP_CONTAINER_TYPE_AVI                ///< AVI��������
}FPI_MP_CONTAINER_TYPE_E;

/**
@brief ������Ļ����ö��
*/
typedef enum {
    EN_FPI_MP_SUBTITLE_TYPE_CC,                 ///< CloseCaption������Ļ
    EN_FPI_MP_SUBTITLE_TYPE_SUBTITLE            ///< Subtitle������Ļ
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
@brief ����ý��sample��������Ϣ
*/
typedef struct {
    uint32_t track_id;                          ///< track id      
    uint32_t  duration;                         ///< sample ��duration             
    uint32_t  size;                             ///< sample �Ĵ�С 
    uint32_t  composition_time_offset;          ///< time offset
    uint32_t  time_scale;                       ///< time scale
}FPI_MP_Sample_S;


/**
@brief ����ý���ļ�������Ϣ�ṹ��
*/
typedef struct {
    int size;                                               ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_ContainerInfo_S)
    int id;                                                 ///< MSE & EME ���buffer id���������playerid
    FPI_MP_CONTAINER_TYPE_E type;                           ///< ��������
    bool seekable;                                          ///< �Ƿ�֧�ֶ�λ����,true��ʾ֧��,false��ʾ��֧��
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< ����
    unsigned char rating[TOS_MP_STRING_LENGTH_8];           ///< �ȼ�

    uint32_t  sample_count;                                 ///< sample ��Ŀ
    FPI_MP_Sample_S *samples;                               ///< sample��������Ϣ��ʹ�����Ҫ�ǵ�free
}FPI_MP_ContainerInfo_S;


/**
@brief ������Ƶ����Ϣ�ṹ��
*/
typedef struct {
    int size;                                               ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_AudioStream_S)
    int id;                                                 ///< ��Ƶ��IDֵ
    unsigned char codec[TOS_MP_STRING_LENGTH_8];            ///< ��������
    unsigned char language[TOS_MP_STRING_LENGTH_8];         ///< ISO 639 3-letter language code (empty string if undefined)
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< ��Ƶ������
    int channelCount;                                       ///< ��������
}FPI_MP_AudioStream_S;

/**
@brief ������Ƶ����Ϣ�ṹ��
*/
typedef struct {
    int size;                                               ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_VideoStream_S)
    int id;                                                 ///< ��Ƶ��IDֵ
    unsigned int width;
    unsigned int height;
    unsigned char codec[TOS_MP_STRING_LENGTH_8];            ///< ��������
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< ��Ƶ������
}FPI_MP_VideoStream_S;

/**
@brief ������Ļ��Ϣ�ṹ��
*/
typedef struct {
    int size;                                               ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_SubtitleInfo_S)
    FPI_MP_SUBTITLE_TYPE_E type;                            ///< ��Ļ����
    unsigned char language[TOS_MP_STRING_LENGTH_8];         ///< ISO 639 3-letter language code (empty string if undefined)
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< ��Ļ����
    unsigned char displayname[TOS_MP_STRING_LENGTH_8*2];    ///< ��Ļ����
}FPI_MP_SubtitleInfo_S;

/**
@brief �����½���Ϣ�ṹ��
*/
typedef struct {
    int id;                                                 ///< �½�idֵ
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< �½�����
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
@brief ��ȡ���ڲ��ŵ�ý���������Ϣ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[out] containerInfo �������,��������Ϣ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_container_info(unsigned int playerId, FPI_MP_ContainerInfo_S* containerInfo);


/**
@brief ��ȡ��ǰ���ŵ�ý�����Ƶ������

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý�����Ƶ������
*/
int tos_mp_get_audio_stream_count(unsigned int playerId);


/**
@brief ��ȡָ����������Ƶ����Ϣ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index ��Ƶ��������.
@param[out] audioStream �������,��Ƶ������Ϣ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_audio_stream(unsigned int playerId, int index, FPI_MP_AudioStream_S* audioStream);


/**
@brief ���ò���ָ����������Ƶ��

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index ��Ƶ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_audio_stream(unsigned int playerId, int index);


/**
@brief ��ȡ��ǰ���ŵ�ý�����Ƶ������

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý�����Ƶ������
*/
int tos_mp_get_current_audio_stream(unsigned int playerId);


/**
@brief ��ȡ��ǰ����������Ƶ������

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý�����Ƶ������
*/
int tos_mp_get_video_stream_count(unsigned int playerId);

/**
@brief ��ȡָ����������Ƶ����Ϣ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index ��Ƶ��������.
@param[out] videoStream �������,��Ƶ������Ϣ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_video_stream(unsigned int playerId, int index, FPI_MP_VideoStream_S* videoStream);


/**
@brief ���������Ļ��URI

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] uri �����Ļ�ļ���·��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_subtitle_uri(unsigned int playerId, const char* uri);


/**
@brief ��ȡ��ǰ���ŵ�ý���subtitle����

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý���subtitle����
*/
int tos_mp_get_subtitle_count(unsigned int playerId);


/**
@brief ��ȡָ��������subtitle��Ϣ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index subtitle������.
@param[out] subtitleInfo �������,subtitle����Ϣ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_subtitle(unsigned int playerId, int index, FPI_MP_SubtitleInfo_S* subtitleInfo);


/**
@brief ���ò���ָ��������subtitle

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index subtitle������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_subtitle(unsigned int playerId, int index);


/**
@brief ��ȡ��ǰ���ŵ�ý���subtitle����

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý���subtitle����
*/
int tos_mp_get_current_subtitle(unsigned int playerId);


/**
@brief ������Ļ�Ƿ���ʾ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] visible true��ʾ��ʾ��Ļ;false��ʾ������Ļ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_subtitle_visible(unsigned int playerId, bool visible);



/**
@brief ��ȡ��ǰ���ŵ�ý����½ڸ���

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý����½ڸ���
*/
int tos_mp_get_chapter_count(unsigned int playerId);


/**
@brief ��ȡָ���������½���Ϣ

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index �½ڵ�����.
@param[out] chapterInfo �������,�½ڵ���Ϣ.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_chapter(unsigned int playerId, int index, FPI_MP_ChapterInfo_S* chapterInfo);


/**
@brief ���ò���ָ���������½�

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] index �½ڵ�����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_chapter(unsigned int playerId, int index);


/**
@brief ��ȡ��ǰ���ŵ�ý����½�����

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return ��ǰ���ڲ��ŵ�ý����½�����
*/
int tos_mp_get_current_chapter(unsigned int playerId);



/**
@brief ����ý��INIT DATA ����ö��
*/
typedef enum {
    EN_FPI_MP_CENC,               ///<CENC
    EN_FPI_MP_KEYID,                ///< KEYID
    EN_FPI_MP_WEBM,                ///< WEBM
}FPI_MP_INIT_DATA_TYPE_E;

/**
@brief ����ý��INIT DATA ����ö��
*/
typedef enum {
    EN_FPI_MP_CLEARKEY,               ///<CLEARKEY
    EN_FPI_MP_PLAYREADY,              ///< PLAYREADY
    EN_FPI_MP_WIDEVINE,               ///< WIDEVINE
}FPI_MP_DRM_TYPE_E;


/**
@brief ��ȡý��INIT DATA

@param[in] playerId ý�岥����ID�������MSE&EME����SourceBufferID
@param[in] type INIT data ����
@param[in] size  INIT data ��С
@param[in] data INIT data

@return �ɹ�����: 0��ʧ�ܷ���: -1
*/
int tos_mp_get_init_data(unsigned int playerId, FPI_MP_INIT_DATA_TYPE_E *init_type, unsigned int *size, void** data);

/**
@brief ����drm������Ϣ

@param[in] playerId ý�岥����ID, �����MSE&EME����SourceBufferID
@param[in] type INIT data ����
@param[in] ��������
@param[in] ���ݴ�С

@return �ɹ�����: 0��ʧ�ܷ���: -1
*/
int tos_mp_update_drm(unsigned int playerId, FPI_MP_DRM_TYPE_E drm, void *data, unsigned int len);

/**
@brief �����½���Ϣ�ṹ��
*/
typedef struct {
    int id;                                                 ///< �½�idֵ
    unsigned char name[TOS_MP_STRING_LENGTH_128];           ///< �½�����
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
@brief ��ѯ��ǰ�ļ���TITLE����
@note
@return ��ǰ���ڲ��ŵ�ý���TITLE����
*/
int tos_mp_get_title_count(unsigned int playerId);

/**
@brief �л�TITLE  ����
@note 

@param[in] title 
		
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_title(unsigned int playerId, int32_t title, int64_t time);


/**
@brief ��ѯ��ǰ���ڲ��ŵ��ǵڼ���TITLE
@note
@param[out] titleinfo
		    ���ݽṹ:
				int titleid; TITLE ID
				char titleName[MM_TITLE_LENGTH]; TITLE������
				char titleLawRating[MM_LAW_RATING_LENGTH];TITLE�ķּ���Ϣ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_title(unsigned int playerId, FPI_MP_TitleInfo_S * titleinfo);

/**
@brief ����ͼƬ����Ч��

@param[in] effect ͼƬ����Ч������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_id3info(unsigned int playerId, char* filesrc, FPI_MP_ID3_S* info);


/**
@brief ��ȡָ��ý���ļ�ĳ��ʱ������Ƶ����ͼ
@note
@param[in] width  ͼƬ���
@param[in] height ͼƬ�߶�
@param[in] time ʱ���
@param[in]src_url �򿪵�ͼƬ·��
@param[out]thumbnail_url �����ͼƬ·��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_create_thumbnail(unsigned int playerId, char* filesrc, FPI_MP_Thunmnail_S* info);


/**
@brief ���divx�ļ���״̬

@note

@param[out] state
		DRM_DIVX_ACTIVATE_FIRST_TIME,  --  �״μ���
             DRM_DIVX_ACTIVATED_STATE,      --   �Ѽ���
             DRM_DIVX_DEACTIVATED_STATE,    --  δ����

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_divx_active_state(unsigned int playerId, FPI_MP_DIVXDRM_ACTIVITYSTATE_E *state);

/**
@brief ��ȡdivx��ע����

@note

@param[out] buf ע��������
@param[in] buf_size ע���볤��
		
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_divx_regcode(unsigned int playerId, char *buf, uint32_t buf_size);

/**
@brief ��ȡdivx��ע����

@note

@param[out] buf ע��������
@param[in] buf_size ע���볤��
		
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_divx_deactivecode(unsigned int playerId, char *buf, uint32_t buf_size);

/**
@brief ��ȡdivx������Ϣ
@note

@param[out] info
		    ���ݽṹ:
		       int  DRMflag;                                  is drm file
                    FPI_MP_DIVXDRM_CP_TYPE_E   drmType;           drm protected mode
                    FPI_MP_DIVXDRM_CP_STATUS_E drmStatus;       drm protected status
                    unsigned int      numRentalPlays;        used times
                    unsigned int      TotalNumPlays;         total times
                    unsigned char     isAudioProtected;  audio protected status
		
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_divx_protectinfo(unsigned int playerId, FPI_MP_DivxDRM_CopyProtectionInfo_S *info);

/**
@brief ��ȡָ����Ƶ�ļ���cover
@note
@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] filepath ��Ƶ�ļ���·��
@param[out]cover_path ��Ƶ�ļ�cover�����·��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
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
@brief ����DRM��USER CONFIG����,����user agent �� custom data
@note
@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] type user config ����
@param[in] data,user config�ľ�������
@param[in] data_size,user config�ľ������ݵĳ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_user_config(unsigned int playerId, FPI_MP_user_config_type type, char *data, uint32_t data_size);


/**
@brief ����������ڴ�С
@note
@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] x, ������ڵ�X����
@param[in] y, ������ڵ�Y����
@param[in] width, ������ڵĳ�
@param[in] height, ������ڵĸ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_output_window(unsigned int playerId, int x, int y, int width, int height);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
