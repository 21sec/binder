INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#SERVER for socketTestServer
set(SAMPLE_SOCKETTEST_SRC_SERVICE
   ${CMAKE_CURRENT_SOURCE_DIR}/socketServer.c
)

ADD_EXECUTABLE(socketTestService ${SAMPLE_SOCKETTEST_SRC_SERVICE})
set_target_properties(socketTestService PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(socketTestService libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(socketTestService libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(socketTestService ${SBINDER_PLTFORM_LINK_LIBRARIES})


#CLIENT for socketTestClient
set(SAMPLE_BUFFERTEST_SRC_CLIENT
   ${CMAKE_CURRENT_SOURCE_DIR}/socketClient.c
)

ADD_EXECUTABLE(socketTestClient ${SAMPLE_BUFFERTEST_SRC_CLIENT})
set_target_properties(socketTestClient PROPERTIES COMPILE_DEFINITIONS "BINDER_SERVICE")
ADD_DEPENDENCIES(socketTestClient libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(socketTestClient libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(socketTestClient ${SBINDER_PLTFORM_LINK_LIBRARIES})