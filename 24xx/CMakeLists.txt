cmake_minimum_required(VERSION 3.2)
project(_24xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(2404 2404_test.cc 2404.h)
add_test(NAME 2404 COMMAND 2404)

add_executable(2409 2409_test.cc 2409.h)
add_test(NAME 2409 COMMAND 2409)
