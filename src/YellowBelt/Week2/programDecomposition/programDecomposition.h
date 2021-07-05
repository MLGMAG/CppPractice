#include <string>
#include <vector>

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

struct BusesForStopResponse {
    vector<string> buses;
};

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    StringToVectorMap stop_to_busses;
};

struct AllBusesResponse {
    StringToVectorMap busses_to_stops;
};

class BusManager {
private:
    StringToVectorMap stops_to_buses;
    StringToVectorMap buses_to_stops;

public:
    void AddBus(const string &bus, const vector<string> &stops);

    BusesForStopResponse GetBusesForStop(const string &stop) const;

    StopsForBusResponse GetStopsForBus(const string &bus) const;

    AllBusesResponse GetAllBuses() const;
};

istream &operator>>(istream &is, Query &q);

ostream &operator<<(ostream &os, const BusesForStopResponse &r);

ostream &operator<<(ostream &os, const StopsForBusResponse &r);

ostream &operator<<(ostream &os, const AllBusesResponse &r);

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
