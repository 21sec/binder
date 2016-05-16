/**@defgroup tos_mp_player
@{

@brief ý�岥����ģ��,���ڿ��Ʋ��Ÿ���ý��Դ,�ݲ�����PIP

Ŀǰ֧�ֵ�ý��Դ���Ͱ���:
 - ����ý��: ��http://xxx��
 - ����ý��: ��file:///xxx��.

@code ����ʹ�ó���ʾ��
//��������VOD
tos_mp_set_datasource(x,"http://xxx");
tos_mp_prepare(x);
tos_mp_play(x);

//�Ӳ�������VOD��Ӧ������
//���ͷŶ�ý�岥����
tos_mp_stop(x);
tos_mp_release(x);

//�л�USB�豸�е�ӰƬ
tos_mp_stop(x);
tos_mp_set_datasource(x,"file:///xxx");
tos_mp_prepare(x);
tos_mp_play(x);
@endcode

������״̬�����£�
<img src="doc-files/mediaplayer.pdf">

@history 2014/12/17 ����
@history 2014/12/25 ������������޸�,���PREPARING��PLAYBACK_COMPLETED����״̬
*/

#ifndef __TOS_MP_PLAYER_H__
#define __TOS_MP_PLAYER_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
@brief ���岥����״̬ö��
*/
typedef enum {
    EN_FPI_MP_STATE_IDLE,               ///< ��ʼ״̬
    EN_FPI_MP_STATE_PREPARING,          ///< ׼����״̬
    EN_FPI_MP_STATE_PREPARED,           ///< ׼������״̬
    EN_FPI_MP_STATE_STARTED,            ///< ��ʼ״̬
    EN_FPI_MP_STATE_PAUSED,             ///< ��ͣ״̬
    EN_FPI_MP_STATE_TRICKMODE,          ///< �������״̬
    EN_FPI_MP_STATE_PLAYBACK_COMPLETED  ///< �������״̬
}FPI_MP_STATE_E;


