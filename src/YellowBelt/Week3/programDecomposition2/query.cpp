#include "query.h"
#include <iostream>

using namespace std;


istream &operator>>(istream &is, Query &q) {
    string queryType;
    is >> queryType;

    if (queryType == "NEW_BUS") {
        q.type = QueryType::NewBus;
        string bus;
        is >> bus;
        q.bus = bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string &stop : q.stops) {
            is >> stop;
        }
        return is;
    }

    if (queryType == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        string stop;
        is >> stop;
        q.stop = stop;
        return is;
    }

    if (queryType == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        string bus;
        is >> bus;
        q.bus = bus;
        return is;
    }

    if (queryType == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
        return is;
    }

    return is;
}
