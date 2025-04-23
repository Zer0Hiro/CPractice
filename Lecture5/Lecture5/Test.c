#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes memory allocation
#include <stdlib.h>

int main()
{
	int* arr;
	int n = 6;
	// Same as malloc but makes all objects in array equal to 0 arr[n] = {0}
	arr = (int*)calloc(n, sizeof(int));
	if (arr == NULL) return 0; //Not enough memory
	printf(arr);
	return 0;
}