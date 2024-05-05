#include <bits/stdc++.h>

using namespace std;
void input(int &n, int &pos, int pattern[]);
int sum(int n, int pos, int pattern[]);
void output(int answer);

int main ()
{
    int n,pos;
    int arr[9999];
    input(n,pos,arr);
    int answer = sum(n,pos,arr);
    output(answer);
    return 0;
}
void input(int &n, int &pos, int pattern[])
{
    cin >> n >> pos;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int sum(int n, int pos, int pattern[])
{
    int t = 0;
    for (int i = 0 ; i < n ; i++)
        if (pattern[i]==pos)
            t = 1;
    return t;
}
void output(int answer)
{
    cout << answer;
}
