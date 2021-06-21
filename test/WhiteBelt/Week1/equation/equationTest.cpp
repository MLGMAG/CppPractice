#include <gtest/gtest.h>
#include <equation.h>
#include <vector>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(equationTests, generalTest1) {
    int k1 = 2;
    int k2 = 5;
    int k3 = 2;
    double expectedFirstRoot = -0.5;
    double expectedSecondRoot = -2;

    vector<double> result = calculateRoots(k1, k2, k3);

    double actualFirstRoot = result[0];
    double actualSecondRoot = result[1];
    EXPECT_EQ(actualFirstRoot, expectedFirstRoot);
    EXPECT_EQ(actualSecondRoot, expectedSecondRoot);
}

TEST(equationTests, generalTest2) {
    int k1 = 2;
    int k2 = 4;
    int k3 = 2;
    double expectedRoot = -1;

    vector<double> result = calculateRoots(k1, k2, k3);

    double actualRoot = result[0];
    EXPECT_EQ(actualRoot, expectedRoot);
}

TEST(equationTests, generalTest3) {
    int k1 = 2;
    int k2 = 1;
    int k3 = 2;

    vector<double> result = calculateRoots(k1, k2, k3);

    EXPECT_EQ(result.size(), 0);
}

TEST(equationTests, generalTest4) {
    int k1 = 0;
    int k2 = 4;
    int k3 = 10;
    double expectedRoot = -2.5;

    vector<double> result = calculateRoots(k1, k2, k3);

    double actualRoot = result[0];
    EXPECT_EQ(actualRoot, expectedRoot);
}

TEST(equationTests, generalTest5) {
    int k1 = 1;
    int k2 = 3;
    int k3 = -10;
    double expectedFirstRoot = 2;
    double expectedSecondRoot = -5;

    vector<double> result = calculateRoots(k1, k2, k3);

    double actualFirstRoot = result[0];
    double actualSecondRoot = result[1];
    EXPECT_EQ(actualFirstRoot, expectedFirstRoot);
    EXPECT_EQ(actualSecondRoot, expectedSecondRoot);
}

TEST(equationTests, generalTest6) {
    int k1 = 1;
    int k2 = -8;
    int k3 = 16;
    double expectedRoot = 4;

    vector<double> result = calculateRoots(k1, k2, k3);

    double actualRoot = result[0];
    EXPECT_EQ(actualRoot, expectedRoot);
}
