#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int &m, double arr[], double pattern[]);
void listed(int n, int m, double arr[], double pattern[]);
void output(double answer);

int main () 
{
	int n, m ;
	double arr[99999];
	double pattern[99999];
	input(n,m,arr,pattern);
	listed(n,m,arr,pattern); 
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
void listed(int n, int m, double arr[], double pattern[])
{
	int tam = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			if (arr[i] == pattern[j])
				tam++;
		if (tam == 0)
			output(arr[i]);
		tam = 0;
	}
	tam = 0;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			if (pattern[i] == arr[j])
				tam++;
		if (tam == 0)
			output(pattern[i]);
		tam = 0;
	}
}
void output(double answer)
{
	cout << answer << " ";
}

