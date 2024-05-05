#include <bits/stdc++.h>

using namespace std;
void input(int &m, int &n, int arr[][100]);
void sum_elements(int m, int n, int arr[][100]);
void output(int answer);

int main ()
{
	int m,n,arr[100][100];
	input(m,n,arr);
	sum_elements(m,n,arr);
	return 0;
}
void input(int &m, int &n, int arr[][100])
{
	cin >> m >> n;
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cin >> arr[i][j];
}
void sum_elements(int m, int n, int arr[][100])
{
	int sum_row = 0;
	int sum_col = 0 ;
	int form_left = 0;
	int form_right = 0;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			output(arr[i][j]);
			sum_row = sum_row + arr[i][j]; 
		}
		output(sum_row);
		cout << endl;
		sum_row = 0;
	}
	for (int j = 0; j<n; j++)
	{
		for (int i = 0; i<m;i++)
			sum_col = sum_col + arr[i][j];
		output(sum_col);
		sum_col = 0;
	}
	if (m == n)
	{
		for (int i = 0; i<m; i++)
			form_left = form_left + arr[i][i];
		for (int i = m - 1; i>=0;i--)
			form_right = form_right + arr[i][i];
	}
	cout << endl;
	output(form_left);	
	cout << endl;
	output(form_right);
}		
void output(int answer)
{
	cout << answer << " ";
}
