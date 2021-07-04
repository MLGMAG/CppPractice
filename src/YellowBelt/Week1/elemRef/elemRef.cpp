#include <map>

using namespace std;

template<typename K, typename V>
V &GetRefStrict(map<K, V> &inputMap, K key) {
    if (inputMap.count(key) == 0) {
        throw runtime_error("Key does not exist!");
    }
    return inputMap.at(key);
}
