#include <bits/stdc++.h>

using namespace std;
void input(double &inp);
double sum(double inp, double arr[]);
void output(double inp, double answer);

int main ()
{
    double inp;
    input(inp);
    double arr[int(inp)];
    for (int i = 0 ; i < int(inp) ; i++)
        input(arr[i]);
    double answer = sum(inp,arr);
    output(inp,answer);
    return 0;

}
void input(double &inp)
{
    cin >> inp;
}
double sum(double inp, double arr[])
{
    double t = 0;
    for (int i = 0 ; i < int(inp); i++ )
        t = t + arr[i];
    return t;
}
void output(double inp, double answer)
{
    cout << answer/inp;
}

