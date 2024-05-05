#include <bits/stdc++.h>

using namespace std;
void input(int &lft, int &rght, double arr[]);
void scan(int lft, int rght, double arr[]);
void output(int lft, double arr[]);

int main ()
{
	int lft,rght;
	double arr[9999];
	input(lft,rght,arr);
	scan(lft,rght,arr);
	output(lft,arr);
	return 0;
}
void input(int &lft, int &rght, double arr[])
{
	cin >> lft ;
	for (int i = 0; i<lft; i++)
		cin >> arr[i];
	cin >> rght;
}
void scan(int lft, int rght, double arr[])
{
	while (rght > 0)
	{
		arr[-1] = arr[lft-1];
		for (int i = lft-1 ; i>=0; i--)
			arr[i] = arr[i-1];
		rght--;
	}
}
void output(int lft, double arr[])
{
	for (int i = 0; i<lft; i++)
		cout << arr[i] << " ";
}

