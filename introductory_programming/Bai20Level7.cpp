#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int prime(int scan);
int work(int n , int pattern[]);
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
    if (scan==2) return 1;
    for (int i = 2 ; i < scan ; i++)
        if (scan%i==0)
        {
            return 0;
            break;
        }
        else return 1;
}
int work(int n , int pattern[])
{
    int t = -1;
    for (int i = 0 ; i < n ; i++)
        if (prime(pattern[i])==1)
            t = pattern[i];
    return t;
}
void output(int answer)
{
    cout << answer;
}
