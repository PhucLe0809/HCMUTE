#include <bits/stdc++.h>

using namespace std ;
void input(int &n, double arr[]);
void swap(double &scan, double &tmp);
void __sort(int n, double arr[]);
void frequence(int n, double arr[]);
void output(double scan, int cnt);

int main()
{
	int n;
	double arr[9999];
	input(n,arr);
	frequence(n,arr);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++ )
		cin >> arr[i];
}
void swap(double &scan, double &tmp)
{
	double t = scan ;
	scan = tmp ;
	tmp = t;
}
void __sort(int n, double arr[])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (arr[i] < arr[j])
				swap(arr[i],arr[j]);
}
void frequence(int n, double arr[])
{	
	__sort(n,arr);
	int j;
	int cnt = 1;
	for (int i = 0; i<n; i++)
	{	
		j = i + 1;
		while (arr[i] == arr[j])
		{
			cnt++;
			j++;
		}
		output(arr[i],cnt);
		cnt = 1 ;
		i = j - 1;
		
	}
}
void output(double scan, int cnt)
{
	cout << scan << " " << cnt << " " << endl;
}
