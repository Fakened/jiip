cmake_minimum_required(VERSION 3.16)

project(tasks)
include_directories(include)

add_executable(tasks src/main.cpp src/TaskList.cpp src/TaskNote.cpp)
