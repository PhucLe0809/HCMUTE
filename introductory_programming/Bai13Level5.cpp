#include <bits/stdc++.h>

using namespace std;
void input(int &n, int &x);
double scan(int n, int x);
void output(double out);

int main()
{
    int x, y;
    input(x, y);
    double answer = scan(x, y);
    output(answer);
    return 0;
}
void input(int &n, int &x)
{
    cin >> n >> x;
}
double scan(int n, int x)
{
    double answer;
    if (n == 0) answer = 1;
    else if (n == 1) answer = 1 + x;
    else
    {
        double answer = 1.0 + x;
        double down = 1.0;
        for (int i = 2; i <= n; i++)
        {
            x *= x; down *= i;
            answer += (x*1.0/down);
        }
    }
    return answer;
}
void output(double out)
{
    cout << setprecision(9) << fixed << out;
}
