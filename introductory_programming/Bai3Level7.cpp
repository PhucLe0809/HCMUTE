#include <bits/stdc++.h>

using namespace std;
void input(int &n, float pattern[]);
int palindrome(int n, float pattern[]);
void output(int answer);

int main ()
{
    int n ;
    float arr[9999];
    input(n,arr);
    int answer = palindrome(n,arr);
    output(answer);
    return 0;
}
void input(int &n, float pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int palindrome(int n, float pattern[])
{
    int t = 1;
    for (int i = 0; i < n/2 ; i++)
        if (pattern[i] != pattern[n - i - 1])
        {
            t = 0 ;
            break ;
        }
    return t ;
}
void output(int answer)
{
    if (answer==1)
        cout << "True";
    else
        cout << "False";
}
