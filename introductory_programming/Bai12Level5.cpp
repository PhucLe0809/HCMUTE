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
    double up = 0.0, down = 1.0;
    double answer = 0;
    for (int i = 1; i <= x; i++)
    {
        up += i; down *= i;
        answer += (up*(1.0)/down);
    }
    return answer;
}
void output(double out)
{
    cout << setprecision(9) << fixed << out;
}
