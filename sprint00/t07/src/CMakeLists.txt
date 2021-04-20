cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(t_07_lib)

set(TARGET libInventoryManager)

include_directories(.)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

add_library(${TARGET} libInventoryManager.cpp)