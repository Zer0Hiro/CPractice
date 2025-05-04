#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes memory allocation
#include <stdlib.h>

int main()
{
	int* arr;
	int n;
	
	// Will allocate memory with size of n
	// basically makes arr[] with length of n
	arr = (int*)malloc(n * sizeof(int));
	// Mandatory to check if there is actually a place for arr
	if (arr == NULL) return 0; //Not enough memory
	
	free(arr); // Free memory from arr

	// Same as malloc but makes all objects in array equal to 0 arr[n] = {0}
	arr = (int*)calloc(n, sizeof(int));
}