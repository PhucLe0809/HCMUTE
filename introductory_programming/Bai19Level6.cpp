#include <bits/stdc++.h>

using namespace std ;
void input(int &n ,int pattern[] , int &u, int &v);
void output(int n , int pattern[], int u, int v);

int main ()
{
    int n , u ,v ;
    int arr[9999];
    input(n,arr,u,v);
    output(n,arr,u,v);
    return 0;
}
void input(int &n ,int pattern[] , int &u, int &v)
{
    cin >> n >> u >> v ;
    for (int i = 0 ; i < n ;i++)
        cin >> pattern[i];
}
void output(int n , int pattern[], int u, int v)
{
    for (int i = 0 ; i < n ; i++)
        if (pattern[i]>=u && pattern[i]<=v)
            cout << pattern[i] << " ";
}
