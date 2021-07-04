#include <gtest/gtest.h>
#include <elemRef.h>
#include <map>
#include <string>

using namespace std;

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(elemRefTests, shouldReturnCorrectValue) {
    map<int, string> inputData = {{0, "value"},
                                  {1, "newValue"}};
    string expected = "value";

    const string &actual = GetRefStrict(inputData, 0);

    EXPECT_EQ(actual, expected);
}

TEST(elemRefTests, shouldChangeValueInMap) {
    map<int, string> inputData = {{0, "value"},
                                  {1, "newValue"}};
    string expected = "changedValue";

    string &elementInMap = GetRefStrict(inputData, 0);
    elementInMap = expected;

    EXPECT_EQ(inputData.at(0), expected);
}

TEST(elemRefTests, shouldThrowExceptionOnNonExistingElem) {
    map<int, string> inputData;
    try {
        GetRefStrict(inputData, 1);
        FAIL();
    } catch (const runtime_error &error) {
        EXPECT_EQ(error.what(), string("Key does not exist!"));
    }

}
