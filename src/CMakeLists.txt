# Testing Framework
include_directories(testFramework)
add_library(
        testFrameworkLib STATIC
        testFramework/test_runner.h
        testFramework/test_runner.cpp
)

# White belt
add_subdirectory(WhiteBelt/Week1)
add_subdirectory(WhiteBelt/Week2)

#Yellow belt
add_subdirectory(YellowBelt/Week1)
add_subdirectory(YellowBelt/Week2)
add_subdirectory(YellowBelt/Week3)
add_subdirectory(YellowBelt/Week4)
add_subdirectory(YellowBelt/Week5)
