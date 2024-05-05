#include <bits/stdc++.h>

using namespace std;

void input(int &n1, int one[]);
void divideArray(int n1, int &n2, int &n3, int one[], int two[], int three[]);
void output(int n2, int n3, int two[], int three[]);

int main ()
{
	int n1,n2,n3;
	int one[99999];
	int two[99999];
	int three[99999];
	input(n1,one);
	divideArray(n1,n2,n3,one,two,three);
	output(n2,n3,two,three);
	return 0;
}
void input(int &n1, int one[])
{
	cin >> n1;
	for (int i = 0; i<n1; i++)
		cin >> one[i];
}
void divideArray(int n1, int &n2, int &n3, int one[], int two[], int three[])
{
		// So Duong
	int j = 0 ;
	for (int i = 0; i<n1; i++)
		if (one[i] >= 0)
		{
			two[j] = one[i];
			j++;
		}
	n2 = j;
		// SO AM
	int k = 0 ;
	for (int i = 0; i<n1; i++)
		if (one[i] < 0)
		{
			three[k] = one[i];
			k++;
		}
	n3 = k;
}
void output(int n2, int n3, int two[], int three[])
{
	for (int i = 0; i<n2; i++)
		cout << two[i] << " " ;
	cout << endl;
	for (int i = 0; i<n3; i++)
		cout << three[i] << " " ;
	
}

