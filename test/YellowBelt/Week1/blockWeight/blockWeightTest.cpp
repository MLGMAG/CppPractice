#include <gtest/gtest.h>
#include <blockWeight.h>

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(blockWeightTests, generalTest1) {
    Block block1 = {1, 2, 3};
    Block block2 = {30, 40, 50};
    vector<Block> inputData = {block1, block2};
    int consistence = 14;
    uint64_t expected = 840084;

    uint64_t actual = calculateWeight(inputData, consistence);

    EXPECT_EQ(actual, expected);
}

TEST(blockWeightTests, generalTest2) {
    Block block = {1, 1200, 1900};
    vector<Block> inputData = {block};
    int consistence = 170;
    uint64_t expected = 387'600'000;

    uint64_t actual = calculateWeight(inputData, consistence);

    EXPECT_EQ(actual, expected);
}


TEST(blockWeightTests, generalTest3) {
    Block block = {10'000, 10'000, 10'000};
    vector<Block> inputData = {block};
    int consistence = 100'000;
    uint64_t expected = 100'000'000'000'000'000;

    uint64_t actual = calculateWeight(inputData, consistence);

    EXPECT_EQ(actual, expected);
}
