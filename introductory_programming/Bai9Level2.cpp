#include <bits/stdc++.h>

using namespace std;
void input(int &x, int &y, int &z);
int calculator(int x, int y, int z);
void output(int out);

int main()
{
	int a, b, c;
	input(a, b, c);
	int answer = calculator(a, b, c);
	output(answer);
	return 0;
}
void input(int &x, int &y, int &z)
{
	cin >> x >> y >> z;
}
int calculator(int x, int y, int z)
{
	if (x > y) swap(x, y);
	if (x > z) swap(x, z);
	if (y > z) swap(y, z);
	return y;
}
void output(int out)
{
	cout << out;
}
