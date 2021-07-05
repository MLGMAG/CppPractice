#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using StringToVectorMap = map<string, vector<string>>;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

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

ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        os << r.buses;
    }

    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    StringToVectorMap stop_to_busses;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
    if (r.stop_to_busses.empty()) {
        os << "No bus";
    } else {
        for (size_t i = 0; i < r.stops.size(); ++i) {
            if (r.stop_to_busses.at(r.stops[i]).size() == 1) {
                os << "Stop " << r.stops[i] << ": no interchange";
            } else {
                const vector<string> &busesVector = r.stop_to_busses.at(r.stops[i]);
                os << "Stop " << r.stops[i] << ": ";
                for (const string& bus : busesVector) {
                    if (bus != r.bus) {
                        os << bus << ' ';
                    }
                }
            }

            if ((i + 1) != r.stops.size()) {
                os << endl;
            }
        }
    }

    return os;
}

struct AllBusesResponse {
    StringToVectorMap busses_to_stops;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r) {
    if (r.busses_to_stops.empty()) {
        os << "No buses";
    } else {
        for (const auto&[bus, stopsVector] : r.busses_to_stops) {
            os << "Bus " << bus << ": " << stopsVector << endl;
        }
    }

    return os;
}

class BusManager {
private:
    StringToVectorMap buses_to_stops;
    StringToVectorMap stops_to_buses;

public:
    void AddBus(const string &bus, const vector<string> &stops) {
        buses_to_stops[bus] = stops;

        for (const string &stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string &stop) const {
        if (stops_to_buses.count(stop) == 0) {
            return {vector<string>()};
        }
        return {stops_to_buses.at(stop)};
    }

    StopsForBusResponse GetStopsForBus(const string &bus) const {

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

    AllBusesResponse GetAllBuses() const {
        return {buses_to_stops};
    }
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
