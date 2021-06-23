set(LOCAL_DIR_PATH ${SOURCE_PATH}/WhiteBelt/Week1)


# Basic sum tests
include_directories(${LOCAL_DIR_PATH}/basicSum)
add_library(
        basicSumLib STATIC
        ${LOCAL_DIR_PATH}/basicSum/basicSum.cpp
        ${LOCAL_DIR_PATH}/basicSum/basicSum.h
)

add_executable(basicSumTest basicSum/basicSumTest.cpp)
target_link_libraries(basicSumTest PRIVATE basicSumLib gtest gtest_main)


# Min string
include_directories(${LOCAL_DIR_PATH}/minString)
add_library(
        minStringLib STATIC
        ${LOCAL_DIR_PATH}/minString/minString.cpp
        ${LOCAL_DIR_PATH}/minString/minString.h
)
add_executable(minStringTest minString/minStringTest.cpp)
target_link_libraries(minStringTest PRIVATE minStringLib gtest gtest_main)


# Equation
include_directories(${LOCAL_DIR_PATH}/equation)
add_library(
        equationLib STATIC
        ${LOCAL_DIR_PATH}/equation/equation.cpp
        ${LOCAL_DIR_PATH}/equation/equation.h
)
add_executable(equationTest equation/equationTest.cpp)
target_link_libraries(equationTest PRIVATE equationLib gtest gtest_main)


# Decimal division
include_directories(${LOCAL_DIR_PATH}/decimalDivision)
add_library(
        decimalDivisionLib STATIC
        ${LOCAL_DIR_PATH}/decimalDivision/decimalDivision.cpp
        ${LOCAL_DIR_PATH}/decimalDivision/decimalDivision.h
)
add_executable(decimalDivisionTest decimalDivision/decimalDivisionTest.cpp)
target_link_libraries(decimalDivisionTest PRIVATE decimalDivisionLib gtest gtest_main)


# Market calc
include_directories(${LOCAL_DIR_PATH}/marketCalc)
add_library(
        marketCalcLib
        ${LOCAL_DIR_PATH}/marketCalc/marketCalc.cpp
        ${LOCAL_DIR_PATH}/marketCalc/marketCalc.h
)
add_executable(marketCalcTest marketCalc/marketCalcTest.cpp)
target_link_libraries(marketCalcTest PRIVATE marketCalcLib gtest gtest_main)
