cmake_minimum_required(VERSION 3.27)
project(TrainStringMatching)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TrainStringMatching
        main.cpp
        smatching.h
        suffixtree.h)
