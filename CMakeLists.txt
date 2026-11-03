cmake_minimum_required(VERSION 3.9)
project(raytracer_test)

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options($<$<CONFIG:Release>:-Ofast>)
endif()

find_package(SDL2 REQUIRED CONFIG)
add_executable(raytracer_test
        CApp.h
        CApp.cpp
        main.cpp
        rayTrace/image.h
        rayTrace/image.cpp
        rayTrace/scene.h
        rayTrace/scene.cpp
        rayTrace/ray.h
        rayTrace/ray.cpp
        rayTrace/camera.h
        rayTrace/camera.cpp
        rayTrace/objects/object_base.h
        rayTrace/objects/object_base.h
        rayTrace/objects/object_base.cpp
        rayTrace/objects/objsphere.h
        rayTrace/objects/objsphere.cpp
        rayTrace/objects/lightbase.h
        rayTrace/objects/lightbase.cpp
        rayTrace/objects/pointlight.h
        rayTrace/objects/pointlight.cpp
)

target_link_libraries(raytracer_test PRIVATE SDL2::SDL2 SDL2::SDL2main)