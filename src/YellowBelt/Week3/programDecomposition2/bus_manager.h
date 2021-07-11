#pragma once

#include <string>
#include <vector>
#include <map>
#include "responses.h"

using namespace std;

using StringToVectorMap = map<string, vector<string>>;


class BusManager {
private:
    StringToVectorMap buses_to_stops;
    StringToVectorMap stops_to_buses;

public:
    void AddBus(const string &bus, const vector<string> &stops);

    BusesForStopResponse GetBusesForStop(const string &stop) const;

    StopsForBusResponse GetStopsForBus(const string &bus) const;

    AllBusesResponse GetAllBuses() const;
};
