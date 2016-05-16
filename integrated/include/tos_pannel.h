/**@defgroup 屏的设置
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/17 linshunda 初稿
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


//背光可控制阵列
typedef struct _ST_FPI_PANEL_LED_ARRAY_T
{
	uint32_t horizontal_control_point_num;  // 背光水平方向上有多少可控制列
	uint32_t vertical_control_point_num;      // 背光垂直方向上有多少可控制行
}ST_FPI_PANEL_LED_ARRAY_T;

//背光灯的行为状态
typedef enum _EN_FPI_PANEL_SHINE_ACTION_T
{
	EN_PANEL_SHINE_ALL_ON_IMMEDIATELY,            //背光所有灯立即全亮
	EN_PANEL_SHINE_ALL_OFF_IMMEDIATELY,          //背光灯所有灯立即全灭
	EN_PANEL_SHINE_ONEBYONE_ALLWAYS,              // 一颗一颗点，点亮之后一直亮
	EN_PANEL_SHINE_ONEBYONE_BRIGHT_DELAY,   //一颗一颗点，点亮之后在一定时间内慢慢熄灭
	EN_PANEL_SHINE_ONEBYONE_OTHER,                  //其它情况
	EN_PANEL_SHINE_KEEP_LAST,                                //只保留最后点亮的一颗
	EN_PANEL_SHINE_NUM
}EN_FPI_PANEL_SHINE_ACTION_T;


//背光灯的扫描行为
typedef enum _EN_FPI_PANEL_DIR_T
{
	EN_PANEL_DIR_CLOCKWISE,                          // 顺时针，通常适用于开始点和结束点相同的情况
	EN_PANEL_DIR_ANTICLOCKWISE,                // 逆时针，通常适用于开始点和结束点相同的情况
	EN_PANEL_DIR_LINE_BY_LINE,                    // 一行一行扫描
	EN_PANEL_DIR_COLUMN_BY_COLUMN,      // 一列一列扫描
	EN_PANEL_DIR_RECTANGLE,                        // 点亮以起点和终点为对角线组成的矩形区域
	EN_PANEL_DIR_NUM
}EN_FPI_PANEL_DIR_T;

//背光灯的位置定义
typedef enum _EN_FPI_PANEL_POS_T
{
	EN_PANEL_POS_LEFT_TOP,                      //左上角的一颗    
	EN_PANEL_POS_RIGHT_TOP,                  //右上角的一颗 
	EN_PANEL_POS_LEFT_BOTTOM,             //左下角的一颗 
	EN_PANEL_POS_RIGHT_BOTTOM,         //右下角的一颗 
	EN_PANEL_POS_MIDDLE,                        //正中间的一颗 
	EN_PANEL_POS_USER_DEFINE,             //用户根据tos_panel_local_dimming_array_get获取的阵列，自行输入hpos和vpos
	EN_PANEL_POS_DRV_FREE_RUN,         //预留，特殊情况下由底层driver自行决定
	EN_PANEL_POS_NUM
}EN_FPI_PANEL_POS_T;

typedef struct _ST_FPI_PANEL_POS_INFO_T
{
	EN_FPI_PANEL_POS_T      pos;                 //参考EN_FPI_PANEL_POS_T 定义
	uint32_t                h_pos;           //如果pos 为EN_PANEL_POS_USER_DEFINE，必须输入h_pos，否则可以不输入
	uint32_t                v_pos;          //如果pos 为EN_PANEL_POS_USER_DEFINE，必须输入v_pos，否则可以不输入
}ST_FPI_PANEL_POS_INFO_T;

typedef struct _ST_FPI_PANEL_CTRL_INFO_T
{
	EN_FPI_PANEL_SHINE_ACTION_T  action;           // LOCAL_DIMMING的表现行为，参考EN_FPI_PANEL_SHINE_ACTION_T定义
	EN_FPI_PANEL_DIR_T  dir;                                     // LOCAL_DIMMING的扫描方式，参考EN_FPI_PANEL_DIR_T定义
	ST_FPI_PANEL_POS_INFO_T start_pos;             // LOCAL_DIMMING开始的位置，如果参数是EN_PANEL_POS_USER_DEFINE
	ST_FPI_PANEL_POS_INFO_T end_pos;              // LOCAL_DIMMING结束的位置，如果参数是EN_PANEL_POS_USER_DEFINE
}ST_FPI_PANEL_CTRL_INFO_T;

/**
@brief 设置背光可控制阵列信息，当设置为0,0 时不起作用，即不能通过fpp_pannel_local_dimming_ctrl接口控制LOCALDIMMING
@param[in] array 背光可控制阵列信息(列数与行数)
@param[out] NONE
@return FPI_ERROR_SUCCESS 执行成功
	     FPI_ERROR_FAIL 执行失败
*/

fpi_error tos_panel_local_dimming_array_set(ST_FPI_PANEL_LED_ARRAY_T* array);
/**
@brief     控制LOCAL_DIMMING背光的显示效果
@param [in]   info  控制LOCAL_DIMMING背光的相关参数
@param [out] NONE
@return FPI_ERROR_SUCCESS 执行成功;   FPI_ERROR_FAIL 执行失败
*/
fpi_error tos_panel_local_dimming_ctrl(ST_FPI_PANEL_CTRL_INFO_T* info);


/** 
@brief 获取屏类型

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_panel_get_type(EN_FPI_PANEL_TYPE *panel_type);

/** 
@brief 设置屏的模式:4k,2k,等

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_panel_set_mode(EN_FPI_PANEL_MODE mode,EN_ACT_CTRL act);


/** 
@brief 获取屏的模式:4k,2k,等

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_panel_get_mode(EN_FPI_PANEL_MODE *mode);

/** 
@brief 获取当前屏的大小；

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_panel_get_size(st_fpi_panel_property *value);

/** 
@brief 获取当前屏是60HZ，120HZ；

@note 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/
fpi_error tos_panel_get_refreshrate(int16_t *panel_freq);
/** 
@brief 获取屏幕的尺寸，长宽
@param[out] width 
              屏幕的宽cm
@param[out] height 
              屏幕的高cm
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值*/

fpi_error tos_panel_get_physical_size( int32_t* width, int32_t* height );


#ifdef __cplusplus
}
#endif
/** @} */

#endif //__API_PICTURE_SETTING_H__
