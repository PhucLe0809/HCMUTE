#include <bits/stdc++.h>

using namespace std;
void input(string &x);
long long scan(string x);
void output(long long out);

int main()
{
    string str;
    input(str);
    long long answer = scan(str);
    output(answer);
    return 0;
}
void input(string &x)
{
    cin >> x;
}
long long scan(string x)
{
    long long out = 0;
    for (int i = 0; i < x.size(); i++)
        out += (int(x[i]) - 48);
    return out;
}
void output(long long out)
{
    cout << out;
}
