#include <bits/stdc++.h>

using namespace std;
int n;
bool kt;
void input(int &x);
bool check(int x);
void output(bool test);

int main()
{
	input(n);
	kt = check(n);
	output(kt);
	return 0;
}
void input(int &x)
{
	cin >> x;
}
bool check(int x)
{
	if (x % 4 == 0 && x % 100 != 0)
		return true;
	else return false;
}
void output(bool test)
{
	if (test)
		cout << n << " la mot nam NHUAN!";
	else cout << n << " khong la mot nam NHUAN!";
}
