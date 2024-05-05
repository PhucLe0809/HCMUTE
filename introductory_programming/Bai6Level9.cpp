#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double arr[]);
double sum_max(int n, double arr[]);
double sum_min(int n, double arr[]);
double sum_point(int n, double arr[]);
void output(double answer);
int main ()
{
	int n;
	double arr[9999];
	input(n,arr);
	double answer = sum_point(n,arr);
	output(answer);
	return 0 ;
}
void input(int &n, double arr[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
double sum_max(int n, double arr[])
{
	double sum = 0;
	for (int i = 1; i<n-1; i++)
		if (arr[i]>arr[i-1] && arr[i]>arr[i+1])
			sum = sum + arr[i];
	return sum;
}
double sum_min(int n, double arr[])
{
	double sum = 0;
	for (int i = 1; i<n-1; i++)
		if (arr[i]<arr[i-1] && arr[i]<arr[i+1])
			sum = sum + arr[i];
	return sum;
}
double sum_point(int n, double arr[])
{
	double sum = sum_min(n,arr) + sum_max(n,arr);
	return sum;
}
void output(double answer)
{
	cout << answer ;
}
