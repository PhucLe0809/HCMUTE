#include <bits/stdc++.h>

using namespace std ;

void input(int &n, int pattern[]);
void GCD(int scan ,int divisors[], int &amount);
int search(int n, int pattern[]);
int gcd_array(int n, int pattern[]);
void output(int answer);

int main ()
{
	int n;
	int arr[9999];
	input(n,arr);
	int answer = gcd_array(n,arr);
	output(answer);
	return 0;
}
void input(int &n, int pattern[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> pattern[i];
}
void GCD(int scan ,int divisors[], int &amount)
{
	amount = 0;
	for (int i = 1; i<=scan; i++)
		if (scan % i == 0)
		{
			divisors[amount] = i ;
			amount++;
		}
}
int search(int n, int pattern[])
{
	int t = pattern[0];
	for (int i = 1 ; i<n ; i++)
		if (t > pattern[i])
			t = pattern[i];
	return t;
}
int gcd_array(int n, int pattern[])
{
	int cnt = 0;
	int divisors[9999];
	int amount;
	int min = search(n,pattern);
	GCD(min,divisors,amount);
	for (int i = amount - 1; i>=0; i--)
	{
		for (int j = 0; j < n ; j++)
			if (pattern[j] % divisors[i] == 0)
				cnt++;
		if (cnt == n)
			return divisors[i];
		cnt = 0;
	}
}
void output(int answer)
{
	cout << answer;
}
