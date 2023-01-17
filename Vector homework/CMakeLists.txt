cmake_minimum_required(VERSION 3.15)

project(vector)

set(CXX_STANDARD 17)

enable_testing()

add_library(vector_lib src/MVector.h src/MVector.cpp)

add_executable(vector_main src/main.cpp)

target_link_libraries(vector_main vector_lib)