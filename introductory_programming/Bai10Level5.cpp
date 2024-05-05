#include <bits/stdc++.h>

using namespace std;
void scan();

int main()
{
    scan();
    return 0;
}
void scan()
{
    for (int i = 1; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (i*j == 2*(i + j)) cout << i << j << " ";
}
