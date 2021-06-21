#include <gtest/gtest.h>
#include <string>
#include <minString.h>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(minStringTest, generalTest1) {
    string firstString = "milk";
    string secondString = "milkshake";
    string thirdString = "month";
    string expected = "milk";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}

TEST(minStringTest, generalTest2) {
    string firstString = "fire";
    string secondString = "fog";
    string thirdString = "wood";
    string expected = "fire";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}

TEST(minStringTest, generalTest3) {
    string firstString = "a";
    string secondString = "b";
    string thirdString = "c";
    string expected = "a";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}

TEST(minStringTest, generalTest4) {
    string firstString = "b";
    string secondString = "c";
    string thirdString = "a";
    string expected = "a";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}

TEST(minStringTest, generalTest5) {
    string firstString = "c";
    string secondString = "a";
    string thirdString = "b";
    string expected = "a";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}

TEST(minStringTest, generalTest6) {
    string firstString = "c";
    string secondString = "b";
    string thirdString = "a";
    string expected = "a";

    string actual = minString(firstString, secondString, thirdString);

    EXPECT_EQ(actual, expected);
}
