cmake_minimum_required(VERSION 3.2)
project(_16xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(1646 1646_test.cc 1646.h)
add_test(NAME 1646 COMMAND 1646)
