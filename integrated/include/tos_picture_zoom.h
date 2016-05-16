/**@defgroup ͼ�����ģʽ����
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
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
@brief ͼ��ģʽ
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
@brief ������ͼ��ߴ���ص�Ч��
**/
typedef enum
{
	EN_APPEAR_AUTO_FORMAT, ///<�Զ�ģʽ
	
	EN_APPEAR_OVERSCAN,	///<ȫ��ģʽ
}EN_VIDEO_APPEAR_TYPE;

/**
@brief ����������ʼ����ʹ�С
*/
typedef struct
{
	int32_t hposition;  ///<������
	int32_t vposition; ///<������
	int32_t hsize; ///<��
	int32_t vsize; ///<��
}st_tos_zoom_window;

/**
@brief ������������
**/
typedef enum
{
	EN_ZOOM_WINDOW_CROP,///cropwindow
	EN_ZOOM_WINDOW_MAX,
}EN_ZOOM_WINDOW_TYPE;



/**
@brief      	  tos_zoom_set_size      
			  ���û򱣴�ͼ����ʾ�ı���ģʽ	
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ�ı���ģʽ�����Ա��治ͬ�ı���ģʽ��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ�ı���ģʽ�����Ըò���Ŀ		 
						   ǰ��ʱû���õ�
@param [in]	 e_picture_mode  ����ģʽ����ͬ�Ĳ�����Ӧ��ͬ�ı���ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õı���ģʽ(EN_ACT_EXEC)
			  	   							ֻ�������õı���ģʽ(EN_ACT_SAVE)
			  	   							��ִ�����ñ���ģʽ���������õı���ģʽ��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/
fpi_error tos_zoom_set_size(EN_VIDEO_MODE e_video_mode,EN_FPI_PIC_SIZE e_picture_mode,EN_ACT_CTRL act);



/**
@brief		tos_zoom_get_size
			��ȡ��ǰ���õı���ģʽ
@param[in]    e_video_mode  ͼ��ģʽ������ģʽ���Ը���ͼ��ģʽ�Ĳ�ͬ�ֿ����棬���Ի�ȡ�ڲ�ͬͼ��ģʽ�µ����õĵ�ǰ����ģʽ
						    				    ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ�ı���ģʽ�����Ըò���Ŀ
						                              ǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õı���ģʽ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/
fpi_error tos_zoom_get_size(EN_VIDEO_MODE e_video_mode,EN_FPI_PIC_SIZE *value);



/**
@brief	      tos_zoom_set_appear
			1������ͼ����Զ�����ģʽ(�����ź�ʵ�ʵķֱ��ʻ���AFD����WSS��Ϣ��ʾͼ���С)
			2������ͼ�����Ұģʽ
@param[in]   e_type      ѡ�������Զ�����ģʽ������Ұģʽ(EN_APPEAR_AUTO_FORMAT �Զ�����ģʽ��EN_APPEAR_OVERSCAN��Ұģʽ)
@param[in]   enable       ��e_typeΪEN_APPEAR_AUTO_FORMAT�Զ�����ģʽ����enable == fpi_true��ʾ�Զ�����ģʽΪon��enable == fpi_false��ʾ�Զ�����ģʽΪoff��
		                     ��e_typeΪEN_APPEAR_OVERSCAN��Ұģʽ����enable == fpi_true��ʾ��ҰģʽΪon��enable == fpi_false��ʾ��ҰģʽΪoff��

@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��

*/
fpi_error tos_zoom_set_appear(EN_VIDEO_APPEAR_TYPE e_type,int16_t enable,EN_ACT_CTRL act);



/**
@brief		tos_zoom_get_appear
			1���ж��Ƿ����Զ�ģʽ����
			2����ȡ����ͼ�����Ұģʽ
@param[in]    e_type	��ȡ�Զ�����ģʽ������Ұģʽ(EN_APPEAR_AUTO_FORMAT �Զ�����ģʽ��EN_APPEAR_OVERSCAN��Ұģʽ)

@param[out]   enable	��e_typeΪEN_APPEAR_AUTO_FORMAT�Զ�����ģʽ����enable Ϊ�ж��Ƿ�Ϊ�Զ�ģʽ����
		                   ��e_typeΪEN_APPEAR_OVERSCAN��Ұģʽ����enable Ϊ��Ұģʽ����
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��
*/
fpi_error tos_zoom_get_appear(EN_VIDEO_APPEAR_TYPE e_type,int16_t *enable);



