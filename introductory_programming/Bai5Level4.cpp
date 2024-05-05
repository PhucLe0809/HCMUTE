#include <bits/stdc++.h>

using namespace std;
void input(string &x);
int scan(string x);
void output(int out);

int main()
{
    string str;
    input(str);
    int answer = scan(str);
    output(answer);
    return 0;
}
void input(string &x)
{
    cin >> x;
}
int scan(string x)
{
    int answer = -1;
    for (int i = 0; i < x.size(); i++)
        answer = max(answer, int(x[i]) - 48);
    return answer;
}
void output(int out)
{
    cout << out;
}
