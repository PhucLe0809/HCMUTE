#include <bits/stdc++.h>

using namespace std;
void input(char str[], char ansi[]);
int substring(char str[], char ansi[]);
void output(int answer);

int main ()
{
	char str[99999];
	char ansi[99999];
	input(str,ansi);
	int answer = substring(str,ansi);
	output(answer);
}
void input(char str[], char ansi[])
{
	gets(str);
	gets(ansi);
}
int substring(char str[], char ansi[])
{
	int t = 0;
	int cnt;
	int lens1 = strlen(str);
	int lens2 = strlen(ansi);
	for (int i = 0; i<lens1; i++)
	{
		if (str[i] == ansi[0])
			for (int j = 0; j<lens2; j++)
				if (str[i+j] == ansi[j])
					cnt++;
		if (cnt == lens2) 
		{
			t = 1 ;
			break;
		}
		cnt = 0;
	}
	return t;
}
void output(int answer)
{
	if (answer == 1)
		cout << "True";
	else 
		cout << "False";
}
