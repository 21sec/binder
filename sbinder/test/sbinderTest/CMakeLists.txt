INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/core/sbinder/kmodule)


#SERVER for socketTestServer
set(SAMPLE_SOCKETTEST_SRC_SERVICE
   ${CMAKE_CURRENT_SOURCE_DIR}/sbinderTestServer.cpp
)

ADD_EXECUTABLE(sbinderTestService ${SAMPLE_SOCKETTEST_SRC_SERVICE})
set_target_properties(sbinderTestService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(sbinderTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderTestService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderTestService ${SBINDER_PLTFORM_LINK_LIBRARIES})

#-----------------------------------------

#CLIENT for socketTestClient
set(SAMPLE_BUFFERTEST_SRC_CLIENT
   ${CMAKE_CURRENT_SOURCE_DIR}/sbinderTestClient.cpp
)

ADD_EXECUTABLE(sbinderTestClient ${SAMPLE_BUFFERTEST_SRC_CLIENT})
set_target_properties(sbinderTestClient PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(sbinderTestClient libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderTestClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderTestClient ${SBINDER_PLTFORM_LINK_LIBRARIES})