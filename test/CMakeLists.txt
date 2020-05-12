cmake_minimum_required(VERSION 3.2)

project(test VERSION 0.0.1)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/../googletest" 
    "googletest"
)

# Test target
add_executable(test test.cpp)

# Add src to the include directories for the test target
target_include_directories(
    test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../src"
    "${CMAKE_CURRENT_SOURCE_DIR}/../lib"
)

# Link test target against gtest libraries
target_link_libraries(
    test PRIVATE
    lib
    gtest gtest_main
)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(test PRIVATE /W4)
else ()
    target_compile_options(
        test PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()