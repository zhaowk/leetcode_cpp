cmake_minimum_required(VERSION 3.25)
project(_10xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(_1041 1041_test.cc 1041.h)
add_test(NAME _1041 COMMAND _1041)
