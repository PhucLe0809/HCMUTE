#include <bits/stdc++.h>

using namespace std;
void input(int &x);
void scan(int x);

int main()
{
    int n;
    input(n);
    scan(n);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
void scan(int x)
{
    if (x == 1) cout << 1;
    if (x == 2) cout << 1 << " " << 1;
    if (x > 2)
    {
        cout << 1 << " " << 1 << " ";
        double f1 = 1.0, f2 = 1.0;
        double f;
        for (int i = 3; i <= x; i++)
        {
            f = f1 + f2;
            cout << setprecision(0) << fixed << f << " ";
            f1 = f2; f2 = f;
        }
    }
}
