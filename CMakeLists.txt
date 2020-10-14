cmake_minimum_required(VERSION 3.17)
project(split)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(split
        DataSequence.cpp
        DataSequence.h
        Histogram.cpp
        Histogram.h
        input.txt
        main.cpp)
