#include <bits/stdc++.h>

using namespace std ;
void input(int &n, int pattern[]);
int square(int scan);
int check_square_number(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[9999];
    input(n,arr);
    int answer = check_square_number(n,arr);
    output(answer);
    return 0 ;
}
void input(int &n, int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int square(int scan)
{
    int t = 1 ;
    int tmp = sqrt(scan);
    if (tmp*tmp != scan)
        t = 0;
    return t;
}
int check_square_number(int n , int pattern[])
{
    int t = 1;
    for (int i = 0 ; i<n ; i++)
        if (square(pattern[i]) == 0)
        {
            t = 0 ;
            break;
        }
    return t;
}
void output(int answer)
{
    if (answer==1)
        cout << "True";
    else
        cout << "False";
}
