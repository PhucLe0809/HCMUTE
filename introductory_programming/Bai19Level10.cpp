#include <bits/stdc++.h>
#define SIZE 100

using namespace std ;
void input(int &m, int &n, int matrix[][SIZE], int &k);
int scan(int m, int n, int matrix[][SIZE], int k);
void output(int answer);

int main ()
{
	int m,n,k;
	int matrix[SIZE][SIZE] ;
	input(m,n,matrix,k);
	int answer = scan(m,n,matrix,k);
	output(answer);
	return 0;
}
void input(int &m, int &n, int matrix[][SIZE], int &k)
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> matrix[i][j];
	cin >> k;
}
int scan(int m, int n, int matrix[][SIZE], int k)
{
	for (int i = 0; i<n-1; i++)
		if (matrix[k][i] < matrix[k][i+1])
			return 0;
	return 1;
}
void output(int answer)
{
	if (answer == 1)
		cout << "True";
	else
		cout << "False";
}
