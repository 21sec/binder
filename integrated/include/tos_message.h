
/**@defgroup 消息处理
@{

@brief 

@author 

@note 

@version 1.0.0 2015-3-23 18:34:08
*/


#ifndef __TOS_MESSAGE_H__
#define __TOS_MESSAGE_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	int msg;
	int data1;
	int data2;
    void *data;
    int datasize;
}st_msg_notify_t;


typedef int (*tos_msg_cb)(st_msg_notify_t* msg,void* userdata);


fpi_error tos_msg_add_callback(tos_msg_cb callback,void* userdata);

fpi_error tos_msg_remove_callback(tos_msg_cb callback,void* userdata);


#ifdef __cplusplus
}
#endif
/** @} */

#endif


