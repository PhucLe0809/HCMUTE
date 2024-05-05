#include <bits/stdc++.h>
#define maxarray 100005

using namespace std;
int32_t numSCC;
bool visited[maxarray];
vector <int32_t> inp[maxarray], reserve[maxarray], save[maxarray];
vector <int32_t> :: iterator it;
stack <int32_t> sta;

void reset (bool visited[], bool arrayvalue, int32_t start, int32_t thend)
{
    for (int32_t i = start; i <= thend; i++)
        visited[i] = arrayvalue;
}

void Finishing (int32_t v, vector <int32_t> inp[], stack <int32_t> &sta)
{
    int32_t i;
    visited[v] = true;
    for (int i = 0; i < inp[v].size(); i++)
        if (visited[inp[v][i]] == false)
            {
                Finishing(inp[v][i], inp, sta);
            }
    sta.push(v);
}

void DFS (int32_t u)
{
    int32_t i;
    visited[u] = true;
    save[numSCC].push_back(u);
    for (i = 0; i < reserve[u].size(); i++)
        if (visited[reserve[u][i]] == false)
            DFS(reserve[u][i]);
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
        reserve[v].push_back(u);
    }
    reset(visited, false, 0, n);
    for (u = 1; u <= n; u++)
        if (visited[u] == false)
            Finishing(u, inp, sta);
    reset(visited, false, 0, n);
    numSCC = 0;
    while (!sta.empty())
    {
        u = sta.top(); sta.pop();
        if (visited[u] == false)
        {
            numSCC++;
            DFS(u);
        }
    }
    fout << numSCC << '\n';
    for (int i = 1; i <= numSCC; i++)
    {
        for (it = save[i].begin(); it != save[i].end(); it++)
            fout << *it << " ";
        fout << '\n';
    }
    finp.close();
    fout.close();
    return 0;
}
