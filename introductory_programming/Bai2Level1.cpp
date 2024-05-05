#include <bits/stdc++.h>

using namespace std;
int n, answer;
void input(int &x);
int calculator(int m);
void output(int out);

int main()
{
	input(n);
	answer = calculator(n);
	output(answer);
	return 0;
}
void input(int &x)
{
	cin >> x;
}
int calculator(int m)
{
	return abs(m);
}
void output(int out)
{
	cout << out;
}

