#include <bits/stdc++.h>

using namespace std;
char ch, answer;
void input(char &x);
char convert(char x);
void output(char out);

int main()
{
	input(ch);
	answer = convert(ch);
	output(answer);
	return 0;
}
void input(char &x)
{
	cin >> x;
}
char convert(char x)
{
	if ('a' <= x && x <= 'z')
		return char(int(x) - 32);
	else return char(int(x) + 32);
}
void output(char out)
{
	cout << out;
}
