#include <bits/stdc++.h>

using namespace std;
void input(int &n, int &k);
double scan(int n, int k);
void output(double out);

int main()
{
    int x, y;
    input(x, y);
    double answer = scan(x, y);
    output(answer);
    return 0;
}
void input(int &n, int &k)
{
    cin >> n >> k;
}
double scan(int n, int k)
{
    double up = 1.0, down = 1.0;
    for (int i = n; i >= n-k+1; i--) up *= i;
    for (int i = 1; i <= k; i++) down *= i;
    double answer = up/down;
    return answer;
}
void output(double out)
{
    cout << setprecision(0) << fixed << out;
}
