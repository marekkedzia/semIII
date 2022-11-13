cmake_minimum_required(VERSION 3.23)
project(tep)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)
include_directories(zad1)
include_directories(zad2)
include_directories(zad3)
include_directories(zad4)

add_executable(tep
        zad1/zad1.cpp
        zad1/zad1.h
        zad2/zad2.cpp
        zad2/zad2.h
        zad3/zad3.cpp
        zad3/zad3.h
        utils.cpp
        utils.h
        zad4/zad4.h
        zad4/zad4.cpp
        )
