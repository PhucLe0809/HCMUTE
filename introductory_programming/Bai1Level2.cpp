#include <bits/stdc++.h>

using namespace std;
void input(double &x, double &y);
double calculator(double x, double y);
void output(double out);

int main()
{
	double a, b;
	input(a, b);
	if (b == 0)
		cout << "ERROR!";
	else
	{
		double answer = calculator(a, b);
		output(answer);	
	}
	return 0;
}
void input(double &x, double &y)
{
	cin >> x >> y;
}
double calculator(double x, double y)
{
	return x/y;
}
void output(double out)
{
	cout << setprecision(2) << fixed << out;
}
