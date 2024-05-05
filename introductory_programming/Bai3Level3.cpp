#include <bits/stdc++.h>

using namespace std;
void input(long long &x);
double scan(long long x);
void output(double out);

int main()
{
    long long n;
    input(n);
    double answer = scan(n);
    output(answer);
    return 0;
}
void input(long long &x)
{
    cin >> x;
}
double scan(long long x)
{
    double out = 0;
    for (int i = 1; i <= x; i++) out += ((1.0)/i);
    return out;
}
void output(double out)
{
    cout << setprecision(9) << fixed << out;
}
