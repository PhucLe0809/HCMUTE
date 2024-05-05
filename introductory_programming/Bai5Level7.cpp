#include <bits/stdc++.h>

using namespace std ;

void input(int &n , int pattern[]);
int is_prime(int scan);
int check_prime(int n , int pattern[]);
void output(int answer);

int main()
{
    int n;
    int arr[9999];
    input(n,arr);
    int answer = check_prime(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int is_prime(int scan)
{
    int t = 1;
    if (scan==0 || scan==1)
        t = 0 ;
    for (int i = 2 ; i < scan ; i++)
        if (scan % 2 == 0)
        {
            t = 0;
            break ;
        }
    return t ;
}
int check_prime(int n , int pattern[])
{
    int t = 1;
    for (int i = 0; i<n ; i++)
        if (is_prime(pattern[i])==0)
        {
            t = 0;
            break;
        }
    return t ;
}
void output(int answer)
{
    if (answer==1)
        cout << "True";
    else
        cout << "False";
}
