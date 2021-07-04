#include <tuple>
#include <string>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;

tuple<const string &, const string &, const map<Lang, string> &, const int64_t &>
createTupleFromRegion(const Region &region) {
    return tie(region.std_name, region.parent_std_name, region.names, region.population);
}

bool operator<(const Region &lhs, const Region &rhs) {
    return createTupleFromRegion(lhs) < createTupleFromRegion(rhs);

}

int FindMaxRepetitionCount(const vector<Region> &regions) {
    map<Region, int> regionMap;

    for (const Region &region : regions) {
        regionMap[region]++;
    }

    int maxRepetitionCount = 0;
    for (const auto&[key, value] : regionMap) {
        if (maxRepetitionCount < value) {
            maxRepetitionCount = value;
        }
    }

    return maxRepetitionCount;
}
