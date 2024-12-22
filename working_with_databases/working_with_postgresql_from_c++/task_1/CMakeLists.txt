cmake_minimum_required(VERSION 3.30)
project(task_1)

set(CMAKE_CXX_STANDARD 17)
find_package(libpqxx REQUIRED)
add_executable(${PROJECT_NAME} main.cpp db_manager/db_manager.h db_manager/db_manager.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE pqxx pq)