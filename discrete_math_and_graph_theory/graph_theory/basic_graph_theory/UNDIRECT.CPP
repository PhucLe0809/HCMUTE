#include <bits/stdc++.h>
#define maxarray 100005

using namespace std; 
vector <int32_t> alone, hang, loop, element;
vector <int32_t> visited(maxarray, false);
vector <int32_t> degree(maxarray);
vector <vector<int32_t>> connect;
vector <set<int32_t>> multi(maxarray);
vector <map<int32_t, int32_t>> graph(maxarray);

void BFS(int32_t vertice){
    queue <int32_t> que;
    visited[vertice] = true;
    que.push(vertice);
    element.push_back(vertice);
    int32_t u;
    while (que.size()){
        u = que.front(); que.pop();
        for (auto it : graph[u])
            if (!visited[it.first]){
                visited[it.first] = true;
                que.push(it.first);
                element.push_back(it.first);
            }
    }
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
        graph[u][v]++;
        graph[v][u]++;
    }
    //Graph Traversal - BFS
    for (u = 1; u <= n; u++){
        if (!visited[u]){
            element.clear();
            BFS(u);
            connect.push_back(element);
        }
    }
    //Scan Graph
    int32_t cnt;
    int32_t multi_edges = 0;
    for (u = 1; u <= n; u++){
        cnt = 0;
        for (auto it : graph[u]){
            cnt += it.second;
            if (it.second>1){
                if (it.first!=u){
                    multi_edges++;
                    multi[min(u, it.first)].insert(max(u, it.first));
                } else {
                    loop.push_back(u);
                }
            }
        }
        degree[u] = cnt;
    }
    //Count Hanging Ver and Alone Ver
    for (u = 1; u <= n; u++){
        if (degree[u] == 1) hang.push_back(u);
        if (degree[u] == 0) alone.push_back(u);
    }
    //============================================================================
    //Print Connected Components
    fout << "= Connected components of the graph: " << connect.size() << '\n';
    for (int i = 0; i < connect.size(); i++){
        fout << "    Component " << i+1 << ": ";
        for (auto it : connect[i]) fout << it << " ";
        fout << '\n';
    }
    //Print Multiple Edges
    fout << "= Multiple edges of the graph: " << multi_edges/2 << '\n';
    for (u = 1; u <= n; u++){
        for (auto it : multi[u]) fout << "    " << u << " " << it << '\n';
    }
    //Print Hanging Vertices
    fout << "= Hanging vertices of the graph: " << hang.size() << '\n';
    fout << "    include: ";
    for (auto it : hang) fout << it << " ";
    fout << '\n';
    //Print Alone Vertices
    fout << "= Alone vertices of the graph: " << alone.size() << '\n';
    fout << "    include: ";
    for (auto it : alone) fout << it << " ";
    fout << '\n';
    //Print Vertices containing the loop
    fout << "= Vertices containing the loop: " << loop.size() << '\n';
    fout << "    include: ";
    for (auto it : loop) fout << it << " ";
    fout << '\n';
    //Print Degree of Veritces
    fout << "= Degree of vertices: \n";
    for (u = 1; u <= n; u++){
        fout << "    degree of " << u << ": " << degree[u] << '\n';
    }
    //============================================================================
    finp.close(); fout.close();
    return 0;
}