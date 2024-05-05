#include <bits/stdc++.h>

using namespace std ;
void input(int &m, int &n, double one[], double two[]);
void appearAandB(int m, int n, int &l, double one[], double two[], double three[]);
void xoa(int &l, double three[], int place);
void swap(double &one, double &two);
void sort_array(int l, double three[]);
void output(int l, double three[]);
void erase_duplicate(int &l, double three[]);

int main ()
{
	int m, n, l;
	double one[9999];
	double two[9999];
	double three[9999];
	input(m,n,one,two);
	appearAandB(m,n,l,one,two,three);
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
void appearAandB(int m, int n, int &l, double one[], double two[], double three[])
{
	int tam = 0 ;
	l = 0 ;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
			if (one[i] == two[j])
				tam++;
		if (tam != 0)
		{
			three[l] = one[i];
			l++;
		}
		tam = 0 ;
	}
	sort_array(l,three);
	erase_duplicate(l,three);
}
void xoa(int &l, double three[], int place)
{
	for (int i = place; i<l; i++)
		three[i] = three[i+1];
	l--;
}
void erase_duplicate(int &l, double three[])
{
	for (int i = 0; i<l; i++)
		if (three[i] == three[i+1])
		{
			xoa(l,three,i+1);
			i--;
		}			
}
void swap(double &one, double &two)
{
	double t = one;
	one = two ;
	two = t;
}
void sort_array(int l, double three[])
{
	for (int i = 0; i<l; i++)
		for (int j = 0; j<l; j++)
			if (three[i]<three[j])
				swap(three[i],three[j]);
}
void output(int l, double three[])
{
	for (int i = 0; i<l; i++)
		cout << three[i] << " " ;
}
