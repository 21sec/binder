/**@defgroup 声音设置
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
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
	EN_TOS_AUDIO_DEVICE_TYPE_MAIN       = 1 << 0,   ///< 主声音设备，即内置喇叭 SPEAKER
	EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE  = 1 << 1,   ///< 耳机|
	EN_TOS_AUDIO_DEVICE_TYPE_CAPTURE    = 1 << 2,   ///< 声音抓取
	EN_TOS_AUDIO_DEVICE_TYPE_SPDIF      = 1 << 3,   ///< AVOUT
	EN_TOS_AUDIO_DEVICE_TYPE_AVOUT		= 1 << 4,	///< AVOUT
	EN_TOS_AUDIO_DEVICE_TYPE_AMP		= 1 << 5,	///< AMP
	EN_TOS_AUDIO_DEVICE_TYPE_ARC		= 1 << 6,	///< ARC
	EN_TOS_AUDIO_DEVICE_TYPE_MAX,
	EN_TOS_AUDIO_DEVICE_TYPE_ALL_EXCEPT_AMP 	= EN_TOS_AUDIO_DEVICE_TYPE_MAIN|EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE|EN_TOS_AUDIO_DEVICE_TYPE_SPDIF|EN_TOS_AUDIO_DEVICE_TYPE_AVOUT|EN_TOS_AUDIO_DEVICE_TYPE_ARC,
	EN_TOS_AUDIO_DEVICE_TYPE_ALL				= EN_TOS_AUDIO_DEVICE_TYPE_MAIN|EN_TOS_AUDIO_DEVICE_TYPE_HEADPHONE|EN_TOS_AUDIO_DEVICE_TYPE_SPDIF|EN_TOS_AUDIO_DEVICE_TYPE_AVOUT|EN_TOS_AUDIO_DEVICE_TYPE_AMP|EN_TOS_AUDIO_DEVICE_TYPE_ARC,
}EN_TOS_AUDIO_DEVICE_TYPE;

/**
声音输入类型
*/
typedef enum
{
	EN_TOS_AUDIO_INPUT_TYPE_MAIN      = 1 << 0,   ///< 主声音
	EN_TOS_AUDIO_INPUT_TYPE_AD        = 1 << 1,   ///< AD声音,即audio description
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
	TOS_AUDIO_MUTE_LOWEST, 						  ///<不控制SPDIF --> 0x01
	TOS_AUDIO_MUTE_CEC, 						  ///<CEC--> 0x02
	TOS_AUDIO_MUTE_USER, 						  ///<不控制SPDIF --> 0x04
	TOS_AUDIO_MUTE_PVR,  						  ///<控制SPDIF --> 0x08
	TOS_AUDIO_MUTE_SYNC, 					      ///<控制SPDIF  -->0x10
	TOS_AUDIO_MUTE_LOCK, 						  ///<控制SPDIF -->0x20     
	TOS_AUDIO_MUTE_MHEG, 						  ///<控制SPDIF  -->0x40
	TOS_AUDIO_MUTE_SCAN, 						  ///<控制SPDIF -->0x80
	TOS_AUDIO_MUTE_CHANGE_CHANNEL, 				  ///<控制SPDIF -->0x100
	TOS_AUDIO_MUTE_CHANGE_LINEIN, 				  ///<控制SPDIF -->0x200
	TOS_AUDIO_MUTE_INTER, 						  ///<控制SPDIF ,功放 -->0x400
	TOS_AUDIO_MUTE_CHILDREN_LOCK,				  ///<儿童锁    -->0x800
	TOS_AUDIO_MUTE_HIGHEST, 					  ///<控制SPDIF ,功放   -->0x1000
	TOS_AUDIO_MUTE_SCART,     					  ///<控制SPDIF-->0x2000
	TOS_AUDIO_MUTE_HP_PLUGIN    = 31  			  ///<控制SPDIF-->0x80000000
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
	EN_TOS_AUDIO_CHANNEL_NORMAL, ///<TV通道的声音，即各个信源本身的声音
	EN_TOS_AUDIO_CHANNEL_AD,///<AD和TV通道的声音
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
    int32_t describe_Contents; //暂时不用，默认为0
    char audioLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string 类型,默认当前audio language
    int32_t current_audio_language_index;
    char currentLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string 类型,默认当前audio language
    int32_t digital_mts; //声道，具体指左右立体声 EN_TOS_DTV_STEREO_MODE digital_channel; //声道，具体指左右立体声
    int32_t total_number; //当前节目总数
    EN_TOS_AUDIO_TYPE audioType; //音频类型
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
    EN_TOS_MTS_TYPE     html_ui_mts_mode;    //set 需要
    uint8_t             html_set_idx;        //set 需要
    uint8_t             html_mode_total_item;  //get 需要
    uint8_t             html_reserved[2];
    EN_TOS_AUDIO_MTS_TYPE      html_mode_include_type[TOS_MTS_UI_ITEM_MAX];//get 需要
}st_tos_mts_info_t;

