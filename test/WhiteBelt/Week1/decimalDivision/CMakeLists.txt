include_directories(${LOCAL_DIR_PATH}/decimalDivision)
add_library(
        decimalDivisionLib STATIC
        ${LOCAL_DIR_PATH}/decimalDivision/decimalDivision.cpp
        ${LOCAL_DIR_PATH}/decimalDivision/decimalDivision.h
)

add_executable(decimalDivisionTest decimalDivisionTest.cpp)
target_link_libraries(decimalDivisionTest PRIVATE decimalDivisionLib gtest gtest_main)
