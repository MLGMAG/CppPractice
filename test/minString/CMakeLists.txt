include_directories(${SOURCE_PATH}/minString)
add_library(
        minStringLib STATIC
        ${SOURCE_PATH}/minString/minString.cpp
        ${SOURCE_PATH}/minString/minString.h
)

add_executable(minStringTest minStringTest.cpp)
target_link_libraries(minStringTest PRIVATE minStringLib gtest gtest_main)
