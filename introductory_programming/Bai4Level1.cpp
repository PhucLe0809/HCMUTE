#include <bits/stdc++.h>

using namespace std;
int a, b, answer;
void input(int &x, int &y);
int calculator(int x, int y);
void output(int out);

int main()
{
	input(a, b);
	answer = calculator(a, b);
	output(answer);
	return 0;
}
void input(int &x, int &y)
{
	cin >> x >> y;
}
int calculator(int x, int y)
{
	return max(x, y);
}
void output(int out)
{
	cout << out;
}
