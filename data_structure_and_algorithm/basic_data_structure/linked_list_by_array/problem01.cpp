#include <bits/stdc++.h>
#define MAXSIZE 10000

using namespace std;

#pragma region TOTAL FUNCTION
void clearScreen() {
    system("cls");
}
void stopToRead() {
    cout << endl;
    cout << "Press Enter to continue." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
#pragma endregion

#pragma region STRUCT FOR NODE
struct PEOPLE {
    int id;
    string name;
    string address;
};
#pragma endregion

#pragma region LINKED LIST BY ARRAY
struct listArray {
    #pragma region INFORMATION
    int maxSize;
    int currentSize;
    PEOPLE *list;
    #pragma endregion

    #pragma region BASIC METHOD
    void maxSizeAdd() {
        maxSize += 1;
    }
    listArray(int size) {
        maxSize = size;
        currentSize = 0;
        list = new PEOPLE[MAXSIZE];
    } 
    bool isEmptyList() {
        return currentSize == 0;
    }
    bool isFullList() {
        return currentSize == MAXSIZE;
    }
    void addFirst(PEOPLE people) {
        if (isFullList()) {
            cout << "List is full" << endl;
            return;
        }
        for (int i = currentSize; i>0; i--) {
            list[i] = list[i-1];
        }
        list[0] = people;
        currentSize++;
    }
    void addLast(PEOPLE people) {
        if (isFullList()) {
            cout << "List is full." << endl;
            return;           
        }
        list[currentSize] = people;
        currentSize++;
    }
    void removeFirst() {
        if (isEmptyList()) {
            cout << "List is empty" << endl;
            return;
        }
        for (int i = 0; i < currentSize - 1; i++) {
            list[i] = list[i + 1];
        }
        currentSize--;
    }
    void removeLast() {
        if (isEmptyList()) {
            cout << "List is empty" << endl;
            return;
        }
        currentSize--;
    }
    int search(string name) {
        for (int i = 0; i < currentSize; i++) {
            if (list[i].name == name) {
                return i;
            }
        }
        return -1;  
    }
    void printList() {
        if (isEmptyList()) {
            cout << "List is empty" << endl;
            return;
        } 
        cout << endl;
        cout << "----- Print List -----" << endl;
        for (int i = 0; i < currentSize; i++) {
            cout << "Name: " << list[i].name << endl;
            cout << "ID: " << list[i].id << endl;
            cout << "Country: " << list[i].address << endl;
            cout << endl;
        }      
    }
    #pragma endregion

    #pragma region SORT METHOD
    void selectionSort() {
        for (int i = 0; i < currentSize - 1; i++) {
            int min = i;
            for (int j = i + 1; j < currentSize; j++) {
                if (list[j].id < list[min].id) {
                    min = j;
                }
            }
            swap(list[i], list[min]);
        }
    }
    void quickSort( int l, int r) {
        int i = l, j = r;
        int pivot = list[(l+r) / 2].id;
        while (i <= j) {
            while (list[i].id < pivot) i++;
            while (list[j].id > pivot) j--;
            if (i <= j) {
                swap(list[i],list[j]);
                i++;
                j--;
            }
        }
        if (l<j) quickSort(l,j);
        if (i<r) quickSort(i,r);
    }
    void bubbleSort() {
        int i = 0;
        while (i<currentSize-2) {
            for (int j = currentSize-1; j > i; j--) {
                if (list[j-1].id > list[j].id)
                    swap(list[j],list[j-1]);  
            }
            i++;
            
        }
    }
    void insertionSort() {
        int pos = 1;
        int tmp;
        while (pos < currentSize) {
            tmp = pos;
            for (int i = pos - 1; i >= 0; i--) {
                if (list[i].id > list[tmp].id) {
                    swap(list[i], list[tmp]);
                    tmp = i;
                }
            }
            pos++;
        }
    }
    void quickSort() {
        quickSort(0, currentSize - 1);
    }
    #pragma endregion

    #pragma region OUTPUT INFORMATION
    void removeAllName(string& name) {
        int tmp = 0;
        int res = search(name);
        while (res != -1) {
            for (int i = res; i < currentSize - 1; i++) {
                list[i] = list[i + 1];
            }
            currentSize--;
            tmp++;
            res = search(name);
        }
        if (tmp == 0) cout << "There is no " << name << " information in the list" << endl;
         else cout << "Deleted all information name " << name << " from this list" << endl;
    }
    #pragma endregion
};
#pragma endregion

#pragma region INTERACT
void intro() {
    cout << "-------------------------------------- List People -----------------------------------" << endl;
    cout << "| 1. Check for empty list.                                                           |" << endl;
    cout << "| 2. Insert an element at the beginning of the list.                                 |" << endl;
    cout << "| 3. Insert an element at the end of the list.                                       |" << endl;
    cout << "| 4. Remove an element from the beginning of the list.                               |" << endl;
    cout << "| 5. Remove an element at the end of the list.                                       |" << endl;
    cout << "| 6. Find an element in the list with a name.                                        |" << endl;
    cout << "| 7. Check if the list is full.                                                      |" << endl;
    cout << "| 8. Selection Sort.                                                                 |" << endl;
    cout << "| 9. Quick Sort.                                                                     |" << endl;
    cout << "| 10. Bubble Sort.                                                                   |" << endl;
    cout << "| 11. Insertion Sort.                                                                |" << endl;
    cout << "| 12. Delete all elements with the same name.                                        |" << endl;
    cout << "| 13. Print list.                                                                    |" << endl;                                                                   
    cout << "| 14. Exit.                                                                          |" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "Your choice: ";
}
bool isNumber(string str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
void start() {
    ifstream ip("DanhSach.INP");
    if (ip.fail()) {
        cout << "Can not open file!!";
        exit(1);
    }
    int intValue;
    if (ip >> intValue) {   
    }
    else {
        cout << "The input data is incorrect, please check the file";
        exit(1);
    }
    listArray myList(intValue);
    int n = intValue;
    for (int i = 0; i<n; i++) {
        PEOPLE person;
        if (ip >> intValue) {
            person.id = intValue;
        }
        else {
            cout << "The input data is incorrect, please check the file";
            exit(1);
        }
        ip.ignore();
        getline(ip, person.name);
        getline(ip, person.address);
        myList.addFirst(person);
    }
    cout << "The data was loaded successfully" << endl;
    bool run = true;
    while (run) {
        bool tmp;
        PEOPLE person;
        int index;
        intro();
        string select;
        int choice = 0;
        do {
            if (cin >> select && isNumber(select))  {
                choice = stoi(select);
                if (choice < 1 || choice > 14) {
                    clearScreen();
                    cout << "Don't have that choice" << endl;
                    intro();
                }
            } else {
                cout << "The data entered is incorrect, please select again: ";
                choice = -1;
            }
        } while (choice < 1 || choice > 14);
        switch (choice) {
            case 1:
                tmp = myList.isEmptyList();
                if (tmp) cout << "This list is empty." << endl;
                else cout << "This list is not empty." << endl;
                stopToRead();
                break;
            case 2:
                cout << "Enter ID: ";
                do {
                    if (cin >> select && isNumber(select))  {
                        person.id = stoi(select);
                        break;
                    } else {
                        cout << "The data entered is incorrect, please select again: ";
                    }
                } while (true);
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, person.name);
                cout << "Enter country: " ;
                getline(cin, person.address);
                myList.addFirst(person);
                myList.printList();
                stopToRead();
                break;
            case 3:
                cout << "Enter ID: ";
                do {
                    if (cin >> select && isNumber(select))  {
                        person.id = stoi(select);
                        break;
                    } else {
                        cout << "The data entered is incorrect, please select again: ";
                    }
                } while (true);
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, person.name);
                cout << "Enter country: " ;
                getline(cin, person.address);
                myList.addLast(person);
                myList.printList();
                stopToRead();
                break;
            case 4:
                myList.removeFirst();
                myList.printList();
                stopToRead();
                break;
            case 5:
                myList.removeLast();
                myList.printList();
                stopToRead();
                break;
            case 6:
                cout << "Enter the name you need to find: ";
                cin.ignore();
                getline(cin, person.name);
                index = myList.search(person.name);
                if (index != -1) {
                    cout << "The name you are looking for is at position " << index << endl;
                }
                else cout << "The name you are looking for is not in the list." << endl;
                stopToRead();
                break;
            case 7:
                if (myList.isFullList()) cout << "List is full." << endl;
                else cout << "List is not full." << endl;
                stopToRead();
                break;
            case 8:
                myList.selectionSort();
                myList.printList();
                stopToRead();
                break;
            case 9:
                myList.quickSort();
                myList.printList();
                stopToRead();
                break;
            case 10:
                myList.bubbleSort();
                myList.printList();
                stopToRead();
                break;
            case 11:
                myList.insertionSort();
                myList.printList();
                stopToRead();
                break;
            case 12:
                cout << "Enter the name you need to delete: " ;
                cin.ignore();
                getline(cin, person.name);
                myList.removeAllName(person.name);
                myList.printList();
                stopToRead();
                break;
            case 13:
                myList.printList();
                stopToRead();
                break;
            default:
                run = false;
                break;

        }
        clearScreen();
    }
    ip.close();
}
#pragma endregion

int main(){
    start();
    return 0;
}