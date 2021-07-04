#include <string>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions);
