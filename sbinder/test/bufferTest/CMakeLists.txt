INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#SERVER for bufferTest
set(SAMPLE_BUFFERTEST_SRC_SERVICE
   ${CMAKE_CURRENT_SOURCE_DIR}/matrix_ringbuf.c
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_buffer_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
)

ADD_EXECUTABLE(bufferTestService ${SAMPLE_BUFFERTEST_SRC_SERVICE})
set_target_properties(bufferTestService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(bufferTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(bufferTestService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(bufferTestService ${SBINDER_PLTFORM_LINK_LIBRARIES})


#CLIENT for bufferTest
set(SAMPLE_BUFFERTEST_SRC_CLIENT
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_buffer_module.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/remote_test_main.c
)

ADD_EXECUTABLE(bufferTestClient ${SAMPLE_BUFFERTEST_SRC_CLIENT})
set_target_properties(bufferTestClient PROPERTIES COMPILE_DEFINITIONS "BINDER_CLIENT")
ADD_DEPENDENCIES(bufferTestClient libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(bufferTestClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(bufferTestClient ${SBINDER_PLTFORM_LINK_LIBRARIES})
