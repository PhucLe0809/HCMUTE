#include <bits/stdc++.h>

using namespace std ;

void input(int &n , int pattern[]);
int perfect(int scan);
int perfect_min(int n, int pattern[]);
void output(int answer);

int main ()
{
	int n ;
	int arr[99999];
	input(n,arr);
	int answer = perfect_min(n,arr);
	output(answer);
	return 0;
}
void input(int &n, int pattern[])
{
	cin >> n ;
	for (int i = 0 ; i<n ; i++)
		cin >> pattern[i];
}
int perfect(int scan)
{
	int t = 0;
	int tmp = 0;
	for (int i = 1 ; i <= scan/2; i++)
		if (scan%i == 0)
			tmp = tmp + i ;
	if (tmp == scan)
		t = 1 ;
	return t ;		
}
int perfect_min(int n, int pattern[])
{
	int min = 0;
	for (int i = 0 ; i<n ; i++)
		if (perfect(pattern[i]) == 1)
		{
			min = pattern[i];
			break;
		}
	for (int i = 0 ; i<n ; i++)
		if (perfect(pattern[i]) == 1 && min > pattern[i])
			min = pattern[i];
	return min;
}
void output(int answer)
{
	cout << answer ;
}
