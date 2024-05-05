#include <bits/stdc++.h>

using namespace std;
void input(double &n);
double sum(double n, double arr[]);
void output(double answer);

int main ()
{
    double n;
    input(n);
    double arr[int(n)];
    for (int i = 0 ; i < int(n) ; i++)
        input(arr[i]);
    double answer = sum(n,arr);
    output(answer);
    return 0;
}
void input(double &n)
{
    cin >> n;
}
double sum(double n, double arr[])
{
    double t = 0;
    for (int i = 0 ; i < int(n); i++ )
        t = t + arr[i];
    return t;
}
void output(double answer)
{
    cout << answer ;
}

