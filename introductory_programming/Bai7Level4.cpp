#include <bits/stdc++.h>

using namespace std;
void input(string &x);
bool scan(string x);
void output(bool out);

int main()
{
    string str;
    input(str);
    bool test = scan(str);
    output(test);
    return 0;
}
void input(string &x)
{
    cin >> x;
}
bool scan(string x)
{
    int i;
    for (i = 0; i < x.size(); i++)
        if ((int(x[i]) - 48) % 2 != 0) break;
    if (i == x.size()) return true; else return false;
}
void output(bool out)
{
    if (out) cout << "YES"; else cout << "NO";
}
