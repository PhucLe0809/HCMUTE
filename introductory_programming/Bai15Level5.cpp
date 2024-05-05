#include <bits/stdc++.h>

using namespace std;
void input(int &n, double &x);
double scan(int n, double x);
void output(double out);

int main()
{
    int x; double y;
    input(x, y);
    double answer = scan(x, y);
    output(answer);
    return 0;
}
void input(int &n, double &x)
{
    cin >> n >> x;
}
double scan(int n, double x)
{
    double answer = sqrt(x);
    for (int i = 2; i <= n; i++) answer = sqrt(x + answer);
    return answer;
}
void output(double out)
{
    cout << setprecision(9) << fixed << out;
}
