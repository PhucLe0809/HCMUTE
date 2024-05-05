#include <bits/stdc++.h>
#define oper_size 6 
#define bracket_size 2
#define maxclause 1025
#define maxrelation 105

using namespace std;
// INPUT AND OUTPUT =============================
ifstream finp ("LOGIC.INP");
ofstream fo_clause ("CLAUSE.OUT");
ofstream fo_relation ("RELATIONSHIP.OUT");
// LOGIC DATA STRUCTER ==========================
struct logic{ bool val[maxclause]; };
// RELATION DATA STRUCTURE ======================
struct relation{ bool val[maxrelation][maxrelation]; };
struct group{ int32_t val[maxrelation]; };
struct exitre{ pair <bool, vector <pair<int32_t, int32_t>>> val; };
// FOR CLAUSE: TOTAL AND LOCAL ==================
void initi(string &str);
bool is_word(char &key);
bool is_oper(char &key);
bool is_bracket(char &key);
bool is_clause(string &str);
logic convert_logic(char &key);
logic __and(logic &a, logic &b);
logic __or(logic &a, logic &b);
logic __but(logic &a, logic &b);
logic __negative(logic &a);
logic __oneway(logic &a, logic &b);
logic __twoway(logic &a, logic &b);
void scan_clause(string &str);
void CLAUSE(int32_t &n);
// FOR RELATIONSHIP: TOTAL AND LOCAL ============
exitre is_reflex(relation &a, group &inp, int32_t &sz);
exitre is_symmetry(relation &a, group &inp, int32_t &sz);
exitre is_bridge(relation &a, vector <vector<int32_t>> &graph, int32_t &sz);
exitre is_contrarian(relation &a, vector <vector<int32_t>> &graph, int32_t &sz);
void scan_relation(relation &a, group &inp, vector <vector<int32_t>> &graph, int32_t &sz);
void RELATIONSHIP(int32_t m);
// INITIALIZATION FOR CLAUSE ====================
char oper[9] = {'&', '|', '/', '*', '-', '='};
char bracket[3] = {'(', ')'};
int32_t value_size;
map <char, int32_t> inturn;
void initi(string &str){
    set <char> st; int32_t stsize;
    for (auto &x : str){
        if (x >= 'a' && x <= 'z'){
            stsize = st.size();
            st.insert(x);
            if (st.size() > stsize) inturn[x]++;
        }
    }
    stsize = value_size = pow(2, st.size());
    for (auto &it : inturn){
        stsize /= 2; it.second = stsize;
    }
}

// CHECK FUNCTION FOR CLAUSE ====================
bool is_word(char &key){
    if (key >= 'a' && key <= 'z') 
        return true; else return false;
}
bool is_oper(char &key){
    for (int i = 0; i < oper_size; i++) 
        if (key == oper[i]) return true;
    return false;
}
bool is_bracket(char &key){
    for (int i = 0; i < bracket_size; i++) 
        if (key == bracket[i]) return true;
    return false;
}
bool is_clause(string &str){
    int32_t cnt = 0; bool check = true;
    for (int i = 0; i < str.size() && check; i++)
    {
        if (str[i] == '(') cnt--;
        else if (str[i] == ')') cnt++;
        if (cnt > 0) check = false;
    }
    if (!cnt && check) return true;
    else return false;
}

// CONVERT FUNCTION FOR CLAUSE ==================
logic convert_logic(char &key){
    logic c; int32_t i, j;
    i = 0;
    while (i < value_size)
    {
        for (j = 0; j < inturn[key]; j++, i++) c.val[i] = true;
        for (j = 0; j < inturn[key]; j++, i++) c.val[i] = false;
    }
    return c;
}

// CALCULATE FUNCTION FOR CLAUSE ================
logic __and(logic &a, logic &b){
    logic c;
    for (int i = 0; i < value_size; i++){
        if (a.val[i] && b.val[i]) c.val[i] = true;
        else c.val[i] = false;
    }
    return c;
}
logic __or(logic &a, logic &b){
    logic c;
    for (int i = 0; i < value_size; i++){
        if (!a.val[i] && !b.val[i]) c.val[i] = false;
        else c.val[i] = true;
    }
    return c;
}
logic __but(logic &a, logic &b){
    logic c;
    for (int i = 0; i < value_size; i++){
        if ((a.val[i] && b.val[i])
        || (!a.val[i] && !b.val[i]))
            c.val[i] = false;
        else c.val[i] = true;
    }
    return c;
}
logic __negative(logic &a){
    logic c;
    for (int i = 0; i < value_size; i++){
        if (a.val[i]) c.val[i]= false;
        else c.val[i] = true;
    }
    return c;
}
logic __oneway(logic &a, logic &b){
    logic c;
    for (int i = 0; i < value_size; i++){
        if (a.val[i] && !b.val[i]) c.val[i] = false;
        else c.val[i] = true;
    }
    return c;
}
logic __twoway(logic &a, logic &b){
    logic c;
    for (int i = 0; i < value_size; i++){
        if ((a.val[i] && b.val[i])
        || (!a.val[i] && !b.val[i]))
            c.val[i] = true;
        else c.val[i] = false;
    }
    return c;
}

