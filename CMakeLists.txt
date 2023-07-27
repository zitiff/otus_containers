cmake_minimum_required(VERSION 3.1)

project(homework6)

add_executable(homework6 "sequential.cpp" 
    "linkedlist.cpp" 
    "main.cpp"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(homework6 PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(homework6 PRIVATE
        /EHsc
        /W4
    )
endif()
