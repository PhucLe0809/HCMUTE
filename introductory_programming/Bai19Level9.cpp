#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double arr[]);
double max_elements(int n, double arr[]);
void __erase(int &n, double arr[], int place);
double max_second(int &n, double arr[]);
void output(double answer);

int main()
{
	int n;
	double arr[99999];
	input(n,arr);
	double answer = max_second(n,arr);
	output(answer);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
double max_elements(int n, double arr[])
{
	double max = arr[0];
	for (int i = 1; i<n; i++)
		if (max<arr[i])
			max = arr[i];
	return max;
}
void __erase(int &n, double arr[], int place)
{
	for (int i = place; i<n;i++)
		arr[i] = arr[i+1];
	n--;
}
double max_second(int &n, double arr[])
{
	double max = max_elements(n,arr);
	for (int i = 0; i<n; i++)
		if (arr[i] == max)
		{
			__erase(n,arr,i);
			i--;
		}
	max = max_elements(n,arr);
	return max;
}
void output(double answer)
{
	cout << answer ;
}

