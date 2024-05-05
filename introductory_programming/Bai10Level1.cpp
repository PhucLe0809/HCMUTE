#include <bits/stdc++.h>

using namespace std;
double n;
int answer;
void input(double &x);
int scan(double x);
void output(int out);

int main()
{
	input(n);
	answer = scan(n);
	output(answer);
}
void input(double &x)
{
	cin >> x;
}
int scan(double x)
{
	int tmp = int(x);
	if (tmp - x == 0) 
		if (tmp > 0)
			tmp--;
		else tmp++;
	return tmp;
}
void output(int out)
{
	cout << out;
}
