include_directories(${LOCAL_DIR_PATH}/minString)
add_library(
        minStringLib STATIC
        ${LOCAL_DIR_PATH}/minString/minString.cpp
        ${LOCAL_DIR_PATH}/minString/minString.h
)

add_executable(minStringTest minStringTest.cpp)
target_link_libraries(minStringTest PRIVATE minStringLib gtest gtest_main)
