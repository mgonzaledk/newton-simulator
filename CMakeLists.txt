cmake_minimum_required(VERSION 3.10)
project(newton-simulator CXX)

set(CMAKE_CPP_STANDARD 11)

add_executable(newton-simulator
    Main.cpp
    Vector3.cpp)

target_link_libraries(newton-simulator m)
