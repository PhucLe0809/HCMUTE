#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int prime(int scan);
int work(int n ,int pattern[], int &avg , int &cnt);
void output(int avg , int cnt);

int main ()
{
    int n,avg,cnt;
    int arr[9999];
    input(n,arr);
    work(n,arr,avg,cnt);
    output(avg,cnt);
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
int work(int n ,int pattern[], int &avg , int &cnt)
{
    cnt = 0;
    avg = 0;
    for (int i = 0 ; i < n ; i++)
        if (prime(pattern[i])==0)
        {
            cnt++;
            avg = avg + pattern[i];
        }
}
void output(int avg , int cnt)
{
    cout << double(avg)/double(cnt);
}
