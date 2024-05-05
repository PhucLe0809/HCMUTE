#include  <bits/stdc++.h>

using namespace std ;
void input(char normal[]);
int sum_number(char normal[]);
void output(int answer);

int main ()
{
	char normal[99999];
	input(normal);
	int answer = sum_number(normal);
	output(answer);
	return 0;
}
void input(char normal[])
{
	gets(normal);
}
int sum_number(char normal[])
{
	int sum = 0;
	int len = strlen(normal);
	for (int i = 0; i<len; i++)
		if (int(normal[i]) >= 48 && int(normal[i]) <= 57)
			sum  = sum + int(normal[i]) - 48;
	return sum;
}
void output(int answer)
{
	cout << answer;
}
