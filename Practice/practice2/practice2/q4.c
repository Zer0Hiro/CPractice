#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checker(int arr[], int size, int num);

int main()
{

}


// This function will check if there digits in number are in the same positions.
int checker(int arr[], int size, int num)
{
	int i, digit;

	// Is every number on its position
	for (i = size - 1; i >= 0; i--)
	{
		digit = num % 10;
		if (arr[i] == digit) num /= 10;
	}
	return num == 0; // True or False
}