typedef struct
{
   uint8_t audioCount;
   uint8_t curAudioIdx;
   st_tos_audio_info stAudInfo[TOS_MAX_AUD_LANG_NUM];
   int32_t langCode[TOS_MAX_AUD_LANG_NUM]; //MEMBER_LANGUAGE
   uint8_t audioSelCount; //当前音频个数
   uint8_t audioAdMixed[TOS_MAX_AUD_LANG_NUM];
   uint8_t audioMainMixed[TOS_MAX_AUD_LANG_NUM];
   fpi_bool Is_CurrentPID_DualMono;
}st_tos_audio_language_info;

typedef struct
{
    int32_t alternative_audio; //暂时没用
    int32_t mts; //声道，具体指左右立体声0x00 -->STEREO,立体声，0x01--> LL,左声道 , 0x02 --> RR,右声道
}st_tos_audio_information; 

/*typedef struct
{
    int32_t describe_Contents; //暂时不用，默认为0
    char audioLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string 类型,默认当前audio language
    int32_t current_audio_language_index;
    char currentLanguage[TOS_DTV_AUDIO_LANGUAGE_LENGTH]; //string 类型,默认当前audio language
    int32_t digital_mts; //声道，具体指左右立体声
    int32_t total_number; //当前节目总数
    EN_TOS_AUDIO_TYPE audioType; //音频类型
}st_tos_audio_language_information;
*/

/** 
@brief 设置静音

@param [in] mute_level 设置静音的原因，取值范围见AUDIO_MUTE_LEVEL 枚举

@param [in] b_mute 

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

@note    该接口不能为不同的音频设备设置静音不推荐使用
*/
fpi_error tos_audio_set_mute(int16_t mute_level, int16_t b_mute, EN_ACT_CTRL act );

/** 
@brief 获得指定原因对应的静音状态

@param [in] mute_level 设置静音的原因，取值范围见AUDIO_MUTE_LEVEL 枚举

@param [out] b_mute 

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

@note    该接口不能为不同的音频设备设置静音不推荐使用
*/
fpi_error tos_audio_get_mute(int16_t mute_level,int16_t *mute);

/** 
@brief 设置音频设备的输出音量

@param [in] volume 用户设置的音量值，取值范围0-100

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

@note    该接口不能为不同的音频设备设置音量不推荐使用
*/
fpi_error tos_audio_set_volume(int16_t volume, EN_ACT_CTRL act);

/** 
@brief 获取音频设备 的输出音量

@param [out] volume 用户设置的音频设备 音量值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

@note    该接口不能获取不同音频设备的音量不推荐使用
*/
fpi_error tos_audio_get_volume(int16_t *volume);

