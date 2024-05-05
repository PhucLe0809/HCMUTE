#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void Output(unordered_map<int, int>& pageMap){
    cout << "[ ";
    for (auto &it:pageMap) cout << it.first << ", ";
    cout << "] \n";
    
    cout << "[ ";
    for (auto &it:pageMap) cout << it.second << ", ";
    cout << "] \n";

    cout << "------------------------------------------------\n";
}
void CountingLFU(const vector<int>& pages, int capacity) {
    unordered_map<int, int> pageMap;
    int pageFaults = 0;

    for (int page : pages) {
        Output(pageMap);
        if (pageMap.find(page) == pageMap.end()) {
            if (pageMap.size() == capacity) {
                int minFrequency = INT32_MAX;
                int leastFrequencyPage = -1;
                for (auto &it : pageMap) {
                    if (minFrequency > it.second) {
                        minFrequency = it.second; 
                        leastFrequencyPage = it.first;
                    }
                }
                pageMap.erase(leastFrequencyPage);
                cout << "Page " << leastFrequencyPage << " replaced by page " << page << endl;
            }
            pageFaults++;
            cout << "Page " << page << " loaded into memory" << endl;
        }else{
            cout << "Page " << page << " existed in memory" << endl;
        }
        pageMap[page]++;
    }
    Output(pageMap);

    cout << "LFU: Total page faults = " << pageFaults << endl;
}

int main() {
    vector<int> pages = {1, 2, 1, 2, 1, 4, 5, 1, 2, 3, 4, 5};
    int capacity = 3;

    CountingLFU(pages, capacity);

    return 0;
}
