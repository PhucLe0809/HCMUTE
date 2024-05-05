#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int is_prime(int scan);
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
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int is_prime(int scan)
{
    if (scan == 2) return 0;
    for (int i = 2 ; i < scan; i++)
        if (scan%i == 0)
        {
            return 1;
            break;
        }
        else return 0;
}
int work(int n , int pattern[])
{
    int t = -1;
    for (int i = 0 ; i < n ; i++)
        if (is_prime(pattern[i])==0)
        {
            t = pattern[i];
            break;
        }
    return t;
}
void output(int answer)
{
    cout << answer;
}
