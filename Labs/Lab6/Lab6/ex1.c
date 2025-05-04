#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 5

double average(int Matrix[][M], int Rows, int Cols, int r, int c);
int poscheck(int Matrix[][M], int r, int c);

int main()
{
	double answer;
	int r,c,mat[N][M] = { 
{11,12,13,14},
{0,-7,18,7},
{1,2,-1,-2},
{6,-9,-19,9},
{300,149,267,10} };
	printf("Enter index which you want to check: ");
	scanf("%d %d", &r, &c);
	answer = average(mat, N, M, r, c);
	printf("The sum of all neighbours of pos(%d,%d) which is number %d are: %f ",r,c,mat[r][c],answer);
}

// This function will check if there is index in matrix like that
int poscheck(int Matrix[][M], int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M) return 0;
	return 1;
}

// This function will find average number around number in Matrix
double average(int Matrix[][M], int Rows, int Cols, int r, int c)
{
	int i,j,sum = 0,count = 0;
	// Start from index that is (x-1,y-1)
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			// Check if this position is available
			if (poscheck(Matrix, r + i, c + j) == 1)
			{
				if (r + i != r || c + j != c)
				{
					sum += Matrix[r + i][c + j];
					count++;
				}
			}
		}
	}
	return (double)sum / count;
}

