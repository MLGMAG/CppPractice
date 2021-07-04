#include <gtest/gtest.h>
#include <square.h>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(squareTests, generalTest1) {
    vector<int> inputData = {1, 2, 3};
    vector<int> expected = {1, 4, 9};

    vector<int> actual = Sqr(inputData);

    EXPECT_EQ(actual, expected);
}


TEST(squareTests, generalTest2) {
    map<string, int> inputData = {{"One",   1},
                                  {"Two",   2},
                                  {"Three", 3},
                                  {"Four",  4}};
    map<string, int> expected = {{"One",   1},
                                 {"Two",   4},
                                 {"Three", 9},
                                 {"Four",  16}};

    map<string, int> actual = Sqr(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(squareTests, generalTest3) {
    pair<int, double> inputData = make_pair(10, 14.5);
    pair<int, double> expected = make_pair(100, 210.25);

    pair<int, double> actual = Sqr(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(squareTests, generalTest4) {
    vector<pair<int, double>> inputData = {{10, 14.5}, {5, 7.25}, {20, 29}};
    vector<pair<int, double>> expected = {{100, 210.25}, {25, 52.5625}, {400, 841}};

    vector<pair<int, double>> actual = Sqr(inputData);

    EXPECT_EQ(actual, expected);
}
