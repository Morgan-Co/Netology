cmake_minimum_required(VERSION 3.22.0)
project(task_5)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(ShapesDynamicLib SHARED Shapes.h Shapes.cpp)
add_executable(Task5 task_5.cpp)
target_link_libraries(Task5 ShapesDynamicLib)
