#include <bits/stdc++.h>
#define SIZE 100

using namespace std;
void input(int &m, int &n, int matrix[][SIZE]);
void prime_in_matrix(int m, int n, int matrix[][SIZE]);
int nTo(int pos);
void output(int i, int j);

int main ()
{
	int m,n;
	int matrix[SIZE][SIZE];
	input(m,n,matrix);
	prime_in_matrix(m,n,matrix);
	return 0;
}
void input(int &m, int &n, int matrix[][SIZE])
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> matrix[i][j];
}
int nTo(int pos)
{
	int t = 1;
	if (pos == 0 || pos == 1)
		t = 0;
	for (int i = 2; i<pos; i++)
		if (pos % i == 0)
		{
			t = 0;
			break;
		}
	return t;
}
void prime_in_matrix(int m, int n, int matrix[][SIZE])
{
	int cnt = 0;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (nTo(matrix[i][j]) == 1)
			{
				output(i+1,j+1);
				cnt++;
				break;
			}
		}
		if (cnt > 0)
			break;
	}
}	
void output(int i, int j)
{
	cout << i << " " << j ;
}
