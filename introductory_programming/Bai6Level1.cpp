#include <bits/stdc++.h>

using namespace std;
int h, m, s;
bool kt;
void input(int &x, int &y, int &z);
bool check(int x, int y, int z);
void output(bool test);

int main()
{
	input(h, m, s);
	kt = check(h, m, s);
	output(kt);
	return 0;
}
void input(int &x, int &y, int &z)
{
	cin >> x >> y >> z;
}
bool check(int x, int y, int z)
{
	if (x < 0 || x > 23 || y < 0 || y > 59 || z < 0 || z > 59)
		return false;
	else return true;
}
void output(bool test)
{
	if (test)
		cout << h << ":" << m << ":" << s << " la 1 bo thoi gian hop le!";
	else cout << "Khong tao thanh 1 bo thoi gian hop le!";
}
