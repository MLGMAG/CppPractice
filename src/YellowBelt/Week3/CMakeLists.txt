include_directories(testFramework)
add_library(
        testFrameworkLib STATIC
        testFramework/test_runner.h
        testFramework/test_runner.cpp
)

add_executable(functionDefinition functionDefinition/sum_reverse_sort.cpp functionDefinition/sum_reverse_sort.h functionDefinition/sum_reverse_sort_tests.cpp)
target_link_libraries(functionDefinition PRIVATE testFrameworkLib)
