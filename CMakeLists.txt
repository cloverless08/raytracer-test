cmake_minimum_required(VERSION 4.4)
project(raytracer_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(raytracer_test
        CApp.h
        CApp.cpp
        main.cpp)
