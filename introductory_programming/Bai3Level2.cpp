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
	return min(min(x, y), z);
}
void output(int out)
{
	cout << out;
}
