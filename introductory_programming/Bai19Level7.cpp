#include <bits/stdc++.h>

using namespace std ;
void input(int &n , int pattern[]);
int perfect(int scan);
int work(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n;
    int arr[99999];
    input(n,arr);
    int answer = work(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int perfect(int scan)
{
    int t = 0;
    for (int i = 1; i <= scan/2 ; i ++)
        if (scan%i == 0)
            t  = t + i;
    return t;
}
int work(int n , int pattern[])
{
    int t = 0;
    for (int i = 0 ; i < n ; i++)
        if (perfect(pattern[i])==pattern[i])
            t = pattern[i];
    return t;
}
void output(int answer)
{
    cout << answer;
}
