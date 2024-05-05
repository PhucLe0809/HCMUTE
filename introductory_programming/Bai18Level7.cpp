#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int prime(int scan);
int work(int n ,int pattern[]);
void output(int answer);

int main ()
{
    int n;
    int arr[9999];
    input(n,arr);
    int answer = work(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int prime(int scan)
{
    int t = 0;
    if (scan==2)
        return t;
    else
        for (int i = 2; i < scan ; i ++ )
            if (scan%i==0)
            {
                t = 1 ;
                break ;
            }
    if (scan==1)
        t = 1;

    return t;
}
int work(int n ,int pattern[])
{
    int cnt = 0;
    for (int i = 0 ; i < n ; i++)
        if (prime(pattern[i])==0)
            cnt++;
    return cnt;
}
void output(int answer)
{
    cout << answer;
}
