#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int interupted(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[99999];
    input(n,arr);
    int answer = interupted(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int interupted(int n , int pattern[])
{
    int t = 0;
    for (int i = 0 ; i < n - 1 ; i++)
        if (pattern[i] == 0 && pattern[i+1] == 0)
        {
            t = 1 ;
            break;
        }
    return t ;
}
void output(int answer)
{
    if (answer == 1)
        cout << "True";
    else
        cout << "False";
}
