set(LOCAL_DIR_PATH ${SOURCE_PATH}/WhiteBelt/Week2)


# Factorial tests
include_directories(${LOCAL_DIR_PATH}/factorial)
add_library(
        factorialLib STATIC
        ${LOCAL_DIR_PATH}/factorial/factorial.cpp
        ${LOCAL_DIR_PATH}/factorial/factorial.h
)
add_executable(factorialTest factorial/factorialTest.cpp)
target_link_libraries(factorialTest PRIVATE factorialLib gtest gtest_main)


# Palindrome tests
include_directories(${LOCAL_DIR_PATH}/palindrome)
add_library(
        palindromeLib STATIC
        ${LOCAL_DIR_PATH}/palindrome/palindrome.cpp
        ${LOCAL_DIR_PATH}/palindrome/palindrome.h
)
add_executable(palindromeTest palindrome/palindromeTest.cpp)
target_link_libraries(palindromeTest PRIVATE palindromeLib gtest gtest_main)
