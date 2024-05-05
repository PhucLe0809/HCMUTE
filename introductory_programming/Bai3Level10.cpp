#include <bits/stdc++.h>

using namespace std ;
void input(char normal[]);
void swap(char arr[], char pattern[]);
void reverse_char(char normal[]);
void output(char normal[]);

int main ()
{
	char normal[9999];
	input(normal);
	reverse_char(normal);
	output(normal);
	return 0;
}
void input(char normal[])
{
	gets(normal);
}
void swap(char arr[], char pattern[])
{
	char t[9999];
	t[0] = arr[0];
	arr[0] = pattern[0];
	pattern[0] = t [0];
}
void reverse_char(char normal[])
{
	int len = strlen(normal);
	for (int i = 0; i<=len/2; i++)
		swap(normal[i], normal[len - 1 - i]);
}
void output(char normal[])
{
	cout << normal;
}

