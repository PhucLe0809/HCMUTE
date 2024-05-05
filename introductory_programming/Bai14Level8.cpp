#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double pattern[]);
int min_elements(int n, double pattern[]);
int max_elements(int n, double pattern[]);
void par_ab(int n, double pattern[], int &min, int &max);
void output(int min, int max);

int main ()
{
	int n, min, max;
	double arr[99999];
	input(n,arr);
	par_ab(n,arr,min,max);
	output(min,max);
	return 0;
}
void input(int &n, double pattern[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
int min_elements(int n, double pattern[])
{
	int min = pattern[0];
	for (int i = 0; i<n; i++)
		if (min>pattern[i])
			min = pattern[i];
	return min;
}
int max_elements(int n, double pattern[])
{
	int max = pattern[0];
	for (int i = 0; i<n; i++)
		if (max<pattern[i])
			max = pattern[i];
	return max;
}
void par_ab(int n, double pattern[], int &min, int &max)
{
	min = min_elements(n,pattern) - 1 ;
	max = max_elements(n,pattern) + 1 ;
}
void output(int min, int max)
{
	cout << "[" << min << ", " << max << "]" ;
}
