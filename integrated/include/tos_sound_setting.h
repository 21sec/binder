/**@defgroup ��������
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/


#ifndef __TOS_SOUND_SETTING_H__
#define __TOS_SOUND_SETTING_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_input_source.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOS_DTV_AUDIO_LANGUAGE_LENGTH   10
#define TOS_MAX_AUD_LANG_NUM      32 //NZ default 16 do not change
#define TOS_MTS_UI_ITEM_MAX     5

#define TOS_MAX_AUD_LANG_NUM      32 //NZ default 16 do not change
#define TOS_MTS_UI_ITEM_MAX     5
#define TOS_DTV_AUDIO_LANGUAGE_CHI  "chi"
#define TOS_DTV_AUDIO_LANGUAGE_CHS  "chs"

#define TOS_DTV_AUDIO_LANGUAGE_ENG  "eng"
#define TOS_DTV_AUDIO_LANGUAGE_UNKNOW  "unknow"


typedef enum{
	EN_TOS_SOUND_EQUALIZER_100HZ,
	EN_TOS_SOUND_EQUALIZER_300HZ,
	EN_TOS_SOUND_EQUALIZER_1KHZ,
	EN_TOS_SOUND_EQUALIZER_10KHZ,
	EN_TOS_SOUND_EQUALIZER_3KHZ
}EN_TOS_SOUND_EQUALIZER_TYPE;

typedef enum{
	EN_TOS_AUDIO_DEVICE_TYPE_MAIN       = 1 << 0,   ///< �������豸������������ SPEAKER
	EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE  = 1 << 1,   ///< ����|
	EN_TOS_AUDIO_DEVICE_TYPE_CAPTURE    = 1 << 2,   ///< ����ץȡ
	EN_TOS_AUDIO_DEVICE_TYPE_SPDIF      = 1 << 3,   ///< AVOUT
	EN_TOS_AUDIO_DEVICE_TYPE_AVOUT		= 1 << 4,	///< AVOUT
	EN_TOS_AUDIO_DEVICE_TYPE_AMP		= 1 << 5,	///< AMP
	EN_TOS_AUDIO_DEVICE_TYPE_ARC		= 1 << 6,	///< ARC
	EN_TOS_AUDIO_DEVICE_TYPE_MAX,
	EN_TOS_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP 	= EN_TOS_AUDIO_DEVICE_TYPE_MAIN|EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE|EN_TOS_AUDIO_DEVICE_TYPE_SPDIF|EN_TOS_AUDIO_DEVICE_TYPE_AVOUT|EN_TOS_AUDIO_DEVICE_TYPE_ARC,
	EN_TOS_AUDIO_DEVICE_TYPE_ALL				= EN_TOS_AUDIO_DEVICE_TYPE_MAIN|EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE|EN_TOS_AUDIO_DEVICE_TYPE_SPDIF|EN_TOS_AUDIO_DEVICE_TYPE_AVOUT|EN_TOS_AUDIO_DEVICE_TYPE_AMP|EN_TOS_AUDIO_DEVICE_TYPE_ARC,
}EN_TOS_AUDIO_DEVICE_TYPE;

/**
������������
*/
typedef enum
{
	EN_TOS_AUDIO_INPUT_TYPE_MAIN      = 1 << 0,   ///< ������
	EN_TOS_AUDIO_INPUT_TYPE_AD        = 1 << 1,   ///< AD����,��audio description
	EN_TOS_AUDIO_INPUT_TYPE_MAX
}EN_TOS_AUDIO_INPUT_TYPE;


typedef enum
{  
	EN_TOS_AUDIO_INPUT_MIC,
	EN_TOS_AUDIO_INPUT_MEDIA_IN,
	EN_TOS_AUDIO_INPUT_MAX
}EN_TOS_AUDIO_INPUT;


typedef enum
{
	EN_TOS_AUDIO_INPUT_INFO_5P1,
	EN_TOS_AUDIO_INPUT_INFO_7P1
}EN_TOS_AUDIO_INPUT_INFO;

//Audio add by Areos 2013-7-29
typedef enum
{
	EN_TOS_AUDIOTYPE_MPEG		= 0x00,
	EN_TOS_AUDIOTYPE_AC3			= 0x01, 
	//AUDIOTYPE_MPEG4		= 0x02,
	EN_TOS_AUDIOTYPE_AAC			= 0x03,
	EN_TOS_AUDIOTYPE_AC3P		= 0x04,
	EN_TOS_AUDIOTYPE_AACP		= 0x05,
	//AUDIOTYPE_MPEG_AD	= 0x06,
	//AUDIOTYPE_AC3_AD	= 0x07,
	//AUDIOTYPE_AC3P_AD	= 0x08,
	//AUDIOTYPE_AACP_AD	= 0x09,
	EN_TOS_AUDIOTYPE_HEAAC		= 0x10,
	EN_TOS_AUDIOTYPE_AAC_V2		= 0x11,
	EN_TOS_AUDIOTYPE_AAC_V4		= 0x12,
	EN_TOS_AUDIOTYPE_HEAAC_V2	= 0x13,
	EN_TOS_AUDIOTYPE_HEAAC_V4	= 0x14
}EN_TOS_AUDIO_TYPE;


