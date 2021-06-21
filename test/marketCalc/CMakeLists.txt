include_directories(${SOURCE_PATH}/marketCalc)
add_library(
        marketCalcLib
        ${SOURCE_PATH}/marketCalc/marketCalc.cpp
        ${SOURCE_PATH}/marketCalc/marketCalc.h
)

add_executable(marketCalcTest marketCalcTest.cpp)
target_link_libraries(marketCalcTest PRIVATE marketCalcLib gtest gtest_main)
