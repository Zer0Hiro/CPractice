#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

float avg(float arr[], int size);

int main()
{
	float arr[N], aver;
	int i = 0, j = 0, count = 0;
	printf("Enter time of %d runners: ", N);
	// Get all info
	for (i; i < N;)
	{
		if (scanf("%f", &arr[i]) == 0) 
		{
			printf("Wrong Input");
			return 0;
		}	
		else i++;
	}
	aver = avg(arr, N);
	// Find who's below average
	for (j; j < N;j++)
	{
		if (arr[j] < aver) count++;
	}
	printf("The number runners, running below average time is %d. ", count);
	return 0;
}

// This function will check average time of all runners
float avg(float arr[], int size)
{
	int i = 0;
	float sum = 0, average;
	for (i; i < size; i++)
	{
		sum += arr[i];
	}
	// Calculate the average time 
	average = sum / size;
	return average;
}