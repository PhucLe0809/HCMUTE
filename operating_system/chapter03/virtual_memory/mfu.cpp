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
void CountingMFU(const vector<int>& pages, int capacity) {
    unordered_map<int, int> pageMap;
    int pageFaults = 0;

    for (int page : pages) {
        Output(pageMap);
        if (pageMap.find(page) == pageMap.end()) {
            if (pageMap.size() == capacity) {
                int maxFrequency = 0;
                int mostFrequencyPage = -1;
                for (auto &it : pageMap) {
                    if (maxFrequency < it.second) {
                        maxFrequency = it.second; 
                        mostFrequencyPage = it.first;
                    }
                }
                pageMap.erase(mostFrequencyPage);
                cout << "Page " << mostFrequencyPage << " replaced by page " << page << endl;
            }
            pageFaults++;
            cout << "Page " << page << " loaded into memory" << endl;
        }else{
            cout << "Page " << page << " existed in memory" << endl;
        }
        pageMap[page]++;
    }
    Output(pageMap);

    cout << "MFU: Total page faults = " << pageFaults << endl;
}

int main() {
    // vector<int> pages = {1, 2, 1, 2, 1, 4, 5, 2, 2, 3, 4, 5};
    vector<int> pages = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3};
    int capacity = 3;

    CountingMFU(pages, capacity);

    return 0;
}
