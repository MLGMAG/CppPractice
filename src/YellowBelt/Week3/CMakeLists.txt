# Testing Framework
include_directories(testFramework)
add_library(
        testFrameworkLib STATIC
        testFramework/test_runner.h
        testFramework/test_runner.cpp
)

# Function Definition
add_executable(functionDefinition functionDefinition/sum_reverse_sort.cpp functionDefinition/sum_reverse_sort.h functionDefinition/sum_reverse_sort_tests.cpp)
target_link_libraries(functionDefinition PRIVATE testFrameworkLib)

# Phone Number
add_executable(phoneNumber phoneNumber/phone_number.cpp phoneNumber/phone_number.h phoneNumber/phoneNumberTests.cpp)
target_link_libraries(phoneNumber PRIVATE testFrameworkLib)
