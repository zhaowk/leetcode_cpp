cmake_minimum_required(VERSION 3.2)
project(_20xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(2012 2012_test.cc 2012.h)
add_test(NAME 2012 COMMAND 2012)
