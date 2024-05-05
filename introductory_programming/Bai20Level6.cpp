#include<bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
void output(int n , int pattern[]);

int main()
{
    int n;
    int arr[10000];
    input(n,arr);
    output(n,arr);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
void output(int n , int pattern[])
{
    for (int i = 0 ; i < n ; i++)
        cout << pattern[i] << " " ;
}
