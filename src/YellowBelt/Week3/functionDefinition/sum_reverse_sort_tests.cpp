#include "sum_reverse_sort.h"
#include "test_runner.h"

void sumTests() {
    AssertEqual(Sum(8, 2), 10);
    AssertEqual(Sum(0, 0), 0);
    AssertEqual(Sum(-2, -3), -5);
    AssertEqual(Sum(1, 0), 1);
}

void reversTests() {
    AssertEqual(Reverse("abcdefg"), "gfedcba");
    AssertEqual(Reverse("a"), "a");
    AssertEqual(Reverse(""), "");
    AssertEqual(Reverse("12 34"), "43 21");
}

void shouldSortVector() {
    vector<int> inputData = {10, 9, 8, 7, 6};
    vector<int> expected = {6, 7, 8, 9, 10};

    Sort(inputData);

    AssertEqual(inputData, expected);
}

void shouldEmptyVector() {
    vector<int> inputData = {};
    vector<int> expected = {};

    Sort(inputData);

    AssertEqual(inputData, expected);
}

void shouldSortSortedVector() {
    vector<int> inputData = {6, 7, 8, 9, 10};
    vector<int> expected = {6, 7, 8, 9, 10};

    Sort(inputData);

    AssertEqual(inputData, expected);
}

int main() {
    TestRunner testRunner;
    testRunner.RunTest(sumTests, "sumTests");
    testRunner.RunTest(reversTests, "reversTests");
    testRunner.RunTest(shouldSortVector, "shouldSortVector");
    testRunner.RunTest(shouldEmptyVector, "shouldEmptyVector");
    testRunner.RunTest(shouldSortSortedVector, "shouldSortSortedVector");
}
