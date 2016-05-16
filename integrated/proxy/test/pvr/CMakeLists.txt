aux_source_directory(. BIN_SBINDER_TEST)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

add_executable(pvr_client ${BIN_SBINDER_TEST} )
set_target_properties(pvr_client  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(pvr_client ${PROXY_LIB_NAME}S)

