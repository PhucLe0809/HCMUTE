#include <bits/stdc++.h>

using namespace std;
void input(int &n, int one[], int two[]);
void interleaved(int &n, int one[], int two[], int three[]);
void output(int n, int three[]);

int main ()
{
	int n;
	int one[9999];
	int two[9999];
	int three[9999];
	input(n,one,two);
	interleaved(n,one,two,three);
	output(n,three);
	return 0;
}
void input(int &n, int one[], int two[])
{
	cin >> n ;
	for(int i = 0 ; i<n ; i++)
		cin >> one[i];
	for(int i = 0 ; i<n ; i++)
		cin >> two[i];
}
void interleaved(int &n, int one[], int two[], int three[])
{
	n = n * 2;
	int j = 0;
	int k = 0;
	for (int i = 0 ; i<n ; i++)
	{
		if (i % 2 == 0)
		{
			three[i] = one[k];
			k++;
		}
		if (i % 2 != 0)
		{
			three[i] = two[j];
			j++;
		}
	}
}
void output(int n, int three[])
{
	for (int i = 0; i<n; i++)
		cout << three[i] << " " ;
}
