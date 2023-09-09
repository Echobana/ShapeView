cmake_minimum_required(VERSION 3.25)
project(geometry)

set(CMAKE_CXX_STANDARD 14)

add_library(geometry geometry.cpp)
add_library(erdeni::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
