##################################################
#                                                #
# CMakeLists for F1 fpi_route service src .                  #
#                                                #
# Author : linshunda, linshunda@tcl.com          #
##################################################

aux_source_directory(${PROJECT_DIR_INTEGRATED}/server/service/service_socket SRC_FPI_ROUTE_SERVICE_SRC_SOCKET )
#aux_source_directory(. SRC_FPI_ROUTE_SERVICE_SRC_SOCKET)
include_directories(${INCLUDE_DIRECTORY_CORE})
include_directories(${INCLUDE_DIRECTORY_CORE_DTV_INNER})

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

if(OUT_SO_LIB)
add_executable(tvh_service_socket ${SRC_FPI_ROUTE_SERVICE_SRC_SOCKET})

if(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)
	set_target_properties(tvh_service_socketS PROPERTIES LINKER_LANGUAGE CXX )
elseif(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_C)
	set_target_properties(tvh_service_socketS PROPERTIES LINKER_LANGUAGE C )
else(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)
endif(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)

target_link_libraries(tvh_service_socket ${SERVICE_LINK_LIBRARIES_SO} SitaTest.so) 

	if(SYS_OS STREQUAL android)
	add_library(libtvh_service SHARED ${SRC_FPI_ROUTE_SERVICE_SRC_SOCKET})
	target_link_libraries(libtvh_service ${SERVICE_LINK_LIBRARIES_SO})
	set_target_properties(libtvh_service PROPERTIES OUTPUT_NAME "tvh_service")
	endif(SYS_OS STREQUAL android)
	
endif() 

if(OUT_STATIC_LIB)
add_executable(${TVH_SERVICE_NAME} ${SRC_FPI_ROUTE_SERVICE_SRC_SOCKET})


if(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)
	set_target_properties(${TVH_SERVICE_NAME} PROPERTIES LINKER_LANGUAGE CXX COMPILE_DEFINITIONS "BINDER_SERVICE")
elseif(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_C)
	set_target_properties(${TVH_SERVICE_NAME} PROPERTIES LINKER_LANGUAGE C COMPILE_DEFINITIONS "BINDER_SERVICE")
else(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)
endif(SET_LINKER_LANGUAGE_SERVICE STREQUAL LANGUAGE_CXX)

target_link_libraries(${TVH_SERVICE_NAME} ${SPROXY_LIB_NAME}S)
target_link_libraries(${TVH_SERVICE_NAME} ${SITA_LINK_LIBRARIES})
	
endif() 


