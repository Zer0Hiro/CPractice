#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Includes memory allocation
#include <stdlib.h>

int main()
{
	int* arr, *temp;
	int n;
	// Reallocate arr to new adress
	// If there is a possibillity to stay at the same adress but get more memory will add baits to this
	// Copy and paste it to the new adress
	
	// n + 2 is a new size of arr
	temp = (int*)realloc(arr,(n + 2) * sizeof(int));
	if (temp != NULL) arr = temp;
	else return 1;
	printf("%d", arr);
	return 1;
}