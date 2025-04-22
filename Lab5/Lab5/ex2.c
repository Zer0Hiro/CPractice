#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

void print(int arr[], int size, char name);
int greater(int arr1[], int arr2[], int size);

int main()
{
	int arr1[N], arr2[N], i = 0, j = 0, maxValue = 0, index;
	srand(time(NULL));

	// Get all numbers for arr1[]
	printf("Enter %d whole numbers: \n", N);
	for (i; i < N;)
	{
		printf("Enter arr[%d]: ", i);
		if (scanf("%d", &arr1[i]) == 0) printf("Wrong Input");
		else i++;
	}

	// Get maxValue 
	printf("Enter max value greater than 0: ");
	while (maxValue <= 0)
	{
		if (scanf("%d", &maxValue) == 0) printf("Wrong input");
	}

	// Get all values for arr2[]
	for (j; j < N; j++)
	{
		// Fills with random numbers
		arr2[j] = rand() % (maxValue + 1);

	}

	print(arr1, N, '1');
	print(arr2, N, '2');
	index = greater(arr1, arr2, N);
	if (index != -1) printf("\nThe index is %d (number %d and %d)", index, arr1[index], arr2[index]);
	else printf("No!!!");
	return 1;
}


// This function check if there is a greater number in arr1[] than in arr2[] at the same position
int greater(int arr1[], int arr2[], int size)
{
	int i = 0;

	for (i; i < size; i++)
	{
		if (arr1[i] > arr2[i]) return i;
	}
	return -1; // No number like that
}


// This function will print arrays
void print(int arr[], int size, char name)
{
	int i = 0;
	printf("Array %c: ", name);
	for (i; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}