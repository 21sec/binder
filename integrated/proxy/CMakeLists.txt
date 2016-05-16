##################################################
#                                                #
# Main CMakeLists               .                #
#                                                #
# Author : ganyue, gany@tcl.com                  #
##################################################
#SERVER for PROXYTEST  lib
include_directories(${PROJECT_DIR_INTEGRATED}/proxy/utils)
include_directories (${INCLUDE_DIRECTORY_CORE})
include_directories (${PROJECT_SOURCE_DIR}/porting/include/fpp)

aux_source_directory(. SRC_LIB_SBINDER_PROXY)

set(LIB_SBINDER_SHARE
   ${SRC_LIB_SBINDER_PROXY}
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/property/remote_property_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/property/stringspool.c
   ${CMAKE_CURRENT_SOURCE_DIR}/utils/tcli/remote_tos_tcli.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/proxy.c
)

#----------------------------------------------

set(LIB_SBINDER_PROXY_SERVER
   ${LIB_SBINDER_SHARE}
)

add_library(${SPROXY_LIB_NAME} SHARED ${LIB_SBINDER_PROXY_SERVER} )
set_target_properties(${SPROXY_LIB_NAME} PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
add_dependencies(${SPROXY_LIB_NAME} libbinderservicemanager.a libStandaloneBinderS.a libUtiLog.a libAndroidToolsetsS.a )
##target_link_libraries(${SPROXY_LIB_NAME} -Wl,-whole-archive libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a -Wl,-no-whole-archive)
target_link_libraries(${SPROXY_LIB_NAME} libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
##target_link_libraries(${SPROXY_LIB_NAME} ${SBINDER_PLTFORM_LINK_LIBRARIES}  -Wl,-whole-archive libUtiLog.a -Wl,-no-whole-archive)
target_link_libraries(${SPROXY_LIB_NAME} ${SBINDER_PLTFORM_LINK_LIBRARIES}  libUtiLog.a libAndroidToolsetsS.a )

add_library(${SPROXY_LIB_NAME}S STATIC ${LIB_SBINDER_PROXY_SERVER} )
set_target_properties(${SPROXY_LIB_NAME}S PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
add_dependencies(proxyS libbinderservicemanager.a libStandaloneBinderS.a libUtiLog.a libAndroidToolsetsS.a )
target_link_libraries(${SPROXY_LIB_NAME}S libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
target_link_libraries(${SPROXY_LIB_NAME}S ${SBINDER_PLTFORM_LINK_LIBRARIES} libUtiLog.a libAndroidToolsetsS.a)


#----------------------------------------------


#CLIENT for PROXYTEST lib
set(LIB_SBINDER_PROXY_CLIENT
   ${LIB_SBINDER_SHARE}
#   ${PROJECT_SOURCE_DIR}/utils/log/tos_log.cpp
)

add_library(${API_LIB_NAME} SHARED ${LIB_SBINDER_PROXY_CLIENT} )
set_target_properties( ${API_LIB_NAME} PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
add_dependencies(${API_LIB_NAME} libbinderservicemanager.a libStandaloneBinderS.a libUtiLog.a libAndroidToolsetsS.a )
target_link_libraries(${API_LIB_NAME} LINK_PRIVATE -Wl,--no-allow-shlib-undefined -Wl,-whole-archive libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a libFpiOsLinuxC.a libutility.a -Wl,-no-whole-archive)
target_link_libraries(${API_LIB_NAME} LINK_PUBLIC ${SBINDER_PLTFORM_LINK_LIBRARIES})
target_link_libraries(${API_LIB_NAME} LINK_PRIVATE -Wl,-whole-archive libUtiLog.a -Wl,-no-whole-archive )


add_library(${PROXY_LIB_NAME}S STATIC ${LIB_SBINDER_PROXY_CLIENT} )
set_target_properties( ${PROXY_LIB_NAME}S PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
add_dependencies(${PROXY_LIB_NAME}S libbinderservicemanager.a libStandaloneBinderS.a libUtiLog.a libAndroidToolsetsS.a )
target_link_libraries(${PROXY_LIB_NAME}S libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
target_link_libraries(${PROXY_LIB_NAME}S ${SBINDER_PLTFORM_LINK_LIBRARIES} libUtiLog.a libAndroidToolsetsS.a)
add_subdirectory(utils)
add_subdirectory(test)
