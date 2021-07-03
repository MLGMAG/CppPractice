#include <vector>
#include <cstdint>

using namespace std;

int64_t calculateAverage(const vector<int64_t> &data) {
    int64_t sum = 0;
    for (const auto &item : data) {
        sum += item;
    }

    auto elementCount = static_cast<int64_t> (data.size());
    return sum / elementCount;
}

vector<int> getIndexesHigherThanValue(const vector<int64_t> &data, const int64_t &value) {
    vector<int> result;

    for (int i = 0; i < data.size(); ++i) {
        if (data[i] > value) {
            result.push_back(i);
        }
    }

    return result;
}

vector<int> process(const vector<int64_t> &temperatures) {
    int64_t average = calculateAverage(temperatures);
    return getIndexesHigherThanValue(temperatures, average);
}
