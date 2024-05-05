#include <bits/stdc++.h>

using namespace std;
double a, b, c;
bool kt;
void input(double &x, double &y, double &z);
bool check(double x, double y, double z);
void output(bool test);

int main()
{
	input(a, b, c);
	kt = check(a, b, c);
	output(kt);
	return 0;
}
void input(double &x, double &y, double &z)
{
	cin >> x >> y >> z;
}
bool check(double x, double y, double z)
{
	if (x+y>z && x+z>y && y+z>x)
		return true;
	else return false;
}
void output(bool test)
{
	if (test)
		cout << "Bo ba so lap thanh tam giac!";
	else cout << "Khong lap thanh tam giac!";
}
