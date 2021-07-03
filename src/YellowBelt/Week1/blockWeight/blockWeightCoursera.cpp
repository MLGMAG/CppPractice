#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

struct Block {
    uint64_t length;
    uint64_t width;
    uint64_t height;
};

uint64_t calculateWeight(const vector<Block> &blocks, const uint64_t &consistence) {
    uint64_t generalWeight = 0;
    for (const Block &currentBlock : blocks) {
        generalWeight += currentBlock.length * currentBlock.width * currentBlock.height * consistence;
    }

    return generalWeight;
}

int main() {
    int blockCount;
    uint64_t consistence;
    cin >> blockCount >> consistence;

    uint64_t length;
    uint64_t width;
    uint64_t height;
    vector<Block> blocks;
    for (int i = 0; i < blockCount; ++i) {
        cin >> length >> width >> height;
        blocks.push_back({length, width, height});
    }

    cout << calculateWeight(blocks, consistence);
}
