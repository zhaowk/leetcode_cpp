cmake_minimum_required(VERSION 3.2)
project(others)

enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -std=c++17")

add_executable(lru_test lru_test.cc lru.h)
add_test(NAME lru_test COMMAND lru_test)

find_package(OpenCL REQUIRED)
add_executable(cl_test cl_test.cc cl_test.h)
target_include_directories(cl_test PRIVATE ${OpenCL_INCLUDE_DIRS})
target_link_libraries(cl_test PRIVATE ${OpenCL_LIBRARIES})
add_test(NAME cl_test COMMAND cl_test)
