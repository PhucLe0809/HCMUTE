#include <bits/stdc++.h>

using namespace std;
void input(int &m, int &n, int matrix[][100]);
void matrix_from_left(int m, int n, int matrix[][100]);
void swap(int &scan, int &b);
void output(int m, int n, int matrix[][100]);

int main ()
{
    int m,n;
    int matrix[100][100];
    input(m,n,matrix);
    matrix_from_left(m,n,matrix);
	output(m,n,matrix);
    return 0;
}
void input(int &m, int &n, int matrix[][100])
{
	cin >> m >> n;
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
            cin >> matrix[i][j];
}
void swap(int &scan, int &b)
{
	int t = scan;
	scan = b ;
	b = t ;
}
void matrix_from_left(int m, int n, int matrix[][100])
{
	for (int i = 0; i<m-1; i++)
		for (int j = i+1; j<n; j++)
			if (matrix[i][i]>matrix[j][j])
				swap(matrix[i][i],matrix[j][j]);
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
