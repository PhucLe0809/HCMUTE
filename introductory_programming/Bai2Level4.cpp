#include <bits/stdc++.h>

using namespace std;
void input(int &x);
bool scan(int x);
void output(bool out);

int main()
{
    int n;
    input(n);
    bool test = scan(n);
    output(test);
    return 0;
}
void input(int &x)
{
    cin >> x;
}
bool scan(int x)
{
    if (x < 2) return false;
    else
    {
        int i = 2; bool kt = true;
        while (i <= round(sqrt(x)) && kt)
            if (x
                 % i == 0) kt = false; else i++;
        if (kt) return true; else return false;
    }
}
void output(bool out)
{
    if (out) cout << "YES"; else cout << "NO";
}
