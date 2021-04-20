cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")

set(CMAKE_CXX_EXTENSIONS OFF)

set(TARGET werewolf)

project(${TARGET} LANGUAGES CXX)

add_subdirectory(./app)