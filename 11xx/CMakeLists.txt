cmake_minimum_required(VERSION 3.25)
project(_11xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(_1147 1147_test.cc 1147.h)
add_test(NAME _1147 COMMAND _1147)
