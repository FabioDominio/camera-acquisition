# The name of my project is "CameraAcquisition". CMakeLists files in this project can 
# refer to the root source directory of the project as ${CAMERAACQUISITION_SOURCE_DIR} and 
# to the root binary directory of the project as ${CAMERAACQUISITION_BINARY_DIR}. 
cmake_minimum_required (VERSION 3.2 FATAL_ERROR) 

# The version number.
# must go before the project command
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(DEFINED CMAKE_BUILD_TYPE)
  set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES} )
endif()

set(CMAKE_BUILD_TYPE Release)
if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Set default install path
set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE )
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
set (OpenCV_LIB_COMPONENTS core highgui imgproc)

project ("CameraAcquisition")

find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(CameraAcquisition src/main.cpp) 
target_link_libraries(CameraAcquisition ${OpenCV_LIBS})

install(TARGETS CameraAcquisition DESTINATION bin)

#install(FILES ${OpenCV_LIB_DIR_OPT}/../bin/opencv_world310.dll DESTINATION bin CONFIGURATIONS Release)
#install(FILES ${OpenCV_LIB_DIR_OPT}/../bin/opencv_world310d.dll DESTINATION bin CONFIGURATIONS Debug)
