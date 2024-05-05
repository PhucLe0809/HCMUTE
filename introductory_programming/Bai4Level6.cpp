#include <bits/stdc++.h>

using namespace std ;
void input(int &n ,int pattern[]);
int work(int n, int pattern[], int &answer, int &cnt);
void output(int cnt, int answer);

int main () {
    int n;
    int arr[10000];
    input(n ,arr);
    int answer,cnt;
    work(n,arr,answer,cnt);
    output(cnt,answer);
    return 0;
}
void input(int &n ,int pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++ )
        cin >> pattern[i];
}
int work(int n, int pattern[], int &answer , int &cnt)
{
    cnt = 0;
    answer =0;
    for (int i = 0 ; i < n ; i++)
    {
        if (pattern[i] % 5 == 0)
        {
            cnt++;
            answer = answer +pattern[i];
        }
    }
}
void output(int cnt, int answer)
{
    cout << double(answer)/double(cnt) ;
}
