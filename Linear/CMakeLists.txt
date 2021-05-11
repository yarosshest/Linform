cmake_minimum_required(VERSION 3.19)
project(Linform)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Tests)
add_executable(Linform main.cpp)