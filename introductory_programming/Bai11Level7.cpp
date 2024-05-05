#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int find_num(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[9999];
    input(n, arr);
    int answer = find_num(n, arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int find_num(int n , int pattern[])
{
    int t = 1 ;
    for (int i = 0 ; i < n ; i++)
        if (pattern[i] < 1)
        {
            t = 0;
            break;
        }
    return t;
}
void output(int answer)
{
    if (answer == 1)
        cout << "TRUE" ;
    else
        cout << "FALSE";
}
