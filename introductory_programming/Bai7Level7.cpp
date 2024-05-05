#include <bits/stdc++.h>

using namespace std ;

void input(int &n , int pattern[]);
int prime(int scan);
int perfect(int scan);
int check(int n , int pattern[]);
void output(int answer);

int main ()
{
    int n ;
    int arr[9999];
    input(n, arr);
    int answer = check(n ,arr);
    output(answer);
    return 0;
}
void input(int &n , int pattern[])
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin >> pattern[i];
}
int prime(int scan)
{
    int t = 1;
    if (scan==1 || scan==0)
    	t = 0;
	for (int i = 2 ; i < scan; i++)
		if(scan%i==0)
		{
			t = 0;
			break;
		}
	return t;
}
int perfect(int scan)
{
    int tmp = 0 ;
    int t = 0;
    for (int i = 1 ; i <= scan/2  ; i++)
        if (scan%i==0)
            tmp = tmp + i;
    if (tmp == scan)
        t = 1 ;
    return t;
}
int check(int n , int pattern[])
{
    int cnt_prime = 0 ;
    int cnt_perfect = 0 ;
    for (int i = 0; i < n ; i++)
    {
        if (prime(pattern[i])==1)
            cnt_prime = cnt_prime + 1 ;
        if (perfect(pattern[i])==1)
            cnt_perfect = cnt_perfect + 1 ;
    }
    if (cnt_prime==cnt_perfect)
        return 1 ;
    else
        return 0 ;
}
void output(int answer)
{
    if (answer==1)
        cout <<"Equal";
    else
        cout <<"Not equal";
}
