#include <cstdint>
#include <vector>

using namespace std;

struct Block {
    uint64_t length;
    uint64_t width;
    uint64_t height;
};

uint64_t calculateWeight(const vector<Block> &blocks, const uint64_t &consistence);
