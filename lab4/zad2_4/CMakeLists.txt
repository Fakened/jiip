cmake_minimum_required(VERSION 3.16)

project(e1NoCopyingConstructor)
include_directories(include)

add_executable(e1NoCopyingConstructor src/main.cpp src/Figure.cpp src/Circle.cpp src/Square.cpp src/Trapeze.cpp)