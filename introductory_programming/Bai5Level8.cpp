#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double pattern[]);
int tick(int n ,double pattern[]);
void output(int answer);

int main ()
{
	int n ;
	double arr[9999];
	input(n,arr);
	int answer = tick(n,arr);
	output(answer);
	return 0;
}
void input(int &n, double pattern[])
{
	cin >> n ;
	for (int i = 0 ; i < n ; i++)
		cin >> pattern[i];
}
int tick(int n ,double pattern[])
{
	int t = 0 ;
	for (int i = 1 ; i < n - 1 ; i++)
		if (pattern[i] != pattern[i-1] && pattern[i] != pattern[i+1])
			t = 1 ;
		else 
		{
			t = 0;
			break;
		}
	return t;
}
void output(int answer)
{
	if (answer==1)
		cout << "True";
	else 
		cout << "False";
}
