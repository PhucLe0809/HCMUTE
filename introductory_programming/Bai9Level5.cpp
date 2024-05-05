#include <bits/stdc++.h>

using namespace std;
void input(int &a, int &b, int &c, int &d);
int GCD(int x, int y);
void scan(int a, int b, int c, int d);

int main()
{
    int x, y, z, t;
    input(x, y, z, t);
    scan(x, y, z, t);
    return 0;
}
void input(int &a, int &b, int &c, int &d)
{
    cin >> a >> b >> c >> d;
}
int GCD(int x, int y)
{
    int r;
    while (y != 0)
    {
        r = x % y;
        x = y; y = r;
    }
    return x;
}
void scan(int a, int b, int c, int d)
{
    int up = (a*d + b*c);
    int down = (b*d);
    int pivot = GCD(up, down);
    up /= pivot; down /= pivot;
    cout << up << '\n' << down;
}
