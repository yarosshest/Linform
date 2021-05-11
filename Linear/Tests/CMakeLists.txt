cmake_minimum_required(VERSION 3.19)
project(Tests)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Tests LinearTests.cpp DynamicArrayTests.cpp LinkedListTests.cpp)
target_link_libraries(Tests gtest gtest_main)