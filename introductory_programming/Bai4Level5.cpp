#include <bits/stdc++.h>

using namespace std;
void input(int &x);
void scan(int x);

int main()
{
    int n;
    input(n); scan(n);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
void scan(int x)
{
    for (int i = 1; i*i <= x; i++) cout << i*i << " ";
}
