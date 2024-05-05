#include <bits/stdc++.h>

using namespace std;
void input(string &x);
void output(string out);

int main()
{
    string str;
    input(str);
    reverse(str.begin(), str.end());
    output(str);
    return 0;
}
void input(string &x)
{
    cin >> x;
}
void output(string out)
{
    cout << out;
}
