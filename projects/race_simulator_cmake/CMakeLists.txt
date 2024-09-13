cmake_minimum_required(VERSION 3.22.0)
project(RaceSimulator_CMake)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(RaceLib SHARED)

add_subdirectory(Races)
add_subdirectory(Transports)
add_subdirectory(Enums)
add_subdirectory(Functions)


add_executable(Main main.cpp)
target_link_libraries(Main RaceLib)