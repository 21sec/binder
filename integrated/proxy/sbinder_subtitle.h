/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_subtitle.sidl
 */

#ifndef __sbinder_subtitle_h__
#define __sbinder_subtitle_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#include "tos_subtitle.h"


///< call this api to only add this service
int sbinder_subtitle_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif