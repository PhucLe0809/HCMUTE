#include <bits/stdc++.h>
#define limn 1005

using namespace std;
int32_t n, m, u, v;
int32_t num[limn + 1];
bool answer;
bool connect[limn], inp[limn][limn];

void Hamilton (int32_t u)
{
    int32_t v;
    for (v = 2; v <= n; v++)
        if ((connect[v] == false) && (inp[num[u-1]][v]))
        {
            num[u] = v;
            if (u == n)
            {
                if (inp[v][1])
                    answer = true;
                return ;
            }
            else
            {
                connect[v] = true;
                Hamilton(u + 1);
                if (answer)
                    return ;
                connect[v] = false;
            }
        }
}

int main()
{
    ifstream finp ("GRAPH.INP");
    ofstream fout ("GRAPH.OUT");
    finp >> n >> m;
    memset(inp, false, sizeof inp);
    memset(num, -1, sizeof num);
    memset(connect, false, sizeof connect);
    for (int i = 1; i <= m; i++)
    {
        finp >> u >> v;
        inp[u][v] = inp[v][u] = true;
    }
    num[1] = 1;
    connect[1] = true;
    answer = false;
    Hamilton(2);
    num[n+1] = 1;
    for (int i = 1; i <= n + 1; i++)
        fout << num[i] << " ";
    finp.close();
    fout.close();
    return 0;
}
