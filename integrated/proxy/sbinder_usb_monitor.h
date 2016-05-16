/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: sbinder_usb_monitor.sidl
 */

#ifndef __sbinder_usb_monitor_h__
#define __sbinder_usb_monitor_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "tos_usb_monitor.h"
#include "fpi_base_type.h"
#include "fpi_error_code.h"


///< call this api to only add this service
int sbinder_usb_monitor_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif