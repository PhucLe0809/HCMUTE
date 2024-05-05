#include <bits/stdc++.h>

using namespace std;
void input(int &n ,int pattern[]);
int scan(int dis);
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
void input(int &n ,int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int scan(int dis)
{
    int t = 0;
    for (int i = 1; i<=dis/2; i++)
        if (dis%i==0)
            t = t + i;
    if (t == dis)
        return 1;
    else
        return 0;
}
int work(int n ,int pattern[])
{
    int t = -1;
    for (int i = 0 ; i < n ; i++)
        if (scan(pattern[i])==1)
        {
            t=pattern[i];
            break;
        }
    return t;
}
void output(int answer)
{
    cout << answer;
}
