#include <bits/stdc++.h>

using namespace std;
void input(int &n, double arr[]);
void swap(double &scan, double &tmp);
void __sort(int n, double arr[]);
void max_appear(int &n, double arr[]);
void output(double out);

int main()
{
	int n;
	double arr[9999];
	input(n,arr);
	max_appear(n,arr);
	return 0;
}
void input(int &n, double arr[])
{
	cin >> n ;
	for (int i = 0; i<n; i++)
		cin >> arr[i];
}
void swap(double &scan, double &tmp)
{
	double t = scan;
	scan = tmp ;
	tmp = t ;
}
void __sort(int n, double arr[])
{
	for (int i = 0 ; i<n; i++)
		for (int j = i+1; j<n; j++)
			if (arr[i] > arr[j])
				swap(arr[i],arr[j]);
}
void max_appear(int &n, double arr[])
{
	__sort(n,arr);
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		while (arr[i] == arr[i+1])
		{
			cnt++;
			i++;
		}
		if (cnt != 0)
			output(arr[i]);
		cnt = 0;
	}
}
void output(double out)
{
	cout << out << " ";
}
