cmake_minimum_required(VERSION 3.10)
project(some_tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(catch2)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)