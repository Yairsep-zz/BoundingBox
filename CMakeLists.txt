cmake_minimum_required(VERSION 3.15)
project(boundingBox)

set(CMAKE_CXX_STANDARD 14)

add_executable(boundingBox main.cpp src/main.cpp src/BoundingBox.cpp include/BoundingBox.h)