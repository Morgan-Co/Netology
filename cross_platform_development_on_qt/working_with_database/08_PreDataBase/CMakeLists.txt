cmake_minimum_required(VERSION 3.5)

project(08_PreDataBase VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent Sql PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        database.h
        database.cpp
        dbdata.h
        dbdata.cpp
        dbdata.ui
)

add_executable(08_PreDataBase
        ${PROJECT_SOURCES}
)

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PG_Libs)

# Без 'lib' в начале
target_link_libraries(08_PreDataBase PRIVATE Qt6::Widgets
                                             crypto-3-x64
                                             iconv-2
                                             intl-9
                                             pq
                                             ssl-3-x64
                                             Qt${QT_VERSION_MAJOR}::Concurrent
                                             Qt${QT_VERSION_MAJOR}::Sql
                                             Qt${QT_VERSION_MAJOR}::PrintSupport)

# Копируем .dll после сборки
add_custom_command(TARGET 08_PreDataBase POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/PG_Libs/bin"
        "$<TARGET_FILE_DIR:08_PreDataBase>")
