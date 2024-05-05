#include <bits/stdc++.h>

using namespace std ;
void input(string &n);
double exponential(int a);
double hexa(string n);
void output(double answer);

int main ()
{
	string n ;
	input(n);
	int up_to_up;
	double answer = hexa(n);
	output(answer);
	return 0;
}
void input(string &n)
{
	cin >> n ;
}
double exponential(int a)
{
	double t = 1 ;

	if (a > 0)
		for (int i = 1; i<=a; i++)
			t = t * 16;
	if (a < 0)
	{
		a = a * -1 ;
		for (int i = 1; i<=a; i++)
			t = t * 16;
		t = 1 / t ;
	}
	return t;	
}
double hexa(string n)
{
	double answer = 0;
	int up_to_up = -1;
	int counting = n.length();
	if (n[0] != '-')
	{
		for (int i = 0; i<counting; i++)
		{
			if (n[i] == '.')
				break;
			up_to_up++;
		}
		for (int i = 0; i<counting; i++)
		{
			if (n[i] != '.')
			{
				answer = answer + ((int(n[i]) - 48) * exponential(up_to_up));
				up_to_up--;
			}
		}
	}
	else 
	{
		for (int i = 1; i<counting; i++)
		{
			if (n[i] == '.')
				break;
			up_to_up++;
		}
		for (int i = 1; i<counting; i++)
		{
			if (n[i] != '.')
			{
				answer = answer + ((int(n[i]) - 48) * exponential(up_to_up));
				up_to_up--;
			}
		}
		answer = answer * - 1;
	}	
	return answer;		
}
void output(double answer)
{
	cout << answer;
}
