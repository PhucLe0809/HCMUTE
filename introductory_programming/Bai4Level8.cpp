#include <bits/stdc++.h>

using namespace std ;
void input(int &n , int pattern[]);
int odd(int scan);
int odd_first(int n, int pattern[]);
void output(int answer);

int main ()
{
	int n;
	int arr[9999] ;
	input(n,arr);
	int answer = odd_first(n,arr);
	output(answer);
	return 0;
}
void input(int &n , int pattern[])
{
	cin >> n ;
	for (int i = 0 ; i < n ; i++)
		cin >> pattern[i];
}
int odd(int scan)
{
	int t = 0 ;
	int tmp ;
	while (scan > 0)
	{
		tmp = scan % 10 ;
		scan = scan / 10 ;
	}
	if (tmp % 2 != 0)
		t = 1;
	return t;
}
int odd_first(int n, int pattern[])
{
	int t = 0;
	for (int i = 0 ; i<n ; i++)
		if (odd(pattern[i]) == 1)
		{
			t = pattern[i];
			break;
		}
	return t;
}
void output(int answer)
{
	cout << answer ;
}
