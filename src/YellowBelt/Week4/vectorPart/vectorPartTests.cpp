#include "vectorPart.h"
#include "test_runner.h"
#include <vector>

using namespace std;

void shouldProcessEmptyVector() {
    vector<int> data;

    vector<int> actual = generateOutputVector(data);

    AssertEqual(actual, data);
}

void shouldProcessNonNegativeVector() {
    vector<int> data = {1, 2, 3, 4, 5, 6};
    vector<int> expected(data.rbegin(), data.rend());

    vector<int> actual = generateOutputVector(data);

    AssertEqual(actual, expected);
}

void shouldProcessFirstNegativeElem() {
    vector<int> data = {-1, 2, 3, 4, 5, 6};
    vector<int> expected;

    vector<int> actual = generateOutputVector(data);

    AssertEqual(actual, expected);
}

void shouldProcessVector() {
    vector<int> data = {1, 2, 3, 4, 5, -6};
    vector<int> expected = {5, 4, 3, 2, 1};

    vector<int> actual = generateOutputVector(data);

    AssertEqual(actual, expected);
}

int main() {
    TestRunner testRunner;
    testRunner.RunTest(shouldProcessEmptyVector, "shouldProcessEmptyVector");
    testRunner.RunTest(shouldProcessNonNegativeVector, "shouldProcessNonNegativeVector");
    testRunner.RunTest(shouldProcessFirstNegativeElem, "shouldProcessFirstNegativeElem");
    testRunner.RunTest(shouldProcessVector, "shouldProcessVector");
}
