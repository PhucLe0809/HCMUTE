#include <bits/stdc++.h>
#define limn 100005
#define limm 100005

using namespace std;
int32_t n, m, i, j;
int32_t deg[limn], link[2*limm], head[limn];
bool deleted[2*limm];
vector <int32_t> save;
struct arcs
{
    int32_t x, y;
    int32_t edges;
} inp[2*limm];

void EulerCircuit (int32_t vertices)
{
    int32_t u, e;
    stack <int32_t> sta;
    sta.push(vertices);
    do
    {
        u = sta.top();
        e = head[u];
        while ((e != 0) && (deleted[inp[e].edges]))
            e = link[e];
        head[u] = e;
        if (e != 0)
        {
            sta.push(inp[e].x);
            deleted[inp[e].edges] = true;
        }
        else
        {
            save.push_back(u);
            sta.pop();
        }
    }
    while (!sta.empty());
}

int32_t main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    finp >> n >> m;
    memset(deg, 0, sizeof deg);
    memset(link, 0, sizeof link);
    memset(head, 0, sizeof head);
    memset(deleted, false, sizeof deleted);
    j = 2*m;
    int32_t u, v;
    for (i = 1; i <= m; i++)
    {
        finp >> u >> v;
        deg[u]++; deg[v]++;
        inp[i].x = u; inp[i].y = v; inp[i].edges = i;
        inp[j].x = v; inp[j].y = u; inp[j].edges = i;
        j--;
    }
    for (u = 1; (u <= n) && (deg[u] % 2 == 0); u++);
    if (u <= n)
        fout << -1;
    else
    {
        for (j = 2*m; j >= 1; j--)
        {
            link[j] = head[inp[j].y];
            head[inp[j].y] = j;
        }
        EulerCircuit(1);
        for (i = 0; i < save.size(); i++)
            fout << save[i] << " ";
    }
    finp.close();
    fout.close();
    return 0;
}
