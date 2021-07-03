#include <gtest/gtest.h>
#include <avrTemp.h>
#include <vector>
#include <cstdint>

using namespace std;

vector<int64_t> generalTest3InputData();

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(AvrTempTests, generalTest1) {
    vector<int64_t> inputData = {5, 4, 1, -2, 7};
    vector<int> expected = {0, 1, 4};

    vector<int> actual = process(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(AvrTempTests, generalTest2) {
    vector<int64_t> inputData = {2, 2, 2, 2, 2};
    vector<int> expected;

    vector<int> actual = process(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(AvrTempTests, generalTest3) {
    vector<int64_t> inputData = generalTest3InputData();
    vector<int> expected;

    vector<int> actual = process(inputData);

    EXPECT_EQ(actual, expected);
}

vector<int64_t> generalTest3InputData() {
    vector<int64_t> data;

    uint64_t elementsCount = 10e6;
    int64_t element = 10e8;
    for (uint64_t i = 0; i < elementsCount; ++i) {
        data.push_back(element);
    }

    return data;
}