/**
@brief		tos_zoom_get_video_zoom
			�жϵ�ǰ��Դ�ĸ�picturesize��Ч���˽ӿ��Ǻ��������spec������
			��Ҫѭ����ȡÿһ��picturesize���жϸ�ģʽ�Ƿ���Ч
@param[in]    pic_size	����ģʽ

@param[out]   enable	����ģʽ�Ƿ���Чֵ
			*enable == fpi_true����ʾ��pic_size��Ч��*enable == fpi_false����ʾ��pic_size��Ч
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/
fpi_error tos_zoom_get_video_zoom(EN_FPI_PIC_SIZE pic_size,int16_t *enable);


/**
@brief	       tos_zoom_get_current_window
			��ȡ��ǰͼ�����ʾ��������ʹ�С
			������ʹ��
@param[in]   NONE

@param[out]	start_x      ��ʾ��������ʼλ��
@param[out]	start_y      ��ʾ������ʼλ��
@param[out]	width   		��ʾ���������ʼλ��������д�С
@param[out]	height  		��ʾ����ӳ���ʼλ������ĳ���С

@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��    
*/
fpi_error tos_zoom_get_current_window(int32_t *start_x,int32_t *start_y,int32_t *width,int32_t *height);


/**
@brief		tos_zoom_set_scale_window
			���õ�ǰ���ڵĴ�С
@param[in]    x       ����ʼλ��
@param [in]	y       ����ʼλ��
@param [in]	width        ������ʼλ��������д�С
@param [in]	height       �ӳ���ʼλ������ĳ���С
@param [in]   act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õı���ģʽ(EN_ACT_EXEC)
			  	ֻ�������õı���ģʽ(EN_ACT_SAVE)
			  	��ִ�����ñ���ģʽ���������õı���ģʽ��������(EN_ACT_EXEC_SAVE)				

@param[out]   NONE
@retval	    	FPI_ERROR_SUCCESS  ��ʾ���ò����ɹ���
@retval		FPI_ERROR_FAIL  ��ʾ���ò���ʧ��  
*/
fpi_error tos_zoom_set_scale_window(int32_t x,int32_t y,int32_t width,int32_t height,EN_ACT_CTRL act);




/**
@brief	   tos_zoom_get_small_window_state
		   ��ȡС����״̬���ж��Ƿ���С����
@param[in]    NONE

@param[out]   state  С����״̬
		       *state == fpi_true����ʾ��pic_size��Ч��*state == fpi_false����ʾ��pic_size��Ч
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��    
*/
fpi_error tos_zoom_get_small_window_state(int16_t* state);



/**
@brief	       tos_zoom_get_window
			��ȡ��Ҫ�Ĵ�������ʹ�С
			���ݵ�һ�������Ĳ�ͬ���Ի�ȡ��ͬ���ڵ����꣬��cropwindow������ʹ�С��displaywindow������ʹ�С��capturewindow������ʹ�С
			Ŀǰ���Ի�ȡ��cropwindow������ʹ�С��
@param[in]    mode  ��������
				   �ӿڸ��ݴ������ͣ�����ȡ��ͬ������ʹ�Сֵ
@param[out]   pstWindow  ��ͬ���ڵ�����ʹ�Сֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��    
*/
fpi_error tos_zoom_get_window(EN_ZOOM_WINDOW_TYPE mode,st_tos_zoom_window *pstWindow);




/**
@brief		tos_zoom_set_crop_window
			����ͼ���źŲü�����
@param[in]    un32_windowId        ��������ĳһ·�źŵĴ���ID
@param[in] 	un32_hposition      ����ʼλ��
@param[in] 	un32_vposition     ����ʼλ��
@param[in] 	un32_hsize    ������ʼλ��������д�С
@param[in] 	un32_vsize    �ӳ���ʼλ������ĳ���С

@param[out]   NONE

@retval	    	FPI_ERROR_SUCCESS  ��ʾ���ò����ɹ���
@retval		FPI_ERROR_FAIL  ��ʾ���ò���ʧ��  
*/
fpi_error     tos_zoom_set_crop_window(uint32_t  un32_windowId , 
										uint32_t un32_hposition, uint32_t un32_vposition, 
										uint32_t un32_hsize, uint32_t un32_vsize);


/**
@brief			 tos_zoom_set_display_window 
				��������Ļ����ʾ������
@param[in]    un32_windowId        ��������ĳһ·�źŵĴ���ID
@param[in] 	un32_hposition      ����ʼλ��
@param[in] 	un32_vposition     ����ʼλ��
@param[in] 	un32_hsize    ������ʼλ��������д�С
@param[in] 	un32_vsize    �ӳ���ʼλ������ĳ���С

@param[out]		NONE    

@retval	    	FPI_ERROR_SUCCESS  ��ʾ���ò����ɹ���
@retval		FPI_ERROR_FAIL  ��ʾ���ò���ʧ��  
*/
fpi_error      tos_zoom_set_display_window(uint32_t  un32_windowId, 
									uint32_t un32_hposition, uint32_t un32_vposition, 
									uint32_t un32_hsize, uint32_t un32_vsize );
#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
