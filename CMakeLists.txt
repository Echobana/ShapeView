cmake_minimum_required(VERSION 3.20.1)

set(CMAKE_CXX_STANDARD 14)

project(GraphEditor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/eigen-3.3.7)

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
	       ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
#target_link_libraries(${PROJECT_NAME} eigen)
