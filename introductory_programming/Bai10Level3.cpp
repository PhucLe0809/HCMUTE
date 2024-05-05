#include <bits/stdc++.h>

using namespace std;
void input(long long &x, long long &y, long long &m);
long long scan(long long x, long long y, long long m);
void output(long long out);

int main()
{
    long long a, b, n;
    input(a, b, n);
    long long answer = scan(a, b, n);
    output(answer);
    return 0;
}
void input(long long &x, long long &y, long long &m)
{
    cin >> x >> y >> m;
}
long long scan(long long x, long long y, long long m)
{
    long long out = 0;
    for (int i = 1; i <= m/x; i++)
        if (x*i % y != 0) out += (x*i);
    if (m % x == 0 && m % y != 0) out -= m;
    return out;
}
void output(long long out)
{
    cout << out;
}
