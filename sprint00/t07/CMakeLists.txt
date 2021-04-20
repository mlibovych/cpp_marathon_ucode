cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

project(t_07)

set(TARGET inventory)

set(SOURCES main.cpp)

include_directories(. ./src)

add_subdirectory(./src/)

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} libInventoryManager)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)
