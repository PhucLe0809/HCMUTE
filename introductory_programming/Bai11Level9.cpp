#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int &m, double arr[], double pattern[]);
int sub(int n, int m, double arr[], double pattern[]);
void output(int answer);

int main ()
{
	int n, m;
	double arr[99999];
	double pattern[99999];
	input(n,m,arr,pattern);
	int answer = sub(n,m,arr,pattern); 
	output(answer);
	return 0;
}
void input(int &n, int &m, double arr[], double pattern[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
	cin >> m ;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
int sub(int n, int m, double arr[], double pattern[])
{
	int tmp = 0 ;
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			if (arr[i]==pattern[j])
				tmp++;
		if (tmp != 0)
			cnt++;
		tmp = 0;
	}
	if (cnt == n)
		return 1;
	else 
		return 0;
}
void output(int answer)
{
	if (answer == 1)
		cout << "True";
	else 
		cout << "False";
}
