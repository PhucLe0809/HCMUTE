#include <bits/stdc++.h>

using namespace std;
void input(int &n, int pattern[]);
int find_positive(int n, int pattern[]);
void output(int answer);

int main ()
{
    int n;
    int arr[9999];
    input(n,arr);
    int answer = find_positive(n,arr);
    output(answer);
    return 0;
}
void input(int &n, int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int find_positive(int n, int pattern[])
{
    int t = -1;
    for (int i = 0 ; i < n ; i++)
        if (pattern[i]>0)
            t = pattern[i];

    return t;
}
void output(int answer)
{
    cout << answer;
}
