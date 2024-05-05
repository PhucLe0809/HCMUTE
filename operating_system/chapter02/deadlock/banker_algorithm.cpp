#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX
#define vecone vector<int>
#define vectwo vector<vecone>
#define endl '\n'

using namespace std;
ifstream finp("banker.inp");
ofstream fout("banker.out");
int n, m, q, col_width = 4;
vecone instances, available;
vectwo allocation, maximum, need, record;
struct query{
    int id;
    vecone para;
};
vector<query> request;
vector<string> header = {"ALLOCATION", "MAX", "NEED", "AVAILABLE", "RECORD"};

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
    maximum.resize(n, vecone(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            finp >> maximum[i][j];
        }
    }

    finp >> q;
    request.resize(q);
    for (int i = 0; i < q; i++){
        finp >> request[i].id;
        request[i].para.resize(m);
        for (auto &it:request[i].para) finp >> it;
    }

    record.resize(n, vecone(m));
}
void pretreatment(){    
    need.resize(n, vecone(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    available.resize(m);
    for (int j = 0; j < m; j++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += allocation[i][j];
        }
        available[j] = instances[j] - sum;
    }
}

void print_datatable(vectwo &all, vectwo &mam, vectwo &ned, vecone &ava, vectwo &rec){
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
            fout << setw(col_width) << left << mam[i][j];
        }
        fout << setw(col_width) << left << "|";
        for (int j = 0; j < m; j++){
            fout << setw(col_width) << left << ned[i][j];
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
void print_request(query &req, vecone &perform, bool flag){
    fout << "# Request for P" << req.id << " ";
    fout << "(";
    for (int i = 0; i < m; i++){
        fout << req.para[i];
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

bool check_perform(int &id, vecone &ava, vectwo &ned){
    for (int j = 0; j < m; j++){
        if (ned[id][j] > ava[j]){
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
vecone banker_algorithm(vectwo &all, vectwo &mam, vectwo &ned, vecone &ava, vectwo &rec){
    int id = 0, cnt = 0;
    vecone perform;
    vecone executed(n);
    while ((int)perform.size() != n){
        if (executed[id]){
            id++; id %= n;
            continue;
        }
        if (check_perform(id, ava, ned)){
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
void update_datatable(vectwo &all, vectwo &mam, vectwo &ned, vecone &ava, query &req){
    int id = req.id;
    vecone para = req.para;
    for (int j = 0; j < m; j++){
        all[id][j] += para[j];
        ned[id][j] -= para[j];
        ava[j] -= para[j];
    }
}
bool check_request(query &req){
    int id = req.id;
    vecone para = req.para;
    for (int j = 0; j < m; j++){
        if (para[j] > need[id][j] || para[j] > available[j]){
            return false;
        }
    }
    return true;
}
void rep_request(query &req){
    if (!check_request(req)){
        vecone temp;
        print_request(req, temp, false);
        return;
    }
    vectwo all = allocation;
    vectwo mam = maximum;
    vectwo ned = need;
    vecone ava = available;
    vectwo rec = record;
    update_datatable(all, mam, ned, ava, req);
    vecone tmp = ava;
    auto it = banker_algorithm(all, mam, ned, ava, rec);    
    print_datatable(all, mam, ned, tmp, rec);
    print_request(req, it, !it.empty());
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

    // print_datatable(allocation, maximum, need, available);
    fout << "--- BANKER ALGORITHM code by Le Hong Phuc ---" << endl;
    for (int j = 0; j < m; j++){
        fout << (char)('A' + j) << " (" << instances[j] << " instances)";
        if (j != m-1) fout << ", ";
    }
    fout << endl;
    for (auto &it:request){
        rep_request(it);
        write_line();
    }

    __close();    

    return 0;
}