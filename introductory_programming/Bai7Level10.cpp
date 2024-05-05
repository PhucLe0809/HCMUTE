#include <bits/stdc++.h>

using namespace std;
void input(int &n, int &pos, char str[]);
void substring(int n, int pos, char str[], char ansi[]);
void output(int pos, char ansi[]);

int main ()
{
	int n,pos;
	char str[1000], ansi[1000];
	input(n,pos,str);
	substring(n,pos,str,ansi);
	output(pos,ansi);
	return 0;
}
void input(int &n, int &pos, char str[])
{
	cin >> n >> pos >> str;
}
void substring(int n, int pos, char str[], char ansi[])
{
	int len = 0;
	for (int i = pos; i<pos+n; i++)
	{
		if (i == len)
			break;
		else
		{
			ansi[len] = str[i];
			len++;
		}
	}
}
void output(int pos, char ansi[])
{
	for (int i = 0; i<pos; i++)
		cout << ansi[i];
}