typedef enum
{
	EN_TOS_MTS_INVALID,
	EN_TOS_MTS_MONO,
	EN_TOS_MTS_DUAL_BGDKI,
	EN_TOS_MTS_DUAL_KEREA,
	EN_TOS_MTS_STEREO_BGDKI,
	EN_TOS_MTS_STEREO_KOREA,
	EN_TOS_MTS_NICAM_MONO,
	EN_TOS_MTS_NICAM_DUAL,
	EN_TOS_MTS_NICAM_STEREO,
	EN_TOS_MTS_BTSC_MONO,
	EN_TOS_MTS_BTSC_SAP,
	EN_TOS_MTS_BTSC_STEREO,
	EN_TOS_MTS_BTSC_STEREO_SAP,
	EN_TOS_MTS_NICAM_MAX //UI NEED
} EN_TOS_MTS_TYPE;

typedef enum
{
	EN_TOS_AUD_CH_UNKNOW = 0,
	EN_TOS_AUD_CH_MONO, /* 1/0 */ //center
	EN_TOS_AUD_CH_SUB, /*1+sub-language */
	EN_TOS_AUD_CH_DUAL_MONO, /*1+1*/
	EN_TOS_AUD_CH_STEREO, /* 2/0 */  //left+right
	EN_TOS_AUD_CH_STEREO_SUB, /*2+sub-language */
	EN_TOS_AUD_CH_STEREO_DOLBY_SURROUND, /* 2/0,dolby surround*/
	EN_TOS_AUD_CH_SURROUND_2CH, /* 2/1*/ //left+right+(LS or RS)
	EN_TOS_AUD_CH_SURROUND, /*3/1*/ //left+center+right+(LS or RS)
	EN_TOS_AUD_CH_3_0, /*3/0*/ //left+center+right
	EN_TOS_AUD_CH_4_0, /* 2/2*/ //left+right+LS+RS
	EN_TOS_AUD_CH_5_0, /*3/2*/  //left+center+right+LS+RS
	EN_TOS_AUD_CH_MONO_LFE, /*1/0.L*/
	EN_TOS_AUD_CH_DUAL_MONO_LFE, /*1+1.L*/
	EN_TOS_AUD_CH_STEREO_LFE, /*2/0.L*/
	EN_TOS_AUD_CH_SURROUND_2CH_LFE, /*2/1.L*/
	EN_TOS_AUD_CH_SURROUND_LFE, /*3/1.L/*/
	EN_TOS_AUD_CH_3_1, /*3/ 0.L*/ //left+center+right+low
	EN_TOS_AUD_CH_4_1, /*2/2.L*/ //left+right+LS+RS+low
	EN_TOS_AUD_CH_5_1, /*3/2.L*/  //left+center+right+LS+RS+low
	EN_TOS_AUD_CH_7_1, /*5/2.L*/ //left+center+right+LS+RS+LB+RB+low
	EN_TOS_AUD_CH_JOINT_STEREO,
	EN_TOS_AUD_CH_FMRDO_MONO,
	EN_TOS_AUD_CH_FMRDO_STEREO,
	EN_TOS_AUD_CH_FM_MONO_NICAM_MONO,
	EN_TOS_AUD_CH_FM_MONO_NICAM_STEREO,
	EN_TOS_AUD_CH_FM_MONO_NICAM_DUAL,
	EN_TOS_AUD_CH_LEFT, // left
	EN_TOS_AUD_CH_RIGHT, // right
	EN_TOS_AUD_CH_OTHERS    
}EN_TOS_AUD_CHANNEL_MODE; // st_api_lang_iso639.u8AudMode

typedef enum
{
	EN_TOS_SND_MODE_MUSIC,
	EN_TOS_SND_MODE_MOVIE,
	EN_TOS_SND_MODE_NEWS,
	EN_TOS_SND_MODE_STANDARD,
	EN_TOS_SND_MODE_USER,
	EN_TOS_SND_MODE_SUBWOOFER, //Kevin.L subwoffer
	EN_TOS_SND_MODE_STADIUM,
	EN_TOS_SND_MODE_NUM
}EN_TOS_SOUND_MODE;


typedef enum
{
	EN_TOS_STEREO_OFF,
	EN_TOS_STEREO_XT,
	EN_TOS_STEREO_HD ,//SRS TSHD
	EN_TOS_STEREO_NUM
}EN_TOS_STEREO_MODE;

typedef enum
{
	EN_TOS_SPDIF_AUTO,
	EN_TOS_SPDIF_PCM,
	EN_TOS_SPDIF_OFF,
	EN_TOS_SPDIF_NUM
}EN_TOS_SPDIF_TYPE;

