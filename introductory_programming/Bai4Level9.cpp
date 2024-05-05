#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double pattern[]);
double absolute(double arr);
void work(int n, double pattern[]);
void output(double arr);

int main ()
{
	int n;
	double arr[9999];
	input(n,arr);
	work(n,arr); 
	return 0;
}
void input(int &n, double pattern[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
double absolute(double arr)
{
	if (arr>=0)
		return arr;
	else 
	{
		arr = arr * -1 ;
		return arr;
	}
} 
void work(int n, double pattern[])
{
	for (int i = 0; i<n-1;i++)
		if (pattern[i] > absolute(pattern[i+1]))
			output(pattern[i]);
}
void output(double arr)
{
	cout << arr << " " ;
}
