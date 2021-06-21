#include <gtest/gtest.h>
#include <basicSum.h>

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(sumTest, generalTest1) {
    int a = 5;
    int b = 10;
    int expected = 15;

    int actual = sum(a, b);

    EXPECT_EQ(actual, expected);
}

TEST(sumTest, generalTest2) {
    int a = -4;
    int b = -9;
    int expected = -13;

    int actual = sum(a, b);

    EXPECT_EQ(actual, expected);
}

TEST(sumTest, generalTest3) {
    int a = -1;
    int b = 2;
    int expected = 1;

    int actual = sum(a, b);

    EXPECT_EQ(actual, expected);
}
