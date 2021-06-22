include_directories(${LOCAL_DIR_PATH}/palindrome)
add_library(
        palindromeLib STATIC
        ${LOCAL_DIR_PATH}/palindrome/palindrome.cpp
        ${LOCAL_DIR_PATH}/palindrome/palindrome.h
)

add_executable(palindromeTest palindromeTest.cpp)
target_link_libraries(palindromeTest PRIVATE palindromeLib gtest gtest_main)
