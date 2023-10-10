cmake_minimum_required(VERSION 3.10)
project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
