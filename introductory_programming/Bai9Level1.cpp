#include <bits/stdc++.h>

using namespace std;
double n;
int answer;
void input(double &x);
int convert(double x);
void output(int out);

int main()
{
	input(n);
	answer = convert(n);
	output(answer);
	return 0;
}
void input(double &x)
{
	cin >> x;
}
int convert(double x)
{
	return round(x);
}
void output(int out)
{
	cout << out;
}
