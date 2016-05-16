include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/)

set(LIB_MESSAGE_LH_SRC 
	tos_androidHandler_testMain.c)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})
add_executable(TESTHandleLooper ${LIB_MESSAGE_LH_SRC})
set_target_properties(TESTHandleLooper  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(TESTHandleLooper  -Wl,--start-group ${PROXY_LIB_NAME}S  libtoolsets.a libUtilClogS.a libtcliS.a libFpiOsLinuxC.a   -Wl,--end-group)


