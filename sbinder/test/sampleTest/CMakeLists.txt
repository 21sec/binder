include_directories(${CMAKE_CURRENT_BINARY_DIR})


#generate sample_module and remote code
set(SAMPLETEST_MODULE_CODE_LIST
    ${CMAKE_CURRENT_BINARY_DIR}/sample_module.c
    ${CMAKE_CURRENT_BINARY_DIR}/sample_module.h
    ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.sidl
    ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.h
    ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.cpp
)
add_custom_command(OUTPUT ${SAMPLETEST_MODULE_CODE_LIST} 
    COMMAND echo "Generating sample_module code file..."
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/genSampleApis.py
    COMMAND python ${PROJECT_SOURCE_DIR}/core/sbinder/tools/sidl/sidl.py ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.sidl
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/genSampleApis.py
    DEPENDS ${Sidl_INCLUDE_FILES}
    )

add_custom_target(sampleTestCode DEPENDS ${SAMPLETEST_MODULE_CODE_LIST})
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -Wno-uninitialized")
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wno-uninitialized")

#Service for sampleTest
set(SAMPLETEST_SRC_SERVICE
   ${CMAKE_CURRENT_BINARY_DIR}/sample_module.c
   ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
)
add_executable(sampleTestService ${SAMPLETEST_SRC_SERVICE})
set_target_properties(sampleTestService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
add_dependencies(sampleTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
target_link_libraries(sampleTestService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
target_link_libraries(sampleTestService ${SBINDER_PLTFORM_LINK_LIBRARIES})

#--------------------------------------------

#Client for sampleTest
set(SAMPLETEST_SRC_CLIENT
   ${CMAKE_CURRENT_BINARY_DIR}/remote_sample_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
)
add_executable(sampleTestClient ${SAMPLETEST_SRC_CLIENT})
set_target_properties(sampleTestClient PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT")
add_dependencies(sampleTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
target_link_libraries(sampleTestClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
target_link_libraries(sampleTestClient ${SBINDER_PLTFORM_LINK_LIBRARIES})
