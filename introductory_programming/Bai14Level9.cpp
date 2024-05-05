#include <bits/stdc++.h>

using namespace std;
void input(int &n, double arr[]);
void __erase(int &n, double arr[], int place);
void erase_duplicate(int &n, double arr[]);
void output(int n, double arr[]);

int main()
{
	int n;
	double arr[9999];
	input(n,arr);
	erase_duplicate(n,arr);
	output(n,arr);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
void __erase(int &n, double arr[], int place)
{
	for (int i = place; i<n - 1;i++)
		arr[i] = arr[i+1];
	n--;
}
void erase_duplicate(int &n, double arr[])
{
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++)
			if (arr[i] == arr[j])
			{
				__erase(n,arr,j);	
				j--;
			}
}
void output(int n, double arr[])
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}
