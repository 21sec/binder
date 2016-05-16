#ifndef __sbinder_message_h__
#define __sbinder_message_h__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BINDER_SERVICE)

 #include "tos_message.h"


///< call this api loop for ever and star service
int sbinder_message_service_serv();

///< call this api to only add this service
int sbinder_message_service_add();

#elif defined(BINDER_CLIENT)
 #error This file is only used on server
#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif


#ifdef __cplusplus
}
#endif

#endif