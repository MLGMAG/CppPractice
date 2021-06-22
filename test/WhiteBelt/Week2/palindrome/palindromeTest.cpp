#include <palindrome.h>
#include <gtest/gtest.h>
#include <string>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(palindromeTest, generalTest1) {
    string word = "madam";
    bool expected = true;

    bool actual = isPalindrome(word);

    EXPECT_EQ(actual, expected);
}

TEST(palindromeTest, generalTest2) {
    string word = "gentleman";
    bool expected = false;

    bool actual = isPalindrome(word);

    EXPECT_EQ(actual, expected);
}

TEST(palindromeTest, generalTest3) {
    string word = "X";
    bool expected = true;

    bool actual = isPalindrome(word);

    EXPECT_EQ(actual, expected);
}
