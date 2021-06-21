include_directories(${LOCAL_DIR_PATH}/equation)
add_library(
        equationLib STATIC
        ${LOCAL_DIR_PATH}/equation/equation.cpp
        ${LOCAL_DIR_PATH}/equation/equation.h
)

add_executable(equationTest equationTest.cpp)
target_link_libraries(equationTest PRIVATE equationLib gtest gtest_main)
