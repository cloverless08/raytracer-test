cmake_minimum_required(VERSION 4.4)
project(raytracer_test)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG)
add_executable(raytracer_test
        CApp.h
        CApp.cpp
        main.cpp
        rayTrace/image.h
        rayTrace/image.cpp)

target_link_libraries(raytracer_test PRIVATE SDL2::SDL2 SDL2::SDL2main)