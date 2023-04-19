cmake_minimum_required(VERSION 3.2)
project(_10xx)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(1023 1023_test.cc 1023.h)
add_test(NAME 1023 COMMAND 1023)

add_executable(1026 1026_test.cc 1026.h ../tree_node.h)
add_test(NAME 1026 COMMAND 1026)

add_executable(1041 1041_test.cc 1041.h)
add_test(NAME 1041 COMMAND 1041)

add_executable(1042 1042_test.cc 1042.h)
add_test(NAME 1042 COMMAND 1042)
