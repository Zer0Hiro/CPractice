#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 50 

int average(float array[], int size, float *avg);

int main()
{
	
}

int average(float array[], int size, float *avg)
{
	int i, count = 0;
	*avg = 0;

	//Calculating the average.
	for (i = 0; i < size; i++)
	{
		*avg += array[i];
	}
	*avg /= size;

	//Counting the amount of users with higher than everage salary
	for (i = 0; i < size; i++)
	{
		if (array[i] > *avg) count++;
	}

	return count;
}