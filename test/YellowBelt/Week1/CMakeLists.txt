set(LOCAL_DIR_PATH ${SOURCE_PATH}/YellowBelt/Week1)

# Matrix sum test
include_directories(${LOCAL_DIR_PATH}/matrixSum)
add_library(
        matrixSumLib STATIC
        ${LOCAL_DIR_PATH}/matrixSum/matrixSum.cpp
        ${LOCAL_DIR_PATH}/matrixSum/matrixSum.h
)
add_executable(matrixSumTest matrixSum/matrixSumTest.cpp)
target_link_libraries(matrixSumTest PRIVATE matrixSumLib gtest gtest_main)
