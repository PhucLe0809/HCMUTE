#include <bits/stdc++.h>

using namespace std;
void input(long long &x);
long long scan(long long x);
void output(long long out);

int main()
{
    long long n;
    input(n);
    long long answer = scan(n);
    output(answer);
    return 0;
}
void input(long long &x)
{
    cin >> x;
}
long long scan(long long x)
{
    long long out = 0;
    for (int i = 1; i <= x; i++) out += i*i;
    return out;
}
void output(long long out)
{
    cout << out;
}
