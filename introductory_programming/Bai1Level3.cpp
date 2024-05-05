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
    return x*(x+1)/2;
}
void output(long long out)
{
    cout << out;
}
