#include <bits/stdc++.h>

using namespace std;
void input(int &x, int &y, int &z);
void scan(int &x, int &y, int &z);
void output(int x, int y, int z);

int main()
{
	int a, b, c;
	input(a, b, c);
	scan(a, b, c);
	output(a, b, c);
	return 0;
}
void input(int &x, int &y, int &z)
{
	cin >> x >> y >> z;
}
void scan(int &x, int &y, int &z)
{
	z = (++z) % 60;
	if (z == 0)
	{
		y = (++y) % 60;
		if (y == 0)
		{
			x = (++x) % 24;
		}
	}
}
void output(int x, int y, int z)
{
	cout << x << ":" << y << ":" << z;
}
