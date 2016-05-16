include_directories(${PROJECT_SOURCE_DIR}/core/sbinder/kmodule)
set(SERVICE_MANAGER_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/src/service_manager.c
   ${CMAKE_CURRENT_SOURCE_DIR}/src/binder.c
)

#ADD_EXECUTABLE(servicemanager ${SERVICE_MANAGER_SRC})
#TARGET_LINK_LIBRARIES(servicemanager tcli)
#SET_TARGET_PROPERTIES(servicemanager PROPERTIES COMPILE_DEFINITIONS "SM_MAIN")

ADD_LIBRARY(libbinderservicemanager STATIC ${SERVICE_MANAGER_SRC} )
TARGET_LINK_LIBRARIES(libbinderservicemanager tcliS)
SET_TARGET_PROPERTIES(libbinderservicemanager PROPERTIES COMPILE_DEFINITIONS "SM_LIB")
SET_TARGET_PROPERTIES(libbinderservicemanager PROPERTIES OUTPUT_NAME "binderservicemanager") 
