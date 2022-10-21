cmake_minimum_required(VERSION 3.23)
project(tep)

set(CMAKE_CXX_STANDARD 98)

include_directories(list1)
include_directories(list1/zad1)
include_directories(list1/zad2)
include_directories(list1/zad3)
include_directories(list1/zad4)

add_executable(tep
        list1/zad1/zad1.cpp
        list1/zad1/zad1.h
        list1/zad2/zad2.cpp
        list1/zad2/zad2.h
        list1/zad3/zad3.cpp
        list1/zad3/zad3.h
        list1/utils.cpp
        list1/utils.h
        list1/zad4/zad4.h
        list1/zad4/zad4.cpp
        )
