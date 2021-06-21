#include <decimalDivision.h>
#include <gtest/gtest.h>
#include <string>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(decimalDivisionTest, generalTest1) {
    testing::internal::CaptureStdout();
    int value = 10;
    int divider = 2;
    string expected = "5";

    divide(value, divider);

    string actual = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual, expected);
}

TEST(decimalDivisionTest, generalTest2) {
    testing::internal::CaptureStdout();
    int value = 3;
    int divider = 5;
    string expected = "0";

    divide(value, divider);

    string actual = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual, expected);
}

TEST(decimalDivisionTest, generalTest3) {
    testing::internal::CaptureStdout();
    int value = 11;
    int divider = 0;
    string expected = "Impossible";

    divide(value, divider);

    string actual = testing::internal::GetCapturedStdout();
    EXPECT_EQ(actual, expected);
}
