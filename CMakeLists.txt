cmake_minimum_required(VERSION 3.10)
project(newton-simulator CXX)

set(CMAKE_CPP_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(newton-simulator
    Main.cpp
    Vector3.cpp
    Particle.cpp
    Universe.cpp
    Graphics.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS})

target_link_libraries(newton-simulator m
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY})
