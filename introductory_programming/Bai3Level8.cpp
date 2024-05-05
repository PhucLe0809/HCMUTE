#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int b[]);
int near_h(int scan);
int near_h_first(int n, int b[]);
void output(int answer , int b[]);

int main ()
{
	int n ;
	int arr[9999];
	input(n,arr);
	int answer = near_h_first(n,arr);
	output(answer,arr);
	return 0;
}
void input(int &n, int b[])
{
	cin >> n ;
	for (int i = 0 ; i < n ;i++)
		cin >> b[i];
}
int near_h(int scan)
{
	int t = 0 ;
	int tmp1 = scan;
	int tmp2 = tmp1 % 10 ;
	int soDao = 0;
	while (tmp1>0)
	{
		soDao = soDao * 10 + tmp2;
		tmp1 = tmp1 / 10;
		tmp2 = tmp1 % 10;
	}
	if (soDao == scan)
		t = 1;
	return t;
}
int near_h_first(int n, int b[])
{
	int t = -1 ;
	for (int i = 0 ; i<n ; i++)
		if (near_h(b[i])==1)
		{
			t = i ;
			break ;
		}
	return t;
}
void output(int answer , int b[])
{
	if (answer == -1)
		cout << "No result";
	else 
		cout << b[answer];
}
