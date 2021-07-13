#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
void RemoveDuplicatesSetSoultion(vector <T> &elements) {
    set<T> result(begin(elements), end(elements));
    elements = vector(begin(result), end(result));
}
