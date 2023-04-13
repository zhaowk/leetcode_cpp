cmake_minimum_required(VERSION 3.2)
project(_24xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(_2404 2404_test.cc 2404.h)
add_test(NAME _2404 COMMAND _2404)
