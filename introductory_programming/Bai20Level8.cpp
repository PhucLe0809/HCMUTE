#include <bits/stdc++.h>

using namespace std;
void input(int arr[], int &mor);
void output(int arr[], int mor);

int main ()
{
	int mor,arr[1000];
	input(arr,mor);
	output(arr,mor);
	return 0;
}
void input(int arr[], int &mor)
{
	cin >> arr[0] >> arr[1];
	mor = 1;
	if (arr[1] - arr[0] > 0)
	{
		while(arr[mor] > arr[mor-1])
		{
			mor++;
			cin >> arr[mor];
		}
	}
	else
	{
		if (arr[1] - arr[0] < 0)
		{
			while(arr[mor] < arr[mor-1])
			{
				mor++;
				cin >> arr[mor];
			}
		}
	}
}
void output(int arr[], int mor)
{
	for (int i = 0; i<mor ;i++)
		cout << arr[i] << " ";
}
