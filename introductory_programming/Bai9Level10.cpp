#include <bits/stdc++.h>

using namespace std;
void input(char normal[]);
void upcase_first(char normal[]);
void output(char normal[]);

int main ()
{
	char normal[99999];
	input(normal);
	upcase_first(normal);
	output(normal);
	return 0;
}
void input(char normal[])
{
	gets(normal);
}
void upcase_first(char normal[])
{
	int len = strlen(normal);
	if (normal[0] != ' ')
		normal[0] = int(normal[0]) -32;
	for (int i = 0; i<len; i++)
		if (normal[i-1] == ' ' && normal[i] != ' ' )
			normal[i] = int(normal[i]) -32;
}
void output(char normal[])
{
	cout << normal;
}
