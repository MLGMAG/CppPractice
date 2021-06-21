include_directories(${SOURCE_PATH}/basicSum)
add_library(
        basicSumLib STATIC
        ${SOURCE_PATH}/basicSum/basicSum.cpp
        ${SOURCE_PATH}/basicSum/basicSum.h
)

add_executable(basicSumTest basicSumTest.cpp)
target_link_libraries(basicSumTest PRIVATE basicSumLib gtest gtest_main)
