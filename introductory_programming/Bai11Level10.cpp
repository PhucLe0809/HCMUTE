#include <bits/stdc++.h>

using namespace std ;
void input(int &m, int &n, int &m2, int &n2, int arr[][100], int pattern[][100]);
void matrix_sum(int m, int n, int m2, int n2, int arr[][100], int pattern[][100], int scan[][100]);
void output(int m, int n, int scan[][100]);

int main ()
{
	int m,n,m2,n2,arr[100][100],pattern[100][100],scan[100][100];
	input(m,n,m2,n2,arr,pattern);
	matrix_sum(m,n,m2,n2,arr,pattern,scan);
	output(m,n,scan);
	return 0;
}
void input(int &m, int &n, int &m2, int &n2, int arr[][100], int pattern[][100])
{
	cin >> m >> n ;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> arr[i][j];
	cin >> m2 >> n2 ;
	for (int i = 0; i<m2; i++)
		for (int j = 0; j<n2; j++)
			cin >>pattern[i][j];
}
void matrix_sum(int m, int n, int m2, int n2, int arr[][100], int pattern[][100], int scan[][100])
{
	for (int i = 0; i<m2; i++)
		for (int j = 0; j<n2; j++)
			scan[i][j] = arr[i][j] + pattern[i][j];
}
void output(int m, int n, int scan[][100])
{
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			cout << scan[i][j] << " ";
		cout << endl;
	}
}
