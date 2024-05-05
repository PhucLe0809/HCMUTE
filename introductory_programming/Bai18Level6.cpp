#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int swap(int &scan,int &tmp);
int convert(int n , int pattern[]);
void output(int n,int pattern[]);

int main ()
{
    int n;
    int arr[9999];
    input(n , arr);
    convert(n , arr);
    output(n , arr);
    return 0;
}

void input(int &n , int pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int swap(int &scan,int &tmp)
{
    int t = scan;
    scan = tmp;
    tmp = t;
}
int convert(int n , int pattern[])
{
    for (int i = 0 ; i <= (n-1)/2 ; i++)
        swap(pattern[i],pattern[n-1-i]);
}
void output(int n, int pattern[])
{
    for (int i = 0 ; i < n ; i ++)
        cout << pattern[i] << " ";
}

