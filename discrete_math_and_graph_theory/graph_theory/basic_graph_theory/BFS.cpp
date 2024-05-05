#include <bits/stdc++.h>
#define maxarray 100005

using namespace std;
bool visited[maxarray];
vector <int32_t> inp[maxarray];

void BFS (int32_t u)
{
    int32_t v;
    queue <int32_t> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        v = q.front(); q.pop();
        for (auto x : inp[v])
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
    }
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
    BFS(s);
    for (int i = 1; i <= n; i++)
        if (visited[i]) fout << i << " ";
    finp.close();
    fout.close();
    return 0;
}
