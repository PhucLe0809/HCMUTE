#include <bits/stdc++.h>

using namespace std;
void input(int &x);
bool perfect(int num);
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
bool perfect(int num)
{
    int scan = 1;
    for (int i = 2; i <= round(sqrt(num)); i++)
        if (num % i == 0) scan += (i + num/i);
    if (int(sqrt(num)) == sqrt(num)) scan -= sqrt(num);
    if (scan == num) return true; else return false;
}
int scan(int x)
{
    int counting = 0;
    for (int i = 6; i <= x; i++)
        counting += perfect(i);
    return counting;
}
void output(int out)
{
    cout << out;
}
