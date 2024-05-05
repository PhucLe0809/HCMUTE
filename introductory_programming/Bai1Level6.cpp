#include <bits/stdc++.h>

using namespace std ;
void input(int &n ,int pattern[] , int &x, int &y);
void output(int n , int pattern[], int x, int y);

int main ()
{
    int n , x ,y ;
    int arr[9999];
    input(n,arr,x,y);
    output(n,arr,x,y);
    return 0;
}
void input(int &n ,int pattern[] , int &x, int &y)
{
    cin >> n >> x >> y ;
    for (int i = 0 ; i < n ;i++)
        cin >> pattern[i];
}
void output(int n , int pattern[], int x, int y)
{
    for (int i = 0 ; i < n ; i++)
        if (pattern[i]>=x && pattern[i]<=y && pattern[i]%2==0)
            cout << pattern[i] << " ";
}
