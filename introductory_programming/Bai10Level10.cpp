#include <bits/stdc++.h>

using namespace std;
void input(int &m, int &n, int arr[][100]);
long long sum_array(int m, int n, int arr[][100]);
void output(long long answer);

int main ()
{
    int m,n;
    int arr[100][100];
    input(m,n,arr);
    long long answer = sum_array(m,n,arr);
	output(answer);
    return 0;
}

void input(int &m, int &n, int arr[][100])
{
    cin >> m >> n;
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            cin >> arr[i][j];
}
long long sum_array(int m, int n, int arr[][100])
{
    long long sum = 0;
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            sum = sum + arr[i][j];
    return sum;
}
void output(long long answer)
{
    cout << answer;
}
