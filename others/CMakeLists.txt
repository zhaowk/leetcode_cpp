cmake_minimum_required(VERSION 3.2)
project(others)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(lru_test lru_test.cc lru.h)
add_test(NAME lru_test COMMAND lru_test)
