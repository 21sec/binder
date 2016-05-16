include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(TCLI_TEST_SERVER_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/test_tcli.c
)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

add_executable(tclicmdtool ${TCLI_TEST_SERVER_SRC} )
set_target_properties(tclicmdtool  PROPERTIES OUTPUT_NAME "tcli" )
target_link_libraries(tclicmdtool ${PROXY_LIB_NAME}S)

#---------------------------------------------------

set(TCLI_TEST_CLIENT_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/test_tcli_cc.c
)

add_executable(tclicmdtoolc ${TCLI_TEST_CLIENT_SRC} )
set_target_properties(tclicmdtoolc  PROPERTIES OUTPUT_NAME "tclic" )
target_link_libraries(tclicmdtoolc ${PROXY_LIB_NAME}S)


