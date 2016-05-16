/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_tifhal_helper.sidl
 */

#ifndef __remote_tifhal_helper_h__
#define __remote_tifhal_helper_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "tos_tifhal_helper.h"


///< call this api to only add this service
int remote_tifhal_helper_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif