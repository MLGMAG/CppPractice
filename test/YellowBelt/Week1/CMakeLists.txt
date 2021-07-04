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

# Block weight test
include_directories(${LOCAL_DIR_PATH}/blockWeight)
add_library(
        blockWeightLib STATIC
        ${LOCAL_DIR_PATH}/blockWeight/blockWeight.cpp
        ${LOCAL_DIR_PATH}/blockWeight/blockWeight.h
)
add_executable(blockWeightTest blockWeight/blockWeightTest.cpp)
target_link_libraries(blockWeightTest PRIVATE blockWeightLib gtest gtest_main)

# Region database test
include_directories(${LOCAL_DIR_PATH}/regionDatabase)
add_library(
        regionDatabaseLib STATIC
        ${LOCAL_DIR_PATH}/regionDatabase/regionDatabase.cpp
        ${LOCAL_DIR_PATH}/regionDatabase/regionDatabase.h
)
add_executable(regionDatabaseTest regionDatabase/regionDatabaseTest.cpp)
target_link_libraries(regionDatabaseTest PRIVATE regionDatabaseLib gtest gtest_main)

# Square test
include_directories(${LOCAL_DIR_PATH}/square)
add_library(
        squareLib STATIC
        ${LOCAL_DIR_PATH}/square/square.cpp
        ${LOCAL_DIR_PATH}/square/square.h
)
add_executable(squareTest square/squareTest.cpp)
target_link_libraries(squareTest PRIVATE squareLib gtest gtest_main)
