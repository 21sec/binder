include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(TCLI_TEST_SERVER_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/test_tcli_server.c tvh_debug_server_tcli.c 
   tvh_debug_server_log_tcli.c 
)

set(TCLI_TEST_SERVER_LIB_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/tos_debug_common.c tvh_debug_server_tcli.c 
   tvh_debug_server_log_tcli.c 
)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

add_executable(tclicmdtoolserver ${TCLI_TEST_SERVER_SRC} )
set_target_properties(tclicmdtoolserver  PROPERTIES OUTPUT_NAME "tcli_server" )
target_link_libraries(tclicmdtoolserver ${PROXY_LIB_NAME}S libSitaTestS)
if(COMPILER_USE_BIONIC)
target_link_libraries(tclicmdtoolserver log)
endif()


add_library(libPCDebugS STATIC ${TCLI_TEST_SERVER_LIB_SRC})
set_target_properties(libPCDebugS PROPERTIES OUTPUT_NAME "PCDebug")
#---------------------------------------------------


