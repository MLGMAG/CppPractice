include_directories(${LOCAL_DIR_PATH}/marketCalc)
add_library(
        marketCalcLib
        ${LOCAL_DIR_PATH}/marketCalc/marketCalc.cpp
        ${LOCAL_DIR_PATH}/marketCalc/marketCalc.h
)

add_executable(marketCalcTest marketCalcTest.cpp)
target_link_libraries(marketCalcTest PRIVATE marketCalcLib gtest gtest_main)