typedef enum
{
	EN_TOS_SPDIF_DDP_OFF,
	EN_TOS_SPDIF_DDP_ON
}EN_TOS_SPDIF_DDP_MODE;



/// Audio MTS Mode Type
typedef enum
{  
	EN_TOS_MTS_INVALID_                    = 0x00,
	EN_TOS_MTS_MONO_                       = 0x01,
	EN_TOS_MTS_FORCED_MONO_                = 0x02,
	EN_TOS_MTS_G_STEREO_                   = 0x03,
	EN_TOS_MTS_K_STEREO_                   = 0x04,
	EN_TOS_MTS_MONO_SAP_                   = 0x05,
	EN_TOS_MTS_STEREO_SAP_                 = 0x06,
	EN_TOS_MTS_DUAL_A_                     = 0x07,
	EN_TOS_MTS_DUAL_B_                     = 0x08,
	EN_TOS_MTS_DUAL_AB_                    = 0x09,
	EN_TOS_MTS_NICAM_MONO_                 = 0x0A,
	EN_TOS_MTS_NICAM_STEREO_               = 0x0B,
	EN_TOS_MTS_NICAM_DUAL_A_               = 0x0C,
	EN_TOS_MTS_NICAM_DUAL_B_               = 0x0D,
	EN_TOS_MTS_NICAM_DUAL_AB_              = 0x0E,
	EN_TOS_MTS_HIDEV_MONO_                 = 0x0F,
	EN_TOS_MTS_LEFT_LEFT_                  = 0x10,
	EN_TOS_MTS_RIGHT_RIGHT_                = 0x11,
	EN_TOS_MTS_LEFT_RIGHT_                 = 0x12
}EN_TOS_AUDIO_MTS_TYPE;

typedef enum
{  
	EN_TOS_AUD_DESKTOP,
	EN_TOS_AUD_HUNG_ON
}EN_TOS_AUDIO_SCENE;


typedef enum
{
	TOS_AUDIO_MUTE_LOWEST, 						  ///<������SPDIF --> 0x01
	TOS_AUDIO_MUTE_CEC, 						  ///<CEC--> 0x02
	TOS_AUDIO_MUTE_USER, 						  ///<������SPDIF --> 0x04
	TOS_AUDIO_MUTE_PVR,  						  ///<����SPDIF --> 0x08
	TOS_AUDIO_MUTE_SYNC, 					      ///<����SPDIF  -->0x10
	TOS_AUDIO_MUTE_LOCK, 						  ///<����SPDIF -->0x20     
	TOS_AUDIO_MUTE_MHEG, 						  ///<����SPDIF  -->0x40
	TOS_AUDIO_MUTE_SCAN, 						  ///<����SPDIF -->0x80
	TOS_AUDIO_MUTE_CHANGE_CHANNEL, 				  ///<����SPDIF -->0x100
	TOS_AUDIO_MUTE_CHANGE_LINEIN, 				  ///<����SPDIF -->0x200
	TOS_AUDIO_MUTE_INTER, 						  ///<����SPDIF ,���� -->0x400
	TOS_AUDIO_MUTE_CHILDREN_LOCK,				  ///<��ͯ��    -->0x800
	TOS_AUDIO_MUTE_HIGHEST, 					  ///<����SPDIF ,����   -->0x1000
	TOS_AUDIO_MUTE_SCART,     					  ///<����SPDIF-->0x2000
	TOS_AUDIO_MUTE_HP_PLUGIN    = 31  			  ///<����SPDIF-->0x80000000
}EN_TOS_AUDIO_MUTE_TYPE;

typedef enum
{
    EN_TOS_DTV_SOUND_MODE_STEREO,
    EN_TOS_DTV_SOUND_MODE_LEFT,
    EN_TOS_DTV_SOUND_MODE_RIGHT,
    EN_TOS_DTV_SOUND_MODE_MAX
} EN_TOS_DTV_STEREO_MODE;


typedef enum
{
	EN_TOS_AUDIO_CHANNEL_OFF = 0x0,
	EN_TOS_AUDIO_CHANNEL_NORMAL, ///<TVͨ������������������Դ���������
	EN_TOS_AUDIO_CHANNEL_AD,///<AD��TVͨ��������
	EN_TOS_AUDIO_CHANNEL_MAX
}EN_TOS_AUDIO_DECODER_CHANNEL_TYPE;

typedef enum
{
	EN_TOS_AUDIO_OUTPUT_OFF = 0x0,
	EN_TOS_AUDIO_OUTPUT_ON
}EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS;

typedef enum{
	EN_TOS_AUDIO_TREBLE_VALUE_TYPE       = 0,
	EN_TOS_AUDIO_BASS_VALUE_TYPE  = 1
}EN_TOS_AUDIO_VALUE_TYPE;

