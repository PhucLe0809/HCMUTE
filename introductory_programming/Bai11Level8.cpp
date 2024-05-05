#include <bits/stdc++.h>

using namespace std;
void input(int &n, int pattern[]);
int ODD(int scan);
int ODD_min(int n, int pattern[]);
void output(int answer);

int main ()
{
	int n ;
	int arr[9999];
	input(n,arr);
	int answer = ODD_min(n,arr);
	output(answer);
	return 0;
}
void input(int &n, int pattern[])
{
	cin >> n;
	for (int i = 0 ; i<n; i++)
		cin >> pattern[i];
}
int ODD(int scan)
{
	int t = 0;
	if (scan%2 == 0)
		t = 1;
	return t;
}
int ODD_min(int n, int pattern[])
{
	int min = -1;
	for (int i = 0 ; i<n; i++)
		if (ODD(pattern[i]) == 1)
		{
			min = pattern[i];
			break;
		}
	for (int i = 0 ; i<n; i++)
		if (ODD(pattern[i]) == 1 && min > pattern[i])
			min = pattern[i];
	return min;
}
void output(int answer)
{
	cout << answer;
}
