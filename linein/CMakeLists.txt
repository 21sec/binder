##################################################
#                                                #
# CMakeLists for F1 driver_core src linein.            #
#                                                #
# Author : linshunda, linshunda@tcl.com          #
##################################################
set(PROJECT_SOURCE_DIR_FPI_CORE_SRC_LINEIN ${PROJECT_SOURCE_DIR_FPI_CORE_SRC}/linein )
aux_source_directory(linein SRC_FPI_CORE_SRC_LINEIN ) 

if(OUT_SO_LIB)
	add_library(libFpiLinein SHARED ${SRC_FPI_CORE_SRC_LINEIN})
	set_target_properties(libFpiLinein PROPERTIES OUTPUT_NAME "FpiLinein")
endif(OUT_SO_LIB)	

if(OUT_STATIC_LIB)
	add_library(libFpiLineinS STATIC ${SRC_FPI_CORE_SRC_LINEIN})
	set_target_properties(libFpiLineinS PROPERTIES OUTPUT_NAME "FpiLinein")
endif(OUT_STATIC_LIB)
