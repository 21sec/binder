##################################################
#                                                #
# Main CMakeLists               .                #
#                                                #
# Author : ganyue, gany@tcl.com                  #
##################################################
#CLIENT for PROPERTYTEST  lib
add_definitions(${SBINDER_CMAKE_FLAGS})

set(BIN_SBINDER_PROPERTY_SRC_SERVER
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_property_main.c
)


add_executable(PROPERTYCLIENT ${BIN_SBINDER_PROPERTY_SRC_SERVER} )
set_target_properties(PROPERTYCLIENT  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(PROPERTYCLIENT ${PROXY_LIB_NAME}S)

