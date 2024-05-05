#include <bits/stdc++.h>

using namespace std;
void input(int &a, int &b, int &c, int &d, int &e, int &f);
int check(int year);
int calculating(int day, int mon, int year, int pivot[]);
int scan(int a, int b, int c, int d, int e, int f);
void output(int out);

int main()
{
    int x, y, z, t, h, k;
    input(x, y, z, t, h, k);
    int answer = scan(x, y, z, t, h, k);
    output(answer);
    return 0;
}
void input(int &a, int &b, int &c, int &d, int &e, int &f)
{
    cin >> a >> b >> c >> d >> e >> f;
}
int check(int year)
{
    return ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0);
}
int calculating(int day, int mon, int year, int pivot[])
{
    int res = (mon > 2)?(check(year)):(0);
    int out = pivot[mon - 1] + day + res;
    return out;
}
int scan(int a, int b, int c, int d, int e, int f)
{
    int pivot[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 2; i <= 12; i++) pivot[i] = pivot[i-1] + pivot[i];
    bool test = true;
    if (c == f)
    {
        if (b == e)
        {
            if (a == d) {}
        } else if (b > e) test = false;
    } else if (c > f) test = false;
    int answer;
    if (c == f)
        answer = abs(calculating(d, e, f, pivot) - calculating(a, b, c, pivot));
    else if (test)
            answer = (365 + check(c) - calculating(a, b, c, pivot)) + calculating(d, e, f, pivot) + (f - c - 1)*365;
         else answer = (365 + check(f) - calculating(d, e, f, pivot)) + calculating(a, b, c, pivot) + (c - f - 1)*365;
    return answer;
}
void output(int out)
{
    cout << out;
}
