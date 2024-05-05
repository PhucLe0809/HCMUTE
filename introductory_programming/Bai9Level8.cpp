#include <bits/stdc++.h>

using namespace std;
void input(int &n, int pattern[]);
int prime(int scan);
int prime_max(int n, int pattern[]);
void output(int answer);

int main ()
{
	int n ;
	int arr[9999];
	input(n,arr);
	int answer = prime_max(n,arr);
	output(answer);
	return 0;
}
void input(int &n, int pattern[])
{
	cin >> n ;
	for (int i = 0; i<n ; i++)
		cin >> pattern[i];
}
int prime(int scan)
{
	int t = 1;
	if (scan==0 || scan==1)
		t = 0 ;
	for (int i = 2 ; i < scan; i++)
		if (scan%i == 0)
			t = 0 ;
	return t;
}
int prime_max(int n, int pattern[])
{
	int max = 0;
	for (int i = 0 ; i<n; i++)
		if (prime(pattern[i]) == 1)
			max = pattern[i];
	for (int i = 0 ; i<n; i++)
		if (prime(pattern[i]) == 1 && max < pattern[i])
			max = pattern[i];
	return max;
}
void output(int answer)
{
	cout << answer;
}
