aux_source_directory(. BIN_SBINDER_TEST)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

add_executable(tcli_client_test ${BIN_SBINDER_TEST} )
set_target_properties(tcli_client_test  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(tcli_client_test ${API_LIB_NAME})

