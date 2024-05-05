#include <bits/stdc++.h>

using namespace std;
void input(long long &x, long long &y);
long long scan(long long x, long long y);
void output(long long out);

int main()
{
    long long a, b;
    input(a, b);
    long long answer = scan(a, b);
    output(answer);
    return 0;
}
void input(long long &x, long long &y)
{
    cin >> x >> y;
}
long long scan(long long x, long long y)
{
    if (y == 0)
        return x;
    else scan(y, x%y);
}
void output(long long out)
{
    cout << out;
}
