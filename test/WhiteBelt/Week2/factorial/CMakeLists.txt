include_directories(${LOCAL_DIR_PATH}/factorial)
add_library(
        factorialLib STATIC
        ${LOCAL_DIR_PATH}/factorial/factorial.cpp
        ${LOCAL_DIR_PATH}/factorial/factorial.h
)

add_executable(factorialTest factorialTest.cpp)
target_link_libraries(factorialTest PRIVATE factorialLib gtest gtest_main)
