cmake_minimum_required (VERSION 3.15)
project (cpp_learning)

set(SRC src)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/gcc)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g3")

add_subdirectory(${SRC})