// SCAN CLAUSE ==================================
void scan_clause(string &str){
    //=== CONVERT INFIX TO POSTFIX ===
    char key;
    stack <char> infix;
    vector <char> postfix;
    for (int i = 0; i < str.size(); i++){
        if (is_word(str[i])){
            postfix.push_back(str[i]);
        } else {
            if (str[i] != ')') infix.push(str[i]);
            else{
                if (!infix.empty()){
                    key = infix.top(); infix.pop();
                    while (is_oper(key)){
                        postfix.push_back(key);
                        if (infix.empty()) break;
                        { key = infix.top(); infix.pop(); }
                    }
                }
            }
        }
    }
    while (!infix.empty()){
        key = infix.top(); infix.pop();
        if (key != '(') postfix.push_back(key);
    }

    //=== PRINT POSTFIX ===
    // fo_clause << "POSTFIX : ";
    // for (auto &x : postfix) fo_clause << x << " "; fo_clause << "\n";
    
    //=== CALCULATE POSTFIX EXPRESSION ===
    stack <pair<string, logic>> calculate;
    vector <pair<string, logic>> truth;
    pair <string, logic> tmp, x, y; 
    logic sub; string name;
    for (auto &it : postfix){
        if (is_word(it)){
            sub = convert_logic(it);
            name = it;
            calculate.push({name, sub});
            truth.push_back({name, sub});
        }
        else 
        {
            if (it == oper[3]){
                tmp = calculate.top(); calculate.pop();
                sub = __negative(tmp.second);
                if (tmp.first.size() == 1){ 
                    name = it; name += tmp.first; 
                }
                else{
                    name = it; name += '('; 
                    name += tmp.first; name += ')';
                }
                calculate.push({name, sub});
                truth.push_back({name, sub});
            }
            else{
                x = calculate.top(); calculate.pop();
                y = calculate.top(); calculate.pop();
                if (it == oper[0]) sub = __and(y.second, x.second);
                if (it == oper[1]) sub = __or(y.second, x.second);
                if (it == oper[2]) sub = __but(y.second, x.second);
                if (it == oper[4]) sub = __oneway(y.second, x.second);
                if (it == oper[5]) sub = __twoway(y.second, x.second);
                if (y.first.size() == 1){
                    name = y.first;
                }
                else{
                    name = '('; name += y.first; name += ')';
                }
                name += it; 
                if (x.first.size() == 1){
                    name += x.first;
                }
                else{
                    name += '('; name += x.first; name += ')';
                }
                calculate.push({name, sub});
                truth.push_back({name, sub});
            }
        }
    }
    
    //=== PRINT TRUTH TABLE ===
    set <string> st; int32_t st_size;
    vector <pair<string, logic>> table;
    vector <pair<string, logic>> :: iterator it;
    for (it = truth.begin(); it != truth.end(); it++){
        st_size = st.size(); 
        st.insert(it->first);
        if (st_size != st.size()) 
            table.push_back({it->first, it->second});
    }
    fo_clause << '\n';
    fo_clause << "=== TRUTH TABLE ===\n";
    for (it = table.begin(); it != table.end(); it++)
        if ((it->first).size() == 1){
            sub = it->second;
            for (int i = 0; i < value_size; i++)
                fo_clause << sub.val[i] << " ";
            fo_clause << ": " << it->first << '\n'; 
        }
    for (it = table.begin(); it != table.end(); it++)
        if ((it->first).size() != 1){
            sub = it->second;
            for (int i = 0; i < value_size; i++)
                fo_clause << sub.val[i] << " ";
            fo_clause << ": " << it->first << '\n'; 
        }
    
    //=== PRINT STEP BY STEP ===
    fo_clause << '\n';
    fo_clause << "=== STEP BY STEP ===\n";
    for (it = truth.begin(); it != truth.end(); it++){
        sub = it->second;
        for (int i = 0; i < value_size; i++)
            fo_clause << sub.val[i] << " ";
        fo_clause << ": " << it->first << '\n';
    }
    //=== PRINT RESULT ===
    tmp = calculate.top(); 
    fo_clause << '\n';
    fo_clause << "STANDARDIZED : " << tmp.first << '\n';
    sub = tmp.second;
    int32_t tr, fl; tr = fl = 0;
    for (int i = 0; i < value_size; i++)
        if (sub.val[i]) tr++; else fl++;
    fo_clause << "RESULT : ";
    if (tr == value_size) fo_clause << "CONSTANT TRUE\n";
    else if (fl == value_size) fo_clause << "CONSTANT FALSE\n";
        else fo_clause << "IS BOTH TRUE AND FALSE\n";
}
// ======================================================================
exitre is_reflex(relation &a, group &inp, int32_t &sz){
    exitre out;
    bool check = true;
    vector <pair<int32_t, int32_t>> save;
    for (int i = 0; i < sz && check; i++){
        if (a.val[inp.val[i]][inp.val[i]]){
            save.push_back({inp.val[i], inp.val[i]});
        }else{
            check = false; save.clear();
        }
    }
    out.val.first = check;
    out.val.second = save;
    return out;
}
exitre is_symmetry(relation &a, group &inp, int32_t &sz){
    exitre out;
    bool check = true;
    vector <pair<int32_t, int32_t>> save;
    for (int i = 0; i < maxrelation && check; i++)
        for (int j = 0; j < maxrelation && check; j++){
            if (a.val[i][j]+a.val[j][i] == 2){
                save.push_back({i, j});
                save.push_back({j, i});
            }else if (a.val[i][j] || a.val[j][i]){
                check = false; save.clear();
            }
        }
    out.val.first = check;
    out.val.second = save;
    return out;
}
exitre is_bridge(relation &a, vector <vector<int32_t>> &graph, int32_t &sz){
    exitre out;
    vector <pair<int32_t, int32_t>> save;
    for (int u = 1; u <= sz; u++){
        for (auto x : graph[u]){
            for (auto y : graph[x]){
                if (a.val[u][y]){
                    save.push_back({u, x});
                    save.push_back({x, y});
                    save.push_back({u, y});
                }
            }
        }
    }
    out.val.first = (!save.empty());
    out.val.second = save;
    return out;
}
exitre is_contrarian(relation &a, vector <vector<int32_t>> &graph, int32_t &sz){
    exitre out;
    bool check = true;
    vector <pair<int32_t, int32_t>> save;
    for (int i = 0; i < maxrelation && check; i++)
        for (int j = 0; j < maxrelation && check; j++){
            if (a.val[i][j]+a.val[j][i] == 2){
                if (i == j) save.push_back({i, j});
                else{
                    check = false; save.clear();
                }
            }else{
                if (a.val[i][j]) save.push_back({i, j});
            }
        }
    out.val.first = check;
    out.val.second = save;
    return out;
}

