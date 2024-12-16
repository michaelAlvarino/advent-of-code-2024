cmake_minimum_required(VERSION 3.10.0)
project(advent-of-code VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(extract lib/extract.cpp)
add_executable(day-2 day2/main.cpp)
add_executable(day-3 day3/main.cpp)
add_executable(day-4 day4/main.cpp)

add_library(list ds/list.cpp)
add_executable(list_test ds/list_test.cpp)
add_library(heap ds/heap.cpp)
add_executable(heap_test ds/heap_test.cpp)
target_link_libraries(heap_test heap)
target_link_libraries(list_test list)

include(CTest)
enable_testing()

add_test(NAME ListTest COMMAND list_test)
add_test(NAME HeapTest COMMAND heap_test)
