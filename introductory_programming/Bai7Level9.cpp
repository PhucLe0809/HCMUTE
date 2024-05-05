#include <bits/stdc++.h>

using namespace std;
void input(int &n, double arr[]);
double find_max(int n, double arr[]);
int cnt_max(int n, double arr[]);
void output(int answer);

int main ()
{
	int n ;
	double arr[9999];
	input(n,arr);
	int answer = cnt_max(n,arr);
	output(answer);
	return 0;
}

void input(int &n, double arr[])
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> arr[i]; 
}
double find_max(int n, double arr[])
{
	double max = arr[0];
	for (int i = 1; i<n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
int cnt_max(int n, double arr[])
{
	int cnt = 0;
	double max = find_max(n,arr);
	for (int i = 1; i<n; i++)
		if (max == arr[i])
			cnt++;
	return cnt;
}
void output(int answer)
{
	cout << answer ;
}
