#include <bits/stdc++.h>

using namespace std;
void input(int &n, double pattern[], double &pos);
void swap(double &scan, double &tmp);
void __sort(int n, double pattern[]);
void insert_num(int &n, double pattern[], double pos);
void output(int n, double pattern[]);

int main()
{
	int n ;
	double arr[9999];
	double pos;
	input(n,arr,pos);
	insert_num(n,arr,pos);
	output(n,arr);
	return 0;
}
void input(int &n, double pattern[], double &pos)
{
	cin >> n ;
	for (int i = 0 ; i<n ; i++)
		cin >> pattern[i];
	cin >> pos;
}
void swap(double &scan, double &tmp)
{
	double t = scan;
	scan = tmp;
	tmp = t;
}
void __sort(int n, double pattern[])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n ;j++)
			if (pattern[j]>pattern[i])
				swap(pattern[i],pattern[j]);
}
void insert_num(int &n, double pattern[], double pos)
{
	pattern[n] = pos;
	n++;
	for (int i = 0 ; i<n ; i++)
		__sort(n,pattern);
}
void output(int n, double pattern[])
{
	for (int i = 0 ; i<n; i++)
		cout << pattern[i] << " " ;
}
