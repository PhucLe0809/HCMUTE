#include <bits/stdc++.h>
using namespace std;

void input(int &n, double arr[]);
double search(int n, double arr[]);
void __erase(int &n, double arr[], int place);
void __erase_max(int &n, double arr[]);
void output(int n, double arr[]);

int main ()
{
	int n ;
	double arr[9999];
	input(n,arr);
	__erase_max(n,arr);
	output(n,arr);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
double search(int n, double arr[])
{
	double max = arr[0];
	for (int i = 1; i<n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
void __erase(int &n, double arr[], int place)
{
	for (int i = place; i<n - 1; i++)
		arr[i] = arr[i+1];
	n--;	
}
void __erase_max(int &n, double arr[])
{
	double max = search(n,arr);
	for (int i = 0; i<n; i++)
	{
		if (arr[i] == max)
		{
			__erase(n,arr,i);
			i--;
		}		
	}	
}
void output(int n, double arr[])
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}
