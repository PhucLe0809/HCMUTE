#include <bits/stdc++.h>

using namespace std ;
void input(int &rght, int &lft, int matrix[][100]);
int matrix_max(int pos, int lft, int matrix[][100]);
int matrix_min(int pos, int rght, int matrix[][100]);
int horse(int rght, int lft, int matrix[][100]);
void output(int answer);

int main ()
{
	int rght,lft;
	int matrix[100][100];
	input(rght,lft,matrix);
	int answer = horse(rght,lft,matrix);
	output(answer);
	return 0;
}
void input(int &rght, int &lft, int matrix[][100])
{
	cin >> rght >> lft;
	for (int i = 0; i<rght; i++)
		for (int j = 0; j<lft; j++)
			cin >> matrix[i][j];
}
int matrix_max(int pos, int lft,int matrix[][100]) 
{
	int max = matrix[pos][0];
	for (int i = 1; i<lft ;i++)
		if (max<matrix[pos][i])
			max = matrix[pos][i];
	return max;
}
int matrix_min(int pos, int rght,int  matrix[][100])
{
	int min = matrix[0][pos];
	for (int i = 1; i<rght ;i++)
		if (min > matrix[i][pos])
			 min = matrix[i][pos];
	return min;
}
int horse(int rght, int lft, int matrix[][100])
{
	int cnt = 0;
	for (int i = 0; i<rght; i++)
		for (int j = 0; j<lft; j++)
			if (matrix_max(i,lft,matrix) == matrix_min(j,rght,matrix))
				cnt++ ;
	return cnt;
}
void output(int answer)
{
	cout << answer;
}

