#include <iostream>

using namespace std;
void input(int &n, int &m, int one[], int two[]);
void interleaved(int n, int m, int &l, int one[], int two[], int out[]);
void output(int l, int out[]);

int main ()
{
	int n,m,l;
	int one[99999];
	int two[99999];
	int out[99999];
	input(n,m,one,two);
	interleaved(n,m,l,one,two,out);
	output(l,out);
	return 0;
}
int fMin(int one, int two)
{
	int min = one;
	if (two < min)
		min = two;
	return min;
}
void input(int &n, int &m, int one[], int two[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> one[i];
	cin >> m;
	for (int i = 0; i<m; i++)
		cin >> two[i];
}
void interleaved(int n, int m, int &l, int one[], int two[], int out[])
{
	l = min(n,m) * 2 ;
	int nA = 0 ;
	int mB = 0;
	for (int i = 0 ; i<l; i++)
	{
		if(i % 2 == 0)
		{
			out[i] = one[nA];
			nA++;
		}
		if(i % 2 != 0)
		{
			out[i] = two[mB];
			mB++;
		}	
	}
	l = m + n;
	for (int j = min(n,m) * 2 ; j<l; j++)
	{
		if (n>m)
		{
			out[j] = one[nA];
			nA++;
		}
		if (m>n)
		{
			out[j] = two[mB];
			mB++;
		}
	}	
}
void output(int l, int out[])
{
	for (int i = 0; i<l; i++)
		cout << out[i] << " ";
}
