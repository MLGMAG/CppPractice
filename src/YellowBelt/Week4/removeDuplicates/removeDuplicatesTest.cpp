#include "removeDuplicates.h"
#include "test_runner.h"

void shouldRemoveDuplicatesSetSolution() {
    vector<int> data = {6, 4, 7, 6, 4, 4, 0, 1};
    set<int> expectedSet = {6, 4, 7, 0, 1};
    vector<int> expected(begin(expectedSet), end(expectedSet));

    RemoveDuplicatesSetSoultion(data);

    AssertEqual(data, expected);
}

void shouldRemoveDuplicatesUniqueSolution() {
    vector<int> data = {6, 4, 7, 6, 4, 4, 0, 1};
    set<int> expectedSet = {6, 4, 7, 0, 1};
    vector<int> expected(begin(expectedSet), end(expectedSet));

    RemoveDuplicatesUniqueSoultion(data);

    AssertEqual(data, expected);
}

int main() {
    TestRunner testRunner;
    testRunner.RunTest(shouldRemoveDuplicatesSetSolution, "shouldRemoveDuplicatesSetSolution");
    testRunner.RunTest(shouldRemoveDuplicatesUniqueSolution, "shouldRemoveDuplicatesUniqueSolution");
}
