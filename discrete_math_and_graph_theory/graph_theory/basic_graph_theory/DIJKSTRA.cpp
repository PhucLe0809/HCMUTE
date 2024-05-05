#include <bits/stdc++.h>
#define maxarray 100005
#define inf 1e9

using namespace std;
int32_t infront[maxarray];
vector <int32_t> path;
vector <int32_t> distan(maxarray, inf);
vector <pair<int32_t, int32_t>> inp[maxarray];

void Dijkstra (int32_t s)
{
    distan[s] = 0;
    priority_queue <pair<int32_t, int32_t>, vector <pair<int32_t, int32_t>>, greater<pair<int32_t, int32_t>>> que;
    //distance & vertice
    que.push({0, s});
    int32_t u, d, v, w;
    while (!que.empty())
    {
        pair <int32_t, int32_t> tmp = que.top(); que.pop();
        u = tmp.second; d = tmp.first;
        if (d > distan[u]) continue;
        //Relaxation
        for(auto it : inp[u])
        {
            v = it.first; w = it.second;
            if (distan[v] > distan[u] + w)
            {
                distan[v] = distan[u] + w;
                que.push({distan[v], v});
                infront[v] = u;
            }
        }
    }
    // if (distan[t] == inf)
    //     answer = -1;
    // else
    // {
    //     answer = distan[t];
    //     while (true)
    //     {
    //         path.push_back(t);
    //         if (t == s) break;
    //         t = infront[t];
    //     }
    //     reverse(path.begin(), path.end());
    // }
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t n, m, s, t, u, v, w;
    finp >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        finp >> u >> v >> w;
        inp[u].push_back({v, w});
        //inp[v].push_back({u, w});
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++) 
        if (distan[i] < inf) fout << distan[i] << " ";
        else fout << -1 << " ";
    finp.close();
    fout.close();
    return 0;
}


