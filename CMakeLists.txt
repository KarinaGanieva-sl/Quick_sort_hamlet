cmake_minimum_required(VERSION 3.17)
project(quick_sort_hamlet)

set(CMAKE_CXX_STANDARD 14)

add_executable(quick_sort_hamlet main.cpp quick_sort.h quick_sort.cpp tests.cpp tests.h)