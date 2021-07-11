#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

using StringToVectorMap = map<string, vector<string>>;


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const auto &elem : v) {
        os << elem + ' ';
    }
    return os;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r);

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    StringToVectorMap stop_to_busses;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r);

struct AllBusesResponse {
    StringToVectorMap busses_to_stops;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r);
