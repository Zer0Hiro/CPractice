#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double* inputArithmetic(double* a1, double* d, int* n);
double setArithmetic(double a1, double d, double* arr, int n);

int main()
{
	int n,i;
	double a1, d, sum;
	double* arr;
	arr = inputArithmetic(&a1, &d, &n);
	// Gets sum of all elements in sequence
	sum = setArithmetic(a1, d, arr, n);
	// Prints all numbers in sequence 5 in each row
	for (i = 0;i < n;i++)
	{
		if (i % 5 == 0) printf("\n");
		printf("  %lf", arr[i]);
	}

	printf("\nThe sum of the sequence elements is: %9.6f", sum);
	
	// Free memory of array
	free(arr);
	return 1;
}

// This function will get starting number, difference between numbers and amount of steps
double* inputArithmetic(double* a1, double* d, int* n)
{
	double* arr;
	// Get's first number of sequence
	printf("Enter a1, d, and n respectievly, please: ");
	if (scanf("%lf", a1) != 1)
	{
		printf("Wrong input"); 
		return -1;
	}
	// Get size of each step
	if (scanf("%lf", d) != 1)
	{
		printf("Wrong input");
		return -1;
	}
	// Get amount of numbers in sequence
	if (scanf("%d", n) != 1)
	{
		printf("Wrong input");
		return -1;
	}

	if (*n <= 0) return NULL;

	arr = (double*)malloc((*n) * sizeof(double));
	// Check if memory allocated
	if (arr == NULL)
	{
		printf("Error: Not Enough Memory");
		free(arr);
		exit(1);
	}
	return arr;
}

// Fill the array of sequence and returns SUM of array
double setArithmetic(double a1, double d, double* arr, int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n; i++)
	{
		arr[i] = a1 + d*i;
		sum += arr[i];
	}
	return sum;
}

