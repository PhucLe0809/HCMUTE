#include <bits/stdc++.h>

using namespace std;
void input(int &x);
bool scan(int x);
void output(bool out);

int main()
{
    int n;
    input(n);
    bool test = scan(n);
    output(test);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
bool scan(int x)
{
    int scan = 1;
    for (int i = 2; i <= round(sqrt(x)); i++)
        if (x % i == 0) scan += (i + x/i);
    if (int(sqrt(x)) == sqrt(x)) scan -= sqrt(x);
    if (scan == x) return true; else return false;
}
void output(bool out)
{
    if (out) cout << "YES"; else cout << "NO";
}
