cmake_minimum_required(VERSION 3.18.2)

SET(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED on)

SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wpedantic")

set(TARGET worker)

project(${TARGET} LANGUAGES CXX)

add_executable(${TARGET} main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(./src ./resources)

add_subdirectory(./src)

target_link_libraries(${TARGET} libsrc)

# target_include_directories(${PROJECT_NAME} PUBLIC
# 							"${PROJECT_BINARY_DIR}"
# 							"${PROJECT_SOURCE_DIR}/src")