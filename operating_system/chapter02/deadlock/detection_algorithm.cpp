#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX
#define vecone vector<int>
#define vectwo vector<vecone>
#define endl '\n'

using namespace std;
ifstream finp("detection.inp");
ofstream fout("detection.out");
int n, m, q, col_width = 4;
vecone instances, available;
vectwo allocation, request, record;
struct query{
    int id;
    vecone para;
};
vector<query> que;
vector<string> header = {"ALLOCATION", "REQUEST", "AVAILABLE", "RECORD"};

void input(){
    finp >> n >> m;
    instances.resize(m);
    for (auto &it:instances) finp >> it;

    allocation.resize(n, vecone(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            finp >> allocation[i][j];
        }
    }
    request.resize(n, vecone(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            finp >> request[i][j];
        }
    }

    finp >> q;
    que.resize(q);
    for (int i = 0; i < q; i++){
        finp >> que[i].id;
        que[i].para.resize(m);
        for (auto &it:que[i].para) finp >> it;
    }

    record.resize(n, vecone(m));
}
void pretreatment(){
    available.resize(m);
    for (int j = 0; j < m; j++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += allocation[i][j];
        }
        available[j] = instances[j] - sum;
    }
}

void print_datatable(vectwo &all, vectwo &req, vecone &ava, vectwo &rec){
    fout << endl;
    for (auto &it:header){
        fout << setw(col_width) << left << " ";
        fout << setw(col_width * m) << left << it;
    }
    fout << endl;
    fout << setw(col_width) << left << " ";
    for (int i = 0; i < (int)header.size(); i++){
        for (int j = 0; j < m; j++){
            fout << setw(col_width) << left << (char)('A' + j);
        }
        fout << setw(col_width) << left << "|";
    }
    fout << endl;

    for (int i = 0; i < n; i++){
        fout << "P";
        fout << setw(col_width - 1) << left << i;
        for (int j = 0; j < m; j++){
            fout << setw(col_width) << left << all[i][j];
        }
        fout << setw(col_width) << left << "|";
        for (int j = 0; j < m; j++){
            fout << setw(col_width) << left << req[i][j];
        }
        fout << setw(col_width) << left << "|";

        if (i == 0){
            for (int j = 0; j < m; j++){
                fout << setw(col_width) << left << ava[j];
            }
        }else{
            for (int j = 0; j < m; j++){
                fout << setw(col_width) << left << " ";
            }
        }
        fout << setw(col_width) << left << "|";
        
        for (int j = 0; j < m; j++){
            fout << setw(col_width) << left << rec[i][j];
        }
        fout << setw(col_width) << left << "|";
        fout << endl;
    }
    fout << endl;
}
void print_request(query &re, vecone &perform, bool flag){
    fout << "# Query for P" << re.id << " ";
    fout << "(";
    for (int i = 0; i < m; i++){
        fout << re.para[i];
        if (i != m - 1) fout << ", ";
    }
    fout << ") : ";

    if (!flag){
        fout << "Request cannot be executed\n";
        return;
    }
    int len = perform.size();
    for (int i = 0; i < len; i++){
        fout << "P" << perform[i];
        if (i != len - 1) fout << " --> ";
    }
    fout << endl;
}

bool check_perform(int &id, vecone &ava, vectwo &req){
    for (int j = 0; j < m; j++){
        if (req[id][j] > ava[j]){
            return false;
        }
    }
    return true;
}
void free_up_resources(int &id, vecone &ava, vectwo &all){
    for (int j = 0; j < m; j++){
        ava[j] += all[id][j];
    }
}
vecone detection_algorithm(vectwo &all, vectwo &req, vecone &ava, vectwo &rec){
    int id = 0, cnt = 0;
    vecone perform;
    vecone executed(n);
    while ((int)perform.size() != n){
        if (executed[id]){
            id++; id %= n;
            continue;
        }
        if (check_perform(id, ava, req)){
            free_up_resources(id, ava, all);
            executed[id] = 1;
            perform.push_back(id);
            for (int j = 0; j < m; j++) rec[id][j] = ava[j];
            cnt = (id != n-1) ? (cnt + 1) : (0);
        }else{
            if (id == n-1 && cnt == 0){
                return vecone();
            }
        }
        if (id == n-1) cnt = 0;
        id++; id %= n;
    }
    return perform;
}
void update_datatable(vectwo &all, vectwo &req, vecone &ava, query &re){
    int id = re.id;
    vecone para = re.para;
    for (int j = 0; j < m; j++){
        req[id][j] += para[j];
    }
}
bool check_request(query &re){
    return true;
}
void rep_request(query &re){
    if (!check_request(re)){
        vecone temp;
        print_request(re, temp, false);
        return;
    }
    vectwo all = allocation;
    vectwo req = request;
    vecone ava = available;
    vectwo rec = record;
    update_datatable(all, req, ava, re);
    vecone tmp = ava;
    auto it = detection_algorithm(all, req, ava, rec);    
    print_datatable(all, req, tmp, rec);
    print_request(re, it, !it.empty());
}
void write_line(){
    for (int i = 0; i <= col_width * (m + 1) * 4; i++) fout << "-";
    fout << endl;
}
void __close(){
    finp.close();
    fout.close();
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    input();
    pretreatment();

    // print_datatable(allocation, maximum, request, available);
    fout << "--- DETECTION ALGORITHM code by Le Hong Phuc ---" << endl;
    for (int j = 0; j < m; j++){
        fout << (char)('A' + j) << " (" << instances[j] << " instances)";
        if (j != m-1) fout << ", ";
    }
    fout << endl;
    for (auto &it:que){
        rep_request(it);
        write_line();
    }

    __close();    

    return 0;
}