/**@defgroup ͼ������
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/



#ifndef __TOS_PICTURE_SETTING_H__
#define __TOS_PICTURE_SETTING_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"


#include "tos_input_source.h"



#ifdef __cplusplus
extern "C" {
#endif

/**
@brief ͼ��λ�ĸ�������
**/
typedef enum
{
	EN_PICTURE_DEFAULT,///<�ָ�ͼ��Ĭ��ֵ
	EN_PICTURE_COLOR_GAMMA, ///<��λ ��ɫͨ����gamma ֵ
	EN_PICTURE_COLOR_SPACE, ///<��λɫ�ʿռ�
	EN_PICTURE_MOTION_CLARITY,///<��λMEMC���ܵĳ�ʼֵ
		
}EN_PICTURE_TYPE;



/**
@brief 2D3Dģʽ
**/
typedef enum
{
	EN_VIDEO_2D, ///2d video mode
	EN_VIDEO_3D,///3d mode
	EN_VIDEO_GRAPHIC ///PC mode
}EN_VIDEO_MODE;




/**
@brief DBC message
**/

typedef enum
{
	EN_DBC_DEFAULT = 0,
	EN_DBC_GRAPHIC,
	EN_DBC_EPG_ON,
	EN_DBC_EPG_OFF,
	EN_DBC_TV,
    EN_DBC_VIDEO_PLAY,  // Start VIDEO play
    EN_DBC_VIDEO_EXIT,  // Exit VIDEO play
    EN_DBC_INITIAL_ON,  // Initial setup display
    EN_DBC_INITIAL_OFF,  // Initial setup hide
    EN_DBC_P_MODE_ON,
    EN_DBC_P_MODE_OFF,
    EN_DBC_MIX_DIMMING_PAGE_ON,
    EN_DBC_MIX_DIMMING_PAGE_OFF
}EN_TOS_MSG_TO_DBC;


/**
@brief memc��BLUR ,DEJUDDER ��Ч��
**/
typedef enum
{
	EN_MEMC_EFFECT_BLUR, //memc blur 
	EN_MEMC_EFFECT_DEJUDDER,///memc dejudder
}EN_MEMC_EFFECT_TYPE;




/**
@brief 4K2K,4K1Kת��
**/
typedef enum
{
	EN_RESOLUTION_4K2K,///panel 4k2k
	EN_RESOLUTION_4K1K,///panel 4k1k
}EN_RESOLUTION_TYPE;

/**
@brief ͼ��ģʽ
**/
typedef enum
{
	E_PICTURE_MODE_STANDARD= 0, // standard
	E_PICTURE_MODE_BRIGHT,//bright
	E_PICTURE_MODE_SOFT,     //soft
	E_PICTURE_MODE_STUDIO,//moive
    E_PICTURE_MODE_USER,    //Personal
    E_PICTURE_MODE_EX1,    //HDR
    E_PICTURE_MODE_STADIUM,  //stadium
    E_PICTURE_MODE_DIGITAL_CINEMA, ///digital cinema

	E_PICTURE_MODE_DOBLY_BRIGHT, ///dobly vision bright
	E_PICTURE_MODE_DOBLY_SOFT,///dobly soft
	E_PICTURE_MODE_DOBLY_VIVID,///dobly vivid
	E_PICTURE_MODE_DOBLY_ECO, ///dobly eco
	E_PICTURE_MODE_DOBLY_USER,///dobly user

	E_PICTURE_MODE_HDR10_BRIGHT, ///hdr10 bright
	E_PICTURE_MODE_HDR10_SOFT,///hdr10 soft
	E_PICTURE_MODE_HDR10_ECO,///hdr10 eco
	E_PICTURE_MODE_HDR10_USER,///hdr10 user

	E_PICTURE_MODE_NUM
}EN_FPI_PICTURE_MODE;






