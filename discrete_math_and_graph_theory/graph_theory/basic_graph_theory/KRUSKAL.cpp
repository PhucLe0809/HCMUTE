#include <bits/stdc++.h>
#define X first
#define Y second
#define maxarray 100005

using namespace std;
int32_t par[maxarray];
typedef
    pair <int32_t, int32_t> two;
typedef
    pair <int32_t, two> three;
vector <three> edges;

int32_t anc (int32_t u) //ancesters
{
    if (par[u] == u)
        return u;
    return par[u] = anc(par[u]);
}

void join (int32_t u, int32_t v)
{
    par[anc(u)] = anc(v);
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    int32_t n, m, s;
    finp >> n >> m >> s;
    for (int i = 0; i <= n; i++)
        par[i] = i;
    int32_t u, v, w;
    for (int i = 0; i < m; i++)
    {
        finp >> u >> v >> w;
        edges.push_back(three(w, two(u, v)));
    }
    sort(edges.begin(), edges.end());
    int32_t sum = 0;
    vector <three> :: iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
        if (anc(it -> Y.X) != anc(it -> Y.Y))
        {
            fout << it -> Y.X << " " << it -> Y.Y << '\n';
            join(it -> Y.X, it -> Y.Y);
            sum += it -> X;
        }
    fout << sum;
    finp.close();
    fout.close();
    return 0;
}
