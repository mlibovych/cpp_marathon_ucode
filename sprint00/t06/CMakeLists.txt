cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

project(t_06)

set(TARGET meadSong)

set(SOURCES main.cpp meadSong.cpp)

include_directories(.)

add_executable(${TARGET} ${SOURCES})

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)
