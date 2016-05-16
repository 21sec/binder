/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_hbbtv.sidl
 */

#ifndef __sbinder_hbbtv_h__
#define __sbinder_hbbtv_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 

///< call this api to only add this service
int sbinder_hbbtv_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif