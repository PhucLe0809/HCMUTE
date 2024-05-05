#include <bits/stdc++.h>
#define SIZE 100

using namespace std;
void input(int &m, int &n, int matrix[][SIZE]);
int matrix_max(int m, int n, int matrix[][SIZE]);
void find_max_elements(int m, int n, int matrix[][SIZE]);
void output(int i, int j);

int main ()
{
	int m,n;
	int matrix[SIZE][SIZE];
	input(m,n,matrix);
	find_max_elements(m,n,matrix);
	return 0;
}
void input(int &m, int &n, int matrix[][SIZE])
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> matrix[i][j];
}
int matrix_max(int m, int n, int matrix[][SIZE])
{
	int max = matrix[0][0];
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			if (max < matrix[i][j])
				max = matrix[i][j];
	return max;
}
void find_max_elements(int m, int n, int matrix[][SIZE])
{
	int max = matrix_max(m,n,matrix);
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			if (max == matrix[i][j])
				output(i+1,j+1);
}
void output(int i, int j)
{
	cout << i << " " << j << endl;
}

