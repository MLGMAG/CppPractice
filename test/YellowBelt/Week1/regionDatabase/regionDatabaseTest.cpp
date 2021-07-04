#include <gtest/gtest.h>
#include <regionDatabase.h>

Region region1 = {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
};

Region region2 = {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
};

Region region3 = {
        "Moscow",
        "Toulouse",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
};

Region region4 = {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
        89
};

Region region5 = {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        31
};

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(regionDatabaseTests, generalTest1) {
    vector<Region> inputData = {region1, region2, region1, region1, region2};
    FindMaxRepetitionCount(inputData);
    int expected = 3;

    int actual = FindMaxRepetitionCount(inputData);

    EXPECT_EQ(actual, expected);
}

TEST(regionDatabaseTests, generalTest2) {
    vector<Region> inputData = {region1, region2, region3, region4, region5};
    FindMaxRepetitionCount(inputData);
    int expected = 1;

    int actual = FindMaxRepetitionCount(inputData);

    EXPECT_EQ(actual, expected);
}