typedef enum
{
    EN_TOS_TCL_SUDEFFECT_OFF = 0x00,
    EN_TOS_TCL_SUDEFFECT_ON
}EN_TOS_TCL_SUDEFFECT_MODE;

typedef enum
{
    EN_TOS_TCL_SUDEFFECT_AUTO_VOLUME_CONTROL = 0x00,
    EN_TOS_TCL_SUDEFFECT_VIRTUAL_BASS,
    EN_TOS_TCL_SUDEFFECT_MAX
}EN_TOS_TCL_SUDEFFECT_TYPE;

//KEVIN_MS12_ENABLE 
typedef enum
{
    EN_TOS_DOLBY_MS12_SOUND_MODE,
	EN_TOS_DOLBY_MS12_SURROUND_VIRTUALIZER,
	EN_TOS_DOLBY_MS12_DIALOG_ENHANCER,
	EN_TOS_DOLBY_MS12_BASS_ENHANCER,
	EN_TOS_DOLBY_MS12_AUTO_VOLUME_CONTROL,
	EN_TOS_DOLBY_MS12_MEDIA_INTELLIGENCE,
	EN_TOS_DOLBY_MS12_INTELLIGENT_EQ,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ_BALANCE1,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ_BALANCE2,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ_BALANCE3,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ_BALANCE4,
	EN_TOS_DOLBY_MS12_GRAPHIC_EQ_BALANCE5,
	EN_TOS_DOLBY_MS12_SUM,
}EN_TOS_DOLBY_MS12_SETTING_TYPE;


typedef struct
{
    int32_t describe_Contents; //��ʱ���ã�Ĭ��Ϊ0
    char audioLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string ����,Ĭ�ϵ�ǰaudio language
    int32_t current_audio_language_index;
    char currentLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string ����,Ĭ�ϵ�ǰaudio language
    int32_t digital_mts; //����������ָ���������� EN_TOS_DTV_STEREO_MODE digital_channel; //����������ָ����������
    int32_t total_number; //��ǰ��Ŀ����
    EN_TOS_AUDIO_TYPE audioType; //��Ƶ����
}st_audio_language_information;



typedef struct
{
    int u8ISOLangInfo[3];       //:24
    int u8AudMode;              //:2 ///< 0x00: Stereo, 0x01: Mono left, 0x02: Mono right  //EN_TOS_AUD_CHANNEL_MODE
    int u8AudType;		//0:undefined,1 clean effects,2 hearing impaired,3 visual impaired
    int u8IsValid;
}st_tos_lang_iso639;


typedef struct
{
    st_tos_lang_iso639 isoLangInfo;
    int32_t audioPid;
    EN_TOS_AUDIO_TYPE audioType;
    int32_t broadcastMixAD;
    int32_t aacType;
    int32_t aacProfileAndLevel;
}st_tos_audio_info;



typedef struct
{
    EN_TOS_MTS_TYPE     html_ui_mts_mode;    //set ��Ҫ
    uint8_t             html_set_idx;        //set ��Ҫ
    uint8_t             html_mode_total_item;  //get ��Ҫ
    uint8_t             html_reserved[2];
    EN_TOS_AUDIO_MTS_TYPE      html_mode_include_type[TOS_MTS_UI_ITEM_MAX];//get ��Ҫ
}st_tos_mts_info_t;

typedef struct
{
   uint8_t audioCount;
   uint8_t curAudioIdx;
   st_tos_audio_info stAudInfo[TOS_MAX_AUD_LANG_NUM];
   int32_t langCode[TOS_MAX_AUD_LANG_NUM]; //MEMBER_LANGUAGE
   uint8_t audioSelCount; //��ǰ��Ƶ����
   uint8_t audioAdMixed[TOS_MAX_AUD_LANG_NUM];
   uint8_t audioMainMixed[TOS_MAX_AUD_LANG_NUM];
   fpi_bool Is_CurrentPID_DualMono;
}st_tos_audio_language_info;

typedef struct
{
    int32_t alternative_audio; //��ʱû��
    int32_t mts; //����������ָ����������0x00 -->STEREO,��������0x01--> LL,������ , 0x02 --> RR,������
}st_tos_audio_information; 

/*typedef struct
{
    int32_t describe_Contents; //��ʱ���ã�Ĭ��Ϊ0
    char audioLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string ����,Ĭ�ϵ�ǰaudio language
    int32_t current_audio_language_index;
    char currentLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string ����,Ĭ�ϵ�ǰaudio language
    int32_t digital_mts; //����������ָ����������
    int32_t total_number; //��ǰ��Ŀ����
    EN_TOS_AUDIO_TYPE audioType; //��Ƶ����
}st_tos_audio_language_information;
*/

/** 
@brief ���þ���

@param [in] mute_level ���þ�����ԭ��ȡֵ��Χ��AUDIO_MUTE_LEVEL ö��

@param [in] b_mute 

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

@note    �ýӿڲ���Ϊ��ͬ����Ƶ�豸���þ������Ƽ�ʹ��
*/
fpi_error tos_audio_set_mute(int16_t mute_level, int16_t b_mute, EN_ACT_CTRL act );

