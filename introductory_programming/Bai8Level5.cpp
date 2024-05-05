#include <bits/stdc++.h>

using namespace std;
void input(int &x);
int scan(int x);
void output(int out);

int main()
{
    int n;
    input(n);
    int answer = scan(n);
    output(answer);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
int scan(int x)
{
    int answer = -1;
    for (int i = 1; i <= round(sqrt(x)); i++)
        if (x % i == 0)
        {
            if (i % 2 != 0) answer = max(answer, i);
            if ((x/i) % 2 != 0) answer = max(answer, x/i);
        }
    return answer;
}
void output(int out)
{
    cout << out;
}
