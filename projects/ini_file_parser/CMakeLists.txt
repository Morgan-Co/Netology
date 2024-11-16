cmake_minimum_required(VERSION 3.10)
project(ini_file_parser)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(catch2)
add_executable(${PROJECT_NAME} main.cpp "ini_parser/ini_parser.h" "ini_parser/ini_parser.cpp" "tests/main_test.cpp" "tests/ini_parser_test.cpp")
target_link_directories(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)