/**
@brief ��Ч����
**/
typedef enum
{
    EN_ENERGY_SAVING_OFF,
    EN_ENERGY_SAVING_LOW,
    EN_ENERGY_SAVING_HIGH,
    EN_ENERGY_SAVING_HDR,
    EN_ENERGY_SAVING_NUM
}EN_FPI_ENERGY_SAVING;

/**
@brief �������г���
**/
typedef enum
{
	EN_BACKLIGHT_RUNNING , ///<�豸�������еı���״̬
	EN_BACKLIGHT_POWER,   ///<�豸�ڵ�Դ�������߹رյı���״̬���漰������mboot
}EN_BACKLIGHT_STATE;

/**
@brief ���ε������
**/
typedef enum
{
    EN_GEO_MANUAL,
    EN_GEO_AUTO,
    EN_GEO_NUM
} EN_FPI_PICTURE_GEO_ADJUST_TYPE;
/**
@brief HDMIͼ������
**/
typedef enum
{
    EN_PICTURE_TYPE_AUTO, ///auto
    EN_PICTURE_TYPE_PC, ///pc
    EN_PICTURE_TYPE_VIDEO,///video
    EN_PICTURE_TYPE_GAME,///game
    EN_PICTURE_TYPE_MAX,
}EN_FPI_PICTURE_TYPE;

//mute ����                
typedef enum
{
    EN_FPI_VIDEO_MUTE_EXTERNAL1 = 0x00000001, // 0x01
    EN_FPI_VIDEO_MUTE_EXTERNAL2 = 0x00000002, // 0x02
    EN_FPI_VIDEO_MUTE_FACTORY = 0x00000004,  //0x04
    EN_FPI_VIDEO_MUTE_BY_COLOR = 0x00000008, //0x08
    EN_FPI_VIDEO_MUTE_PVR = 0x00000010, // 0x10
    EN_FPI_VIDEO_MUTE_MHEG = 0x00000020, // 0x20
    EN_FPI_VIDEO_MUTE_SYNC = 0x00000040, //0x40 /*signal sync --> lock/unlock */
    EN_FPI_VIDEO_MUTE_PLAY = 0x00000080, //0x80 
    EN_FPI_VIDEO_MUTE_LOCK = 0x00000100, // 0x100 /* channel lock/input lock/...*/
    EN_FPI_VIDEO_MUTE_ENTERNAL1 = 0x00000200, //0x200
    EN_FPI_VIDEO_MUTE_ENTERNAL2 = 0x00000400, //0x400
    EN_FPI_VIDEO_MUTE_SCAN = 0x00000800,         //0x800
    EN_FPI_VIDEO_MUTE_CHANGE_CHANNEL = 0x00001000, // 0x1000
    EN_FPI_VIDEO_MUTE_CHANGE_LINEIN = 0x00002000, //0x2000
    EN_FPI_VIDEO_MUTE_ZOOM = 0x00004000, //0x4000
    EN_FPI_VIDEO_MUTE_HBBTV = 0x00008000, //0x8000
    EN_FPI_VIDEO_MUTE_CHILDREN_LOCK= 0x00010000, //linshunda,��ͯ��
    EN_FPI_VIDEO_MUTE_SCART    = 0x00020000, //lilijun: mute for scart 
    EN_FPI_VIDEO_MUTE_STILL_IMG = 0x00040000, //lilijun: mute for still image 
    EN_FPI_VIDEO_MUTE_DECODER =  0x00080000, // mute for still video_decoder 
    EN_FPI_VIDEO_MUTE_MEDIA = 0x00100000, // for multimedia
    EN_FPI_VIDEO_MUTE_LV_ANY = 0xffffffff
}EN_FPI_VIDEO_MUTE_LEVEL;



