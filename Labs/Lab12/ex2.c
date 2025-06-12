#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef enum {FALSE, TRUE} BOOL;
BOOL Int_Sum(void *, void *, void *);
BOOL Float_Sum(void *, void *, void *);
BOOL Sum(BOOL (*f)(void *, void *, void *), void **p_num, void *number);

int main()
{
	int num[] = {3, 5, 23, 5, 6}, i, value;
	float fnum[] = {3.5, 5.0, 2.3, 5.8, 6.2}, fvalue;
	void *p_num[N];

	// Check for ints
	for (i = 0; i < N; i++)
	{
		p_num[i] = &num[i];
	}
	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	if (Sum(Int_Sum, p_num, &value) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");

	// Check for floats
	for (i = 0; i < N; i++)
	{
		p_num[i] = &fnum[i];
	}
	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	if (Sum(Float_Sum, p_num, &fvalue) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");
	
	return 0;
}

// This function will try to find specific number by sum of 2 others (INT)
BOOL Int_Sum(void *a, void *b, void *c)
{
	if (*(int *)a + *(int *)b == *(int *)c)
		return TRUE;
	return FALSE;
}

// This function will try to find specific number by sum of 2 others (FLOAT)
BOOL Float_Sum(void *a, void *b, void *c)
{
	if (*(float *)a + *(float *)b == *(float *)c)
		return TRUE;
	return FALSE;
}

// This function will check all possible ways to get number from some array
BOOL Sum(BOOL (*f)(void *, void *, void *), void **p_num, void *number)
{
	int i, j;

	// Check all numbers
	for (i = 0; i < N; i++) // Number to check
	{
		for (j = 0; j < N; j++) // Second Number
		{
			if (i != j)
			{
				if (f(p_num[i], p_num[j], number) == TRUE)
					return TRUE;
			}
		}
	}
	return FALSE;
}