INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/core/sbinder/kmodule)

#SERVER for sbinderLogTestServer
set(SAMPLE_SBINDERLOGTEST_SRC_SERVICE
   ${CMAKE_CURRENT_SOURCE_DIR}/sbinderLogTestServer.cpp
)

ADD_EXECUTABLE(sbinderLogTestService ${SAMPLE_SBINDERLOGTEST_SRC_SERVICE})
set_target_properties(sbinderLogTestService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(sbinderLogTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderLogTestService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderLogTestService ${SBINDER_PLTFORM_LINK_LIBRARIES})

#CLIENT for sbinderLogTestClient
set(SAMPLE_BUFFERTEST_SRC_CLIENT
   ${CMAKE_CURRENT_SOURCE_DIR}/sbinderLogTestClient.cpp
)

ADD_EXECUTABLE(sbinderLogTestClient ${SAMPLE_BUFFERTEST_SRC_CLIENT})
set_target_properties(sbinderLogTestClient PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(sbinderLogTestClient libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderLogTestClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(sbinderLogTestClient ${SBINDER_PLTFORM_LINK_LIBRARIES})