/**
@brief ͼ������
**/
typedef struct
{
    uint32_t mask;    // mask to judge which attriute to access
    int32_t DTVDisplayAspectRatioValue;          //--->PIC_ATTRI_DTV_DISPLAY_ASPECT_RATIO_MASK
    int32_t DTVVideViewValue;                    //--->PIC_ATTRI_DTV_VIDEO_VIEW_MASK
    
  
}st_fpi_picture_attributes;


typedef enum
{
    E_PIXEL_STAGE_AFTER_DLC,
    E_PIXEL_STAGE_AFTER_OSD,  
    E_PIXEL_STAGE_PRE_GAMMA,
    E_PIXEL_STAGE_MAX,
}EN_FPI_PIXEL_RGB_STAGE;

/**
@brief VGA��Դ�Ĳ���
**/
typedef enum
{
	EN_VGA_HPOS,
	EN_VGA_VPOS,
	EN_VGA_PHASE,
	EN_VGA_CLOCK,
	EN_VGA_AUTO_ADJUST, ///< 0 Ϊ�ֶ���1Ϊ�Զ�����
}EN_VGA_PARA_CTRL;

typedef enum
{
    E_SRC_TYPE_CURRENT = 0, ///current source
    E_SRC_TYPE_ALL  ///all source
}EN_TOS_SOURCE_TYPE;

typedef struct 
{
    fpi_bool showRepWin;
    EN_FPI_PIXEL_RGB_STAGE stage;
    int32_t tmpStage;
    int16_t BCbMax;
    int16_t BCbMin;
    int16_t GYMax;
    int16_t GYMin;

    int16_t RCrMax;
    int16_t RCrMin;
    int16_t reportPixelInfoLength;
    int16_t RepWinColor;

    int16_t XEnd;
    int16_t XStart;
    int16_t YEnd;
    int16_t YStart;


    int32_t BCbSum;
    int32_t GYSum;
    int32_t RCrSum;
    int32_t reportPixelInfoVersion;

}st_fpi_screen_pixel_info;

typedef struct
{
	uint16_t 			x; //x
	uint16_t 			y; //y
	uint16_t 			width;     //w
	uint16_t 			height;     //h
}st_fpi_osd_window;

#define VIDEO_HD_BOUNDS           720

