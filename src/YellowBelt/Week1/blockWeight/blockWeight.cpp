#include <cstdint>
#include <vector>
#include "blockWeight.h"

using namespace std;

uint64_t calculateWeight(const vector<Block> &blocks, const uint64_t &consistence) {
    uint64_t generalWeight = 0;
    for (const Block &currentBlock : blocks) {
        generalWeight += currentBlock.length * currentBlock.width * currentBlock.height * consistence;
    }

    return generalWeight;
}
