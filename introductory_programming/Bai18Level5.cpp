#include <bits/stdc++.h>

using namespace std;
void input(int &day, int &mon, int &year);
int scan(int day, int mon, int year);
void output(int out);

int main()
{
    int x, y, z;
    input(x, y, z);
    int answer = scan(x, y, z);
    output(answer);
    return 0;
}
void input(int &day, int &mon, int &year)
{
    cin >> day >> mon >> year;
}
int scan(int day, int mon, int year)
{
    int pivot[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 2; i <= 12; i++) pivot[i] = pivot[i-1] + pivot[i];
    int check = (mon > 2)?((year % 4 == 0 || year % 400 == 0) && year % 100 != 0):(0);
    int answer = pivot[mon - 1] + day + check;
   return 365 - answer;
}
void output(int out)
{
    cout << out;
}
