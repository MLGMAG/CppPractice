#include "bus_manager.h"


void BusManager::AddBus(const string &bus, const vector<string> &stops) {
    buses_to_stops[bus] = stops;

    for (const string &stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const {
    if (stops_to_buses.count(stop) == 0) {
        return {vector<string>()};
    }
    return {stops_to_buses.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {

    if (buses_to_stops.count(bus) == 0) {
        return {bus, vector<string>(), StringToVectorMap()};
    }

    vector<string> stops = buses_to_stops.at(bus);
    StringToVectorMap stop_to_buses;

    for (const string &stop : stops) {
        stop_to_buses[stop] = stops_to_buses.at(stop);
    }

    return {bus, stops, stop_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_to_stops};
}
