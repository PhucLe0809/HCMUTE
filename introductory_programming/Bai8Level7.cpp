#include <bits/stdc++.h>

using namespace std;
void input(int &n , int pattern[]);
int check(int n ,int pattern[]);
void output(int answer);

int main ()
{
	int n ;
	int arr[9999];
	input(n, arr);
	int answer = check(n, arr);
	output(answer);
	return 0;
}
void input(int &n , int pattern[])
{
	cin >> n ;
	for (int i = 0; i < n; i++)
		cin >> pattern[i];
}
int check(int n ,int pattern[])
{
	int t = 1;
	int tam = pattern[1] - pattern[0];
	for (int i = 1 ; i < n - 1 ; i++)
		if (pattern[i+1] - pattern[i] != tam)	
		{
			t = 0 ;
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