/** 
@brief ���ָ��ԭ���Ӧ�ľ���״̬

@param [in] mute_level ���þ�����ԭ��ȡֵ��Χ��AUDIO_MUTE_LEVEL ö��

@param [out] b_mute 

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

@note    �ýӿڲ���Ϊ��ͬ����Ƶ�豸���þ������Ƽ�ʹ��
*/
fpi_error tos_audio_get_mute(int16_t mute_level,int16_t *mute);

/** 
@brief ������Ƶ�豸���������

@param [in] volume �û����õ�����ֵ��ȡֵ��Χ0-100

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

@note    �ýӿڲ���Ϊ��ͬ����Ƶ�豸�����������Ƽ�ʹ��
*/
fpi_error tos_audio_set_volume(int16_t volume, EN_ACT_CTRL act);

/** 
@brief ��ȡ��Ƶ�豸 ���������

@param [out] volume �û����õ���Ƶ�豸 ����ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

@note    �ýӿڲ��ܻ�ȡ��ͬ��Ƶ�豸���������Ƽ�ʹ��
*/
fpi_error tos_audio_get_volume(int16_t *volume);

/** 
@brief Ϊ��ͬ����Ƶ����豸���þ���

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [in] ch_reason ���þ�����ԭ��

@param [in] b_mute 

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev,  char* ch_reason, int16_t b_mute, EN_ACT_CTRL act );

/** 
@brief ��ȡָ����Ƶ����豸ָ��ԭ��ľ���״̬

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [in] ch_reason ���þ�����ԭ��

@param [out] state ������״̬

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev,  char* mute_reason, int16_t* state );

/** 
@brief ����ָ����Ƶ����豸ָ��ͨ�����������

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [in] input    ������Ƶ��ͨ�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_INPUT_TYPE ö��

@param [in] volume ���õ�����ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_volume_ex(EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input,int16_t volume, EN_ACT_CTRL act);


/** 

@brief ��ȡָ����Ƶ����豸ָ��ͨ�����������

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [in] input    ������Ƶ��ͨ�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_INPUT_TYPE ö��

@param [out] volume ���õ�����ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

*/
fpi_error tos_audio_get_volume_ex(EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input,int16_t *volume);

/** 
@brief��ȡ����������

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n
                              
                   �ò���Ԥ����չ������ʱ�����ã������߿ɺ���
                   
@param [out] value �Ƶ�˵���lock �˵����õ��������ֵ(�Ƶ�˵��������������)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

@note ����ӿ������⣬��Ӧ�ý��Ƶ�����������������

*/

 fpi_error tos_audio_get_max_volume(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *value);

/** 
@brief ��������������

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n
                              
                   �ò���Ԥ����չ������ʱ�����ã������߿ɺ���
                   
@param [in] maxVolume �������ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/

fpi_error tos_audio_set_max_volume(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t maxVolume,EN_ACT_CTRL act);


/** 
@brief ����ָ���ⲿ�����豸�ľ���

@param [in] en_dev �ⲿ�����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_INPUT ö��
                   
@param [in] mute    ���õ�mute ״̬

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_input_mute(EN_TOS_AUDIO_INPUT input, int16_t mute,EN_ACT_CTRL act);

/** 
@brief ��ȡָ���ⲿ�����豸�ľ���״̬

@param [in] en_dev �ⲿ�����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_INPUT ö��
                   
@param [out] mute    ���õ�mute ״̬

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_input_mute(EN_TOS_AUDIO_INPUT input, int16_t *mute);

/** 
@brief ����ָ���ⲿ�����豸������

@param [in] en_dev �ⲿ�����豸������(��˷��)��ȡֵ��Χ��EN_TOS_AUDIO_INPUT ö��
                   
@param [in] soundValue    ���õ�����ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

*/
fpi_error tos_audio_set_input_volume(EN_TOS_AUDIO_INPUT input, int16_t soundValue, EN_ACT_CTRL act);

/** 
@brief ��ȡָ���ⲿ�����豸������

@param [in] en_dev �ⲿ�����豸������(��˷��)��ȡֵ��Χ��EN_TOS_AUDIO_INPUT ö��
                   
@param [out] soundValue    ����ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_input_volume(EN_TOS_AUDIO_INPUT input, int16_t *soundValue);

/** 
@brief ������Чģʽ

@param [in] mode    ���õ���Чģʽ��ȡֵ��Χ��EN_TOS_SOUND_MODE ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_equalizer_mode(EN_TOS_SOUND_MODE mode,EN_ACT_CTRL act);

/** 
@brief ��ȡ��ǰ���õ���Чģʽ

@param [out] value    ��ǰ���õ���Чģʽ��ȡֵ��Χ��EN_TOS_SOUND_MODE ö��

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ

*/
fpi_error tos_audio_get_equalizer_mode(EN_TOS_SOUND_MODE *value);

