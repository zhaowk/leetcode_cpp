cmake_minimum_required(VERSION 3.2)
project(_02xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(_0233 0233_test.cc 0233.h)
add_test(NAME _0233 COMMAND _0233)
