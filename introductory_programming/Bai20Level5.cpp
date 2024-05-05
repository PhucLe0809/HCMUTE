#include <bits/stdc++.h>

using namespace std;
void input(long long &n);
void scan(long long n);

int main()
{
    long long n;
    input(n); scan(n);
    return 0;
}
void input(long long &n)
{
    cin >> n;
}
void scan(long long n)
{
    if (n < 2) return;
    else
    {
        for (int i = 2; i <= round(sqrt(n)) && n != 1; i++)
            while (!(n%i))
            {
                cout << i << " "; n /= i;
            }
        if (n > 1) cout << n;
    }
}