/** 
@brief ����ָ��Ƶ�εľ���ֵ

@param [in] type    ���õ�Ƶ�����ͣ�ȡֵ��Χ��EN_TOS_SOUND_EQUALIZER_TYPE ö��

@param [in] value    ���õľ���ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_equalizer(EN_TOS_SOUND_EQUALIZER_TYPE type,int16_t value,EN_ACT_CTRL act);

/** 
@brief ��ȡָ��Ƶ�εľ���ֵ

@param [in] type    ���õ�Ƶ�����ͣ�ȡֵ��Χ��EN_TOS_SOUND_EQUALIZER_TYPE ö��

@param [out] value    ���õľ���ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_equalizer(EN_TOS_SOUND_EQUALIZER_TYPE type,int16_t *value);


/** 
@brief ����ָ����Ƶ����豸��ƽ��ֵ

@param [in] dev    ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n

@param [in] value    ���õ�ƽ��ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_balance(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t value,EN_ACT_CTRL act);

/** 
@brief ��ȡָ����Ƶ����豸��ƽ��ֵ

@param [in] dev    ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n

@param [out] value    ���ص�ǰָ����Ƶ����豸���õ�ƽ��ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_balance(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *value);


/** 
@brief �����Զ�������״̬(����SOCоƬ���Զ���������)

@param [in] enable    ���õ��Զ�����״̬

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_auto_volume(int16_t enable,EN_ACT_CTRL act);

/** 
@brief ��ȡ�Զ�������״̬(����SOCоƬ���Զ���������)

@param [out] enable    ���ص�ǰ���õ��Զ�����״̬

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_auto_volume(int16_t *enable);

/** 
@brief �����豸�������ӳ�

@param [in] dev    ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n

@param [in] delay  �����ӳٵ�ֵ����msΪ��λ,��ͬ��Ŀ�в�ͬ��ȡֵ��Χ(ŷ���¹�-50��1000)

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_delay(EN_TOS_AUDIO_DEVICE_TYPE dev,int32_t delay,EN_ACT_CTRL act);

/** 
@brief ��ȡ�豸�����ӳ�ֵ

@param [in] dev    ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��\n

@param [out] delay  �����ӳٵ�ֵ����msΪ��λ,��ͬ��Ŀ�в�ͬ��ȡֵ��Χ(ŷ���¹�-50��1000)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_delay(EN_TOS_AUDIO_DEVICE_TYPE dev,int32_t *delay);

/** 
@brief ����������Ч��

@param [in] mode    ���õ�������������,ȡֵ��Χ��EN_TOS_STEREO_MODE ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_wide_stereo(EN_TOS_STEREO_MODE mode,EN_ACT_CTRL act);

/** 
@brief ��ȡ��ǰ����������������

@param [out] value    ���ص�ǰ���õ�������������

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_wide_stereo(EN_TOS_STEREO_MODE *value);

/** 
@brief ������������ĸ�ʽ

@param [in] type    ���õ�SPDIF ����,ȡֵ��Χ��EN_TOS_SPDIF_TYPE ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_spdif_type(EN_TOS_SPDIF_TYPE type,EN_ACT_CTRL act);

 /** 
 @brief ��ȡ��������ĸ�ʽ
 
@param [out] value    ���ص�ǰ���õ�SPDIF ����,ȡֵ��Χ��EN_TOS_SPDIF_TYPE ö��
 
@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_spdif_type(EN_TOS_SPDIF_TYPE *value);


/** 
@brief ��ȡ�Ӿ��ϰ����ܵ�״̬

@param [out] state  �Ӿ��ϰ����ܵ�״̬,0Ϊoff,1Ϊon

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_visual_impaired(int16_t *state);

/** 
@brief �����Ӿ��ϰ����ܵĿ���

@param [in] state  ���õ��Ӿ��ϰ����ܵ�״̬,0Ϊoff,1Ϊon

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_visual_impaired(int16_t state,EN_ACT_CTRL act);

/** 
@brief ������Ƶ�������ܵĿ���

@param [in] enable  ���õ���Ƶ�������ܵ�״̬,0Ϊdisable,1Ϊenable

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_audio_description(int16_t enable,EN_ACT_CTRL act);

/** 
@brief ��ȡ��Ƶ�������ܵ�״̬

@param [out] enable  ��Ƶ�������ܵ�״̬,0Ϊdisable,1Ϊenable

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_audio_description(int16_t *enable);

/** 
@brief ������Ƶ�������ܵ���������(tvos 2.0�����ã����õ�tos_audio_set_volume_ex�ӿ�)

@param [in] level	���õ���Ƶ�������ܵ���������,ֵ��ΧΪ0-100

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_audio_description_mix_level(uint16_t level,EN_ACT_CTRL act);

/** 
@brief ��ȡ��Ƶ�������ܵ���������(tvos 2.0�����ã����õ�tos_audio_get_volume_ex�ӿ�)

@param [out] value	���õ���Ƶ�������ܵ���������,ֵ��ΧΪ0-100

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_audio_description_mix_level(uint16_t *value);

/** 
@brief ��ȡ�����������Ϣ

@param [out] audioInfo	�������������

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_mts_info(st_tos_mts_info_t *audioInfo);

/** 
@brief ��������������

@param [in] audioInfo ����������ͣ��뿴EN_TOS_AUDIO_MTS_TYPEö�ٶ���

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_mts_info(st_tos_mts_info_t *audioInfo,EN_ACT_CTRL act);


/** 
@brief ��ȡ��ǰ����������Ƶstream��Ϣ

@param [out] info ��ز�����Ƶstream����Ϣ�������뿴st_tos_audio_language_info�Ľṹ������

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_language_info(st_tos_audio_language_info *info);


/** 
@brief ���õ�ǰ����������Ƶ����

@param [in] audioIndex ��Ƶ���Ե�����ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_language_index(uint8_t audioIndex,EN_ACT_CTRL act);

/** 
@brief ��������豸ʹ�õĳ�������

@param [out] scene 0Ϊ����ģʽ��1Ϊ�ڹ�ģʽ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_scene(EN_TOS_AUDIO_SCENE *scene);

/** 
@brief ���õ�ǰ�����豸��ʹ�ó���

@param [in] scene 0Ϊ����ģʽ��1Ϊ�ڹ�ģʽ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_scene(EN_TOS_AUDIO_SCENE scene,EN_ACT_CTRL act);

/** 
@brief ��ȡ���������豸�Ľ���״̬(headphone�ǿ���ͨ����ȡGPIO�ڵ�״�����Բ�ѯ��speaker��spdif
       ��ͨ��IIC����GPIO�ڲ�ѯ��Ҫ��NTK�˽⡣�м��������ȡ��ͨ��GPIO��ʽȥ����״̬������ʵ�ַ���δ֪

@param [in] en_dev ��Ƶ����豸�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [out] isplugin ��ز���״̬���豸����

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_dev_plugin(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *isplugin);

/** 
@brief �õ���ǰ����Դ��֧�ֵ�������Ŀ

@param [in] type ȡֵ��Χ��EN_TOS_AUDIO_INPUT_INFO ö��

@param [out] value ������Ŀ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_source_info(EN_TOS_AUDIO_INPUT_INFO type,int16_t *value);

/** 
@brief ������Դ(Ŀǰֻ֧��DTV)����ȡ��ǰ��Դ�²��ŵ���Ƶstream��Ϣ

@param [in] input ��Դ��ȡֵ��Χ��EN_API_SOURCE_INPUT ö��

@param [out] dAudioInfo ��Ƶstream��Ϣ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_language_information(EN_API_SOURCE_INPUT input,st_audio_language_information *dAudioInfo) ;

/** 
@brief ������Դ(Ŀǰֻ֧��DTV)�����õ�ǰ��Դ�²��ŵ���Ƶstream��Ϣ

@param [in] input ��Դ��ȡֵ��Χ��EN_API_SOURCE_INPUT ö��

@param [in] dAudioInfo ��Ƶstream��Ϣ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_language_information(EN_API_SOURCE_INPUT input,st_audio_language_information *dAudioInfo,EN_ACT_CTRL act) ;

/** 
@brief ��ȡ����״̬��speaker�Ƿ�enable

@param [out] enable 0Ϊdisable��1Ϊenable

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_speaker_enable(int16_t *enable);

/** 
@brief ���ö���״̬��speaker�Ƿ�enable

@param [in] enable 0Ϊdisable��1Ϊenable

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/

fpi_error tos_audio_set_speaker_enable(int16_t enable,EN_ACT_CTRL act);


/** 
@brief ����dtv������ģʽ

@param [in] mode ����������������������������ȡֵ��Χ��EN_TOS_DTV_STEREO_MODE ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_dtv_stereo_sound_mode(EN_TOS_DTV_STEREO_MODE mode,EN_ACT_CTRL act);

/** 
@brief ���õ�ǰ��Ƶ����豸��Ƶstream������

@param [in] dev ��Դ��ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [in] decoder_type Ŀǰ֧��MAIN��MAIN+AD,ȡֵ��Χ��EN_TOS_AUDIO_DECODER_CHANNEL_TYPE ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_output_device_mix_type(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type,EN_ACT_CTRL act);

/** 
@brief ��ȡ��ǰ��Ƶ����豸��Ƶstream������

@param [in] dev ��Դ��ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [out] decoder_type Ŀǰ֧��MAIN��MAIN+AD,ȡֵ��Χ��EN_TOS_AUDIO_DECODER_CHANNEL_TYPE ö��

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_output_device_mix_type(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DECODER_CHANNEL_TYPE *decoder_type);

 /** 
 @brief �洢��Ƶ�豸��on-off״̬���ϲ�ʵ���߼����м��ֻ���洢����
 
 @param [in] dev ��Դ��ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��
 
 @param [in] status ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS ö��
 
 @param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)
 
 @retval  �ɹ�����FPI_ERROR_SUCCESS;
 
 @retval  ʧ�ܷ�������ֵ
 */
