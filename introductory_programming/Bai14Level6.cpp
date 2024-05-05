#include <bits/stdc++.h>

using namespace std ;
void input(int &n , double pattern[]);
double scan(int n , double pattern[]);
void output(double answer);

int main ()
{
    int n;
    double arr[999];
    input(n,arr);
    double answer = scan(n,arr);
    output(answer);
    return 0;
}
void input(int &n , double pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
double scan(int n , double pattern[])
{
    double t = 1;
    for (int i = 0 ; i < n ; i++)
        if (pattern[i]<0)
        {
            t = pattern[i];
            break;
        }
    return t;
}
void output(double answer)
{
    cout << answer ;
}
