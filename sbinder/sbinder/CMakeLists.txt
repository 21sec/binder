include_directories(${PROJECT_SOURCE_DIR}/core/sbinder/kmodule)

#binder
set(LIB_Binder_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/binder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/BpBinder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/IPCThreadState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/IServiceManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/Parcel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/ProcessState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/IInterface.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/Static.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/TextOutput.cpp #ProcessState.cpp used it a lot
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/BufferedTextOutput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/binder/Debug.cpp
)

#sbinder, code added in this project
set(LIB_SBINDER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/sbinder/RemoteCallbackList.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sbinder/ICallbackList.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sbinder/sbinderServ.cpp
)

add_library(StandaloneBinder SHARED
    ${LIB_Binder_SRC}
    ${LIB_SBINDER_SRC}
)
add_dependencies(StandaloneBinder AndroidToolsets)
target_link_libraries(StandaloneBinder AndroidToolsets)

add_library(StandaloneBinderS STATIC 
    ${LIB_Binder_SRC}
    ${LIB_SBINDER_SRC}
)
add_dependencies(StandaloneBinderS AndroidToolsetsS)
target_link_libraries(StandaloneBinderS AndroidToolsetsS)
