cmake_minimum_required(VERSION 3.22)
project(Vector)
add_executable(Vector main.cpp)
set(CMAKE_CXX_STANDARD 17)

#add_library(Vector Vector.cpp)

project(test)
add_executable(test test/test.cpp)
target_link_libraries(test Unity)