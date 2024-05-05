#include <bits/stdc++.h>

using namespace std;
void input(int &m, int &n, int matrix[][100]);
void swap(int &a, int &b);
void __sort_matrix(int m, int n, int matrix[][100]);
void output(int m, int n, int matrix[][100]);

int main ()
{
	int m,n;
	int matrix[100][100];
	input(m,n,matrix);
	__sort_matrix(m,n,matrix);
	output(m,n,matrix);
	return 0;
}
void input(int &m, int &n, int matrix[][100])
{
	cin >> m >> n ;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> matrix[i][j];
}
void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void __sort_matrix(int m, int n, int matrix[][100])
{
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			for (int l = 0; l<m; l++)
				for (int k = 0; k<n; k++)
					if (matrix[i][j] < matrix[l][k])
						swap(matrix[i][j],matrix[l][k]);
}
void output(int m, int n, int matrix[][100])
{
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}	
}
