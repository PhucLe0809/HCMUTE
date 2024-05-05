#include <bits/stdc++.h>

using namespace std;
void input(int &x);
void scan(int x);
 
int main()
{
	int n;
	input(n);
	scan(n);
	return 0;
}
void input(int &x)
{
	cin >> x;
}
void scan(int x)
{
	switch (x)
	{
		case 1: cout << "mot"; break;
		case 2: cout << "hai"; break;
		case 3: cout << "ba"; break;
		case 4: cout << "bon"; break;
		case 5: cout << "nam"; break;
		case 6: cout << "sau"; break;
		case 7: cout << "bay"; break;
		case 8: cout << "tam"; break;
		case 9: cout << "chin"; break;
		case 0: cout << "khong"; break;
		default:
			cout << "ERROR!";
	}
}
