#include <bits/stdc++.h>
#define maxarray 100005

using namespace std;
bool visited[maxarray];
vector <int32_t> inp[maxarray];

void DFS (int32_t u)
{
    visited[u] = true;
    for (auto x : inp[u])
        if (!visited[x]) DFS(x);
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t n, m, s, u, v;
    finp >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        finp >> u >> v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    fill(visited, visited+maxarray, false);
    DFS(s);
    for (int i = 1; i <= n; i++)
        if (visited[i]) fout << i << " ";
    finp.close();
    fout.close();
    return 0;
}
