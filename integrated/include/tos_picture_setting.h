/**@defgroup 图像设置
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
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
@brief 图像复位的各个功能
**/
typedef enum
{
	EN_PICTURE_DEFAULT,///<恢复图像默认值
	EN_PICTURE_COLOR_GAMMA, ///<复位 颜色通道的gamma 值
	EN_PICTURE_COLOR_SPACE, ///<复位色彩空间
	EN_PICTURE_MOTION_CLARITY,///<复位MEMC功能的初始值
		
}EN_PICTURE_TYPE;



/**
@brief 2D3D模式
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
@brief memc的BLUR ,DEJUDDER 等效果
**/
typedef enum
{
	EN_MEMC_EFFECT_BLUR, //memc blur 
	EN_MEMC_EFFECT_DEJUDDER,///memc dejudder
}EN_MEMC_EFFECT_TYPE;




/**
@brief 4K2K,4K1K转换
**/
typedef enum
{
	EN_RESOLUTION_4K2K,///panel 4k2k
	EN_RESOLUTION_4K1K,///panel 4k1k
}EN_RESOLUTION_TYPE;

/**
@brief 图像模式
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
@brief 能效级别
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
@brief 背光运行场景
**/
typedef enum
{
	EN_BACKLIGHT_RUNNING , ///<设备正常运行的背光状态
	EN_BACKLIGHT_POWER,   ///<设备在电源开启或者关闭的背光状态，涉及到控制mboot
}EN_BACKLIGHT_STATE;

/**
@brief 几何调整情况
**/
typedef enum
{
    EN_GEO_MANUAL,
    EN_GEO_AUTO,
    EN_GEO_NUM
} EN_FPI_PICTURE_GEO_ADJUST_TYPE;
/**
@brief HDMI图像类型
**/
typedef enum
{
    EN_PICTURE_TYPE_AUTO, ///auto
    EN_PICTURE_TYPE_PC, ///pc
    EN_PICTURE_TYPE_VIDEO,///video
    EN_PICTURE_TYPE_GAME,///game
    EN_PICTURE_TYPE_MAX,
}EN_FPI_PICTURE_TYPE;

//mute 级别                
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
    EN_FPI_VIDEO_MUTE_CHILDREN_LOCK= 0x00010000, //linshunda,儿童锁
    EN_FPI_VIDEO_MUTE_SCART    = 0x00020000, //lilijun: mute for scart 
    EN_FPI_VIDEO_MUTE_STILL_IMG = 0x00040000, //lilijun: mute for still image 
    EN_FPI_VIDEO_MUTE_DECODER =  0x00080000, // mute for still video_decoder 
    EN_FPI_VIDEO_MUTE_MEDIA = 0x00100000, // for multimedia
    EN_FPI_VIDEO_MUTE_LV_ANY = 0xffffffff
}EN_FPI_VIDEO_MUTE_LEVEL;