/** 
@brief 为不同的音频输出设备设置静音

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [in] ch_reason 设置静音的原因

@param [in] b_mute 

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev,  char* ch_reason, int16_t b_mute, EN_ACT_CTRL act );

/** 
@brief 获取指定音频输出设备指定原因的静音状态

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [in] ch_reason 设置静音的原因

@param [out] state 静音的状态

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_mute_ex( EN_TOS_AUDIO_DEVICE_TYPE en_dev,  char* mute_reason, int16_t* state );

/** 
@brief 设置指定音频输出设备指定通道的输出音量

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [in] input    输入音频的通道类型，取值范围见EN_TOS_AUDIO_INPUT_TYPE 枚举

@param [in] volume 设置的音量值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_volume_ex(EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input,int16_t volume, EN_ACT_CTRL act);


/** 

@brief 获取指定音频输出设备指定通道的输出音量

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [in] input    输入音频的通道类型，取值范围见EN_TOS_AUDIO_INPUT_TYPE 枚举

@param [out] volume 设置的音量值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

*/
fpi_error tos_audio_get_volume_ex(EN_TOS_AUDIO_DEVICE_TYPE dev, EN_TOS_AUDIO_INPUT_TYPE input,int16_t *volume);

/** 
@brief获取最大输出音量

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n
                              
                   该参数预留扩展功能暂时无作用，调用者可忽略
                   
@param [out] value 酒店菜单或lock 菜单设置的最大音量值(酒店菜单的最大音量优先)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

@note 这个接口有问题，不应该将酒店的最大音量包含进来

*/

 fpi_error tos_audio_get_max_volume(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *value);

/** 
@brief 设置最大输出音量

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n
                              
                   该参数预留扩展功能暂时无作用，调用者可忽略
                   
@param [in] maxVolume 最大音量值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/

fpi_error tos_audio_set_max_volume(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t maxVolume,EN_ACT_CTRL act);


/** 
@brief 设置指定外部输入设备的静音

@param [in] en_dev 外部输入设备的类型，取值范围见EN_TOS_AUDIO_INPUT 枚举
                   
@param [in] mute    设置的mute 状态

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_input_mute(EN_TOS_AUDIO_INPUT input, int16_t mute,EN_ACT_CTRL act);

/** 
@brief 获取指定外部输入设备的静音状态

@param [in] en_dev 外部输入设备的类型，取值范围见EN_TOS_AUDIO_INPUT 枚举
                   
@param [out] mute    设置的mute 状态

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_input_mute(EN_TOS_AUDIO_INPUT input, int16_t *mute);

/** 
@brief 设置指定外部输入设备的音量

@param [in] en_dev 外部输入设备的类型(麦克风等)，取值范围见EN_TOS_AUDIO_INPUT 枚举
                   
@param [in] soundValue    设置的音量值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

*/
fpi_error tos_audio_set_input_volume(EN_TOS_AUDIO_INPUT input, int16_t soundValue, EN_ACT_CTRL act);

/** 
@brief 获取指定外部输入设备的音量

@param [in] en_dev 外部输入设备的类型(麦克风等)，取值范围见EN_TOS_AUDIO_INPUT 枚举
                   
@param [out] soundValue    音量值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_input_volume(EN_TOS_AUDIO_INPUT input, int16_t *soundValue);

/** 
@brief 设置音效模式

@param [in] mode    设置的音效模式，取值范围见EN_TOS_SOUND_MODE 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_equalizer_mode(EN_TOS_SOUND_MODE mode,EN_ACT_CTRL act);

/** 
@brief 获取当前设置的音效模式

@param [out] value    当前设置的音效模式，取值范围见EN_TOS_SOUND_MODE 枚举

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值

*/
fpi_error tos_audio_get_equalizer_mode(EN_TOS_SOUND_MODE *value);

