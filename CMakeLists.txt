# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(Camera_calibration_Project)


find_package(OpenCV REQUIRED)
set (CMAKE_CXX_STANDARD 11)


message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

if(CMAKE_VERSION VERSION_LESS "2.8.11")
  # Add OpenCV headers location to your include paths
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

# Declare the executable target built from your sources
add_executable(run main.cpp)

# Link your application with OpenCV libraries
target_link_libraries(run ${OpenCV_LIBS})
