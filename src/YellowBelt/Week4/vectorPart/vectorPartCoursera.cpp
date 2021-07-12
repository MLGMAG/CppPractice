#include <algorithm>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &data) {
    for (const int &elem: data) {
        os << elem << ' ';
    }
    return os;
}

bool hasNegativeNumbers(const vector<int> &numbers) {
    int numberOfNegativeNums = count_if(begin(numbers), end(numbers), [](int elem) { return elem < 0; });
    return numberOfNegativeNums > 0;
}

bool isFirstNegative(const vector<int> &numbers) {
    return numbers[0] < 0;
}

vector<int> processOperation(const vector<int> &numbers) {
    auto negativeIter = find_if(begin(numbers), end(numbers), [](int elem) { return elem < 0; });
    vector<int> result;

    while (negativeIter != numbers.begin()) {
        --negativeIter;
        result.push_back(*negativeIter);
    }

    return result;
}

vector<int> generateOutputVector(const vector<int> &numbers) {
    if (numbers.empty() || isFirstNegative(numbers)) {
        return {};
    }

    if (!hasNegativeNumbers(numbers)) {
        return vector(numbers.rbegin(), numbers.rend());
    }

    return processOperation(numbers);
}

void PrintVectorPart(const vector<int> &numbers) {
    cout << generateOutputVector(numbers);
}
