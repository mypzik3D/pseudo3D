cmake_minimum_required(VERSION 3.27)
project(pseudo3D_by_mypzik3D)

set(CMAKE_CXX_STANDARD 17)

add_executable(pseudo3D_by_mypzik3D main.cpp
        draw.h
        delay.h
        raycasting.h
        data.h)
