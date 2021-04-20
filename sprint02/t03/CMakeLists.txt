cmake_minimum_required(VERSION 3.15)

set(TARGET tesLibrary)

add_executable(${TARGET} main.cpp)

project(t_03)

add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ./${TARGET} ..)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

include_directories(. ./src)

add_compile_options(
        -std=c++17
        -Wall
        -Wextra
        -Werror
        -Wpedantic
)

add_subdirectory(./src/)

target_link_libraries(${TARGET} libsrc)