#include <gtest/gtest.h>
#include <marketCalc.h>

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(marketCalcTest, generalTest1) {
    double initialPrice = 100;
    double firstDiscountBorder = 110;
    double secondDiscountBorder = 120;
    double firstDiscountPercent = 5;
    double secondDiscountPercent = 10;
    double expected = 100;

    double actual = calculatePrice(initialPrice, firstDiscountBorder, secondDiscountBorder, firstDiscountPercent,
                                   secondDiscountPercent);

    EXPECT_EQ(actual, expected);
}

TEST(marketCalcTest, generalTest2) {
    double initialPrice = 115;
    double firstDiscountBorder = 110;
    double secondDiscountBorder = 120;
    double firstDiscountPercent = 5;
    double secondDiscountPercent = 10;
    double expected = 109.25;

    double actual = calculatePrice(initialPrice, firstDiscountBorder, secondDiscountBorder, firstDiscountPercent,
                                   secondDiscountPercent);

    EXPECT_EQ(actual, expected);
}

TEST(marketCalcTest, generalTest3) {
    double initialPrice = 150;
    double firstDiscountBorder = 110;
    double secondDiscountBorder = 120;
    double firstDiscountPercent = 5;
    double secondDiscountPercent = 12.5;
    double expected = 131.25;

    double actual = calculatePrice(initialPrice, firstDiscountBorder, secondDiscountBorder, firstDiscountPercent,
                                   secondDiscountPercent);

    EXPECT_EQ(actual, expected);
}