/**
@brief 图像属性
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
@brief VGA信源的参数
**/
typedef enum
{
	EN_VGA_HPOS,
	EN_VGA_VPOS,
	EN_VGA_PHASE,
	EN_VGA_CLOCK,
	EN_VGA_AUTO_ADJUST, ///< 0 为手动，1为自动调整
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
			  设置或保存图效模式
@param [in]	 e_src_type  起作用信源的类型，具体参看枚举EN_TOS_SOURCE_TYPE说明
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的图效	，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的图效，所以该参数目		 
						   前暂时没有用到
@param [in]	 mode  图效模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的模式(EN_ACT_EXEC)
			  	   							只保存设置的模式(EN_ACT_SAVE)
			  	   							先执行设置模式，并将设置的模式保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_set_mode(EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode,EN_FPI_PICTURE_MODE mode,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_mode
			获取当前设置的图效
@param [in]	 e_src_type  起作用信源的类型，具体参看枚举EN_TOS_SOURCE_TYPE说明
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的图效	，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的图效，所以该参数目前暂时没有用到	
@param[out]  value  获取到的当前设置的模式
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_picture_get_mode(EN_TOS_SOURCE_TYPE e_src_type, EN_VIDEO_MODE e_mode,EN_FPI_PICTURE_MODE *mode);

/** 
@brief 设置图像再3D或者2D下的背光。

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_picture_set_backlight(EN_VIDEO_MODE e_mode,uint16_t value ,EN_ACT_CTRL act );

/** 
@brief 获得图像在2D或者3D下的背光

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_picture_get_backlight(EN_VIDEO_MODE e_mode,uint16_t *value);


/**
@brief      	  tos_picture_set_brightness      
			  设置或保存图像显示的亮度	
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param [in]	 value  亮度参数
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的参数(EN_ACT_EXEC)
			  	   							只保存设置的参数(EN_ACT_SAVE)
			  	   							先执行设置参数，并将设置的参数保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_set_brightness(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);
/**
@brief		tos_picture_get_brightness
			获取当前设置的亮度参数
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的亮度参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_picture_get_brightness(EN_VIDEO_MODE e_mode,uint16_t *value);



/** 
@brief 设置图像在2D或者3D下的对比度

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_set_contrast(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);


/** 
@brief 获得图像在2D或者3D下的对比度

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_get_contrast(EN_VIDEO_MODE e_mode,uint16_t *value);


/**
@brief      	  tos_picture_set_sharpness      
			  设置或保存图像显示的锐度	
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param [in]	 value  锐度参数
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的参数(EN_ACT_EXEC)
			  	   							只保存设置的参数(EN_ACT_SAVE)
			  	   							先执行设置参数，并将设置的参数保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_picture_set_sharpness(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);


/**
@brief		tos_picture_get_sharpness
			获取当前设置的锐度参数
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

 fpi_error tos_picture_get_sharpness(EN_VIDEO_MODE e_mode,uint16_t * value);



/**
@brief      	  tos_picture_set_saturation      
			  设置或保存图像显示的饱和度
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param [in]	 value  饱和度参数
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的参数(EN_ACT_EXEC)
			  	   							只保存设置的参数(EN_ACT_SAVE)
			  	   							先执行设置参数，并将设置的参数保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_set_saturation(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_saturation
			获取当前设置的饱和度参数
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_picture_get_saturation(EN_VIDEO_MODE e_mode,uint16_t *value);



/**
@brief      	  tos_picture_set_hue      
			  设置或保存图像显示的色调
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param [in]	 value  色调参数
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的参数(EN_ACT_EXEC)
			  	   							只保存设置的参数(EN_ACT_SAVE)
			  	   							先执行设置参数，并将设置的参数保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_set_hue(EN_VIDEO_MODE e_mode,uint16_t value,EN_ACT_CTRL act);

/**
@brief		tos_picture_get_hue
			获取当前设置的色调参数
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的状态，可以保存不同的状态，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的状态，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_picture_get_hue(EN_VIDEO_MODE e_mode,uint16_t *value);





/** 
@brief 设置能效级别

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_set_energy_saving(EN_FPI_ENERGY_SAVING level,EN_ACT_CTRL act);
/** 
@brief 获得能效级别

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_get_energy_saving(EN_FPI_ENERGY_SAVING *value);

/** 
@brief 开启或者关闭背光

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_picture_set_backlight_state(EN_BACKLIGHT_STATE state,int16_t bOnOff,EN_ACT_CTRL act);

/** 
@brief 获得背光开启或者关闭状态

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_get_backlight_state(EN_BACKLIGHT_STATE state,int16_t *bOnOff);



/**
@brief		tos_picture_get_video_freeze
			获取当前画面是否冻结
@param[out]  value  获取到的当前设置的参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_picture_get_video_freeze(int16_t *state);


/**
@brief      	  tos_picture_set_video_freeze      
			  设置画面冻结
@param [in]	 state  开关
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_picture_set_video_freeze(int16_t state,EN_ACT_CTRL act);


/**
@brief      	  tos_picture_reset      
			   恢复图像页面下一些功能项的默认值
@param [in]	 type  具体功能项，具体参看枚举EN_PICTURE_TYPE说明
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_reset(EN_PICTURE_TYPE type);



/**
@brief      	  tos_picture_set_hdmi_type      
			  设置HDMI的图像类型
@param [in]	 type  图像类型参数
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的参数(EN_ACT_EXEC)
			  	   							只保存设置的参数(EN_ACT_SAVE)
			  	   							先执行设置参数，并将设置的参数保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_set_hdmi_type(EN_FPI_PICTURE_TYPE type,EN_ACT_CTRL act);


/**
@brief		tos_picture_get_hdmi_type
			获取当前设置的HDMI图像类型
@param[out]  type  获取到的当前设置的参数
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_picture_get_hdmi_type( EN_FPI_PICTURE_TYPE *type);





/** 
@brief 屏进入高分辨率模式

@note  比如4K2K,4K1K模式

@note  保留未用，

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_enter_resolution_mode(EN_RESOLUTION_TYPE type,int32_t mode,EN_ACT_CTRL act);




/** 
@brief 屏退出高分辨率模式

@note  比如4K2K,4K1K模式

@note 保留未用，

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_exit_resolution_mode(EN_RESOLUTION_TYPE type,int32_t mode,EN_ACT_CTRL act);

/** 
@brief 屏是否是某一高分辨率模式

@note  比如4K2K,4K1K模式

@note  保留未用，

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_is_resolution_mode(EN_RESOLUTION_TYPE type,int16_t *flag);




/**
@brief      	  tos_picture_get_pixel_info      
			  获取指定区域的图像属性，需要获取的数据，目前主要是要获取当前区域的R/G/B的总和，该指针指向一个调用者申请和维护的内存，底层直接填充数据即可，且不得释放；
@param [in]	 startX  起点X坐标
@param [in]	 startY  起点Y坐标
@param [in]	 endX    终点X坐标
@param [in]	 endY    终点Y坐标
@param [in]	 info 要获取当前区域的R/G/B的总和 
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_picture_get_pixel_info(int32_t startX,int32_t startY,int32_t endX,int32_t endY,st_fpi_screen_pixel_info* info);


/** 
@brief 设置现在的图像显示情况

@note 一般用于自然光算法，根据不同的图像模式，自然光算法有会有差别

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_set_display_condition(EN_TOS_MSG_TO_DBC msg,EN_ACT_CTRL act);

/** 
@brief 设置现在的图像显示情况

@note 一般用于自然光算法，根据不同的图像模式，自然光算法有会有差别

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_get_display_condition(EN_TOS_MSG_TO_DBC *msg);


/** 
@brief 设置VGA下的图像 参数

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/	
fpi_error tos_picture_vga_set_para(EN_VGA_PARA_CTRL type,uint16_t value,EN_ACT_CTRL act);

/** 
@brief 获得VGA下的图像参数

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_picture_get_vga_para(EN_VGA_PARA_CTRL type,uint16_t *value);

/**
@brief      	  tos_picture_memc_bypass_osd      
			  设置运动补偿下OSD保护
@param [in]	 stOsdWindow  OSD界面的坐标信息
@param [in]	 mode OSD是否显示，0表示OSD显示，1表示OSD隐藏  
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_picture_memc_bypass_osd( st_fpi_osd_window* stOsdWindow, int8_t mode );


/** 
@brief 设置视频开关画

@param[in]mute_mask, 使用mute_mask的那一位，请在此添加，并注明功能 
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_picture_video_mute(uint32_t mute_mask, fpi_bool b_mute);


/** 
@brief 设置视频开关画

@param[in]reason, mute 或 unmute 原 因
@param[in]b_mute
		    fpi_true: mute video; fpi_false: unmute video
@param[out]无
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_picture_set_video_mute_with_reason( char* reason, fpi_bool b_mute);


#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
