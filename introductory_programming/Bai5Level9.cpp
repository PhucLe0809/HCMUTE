#include <bits/stdc++.h>

using namespace std;
void input(int &normal, double arr[]);
void work(int normal, double arr[]);
void output(double arr);
int main ()
{
	int normal;
	double arr[9999];
	input(normal,arr);
	work(normal,arr); //Liet ke cac so lan can trai dau
	return 0;
}
void input(int &normal, double arr[])
{
	cin >> normal;
	for (int run = 0; run<normal; run++)
		cin >> arr[run];
}
void work(int normal, double arr[])
{
	for (int run = 0; run<normal; run++)
		if (arr[run]*arr[run+1] < 0 || arr[run]*arr[run-1] < 0)
			output(arr[run]);
}
void output(double arr)
{
	cout << arr << " ";
}
