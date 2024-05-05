#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double pattern[], double &pos);
double min_negative(int n, double pattern[], double pos);
void output(double answer);

int main ()
{
	int n;
	double pos;
	double arr[99999];
	input(n,arr,pos);
	double result = min_negative(n,arr,pos);
	output(result);
	return 0;
}
void input(int &n, double pattern[], double &pos)
{
	cin >> n ;
	for (int i = 0 ; i<n ; i++)
		cin >> pattern[i];
	cin >> pos;
}
double min_negative(int n, double pattern[], double pos)
{
	double max = 0;
	for (int i = n - 1; i>=0; i--)
		if (pattern[i] < 0 && pattern[i]>pos)
		{
			max = pattern[i];
			break;
		}
	return max;
}
void output(double answer)
{
	cout << answer;
}