/** 
@brief 设置指定频段的均衡值

@param [in] type    设置的频段类型，取值范围见EN_TOS_SOUND_EQUALIZER_TYPE 枚举

@param [in] value    设置的均衡值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_equalizer(EN_TOS_SOUND_EQUALIZER_TYPE type,int16_t value,EN_ACT_CTRL act);

/** 
@brief 获取指定频段的均衡值

@param [in] type    设置的频段类型，取值范围见EN_TOS_SOUND_EQUALIZER_TYPE 枚举

@param [out] value    设置的均衡值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_equalizer(EN_TOS_SOUND_EQUALIZER_TYPE type,int16_t *value);


/** 
@brief 设置指定音频输出设备的平衡值

@param [in] dev    音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n

@param [in] value    设置的平衡值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_balance(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t value,EN_ACT_CTRL act);

/** 
@brief 获取指定音频输出设备的平衡值

@param [in] dev    音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n

@param [out] value    返回当前指定音频输出设备设置的平衡值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_balance(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *value);


/** 
@brief 设置自动音量的状态(控制SOC芯片的自动音量开关)

@param [in] enable    设置的自动音量状态

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_auto_volume(int16_t enable,EN_ACT_CTRL act);

/** 
@brief 获取自动音量的状态(控制SOC芯片的自动音量开关)

@param [out] enable    返回当前设置的自动音量状态

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_auto_volume(int16_t *enable);

/** 
@brief 设置设备的声音延迟

@param [in] dev    音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n

@param [in] delay  设置延迟的值，以ms为单位,不同项目有不同的取值范围(欧洲新规-50到1000)

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_delay(EN_TOS_AUDIO_DEVICE_TYPE dev,int32_t delay,EN_ACT_CTRL act);

/** 
@brief 获取设备声音延迟值

@param [in] dev    音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举\n

@param [out] delay  设置延迟的值，以ms为单位,不同项目有不同的取值范围(欧洲新规-50到1000)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_delay(EN_TOS_AUDIO_DEVICE_TYPE dev,int32_t *delay);

/** 
@brief 设置立体声效果

@param [in] mode    设置的立体声的类型,取值范围见EN_TOS_STEREO_MODE 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_wide_stereo(EN_TOS_STEREO_MODE mode,EN_ACT_CTRL act);

/** 
@brief 获取当前设置立体声的类型

@param [out] value    返回当前设置的立体声的类型

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_wide_stereo(EN_TOS_STEREO_MODE *value);

/** 
@brief 设置数字输出的格式

@param [in] type    设置的SPDIF 类型,取值范围见EN_TOS_SPDIF_TYPE 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_spdif_type(EN_TOS_SPDIF_TYPE type,EN_ACT_CTRL act);

 /** 
 @brief 获取数字输出的格式
 
@param [out] value    返回当前设置的SPDIF 类型,取值范围见EN_TOS_SPDIF_TYPE 枚举
 
@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_spdif_type(EN_TOS_SPDIF_TYPE *value);


/** 
@brief 获取视觉障碍功能的状态

@param [out] state  视觉障碍功能的状态,0为off,1为on

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_visual_impaired(int16_t *state);

/** 
@brief 设置视觉障碍功能的开关

@param [in] state  设置的视觉障碍功能的状态,0为off,1为on

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_visual_impaired(int16_t state,EN_ACT_CTRL act);

/** 
@brief 设置音频描述功能的开关

@param [in] enable  设置的音频描述功能的状态,0为disable,1为enable

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_audio_description(int16_t enable,EN_ACT_CTRL act);

/** 
@brief 获取音频描述功能的状态

@param [out] enable  音频描述功能的状态,0为disable,1为enable

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_audio_description(int16_t *enable);

/** 
@brief 设置音频描述功能的声音级别(tvos 2.0已弃用，复用到tos_audio_set_volume_ex接口)

@param [in] level	设置的音频描述功能的声音级别,值范围为0-100

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_audio_description_mix_level(uint16_t level,EN_ACT_CTRL act);

/** 
@brief 获取音频描述功能的声音级别(tvos 2.0已弃用，复用到tos_audio_get_volume_ex接口)

@param [out] value	设置的音频描述功能的声音级别,值范围为0-100

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_audio_description_mix_level(uint16_t *value);

/** 
@brief 获取丽音的相关信息

@param [out] audioInfo	相关丽音的描述

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_mts_info(st_tos_mts_info_t *audioInfo);

/** 
@brief 设置丽音的类型

@param [in] audioInfo 相关丽音类型，请看EN_TOS_AUDIO_MTS_TYPE枚举定义

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_mts_info(st_tos_mts_info_t *audioInfo,EN_ACT_CTRL act);


/** 
@brief 获取当前播放流的音频stream信息

@param [out] info 相关播放音频stream的信息，详情请看st_tos_audio_language_info的结构体描述

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_language_info(st_tos_audio_language_info *info);


/** 
@brief 设置当前播放流的音频语言

@param [in] audioIndex 音频语言的索引值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_language_index(uint8_t audioIndex,EN_ACT_CTRL act);

/** 
@brief 获得声音设备使用的场景设置

@param [out] scene 0为桌面模式，1为壁挂模式

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_scene(EN_TOS_AUDIO_SCENE *scene);

/** 
@brief 设置当前声音设备的使用场景

@param [in] scene 0为桌面模式，1为壁挂模式

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_scene(EN_TOS_AUDIO_SCENE scene,EN_ACT_CTRL act);

/** 
@brief 获取声音播放设备的接入状态(headphone是可以通过读取GPIO口的状况可以查询。speaker，spdif
       是通过IIC或者GPIO口查询需要向NTK了解。中间件慢慢会取消通过GPIO方式去或者状态，代替实现方法未知

@param [in] en_dev 音频输出设备的类型，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [out] isplugin 相关插入状态适设备而定

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_dev_plugin(EN_TOS_AUDIO_DEVICE_TYPE dev,int16_t *isplugin);

/** 
@brief 得到当前声音源所支持的声道数目

@param [in] type 取值范围见EN_TOS_AUDIO_INPUT_INFO 枚举

@param [out] value 声道数目

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_source_info(EN_TOS_AUDIO_INPUT_INFO type,int16_t *value);

/** 
@brief 根据信源(目前只支持DTV)，获取当前信源下播放的音频stream信息

@param [in] input 信源，取值范围见EN_API_SOURCE_INPUT 枚举

@param [out] dAudioInfo 音频stream信息

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_language_information(EN_API_SOURCE_INPUT input,st_audio_language_information *dAudioInfo) ;

/** 
@brief 根据信源(目前只支持DTV)，设置当前信源下播放的音频stream信息

@param [in] input 信源，取值范围见EN_API_SOURCE_INPUT 枚举

@param [in] dAudioInfo 音频stream信息

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_language_information(EN_API_SOURCE_INPUT input,st_audio_language_information *dAudioInfo,EN_ACT_CTRL act) ;

/** 
@brief 获取耳机状态，speaker是否enable

@param [out] enable 0为disable，1为enable

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_speaker_enable(int16_t *enable);

/** 
@brief 设置耳机状态，speaker是否enable

@param [in] enable 0为disable，1为enable

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/

fpi_error tos_audio_set_speaker_enable(int16_t enable,EN_ACT_CTRL act);


/** 
@brief 设置dtv的声道模式

@param [in] mode 包含左声道、右声道和立体声，取值范围见EN_TOS_DTV_STEREO_MODE 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_dtv_stereo_sound_mode(EN_TOS_DTV_STEREO_MODE mode,EN_ACT_CTRL act);

/** 
@brief 设置当前音频输出设备音频stream的类型

@param [in] dev 信源，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [in] decoder_type 目前支持MAIN和MAIN+AD,取值范围见EN_TOS_AUDIO_DECODER_CHANNEL_TYPE 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_output_device_mix_type(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DECODER_CHANNEL_TYPE decoder_type,EN_ACT_CTRL act);

/** 
@brief 获取当前音频输出设备音频stream的类型

@param [in] dev 信源，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [out] decoder_type 目前支持MAIN和MAIN+AD,取值范围见EN_TOS_AUDIO_DECODER_CHANNEL_TYPE 枚举

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_output_device_mix_type(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DECODER_CHANNEL_TYPE *decoder_type);

 /** 
 @brief 存储音频设备的on-off状态，上层实现逻辑，中间件只做存储操作
 
 @param [in] dev 信源，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举
 
 @param [in] status 取值范围见EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS 枚举
 
 @param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)
 
 @retval  成功返回FPI_ERROR_SUCCESS;
 
 @retval  失败返回其他值
 */
