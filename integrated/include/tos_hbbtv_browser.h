/**@defgroup hbbtv
@{

@author 

@note 

@version 1.0.0 2016/04/06 liujian ����
*/

#ifndef __TOS_TBROWSER_TEST_H__
#define __TOS_TBROWSER_TEST_H__

#ifndef CLOG_TAG
#define CLOG_TAG "clog_tbrowser"
#endif

#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif
/** 
@brief����Ӧ�����¼� (���Androidƽ̨��hbbtv����ֱ�Ӵ��͸�hbbtv���̣��������м��)
@param[in] keyCode����ֵ��keyType:�����¼����ͣ�
@param[out] isHandle��hbbtv�Ƿ�ʹ�øð����������˸ð�������fpi_true;��֮����fpi_false
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ 
*/ 
fpi_error tos_hbbtv_browser_handle_key(uint16_t keyCode,uint16_t keyType,fpi_bool* isHandle);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
