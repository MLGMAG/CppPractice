#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
    for (const auto &x : s) {
        os << x << ' ';
    }
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        os << *i << endl;
    }

    return os;
}

vector<int> createVector(int num) {
    vector<int> result;
    while (num > 0) {
        result.push_back(num);
        --num;
    }
    return result;
}

void rearrangements(int num) {
    vector<int> data = createVector(num);
    sort(begin(data), end(data));
    set<vector<int>> result;
    do {
        result.emplace(vector(begin(data), end(data)));
    } while (next_permutation(data.begin(), data.end()));
    cout << result;
}


int main() {
    int data;
    cin >> data;
    rearrangements(data);
}