fpi_error tos_audio_set_audDevice_output_onOff(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status,EN_ACT_CTRL act);

/** 
@brief ��ȡ��Ƶ�豸��on-off�Ĵ洢״̬���ϲ�ʵ���߼����м��ֻ���洢����

@param [in] dev ��Դ��ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_TYPE ö��

@param [out] status ȡֵ��Χ��EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS ö��

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_audDevice_output_onOff(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS *status);

/** 
@brief audio����ֵ��ͨ�ýӿ�

@param [in] type ����ֵ�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_VALUE_TYPE ö��

@param [in] value �������͵�ֵ���Ӻ����������͵ķ�Χ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_value(EN_TOS_AUDIO_VALUE_TYPE type ,int16_t value,EN_ACT_CTRL act);

/** 
@brief ��ȡaudio����ֵ��ͨ�ýӿ�

@param [in] type ����ֵ�����ͣ�ȡֵ��Χ��EN_TOS_AUDIO_VALUE_TYPE ö��

@param [out] value �������͵�ֵ���Ӻ����������͵ķ�Χ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_value(EN_TOS_AUDIO_VALUE_TYPE type ,int16_t *value);

/** 
@brief ���ڿ���TCL��ס��Ч�㷨������״̬

@param [in] type �㷨������(Ŀǰ�����������������������)��ȡֵ��Χ��EN_TOS_TCL_SUDEFFECT_TYPE ö��

@param [in] mode ����״̬��0Ϊoff��1Ϊon

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_tcl_sound_effects_mode(EN_TOS_TCL_SUDEFFECT_TYPE type,EN_TOS_TCL_SUDEFFECT_MODE mode ,EN_ACT_CTRL act);

/** 
@brief ��ȡTCL��ס��Ч�㷨������״̬

@param [in] type �㷨������(Ŀǰ�����������������������)��ȡֵ��Χ��EN_TOS_TCL_SUDEFFECT_TYPE ö��

@param [out] mode ����״̬��0Ϊoff��1Ϊon

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_tcl_sound_effects_mode(EN_TOS_TCL_SUDEFFECT_TYPE type,EN_TOS_TCL_SUDEFFECT_MODE* mode);

/** 
@brief ��������Input Stream��Dolby Digital Plus��ʱ���Ƿ�ͨ��HDMI ARC ���Dolby Digital Plus raw data���ⲿ����

@param [in] mode ����״̬��0Ϊoff��1Ϊon

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_spdif_dobly_digital_plus_mode(EN_TOS_SPDIF_DDP_MODE mode,EN_ACT_CTRL act);

/** 
@brief ������ȡInput Stream��Dolby Digital Plus��ʱ��HDMI ARC ���Dolby Digital Plus raw data���ⲿ���ŵ�״̬

@param [out] mode ����״̬��0Ϊoff��1Ϊon

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_spdif_dobly_digital_plus_mode(EN_TOS_SPDIF_DDP_MODE *mode);

/** 
@brief ����dobly ms12 ��ز�����״̬;Dobly MS12��֤��Ҫ

@Param [in] type ������������������ͣ�ȡֵ��Χ��EN_TOS_DOLBY_MS12_SETTING_TYPE ö��

@Param [in] value ���õ�ֵ

@param [in] EN_ACT_CTRL ����ִ�е�����(ִֻ�У�ֻ���棬ִ�к󱣴�)

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_set_dobly_ms12_setting(EN_TOS_DOLBY_MS12_SETTING_TYPE type,int16_t value,EN_ACT_CTRL act);

/** 
@brief ��ȡdobly ms12 ��ز�����״̬

@Param [in] type ��Ҫ��ȡ������������������� ��ȡֵ��Χ��EN_TOS_DOLBY_MS12_SETTING_TYPE ö��

@Param [out] value ����������dbֵ 

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_get_dobly_ms12_setting(EN_TOS_DOLBY_MS12_SETTING_TYPE type,int16_t *value);

/** 
@brief ����soundҳ����ز����趨
	   ������ز������κ�һ��MS12��Чģʽ�¶���Ҫ���Ե���������,����ִ��"����ҳ��-�ָ�Ĭ������"ѡ��ʱ,
	   ���audio/para.ini��ȡ����������Ĭ��ֵ������ms12_setting db table������ֵ

@retval  �ɹ�����FPI_ERROR_SUCCESS;

@retval  ʧ�ܷ�������ֵ
*/
fpi_error tos_audio_reset_sound_setting(void);

#ifdef __cplusplus
}
#endif
/** @} */

#endif
