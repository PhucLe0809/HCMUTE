#include <iostream>
#include <vector>

using namespace std;

struct MemoryBlock {
    int start;
    int end;
    int size;
    bool allocated;
};

void bestFit(vector<MemoryBlock>& memory, int processSize) {
    int minBlockSize = INT_MAX;
    int minBlockIndex = -1;

    for (size_t i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size < minBlockSize) {
            minBlockSize = memory[i].size;
            minBlockIndex = i;
        }
    }
    
    if (minBlockIndex != -1) {
        memory[minBlockIndex].allocated = true;
        cout << "Process allocated from " << memory[minBlockIndex].start << " to " << memory[minBlockIndex].end << endl;
    } else {
        cout << "Process cannot be allocated." << endl;
    }
}

int main() {
    vector<MemoryBlock> memory = {{0, 99, 100, false}, {100, 199, 20, false}, 
                                    {200, 299, 40, false}, {300, 399, 10, false}};
    vector<int> processSizes = {20, 30, 10, 60};

    cout << "B9est Fit:" << endl;
    for (int size : processSizes) {
        bestFit(memory, size);
    }

    return 0;
}
