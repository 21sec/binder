/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: /home/weigj/samba/sita/tbrowser/integrated/proxy/sbinder_tbrowser.sidl
 */

#ifndef __sbinder_tbrowser_h__
#define __sbinder_tbrowser_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "tos_tbrowser.h"
 #include "tos_key_code.h"


///< call this api to only add this service
int sbinder_tbrowser_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif