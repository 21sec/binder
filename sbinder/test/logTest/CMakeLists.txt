INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

set(SAMPLE_LOG_TEST
   ${CMAKE_CURRENT_SOURCE_DIR}/logtest.c
)

ADD_EXECUTABLE(logtest ${SAMPLE_LOG_TEST})
ADD_DEPENDENCIES(logtest libbinderservicemanager.a libStandaloneBinderS.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(logtest libStandaloneBinderS.a libbinderservicemanager.a libAndroidToolsetsS.a)
TARGET_LINK_LIBRARIES(logtest ${SBINDER_PLTFORM_LINK_LIBRARIES})

