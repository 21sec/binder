INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})


#generate sample_module and remote code
SET(STRUCTTEST_MODULE_CODE_LIST
    ${CMAKE_CURRENT_BINARY_DIR}/remote_struct_module.h
    ${CMAKE_CURRENT_BINARY_DIR}/remote_struct_module.cpp
)
ADD_CUSTOM_COMMAND(OUTPUT ${STRUCTTEST_MODULE_CODE_LIST} 
    COMMAND echo "Generating struct_module code file..."
    COMMAND python ${PROJECT_SOURCE_DIR}/core/sbinder/tools/sidl/sidl.py ${CMAKE_CURRENT_SOURCE_DIR}/remote_struct_module.sidl
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/remote_struct_module.sidl
    DEPENDS ${Sidl_INCLUDE_FILES}
    )

ADD_CUSTOM_TARGET(STRUCTTESTCode DEPENDS ${STRUCTTEST_MODULE_CODE_LIST})
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -Wno-uninitialized")
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wno-uninitialized")

#Service for STRUCTTEST
set(STRUCTTEST_SRC_SERVICE
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
   ${CMAKE_CURRENT_SOURCE_DIR}/struct_module.c
   ${CMAKE_CURRENT_SOURCE_DIR}/struct_module.h
   ${CMAKE_CURRENT_BINARY_DIR}/remote_struct_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_upstruct_module.cpp
)
ADD_EXECUTABLE(STRUCTTESTService ${STRUCTTEST_SRC_SERVICE})
set_target_properties(STRUCTTESTService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(STRUCTTESTService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(STRUCTTESTService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(STRUCTTESTService ${SBINDER_PLTFORM_LINK_LIBRARIES})

#Client for STRUCTTEST
set(STRUCTTEST_SRC_CLIENT
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
   ${CMAKE_CURRENT_BINARY_DIR}/remote_struct_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_upstruct_module.cpp
)
ADD_EXECUTABLE(STRUCTTESTClient ${STRUCTTEST_SRC_CLIENT})
set_target_properties(STRUCTTESTClient PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT")
ADD_DEPENDENCIES(STRUCTTESTClient libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(STRUCTTESTClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(STRUCTTESTClient ${SBINDER_PLTFORM_LINK_LIBRARIES})
