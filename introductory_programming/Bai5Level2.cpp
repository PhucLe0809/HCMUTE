#include <bits/stdc++.h>

using namespace std;
void input(int &x, int &y, int &z, int &t);
int calculator(int x, int y, int z, int t);
void output(int out);

int main()
{
	int a, b, c, d;
	input(a, b, c, d);
	int answer = calculator(a, b, c, d);
	output(answer);
	return 0;
}
void input(int &x, int &y, int &z, int &t)
{
	cin >> x >> y >> z >> t;
}
int calculator(int x, int y, int z, int t)
{
	return max(max(x, y), max(z, t));
}
void output(int out)
{
	cout << out;
}
