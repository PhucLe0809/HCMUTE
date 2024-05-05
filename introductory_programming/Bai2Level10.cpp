#include <bits/stdc++.h>

using namespace std;
void input(int &n);
void binary(int n);
void octal(int n);
void hexan_decimal(int n);
void output(int n);
void screen(int n);

int main ()
{
	int n;
	input(n);
	binary(n);
	octal(n);
	hexan_decimal(n);
}
void input(int &n)
{
	cin >> n;
}
void binary(int n)
{
	int a[99999];
	int i = 0;
	int tam = n;
	if (tam < 0)
		n = n*-1;
	while (n>0)
	{
		a[i] = n % 2;
		n = n / 2;
		i++;
	}
	if(tam < 0)
		a[i-1] = a[i-1] * -1;
	if(tam == 0)
	{
		output(a[0]);
		screen(tam);
	}
	
	for (int j = i-1; j>=0; j--)
	{
		output(a[j]);
		if (j == 0)
			screen(j);
	}
}
void octal(int n)
{
	int a[99999];
	int i = 0;
	int tam = n;
	if (tam < 0)
		n = n*-1;
	while (n>0)
	{
		a[i] = n % 8;
		n = n / 8;
		i++;
	}
	if(tam < 0)
		a[i-1] = a[i-1] * -1;
	if(tam == 0)
	{
		output(a[0]);
		screen(0);
	}
	
	for (int j = i-1; j>=0; j--)
	{
		output(a[j]);
		if (j == 0)
			screen(j);
	}
}
void hexan_decimal(int n)
{
	int tAm = n;
	if (n<0) 
		n = n*-1;
	string tam;
	int j = 0;
	while (n > 0)
	{
		int tam2 = n % 16;
		if (tam2 >= 10)
		{
			switch (tam2)
			{
				case 10 :
				{
					tam[j] = 'A'; 
					break;
				}
				case 11 :
				{
					tam[j] = 'B';
					break; 
				}
				case 12 :
				{
					tam[j] = 'C'; 
					break;
				}
				case 13 :
				{
					tam[j] = 'D'; 
					break;
				}
				case 14 :
				{
					tam[j] = 'E';
					break;
				} 
				default :
				{
					tam[j] = 'F';
					break;
				}
			}
			j++;
			n = n/16;
		}
		else 
		{
			tam[j] = tam2;
			n = n/16;
			j++;
		}		
	}
	if (j == 0)
		output(tam[j]);
	if (tAm<0)
		for (int i = j ; i>=0; i--)
			{
				tam[j] = '-';
				output(tam[i]);	
			}
	else
		for (int i = j -1 ; i>=0; i--)
			output(tam[i]);
}
void output(int n)
{
	if (n<10)
		cout << n;
	else 
		cout << char(n);
}
void screen(int n)
{
	cout << endl;
}
