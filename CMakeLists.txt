cmake_minimum_required(VERSION 3.15)
project(dataStructure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dataStructure
    Compress.cpp
    Compress.h
    Extract.cpp
    Extract.h
    test.cpp
        BitBuffer.h
        BitBuffer.cpp)
