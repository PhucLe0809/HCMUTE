#include <bits/stdc++.h>

using namespace std ;

void input(int &n, int &m, double arr[], double pattern[]);
int scanA(int n, int m, double arr[], double pattern[]);
int scanB(int n, int m, double arr[], double pattern[]);
int scan(int n, int m, double arr[], double pattern[]);
void output(int answer);

int main () 
{
	int n, m ;
	double arr[99999];
	double pattern[99999];
	input(n,m,arr,pattern);
	int answer = scan(n,m,arr,pattern); 
	output(answer);
	return 0;	
}
void input(int &n, int &m, double arr[], double pattern[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
	cin >> m;
	for (int i = 0; i<m; i++)
		cin >> pattern[i];
}
int scanA(int n, int m, double arr[], double pattern[])
{
	int cnt = 0;
	int tmp = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			if (arr[i] == pattern[j])
				tmp++;
		if (tmp == 0)
			cnt++;
		tmp = 0;
	}
	return cnt ;
}
int scanB(int n, int m, double arr[], double pattern[])
{
	int cnt = 0;
	int tmp = 0;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			if (pattern[i] == arr[j])
				tmp++;
		if (tmp == 0)
			cnt++;
		tmp = 0;
	}
	return cnt ;
}
int scan(int n, int m, double arr[], double pattern[])
{
	int cnt = scanA(n,m,arr,pattern) + scanB(n,m,arr,pattern);
	return cnt;
}
void output(int answer)
{
	cout << answer;
}

