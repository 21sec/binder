/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_zoom.sidl
 */

#ifndef __sbinder_zoom_h__
#define __sbinder_zoom_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "fpp_zoom.h"


///< call this api to only add this service
int sbinder_zoom_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif