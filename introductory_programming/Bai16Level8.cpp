#include <bits/stdc++.h>

using namespace std;
void input(int &n, int &pos, int arr[], int &number, int &m);
void scan(int n, int &m, int pos, int arr[], int number);
void output(int m, int arr[]);

int main ()
{
	int n,pos,m,number;
	int arr[1000];
	input(n,pos,arr,number,m);
	scan(n,m,pos,arr,number);
	output(m,arr);
	return 0;
}
void input(int &n, int &pos, int arr[], int &number, int &m)
{
	cout << "1. Delete i place  " << endl;
	cout << "2. insert  integer number to i place" << endl;
	cin >> n;
	if (n == 1)
	{
		cin >> m >> pos;
		for (int i = 0; i<m; i++)
			cin >> arr[i];
	}
	else 
	{
		cin >> m >> number >> pos;
		for (int i = 0; i<m; i++)
			cin >> arr[i];
	}	
}
void scan(int n, int &m, int pos, int arr[], int number)
{
	if (n == 1)
	{
		for (int i = pos; i<m-1; i++)
			arr[i] = arr[i+1];
		m--;
	}
	else 
	{
		for (int i = m ; i >= pos; i--)
		{
			arr[i] = arr[i-1];
			if (i == pos)
				arr[i] == number;
		}
		m++;
	}
}
void output(int m, int arr[])
{
	for (int i = 0; i<m; i++)
		cout << arr[i] << " ";
}
