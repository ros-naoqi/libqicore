## Copyright (c) 2012 Aldebaran Robotics. All rights reserved.

cmake_minimum_required(VERSION 3.5)
project(naoqi_libqicore)
find_package(ament_cmake REQUIRED)
find_package(naoqi_libqi REQUIRED)
find_package(Boost QUIET COMPONENTS chrono filesystem program_options regex system thread random)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -O3 -fPIC" )
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()
add_definitions(-DLIBQI_VERSION=${naoqi_libqi_VERSION_MAJOR}${naoqi_libqi_VERSION_MINOR})

# Tests
enable_testing()

add_subdirectory("libqicore")

# Install
install(FILES package.xml DESTINATION share/${PROJECT_NAME})

ament_export_libraries(qicore)
ament_export_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libqicore/)
ament_export_dependencies(Boost)
ament_package()