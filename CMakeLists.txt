cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(statistics "sources/serial.cpp" "sources/list.cpp" "main.cpp")
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

