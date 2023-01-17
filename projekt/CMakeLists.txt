cmake_minimum_required(VERSION 3.24)
project(projektcmd)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(projekt src/main.cpp src/vehicle.cpp include/vehicle.h src/car.cpp include/car.h src/bike.cpp include/bike.h src/scooter.cpp include/scooter.h src/motorbike.cpp include/motorbike.h src/person.cpp include/person.h src/function.cpp include/function.h)
