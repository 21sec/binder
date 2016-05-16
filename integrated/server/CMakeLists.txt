##################################################
#                                                #
# CMakeLists for F1 driver_bsp.                 #
#                                                #
# Author : linshunda, linshunda@tcl.com          #
##################################################
set(PROJECT_SOURCE_DIR_FPI_ROUTE ${PROJECT_SOURCE_DIR_ROOT}/tvh )

include_directories(${PROJECT_SOURCE_DIR_FPI_ROUTE}/include)	
####################################################################################################

#option(COMPILE_ROUTE_SERVICE "ON:compile fpi_route service application;  OFF:no compile it" ON )
#if(COMPILE_ROUTE_SERVICE)
	ADD_SUBDIRECTORY(service)
#endif(COMPILE_ROUTE_SERVICE)



