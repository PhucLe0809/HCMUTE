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
    if (int(sqrt(x)) == sqrt(x)) return true; else return false;
}
void output(bool out)
{
    if (out) cout << "YES"; else cout << "NO";
}
