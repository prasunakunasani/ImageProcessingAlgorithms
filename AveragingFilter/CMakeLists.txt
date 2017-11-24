cmake_minimum_required(VERSION 3.8)
project(AveragingFilter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        avgfilter.cpp
        testpattern.raw
        testpatternnew.png
        testpatternnew.raw
        testpatternnew2.png
        testpatternnew2.raw)

add_executable(AveragingFilter ${SOURCE_FILES})