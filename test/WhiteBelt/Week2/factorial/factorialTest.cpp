#include <factorial.h>
#include <gtest/gtest.h>

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(factorialTest, generalTest1) {
    int x = 1;
    int expected = 1;

    int actual = factorial(x);

    EXPECT_EQ(actual, expected);
}

TEST(factorialTest, generalTest2) {
    int x = -2;
    int expected = 1;

    int actual = factorial(x);

    EXPECT_EQ(actual, expected);
}

TEST(factorialTest, generalTest3) {
    int x = 4;
    int expected = 24;

    int actual = factorial(x);

    EXPECT_EQ(actual, expected);
}

TEST(factorialTest, generalTest4) {
    int x = 3;
    int expected = 6;

    int actual = factorial(x);

    EXPECT_EQ(actual, expected);
}
