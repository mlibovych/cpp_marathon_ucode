cmake_minimum_required(VERSION 3.15)

project(t_00)

set(TARGET simpleSort)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

include_directories(. ./src)

add_subdirectory(./src/)

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} libsort)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)