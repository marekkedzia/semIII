cmake_minimum_required(VERSION 3.23)
project(generic_algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(generic_algorithm
        main.cpp
        algorithm/GeneticAlgorithm.cpp
        algorithm/GeneticAlgorithm.h
        algorithm/Individual.cpp
        algorithm/Individual.h
        utils.h
        utils.cpp
        problems/CapacityProblem.cpp
        problems/CapacityProblem.h
        problems/KnapsackProblem.cpp
        problems/KnapsackProblem.h)
