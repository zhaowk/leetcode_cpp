cmake_minimum_required(VERSION 3.2)
project(_19xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(1913 1913_test.cc 1913.h)
add_test(NAME 1913 COMMAND 1913)
