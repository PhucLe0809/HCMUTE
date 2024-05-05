#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

void Output(unordered_map<int, list<int>::iterator>& pageMap){
    cout << "[ ";
    for (auto &it:pageMap) cout << it.first << ", ";
    cout << "] \n";
    cout << "------------------------------------------------\n";
}
void LRU(const vector<int>& pages, int capacity) {
    list<int> pageList;
    unordered_map<int, list<int>::iterator> pageMap;
    int pageFaults = 0;

    for (int page : pages) {
        Output(pageMap);
        if (pageMap.find(page) == pageMap.end()) { // Page not in memory
            if (pageList.size() == capacity) {     // Memory full
                int replacedPage = pageList.front();
                pageList.pop_front();
                pageMap.erase(replacedPage);
                cout << "Page " << replacedPage << " replaced by page " << page << endl;
            }
            pageList.push_back(page);
            pageMap[page] = --pageList.end();
            pageFaults++;
            cout << "Page " << page << " loaded into memory" << endl;
        } else { // Page already in memory
            cout << "Page " << page << " already in memory" << endl;
            pageList.erase(pageMap[page]);
            pageList.push_back(page);
            pageMap[page] = --pageList.end();
        }
    }
    Output(pageMap);

    cout << "LRU: Total page faults = " << pageFaults << endl;
}

int main() {
    // vector<int> pages = {1, 2, 1, 3, 1, 4, 5, 1, 2, 3, 4, 5};
    vector<int> pages = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3};
    int capacity = 3;

    LRU(pages, capacity);

    return 0;
}
