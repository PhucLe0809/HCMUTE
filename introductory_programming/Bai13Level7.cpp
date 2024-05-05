#include <bits/stdc++.h>

using namespace std ;
void input(int &n , double pattern[]);
int find_odd(double arr);
void output(int n , double pattern[]);

int main ()
{
	int n ;
	double arr[9999];
	input (n,arr);
	output(n,arr);
	return 0;
}
void input(int &n , double pattern[])
{
	cin >> n ;
	for (int i = 0 ; i < n ; i++)
		cin >> pattern[i];
	
}
int find_odd(double arr)
{	
	int t = 1 ;
	while (arr>=10)
	{
		arr = int(arr) / 10;
	}
	if (int(arr)%2==0)
		t = 0;
	return t;
}
void output(int n , double pattern[])
{
	for (int i = 0 ; i < n ; i++)
		if (find_odd(pattern[i]) == 0)
			cout << pattern[i] << " ";
}

