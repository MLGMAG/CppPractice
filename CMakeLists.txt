cmake_minimum_required(VERSION 3.19)

project(CppPractice)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)
