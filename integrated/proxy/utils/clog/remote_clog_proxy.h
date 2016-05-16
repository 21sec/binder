/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_clog_proxy.sidl
 */

#ifndef __remote_clog_proxy_h__
#define __remote_clog_proxy_h__



#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

#include "clog.h"
#include "_clog.h"


///< call this api to only add this service
int remote_clog_proxy_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif

#ifdef __cplusplus
}
#endif

#endif