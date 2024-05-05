#include <bits/stdc++.h>

using namespace std;
void input(double &x, double &y, double &z);
void calculator(double x, double y, double z);

int main()
{
	double a, b, c;
	input(a, b, c);
	calculator(a, b, c);
	return 0; 
}
void input(double &x, double &y, double &z)
{
	cin >> x >> y >> z;
}
void calculator(double x, double y, double z)
{
	if (x == 0)
	{	
		if (y == 0)
		{
			if (z == 0)
				cout << "PHUONG TRINH VO SO NGHIEM";
			else cout << "PHUONG TRINH VO NGHIEM";
		}
		else
		{
			double x = -z/y;
			cout << setprecision(2) << fixed << x;
		}
	}
	else
	{
		double delta = y*y - 4*x*z;
		double x1 = (-y + sqrt(delta))/(2*x);
		double x2 = (-y - sqrt(delta))/(2*x);
		cout << setprecision(2) << fixed << x1 << " " << x2;
	}
}
