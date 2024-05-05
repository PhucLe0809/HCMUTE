#include <bits/stdc++.h>

using namespace std;
void input(int &x);
int scan(int x);
void output(int out);

int main()
{
    int n;
    input(n);
    int answer = scan(n);
    output(answer);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
int scan(int x)
{
    int counting = 0;
    for (int i = 1; i*i <= x; i++) counting++;
    return counting;
}
void output(int out)
{
    cout << out;
}
