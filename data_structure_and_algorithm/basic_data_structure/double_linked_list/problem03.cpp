#include <bits/stdc++.h>

using namespace std;

#pragma region FILE FOR INTEGER LIST
ifstream fint("INTLIST.INP");
ifstream fintmenu("INTMENU.INP");
#pragma endregion
struct IntNode{
    #pragma region INFORMATION AND POINTER
    int data;
    IntNode *pre;
    IntNode *next;
    #pragma endregion

    #pragma region CONTRUCTOR AND DISTRUCTOR
    IntNode(){
        data = 0;
        pre = next = nullptr;
    }
    IntNode(int data){
        this->data = data;
        pre = next = nullptr;
    }
    ~IntNode(){}
    #pragma endregion

    #pragma region CHECK DATA
    bool can_parse_to_int(string &str){
        if (str.empty()){
            return false;
        }
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                if (i != 0) return false;
            }else{
                if (!('0' <= str[i] && str[i] <= '9')) return false;
            }
        }
        return true;
    }
    int string_to_int(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int(int &num){
        string str; cin >> str;
        num = string_to_int(str);
    }
    void to_positive(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num > 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_negative(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num < 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num == 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    int string_to_int_file(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
    }
    void to_positive_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num > 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_negative_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num < 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num == 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    #pragma endregion

    #pragma region METHOD FUNCTION
    void input_infor(){
        cout << "Enter value of element : ";
        to_int(this->data);
    }
    void output_infor(){
        cout << data;
    }
    bool comp_pair(IntNode *inter){
        return (this->data == inter->data);
    }
    bool comp_lower(IntNode *inter){
        return (this->data >= inter->data);
    }
    bool comp_upper(IntNode *inter){
        return (this->data > inter->data);
    }
    #pragma endregion
};
struct IntList{
    #pragma region INFORMATION
    IntNode *phead = nullptr;
    IntNode *ptail = nullptr;
    int cnt = 0;
    vector <string> menu_console;
    #pragma endregion

    #pragma region FUNCTION IN STRUCT
    // *** CONSOLE METHOD ***
    // void input_from_file(int n){}
    // void input_all_menu(){}
    // void print_menu(){}
    // void print_tutorial(){}
    // void scan_print_list(){} -> void scan_get_list_upper(){}
    // void once_process(){}
    // void multi_process(){}

    // *** CAPACITY FUNCTION ***
    // bool is_empty(){}
    // int size_list(){}

    // *** BASIC METHOD FUNCTION ***
    // void insert_front(IntNode *inter){}
    // void insert_back(IntNode *inter){}
    // void insert_between(IntNode *pos, IntNode *inter){}
    // void insert_less(IntNode *inter){}
    // void move_front(){}
    // void move_back(){}
    // void move_between(IntNode *pos){}
    // void move_value(IntNode *inter){}
    // IntNode* find_max(){}
    // IntNode* find_min(){}
    // IntNode* find_value(IntNode *inter){}
    // IntNode* find_lower(IntNode *inter){}
    // IntNode* find_upper(IntNode *inter){}
    // void selection_sort(){}
    // ---- IntNode* to_pointer(int &ind){};

    // *** EXTEND METHOD FUNCTION ***
    // vector<IntNode*> get_list_upper(IntNode *inter){}
    // vector<IntNode*> get_list_value(IntNode *inter){}
    // vector<IntNode*> get_list_max(){}
    // vector<IntNode*> get_list_min(){}
    // void erase_list_upper(IntNode *inter){}
    // int count_value(IntNode *inter){}
    // int count_negative(){}
    // int count_positive(){}
    // IntNode* find_greatest_negative(){}
    // IntNode* find_smallest_positive(){}
    // void quick_sort(){}

    // *** OUTPUT DATA ***
    // void print_list(){}
    #pragma endregion

    #pragma region CHECK DATA
    bool can_parse_to_int(string &str){
        if (str.empty()){
            return false;
        }
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                if (i != 0) return false;
            }else{
                if (!('0' <= str[i] && str[i] <= '9')) return false;
            }
        }
        return true;
    }
    int string_to_int(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int(int &num){
        string str; cin >> str;
        num = string_to_int(str);
    }
    void to_positive(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num > 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_negative(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num < 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num == 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    int string_to_int_file(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
    }
    void to_positive_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num > 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_negative_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num < 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num == 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    #pragma endregion

    #pragma region CONSOLE LIST
    void input_from_file(int n){
        int data;
        for (int i = 0; i < n; i++){
            to_int_file(fint, data);
            insert_back(new IntNode(data));
        }
    }
    void input_all_menu(){
        string str;
        while (getline(fintmenu, str)) menu_console.push_back(str);
    }
    void print_menu(){
        string topic = "*** MENU FOR INTEGER LIST ***";
        int width = (68 - topic.size())/2;
        for (int i = 0; i < width; i++) cout << "*";
        cout << topic;
        for (int i = 0; i <= width; i++) cout << "*";
        cout << '\n';
        for (int id = 0; id < menu_console.size(); id++){
            cout << left << setw(2) << "|";
            cout << left << setw(3) << id+1;
            cout << left << setw(2) << ":";
            cout << left << setw(60) << menu_console[id];
            cout << left << setw(2) << "|";
            cout << '\n';
        }
        for (int i = 0; i < 68; i++) cout << "*";
        cout << '\n';
        cout << "Your choose is : ";
    }
    #pragma region SCAN_
    void scan_print_list(){
        cout << "***Your list\n";
        print_list(); cout << '\n';
    }
    void scan_is_empty(){
        cout << "List ";
        if (is_empty()) cout << "is empty\n"; else cout << "isn't empty\n";
    }
    void scan_size_list(){
        cout << "The size of the list is " << size_list() << '\n';
    }
    void scan_insert_front(){
        IntNode *inter = new IntNode(); inter->input_infor();
        insert_front(inter);
    }
    void scan_insert_back(){
        IntNode *inter = new IntNode(); inter->input_infor();
        insert_back(inter);
    }
    void scan_insert_between(){
        cout << "You can use this method by index in list\n";
        int ind;
        cout << "Enter index of element : ";
        to_int(ind);
        if (ind < 0 || ind > cnt-1){
            cout << "Error: Your selection is not available!\n";
            return;
        }
        IntNode *inter = new IntNode(); inter->input_infor();
        IntNode *pointer = to_pointer(ind);
        if (pointer == nullptr) return;
        insert_between(pointer, inter);
    }
    void scan_insert_less(){
        IntNode *inter = new IntNode(); inter->input_infor();
        insert_less(inter);
    }
    void scan_move_front(){
        move_front();
    }
    void scan_move_back(){
        move_back();
    }
    void scan_move_between(){
        cout << "You can use this method by index in list\n";
        int ind;
        cout << "Enter index of element : ";
        to_int(ind);
        if (ind < 0 || ind > cnt-1){
            cout << "Error: Your selection is not available!\n";
            return;
        }
        IntNode *pointer = to_pointer(ind);
        if (pointer == nullptr) return;
        move_between(pointer);
    }
    void scan_move_value(){
        IntNode *inter = new IntNode(); inter->input_infor();
        move_value(inter);
    }
    void scan_find_max(){
        IntNode *node = new IntNode();
        node = find_max();
        if (node == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Maximum value is ";
            node->output_infor();
            cout << '\n';
        }
    }
    void scan_find_min(){
        IntNode *node = new IntNode();
        node = find_min();
        if (node == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Minimum value is ";
            node->output_infor();
            cout << '\n';
        }
    }
    void scan_find_value(){
        IntNode *inter = new IntNode(); inter->input_infor();
        IntNode *pointer = find_value(inter);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else cout << "Yes, this value appears in list\n";
    }
    void scan_find_lower(){
        IntNode *inter = new IntNode(); inter->input_infor();
        IntNode *pointer = find_lower(inter);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Yes, this value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_find_upper(){
        IntNode *inter = new IntNode(); inter->input_infor();
        IntNode *pointer = find_upper(inter);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Yes, this value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_sort_less(){
        selection_sort();
    }
    void scan_get_list_upper(){
        IntNode *inter = new IntNode(); inter->input_infor();
        vector <IntNode*> res = get_list_upper(inter);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << " ";
        }
        cout << '\n';
    }
    void scan_get_list_value(){
        IntNode *inter = new IntNode(); inter->input_infor();
        vector <IntNode*> res = get_list_value(inter);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << " ";
        }
        cout << '\n';
    }
    void scan_get_list_max(){
        vector <IntNode*> res = get_list_max();
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << " ";
        }
        cout << '\n';
    }
    void scan_get_list_min(){
        vector <IntNode*> res = get_list_min();
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << " ";
        }
        cout << '\n';
    }
    void scan_erase_list_upper(){
        IntNode *inter = new IntNode(); inter->input_infor();
        erase_list_upper(inter);
    }
    void scan_count_value(){
        IntNode *inter = new IntNode(); inter->input_infor();
        cout << "Result is " << count_value(inter) << '\n';
    }
    void scan_count_negative(){
        cout << "Result is " << count_negative() << '\n';
    }
    void scan_count_positive(){
        cout << "Result is " << count_positive() << '\n';
    }
    void scan_find_greatest_negative(){
        IntNode *pointer = find_greatest_negative();
        if (pointer == nullptr) cout << "Not found!!!\n";
        else cout << "The greatest negative value is " << pointer->data << '\n';
    }
    void scan_find_smallest_positive(){
        IntNode *pointer = find_smallest_positive();
        if (pointer == nullptr) cout << "Not found!!!\n";
        else cout << "The smallest positive value is " << pointer->data << '\n';
    }
    void scan_quick_sort(){
        quick_sort();
    }
    #pragma endregion
    void once_process(){
        int choose; print_menu(); cin >> choose;
        cout << "====================================================================\n";
        switch(choose){
            case 1: scan_print_list(); break;
            case 2: scan_is_empty(); break;
            case 3: scan_size_list(); break;
            case 4: scan_insert_front(); break;
            case 5: scan_insert_back(); break;
            case 6: scan_insert_between(); break;
            case 7: scan_insert_less(); break;
            case 8: scan_move_front(); break;
            case 9: scan_move_back(); break;
            case 10: scan_move_between(); break;
            case 11: scan_move_value(); break;
            case 12: scan_find_max(); break;
            case 13: scan_find_min(); break;
            case 14: scan_find_value(); break;
            case 15: scan_find_lower(); break;
            case 16: scan_find_upper(); break;
            case 17: scan_sort_less(); break;
            case 18: scan_get_list_upper(); break;
            case 19: scan_get_list_value(); break;
            case 20: scan_get_list_max(); break;
            case 21: scan_get_list_min(); break;
            case 22: scan_erase_list_upper(); break;
            case 23: scan_count_value(); break;
            case 24: scan_count_negative(); break;
            case 25: scan_count_positive(); break;
            case 26: scan_find_greatest_negative(); break;
            case 27: scan_find_smallest_positive(); break;
            case 28: scan_quick_sort(); break;
        }
    }
    void multi_process(){
        input_all_menu();
        string answer = "y";
        do{
            system("cls"); once_process(); 
            cout << "Enter to continue ...";
            cin.ignore(); string dummy; getline(cin, dummy);
            // cout << "====================================================================\n";
            // cout << "Do you want to continue? Enter \"y\" or \"n\"\n";
            // cout << "If you choose any other string it means \"NO\"\n";
            // cout << "Your answer is "; cin >> answer;
        } while (answer == "y");
    }
    #pragma endregion

    #pragma region CAPACITY FUNCTION
    // CAPACITY FUNCTION
    bool is_empty(){
        return (cnt == 0);
    }
    int size_list(){
        return cnt;
    }
    #pragma endregion

    #pragma region BASIC METHOD FUNCTION
    // METHOD FUNCTION
    void insert_front(IntNode *inter){
        if (phead == nullptr){
            phead = inter;
            ptail = inter;
        }else{
            inter->next = phead;
            phead = inter;
        }
        cnt++;
    }
    void insert_back(IntNode *inter){
        if (phead == nullptr){
            phead = inter;
            ptail = inter;
        }else{
            inter->pre = ptail;
            ptail->next = inter;
            ptail = inter;
        }
        cnt++;
    }
    void insert_between(IntNode *pos, IntNode *inter){
        if (pos == nullptr) return;
        if (pos == phead){
            insert_front(inter); return;
        }
        if (pos == ptail){
            insert_back(inter); return;
        }
        IntNode *infront = new IntNode();
        infront = pos->pre;
        infront->next = inter;
        inter->next = pos;
        cnt++;
    }
    void insert_less(IntNode *inter){
        IntNode *pos = find_lower(inter);
        if (pos == nullptr) return;
        insert_between(pos, inter);
    }
    void move_front(){
        if (phead == nullptr) return;
        phead = phead->next;
        cnt--;
    }
    void move_back(){
        if (phead == nullptr) return;
        ptail = ptail->pre;
        ptail->next = nullptr;
        cnt--;
    }
    void move_between(IntNode *pos){
        if (pos == nullptr) return;
        if (pos == phead){
            move_front(); return;
        }
        if (pos == ptail){
            move_back(); return;
        }
        IntNode *infront = pos->pre;
        IntNode *behind = pos->next;
        infront->next = behind;
        behind->pre = infront;
        cnt--;
    }
    void move_value(IntNode *inter){
        if (phead == nullptr) return;
        IntNode *pos = find_value(inter);
        if (pos != phead && pos != ptail){
            move_between(pos);
        }else{
            if (pos == phead) move_front();
            else move_back();
        }
    }
    IntNode* find_max(){
        if (phead == nullptr) return nullptr;
        IntNode *res = phead;
        IntNode *node = phead->next;
        while (node != nullptr){
            if (node->comp_upper(res)) res = node;
            node = node->next;
        }
        return res;
    }
    IntNode* find_min(){
        if (phead == nullptr) return nullptr;
        IntNode *res = phead;
        IntNode *node = phead->next;
        while (node != nullptr){
            if (res->comp_upper(node)) res = node;
            node = node->next;
        }
        return res;
    }
    IntNode* find_value(IntNode *inter){
        IntNode *pos = phead;
        while (pos != nullptr){
            if (pos->comp_pair(inter)) return pos;
            pos = pos->next;
        }
        return nullptr;
    }
    IntNode* find_lower(IntNode *inter){
        IntNode *pos = phead;
        while (pos != nullptr){
            if (pos->comp_lower(inter)) return pos;
            pos = pos->next;
        }
        return nullptr;
    }
    IntNode* find_upper(IntNode *inter){
        IntNode *pos = phead;
        while (pos != nullptr){
            if (pos->comp_upper(inter)) return pos;
            pos = pos->next;
        }
        return nullptr;
    }
    void selection_sort(){
        for (IntNode *infront = phead; infront != nullptr; infront = infront->next){
            for (IntNode *behind = infront->next; behind != nullptr; behind = behind->next){
                if (infront->data > behind->data){
                    swap(infront->data, behind->data);
                }
            }
        }
    }
    IntNode* to_pointer(int &ind){
        if (ind >= cnt) return nullptr;
        IntNode *pointer = phead; int run = 0;
        while (run < ind){
            pointer = pointer->next; run++;
        }
        return pointer;
    }
    #pragma endregion

    #pragma region EXTEND METHOD FUNCTION
    vector<IntNode*> get_list_upper(IntNode *inter){
        vector <IntNode*> res;
        IntNode *node = phead;
        while (node != nullptr){
            if (node->comp_upper(inter)) res.push_back(node);
            node = node->next;
        }
        return res;
    }
    vector<IntNode*> get_list_value(IntNode *inter){
        vector <IntNode*> res;
        IntNode *node = phead;
        while (node != nullptr){
            if (node->comp_pair(inter)) res.push_back(node);
            node = node->next;
        }
        return res;
    }
    vector<IntNode*> get_list_max(){
        IntNode *inter = find_max();
        if (inter == nullptr) return vector<IntNode*>(0);
        return get_list_value(inter);
    }
    vector<IntNode*> get_list_min(){
        IntNode *inter = find_min();
        if (inter == nullptr) return vector<IntNode*>(0);
        return get_list_value(inter);
    }
    void erase_list_upper(IntNode *inter){
        vector <IntNode*> res = get_list_upper(inter);
        for (auto &it:res) move_value(it);
    }
    int count_value(IntNode *inter){
        int res = 0;
        IntNode *node = phead;
        while (node != nullptr){
            if (node->comp_pair(inter)) res++;
            node = node->next;
        }
        return res;
    }
    int count_negative(){
        int res = 0;
        IntNode *node = phead;
        while (node != nullptr){
            if (node->data < 0) res++;
            node = node->next;
        }
        return res;
    }
    int count_positive(){
        int res = 0;
        IntNode *node = phead;
        while (node != nullptr){
            if (node->data > 0) res++;
            node = node->next;
        }
        return res;
    }
    IntNode* find_greatest_negative(){
        IntNode *res = new IntNode(INT_MIN);
        IntNode *node = phead;
        while (node != nullptr){
            if (node->data < 0 && node->comp_upper(res)) res = node;
            node = node->next;
        }
        if (res->data == INT_MIN) return nullptr;
        else return res;
    }
    IntNode* find_smallest_positive(){
        IntNode *res = new IntNode(INT_MAX);
        IntNode *node = phead;
        while (node != nullptr){
            if (node->data > 0 && res->comp_upper(node)) res = node;
            node = node->next;
        }
        if (res->data == INT_MAX) return nullptr;
        else return res;
    }
    void modify_quick(vector <IntNode> &scan, int l, int r){
        int i = l, j = r;
        int mid = l + r >> 1;
        while (i < j){
            while (scan[i].data < scan[mid].data) i++;
            while (scan[j].data > scan[mid].data) j--;
            if (i <= j){
                swap(scan[i], scan[j]);
                i++; j--;
            }
        }
        if (l < j) modify_quick(scan, l, j);
        if (i < r) modify_quick(scan, i, r);
    }
    void quick_sort(){
        vector <IntNode> scan;
        IntNode *pointer = phead;
        while (pointer != nullptr){
            scan.push_back(*pointer);
            pointer = pointer->next;
            move_front();
        }
        modify_quick(scan, 0, scan.size()-1);
        for (auto &it:scan) insert_back(new IntNode(it.data));
    }
    #pragma endregion

    #pragma region OUTPUT DATA
    // OUTPUT DATA
    void print_list(){
        IntNode *inter = phead;
        while (inter != nullptr){
            inter->output_infor();
            cout << " ";
            inter = inter->next;
        }
    }
    #pragma endregion
};

#pragma region FILE FOR CAR LIST
ifstream fcar("CARLIST.INP");
ifstream fcarmenu("CARMENU.INP");
#pragma endregion
struct CarNode{
    #pragma region INFORMATION AND POINTER
    struct Infor{
        string id;
        string vehicles;
        int year;
        int price;
    } data;
    CarNode *pre;
    CarNode *next;
    #pragma endregion

    #pragma region CONTRUCTOR AND DISTRUCTOR
    CarNode(){
        data.id = data.vehicles = "";
        data.year = 0; data.price = 0;
    }
    CarNode(string id, string vehicles, int year, int price){
        this->data.id = id;
        this->data.vehicles = vehicles;
        this->data.year = year;
        this->data.price = price;
        pre = next = nullptr;
    }
    ~CarNode(){}
    #pragma endregion

    #pragma region CHECK DATA
    bool can_parse_to_int(string &str){
        if (str.empty()){
            return false;
        }
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                if (i != 0) return false;
            }else{
                if (!('0' <= str[i] && str[i] <= '9')) return false;
            }
        }
        return true;
    }
    int string_to_int(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int(int &num){
        string str; cin >> str;
        num = string_to_int(str);
    }
    void to_positive(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num > 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_negative(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num < 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num == 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    int string_to_int_file(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
    }
    void to_positive_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num > 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_negative_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num < 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num == 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    #pragma endregion

    #pragma region METHOD FUNCTION
    void input_infor(){
        cout << "ID: "; cin.ignore(1); getline(cin, this->data.id);
        cout << "Vehicles: "; getline(cin, this->data.vehicles);
        cout << "Year of manufacture: "; to_positive(this->data.year);
        cout << "Price: "; to_positive(this->data.price);
    }
    void output_infor(){
        cout << "ID: " << data.id << '\n';
        cout << "Vehicles: " << data.vehicles << '\n';
        cout << "Year of manufacture: " << data.year << '\n';
        cout << "Price: " << data.price << "$" << '\n';
        cout << "--------------------------------------------------------------------";
    }
    bool comp_pair(CarNode *car){
        return (this->data.id == car->data.id && this->data.vehicles == car->data.vehicles
        && this->data.year == car->data.year && this->data.price == car->data.price);
    }
    bool comp_price(CarNode *car){
        return (this->data.price == car->data.price);
    }
    bool comp_lower_price(CarNode *car){
        return (this->data.price >= car->data.price);
    }
    bool comp_upper_price(CarNode *car){
        return (this->data.price > car->data.price);
    }
    #pragma endregion
};
struct CarList{
    #pragma region INFORMATION
    CarNode *phead = nullptr;
    CarNode *ptail = nullptr;
    int cnt = 0;
    vector <string> menu_console;
    #pragma endregion

    #pragma region FUNCTION IN STRUCT
    // *** CONSOLE METHOD ***
    // void input_from_file(int n){}
    // void input_all_menu(){}
    // void print_menu(){}
    // void print_tutorial(){}
    // void scan_print_list(){} -> void scan_16(){}
    // void once_process(){}
    // void multi_process(){}

    // *** CAPACITY FUNCTION ***
    // bool is_empty(){}
    // int size_list(){}

    // *** BASIC METHOD FUNCTION ***
    // void insert_front(CarNode *car){}
    // void insert_back(CarNode *car){}
    // void insert_between(CarNode *pos, CarNode *car){}
    // void move_front(){}
    // void move_back(){}
    // void move_between(CarNode *pos){}
    // void move_value(CarNode *car){}
    // CarNode* find_value(CarNode *car){}
    // void selection_sort_by_price(){}
    // ---- CarNode* to_pointer(int &ind){};

    // *** EXTEND METHOD FUNCTION ***
    // CarNode* find_lower_by_price(CarNode *car){}
    // CarNode* find_upper_by_price(CarNode *car){}
    // CarNode* find_max_by_price(){}
    // CarNode* find_min_by_price(){}
    // void insert_less_by_price(CarNode *car){}
    // vector<CarNode*> get_list_value_by_price(CarNode *car){}
    // vector<CarNode*> get_list_lower_by_price(CarNode *car){}
    // vector<CarNode*> get_list_upper_by_price(CarNode *car){}
    // vector<CarNode*> get_list_right(int kth){}
    // vector<CarNode*> get_list_left(int kth){}
    // void erase_list_upper_by_price(CarNode *car){}
    // void quick_sort_by_price(){}

    // *** OUTPUT DATA ***
    // void print_list(){}
    #pragma endregion

    #pragma region CHECK DATA
    bool can_parse_to_int(string &str){
        if (str.empty()){
            return false;
        }
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                if (i != 0) return false;
            }else{
                if (!('0' <= str[i] && str[i] <= '9')) return false;
            }
        }
        return true;
    }
    int string_to_int(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int(int &num){
        string str; cin >> str;
        num = string_to_int(str);
    }
    void to_positive(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num > 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_negative(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num < 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num == 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    int string_to_int_file(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
    }
    void to_positive_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num > 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_negative_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num < 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num == 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    #pragma endregion

    #pragma region CONSOLE LIST
    void input_from_file(int n){
        string id, vehicles; int year; int price;
        for (int i = 0; i < n; i++){
            fcar.ignore(1); getline(fcar, id);
            getline(fcar, vehicles);
            to_positive_file(fcar, year);
            to_positive_file(fcar, price);
            insert_back(new CarNode(id, vehicles, year, price));
        }
    }
    void input_all_menu(){
        string str;
        while (getline(fcarmenu, str)) menu_console.push_back(str);
    }
    void print_menu(){
        string topic = "*** MENU FOR CAR LIST ***";
        int width = (68 - topic.size())/2;
        for (int i = 0; i < width; i++) cout << "*";
        cout << topic;
        for (int i = 0; i <= width; i++) cout << "*";
        cout << '\n';
        for (int id = 0; id < menu_console.size(); id++){
            cout << left << setw(2) << "|";
            cout << left << setw(3) << id+1;
            cout << left << setw(2) << ":";
            cout << left << setw(60) << menu_console[id];
            cout << left << setw(2) << "|";
            cout << '\n';
        }
        for (int i = 0; i < 68; i++) cout << "*";
        cout << '\n';
        cout << "Your choose is : ";
    }
    #pragma region SCAN_
    void scan_print_list(){
        cout << "***Your list\n";
        print_list(); cout << '\n';
    }
    void scan_is_empty(){
        cout << "List ";
        if (is_empty()) cout << "is empty\n"; else cout << "isn't empty\n";
    }
    void scan_size_list(){
        cout << "The size of the list is " << size_list() << '\n';
    }
    void scan_insert_front(){
        CarNode *car = new CarNode(); car->input_infor();
        insert_front(car);
    }
    void scan_insert_back(){
        CarNode *car = new CarNode(); car->input_infor();
        insert_back(car);
    }
    void scan_insert_between(){
        cout << "You can use this method by index in list\n";
        int ind;
        cout << "Enter index of element : ";
        to_int(ind);
        if (ind < 0 || ind > cnt-1){
            cout << "Error: Your selection is not available!\n";
            return;
        }
        CarNode *car = new CarNode(); car->input_infor();
        CarNode *pointer = to_pointer(ind);
        if (pointer == nullptr) return;
        insert_between(pointer, car);
    }
    void scan_move_front(){
        move_front();
    }
    void scan_move_back(){
        move_back();
    }
    void scan_move_between(){
        cout << "You can use this method by index in list\n";
        int ind;
        cout << "Enter index of element : ";
        to_int(ind);
        if (ind < 0 || ind > cnt-1){
            cout << "Error: Your selection is not available!\n";
            return;
        }
        CarNode *pointer = to_pointer(ind);
        if (pointer == nullptr) return;
        move_between(pointer);
    }
    void scan_move_value(){
        CarNode *car = new CarNode(); car->input_infor();
        move_value(car);
    }
    void scan_find_value(){
        CarNode *car = new CarNode(); car->input_infor();
        CarNode *pointer = find_value(car);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else cout << "Yes, this value appears in list\n";
    }
    void scan_sort_less_by_price(){
        sort_less_by_price();
    }
    void scan_find_lower_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        CarNode *pointer = find_lower_by_price(car);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Yes, this value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_find_upper_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        CarNode *pointer = find_upper_by_price(car);
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Yes, this value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_find_max_by_price(){
        CarNode *pointer = find_max_by_price();
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Maximum value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_find_min_by_price(){
        CarNode *pointer = find_min_by_price();
        if (pointer == nullptr) cout << "Not found!!!\n";
        else{
            cout << "Minimum value is "; 
            pointer->output_infor();
            cout << '\n';
        }
    }
    void scan_insert_less_by_price(){
        CarNode *car = new CarNode(); car->input_infor();
        insert_less_by_price(car);
    }
    void scan_get_list_value_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        vector <CarNode*> res = get_list_value_by_price(car);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << "\n";
        }
    }
    void scan_get_list_lower_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        vector <CarNode*> res = get_list_lower_by_price(car);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << "\n";
        }
    }
    void scan_get_list_upper_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        vector <CarNode*> res = get_list_lower_by_price(car);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << "\n";
        }
    }
    void scan_get_list_right(){
        int kth;
        cout << "The number of elements is "; cin >> kth;
        vector <CarNode*> res = get_list_right(kth);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << "\n";
        }
    }
    void scan_get_list_left(){
        int kth;
        cout << "The number of elements is "; cin >> kth;
        vector <CarNode*> res = get_list_left(kth);
        if (res.empty()){
            cout << "Get failed!!!\n";
            return;
        }
        for (auto &it:res){
            it->output_infor(); cout << "\n";
        }
    }
    void scan_erase_list_upper_by_price(){
        int price; 
        cout << "The value of Price is "; cin >> price;
        CarNode *car = new CarNode("", "", 0, price);
        erase_list_upper_by_price(car);
    }
    void scan_quick_sort_by_price(){
        quick_sort_by_price();
    }
    #pragma endregion
    void once_process(){
        int choose; print_menu(); cin >> choose;
        cout << "====================================================================\n";
        switch(choose){
            case 1: scan_print_list(); break;
            case 2: scan_is_empty(); break;
            case 3: scan_size_list(); break;
            case 4: scan_insert_front(); break;
            case 5: scan_insert_back(); break;
            case 6: scan_insert_between(); break;
            case 7: scan_move_front(); break;
            case 8: scan_move_back(); break;
            case 9: scan_move_between(); break;
            case 10: scan_move_value(); break;
            case 11: scan_find_value(); break;
            case 12: scan_sort_less_by_price(); break;
            case 13: scan_find_lower_by_price(); break;
            case 14: scan_find_upper_by_price(); break;
            case 15: scan_find_max_by_price(); break;
            case 16: scan_find_min_by_price(); break;
            case 17: scan_insert_less_by_price(); break;
            case 18: scan_get_list_value_by_price(); break;
            case 19: scan_get_list_lower_by_price(); break;
            case 20: scan_get_list_upper_by_price(); break;
            case 21: scan_get_list_right(); break;
            case 22: scan_get_list_left(); break;
            case 23: scan_erase_list_upper_by_price(); break;
            case 24: scan_quick_sort_by_price(); break;
        }
    }
    void multi_process(){
        input_all_menu();
        string answer = "y";
        do{
            system("cls"); once_process(); 
            cout << "Enter to continue ...";
            cin.ignore(); string dummy; getline(cin, dummy);
            // cout << "====================================================================\n";
            // cout << "Do you want to continue? Enter \"y\" or \"n\"\n";
            // cout << "If you choose any other string it means \"NO\"\n";
            // cout << "Your answer is "; cin >> answer;
        } while (answer == "y");
    }
    #pragma endregion

    #pragma region CAPACITY FUNCTION
    // CAPACITY FUNCTION
    bool is_empty(){
        return (cnt == 0);
    }
    int size_list(){
        return cnt;
    }
    #pragma endregion

    #pragma region BASIC METHOD FUNCTION
    // METHOD FUNCTION
    void insert_front(CarNode *car){
        if (phead == nullptr){
            phead = car;
            ptail = car;
        }else{
            car->next = phead;
            phead = car;
        }
        cnt++;
    }
    void insert_back(CarNode *car){
        if (phead == nullptr){
            phead = car;
            ptail = car;
        }else{
            car->pre = ptail;
            ptail->next = car;
            ptail = car;
        }
        cnt++;
    }
    void insert_between(CarNode *pos, CarNode *car){
        if (pos == nullptr) return;
        if (pos == phead){
            insert_front(car); return;
        }
        if (pos == ptail){
            insert_back(car); return;
        }
        CarNode *infront = new CarNode();
        infront = pos->pre;
        infront->next = car;
        car->next = pos;
        cnt++;
    }
    void move_front(){
        if (phead == nullptr) return;
        phead = phead->next;
        cnt--;
    }
    void move_back(){
        if (phead == nullptr) return;
        ptail = ptail->pre;
        ptail->next = nullptr;
        cnt--;
    }
    void move_between(CarNode *pos){
        if (pos == nullptr) return;
        if (pos == phead){
            move_front(); return;
        }
        if (pos == ptail){
            move_back(); return;
        }
        CarNode *infront = pos->pre;
        CarNode *behind = pos->next;
        infront->next = behind;
        behind->pre = infront;
        cnt--;
    }
    void move_value(CarNode *car){
        if (phead == nullptr) return;
        CarNode *pos = find_value(car);
        if (pos != phead && pos != ptail){
            move_between(pos);
        }else{
            if (pos == phead) move_front();
            else move_back();
        }
    }
    CarNode* find_value(CarNode *car){
        CarNode *node = phead;
        while (node != nullptr){
            if (node->comp_pair(car)) return node;
            node = node->next;
        }
        return nullptr;
    }
    void sort_less_by_price(){
        for (CarNode *infront = phead; infront != nullptr; infront = infront->next){
            for (CarNode *behind = infront->next; behind != nullptr; behind = behind->next){
                if (infront->data.price > behind->data.price){
                    swap(infront->data, behind->data);
                }
            }
        }
    }
    CarNode* to_pointer(int &ind){
        if (ind >= cnt) return nullptr;
        CarNode *pointer = phead; int run = 0;
        while (run < ind){
            pointer = pointer->next; run++;
        }
        return pointer;
    }
    #pragma endregion

    #pragma region EXTEND METHOD FUNCTION
    CarNode* find_lower_by_price(CarNode *car){
        CarNode *pos = phead;
        while (pos != nullptr){
            if (pos->comp_lower_price(car)) return pos;
            pos = pos->next;
        }
        return nullptr;
    }
    CarNode* find_upper_by_price(CarNode *car){
        CarNode *pos = phead;
        while (pos != nullptr){
            if (pos->comp_upper_price(car)) return pos;
            pos = pos->next;
        }
        return nullptr;
    }
    CarNode* find_max_by_price(){
        if (phead == nullptr) return nullptr;
        CarNode *res = phead;
        CarNode *node = phead->next;
        while (node != nullptr){
            if (node->comp_upper_price(res)) res = node;
            node = node->next;
        }
        return res;
    }
    CarNode* find_min_by_price(){
        if (phead == nullptr) return nullptr;
        CarNode *res = phead;
        CarNode *node = phead->next;
        while (node != nullptr){
            if (res->comp_upper_price(node)) res = node;
            node = node->next;
        }
        return res;
    }
    void insert_less_by_price(CarNode *car){
        CarNode *pos = find_lower_by_price(car);
        if (pos == nullptr) return;
        insert_between(pos, car);
    }
    vector<CarNode*> get_list_value_by_price(CarNode *car){
        vector <CarNode*> res;
        CarNode *node = phead;
        while (node != nullptr){
            if (node->comp_price(car)) res.push_back(node);
            node = node->next;
        }
        return res;
    }
    vector<CarNode*> get_list_lower_by_price(CarNode *car){
        vector <CarNode*> res;
        CarNode *node = phead;
        while (node != nullptr){
            if (node->comp_lower_price(car)) res.push_back(node);
            node = node->next;
        }
        return res;
    }
    vector<CarNode*> get_list_upper_by_price(CarNode *car){
        vector <CarNode*> res;
        CarNode *node = phead;
        while (node != nullptr){
            if (node->comp_upper_price(car)) res.push_back(node);
            node = node->next;
        }
        return res;
    }
    vector<CarNode*> get_list_right(int kth){
        if (cnt < kth) return vector<CarNode*>(0);
        vector <CarNode*> res;
        CarNode *node = ptail;
        while (node != nullptr && kth != 0){
            res.push_back(node);
            node = node->pre; kth--;
        }
        return res;
    }
    vector<CarNode*> get_list_left(int kth){
        if (cnt < kth) return vector<CarNode*>(0);
        vector <CarNode*> res;
        CarNode *node = phead;
        while (node != nullptr && kth != 0){
            res.push_back(node);
            node = node->next; kth--;
        }
        return res;
    }
    void erase_list_upper_by_price(CarNode *car){
        vector <CarNode*> res = get_list_upper_by_price(car);
        for (auto &it:res) move_value(it);
    }
    void modify_quick_by_price(vector <CarNode> &scan, int l, int r){
        int i = l, j = r;
        int mid = l + r >> 1;
        while (i < j){
            while (scan[i].data.price < scan[mid].data.price) i++;
            while (scan[j].data.price > scan[mid].data.price) j--;
            if (i <= j){
                swap(scan[i], scan[j]);
                i++; j--;
            }
        }
        if (l < j) modify_quick_by_price(scan, l, j);
        if (i < r) modify_quick_by_price(scan, i, r);
    }
    void quick_sort_by_price(){
        vector <CarNode> scan;
        CarNode *pointer = phead;
        while (pointer != nullptr){
            scan.push_back(*pointer);
            pointer = pointer->next;
            move_front();
        }
        modify_quick_by_price(scan, 0, scan.size()-1);
        for (auto &it:scan) insert_back(new CarNode(it.data.id, it.data.vehicles, it.data.year, it.data.price));
    }
    #pragma endregion

    #pragma region OUTPUT DATA
    // OUTPUT DATA
    void print_list(){
        CarNode *car = phead;
        while (car != nullptr){
            car->output_infor();
            cout << "\n";
            car = car->next;
        }
    }
    #pragma endregion
};

