#include <bits/stdc++.h>

using namespace std;
void input(int &n, double arr[]);
void scan(int n, double arr[]);
void screen(int n, double arr[]);

int main ()
{
	int n;
	double arr[9999];
	input(n,arr);
	scan(n,arr);
	screen(n,arr);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
void scan(int n, double arr[])
{
	arr[n] = arr[0];
	for (int i = 0 ; i<n; i++)
		arr[i] = arr[i+1];
}
void screen(int n, double arr[])
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}

