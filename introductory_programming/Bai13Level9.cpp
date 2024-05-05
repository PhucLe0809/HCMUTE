#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int arr[]);
int square(int scan);
int __erase(int &n, int arr[], int place);
void erase_square(int &n, int arr[]);
void output(int n, int arr[]);

int main ()
{
	int n;
	int arr[9999];
	input(n,arr);
	erase_square(n,arr);
	output(n,arr);
	return 0;	
}
void input(int &n, int arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
int square(int scan)
{
	int tmp = sqrt(scan);
	if (tmp*tmp == scan)
		return 1;
	else 
		return 0;
}
int __erase(int &n, int arr[], int place)
{
	for (int i = place; i<n; i++)
		arr[i] = arr[i+1];
	n--;
}
void erase_square(int &n, int arr[])
{
	for (int i = 0; i<n; i++)
		if (square(arr[i]) == 1)
		{
			__erase(n,arr,i);
			i--;
		}
}
void output(int n, int arr[])
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}
