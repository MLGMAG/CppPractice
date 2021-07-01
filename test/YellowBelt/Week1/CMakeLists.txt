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

# Average temperature test
include_directories(${LOCAL_DIR_PATH}/avrTemp)
add_library(
        avrTempLib STATIC
        ${LOCAL_DIR_PATH}/avrTemp/avrTemp.cpp
        ${LOCAL_DIR_PATH}/avrTemp/avrTemp.h
)
add_executable(avrTempTest avrTemp/avrTempTest.cpp)
target_link_libraries(avrTempTest PRIVATE avrTempLib gtest gtest_main)
