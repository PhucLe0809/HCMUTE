#include <bits/stdc++.h>

using namespace std ;
void input(int &m, int &n, double one[], double two[]);
void no_relation(int m, int n, int &l, double one[], double two[], double three[]);
void output(int l, double three[]);

int main ()
{
	int m, n, l;
	double one[9999];
	double two[9999];
	double three[9999];
	input(m,n,one,two);
	no_relation(m,n,l,one,two,three);
	output(l,three);
	return 0;	
}
void input(int &m, int &n, double one[], double two[])
{
	cin >> m ;
	for (int i = 0; i<m; i++)
		cin >> one[i];
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> two[i];
}
void no_relation(int m, int n, int &l, double one[], double two[], double three[])
{
	int tmp = 0 ;
	l = 0 ;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			if (one[i] == two[j])
				tmp++;
		if (tmp == 0)
		{
			three[l] = one[i];
			l++;
		}
		tmp = 0 ;
	}
}
void output(int l, double three[])
{
	for (int i = 0; i<l; i++)
		cout << three[i] << " " ;
}
