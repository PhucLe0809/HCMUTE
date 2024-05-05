#include <bits/stdc++.h>

using namespace std;
void input(double &x, double &y, double &z);
int scan(double x, double y, double z);
void output(int out);

int main()
{
	double a, b, c;
	input(a, b, c);
	int answer = scan(a, b, c);
	output(answer);
	return 0; 
}
void input(double &x, double &y, double &z)
{
	cin >> x >> y >> z;
}
int scan(double x, double y, double z)
{
	if (x + y <= z || x + z <= y || y + z <= x)
		return 0;
	else
	{
		int test;
		if (x == y || y == z || z == x) test = 1;
		if (x == y && y == z) test = 2;
		if (x*x == y*y + z*z || y*y == x*x + z*z || z*z == x*x + y*y) test = 3;
		if (test == 3 && (x == y || y == z || z == x)) test = 4;
		return test;
	}
}
void output(int out)
{
	switch (out)
	{
		case 0: cout << "KHONG LAP THANH TAM GIAC"; break;
		case 1: cout << "TAM GIAC CAN"; break;
		case 2: cout << "TAM GIAC DEU"; break;
		case 3: cout << "TAM GIAC VUONG"; break;
		case 4: cout << "TAM GIAC VUONG CAN"; break;
	}
}
