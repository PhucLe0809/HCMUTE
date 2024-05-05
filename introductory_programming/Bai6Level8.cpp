#include <bits/stdc++.h>

using namespace std;
void input(int &n, double pattern[]);
void swap(double &arr , double &pattern);
void swap_max_min(int n, double  pattern[]);
void output(int n , double pattern[]);

int main ()
{
	int n;
	double arr[9999];
	input(n,arr);
	swap_max_min(n,arr);
	output(n,arr);
	return 0;
}
void input(int &n, double pattern[])
{
	cin >> n ;
	for (int i = 0 ; i<n ; i++)
		cin >> pattern[i];
}
void swap(double &arr , double &pattern)
{
	double t = arr;
	arr = pattern ;
	pattern = t;
}
void swap_max_min(int n, double  pattern[])
{
	// Find Max
	double max = pattern[0];
	int placeMax;
	for (int i = 1; i<n ; i++)
		if (max<pattern[i])
		{
			max = pattern[i];
			placeMax = i;
		}
	// Find Min		
	double min = pattern[0];
	int placeMin;
	for (int i = 1; i<n ; i++)
		if (min>pattern[i])
		{
			min = pattern[i];
			placeMin = i;
		}
	swap(pattern[placeMax], pattern[placeMin]);
}
void output(int n , double pattern[])
{
	for (int i = 0 ; i<n ; i++)
		cout << pattern[i] << " ";
}

