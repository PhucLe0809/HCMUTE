#include <bits/stdc++.h>

using namespace std ;
void input(int &m, int &n, int matrix[][100]);
int max_row(int h, int n, int matrix[][100]);
int max_col(int c, int m, int matrix[][100]);
int queen(int m, int n, int matrix[][100]);
int matrix_from_left(int k, int l, int m, int n, int matrix[][100]);
int matrix_from_right(int l, int k, int m, int n, int matrix[][100]);
void output(int answer);

int main ()
{
	int m,n,matrix[100][100];
	input(m,n,matrix);
	int answer = queen(m,n,matrix);
	return 0;
}
void input(int &m, int &n, int matrix[][100])
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> matrix[i][j];
}
int max_row(int h, int n,int matrix[][100])
{
	int max = matrix[h][0];
	for (int i = 1; i<n; i++)
		if (matrix[h][i] > max)
			max = matrix[h][i];
	return max;
}
int max_col(int c, int m, int matrix[][100])
{
	int max = matrix[0][c];
	for (int i = 1; i<m; i++)
		if (matrix[i][c] > max)
			max = matrix[i][c];
	return max;
}
int matrix_from_left(int k, int l, int m, int n, int matrix[][100])
{
	int max = matrix[k][l];
	int tam;
	if (k > l)
	{
		tam = k - l;
		for (int i = tam; i<m; i++)
			if (matrix[i][i-1] > max)
				max = matrix[i][i-1];
		return max;
	}
	if (k < l)
	{
		tam = l - k;
		for (int i = tam; i<n; i++)
			if (matrix[i-1][i] > max)
				max = matrix[i][i-1];
		return max;
	}
	if (k == l)
	{
		for (int i = 0; i<m; i++)
			if (max < matrix[i][i])
				max = matrix[i][i];
		return max;
	}		
}
int matrix_from_right(int l, int k, int m, int n, int matrix[][100])
{
	int i = l;
	int j = k;
	int max = matrix[i][j];
	while (i > 0 && j < m - 1)
	{
		i--;
		j++;
		if (max < matrix[i][j])
			max = matrix[i][j];
	}
	i = l;
	j = k;
	while ( i < n - 1 && j > 0)
	{
		i++;
		j--;
		if (max < matrix[i][j])
			max = matrix[i][j];
	}
	return max;
}
int queen(int m, int n, int matrix[][100])
{
	int cnt = 0;
	int max;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			if ((max_row(i,n,matrix) == max_col(j,m,matrix)) && (matrix_from_left(i,j,m,n,matrix) == max_row(i,n,matrix))&& (max_row(i,n,matrix) == matrix_from_right(i,j,m,n,matrix)))
				cout << i << j << " ";
	return cnt ;
}
void output(int answer)
{
	cout << answer ;	
}
