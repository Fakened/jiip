cmake_minimum_required(VERSION 3.15)

project(matrixTest)

add_library(matrix_lib src/matrixLib.h src/matrixLib.cpp)

add_executable(matrix_main src/main.cpp)

target_link_libraries(matrix_main matrix_lib)