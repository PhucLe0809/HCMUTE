#include <bits/stdc++.h>

using namespace std ;
void input(char normal[]);
void erase_space(char normal[], int &len, int place);
void __erase(char normal[]);
void output(char normal[]);
int main ()
{
	char normal[99999];
	input(normal);
	__erase(normal);
	output(normal);
	return 0;
}
void input(char normal[])
{
	gets(normal);
}
void erase_space(char normal[], int &len, int place)
{
	for (int i = place ; i<len; i++)
		normal[i] = normal[i+1];
	len--;
}
void __erase(char normal[])
{
	int len = strlen(normal);
	while (normal[0] == ' ')
		erase_space(normal,len,0);
	for (int i = 0; i<len; i++)
	{
		if (normal[i] == ' ' && normal[i+1] == ' ')
		{
			erase_space(normal,len,i+1);
			i--;
		}		
	}
	while (normal[len-1] == ' ')
		erase_space(normal,len,len-1);		
}
void output(char normal[])
{
	cout << normal;
}
