/**@defgroup 图像比例模式设置
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
*/



#ifndef __TOS_PICTURE_ZOOM_H__
#define __TOS_PICTURE_ZOOM_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_picture_setting.h"


#ifdef __cplusplus
extern "C" {
#endif




/**
@brief 图像模式
**/
typedef enum
{
    EN_PIC_SIZE_16_9 = 0, // 16:9
    EN_PIC_SIZE_4_3,      // 4:3
    EN_PIC_SIZE_14_9,  //   14:9
    EN_PIC_SIZE_CINERAMA, // Cinerama
    EN_PIC_SIZE_16_9_ZOOM, //16:9 Zoom or movie 
    EN_PIC_SIZE_16_9_ZOOM_UP,  //16:9 Zoom up or subtitle 
    EN_PIC_SIZE_14_9_ZOOM,    // 14:9 Zoom
    EN_PIC_SIZE_STRETCH_ZOOM,     // Stretch Zoom
    EN_PIC_SIZE_WIDE_ZOOM,    // Wide Zoom
    EN_PIC_SIZE_ZOOM_2,  //   Zoom2
    EN_PIC_SIZE_WIDE_ZOOM2,  //  Wide Zoom2
    EN_PIC_SIZE_NATIVE,      // Native or justscan
    EN_PIC_SIZE_DOT_BY_DOT,  // Dot by Dot
    EN_PIC_SIZE_ORIGINAL,   //Original or auto
    EN_PIC_SIZE_PARONAMA,	// Paronama
    EN_PIC_SIZE_NUM //15
}EN_FPI_PIC_SIZE;

/**
@brief 描述和图像尺寸相关的效果
**/
typedef enum
{
	EN_APPEAR_AUTO_FORMAT, ///<自动模式
	
	EN_APPEAR_OVERSCAN,	///<全景模式
}EN_VIDEO_APPEAR_TYPE;

/**
@brief 描述窗口起始坐标和大小
*/
typedef struct
{
	int32_t hposition;  ///<行坐标
	int32_t vposition; ///<列坐标
	int32_t hsize; ///<宽
	int32_t vsize; ///<高
}st_tos_zoom_window;

/**
@brief 描述窗口类型
**/
typedef enum
{
	EN_ZOOM_WINDOW_CROP,///cropwindow
	EN_ZOOM_WINDOW_MAX,
}EN_ZOOM_WINDOW_TYPE;



/**
@brief      	  tos_zoom_set_size      
			  设置或保存图像显示的比例模式	
@param[in]      e_video_mode  图像模式，不同的图像模式下可以设置不同的比例模式，可以保存不同的比例模式，
						   由于还没有需求，要求不同的图像模式下保存和设置不同的比例模式，所以该参数目		 
						   前暂时没有用到
@param [in]	 e_picture_mode  比例模式，不同的参数对应不同的比例模式
@param [in]	 act  接口执行的状态， 可以选择只执行不保存设置的比例模式(EN_ACT_EXEC)
			  	   							只保存设置的比例模式(EN_ACT_SAVE)
			  	   							先执行设置比例模式，并将设置的比例模式保存下来(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败  
*/
fpi_error tos_zoom_set_size(EN_VIDEO_MODE e_video_mode,EN_FPI_PIC_SIZE e_picture_mode,EN_ACT_CTRL act);



/**
@brief		tos_zoom_get_size
			获取当前设置的比例模式
@param[in]    e_video_mode  图像模式，比例模式可以根据图像模式的不同分开保存，可以获取在不同图像模式下的设置的当前比例模式
						    				    由于还没有需求，要求不同的图像模式下保存和设置不同的比例模式，所以该参数目
						                              前暂时没有用到
@param[out]  value  获取到的当前设置的比例模式
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/
fpi_error tos_zoom_get_size(EN_VIDEO_MODE e_video_mode,EN_FPI_PIC_SIZE *value);



/**
@brief	      tos_zoom_set_appear
			1、设置图像的自动比例模式(根据信号实际的分辨率或者AFD或者WSS信息显示图像大小)
			2、设置图像的视野模式
@param[in]   e_type      选择设置自动比例模式或者视野模式(EN_APPEAR_AUTO_FORMAT 自动比例模式，EN_APPEAR_OVERSCAN视野模式)
@param[in]   enable       若e_type为EN_APPEAR_AUTO_FORMAT自动比例模式，则enable == fpi_true表示自动比例模式为on，enable == fpi_false表示自动比例模式为off；
		                     若e_type为EN_APPEAR_OVERSCAN视野模式，则enable == fpi_true表示视野模式为on，enable == fpi_false表示视野模式为off。

@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    表示设置操作成功
@retval           FPI_ERROR_FAIL          表示设置操作失败

*/
fpi_error tos_zoom_set_appear(EN_VIDEO_APPEAR_TYPE e_type,int16_t enable,EN_ACT_CTRL act);



/**
@brief		tos_zoom_get_appear
			1、判断是否是自动模式类型
			2、获取设置图像的视野模式
@param[in]    e_type	获取自动比例模式或者视野模式(EN_APPEAR_AUTO_FORMAT 自动比例模式，EN_APPEAR_OVERSCAN视野模式)

@param[out]   enable	若e_type为EN_APPEAR_AUTO_FORMAT自动比例模式，则enable 为判断是否为自动模式类型
		                   若e_type为EN_APPEAR_OVERSCAN视野模式，则enable 为视野模式类型
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败
*/
fpi_error tos_zoom_get_appear(EN_VIDEO_APPEAR_TYPE e_type,int16_t *enable);



/**
@brief		tos_zoom_get_video_zoom
			判断当前信源哪个picturesize有效，此接口是海外区相关spec的需求
			需要循环获取每一个picturesize，判断该模式是否有效
@param[in]    pic_size	比例模式

@param[out]   enable	比例模式是否有效值
			*enable == fpi_true，表示该pic_size有效，*enable == fpi_false，表示该pic_size无效
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败  
*/
fpi_error tos_zoom_get_video_zoom(EN_FPI_PIC_SIZE pic_size,int16_t *enable);


/**
@brief	       tos_zoom_get_current_window
			获取当前图像的显示区域坐标和大小
			不建议使用
@param[in]   NONE

@param[out]	start_x      显示区域行起始位置
@param[out]	start_y      显示区域场起始位置
@param[out]	width   		显示区域从行起始位置算起的行大小
@param[out]	height  		显示区域从场起始位置算起的场大小

@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败    
*/
fpi_error tos_zoom_get_current_window(int32_t *start_x,int32_t *start_y,int32_t *width,int32_t *height);


/**
@brief		tos_zoom_set_scale_window
			设置当前窗口的大小
@param[in]    x       行起始位置
@param [in]	y       场起始位置
@param [in]	width        从行起始位置算起的行大小
@param [in]	height       从场起始位置算起的场大小
@param [in]   act  接口执行的状态， 可以选择只执行不保存设置的比例模式(EN_ACT_EXEC)
			  	只保存设置的比例模式(EN_ACT_SAVE)
			  	先执行设置比例模式，并将设置的比例模式保存下来(EN_ACT_EXEC_SAVE)				

@param[out]   NONE
@retval	    	FPI_ERROR_SUCCESS  表示设置操作成功，
@retval		FPI_ERROR_FAIL  表示设置操作失败  
*/
fpi_error tos_zoom_set_scale_window(int32_t x,int32_t y,int32_t width,int32_t height,EN_ACT_CTRL act);




/**
@brief	   tos_zoom_get_small_window_state
		   获取小窗口状态，判断是否是小窗口
@param[in]    NONE

@param[out]   state  小窗口状态
		       *state == fpi_true，表示该pic_size有效，*state == fpi_false，表示该pic_size无效
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败    
*/
fpi_error tos_zoom_get_small_window_state(int16_t* state);



/**
@brief	       tos_zoom_get_window
			获取需要的窗口坐标和大小
			根据第一个参数的不同可以获取不同窗口的坐标，如cropwindow的坐标和大小，displaywindow的坐标和大小，capturewindow的坐标和大小
			目前可以获取到cropwindow的坐标和大小。
@param[in]    mode  窗口类型
				   接口根据窗口类型，来获取不同的坐标和大小值
@param[out]   pstWindow  不同窗口的坐标和大小值
@retval	    	FPI_ERROR_SUCCESS   表示获取成功
@retval         FPI_ERROR_FAIL          表示获取失败    
*/
fpi_error tos_zoom_get_window(EN_ZOOM_WINDOW_TYPE mode,st_tos_zoom_window *pstWindow);




/**
@brief		tos_zoom_set_crop_window
			设置图像信号裁剪区域
@param[in]    un32_windowId        用于描述某一路信号的窗口ID
@param[in] 	un32_hposition      行起始位置
@param[in] 	un32_vposition     场起始位置
@param[in] 	un32_hsize    从行起始位置算起的行大小
@param[in] 	un32_vsize    从场起始位置算起的场大小

@param[out]   NONE

@retval	    	FPI_ERROR_SUCCESS  表示设置操作成功，
@retval		FPI_ERROR_FAIL  表示设置操作失败  
*/
fpi_error     tos_zoom_set_crop_window(uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize);


/**
@brief			 tos_zoom_set_display_window 
				设置在屏幕上显示的区域
@param[in]    un32_windowId        用于描述某一路信号的窗口ID
@param[in] 	un32_hposition      行起始位置
@param[in] 	un32_vposition     场起始位置
@param[in] 	un32_hsize    从行起始位置算起的行大小
@param[in] 	un32_vsize    从场起始位置算起的场大小

@param[out]		NONE    

@retval	    	FPI_ERROR_SUCCESS  表示设置操作成功，
@retval		FPI_ERROR_FAIL  表示设置操作失败  
*/
fpi_error      tos_zoom_set_display_window(uint32_t  un32_windowId, 
									uint32_t un32_hposition, uint32_t un32_vposition, 
									uint32_t un32_hsize, uint32_t un32_vsize );
#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
