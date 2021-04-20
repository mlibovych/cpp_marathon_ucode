cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_EXTENSIONS OFF)

project(libsrc)

set(TARGET libsrc)

set(SOURCES ThreadPool.cpp)

include_directories(.)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

add_library(${TARGET} ${SOURCES})