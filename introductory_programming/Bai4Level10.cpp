#include <bits/stdc++.h>

using namespace std;
void input(char normal[]);
int words(char normal[]);
void output(int answer);

int main ()
{
	char normal[99999];
	input(normal);
	int answer = words(normal);
	output(answer);
	return 0;
}
void input(char normal[])
{
	gets(normal);
}
int words(char normal[])
{
	int cnt = 0;
	int tmp = strlen(normal);
	if (normal[0] != ' ')
		cnt++;
	for (int i = 0; i<tmp; i++)
		if (normal[i] == ' ' && normal[i+1] != ' ')
			cnt++;
	return cnt;
}
void output(int answer)
{
	cout << answer;
}
