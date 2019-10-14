cmake_minimum_required(VERSION 3.14)
project(Fractions)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Fractions src/main.cpp src/Fractions.cpp)