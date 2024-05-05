#include <bits/stdc++.h>

using namespace std;
void input(int &x);
bool is_prime(int num);
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
bool is_prime(int num)
{
    if (num < 2) return false;
    int i = 2; bool test = true;
    while (i <= round(sqrt(num)) && test)
        if (num % i == 0) test = false; else i++;
    return test;
}
int scan(int x)
{
    int counting = 0;
    for (int i = 2; i <= x; i++)
        counting += is_prime(i);
    return counting;
}
void output(int out)
{
    cout << out;
}
