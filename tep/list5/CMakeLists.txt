cmake_minimum_required(VERSION 3.23)
project(list5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(list5
        list5.cpp
        list5.h
        mod.cpp
        mod.h)
