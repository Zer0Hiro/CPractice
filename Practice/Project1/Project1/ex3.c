#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5
#define ROWS 3

void order(int a[][MAX], int rows, int cols, int x);
void print(int a[][MAX], int rows, int cols);

int main()
{
	int mat[ROWS][MAX],i,j,x;

	// Get matrix from user
	for (i = 0; i < ROWS; i++)
	{
		printf("Enter row number %d: ", i + 1);
		for (j = 0; j < MAX; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}

	// Get X
	printf("Enter X: ");
	scanf("%d", &x);

	// Print first matrix
	printf("\n");
	print(mat, ROWS, MAX);
	printf("\n");

	order(mat, ROWS, MAX, x);
	return 0;
}


// This function will allow to sort matrix by X
// Every number < x will be before X
void order(int a[][MAX], int rows, int cols, int x)
{
	int i, j, temp, pos = 0, prow = 0, buf[2];

	// Rows
	for (i = 0; i < rows; i++)
	{
		// Cols
		for (j = 0; j < cols; j++)
		{
			if (a[i][j] < x)
			{
				// Swap positions of elements
				temp = a[prow][pos];
				a[prow][pos] = a[i][j];
				a[i][j] = temp;

				// Count position that still didnt get swapped
				pos++;
				if (pos == cols) prow++;
				pos %= cols;
			}
			// Saves the location of X
			if (a[i][j] == x)
			{
				buf[0] = i;
				buf[1] = j;
			}
				
		}
	}
	// Finds the place for X
	temp = a[prow][pos];
	a[prow][pos] = a[buf[0]][buf[1]];
	a[buf[0]][buf[1]] = temp;
	
	// Print the final matrix
	print(a, ROWS, MAX);
}


// This function prints the matrix
void print(int a[][MAX], int rows, int cols)
{
	int i, j;
	// Print Matrix
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (j == 0) printf("[%d", a[i][j]);

			if (j != 0) printf("%d", a[i][j]);

			if (j < MAX - 1)
				printf(", ");
		}
		printf("]\n");
	}
}

