include_directories(${SOURCE_PATH}/equation)
add_library(
        equationLib STATIC
        ${SOURCE_PATH}/equation/equation.cpp
        ${SOURCE_PATH}/equation/equation.h
)

add_executable(equationTest equationTest.cpp)
target_link_libraries(equationTest PRIVATE equationLib gtest gtest_main)
