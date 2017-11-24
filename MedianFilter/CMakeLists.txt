cmake_minimum_required(VERSION 3.8)
project(MedianFilter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        circuit.raw
        circuitnew.png
        circuitnew.raw
        medianfilter.cpp)

add_executable(MedianFilter ${SOURCE_FILES})