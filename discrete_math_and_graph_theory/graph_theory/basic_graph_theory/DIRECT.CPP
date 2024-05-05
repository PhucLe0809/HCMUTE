#include <bits/stdc++.h>
#define maxarray 100005

using namespace std; 
set <int32_t> loop;
vector <int32_t> deg_in(maxarray), deg_out(maxarray);
vector <vector<int32_t>> multi_same(maxarray), multi_oppsite(maxarray);
vector <map<int32_t, int32_t>> input(maxarray), output(maxarray);

bool comp (pair <int32_t, int32_t> a, pair <int32_t, int32_t> b){
    return a.first > b.first;
    //mean: !(comp(a, b)) && !(comp(b, a))
}

int main() 
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t n, m;
    finp >> n >> m;
    int32_t u, v;
    for (int i = 0; i < m; i++){
        finp >> u >> v;
        input[u][v]++;
        output[v][u]++;
    }
    //Scan Graph
    int32_t forward, rever;
    int32_t multi_edges_same = 0;
    int32_t multi_edges_oppsite = 0;
    for (u = 1; u <= n; u++){
        forward = 0;
        for (auto it : input[u]){
            forward += it.second;
            if (it.second > 1){
                multi_same[u].push_back(it.first);
                multi_edges_same++;
            }
            if (it.first == u) loop.insert(u);
        }
        deg_out[u] = forward;
        rever = 0;
        for (auto it : output[u]){
            rever += it.second;
            if (!output[it.first].empty()
            && binary_search(output[it.first].begin(), output[it.first].end(), pair <int32_t, int32_t> (u, 0), comp)){
                multi_oppsite[u].push_back(it.first);
                multi_edges_oppsite++;
            }
            if (it.first == u) loop.insert(u);
        }
        deg_in[u] = rever;
    }
    //============================================================================
    //Print Parallel same direction edges of the graph
    fout << "= Parallel same direction edges of the graph: " << multi_edges_same << '\n';
    for (u = 1; u <= n; u++){
        for (auto it : multi_same[u]) fout << "    " << u << " " << it << '\n';
    }
    //Print Parallel oppsite direction edges of the graph
    fout << "= Parallel oppsite direction edges of the graph: " << multi_edges_oppsite << '\n';
    for (u = 1; u <= n; u++){
        for (auto it : multi_oppsite[u]) fout << "    " << u << " " << it << '\n';
    }
    //Print Vertices containing the loop
    fout << "= Vertices containing the loop: " << loop.size() << '\n';
    fout << "    include: ";
    for (auto it : loop) fout << it << " ";
    fout << '\n';
    //Print Degree input
    fout << "= Degree input: \n";
    for (u = 1; u <= n; u++){
        fout << "    degree input of " << u << ": " << deg_in[u] << '\n';
    }
    //Print Degree output
    fout << "= Degree output: \n";
    for (u = 1; u <= n; u++){
        fout << "    degree output of " << u << ": " << deg_out[u] << '\n';
    }
    //============================================================================
    finp.close(); fout.close();
    return 0;
}