cmake_minimum_required(VERSION 3.14)
project(labwork8)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(labwork8
        src/main.cpp include/Station.h)
