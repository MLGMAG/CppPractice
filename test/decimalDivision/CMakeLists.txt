include_directories(${SOURCE_PATH}/decimalDivision)
add_library(
        decimalDivisionLib STATIC
        ${SOURCE_PATH}/decimalDivision/decimalDivision.cpp
        ${SOURCE_PATH}/decimalDivision/decimalDivision.h
)

add_executable(decimalDivisionTest decimalDivisionTest.cpp)
target_link_libraries(decimalDivisionTest PRIVATE decimalDivisionLib gtest gtest_main)
