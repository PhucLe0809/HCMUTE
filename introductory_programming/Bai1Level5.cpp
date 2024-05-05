#include <bits/stdc++.h>

using namespace std;
void input(int &x);
bool is_prime(int num);
void scan(int x);

int main()
{
    int n;
    input(n);
    scan(n);
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
void scan(int x)
{
    for (int i = 2; i <= x; i++)
        if (is_prime(i)) cout << i << " ";
}
