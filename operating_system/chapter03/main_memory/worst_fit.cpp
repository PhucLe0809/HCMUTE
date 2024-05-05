#include <iostream>
#include <vector>

using namespace std;

struct MemoryBlock {
    int start;
    int end;
    int size;
    bool allocated;
};

void worstFit(vector<MemoryBlock>& memory, int processSize) {
    int maxBlockSize = INT_MIN;
    int maxBlockIndex = -1;

    for (size_t i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size > maxBlockSize) {
            maxBlockSize = memory[i].size;
            maxBlockIndex = i;
        }
    }

    if (maxBlockIndex != -1) {
        memory[maxBlockIndex].allocated = true;
        cout << "Process allocated from " << memory[maxBlockIndex].start << " to " << memory[maxBlockIndex].end << endl;
    } else {
        cout << "Process cannot be allocated." << endl;
    }
}

int main() {
    vector<MemoryBlock> memory = {{0, 99, 100, false}, {100, 199, 20, false}, 
                                    {200, 299, 40, false}, {300, 399, 10, false}};
    vector<int> processSizes = {20, 30, 10, 60};

    cout << "Worst Fit:" << endl;
    for (int size : processSizes) {
        worstFit(memory, size);
    }

    return 0;
}
