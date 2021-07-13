#pragma once

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
void RemoveDuplicatesSetSoultion(vector <T> &elements) {
    set<T> result(begin(elements), end(elements));
    elements = vector(begin(result), end(result));
}

template<typename T>
void RemoveDuplicatesUniqueSoultion(vector <T> &elements) {
    sort(begin(elements), end(elements));
    auto it = unique(begin(elements), end(elements));
    elements.erase(it, end(elements));
}
