#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnum(char arr[], int size);

int main()
{
	int arr[] = { '1', '2','a', 'n','5' };
	printf("The number is: %d", cnum(arr, 55));
	return 0;
}

int cnum(char arr[], int size)
{
	int i, newnum = 0;
	int flag = 0; // False

	// Checking if the array contains any numbers
	for (i = 0; i < size; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9') flag = 1;
	}
	if (flag == 0)
	{
		printf("\nThere is no numbers");
		return -1;
	}

	// Create number

	for (i = 0; i < size; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			newnum = (newnum * 10) + (arr[i] - '0');
		}
	}
	return newnum;
}