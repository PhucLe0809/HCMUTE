#include <bits/stdc++.h>

using namespace std ;
void input(int &n);
int scan(int n , double pattern[]);
void output(int n , double pattern[]);

int main ()
{
    int n;
    double arr[1000];
    input(n);
    scan(n,arr);
    output(n,arr);
    return 0;
}
void input(int &n)
{
    cin >> n;
}
int scan(int n , double pattern[])
{
    pattern[1]=1;
    pattern[2]=1;
    for (int i = 3 ; i <= n; i++)
        pattern[i]=pattern[i-1]+pattern[i-2];
}
void output(int n , double pattern[])
{
    for (int i = 1 ; i <= n ; i++)
        cout << setprecision(0) << fixed << pattern[i] << " ";
}
