#include <bits/stdc++.h>

using namespace std ;
void input(int &n , int pattern[]);
int __square(int scan);
int sum(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[9999];
    input(n,arr);
    int answer = sum(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int __square(int scan)
{
    int t = 0 ;
    if (sqrt(scan)*sqrt(scan)==scan)
        t = 1;
    return t;
}
int sum(int n , int pattern[])
{
    int t = 0;
    for (int i = 0 ; i < n ; i++ )
        if (__square(pattern[i])==1)
            t = t + pattern[i];
    return t;
}
void output(int answer)
{
    cout << answer;
}
