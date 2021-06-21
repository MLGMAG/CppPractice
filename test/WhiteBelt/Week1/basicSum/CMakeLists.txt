include_directories(${LOCAL_DIR_PATH}/basicSum)
add_library(
        basicSumLib STATIC
        ${LOCAL_DIR_PATH}/basicSum/basicSum.cpp
        ${LOCAL_DIR_PATH}/basicSum/basicSum.h
)

add_executable(basicSumTest basicSumTest.cpp)
target_link_libraries(basicSumTest PRIVATE basicSumLib gtest gtest_main)
