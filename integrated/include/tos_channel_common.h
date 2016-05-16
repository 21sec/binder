
/**@defgroup 搜台或节目操作的一些基本公用结构数据
@{

@brief 

@author 

@note 

@version 1.0.0 2015/3/25  初稿
*/




#ifndef __TOS_CHANNEL_COMMON_H__
#define __TOS_CHANNEL_COMMON_H__

#include "fpi_error_code.h"
#include "fpi_base_type.h"



#ifdef __cplusplus
extern "C" {
#endif


/**
@brief 对搜台频道的动作
**/
typedef enum{
	EN_ATV_SCAN_CHANNEL_SAVE,  ///<保存
	EN_ATV_SCAN_CHANNEL_REPLACE,///<覆盖
	EN_ATV_SCAN_CHANNEL_CANCEL_SAVE,///<取消保存
}EN_ATV_SCAN_CTRL;

typedef struct
{
 	int32_t atv_scan_count;
	int32_t dtv_scan_count;
	int32_t radio_scan_count;
	int32_t scaned_freq;
	int32_t scaned_progress;
} st_api_scanning_info_t;

 
#ifdef __cplusplus
}
#endif
/** @} */

#endif //__TOS_CHANNEL_COMMON_H__