/**
@brief ���岥�����ص��¼�ö��
*/
typedef enum {
    EN_FPI_MP_EVENT_BUFFERING_UPDATE,       ///< ����ٷֱȱ仯,��ʱcode��ʾ�Ѿ������˵İٷֱ�,ȡֵ0~100
    EN_FPI_MP_EVENT_BUFFERING_START,        ///< ��ͣ����,��ʼ��������
    EN_FPI_MP_EVENT_BUFFERING_END,          ///< ���嵽���㹻������,��ʼ���²���
    EN_FPI_MP_EVENT_PREPARED_COMPLETED,     ///< ����������PREPARED״̬����ʼ���ŵ�ʱ�򴥷�
    EN_FPI_MP_EVENT_VIDEO_PLAY_SUCCESS,     ///< ��Ƶ���ųɹ�,��ʾ��ʼ��Ⱦ��һ֡
    EN_FPI_MP_EVENT_VIDEO_PLAY_FAILED,      ///< ��Ƶ����ʧ��,��ʱcode��ʾʧ��ԭ��,ȡֵΪFPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_AUDIO_PLAY_SUCCESS,     ///< ��Ƶ���ųɹ�
    EN_FPI_MP_EVENT_AUDIO_PLAY_FAILED,      ///< ��Ƶ����ʧ��,��ʱcode��ʾʧ��ԭ��,ȡֵΪFPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_SEEK_COMPLETED,         ///< ��λ���Ų�����ɺ󴥷�
    EN_FPI_MP_EVENT_PAUSE_COMPLETED,        ///< ��ͣ���Ų�����ɺ󴥷�
    EN_FPI_MP_EVENT_RATE_CHANGED,           ///< ���������ʷ����仯,��ʱcode��ʾ�µ�����
    EN_FPI_MP_EVENT_REWIND_TO_HEAD,         ///< ���˵���ʼ��
    EN_FPI_MP_EVENT_FORWARD_TO_END,         ///< �������β
    EN_FPI_MP_EVENT_PLAY_TO_END,            ///< �������ŵ���β
    EN_FPI_MP_EVENT_SERVER_DIED,            ///< ������Դ����������ʧ��,��ʱcode��ʾʧ��ԭ��,ȡֵΪFPI_MP_PLAY_FAILED_REASON_E
    EN_FPI_MP_EVENT_NOT_SEEKABLE,           ///< ý�岻֧��seek,����ֱ����
    EN_FPI_MP_EVENT_NOT_CHANGE_RATE,        ///< ý�岻֧�ֿ������
    EN_FPI_MP_EVENT_FIND_AUDIO_STREAM,      ///< ��⵽��Ƶ����Ϣ,������Ϣͨ��fpi_mp_avformat.h�е���ؽӿ�����ȡ
    EN_FPI_MP_EVENT_FIND_VIDEO_STREAM,      ///< ��⵽��Ƶ����Ϣ,������Ϣͨ��fpi_mp_avformat.h�е���ؽӿ�����ȡ
    EN_FPI_MP_EVENT_FIND_SUBTITLE,          ///< ��⵽��Ļ��Ϣ,������Ϣͨ��fpi_mp_avformat.h�е���ؽӿ�����ȡ
    EN_FPI_MP_EVENT_TIME_UPDATE,            ///< ����ʱ�����,ÿ�뷢��һ��,��ʱcode��ʾ�������ʼ����ʱ���ƫ��,��λ�Ǻ���
    EN_FPI_MP_EVENT_STOP_COMPLETED,         ///< ֹͣ���ųɹ�
    EN_FPI_MP_EVENT_RELEASE_COMPLETED,      ///< �ͷŲ������ɹ�
    EN_FPI_MP_EVENT_MEDIA_PARSE,            ///< ý����Ϣ����
    EN_FPI_MP_EVENT_MEDIA_REMOVE,           ///< ý����Ϣ�Ƴ�
    EN_FPI_MP_EVENT_VIDEO_IN,               ///<��Ƶ���ſ�ʼ����ʾ���Կ���
    EN_FPI_MP_EVENT_VIDEO_OUT,              ///<��Ƶ���Ž�������ʾ���Թػ�
    EN_FPI_MP_EVENT_AUDIO_MUTE,             ///<��Ƶ���Ž�������ʾ���Թ�����
    EN_FPI_MP_EVENT_AUDIO_UNMUTE,           ///<��Ƶ���ſ�ʼ����ʾ���Կ�����
    EN_FPI_MP_EVENT_AV_SYNC_DONE,
    EN_FPI_MP_EVENT_HDCP_OK,                ///<HDCP��֤�ɹ�
    EN_FPI_MP_EVENT_HDCP_FAIURE,            ///<HDCP��֤ʧ��
    EN_FPI_MP_EVENT_HDCP_NEED,              ///<��ҪHDCP��֤
    EN_FPI_MP_EVENT_THUMBNAIL_CREATE,       ///<����ͼ�������
}FPI_MP_CB_EVENT_E;


/**
@brief ���岥��ʧ��ԭ��ö��
*/
typedef enum {
    EN_FPI_MP_REASON_UNKNOWN,               ///< δ֪ԭ��
    EN_FPI_MP_REASON_CONNECT_FAILED,        ///< ��������Դʧ��
    EN_FPI_MP_REASON_FORMAT_NOT_SUPPORT,    ///< ��Ƶ/��Ƶ��ʽ��֧��
    EN_FPI_MP_REASON_UNAUTHORIZED,          ///< δ��Ȩ
	EN_FPI_MP_REASON_EXPIRED,				///< �Ѿ�����
    EN_FPI_MP_REASON_CACHE_FAILED,          ///< ����ʧ��
    EN_FPI_MP_REASON_NO_VIDEO,              ///< û����Ƶ
    EN_FPI_MP_REASON_NO_AUIDO,              ///< û����Ƶ
    EN_FPI_MP_REASON_INITSEG_PARSED,        ///< ý����Ϣͷ�������
    EN_FPI_MP_REASON_SAMPLE_PARSED,         ///< ý��sample�������
    EN_FPI_MP_REASON_NEEDKEY_PARSED,        ///< NK��Ϣ�������
    EN_FPI_MP_REASON_PARSE_COMPLETED,       ///< ý������ȫ���������
}FPI_MP_PLAY_FAILED_REASON_E;

/**
@brief ���岥��������ö��
*/
typedef enum {
    EN_FPI_MP_TYPE_GST,                     ///< gstreamer������
    EN_FPI_MP_TYPE_FFMPEG,                  ///< ffmpeg������
    EN_FPI_MP_TYPE_PICTURE,                 ///< ͼƬ������
	EN_FPI_MP_TYPE_NUM
}FPI_MP_TYPE_E;

