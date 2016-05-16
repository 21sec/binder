/**@defgroup 画质模块
@{

@brief 用于获取/设置画质(PQ)相关的选项

@author lihui02@tcl.com

@version 1.0.0 2014/10/30 初稿
@version 1.0.1 2014/10/30 将模块名修改为PQ模块.
@version 1.0.1 2014/1/3 linshunda 改为fpi开头

*/

#ifndef __TOS_PICTURE_QUALITY__
#define __TOS_PICTURE_QUALITY__

#ifdef __cplusplus
extern "C" {
#endif
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_picture_setting.h"
//#include "fpi_system.h"


/**
@brief 色温
**/
typedef enum
{
    EN_COLOR_TEMP_COOL,//冷色温
    EN_COLOR_TEMP_STANDARD,//标准色温
    EN_COLOR_TEMP_WARM,//暖
    EN_COLOR_TEMP_PERSONAL,//自定义
    EN_COLOR_TEMP_CUSTOM_1,//暖色温增强
    EN_COLOR_TEMP_NUM
} EN_FPI_COLOR_TEMPERATURE;

/**
@brief PQ参数
**/
typedef enum
{
    EN_PQ_COLOR_PARAMTER_NORMAL,			///< 普通颜色PQ参数
    EN_PQ_COLOR_PARAMTER_WIDE_COLOR_ENHANCE,///< 高色域颜色PQ参数
    EN_PQ_COLOR_PARAMTER_XVYCC,				///< xvYCC颜色模式PQ参数，建议仅当信号中有xvYCC信号时才使用。见api_is_xvycc_support
    EN_PQ_COLOR_PARAMTER_HDR_NORMAL,///<HDR 普通颜色PQ参数
    EN_PQ_COLOR_PARAMTER_HDR_WIDE_COLOR_ENHANCE,///< HDR高色域颜色PQ参数
    EN_PQ_COLOR_PARAMTER_BYPASS=0xff,///< 不做色彩相关处理
    EN_PQ_COLOR_PARAMTER_MAX,
}EN_FPI_PQ_COLOR_PARAMTER;

typedef enum
{
	EN_MOTION_CLARITY_FLIM,///<
	EN_MOTION_CLARITY_SMOOTH,
	EN_MOTION_CLARITY_CLEAR,
	EN_MOTION_CLARITY_SPORT,
	EN_MOTION_CLARITY_CUSTOM,
       EN_MOTION_CLARITY_AUTO,
       
	EN_MOTION_CLARITY_MAX
}EN_FPI_MOTION_CLARITY_MODE;

/**
@brief 描述和图像效果相关
**/
typedef enum
{
	EN_EFFECT_DYNAMIC_CONTRAST,  ///<自动对比度
	EN_EFFECT_DYNAMIC_BACKLIGHT, ///<自动背光
	EN_EFFECT_LIGHT_SENSOR,      ///<自然光
	
	EN_EFFECT_BLACK_STRETCH,///<黑边裁剪
	EN_EFFECT_FLESH_TONE, ///<肤色矫正
	EN_EFFECT_GAME_MODE,  ///<电影模式
	EN_EFFECT_MOTION_CLARITY,///<运动组合开关，控制MEMC和4K1K
	EN_EFFECT_MIX_DIMMING, ///<混合调光
	EN_EFFECT_MOTION_INTERPORATION,// 4k2k-4k1k
	EN_EFFECT_FILM_MODE,///<电影模式
	EN_EFFECT_LOCAL_DIMMING,///<局部控光

	EN_EFFECT_APPLY_MODE,//picture preset to all src
}EN_VIDEO_EFFECT_TYPE;


/**
@brief 三基色
**/
typedef enum
{
    EN_COLOR_OFF,///
	EN_COLOR_RED,///<Red
	EN_COLOR_GREEN,
	EN_COLOR_BLUE,
    EN_COLOR_NUM
}EN_COLOR_TYPE;

/**
@brief 降噪级别
**/
typedef enum
{
   EN_MPEG_NR_OFF,
   EN_MPEG_NR_LOW,
   EN_MPEG_NR_MIDDLE,
   EN_MPEG_NR_HIGH,
   EN_MPEG_NR_NUM
}EN_FPI_MPEG_NR_MODE;


/**
@brief 降噪级别
**/
typedef enum
{
   EN_NOISE_REDUCTION_OFF,
   EN_NOISE_REDUCTION_LOW,
   EN_NOISE_REDUCTION_MIDDLE,
   EN_NOISE_REDUCTION_HIGH,
   EN_NOISE_REDUCTION_AUTO,
   EN_NOISE_REDUCTION_NUM
}EN_FPI_NOISE_REDUCTION_MODE;

/**
@brief MEMC级别
**/
typedef enum
{
	EN_MEMC_OFF,
	EN_MEMC_LOW,
	EN_MEMC_MID,
	EN_MEMC_HIGH,
	EN_MEMC_CUSTOMER,
	EN_MEMC_MAX,
}EN_FPI_MEMC_CONFIG;
/**
@brief 色彩空间
**/
typedef enum
{
	EN_COLOR_SPACE_AUTO, /// 自动识别色彩空间
	EN_COLOR_SPACE_NATIVE,///用屏本身的色彩空间
	EN_COLOR_SPACE_CUSTOM,///自定义
	EN_COLOR_SPACE_EX1,
	EN_COLOR_SPACE_MAX
} EN_FPI_COLOR_SPACE_MODE;

/**
@brief 色域色彩
**/
typedef enum
{
	EN_CS_CUSTOM_RED,
	EN_CS_CUSTOM_GREEN,
	EN_CS_CUSTOM_BLUE,
	EN_CS_CUSTOM_YELLOW,
	EN_CS_CUSTOM_CYAN,
	EN_CS_CUSTOM_MAGENTA,
	EN_CS_CUSTOM_MAX
} EN_FPI_CS_COLOR_MODE;

/**
@brief 占空比基本
**/
typedef enum
{
    EN_CLARITY_OFF, //背光100%
	EN_CLARITY_LOW,
	EN_CLARITY_MIDDLE,
	EN_CLARITY_HIGH,
	EN_CLARITY_MAX
} EN_FPI_CLARITY_TYPE;

/**
@brief PQ demo
**/

typedef enum
{
    EN_DEMO_OFF,
    EN_DEMO_CUSTOMER1, ///< 2k->4k
    EN_DEMO_CUSTOMER2,
    EN_DEMO_CUSTOMER3,
    EN_DEMO_DEFAULT,
    EN_DEMO_DYNAMICCOMPARE,
    EN_DEMO_ENHANCE,
    EN_DEMO_GOLDENEYES,
    EN_DEMO_HIGH_SPEED_MOVEMENT_PROCESSING,///< 4K高速运动处理
    EN_DEMO_LED_BACKLIGHT_CONTROL,    ///< LED背光控制
    EN_DEMO_MOVEALONG,  
    EN_DEMO_OPTIMIZE,
    EN_DEMO_SIDE_BY_SIDE,
    EN_DEMO_SQUAREMOVE,
    EN_DEMO_TRUE_COLOR_ANALYSIS_ASCENSION, ///< 晶彩分析提升
    EN_DEMO_WIDE_COLOR_ENHANCE,	///< 高色域演示模式
    EN_DEMO_WIDE_COLOR_ENHANCE_CONTRAST, ///< 高色域对比演示模式，即高色域方面很差的一组PQ
    EN_DEMO_HDR_LEFT_RIGHT_SIDE,									  ///<HDR演示左右分屏模式
	EN_DEMO_HDR_HORIZONTAL_SCANING_FORM_LEFT_TO_RIGHT,									   ///<HDR演示从左到又水平扫描模式
	EN_DEMO_HDR_FULLSCREEN_OPEN,								  //HDR演示全屏效果开		
	EN_DEMO_HDR_FULLSCREEN_CLOSE,								  //HDR演示全屏效果关
	EN_DEMO_PRECISE_COLOUR_GAMUT_CONTROLING,					  //精准色域控制技术
	EN_DEMO_PRECISE_COLOR_REDUCTION, //精准彩色还原技术
	EN_DEMO_PRECISE_BRIGHTNESS_DISPLAY, //精准亮度显示技术
	EN_DEMO_STH_DYNAMIC_ASCENSION, //睿耀STH动态提升技术(STR 转HDR)
	EN_DEMO_MATRIX_PARTITION_CONTROLING,				  //点阵式分区控制技术
	EN_DEMO_LOCAL_DIMMING_IR_NUM_SWITCH_LED,						//localdiming演示模式需求1，遥控器输入数字，对应背光板亮
	EN_DEMO_LOCAL_DIMMING_LEFT_RIGHT_COLOR_SHELTER,				//localdiming演示模式需求2，图像/ 灯型，左右对比
	EN_DEMO_LOCAL_DIMMING_MARQUEE,								//localdiming演示模式需求3，跑马灯
	EN_DEMO_MEMC_LEFT_RIGHT_SIDE,

    EN_DEMO_MAX,

} EN_FPI_PQ_DEMO_MODE;

/**
@brief      	  tos_pq_set_colortemperature      
			  设置或保存图像显示的色温	
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的色温	，可以保存不同的色温	，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的色温，所以该参数目		 
						   前暂时没有用到
@param [in]	 mode  色温模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的色温模式(EN_ACT_EXEC)
			  	   							只保存设置的色温模式(EN_ACT_SAVE)
			  	   							先执行设置色温模式，并将设置的色温模式保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_colortemperature(EN_VIDEO_MODE e_mode,EN_FPI_COLOR_TEMPERATURE mode,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_colortemperature
			获取当前设置的色温
@param[in]    e_video_mode  图像模式，色温模式可以根据图像模式的不同分开保存，可以获取在不同图像模式下的设置的当前色温模式
						    				    由于还没有需求，要求不同的图像模式下保存和设置不同的色温模式，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的色温模式
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_pq_get_colortemperature(EN_VIDEO_MODE e_mode,EN_FPI_COLOR_TEMPERATURE *value);

/**
@brief      	  tos_pq_set_pq_color_paramter      
			设置PQ的颜色参数模式（广色域接口）,在当前PQ参数的基础上，设置PQ的颜色参数。
@param [in]	 color  色域模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的色域模式(EN_ACT_EXEC)
			  	   							只保存设置的色域模式(EN_ACT_SAVE)
			  	   							先执行设置色域模式，并将设置的色域模式保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_pq_color_paramter(EN_FPI_PQ_COLOR_PARAMTER color,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_pq_color_paramter
			获取当前设置的色域
@param[out]  color  获取到的当前设置的色域模式
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_pq_color_paramter(EN_FPI_PQ_COLOR_PARAMTER *color);

/**
@brief      	  tos_pq_set_gamma      
			  设置或保存图像显示的伽马	
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的伽马，可以保存不同的伽马		，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的伽马	，所以该参数目		 
						   前暂时没有用到
@param [in]	 value  伽马模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的伽马	模式(EN_ACT_EXEC)
			  	   							只保存设置的伽马	模式(EN_ACT_SAVE)
			  	   							先执行设置伽马	模式，并将设置的伽马模式保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_gamma(EN_VIDEO_MODE e_mode,int16_t value,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_gamma
			获取当前设置的伽马
@param[in]    e_video_mode  图像模式，伽马模式可以根据图像模式的不同分开保存，可以获取在不同图像模式下的设置的当前伽马模式
						    				    由于还没有需求，要求不同的图像模式下保存和设置不同的伽马模式，所以该参数目前暂时没有用到
@param[out]  value  获取到的当前设置的伽马模式
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_pq_get_gamma(EN_VIDEO_MODE e_mode,int16_t *value);

/**
@brief      	  tos_pq_set_white_balance_gain      
			设置白平衡的增益，对应色温选项为自定义时候显示
@param [in]	 red  红基色，范围[-30,30] 
@param [in]	 green  绿基色，范围[-30,30] 
@param [in]	 blue  蓝基色，范围[-30,30] 
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_white_balance_gain(int16_t red,int16_t green,int16_t blue,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_white_balance_gain
			获取当前设置的红绿蓝三基色的数值，范围[-30,30] 
@param[out]  red  获取到的当前设置的红基色
@param[out]  green  获取到的当前设置的绿基色
@param[out]  blue  获取到的当前设置的蓝基色
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_white_balance_gain(int16_t *red,int16_t *green,int16_t *blue);


/**
@brief      	  tos_pq_set_white_balance_offset      
			设置白平衡的偏移，对应色温选项为自定义时候显示
@param [in]	 red  红基色，范围[-30,30] 
@param [in]	 green  绿基色，范围[-30,30] 
@param [in]	 blue  蓝基色，范围[-30,30] 
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_white_balance_offset(int16_t red,int16_t green,int16_t blue,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_white_balance_offset
			获取当前设置的红绿蓝三基色的数值，范围[-30,30] 
@param[out]  red  获取到的当前设置的红基色
@param[out]  green  获取到的当前设置的绿基色
@param[out]  blue  获取到的当前设置的蓝基色
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_white_balance_offset(int16_t *red,int16_t *green,int16_t *blue);
/**
@brief		tos_pq_get_special_effect
			获得图像的显示效果， 跟对画面的亮暗，色彩等自动处理相关
@param[in]    e_type  不同效果模式，具体参看枚举EN_VIDEO_EFFECT_TYPE说明
@param[out]  enable  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_pq_get_special_effect(EN_VIDEO_EFFECT_TYPE e_type,int16_t *enable,EN_ACT_CTRL act);

/**
@brief      	  tos_pq_set_special_effect      
			  设置图像的显示效果， 跟对画面的亮暗，色彩等自动处理相关
@param[in]      e_type  不同效果模式，具体参看枚举EN_VIDEO_EFFECT_TYPE说明
@param [in]	 enable  状态数值，不同的参数对应不同的状态
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_special_effect(EN_VIDEO_EFFECT_TYPE e_type,int16_t enable,EN_ACT_CTRL act);


/**
@brief      	  tos_pq_set_rgb_mode      
			  设置RGB单独通道的模式，对应就是把白平衡三通道，进行分开关闭,不保存数据库
@param[in]      mode  不同效果模式，RED时候，将白平衡其余两色关闭，即只有红色，其余同理
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_rgb_mode(EN_COLOR_TYPE mode,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_rgb_mode
			获得当前RGB单独通道的模式
@param[in]    e_type  不同效果模式，具体参看枚举EN_VIDEO_EFFECT_TYPE说明
@param[out]  enable  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_rgb_mode(EN_COLOR_TYPE *value);

/**
@brief      	  tos_pq_set_mpeg_nr      
			  设置MPEG降噪的状态
@param[in]      level  MPEG降噪效果模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_mpeg_nr(EN_FPI_MPEG_NR_MODE level,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_mpeg_nr
			获得MPEG降噪的状态
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_mpeg_nr(EN_FPI_MPEG_NR_MODE *value);

/**
@brief      	  tos_pq_set_noise_reduction      
			  设置降噪的状态
@param[in]      level  降噪效果模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_noise_reduction(EN_FPI_NOISE_REDUCTION_MODE level,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_noise_reduction
			获得降噪的状态
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_noise_reduction(EN_FPI_NOISE_REDUCTION_MODE *value);

/**
@brief		tos_pq_get_memc_config
			获得运动补偿的状态
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_memc_config(EN_FPI_MEMC_CONFIG *config);
/**
@brief      	  tos_pq_set_memc_config      
			  设置运动补偿的状态
@param[in]      config  运动补偿效果模式，不同的参数对应不同的模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_memc_config(EN_FPI_MEMC_CONFIG config,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_memc_effect
			获得运动补偿自定义的效果
@param[in]    type  不同参数调整模式，具体参看枚举EN_MEMC_EFFECT_TYPE说明
@param[out]  level  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_pq_get_memc_effect(EN_MEMC_EFFECT_TYPE type,int16_t *level);

/**
@brief      	  tos_pq_set_memc_effect      
			  设置运动补偿自定义的效果， 
@param[in]      type  不同参数调整模式，具体参看枚举EN_MEMC_EFFECT_TYPE说明
@param [in]	 level  状态数值，不同的参数对应不同的状态
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/


fpi_error tos_pq_set_memc_effect(EN_MEMC_EFFECT_TYPE type,int16_t level,EN_ACT_CTRL act);


/**
@brief      	  tos_pq_set_color_gamma_enable      
			  设置色彩通道的gamma调整开启
@param[in]      enable  开关
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_gamma_enable(int16_t enable,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_gamma_enable
			获得色彩通道的gamma是否开启
@param[out]  enable  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_color_gamma_enable(int16_t *enable);


/**
@brief      	  tos_pq_set_color_gamma_interval      
			   设置色彩gamma的间隔，即GAMMA曲线上的取样点
@param[in]      interval  对应取样点
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_gamma_interval(int16_t interval,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_gamma_interval
			获得色彩gamma的间隔
@param[out]  interval  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_color_gamma_interval(int16_t *interval);



/**
@brief      	  tos_pq_set_color_gamma      
			   设置色彩gamma曲线上的取样点的效果
@param[in]      color  三原色，具体参看枚举EN_COLOR_TYPE说明
@param[in]      value  对应设置的数值
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_gamma(EN_COLOR_TYPE color, int16_t value,EN_ACT_CTRL act );


/**
@brief		tos_pq_get_color_gamma
			获得色彩gamma曲线上的取样点的效果
@param[in]      color  三原色，具体参看枚举EN_COLOR_TYPE说明
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_color_gamma(EN_COLOR_TYPE color, int16_t *value );


/**
@brief      	  tos_pq_set_color_space_mode      
			设置色彩空间的模式
@param[in]      mode  不同模式对应不同的效果，具体参看枚举EN_FPI_COLOR_SPACE_MODE说明
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_space_mode(EN_FPI_COLOR_SPACE_MODE mode,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_color_space_mode
			获得当前的色彩空间的模式
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/


fpi_error tos_pq_get_color_space_mode(EN_FPI_COLOR_SPACE_MODE *mode);

/**
@brief      	  tos_pq_set_color_type      
		 设置色彩类型
@param[in]      csMode  不同模式对应不同的效果，具体参看枚举EN_FPI_CS_COLOR_MODE说明
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_type(EN_FPI_CS_COLOR_MODE csMode,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_type
			获得当前的色彩空间的模式
@param[out]  csMode  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_color_type(EN_FPI_CS_COLOR_MODE *csMode);

/**
@brief      	  tos_pq_set_color_space      
		 设置色彩空间每一个色彩的值
@param[in]      color  三原色，具体参看枚举EN_COLOR_TYPE说明
@param[in]      value  对应设置的数值
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_color_space(EN_COLOR_TYPE color,int16_t value ,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_type
			 获得色彩空间每一个色彩的值
@param[in]      color  三原色，具体参看枚举EN_COLOR_TYPE说明
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_color_space(EN_COLOR_TYPE color,int16_t *value);
/** 
@brief 获取4K1K状态下背光占空比 

@note 动态背光模块负责解释

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_pq_get_led_motion_clarity(EN_FPI_CLARITY_TYPE *clarity_type);




/** 
@brief 设置4K1K状态下背光占空比

@note  动态背光模块负责解释

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_pq_set_led_motion_clarity(EN_FPI_CLARITY_TYPE clarity_type,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_motion_mode_is_use
			判断用户是否调整过motion clarity功能的数值 
@param[in]      motion_mode，当前的运动特效模式，具体参看枚举EN_FPI_MOTION_CLARITY_MODE说明
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_motion_mode_is_use(int16_t *value,EN_FPI_MOTION_CLARITY_MODE motion_mode);

/**
@brief      	  tos_pq_set_PQ_demo      
		 设置画质演示模式，无需存储数据库
@param[in]      color  设置不同的演示效果，具体参看枚举EN_FPI_PQ_DEMO_MODE说明
@param[in]      value  对应设置的数值
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的状态(EN_ACT_EXEC)
			  	   							只保存设置的状态(EN_ACT_SAVE)
			  	   							先执行设置状态，并将设置的状态保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/

fpi_error tos_pq_set_PQ_demo(EN_FPI_PQ_DEMO_MODE mode);


/**
@brief		tos_pq_get_color_type
			 获得画质演示模式的值，从驱动层获取
@param[out]  value  获取到的当前设置的状态数值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/

fpi_error tos_pq_get_PQ_demo(EN_FPI_PQ_DEMO_MODE *value);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
