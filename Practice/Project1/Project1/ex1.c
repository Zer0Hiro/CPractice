#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 6

/*
This program will allow to check if array contains numbers with specific instruction:

The program will return 1 if: for every EVEN/odd number there is EVEN/odd amount of numbers smaller than number

The program will return 0 if: For every EVEN/odd number there is ODD/even amount of numbers....
*/

int f(int A[], int n);
int scan(int* nums, int number, int len, int pos);

// This function will get 6 numbers from user and return 0 or 1
int main()
{
	int array[N],i;
	printf("Please enter 6 natural numbers\n");
	for (i = 0; i < N;)
	{
		printf("Number %d: ", i+1);
		rewind(stdin);
		if (scanf("%d",&array[i]) == 0) printf("Wrong input\n"); //Error
		else i++;
	}
	printf("The output is: %d", f(array,N));
	return 1;
}

// This function will check if the amount of numbers that smaller than X are even/odd
int f(int A[], int n)
{
	int i, k, pos, count;
	for (i = 0; i < n; i++)
	{
		int storage[N] = {-1,-1,-1,-1,-1,-1};
		pos = 0;
		count = 0;
		for (k = 0; k < n; k++)
		{
			if (A[i] > A[k])
			{
				if (scan(storage, A[k], n, pos) != 0) count++;
				pos++;
			}
		}
		// Even/Odd checker
		if (A[i] % 2 != 0 && count % 2 == 0 || A[i] % 2 == 0 && count % 2 != 0) return 0;
	}
	return 1;
}

// This function will check if the number already been counted
int scan(int *nums, int number, int len, int pos)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (nums[i] == number) return 0;
	}
	nums[pos] = number;
	return 1;
}