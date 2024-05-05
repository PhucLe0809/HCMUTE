#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

void Output(unordered_map<int, int>& pageMap){
    cout << "[ ";
    for (auto &it:pageMap) cout << it.first << ", ";
    cout << "] \n";
    cout << "------------------------------------------------\n";
}
void Optimal(const vector<int>& pages, const vector<int>& references, int capacity) {
    unordered_map<int, int> pageMap;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        Output(pageMap);
        if (pageMap.size() == capacity) {
            int farthest = pageMap.begin()->first;
            for (auto it = pageMap.begin(); it != pageMap.end(); ++it) {
                if (it->second == -1) {
                    farthest = it->first;
                    break;
                }
            }
            cout << "Page " << farthest << " has been moved " << endl;
            pageMap.erase(farthest);
        }
        if (pageMap.find(pages[i]) == pageMap.end()) {
            pageFaults++;
            if (pageMap.size() < capacity) {
                pageMap[pages[i]] = references[i];
            }
        }
        cout << "Page " << pages[i] << " loaded into memory" << endl;
    }
    Output(pageMap);

    cout << "Optimal: Total page faults = " << pageFaults << endl;
}

int main() {
    vector<int> pages = {1,  2, 3,  4,  1,  2, 5,  1, 2,  3,  4,  5};
    vector<int> refer = {1, -1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1};
    int capacity = 3;

    Optimal(pages, refer, capacity);

    return 0;
}
