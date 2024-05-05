#include <bits/stdc++.h>

using namespace std;
void input(int &x);
double scan(int x);
void output(double out);

int main()
{
    int n;
    input(n);
    double answer = scan(n);
    output(answer);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
double scan(int x)
{
    double answer = 0.0;
    double pivot = 1.0;
    for(int i = 1; i <= x; i++)
    { pivot *= i; answer += pivot;}
    return answer;
}
void output(double out)
{
    cout << setprecision(0) << fixed << out;
}