/**
@brief      	  tos_picture_set_mode      
			  ���û򱣴�ͼЧģʽ
@param [in]	 e_src_type  ��������Դ�����ͣ�����ο�ö��EN_TOS_SOURCE_TYPE˵��
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��ͼЧ	�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��ͼЧ�����Ըò���Ŀ		 
						   ǰ��ʱû���õ�
@param [in]	 mode  ͼЧģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�ģʽ(EN_ACT_EXEC)
			  	   							ֻ�������õ�ģʽ(EN_ACT_SAVE)
			  	   							��ִ������ģʽ���������õ�ģʽ��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_set_mode(EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode,EN_FPI_PICTURE_MODE mode,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_mode
			��ȡ��ǰ���õ�ͼЧ
@param [in]	 e_src_type  ��������Դ�����ͣ�����ο�ö��EN_TOS_SOURCE_TYPE˵��
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��ͼЧ	�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��ͼЧ�����Ըò���Ŀǰ��ʱû���õ�	
@param[out]  value  ��ȡ���ĵ�ǰ���õ�ģʽ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_picture_get_mode(EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode,EN_FPI_PICTURE_MODE *mode);

/** 
@brief ����ͼ����3D����2D�µı��⡣

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_picture_set_backlight(EN_VIDEO_MODE e_mode,uint16_t value ,EN_ACT_CTRL act );

/** 
@brief ���ͼ����2D����3D�µı���

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_picture_get_backlight(EN_VIDEO_MODE e_mode,uint16_t *value);


/**
@brief      	  tos_picture_set_brightness      
			  ���û򱣴�ͼ����ʾ������	
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param [in]	 value  ���Ȳ���
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õĲ���(EN_ACT_EXEC)
			  	   							ֻ�������õĲ���(EN_ACT_SAVE)
			  	   							��ִ�����ò������������õĲ�����������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_set_brightness(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);
/**
@brief		tos_picture_get_brightness
			��ȡ��ǰ���õ����Ȳ���
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õ����Ȳ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_picture_get_brightness(EN_VIDEO_MODE e_mode,uint16_t *value);



/** 
@brief ����ͼ����2D����3D�µĶԱȶ�

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_set_contrast(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);


/** 
@brief ���ͼ����2D����3D�µĶԱȶ�

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_get_contrast(EN_VIDEO_MODE e_mode,uint16_t *value);


/**
@brief      	  tos_picture_set_sharpness      
			  ���û򱣴�ͼ����ʾ�����	
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param [in]	 value  ��Ȳ���
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õĲ���(EN_ACT_EXEC)
			  	   							ֻ�������õĲ���(EN_ACT_SAVE)
			  	   							��ִ�����ò������������õĲ�����������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_picture_set_sharpness(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);


/**
@brief		tos_picture_get_sharpness
			��ȡ��ǰ���õ���Ȳ���
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õĲ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

 fpi_error tos_picture_get_sharpness(EN_VIDEO_MODE e_mode,uint16_t * value);



/**
@brief      	  tos_picture_set_saturation      
			  ���û򱣴�ͼ����ʾ�ı��Ͷ�
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param [in]	 value  ���ͶȲ���
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õĲ���(EN_ACT_EXEC)
			  	   							ֻ�������õĲ���(EN_ACT_SAVE)
			  	   							��ִ�����ò������������õĲ�����������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_set_saturation(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_saturation
			��ȡ��ǰ���õı��ͶȲ���
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õĲ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_picture_get_saturation(EN_VIDEO_MODE e_mode,uint16_t *value);



/**
@brief      	  tos_picture_set_hue      
			  ���û򱣴�ͼ����ʾ��ɫ��
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param [in]	 value  ɫ������
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õĲ���(EN_ACT_EXEC)
			  	   							ֻ�������õĲ���(EN_ACT_SAVE)
			  	   							��ִ�����ò������������õĲ�����������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_set_hue(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_hue
			��ȡ��ǰ���õ�ɫ������
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��״̬�����Ա��治ͬ��״̬��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��״̬�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õĲ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_picture_get_hue(EN_VIDEO_MODE e_mode,uint16_t *value);





/** 
@brief ������Ч����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_set_energy_saving(EN_FPI_ENERGY_SAVING level,EN_ACT_CTRL act);
/** 
@brief �����Ч����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_get_energy_saving(EN_FPI_ENERGY_SAVING *value);

/** 
@brief �������߹رձ���

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_picture_set_backlight_state(EN_BACKLIGHT_STATE state,int16_t bOnOff,EN_ACT_CTRL act);

/** 
@brief ��ñ��⿪�����߹ر�״̬

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_get_backlight_state(EN_BACKLIGHT_STATE state,int16_t *bOnOff);



/**
@brief		tos_picture_get_video_freeze
			��ȡ��ǰ�����Ƿ񶳽�
@param[out]  value  ��ȡ���ĵ�ǰ���õĲ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_picture_get_video_freeze(int16_t *state);


/**
@brief      	  tos_picture_set_video_freeze      
			  ���û��涳��
@param [in]	 state  ����
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_picture_set_video_freeze(int16_t state,EN_ACT_CTRL act);


/**
@brief      	  tos_picture_reset      
			   �ָ�ͼ��ҳ����һЩ�������Ĭ��ֵ
@param [in]	 type  ���幦�������ο�ö��EN_PICTURE_TYPE˵��
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_reset(EN_PICTURE_TYPE type);



/**
@brief      	  tos_picture_set_hdmi_type      
			  ����HDMI��ͼ������
@param [in]	 type  ͼ�����Ͳ���
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õĲ���(EN_ACT_EXEC)
			  	   							ֻ�������õĲ���(EN_ACT_SAVE)
			  	   							��ִ�����ò������������õĲ�����������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_set_hdmi_type(EN_FPI_PICTURE_TYPE type,EN_ACT_CTRL act);


/**
@brief		tos_picture_get_hdmi_type
			��ȡ��ǰ���õ�HDMIͼ������
@param[out]  type  ��ȡ���ĵ�ǰ���õĲ���
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_picture_get_hdmi_type( EN_FPI_PICTURE_TYPE *type);





/** 
@brief ������߷ֱ���ģʽ

@note  ����4K2K,4K1Kģʽ

@note  ����δ�ã�

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_enter_resolution_mode(EN_RESOLUTION_TYPE type,int32_t mode,EN_ACT_CTRL act);




/** 
@brief ���˳��߷ֱ���ģʽ

@note  ����4K2K,4K1Kģʽ

@note ����δ�ã�

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_exit_resolution_mode(EN_RESOLUTION_TYPE type,int32_t mode,EN_ACT_CTRL act);

/** 
@brief ���Ƿ���ĳһ�߷ֱ���ģʽ

@note  ����4K2K,4K1Kģʽ

@note  ����δ�ã�

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_is_resolution_mode(EN_RESOLUTION_TYPE type,int16_t *flag);




/**
@brief      	  tos_picture_get_pixel_info      
			  ��ȡָ�������ͼ�����ԣ���Ҫ��ȡ�����ݣ�Ŀǰ��Ҫ��Ҫ��ȡ��ǰ�����R/G/B���ܺͣ���ָ��ָ��һ�������������ά�����ڴ棬�ײ�ֱ��������ݼ��ɣ��Ҳ����ͷţ�
@param [in]	 startX  ���X����
@param [in]	 startY  ���Y����
@param [in]	 endX    �յ�X����
@param [in]	 endY    �յ�Y����
@param [in]	 info Ҫ��ȡ��ǰ�����R/G/B���ܺ� 
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_picture_get_pixel_info(int32_t startX,int32_t startY,int32_t endX,int32_t endY,st_fpi_screen_pixel_info* info);


/** 
@brief �������ڵ�ͼ����ʾ���

@note һ��������Ȼ���㷨�����ݲ�ͬ��ͼ��ģʽ����Ȼ���㷨�л��в��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_set_display_condition(EN_TOS_MSG_TO_DBC msg,EN_ACT_CTRL act);

/** 
@brief �������ڵ�ͼ����ʾ���

@note һ��������Ȼ���㷨�����ݲ�ͬ��ͼ��ģʽ����Ȼ���㷨�л��в��

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_get_display_condition(EN_TOS_MSG_TO_DBC *msg);


/** 
@brief ����VGA�µ�ͼ�� ����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/	
fpi_error tos_picture_vga_set_para(EN_VGA_PARA_CTRL type,uint16_t value,EN_ACT_CTRL act);

/** 
@brief ���VGA�µ�ͼ�����

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_picture_get_vga_para(EN_VGA_PARA_CTRL type,uint16_t *value);

/**
@brief      	  tos_picture_memc_bypass_osd      
			  �����˶�������OSD����
@param [in]	 stOsdWindow  OSD�����������Ϣ
@param [in]	 mode OSD�Ƿ���ʾ��0��ʾOSD��ʾ��1��ʾOSD����  
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_picture_memc_bypass_osd( st_fpi_osd_window* stOsdWindow, int8_t mode );


/** 
@brief ������Ƶ���ػ�

@param[in]mute_mask, ʹ��mute_mask����һλ�����ڴ���ӣ���ע������ 
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_picture_video_mute(uint32_t mute_mask, fpi_bool b_mute);


/** 
@brief ������Ƶ���ػ�

@param[in]reason, mute �� unmute ԭ ��
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_picture_set_video_mute_with_reason( char* reason, fpi_bool b_mute);


#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
