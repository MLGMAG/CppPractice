#pragma once

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T> &elements, const T &border) {
    auto borderIter = find_if(begin(elements), end(elements), [border](T element) { return border < element; });

    vector<T> result;
    while (borderIter != end(elements)) {
        result.push_back(*borderIter);
        ++borderIter;
    }

    return result;
}
