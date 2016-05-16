##################################################
#                                                #
# Main CMakeLists for F1 SRC    .                #
#                                                #
# Author : linshunda, linshunda@tcl.com          #
##################################################

set(PROJECT_DIR_INTEGRATED ${PROJECT_SOURCE_DIR}/integrated)

add_subdirectory(server)
add_subdirectory(client)

add_subdirectory(proxy)

if(COMPILE_SITA_SERVICE)
add_subdirectory(${PROJECT_DIR_INTEGRATED}/server/service/service_socket)
endif()

#add_subdirectory(${PROJECT_DIR_INTEGRATED}/client/interface/test)
