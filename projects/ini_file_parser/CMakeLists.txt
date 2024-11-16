cmake_minimum_required(VERSION 3.10)
project(ini_file_parser)

add_executable(${PROJECT_NAME} main.cpp "ini_parser/ini_parser.h" "ini_parser/ini_parser.cpp")