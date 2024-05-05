#include <bits/stdc++.h>
#define maxarray 100005
#define inf 1e9

using namespace std;
int32_t n, m, s, num;
int32_t d[maxarray], infront[maxarray];
vector <int32_t> inp[maxarray], weight[maxarray];
pair <int32_t, int32_t> save[maxarray];
typedef
    pair <int32_t, int32_t> prim;

int32_t Prim (int32_t u)
{
    int32_t v, w, sum;
    prim tmp;
    priority_queue <prim> q;
    for (int i = 0; i <= n; i++)
    {
        d[i] = inf;
        infront[i] = 0;
    }
    q.push(prim(0, u));
    d[u] = 0;
    sum = num = 0;
    while (!q.empty())
    {
        tmp = q.top(); q.pop();
        u = tmp.second; w = -tmp.first;
        if (w != d[u])
            continue;
        sum += d[u];
        d[u] = 0;
        num++;
        save[num].first = infront[u];
        save[num].second = u;
        for (int i = 0; i < inp[u].size(); i++)
        {
            v = inp[u][i];
            if (d[v] > weight[u][i])
                {
                    d[v] = weight[u][i];
                    q.push(prim(-d[v], v));
                    infront[v] = u;
                }
        }
    }
    return sum;
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t u, v, w;
    finp >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        finp >> u >> v >> w;
        inp[u].push_back(v);
        inp[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
    int32_t answer = Prim(s);
    if (answer == 0)
        fout << -1;
    else
    {
        fout << answer << '\n';
        for (int i = 2; i <=  num; i++)
            fout << save[i].first << " " << save[i].second << '\n';
    }
    finp.close();
    fout.close();
    return 0;
}
