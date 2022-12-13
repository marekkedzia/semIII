cmake_minimum_required(VERSION 3.23)
project(list4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(list4
        generic.cpp
        generic.h)
