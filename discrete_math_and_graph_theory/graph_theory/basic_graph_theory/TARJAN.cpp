#include <bits/stdc++.h>
#define maxarray 100005
#define inf 1e9

using namespace std;
int32_t cnt, numSCC;
int32_t num[maxarray], low[maxarray];
bool connect[maxarray];
vector <vector<int32_t>> inp(maxarray), save(maxarray);
stack <int32_t> sta;

void DFS (int32_t u)
{
    num[u] = low[u] = cnt++;
    connect[u] = true;
    sta.push(u);
    vector <int32_t> :: iterator it;
    for (it = inp[u].begin(); it != inp[u].end(); it++)
    {
        if (num[*it] == -1)
            DFS(*it);
        if (connect[*it])
            low[u] = min(low[u], low[*it]);
    }
    int32_t v;
    if (num[u] == low[u])
    {
        numSCC++;
        while (true)
        {
            v = sta.top(); sta.pop();
            connect[v] = false;
            save[numSCC].push_back(v);
            if (u == v)
                break;
        }
    }
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t n, m, u, v;
    finp >> n >> m;
    for (int i = 0; i < m; i++)
    {
        finp >> u >> v;
        inp[u].push_back(v);
    }
    fill(num, num + n+1, -1);
    fill(low, low + n+1, inf);
    fill(connect, connect + n+1, false);
    cnt = numSCC = 0;
    for (u = 1; u <= n; u++)
        if (num[u] == -1)
            DFS(u);
    fout << numSCC << '\n';
    for (int i = 1; i <= numSCC; i++)
    {
        for (auto it : save[i]) fout << it << " ";
        fout << '\n';
    }
    finp.close();
    fout.close();
    return 0;
}
