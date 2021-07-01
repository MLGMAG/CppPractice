#include <gtest/gtest.h>
#include <avrTemp.h>
#include <vector>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(AvrTempTests, generalTest1) {
    vector<int> inputData = {5, 4, 1, -2, 7};
    vector<int> expected = {0, 1, 4};

    vector<int> actual = process(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(AvrTempTests, generalTest2) {
    vector<int> inputData = {2, 2, 2, 2, 2};
    vector<int> expected;

    vector<int> actual = process(inputData);

    EXPECT_EQ(actual, expected);
}
