/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: remote_itv_smc_module.sidl
 */

#ifndef __remote_itv_smc_module_h__
#define __remote_itv_smc_module_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "itv_defines.h"
#include "itv_smc.h"


///< call this api to only add this service
int remote_itv_smc_module_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif