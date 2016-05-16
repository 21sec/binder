#开源项目的警告不做处理,以方便同步
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wno-unused-but-set-variable -Wno-maybe-uninitialized  -Wno-sign-compare -Wno-unused-function")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wno-unused-but-set-variable -Wno-maybe-uninitialized  -Wno-sign-compare -Wno-unused-function")

ADD_SUBDIRECTORY(servicemanager) 
ADD_SUBDIRECTORY(sbinder) 
#ADD_SUBDIRECTORY(test)
