#include <bits/stdc++.h>

using namespace std ;
void input(int &n , int pattern[]);
int accumulates(int n , int pattern[]);
void output(int answer);

int main()
{
    int n;
    int arr[9999];
    input(n,arr);
    int answer = accumulates(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int accumulates(int n , int pattern[])
{
    int t = 0;
    for (int i = 0 ; i < n ; i++)
        if (pattern[i] % 2 == 0)
            t = t + pattern[i];
    return t;
}
void output(int answer)
{
    cout << answer ;
}
