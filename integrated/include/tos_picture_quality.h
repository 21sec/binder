/**@defgroup ����ģ��
@{

@brief ���ڻ�ȡ/���û���(PQ)��ص�ѡ��

@author lihui02@tcl.com

@version 1.0.0 2014/10/30 ����
@version 1.0.1 2014/10/30 ��ģ�����޸�ΪPQģ��.
@version 1.0.1 2014/1/3 linshunda ��Ϊfpi��ͷ

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
@brief ɫ��
**/
typedef enum
{
    EN_COLOR_TEMP_COOL,//��ɫ��
    EN_COLOR_TEMP_STANDARD,//��׼ɫ��
    EN_COLOR_TEMP_WARM,//ů
    EN_COLOR_TEMP_PERSONAL,//�Զ���
    EN_COLOR_TEMP_CUSTOM_1,//ůɫ����ǿ
    EN_COLOR_TEMP_NUM
} EN_FPI_COLOR_TEMPERATURE;

/**
@brief PQ����
**/
typedef enum
{
    EN_PQ_COLOR_PARAMTER_NORMAL,			///< ��ͨ��ɫPQ����
    EN_PQ_COLOR_PARAMTER_WIDE_COLOR_ENHANCE,///< ��ɫ����ɫPQ����
    EN_PQ_COLOR_PARAMTER_XVYCC,				///< xvYCC��ɫģʽPQ��������������ź�����xvYCC�ź�ʱ��ʹ�á���api_is_xvycc_support
    EN_PQ_COLOR_PARAMTER_HDR_NORMAL,///<HDR ��ͨ��ɫPQ����
    EN_PQ_COLOR_PARAMTER_HDR_WIDE_COLOR_ENHANCE,///< HDR��ɫ����ɫPQ����
    EN_PQ_COLOR_PARAMTER_BYPASS=0xff,///< ����ɫ����ش���
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
@brief ������ͼ��Ч�����
**/
typedef enum
{
	EN_EFFECT_DYNAMIC_CONTRAST,  ///<�Զ��Աȶ�
	EN_EFFECT_DYNAMIC_BACKLIGHT, ///<�Զ�����
	EN_EFFECT_LIGHT_SENSOR,      ///<��Ȼ��
	
	EN_EFFECT_BLACK_STRETCH,///<�ڱ߲ü�
	EN_EFFECT_FLESH_TONE, ///<��ɫ����
	EN_EFFECT_GAME_MODE,  ///<��Ӱģʽ
	EN_EFFECT_MOTION_CLARITY,///<�˶���Ͽ��أ�����MEMC��4K1K
	EN_EFFECT_MIX_DIMMING, ///<��ϵ���
	EN_EFFECT_MOTION_INTERPORATION,// 4k2k-4k1k
	EN_EFFECT_FILM_MODE,///<��Ӱģʽ
	EN_EFFECT_LOCAL_DIMMING,///<�ֲ��ع�

	EN_EFFECT_APPLY_MODE,//picture preset to all src
}EN_VIDEO_EFFECT_TYPE;


/**
@brief ����ɫ
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
@brief ���뼶��
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
@brief ���뼶��
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
@brief MEMC����
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
@brief ɫ�ʿռ�
**/
typedef enum
{
	EN_COLOR_SPACE_AUTO, /// �Զ�ʶ��ɫ�ʿռ�
	EN_COLOR_SPACE_NATIVE,///���������ɫ�ʿռ�
	EN_COLOR_SPACE_CUSTOM,///�Զ���
	EN_COLOR_SPACE_EX1,
	EN_COLOR_SPACE_MAX
} EN_FPI_COLOR_SPACE_MODE;

/**
@brief ɫ��ɫ��
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
@brief ռ�ձȻ���
**/
typedef enum
{
    EN_CLARITY_OFF, //����100%
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
    EN_DEMO_HIGH_SPEED_MOVEMENT_PROCESSING,///< 4K�����˶�����
    EN_DEMO_LED_BACKLIGHT_CONTROL,    ///< LED�������
    EN_DEMO_MOVEALONG,  
    EN_DEMO_OPTIMIZE,
    EN_DEMO_SIDE_BY_SIDE,
    EN_DEMO_SQUAREMOVE,
    EN_DEMO_TRUE_COLOR_ANALYSIS_ASCENSION, ///< ���ʷ�������
    EN_DEMO_WIDE_COLOR_ENHANCE,	///< ��ɫ����ʾģʽ
    EN_DEMO_WIDE_COLOR_ENHANCE_CONTRAST, ///< ��ɫ��Ա���ʾģʽ������ɫ����ܲ��һ��PQ
    EN_DEMO_HDR_LEFT_RIGHT_SIDE,									  ///<HDR��ʾ���ҷ���ģʽ
	EN_DEMO_HDR_HORIZONTAL_SCANING_FORM_LEFT_TO_RIGHT,									   ///<HDR��ʾ������ˮƽɨ��ģʽ
	EN_DEMO_HDR_FULLSCREEN_OPEN,								  //HDR��ʾȫ��Ч����		
	EN_DEMO_HDR_FULLSCREEN_CLOSE,								  //HDR��ʾȫ��Ч����
	EN_DEMO_PRECISE_COLOUR_GAMUT_CONTROLING,					  //��׼ɫ����Ƽ���
	EN_DEMO_PRECISE_COLOR_REDUCTION, //��׼��ɫ��ԭ����
	EN_DEMO_PRECISE_BRIGHTNESS_DISPLAY, //��׼������ʾ����
	EN_DEMO_STH_DYNAMIC_ASCENSION, //�ҫSTH��̬��������(STR תHDR)
	EN_DEMO_MATRIX_PARTITION_CONTROLING,				  //����ʽ�������Ƽ���
	EN_DEMO_LOCAL_DIMMING_IR_NUM_SWITCH_LED,						//localdiming��ʾģʽ����1��ң�����������֣���Ӧ�������
	EN_DEMO_LOCAL_DIMMING_LEFT_RIGHT_COLOR_SHELTER,				//localdiming��ʾģʽ����2��ͼ��/ ���ͣ����ҶԱ�
	EN_DEMO_LOCAL_DIMMING_MARQUEE,								//localdiming��ʾģʽ����3�������
	EN_DEMO_MEMC_LEFT_RIGHT_SIDE,

    EN_DEMO_MAX,

} EN_FPI_PQ_DEMO_MODE;

/**
@brief      	  tos_pq_set_colortemperature      
			  ���û򱣴�ͼ����ʾ��ɫ��	
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��ɫ��	�����Ա��治ͬ��ɫ��	��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��ɫ�£����Ըò���Ŀ		 
						   ǰ��ʱû���õ�
@param [in]	 mode  ɫ��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�ɫ��ģʽ(EN_ACT_EXEC)
			  	   							ֻ�������õ�ɫ��ģʽ(EN_ACT_SAVE)
			  	   							��ִ������ɫ��ģʽ���������õ�ɫ��ģʽ��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_colortemperature(EN_VIDEO_MODE e_mode,EN_FPI_COLOR_TEMPERATURE mode,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_colortemperature
			��ȡ��ǰ���õ�ɫ��
@param[in]    e_video_mode  ͼ��ģʽ��ɫ��ģʽ���Ը���ͼ��ģʽ�Ĳ�ͬ�ֿ����棬���Ի�ȡ�ڲ�ͬͼ��ģʽ�µ����õĵ�ǰɫ��ģʽ
						    				    ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��ɫ��ģʽ�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õ�ɫ��ģʽ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_pq_get_colortemperature(EN_VIDEO_MODE e_mode,EN_FPI_COLOR_TEMPERATURE *value);

/**
@brief      	  tos_pq_set_pq_color_paramter      
			����PQ����ɫ����ģʽ����ɫ��ӿڣ�,�ڵ�ǰPQ�����Ļ����ϣ�����PQ����ɫ������
@param [in]	 color  ɫ��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�ɫ��ģʽ(EN_ACT_EXEC)
			  	   							ֻ�������õ�ɫ��ģʽ(EN_ACT_SAVE)
			  	   							��ִ������ɫ��ģʽ���������õ�ɫ��ģʽ��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_pq_color_paramter(EN_FPI_PQ_COLOR_PARAMTER color,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_pq_color_paramter
			��ȡ��ǰ���õ�ɫ��
@param[out]  color  ��ȡ���ĵ�ǰ���õ�ɫ��ģʽ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_pq_color_paramter(EN_FPI_PQ_COLOR_PARAMTER *color);

/**
@brief      	  tos_pq_set_gamma      
			  ���û򱣴�ͼ����ʾ��٤��	
@param[in]      e_video_mode  ͼ��ģʽ����ͬ��ͼ��ģʽ�¿������ò�ͬ��٤�����Ա��治ͬ��٤��		��
						   ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��٤��	�����Ըò���Ŀ		 
						   ǰ��ʱû���õ�
@param [in]	 value  ٤��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�٤��	ģʽ(EN_ACT_EXEC)
			  	   							ֻ�������õ�٤��	ģʽ(EN_ACT_SAVE)
			  	   							��ִ������٤��	ģʽ���������õ�٤��ģʽ��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_gamma(EN_VIDEO_MODE e_mode,int16_t value,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_gamma
			��ȡ��ǰ���õ�٤��
@param[in]    e_video_mode  ͼ��ģʽ��٤��ģʽ���Ը���ͼ��ģʽ�Ĳ�ͬ�ֿ����棬���Ի�ȡ�ڲ�ͬͼ��ģʽ�µ����õĵ�ǰ٤��ģʽ
						    				    ���ڻ�û������Ҫ��ͬ��ͼ��ģʽ�±�������ò�ͬ��٤��ģʽ�����Ըò���Ŀǰ��ʱû���õ�
@param[out]  value  ��ȡ���ĵ�ǰ���õ�٤��ģʽ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_pq_get_gamma(EN_VIDEO_MODE e_mode,int16_t *value);

/**
@brief      	  tos_pq_set_white_balance_gain      
			���ð�ƽ������棬��Ӧɫ��ѡ��Ϊ�Զ���ʱ����ʾ
@param [in]	 red  ���ɫ����Χ[-30,30] 
@param [in]	 green  �̻�ɫ����Χ[-30,30] 
@param [in]	 blue  ����ɫ����Χ[-30,30] 
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_white_balance_gain(int16_t red,int16_t green,int16_t blue,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_white_balance_gain
			��ȡ��ǰ���õĺ���������ɫ����ֵ����Χ[-30,30] 
@param[out]  red  ��ȡ���ĵ�ǰ���õĺ��ɫ
@param[out]  green  ��ȡ���ĵ�ǰ���õ��̻�ɫ
@param[out]  blue  ��ȡ���ĵ�ǰ���õ�����ɫ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_white_balance_gain(int16_t *red,int16_t *green,int16_t *blue);


/**
@brief      	  tos_pq_set_white_balance_offset      
			���ð�ƽ���ƫ�ƣ���Ӧɫ��ѡ��Ϊ�Զ���ʱ����ʾ
@param [in]	 red  ���ɫ����Χ[-30,30] 
@param [in]	 green  �̻�ɫ����Χ[-30,30] 
@param [in]	 blue  ����ɫ����Χ[-30,30] 
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_white_balance_offset(int16_t red,int16_t green,int16_t blue,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_white_balance_offset
			��ȡ��ǰ���õĺ���������ɫ����ֵ����Χ[-30,30] 
@param[out]  red  ��ȡ���ĵ�ǰ���õĺ��ɫ
@param[out]  green  ��ȡ���ĵ�ǰ���õ��̻�ɫ
@param[out]  blue  ��ȡ���ĵ�ǰ���õ�����ɫ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_white_balance_offset(int16_t *red,int16_t *green,int16_t *blue);
/**
@brief		tos_pq_get_special_effect
			���ͼ�����ʾЧ���� ���Ի����������ɫ�ʵ��Զ��������
@param[in]    e_type  ��ͬЧ��ģʽ������ο�ö��EN_VIDEO_EFFECT_TYPE˵��
@param[out]  enable  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_pq_get_special_effect(EN_VIDEO_EFFECT_TYPE e_type,int16_t *enable,EN_ACT_CTRL act);

/**
@brief      	  tos_pq_set_special_effect      
			  ����ͼ�����ʾЧ���� ���Ի����������ɫ�ʵ��Զ��������
@param[in]      e_type  ��ͬЧ��ģʽ������ο�ö��EN_VIDEO_EFFECT_TYPE˵��
@param [in]	 enable  ״̬��ֵ����ͬ�Ĳ�����Ӧ��ͬ��״̬
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_special_effect(EN_VIDEO_EFFECT_TYPE e_type,int16_t enable,EN_ACT_CTRL act);


/**
@brief      	  tos_pq_set_rgb_mode      
			  ����RGB����ͨ����ģʽ����Ӧ���ǰѰ�ƽ����ͨ�������зֿ��ر�,���������ݿ�
@param[in]      mode  ��ͬЧ��ģʽ��REDʱ�򣬽���ƽ��������ɫ�رգ���ֻ�к�ɫ������ͬ��
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_rgb_mode(EN_COLOR_TYPE mode,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_rgb_mode
			��õ�ǰRGB����ͨ����ģʽ
@param[in]    e_type  ��ͬЧ��ģʽ������ο�ö��EN_VIDEO_EFFECT_TYPE˵��
@param[out]  enable  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_rgb_mode(EN_COLOR_TYPE *value);

/**
@brief      	  tos_pq_set_mpeg_nr      
			  ����MPEG�����״̬
@param[in]      level  MPEG����Ч��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_mpeg_nr(EN_FPI_MPEG_NR_MODE level,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_mpeg_nr
			���MPEG�����״̬
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_mpeg_nr(EN_FPI_MPEG_NR_MODE *value);

/**
@brief      	  tos_pq_set_noise_reduction      
			  ���ý����״̬
@param[in]      level  ����Ч��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_noise_reduction(EN_FPI_NOISE_REDUCTION_MODE level,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_noise_reduction
			��ý����״̬
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_noise_reduction(EN_FPI_NOISE_REDUCTION_MODE *value);

/**
@brief		tos_pq_get_memc_config
			����˶�������״̬
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_memc_config(EN_FPI_MEMC_CONFIG *config);
/**
@brief      	  tos_pq_set_memc_config      
			  �����˶�������״̬
@param[in]      config  �˶�����Ч��ģʽ����ͬ�Ĳ�����Ӧ��ͬ��ģʽ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_memc_config(EN_FPI_MEMC_CONFIG config,EN_ACT_CTRL act);


/**
@brief		tos_pq_get_memc_effect
			����˶������Զ����Ч��
@param[in]    type  ��ͬ��������ģʽ������ο�ö��EN_MEMC_EFFECT_TYPE˵��
@param[out]  level  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_pq_get_memc_effect(EN_MEMC_EFFECT_TYPE type,int16_t *level);

/**
@brief      	  tos_pq_set_memc_effect      
			  �����˶������Զ����Ч���� 
@param[in]      type  ��ͬ��������ģʽ������ο�ö��EN_MEMC_EFFECT_TYPE˵��
@param [in]	 level  ״̬��ֵ����ͬ�Ĳ�����Ӧ��ͬ��״̬
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/


fpi_error tos_pq_set_memc_effect(EN_MEMC_EFFECT_TYPE type,int16_t level,EN_ACT_CTRL act);


/**
@brief      	  tos_pq_set_color_gamma_enable      
			  ����ɫ��ͨ����gamma��������
@param[in]      enable  ����
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_gamma_enable(int16_t enable,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_gamma_enable
			���ɫ��ͨ����gamma�Ƿ���
@param[out]  enable  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_color_gamma_enable(int16_t *enable);


/**
@brief      	  tos_pq_set_color_gamma_interval      
			   ����ɫ��gamma�ļ������GAMMA�����ϵ�ȡ����
@param[in]      interval  ��Ӧȡ����
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_gamma_interval(int16_t interval,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_gamma_interval
			���ɫ��gamma�ļ��
@param[out]  interval  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_color_gamma_interval(int16_t *interval);



/**
@brief      	  tos_pq_set_color_gamma      
			   ����ɫ��gamma�����ϵ�ȡ�����Ч��
@param[in]      color  ��ԭɫ������ο�ö��EN_COLOR_TYPE˵��
@param[in]      value  ��Ӧ���õ���ֵ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_gamma(EN_COLOR_TYPE color, int16_t value,EN_ACT_CTRL act );


/**
@brief		tos_pq_get_color_gamma
			���ɫ��gamma�����ϵ�ȡ�����Ч��
@param[in]      color  ��ԭɫ������ο�ö��EN_COLOR_TYPE˵��
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_color_gamma(EN_COLOR_TYPE color, int16_t *value );


/**
@brief      	  tos_pq_set_color_space_mode      
			����ɫ�ʿռ��ģʽ
@param[in]      mode  ��ͬģʽ��Ӧ��ͬ��Ч��������ο�ö��EN_FPI_COLOR_SPACE_MODE˵��
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_space_mode(EN_FPI_COLOR_SPACE_MODE mode,EN_ACT_CTRL act);
/**
@brief		tos_pq_get_color_space_mode
			��õ�ǰ��ɫ�ʿռ��ģʽ
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/


fpi_error tos_pq_get_color_space_mode(EN_FPI_COLOR_SPACE_MODE *mode);

/**
@brief      	  tos_pq_set_color_type      
		 ����ɫ������
@param[in]      csMode  ��ͬģʽ��Ӧ��ͬ��Ч��������ο�ö��EN_FPI_CS_COLOR_MODE˵��
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_type(EN_FPI_CS_COLOR_MODE csMode,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_type
			��õ�ǰ��ɫ�ʿռ��ģʽ
@param[out]  csMode  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_color_type(EN_FPI_CS_COLOR_MODE *csMode);

/**
@brief      	  tos_pq_set_color_space      
		 ����ɫ�ʿռ�ÿһ��ɫ�ʵ�ֵ
@param[in]      color  ��ԭɫ������ο�ö��EN_COLOR_TYPE˵��
@param[in]      value  ��Ӧ���õ���ֵ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_color_space(EN_COLOR_TYPE color,int16_t value ,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_color_type
			 ���ɫ�ʿռ�ÿһ��ɫ�ʵ�ֵ
@param[in]      color  ��ԭɫ������ο�ö��EN_COLOR_TYPE˵��
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_color_space(EN_COLOR_TYPE color,int16_t *value);
/** 
@brief ��ȡ4K1K״̬�±���ռ�ձ� 

@note ��̬����ģ�鸺�����

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_pq_get_led_motion_clarity(EN_FPI_CLARITY_TYPE *clarity_type);




/** 
@brief ����4K1K״̬�±���ռ�ձ�

@note  ��̬����ģ�鸺�����

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_pq_set_led_motion_clarity(EN_FPI_CLARITY_TYPE clarity_type,EN_ACT_CTRL act);

/**
@brief		tos_pq_get_motion_mode_is_use
			�ж��û��Ƿ������motion clarity���ܵ���ֵ 
@param[in]      motion_mode����ǰ���˶���Чģʽ������ο�ö��EN_FPI_MOTION_CLARITY_MODE˵��
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_motion_mode_is_use(int16_t *value,EN_FPI_MOTION_CLARITY_MODE motion_mode);

/**
@brief      	  tos_pq_set_PQ_demo      
		 ���û�����ʾģʽ������洢���ݿ�
@param[in]      color  ���ò�ͬ����ʾЧ��������ο�ö��EN_FPI_PQ_DEMO_MODE˵��
@param[in]      value  ��Ӧ���õ���ֵ
@param [in]	 act  �ӿ�ִ�е�״̬�� ����ѡ��ִֻ�в��������õ�״̬(EN_ACT_EXEC)
			  	   							ֻ�������õ�״̬(EN_ACT_SAVE)
			  	   							��ִ������״̬���������õ�״̬��������(EN_ACT_EXEC_SAVE)
@param[out]    NONE
@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/

fpi_error tos_pq_set_PQ_demo(EN_FPI_PQ_DEMO_MODE mode);


/**
@brief		tos_pq_get_color_type
			 ��û�����ʾģʽ��ֵ�����������ȡ
@param[out]  value  ��ȡ���ĵ�ǰ���õ�״̬��ֵ
@retval	    	FPI_ERROR_SUCCESS   ��ʾ��ȡ�ɹ�
@retval         FPI_ERROR_FAIL          ��ʾ��ȡʧ��  
*/

fpi_error tos_pq_get_PQ_demo(EN_FPI_PQ_DEMO_MODE *value);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
