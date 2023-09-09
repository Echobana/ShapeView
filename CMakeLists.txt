cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 14)

project(ShapeViewer)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/yaml-cpp)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/geometry)

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
	       		${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME} yaml-cpp erdeni::geometry)

