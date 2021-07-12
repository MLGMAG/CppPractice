#include "splitString.h"
#include "test_runner.h"

void shouldSplitWords() {
    string input = "C Cpp Java Python";
    vector<string> expected = {"C", "Cpp", "Java", "Python"};

    vector<string> actual = SplitIntoWords(input);

    AssertEqual(actual, expected);
}

void shouldSplitWord() {
    string input = "C";
    vector<string> expected = {"C"};

    vector<string> actual = SplitIntoWords(input);

    AssertEqual(actual, expected);
}

int main() {
    TestRunner testRunner;
    testRunner.RunTest(shouldSplitWords, "shouldSplitWords");
    testRunner.RunTest(shouldSplitWord, "shouldSplitWord");
}
