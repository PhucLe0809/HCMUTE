#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void Output(unordered_set<int>& pageSet){
    cout << "[ ";
    for (auto &it:pageSet) cout << it << ", ";
    cout << "] \n";
    cout << "------------------------------------------------\n";
}
void FIFO(const vector<int>& pages, int capacity) {
    queue<int> pageQueue;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int page : pages) {
        Output(pageSet);
        if (pageSet.find(page) == pageSet.end()) { // Page not in memory
            if (pageQueue.size() == capacity) {    // Memory full
                int replacedPage = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(replacedPage);
                cout << "Page " << replacedPage << " has been moved " << endl;
            }
            pageQueue.push(page);
            pageSet.insert(page);
            pageFaults++;
            cout << "Page " << page << " loaded into memory" << endl;
        }else{
            cout << "Page " << page << " existed in memory" << endl;
        }
    }
    Output(pageSet);

    cout << "FIFO: Total page faults = " << pageFaults << endl;
}

int main() {
    // vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    vector<int> pages = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3};
    int capacity = 3;

    FIFO(pages, capacity);

    return 0;
}
