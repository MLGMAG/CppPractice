#include "responses.h"
#include <iostream>

using namespace std;


ostream &operator<<(ostream &os, const BusesForStopResponse &r) {
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        os << r.buses;
    }

    return os;
}

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
