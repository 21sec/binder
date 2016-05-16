/**@defgroup ��������
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/



#ifndef __TOS_PANEL__H__
#define __TOS_PANEL__H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    EN_PANEL_MODE_4K2K,   //open 4k2k mode  
    EN_PANEL_MODE_NORMAL, //close 4k2k mode
    EN_PANEL_MODE_MAX,
}EN_FPI_PANEL_MODE;


//����ɿ�������
typedef struct _ST_FPI_PANEL_LED_ARRAY_T
{
	uint32_t horizontal_control_point_num;  // ����ˮƽ�������ж��ٿɿ�����
	uint32_t vertical_control_point_num;      // ���ⴹֱ�������ж��ٿɿ�����
}ST_FPI_PANEL_LED_ARRAY_T;

//����Ƶ���Ϊ״̬
typedef enum _EN_FPI_PANEL_SHINE_ACTION_T
{
	EN_PANEL_SHINE_ALL_ON_IMMEDIATELY,            //�������е�����ȫ��
	EN_PANEL_SHINE_ALL_OFF_IMMEDIATELY,          //��������е�����ȫ��
	EN_PANEL_SHINE_ONEBYONE_ALLWAYS,              // һ��һ�ŵ㣬����֮��һֱ��
	EN_PANEL_SHINE_ONEBYONE_BRIGHT_DELAY,   //һ��һ�ŵ㣬����֮����һ��ʱ��������Ϩ��
	EN_PANEL_SHINE_ONEBYONE_OTHER,                  //�������
	EN_PANEL_SHINE_KEEP_LAST,                                //ֻ������������һ��
	EN_PANEL_SHINE_NUM
}EN_FPI_PANEL_SHINE_ACTION_T;


//����Ƶ�ɨ����Ϊ
typedef enum _EN_FPI_PANEL_DIR_T
{
	EN_PANEL_DIR_CLOCKWISE,                          // ˳ʱ�룬ͨ�������ڿ�ʼ��ͽ�������ͬ�����
	EN_PANEL_DIR_ANTICLOCKWISE,                // ��ʱ�룬ͨ�������ڿ�ʼ��ͽ�������ͬ�����
	EN_PANEL_DIR_LINE_BY_LINE,                    // һ��һ��ɨ��
	EN_PANEL_DIR_COLUMN_BY_COLUMN,      // һ��һ��ɨ��
	EN_PANEL_DIR_RECTANGLE,                        // �����������յ�Ϊ�Խ�����ɵľ�������
	EN_PANEL_DIR_NUM
}EN_FPI_PANEL_DIR_T;

//����Ƶ�λ�ö���
typedef enum _EN_FPI_PANEL_POS_T
{
	EN_PANEL_POS_LEFT_TOP,                      //���Ͻǵ�һ��    
	EN_PANEL_POS_RIGHT_TOP,                  //���Ͻǵ�һ�� 
	EN_PANEL_POS_LEFT_BOTTOM,             //���½ǵ�һ�� 
	EN_PANEL_POS_RIGHT_BOTTOM,         //���½ǵ�һ�� 
	EN_PANEL_POS_MIDDLE,                        //���м��һ�� 
	EN_PANEL_POS_USER_DEFINE,             //�û�����tos_panel_local_dimming_array_get��ȡ�����У���������hpos��vpos
	EN_PANEL_POS_DRV_FREE_RUN,         //Ԥ��������������ɵײ�driver���о���
	EN_PANEL_POS_NUM
}EN_FPI_PANEL_POS_T;

typedef struct _ST_FPI_PANEL_POS_INFO_T
{
	EN_FPI_PANEL_POS_T      pos;                 //�ο�EN_FPI_PANEL_POS_T ����
	uint32_t                h_pos;           //���pos ΪEN_PANEL_POS_USER_DEFINE����������h_pos��������Բ�����
	uint32_t                v_pos;          //���pos ΪEN_PANEL_POS_USER_DEFINE����������v_pos��������Բ�����
}ST_FPI_PANEL_POS_INFO_T;

typedef struct _ST_FPI_PANEL_CTRL_INFO_T
{
	EN_FPI_PANEL_SHINE_ACTION_T  action;           // LOCAL_DIMMING�ı�����Ϊ���ο�EN_FPI_PANEL_SHINE_ACTION_T����
	EN_FPI_PANEL_DIR_T  dir;                                     // LOCAL_DIMMING��ɨ�跽ʽ���ο�EN_FPI_PANEL_DIR_T����
	ST_FPI_PANEL_POS_INFO_T start_pos;             // LOCAL_DIMMING��ʼ��λ�ã����������EN_PANEL_POS_USER_DEFINE
	ST_FPI_PANEL_POS_INFO_T end_pos;              // LOCAL_DIMMING������λ�ã����������EN_PANEL_POS_USER_DEFINE
}ST_FPI_PANEL_CTRL_INFO_T;

/**
@brief ���ñ���ɿ���������Ϣ��������Ϊ0,0 ʱ�������ã�������ͨ��fpp_pannel_local_dimming_ctrl�ӿڿ���LOCALDIMMING
@param[in] array ����ɿ���������Ϣ(����������)
@param[out] NONE
@return FPI_ERROR_SUCCESS ִ�гɹ�
	     FPI_ERROR_FAIL ִ��ʧ��
*/

fpi_error tos_panel_local_dimming_array_set(ST_FPI_PANEL_LED_ARRAY_T* array);
/**
@brief     ����LOCAL_DIMMING�������ʾЧ��
@param [in]   info  ����LOCAL_DIMMING�������ز���
@param [out] NONE
@return FPI_ERROR_SUCCESS ִ�гɹ�;   FPI_ERROR_FAIL ִ��ʧ��
*/
fpi_error tos_panel_local_dimming_ctrl(ST_FPI_PANEL_CTRL_INFO_T* info);


/** 
@brief ��ȡ������

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_panel_get_type(EN_FPI_PANEL_TYPE *panel_type);

/** 
@brief ��������ģʽ:4k,2k,��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_panel_set_mode(EN_FPI_PANEL_MODE mode,EN_ACT_CTRL act);


/** 
@brief ��ȡ����ģʽ:4k,2k,��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_panel_get_mode(EN_FPI_PANEL_MODE *mode);

/** 
@brief ��ȡ��ǰ���Ĵ�С��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_panel_get_size(st_fpi_panel_property *value);

/** 
@brief ��ȡ��ǰ����60HZ��120HZ��

@note 

@note 

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_panel_get_refreshrate(int16_t *panel_freq);
/** 
@brief ��ȡ��Ļ�ĳߴ磬����
@param[out] width 
              ��Ļ�Ŀ�cm
@param[out] height 
              ��Ļ�ĸ�cm
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/

fpi_error tos_panel_get_physical_size( int32_t* width, int32_t* height );


#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
