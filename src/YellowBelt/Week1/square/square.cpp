#include <vector>
#include <map>
#include <utility>

using namespace std;

template<typename K, typename V>
vector<K> getMapKeys(const map<K, V> &data);

template<typename K, typename V>
vector<V> getMapValues(const map<K, V> &data);

template<typename T>
vector<T> operator*(const vector<T> &lhs, const vector<T> &rhs);

template<typename K, typename V>
map<K, V> operator*(const map<K, V> &lhs, const map<K, V> &rhs);

template<typename FIRST, typename SECOND>
pair<FIRST, SECOND> operator*(const pair<FIRST, SECOND> &lhs, const pair<FIRST, SECOND> &rhs);

template<typename T>
T Sqr(T t);

template<typename K, typename V>
vector<K> getMapKeys(const map<K, V> &data) {
    vector<K> data_values;
    for (const auto&[key, value] : data) {
        data_values.push_back(key);
    }
    return data_values;
}

template<typename K, typename V>
vector<V> getMapValues(const map<K, V> &data) {
    vector<V> data_values;
    for (const auto&[key, value] : data) {
        data_values.push_back(value);
    }
    return data_values;
}

template<typename T>
vector<T> operator*(const vector<T> &lhs, const vector<T> &rhs) {
    vector<T> vector;
    for (size_t i = 0; i < lhs.size(); ++i) {
        vector.push_back(lhs.at(i) * rhs.at(i));
    }
    return vector;
}

template<typename K, typename V>
map<K, V> operator*(const map<K, V> &lhs, const map<K, V> &rhs) {
    vector<V> lhs_values = getMapValues(lhs);
    vector<V> rhs_values = getMapValues(rhs);
    vector<V> squareVector = lhs_values * rhs_values;
    vector<K> lhs_keys = getMapKeys(lhs);

    map<K, V> squareMap;
    for (size_t i = 0; i < lhs.size(); ++i) {
        squareMap.insert({lhs_keys.at(i), squareVector.at(i)});
    }

    return squareMap;
}

template<typename FIRST, typename SECOND>
pair<FIRST, SECOND> operator*(const pair<FIRST, SECOND> &lhs, const pair<FIRST, SECOND> &rhs) {
    FIRST first_value = lhs.first * rhs.first;
    SECOND second_value = lhs.second * rhs.second;

    return make_pair(first_value, second_value);
}

template<typename T>
T Sqr(T t) {
    return t * t;
}
