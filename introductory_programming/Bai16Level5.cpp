#include <bits/stdc++.h>

using namespace std;
void input(int &n);
void scan(int n);

int main()
{
    int x;
    input(x);
    scan(x);
    return 0;
}
void input(int &n)
{
    cin >> n;
}
void scan(int n)
{
    int pivot[] = {10, 20, 50, 100};
    int save[5] = {0, 0, 0, 0};
    n /= 1000;
    for (int i = 3; i >= 0; i--)
    {
        if (n / pivot[i] != 0)
        {
            save[i] = n / pivot[i];
            n -= save[i]*pivot[i];
        }
    }
    for (int i = 0; i < 4; i++)
        cout << pivot[i]*1000 << " " << save[i] << '\n';
}