/**
@brief �������Ļص��������Ͷ���

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] event �������¼�����ö��
@param[in] code �������¼���ֵ,����event���Ͳ�ͬ�в�ͬ�Ķ���,��ϸ��FPI_MP_CB_EVENT_E��ÿ�����͵Ķ���˵��
@param[in] data �������¼���������,����event���Ͳ�ͬ�в�ͬ�Ķ���,��ϸ��FPI_MP_CB_EVENT_E��ÿ�����͵Ķ���˵��
@param[in] userData �û�����,��ֵΪ����fpi_mp_add_callbackʱ������û�����
*/
typedef void (*tos_mp_callback_fn)(unsigned int playerId, FPI_MP_CB_EVENT_E event, int code, void* data, void *userData);


/**
@brief ����ý�岥����

��ɴ˲������ĳ�ʼ�����������ǲ����ڴ�ʱ�����κ���Դ

@param[in] type ȡFPI_MP_TYPE_Eö���е�ֵ����ʾ��Ҫ�����Ĳ���������.
@return �ɹ�����ý�岥����ID, Ψһ��ʾһ��������; ʧ�ܷ���0
*/
unsigned int tos_mp_create_mediaplayer(FPI_MP_TYPE_E type);


/**
@brief ����ָ����ý�岥����

�˽ӿ�Ϊͬ��,�������,�˲�����������

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_destroy_mediaplayer(unsigned int playerId);


/**
@brief ���ָ���������Ļص�����

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] cb �ص�����ָ��
@param[in] userData �û�����,���ڻص��������׳�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_add_callback(unsigned int playerId, tos_mp_callback_fn cb, void* userData);


/**
@brief ɾ��ָ���������Ļص�����

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] cb �ص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_remove_callback(unsigned int playerId, tos_mp_callback_fn cb);


/**
@brief ����ý�岥����������Դ����

�˽ӿڿ������������κ����͵�����Դ.Ŀǰ֧�ֵ�URL��ʽ����:
- http:// ��������ý��������Դ
- file:/// ���ű���ý��������Դ

@note ��������ļ���ts�ļ�,�������url����Ӹ���programNumber������ʾ���Ŵ�ts���ĸ���Ŀ,��ʽ����: file:///xxx.ts?programNumber=xx

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@param[in] url ϣ�����ŵ�Ŀ������Դ��Ӧ��url
@return  �ɹ�����sourceId,  ʧ�ܷ���-1.
*/
int tos_mp_set_datasource(unsigned int playerId, const char* url);


