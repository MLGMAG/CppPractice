#include "greaterElement.h"
#include "test_runner.h"

void shouldProcessEmptyList() {
    set<int> input = {};
    int border = 10;
    vector<int> expected = {};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

void shouldProcessIncorrectBorder() {
    set<int> input = {1, 2, 3, 4, 5, 6};
    int border = 10;
    vector<int> expected = {};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

void shouldProcessNormalFlow() {
    set<int> input = {1, 5, 7, 8};
    int border = 5;
    vector<int> expected = {7, 8};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

void shouldProcessBorderLast() {
    set<int> input = {1, 2, 3, 5};
    int border = 5;
    vector<int> expected = {};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

void shouldProcessBorderLastButOne() {
    set<int> input = {1, 2, 7, 5};
    int border = 5;
    vector<int> expected = {7};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

void shouldFindUpperBound() {
    set<int> input = {1, 2, 7, 5};
    int border = 3;
    vector<int> expected = {5, 7};

    vector<int> actual = FindGreaterElements(input, border);

    AssertEqual(actual, expected);
}

int main() {
    TestRunner testRunner;
    testRunner.RunTest(shouldProcessEmptyList, "shouldProcessEmptyList");
    testRunner.RunTest(shouldProcessIncorrectBorder, "shouldProcessIncorrectBorder");
    testRunner.RunTest(shouldProcessNormalFlow, "shouldProcessNormalFlow");
    testRunner.RunTest(shouldProcessBorderLast, "shouldProcessBorderLast");
    testRunner.RunTest(shouldProcessBorderLastButOne, "shouldProcessBorderLastButOne");
    testRunner.RunTest(shouldFindUpperBound, "shouldFindUpperBound");
}
