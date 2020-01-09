cmake_minimum_required(VERSION 3.15)
project(hello)

set(CMAKE_CXX_STANDARD 14)

include_directories(/home/hwj/Downloads/eigen3)
add_executable(hello main.cpp Stack.h Stack.cpp)