void scan_relation(relation &a, group &inp, vector <vector<int32_t>> &graph, int32_t &sz){
    fo_relation << '\n';
    fo_relation << "RESULT : PROPERIES OF R\n";
    exitre result; int32_t inturn = 0;
    vector <pair<int32_t, int32_t>> out;
    // PRINT REFLEX =============================
    result = is_reflex(a, inp, sz); 
    if (!result.val.first){
        fo_relation << "= Not reflective!\n";
    }else{
        inturn++;
        fo_relation << "= Reflective: ";
        out = result.val.second;
        fo_relation << out.size()/1 << '\n'; 
        for (int i = 0; i < out.size(); i++){
            fo_relation << "(" << out[i].first << "," << out[i].second << ")" << " ";
        }
        fo_relation << '\n';
    }
    // PRINT SYMMETRY ===========================
    result = is_symmetry(a, inp, sz); 
    if (!result.val.first){
        fo_relation << "= Unsymmetrical!\n";
    }else{
        fo_relation << "= Symmetrical: ";
        out = result.val.second;
        fo_relation << out.size()/2 << '\n';
        for (int i = 0; i < out.size(); i++){
            fo_relation << "(" << out[i].first << "," << out[i].second << ")" << " ";
            if ((i+1)%2==0) fo_relation << '\n';
        }
    }
    // PRINT BRIDGE =============================
    result = is_bridge(a, graph, sz); 
    if (!result.val.first){
        fo_relation << "= Not transitivel!\n";
    }else{
        inturn++;
        fo_relation << "= Transitive: ";
        out = result.val.second;
        fo_relation << out.size()/3 << '\n';
        for (int i = 0; i < out.size(); i++){
            fo_relation << "(" << out[i].first << "," << out[i].second << ")" << " ";
            if ((i+1)%3==0) fo_relation << '\n';
        }
    }
    // PRINT CONTRARIAN =========================
    result = is_contrarian(a, graph, sz); 
    if (!result.val.first){
        fo_relation << "= No antagonism!\n";
    }else{
        inturn++;
        fo_relation << "= Disproportionate: ";
        out = result.val.second;
        fo_relation << out.size()/1 << '\n';
        for (int i = 0; i < out.size(); i++){
            fo_relation << "(" << out[i].first << "," << out[i].second << ")" << " ";
        }
        fo_relation << '\n';
    }

    // CHECK TO BUILD HASSE GRAPH ===============
    fo_relation << '\n';
    fo_relation << "HASSE GRAPH : \n";
    if (inturn < 3) fo_relation << "R is not a orderly relationship on episode X\n";
    else
    {
        // BUILD HASSE GRAPH ========================
        for (int i = 0; i < maxrelation-1; i++){
            for (int j = 0; j < maxrelation-1; j++){
                if (i==j) a.val[i][j] = false;
                else{
                    if (a.val[i][j]){
                        for (int t = 0; t < maxrelation; t++)
                            if (a.val[j][t] && j!=t) a.val[i][t] = false;
                    }
                }
            }
        }
        vector <vector<int32_t>> hasse(maxrelation);
        for (int i = 0; i < maxrelation; i++)
            for (int j = 0; j < maxrelation; j++)
                if (a.val[i][j]) hasse[i].push_back(j);
        // GRAPH TRAVERSAL ==========================
        vector <int32_t> father(maxrelation, 0);
        vector <int32_t> children(maxrelation, 0);
        int32_t u, v;
        for (int i = 0; i < sz; i++)
        {
            vector <int32_t> visited(maxrelation, false);
            queue <int32_t> q;
            u = inp.val[i]; father[u]++; children[u]++;
            q.push(u); visited[u] = true;
            while (q.size()){
                v = q.front(); q.pop();
                for (auto x : hasse[v]){
                    if (!visited[x]){
                        q.push(x);
                        visited[x] = true;
                        father[u]++; children[x]++;
                    }
                }
            }
        }
        // ==========================================
        vector <int32_t> :: iterator it;
        int32_t re_large, re_small, cnt; 
        re_large = re_small = -1;
        // PRINT MAX ELEMENT ========================
        it = find(children.begin(), children.end(), sz);
        fo_relation << "The largest element: ";
        if (it != children.end()){
            re_large = it-children.begin();
            fo_relation << re_large << '\n';
        } else fo_relation << "does not exist!\n";
        // PRINT MIN ELEMENT ========================
        it = find(father.begin(), father.end(), sz);
        fo_relation << "The smallest element: ";
        if (it != father.end()){
            re_small = it-father.begin();
            fo_relation << re_small << '\n';
        } else fo_relation << "does not exist!\n";
        // PRINT relatively largest element =========
        if (re_large != -1){
            fo_relation << "The relatively largest element: " << re_large << '\n';
        }else{
            it = max_element(children.begin(), children.end());
            cnt = 0;
            fo_relation << "The relatively largest element: ";
            for (int i = 0; i < maxrelation; i++) 
                if (children[i] == *it){
                    cnt++; fo_relation << i << " ";
                }
            if (cnt == 0) fo_relation << "does not exist!\n";
            else fo_relation << '\n';
        }
        // PRINT relatively smallest element ========
        if (re_small != -1){
            fo_relation << "The relatively smallest element: " << re_small << '\n';
        }else{
            it = max_element(father.begin(), father.end());
            cnt = 0;
            fo_relation << "The relatively smallest element: ";
            for (int i = 0; i < maxrelation; i++) 
                if (father[i] == *it){
                    cnt++; fo_relation << i << " ";
                }
            if (cnt == 0) fo_relation << "does not exist!\n";
            else fo_relation << '\n';
        }
    }
}

// ======================================================================
void CLAUSE(int32_t &n)
{
    string inp;
    for (int i = 0; i < n; i++){
        finp >> inp;
        if (is_clause(inp))
        { initi(inp); scan_clause(inp); }
        else fo_clause << "INVALID BRACKETS!!!\n";
        fo_clause << "======================================================================\n";
    }
}
void RELATIONSHIP(int32_t m)
{
    int32_t s, t, u, v;
    group element;
    relation tick;
    vector <vector<int32_t>> graph(maxrelation);
    for (int i = 0; i < m; i++){
        finp >> s >> t; 
        for (int j = 0; j < s; j++) finp >> element.val[j];
        for (int j = 0; j < maxrelation; j++){
            fill(tick.val[j], tick.val[j]+maxrelation, false);
            graph[j].clear();
        }
        for (int j = 0; j < t; j++){
            finp >> u >> v;
            tick.val[u][v] = true;
            graph[u].push_back(v);
        } 
        scan_relation(tick, element, graph, s);
        fo_relation << "======================================================================\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int32_t n, m; finp >> n >> m;
    CLAUSE(n);
    RELATIONSHIP(m);
    finp.close(); 
    fo_clause.close();
    fo_relation.close();
    return 0;
}