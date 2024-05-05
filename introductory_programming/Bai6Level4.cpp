#include <bits/stdc++.h>

using namespace std;
void input(string &x);
bool is_prime(int num);
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
bool is_prime(int num)
{
    if (num < 2) return false;
    int i = 2; bool test = true;
    while (i <= round(sqrt(num)) && test)
        if (num % i == 0) test = false; else i++;
    return test;
}
int scan(string x)
{
    int counting = 0;
    for (int i = 0; i < x.size(); i++)
        if (is_prime(int(x[i]) - 48)) counting++;
    return counting;
}
void output(int out)
{
    cout << out;
}
