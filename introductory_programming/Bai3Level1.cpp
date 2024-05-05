#include <bits/stdc++.h>

using namespace std;
double a, b, answer;
void input(double &x, double &y);
double calculator(double x, double y);
void output(double out);

int main()
{
	input(a, b);
	answer = calculator(a, b);
	output(answer);
	return 0;
}
void input(double &x, double &y)
{
	cin >> x >> y;
}
double calculator(double x, double y)
{
	return (x + y)*2;
}
void output(double out)
{
	cout << setprecision(2) << fixed << out;
}
