#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int arr[]);
void left_right(int n, int arr[]);
void output(int n, int arr[]);

int main()
{
	int n;
	int arr[9999];
	input(n,arr);
	left_right(n,arr);
	output(n,arr);
	return 0;
}
void input(int &n, int arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
void left_right(int n, int arr[])
{
	int j = 0;
	int k = n-1;
	int scan[n];
	for (int i = 0; i<n; i++)
		if (arr[i] % 2 == 0 && arr[i] != 0)
		{
			scan[j] = arr[i];
			j++;
		}
	for (int i = 0; i<n; i++)
		if (arr[i]  % 2 != 0)
		{
			scan[k] = arr[i];
			k--;
		}
	for (int i = j; i<=k; i++)
		scan[i] = 0;
	for (int i = 0; i<n; i++)
		arr[i] = scan[i];
}
void output(int n, int arr[])
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}
