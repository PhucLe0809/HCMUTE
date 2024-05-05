#include <bits/stdc++.h>

using namespace std;
void input(int &x, int &y);
int scan(int x, int y);
void output(int out);

int main()
{
	int month, year;
	input(month, year);
	int answer = scan(month, year);
	output(answer);
	return 0;
}
void input(int &x, int &y)
{
	cin >> x >> y;
}
int scan(int x, int y)
{
	switch (x)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		default:
			if (y % 4 == 0 && y % 100 != 0)
				return 29;
			else return 28;
	}
}
void output(int out)
{
	cout << out;
}
