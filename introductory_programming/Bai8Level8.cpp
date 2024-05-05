#include <bits/stdc++.h>

using namespace std ;

void input(int &n, double pattern[]);
double search(int n, double pattern[]);
void output(double answer);

int main ()
{
	int n ;
	double arr[99999];
	input(n, arr);
	double answer = search(n,arr);
	output(answer);
	return 0 ;
}
void input(int &n, double pattern[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
double search(int n, double pattern[])
{
	double max = 0;
	for (int i = 0 ; i<n; i++)
		if (pattern[i] * 1 < 0)
		{
			max = pattern[i];
			break;
		}
	for (int i = 0 ; i<n; i++)
		if (pattern[i] * 1 < 0 && max < pattern[i])
			max = pattern[i]; 
	return max;		
}
void output(double answer)
{
	cout << answer;
}