#pragma region FILE FOR INTERACT LIST
ifstream fmenu("MENU.INP");
#pragma endregion
struct Interact{
    #pragma region INFORMATION
    vector <string> menu_console;
    #pragma endregion

    #pragma region CHECK DATA
    bool can_parse_to_int(string &str){
        if (str.empty()){
            return false;
        }
        for (int i = 0; i < str.size(); i++){
            if (str[i] == '-'){
                if (i != 0) return false;
            }else{
                if (!('0' <= str[i] && str[i] <= '9')) return false;
            }
        }
        return true;
    }
    int string_to_int(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int(int &num){
        string str; cin >> str;
        num = string_to_int(str);
    }
    void to_positive(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num > 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_negative(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num < 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num == 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero(int &num){
        string str; cin >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type not available!" << '\n';
            exit(0);
        }
    }
    int string_to_int_file(string &str){
        if (!can_parse_to_int(str)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
        int result;
        istringstream iss(str);
        iss >> result;
        return result;
    }
    void to_int_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
    }
    void to_positive_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num > 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_negative_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num < 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int_file(str);
        if (!(num == 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_lower_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num >= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    void to_smaller_zero_file(ifstream &finp, int &num){
        string str; finp >> str;
        num = string_to_int(str);
        if (!(num <= 0)){
            cerr << "Error: Data type in file INPUT not available!" << '\n';
            exit(0);
        }
    }
    #pragma endregion

    #pragma region INIT FUNCTION
    void input_all_menu(){
        if (fmenu.fail()){
            cout << "Can not open menu file!!!";
            exit(0);
        }
        string str;
        while (getline(fmenu, str)) menu_console.push_back(str);
    }
    void print_menu(){
        string topic = "*** MENU FOR INTERACT LIST ***";
        int width = (68 - topic.size())/2;
        for (int i = 0; i < width; i++) cout << "*";
        cout << topic;
        for (int i = 0; i < width; i++) cout << "*";
        cout << '\n';
        for (int id = 0; id < menu_console.size(); id++){
            cout << left << setw(2) << "|";
            cout << left << setw(3) << id+1;
            cout << left << setw(2) << ":";
            cout << left << setw(60) << menu_console[id];
            cout << left << setw(2) << "|";
            cout << '\n';
        }
        for (int i = 0; i < 68; i++) cout << "*";
        cout << '\n';
        cout << "Your choose is : ";
    }
    #pragma endregion

    #pragma region INTERACT FUNCTION
    void scan_int_list(){
        if (fint.fail()){
            cout << "Can not open data file!!!";
            exit(0);
        }
        if (fintmenu.fail()){
            cout << "Can not open menu file!!!";
            exit(0);
        }
        int n; to_lower_zero_file(fint, n);
        IntList interact;
        interact.input_from_file(n);
        interact.multi_process();
    }
    void scan_stu_list(){
        if (fcar.fail()){
            cout << "Can not open data file!!!";
            exit(0);
        }
        if (fcarmenu.fail()){
            cout << "Can not open menu file!!!";
            exit(0);
        }
        int n; to_lower_zero_file(fcar, n);
        CarList interact;
        interact.input_from_file(n);
        interact.multi_process();
    }
    void once_process(){
        int choose; print_menu(); to_int(choose);
        if (choose < 1 || choose > 2){
            cout << "Error: Your selection is not available!\n";
            return;
        }
        cout << "====================================================================\n";
        switch(choose){
            case 1: scan_int_list(); break;
            case 2: scan_stu_list(); break;
        }
    }
    void multi_process(){
        input_all_menu();
        string answer = "";
        do{
            system("cls"); once_process(); 
            cout << "Enter to continue ...";
            cin.ignore(); string dummy; getline(cin, dummy);
            // cout << "Do you want to continue? Enter \"y\" or \"n\"\n";
            // cout << "If you choose any other string it means \"NO\"\n";
            // cout << "Your answer is "; 
            // cin >> answer;
        } while (answer != " ");
    }
    #pragma endregion 

    #pragma region THE END
    void close_all_file(){
        fint.close();
        fcar.close();
        fmenu.close();
        fintmenu.close();
        fcarmenu.close();
    }
    #pragma endregion
};

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    Interact interact; 
    interact.multi_process();
    interact.close_all_file();
    return 0;
}