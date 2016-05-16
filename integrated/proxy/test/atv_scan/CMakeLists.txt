aux_source_directory(. BIN_SBINDER_TEST)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS})

add_executable(atv_scan_bin ${BIN_SBINDER_TEST} )
set_target_properties(atv_scan_bin  PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT" )
target_link_libraries(atv_scan_bin ${PROXY_LIB_NAME}S)

