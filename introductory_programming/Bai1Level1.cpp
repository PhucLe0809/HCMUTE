#include <bits/stdc++.h>

using namespace std;
void input(int &x, int &y);
int calculator(int x, int y);
void output(int out);

int main()
{
	int a, b;
	input(a, b);
	int s = calculator(a, b);
	output(s);
	return 0;
}
void input(int &x, int &y)
{
	cin >> x >> y;
}
int calculator(int x, int y)
{
	return x + y;
}
void output(int out)
{
	cout << out;
}

