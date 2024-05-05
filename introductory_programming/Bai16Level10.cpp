#include <bits/stdc++.h>
#define SIZE 100

using namespace std;
void input(int &m, int &n, int marix[][SIZE]);
int odd_amplitude(int m, int n, int marix[][SIZE]);
void output(int answer);

int main ()
{
	int m,n;
	int marix[SIZE][SIZE];
	input(m,n,marix);
	int answer = odd_amplitude(m,n,marix);
	output(answer);
	return 0;
}
void input(int &m, int &n, int marix[][SIZE])
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> marix[i][j];
}
int odd_amplitude(int m, int n, int marix[][SIZE])
{
	int cnt = 0 ;
	for (int i = 0 ; i<n; i++)
	{
		if (marix[1][i] % 2 == 0)
			cnt++;
		if (marix[m-1][i] % 2 == 0)
			cnt++;
	}
	for (int i = 1 ; i<m-1; i++)
	{
		if (marix[i][1] % 2 == 0)
			cnt++;
		if (marix[i][m-1] % 2 == 0)
			cnt++;
	}
	return cnt;
}
void output(int answer)
{
	cout << answer;
}