/**
@brief ׼�������õ�����Դ

׼���ò�����Ҫ�õ�����Դ,���Կ�ʼȥ������Ķ���

@note ������fpi_mp_set_datasource�ӿ�֮�����.
@note �˽ӿ�Ϊ�첽

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_prepare(unsigned int playerId);


/**
@brief �ͷ�ָ����ý�岥������ռ����Դ

@note �˽ӿ�Ϊ�첽

@param[in] playerId ý�岥����ID, Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_release(unsigned int playerId);


/**
@brief ��ָ��ʱ�俪ʼ��������Դ,������Ƶ

�ɹ����ú�Ὺʼ����.
@note �˽ӿ����첽ʵ��,�����Ƿ������ɹ���Ҫ�ص���Ϣȷ��.

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] timestamp ��ʼ����ʱ��,��λ�Ǻ���;���ڵ㲥��,��ʾ�ӿ�ʼ��Ŀ��λ�õĺ�����(���ʱ��);����ʱ������ʱ�����ý��,��ʾ��ʼ����ʱ�䵽1997��7��1�յĺ�����(����ʱ��).
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_play(unsigned int playerId, int64_t timestamp);


/**
@brief ֹͣ��������Դ,�ر�����Ƶ

@note �˽ӿ����첽ʵ��,�����Ƿ�����ֹͣ�ɹ���Ҫ�ص���Ϣȷ��.

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_stop(unsigned int playerId);


/**
@brief ��λ����,��ָ��ʱ�俪ʼ��������Դ

@note �˽ӿ����첽ʵ��,��λ�Ƿ������ɹ���Ҫ�ص���Ϣȷ��.
@note �˽ӿ�Ҫ���ö��Ƶ�����õ���ش���

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] timestamp ��ʼ����ʱ��,��λ�Ǻ���;���ڵ㲥��,��ʾ�ӿ�ʼ��Ŀ��λ�õĺ�����(���ʱ��);����ʱ������ʱ�����ý��,��ʾ��ʼ����ʱ�䵽1997��7��1�յĺ�����(����ʱ��).
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_seek(unsigned int playerId, int64_t timestamp);


/**
@brief ��ͣ��������Դ

@note �˽ӿ����첽ʵ��,��ͣ�Ƿ������ɹ���Ҫ�ص���Ϣȷ��.

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_pause(unsigned int playerId);


/**
@brief �ָ���������Դ

@note �˽ӿ����첽ʵ��,�ָ��Ƿ������ɹ���Ҫ�ص���Ϣȷ��.

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_resume(unsigned int playerId);


/**
@brief ���ò�������,����ʵ�ֿ��/����/����/���˵Ȳ���

@note �˽ӿ����첽ʵ��,�Ƿ������ɹ���Ҫ�ص���Ϣȷ��.

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@param[in] rate ����,����0��ʾǰ��������;С��0��ʾ���˵�����.0��ʾ��ͣ״̬������.
    Ϊ�˲���int���ͱ�ʾ��0.5���ٵ���������,���rate��ȡֵ��������˵��:
    1024��ʾ1����,�Դ�����,512��ʾ0.5����,2*1024��ʾ2����,16*1024��ʾ16����
    ��֮,-1024��ʾ1���ٺ���,-2*1024��ʾ2���ٺ���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_rate(unsigned int playerId, int rate);


/**
@brief ��ȡ��ǰ��������

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ���ص�ǰ����,����0��ʾǰ��������;С��0��ʾ���˵�����.0��ʾ��ͣ״̬������.
    Ϊ�˲���int���ͱ�ʾ��0.5���ٵ���������,���rate��ȡֵ��������˵��:
    1024��ʾ1����,�Դ�����,512��ʾ0.5����,2*1024��ʾ2����,16*1024��ʾ16����
    ��֮,-1024��ʾ1���ٺ���,-2*1024��ʾ2���ٺ���
*/
int tos_mp_get_rate(unsigned int playerId);


/**
@brief ��ȡ�������ĵ�ǰ����״̬

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ���ص�ǰ��״̬
*/
FPI_MP_STATE_E tos_mp_get_current_state(unsigned int playerId);


/**
@brief ��ȡ���ڲ��ŵ�ý�����ʱ��

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ��λ�Ǻ���,���ص�ǰý�����ʱ��;����޹̶�ʱ��,�򷵻�-1
*/
int64_t tos_mp_get_duration(unsigned int playerId);

/**
@brief ��ȡ��ǰ����ʱ��

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ���ص�ǰ����ʱ��,��λ����;���ڵ㲥��,��ʾ�ӿ�ʼ��Ŀ��λ�õĺ�����(���ʱ��);����ʱ������ʱ�����ý��,��ʾ��ʼ����ʱ�䵽1997��7��1�յĺ�����(����ʱ��).
*/
int64_t tos_mp_get_current_play_time(unsigned int playerId);


/**
@brief ��ȡ���ڲ��ŵ�ý�����ʼʱ��

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ��λ����;���ڵ㲥��,Ӧ�÷���0(���ʱ��);����ʱ������ʱ�����ý��,��ʾ��ʼ����ʱ�䵽1997��7��1�յ�����(����ʱ��).
*/
int64_t tos_mp_get_start_time(unsigned int playerId);


/**
@brief ��ȡ���ڲ��ŵ�ý��Ľ���ʱ��

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ��λ����;���ڵ㲥��,Ӧ�÷�����ʱ��(���ʱ��);����ʱ������ʱ�����ý��,��ʾ��ʼ����ʱ�䵽1997��7��1�յ�����(����ʱ��).
*/
int64_t tos_mp_get_end_time(unsigned int playerId);


/**
@brief ��ȡĿǰ�Ѿ�����Ľ��Ȱٷֱ�

@param[in] playerId ý�岥����ID,Ψһ��ʾһ��������.
@return ����Ľ��Ȱٷֱ�,ȡֵ0~100.
*/
int tos_mp_get_buffer_progress(unsigned int playerId);


unsigned int  tos_mp_get_handle(unsigned int playerId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
