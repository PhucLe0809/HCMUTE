#include <iostream>
#include <vector>

using namespace std;

struct MemoryBlock {
    int start;
    int end;
    int size;
    bool allocated;
};

void firstFit(vector<MemoryBlock>& memory, int processSize) {
    for (auto& block : memory) {
        if (!block.allocated && block.size >= processSize) {
            block.allocated = true;
            cout << "Process allocated from " << block.start << " to " << block.end << endl;
            return;
        }
    }
    cout << "Process cannot be allocated." << endl;
}

int main() {
    vector<MemoryBlock> memory = {{0, 99, 100, false}, {100, 199, 20, false}, 
                                    {200, 299, 40, false}, {300, 399, 10, false}};
    vector<int> processSizes = {20, 30, 10, 60};

    cout << "First Fit:" << endl;
    for (int size : processSizes) {
        firstFit(memory, size);
    }

    return 0;
}
