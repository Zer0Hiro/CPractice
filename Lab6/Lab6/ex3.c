#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void set_2d(float** a, int m, int n);
void print_2d(float** a, int m, int n);

int main()
{
	int m, n, i;
	float** a;
	printf("enter m and n, for m*n array: \n");
	if (scanf("%d %d", &m, &n) != 2)
	{
		printf("\nError");
		return 0;
	}

	// Allocate memory for every row
	a = (float**)malloc(sizeof(int*) * m);
	if (a == NULL)
	{
		printf("\nError: Not Enough Memory");
		free(a);
		exit(1);
	}

	// Allocate memory for every col
	for (i = 0;i < m;i++)
	{
		a[i] = (int*)malloc(sizeof(int) * n);
		if (a[i] == NULL)
		{
			printf("\nError: Not Enough Memory");
			free(a);
			exit(1);
		}
	}

	set_2d(a, m, n);
	print_2d(a, m, n);
	free(a);
	return 0;
}


// This function will fill matrix with float number
void set_2d(float** a, int m, int n)
{
	int i, j, k = 1;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = k++;
}

// This function will print matrix
void print_2d(float** a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%10.1lf", a[i][j]);
	}
}
