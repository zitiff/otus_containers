cmake_minimum_required(VERSION 3.1)

project(homework6)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    #By default, new Visual Studio projects link the C runtimes dynamically
    #but GoogleTest links them statically. This will generate an error
    #Enabling this option will make gtest link the runtimes dynamically too
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory (
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
    "googletest"
)

add_executable(
    homework6 
    "sequential.cpp" 
    "linkedlist.cpp" 
    "main.cpp"
)

add_executable(
    containers_tests 
    "test/sequential_tests.cpp" 
    "test/linkedlist_tests.cpp"
)

# Add src to the include directories for the test target
target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    containers_tests PRIVATE 
    gtest gtest_main
)


set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        containers_tests PRIVATE
        /W4
    )
   
else ()
    target_compile_options(
        containers_tests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