fpi_error tos_audio_set_audDevice_output_onOff(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS status,EN_ACT_CTRL act);

/** 
@brief 获取音频设备的on-off的存储状态，上层实现逻辑，中间件只做存储操作

@param [in] dev 信源，取值范围见EN_TOS_AUDIO_DEVICE_TYPE 枚举

@param [out] status 取值范围见EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS 枚举

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_audDevice_output_onOff(EN_TOS_AUDIO_DEVICE_TYPE dev,EN_TOS_AUDIO_DEVICE_OUTPUT_STATUS *status);

/** 
@brief audio设置值的通用接口

@param [in] type 设置值的类型，取值范围见EN_TOS_AUDIO_VALUE_TYPE 枚举

@param [in] value 设置类型的值，视乎于设置类型的范围

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_value(EN_TOS_AUDIO_VALUE_TYPE type ,int16_t value,EN_ACT_CTRL act);

/** 
@brief 获取audio设置值的通用接口

@param [in] type 设置值的类型，取值范围见EN_TOS_AUDIO_VALUE_TYPE 枚举

@param [out] value 设置类型的值，视乎于设置类型的范围

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_value(EN_TOS_AUDIO_VALUE_TYPE type ,int16_t *value);

/** 
@brief 用于控制TCL自住音效算法的运行状态

@param [in] type 算法的类型(目前有智能音量和虚拟低音两种)，取值范围见EN_TOS_TCL_SUDEFFECT_TYPE 枚举

@param [in] mode 运行状态，0为off，1为on

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_tcl_sound_effects_mode(EN_TOS_TCL_SUDEFFECT_TYPE type,EN_TOS_TCL_SUDEFFECT_MODE mode ,EN_ACT_CTRL act);

/** 
@brief 获取TCL自住音效算法的运行状态

@param [in] type 算法的类型(目前有智能音量和虚拟低音两种)，取值范围见EN_TOS_TCL_SUDEFFECT_TYPE 枚举

@param [out] mode 运行状态，0为off，1为on

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_tcl_sound_effects_mode(EN_TOS_TCL_SUDEFFECT_TYPE type,EN_TOS_TCL_SUDEFFECT_MODE* mode);

/** 
@brief 用来控制Input Stream是Dolby Digital Plus的时候，是否通过HDMI ARC 输出Dolby Digital Plus raw data到外部功放

@param [in] mode 控制状态，0为off，1为on

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_spdif_dobly_digital_plus_mode(EN_TOS_SPDIF_DDP_MODE mode,EN_ACT_CTRL act);

/** 
@brief 用来获取Input Stream是Dolby Digital Plus的时候，HDMI ARC 输出Dolby Digital Plus raw data到外部功放的状态

@param [out] mode 控制状态，0为off，1为on

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_spdif_dobly_digital_plus_mode(EN_TOS_SPDIF_DDP_MODE *mode);

/** 
@brief 设置dobly ms12 相关参数和状态;Dobly MS12认证需要

@Param [in] type 技术参数设置项的类型，取值范围见EN_TOS_DOLBY_MS12_SETTING_TYPE 枚举

@Param [in] value 设置的值

@param [in] EN_ACT_CTRL 函数执行的类型(只执行，只保存，执行后保存)

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_set_dobly_ms12_setting(EN_TOS_DOLBY_MS12_SETTING_TYPE type,int16_t value,EN_ACT_CTRL act);

/** 
@brief 获取dobly ms12 相关参数和状态

@Param [in] type 需要获取技术参数设置项的类型 ，取值范围见EN_TOS_DOLBY_MS12_SETTING_TYPE 枚举

@Param [out] value 相关设置项的db值 

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_get_dobly_ms12_setting(EN_TOS_DOLBY_MS12_SETTING_TYPE type,int16_t *value);

/** 
@brief 重置sound页面相关参数设定
	   由于相关参数在任何一种MS12音效模式下都需要可以调整并保存,所以执行"声音页面-恢复默认设置"选项时,
	   会从audio/para.ini读取相关设置项的默认值并重置ms12_setting db table的所有值

@retval  成功返回FPI_ERROR_SUCCESS;

@retval  失败返回其他值
*/
fpi_error tos_audio_reset_sound_setting(void);

#ifdef __cplusplus
}
#endif
/** @} */

#endif
