# Function Definition
add_executable(functionDefinition functionDefinition/sum_reverse_sort.cpp functionDefinition/sum_reverse_sort.h functionDefinition/sum_reverse_sort_tests.cpp)
target_link_libraries(functionDefinition PRIVATE testFrameworkLib)

# Phone Number
add_executable(phoneNumber phoneNumber/phone_number.cpp phoneNumber/phone_number.h phoneNumber/phoneNumberTests.cpp)
target_link_libraries(phoneNumber PRIVATE testFrameworkLib)

# Class Declaration
add_executable(classDeclaration classDeclaration/rectangle.h classDeclaration/rectangle.cpp)

# Program Decomposition 2
add_executable(programDecomposition2
        programDecomposition2/query.h programDecomposition2/query.cpp
        programDecomposition2/responses.h programDecomposition2/responses.cpp
        programDecomposition2/bus_manager.h programDecomposition2/bus_manager.cpp
        programDecomposition2/main.cpp)
