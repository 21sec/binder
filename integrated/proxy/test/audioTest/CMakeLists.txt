include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/)

set(LIB_MESSAGE_LH_SRC 
	main.c)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})
add_executable(audioTestClient ${LIB_MESSAGE_LH_SRC})
set_target_properties(audioTestClient  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(audioTestClient  -Wl,--start-group ${PROXY_LIB_NAME}S  libtoolsets.a libtcliS.a libFpiOsLinuxC.a  -Wl,--end-group )