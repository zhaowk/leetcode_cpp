cmake_minimum_required(VERSION 3.2)
project(_24xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(_1913 1913_test.cc 1913.h)
add_test(NAME _1913 COMMAND _1913)
