#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int update(int scan);
void output(int n , int pattern[]); 	

int main ()
{
	int n ;
	int arr[9999];
	input(n,arr);
	output(n,arr);
	return 0;
}
void input(int &n, int pattern[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
int update(int scan)
{
	int t = 0 ;
	int tmp;
	int max = scan % 10;
	
	while (scan>0) 
	{
		scan = scan / 10 ;
		tmp = scan % 10;
		if (max > tmp)
			t = 1;
		else
			return 0;
	return t;
	}
}
void output(int n , int pattern[])
{
	for (int i = 0 ; i < n ; i++)
		if (update(pattern[i])==1)
			cout << pattern[i]<<" update" << endl;
		else 
			cout << pattern[i]<<" NoUp" << endl;
}
