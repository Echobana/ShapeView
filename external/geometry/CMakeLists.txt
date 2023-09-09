cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 14)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

project(geometry)

add_library(geometry geometry.cpp)
add_library(erdeni::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if (LINUX)
    target_link_libraries(m)
endif ()
