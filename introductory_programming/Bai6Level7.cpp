#include <bits/stdc++.h>

using namespace std ;
void input(int &n , int pattern[]);
int perfect(int arr);
int check_perfect_number(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[9999];
    input(n,arr);
    int answer = check_perfect_number(n,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n ;
    for (int i = 0 ; i < n ; i++ )
        cin >> pattern[i];
}
int perfect(int arr)
{
    int tmp = 0 ;
    int t = 0;
    for (int i = 1 ; i <= arr/2  ; i++)
        if (arr%i==0)
            tmp = tmp + i;
    if (tmp == arr)
        t = 1 ;
    return t;
}
int check_perfect_number(int n , int pattern[])
{
    int t = 1;
    for (int i = 0 ; i < n ; i++)
        if (perfect(pattern[i]) == 0)
        {
            t = 0;
            break;
        }
    return t ;
}
void output(int answer)
{
    if (answer == 1)
        cout <<"True";
    else
        cout << "False";
}
