cmake_minimum_required(VERSION 3.25)
project(_11xx)

enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g -std=c++20")

add_executable(1147 1147_test.cc 1147.h)
add_test(NAME 1147 COMMAND 1147)

add_executable(1172 1172_test.cc 1172.h)
add_test(NAME 1172 COMMAND 1172)
